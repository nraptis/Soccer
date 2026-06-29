#include "TwistExpander_Billiards_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Billiards_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC37828BE8FC8027DULL + 0xD45035CBEFBD4191ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC25305D2F02330DULL + 0xFAC58232CBDB297DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9BA4A47C19CEDC11ULL + 0x9E7CCC939BE2C6F4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB3FED05DD43E54A9ULL + 0xFCDC26044B6A8BB6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE3D0B2901946A4DBULL + 0x9D31C009A1C139F5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC67F737D2D190597ULL + 0xD97A6959A123CAA9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA0E8B80912C34715ULL + 0x87C0856640DEA440ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3857E2D395373CDULL + 0xDFD2083966CCB3C9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8BF94E6129A1D81BULL + 0xB32FDCF86EE8E485ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF7AE0DBAE9D787D5ULL + 0xD6EFDEF186EEB5D7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF53C56D5D90D92E9ULL + 0xE4B494953DA5E8B6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA8178C3647C2936DULL + 0x8C229A2F5245A891ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x90475A12D0181CC5ULL + 0xD6F26426AB1FE952ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEA64C8544010C6D7ULL + 0xEF72803FEDD54C10ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBA82BCB7F4427747ULL + 0xA4B7B5219B3A5DFFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD5A53243C45551BBULL + 0x869609B076C89CFFULL);
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
            aIngress = RotL64(mSource[((aIndex + 1035U)) & S_BLOCK1], 24U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4133U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2646U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 625U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 38U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererI + RotL64(aScatter, 47U)) + 2168513956284366370U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 10290361969974613111U) + aNonceWordF;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 53U)) + 15673836275828498050U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 16600540024145812236U;
            aOrbiterI = (aWandererK + RotL64(aCross, 57U)) + 9428052101528111892U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 43U)) + 12763657928312763377U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 14U)) + 10751286982008662485U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 1708230173038057979U;
            aOrbiterG = (aWandererC + RotL64(aCross, 39U)) + 4011389705422783816U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 37U)) + 11704428328093077714U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 60U)) + 2055336619674699284U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1870865272102705804U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3574214263751923179U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 13132083406834413563U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 984611970726966186U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15207945449947643672U;
            aOrbiterC = RotL64((aOrbiterC * 9539470161576639981U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4181398506373973169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15222345431506025949U;
            aOrbiterB = RotL64((aOrbiterB * 6925143692628659467U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 15023513452326240962U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14965669361708810699U;
            aOrbiterF = RotL64((aOrbiterF * 587008860996713147U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7985755518735406360U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 225592097619240187U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2313509354133400439U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3659537916566939383U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17043668033610689611U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 10797634709118100773U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10217321522161675848U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8013663869536146842U;
            aOrbiterJ = RotL64((aOrbiterJ * 2293233079384777175U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13762445330867496042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2692400019659269106U;
            aOrbiterE = RotL64((aOrbiterE * 167704184292219399U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18232551682424867647U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14785847596876239854U;
            aOrbiterK = RotL64((aOrbiterK * 4569180925037758487U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5910282247522389536U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16556038638738871204U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18356922295088260901U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 141620663839815754U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2168513956284366370U;
            aOrbiterI = RotL64((aOrbiterI * 8605382725635471683U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 44U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 40U) + aOrbiterI) + RotL64(aOrbiterJ, 40U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6858U)) & S_BLOCK1], 44U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5735U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8562U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((aIndex + 5764U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 6654158889644956636U) + aNonceWordA;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 9045779659363991870U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 3888897662136993491U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 57U)) + 6882016842864459345U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 43U)) + 15601891715956172291U) + aNonceWordO;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 21U)) + 5176811598629335350U) + aNonceWordH;
            aOrbiterH = (aWandererK + RotL64(aScatter, 24U)) + 12519945150889074325U;
            aOrbiterG = (aWandererD + RotL64(aCross, 39U)) + 4552583214397603278U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 29U)) + 14225482701804864688U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 11U)) + 5485298070606280363U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 13U)) + 11237713257388094289U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14340345895626142788U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 16275167270553643347U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 7308578867128951199U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14041860597556520250U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1436068974197066343U;
            aOrbiterK = RotL64((aOrbiterK * 3938460345031496843U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11483155566419547004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4608508534724289325U;
            aOrbiterE = RotL64((aOrbiterE * 13461385011638899485U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2389196334288832895U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4062682330273866602U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8787682133271101901U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5655656046585592034U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7977947821249746880U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11653718118543974168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5456429682072377614U;
            aOrbiterH = RotL64((aOrbiterH * 12504180638665296649U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12457179652004203574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 445821754230182952U;
            aOrbiterF = RotL64((aOrbiterF * 16043092621697786393U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12429505513284703263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 12480745784412363537U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 643617210585287593U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6952219750393303609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13965647644550998416U;
            aOrbiterB = RotL64((aOrbiterB * 5395755018020115073U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5602193483992512507U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9593414134773695959U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2186313187456153775U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16469843418561148995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6654158889644956636U;
            aOrbiterG = RotL64((aOrbiterG * 17490973872858383001U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterF, 22U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aScatter, 54U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 53U));
            aWandererH = aWandererH + (((RotL64(aScatter, 40U) + RotL64(aOrbiterJ, 48U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 15325U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13526U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11397U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 14786U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 21U)) + 16424657151168221875U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 56U)) + 17150123681886380361U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 37U)) + 16041993588694572757U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 43U)) + 9871185846434828537U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 47U)) + 11227236398354430757U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 5399325217402192631U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 53U)) + 9248828789282890454U) + aNonceWordK;
            aOrbiterA = (aWandererK + RotL64(aIngress, 19U)) + 9041370494203701062U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 50U)) + 14944424084524970764U) + aNonceWordN;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 5481938174456671041U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 14783648629543752715U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12355573914530445723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9863991559011968318U;
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16149688605937250965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 106041828692026825U;
            aOrbiterI = RotL64((aOrbiterI * 12199934305374582599U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8076098639554567792U) + aNonceWordG;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 11155119311895580013U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 1495180896564818647U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6847612160595917702U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16094377920388017367U;
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13584719866672696684U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13446209321646234607U;
            aOrbiterF = RotL64((aOrbiterF * 9945349065094781529U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15829806645369560988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12573767256739062550U;
            aOrbiterG = RotL64((aOrbiterG * 5649504278826069077U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3850030870300393809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11857593987748189858U;
            aOrbiterD = RotL64((aOrbiterD * 15942863910931814193U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5505918410521728373U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12949653497121247860U;
            aOrbiterE = RotL64((aOrbiterE * 90944913639560027U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2448323375614082955U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4386059032042654583U;
            aOrbiterB = RotL64((aOrbiterB * 11730132905525317201U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 108129028178045299U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 18292666533864994149U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2599590507178673531U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10771402979550786312U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16424657151168221875U;
            aOrbiterK = RotL64((aOrbiterK * 6255743082177474607U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 40U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 36U) + aOrbiterB) + RotL64(aOrbiterG, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterA) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 52U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + aNonceWordO);
            aWandererG = aWandererG + ((RotL64(aCross, 22U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17203U)) & S_BLOCK1], 14U) ^ RotL64(pSnow[((aIndex + 16456U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19003U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19660U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneB[((aIndex + 19017U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 16200278595895089008U) + aNonceWordK;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 56U)) + 1029614154810465897U) + aNonceWordG;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 27U)) + 7129562468705441295U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 14388903902433951274U;
            aOrbiterD = (aWandererA + RotL64(aCross, 5U)) + 1013568949315967455U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 39U)) + 3128823373497815651U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 13U)) + 14525694606889470589U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 11U)) + 14443983602196782887U) + aNonceWordO;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 42U)) + 12244220415328641190U) + aNonceWordJ;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 21U)) + 10477159225338766614U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 2842870123078131566U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8621138818955849917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5038396344400303181U;
            aOrbiterH = RotL64((aOrbiterH * 14636756322207385447U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2768613802894372496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2027754864051410015U;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2848088309172056399U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15017458513904884651U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9926904679902843055U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9079797279596336139U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 15424866642305110811U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 12912331089970158845U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13751764050290602740U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 14980807690491467023U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3508673897305667669U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3600868397311393233U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 5165032044164139165U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1222655844979128996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2257342337168905875U;
            aOrbiterA = RotL64((aOrbiterA * 6198995971182272119U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6290990717563682725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15308494772443447109U;
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4065385272074155855U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17216369169581934516U;
            aOrbiterG = RotL64((aOrbiterG * 16172589962950781777U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15683161334290612079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4197626901960576264U;
            aOrbiterB = RotL64((aOrbiterB * 2822547214684481747U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4400047838649306704U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16200278595895089008U;
            aOrbiterI = RotL64((aOrbiterI * 6603195071605635697U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 6U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 51U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 6U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterF, 30U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22004U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 22035U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25114U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22882U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24148U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((aIndex + 24048U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 11U)) + 11698283336767769359U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 43U)) + 13297826354831483872U) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 15254999058287530795U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 51U)) + 17474166585085346567U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 15684783498452840289U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 4U)) + 5061229733465216486U) + aNonceWordE;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 39U)) + 15370981279168377944U) + aNonceWordH;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 21U)) + 17966672773619554092U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 14685092893994491068U;
            aOrbiterE = (aWandererC + RotL64(aCross, 24U)) + 12798804186209406389U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 19U)) + 2848444181474221574U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8551142075919636146U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8833198159158950723U;
            aOrbiterB = RotL64((aOrbiterB * 7650289040764974737U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7351473160893666232U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14204899612487622222U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6317485031956448029U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7008985178526543258U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13576796403863120356U;
            aOrbiterK = RotL64((aOrbiterK * 13745839827679114077U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5769784656937900699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14075925808204936705U;
            aOrbiterE = RotL64((aOrbiterE * 5844894088757604713U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17818667502858010896U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16016922065572683130U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7525645833898085373U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1582458237855075977U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10830440354527138227U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 10499386926982228251U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10653964151654643772U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11218475491129483859U;
            aOrbiterC = RotL64((aOrbiterC * 3338108067044357141U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9863649760189649255U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13790281439048354358U;
            aOrbiterD = RotL64((aOrbiterD * 4682098083538482849U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14846954923718136337U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 522207783972623813U;
            aOrbiterG = RotL64((aOrbiterG * 14299798934454852811U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 426829715716262697U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7482977730216354509U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 6317437989422015173U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10736099808538972990U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11698283336767769359U;
            aOrbiterI = RotL64((aOrbiterI * 17230175904095995929U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 46U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28014U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 28725U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28367U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27931U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 31642U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 31463U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31646U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 11U)) + 5295352595333316211U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 2341795367042042605U) + aNonceWordB;
            aOrbiterH = (aWandererH + RotL64(aScatter, 22U)) + 10122175780504033663U;
            aOrbiterD = ((((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 10084612804696198554U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 13U)) + 16470424309851045971U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 29U)) + 656016130975227994U) + aNonceWordM;
            aOrbiterK = (aWandererI + RotL64(aIngress, 3U)) + 15313268829659834317U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 27U)) + 3795220914993923394U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 14044442220988813825U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 43U)) + 3804224626734584802U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 54U)) + 7980006306010255693U) + aNonceWordK;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13746830564584711549U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11852212099729274845U;
            aOrbiterH = RotL64((aOrbiterH * 2164880979318247855U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9083223471018084847U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11361854103656219887U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1713819986642275223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1382000168233902914U;
            aOrbiterK = RotL64((aOrbiterK * 3894160765130198157U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4540474625764565485U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1756168174375757220U;
            aOrbiterA = RotL64((aOrbiterA * 12739160208010092017U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1409297070183609309U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6082750101445444357U;
            aOrbiterE = RotL64((aOrbiterE * 17438740230251860935U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1113239890859479202U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10932192439503964363U;
            aOrbiterC = RotL64((aOrbiterC * 5915660289913324281U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3732595033748508428U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5117760372351117286U;
            aOrbiterB = RotL64((aOrbiterB * 2671510075176315761U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7399968659654088641U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14835608167871904147U;
            aOrbiterJ = RotL64((aOrbiterJ * 8312521710415756159U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7851355416751467648U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 262169565276199916U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11801419425408657509U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1771847554312299305U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15588805765521695222U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8541206691371972017U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6162696602553964144U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5295352595333316211U;
            aOrbiterG = RotL64((aOrbiterG * 8368226841948931873U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + aNonceWordO);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 54U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 24U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 42U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Billiards_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x90EEBC3650098C9DULL + 0x8700C599ACF87FF2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x861266189C214F73ULL + 0xFE6A98AABA562595ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD5778A9079F3B4C7ULL + 0x8DB0B11237D6A392ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x90B5DCD4D603205FULL + 0x9B90D2BF8455D6B7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9AAC8CAEB44E5DFBULL + 0xF69EFBFD0D8C1F89ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8D9380EFE691793FULL + 0xDE3FEB1CDBBA28B0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA962EAF8C5B52EF1ULL + 0xAC740F847AF7D12FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA8E687F676E87173ULL + 0xF41DD2D0B7137AD0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFCF52B3900DA3529ULL + 0xDCAEE4504679203EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA04DDC5D7119145FULL + 0xC3CF76CCB283FB42ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD5A3F227232A15C5ULL + 0xE7074D85BDF43054ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9DBC10CCDC5EC9F3ULL + 0xBC5568D5AAC7439CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8581CA58F81BE2CDULL + 0xB2BCEF441F54DFD6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA240A9E03E7935B3ULL + 0xBF743CB4B21E05FFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAF57536BD0A342BFULL + 0xA8F779C01995437DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDC0C13D886CA4AC3ULL + 0xED13EFFF519B0945ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 2787U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1204U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1873U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 4709U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 51U)) + 15904465836916519864U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 17725629806317789307U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 13794170125914914828U) + aNonceWordD;
            aOrbiterF = ((aWandererF + RotL64(aCross, 37U)) + 2149055907476874332U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 41U)) + 5342047776745074649U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 8268148484060546838U;
            aOrbiterK = (aWandererG + RotL64(aCross, 13U)) + 10821151364028563719U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 23U)) + 4294213820894407378U) + aNonceWordJ;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 18U)) + 10884726101307943090U) + aNonceWordA;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16432210042202444824U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 15196602644336228055U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 12680438355124070237U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14117787670220328165U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 219833877949480215U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 10736293047771972173U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3326396981881473962U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14918513066311426279U;
            aOrbiterA = RotL64((aOrbiterA * 14269763278564574663U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11795234681370163206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3068267285352664813U;
            aOrbiterK = RotL64((aOrbiterK * 15746255933920904619U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 245233356957999496U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 709926406353796673U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 13627039596842073595U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5378105439430271038U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10114555061122044430U;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13233010815716769713U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8231291294833548389U;
            aOrbiterF = RotL64((aOrbiterF * 10840516135212753869U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7160760224172419829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14767926435411546785U;
            aOrbiterJ = RotL64((aOrbiterJ * 1643485739468851073U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4464245330038080103U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15778166658285494712U;
            aOrbiterH = RotL64((aOrbiterH * 13980891936095282989U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 24U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterG) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 58U) + RotL64(aOrbiterH, 56U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererF, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8906U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 7467U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 5850U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5856U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 6618U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 42U)) + RotL64(aCarry, 39U)) + 2571116506511057880U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 13112435411509707292U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 29U)) + 10403251762787357256U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 51U)) + 8461951095541400405U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 5U)) + 9890793478557463815U) + aNonceWordD;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 37U)) + 3030229465991783707U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 18U)) + 7273848154043719247U) + aNonceWordB;
            aOrbiterB = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 10681774862516028276U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 11U)) + 7105082755586853104U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6588579345319551129U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14616333550242386092U;
            aOrbiterF = RotL64((aOrbiterF * 2934574715879306337U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15439666290229654921U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14438730801970761889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14515616787452085729U;
            aOrbiterD = RotL64((aOrbiterD * 2041601927968559821U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4167853822635132419U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8950982233003320239U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 12391327853728029953U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7100871010552394421U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16552349374101955967U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15381697462381887944U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6801677551341079401U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 13325954438427340703U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 947011315719204867U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6356920162398333481U;
            aOrbiterC = RotL64((aOrbiterC * 5566721941682667419U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8910262020598577378U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8778455415977526457U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4092470497616637283U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5585696961453127223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9670655481681494412U;
            aOrbiterB = RotL64((aOrbiterB * 7863197168965036383U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterG, 24U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordA) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterD, 43U)) + aOrbiterE) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 58U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 14682U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 13097U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 14446U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12645U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((aIndex + 14413U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 14U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererD + RotL64(aScatter, 10U)) + 8988572360732005217U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 51U)) + 17889613225105985335U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 15563478320513948626U) + aNonceWordI;
            aOrbiterD = (aWandererA + RotL64(aIngress, 3U)) + 3441351228410524816U;
            aOrbiterA = (aWandererB + RotL64(aCross, 19U)) + 4425592689451435346U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 37U)) + 12733160231627305928U) + aNonceWordD;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 29U)) + 3574152157304607854U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 15167631896729808783U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 24U)) + 15822667973915417055U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17181685481076577637U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9979204751408873468U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8244434774754786565U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1334240485667164762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9190066751460137016U;
            aOrbiterE = RotL64((aOrbiterE * 14585141844653660363U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15465215829109246336U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2305208282453624419U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10257861974108363283U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16951510027310993926U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11117938943423526901U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 7805486716716924787U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12461379120662979432U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11719697049048823897U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14880996802304818757U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6843357278142933570U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12727898578324702374U;
            aOrbiterC = RotL64((aOrbiterC * 9786435451654365097U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18127999660067652233U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 11754709060558683082U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 12798744012150745847U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16940151146420516184U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12924950783056761895U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8898170377271926745U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14829713915929878471U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 840466047621042565U;
            aOrbiterG = RotL64((aOrbiterG * 10748511630509529489U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 52U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 48U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21185U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 16721U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21827U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21771U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 16584U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 6U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (aWandererH + RotL64(aCross, 29U)) + 4773124477323378268U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 4U)) + 16848723289435796005U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 13846642134917107058U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 51U)) + 6472057872482789939U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 11U)) + 2747019500690707226U) + aNonceWordN;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 9003965289739733880U) + aNonceWordH;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 3013390651936257377U) + aNonceWordG;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + 3331004709895625067U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 58U)) + 15355010435553517129U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7709870658004280052U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 13568728443963926564U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 6736090830113688981U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12409548853419307131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15370309834426476775U) + aNonceWordF;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 3896803894396631184U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 11018830202891911603U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10848873633291935766U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12885336509190543440U;
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8252290890093788010U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9201553615601641350U;
            aOrbiterG = RotL64((aOrbiterG * 420321130559162915U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14014209645503188472U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4015071464301844550U;
            aOrbiterD = RotL64((aOrbiterD * 17444195018239904971U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16173085647514027347U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16916627014974363360U;
            aOrbiterF = RotL64((aOrbiterF * 7699587344277490953U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1591680303404522110U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16499606051269327916U;
            aOrbiterJ = RotL64((aOrbiterJ * 814405848002794813U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6932673635509444619U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 8745681160108707944U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 14565255558668084787U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 18U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterE, 56U)) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 40U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 60U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 27075U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 25770U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22871U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27184U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 20U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 46U)) + RotL64(aCarry, 21U)) + 9751314027302668907U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 19U)) + 12175450995523107056U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 17519694958730119552U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 27U)) + 9093525527925682263U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 13U)) + 3713831321786810138U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 42U)) + RotL64(aCarry, 57U)) + 10108355209191835040U) + aNonceWordC;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 53U)) + 12956307447311314768U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 37U)) + 1904298513945877359U) + aNonceWordF;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 4658049993308574460U) + aNonceWordB;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9826333658248851902U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12058666914724365134U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 964233873188373939U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2516574707110528099U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13335308331049750235U;
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 8230749255538495304U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12387639130570188998U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8459259798142872020U;
            aOrbiterI = RotL64((aOrbiterI * 8001346480955847013U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16083784052002800300U) + aNonceWordP;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 1957284290736468379U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 5046501301740813065U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 7349538179311335863U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16395170077006105258U;
            aOrbiterB = RotL64((aOrbiterB * 4230485452156662763U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 3317652065873784068U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterE = RotL64((aOrbiterE * 9789270651974719183U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5568525912112200094U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9334250662962319598U;
            aOrbiterK = RotL64((aOrbiterK * 5034887614541768961U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5641394627075994165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 14U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 36U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 6U) + aOrbiterC) + RotL64(aOrbiterA, 30U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 27381U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 32368U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32001U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29680U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 60U)) + 16183871922837164759U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 23U)) + 7002058258090219055U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 3U)) + 5650868611888303705U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 47U)) + 11899839660943876690U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 12U)) + 15349649504488111111U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 14060149569086744970U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 12920917574225030112U) + aNonceWordB;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 2831994965175330135U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 19U)) + 18312543585028439192U) + aNonceWordF;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11657562205118394239U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10850792819281246052U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10663100544207879337U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17810371216216125323U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 534217972450595401U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5498715358793875584U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9256727548911651373U;
            aOrbiterI = RotL64((aOrbiterI * 10498848323914000989U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17246360111302191699U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 18309978718113983369U;
            aOrbiterF = RotL64((aOrbiterF * 18267472694666221077U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3100998994319502921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterD = RotL64((aOrbiterD * 17847033539279176187U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1889641029473279114U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16538494307002917945U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8081488217920885783U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5432230549146849322U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2634437941396090817U;
            aOrbiterG = RotL64((aOrbiterG * 7612999214758935211U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16940172599174185058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13151669140593952203U;
            aOrbiterA = RotL64((aOrbiterA * 16225319638131723487U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3995064294869931681U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 913081077665768816U;
            aOrbiterB = RotL64((aOrbiterB * 9299514648768060453U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 48U) + RotL64(aOrbiterD, 13U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterF, 6U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 51U);
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

void TwistExpander_Billiards_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC24F41CABB6FE927ULL + 0xBEF349704472CB52ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCD385E7F00AE9F71ULL + 0x918C19E0970D52BDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBCAF058250C67549ULL + 0xC7E41EEB01B6BE51ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA2063E5874A05237ULL + 0xCBAC1F6FA2F15958ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBCC247A3F8B1C11DULL + 0xE5C2FF1C6B16A7A4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAE181D24BDAA0BDFULL + 0xED56FFDA8B32FE2FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDCA726339A9113FBULL + 0x962EA086A540D1B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9BA5AAAE8041C865ULL + 0xAB8A43D2B3949221ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF76FE1607A39C497ULL + 0xBFA6AD2A25C8368EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFDFDD144B6F5E7E9ULL + 0xE09BE815AE06D3E8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD5AC6288021F06DDULL + 0x9A1DE2E55D49EF55ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8B2195D82971CDABULL + 0xBEDCEAABA97DEEBDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCD5C899EABD6357BULL + 0xB2D0D77323F174CCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD26F06BED389CA3BULL + 0x92D6FA6CCB8BF079ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x87FB1CE0F05CD90BULL + 0xA131BCC9DDA17003ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBB01B51EE2F6658FULL + 0xDB9CDE1942A590E9ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4770U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 3155U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6710U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 381U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 114U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5488U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 12U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 10336802574069791273U;
            aOrbiterB = (aWandererH + RotL64(aCross, 54U)) + 169025388197058936U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 6541354188379168846U) + aNonceWordE;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 16223920526599306104U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 13U)) + 12756613707692514808U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5082475548176484035U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4907435526952698526U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1379692095754989215U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14236627073831834337U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11502511046130497584U;
            aOrbiterB = RotL64((aOrbiterB * 3460330807286625917U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3679044835550219497U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11254838916686736746U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 8631695922983532915U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10582608424233200966U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10449735026385340313U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 7363770199734997411U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4628253464169957835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterK = RotL64((aOrbiterK * 4234720298731378527U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 4U) + RotL64(aOrbiterK, 4U)) + aOrbiterB) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13506U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 13327U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13600U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneC[((aIndex + 15819U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8828U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12948U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16308U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 3612110001869385068U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererI + RotL64(aScatter, 56U)) + 16340824141280225936U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 15222338965130765231U) + aNonceWordL;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 11U)) + 6649270508107155041U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 768217258655426384U) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4481855259658861851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18318041934562434016U;
            aOrbiterH = RotL64((aOrbiterH * 14913761339765234979U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4212457153804401807U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16143621095636987628U;
            aOrbiterC = RotL64((aOrbiterC * 6576072860505961427U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2095664232866642086U) + aNonceWordA;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 4339527736737366572U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 17503569508822244125U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13679353177869884790U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11582168502846418236U;
            aOrbiterI = RotL64((aOrbiterI * 135539430034462861U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10451330452898542191U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12951448817640617841U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 52U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterB, 38U)) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23432U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 19806U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 16761U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20704U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17478U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22428U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16449U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 39U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 826930775230515406U) + aNonceWordI;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 5137814617363250861U) + aNonceWordO;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + 14761561947426681616U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 60U)) + 12773023438753662590U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 7331345852207096322U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3899381212671247460U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10072004147620068599U;
            aOrbiterG = RotL64((aOrbiterG * 5663583566047763435U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3424585039401897560U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8246760141625966321U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 11478879365443736383U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 3655992860610853290U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11154618022505863898U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 4791494171286145231U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15629361991059709973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5571312349016336686U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 589313823745748879U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1356685926549786027U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 18U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + aNonceWordL) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aNonceWordB);
            aWandererG = aWandererG + (((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 29U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24654U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 31593U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 32597U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 25402U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25598U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24693U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29705U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 15549114274303128055U) + aNonceWordC;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 46U)) + RotL64(aCarry, 39U)) + 16466750056388063241U) + aNonceWordN;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 12209449840836787142U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 37U)) + 14551496099734294336U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 21U)) + 6266576428679808622U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16892841575635668152U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7375966221423362125U;
            aOrbiterE = RotL64((aOrbiterE * 15338878556107177587U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11926105302821753530U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16219253791550461124U;
            aOrbiterC = RotL64((aOrbiterC * 2117550758226173419U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 7299056065319248160U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15234001484933728439U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8182244796017018911U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 6615802589932632120U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5481176858895819247U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 3604590158551984877U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17220507586542139380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterH = RotL64((aOrbiterH * 10634645686035907603U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 18U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Billiards_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D4406AD8B51C87FULL + 0xD4A9078FC109C6E4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC89A02F4BD136743ULL + 0xFB37324C0D9A2833ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8A6185500FD1EAF1ULL + 0x92E7929328C8412FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x873F87A3061B3ED1ULL + 0xD383819E805A1C66ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEDBFE66E44EFAB97ULL + 0xF7D436C97A9D3389ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x828B69C3DA76DBCFULL + 0xEF881E2F37A765AEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEDA763CEE3ED583FULL + 0x86BDC99DB95B6C74ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x90063FA1539C9765ULL + 0xB3E857E8065B3A3FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDD7E95F7C8B57A13ULL + 0x8BE61CBD41931E42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x85BCBA2C8EE8850BULL + 0xAFCB733056971C9AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDAC5B7AA39D73FDBULL + 0xFC2DF247D7405638ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x928E740A71A28A13ULL + 0xBBBC98C49051DA4CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB4E645155502CCC5ULL + 0xB76771B9DD9C825DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEF49F53C78A3207BULL + 0x93B6318AC56267F5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCE57D676DE6360B3ULL + 0xE836CD6A4A074ADBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE2DB7F3A324CE773ULL + 0xC650F280163A4012ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 393U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 6153U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1834U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1206U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1032U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7243U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 34U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 6243113109470883144U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + 3891552123999605832U) + aNonceWordN;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 43U)) + 8758797898587019128U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 60U)) + 1005891374086408851U) + aNonceWordM;
            aOrbiterH = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 3713426782180050764U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 18358143862391573534U) + aNonceWordI;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 35U)) + 17504394029693712404U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5312729289027417014U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2560873623431186029U;
            aOrbiterI = RotL64((aOrbiterI * 16843728573219210173U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16309322822806704211U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10195513918020652600U;
            aOrbiterG = RotL64((aOrbiterG * 14569219741824123715U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2552116263258744287U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7732784879810980089U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15041929399477790999U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16499127570665381507U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10890036715535519036U;
            aOrbiterA = RotL64((aOrbiterA * 9065115450010475187U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16288944603478791554U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14542766121469312846U;
            aOrbiterB = RotL64((aOrbiterB * 8435383464425875209U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5973595239494084696U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1820492719977197097U;
            aOrbiterH = RotL64((aOrbiterH * 16164917159141304405U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 10489529555776381736U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6392552206958240484U;
            aOrbiterE = RotL64((aOrbiterE * 11761477994533503307U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterI, 10U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aNonceWordA);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterH, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererB = aWandererB + (((((RotL64(aCross, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15376U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 15753U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8438U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 13061U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15303U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13915U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13528U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 13174219512651137892U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 2715455762789269341U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 19U)) + 1338018183235594313U) + aNonceWordC;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 39U)) + 16566866551729552930U;
            aOrbiterE = (aWandererK + RotL64(aCross, 27U)) + 6901845297307236726U;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 2476078302049201718U) + aNonceWordO;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 5U)) + 15531109473927052260U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4087849380858572351U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5167830630098599644U;
            aOrbiterF = RotL64((aOrbiterF * 1982835131228146099U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7275995452428627217U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 14794340370010024117U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 8779497557416568379U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8509217403041662849U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2321522025240806996U;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5676672952755594051U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2304681269233504384U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 15731441084605554497U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8383399721062437300U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13181984036942227666U;
            aOrbiterC = RotL64((aOrbiterC * 1648761328771932069U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13602604532551684210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12725687663616352843U;
            aOrbiterJ = RotL64((aOrbiterJ * 4684699861686199753U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5831790822416009806U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4535048543735457407U;
            aOrbiterA = RotL64((aOrbiterA * 12076777878870257053U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 6U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 12U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterE, 60U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17911U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 23439U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18576U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17254U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17076U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17231U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17815U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 1364174714924216027U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 13561796874229506613U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 3U)) + 11845572344206238305U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 15762708240326773763U) + aNonceWordP;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 47U)) + 1157119665207900473U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 19U)) + 6823546624372055260U) + aNonceWordB;
            aOrbiterA = ((aWandererA + RotL64(aCross, 34U)) + 14465564210523945121U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10667464548080807531U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13445737493224316575U;
            aOrbiterB = RotL64((aOrbiterB * 12137295000900795711U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3009837893785957665U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2886920524111083752U;
            aOrbiterI = RotL64((aOrbiterI * 15308180928967762543U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10886177449328249656U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15067759884678100433U;
            aOrbiterD = RotL64((aOrbiterD * 5724566815989860041U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18307930462682331536U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8791864377579255801U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 9265158882471421767U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 805797468642992351U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5743305867058244964U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16263000753351131717U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17102025528234481273U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1841579177327486899U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3841603385577825265U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2189493507896508972U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 18209567010094914374U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3737080408976852351U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterD, 53U)) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28505U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 25570U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31245U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25897U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27876U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25647U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31992U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + 17936518874386450467U) + aNonceWordL;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 13722737841589910344U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 11774969167948715796U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 3640101505680493777U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 57U)) + 1369495382725650822U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 37U)) + 11827310354654653345U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 20U)) + RotL64(aCarry, 41U)) + 186037671377175394U) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11428829344234627340U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2275016369870029068U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 14936799202145280833U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15471646673734798328U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 12172082573115640145U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 9629417882787847753U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6626736341348283154U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12220614992483863623U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 8137086205714097487U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13157102324253760215U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4143587482368093601U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5060677690991506895U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11007575246013796426U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11721585930088637162U;
            aOrbiterH = RotL64((aOrbiterH * 15009627907125738519U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5720789204450196217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3094696226821431648U;
            aOrbiterI = RotL64((aOrbiterI * 4412033981712165541U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14675830108100986773U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9444071495289719645U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10983136361953366557U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 40U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 42U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Billiards_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9B7F655FCA209E25ULL + 0xFB4E7BDF0BDFA21DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8ADF8EE8341E77ABULL + 0x86A360F93543D20FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD64CB5433B9AC769ULL + 0x80F8A3C02132D478ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x801E9D5D484D30B7ULL + 0xFA1991857321C2AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x87E4B78689E9A041ULL + 0x84516EC3441A4879ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB59D073732B9F7D3ULL + 0xC9F00B4068FD7500ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF9C257C66746F74FULL + 0xCD11648897C2556FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCF6FDBA73461F52BULL + 0xF20FD4F9C6275C8AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB21BF101E4BB1765ULL + 0x9574272C8D29C329ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x97BCD8E2E1F035E7ULL + 0xE566014396E88100ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x93867BB1D4735E2BULL + 0xEA08A4C5E6EF2344ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBDB71AE06FF6DC69ULL + 0x85DA71A017E97174ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9864B5E9DF5E7753ULL + 0x84B97A874F29F1CDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD893A9FA9A7B478FULL + 0xB371A9B477AC0858ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAB01C6A63EB410C3ULL + 0xFF605F3847218728ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB69E55916FFD55AFULL + 0xEC0A5F6FCF6DDF62ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3938U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 3189U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 969U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5042U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((aIndex + 284U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 380024772508948442U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 7649029098162567210U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 12U)) + 5329304598870421851U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 29U)) + 12306118665045151326U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 5U)) + 960751560457324256U) + aNonceWordA;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 3244070254386191876U) + aNonceWordB;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 23U)) + 15733408571609521746U) + aNonceWordM;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17623448932647018544U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8787759896149035829U;
            aOrbiterF = RotL64((aOrbiterF * 7092515868845497573U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14741681792348288162U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8801731213568307302U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12127126999570616489U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9872248187499779222U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15407371518644528235U;
            aOrbiterC = RotL64((aOrbiterC * 1245102406469471673U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4242060317152943062U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 888649755587764533U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7296348796484458631U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15061417216070157797U;
            aOrbiterK = RotL64((aOrbiterK * 10349554676953256231U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3233185810644297433U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9241229457641024287U;
            aOrbiterH = RotL64((aOrbiterH * 2728237515724597517U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8464051359381554575U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 3307872165699029375U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 4859663401033023433U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 36U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 50U));
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 7867U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 8864U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 9837U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10556U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7673U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8542U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 8604208734152026945U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 19U)) + 1374329953253889829U) + aNonceWordO;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 51U)) + 5779278910548228339U) + aNonceWordG;
            aOrbiterA = (aWandererI + RotL64(aIngress, 60U)) + 17670451230882805140U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 37U)) + 8193848740764866860U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 15801168428145650104U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 2584718176087499066U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14950366247822737997U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9779293225265670135U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11625969538497982117U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8688968319288372383U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13665723186950342601U;
            aOrbiterH = RotL64((aOrbiterH * 292035540396910837U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9395428688359973510U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 1350324137411377992U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8729317951386057921U;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6317310451893678411U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10175620379041384281U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14079679617394330781U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1203082119358827708U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 523869107818193101U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 4629501113595689157U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4028324959540432983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15447631947468213912U;
            aOrbiterK = RotL64((aOrbiterK * 6037306615787729185U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterA, 43U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 50U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15676U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 12955U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 15223U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12051U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12763U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 11998579547770778580U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 23U)) + 8409465187298704610U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 3470222286110333500U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 5704486785203069994U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 50U)) + 10334944660253279633U) + aNonceWordJ;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 7626852700722567477U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 43U)) + 14631310754943209743U) + aNonceWordB;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 807160297237854120U) + aNonceWordK;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 5624154783624196107U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2404066593958052159U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4971444394698940423U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6340057638461027062U;
            aOrbiterF = RotL64((aOrbiterF * 12027586111086798629U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9003019862787819481U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13632057463595873033U;
            aOrbiterK = RotL64((aOrbiterK * 12575202147280216765U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12766104026871797746U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4062118445824915939U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5258212525426469978U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9956946981015983939U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8106382657040497669U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10837606223056473999U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13292864885504191134U;
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 166087925900318658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6786842221885441388U;
            aOrbiterD = RotL64((aOrbiterD * 4411147600413147773U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererC = aWandererC + (((((RotL64(aCross, 41U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 30U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16544U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 21717U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19938U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21646U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((aIndex + 19873U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (((aWandererD + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 11410829607777684449U) + aNonceWordJ;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 43U)) + 7502698839700975347U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aCross, 57U)) + 13267685058252106173U) + aNonceWordE;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 238242706996630625U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 3U)) + 8184695499511454281U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 13U)) + 12767823220461985403U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 12293198423143850330U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11149495229952495939U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7556992689338382800U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18232398462716803063U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3431338808774134649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16863099140844995099U;
            aOrbiterG = RotL64((aOrbiterG * 752376661101787919U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17872458049880677604U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16760153457252546974U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11225037229069712805U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3115544493537438408U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4359882942759752958U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13387113067202396536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12955690074544490161U;
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15614054443728226807U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1939441328066616114U;
            aOrbiterK = RotL64((aOrbiterK * 4484917074808974359U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4599016263007782537U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9962305629016158048U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 1496184427500037279U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterH, 12U));
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 37U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 24885U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneB[((aIndex + 26188U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26511U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22215U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 11450949896247900941U) + aNonceWordE;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 13U)) + 3905542253538116335U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 29U)) + 9529740545977785305U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 37U)) + 1856876631533143492U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 84253466320181686U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 12577480918745432444U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 57U)) + 5625703170397704029U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 694608607323629282U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3993981243536262204U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 2502835860198146381U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4119215953484892051U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8785040118556157146U;
            aOrbiterE = RotL64((aOrbiterE * 17113521266125471625U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16234403619456882890U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10398727475672860610U;
            aOrbiterH = RotL64((aOrbiterH * 5086871400049644715U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18327987141759096769U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2645964788056875452U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8778681366114628045U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2859452497983106129U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 7196557924940881076U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 14415389907490256711U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 930127943984174668U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15673596916054795749U;
            aOrbiterB = RotL64((aOrbiterB * 7505660488733199479U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16673140529110941163U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2258448294877833760U;
            aOrbiterJ = RotL64((aOrbiterJ * 1821550319748977445U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 46U) + aOrbiterB) + RotL64(aOrbiterE, 12U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordG);
            aWandererH = aWandererH + (((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 29U)) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 29301U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 31475U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29598U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29633U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 35U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 15904465836916519864U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 40U)) + RotL64(aCarry, 43U)) + 17725629806317789307U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 53U)) + 13794170125914914828U) + aNonceWordB;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 2149055907476874332U) + aNonceWordE;
            aOrbiterF = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 5342047776745074649U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aScatter, 29U)) + 8268148484060546838U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 11U)) + 10821151364028563719U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4294213820894407378U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10884726101307943090U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1116128870387229159U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16432210042202444824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15196602644336228055U;
            aOrbiterF = RotL64((aOrbiterF * 12680438355124070237U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14117787670220328165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 219833877949480215U;
            aOrbiterD = RotL64((aOrbiterD * 10736293047771972173U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3326396981881473962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14918513066311426279U;
            aOrbiterH = RotL64((aOrbiterH * 14269763278564574663U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11795234681370163206U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3068267285352664813U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15746255933920904619U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 245233356957999496U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 709926406353796673U;
            aOrbiterB = RotL64((aOrbiterB * 13627039596842073595U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5378105439430271038U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10114555061122044430U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 5351295043424885549U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterG, 12U));
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Billiards_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBB979628B81CF55FULL + 0xBAA7D081AAC8938DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEC219F9BAFE02F57ULL + 0x9AD580851F662F56ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA2E3508F521EC63DULL + 0xE680E5C023C014D6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEA92DA8FCA76B369ULL + 0xB862F479F51CD0F8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAE63DA0DA47EB483ULL + 0x95D99C34670AFEC3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8F220F72FEFC3BD7ULL + 0xE0FD2D2A513640FEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9E6354920FE19D23ULL + 0xFC21A19156BD16B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x990CD0EFDD6C335BULL + 0xEB029CBC15B70B57ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFFB54A3F25887D7DULL + 0xA83DAA8FC298EE4BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDDB261D55DC0FB53ULL + 0xA639D39B9BD3A63EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF40B944C6E605029ULL + 0xC7E45C6667B2E5A9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA728E9F678FA0969ULL + 0xEF4584474EB575FEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAC9A4BF585A56F61ULL + 0x93F4E74ED1005460ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x91557D1A58C54443ULL + 0x84B7648A050C46C2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8EB3258B14A550A9ULL + 0xEE1054C338748F56ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xECE5353E87752AEFULL + 0xDE417AD0D96B429DULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3949U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 6587U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5922U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 812U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1167U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1136U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 58U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 50U)) + RotL64(aCarry, 5U)) + 15188686795415908074U) + aNonceWordI;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 17310049041983079779U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 41U)) + 8246925977992441471U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 37U)) + 8644260919918112781U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 13401663736874819483U) + aNonceWordF;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 44U)) + RotL64(aCarry, 53U)) + 7940358935238314973U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 5U)) + 13278990328548007839U) + aNonceWordE;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 11U)) + 11346868298353840706U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 35U)) + 2374077904806833579U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 53U)) + 6978903378645019166U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 19U)) + 11951633297870965212U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 17398460995357409673U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1215437945597836770U;
            aOrbiterG = RotL64((aOrbiterG * 9322970054123481621U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1878751468043972239U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5343002808239712390U;
            aOrbiterK = RotL64((aOrbiterK * 11878640995447558811U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9884918450053276861U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15894599082080422550U;
            aOrbiterE = RotL64((aOrbiterE * 8359936745539546131U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13917339232771145459U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18101134009493720683U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15835859435306756387U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3830086372356903769U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15894394599564584010U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 9513921913446609263U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5127590955274245812U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9410946933309720054U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14507476989423060561U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15544384157294987085U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 998801294460434123U;
            aOrbiterB = RotL64((aOrbiterB * 5946968142746472745U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16442095194965452163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14294936349037516932U;
            aOrbiterI = RotL64((aOrbiterI * 14655345374740882581U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16680659892463349201U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10921918150041635666U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2908474941036821745U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15350264522133299871U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16413848767507968239U;
            aOrbiterA = RotL64((aOrbiterA * 10226942289998651355U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11963105565077056299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15188686795415908074U;
            aOrbiterF = RotL64((aOrbiterF * 13002484121826831091U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterA) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 44U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 22U) + aOrbiterD) + RotL64(aOrbiterF, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12365U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 9498U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 13586U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneC[((aIndex + 14012U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10275U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11914U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 15449U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 39U)) + 2168513956284366370U) + aNonceWordO;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 12U)) + RotL64(aCarry, 3U)) + 10290361969974613111U) + aNonceWordI;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 37U)) + 15673836275828498050U) + aNonceWordL;
            aOrbiterE = (aWandererB + RotL64(aScatter, 51U)) + 16600540024145812236U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 23U)) + 9428052101528111892U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 41U)) + 12763657928312763377U;
            aOrbiterK = (aWandererF + RotL64(aCross, 47U)) + 10751286982008662485U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 57U)) + 1708230173038057979U) + aNonceWordN;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 4011389705422783816U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 21U)) + 11704428328093077714U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 13U)) + 2055336619674699284U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1870865272102705804U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3574214263751923179U;
            aOrbiterA = RotL64((aOrbiterA * 13132083406834413563U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 984611970726966186U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4181398506373973169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15222345431506025949U;
            aOrbiterB = RotL64((aOrbiterB * 6925143692628659467U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15023513452326240962U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14965669361708810699U;
            aOrbiterK = RotL64((aOrbiterK * 587008860996713147U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7985755518735406360U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 225592097619240187U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2313509354133400439U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3659537916566939383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17043668033610689611U;
            aOrbiterC = RotL64((aOrbiterC * 10797634709118100773U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10217321522161675848U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 8013663869536146842U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 2293233079384777175U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13762445330867496042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2692400019659269106U;
            aOrbiterD = RotL64((aOrbiterD * 167704184292219399U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 18232551682424867647U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14785847596876239854U;
            aOrbiterE = RotL64((aOrbiterE * 4569180925037758487U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5910282247522389536U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16556038638738871204U;
            aOrbiterG = RotL64((aOrbiterG * 18356922295088260901U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 141620663839815754U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2168513956284366370U;
            aOrbiterJ = RotL64((aOrbiterJ * 8605382725635471683U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterE, 24U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 57U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 50U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 18585U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 21103U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 16482U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18251U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21189U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24156U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 17656U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 52U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 10U)) + 6069475454765660321U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 23U)) + 11483704742497268068U) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 41U)) + 11055697447388986418U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 29U)) + 10897095046039997004U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 57U)) + 4731637118230457840U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 4U)) + 13855839187084986751U) + aNonceWordL;
            aOrbiterG = (aWandererI + RotL64(aIngress, 53U)) + 5328208115460188239U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 12479538544291412985U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 35U)) + 10740165998792608231U) + aNonceWordK;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 6492798157284955373U) + aNonceWordP;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 13056825957483891921U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2068184064919194657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11193756120230763294U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 17306750816837208999U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 7949360041241439741U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12952818800389361804U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15380412293642628312U;
            aOrbiterG = RotL64((aOrbiterG * 2914662289178925547U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7706090204767242996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14598802276412649570U;
            aOrbiterK = RotL64((aOrbiterK * 4821408736292041399U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17819762117328075515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6481384240915075101U;
            aOrbiterD = RotL64((aOrbiterD * 4836701121865783029U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 754936290510338717U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15510875946573720154U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2994718968852184303U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9245381722813944586U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2629847912019726214U;
            aOrbiterA = RotL64((aOrbiterA * 6718795794951106961U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3909987749797113773U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9277056074757335265U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 11580847505996697115U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12577180954515966707U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9144513680789115458U;
            aOrbiterF = RotL64((aOrbiterF * 8880777678193004979U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1544232962956974411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2658275904714859636U;
            aOrbiterC = RotL64((aOrbiterC * 1926083316365175327U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5733515391293514025U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6069475454765660321U;
            aOrbiterE = RotL64((aOrbiterE * 9627476106108146391U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 30U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterA, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterG, 46U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26211U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 30879U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 31646U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 25353U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29603U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31108U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25886U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererD + RotL64(aCross, 3U)) + 5568146815535263910U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 7736084960873834666U) + aNonceWordI;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 1336413621817562093U) + aNonceWordH;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 46U)) + 5218462026934984692U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 23U)) + 7048890985969555935U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 19U)) + 13415955213864702118U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 5U)) + 5657023257021528548U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 57U)) + 14338310943137497116U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 36U)) + RotL64(aCarry, 11U)) + 12305161641833950473U;
            aOrbiterD = (aWandererA + RotL64(aCross, 41U)) + 14514226578370459131U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 13U)) + 12692904083266024340U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11012959130001327964U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7106471380403489078U;
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3718101961355280891U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13364192077222322664U;
            aOrbiterC = RotL64((aOrbiterC * 1411328915372590283U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6720867800318913440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14497243926965866546U;
            aOrbiterG = RotL64((aOrbiterG * 13595058589060114653U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5789056168233262435U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14438482587495779937U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 313917798940179945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3591957424821693032U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1559050939014453558U;
            aOrbiterK = RotL64((aOrbiterK * 17933346117866604725U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15340590914441451383U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5538037287390050110U;
            aOrbiterB = RotL64((aOrbiterB * 4082576643144951473U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4151270491894969214U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 263593701314144898U;
            aOrbiterI = RotL64((aOrbiterI * 10372046955804512457U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9025145270653080646U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6867950904094870056U;
            aOrbiterE = RotL64((aOrbiterE * 9975247022340627751U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3183454301841252109U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3054904157641290615U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4092317552439599475U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1768555574434776135U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 5568146815535263910U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 12466957001078663927U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 36U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterA, 41U));
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 46U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 34U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 14U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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

void TwistExpander_Billiards_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC03E4E02B97E49C3ULL + 0xB4811F45C3FDCA9DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9537EBDA4C00C279ULL + 0xA25BDE78F8F73BC7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x83BF261ECEF03DF7ULL + 0xC2EF7B71D95622EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEB7BD5B6366EF973ULL + 0xCBB07BCA2CA1BF51ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC98D1963CED7102FULL + 0xDD5F3071F8808AF0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF2837831E65EBD85ULL + 0xC19C0D5C5ADF629BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC19ACA9CEC055DFBULL + 0xC1F81302246EA39CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x90D0B7A119C1162DULL + 0xE08E5FB78790C54DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF2623DD966AA587FULL + 0xE3F0506DE2770B1EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDD940D3F734C8405ULL + 0xAFD2E687428C319AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFA0DDB6A4B157F51ULL + 0xEE942CCDB0116226ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEC8F5E878BE8CB2BULL + 0xC2E71646B33E2941ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB16E20AD8752191BULL + 0xDAF9A7EF52276735ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEAAF9E63567B3059ULL + 0xDA081670E7B8D4C5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC5C0CDF3776CC131ULL + 0x8607CD1DEE268A19ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE84AAC93D8BD2511ULL + 0xD11C8F7D9AA6330BULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1162U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 7638U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 8171U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4033U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1257U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5942U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 38U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 77518479758428414U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 57U)) + 4832061802166300011U) + aNonceWordI;
            aOrbiterH = (aWandererI + RotL64(aIngress, 46U)) + 11695291171006574112U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + 7467412817843260094U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aScatter, 29U)) + 17801484124471154757U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 5555455638503958639U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 51U)) + 5669470540733721606U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 3042388456327784163U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 42U)) + 2236734925228156691U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14459720401528685450U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4814967631216658856U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16950679344449075945U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6262238639302011050U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3522256359074996724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12524717897707074242U;
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13891759914865623828U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11910250571469028666U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 12311343917878428995U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2240189915640314069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5365912986308810837U;
            aOrbiterA = RotL64((aOrbiterA * 15133972552032469957U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9323732721344489753U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13087326560957916553U;
            aOrbiterD = RotL64((aOrbiterD * 14659491687401151733U), 39U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 16398238057564892809U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11517870519285159224U;
            aOrbiterF = RotL64((aOrbiterF * 1501848878469712681U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7758285512254776734U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17475149091906684720U;
            aOrbiterI = RotL64((aOrbiterI * 6015816725428299273U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 2051631493975035243U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11684740065349595315U;
            aOrbiterG = RotL64((aOrbiterG * 10918975496337269197U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 46U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + aNonceWordG);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterK, 6U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16282U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 11751U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13966U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8506U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12801U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9742U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11143U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 23U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 2617613537256538553U) + aNonceWordC;
            aOrbiterB = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 16642868916835132715U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 58U)) + 10860291124337073254U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 5U)) + 6432511273906902472U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 39U)) + 7505375005848241910U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 11086616004678821329U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 34U)) + 3298830587569881951U) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 19U)) + 9775143140064220979U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 23U)) + 4147601326580823120U) + aNonceWordL;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12245920269898100415U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8391940489176734499U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9119606167674098007U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17876893379544668477U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18301882058180370541U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16680384667098921309U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6869225862715140102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15404118372589259800U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 5766851935950389915U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17757381020518233814U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17677969146092374455U;
            aOrbiterG = RotL64((aOrbiterG * 3469432916562405063U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15783378556632870114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5792858258663697864U;
            aOrbiterI = RotL64((aOrbiterI * 12008981883482080427U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11737803388202260296U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16001927091970715330U;
            aOrbiterK = RotL64((aOrbiterK * 3062030309852922061U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1749586939123286632U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6169421068855905938U;
            aOrbiterC = RotL64((aOrbiterC * 12374789910763348695U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10073586820719728062U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17744171227198661555U;
            aOrbiterA = RotL64((aOrbiterA * 10658375268803957647U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1149819647337612792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7725598665625892006U;
            aOrbiterF = RotL64((aOrbiterF * 15097586655234391559U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterI, 26U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterG) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 40U) + aOrbiterK) + RotL64(aOrbiterF, 30U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19503U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 22018U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23044U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 19238U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18516U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19965U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21717U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 12206125048349568300U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + 5843520589343188818U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 28U)) + 12195046124287121687U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 16769779119214020640U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 5257603646260695833U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 41U)) + 8523523946234886745U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 19U)) + 7316024684200084096U) + aNonceWordH;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 46U)) + 11996978575084115207U) + aNonceWordO;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 53U)) + 15491711479085513628U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 6036648530996821484U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 926323222234121863U;
            aOrbiterA = RotL64((aOrbiterA * 6639661141258803779U), 53U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 2700323841295743492U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5852273765810284935U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 16665696735016345215U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11697397483133538067U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17777142964957007194U;
            aOrbiterH = RotL64((aOrbiterH * 6338967222543284999U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10892176201151170298U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11759700374509499684U;
            aOrbiterF = RotL64((aOrbiterF * 14247697264744736081U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11343756773329590643U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15785048929757652350U;
            aOrbiterJ = RotL64((aOrbiterJ * 17208103574389502597U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7508839228498497238U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13088508510402094665U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15730279447009669103U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16259236641717377699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11228995722951003980U;
            aOrbiterG = RotL64((aOrbiterG * 4870092259515181323U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13775851561528617086U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3023564646900497080U;
            aOrbiterD = RotL64((aOrbiterD * 9936548213275464131U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 154952467284609583U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14239675888632174461U;
            aOrbiterC = RotL64((aOrbiterC * 1370550680736926425U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 54U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 30U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 34U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28358U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 30237U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26722U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 25151U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29996U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28895U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28362U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 17454559218352016650U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 6U)) + 8005709669325164803U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 13393741948412816357U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 57U)) + 3665865624348875553U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 41U)) + 8334142570031883436U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 17226066128706139657U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 28U)) + 3319093033121522613U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 47U)) + 6657535603401588798U) + aNonceWordO;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 23U)) + 5469746182326331147U) + aNonceWordK;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 17846791786050221418U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15939541003714896288U;
            aOrbiterD = RotL64((aOrbiterD * 1400351482213119809U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12076763190461077406U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 3594038213596405284U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8301291631324464622U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8460406137668390582U;
            aOrbiterA = RotL64((aOrbiterA * 9117147929757711595U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7612394867020871200U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8525076134853103975U;
            aOrbiterB = RotL64((aOrbiterB * 5790440201072204659U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11929899088215090379U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7119509166360685726U;
            aOrbiterJ = RotL64((aOrbiterJ * 1662341427992528823U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5081078459225240607U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17149991983909906705U;
            aOrbiterI = RotL64((aOrbiterI * 950223374568067343U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8817303295675241994U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7962039282652745113U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12773588587795522121U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13596273086338032370U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8186297702278180956U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6226504769888753861U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1696277861691580263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17360461831507082959U;
            aOrbiterG = RotL64((aOrbiterG * 1651378456022210983U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 30U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 6U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Billiards_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9E2CB332EEB68A53ULL + 0x872376FB3939535BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x88D8F9CD9A412353ULL + 0xFAE4D13E151E57FCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x92BA70BFF5DC8065ULL + 0x8857BFD41367DCE2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCB7B7086405D80FFULL + 0xF048E1187401E3C4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAD871C1D25C8EED1ULL + 0x85053901DC5C1283ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x80E824011C0C6BCBULL + 0xF6DEF123C8880A6AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x846399C1A52B9EEDULL + 0xA25493A994254C43ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD2A52DA6D45F648BULL + 0xA07E34455F5F7D0FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xACCAF2CC96ADF7F3ULL + 0xA53599C3CEFCC99AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8DDEEAEB52A806C1ULL + 0xAAF0EED4A6E01936ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA7781171A0262021ULL + 0xCCAD20AA89B10AC3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9909897473220E13ULL + 0xB2E8BFD6179FBAEAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBACE65DEC146811BULL + 0xD80F75F786A06735ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8D87DDD88B4CF113ULL + 0xBE24E03DD64E9D5BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE069698CA27B80F3ULL + 0x9133DAD94F07623EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDC33F6926CA04B55ULL + 0x9D96738E660A9EFAULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2328U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 6183U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7968U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3641U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1341U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6254U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 38U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 23U)) + 6654158889644956636U) + aNonceWordJ;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 23U)) + 9045779659363991870U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + 3888897662136993491U) + aNonceWordB;
            aOrbiterE = ((((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 6882016842864459345U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 15601891715956172291U) + aNonceWordI;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 5U)) + 5176811598629335350U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 37U)) + 12519945150889074325U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4552583214397603278U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 14225482701804864688U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 8526052833180466359U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5485298070606280363U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11237713257388094289U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11032429223099413011U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14340345895626142788U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16275167270553643347U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 7308578867128951199U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14041860597556520250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1436068974197066343U;
            aOrbiterG = RotL64((aOrbiterG * 3938460345031496843U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11483155566419547004U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4608508534724289325U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13461385011638899485U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2389196334288832895U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4062682330273866602U;
            aOrbiterB = RotL64((aOrbiterB * 8787682133271101901U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5655656046585592034U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7977947821249746880U;
            aOrbiterC = RotL64((aOrbiterC * 10082104644185964787U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 44U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterB, 28U));
            aWandererE = aWandererE + ((((RotL64(aCross, 10U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + (((((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 51U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10656U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 10841U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 13593U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((aIndex + 10400U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13604U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13101U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14837U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 54U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 5U)) + 16200278595895089008U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 56U)) + 1029614154810465897U) + aNonceWordJ;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 7129562468705441295U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 14388903902433951274U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 1013568949315967455U) + aNonceWordH;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 29U)) + 3128823373497815651U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + 14525694606889470589U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14443983602196782887U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12244220415328641190U;
            aOrbiterB = RotL64((aOrbiterB * 15052949098014803181U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10477159225338766614U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2842870123078131566U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 11522265477555954071U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8621138818955849917U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5038396344400303181U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14636756322207385447U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2768613802894372496U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2027754864051410015U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2461322540050569287U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2848088309172056399U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15017458513904884651U;
            aOrbiterC = RotL64((aOrbiterC * 9926904679902843055U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9079797279596336139U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15424866642305110811U;
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13751764050290602740U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7694557131324740282U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14980807690491467023U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 34U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 4U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 51U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21681U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 17169U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 21255U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 23225U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19437U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 17607U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21079U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 14823268998003220191U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 15295237288788213847U;
            aOrbiterK = (aWandererB + RotL64(aCross, 19U)) + 16434853402001133899U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 7555911304407871631U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 10U)) + 14977248264994834620U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererC + RotL64(aScatter, 51U)) + 9707764144919392380U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 57U)) + 1277304385464681529U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3089786220465849395U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3700503853358695085U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2079089949442685421U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 3240054112993517371U) + aNonceWordI;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 16897532076915366859U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 4120874717534309035U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18167359289798364307U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8870819278575769863U;
            aOrbiterH = RotL64((aOrbiterH * 9334066154398059075U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15363069206212330251U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14858164441499725158U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14931933411393847915U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5357144808788707522U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2910681277417754860U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13170868582159347059U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9824408699018165151U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 368370224788793300U;
            aOrbiterD = RotL64((aOrbiterD * 14358982366258729959U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7095398304588825115U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11418879758164313554U;
            aOrbiterB = RotL64((aOrbiterB * 5983520332639771791U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterH, 47U)) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29070U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 25460U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 30589U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27090U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32193U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31295U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 31098U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 18191288703716505885U) + aNonceWordH;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 9824014524910417136U;
            aOrbiterE = (aWandererB + RotL64(aCross, 35U)) + 11953012029254917548U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 5U)) + 6297568011027199089U) + aNonceWordC;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 11U)) + 2576999400457367975U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 28U)) + RotL64(aCarry, 57U)) + 13176139160575558254U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 47U)) + 9978408174563621810U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16765834875061607142U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16534507305459121344U;
            aOrbiterE = RotL64((aOrbiterE * 8943988574248229067U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3114710944346151807U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10240517868726718592U;
            aOrbiterG = RotL64((aOrbiterG * 4645691562915606463U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10721450637990777883U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16689590768796583952U;
            aOrbiterF = RotL64((aOrbiterF * 3046344179729901637U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2427422768928450209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7058636403765106682U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9897341853944713767U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14286816859999869231U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17749559755733386064U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6582878478865838245U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2625692458813609962U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10596240255026143019U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11605800195771080135U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 50U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 50U);
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

void TwistExpander_Billiards_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x80203956C180D2B3ULL + 0xEF75705278F40D1EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8936AAF4D6D0BD95ULL + 0xD9673F958C6D8F18ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83625E9F097CA9BDULL + 0xBB7C084F8B7A70F5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF882095C71A7BD79ULL + 0xE5A6498A2CF559D2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC011999C3544C1C5ULL + 0xA874E850681E3477ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9AD0C49BC30173D3ULL + 0xFDD861E673111110ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDD5C599078AD6CDULL + 0xE025FEEA1C84BD6AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA3011F275DD8CBA3ULL + 0xA3F9B63A718DE42DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF4AE9CAC5CACE421ULL + 0xBC59940AC64151FDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD5564F2BB327F2B3ULL + 0xC99B1B7581D0E91BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD09A1E254379D179ULL + 0xB8B3CFE878F02DF8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9A765AB375FDB595ULL + 0x87C4C647E375186DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA522907E70F94535ULL + 0xB3DA59C63EC50D13ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB0AA50BB9DC531C1ULL + 0x9A2DB37E9FCEFD71ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB2374849CB81D497ULL + 0xA0674B697E77EE6DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB51A7F6971727D91ULL + 0x8197DDEF865DFC88ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2318U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[((aIndex + 1447U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2623U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 8U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 7075016829833562104U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 8783765886115517036U) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 2996723892384565829U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 14U)) + 9494134707342189476U) + aNonceWordO;
            aOrbiterA = (((aWandererI + RotL64(aCross, 35U)) + 5052642981395679904U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 8766787055127962238U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 41U)) + 4467211954388738079U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 8030255604633658608U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16962408063455702251U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 11171737929747471631U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3768222186567699076U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14930990410207899871U;
            aOrbiterI = RotL64((aOrbiterI * 10930005786146268241U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 14179761938395502502U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1879084742719898108U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5535012408925981515U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12792553516710295939U;
            aOrbiterH = RotL64((aOrbiterH * 8577530993755159329U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8979253163346099252U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5559189896063990740U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 8832485423727331621U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13937564337299044079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2393376759689394948U;
            aOrbiterA = RotL64((aOrbiterA * 2352815657830413941U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12647519563697356479U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10946871249960389549U;
            aOrbiterG = RotL64((aOrbiterG * 6272580371881237173U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + aNonceWordG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordA) + aPhaseEWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 60U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2954U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3244U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4458U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4051U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 35U)) + 12046647397183218524U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 2760779375026461991U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 51U)) + 13735454443176855650U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 29U)) + 4370377000586647724U) + aNonceWordB;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 41U)) + 14566322384189969094U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aIngress, 6U)) + RotL64(aCarry, 13U)) + 5056565959818422786U) + aNonceWordJ;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 8795403810686579209U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9625947666256011567U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1703669290934254701U;
            aOrbiterB = RotL64((aOrbiterB * 5763881345676123583U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6664070663184147951U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2104148316797553431U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 12887842067180975983U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 1197910004222596145U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9922977170060903197U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13047828062605568603U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2048376210852567829U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12568990647075931409U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15026894775772902751U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3439447160137900629U;
            aOrbiterC = RotL64((aOrbiterC * 1813754963043785165U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6532671388552829796U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17261098369835997661U;
            aOrbiterD = RotL64((aOrbiterD * 568292591215203521U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3171300991007459947U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5935563269327662024U;
            aOrbiterG = RotL64((aOrbiterG * 11271790283157765003U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 48U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 5557U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5633U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7437U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7305U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6855U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 53U)) + 2915859148137000694U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 210680583721444425U) + aNonceWordP;
            aOrbiterA = (aWandererC + RotL64(aScatter, 60U)) + 6668118118775650387U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 15794200818099010989U) + aNonceWordI;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + 6565076707062828369U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 47U)) + 16323164497808856719U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 7965435318816716560U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7390281030573369017U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2269738866911824875U;
            aOrbiterA = RotL64((aOrbiterA * 1198697877998135567U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9664014216039993873U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18284857398028357633U;
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 367667619795303009U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7935945060956274197U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16683666162337789540U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10655658270998102390U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8307037916581540297U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3247742749860703524U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15052136713218656641U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10446792483683818139U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16374602929344972364U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12599903932725787599U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2411334498322777183U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1093701164116833765U;
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterI, 20U)) + RotL64(aCarry, 57U)) + aNonceWordN) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 27U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aCross, 23U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10204U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[((aIndex + 9656U)) & W_KEY1], 30U));
            aIngress ^= (RotL64(mSource[((aIndex + 10134U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 8521U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10015U)) & W_KEY1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8942U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 35U)) + 2571116506511057880U) + aNonceWordO;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 4U)) + 13112435411509707292U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 41U)) + 10403251762787357256U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 8461951095541400405U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 9890793478557463815U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 19U)) + 3030229465991783707U;
            aOrbiterK = ((((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 7273848154043719247U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10681774862516028276U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7105082755586853104U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 12217705329504230357U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6588579345319551129U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14616333550242386092U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2934574715879306337U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15439666290229654921U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3360304356760164799U;
            aOrbiterH = RotL64((aOrbiterH * 5164191920584106237U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14438730801970761889U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14515616787452085729U;
            aOrbiterB = RotL64((aOrbiterB * 2041601927968559821U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4167853822635132419U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8950982233003320239U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 887144270884244907U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12391327853728029953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7100871010552394421U;
            aOrbiterF = RotL64((aOrbiterF * 16552349374101955967U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15381697462381887944U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6801677551341079401U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterD, 4U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + aNonceWordP) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12009U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 12927U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12290U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 11337U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13022U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12088U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13168U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 35U)) + 14179205183062705133U) + aNonceWordJ;
            aOrbiterA = (aWandererH + RotL64(aScatter, 60U)) + 210032324058740920U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 7387115089142500152U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 5U)) + 17583362781238061430U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 47U)) + 4991442849150005943U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 2891376254689854555U) + aNonceWordH;
            aOrbiterC = ((((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 10523274382407446239U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3861893764676218667U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3366674459852093746U;
            aOrbiterI = RotL64((aOrbiterI * 14005994095369483813U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5898492634386601145U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7047353571244768721U;
            aOrbiterK = RotL64((aOrbiterK * 2257518291062508467U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14374108805453186316U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8763667021501226510U;
            aOrbiterD = RotL64((aOrbiterD * 7694695426430267863U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 18261523829316379575U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 650477532238860965U;
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2162326554604894042U) + aNonceWordM;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 5776546692501825278U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 14911545784585246537U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3501863793638415049U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14853789267425352958U;
            aOrbiterA = RotL64((aOrbiterA * 10590325397179928739U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15399673014671329743U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12253428583438990426U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12052855472196447849U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 10U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterE, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordG) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aNonceWordP);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordF) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 48U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13702U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15806U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16109U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14060U)) & W_KEY1], 20U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15651U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15424U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14429U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 57U)) + 5295352595333316211U) + aNonceWordC;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 13U)) + 2341795367042042605U) + aNonceWordD;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 10122175780504033663U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 41U)) + 10084612804696198554U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 50U)) + 16470424309851045971U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 656016130975227994U) + aNonceWordI;
            aOrbiterE = ((((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 15313268829659834317U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3795220914993923394U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14044442220988813825U;
            aOrbiterI = RotL64((aOrbiterI * 3270650852546606835U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3804224626734584802U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7980006306010255693U;
            aOrbiterH = RotL64((aOrbiterH * 13958505239726088561U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13746830564584711549U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11852212099729274845U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9083223471018084847U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 13706723820703853346U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11361854103656219887U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1713819986642275223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1382000168233902914U;
            aOrbiterJ = RotL64((aOrbiterJ * 3894160765130198157U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 4540474625764565485U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1756168174375757220U;
            aOrbiterA = RotL64((aOrbiterA * 12739160208010092017U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1409297070183609309U) + aNonceWordN;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6082750101445444357U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17438740230251860935U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 20U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 54U)) + RotL64(aCarry, 23U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aNonceWordE) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19042U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 19082U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(mSource[((aIndex + 17973U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17382U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16549U)) & W_KEY1], 47U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17441U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17142U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 12U)) + 1042610313571524121U) + aNonceWordL;
            aOrbiterA = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 3505725321008825582U) + aNonceWordH;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 37U)) + 12584654563843782991U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 6645399144515770935U) + aNonceWordM;
            aOrbiterJ = ((((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 3608978423753715584U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 51U)) + 8089198857670370983U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 27U)) + 15207251813516399879U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9579268660105824516U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 16055044469473802812U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 2269649280637188723U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 583811872609805949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7027491967970873942U;
            aOrbiterJ = RotL64((aOrbiterJ * 12686754713465826139U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18256061823189677508U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterF = RotL64((aOrbiterF * 12593886633108075321U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12169216645156306078U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12694325407567795065U;
            aOrbiterG = RotL64((aOrbiterG * 3711789483877261899U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16109994660203297503U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 4234704064165718913U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 730085881474787681U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14119541943554602878U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8777769004811352951U;
            aOrbiterD = RotL64((aOrbiterD * 2556957257736134223U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15642663488392549609U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11594468530833278624U;
            aOrbiterA = RotL64((aOrbiterA * 6639306656361601143U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 46U) + aOrbiterG) + RotL64(aOrbiterD, 58U)) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 19U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aPhaseGWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19480U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((aIndex + 21269U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21295U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((aIndex + 21313U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19672U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21507U)) & W_KEY1], 54U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20040U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 20640U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 38U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererH + RotL64(aScatter, 29U)) + 13854738573712660276U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 56U)) + 16835460633412286294U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 6785859293758091931U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 23U)) + 126317283127992659U) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 7568963536291415413U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 39U)) + 12294016745653004819U) + aNonceWordC;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 18269588932920281147U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5872406424994751026U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7764434758831474129U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 3772146788188420071U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4804168969415573371U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 959601763507651280U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 4647396592804833217U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9257644462479293048U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14332699366894494579U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10487012596470786004U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 612729229562321440U;
            aOrbiterK = RotL64((aOrbiterK * 11380387280507726003U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7845523921295625315U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10294667720904610944U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14369711143154904567U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13753005602288309379U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10918344717497681894U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 11U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 50U)) + aOrbiterK) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterH, 5U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 24262U)) & S_BLOCK1], 36U) ^ RotL64(aKeyRowReadA[((aIndex + 21964U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24565U)) & W_KEY1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22578U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24169U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22061U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23664U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 22599U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 11U)) + 1297415699043177788U) + aPhaseGOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 42U)) + RotL64(aCarry, 51U)) + 17583786534509260153U) + aNonceWordI;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + 643197858925708798U) + aNonceWordA;
            aOrbiterE = (aWandererD + RotL64(aCross, 5U)) + 5062653766915694874U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 27U)) + 7034273638367180511U) + aNonceWordF;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 2026909726972916996U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 2785690475553211646U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2910341716302991892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2834181605200829791U;
            aOrbiterB = RotL64((aOrbiterB * 1510617068750957651U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 13323052600571281928U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10434901530315760460U;
            aOrbiterF = RotL64((aOrbiterF * 2042210188346767033U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 247903955625194782U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5196515747387257163U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1799024689023272275U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7196305682377987476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 10609060796540136671U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8386027207212484155U;
            aOrbiterI = RotL64((aOrbiterI * 4855610536246556893U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 729659744301903424U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2350564261412606157U;
            aOrbiterE = RotL64((aOrbiterE * 16713856782349084977U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16611987556673864177U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1525195188708550503U;
            aOrbiterH = RotL64((aOrbiterH * 10045858602151004553U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 42U);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterB, 58U)) + aOrbiterI) + aNonceWordC) + aPhaseGWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27078U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25249U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26737U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24700U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25667U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26819U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26692U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25216U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 29U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 21U)) + 1142447269198373880U;
            aOrbiterB = ((((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 10581460640040336191U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 46U)) + 14703062773878202900U) + aPhaseHOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 15737525756286914746U) + aNonceWordJ;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 29U)) + 16178774478273186999U) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aCross, 35U)) + 2514897053906809160U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 13702496607592508464U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 18030885275418337965U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5241783876161655984U;
            aOrbiterG = RotL64((aOrbiterG * 10970981186787227937U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2807052676283587925U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8022804576763271327U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11727096043219370577U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15597099852232205860U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 1538435607932096400U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 7900752511710516981U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11147868774413615365U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9325213746830411568U;
            aOrbiterJ = RotL64((aOrbiterJ * 561819005818948769U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13792300423550555634U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3134856508983945719U;
            aOrbiterA = RotL64((aOrbiterA * 4271845067763664863U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8654966018053784882U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8937113935476779267U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4135676350355234788U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11407912615743682678U;
            aOrbiterK = RotL64((aOrbiterK * 2773506587480714695U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + aNonceWordO);
            aWandererF = aWandererF + (((((RotL64(aCross, 6U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27904U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 28058U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28586U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28353U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27449U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28643U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29950U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29745U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 12380376990224645149U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 35U)) + 18296928500297384014U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + 3550626816361145100U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 2667792936946706027U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 27U)) + 12020969779370926953U) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + 737340727886903447U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 1681797651799760502U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2956186342689489064U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1876852870402977177U;
            aOrbiterB = RotL64((aOrbiterB * 8875540081346621757U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6433205819353555071U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9065076854974222998U;
            aOrbiterD = RotL64((aOrbiterD * 5459675878087242021U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3254410578766789992U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2005081975473815576U;
            aOrbiterG = RotL64((aOrbiterG * 9947701153722014085U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15992999234834560419U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3458344156815120948U;
            aOrbiterK = RotL64((aOrbiterK * 1668460113964608051U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17069783053664877727U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 1260234710193913099U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3825186451876061335U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2905344294992827535U;
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18141402347899180617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8760129857609925066U;
            aOrbiterH = RotL64((aOrbiterH * 2507999156108123047U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aNonceWordH);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordM) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31686U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31259U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31990U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31757U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32298U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32310U)) & W_KEY1], 42U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 3U)) + 13499155707765393469U) + aNonceWordK;
            aOrbiterA = (aWandererA + RotL64(aCross, 21U)) + 3740324981823726185U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 53U)) + 5470765363949735652U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 47U)) + 3446436171274452326U) + aPhaseHOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 1778929412631211933U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 14666308799855220954U) + aNonceWordN;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 4548410236791175055U) + aNonceWordE;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5829739767694190372U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14319231414903675748U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 4966501102515775601U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1513851750246111405U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1685620217748986019U;
            aOrbiterH = RotL64((aOrbiterH * 9286548037413609445U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16284162182006054402U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 6271539598462003309U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13923286694131331137U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12669312437565969473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11894755313393001665U;
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6315983824634946566U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17106616474222892782U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 167205520766791073U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13350266700180455548U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4608846311203767162U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2504857468837437365U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14195866746143604365U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7917977448256795054U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 20U)) + aOrbiterF) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordI) + aPhaseHWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Billiards_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB883EA2DB1ED9299ULL + 0xD101293C22490459ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x97BF06FAA6F8A469ULL + 0xE426351BB0AE0A77ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDB16F391201739C5ULL + 0xD8891C89204666D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCC1E4D2218DCC605ULL + 0xEDBA0F715F70B99EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE407B2A707AFA399ULL + 0xECB0970F6D66F2E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC625D7E9A2AB91DDULL + 0xC78B2524D70A5D83ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBFAB640FC46D0DB5ULL + 0xCBF417F705DAA8C1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96C57DC7542DB1D3ULL + 0xF2206A3A94B5FB8EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD3559A84799427CFULL + 0xDD579CEC4A49A39DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x82844DB5E8E08B3BULL + 0xCD158F6ACD2EBAA5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB807981934025AA5ULL + 0xF7EA48EC33403A21ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8B4FB2CC6AFA583DULL + 0xFCC765979F38ACE8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x95E36412D9D2B6D7ULL + 0xC6D47838B8EAC5C9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAF1E38764FD60367ULL + 0xEC7708CD3A400213ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x810A56016A12904DULL + 0xC01BA4BEBAAC8ED2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC5E758C641FB0919ULL + 0xD3D65504CF893821ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 410U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 871U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 223U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2650U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3722U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1879U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 53U)) + 2225397913940961213U) + aNonceWordL;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 8342544893601343643U) + aNonceWordJ;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 162922186381417187U) + aNonceWordI;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 11660218373710972210U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererD + RotL64(aCross, 40U)) + 14909034764605802354U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16776955237009701511U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 5834487809188925253U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 4458820879204327709U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1498492772767040320U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4161765458781579617U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15535994410289065281U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10511923076962447765U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8575954471692620021U;
            aOrbiterG = RotL64((aOrbiterG * 12526744988828982731U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 6536325446331340573U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1790628986900286346U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 5262997114200816715U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2623814807619278590U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11676970995834706612U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10057461115132434901U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 58U)) + aOrbiterA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + aNonceWordH) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10169U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 7114U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10221U)) & S_BLOCK1], 42U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10333U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6820U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7876U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8595U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 12U)) + (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 3238389262925516513U) + aNonceWordL;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + 12381787182611386995U) + aNonceWordK;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 7883885539305181549U;
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 1185413044597727092U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 54U)) + 15219353497204773135U) + aPhaseAOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7533774715626734082U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2599930450937763464U;
            aOrbiterG = RotL64((aOrbiterG * 13207380361960949159U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16074720663961214284U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15483613196360051221U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11717479088020532861U), 19U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 9396557867081376268U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9668459976852660245U;
            aOrbiterE = RotL64((aOrbiterE * 11748505665890567063U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 9037269914643207212U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 16936742640861088240U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16481274825758546398U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 481851372837611166U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 2225030139210599207U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + aNonceWordF) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15982U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 13320U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 12551U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16173U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13719U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 17225673071833726819U) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + 10301458382103627331U) + aNonceWordN;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 3960233050857362414U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 37U)) + 17768665685046605837U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 5U)) + 14471018461213959767U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10730597892721340453U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14863394003122760542U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17731557030589257169U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9948587274816688296U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3573569431435100993U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 2303922230056523077U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8153670675740450590U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16438856577722561424U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 4689247488336908827U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15765587867581925041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1082039522061775213U;
            aOrbiterA = RotL64((aOrbiterA * 17023740047246402641U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 4202521649260798876U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15877659681260461141U;
            aOrbiterC = RotL64((aOrbiterC * 11369910758551088173U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aCross, 4U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + aNonceWordI) + aPhaseAWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 18U)) + aOrbiterI) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18773U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 18759U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20318U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20252U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18790U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 12206125048349568300U) + aNonceWordK;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 5843520589343188818U) + aNonceWordD;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + 12195046124287121687U) + aPhaseAOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 16769779119214020640U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 22U)) + 5257603646260695833U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8523523946234886745U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7316024684200084096U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 11620083021691341337U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11996978575084115207U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15491711479085513628U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 15136690392026011819U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6036648530996821484U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 926323222234121863U;
            aOrbiterD = RotL64((aOrbiterD * 6639661141258803779U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2700323841295743492U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5852273765810284935U;
            aOrbiterK = RotL64((aOrbiterK * 16665696735016345215U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11697397483133538067U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17777142964957007194U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6338967222543284999U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 28U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 34U)) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aNonceWordN) + aPhaseAWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 53U)) + aNonceWordF) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26690U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 22483U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26654U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25646U)) & S_BLOCK1], 36U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26102U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 9855743441035905047U) + aNonceWordD;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 8426286937143990276U;
            aOrbiterF = ((((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 7146752367170267002U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererF + RotL64(aCross, 47U)) + 12947210066678101726U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 23U)) + 15902163559925328965U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8506649889346449469U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8226286036430263052U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7264199281303956141U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2703047093452420216U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6769351326360139560U;
            aOrbiterJ = RotL64((aOrbiterJ * 5318104980014706265U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9857025533281333281U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 238297452132277585U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 12974709749856065985U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7203572312072908931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12497027346166575632U;
            aOrbiterK = RotL64((aOrbiterK * 1703586436725662307U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 473851890609048879U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1664484956453886047U;
            aOrbiterA = RotL64((aOrbiterA * 8566500756326590209U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aNonceWordH);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 21U)) + aNonceWordF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 14U)) + aOrbiterF) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + aNonceWordC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30942U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 31075U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32674U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29984U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 32364U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 11450949896247900941U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 3905542253538116335U) + aNonceWordN;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 11U)) + 9529740545977785305U) + aPhaseAOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 1856876631533143492U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + 84253466320181686U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12577480918745432444U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5625703170397704029U;
            aOrbiterI = RotL64((aOrbiterI * 13583960724598036659U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 694608607323629282U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3993981243536262204U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 2502835860198146381U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 4119215953484892051U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8785040118556157146U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17113521266125471625U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16234403619456882890U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10398727475672860610U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5086871400049644715U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18327987141759096769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2645964788056875452U;
            aOrbiterD = RotL64((aOrbiterD * 8778681366114628045U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE) + aNonceWordG);
            aWandererK = aWandererK + (((((RotL64(aCross, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordH) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Billiards_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE86B3B2C3CB5EF8DULL + 0xCA36AA6E1439EE41ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF526C8FF6AB9129DULL + 0xD6B9EE749C720F2FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC86B1189DD8EE927ULL + 0x8619F71391A1031AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB79B858B8B2F90C7ULL + 0xB0F184246484E550ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9E1468D9F8A9A269ULL + 0xB72F13DE4F1DC4A3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9D743CF079924955ULL + 0xB505338A49978EB7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB9C5063A7DA57D19ULL + 0xB88812681704E5DCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x819C2205425E07A5ULL + 0xDB8D992D60A0A94BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC7E8E7168989DBD3ULL + 0xF41EA338BDBEF0E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDA0A49B9AB769B3BULL + 0xFBD847A749E51181ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x844F74469DB884B9ULL + 0x8BDD3D35C2729B6AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA58D087D0523F3B7ULL + 0xD3D2E41B325379B9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBA3835137A6F38E1ULL + 0x940B0070A7C464E9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC6C8F27987721F13ULL + 0x9F14ED18A25E6399ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x88945313192EB71FULL + 0xF89CDC40BE02C17CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDF5BF8785248A9E1ULL + 0x899C874A9DEF1F44ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3944U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 3981U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 78U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2543U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1139U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1123U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 18U)) + 1866656689936219099U) + aNonceWordJ;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 2312314528139448289U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3554037526469185237U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 23U)) + 405707755060974111U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 39U)) + 1862976326004007697U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 48U)) + 12992483065443288263U) + aPhaseBOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererH + RotL64(aScatter, 57U)) + 3793854946371595197U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 35U)) + 4244007978867369382U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 39U)) + 10280867500312580308U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 472563452959164242U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12041770406895816553U;
            aOrbiterD = RotL64((aOrbiterD * 17811798500132002631U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6118634015704900486U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13637107920449233307U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 17712028184714868053U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16673735670669318830U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8602681273646630496U;
            aOrbiterE = RotL64((aOrbiterE * 6995213887710749241U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7683264695930369476U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9146674871199188218U;
            aOrbiterI = RotL64((aOrbiterI * 7403427067419261981U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3012935612827493084U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1259789268731661945U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 2372843620327050137U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5623690455471160780U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18355567776031865462U;
            aOrbiterK = RotL64((aOrbiterK * 9553862670107886679U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7705134893833304792U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4435192506444773834U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 5249651218395299501U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6204683785806409075U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17886971535016484255U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6047216474762933535U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4430578901091376829U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 607557685798141547U;
            aOrbiterJ = RotL64((aOrbiterJ * 12342665567201483107U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 40U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordM) + aPhaseBWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 28U)) + aOrbiterE) + aNonceWordO);
            aWandererI = aWandererI + (((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aNonceWordG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 53U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 48U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11008U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 11755U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 15776U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11107U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14779U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12224U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10389U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 14823268998003220191U) + aNonceWordD;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 15295237288788213847U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 41U)) + 16434853402001133899U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 19U)) + 7555911304407871631U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererJ + RotL64(aCross, 3U)) + 14977248264994834620U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 35U)) + 9707764144919392380U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 51U)) + 1277304385464681529U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 60U)) + 3089786220465849395U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 43U)) + 3700503853358695085U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3240054112993517371U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16897532076915366859U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4120874717534309035U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18167359289798364307U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8870819278575769863U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9334066154398059075U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15363069206212330251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14858164441499725158U;
            aOrbiterI = RotL64((aOrbiterI * 14931933411393847915U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5357144808788707522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2910681277417754860U;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9824408699018165151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 368370224788793300U;
            aOrbiterH = RotL64((aOrbiterH * 14358982366258729959U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7095398304588825115U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11418879758164313554U;
            aOrbiterJ = RotL64((aOrbiterJ * 5983520332639771791U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2171599720681913272U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17593730219647495033U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 12926053208918563087U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17755947635188715523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14565740605227022106U;
            aOrbiterA = RotL64((aOrbiterA * 15866418354612945335U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14538017880915584414U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6174566474851449123U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 179569008593475683U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 4U) + RotL64(aOrbiterI, 34U)) + aOrbiterJ) + aNonceWordC) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aNonceWordG) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterA, 56U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22137U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 21299U)) & S_BLOCK1], 50U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 23142U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18144U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21203U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19203U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17129U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 39U)) + 8367680518550579791U) + aNonceWordI;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 11491674725611181241U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 10U)) + 16673861720782164214U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 9786610124108350855U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 47U)) + 5745080601557577637U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 57U)) + 1959402215131684684U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 53U)) + 6121650036079196522U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 12016309761037342392U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 14U)) + 5986936646177049603U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1000367700904043468U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17425288243569101032U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2174614006719048535U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4856917474950325209U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16312111093223166419U;
            aOrbiterE = RotL64((aOrbiterE * 11046477664487805241U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 456110002032422270U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11393724374787795662U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 1176984359123668389U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8378176867715697176U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8086186452345234815U;
            aOrbiterH = RotL64((aOrbiterH * 8450438271765985235U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8470349167474173245U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2528229938740192694U;
            aOrbiterA = RotL64((aOrbiterA * 8717790851266520943U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13247168811545753141U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8745293957516815264U;
            aOrbiterI = RotL64((aOrbiterI * 14270617180621072619U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6165915500564961987U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12015407798844173213U;
            aOrbiterD = RotL64((aOrbiterD * 3913451986559154153U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 545006684939922156U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16366753936267185001U;
            aOrbiterB = RotL64((aOrbiterB * 6495185976430013201U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3097605623436091728U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15950167830259022926U;
            aOrbiterC = RotL64((aOrbiterC * 4415538963984293323U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 6U)) + aOrbiterC) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 42U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31691U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 32089U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27390U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 29812U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29386U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30750U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 25244U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 57U)) + 15726877954695761686U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 34U)) + 14187652171881943587U) + aNonceWordH;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 8420423151313882782U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 14942322692433259283U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 47U)) + 7272331475919796255U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 51U)) + 154504365041805840U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 38U)) + RotL64(aCarry, 27U)) + 17475491222554948786U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 27U)) + 5759181483165339605U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 5993060214499322845U) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10901786237875941844U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17135786595614068473U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15923538730142047043U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5208202073886811165U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6821452921018900631U;
            aOrbiterE = RotL64((aOrbiterE * 13119330055184115669U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13348064837402206969U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8967943922403445136U;
            aOrbiterA = RotL64((aOrbiterA * 300168481725373093U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8130283784171430891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6351113882502502876U;
            aOrbiterK = RotL64((aOrbiterK * 15960622823993072903U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6894708729226455769U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12065058511247133944U;
            aOrbiterC = RotL64((aOrbiterC * 5432601727436935831U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17138279326229372741U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12987698199066890628U;
            aOrbiterF = RotL64((aOrbiterF * 12665716655177320977U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13688833537574196675U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4211971980434000618U;
            aOrbiterI = RotL64((aOrbiterI * 1374411763361518851U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10376917117582537592U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4807742522197923516U;
            aOrbiterB = RotL64((aOrbiterB * 15257251453302090961U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18038296468177121243U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6879666349379745258U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 15819475269715810555U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aPhaseBWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 46U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Billiards_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD754BA52313187D3ULL + 0x9BF4E8A5D56D69ACULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFF39C25EB4AC683BULL + 0x992ABA7296F38DC1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEFDF030B9CFA72E5ULL + 0x9176018B2EC77ABEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAFFDBD9C4BF3289BULL + 0xA950D3A76B6D5426ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8F90C19E9374EA37ULL + 0xD7EC62B10539915DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDC00BA1FB57D5D53ULL + 0xB0D8F994EFBEB4CFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA9C37D30304DA27BULL + 0xBBF8DA7DEBA64C81ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBA620A3F8C0D4157ULL + 0xB9C5F3987CDA1A4DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x97BE54F0C1662387ULL + 0xA433D577AEE23639ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAC1E310614F69E13ULL + 0xDBEE052F49FC1310ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9B0A916F08C80AC9ULL + 0x9C513D670597AFCEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA46C75B43E33A3B7ULL + 0x8B7D3A366F1EAA4BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEDFCE666DFF38DA9ULL + 0xFAE543E480AC1831ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x809CE6CAE6849FADULL + 0xFE12409DF06E7530ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB43F0F011689D5FFULL + 0x8CEA0AAB4F49E14FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x941D0E81A68DCF4FULL + 0xBCBFCEB3EBDF2915ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2013U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 1745U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2991U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3607U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1044U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2026U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 9107326720193244489U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 47U)) + 10868585484401664145U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 13637736741437846622U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 6130725216183918844U) + aNonceWordE;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 13U)) + 2063834478521338187U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 35U)) + 8564870627911949158U) + aNonceWordM;
            aOrbiterG = (aWandererD + RotL64(aIngress, 4U)) + 6524015751064086390U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9874937766875388236U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14723718409522680894U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 17379140128833323431U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13767059954741528279U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6387608251033722169U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6601902195707980693U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5391425980008431000U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11524218415655093779U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 12508457981779189389U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 155510463350385905U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10554591788433641311U;
            aOrbiterF = RotL64((aOrbiterF * 5412084824127934293U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8662160162966241542U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5092555636369853727U;
            aOrbiterG = RotL64((aOrbiterG * 433807340167635499U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7163345798448796101U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 695089002178413267U;
            aOrbiterD = RotL64((aOrbiterD * 17302689458565434475U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5409173939213468972U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15349690077393827541U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10984681254001609841U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aCross, 22U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aNonceWordO) + aPhaseDWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordP);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterF, 60U));
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6863U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 9949U)) & S_BLOCK1], 6U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7919U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneC[((aIndex + 6618U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7830U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6387U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7439U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 47U)) + 6381335981879993247U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 13U)) + 15595429101600023172U) + aNonceWordE;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 5U)) + 5449234297249826461U) + aNonceWordP;
            aOrbiterJ = ((((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 11213734849329731168U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererE + RotL64(aCross, 27U)) + 16438473952464514248U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 57U)) + 7357872882115186976U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 19U)) + 394402075160738643U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11112941985410283532U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14955125011182736212U;
            aOrbiterE = RotL64((aOrbiterE * 10711684773326395603U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14770727009821304070U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11286366598129204910U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15884310771003021989U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7358400908565425780U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15635109923749114761U;
            aOrbiterH = RotL64((aOrbiterH * 12415152149408700329U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13826842523738623579U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1072811298828325231U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 9662800288646215083U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 4017334196009350776U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8812213572751410831U;
            aOrbiterB = RotL64((aOrbiterB * 12744171921566782795U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6723457786170634403U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9785583533999417673U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7776915427605471097U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10265132640322153964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8435670887514808087U;
            aOrbiterK = RotL64((aOrbiterK * 2706263045620662131U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 12U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 19U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + aNonceWordK) + aPhaseDWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 48U)) + aPhaseDWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11664U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 14467U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13706U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11364U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 13104U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 51U)) + 14499676118633326000U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 35U)) + 17191273593018552288U;
            aOrbiterE = (aWandererH + RotL64(aCross, 29U)) + 4085176294948097737U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 5U)) + 11112671474158908186U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 18U)) + RotL64(aCarry, 57U)) + 8745787969012266485U) + aNonceWordK;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 18074049663777707948U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 2543758649719164688U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4659584749412700523U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 974639159259871273U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17918719351847605523U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9211220687971081987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8567024626862182714U;
            aOrbiterB = RotL64((aOrbiterB * 7755874089832496393U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5803002132294840900U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9470807228394903442U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1692347973120388469U;
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16510815732690193145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 755159406833096510U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14091736464659561165U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1518824876475937620U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 701225390867330446U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8425976693733003889U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7182176375442410367U;
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 28U)) + aOrbiterD) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + aNonceWordD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 22U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 19930U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 21787U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20826U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17760U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18583U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 3U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 17668251151213543491U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 19U)) + 16101602509895104517U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 9083915270773304935U) + aNonceWordN;
            aOrbiterA = ((aWandererF + RotL64(aCross, 47U)) + 12810720730318214811U) + aNonceWordO;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 26U)) + 18113428002071925621U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 1582208899354109878U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 3U)) + 4180688104819188154U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8954598189262820611U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15360094153175355879U;
            aOrbiterF = RotL64((aOrbiterF * 8177798855402983685U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8383954114668216260U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15626783326234049197U;
            aOrbiterI = RotL64((aOrbiterI * 15058420415480073793U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10609978564404958066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17656516608997517984U;
            aOrbiterC = RotL64((aOrbiterC * 4590620354119899777U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 760077259110786536U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 3597338735888033063U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 4431777844935985157U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10710423172154671296U;
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10240882795242085185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7826053487019825891U;
            aOrbiterJ = RotL64((aOrbiterJ * 15053729937684375907U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9418883403715727353U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11507423614799075545U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 16189463984557044693U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 50U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 12U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aNonceWordG) + aPhaseDWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 24195U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 26594U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26645U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23787U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23397U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 29U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 2558105147674438050U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 41U)) + 15856662514774702561U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 19U)) + 13346869226246584582U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 7632111846116243973U;
            aOrbiterG = ((((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 2102101361626976279U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 30U)) + 5605968705067851563U) + aNonceWordG;
            aOrbiterK = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 6842483186584326681U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5559797213819425064U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12422313931331576759U;
            aOrbiterC = RotL64((aOrbiterC * 7399849122565913401U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2751024420047872601U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11031320239359798610U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8607639453141148025U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14366375309473793217U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11971479429768505316U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3947595951884469542U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17882767922372770896U;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 513871456983509223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5951677013597794294U;
            aOrbiterK = RotL64((aOrbiterK * 8508629569649935293U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 437626309049021931U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 466674061172005705U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1310502572084891157U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12362602809233133718U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10525852878882195702U;
            aOrbiterE = RotL64((aOrbiterE * 17755022180514914325U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterB, 14U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + aNonceWordD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29791U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneA[((aIndex + 30918U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 30339U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32502U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29375U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((((aWandererD + RotL64(aCross, 50U)) + RotL64(aCarry, 51U)) + 439898681482066326U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 17362083676671776094U) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aScatter, 57U)) + 6418499837265155024U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 17262244253027454972U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 19U)) + 2382066162993139503U;
            aOrbiterC = (aWandererG + RotL64(aCross, 43U)) + 14345808395587174135U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 13U)) + 7534743166385552851U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16994453324688523966U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7079553728544045092U;
            aOrbiterG = RotL64((aOrbiterG * 10104892188895367489U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3562822704508440641U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13990892681975857821U;
            aOrbiterB = RotL64((aOrbiterB * 8352929306654078795U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 1796728922368577238U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6605161260520067178U;
            aOrbiterC = RotL64((aOrbiterC * 8147537646591674091U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13994083795942328918U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6144523182899107711U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 4153879991344611283U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12247462325297436642U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1065809332002012789U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5496601177032953251U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10147919864511540753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17138553441127273354U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5773875596275267871U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2653924016109573974U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6254416952351699582U;
            aOrbiterJ = RotL64((aOrbiterJ * 12756861659704947257U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 39U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererK = aWandererK + (((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Billiards_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8BAFA8198060893FULL + 0xD3F1C39265F6034BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD1FA0822016281C5ULL + 0xE335028E810A2D48ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF4CF407CE87B13FBULL + 0xDEF6B2CC255ADBE1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x85F48ECD231EA2F7ULL + 0xDB97829C4DD61777ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBFB5740C246A0459ULL + 0xEF4299E65A729BB6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB160165984A26521ULL + 0xA5A706115A9C8E0AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA605EDDAA44226EFULL + 0xF92CE481DF15A367ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC94BFF5B565D6CDULL + 0xA07A05276E8BEEDDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAE46F482D7A010F7ULL + 0xA0F2014B54E96E93ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDBCE71426906720BULL + 0xBB96300D74EE5AF9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC657882A2728F699ULL + 0xECB0C47DB84E2FD6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDEB968F21685CCF3ULL + 0xBF452620A4392508ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9B613CE4B28849F1ULL + 0xEB3004041E63C357ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x98E4E668666FC365ULL + 0xB33DCEA1CCE712A7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x82E75F0DE191935BULL + 0xA7FCFEE8FDB423CEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB6601C977C2C1113ULL + 0xD15645B0BCF689D1ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 2526U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneB[((aIndex + 233U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3738U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 666U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3492U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3988U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 24U)) + 1042610313571524121U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 3505725321008825582U) + aNonceWordP;
            aOrbiterA = ((aWandererG + RotL64(aCross, 5U)) + 12584654563843782991U) + aNonceWordG;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 11U)) + 6645399144515770935U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 37U)) + 3608978423753715584U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 39U)) + 8089198857670370983U) + aNonceWordN;
            aOrbiterK = (aWandererC + RotL64(aIngress, 54U)) + 15207251813516399879U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 35U)) + 9579268660105824516U) + aNonceWordD;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 16055044469473802812U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 29U)) + 583811872609805949U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 7027491967970873942U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18256061823189677508U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12708429127816136937U;
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12169216645156306078U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12694325407567795065U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16109994660203297503U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4234704064165718913U;
            aOrbiterK = RotL64((aOrbiterK * 730085881474787681U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14119541943554602878U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8777769004811352951U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2556957257736134223U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15642663488392549609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11594468530833278624U;
            aOrbiterB = RotL64((aOrbiterB * 6639306656361601143U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7365350535791499871U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5965170981970155956U;
            aOrbiterI = RotL64((aOrbiterI * 1898702752753066851U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9115232101451815522U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9433983580038990072U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 1951249217843992179U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8810565477444156140U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12081286530401844859U;
            aOrbiterF = RotL64((aOrbiterF * 1991383259486140229U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7498045374283306625U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13095973566401200720U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2657451581036351987U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18205793828042507364U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3339020890428651569U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 10195916881103252701U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16957913958369950483U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1042610313571524121U;
            aOrbiterH = RotL64((aOrbiterH * 11206619213970727629U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 30U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterB, 10U));
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 23U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterA, 39U)) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 60U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10630U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 7087U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 5615U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((aIndex + 7445U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9158U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6969U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 7582U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 26U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 8975885703279267062U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 13U)) + 8664844915562660637U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 11U)) + 12281774799736296726U) + aNonceWordC;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 57U)) + 15347461352311329726U;
            aOrbiterK = (aWandererH + RotL64(aCross, 35U)) + 12967500561828907834U;
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 5002833859280402726U) + aPhaseEOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 11908257536954668983U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + 17017174811949227162U) + aNonceWordO;
            aOrbiterE = (aWandererK + RotL64(aCross, 21U)) + 16851323125613931180U;
            aOrbiterD = ((((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 51U)) + 13469326957728686706U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererG + RotL64(aScatter, 27U)) + 5228638551056105241U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11945166198089308564U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16268645041872996022U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5391448793718370911U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14781204627695095701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5365325354838101092U;
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 563147416025715953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14660867395395625851U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4769458126865307103U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3168989056355712105U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16179131669773665579U;
            aOrbiterE = RotL64((aOrbiterE * 5641461617066671723U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4160220074225527179U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8597134686962559111U;
            aOrbiterD = RotL64((aOrbiterD * 639572585431474015U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16811551552456811661U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5827323970423386301U;
            aOrbiterG = RotL64((aOrbiterG * 9328247349730652021U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15583234353262170227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2950816254621717748U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 1102417597476170143U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4426165025104306337U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11871220132164971152U;
            aOrbiterA = RotL64((aOrbiterA * 2366168050042802207U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3832424136113939717U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17673885217916768611U;
            aOrbiterC = RotL64((aOrbiterC * 10887063696370811871U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3479289844909914390U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9498461576098567546U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8734492074299676555U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10645314291190544864U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8975885703279267062U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 16584086014947250551U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererA = aWandererA + ((RotL64(aIngress, 30U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 58U)) + aOrbiterA) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 36U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15024U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 10960U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15659U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11054U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 15658U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 18U)) + 15383045568644941552U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 43U)) + 17452811657750910067U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 15660117718455155603U) + aNonceWordN;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 10396441207743665753U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 3708971058200841442U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 5U)) + 7000673057768598750U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 53U)) + 9886354469011131596U) + aNonceWordI;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 58U)) + 16018065329058043467U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 41U)) + 5024756166109352320U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 23U)) + 6587818720728886652U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 39U)) + 3652672354944162319U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6307315649915348048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16405347331742979258U;
            aOrbiterC = RotL64((aOrbiterC * 7183142442906743699U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5427299664054601957U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4983381733483185898U;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10182995521328377487U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8694282877540593550U;
            aOrbiterG = RotL64((aOrbiterG * 14614602561910403893U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4085927978153269932U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6176195962815240877U;
            aOrbiterJ = RotL64((aOrbiterJ * 16792916528959579875U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6966742100601433005U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9920952446921247521U;
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11958734477518336014U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2058335903640404380U;
            aOrbiterE = RotL64((aOrbiterE * 6986170159285417789U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 77366119537297816U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12072894199692855000U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9083781120514635987U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11874297832446385377U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13715562531763053196U;
            aOrbiterH = RotL64((aOrbiterH * 12822488258322963187U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13664465415354326653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10365386643010882315U;
            aOrbiterA = RotL64((aOrbiterA * 3687934567254955761U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2003863843075564853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8864134110143237364U;
            aOrbiterB = RotL64((aOrbiterB * 4586162015675320985U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8055736412403126985U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15383045568644941552U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5175405553995854715U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 22U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 5U)) + aOrbiterA) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 46U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + aNonceWordA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18904U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneA[((aIndex + 16606U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 17211U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18423U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16580U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 26U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (aWandererH + RotL64(aScatter, 51U)) + 9220392006207660113U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 5U)) + 11305018553489132882U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + 5860373868073513684U) + aPhaseEOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 12319586170883987589U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 36U)) + RotL64(aCarry, 13U)) + 14072333614354649021U) + aNonceWordO;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 9332158529453194608U) + aNonceWordI;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 57U)) + 3860569321145958686U) + aNonceWordE;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 8119005668901240093U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 38U)) + 13918259792880333239U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 6938856216758228704U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 27U)) + 3960905839118710604U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6043879193734253929U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15691425268831319195U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 7189195135654636271U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14912209933584715274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16180183395910618923U;
            aOrbiterJ = RotL64((aOrbiterJ * 3942858974766467849U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4966642362507707776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6962226782462822861U;
            aOrbiterC = RotL64((aOrbiterC * 3647802407741095419U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12409120845092026295U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2302946450253872465U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7099576330777297911U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16118304388937163838U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15968419034359049422U;
            aOrbiterE = RotL64((aOrbiterE * 11736207775827080165U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17098982091525008231U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10298979200690822062U;
            aOrbiterG = RotL64((aOrbiterG * 12620028874653521945U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 552826643694256437U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11786560990790695378U;
            aOrbiterB = RotL64((aOrbiterB * 11190309640069208311U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13730399230389329793U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17614226859252305432U;
            aOrbiterH = RotL64((aOrbiterH * 2640019643570222977U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1062738267846296283U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13959480457644980835U;
            aOrbiterA = RotL64((aOrbiterA * 1194145909157002977U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4635071137794189167U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13374502212707796180U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 129680788767298945U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11479902881487238033U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9220392006207660113U;
            aOrbiterI = RotL64((aOrbiterI * 1437457810224888809U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 54U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 60U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23648U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 26091U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 25551U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25932U)) & S_BLOCK1], 18U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26065U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererE + RotL64(aCross, 48U)) + 13333509828310369865U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 57U)) + 7645352517103840797U) + aNonceWordB;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 5310766306660062655U) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 37U)) + 5165635069832352932U) + aPhaseEOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 3U)) + 15684141764734281849U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 19U)) + 3327963374225061738U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 8625811794878848871U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 7598657468430485291U) + aNonceWordK;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + 2881171216276746485U) + aPhaseEOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 5U)) + 10237691227222918101U) + aNonceWordJ;
            aOrbiterF = (aWandererI + RotL64(aCross, 46U)) + 6419254255884834497U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 4238455444646479956U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14936613353493061492U;
            aOrbiterE = RotL64((aOrbiterE * 3544216916806292273U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15324699725208372627U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9506640480601832011U;
            aOrbiterI = RotL64((aOrbiterI * 12819564111348390227U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3709149613660215641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1724290199312754307U;
            aOrbiterK = RotL64((aOrbiterK * 12597580418257897965U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13191172833570139194U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3686087945377837886U;
            aOrbiterD = RotL64((aOrbiterD * 10883609557429936283U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10418330386245397022U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5383531313632347245U;
            aOrbiterF = RotL64((aOrbiterF * 2987755379396160073U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7414716553072652212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11301761123966206201U;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 8570229732236388847U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8773754460060264773U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 3251360788932563495U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13636929800504199371U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5486599841558573720U;
            aOrbiterC = RotL64((aOrbiterC * 2867914211589815153U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13277541451512422776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10409779509190185921U;
            aOrbiterB = RotL64((aOrbiterB * 1926650154570961573U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7268295836403414306U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13815969853235433830U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 11603750346752441535U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9353249174240162324U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13333509828310369865U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10381405217943841655U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 56U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + aNonceWordN) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterK, 60U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29205U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 32103U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30603U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32445U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29073U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 19U)) + 12222235191147985484U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 21U)) + 16367317014523328414U;
            aOrbiterG = (aWandererG + RotL64(aCross, 24U)) + 3511378091284703789U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 57U)) + 15247492830966725949U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + 7745995913390407897U) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 6463593307540108810U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 41U)) + 1101669311005268630U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 12988052764067518580U) + aNonceWordI;
            aOrbiterA = ((aWandererA + RotL64(aCross, 27U)) + 17717179747434679772U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 43U)) + 11662190906682400416U) + aNonceWordA;
            aOrbiterF = (aWandererH + RotL64(aScatter, 39U)) + 6563014073547628748U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13099094932059419219U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16342730862261868847U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16855346813127524624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6570063128502306944U;
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11328352033809240501U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11640986648833160901U;
            aOrbiterB = RotL64((aOrbiterB * 2895830492089678919U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2675226158571501666U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17700531248266458165U;
            aOrbiterK = RotL64((aOrbiterK * 2231403813970188657U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7729597396731910874U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15172374484412053756U;
            aOrbiterE = RotL64((aOrbiterE * 149009041406406517U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9178769489257842683U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9020154972097834926U;
            aOrbiterD = RotL64((aOrbiterD * 8910504667566521429U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1317403761217790562U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17151528554929201571U;
            aOrbiterH = RotL64((aOrbiterH * 3735945655450625203U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11621882033959669977U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10289504450815075623U;
            aOrbiterA = RotL64((aOrbiterA * 13365982786836243195U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16178772981106335703U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16896130772325866910U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6993524735412868965U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9573223644675562575U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17552463713786507189U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 16103431656424881779U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4801852246698369631U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12222235191147985484U;
            aOrbiterI = RotL64((aOrbiterI * 2835204872125428065U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterI, 60U)) + aNonceWordC) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 28U) + aOrbiterJ) + RotL64(aOrbiterH, 14U));
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_Billiards_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6F75948CF01AB1DULL + 0x8F6D4207A1813A9CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9BC6AC94ADEE785DULL + 0xC8DB25668974A651ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xACC516EA30DA3F85ULL + 0xE8376EBBE35CDC74ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD3544A6AE6C920F7ULL + 0x9E08622686268397ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x95C9C6A54625957DULL + 0xA5A6F1C76E4897CCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAF433316F3F6A715ULL + 0xBE5B4601A5D92232ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8C09953551A22CD1ULL + 0x912BE8889FAC5944ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF96D4E2A0F7FF145ULL + 0xF1B09411A2A06DF4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x86F795373263E515ULL + 0xF13D68217AA5D368ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBAB03D8C2DEC0671ULL + 0xF83C836B11242B19ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE70F0F4477A6AE9BULL + 0xA63D10F81894A6CBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC725FC36B0FE95B7ULL + 0x9B7398680DB29603ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFA8E3ED8F4805945ULL + 0xDD3156A5213672D8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF05F4F014CDC879DULL + 0xF33A768B53904F26ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x892E0EA2D04E1E2DULL + 0xD378CCA3AECE1FA2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEE58E26F95A3C879ULL + 0x85FF506CA10CA347ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3040U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 1741U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2242U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1707U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 64U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4657U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 6U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 47U)) + 12426357877879529292U) + aNonceWordN;
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 12604900366173639176U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 21U)) + 13511119007338929401U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 36U)) + 9878720081166788060U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 15463195409806395076U) + aNonceWordM;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 27U)) + 6407922778852833423U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 7690427254160734016U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 57U)) + 18030974031722143619U) + aNonceWordJ;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 40U)) + 17983938038322737041U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16605512170117753884U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 681802273302348322U;
            aOrbiterE = RotL64((aOrbiterE * 14608920184802647123U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15550312921312083819U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17824154101711884508U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1939207786756735430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3132864634777826569U;
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 12822929773923954849U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16576106045887115660U;
            aOrbiterK = RotL64((aOrbiterK * 16370914370769903051U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2398825881649235260U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13700821892926092479U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10830623703416956043U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2439833784883391606U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15870638514107637833U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9165457123134229670U) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8736642509192659417U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 16219277537523484065U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9232719746484835693U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7826680628853322541U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 12578050118133526187U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14323652326982518782U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2254524512851399313U;
            aOrbiterF = RotL64((aOrbiterF * 4119339547645451149U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 30U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 14U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterF, 39U)) + aNonceWordH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9211U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 8335U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8702U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((aIndex + 6049U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6040U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10742U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9559U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererK + RotL64(aCross, 30U)) + 7825479804710770560U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererI + RotL64(aScatter, 5U)) + 5298124167101358123U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 13U)) + 17774541024369233726U) + aNonceWordF;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 23U)) + 7679371833537454082U;
            aOrbiterC = (aWandererA + RotL64(aCross, 53U)) + 5385914900748772224U;
            aOrbiterF = ((((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 3879781930908486531U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 58U)) + 659110346638873236U) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 10749021728538539749U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 3631252455767429457U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2271978810960685021U) + aNonceWordC;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 5963558780692551176U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 4772055335210781149U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 974909966119198104U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9296998242911152296U;
            aOrbiterF = RotL64((aOrbiterF * 2613629915877957661U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2245318466901521959U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13391076374843288568U;
            aOrbiterK = RotL64((aOrbiterK * 18094558036982107419U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6184487746594236737U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1563385912137291418U;
            aOrbiterG = RotL64((aOrbiterG * 4805455299959232321U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1744840092006498629U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2100927276837188416U;
            aOrbiterA = RotL64((aOrbiterA * 3541788262067077997U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9998911862807246338U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12239948725635220096U;
            aOrbiterD = RotL64((aOrbiterD * 7098620484129489129U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3307447094994950246U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12746613971448298932U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 9463975886346934681U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11577488293733790649U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 191108997585598809U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9574978681405356871U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18096145693841273722U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10026281133603934071U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17261343107314203471U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 34U)) + aOrbiterF) + aNonceWordM) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 4U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterF) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 52U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12035U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 11937U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 16168U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12880U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 14781U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 1142447269198373880U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 34U)) + 10581460640040336191U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 27U)) + 14703062773878202900U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 19U)) + 15737525756286914746U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererG + RotL64(aIngress, 43U)) + 16178774478273186999U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 2514897053906809160U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 47U)) + 13702496607592508464U) + aNonceWordJ;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 10U)) + RotL64(aCarry, 47U)) + 18030885275418337965U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 5U)) + 5241783876161655984U) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2807052676283587925U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8022804576763271327U;
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15597099852232205860U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1538435607932096400U;
            aOrbiterH = RotL64((aOrbiterH * 7900752511710516981U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11147868774413615365U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9325213746830411568U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13792300423550555634U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3134856508983945719U;
            aOrbiterF = RotL64((aOrbiterF * 4271845067763664863U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8654966018053784882U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8937113935476779267U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7386875687217705855U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 4135676350355234788U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11407912615743682678U;
            aOrbiterI = RotL64((aOrbiterI * 2773506587480714695U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10966950663872392059U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6686634993700944582U;
            aOrbiterE = RotL64((aOrbiterE * 2509459942163678241U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14154407529749257990U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18054640398549782388U;
            aOrbiterA = RotL64((aOrbiterA * 7830759861389060149U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14623473030642960240U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1857945571104460086U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 18039903315045620079U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 37U)) + aNonceWordB);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 4U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 52U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 14U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20476U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 20600U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17942U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17099U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 17460U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 14U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 701291026547470433U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 28U)) + RotL64(aCarry, 57U)) + 17283292650462111643U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 9969124091931303406U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + 889176772718046988U) + aNonceWordE;
            aOrbiterD = ((aWandererF + RotL64(aCross, 23U)) + 6054541844643748084U) + aNonceWordL;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 12U)) + 14703226235143028132U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 43U)) + 7977975878522921062U) + aNonceWordK;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 16894322614172266274U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + 12160451749345900570U) + aNonceWordB;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10870847008043897470U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8159920947172520247U;
            aOrbiterC = RotL64((aOrbiterC * 4833194641611011805U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 2440099120969517932U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2428396147731468007U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9363073341539598441U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2213226274394673479U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7079731443427765333U;
            aOrbiterD = RotL64((aOrbiterD * 16918930776877030559U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 958896789550478970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10788682955708075458U;
            aOrbiterG = RotL64((aOrbiterG * 913321215613559729U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2003386579317564870U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8419686358774204999U;
            aOrbiterE = RotL64((aOrbiterE * 6547052526438697621U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6989167615157578904U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17636634003643824148U;
            aOrbiterF = RotL64((aOrbiterF * 11038576417283732937U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13824962118933907859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9543912892587859646U;
            aOrbiterK = RotL64((aOrbiterK * 14736710162285997415U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15729878041027706114U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9542137475454825463U;
            aOrbiterA = RotL64((aOrbiterA * 11420547128115090491U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5327302277575009955U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2707383132257428583U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6120763309390182129U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 34U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 38U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 38U) + aOrbiterH) + RotL64(aOrbiterG, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23582U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((aIndex + 23927U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23820U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23495U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((aIndex + 25140U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 52U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 39U)) + 7722279280863371124U) + aNonceWordN;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 11584220561732385598U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 5U)) + 7834679350105534657U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 57U)) + 11347994382444180879U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 53U)) + 9449903188047063431U) + aNonceWordC;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 6516243976652795170U) + aNonceWordK;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 44U)) + 8420815253991184777U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 9081386852515170937U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 3U)) + 14375955191735286867U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 880757589768436072U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3349856625725164229U;
            aOrbiterH = RotL64((aOrbiterH * 681514212582331781U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7826309957607577207U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8057435761214313635U;
            aOrbiterD = RotL64((aOrbiterD * 4718430712767038607U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9565237500443303103U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15893066735310588501U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 8457633439171452397U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3276844534476430842U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6828644383891274120U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 979580351653410157U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2815676923011504251U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5030251870850928417U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7075653570570819253U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13464083008377887034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8994560761846897590U;
            aOrbiterK = RotL64((aOrbiterK * 9892839554658865143U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8398813387154468736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8136429428340910892U;
            aOrbiterI = RotL64((aOrbiterI * 3348811490733577295U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 418587250696862341U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4111667833838312094U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 860949442143849147U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6075478294190926371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2208124955874142264U;
            aOrbiterB = RotL64((aOrbiterB * 15741988616251072075U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 10U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterB, 4U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterE, 24U)) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 51U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32120U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 31416U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 28667U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32712U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 29162U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 37U)) + 964165145848253292U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 4U)) + 10645976767204934746U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 51U)) + 8241612229349212650U) + aNonceWordL;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 4159196033256913347U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 7194795864620233507U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + 7638928444536778384U) + aNonceWordO;
            aOrbiterE = ((((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 11819105916503968109U) + aPhaseFOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 57U)) + 18052213302858186237U) + aNonceWordF;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 46U)) + RotL64(aCarry, 43U)) + 8663575313970041570U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 16644136720439299786U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16930316530442679864U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2650922074098320859U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16251107616988250593U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7171986193609401665U;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17885046834432626644U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7757069274715713557U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15766885299397923879U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2212805322061155615U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6368539134638838822U;
            aOrbiterG = RotL64((aOrbiterG * 13383744883433594259U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5264326094252925613U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6126345334815012938U;
            aOrbiterC = RotL64((aOrbiterC * 17180934809764905307U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13826731214018407061U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6621261811613643620U;
            aOrbiterE = RotL64((aOrbiterE * 2823596473596114171U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5964406317285863781U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2167324450276308078U;
            aOrbiterJ = RotL64((aOrbiterJ * 1098346374733634905U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16740710162977859724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8236083581048717923U;
            aOrbiterB = RotL64((aOrbiterB * 4364887787000704039U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13967473987446124012U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5136051802217149813U;
            aOrbiterH = RotL64((aOrbiterH * 13997246005108872883U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 34U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterD, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 40U) + aOrbiterG) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + aNonceWordH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Billiards_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF4EBBB87DE857FFBULL + 0xFEEDE421F9E90153ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB562B05CFF68B50DULL + 0xA524ABEC59CFFBDDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA1F96AFDBD5FA24BULL + 0xBB5365A4F691062BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE67F6DE3762AD21DULL + 0x9303C7E479A31185ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF0AC81FC87231BA5ULL + 0xA4CCB0C6651E0F71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC709417DD88DB551ULL + 0x9C81AE769E919991ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8227BA4CABC56775ULL + 0xFD803CF4529A1C20ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDC26D10940798625ULL + 0x889AE53131647C12ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x90D7B95C4DEEDB53ULL + 0x8FAF235C3A6E5440ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8302CA599E0A3551ULL + 0xEA5C42328A27FDB9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x83CC35275DB24EABULL + 0xC26B95DD01B78E77ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA3503C1736CC5FE1ULL + 0xFD622A990AB392CFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEBE6F70797FD6735ULL + 0x87399263320FCAB8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBB71A8F016D687E7ULL + 0xF8C9DA9ABC765251ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF2A0A5CFBF84DAFBULL + 0xF25C78D8CACC8D68ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9A4349E19BC4E155ULL + 0x8567F01D70BB5BE2ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3956U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 375U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2193U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1522U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4184U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 822U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 1142447269198373880U) + aPhaseHOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 60U)) + 10581460640040336191U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 14703062773878202900U) + aNonceWordL;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 15737525756286914746U) + aNonceWordP;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 16178774478273186999U;
            aOrbiterH = (aWandererK + RotL64(aCross, 37U)) + 2514897053906809160U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 19U)) + 13702496607592508464U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18030885275418337965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5241783876161655984U;
            aOrbiterD = RotL64((aOrbiterD * 10970981186787227937U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2807052676283587925U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8022804576763271327U;
            aOrbiterB = RotL64((aOrbiterB * 11727096043219370577U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15597099852232205860U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1538435607932096400U;
            aOrbiterC = RotL64((aOrbiterC * 7900752511710516981U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11147868774413615365U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 9325213746830411568U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13792300423550555634U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 3134856508983945719U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 4271845067763664863U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8654966018053784882U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8937113935476779267U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7386875687217705855U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4135676350355234788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11407912615743682678U;
            aOrbiterE = RotL64((aOrbiterE * 2773506587480714695U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 24U) + aOrbiterC) + RotL64(aOrbiterD, 18U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterB) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + aNonceWordK) + aPhaseHWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8432U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 8910U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10477U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((aIndex + 7158U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7763U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7695U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 6047U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 17081642665820489793U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 35U)) + 14468854040067229623U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 5U)) + 2249450222593057429U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 14964389079511378664U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 17003491054252360650U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 14U)) + 12710882240582032588U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 9887078182156755359U) + aNonceWordF;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7665284531810584704U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7304284015511876717U;
            aOrbiterD = RotL64((aOrbiterD * 6193179739025093929U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 5517927023543751734U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17704756310857362759U;
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11347400363019508578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11696395232760991243U;
            aOrbiterC = RotL64((aOrbiterC * 9725231749679442003U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10875780291242873583U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7808740614343437672U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 3145390996141902032U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16080636485642732615U;
            aOrbiterG = RotL64((aOrbiterG * 7445756373012217305U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 3929263288176983844U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18210228766683996806U;
            aOrbiterJ = RotL64((aOrbiterJ * 13178080076505449091U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13948962323541421431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3037683309790156893U;
            aOrbiterF = RotL64((aOrbiterF * 13406672352222636739U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 12U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13794U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((aIndex + 11574U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 12068U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16323U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneC[((aIndex + 12388U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 48U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 14U)) + 18191288703716505885U) + aNonceWordK;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 5U)) + 9824014524910417136U) + aNonceWordJ;
            aOrbiterG = (aWandererG + RotL64(aIngress, 47U)) + 11953012029254917548U;
            aOrbiterD = ((((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 6297568011027199089U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 2576999400457367975U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 27U)) + 13176139160575558254U) + aNonceWordP;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 9978408174563621810U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16765834875061607142U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 16534507305459121344U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8943988574248229067U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3114710944346151807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 10240517868726718592U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 4645691562915606463U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10721450637990777883U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16689590768796583952U;
            aOrbiterK = RotL64((aOrbiterK * 3046344179729901637U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2427422768928450209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13495584061816457831U;
            aOrbiterJ = RotL64((aOrbiterJ * 6670984773768885119U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7058636403765106682U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9897341853944713767U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14286816859999869231U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17749559755733386064U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12515645083926326659U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 6582878478865838245U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2625692458813609962U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10596240255026143019U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 11605800195771080135U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 44U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterD, 56U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17124U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 21121U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 19943U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16809U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((aIndex + 20242U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 5160910997561396461U) + aNonceWordE;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 14920764751058512062U) + aNonceWordI;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 19U)) + 6080952401749660022U) + aPhaseHOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 35U)) + 17667234330526298627U) + aNonceWordC;
            aOrbiterB = (aWandererA + RotL64(aIngress, 57U)) + 760630072638686756U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 12U)) + 3504157162816997476U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 9489022223422585882U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1149898536879968964U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10492284328940025310U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7893416766300156495U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13213275606286399312U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10557118912847180413U;
            aOrbiterB = RotL64((aOrbiterB * 10077877991284587845U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15618980209023994776U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5268600749854045564U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3849660559223919613U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8011552687609649990U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3148133096349525066U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 5245156554959620007U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12032847944237867285U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14999005703490824673U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6631584955208646049U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5426735969392906710U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3593177531650386729U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12997284886192717043U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1701444719333347373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15928731228196894960U;
            aOrbiterI = RotL64((aOrbiterI * 1919318226904213433U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterD) + aNonceWordA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 6U)) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 38U) + aOrbiterK) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25910U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 23578U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25889U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26937U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23422U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 47U)) + 2672739400294801233U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 41U)) + 8475624545015101850U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + 1252755112289831257U) + aNonceWordG;
            aOrbiterA = ((aWandererI + RotL64(aCross, 5U)) + 7938039507649183387U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 3U)) + 8167413146948861022U) + aNonceWordC;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 17712313989694374353U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 7637042279892596975U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15770412950033467341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3951812021898608685U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6623127125223204737U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8656983621098246507U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17943342344730687317U;
            aOrbiterJ = RotL64((aOrbiterJ * 16495519451034883813U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 3087677463651608668U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7750923317452683057U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2185924841611106546U;
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14676868738946722416U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6849098251696302393U;
            aOrbiterC = RotL64((aOrbiterC * 2599806275837778069U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17817755047153606419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9900465270314068757U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9267925873983176685U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11380000891112113701U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15930503831156546113U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14450535035065393845U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterI, 54U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32394U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30500U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28215U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31894U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneB[((aIndex + 31639U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 48U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + 8767379393098711499U) + aNonceWordO;
            aOrbiterJ = (aWandererH + RotL64(aCross, 57U)) + 7168159491580816433U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 9879279829061883406U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 5U)) + 10537167136053399303U;
            aOrbiterB = ((((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 2839070018069188936U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 13844278063968429732U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 20U)) + 11278946626186474646U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11798425216660557799U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7618446090703335192U;
            aOrbiterE = RotL64((aOrbiterE * 7168757300685156779U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 695423597006983660U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 14344728202803488813U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5168825904902285909U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 11656100506575697086U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10384358779985773937U;
            aOrbiterB = RotL64((aOrbiterB * 247494692039140973U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17585001605131977341U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9964478171465522911U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 13484044854790175315U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2710943171829692624U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17809072853457153057U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16341884203303271365U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12814092033910687774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1743186323268668740U;
            aOrbiterG = RotL64((aOrbiterG * 11150822630624332557U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10750472346626754704U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15925901217078035356U;
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterC, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Billiards_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2479U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 863U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2599U)) & W_KEY1], 39U) ^ RotL64(mSource[((aIndex + 2020U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 14U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 47U)) + 6469584119078165548U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 4U)) + 14329756366517987910U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 12890831797059772123U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + 3164503807500018990U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 177531431387646836U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 3167421392893561015U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 2813174781844753460U;
            aOrbiterF = (aWandererI + RotL64(aCross, 57U)) + 10953270419153249857U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 52U)) + 16911518309710356951U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6616750447844893150U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10276741398025985982U;
            aOrbiterK = RotL64((aOrbiterK * 6824712685896987133U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6206043608461213208U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12021552904553405793U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 15283586234744144846U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterE = RotL64((aOrbiterE * 8200882393521882651U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11044014510971660078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9351141024085076044U;
            aOrbiterD = RotL64((aOrbiterD * 13316079344614432317U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17703395981862992420U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10154548848376027087U;
            aOrbiterC = RotL64((aOrbiterC * 12324478347590509035U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8836420852291617425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10193385413543886344U;
            aOrbiterA = RotL64((aOrbiterA * 824935982418585449U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8248580084535685190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3910083671888152974U;
            aOrbiterG = RotL64((aOrbiterG * 17825311776715895927U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12350341628569930642U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2565977481575002842U;
            aOrbiterF = RotL64((aOrbiterF * 18233446879833776677U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9271041067874027417U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14289254596554201861U;
            aOrbiterH = RotL64((aOrbiterH * 7985522692852251413U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 28U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 60U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 26U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2924U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4301U)) & W_KEY1], 10U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3484U)) & W_KEY1], 12U) ^ RotL64(mSource[((aIndex + 4617U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + 439898681482066326U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 17362083676671776094U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 6418499837265155024U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 47U)) + 17262244253027454972U;
            aOrbiterG = (aWandererK + RotL64(aCross, 38U)) + 2382066162993139503U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 23U)) + 14345808395587174135U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 51U)) + 7534743166385552851U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 27U)) + 16994453324688523966U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 7079553728544045092U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3562822704508440641U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13990892681975857821U;
            aOrbiterB = RotL64((aOrbiterB * 8352929306654078795U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1796728922368577238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6605161260520067178U;
            aOrbiterD = RotL64((aOrbiterD * 8147537646591674091U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13994083795942328918U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6144523182899107711U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4153879991344611283U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12247462325297436642U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1065809332002012789U;
            aOrbiterG = RotL64((aOrbiterG * 5496601177032953251U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10147919864511540753U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17138553441127273354U;
            aOrbiterC = RotL64((aOrbiterC * 5773875596275267871U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2653924016109573974U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6254416952351699582U;
            aOrbiterH = RotL64((aOrbiterH * 12756861659704947257U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 813046408080197079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9624466135414123483U;
            aOrbiterF = RotL64((aOrbiterF * 6960320253124395015U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 972586705850825744U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 155283774901960223U;
            aOrbiterK = RotL64((aOrbiterK * 9928051687724257041U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18200100644751360406U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1168426822045686004U;
            aOrbiterA = RotL64((aOrbiterA * 5867027156069481313U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 18U)) + aPhaseAWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 10U));
            aWandererC = aWandererC + (((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7909U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[((aIndex + 7247U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5762U)) & W_KEY1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8113U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 7374U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 13U)) + (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 51U)) + 15549114274303128055U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 38U)) + RotL64(aCarry, 19U)) + 16466750056388063241U) + aPhaseAOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 12209449840836787142U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 43U)) + 14551496099734294336U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 13U)) + 6266576428679808622U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 3U)) + 16892841575635668152U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 58U)) + 7375966221423362125U) + aPhaseAOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 11926105302821753530U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 29U)) + 16219253791550461124U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7299056065319248160U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15234001484933728439U;
            aOrbiterG = RotL64((aOrbiterG * 8182244796017018911U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6615802589932632120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5481176858895819247U;
            aOrbiterC = RotL64((aOrbiterC * 3604590158551984877U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17220507586542139380U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterE = RotL64((aOrbiterE * 10634645686035907603U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16981960446540932787U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10897565927079518588U;
            aOrbiterJ = RotL64((aOrbiterJ * 418843936329303571U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2746889569299593263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4894117146736361379U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2656750612042673191U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18294823016957137777U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 86828501068883383U;
            aOrbiterB = RotL64((aOrbiterB * 11432686669235402365U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6322053762209547826U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6754524552483363820U;
            aOrbiterF = RotL64((aOrbiterF * 1746163087826694641U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7306452650619361017U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12717201204443785828U;
            aOrbiterA = RotL64((aOrbiterA * 6121251603905574991U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10422327053543898585U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14786413282036348183U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8713024293107068275U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 14U) + aOrbiterJ) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 41U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterG, 51U));
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterJ, 30U)) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 10691U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadB[((aIndex + 9558U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(mSource[((aIndex + 9710U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8273U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9353U)) & W_KEY1], 26U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8340U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 44U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 12583180859826261500U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 3U)) + 9067093488553721468U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 12173106198862881754U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 14U)) + 11333491014394592654U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 27U)) + 3511883526940919554U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 7416810692106273044U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 43U)) + 8341174972619784110U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 18U)) + 2220852854836962979U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 51U)) + 8090781422229383825U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2338801236599102223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12484514711848308104U;
            aOrbiterD = RotL64((aOrbiterD * 10364216764253366067U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13684861340589131816U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12796636819991873058U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5533508014234835669U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7634198650894837690U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10240326122201201762U;
            aOrbiterE = RotL64((aOrbiterE * 8758703497719125901U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4162814763739453934U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2766504649149048469U;
            aOrbiterI = RotL64((aOrbiterI * 16731843453895178671U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11051393030148769655U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17687055068651386665U;
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3353615315436983420U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5971640796220306310U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15804313508835034807U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12299773092762384765U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7435804907797063411U;
            aOrbiterC = RotL64((aOrbiterC * 9848139805288165965U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8735783937125735699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11903126115475835615U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16942088822124940265U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4427166023462475475U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6011733469446008137U;
            aOrbiterK = RotL64((aOrbiterK * 17298067225913923517U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 60U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 3U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 20U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11466U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 11101U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13079U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11253U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11453U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12143U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12719U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 30U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 37U)) + 9446153639709651566U) + aPhaseBOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 29U)) + 10550762260670758167U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 7062634922142578383U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 41U)) + 9178499097812764515U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 53U)) + 6887103379773525538U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 6239750312052010257U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 36U)) + 17645022614523287959U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 3639618183259408272U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 3131737117548745095U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7253994382396406554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15217993711938379561U;
            aOrbiterG = RotL64((aOrbiterG * 17853313384747259923U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12594152227603630033U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11250170200489647869U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12936942656624279424U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10990736056052106149U;
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12787293075893090465U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17154990205620778151U;
            aOrbiterH = RotL64((aOrbiterH * 10031369940028159521U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1270827262969060301U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17337623431665013136U;
            aOrbiterJ = RotL64((aOrbiterJ * 1517262088236356107U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 830330490987911853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6828309232554560547U;
            aOrbiterK = RotL64((aOrbiterK * 9742464176986145819U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11470087853413986203U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10470148870747884420U;
            aOrbiterB = RotL64((aOrbiterB * 6766079738799967443U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18315536891901859637U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12264670822285914271U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5841574505408674119U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10931842095884524879U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11134871340959676257U;
            aOrbiterI = RotL64((aOrbiterI * 11714837622285605745U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 54U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 58U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 13771U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 14876U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16156U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15403U)) & W_KEY1], 58U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14965U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14616U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 16076U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 54U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 47U)) + 77518479758428414U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 29U)) + 4832061802166300011U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 19U)) + 11695291171006574112U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 60U)) + 7467412817843260094U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 17801484124471154757U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 5555455638503958639U) + aPhaseBOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 5669470540733721606U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 41U)) + 3042388456327784163U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 56U)) + 2236734925228156691U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14459720401528685450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4814967631216658856U;
            aOrbiterD = RotL64((aOrbiterD * 18288097536171386643U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16950679344449075945U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6262238639302011050U;
            aOrbiterI = RotL64((aOrbiterI * 9942659897425088183U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3522256359074996724U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12524717897707074242U;
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13891759914865623828U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11910250571469028666U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12311343917878428995U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2240189915640314069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5365912986308810837U;
            aOrbiterK = RotL64((aOrbiterK * 15133972552032469957U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9323732721344489753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterG = RotL64((aOrbiterG * 14659491687401151733U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16398238057564892809U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11517870519285159224U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1501848878469712681U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7758285512254776734U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17475149091906684720U;
            aOrbiterF = RotL64((aOrbiterF * 6015816725428299273U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2051631493975035243U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11684740065349595315U;
            aOrbiterC = RotL64((aOrbiterC * 10918975496337269197U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aPhaseBWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 54U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18620U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 17040U)) & W_KEY1], 36U));
            aIngress ^= (RotL64(mSource[((aIndex + 17432U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18539U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16656U)) & W_KEY1], 60U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16472U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18092U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 42U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 8685374557928800912U;
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 3482312691892161229U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 3U)) + 6948130297389161165U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 19U)) + 5506385663788942690U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 41U)) + 17859982009307397161U;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 9178488809207094043U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 46U)) + 1835479501226057169U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 5368101733632614939U) + aPhaseCOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 57U)) + 9050459666576835422U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9042186993119635078U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17528342580198295025U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6495418332558436882U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8834495762667327342U;
            aOrbiterI = RotL64((aOrbiterI * 10783141541937645995U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4364314196965690905U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6357485231062120459U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3321488322626415347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10817330671781848737U;
            aOrbiterA = RotL64((aOrbiterA * 15875919466358823335U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17974092279281611763U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2871472057292789157U;
            aOrbiterK = RotL64((aOrbiterK * 16104199340711015181U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15187929795092006849U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13482063681546475923U;
            aOrbiterB = RotL64((aOrbiterB * 14466266308157364963U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6232152545071397380U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17488906002621373262U;
            aOrbiterF = RotL64((aOrbiterF * 4719340606442742577U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12444819880507588549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13808941689757772497U;
            aOrbiterG = RotL64((aOrbiterG * 6541360905282412317U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8049361354387692374U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7137831335606542401U;
            aOrbiterE = RotL64((aOrbiterE * 11022231291507235007U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 6U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aPrevious, 40U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 34U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 19630U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 19246U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 21592U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((aIndex + 20595U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21597U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21541U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20625U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((aIndex + 20302U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 23U)) + 1364174714924216027U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 48U)) + 13561796874229506613U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 11845572344206238305U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 15762708240326773763U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 1157119665207900473U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aIngress, 19U)) + 6823546624372055260U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 14465564210523945121U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 11U)) + 10667464548080807531U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 58U)) + 13445737493224316575U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3009837893785957665U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2886920524111083752U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15308180928967762543U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10886177449328249656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15067759884678100433U;
            aOrbiterK = RotL64((aOrbiterK * 5724566815989860041U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18307930462682331536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8791864377579255801U;
            aOrbiterC = RotL64((aOrbiterC * 9265158882471421767U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 805797468642992351U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5743305867058244964U;
            aOrbiterI = RotL64((aOrbiterI * 16263000753351131717U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17102025528234481273U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1841579177327486899U;
            aOrbiterH = RotL64((aOrbiterH * 3841603385577825265U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2189493507896508972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 18209567010094914374U;
            aOrbiterA = RotL64((aOrbiterA * 3737080408976852351U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6697069234216868330U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 927471474577415372U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10680760991009199309U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13155854301197725408U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1014625081915435892U;
            aOrbiterD = RotL64((aOrbiterD * 11592754232949990435U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12697209921410914931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11555096613655648647U;
            aOrbiterJ = RotL64((aOrbiterJ * 4598821388864997089U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterC, 34U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 22U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + aPhaseCWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 60U));
            aWandererG = aWandererG + ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23064U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 22849U)) & W_KEY1], 40U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24127U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 22374U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24444U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23924U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23961U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 23193U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 47U)) + 13333509828310369865U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 34U)) + 7645352517103840797U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 5310766306660062655U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 53U)) + 5165635069832352932U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 39U)) + 15684141764734281849U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 13U)) + 3327963374225061738U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 26U)) + RotL64(aCarry, 3U)) + 8625811794878848871U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 7598657468430485291U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 43U)) + 2881171216276746485U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10237691227222918101U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6419254255884834497U;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4238455444646479956U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14936613353493061492U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15324699725208372627U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9506640480601832011U;
            aOrbiterC = RotL64((aOrbiterC * 12819564111348390227U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3709149613660215641U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1724290199312754307U;
            aOrbiterF = RotL64((aOrbiterF * 12597580418257897965U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13191172833570139194U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3686087945377837886U;
            aOrbiterK = RotL64((aOrbiterK * 10883609557429936283U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10418330386245397022U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5383531313632347245U;
            aOrbiterD = RotL64((aOrbiterD * 2987755379396160073U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7414716553072652212U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11301761123966206201U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1546727321088592187U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8570229732236388847U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8773754460060264773U;
            aOrbiterE = RotL64((aOrbiterE * 3251360788932563495U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13636929800504199371U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5486599841558573720U;
            aOrbiterG = RotL64((aOrbiterG * 2867914211589815153U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + aPhaseCWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 14U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 48U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterD, 37U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 38U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25570U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 26109U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26440U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27155U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24800U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26527U)) & S_BLOCK1], 24U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25578U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26922U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 18U)) + 16424657151168221875U;
            aOrbiterA = (aWandererE + RotL64(aCross, 53U)) + 17150123681886380361U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 16041993588694572757U) + aPhaseDOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 57U)) + 9871185846434828537U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 41U)) + 11227236398354430757U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 5399325217402192631U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 3U)) + 9248828789282890454U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 36U)) + 9041370494203701062U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 14944424084524970764U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5481938174456671041U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14783648629543752715U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7260164783191886395U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12355573914530445723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16149688605937250965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 106041828692026825U;
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8076098639554567792U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11155119311895580013U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1495180896564818647U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6847612160595917702U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16094377920388017367U;
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13584719866672696684U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13446209321646234607U;
            aOrbiterA = RotL64((aOrbiterA * 9945349065094781529U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15829806645369560988U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12573767256739062550U;
            aOrbiterB = RotL64((aOrbiterB * 5649504278826069077U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3850030870300393809U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11857593987748189858U;
            aOrbiterK = RotL64((aOrbiterK * 15942863910931814193U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5505918410521728373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12949653497121247860U;
            aOrbiterE = RotL64((aOrbiterE * 90944913639560027U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 20U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 10U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI + ((RotL64(aCross, 22U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 52U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27422U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((aIndex + 29222U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29563U)) & W_KEY1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29138U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27788U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29142U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29921U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 27703U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 26U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 37U)) + 3970829908171131502U;
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 7040283759419531991U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 11856292169397052901U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 52U)) + 819598588791819022U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 2176451710970866848U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 6454704928613390494U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 11792122387218053841U;
            aOrbiterG = (aWandererE + RotL64(aCross, 60U)) + 9254780213489752211U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 3U)) + 16591812589999846482U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1471246223935074832U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1424843083106386453U;
            aOrbiterE = RotL64((aOrbiterE * 15020536982657410783U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1856469958050891629U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6331743690452052712U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15327924647897459645U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10351075711345476487U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 9518585245330480185U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3792179827396760391U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17787514620244712033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14182328067398162557U;
            aOrbiterC = RotL64((aOrbiterC * 18107337388659070197U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12798088948801072444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9563215159275202323U;
            aOrbiterA = RotL64((aOrbiterA * 7058145016617349141U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9904919772580498232U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16579777394992143043U;
            aOrbiterK = RotL64((aOrbiterK * 10516761340320196661U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6344049286854588503U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3531503618941046788U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10855385899703024105U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11334308840132700377U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11093833870078787770U;
            aOrbiterG = RotL64((aOrbiterG * 16105889714648555755U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3831491136025364271U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12505259454860591372U;
            aOrbiterH = RotL64((aOrbiterH * 6135450888433504093U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterB, 10U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 14U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31478U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 31649U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32490U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32044U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31847U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31145U)) & W_KEY1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 4068921616130916949U) + aPhaseDOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 12077715273915151726U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 52U)) + RotL64(aCarry, 35U)) + 16047546802670596833U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 43U)) + 9690277462716999763U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 47U)) + 14484814700447992628U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 17089267243053958210U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 13U)) + 9138746214446211147U;
            aOrbiterB = (aWandererK + RotL64(aCross, 29U)) + 10181001536979097045U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 18U)) + 6657458969093373191U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7515983477876590988U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3039935555863947600U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12511160550780270119U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16209389224740851136U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 725253312098083182U;
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13307041115748941383U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7159572004825238263U;
            aOrbiterK = RotL64((aOrbiterK * 4855009895002398449U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12027236743251643820U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8717826175991286553U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1175614802543098451U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4769096034227659937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11201226563992939616U;
            aOrbiterG = RotL64((aOrbiterG * 15595355978388159931U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17295978531215563256U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11850923890626719833U;
            aOrbiterC = RotL64((aOrbiterC * 3854851059897397075U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14139441565288097706U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 988684899382304485U;
            aOrbiterA = RotL64((aOrbiterA * 11929090869999700891U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6159251276942253175U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4849529993914550651U;
            aOrbiterB = RotL64((aOrbiterB * 18240712676783671317U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6679745455842119497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15838404437552215214U;
            aOrbiterH = RotL64((aOrbiterH * 17357853511591350887U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 22U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 48U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 10U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 44U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererK, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Billiards_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4469U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 3293U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4682U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6267U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2869U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6036U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 21U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 9080426856729228705U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + 7851218321653539276U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 47U)) + 7023344692919298036U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 9772846154227440734U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 12008298632429608431U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 29U)) + 12201090455849562875U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 58U)) + 9498721803411445471U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 351203764023093632U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4966360430644539250U;
            aOrbiterH = RotL64((aOrbiterH * 10138518378274592739U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9194167899071345693U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4922477697284269116U;
            aOrbiterE = RotL64((aOrbiterE * 8444814161720407881U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15742625291642356429U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7528703106518431730U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11530049278751507567U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15279053574704935317U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2425839793660355555U;
            aOrbiterK = RotL64((aOrbiterK * 11486964816849830667U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13209849392400008898U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9041500097716231309U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 340661035700748739U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7885423750878814599U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1992993999902904603U;
            aOrbiterD = RotL64((aOrbiterD * 1478629826632201617U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6120758615019314102U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8529621625846992066U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8485991471612862467U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 22U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterB, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8704U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((aIndex + 13238U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 12272U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15817U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15917U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10474U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12187U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aPrevious, 19U)) + 3561491146322798260U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 57U)) + 7075025056181885339U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 9230910887904171613U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 51U)) + 4119781172609908917U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 12U)) + 17155609083870983149U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 2423018561430181695U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 12957280305617615744U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2461704174772065813U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7907123257849391997U;
            aOrbiterF = RotL64((aOrbiterF * 9416171962847312179U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7257868138318960007U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16425903703085702285U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7996935869077231999U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2990822664594079467U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5654819006718953817U;
            aOrbiterK = RotL64((aOrbiterK * 4465096036756887801U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12183676471235678779U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15026286960542123922U;
            aOrbiterJ = RotL64((aOrbiterJ * 17199049329995315279U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12169080607071830522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2906296852254787499U;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3029858695410344584U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14406410317495954566U;
            aOrbiterE = RotL64((aOrbiterE * 9663780721657983421U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11048818178401163861U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13622063920319445043U;
            aOrbiterD = RotL64((aOrbiterD * 2516025554421589857U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 26U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 4U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererC, 46U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24191U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 16884U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20584U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((aIndex + 21496U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24576U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22317U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22586U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 39U)) + 7893287783892523139U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 23U)) + 10257331997383491153U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 14562226733652231753U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 14320342577110737851U) + aPhaseEOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 14U)) + 9816717579822880756U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 9558926960095881953U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 29U)) + 9230371862654338324U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6414274291252913420U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13868546184398350849U;
            aOrbiterA = RotL64((aOrbiterA * 1547986864837497409U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16940736952569949038U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2866957764814864371U;
            aOrbiterI = RotL64((aOrbiterI * 3554702178644797003U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7916721976073979724U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1602444214978842275U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11072503711308122385U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9529061385251008037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8402775110887376588U;
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15003592180290390713U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14195681406520825751U;
            aOrbiterF = RotL64((aOrbiterF * 11455000833788877217U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3263577002367714202U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12019422062655581928U;
            aOrbiterE = RotL64((aOrbiterE * 5002313835338447799U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8508638054582582917U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6536618106353552880U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6233964121117511885U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 6U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32245U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 25434U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 24738U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25953U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30528U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32151U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 26877U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 6771552164800695068U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 12131763371571322040U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 3U)) + 3326182381395522013U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aScatter, 35U)) + 12288775097697156383U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 11U)) + 5195948373449796741U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 14404044002250137144U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + 11142382920035825426U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2967149520256475485U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1470907369577818097U;
            aOrbiterB = RotL64((aOrbiterB * 9398653295177725883U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9231668148004163910U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13078929163913892386U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7509829068700523627U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9485274692075657877U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12216951187543631673U;
            aOrbiterG = RotL64((aOrbiterG * 6571066246507310805U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6933334652581744234U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17260276102423580920U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 387767848169714392U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8597538259308082638U;
            aOrbiterK = RotL64((aOrbiterK * 4888054690557707241U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7996708724489146033U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15357384191688149939U;
            aOrbiterD = RotL64((aOrbiterD * 9827691726832491373U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17739222908739454637U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1614322333281471170U;
            aOrbiterJ = RotL64((aOrbiterJ * 7063116837752240891U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterK, 60U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Billiards_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1603U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 40U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3607U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3683U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2674U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5002U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 23U)) + 2168513956284366370U) + aPhaseFOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 13U)) + 10290361969974613111U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 27U)) + 15673836275828498050U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 57U)) + 16600540024145812236U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 42U)) + RotL64(aCarry, 23U)) + 9428052101528111892U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 12763657928312763377U;
            aOrbiterI = (aWandererA + RotL64(aCross, 19U)) + 10751286982008662485U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 53U)) + 1708230173038057979U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 4011389705422783816U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 11U)) + 11704428328093077714U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 40U)) + 2055336619674699284U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1870865272102705804U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3574214263751923179U;
            aOrbiterB = RotL64((aOrbiterB * 13132083406834413563U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 984611970726966186U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15207945449947643672U;
            aOrbiterH = RotL64((aOrbiterH * 9539470161576639981U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4181398506373973169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15222345431506025949U;
            aOrbiterD = RotL64((aOrbiterD * 6925143692628659467U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15023513452326240962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14965669361708810699U;
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7985755518735406360U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 225592097619240187U;
            aOrbiterG = RotL64((aOrbiterG * 2313509354133400439U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3659537916566939383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17043668033610689611U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10797634709118100773U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10217321522161675848U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8013663869536146842U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2293233079384777175U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13762445330867496042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2692400019659269106U;
            aOrbiterK = RotL64((aOrbiterK * 167704184292219399U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18232551682424867647U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14785847596876239854U;
            aOrbiterE = RotL64((aOrbiterE * 4569180925037758487U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5910282247522389536U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16556038638738871204U;
            aOrbiterF = RotL64((aOrbiterF * 18356922295088260901U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 141620663839815754U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2168513956284366370U;
            aOrbiterC = RotL64((aOrbiterC * 8605382725635471683U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 56U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 44U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15536U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 11054U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11454U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 12769U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9487U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15808U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11128U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 44U)) + (RotL64(aCarry, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 23U)) + 11450949896247900941U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 3905542253538116335U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 9529740545977785305U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 1856876631533143492U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 27U)) + 84253466320181686U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 41U)) + 12577480918745432444U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 21U)) + 5625703170397704029U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 5U)) + 694608607323629282U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 53U)) + 3993981243536262204U;
            aOrbiterA = (aWandererF + RotL64(aCross, 29U)) + 4119215953484892051U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 58U)) + 8785040118556157146U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16234403619456882890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10398727475672860610U;
            aOrbiterG = RotL64((aOrbiterG * 5086871400049644715U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18327987141759096769U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2645964788056875452U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8778681366114628045U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2859452497983106129U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7196557924940881076U;
            aOrbiterB = RotL64((aOrbiterB * 14415389907490256711U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 930127943984174668U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15673596916054795749U;
            aOrbiterE = RotL64((aOrbiterE * 7505660488733199479U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16673140529110941163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2258448294877833760U;
            aOrbiterI = RotL64((aOrbiterI * 1821550319748977445U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6870209259643931219U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12749790107942194104U;
            aOrbiterK = RotL64((aOrbiterK * 4871407285968611725U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17131374134617173866U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6426448390733751612U;
            aOrbiterA = RotL64((aOrbiterA * 12490559588384058417U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15592826434339731146U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14182944418026376183U;
            aOrbiterF = RotL64((aOrbiterF * 7218860482893476233U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17447476498234456596U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 972861017466618022U;
            aOrbiterC = RotL64((aOrbiterC * 9610670431280153921U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13185309156950240549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14442284480744008537U;
            aOrbiterJ = RotL64((aOrbiterJ * 2907844852105175837U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7816745313858811117U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11450949896247900941U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18317765298694454463U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 46U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 20U) + RotL64(aOrbiterG, 60U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 46U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16493U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 24530U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 19615U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 17725U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20612U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22501U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 21493U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 37U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 27U)) + 8866844335448071821U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 53U)) + 15159698739856430085U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 58U)) + 9582805772989594633U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 1438538239931588373U) + aPhaseFOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 21U)) + 10862044156620436139U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 13682173320058164615U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 8351013291045977592U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 37U)) + 15777857431516633916U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 13U)) + 16178966745333885377U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 60U)) + 9031889187993001617U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 6308472367425865347U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 642109145903321046U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9186268569255318035U;
            aOrbiterH = RotL64((aOrbiterH * 10714674348507516749U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6091345356803675860U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4266652275234474616U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4391422098164506195U;
            aOrbiterG = RotL64((aOrbiterG * 17634679403195085867U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5160682323243635577U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10351728852161347404U;
            aOrbiterK = RotL64((aOrbiterK * 11105410036471745951U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3950932176454814023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 9536466386833427441U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18064984243491293435U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9927425919978776529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6819384090527481081U;
            aOrbiterB = RotL64((aOrbiterB * 18032965969184368561U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1646274931424218507U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16166524473976135097U;
            aOrbiterC = RotL64((aOrbiterC * 11672192658072663849U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11252501968059485262U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16847854447987609067U;
            aOrbiterI = RotL64((aOrbiterI * 6326299154627028295U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16723218285355036446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13870211254243048975U;
            aOrbiterA = RotL64((aOrbiterA * 10203222183774624097U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11401147367366049493U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4266628469244269926U;
            aOrbiterD = RotL64((aOrbiterD * 2409934496621365221U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11578385782347296942U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8866844335448071821U;
            aOrbiterF = RotL64((aOrbiterF * 6456956795450036515U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 48U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 36U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 26U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterD, 21U));
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30234U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 28145U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 29175U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 25718U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26000U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29252U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 27742U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 47U)) + 5295352595333316211U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 35U)) + 2341795367042042605U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 10122175780504033663U;
            aOrbiterE = (aWandererI + RotL64(aCross, 44U)) + 10084612804696198554U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 39U)) + 16470424309851045971U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 53U)) + 656016130975227994U;
            aOrbiterD = (aWandererD + RotL64(aCross, 23U)) + 15313268829659834317U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 3795220914993923394U;
            aOrbiterA = (aWandererC + RotL64(aCross, 21U)) + 14044442220988813825U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 3804224626734584802U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 3U)) + 7980006306010255693U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13746830564584711549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11852212099729274845U;
            aOrbiterK = RotL64((aOrbiterK * 2164880979318247855U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9083223471018084847U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13706723820703853346U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11361854103656219887U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1713819986642275223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1382000168233902914U;
            aOrbiterD = RotL64((aOrbiterD * 3894160765130198157U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4540474625764565485U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1756168174375757220U;
            aOrbiterF = RotL64((aOrbiterF * 12739160208010092017U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1409297070183609309U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6082750101445444357U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17438740230251860935U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1113239890859479202U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10932192439503964363U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5915660289913324281U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3732595033748508428U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5117760372351117286U;
            aOrbiterC = RotL64((aOrbiterC * 2671510075176315761U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7399968659654088641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14835608167871904147U;
            aOrbiterG = RotL64((aOrbiterG * 8312521710415756159U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 7851355416751467648U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 262169565276199916U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11801419425408657509U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1771847554312299305U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15588805765521695222U;
            aOrbiterJ = RotL64((aOrbiterJ * 8541206691371972017U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6162696602553964144U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5295352595333316211U;
            aOrbiterA = RotL64((aOrbiterA * 8368226841948931873U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterE, 56U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 14U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Billiards_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6450U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 985U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 2936U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2713U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6877U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3356U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 5171470532667965920U) + aPhaseGOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 750549462358682403U;
            aOrbiterB = (aWandererB + RotL64(aCross, 3U)) + 3325689257577120525U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 18031575461559790826U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 39U)) + 13874739537012288677U) + aPhaseGOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4250029868785016865U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8211158803112611161U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9205801383408193959U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1083939790236786027U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3446525462376962464U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13603702473750888213U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6973817815000417325U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15230876489676945543U;
            aOrbiterI = RotL64((aOrbiterI * 7737039082964537651U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9359727659738755880U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8775170107816327654U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6910680458261008653U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11958941755525038545U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16966819714283167348U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16363457661846050749U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13298U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 11833U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10073U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9809U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9190U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14562U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 16016931609704150191U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 43U)) + 14511433515861302636U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 11691237442613269593U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 16383220587320484649U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 52U)) + 14293015313458219868U) + aPhaseGOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4407695248205526670U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1158323195324398372U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7489061637031434357U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6577683409653864555U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 171080079472863843U;
            aOrbiterK = RotL64((aOrbiterK * 3063978974927752653U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5766333425872228205U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16173508656917582960U;
            aOrbiterH = RotL64((aOrbiterH * 12187968015372936695U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11781450063402219202U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13033139686637576694U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4331137994135472025U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4006310759400926020U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13156817947481574467U;
            aOrbiterA = RotL64((aOrbiterA * 563189239835001483U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + ((RotL64(aCross, 12U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19896U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 24412U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21769U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24265U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19501U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 23612U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 15726877954695761686U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 51U)) + 14187652171881943587U) + aPhaseGOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 35U)) + 8420423151313882782U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 14942322692433259283U) + aPhaseGOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 53U)) + 7272331475919796255U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 154504365041805840U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17475491222554948786U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2095330528612694779U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5759181483165339605U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5993060214499322845U;
            aOrbiterI = RotL64((aOrbiterI * 10799489831896153301U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10901786237875941844U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17135786595614068473U;
            aOrbiterK = RotL64((aOrbiterK * 15923538730142047043U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5208202073886811165U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6821452921018900631U;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13348064837402206969U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 44U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 44U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aPhaseGWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27897U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 31606U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29666U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25289U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26473U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 28993U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 12380376990224645149U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 18296928500297384014U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 3550626816361145100U) + aPhaseGOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 58U)) + 2667792936946706027U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + 12020969779370926953U) + aPhaseGOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 737340727886903447U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1681797651799760502U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11923920414802777451U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2956186342689489064U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1876852870402977177U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8875540081346621757U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6433205819353555071U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9065076854974222998U;
            aOrbiterI = RotL64((aOrbiterI * 5459675878087242021U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3254410578766789992U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2005081975473815576U;
            aOrbiterB = RotL64((aOrbiterB * 9947701153722014085U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15992999234834560419U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3458344156815120948U;
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 60U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Billiards_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6419U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 7262U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7669U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3817U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 855U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 7783U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 11274974230580265396U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 16658438747342741547U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 41U)) + 16612986966106053844U) + aPhaseHOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 9329502236843231290U;
            aOrbiterH = (aWandererH + RotL64(aCross, 30U)) + 14088261356708344656U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13692608802007789581U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 6824473946645682398U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13619437545775237601U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2072915876348570040U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7420507753044460759U;
            aOrbiterJ = RotL64((aOrbiterJ * 13239288539564571257U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4677557318688502593U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15081678577055628459U;
            aOrbiterH = RotL64((aOrbiterH * 16659305295251177155U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7026792817486507482U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14871665922943969918U;
            aOrbiterD = RotL64((aOrbiterD * 694073180313083145U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 6807734532159292872U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17882797335141303280U;
            aOrbiterB = RotL64((aOrbiterB * 15439872930381050291U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 39U) + RotL64(aOrbiterH, 34U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12216U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 13698U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 12244U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9557U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15541U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8904U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 3199575576585871314U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 2533378188975571824U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 58U)) + 6819782112558312658U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 12690060987724798497U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 27U)) + 7088375139715629606U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17785618677423695666U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1714999280296491277U;
            aOrbiterA = RotL64((aOrbiterA * 7675674437417383741U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17611338506932491624U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6475727359297421201U;
            aOrbiterK = RotL64((aOrbiterK * 15133348244242438069U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2347744591204119530U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2739317903351401068U;
            aOrbiterB = RotL64((aOrbiterB * 15435029315209475631U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8663535261373274338U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8205245127823536479U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13857005110466856439U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8916510616749754516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3944805940148512932U;
            aOrbiterJ = RotL64((aOrbiterJ * 18082271583211389701U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16823U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 19585U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23168U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24352U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21483U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 22720U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 24U)) + 7825479804710770560U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 5298124167101358123U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 17774541024369233726U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 7679371833537454082U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5385914900748772224U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3879781930908486531U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 659110346638873236U;
            aOrbiterF = RotL64((aOrbiterF * 17439162088869824407U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10749021728538539749U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3631252455767429457U;
            aOrbiterB = RotL64((aOrbiterB * 8552825360915119613U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2271978810960685021U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5963558780692551176U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4772055335210781149U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 974909966119198104U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9296998242911152296U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2245318466901521959U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13391076374843288568U;
            aOrbiterK = RotL64((aOrbiterK * 18094558036982107419U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 54U) + aOrbiterF) + RotL64(aOrbiterE, 44U)) + aPhaseHWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28418U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 25279U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29284U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32120U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24614U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 24854U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 10U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 35U)) + 9654059367478508868U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 6473006635864677427U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 6944184481315853243U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 4U)) + RotL64(aCarry, 23U)) + 4061496421939102306U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 15791809275719085463U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14050798802646323055U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12072905924741758266U;
            aOrbiterA = RotL64((aOrbiterA * 4757104346636738119U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17639076509231343896U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12195388285571234715U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4317060502521195769U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4325404419499496529U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5910567888204238382U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11503787177122206937U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13092940059929942699U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13381962590820308761U;
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 15622862439323440527U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14027151901132249793U;
            aOrbiterH = RotL64((aOrbiterH * 2273573821630510087U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererG, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
