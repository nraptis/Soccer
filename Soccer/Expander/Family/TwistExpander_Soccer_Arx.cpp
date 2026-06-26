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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF1273BB0BC51C7D5ULL + 0xAD550A2491FAE218ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9BA57E1A855C3A6BULL + 0x8F7E0AE4EB2DDD2CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8A69E8643F3DEF69ULL + 0xCB5E272E81731A34ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD835FB978A1677C1ULL + 0x994410CAB9838939ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB186BBB9323EBD4BULL + 0x88C4476DA1122053ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFB0F2C3A3CDC4803ULL + 0xC3B0E10BC4AE337AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA029889C1F1C69D1ULL + 0x89182FA3B4738B15ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8F3ABE7545ADD8B9ULL + 0xBAD5C0B342A239C2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEEF783CE4DF4CA95ULL + 0xD58017974E0EA718ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9C92DA1E68D60AC3ULL + 0x987D65C3ABE926DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x87ADBE31AC498B11ULL + 0xBB2D30E6FD032CD9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEBF3235E41095829ULL + 0x93738E7816588FFEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE920695D54DE91C9ULL + 0x8D7AD9C6C23ABC7CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD50B9901E07DDF41ULL + 0xB54F1990A867D8B2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC1CE9FC2B9C33E5BULL + 0xEA55604BFD344CDAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC6A9E66A24A7A0EDULL + 0x84B4E3479239A706ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5132U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((aIndex + 5443U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1015U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4185U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 51U)) + 13499155707765393469U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 3740324981823726185U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 39U)) + 5470765363949735652U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 47U)) + 3446436171274452326U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 1778929412631211933U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 14666308799855220954U;
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 4548410236791175055U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 58U)) + 5829739767694190372U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 19U)) + 14319231414903675748U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + 1513851750246111405U) + aNonceWordG;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 21U)) + 1685620217748986019U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 16284162182006054402U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6271539598462003309U;
            aOrbiterA = RotL64((aOrbiterA * 13923286694131331137U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12669312437565969473U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11894755313393001665U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12556759675372354075U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6315983824634946566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17106616474222892782U;
            aOrbiterB = RotL64((aOrbiterB * 167205520766791073U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13350266700180455548U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4608846311203767162U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2504857468837437365U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14195866746143604365U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7917977448256795054U;
            aOrbiterC = RotL64((aOrbiterC * 5927771378657284557U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10707336923305131629U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17122696159336995392U;
            aOrbiterF = RotL64((aOrbiterF * 13953518568670659191U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5182322763573586116U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6503754948502556246U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14749002194140663519U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14907832047832987341U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6258064448676621346U;
            aOrbiterJ = RotL64((aOrbiterJ * 4407960312705621487U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1180234574888070795U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 801686887651085881U;
            aOrbiterI = RotL64((aOrbiterI * 433981853631548041U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11810494591997709554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9343740505955858127U;
            aOrbiterH = RotL64((aOrbiterH * 8733378485648720323U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12816829575386720695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13499155707765393469U;
            aOrbiterK = RotL64((aOrbiterK * 9937924703928730369U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 10U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterD, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterD, 60U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 50U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 20U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8648U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6822U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6844U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 8492U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 13U) + RotL64(aCarry, 56U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aCross, 35U)) + 13442819395490639310U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 23U)) + 8187292523194120936U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 11469697159823131388U) + aNonceWordK;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 37U)) + 13414083692375929653U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 3U)) + 11404010733687907517U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 6783212827186218247U) + aNonceWordF;
            aOrbiterD = (aWandererB + RotL64(aScatter, 41U)) + 8561131439340372614U;
            aOrbiterE = (aWandererC + RotL64(aCross, 56U)) + 6252609642004429113U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 12804867444200448952U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 2739648749603690781U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 21U)) + 14808861217017399752U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17588866502571268888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5882260142735642980U;
            aOrbiterC = RotL64((aOrbiterC * 7688252946143263869U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15493099088132862949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5175647411532429582U;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14279707376173642767U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6826363572161275158U;
            aOrbiterB = RotL64((aOrbiterB * 5263708315440161809U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13267185753040999992U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9980987858092888720U;
            aOrbiterD = RotL64((aOrbiterD * 13210290848800728635U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3582972937645514549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10140409019562890804U;
            aOrbiterG = RotL64((aOrbiterG * 6944490201647678479U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6160444117287330557U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16344602960561293113U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2319964919335633293U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3497141036108337171U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 91269118352540308U;
            aOrbiterH = RotL64((aOrbiterH * 5160060720189045505U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12739932748793144857U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12820180915064791197U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 5843849637411948699U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17572075652083359962U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10684041099654982701U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 7121293375756263771U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10739534650885677354U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9731206787727954809U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3730875775588585547U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9655432616347117764U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13442819395490639310U;
            aOrbiterF = RotL64((aOrbiterF * 3650859301708619119U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 46U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 40U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 38U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aNonceWordL) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterD, 60U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 24U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10942U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15986U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14451U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 13545U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 13278949403988203974U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 9213599924054673756U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 19U)) + 1255746482932381798U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 27U)) + 11575321997144516122U) + aNonceWordE;
            aOrbiterC = ((aWandererK + RotL64(aCross, 51U)) + 15881587525529432437U) + aNonceWordC;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 38U)) + 9846195809864862707U) + aNonceWordK;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 12319815691858217670U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 16322617427294439587U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 16332130810525887437U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 4920951156015336794U) + aOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 60U)) + 16767126455124552329U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12553595911087945223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1437522202135436142U;
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12313100454852227143U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2761983020631055729U;
            aOrbiterK = RotL64((aOrbiterK * 3874839760378039509U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17635303588421554367U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 788212489507463763U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 17896475584538528059U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5192552894670654434U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6784748488807738811U;
            aOrbiterC = RotL64((aOrbiterC * 8077237651953896479U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16113417046719114943U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1096874945215225916U;
            aOrbiterA = RotL64((aOrbiterA * 17308604412622879833U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7610274704570171595U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10466070212284342550U;
            aOrbiterI = RotL64((aOrbiterI * 6449728258497920613U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6777845928873855221U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 5251515022021984126U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 9018277343404261611U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13849343158824111498U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7977711210181714021U;
            aOrbiterH = RotL64((aOrbiterH * 4182053966171053577U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6494539818728106982U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11314590450226080781U;
            aOrbiterJ = RotL64((aOrbiterJ * 12455979257225599157U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 552687702594328012U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14961304171192292246U;
            aOrbiterE = RotL64((aOrbiterE * 846375892915484717U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9771874402848476494U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13278949403988203974U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2119203863777871233U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 10U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 50U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 24U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20279U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19553U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18496U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 21243U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 48U)) + 12632404972795375757U) + aNonceWordO;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 29U)) + 5351879979055988456U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 27U)) + 3597737727467443413U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 23U)) + 2830846754917852318U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 52U)) + 17311925960294518018U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 2083584640523695383U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 15049343611387010158U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 39U)) + 6443050378205811147U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 37U)) + 6021965178697344070U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 5080289878758029976U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 576927745306972983U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4728489691382690859U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6184355840165758855U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1515043910404156423U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11220539885798595450U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11091438724966718214U;
            aOrbiterA = RotL64((aOrbiterA * 8225347114759391961U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17184210490020062419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2150997767099116408U;
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7021953562676903717U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17159676348343312834U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13877284519668483549U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10367891770525239784U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11922478487264201233U;
            aOrbiterF = RotL64((aOrbiterF * 9195137452661956029U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17815162358981720634U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9582631251085100284U;
            aOrbiterH = RotL64((aOrbiterH * 11838992994130850483U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 872593750259572264U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17832330100262167302U;
            aOrbiterB = RotL64((aOrbiterB * 1114416841510028467U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16601139856969287418U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14931287111691324985U;
            aOrbiterI = RotL64((aOrbiterI * 16757174577841001179U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11413072442039115924U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15253605470589905889U;
            aOrbiterG = RotL64((aOrbiterG * 10832817442285245673U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3653487723581514107U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14891378240114471865U;
            aOrbiterJ = RotL64((aOrbiterJ * 1386594204573386051U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15659724464711852035U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12632404972795375757U;
            aOrbiterE = RotL64((aOrbiterE * 2407347385127296647U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 48U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterK, 34U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 36U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 40U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26131U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25916U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25087U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26991U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 27U)) + 15383045568644941552U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 3U)) + 17452811657750910067U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 39U)) + 15660117718455155603U) + aNonceWordH;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 10396441207743665753U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 19U)) + 3708971058200841442U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 50U)) + RotL64(aCarry, 51U)) + 7000673057768598750U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 9886354469011131596U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 43U)) + 16018065329058043467U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 5024756166109352320U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 6587818720728886652U;
            aOrbiterB = (aWandererK + RotL64(aCross, 12U)) + 3652672354944162319U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6307315649915348048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16405347331742979258U;
            aOrbiterI = RotL64((aOrbiterI * 7183142442906743699U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5427299664054601957U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4983381733483185898U;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10182995521328377487U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8694282877540593550U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14614602561910403893U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4085927978153269932U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16792916528959579875U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6966742100601433005U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9920952446921247521U;
            aOrbiterF = RotL64((aOrbiterF * 1879821050131820933U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11958734477518336014U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2058335903640404380U;
            aOrbiterH = RotL64((aOrbiterH * 6986170159285417789U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 77366119537297816U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12072894199692855000U;
            aOrbiterG = RotL64((aOrbiterG * 9083781120514635987U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11874297832446385377U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13715562531763053196U;
            aOrbiterD = RotL64((aOrbiterD * 12822488258322963187U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 13664465415354326653U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10365386643010882315U;
            aOrbiterB = RotL64((aOrbiterB * 3687934567254955761U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2003863843075564853U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8864134110143237364U;
            aOrbiterJ = RotL64((aOrbiterJ * 4586162015675320985U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8055736412403126985U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15383045568644941552U;
            aOrbiterE = RotL64((aOrbiterE * 5175405553995854715U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 58U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 50U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 41U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 12U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31956U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28272U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30353U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 32126U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 20U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 13U)) + 4980738603982643969U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 17660278413018470020U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 18U)) + 17598114429859543466U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 53U)) + 10993929335279994739U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 39U)) + 17967203122976322481U;
            aOrbiterD = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 1872290205549034384U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 16607778671782810797U) + aNonceWordM;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 11U)) + 4895226930754394376U) + aNonceWordI;
            aOrbiterG = (aWandererK + RotL64(aScatter, 60U)) + 14960359005982301383U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 47U)) + 9921642352377700630U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 893281964367208693U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8232519988397858732U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4433022122758913407U;
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12689609831247168353U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 404535388957472176U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3349108201964013155U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4386449511297371730U;
            aOrbiterD = RotL64((aOrbiterD * 9596273264321140229U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14314587717949070586U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10923886625271054985U;
            aOrbiterF = RotL64((aOrbiterF * 7838969002623486809U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17634909585329833520U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2021301459918350372U;
            aOrbiterB = RotL64((aOrbiterB * 1388242915918642741U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5219599112498224367U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10641339455385046206U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1022283727595400719U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5003342156562330058U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10951027475628404336U;
            aOrbiterE = RotL64((aOrbiterE * 17836928292555158461U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13040991872592235460U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11149099984302782267U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 4248667283139686251U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2202253777854402763U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16679038924474862612U;
            aOrbiterC = RotL64((aOrbiterC * 2624443661523083597U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1959650241410955571U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8415989510614674816U;
            aOrbiterK = RotL64((aOrbiterK * 16340289102832732519U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2344501711730399821U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4980738603982643969U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 6419275275477478723U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 24U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterD, 10U));
            aWandererK = aWandererK + (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aNonceWordK);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 48U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBEDD0633B2AD7083ULL + 0xC385A2020576F5CDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBBD35617A940947DULL + 0xD2C01DAD47F3F743ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8CEDD8884B99A4C5ULL + 0xF77F8FA0BAE27BCFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE99A4564B22B4427ULL + 0xEF15CAC4C2A690B1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBD2743AF73549BD7ULL + 0xF7D9D9EEA93F156AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAD2B1DA31973E1B7ULL + 0xA48AB5C4E8329A55ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDF0A6C4A683A4D81ULL + 0x8A164EDBE3EF9024ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDB5B7D2822CD9ABBULL + 0xC5F13B93FD573E0DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x932A82FC17217317ULL + 0xD6367B95D71BA008ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xADD12965B549D8D3ULL + 0x818079CCC7B07686ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB4701D8FD5D68031ULL + 0xEE0180ADA543A96BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9694C5AD4D296EB3ULL + 0xD193CD48B2CF7C60ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8D12EEFE6584343DULL + 0x86D95055A55CA1BCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCA97AE5CB4544035ULL + 0xB7EE2EC73783679DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x85791F4B4B5CA7FDULL + 0xB54D928C3AC59987ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFD50B1087DDAA1FBULL + 0xB4E0EDFB3CEB1A65ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3155U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4501U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 268U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7819U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 10U)) + RotL64(aCarry, 51U)) + 13204735390996728477U;
            aOrbiterF = (aWandererD + RotL64(aCross, 53U)) + 851171359595647173U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 16745304202825290723U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 43U)) + 562392736584913979U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 39U)) + 3244267012529053918U) + aNonceWordO;
            aOrbiterK = (aWandererG + RotL64(aIngress, 35U)) + 17282536111067869133U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 48U)) + 14851130066471729068U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 5256130407952363129U;
            aOrbiterH = ((((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 2904742485828362001U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3723346325449225387U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5344621093694027341U;
            aOrbiterG = RotL64((aOrbiterG * 9044881458629673499U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12919263300833603026U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17989801264160996071U;
            aOrbiterK = RotL64((aOrbiterK * 15468293047311883751U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5022175042377172157U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16684822380107847758U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2740326510600876682U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13981423865219318820U;
            aOrbiterH = RotL64((aOrbiterH * 14593082145080056441U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 231945878229848395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14139797734944312580U;
            aOrbiterJ = RotL64((aOrbiterJ * 6492256080432266407U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16704102101387552373U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8506734780526852552U;
            aOrbiterE = RotL64((aOrbiterE * 4684566118627414659U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2774630043988894695U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12490034334296488127U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16765455396278233145U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 545238171291436006U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1023872898002379590U;
            aOrbiterF = RotL64((aOrbiterF * 8626333831510136515U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5065187021047872560U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10391809965648089863U;
            aOrbiterB = RotL64((aOrbiterB * 10912471108849550469U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 34U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 38U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 30U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11023U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9934U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9158U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12610U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 42U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 12136097566601676613U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 29U)) + 7969431322248040056U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 10530676021510553889U;
            aOrbiterI = (aWandererC + RotL64(aCross, 47U)) + 8740777303075445264U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 19U)) + 13249434169895564739U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 13U)) + 15529577005925628472U) + aNonceWordM;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 42U)) + RotL64(aCarry, 39U)) + 344627093687331562U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 51U)) + 8824277416519988893U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 23U)) + 5636276438449709875U) + aNonceWordL;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2079413361031851552U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7807998179168655561U;
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13589392896232029112U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10733011474804473996U;
            aOrbiterC = RotL64((aOrbiterC * 361749145931578805U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15934162328347805968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7573511217796245232U;
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 4828475187337891975U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13284974329890393113U;
            aOrbiterG = RotL64((aOrbiterG * 10831075817642374287U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13173869918669643112U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15841507674783398167U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15632933198136963277U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14168272451055700516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11134471485501999898U;
            aOrbiterA = RotL64((aOrbiterA * 8019507184494591705U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2611858916687822610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17863271539727513641U;
            aOrbiterI = RotL64((aOrbiterI * 4987884722174985677U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8874401993454249066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5131480593493950665U;
            aOrbiterE = RotL64((aOrbiterE * 8585874663602346121U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9366563022381918996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7890729519928340296U;
            aOrbiterF = RotL64((aOrbiterF * 11428572374057899517U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterE, 60U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 22U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22367U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 17314U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18173U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 17966U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 27U)) + 5171470532667965920U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 43U)) + 750549462358682403U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 19U)) + 3325689257577120525U) + aNonceWordE;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 47U)) + 18031575461559790826U) + aNonceWordP;
            aOrbiterH = (aWandererG + RotL64(aScatter, 58U)) + 13874739537012288677U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 13U)) + 4250029868785016865U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 8211158803112611161U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 1083939790236786027U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 52U)) + RotL64(aCarry, 19U)) + 3446525462376962464U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6973817815000417325U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15230876489676945543U;
            aOrbiterI = RotL64((aOrbiterI * 7737039082964537651U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9359727659738755880U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8775170107816327654U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6910680458261008653U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11958941755525038545U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16966819714283167348U;
            aOrbiterK = RotL64((aOrbiterK * 16363457661846050749U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14556087985619763243U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17915047508377045221U;
            aOrbiterJ = RotL64((aOrbiterJ * 6727635453185130109U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8578745677485367222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7002181668717618866U;
            aOrbiterH = RotL64((aOrbiterH * 12329703532414955235U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3569939503066735457U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2956247934282522184U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9946650822131152531U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4285180013402474041U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5976239869535619811U;
            aOrbiterB = RotL64((aOrbiterB * 3458095419039067465U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2424524955161695463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6849595426583763537U;
            aOrbiterC = RotL64((aOrbiterC * 12727902040238318101U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11414890686374886716U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5668287266836153445U;
            aOrbiterE = RotL64((aOrbiterE * 8011885266143066285U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterB, 58U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 39U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 18U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28151U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24866U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32001U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24647U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 53U)) + 11700815697312060726U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 11808423452327465441U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 36U)) + 8670503858631730886U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 5U)) + 2400061067991988544U) + aNonceWordP;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 21U)) + 16163118178366229686U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 3280178595904941068U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 3298683600817047727U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 28U)) + 16321624053445183574U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 57U)) + 6730229877611375225U) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10162830636713641322U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15646771327759599256U;
            aOrbiterG = RotL64((aOrbiterG * 15333053762177144775U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14841751262270544102U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 9545541117228834895U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 11529769874752969377U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14676615635857599982U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1945905595345404833U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1406171421638586846U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1970292335806697198U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5352135521358954576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15465675376193501658U;
            aOrbiterI = RotL64((aOrbiterI * 16385761112921041387U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2842123638916600369U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3544764287036748668U;
            aOrbiterK = RotL64((aOrbiterK * 3360772950777850115U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6038297172906492282U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10249342332287140970U;
            aOrbiterJ = RotL64((aOrbiterJ * 16701083081566042277U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1662076777040529446U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1949705569959740274U;
            aOrbiterH = RotL64((aOrbiterH * 11340691546658994529U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 54U) + aOrbiterH) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterK, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 34U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordN;
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBE350F013A977CD3ULL + 0xA2BEAA53233A2F4EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAE5FC2C0688DC541ULL + 0x93D1030400C36717ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFA243B82A5C46677ULL + 0xEF59135DE49C21B9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x97E51DB24758050BULL + 0xD87F43E395F5F5C3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD9F8EB0C2FDF314DULL + 0xFC966B26791CF52DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEDC4D4AD80F4930DULL + 0x80ADC97808788B64ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDC8EEC93C4277D69ULL + 0xF4412C680004EA13ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB0AB8ED6996FF859ULL + 0xA7BA90B65A239DDBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA9DA88D490B4E5CDULL + 0xCC3F96E42A543701ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9047C4B1BA160FF5ULL + 0xA6E5FE7C2698A49EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE033B06FAB81145BULL + 0xEA9D243D40CF729BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEFC70BC2A09AE527ULL + 0xD0DDFF6A7A9305F5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFE34744301C6786FULL + 0xC1BBF42833F8B23AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCED71D3BA0A69C2BULL + 0xDA12D47D018C412AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCC9FC2B34177463DULL + 0xAD698352060B7B21ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE5E326F9771850DULL + 0x99DD7AB100D46E95ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4126U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5313U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 779U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6191U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 1210605127156905516U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 11964595428173569519U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 13U)) + 16277319029916258482U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 24U)) + RotL64(aCarry, 57U)) + 12369497463101824572U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 53U)) + 6201248574067068202U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1727477025667206661U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 1404510627789806851U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 4810039298122529021U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6948213591282018925U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6688865181284421478U;
            aOrbiterH = RotL64((aOrbiterH * 12619122841662247279U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3351130769402360855U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 12681032488906270823U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 3680893896579741263U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3591412591193726763U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16153817571210878589U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4165137036092246349U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3808228354421006630U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 4534374093769595531U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 40U)) + aOrbiterG) + aNonceWordL) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10194U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 8627U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12115U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14852U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 3248574644570178787U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 4506961512959200024U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 41U)) + 8423739774540738590U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererI + RotL64(aCross, 11U)) + 6593975869641735337U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 39U)) + 16441716090557369103U) + aNonceWordH;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 7936601450453207914U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 13333752583560167065U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 5389149472324384311U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8013703284795432973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2349852779887439236U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2422888500648100783U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5318539364763284138U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 11450957608502944376U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 1957880366707810635U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9058992558327552687U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 632095686920230926U;
            aOrbiterA = RotL64((aOrbiterA * 12460364388358520799U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14734218428913777098U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16344357661370784442U;
            aOrbiterG = RotL64((aOrbiterG * 15049472842002138369U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 14U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 24U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17317U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 24312U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22996U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23639U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 13U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 30U)) + 7896237440058555694U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 11870529476037558635U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 9158983227801569448U) + aNonceWordI;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 4710172270996950329U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererE + RotL64(aScatter, 3U)) + 14634482800356647630U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8822207952170610891U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13755891414028982553U;
            aOrbiterJ = RotL64((aOrbiterJ * 5173750624716006485U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4555293067488040719U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2816805148093762081U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16838149138341713943U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2122631477965135190U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4592922416380416071U;
            aOrbiterE = RotL64((aOrbiterE * 11644507904538573165U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7102471666524164715U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17274623547879474204U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 938587316977094680U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 18258015823797023523U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6068819567674605919U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 52U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 4U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aNonceWordM);
            aWandererI = aWandererI + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25927U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29955U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25183U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 27233U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 966899917801652720U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 53U)) + 10996327672320748649U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 26U)) + 4188171566846621107U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 5886209243097387959U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 14940428957136728111U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 179187285531914832U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6685351948936817752U;
            aOrbiterI = RotL64((aOrbiterI * 15533370414711696803U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1894506461704029700U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4182760368636977082U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 972988091869133921U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12523318028514940790U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5059306166973366892U;
            aOrbiterG = RotL64((aOrbiterG * 2857409765717296483U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5890872367917643851U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17747338389865221534U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5306740664798049267U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13906227834259884100U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7152105382899756368U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6772157117358310485U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 4U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordO);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCD875E26142144E5ULL + 0xF6F57BB92254A512ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x91FE3CD99DD86B09ULL + 0xDFBAC0B209FA4DF2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEC39C654B090B175ULL + 0xF58EE47FD6A5B4FDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB2450C147C4A218FULL + 0xAF0A0D7DAF70C67DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA28B65E0D1A96697ULL + 0xD0BFEC27F53DC568ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA37AB934DC53E4B5ULL + 0x9364214898A6956FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFB11DDCFD0E09A6DULL + 0xAA8C7CBD96818493ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x963FA4A9819AC3FDULL + 0x99CFC913BCE1AE31ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA94E0F22B41B43EBULL + 0xD1B907DF7B78CD81ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC2FBDFE322A84E83ULL + 0xD5A02631796964ECULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF119FBA0530E1F2BULL + 0x904933924BE9A408ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9A85B4DC50BC6645ULL + 0xA42BD3085E7FE477ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF99401606DCAAFDFULL + 0xE0DB490F26B67E67ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x827097E7B0174A7BULL + 0x91E16C5858F83420ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBAC9E18DF1E702F7ULL + 0xF4A594233D867920ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE4FABDD0BEAC3FA9ULL + 0x9576AFC5C3F60F07ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4589U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 2211U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 209U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4623U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 11039986441331892533U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 6256024955965426119U) + aNonceWordG;
            aOrbiterH = (aWandererH + RotL64(aCross, 47U)) + 9857443189988995666U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 21U)) + 11900944813380998208U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + 8422577734978875541U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 3100835100713928724U) + aNonceWordD;
            aOrbiterD = (aWandererF + RotL64(aScatter, 53U)) + 11871553509810206993U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17614749493763417027U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3638372131856199916U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 480683274898147025U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6582275259281025770U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17016882418498941958U;
            aOrbiterE = RotL64((aOrbiterE * 4269869255230867823U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1747214688658984715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9356088987044015278U;
            aOrbiterG = RotL64((aOrbiterG * 16221733545319753695U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4056238112133473456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16013150119949532998U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12913648646318115315U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16076621211111834889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9940824359571581765U;
            aOrbiterI = RotL64((aOrbiterI * 11624767861336495331U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15624084004784515753U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7630989544834680335U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12261063237156822067U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18003586430673313786U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1654118743290334161U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 1153250137357176071U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 18U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 14U) + aOrbiterJ) + RotL64(aOrbiterH, 58U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9576U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 15988U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10323U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 11757U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 11U)) + 1042610313571524121U;
            aOrbiterK = (aWandererC + RotL64(aCross, 5U)) + 3505725321008825582U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 12584654563843782991U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 6645399144515770935U) + aNonceWordP;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 3608978423753715584U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 50U)) + 8089198857670370983U) + aNonceWordL;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 57U)) + 15207251813516399879U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9579268660105824516U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 2269649280637188723U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 583811872609805949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7027491967970873942U;
            aOrbiterI = RotL64((aOrbiterI * 12686754713465826139U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18256061823189677508U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12169216645156306078U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12694325407567795065U;
            aOrbiterK = RotL64((aOrbiterK * 3711789483877261899U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16109994660203297503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4234704064165718913U;
            aOrbiterF = RotL64((aOrbiterF * 730085881474787681U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14119541943554602878U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8777769004811352951U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 2556957257736134223U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 15642663488392549609U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11594468530833278624U;
            aOrbiterE = RotL64((aOrbiterE * 6639306656361601143U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 28U) + RotL64(aOrbiterF, 42U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21545U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22882U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23231U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 16530U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 60U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 9435962834163239322U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 10524704356081318973U) + aNonceWordF;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 44U)) + RotL64(aCarry, 11U)) + 7403401305665208680U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + 7525414805023556493U) + aNonceWordJ;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 5U)) + 1116686470029070951U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 19U)) + 13257612299137802420U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 53U)) + 9181543003986598283U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9739384852307501107U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11308402900229016057U;
            aOrbiterA = RotL64((aOrbiterA * 12690186771773188967U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14935167593705272337U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7171824007631943535U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4839974427616194289U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8068411284829563567U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12350207458513447578U;
            aOrbiterB = RotL64((aOrbiterB * 813973258659041895U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17039236343991574134U) + aNonceWordA;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 18291683592714999632U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 7771718817924840713U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6239616841884430968U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10604527977569876774U;
            aOrbiterE = RotL64((aOrbiterE * 6972820410084939637U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1707724300671717658U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3802268808625297647U;
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 9423064323799920219U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 242153923313096551U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12117679073775630197U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterF, 36U)) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31837U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26319U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32086U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 29277U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 42U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 15383045568644941552U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 41U)) + 17452811657750910067U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 15660117718455155603U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 10396441207743665753U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 43U)) + 3708971058200841442U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 11U)) + 7000673057768598750U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 53U)) + 9886354469011131596U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16018065329058043467U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5024756166109352320U;
            aOrbiterG = RotL64((aOrbiterG * 11660932185479046483U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6587818720728886652U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6307315649915348048U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16405347331742979258U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7183142442906743699U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5427299664054601957U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4983381733483185898U;
            aOrbiterA = RotL64((aOrbiterA * 14646556236306407673U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10182995521328377487U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8694282877540593550U;
            aOrbiterC = RotL64((aOrbiterC * 14614602561910403893U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4085927978153269932U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16792916528959579875U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6966742100601433005U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9920952446921247521U;
            aOrbiterJ = RotL64((aOrbiterJ * 1879821050131820933U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 12U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterG, 47U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterG, 27U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 58U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordH);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE9BDFC3BAC187381ULL + 0xF3F82A6FEA0E7498ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFB2BAF6F83263311ULL + 0xDC5A6E926F6FAF4AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB9FB900DD9401AF7ULL + 0xCCFF5F5A4A983B12ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE5B1D285FEE0C6B1ULL + 0xA13327025E0B4EF7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF989EC6003792313ULL + 0xBE96A201D929110EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB9755904ED2E6CD1ULL + 0xED25E3E18CC8762DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC30D0DFDA94FBCD5ULL + 0xA0AB499129F3AF3CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB3245E1661BE8C2BULL + 0xFC87CC0EBBD7782CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB51277F9C661135FULL + 0xCD49803B9F23C651ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF6DD4A2CC5B476B5ULL + 0x86CC0D2C650095E6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF761FD2991888A45ULL + 0xB62C3F49874F515BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEA705669CF545549ULL + 0x86271A64B1823DF5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA5ECE1805566E58BULL + 0xCCD169B484C295ECULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDCF0F6498BBEFC47ULL + 0xBEF1A34DA4E3B4D1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFA07DC49D8478217ULL + 0xAD6B8FCE6FD6E10DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFFF9FB443CE1C43DULL + 0xCA32DF9683FE919AULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6698U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5676U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6134U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 7331U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aIngress, 35U)) + 7075016829833562104U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 27U)) + 8783765886115517036U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 2996723892384565829U) + aNonceWordE;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 9494134707342189476U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 5052642981395679904U) + aNonceWordL;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 21U)) + 8766787055127962238U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 4467211954388738079U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8030255604633658608U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16962408063455702251U;
            aOrbiterG = RotL64((aOrbiterG * 11171737929747471631U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3768222186567699076U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14930990410207899871U;
            aOrbiterE = RotL64((aOrbiterE * 10930005786146268241U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 14179761938395502502U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1879084742719898108U;
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5535012408925981515U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12792553516710295939U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8979253163346099252U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5559189896063990740U;
            aOrbiterK = RotL64((aOrbiterK * 8832485423727331621U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13937564337299044079U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2393376759689394948U;
            aOrbiterH = RotL64((aOrbiterH * 2352815657830413941U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12647519563697356479U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10946871249960389549U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6272580371881237173U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + aNonceWordF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16013U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10201U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14577U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12793U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 4739486756133131180U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 38U)) + 16089707555501328184U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 5U)) + 15310047330238536453U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 7901411596386834955U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 4357555491060982163U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 11U)) + 15667085602825720102U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 8520635334382269253U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1772509779231068315U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15336170957886025677U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10996880551392077399U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 8628770833489469980U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15469234024247246228U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8905266995119987947U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10796430900884288328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10660110397012853289U;
            aOrbiterC = RotL64((aOrbiterC * 9140007610912037461U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11202284258711214794U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17509491802893182994U;
            aOrbiterK = RotL64((aOrbiterK * 9329107599972703671U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16212572740740103554U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 2190030203761579226U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 3101886685668871045U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12014337082293041909U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3733531010807001506U;
            aOrbiterF = RotL64((aOrbiterF * 5797362244066062299U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7100994963061975529U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17837541162838600258U;
            aOrbiterA = RotL64((aOrbiterA * 8745987361678166553U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aCross, 26U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 57U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterC, 60U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22165U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23375U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23547U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 20222U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 17264605017518259932U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 57U)) + 15209184354580778643U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 3299527965014731384U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 50U)) + 16293096431816127821U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 11031983436878828337U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 3U)) + 9188018632448236358U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aIngress, 35U)) + 13420816400363406556U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2485063384097917101U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8813152992957361153U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10730544971770435788U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterI = RotL64((aOrbiterI * 4723078464590561545U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14883796491656899074U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13322163435314643713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4950101626975919939U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2596253994220103666U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 7181706961838582889U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17961706029559914243U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10321902557977495175U;
            aOrbiterB = RotL64((aOrbiterB * 16189559888625084711U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18146616411403012772U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8414050129421955787U;
            aOrbiterK = RotL64((aOrbiterK * 14879448948196182863U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 14U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 28U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29516U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 31315U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29805U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31024U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 44U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 6024062041314952357U) + aNonceWordF;
            aOrbiterC = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 18340757093658015585U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 21U)) + 11911120493880346751U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 35U)) + 17428074353884654439U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 27U)) + 12790849760814795936U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 12633397052172117800U) + aNonceWordJ;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 44U)) + 11946150433665237945U) + aNonceWordM;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16842157900909419285U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14186235783224155962U;
            aOrbiterE = RotL64((aOrbiterE * 10521157787073684417U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 13284904542579767591U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11609181965078844357U;
            aOrbiterI = RotL64((aOrbiterI * 5455780554452453513U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9628562297095374984U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7850281529011259759U;
            aOrbiterC = RotL64((aOrbiterC * 17611485102925470357U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 257458718073794527U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10693404545773519306U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 14821443722828498323U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3430519236533871460U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6183054506953198055U;
            aOrbiterD = RotL64((aOrbiterD * 6121082743789970911U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2905610989884221654U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16870142883133769663U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1403692060594816451U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 9740854430251597879U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 4U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordP;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD02F81BBB13BA463ULL + 0xD14B1F3FF0744718ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB170FBB1B6BE969ULL + 0x99049FA1DA4A91F7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA2B20AC0046E46BBULL + 0x96AA11D777D066CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCD0A8ACB97B3B2DDULL + 0xCE6E4539BCACC7D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF82F6F2CDF5AB3B5ULL + 0xFB4ECBF1645B4EF7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB364D4323A52A0D9ULL + 0x9AA4108720AEE2F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8A09B62E23746EC3ULL + 0xBF9FBCBE8A3C1BB4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD8306852D5AF1A27ULL + 0x93F43DD333358A68ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD4B3C4E2121EB0D1ULL + 0xBBE9C6BA7C75FDD5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB3AB565C588BBCF7ULL + 0xA6767AC6CC5B16CAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE1AEB39ADACE6D39ULL + 0xCB8ED1D6239FF0E7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9CED75595FFFB2B7ULL + 0xE08ED703DD5C4485ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF0978127377DD4DFULL + 0xF1B13D1B38358193ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD0E9A1D5249A341BULL + 0xDA30DC4FF112DED0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9C3B6E0897D2F37BULL + 0xB4B9E0C921122859ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x81E0A7F03AFB6A53ULL + 0xB97F2ECD17384F5CULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7597U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6771U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3672U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 1673U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 57U)) + 11039986441331892533U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 4U)) + 6256024955965426119U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 9857443189988995666U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 47U)) + 11900944813380998208U) + aNonceWordA;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 39U)) + 8422577734978875541U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 29U)) + 3100835100713928724U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 53U)) + 11871553509810206993U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 17614749493763417027U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 3638372131856199916U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 6U)) + RotL64(aCarry, 37U)) + 6582275259281025770U) + aNonceWordB;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 27U)) + 17016882418498941958U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1747214688658984715U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9356088987044015278U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16221733545319753695U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4056238112133473456U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16013150119949532998U;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16076621211111834889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9940824359571581765U;
            aOrbiterE = RotL64((aOrbiterE * 11624767861336495331U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15624084004784515753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7630989544834680335U;
            aOrbiterH = RotL64((aOrbiterH * 12261063237156822067U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18003586430673313786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1654118743290334161U;
            aOrbiterC = RotL64((aOrbiterC * 1153250137357176071U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3254189676528343910U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 15629083361573065165U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17024833368570949107U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10056859810555674806U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15976683222786846254U;
            aOrbiterG = RotL64((aOrbiterG * 2801754232182942635U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11872378594829637933U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7633773773528713489U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8218288492011593353U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16305188578382203720U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13293036594949754170U;
            aOrbiterI = RotL64((aOrbiterI * 1300645662609848183U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15185013801659166674U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11562899709899198100U;
            aOrbiterB = RotL64((aOrbiterB * 9115495024409604629U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1525205566739385260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11039986441331892533U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9802284050237622047U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 48U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterB, 29U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 41U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterI, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererK, 20U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15687U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 11119U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9578U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10566U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 10U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 23U)) + 13053031069776604052U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 54U)) + 1331396630251085122U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 15879286043343942393U;
            aOrbiterF = (aWandererC + RotL64(aCross, 5U)) + 13590365633321406830U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 14569235423040242618U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 11397370636618371560U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 41U)) + 3455933494593971847U) + aNonceWordN;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 3U)) + 1307153376443784593U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 43U)) + 10688618762584786871U;
            aOrbiterK = (aWandererF + RotL64(aCross, 46U)) + 17746248451153600096U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 39U)) + 8512568600755410158U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8950230550112591092U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17790968369472845496U;
            aOrbiterJ = RotL64((aOrbiterJ * 5104988920132008913U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12583323865381967534U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11243927099685293887U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12867003042486433971U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9690268715525781389U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7466066217365074653U;
            aOrbiterE = RotL64((aOrbiterE * 17565696765505320889U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3673528673209875118U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14079103852360952255U;
            aOrbiterG = RotL64((aOrbiterG * 17449228863409999629U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6747836856132250630U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5027692924422297153U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2492421273167124437U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11370341866003395776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14013204893442579282U;
            aOrbiterA = RotL64((aOrbiterA * 6602239957997240785U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3436953430697936790U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6399073534839993637U;
            aOrbiterF = RotL64((aOrbiterF * 14186050072610021241U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7054057507823631422U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5752085719673338095U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13252660162476029593U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10628323020010327594U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5029617362660411790U;
            aOrbiterB = RotL64((aOrbiterB * 7230663968894173433U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6816547880074551571U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 6683840259024813282U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 13145224557159574541U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5952768353050729617U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13053031069776604052U;
            aOrbiterI = RotL64((aOrbiterI * 13710064584055068065U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterB, 40U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterH, 11U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterB, 34U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterD, 47U));
            aWandererI = aWandererI + ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererA, 22U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24025U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18581U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19577U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 21467U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCross, 40U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 48U)) + 380024772508948442U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 7649029098162567210U) + aNonceWordD;
            aOrbiterA = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 5329304598870421851U) + aNonceWordK;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 12306118665045151326U;
            aOrbiterB = (aWandererC + RotL64(aCross, 26U)) + 960751560457324256U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 51U)) + 3244070254386191876U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 11U)) + 15733408571609521746U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 39U)) + 17623448932647018544U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 8787759896149035829U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 41U)) + 14741681792348288162U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + 8801731213568307302U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9872248187499779222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4242060317152943062U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 888649755587764533U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7296348796484458631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15061417216070157797U;
            aOrbiterG = RotL64((aOrbiterG * 10349554676953256231U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3233185810644297433U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 9241229457641024287U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2728237515724597517U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8464051359381554575U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterH = RotL64((aOrbiterH * 4859663401033023433U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5482617843966711997U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4442149210462943872U;
            aOrbiterJ = RotL64((aOrbiterJ * 8979352218576515647U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10591636597580147381U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14925122230279312217U;
            aOrbiterC = RotL64((aOrbiterC * 15038171961638724013U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9772367878232735350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15800661165607190092U;
            aOrbiterK = RotL64((aOrbiterK * 10493976952980533589U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1571665862499272194U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3162847040693387901U;
            aOrbiterE = RotL64((aOrbiterE * 2747235335326991399U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4868791925868749848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13134549226315884613U;
            aOrbiterI = RotL64((aOrbiterI * 3551955270718495869U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7830447320021657240U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 380024772508948442U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 5143324968958616357U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 30U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterC, 18U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 34U)) + aOrbiterD) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25948U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26149U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27336U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32553U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 52U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 12775735908960052604U) + aNonceWordJ;
            aOrbiterI = (aWandererI + RotL64(aScatter, 26U)) + 11791373812080296887U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 51U)) + 5537362877706057303U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 2023912048504189380U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 13U)) + 17668828109963766893U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 558908629933941224U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 43U)) + 1479633119685446888U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 19U)) + 15460320397843364063U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 24U)) + 10059749397555469054U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + 9987633811929693924U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 35U)) + 10087337844580228269U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9430197906134676162U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterC = RotL64((aOrbiterC * 14247538885252664127U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10611580584157624739U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 9327201928815412810U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7890659377013147073U;
            aOrbiterF = RotL64((aOrbiterF * 13827717178378062047U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10675114832750356941U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8804440385852327267U;
            aOrbiterK = RotL64((aOrbiterK * 8520671775587260601U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12871947817782057116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11015991745792051390U;
            aOrbiterG = RotL64((aOrbiterG * 17152451500505815031U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6320437975845673731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 702457937087191287U;
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16629064896250312921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6054107387816339103U;
            aOrbiterE = RotL64((aOrbiterE * 6983767878966747219U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13274874838094190290U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12211422735294360321U;
            aOrbiterJ = RotL64((aOrbiterJ * 5113738196151089817U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15338616110718583619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1475787183754511373U;
            aOrbiterI = RotL64((aOrbiterI * 10904607643785840003U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15486810401396777742U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12775735908960052604U;
            aOrbiterD = RotL64((aOrbiterD * 7478156942468930207U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 56U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 27U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 54U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterI, 37U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 56U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordH;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB831D96718C8E371ULL + 0x87D2BE55E014F219ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x97C7225A04AF5FC9ULL + 0xA5ED6A0E29A7D0FBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8FA3A1203B407591ULL + 0xB90294D4A46A89D5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAA779ED303FB8F3FULL + 0xAABA0FB0539DBEFAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC5F13ED405DA309BULL + 0xB2D00BF3FD88FA9CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE6CE69CBDD3F4EC1ULL + 0xC18297A0CE424219ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB8C1CCC29C99A21ULL + 0xF4160D4DABEE51A9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE8E14D0EF62F94DBULL + 0x91138C5F87DC814AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x81436B2B915310F5ULL + 0xBA1A55FAFA05F68BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF4559C0BE7C01B7BULL + 0xB378E051F9349F6DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC21E0425084D612DULL + 0xD75D0F63029CB28CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD67957D22F10F68BULL + 0xF5EB51BDF72CE8EAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD2A35574C0B2FD0DULL + 0xEC5A03D83D1366D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFDFC15610FACF72DULL + 0xBEDA7E151BA91BABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEA69A3F850831F15ULL + 0xD2EAA3CD45548F28ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB10AF915869A8197ULL + 0xF24B19420855EDBFULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5194U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 4367U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 559U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 2723U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 38U)) + 3236820517816085022U) + aNonceWordJ;
            aOrbiterI = ((aWandererH + RotL64(aCross, 57U)) + 741288875914097926U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 27U)) + 8417246926007729580U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + 9715717805774537170U) + aNonceWordB;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 14360243844821619482U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aCross, 34U)) + RotL64(aCarry, 43U)) + 10760908100206775334U) + aNonceWordM;
            aOrbiterE = (aWandererD + RotL64(aScatter, 47U)) + 3434641779946167811U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 7885568822756234567U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 5U)) + 3041563437672051294U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15761355327564963516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1158633562785937421U;
            aOrbiterG = RotL64((aOrbiterG * 15511324886867188235U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9338581575871970653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9172038894262857354U;
            aOrbiterH = RotL64((aOrbiterH * 3110871165285625807U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14653924713599790081U) + aNonceWordD;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 3854497592598563309U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 11737111068815795303U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16286980180327600557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5092583772591249756U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4288397994175567333U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15584236478994873104U;
            aOrbiterC = RotL64((aOrbiterC * 1860480595862755379U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5557463939827483792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2659814275753280856U;
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6941807963525063449U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2040598555191211307U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14750544987531722765U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 347572666231116258U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 779304821185302523U;
            aOrbiterI = RotL64((aOrbiterI * 14180254150318109855U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10632524582873079742U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9761308771280517212U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13926235411726048921U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 58U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 52U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + ((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aNonceWordH);
            aWandererA = aWandererA + (((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 37U)) + aNonceWordC) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + aNonceWordF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7353U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 8857U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5544U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8006U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 38U)) + 5697928251815176134U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 53U)) + 337587740689259575U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 43U)) + 4927686903263973950U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 3742409032569801033U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 14U)) + 1608092659172197650U) + aOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 15848744267145717509U) + aNonceWordJ;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 29U)) + 15300174177963339253U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 14162868453323648628U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 12020167069983729869U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16259538291658723956U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8516686212464112245U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 4731296903548893627U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3722184575520553132U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterI = RotL64((aOrbiterI * 14364218128780764749U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15265344442454471986U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1093356813820599238U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5719466863561311069U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15170797965325981472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17826286701992981628U;
            aOrbiterJ = RotL64((aOrbiterJ * 11186808881726573677U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14710892030473425181U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 397194787697553904U;
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1273724124862533034U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9638716186445643730U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7255587739807843785U;
            aOrbiterG = RotL64((aOrbiterG * 6055682981584011189U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9272350563697399628U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1040729335295009339U;
            aOrbiterE = RotL64((aOrbiterE * 17825687660830291443U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 14U)) + aOrbiterA) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterC, 4U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16281U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11202U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15598U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14300U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 6068543441070417854U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 41U)) + 2995980468193441856U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 30U)) + 18020277482171594003U) + aNonceWordI;
            aOrbiterE = (aWandererE + RotL64(aScatter, 51U)) + 4293807434721230702U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 47U)) + 7980599111583893156U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 35U)) + 8593141111851052016U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 12U)) + 5903487523900084325U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 15112035513447930209U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 9854037263057006439U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16759760289688823193U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12622628933030601390U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2151912984825538321U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1264668857268123425U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16302812053619101593U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18291400055836111547U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16087995784896123610U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7970269262800468363U;
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5331477046030959632U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16534913204255550893U;
            aOrbiterI = RotL64((aOrbiterI * 1013433634373673565U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11042821902537871209U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8069677512345031660U;
            aOrbiterJ = RotL64((aOrbiterJ * 13622218526054132397U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5737130058129936372U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1076627182956662997U;
            aOrbiterC = RotL64((aOrbiterC * 14342191224014199929U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13911061091801078190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15397603151098990373U;
            aOrbiterB = RotL64((aOrbiterB * 1802890451633592245U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15137326716738637972U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11248737008959896786U;
            aOrbiterK = RotL64((aOrbiterK * 90789374131547005U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1847847987633923657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10560748778679145431U;
            aOrbiterA = RotL64((aOrbiterA * 2919333327817231099U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterA, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 37U));
            aWandererH = aWandererH + (((RotL64(aIngress, 20U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 56U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20720U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 20397U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16647U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 20808U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 18U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + 6654158889644956636U) + aNonceWordN;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 9045779659363991870U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 13U)) + 3888897662136993491U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 28U)) + 6882016842864459345U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 53U)) + 15601891715956172291U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 43U)) + 5176811598629335350U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 12519945150889074325U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 4552583214397603278U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 58U)) + 14225482701804864688U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5485298070606280363U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11237713257388094289U;
            aOrbiterF = RotL64((aOrbiterF * 11032429223099413011U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 14340345895626142788U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16275167270553643347U;
            aOrbiterB = RotL64((aOrbiterB * 7308578867128951199U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14041860597556520250U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1436068974197066343U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3938460345031496843U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11483155566419547004U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4608508534724289325U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13461385011638899485U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2389196334288832895U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4062682330273866602U;
            aOrbiterG = RotL64((aOrbiterG * 8787682133271101901U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5655656046585592034U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7977947821249746880U;
            aOrbiterI = RotL64((aOrbiterI * 10082104644185964787U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11653718118543974168U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5456429682072377614U;
            aOrbiterA = RotL64((aOrbiterA * 12504180638665296649U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12457179652004203574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 445821754230182952U;
            aOrbiterJ = RotL64((aOrbiterJ * 16043092621697786393U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12429505513284703263U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12480745784412363537U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 643617210585287593U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 40U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 14U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 23U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 29U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 5U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 60U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24733U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24076U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25671U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23551U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 10U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 43U)) + 1952750591494698524U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 58U)) + 4488270851303332830U) + aNonceWordE;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 29U)) + 2738763375328927635U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 6728843649480454340U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 10490717875258865358U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 10U)) + RotL64(aCarry, 23U)) + 1429288737812910205U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 53U)) + 2761375016998907636U;
            aOrbiterG = (aWandererE + RotL64(aCross, 23U)) + 1088988605204499835U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 39U)) + 6829840407300289709U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9267240337867690471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8120113021183975703U;
            aOrbiterB = RotL64((aOrbiterB * 14296504593187173107U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1340980511302566784U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11874452169979878835U;
            aOrbiterC = RotL64((aOrbiterC * 8638486178860092537U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1872314794140971426U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6013952618696225751U;
            aOrbiterG = RotL64((aOrbiterG * 7994863587373565715U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3644011378086236002U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8501867691997891731U;
            aOrbiterF = RotL64((aOrbiterF * 7115282675461711509U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2493546555198066143U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5179240189571799179U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1267579130962756135U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11273348247858394197U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4577476419423118925U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 8427261005061162673U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6201955123046621919U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3930651302557530185U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1563512534463027965U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7571426325227856019U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11098508505512361002U;
            aOrbiterJ = RotL64((aOrbiterJ * 9229352429618815089U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6154830144380484305U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4282054616147137364U;
            aOrbiterD = RotL64((aOrbiterD * 14984813139796280171U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 39U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 12U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 28U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27464U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 29548U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28705U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 30744U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 56U)) + 3621877681473089725U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 11U)) + 4451752751536414717U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 11371625415377772117U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 6046792758881150619U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 29U)) + 8213166120394461682U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 3U)) + 4343156661140422645U;
            aOrbiterC = (aWandererB + RotL64(aCross, 43U)) + 11105271483234947905U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 348904609985341372U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 52U)) + 12924652822526858767U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7461211697358520287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16551553555297890558U;
            aOrbiterH = RotL64((aOrbiterH * 16432952324635746293U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11908056404140782995U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9147367258259948715U;
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8876461054692728610U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10546855952702525404U;
            aOrbiterC = RotL64((aOrbiterC * 10071104785895309677U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4748636139110443794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 783046909529525098U;
            aOrbiterJ = RotL64((aOrbiterJ * 8969157702460927215U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16683965945838696665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12385412690177109575U;
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8210546822184469023U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13146493623236979963U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13199947810161148155U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13857628148804187115U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7241297989337473475U;
            aOrbiterK = RotL64((aOrbiterK * 16223448508809614229U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 773904571213804946U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7660676598236419707U;
            aOrbiterI = RotL64((aOrbiterI * 14467390638468925567U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16822672435156055469U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 6514707119190640433U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 7097496727567460535U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 30U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aNonceWordF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 58U)) + aOrbiterI) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterK, 53U));
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordP);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA3707AA46FD2F6A3ULL + 0xDDD64918CA3DA484ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFD80F5BEABE8A2C9ULL + 0xBFED2E85A4A74065ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x98BF1C613758A4B9ULL + 0x93DBEB63F6134E4CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x80188457FF2B78B7ULL + 0xC248091396655B5EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x87DBC1D12D2CD98BULL + 0xACA9E3590A383B49ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB9BF4B08D966E847ULL + 0xF4F54DA2FD0121FCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBDD2735BB441D705ULL + 0xB216CCF9600F59DFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF3A06E7306660469ULL + 0xF57F31D80B75A495ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8560BBD9FC4381DFULL + 0x842A60592886CE43ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x848264F355A3A269ULL + 0x888EF4D214C5B94CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA117A24C32B40EFBULL + 0xBD7BBA9E24F90E2BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCBC5943D1C6B9281ULL + 0x830D51D3CD5F7CF9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA058BE45B392BB49ULL + 0x8367CE4A8FC454C6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9CEFF5653520EB6DULL + 0xBAF9C631B276A8C7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9FBE5E8817C2A38DULL + 0xA832D6F61F86C6A7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD654F07B4AF1398FULL + 0xC0BADC4EAA76AD53ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 856U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2831U)) & W_KEY1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3888U)) & W_KEY1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1761U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 5960680319644404115U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + 16050752633567034185U) + aPhaseAOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 30U)) + 8447503223226854741U) + aPhaseAOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 23U)) + 14176813813397917591U) + aNonceWordM;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 13U)) + 10534915376130006644U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 6866224454375302514U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 16506374165041008396U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7167814023968794098U) + aNonceWordJ;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 13870852197416596664U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 17015971222069856463U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18064038854848993105U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9869630811507771691U;
            aOrbiterE = RotL64((aOrbiterE * 13723164383800461387U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 863613100452759380U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16597969741225436529U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2680793528887208903U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6575347108051310653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17062262265485019063U;
            aOrbiterC = RotL64((aOrbiterC * 7601045488473620019U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7193399224636409133U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14146747818810433849U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5273185769989530041U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9441449106442431427U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4303295336545399503U;
            aOrbiterA = RotL64((aOrbiterA * 8829695296836242587U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12604760768543193458U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15779327512379787715U;
            aOrbiterD = RotL64((aOrbiterD * 14000905201441272597U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterA, 53U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8551U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 9242U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7608U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 10464U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 20U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 3612110001869385068U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 16340824141280225936U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 15222338965130765231U) + aNonceWordJ;
            aOrbiterG = ((aWandererF + RotL64(aCross, 13U)) + 6649270508107155041U) + aPhaseAOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 768217258655426384U) + aNonceWordF;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 20U)) + 4481855259658861851U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererC + RotL64(aCross, 35U)) + 18318041934562434016U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4212457153804401807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16143621095636987628U;
            aOrbiterK = RotL64((aOrbiterK * 6576072860505961427U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2095664232866642086U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4339527736737366572U;
            aOrbiterF = RotL64((aOrbiterF * 17503569508822244125U), 29U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 13679353177869884790U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11582168502846418236U;
            aOrbiterG = RotL64((aOrbiterG * 135539430034462861U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10451330452898542191U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12951448817640617841U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15389161934419370747U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4754886272708253014U;
            aOrbiterC = RotL64((aOrbiterC * 16638243718191281597U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11746389873929280688U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12042680172517298768U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2648103752465009244U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 451594673632597973U;
            aOrbiterD = RotL64((aOrbiterD * 8496763663271072425U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aPhaseAWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 20U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15600U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 12713U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13919U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 11331U)) & W_KEY1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 44U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 5U)) + 15904465836916519864U) + aNonceWordE;
            aOrbiterF = ((((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 17725629806317789307U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 13794170125914914828U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 35U)) + 2149055907476874332U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 27U)) + 5342047776745074649U) + aPhaseAOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 8268148484060546838U) + aNonceWordI;
            aOrbiterJ = (aWandererG + RotL64(aCross, 56U)) + 10821151364028563719U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4294213820894407378U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10884726101307943090U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1116128870387229159U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16432210042202444824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15196602644336228055U;
            aOrbiterF = RotL64((aOrbiterF * 12680438355124070237U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14117787670220328165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 219833877949480215U;
            aOrbiterG = RotL64((aOrbiterG * 10736293047771972173U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3326396981881473962U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 14918513066311426279U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 14269763278564574663U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11795234681370163206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3068267285352664813U;
            aOrbiterD = RotL64((aOrbiterD * 15746255933920904619U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 245233356957999496U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 709926406353796673U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13627039596842073595U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5378105439430271038U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10114555061122044430U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5351295043424885549U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 10U)) + aOrbiterD) + aNonceWordO) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20728U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20975U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18158U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 20438U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 43U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 28U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + 11698283336767769359U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 40U)) + RotL64(aCarry, 53U)) + 13297826354831483872U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 15254999058287530795U) + aNonceWordK;
            aOrbiterB = (aWandererF + RotL64(aIngress, 27U)) + 17474166585085346567U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 5U)) + 15684783498452840289U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + 5061229733465216486U) + aNonceWordP;
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 15370981279168377944U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17966672773619554092U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14685092893994491068U;
            aOrbiterF = RotL64((aOrbiterF * 1627758964162892429U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12798804186209406389U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2848444181474221574U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 13730480364920876877U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8551142075919636146U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8833198159158950723U;
            aOrbiterC = RotL64((aOrbiterC * 7650289040764974737U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7351473160893666232U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14204899612487622222U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6317485031956448029U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7008985178526543258U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13576796403863120356U;
            aOrbiterD = RotL64((aOrbiterD * 13745839827679114077U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5769784656937900699U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14075925808204936705U;
            aOrbiterB = RotL64((aOrbiterB * 5844894088757604713U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17818667502858010896U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16016922065572683130U;
            aOrbiterK = RotL64((aOrbiterK * 7525645833898085373U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 48U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 41U)) + aNonceWordL) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + aNonceWordG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 6U));
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24041U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24518U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26027U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22182U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 252059974543142812U) + aNonceWordL;
            aOrbiterD = (aWandererJ + RotL64(aCross, 35U)) + 11690823093681457368U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 21U)) + 13282189752890971123U) + aPhaseAOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 9507416294305708435U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aCross, 13U)) + 14053038174390776539U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 14605253312318725009U) + aPhaseAOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 48U)) + 18138286582677863671U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8530091235978489988U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14381731677571170073U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 11675896999665768253U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13316413456378978456U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3910529530149320706U;
            aOrbiterH = RotL64((aOrbiterH * 16000139333493588429U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 6302070286831566901U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12324134652758551396U;
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4773478557638475048U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4031153435446078944U;
            aOrbiterD = RotL64((aOrbiterD * 3876928995240982769U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3114794895962903899U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3552936509969106796U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16823186892738820299U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5828754613946145627U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17985241114076114558U;
            aOrbiterG = RotL64((aOrbiterG * 1986669631395606833U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11319331046368072261U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6104267020171882160U;
            aOrbiterJ = RotL64((aOrbiterJ * 12525117969211576177U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 36U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + aPhaseAWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 4U) + RotL64(aOrbiterJ, 20U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27770U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30097U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30999U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 32241U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 4U)) + 2330952702412094686U) + aNonceWordJ;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 7820188225935060799U) + aPhaseAOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 9347644591709839145U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 23U)) + 2288624878446846870U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 13U)) + 9358977729492824128U) + aPhaseAOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 1858511275052455039U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 29U)) + 13715478509322292552U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16413396625604260455U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17714322215518432705U;
            aOrbiterF = RotL64((aOrbiterF * 1904184102419934333U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16188315436202861122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5564445841368207813U;
            aOrbiterC = RotL64((aOrbiterC * 14125834616162835983U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13717068949900594673U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14143659432287313765U;
            aOrbiterG = RotL64((aOrbiterG * 17281441046722262917U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5729546141908425670U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4297827922736712074U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 829520109395163673U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11547160328525174295U;
            aOrbiterD = RotL64((aOrbiterD * 4759690159673049775U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2907177944512117206U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11100346409065275671U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17927994356809011637U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1344592529249949068U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6470438516791143572U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13339390828725370475U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterA, 53U));
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererK = aWandererK + (((((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 19U)) + aNonceWordN) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 42U) + aOrbiterK) + RotL64(aOrbiterG, 60U)) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAACEA21685AFC2FFULL + 0xAD59EDB3D42ED9F8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x91114FE3A9751BDDULL + 0x86AC5E7E5F19CEFDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE8AE7CE601D3F159ULL + 0xA8CC8557350F900FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE9F6F8F2E5FFF5C9ULL + 0xD9AE92D4E646A1C2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBA4C5410C1DE7B97ULL + 0x912E0DABAF8FDF2FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDE4AA889967218ABULL + 0xFA5281DFCD1E6626ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8039826ECB857B25ULL + 0xA5E11AC5D2A99973ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD3684B6A1AE524EBULL + 0xF3A79689729702A4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x983212E37B1D0BA9ULL + 0xAFD4FA9A47AD2FC8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC495DA3EE07B7EB9ULL + 0xE882D4479E10ADC3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB83256BB256EC2EBULL + 0xD1C6508FBA35F3CCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x86662833D10931C1ULL + 0x95F6F873107D9A88ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC2F65EDE5BA00589ULL + 0xCF81FBE9C3F15B52ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE7945F68A817940FULL + 0xA03799310B09BFD7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC038F934DE4EBCD7ULL + 0xB3DFC23C2DE93885ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x84F531D909198789ULL + 0x89C164D6E5B48AA2ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5100U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 2098U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1783U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 2198U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 4U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 11U)) + 1042610313571524121U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 36U)) + 3505725321008825582U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 12584654563843782991U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 6645399144515770935U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 3608978423753715584U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8089198857670370983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15207251813516399879U;
            aOrbiterI = RotL64((aOrbiterI * 7596841660069752069U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9579268660105824516U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16055044469473802812U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2269649280637188723U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 583811872609805949U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7027491967970873942U;
            aOrbiterA = RotL64((aOrbiterA * 12686754713465826139U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 18256061823189677508U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12708429127816136937U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 12593886633108075321U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 12169216645156306078U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12694325407567795065U;
            aOrbiterJ = RotL64((aOrbiterJ * 3711789483877261899U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 38U)) + aOrbiterI) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aNonceWordH) + aPhaseBWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 27U)) + aNonceWordF) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9836U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 7693U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10139U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 6008U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (aWandererE + RotL64(aIngress, 11U)) + 11177787645248006236U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 3808340254579817169U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 29U)) + 828030667598518279U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 16177835921238398371U;
            aOrbiterD = ((((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 5518747735458708741U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17346319082399995165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6397156921893030937U;
            aOrbiterE = RotL64((aOrbiterE * 11203064569634132929U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15559381654710713582U) + aNonceWordA;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 940404446491415088U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 16401260971303026881U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8047166032048732645U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4688468645859470491U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14383536431614496369U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3710878044770337260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 116343189456629220U;
            aOrbiterA = RotL64((aOrbiterA * 5637725064169289339U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 883908030159391659U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 18058691521694880482U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 3132200449123497619U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterB, 28U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aNonceWordL) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12453U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12201U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11552U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 11466U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 52U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 60U)) + 17081642665820489793U;
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 14468854040067229623U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 2249450222593057429U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 37U)) + 14964389079511378664U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 17003491054252360650U) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12710882240582032588U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9887078182156755359U;
            aOrbiterE = RotL64((aOrbiterE * 8205865025853482573U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7665284531810584704U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7304284015511876717U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6193179739025093929U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5517927023543751734U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17704756310857362759U;
            aOrbiterG = RotL64((aOrbiterG * 15826832172923213591U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11347400363019508578U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11696395232760991243U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9725231749679442003U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10875780291242873583U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7808740614343437672U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8889516201913716283U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 6U)) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aNonceWordO) + aPhaseBWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17012U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 21104U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21044U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19251U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 26U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 42U)) + 14157904117287696136U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 7369512677371640676U;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 8411250745902073798U) + aPhaseBOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 19U)) + 5002041814539710275U) + aPhaseBOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 9538041410816283124U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5210700103927513061U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7600709399101287982U;
            aOrbiterG = RotL64((aOrbiterG * 6777896926889560889U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2366369466696580499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5544575244203019109U;
            aOrbiterA = RotL64((aOrbiterA * 16231219246786333057U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8710073749110329779U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 15998211310115361630U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 15354357553877376422U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10657523549259276169U;
            aOrbiterB = RotL64((aOrbiterB * 13695239532898311073U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10405750198355464768U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 3465819693133515142U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 14678343718277562799U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + aPhaseBWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterA, 53U)) + aNonceWordG);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + aPhaseBWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22001U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27133U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24971U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26391U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 28U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 2974056819475622600U) + aNonceWordO;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 7345051759236356098U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 12738468816846628882U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 30U)) + 7694520596043297922U) + aNonceWordM;
            aOrbiterD = (((aWandererF + RotL64(aCross, 53U)) + 5530753590015084774U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3776309161718383105U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 784780304358106404U;
            aOrbiterK = RotL64((aOrbiterK * 1503119308251871519U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8999942326995036509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5194986506064092779U;
            aOrbiterD = RotL64((aOrbiterD * 15070787038006135963U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7920040007459652762U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11311997270710107937U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 6227571709361790209U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5365231114813547251U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8630110234623825263U;
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 2358235238039571072U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18059414891616491807U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 17150786106857185467U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 6U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aNonceWordC);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + aNonceWordJ) + aPhaseBWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30214U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27541U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27542U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 27681U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 4U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 39U)) + 13053031069776604052U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 1331396630251085122U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 13U)) + 15879286043343942393U) + aNonceWordC;
            aOrbiterC = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 13590365633321406830U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererJ + RotL64(aCross, 35U)) + 14569235423040242618U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11397370636618371560U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3455933494593971847U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13051161161405358793U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1307153376443784593U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10688618762584786871U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 9503823896874842411U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17746248451153600096U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8512568600755410158U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16648320170768234063U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8950230550112591092U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17790968369472845496U;
            aOrbiterC = RotL64((aOrbiterC * 5104988920132008913U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12583323865381967534U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11243927099685293887U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12867003042486433971U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 36U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aNonceWordK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ aNonceWordJ;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC9A4D8FAC6081943ULL + 0xDCB860469BE69069ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDCE216A911952B1DULL + 0x898602EFF85ABBECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF84C6D2391ADC2BBULL + 0xE7C160F39E934AD6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF8E78A436A4AC2F9ULL + 0xDD8F318470C5CCA9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBDC3FC0673D27685ULL + 0x8D06CA02B24F9CA4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD58148566CCEC3A3ULL + 0x99D6A1BEE00A1CA2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9F01050652102521ULL + 0xD0A37D88447A5E93ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x85ADEF4A51DEA2D7ULL + 0xA191FB4715C3986FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE7636ED13549D751ULL + 0xFAA1E53BA10CD8E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD36FCF6F96C73FF3ULL + 0xFB75511F41EFDAFEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCE49C7637C86EDEFULL + 0x934AE2F525E3C2EFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8AFD121A91047335ULL + 0xE16A76B303891A38ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDDD10D38CD280C49ULL + 0xDE65044E6CAB7C1AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xED52195F757F67CFULL + 0xBC69CB8B22E776A0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xACF7EAC4E052D6EBULL + 0xF59997BB74863800ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE86D01AFA0B60C9DULL + 0xCFA789CFD824FE8DULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7993U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 6729U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 263U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 1440U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 12U)) + 439898681482066326U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 17362083676671776094U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 6418499837265155024U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 5U)) + 17262244253027454972U) + aNonceWordK;
            aOrbiterK = (aWandererG + RotL64(aIngress, 53U)) + 2382066162993139503U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + 14345808395587174135U) + aNonceWordI;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 7534743166385552851U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 60U)) + 16994453324688523966U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 43U)) + 7079553728544045092U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3562822704508440641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13990892681975857821U;
            aOrbiterG = RotL64((aOrbiterG * 8352929306654078795U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1796728922368577238U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 6605161260520067178U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8147537646591674091U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13994083795942328918U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6144523182899107711U;
            aOrbiterF = RotL64((aOrbiterF * 4153879991344611283U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12247462325297436642U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1065809332002012789U;
            aOrbiterD = RotL64((aOrbiterD * 5496601177032953251U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10147919864511540753U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17138553441127273354U;
            aOrbiterH = RotL64((aOrbiterH * 5773875596275267871U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2653924016109573974U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6254416952351699582U;
            aOrbiterJ = RotL64((aOrbiterJ * 12756861659704947257U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 813046408080197079U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9624466135414123483U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6960320253124395015U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 972586705850825744U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 155283774901960223U;
            aOrbiterC = RotL64((aOrbiterC * 9928051687724257041U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 18200100644751360406U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 1168426822045686004U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5867027156069481313U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterK, 53U)) + aPhaseCWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 12U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 18U)) + aNonceWordD) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8266U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13184U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8965U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9444U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (((aWandererH + RotL64(aScatter, 58U)) + RotL64(aCarry, 57U)) + 13296600294247799698U) + aNonceWordK;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 5818503518080877515U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 27U)) + 6735784238734173597U) + aNonceWordI;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 11U)) + 7368398209488856201U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererE + RotL64(aCross, 18U)) + 961734029066455638U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 797011946660892011U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 53U)) + 12841876018396622350U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 35U)) + 16213253970483895623U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 23U)) + 15186950557113470375U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5117930310827477341U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12265429373166094162U;
            aOrbiterK = RotL64((aOrbiterK * 1522823535151532249U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13920531346698601568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterD = RotL64((aOrbiterD * 13950964363414164279U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7851960904825938443U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterH = RotL64((aOrbiterH * 5614164120361489613U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5663365182245722077U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18171052650586819280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3442698321538580861U;
            aOrbiterE = RotL64((aOrbiterE * 6317525514963824829U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1491052813469258970U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3956599824067616133U;
            aOrbiterA = RotL64((aOrbiterA * 2928600779267623085U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10963841237346073453U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2303020125591252534U;
            aOrbiterC = RotL64((aOrbiterC * 9969099842343321981U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14503856057958162356U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11147548150090597694U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11856382308792700441U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9191681438318311481U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13556072770381999852U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18316231099054203683U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aPhaseCWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 18U) + aOrbiterD) + RotL64(aOrbiterA, 18U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + aPhaseCWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 48U)) + aOrbiterB) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20139U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 16962U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17690U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21149U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 42U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 46U)) + 5041131702736607991U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 23U)) + 9295010428212681446U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 29U)) + 6235875895358766017U) + aPhaseCOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 2622227802531866918U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 14U)) + 3888894734834524972U;
            aOrbiterF = (aWandererA + RotL64(aCross, 51U)) + 241682012014701753U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 15758000422451568079U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 2061944548396976912U;
            aOrbiterB = ((((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 8177144990755754531U) + aPhaseCOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 554978075608818497U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 250408260560714933U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8700027645880997552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10026130047465480902U;
            aOrbiterK = RotL64((aOrbiterK * 12417270861933696623U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9785843014096326696U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9998582683258411251U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7197956237569462269U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13817734599383455151U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6647207154174092691U;
            aOrbiterD = RotL64((aOrbiterD * 1578528131687283531U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4957715980509035719U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4994885315786213197U;
            aOrbiterE = RotL64((aOrbiterE * 5676683798126497011U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5072908311783966503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5535039946192891515U;
            aOrbiterF = RotL64((aOrbiterF * 2989412783482309753U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6594577050344146271U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8750154123258714856U;
            aOrbiterA = RotL64((aOrbiterA * 6942158167127532003U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3514769314840874873U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8626045200273524281U;
            aOrbiterG = RotL64((aOrbiterG * 4315441782689789689U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8524870284841706517U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1841819423572964209U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9802481758007234681U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + aNonceWordP) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 12U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterE, 24U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30034U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28247U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25562U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28796U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (((aWandererE + RotL64(aScatter, 11U)) + 14179205183062705133U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererI + RotL64(aCross, 41U)) + 210032324058740920U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 23U)) + 7387115089142500152U;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 17583362781238061430U) + aPhaseCOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 4991442849150005943U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 2891376254689854555U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 10523274382407446239U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 29U)) + 3861893764676218667U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 46U)) + 3366674459852093746U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5898492634386601145U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7047353571244768721U;
            aOrbiterG = RotL64((aOrbiterG * 2257518291062508467U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14374108805453186316U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8763667021501226510U;
            aOrbiterB = RotL64((aOrbiterB * 7694695426430267863U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18261523829316379575U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 650477532238860965U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8291758490821819851U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2162326554604894042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5776546692501825278U;
            aOrbiterE = RotL64((aOrbiterE * 14911545784585246537U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3501863793638415049U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14853789267425352958U;
            aOrbiterD = RotL64((aOrbiterD * 10590325397179928739U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15399673014671329743U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12253428583438990426U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12052855472196447849U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13202953937621953839U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7547616636832698398U;
            aOrbiterJ = RotL64((aOrbiterJ * 9533399972562428073U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 15709801946594868318U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12458677982746610971U;
            aOrbiterF = RotL64((aOrbiterF * 6662570874316418993U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6957370791367530127U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10511379961344950861U;
            aOrbiterH = RotL64((aOrbiterH * 15551333099264031337U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterD, 28U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 22U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aNonceWordD);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 6U)) + aOrbiterI) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 39U)) + aNonceWordH) + aPhaseCWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x87637F0948C34593ULL + 0xC5E301BB10E02D6EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCEE116EC8E510B8BULL + 0xB45F0B18C5C0487CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x939F0F0BD177D3A9ULL + 0x851A5EFE1A21D770ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x88646D351D5FE037ULL + 0x9378C592CD4A93BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x981E1AFB96178915ULL + 0xA7085E464023D91DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF17C443749E8ACBDULL + 0x9330CAB21D40F782ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x959796902C7F7F27ULL + 0x830B0268F35C34DEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCFB22699935043C1ULL + 0x94DB18DE0D770E10ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCC1AD3AE04A82193ULL + 0xB2E44AF3E56B970FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x832E4F0D952C3FE7ULL + 0xB390DE8D9545249AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDB6916E4DDCE2701ULL + 0x952A4825953A2CBEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB033D77A5AB922F1ULL + 0xDC03CF4639383A73ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFE64432940B4F035ULL + 0xACEEE29ECA5B1791ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCAF8CFFA3508BFF3ULL + 0xC758329889D97C74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x93E9EA065B5550C7ULL + 0xF221CE593D1F314FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9EA328A2F73F3043ULL + 0xCC57FDF22DC02A9BULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1741U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 804U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3497U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2212U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 13U)) + (RotL64(aCarry, 30U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 29U)) + 4384716820085860551U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 9715780315942116888U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 3U)) + 15963520052789178632U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 14346700690686392938U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 6005518012489966643U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 13U)) + 2506732930310252119U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 16782163084851775826U) + aNonceWordL;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 27U)) + 823673076571076303U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 23U)) + 1634084509064077736U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 60U)) + 1288134975466877686U;
            aOrbiterB = (aWandererF + RotL64(aCross, 51U)) + 2998220403162908444U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 220430672180734911U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10223923547068528867U;
            aOrbiterH = RotL64((aOrbiterH * 12577370238343872139U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11696469696177647608U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6545430420379636963U;
            aOrbiterJ = RotL64((aOrbiterJ * 8387163146257553773U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 79691451831797107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8971444023498649419U;
            aOrbiterC = RotL64((aOrbiterC * 7148919880477390009U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5624403902454498793U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9468064161002030997U;
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8728730962617599223U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9099675924074253030U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 5525644236954497523U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3298303921318288541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5953276499411658358U;
            aOrbiterB = RotL64((aOrbiterB * 10565471305001292693U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6725769507592688539U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1057277456510215817U;
            aOrbiterG = RotL64((aOrbiterG * 8269412198279297075U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11317925732206917722U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17814749417006079067U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4369209051015735925U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9258362135343403308U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4873837345446960113U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14223381466269503273U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7863380865835889675U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4384716820085860551U;
            aOrbiterA = RotL64((aOrbiterA * 2003891033298374621U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 56U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterC, 6U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterH) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10182U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5931U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5888U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 10324U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aScatter, 14U)) + 964165145848253292U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 37U)) + 10645976767204934746U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 8241612229349212650U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 51U)) + 4159196033256913347U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 43U)) + 7194795864620233507U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 7638928444536778384U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 47U)) + 11819105916503968109U) + aNonceWordC;
            aOrbiterK = (aWandererI + RotL64(aIngress, 35U)) + 18052213302858186237U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 57U)) + 8663575313970041570U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 23U)) + 16644136720439299786U) + aNonceWordA;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 16930316530442679864U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16251107616988250593U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterA = RotL64((aOrbiterA * 3543709971414550087U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17885046834432626644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterD = RotL64((aOrbiterD * 15766885299397923879U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2212805322061155615U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6368539134638838822U;
            aOrbiterE = RotL64((aOrbiterE * 13383744883433594259U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5264326094252925613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6126345334815012938U;
            aOrbiterI = RotL64((aOrbiterI * 17180934809764905307U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13826731214018407061U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6621261811613643620U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5964406317285863781U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2167324450276308078U;
            aOrbiterF = RotL64((aOrbiterF * 1098346374733634905U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16740710162977859724U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8236083581048717923U;
            aOrbiterG = RotL64((aOrbiterG * 4364887787000704039U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13967473987446124012U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5136051802217149813U;
            aOrbiterH = RotL64((aOrbiterH * 13997246005108872883U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5842999397215390366U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8621394946580065499U;
            aOrbiterK = RotL64((aOrbiterK * 11658023035736362355U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18086875424872976900U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7429246355923896047U;
            aOrbiterC = RotL64((aOrbiterC * 5077079237334961761U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18123753993386959014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 964165145848253292U;
            aOrbiterB = RotL64((aOrbiterB * 3178072569980307307U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterC, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 38U) + RotL64(aOrbiterC, 36U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterJ, 50U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15062U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 14360U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12043U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12035U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 19U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 11808423452327465441U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 8670503858631730886U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 27U)) + 2400061067991988544U) + aPhaseDOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 57U)) + 16163118178366229686U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 41U)) + 3280178595904941068U;
            aOrbiterF = (aWandererC + RotL64(aCross, 23U)) + 3298683600817047727U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 16321624053445183574U) + aNonceWordN;
            aOrbiterA = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 6730229877611375225U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 50U)) + 10162830636713641322U) + aNonceWordG;
            aOrbiterH = (aWandererA + RotL64(aScatter, 11U)) + 15646771327759599256U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14841751262270544102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9545541117228834895U;
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14676615635857599982U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1231768638470558855U;
            aOrbiterJ = RotL64((aOrbiterJ * 2716808508509014677U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1945905595345404833U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1406171421638586846U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4577864352425476233U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1970292335806697198U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12309719390375013297U;
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5352135521358954576U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15465675376193501658U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2842123638916600369U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3544764287036748668U;
            aOrbiterG = RotL64((aOrbiterG * 3360772950777850115U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6038297172906492282U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10249342332287140970U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 16701083081566042277U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1662076777040529446U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1949705569959740274U;
            aOrbiterE = RotL64((aOrbiterE * 11340691546658994529U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13934194245417822360U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5720408806425535958U;
            aOrbiterF = RotL64((aOrbiterF * 15237561081637415383U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2209251362417210658U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4917447930929521699U;
            aOrbiterA = RotL64((aOrbiterA * 17489570156694692569U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 14817115766683623486U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11700815697312060726U;
            aOrbiterH = RotL64((aOrbiterH * 16982411053956669181U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 20U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + aNonceWordI) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 38U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 26U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18803U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20054U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16960U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19642U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 29U)) + 6771552164800695068U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 12131763371571322040U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 23U)) + 3326182381395522013U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 12288775097697156383U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 43U)) + 5195948373449796741U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 4U)) + 14404044002250137144U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 37U)) + 11142382920035825426U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 2967149520256475485U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 41U)) + 1470907369577818097U) + aNonceWordD;
            aOrbiterI = (aWandererC + RotL64(aIngress, 51U)) + 9231668148004163910U;
            aOrbiterG = (aWandererI + RotL64(aCross, 60U)) + 13078929163913892386U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9485274692075657877U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12216951187543631673U;
            aOrbiterJ = RotL64((aOrbiterJ * 6571066246507310805U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6933334652581744234U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17260276102423580920U;
            aOrbiterD = RotL64((aOrbiterD * 7796879893790990605U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 387767848169714392U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8597538259308082638U;
            aOrbiterB = RotL64((aOrbiterB * 4888054690557707241U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7996708724489146033U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15357384191688149939U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 9827691726832491373U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17739222908739454637U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1614322333281471170U;
            aOrbiterK = RotL64((aOrbiterK * 7063116837752240891U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4531604274893197209U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3453280714992341288U;
            aOrbiterF = RotL64((aOrbiterF * 8390029711127907805U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 116623650872661533U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6565636510115095988U;
            aOrbiterI = RotL64((aOrbiterI * 9691897067492501177U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10303258439817808058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10917642773040237611U;
            aOrbiterG = RotL64((aOrbiterG * 10232856828372963363U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2087058228468680821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3691125545393861889U;
            aOrbiterA = RotL64((aOrbiterA * 1768745056298937903U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9240209357066002219U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7645250700232422804U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6762116797395687607U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9859862257084218280U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6771552164800695068U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11063630807191661109U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 19U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 41U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24894U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 24957U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22223U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25849U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 48U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 13924571355038625040U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 37U)) + 16328300979357156658U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 3947771961206012461U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 3U)) + 15428284250569311285U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aCross, 41U)) + 5777369485254032486U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 11U)) + 16813320300717644673U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 24U)) + RotL64(aCarry, 35U)) + 16689933050200758251U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 1856422419049390708U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 19U)) + 18214498743831925517U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 53U)) + 18278550878494094923U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 46U)) + 797712062039591797U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15854849439012341347U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 996882939768167773U;
            aOrbiterE = RotL64((aOrbiterE * 14936703950807908575U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3005829974130671692U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8793495343509953906U;
            aOrbiterG = RotL64((aOrbiterG * 14065479348374612031U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7710453029930631112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9511995836117707047U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7250766204781428201U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 670902975693341744U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9045820304668279777U;
            aOrbiterJ = RotL64((aOrbiterJ * 18373074917532639027U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12417212387607119470U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12816983560669985622U;
            aOrbiterD = RotL64((aOrbiterD * 8406003970221889847U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17245432086377688540U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6806521945548502014U;
            aOrbiterH = RotL64((aOrbiterH * 11335859481858640857U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8947500746292365294U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4468060468522895852U;
            aOrbiterK = RotL64((aOrbiterK * 7022481284816599797U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9892975931958803992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3042599331526937836U;
            aOrbiterC = RotL64((aOrbiterC * 3308512896171443645U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12991568221485810891U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8551331172836260315U;
            aOrbiterF = RotL64((aOrbiterF * 4509997595920847057U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 183547209633334407U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17275712817092769452U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15677355290000929085U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12743863879392372723U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13924571355038625040U;
            aOrbiterA = RotL64((aOrbiterA * 11966689345179279407U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 42U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 41U)) + aNonceWordD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 34U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 50U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31116U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29059U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29267U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 28934U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 41U)) + 8685374557928800912U) + aNonceWordC;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 10U)) + RotL64(aCarry, 19U)) + 3482312691892161229U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 47U)) + 6948130297389161165U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 23U)) + 5506385663788942690U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 43U)) + 17859982009307397161U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 29U)) + 9178488809207094043U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 27U)) + 1835479501226057169U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 5368101733632614939U) + aNonceWordE;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 3U)) + 9050459666576835422U;
            aOrbiterK = (aWandererE + RotL64(aCross, 13U)) + 9042186993119635078U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + 17528342580198295025U) + aPhaseDOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6495418332558436882U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8834495762667327342U;
            aOrbiterJ = RotL64((aOrbiterJ * 10783141541937645995U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4364314196965690905U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6357485231062120459U;
            aOrbiterF = RotL64((aOrbiterF * 289429584586504995U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3321488322626415347U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10817330671781848737U;
            aOrbiterB = RotL64((aOrbiterB * 15875919466358823335U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17974092279281611763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2871472057292789157U;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15187929795092006849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13482063681546475923U;
            aOrbiterD = RotL64((aOrbiterD * 14466266308157364963U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6232152545071397380U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17488906002621373262U;
            aOrbiterI = RotL64((aOrbiterI * 4719340606442742577U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12444819880507588549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13808941689757772497U;
            aOrbiterK = RotL64((aOrbiterK * 6541360905282412317U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8049361354387692374U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 7137831335606542401U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 11022231291507235007U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7230759462019420058U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3923744511976096944U;
            aOrbiterC = RotL64((aOrbiterC * 9953869624243563101U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15967667946023263856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8677583624693910669U;
            aOrbiterA = RotL64((aOrbiterA * 10737731876339973717U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1604347321263511013U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8685374557928800912U;
            aOrbiterG = RotL64((aOrbiterG * 14103365695918844461U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 28U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterC, 18U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aNonceWordM);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 50U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordG);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9698E2BBA9DCDF63ULL + 0x9ACE60939BAAB14FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCAB99AB6A9AA1A69ULL + 0xF85B43E9E5A37BE6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBB6A413C001D1EDFULL + 0x8FA885799406A6B0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8837F639EA66FD07ULL + 0x9BCB9806E7C9FF89ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAD3E99AD61F36B67ULL + 0xB6BDA0D83D86D087ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB86F6706749468A5ULL + 0xD89C623E27DC1285ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE95EE088BB2273BBULL + 0xAA592E6562A38792ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x947CA8FB83A9E22DULL + 0x845EB2741CE2993BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCB3E490DB26D6E7BULL + 0xC752711379FC44D7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xEEB7FBD79008EB19ULL + 0xB485712E5B927762ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x93557AA41F6FDC11ULL + 0xA28D75EA532900D9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC5D5065CF166D693ULL + 0x84F370678BF81667ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8C3243BA1DD9CC1BULL + 0xA1DCB12D23DA9AA1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDF3C1934A512090BULL + 0xEBEDDF5C1C60E7DEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD6671712A6DCE821ULL + 0xEEBFD391B1F5406EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDE7F14E70F17489BULL + 0xD6646ADFE61727BAULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4297U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((aIndex + 2988U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 484U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4134U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 24U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 28U)) + 12206125048349568300U) + aNonceWordO;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 23U)) + 5843520589343188818U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 11U)) + 12195046124287121687U;
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 16769779119214020640U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 13U)) + 5257603646260695833U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 41U)) + 8523523946234886745U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 7316024684200084096U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + 11996978575084115207U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 39U)) + 15491711479085513628U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 37U)) + 6036648530996821484U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 926323222234121863U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2700323841295743492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5852273765810284935U;
            aOrbiterE = RotL64((aOrbiterE * 16665696735016345215U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11697397483133538067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17777142964957007194U;
            aOrbiterK = RotL64((aOrbiterK * 6338967222543284999U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10892176201151170298U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 11759700374509499684U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 14247697264744736081U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 11343756773329590643U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15785048929757652350U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17208103574389502597U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7508839228498497238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13088508510402094665U;
            aOrbiterI = RotL64((aOrbiterI * 15730279447009669103U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16259236641717377699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11228995722951003980U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 4870092259515181323U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13775851561528617086U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3023564646900497080U;
            aOrbiterB = RotL64((aOrbiterB * 9936548213275464131U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 154952467284609583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14239675888632174461U;
            aOrbiterC = RotL64((aOrbiterC * 1370550680736926425U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 168749514558708557U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 5070416708211422927U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13631900152346927703U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1961290602001581341U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12235345489656113478U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14403534235273302211U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2295581049708176078U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12206125048349568300U;
            aOrbiterG = RotL64((aOrbiterG * 6008868846674396181U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 38U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterC, 34U)) + aOrbiterF) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 50U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8143U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 10771U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7509U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9025U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 5U)) + 5510690816044082200U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + 15967820875033940530U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 37U)) + 539348720848176221U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 15779318183635560817U) + aNonceWordN;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 21U)) + 14511058534424187469U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 3U)) + 5811130556873428391U) + aNonceWordD;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 1085928476499444025U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 52U)) + 6973335316600768130U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 37U)) + 10747243745475009744U) + aNonceWordA;
            aOrbiterK = (aWandererK + RotL64(aIngress, 41U)) + 1072260008981349754U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 27U)) + 2018772405352495753U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1092091597048996547U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15103140149542167197U;
            aOrbiterI = RotL64((aOrbiterI * 621856991658027989U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13194619321108681542U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16749188603268621850U;
            aOrbiterA = RotL64((aOrbiterA * 9575408950550922039U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7427959503086895166U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9895804051379551393U;
            aOrbiterH = RotL64((aOrbiterH * 2701997336201570715U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 4526020800679774259U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4484850928870048176U;
            aOrbiterG = RotL64((aOrbiterG * 17556987520625677313U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1837404844299040155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15213208978489570694U;
            aOrbiterF = RotL64((aOrbiterF * 7062740584650274133U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9615231781751396800U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15872192167825648096U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2900526493682580729U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12530672039655918903U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10617836782870315804U;
            aOrbiterD = RotL64((aOrbiterD * 9716778004909794973U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 550750725406860977U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3498554352021622907U;
            aOrbiterB = RotL64((aOrbiterB * 9846933294851238495U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4059346317776216057U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14161853870874499023U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8601560894939097781U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4088411647683253905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9321241420172776158U;
            aOrbiterK = RotL64((aOrbiterK * 4167888281125330225U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8527337525861632945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5510690816044082200U;
            aOrbiterJ = RotL64((aOrbiterJ * 12464836001483233379U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 52U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 46U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordF) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 10U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15216U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13159U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13195U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11793U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 14U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 5171470532667965920U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 34U)) + 750549462358682403U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 51U)) + 3325689257577120525U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 18031575461559790826U) + aNonceWordE;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 13874739537012288677U) + aNonceWordN;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 48U)) + 4250029868785016865U) + aNonceWordP;
            aOrbiterF = (aWandererA + RotL64(aScatter, 29U)) + 8211158803112611161U;
            aOrbiterK = (aWandererI + RotL64(aCross, 43U)) + 1083939790236786027U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + 3446525462376962464U) + aPhaseEOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 3U)) + 6973817815000417325U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 23U)) + 15230876489676945543U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9359727659738755880U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8775170107816327654U;
            aOrbiterE = RotL64((aOrbiterE * 6910680458261008653U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11958941755525038545U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 16966819714283167348U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 16363457661846050749U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14556087985619763243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17915047508377045221U;
            aOrbiterI = RotL64((aOrbiterI * 6727635453185130109U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8578745677485367222U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7002181668717618866U;
            aOrbiterH = RotL64((aOrbiterH * 12329703532414955235U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3569939503066735457U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2956247934282522184U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4285180013402474041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5976239869535619811U;
            aOrbiterG = RotL64((aOrbiterG * 3458095419039067465U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2424524955161695463U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6849595426583763537U;
            aOrbiterD = RotL64((aOrbiterD * 12727902040238318101U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11414890686374886716U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5668287266836153445U;
            aOrbiterB = RotL64((aOrbiterB * 8011885266143066285U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9976985606260445887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9223940029500676834U;
            aOrbiterF = RotL64((aOrbiterF * 8508023992488499955U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4480967907876921958U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5132766654502526597U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 321625389942019245U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12921555132452983464U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5171470532667965920U;
            aOrbiterJ = RotL64((aOrbiterJ * 9710487797420618879U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 22U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 43U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16794U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21513U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19328U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 18492U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 12U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 12027839670755583592U;
            aOrbiterG = (aWandererA + RotL64(aCross, 21U)) + 15380130703509859843U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 39U)) + 4590907433867798074U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 1754574023602519724U;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 9832756659564903767U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 27U)) + 5035088494491470403U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 23U)) + 14199170923323644638U;
            aOrbiterI = (aWandererD + RotL64(aCross, 51U)) + 8325619421264440438U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 47U)) + 969534320779067977U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + 270575869402913847U) + aPhaseEOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 56U)) + 13344806516599578910U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15143147951139409101U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14425582489214169238U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 16893787086337916355U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13951127523239064584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8258920744278218901U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7408161179397242453U;
            aOrbiterK = RotL64((aOrbiterK * 975737128100519169U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8581481606764773468U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10078416198417433133U;
            aOrbiterD = RotL64((aOrbiterD * 1102721083915858247U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18299772198826189580U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 18304668908084397946U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10589455451200578687U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16729632621573817223U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13362300981585573239U;
            aOrbiterE = RotL64((aOrbiterE * 9824473895535518785U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8629682832849915380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6852852009091469641U;
            aOrbiterC = RotL64((aOrbiterC * 11912646687050011915U), 51U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 7433098156961745198U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10931806208899417308U;
            aOrbiterH = RotL64((aOrbiterH * 14699197041038067483U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 629604718211675247U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1487372736719237118U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 705192821277928909U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3567439893461603384U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11143068753134694333U;
            aOrbiterG = RotL64((aOrbiterG * 15529326960229305389U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14242098279913980463U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12027839670755583592U;
            aOrbiterF = RotL64((aOrbiterF * 6630014752150544153U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 51U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 46U)) + aOrbiterA) + aNonceWordM) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 30U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 24U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24369U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23209U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26207U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 26218U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 19U)) + 15316464782468770057U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 13U)) + 6642872057476351588U) + aNonceWordJ;
            aOrbiterG = (aWandererK + RotL64(aScatter, 35U)) + 660732654689529192U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 28U)) + 7235418086884000655U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 23U)) + 14784518476694580493U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 12222433977933449375U) + aNonceWordB;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 3U)) + 8573001207708329927U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 16035256260815013172U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 15767726974121910203U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 26U)) + 17712217935322939971U;
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 13488963456923357159U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10222949131965611079U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1495561412321657209U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 9706305581868526265U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16156530750584361434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7773792489045606309U;
            aOrbiterD = RotL64((aOrbiterD * 10730624207715601393U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11544578291333360613U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3665587867634242865U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4840528190844842595U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterD) + 15248434984650998090U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15487979645426567581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6972347795052712690U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16074994810010431338U;
            aOrbiterA = RotL64((aOrbiterA * 1262655238856775853U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16851139687900415292U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14630026837021552812U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9577900853521254603U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14236330619137368169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17778707026111136216U;
            aOrbiterE = RotL64((aOrbiterE * 16239561893843454747U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9390961969105999083U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1174881758316573228U;
            aOrbiterI = RotL64((aOrbiterI * 6602061268277529311U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3025148570039849574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2813499258480831171U;
            aOrbiterF = RotL64((aOrbiterF * 12272555492688861861U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15397952138592662354U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10394648143430175275U;
            aOrbiterB = RotL64((aOrbiterB * 18195627209519212303U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3043205345760158739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15316464782468770057U;
            aOrbiterK = RotL64((aOrbiterK * 8162506622688910545U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 24U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + aNonceWordP) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterE, 20U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32510U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30254U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31633U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30404U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 20U)) + 13687218104610230596U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 37U)) + 6841550124960692709U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 17418968668458764131U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 8303537912696948204U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 11U)) + 12376614417285936537U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 39U)) + 14215749063579232654U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 4111736931433665347U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 47U)) + 11250375934571631522U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 51U)) + 5367367837773331275U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 23U)) + 15514089192382674434U) + aNonceWordA;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 1475991716685034960U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5531622777788629748U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8363822215908303335U;
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3741256932685720414U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11634667238062155772U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15925089729784547403U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18180546911210417155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5123234656838556335U;
            aOrbiterF = RotL64((aOrbiterF * 15362857462853398025U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11215734271189250284U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16863747802158398092U;
            aOrbiterI = RotL64((aOrbiterI * 1828035970246160023U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9859050606636646323U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9331300036643654675U;
            aOrbiterA = RotL64((aOrbiterA * 2502263410556166281U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15028845665427209759U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8916444839488901676U;
            aOrbiterK = RotL64((aOrbiterK * 6646561894156038791U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8024631140949068570U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1116378858490660031U;
            aOrbiterB = RotL64((aOrbiterB * 4247798531910227367U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5066486214537899212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9346312092322423057U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13443190089768875191U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11651011617027950122U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11308862427412671711U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12167147966934334703U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3850136281462840708U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13461307727665667424U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10788040812090673421U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17824744996404571928U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13687218104610230596U;
            aOrbiterJ = RotL64((aOrbiterJ * 325803029547254631U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 54U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 50U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 14U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFE422CC6F1261C77ULL + 0xFD188BE1B816AA31ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8EAA97509497F029ULL + 0x9ECB0DF7D286EC8AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA9B027090CDD5211ULL + 0xBDD443E5FF626375ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6CEF8B34874E6ABULL + 0x93E95D6CFECD756EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF75763D28834FBC9ULL + 0xF86BC3F5979C47CEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBB41980ED9266F15ULL + 0xFEC5004223DDAAFFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x97398E8F3A307B6BULL + 0xAD5A4CF17124E2C4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBABD940D65B356B9ULL + 0xC74C61CFCADFE1CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF7288C9BBA584D8DULL + 0x8E32702C8F54F628ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x978C5F660A3F9F45ULL + 0xD0B649CAF55E7721ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE37056D22198C4BFULL + 0xF1DF5AF2D827E471ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCA91932A0A323D15ULL + 0xDB28E1F9A240DDC1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFEA11EE090506939ULL + 0xE06EBA4784E1BC68ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDC370938CF762773ULL + 0xC9599DD9D72C7130ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCAE67301A1A2795FULL + 0xD2D6C577F7CB686CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xABFBC3197A66ABE7ULL + 0xB85B1BD851E43415ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 348U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 980U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3764U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5009U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 13U)) + 14214886793361825363U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 44U)) + RotL64(aCarry, 11U)) + 17267959031078766320U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 5U)) + 16436067429484887644U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 9885951769332633820U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 3U)) + 12971711341813893304U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 57U)) + 199970353398450154U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + 1237341696444162094U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 53U)) + 7991128854417613360U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 37U)) + 14809029847149045833U) + aNonceWordP;
            aOrbiterG = (aWandererH + RotL64(aScatter, 11U)) + 2559509556915775947U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 43U)) + 14336829730147834160U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8853631886733610440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13346159398673246914U;
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12121095718571872976U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16239781125815589804U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5157009090454962231U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9051377033794324106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13805815136723461780U;
            aOrbiterE = RotL64((aOrbiterE * 571129481747181357U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14849157800322754413U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18116651528452542634U;
            aOrbiterC = RotL64((aOrbiterC * 3638480428016835537U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4105057226952948599U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5911714320560994391U;
            aOrbiterI = RotL64((aOrbiterI * 1796514171654961389U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4439149331729987587U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10278532228230163632U;
            aOrbiterJ = RotL64((aOrbiterJ * 17428224919864716517U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2342456582668741750U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2360578572554664800U;
            aOrbiterB = RotL64((aOrbiterB * 1108428466956691925U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12132934875391401246U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17213278726790245812U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 11904899990681410419U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7994340481560109811U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13735851271080138255U;
            aOrbiterA = RotL64((aOrbiterA * 12387076892129731557U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6682417543888875268U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15642799286975840550U;
            aOrbiterD = RotL64((aOrbiterD * 7861250716882028053U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9839299346094784067U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 14214886793361825363U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 2103132743364916037U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 60U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 30U) + aOrbiterA) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 20U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9239U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6881U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8850U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 8380U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 3U)) ^ (RotL64(aCross, 20U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 24U)) + 13278949403988203974U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 47U)) + 9213599924054673756U;
            aOrbiterK = (aWandererD + RotL64(aCross, 19U)) + 1255746482932381798U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 5U)) + 11575321997144516122U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 15881587525529432437U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 39U)) + 9846195809864862707U) + aNonceWordL;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 12319815691858217670U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 16322617427294439587U) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 51U)) + 16332130810525887437U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 37U)) + 4920951156015336794U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + 16767126455124552329U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12553595911087945223U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1437522202135436142U;
            aOrbiterK = RotL64((aOrbiterK * 2001992794165550905U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12313100454852227143U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2761983020631055729U;
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17635303588421554367U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 788212489507463763U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17896475584538528059U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5192552894670654434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6784748488807738811U;
            aOrbiterH = RotL64((aOrbiterH * 8077237651953896479U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16113417046719114943U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 1096874945215225916U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 17308604412622879833U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7610274704570171595U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10466070212284342550U;
            aOrbiterA = RotL64((aOrbiterA * 6449728258497920613U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6777845928873855221U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5251515022021984126U;
            aOrbiterE = RotL64((aOrbiterE * 9018277343404261611U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13849343158824111498U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7977711210181714021U;
            aOrbiterC = RotL64((aOrbiterC * 4182053966171053577U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6494539818728106982U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11314590450226080781U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12455979257225599157U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 552687702594328012U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14961304171192292246U;
            aOrbiterF = RotL64((aOrbiterF * 846375892915484717U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9771874402848476494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13278949403988203974U;
            aOrbiterD = RotL64((aOrbiterD * 2119203863777871233U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 36U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterF, 41U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 6U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 6U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11464U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11931U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15012U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13804U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 12U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 12980104182836602177U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 43U)) + 3172622203188863995U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 13U)) + 1170974132219980203U;
            aOrbiterG = (aWandererI + RotL64(aCross, 60U)) + 6035201940965047490U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 11U)) + 18033907118424996722U) + aNonceWordI;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 41U)) + 14604813424800580304U) + aNonceWordB;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 13720232492851066035U;
            aOrbiterH = (aWandererK + RotL64(aCross, 4U)) + 3902659710585257448U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 23U)) + 8331560652661619868U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 4485014147538689794U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 35U)) + 168202636924512424U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16227825670092707848U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4792781933944671365U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 15859849676231455283U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12636865372722601282U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 18198291399585556632U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 18155803890313399795U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3650053185419807206U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5897288963905408776U;
            aOrbiterB = RotL64((aOrbiterB * 3706949366974086151U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9922308113622901726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13352279749091561510U;
            aOrbiterK = RotL64((aOrbiterK * 4025213180483632557U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14969461950939646117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10231661776135056651U;
            aOrbiterH = RotL64((aOrbiterH * 11284575051455238501U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10621934544068320859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6029116920305246887U;
            aOrbiterA = RotL64((aOrbiterA * 6087523725059376905U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12887482425168671195U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8351351557123783853U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3839381627914762245U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5405938210926464973U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 385145802287899406U;
            aOrbiterG = RotL64((aOrbiterG * 8330751480464271445U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7907749190875916461U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5138733192253468642U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17028325976353263843U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14382272868178763187U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14354777100157531233U;
            aOrbiterD = RotL64((aOrbiterD * 7095764230272037767U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4390647647193363824U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12980104182836602177U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11124472075872147333U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 56U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + aNonceWordO) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 14U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 12U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19205U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 21044U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19831U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 17710U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 26U)) + 13442819395490639310U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aWandererI + RotL64(aCross, 39U)) + 8187292523194120936U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 5U)) + 11469697159823131388U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 51U)) + 13414083692375929653U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 53U)) + 11404010733687907517U;
            aOrbiterK = (aWandererK + RotL64(aCross, 13U)) + 6783212827186218247U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 8561131439340372614U) + aNonceWordO;
            aOrbiterA = (aWandererH + RotL64(aScatter, 57U)) + 6252609642004429113U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 12804867444200448952U) + aNonceWordB;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 2739648749603690781U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 29U)) + 14808861217017399752U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17588866502571268888U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5882260142735642980U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7688252946143263869U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15493099088132862949U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5175647411532429582U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15226544495598541883U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14279707376173642767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6826363572161275158U;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13267185753040999992U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9980987858092888720U;
            aOrbiterD = RotL64((aOrbiterD * 13210290848800728635U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3582972937645514549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10140409019562890804U;
            aOrbiterA = RotL64((aOrbiterA * 6944490201647678479U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6160444117287330557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16344602960561293113U;
            aOrbiterB = RotL64((aOrbiterB * 2319964919335633293U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3497141036108337171U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 91269118352540308U;
            aOrbiterG = RotL64((aOrbiterG * 5160060720189045505U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12739932748793144857U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12820180915064791197U;
            aOrbiterE = RotL64((aOrbiterE * 5843849637411948699U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17572075652083359962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10684041099654982701U;
            aOrbiterF = RotL64((aOrbiterF * 7121293375756263771U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10739534650885677354U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9731206787727954809U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3730875775588585547U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9655432616347117764U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13442819395490639310U;
            aOrbiterI = RotL64((aOrbiterI * 3650859301708619119U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 48U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 52U)) + aOrbiterB) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24352U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 24492U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21979U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21914U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 30U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 41U)) + 9914837590440975587U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 53U)) + 6706125076401958051U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 21U)) + 16570817772679258409U) + aNonceWordI;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + 6843705658115186948U) + aNonceWordN;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 60U)) + 16099930446791572351U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 57U)) + 5420550009556030459U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 23U)) + 5729549069420177477U) + aNonceWordM;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 15590601126188675834U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 44U)) + RotL64(aCarry, 43U)) + 13044027390998620029U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 11068338135659636772U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 6584988841809544332U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8516813219883915404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10647314042912492785U;
            aOrbiterJ = RotL64((aOrbiterJ * 15559481057047148785U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3883760518944464145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13861805129175491145U;
            aOrbiterH = RotL64((aOrbiterH * 17194438894492581181U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12019138626550801486U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13030350224959652248U;
            aOrbiterC = RotL64((aOrbiterC * 11724200983306280107U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2643807255422544248U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 4127143302485631794U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 5441038881111578487U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 14602951930809633069U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4555737199162278494U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12415825635220991865U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6343143902997169834U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10404783711336491985U;
            aOrbiterA = RotL64((aOrbiterA * 6235474458879439079U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7406959231434835393U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6684368109277850196U;
            aOrbiterE = RotL64((aOrbiterE * 8760360417572331159U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4835889355927954728U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7917682889852676712U;
            aOrbiterG = RotL64((aOrbiterG * 9045350756570117327U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 10268055422944417055U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5563744562922937643U;
            aOrbiterB = RotL64((aOrbiterB * 12442484191329795173U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17244672945880141679U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9914837590440975587U;
            aOrbiterD = RotL64((aOrbiterD * 12269340309792850489U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterH, 21U)) + aNonceWordB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterK, 40U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 53U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD + ((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterJ, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32113U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27369U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32757U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31065U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 9630214189402543339U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 23U)) + 4072576573737526819U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 47U)) + 15994787452709618869U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 10U)) + 6403240137132259482U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 10229266900170507720U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 3U)) + 5025294577989748989U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 16696461238217956883U) + aNonceWordB;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 9878318855341719119U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 60U)) + 16086635438116177346U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 27U)) + 12295437783084203730U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aCross, 53U)) + 7681150419912842402U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2639104034287637448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12298170009332243573U;
            aOrbiterK = RotL64((aOrbiterK * 9397919591171238575U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3485932317267669626U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16569551670038752475U;
            aOrbiterA = RotL64((aOrbiterA * 8139802826402217631U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4448490103784103954U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14510534073046885941U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7777192047386438305U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4286195398675733451U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15790355933840266463U;
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6362891510370156055U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15121822034579983174U;
            aOrbiterJ = RotL64((aOrbiterJ * 7268045994574844937U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13817341015719915628U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14113474087906143783U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12838910141533126059U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9988301252236121106U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11287477288382171758U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9491727010910328644U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7961202721830514030U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16300364540313620767U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10058066852293995222U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 541563830282750968U;
            aOrbiterD = RotL64((aOrbiterD * 1516823517052019845U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7791201128863372861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8334318157449352359U;
            aOrbiterF = RotL64((aOrbiterF * 2924838607279239375U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6861081455774799715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9630214189402543339U;
            aOrbiterB = RotL64((aOrbiterB * 10837610668580336781U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 44U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 46U)) + aOrbiterE) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 12U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC251FA30DD472673ULL + 0x8D223966F6D4F7FAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFDA2488A953776DBULL + 0x854C956D61D855ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB39282436929237BULL + 0xAF14096E191120A1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD500135269736B37ULL + 0xADD75A20031C1F67ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC900A6DA837BAD87ULL + 0xEA5DE621E0C171D3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE2A3A1340B49E0EDULL + 0xE4116EA73BC9215EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA09D14CBBBFCCE65ULL + 0xDE5057367AE83334ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB11895CE2CBFDB89ULL + 0xBDAEFA74EA50B413ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF417BA33E7FB0005ULL + 0xEC9B4FB860E74E3DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEF325D82DF679A51ULL + 0xB090783C4CF70207ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAEC3FBEA8A0A7EF5ULL + 0xB94D9DFBA9FFF59CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xED68E11A76E4898BULL + 0xBBE4FA3B0B09F608ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAC87F2E27974276BULL + 0x9291DE0E45540A38ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xECC52A3FF9C991FBULL + 0x95785A1184EE3EF8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB4E391B3C38C33A7ULL + 0xE690A0E066BDA525ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9E39B89A94D9B913ULL + 0x9815974DBA3243CAULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4807U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3668U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4325U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1480U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 40U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 6068543441070417854U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 23U)) + 2995980468193441856U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 36U)) + 18020277482171594003U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 41U)) + 4293807434721230702U;
            aOrbiterI = ((((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 7980599111583893156U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 8593141111851052016U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 21U)) + 5903487523900084325U;
            aOrbiterE = (aWandererB + RotL64(aCross, 47U)) + 15112035513447930209U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 10U)) + 9854037263057006439U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 19U)) + 16759760289688823193U;
            aOrbiterA = (aWandererC + RotL64(aCross, 43U)) + 12622628933030601390U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 1264668857268123425U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16302812053619101593U;
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16087995784896123610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7970269262800468363U;
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5331477046030959632U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16534913204255550893U;
            aOrbiterF = RotL64((aOrbiterF * 1013433634373673565U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11042821902537871209U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8069677512345031660U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13622218526054132397U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5737130058129936372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1076627182956662997U;
            aOrbiterD = RotL64((aOrbiterD * 14342191224014199929U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13911061091801078190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15397603151098990373U;
            aOrbiterK = RotL64((aOrbiterK * 1802890451633592245U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15137326716738637972U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11248737008959896786U;
            aOrbiterA = RotL64((aOrbiterA * 90789374131547005U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1847847987633923657U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10560748778679145431U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2919333327817231099U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2703726238610290251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12950671360471467310U;
            aOrbiterI = RotL64((aOrbiterI * 7490327691501537047U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10331504168520449467U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1541527607705280906U;
            aOrbiterE = RotL64((aOrbiterE * 14197400812600186171U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9135056476214341809U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6068543441070417854U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 14102524444094948875U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 18U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 5U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 20U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 27U)) + aNonceWordK) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8813U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7927U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8028U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7176U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 29U)) + 8793908991006073956U;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 2932916283348441943U) + aNonceWordK;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 39U)) + 11069042087940968262U) + aNonceWordA;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 27U)) + 14369628676782894441U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 34U)) + 8602903272780978282U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 3827036107178568820U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 8905245209036772489U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 13331387530760017893U;
            aOrbiterH = (aWandererC + RotL64(aCross, 11U)) + 9880107580289737823U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 3U)) + 10199619040626900278U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 50U)) + 2466307560891374281U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13973403407981259448U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2851460278409385243U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11226902976321781743U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10365453393815690776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5058198848163792422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10500434740387593487U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5946747708776079787U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11289798395177667084U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14327152153231286666U;
            aOrbiterJ = RotL64((aOrbiterJ * 18155778059595245561U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8065137263811956313U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3865153574847924816U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9495741102667755161U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18102279969722473375U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6306428427188742325U;
            aOrbiterE = RotL64((aOrbiterE * 17826782872351406167U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 16953348204663693724U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11950791817032898613U;
            aOrbiterF = RotL64((aOrbiterF * 1498946055469611133U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11980823193543752994U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17845490308799454871U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16385153013485463791U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5566398755702887071U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10308378271388889968U;
            aOrbiterA = RotL64((aOrbiterA * 142732084484961281U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6717846700455219260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8297225372883997017U;
            aOrbiterG = RotL64((aOrbiterG * 14102812043481327907U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12249337046267666603U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8793908991006073956U;
            aOrbiterK = RotL64((aOrbiterK * 5851229209188473467U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 40U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterA);
            aWandererI = aWandererI + (((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 11U)) + aNonceWordD) + aPhaseFWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 52U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16302U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15184U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14906U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 13886U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aIngress, 43U)) + 13499155707765393469U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 51U)) + 3740324981823726185U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 5U)) + 5470765363949735652U) + aNonceWordJ;
            aOrbiterC = ((aWandererI + RotL64(aCross, 56U)) + 3446436171274452326U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 1778929412631211933U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 19U)) + 14666308799855220954U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 4548410236791175055U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 24U)) + 5829739767694190372U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 47U)) + 14319231414903675748U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 1513851750246111405U) + aNonceWordA;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 1685620217748986019U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16284162182006054402U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6271539598462003309U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13923286694131331137U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12669312437565969473U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11894755313393001665U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12556759675372354075U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6315983824634946566U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17106616474222892782U;
            aOrbiterG = RotL64((aOrbiterG * 167205520766791073U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13350266700180455548U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4608846311203767162U;
            aOrbiterB = RotL64((aOrbiterB * 2504857468837437365U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14195866746143604365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7917977448256795054U;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10707336923305131629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17122696159336995392U;
            aOrbiterH = RotL64((aOrbiterH * 13953518568670659191U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5182322763573586116U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6503754948502556246U;
            aOrbiterD = RotL64((aOrbiterD * 14749002194140663519U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14907832047832987341U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6258064448676621346U;
            aOrbiterC = RotL64((aOrbiterC * 4407960312705621487U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1180234574888070795U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 801686887651085881U;
            aOrbiterI = RotL64((aOrbiterI * 433981853631548041U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11810494591997709554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9343740505955858127U;
            aOrbiterK = RotL64((aOrbiterK * 8733378485648720323U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12816829575386720695U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13499155707765393469U;
            aOrbiterE = RotL64((aOrbiterE * 9937924703928730369U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 28U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 58U));
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aNonceWordF);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 24U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17288U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21105U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18151U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18826U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 4U) ^ RotL64(aIngress, 47U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 6163290588946759209U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 7342672468560105447U) + aNonceWordF;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 35U)) + 11574563167017282321U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 60U)) + 2254820206194758964U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 5U)) + 1469783447473099498U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 23U)) + 14174828900676165088U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 57U)) + 16277954291890598132U;
            aOrbiterD = (aWandererE + RotL64(aCross, 53U)) + 14845750668693136766U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 150099699692047766U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 20U)) + 1200784917165131703U) + aNonceWordJ;
            aOrbiterK = ((aWandererK + RotL64(aCross, 29U)) + 9469982764806754302U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10956702761701710182U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7915506894975487807U;
            aOrbiterI = RotL64((aOrbiterI * 8874108311712727983U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17335794183733623213U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 557028996286989506U;
            aOrbiterA = RotL64((aOrbiterA * 3993359298602424281U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1597385667771002414U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4376417959915162639U;
            aOrbiterG = RotL64((aOrbiterG * 4626236858205178149U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 549770198518993876U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 756554555648070919U;
            aOrbiterC = RotL64((aOrbiterC * 16272320259614325355U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7298557532533152193U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3336802611342112013U;
            aOrbiterD = RotL64((aOrbiterD * 14679103452120080499U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2314938232094714365U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12215066333571149153U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10747052773052630601U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7762752719356805046U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6519429915769040078U;
            aOrbiterF = RotL64((aOrbiterF * 15548676502167938513U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7556691736109752918U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13731245903412646404U;
            aOrbiterK = RotL64((aOrbiterK * 15581965016668635409U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5910925625723735162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16037704866415841869U;
            aOrbiterB = RotL64((aOrbiterB * 11628217027073824759U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12605882248192797360U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9579778913978981884U;
            aOrbiterH = RotL64((aOrbiterH * 5372577227818787957U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6063171520266734946U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6163290588946759209U;
            aOrbiterJ = RotL64((aOrbiterJ * 291843698316138251U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 39U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 48U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 10U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23805U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27071U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23793U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27259U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 10U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 41U)) + 3612110001869385068U;
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 16340824141280225936U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 24U)) + 15222338965130765231U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 21U)) + 6649270508107155041U;
            aOrbiterH = ((((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 768217258655426384U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aCross, 51U)) + 4481855259658861851U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 27U)) + 18318041934562434016U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 4212457153804401807U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 60U)) + 16143621095636987628U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 37U)) + 2095664232866642086U;
            aOrbiterF = ((((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 4339527736737366572U) + aPhaseFOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13679353177869884790U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 11582168502846418236U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 135539430034462861U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10451330452898542191U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12951448817640617841U;
            aOrbiterK = RotL64((aOrbiterK * 4141870904192742091U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15389161934419370747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4754886272708253014U;
            aOrbiterC = RotL64((aOrbiterC * 16638243718191281597U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11746389873929280688U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12042680172517298768U;
            aOrbiterA = RotL64((aOrbiterA * 3814780289755857543U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2648103752465009244U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 451594673632597973U;
            aOrbiterD = RotL64((aOrbiterD * 8496763663271072425U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5696534794094099710U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14609435045257077395U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14658408563237468407U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11599395126850950133U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12699598504604446664U;
            aOrbiterI = RotL64((aOrbiterI * 14313494063098111823U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9398465148537154745U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12139736860648011256U;
            aOrbiterG = RotL64((aOrbiterG * 15257503229375247987U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5390816291244486383U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2797988892316486895U;
            aOrbiterF = RotL64((aOrbiterF * 14668138881285892065U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18356290434261054712U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16582824574485822826U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7207935384746719969U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9858803484150150915U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3612110001869385068U;
            aOrbiterH = RotL64((aOrbiterH * 2862887443435821143U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterE, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 41U)) + aOrbiterG) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 35U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 6U)) + aOrbiterH) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 39U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 56U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aNonceWordE) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29521U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30444U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29547U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30872U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (((aWandererC + RotL64(aScatter, 10U)) + RotL64(aCarry, 19U)) + 16424657151168221875U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 43U)) + 17150123681886380361U;
            aOrbiterI = (((aWandererB + RotL64(aIngress, 13U)) + 16041993588694572757U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 9871185846434828537U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 11227236398354430757U) + aNonceWordJ;
            aOrbiterC = (aWandererD + RotL64(aIngress, 35U)) + 5399325217402192631U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 53U)) + 9248828789282890454U) + aNonceWordP;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 39U)) + 9041370494203701062U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 50U)) + 14944424084524970764U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 37U)) + 5481938174456671041U;
            aOrbiterE = (aWandererG + RotL64(aCross, 47U)) + 14783648629543752715U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12355573914530445723U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 9863991559011968318U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 8495251211794343179U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16149688605937250965U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 106041828692026825U;
            aOrbiterB = RotL64((aOrbiterB * 12199934305374582599U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8076098639554567792U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11155119311895580013U;
            aOrbiterC = RotL64((aOrbiterC * 1495180896564818647U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6847612160595917702U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16094377920388017367U;
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13584719866672696684U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13446209321646234607U;
            aOrbiterJ = RotL64((aOrbiterJ * 9945349065094781529U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15829806645369560988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12573767256739062550U;
            aOrbiterK = RotL64((aOrbiterK * 5649504278826069077U), 5U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 3850030870300393809U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11857593987748189858U;
            aOrbiterG = RotL64((aOrbiterG * 15942863910931814193U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5505918410521728373U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12949653497121247860U;
            aOrbiterE = RotL64((aOrbiterE * 90944913639560027U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2448323375614082955U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4386059032042654583U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11730132905525317201U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 108129028178045299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18292666533864994149U;
            aOrbiterD = RotL64((aOrbiterD * 2599590507178673531U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10771402979550786312U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16424657151168221875U;
            aOrbiterA = RotL64((aOrbiterA * 6255743082177474607U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 48U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 60U)) + aOrbiterC) + aNonceWordA) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterH, 26U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4981U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6699U)) & W_KEY1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4356U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 666U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 58U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 39U)) + 15726877954695761686U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 14187652171881943587U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 26U)) + 8420423151313882782U;
            aOrbiterH = (aWandererI + RotL64(aCross, 35U)) + 14942322692433259283U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 21U)) + 7272331475919796255U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 43U)) + 154504365041805840U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 10U)) + RotL64(aCarry, 39U)) + 17475491222554948786U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 3U)) + 5759181483165339605U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 5993060214499322845U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10901786237875941844U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17135786595614068473U;
            aOrbiterA = RotL64((aOrbiterA * 15923538730142047043U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5208202073886811165U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6821452921018900631U;
            aOrbiterF = RotL64((aOrbiterF * 13119330055184115669U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13348064837402206969U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterG = RotL64((aOrbiterG * 300168481725373093U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8130283784171430891U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6351113882502502876U;
            aOrbiterE = RotL64((aOrbiterE * 15960622823993072903U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6894708729226455769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17138279326229372741U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12987698199066890628U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12665716655177320977U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13688833537574196675U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4211971980434000618U;
            aOrbiterB = RotL64((aOrbiterB * 1374411763361518851U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10376917117582537592U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 4807742522197923516U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15257251453302090961U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18038296468177121243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6879666349379745258U;
            aOrbiterK = RotL64((aOrbiterK * 15819475269715810555U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 36U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterE, 58U)) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterG, 51U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10624U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 9982U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9548U)) & W_KEY1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 15467U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 966899917801652720U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 10996327672320748649U;
            aOrbiterA = (aWandererK + RotL64(aCross, 30U)) + 4188171566846621107U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 5886209243097387959U) + aPhaseCOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 11U)) + 14940428957136728111U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 23U)) + 179187285531914832U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 58U)) + 6685351948936817752U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 1894506461704029700U;
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 4182760368636977082U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12523318028514940790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5059306166973366892U;
            aOrbiterA = RotL64((aOrbiterA * 2857409765717296483U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5890872367917643851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17747338389865221534U;
            aOrbiterH = RotL64((aOrbiterH * 5306740664798049267U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13906227834259884100U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7152105382899756368U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6772157117358310485U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17868101884759619240U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11758843266314148347U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5919135169337501485U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13950566197090324859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17278105609930477854U;
            aOrbiterI = RotL64((aOrbiterI * 11431842718945107359U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9556785965646738355U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 841298436857932987U;
            aOrbiterD = RotL64((aOrbiterD * 15077843186688841797U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1951515285492133830U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15775839819330588437U;
            aOrbiterF = RotL64((aOrbiterF * 7902654031401620995U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5585458468816495436U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17258586689032223623U;
            aOrbiterE = RotL64((aOrbiterE * 1652050227399194271U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5254132659445988836U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15440741734777060925U;
            aOrbiterB = RotL64((aOrbiterB * 17445581079035134067U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + RotL64(aOrbiterB, 34U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 24U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterI, 18U));
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23132U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((aIndex + 20939U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 24485U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21089U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 56U)) + 6381335981879993247U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 13U)) + 15595429101600023172U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 5449234297249826461U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 11213734849329731168U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 23U)) + 16438473952464514248U;
            aOrbiterE = (aWandererF + RotL64(aCross, 51U)) + 7357872882115186976U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 394402075160738643U) + aPhaseCOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 27U)) + 11112941985410283532U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 14955125011182736212U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14770727009821304070U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11286366598129204910U;
            aOrbiterF = RotL64((aOrbiterF * 15884310771003021989U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7358400908565425780U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15635109923749114761U;
            aOrbiterK = RotL64((aOrbiterK * 12415152149408700329U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13826842523738623579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1072811298828325231U;
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4017334196009350776U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8812213572751410831U;
            aOrbiterH = RotL64((aOrbiterH * 12744171921566782795U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6723457786170634403U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9785583533999417673U;
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10265132640322153964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8435670887514808087U;
            aOrbiterE = RotL64((aOrbiterE * 2706263045620662131U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4303823386961718326U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4214384238167491037U;
            aOrbiterD = RotL64((aOrbiterD * 8490707334221154005U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8740835037840799136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5988815405391206280U;
            aOrbiterI = RotL64((aOrbiterI * 17838555472135715929U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 15539461383052981747U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3743772525784217714U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6352086797545969187U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterE, 21U));
            aWandererB = aWandererB + ((RotL64(aIngress, 38U) + aOrbiterD) + RotL64(aOrbiterF, 26U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterE, 30U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31494U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 27172U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25761U)) & S_BLOCK1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29768U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aScatter, 23U)) + 6163290588946759209U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 7342672468560105447U) + aPhaseCOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 11574563167017282321U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 43U)) + 2254820206194758964U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 56U)) + 1469783447473099498U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 14174828900676165088U;
            aOrbiterB = (aWandererB + RotL64(aCross, 11U)) + 16277954291890598132U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 5U)) + 14845750668693136766U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 52U)) + 150099699692047766U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1200784917165131703U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9469982764806754302U;
            aOrbiterF = RotL64((aOrbiterF * 17851969334511301943U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10956702761701710182U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7915506894975487807U;
            aOrbiterI = RotL64((aOrbiterI * 8874108311712727983U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17335794183733623213U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 557028996286989506U;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1597385667771002414U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4376417959915162639U;
            aOrbiterD = RotL64((aOrbiterD * 4626236858205178149U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 549770198518993876U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 756554555648070919U;
            aOrbiterJ = RotL64((aOrbiterJ * 16272320259614325355U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7298557532533152193U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3336802611342112013U;
            aOrbiterA = RotL64((aOrbiterA * 14679103452120080499U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2314938232094714365U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12215066333571149153U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10747052773052630601U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7762752719356805046U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6519429915769040078U;
            aOrbiterE = RotL64((aOrbiterE * 15548676502167938513U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7556691736109752918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13731245903412646404U;
            aOrbiterH = RotL64((aOrbiterH * 15581965016668635409U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 52U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 34U)) + aPhaseCWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 56U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6781U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5418U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 680U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 1691U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 5573188770530340913U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 1431772230889897111U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + 4809192776429682319U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 5576603692574369341U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 19U)) + 2720143226007220386U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17220328778565331629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9629485808442089423U;
            aOrbiterB = RotL64((aOrbiterB * 18349580416082045015U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1136998437010390983U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11893390497814523841U;
            aOrbiterE = RotL64((aOrbiterE * 5329621622743089531U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1764986431917532370U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1741014798007010376U;
            aOrbiterI = RotL64((aOrbiterI * 13414914086049500731U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12221368453236547044U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7694538641172350430U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8439120733670016501U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17472344518811560603U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3308740700728172984U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15290400462887712083U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10417U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12937U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13039U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13377U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 58U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 57U)) + 5131645209694953015U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 12070391048835379854U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 29U)) + 2604295836242338724U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 14042039029284001596U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 39U)) + 8914654543854559327U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2185619407969359869U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5187406295103352574U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10497064008152537837U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8022832481290871217U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8783061916740573472U;
            aOrbiterA = RotL64((aOrbiterA * 3309891377744201773U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10711028365596196301U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13387065038269133571U;
            aOrbiterE = RotL64((aOrbiterE * 12444578026365205255U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11187001318931801582U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14191473173276034019U;
            aOrbiterJ = RotL64((aOrbiterJ * 2491253922434756431U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16207761776716426435U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9677408414452078760U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5487303383095129949U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23523U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 23929U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24004U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24262U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 3248574644570178787U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 4506961512959200024U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + 8423739774540738590U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 6593975869641735337U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 37U)) + 16441716090557369103U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7936601450453207914U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13333752583560167065U;
            aOrbiterD = RotL64((aOrbiterD * 5389149472324384311U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8013703284795432973U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2349852779887439236U;
            aOrbiterJ = RotL64((aOrbiterJ * 2422888500648100783U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5318539364763284138U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11450957608502944376U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1957880366707810635U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9058992558327552687U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 632095686920230926U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12460364388358520799U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14734218428913777098U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16344357661370784442U;
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 50U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25176U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 26338U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32065U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28016U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 24U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 7632760812370906911U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 6007174525479723089U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 47U)) + 3362829642521821048U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 18009548556107978286U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 13U)) + 17880909432272697327U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15961567935420752568U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10136559064656837921U;
            aOrbiterH = RotL64((aOrbiterH * 14473810261421912849U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17622019364405410277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6927494824421416306U;
            aOrbiterI = RotL64((aOrbiterI * 2686290883767829973U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7125170407794874847U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12342273503071032250U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 867417849555857179U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14997696377476124836U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14874498694181230698U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4026127545746010937U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2549397729130885686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4217995818662767955U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525525344485251063U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7836U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((aIndex + 887U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2327U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 5677U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 6521330037475130256U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 21U)) + 12611880456055428940U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 12061611078130934708U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 1558112410801116984U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 13U)) + 10509115227850160786U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 46U)) + 4045915960688792066U) + aPhaseEOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 57U)) + 1196541286513243082U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15564991032722373702U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4897765238703641798U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9693901276712946763U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12327429514907752733U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6189189797708711636U;
            aOrbiterF = RotL64((aOrbiterF * 9017615866338877651U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6374267075282018852U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1888758503831341439U;
            aOrbiterD = RotL64((aOrbiterD * 74387714918264257U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14956857689299491800U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16086885494838105042U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8069724185844303923U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8878470736758734353U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10854345917959911439U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7078313614360332089U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9864025732292844871U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15083669236062255011U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 594879695916679116U;
            aOrbiterC = RotL64((aOrbiterC * 9852515479152735283U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 60U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15291U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13348U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13564U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 9519U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 5U)) + 6469584119078165548U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 35U)) + 14329756366517987910U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 12890831797059772123U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 42U)) + RotL64(aCarry, 51U)) + 3164503807500018990U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 11U)) + 177531431387646836U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 3167421392893561015U;
            aOrbiterB = (aWandererI + RotL64(aCross, 19U)) + 2813174781844753460U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10953270419153249857U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16911518309710356951U;
            aOrbiterI = RotL64((aOrbiterI * 13162785997686570445U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6616750447844893150U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10276741398025985982U;
            aOrbiterK = RotL64((aOrbiterK * 6824712685896987133U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6206043608461213208U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12021552904553405793U;
            aOrbiterG = RotL64((aOrbiterG * 10023362889960174909U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15283586234744144846U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5923238786775948571U;
            aOrbiterE = RotL64((aOrbiterE * 8200882393521882651U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11044014510971660078U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9351141024085076044U;
            aOrbiterH = RotL64((aOrbiterH * 13316079344614432317U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17703395981862992420U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10154548848376027087U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12324478347590509035U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8836420852291617425U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10193385413543886344U;
            aOrbiterB = RotL64((aOrbiterB * 824935982418585449U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 10U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24224U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24081U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20143U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 19821U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 20U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 17668251151213543491U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 21U)) + 16101602509895104517U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 12U)) + RotL64(aCarry, 47U)) + 9083915270773304935U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 39U)) + 12810720730318214811U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 27U)) + 18113428002071925621U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 1582208899354109878U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 4180688104819188154U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8954598189262820611U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15360094153175355879U;
            aOrbiterE = RotL64((aOrbiterE * 8177798855402983685U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8383954114668216260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15626783326234049197U;
            aOrbiterB = RotL64((aOrbiterB * 15058420415480073793U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10609978564404958066U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17656516608997517984U;
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 760077259110786536U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3597338735888033063U;
            aOrbiterJ = RotL64((aOrbiterJ * 6548831472863517621U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4431777844935985157U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10710423172154671296U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16267496318491473315U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10240882795242085185U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7826053487019825891U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15053729937684375907U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9418883403715727353U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11507423614799075545U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16189463984557044693U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 42U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26325U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32320U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28350U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29005U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 1042610313571524121U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 53U)) + 3505725321008825582U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 21U)) + 12584654563843782991U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 28U)) + 6645399144515770935U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 3608978423753715584U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 8089198857670370983U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 5U)) + 15207251813516399879U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9579268660105824516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16055044469473802812U;
            aOrbiterH = RotL64((aOrbiterH * 2269649280637188723U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 583811872609805949U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7027491967970873942U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12686754713465826139U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 18256061823189677508U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12708429127816136937U;
            aOrbiterC = RotL64((aOrbiterC * 12593886633108075321U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12169216645156306078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12694325407567795065U;
            aOrbiterB = RotL64((aOrbiterB * 3711789483877261899U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16109994660203297503U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4234704064165718913U;
            aOrbiterI = RotL64((aOrbiterI * 730085881474787681U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14119541943554602878U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8777769004811352951U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2556957257736134223U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15642663488392549609U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11594468530833278624U;
            aOrbiterF = RotL64((aOrbiterF * 6639306656361601143U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterE, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 18U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 208U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 325U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3848U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1530U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 57U)) + (RotL64(aCarry, 14U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 56U)) + 16451272412693907816U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 47U)) + 10099485419723255462U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 17668900099534923192U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 5497093724143181753U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 10354044773550071706U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12728258851198019099U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4144050505314242618U;
            aOrbiterA = RotL64((aOrbiterA * 13629477513971467419U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14133805325480076530U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 308863673210602899U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2672613556981540433U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11741180130160569753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12926863156769180448U;
            aOrbiterJ = RotL64((aOrbiterJ * 9726030996091054939U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 211920854786494259U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 13234608842479411078U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9164711974854618892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6667377062281954219U;
            aOrbiterB = RotL64((aOrbiterB * 2603737166987437649U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 46U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11608U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9907U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8887U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 10776U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aCross, 60U)) + 6069475454765660321U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 11483704742497268068U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 13U)) + 11055697447388986418U;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 10897095046039997004U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 4731637118230457840U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13855839187084986751U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5328208115460188239U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3800417611141123383U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12479538544291412985U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10740165998792608231U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14046827922294477379U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6492798157284955373U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13056825957483891921U;
            aOrbiterC = RotL64((aOrbiterC * 14882112110627751751U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2068184064919194657U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterI = RotL64((aOrbiterI * 16493021179127646345U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11193756120230763294U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17306750816837208999U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 4U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterD, 46U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19843U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23401U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20419U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19538U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 30U)) + RotL64(aCarry, 5U)) + 6521330037475130256U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 19U)) + 12611880456055428940U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 41U)) + 12061611078130934708U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 1558112410801116984U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 10509115227850160786U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4045915960688792066U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1196541286513243082U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5454309408259753479U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15564991032722373702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4897765238703641798U;
            aOrbiterD = RotL64((aOrbiterD * 9693901276712946763U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12327429514907752733U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6189189797708711636U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9017615866338877651U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6374267075282018852U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1888758503831341439U;
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14956857689299491800U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 48U) + RotL64(aOrbiterH, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 26U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27515U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 32198U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31637U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 30310U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 30U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 8506388683755208267U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 4U)) + 2179323259055019735U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 29U)) + 3345902531140983016U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 17456139311481306584U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 14587864088462311164U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13178947246650647057U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12866578138946916962U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 121991325166969319U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13098524333655118173U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15451329483787541982U;
            aOrbiterE = RotL64((aOrbiterE * 13580376920467431451U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9494299579678389385U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15581954810375490643U;
            aOrbiterG = RotL64((aOrbiterG * 13670002280188424825U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4487042505730624892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2774455928791636186U;
            aOrbiterD = RotL64((aOrbiterD * 15847933919136777451U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12435319582397755819U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10077180055177766823U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 12U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1461U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6304U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1261U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1617U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 12U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 57U)) + 13687218104610230596U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 23U)) + 6841550124960692709U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 42U)) + RotL64(aCarry, 57U)) + 17418968668458764131U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 8303537912696948204U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 12376614417285936537U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14215749063579232654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4111736931433665347U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8841288213954433049U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11250375934571631522U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5367367837773331275U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7262723007545807179U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15514089192382674434U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1475991716685034960U;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5531622777788629748U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8363822215908303335U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3741256932685720414U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11634667238062155772U;
            aOrbiterD = RotL64((aOrbiterD * 15925089729784547403U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterD, 42U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12624U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10322U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15976U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13523U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 14179205183062705133U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 210032324058740920U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 7387115089142500152U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 17583362781238061430U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 29U)) + 4991442849150005943U) + aPhaseGOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2891376254689854555U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10523274382407446239U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17443994099359920915U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3861893764676218667U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3366674459852093746U;
            aOrbiterI = RotL64((aOrbiterI * 14005994095369483813U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5898492634386601145U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7047353571244768721U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2257518291062508467U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14374108805453186316U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8763667021501226510U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7694695426430267863U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18261523829316379575U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 650477532238860965U;
            aOrbiterJ = RotL64((aOrbiterJ * 8291758490821819851U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 52U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 27U)) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 18U));
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 4U) + aOrbiterB) + RotL64(aOrbiterI, 41U)) + aPhaseGWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20353U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23446U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21355U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 23363U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 41U)) + 17074147006464019918U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 27U)) + 10559516626129419928U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 13280363679503946221U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 19U)) + 17657115422132457413U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 13325837013304973008U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3059707750486106037U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4529045702503050852U;
            aOrbiterK = RotL64((aOrbiterK * 12889277842182219673U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10726578475550904292U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14832537837996659885U;
            aOrbiterF = RotL64((aOrbiterF * 808060368961520519U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 220094417441809246U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15343130035105342194U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7984652435043810845U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16592263353426409884U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15649290906447931918U;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11437410545843708269U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5859769136073011444U;
            aOrbiterH = RotL64((aOrbiterH * 1065016088086441107U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 28U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 25098U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31743U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31130U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31586U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 13278949403988203974U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 9213599924054673756U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 1255746482932381798U;
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 11575321997144516122U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 24U)) + 15881587525529432437U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9846195809864862707U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12319815691858217670U;
            aOrbiterJ = RotL64((aOrbiterJ * 14271546305640811091U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16322617427294439587U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16332130810525887437U;
            aOrbiterK = RotL64((aOrbiterK * 7588076439690559343U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4920951156015336794U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16767126455124552329U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4440352337076842603U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12553595911087945223U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1437522202135436142U;
            aOrbiterH = RotL64((aOrbiterH * 2001992794165550905U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12313100454852227143U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2761983020631055729U;
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 34U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + aPhaseGWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4953U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5736U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6340U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 5321U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 29U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 11039986441331892533U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 6256024955965426119U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aCross, 18U)) + RotL64(aCarry, 41U)) + 9857443189988995666U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 47U)) + 11900944813380998208U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 57U)) + 8422577734978875541U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3100835100713928724U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11871553509810206993U;
            aOrbiterH = RotL64((aOrbiterH * 15501681886909921677U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17614749493763417027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3638372131856199916U;
            aOrbiterD = RotL64((aOrbiterD * 480683274898147025U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6582275259281025770U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17016882418498941958U;
            aOrbiterB = RotL64((aOrbiterB * 4269869255230867823U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1747214688658984715U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9356088987044015278U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4056238112133473456U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16013150119949532998U;
            aOrbiterG = RotL64((aOrbiterG * 12913648646318115315U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterF, 20U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11617U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8572U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11488U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9850U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 54U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 8367680518550579791U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 35U)) + 11491674725611181241U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 43U)) + 16673861720782164214U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 24U)) + RotL64(aCarry, 3U)) + 9786610124108350855U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 5745080601557577637U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1959402215131684684U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6121650036079196522U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13375345606276198671U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12016309761037342392U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5986936646177049603U;
            aOrbiterC = RotL64((aOrbiterC * 3585650475703294895U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1000367700904043468U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17425288243569101032U;
            aOrbiterJ = RotL64((aOrbiterJ * 2174614006719048535U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4856917474950325209U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16312111093223166419U;
            aOrbiterG = RotL64((aOrbiterG * 11046477664487805241U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 456110002032422270U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11393724374787795662U;
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 60U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18590U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 19665U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21213U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19858U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 12U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 1866656689936219099U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 23U)) + 2312314528139448289U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 14U)) + 3554037526469185237U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 405707755060974111U) + aPhaseHOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 1862976326004007697U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12992483065443288263U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3793854946371595197U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1819119223110966487U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4244007978867369382U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10280867500312580308U;
            aOrbiterE = RotL64((aOrbiterE * 13729899124177931289U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 472563452959164242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12041770406895816553U;
            aOrbiterH = RotL64((aOrbiterH * 17811798500132002631U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6118634015704900486U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13637107920449233307U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17712028184714868053U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16673735670669318830U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8602681273646630496U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6995213887710749241U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 60U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 32281U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30800U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30936U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((aIndex + 29542U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 36U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 47U)) + 13915875634607599122U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 1695770381382411673U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 3709105579778295511U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 7673376335333251804U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 35U)) + 8814147709738503518U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13451412605350381172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6447870234069609538U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4016219229618539433U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13419487997946496825U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5478309847615220345U;
            aOrbiterA = RotL64((aOrbiterA * 12953043149543448765U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3635184969215610049U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12527903812035294828U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12540800512035534967U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1684685110885338814U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12860354576326835090U;
            aOrbiterC = RotL64((aOrbiterC * 12743745087733307255U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9081823570147481835U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14369321778210049109U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17865953349448767035U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 24U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 60U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
