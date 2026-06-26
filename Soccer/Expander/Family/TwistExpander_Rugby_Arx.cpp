#include "TwistExpander_Rugby_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Rugby_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x83219C5B07B77DC9ULL + 0xC8ADC883665E2841ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA750DBCB10DC637FULL + 0xD9AE2D249E9B3454ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBBFCAF716942E2DFULL + 0xD9487F50BB17B983ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD3E5D44007C9A1C3ULL + 0xE2FC913AF04608AEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB1CCB8B2BDC99501ULL + 0x85756F0CE2C6952EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC1CB743F54EB960FULL + 0xCB4881C86952DDD1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA30EB9CBC937C6C9ULL + 0xE6C139C0F699B5E8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCC4B3389F1EB96EFULL + 0x9C8E70A0D2BB1897ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDE3593A65153A587ULL + 0x9EACE5783579A7FDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xECD14A21505ED97FULL + 0x9FA6251A0EF97064ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE20A3C16D82D9653ULL + 0xDF2BC283E5A077DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA81B2C78B5FC985DULL + 0xEDFBBC00D7A25071ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBA67B390C4930FB1ULL + 0x9ED49DF6B872BA5AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEF855F9487EB8DE9ULL + 0xDE64A08124914CCFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF7DAFF4A3C54A7C5ULL + 0xA44780426B1F72E1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x84A895459D3C1B57ULL + 0xB9271482E11A81BBULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3727U)) & S_BLOCK1], 46U) ^ RotL64(pSnow[((aIndex + 1901U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 754U)) & S_BLOCK1], 29U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4347U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 57U)) + 13915875634607599122U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererK + RotL64(aCross, 23U)) + 1695770381382411673U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 3709105579778295511U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 21U)) + 7673376335333251804U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 41U)) + 8814147709738503518U) + aNonceWordI;
            aOrbiterD = (aWandererE + RotL64(aScatter, 3U)) + 13451412605350381172U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 6447870234069609538U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 6U)) + 13419487997946496825U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 5478309847615220345U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 51U)) + 3635184969215610049U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + 12527903812035294828U) + aNonceWordF;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1684685110885338814U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12860354576326835090U;
            aOrbiterE = RotL64((aOrbiterE * 12743745087733307255U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9081823570147481835U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14369321778210049109U;
            aOrbiterD = RotL64((aOrbiterD * 17865953349448767035U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11518132079084873250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11893535026126957389U;
            aOrbiterG = RotL64((aOrbiterG * 15751374986135615095U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7084079180579206226U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2999676609847603277U;
            aOrbiterI = RotL64((aOrbiterI * 14602698397511266403U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17683445810614029153U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11576460512964896969U;
            aOrbiterA = RotL64((aOrbiterA * 5243651036457051155U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13429800604736567949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14661785761747367546U;
            aOrbiterJ = RotL64((aOrbiterJ * 4765843989277333421U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12837164345582888950U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6222666313184669392U;
            aOrbiterH = RotL64((aOrbiterH * 17402483466567712319U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5358647039491079457U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12459911673401497180U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13605465035256188065U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3333017644772803587U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15501587702102554928U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4921693371641768339U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8492287653837766613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3432736785678875404U;
            aOrbiterK = RotL64((aOrbiterK * 7326419883291516513U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2841486107704281869U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13915875634607599122U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 707861617246345083U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 20U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 56U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 60U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 46U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5502U)) & S_BLOCK1], 38U) ^ RotL64(mSource[((aIndex + 10204U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8116U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8586U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 34U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 21U)) + 9435962834163239322U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 10524704356081318973U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 13U)) + 7403401305665208680U) + aNonceWordI;
            aOrbiterA = (((aWandererB + RotL64(aCross, 41U)) + 7525414805023556493U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 58U)) + 1116686470029070951U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 13257612299137802420U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 53U)) + 9181543003986598283U) + aNonceWordO;
            aOrbiterC = (aWandererK + RotL64(aCross, 39U)) + 9739384852307501107U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 28U)) + 11308402900229016057U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 47U)) + 14935167593705272337U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 7171824007631943535U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8068411284829563567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17039236343991574134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18291683592714999632U;
            aOrbiterK = RotL64((aOrbiterK * 7771718817924840713U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6239616841884430968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10604527977569876774U;
            aOrbiterG = RotL64((aOrbiterG * 6972820410084939637U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1707724300671717658U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3802268808625297647U;
            aOrbiterJ = RotL64((aOrbiterJ * 11296811630387191563U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9423064323799920219U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 242153923313096551U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12117679073775630197U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 945801070951928277U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13094814302414492064U;
            aOrbiterD = RotL64((aOrbiterD * 14638176479878969775U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7572219725951040117U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16494986983782503428U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 2739189408707408171U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10949497978229234856U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11219643352002119905U;
            aOrbiterB = RotL64((aOrbiterB * 16900635614259262873U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14245670385849499678U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13771155918235018585U;
            aOrbiterC = RotL64((aOrbiterC * 14121731385133220921U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15722734439532828816U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11032710342174118366U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 16096465375397981585U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2071496769185495150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9435962834163239322U;
            aOrbiterE = RotL64((aOrbiterE * 10640995428633266765U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterC, 48U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + (((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterK, 23U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 36U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 12U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16256U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15005U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 12979U)) & S_BLOCK1], 14U) ^ RotL64(pSnow[((aIndex + 14176U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 14U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 57U)) + 14624277139785904404U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 6966977309498165611U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 5U)) + 205536824352530761U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 10U)) + 16629575265808255692U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 23U)) + 596881340147972746U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 53U)) + 11944412799107412650U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 4615021315668210206U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 8497630055977606216U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 39U)) + 11131601107309336885U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 47U)) + 5935883479805510099U) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 39U)) + 15629346719765798174U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5279128339113651273U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16778365912440331821U;
            aOrbiterF = RotL64((aOrbiterF * 705421028266789241U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16003052937645491524U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6723226158737614764U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16690657664909260573U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9785784358981219543U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10055457337292292710U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17919129940751761111U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11779163108592974175U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1177999477942202687U;
            aOrbiterD = RotL64((aOrbiterD * 13475069421684114643U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9190694445141492214U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15605342360346353457U;
            aOrbiterG = RotL64((aOrbiterG * 14547769706392595647U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14877565450677523492U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1074095623308025684U;
            aOrbiterB = RotL64((aOrbiterB * 7884068939436891093U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12803174154216941583U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8813356463693637033U;
            aOrbiterH = RotL64((aOrbiterH * 4898237214617563167U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6063909634038581414U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15112191502834052566U;
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13926459034757240311U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4324555954703597591U;
            aOrbiterE = RotL64((aOrbiterE * 18068922072149745351U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7183063131331255506U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18072787091203847052U;
            aOrbiterI = RotL64((aOrbiterI * 12530396154012878153U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10143386327707219710U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14624277139785904404U;
            aOrbiterA = RotL64((aOrbiterA * 12100828883424264587U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + aNonceWordG) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 30U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 54U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21260U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 18399U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21356U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 21746U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererF + RotL64(aScatter, 18U)) + RotL64(aCarry, 23U)) + 15549114274303128055U) + aNonceWordN;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 5U)) + 16466750056388063241U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + 12209449840836787142U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 14551496099734294336U;
            aOrbiterK = (aWandererI + RotL64(aCross, 39U)) + 6266576428679808622U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 54U)) + 16892841575635668152U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 7375966221423362125U) + aNonceWordO;
            aOrbiterG = (aWandererC + RotL64(aIngress, 41U)) + 11926105302821753530U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 11U)) + 16219253791550461124U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 57U)) + 7299056065319248160U) + aNonceWordE;
            aOrbiterF = (aWandererB + RotL64(aCross, 21U)) + 15234001484933728439U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6615802589932632120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5481176858895819247U;
            aOrbiterE = RotL64((aOrbiterE * 3604590158551984877U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17220507586542139380U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterK = RotL64((aOrbiterK * 10634645686035907603U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16981960446540932787U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10897565927079518588U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 418843936329303571U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2746889569299593263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4894117146736361379U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2656750612042673191U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18294823016957137777U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 86828501068883383U;
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6322053762209547826U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6754524552483363820U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1746163087826694641U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7306452650619361017U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12717201204443785828U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 6121251603905574991U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10422327053543898585U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14786413282036348183U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8713024293107068275U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4599182534559908397U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5080179685914177581U;
            aOrbiterH = RotL64((aOrbiterH * 14984675846207762951U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6527649204956325409U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8327234966110052920U;
            aOrbiterC = RotL64((aOrbiterC * 9343969092668123661U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7845497893651522069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15549114274303128055U;
            aOrbiterD = RotL64((aOrbiterD * 15263427406359082909U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 30U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 19U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterA, 60U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22689U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 22855U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22405U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24773U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aIngress, 41U)) + 10336802574069791273U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 169025388197058936U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 3U)) + 6541354188379168846U) + aNonceWordG;
            aOrbiterC = ((aWandererD + RotL64(aCross, 54U)) + 16223920526599306104U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + 12756613707692514808U) + aNonceWordL;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 5082475548176484035U;
            aOrbiterD = (aWandererA + RotL64(aCross, 35U)) + 4907435526952698526U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 44U)) + RotL64(aCarry, 23U)) + 14236627073831834337U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 11502511046130497584U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 3679044835550219497U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 51U)) + 11254838916686736746U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10582608424233200966U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4628253464169957835U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17664454668473204465U;
            aOrbiterG = RotL64((aOrbiterG * 4234720298731378527U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3798386391743884889U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1379331161819246587U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 13086160171095077295U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9816600392407327227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16781971616348376878U;
            aOrbiterK = RotL64((aOrbiterK * 12503867584828289879U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4807797577690520554U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2492057261148595922U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9453302540675483005U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7909676419643119585U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 256053568910383007U;
            aOrbiterC = RotL64((aOrbiterC * 11965085163352053161U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16179914439220412472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3968867762761955845U;
            aOrbiterD = RotL64((aOrbiterD * 7473632378251893139U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7474832923901283742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4736994731050735779U;
            aOrbiterB = RotL64((aOrbiterB * 9839654409121414047U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 596484364660389193U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13822222274464306169U;
            aOrbiterF = RotL64((aOrbiterF * 1723502278319885511U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16307920280681985443U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3505106171801702915U;
            aOrbiterE = RotL64((aOrbiterE * 8479675421552861243U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4987142580981135150U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10336802574069791273U;
            aOrbiterJ = RotL64((aOrbiterJ * 2670706512498539705U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterH, 53U)) + aOrbiterI) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 20U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aNonceWordA);
            aWandererD = aWandererD + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterD, 37U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29717U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29424U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30827U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 32035U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 50U)) + 1952750591494698524U) + aNonceWordH;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 4488270851303332830U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + 2738763375328927635U) + aNonceWordM;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 6728843649480454340U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 47U)) + 10490717875258865358U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 21U)) + 1429288737812910205U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 19U)) + 2761375016998907636U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 41U)) + 1088988605204499835U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 37U)) + 6829840407300289709U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 9267240337867690471U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 39U)) + 8120113021183975703U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1340980511302566784U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11874452169979878835U;
            aOrbiterF = RotL64((aOrbiterF * 8638486178860092537U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1872314794140971426U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6013952618696225751U;
            aOrbiterI = RotL64((aOrbiterI * 7994863587373565715U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3644011378086236002U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8501867691997891731U;
            aOrbiterC = RotL64((aOrbiterC * 7115282675461711509U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2493546555198066143U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5179240189571799179U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1267579130962756135U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11273348247858394197U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4577476419423118925U;
            aOrbiterG = RotL64((aOrbiterG * 8427261005061162673U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6201955123046621919U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3930651302557530185U;
            aOrbiterB = RotL64((aOrbiterB * 1563512534463027965U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 7571426325227856019U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11098508505512361002U;
            aOrbiterA = RotL64((aOrbiterA * 9229352429618815089U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6154830144380484305U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4282054616147137364U;
            aOrbiterJ = RotL64((aOrbiterJ * 14984813139796280171U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14818120999774989697U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12174471855744785761U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3061488029278974095U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3117297607579915182U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2979217539186455309U;
            aOrbiterK = RotL64((aOrbiterK * 12235308335184626143U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 824986728082249286U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1952750591494698524U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10162288961171400541U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 53U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 14U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterB, 22U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordJ);
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

void TwistExpander_Rugby_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE8B0EF17E5C50D4BULL + 0xF8BA66614425D0C0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFB6C559A85D544F9ULL + 0x8590B8CDDF91B6A1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFB3DA90E94A9B691ULL + 0xBEAD84EF1C8CBFB9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA510227607DEAF11ULL + 0xD80ADD201119416AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x905E738FAF55DD65ULL + 0xF6853A49AC7B0105ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB7F00C2649E534A7ULL + 0xACF5E82768266A70ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98632747F0AF6DABULL + 0xCC0364B9339351A4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x92D0D7ADF94932EFULL + 0xBB2C82582B36BFCAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x947AE7F13DB722B1ULL + 0x835EFF686F16A1C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAFDF0C2576766723ULL + 0xB79D8FAF77A157B4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA04D4F2ADD2C4F55ULL + 0x925ECABEA4F9620AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDED387CA9412C5ABULL + 0xFE6D79E5324E76DBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE90A724B0D5BC6C7ULL + 0xB19326592F09FA6DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD08727DCB50AD8B1ULL + 0xF50F98F718D234B8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCC55E21B382A95D9ULL + 0xB367D187ACD7268CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xCBBD5A39EEE69397ULL + 0x8F591ABB3AFD3EB9ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1194U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 6488U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2038U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 1824U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 26U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 53U)) + 1898718075389870739U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 5U)) + 5631794889237247403U) + aNonceWordN;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 58U)) + 18219714659484524607U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 47U)) + 15419581386225732921U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 9125575431710198210U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 13U)) + 12205871520544965505U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aScatter, 35U)) + 7617534300497343422U) + aOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = ((aWandererG + RotL64(aCross, 22U)) + RotL64(aCarry, 43U)) + 18017579105368135814U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 19U)) + 10693882161946020042U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11669615701700895306U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11045110212889232165U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 5965171269273719849U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18019107802806469913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4899009736070044310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17412253404253730364U;
            aOrbiterG = RotL64((aOrbiterG * 10791901166391946485U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4826286251927854181U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4523455921321845084U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4132514462154182215U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7164745605985109269U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14107325508977225261U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6297434295807635654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8813887638672996646U;
            aOrbiterD = RotL64((aOrbiterD * 17495632530773158201U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11086381278955626084U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5660733992573928887U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 11248164458720777889U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14851044686208609882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12707776386060264479U;
            aOrbiterC = RotL64((aOrbiterC * 4470919091467313071U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11508023384209716657U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11752973809740920034U;
            aOrbiterJ = RotL64((aOrbiterJ * 10212754472298834769U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 58U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 38U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12068U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 9155U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15827U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9133U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 8793908991006073956U;
            aOrbiterF = (aWandererD + RotL64(aCross, 34U)) + 2932916283348441943U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 41U)) + 11069042087940968262U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 11U)) + 14369628676782894441U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 8602903272780978282U) + aNonceWordP;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 56U)) + 3827036107178568820U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 8905245209036772489U) + aNonceWordA;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + 13331387530760017893U) + aNonceWordE;
            aOrbiterG = (aWandererA + RotL64(aScatter, 23U)) + 9880107580289737823U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10199619040626900278U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2466307560891374281U;
            aOrbiterC = RotL64((aOrbiterC * 6295342978834217571U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13973403407981259448U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2851460278409385243U;
            aOrbiterI = RotL64((aOrbiterI * 11226902976321781743U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10365453393815690776U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2382382358987358791U;
            aOrbiterE = RotL64((aOrbiterE * 481563628980705781U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5058198848163792422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10500434740387593487U;
            aOrbiterJ = RotL64((aOrbiterJ * 5946747708776079787U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11289798395177667084U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14327152153231286666U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 18155778059595245561U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 8065137263811956313U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3865153574847924816U;
            aOrbiterD = RotL64((aOrbiterD * 9495741102667755161U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18102279969722473375U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6306428427188742325U;
            aOrbiterB = RotL64((aOrbiterB * 17826782872351406167U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16953348204663693724U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 11950791817032898613U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1498946055469611133U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11980823193543752994U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 17845490308799454871U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 16385153013485463791U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 18U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterD, 52U));
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20676U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22247U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20815U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 21188U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 60U)) + 11410829607777684449U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 21U)) + 7502698839700975347U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 13267685058252106173U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 39U)) + 238242706996630625U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 8184695499511454281U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 12767823220461985403U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 3U)) + 12293198423143850330U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 11149495229952495939U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 28U)) + 7556992689338382800U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3431338808774134649U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16863099140844995099U;
            aOrbiterH = RotL64((aOrbiterH * 752376661101787919U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17872458049880677604U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16760153457252546974U;
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3115544493537438408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4359882942759752958U;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13387113067202396536U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12955690074544490161U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12449941770827974511U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15614054443728226807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1939441328066616114U;
            aOrbiterK = RotL64((aOrbiterK * 4484917074808974359U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4599016263007782537U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9962305629016158048U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1496184427500037279U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8428467674122750557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3938884087806393439U;
            aOrbiterD = RotL64((aOrbiterD * 12810531094050481761U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6018636830758044658U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1510372000641305416U;
            aOrbiterG = RotL64((aOrbiterG * 9002834928626918247U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17592782466215337843U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8119921507606870360U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1299795061644535485U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterH, 30U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 30U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 58U)) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28180U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32050U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25746U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26463U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 1297415699043177788U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 47U)) + 17583786534509260153U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 12U)) + 643197858925708798U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5062653766915694874U) + aNonceWordN;
            aOrbiterH = (aWandererE + RotL64(aIngress, 29U)) + 7034273638367180511U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 2026909726972916996U) + aNonceWordI;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 43U)) + 2785690475553211646U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 19U)) + 2910341716302991892U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 56U)) + 2834181605200829791U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13323052600571281928U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10434901530315760460U;
            aOrbiterJ = RotL64((aOrbiterJ * 2042210188346767033U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 247903955625194782U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5196515747387257163U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 1799024689023272275U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7196305682377987476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14777739876892587484U;
            aOrbiterC = RotL64((aOrbiterC * 95220583948241581U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10609060796540136671U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8386027207212484155U;
            aOrbiterA = RotL64((aOrbiterA * 4855610536246556893U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 729659744301903424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2350564261412606157U;
            aOrbiterF = RotL64((aOrbiterF * 16713856782349084977U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16611987556673864177U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1525195188708550503U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10045858602151004553U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4654808490980989596U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8189569777087686263U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17278657566389299577U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10932857495004451792U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1833880112534916813U;
            aOrbiterD = RotL64((aOrbiterD * 8004341577533825681U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 13100236350175516423U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2773759534195186313U;
            aOrbiterI = RotL64((aOrbiterI * 3194954066097323161U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 52U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 35U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_Rugby_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFE7F3DE3D4C06D5DULL + 0xC61288A269C024A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFFE682A0EE07D319ULL + 0x8AC93008D38E1F6AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE344434B65F3F679ULL + 0xBAB1E0DEAE384BE5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCA78EE14A2A09195ULL + 0xFC6F7B4EAA7C58A5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB32CF27293BBF7F3ULL + 0xC30DB2FE6A98B51EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8FD781E622A1B18FULL + 0xF1C72DFD40312268ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF71570C56C73BB13ULL + 0xB3383615984A67CBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE3DF2FC546B0D3A9ULL + 0xC7778FBF94832293ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFC7E99698F08AFC1ULL + 0xE19ED79D23EEF1C8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA8316325A3D72E57ULL + 0xB161C41A3F659A84ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x827E64310CBBDECDULL + 0x8AB6FDAD47B20362ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE8DB5C97744D1605ULL + 0xDD8F7922D5A1919DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x96DD02CA69D64391ULL + 0xFBBBBD10F6D508E6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF89C678057354023ULL + 0xED89535EA90C6C91ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF96F8CBD89D399B7ULL + 0xC78C8A6E126E8CF1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBE05369F28E5BB6FULL + 0xDB738FD7B1972A3CULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 853U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6272U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2819U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 8146U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 24U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 18U)) + 18255347001097480328U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 13679246790311505735U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 10565839529765027116U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 14327172566224769901U) + aNonceWordO;
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + 16239024612038195174U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13800012174212131890U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13900288860157577583U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13177682776510523095U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4144386119777112740U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3154558262670631372U;
            aOrbiterE = RotL64((aOrbiterE * 13236911910092437063U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7456728543137614001U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11709519851158935384U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 7016689518570071587U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15607438907832240304U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9276575329661725624U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 6459435969129449226U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6442382118416542275U;
            aOrbiterK = RotL64((aOrbiterK * 2921027306686588233U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 4U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aNonceWordM);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9409U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10004U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10256U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 15220U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 3970829908171131502U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 7040283759419531991U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 22U)) + RotL64(aCarry, 29U)) + 11856292169397052901U) + aNonceWordN;
            aOrbiterB = (aWandererK + RotL64(aIngress, 3U)) + 819598588791819022U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 43U)) + 2176451710970866848U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6454704928613390494U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11792122387218053841U;
            aOrbiterC = RotL64((aOrbiterC * 17994898985794518565U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9254780213489752211U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16591812589999846482U;
            aOrbiterJ = RotL64((aOrbiterJ * 5425771603523423167U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 1471246223935074832U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1424843083106386453U;
            aOrbiterK = RotL64((aOrbiterK * 15020536982657410783U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1856469958050891629U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6331743690452052712U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15327924647897459645U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10351075711345476487U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9518585245330480185U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 3792179827396760391U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 18U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterC, 52U)) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17194U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23365U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21038U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 20834U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 28U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 57U)) + 12690502671561165478U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 17519943923428102801U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 4U)) + 10705515807975331385U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 16586447272278538179U;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 8006560996840971798U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12928600185788857701U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14240723153798267172U;
            aOrbiterI = RotL64((aOrbiterI * 7446040187505339853U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8636219177994872072U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7586790235186467512U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15052686382507614169U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 1103807034179512424U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7547526530239498693U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 3360295583636013509U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8380239679344786397U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5690809173787433519U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 5354724308093372953U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8390902801141804609U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3507306189192059486U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 18336280496510253103U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterI, 34U)) + aOrbiterC) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 37U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28829U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26740U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25889U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30247U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 50U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 7825479804710770560U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + 5298124167101358123U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 17774541024369233726U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 56U)) + 7679371833537454082U;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 5385914900748772224U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3879781930908486531U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 659110346638873236U;
            aOrbiterC = RotL64((aOrbiterC * 17439162088869824407U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10749021728538539749U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 3631252455767429457U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 8552825360915119613U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2271978810960685021U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5963558780692551176U;
            aOrbiterK = RotL64((aOrbiterK * 4772055335210781149U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 974909966119198104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9296998242911152296U;
            aOrbiterE = RotL64((aOrbiterE * 2613629915877957661U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2245318466901521959U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13391076374843288568U;
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 60U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterK, 51U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordK);
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

void TwistExpander_Rugby_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD2AE5EC2CBBA6107ULL + 0xC84CE4DD5FE05723ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC4EB138F760165B9ULL + 0xE55244557E2A14DEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA05DB544301EA0DFULL + 0xD78B4CAB568AF56DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD6F0CF521FF90FA9ULL + 0xDCF7D0DB46F9BB85ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCC239BD0D34F6A2DULL + 0x8B26106E685F03ADULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8447CDE0B0BB7B63ULL + 0xBC71D9EA0841D59AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x82AFD9C57E0446B1ULL + 0xF586C96372DC3E40ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC3013F61138000CFULL + 0xB659F62B241784CDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x99D63DCF54E2E98FULL + 0xAACEB945AD6EF6A1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBF803BCF77AF3091ULL + 0xBDEFCECD018BD5EFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF2915F4A50F8B301ULL + 0x8F3086D4D178BEC1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9744D60A835BDD9DULL + 0x8D9B5F5F61838D26ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC82F1D6869D6F597ULL + 0xF09503CF9D1F4380ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC8DF70DFDBCB7EDBULL + 0xB19C6B8E4E2514BCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC8796DE72812DDA9ULL + 0x982067D1E0601C2CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE3400B12C65609BDULL + 0xBF98447A61421E4CULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3592U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 735U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2410U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 2572U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 14008824488073394623U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 53U)) + 13317978415866411468U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 13U)) + 13209180141897453900U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 19U)) + 11870521586865233578U) + aNonceWordG;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 8052156380448047385U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 35U)) + 12158131176743680605U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 19U)) + 14674467487607719347U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18055496790566231147U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3838105585041578784U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1075709247574580091U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2839568255183054418U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11933612922864258179U;
            aOrbiterB = RotL64((aOrbiterB * 7571964469321160347U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6289849094151630580U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2640344350528492271U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 16197726750829369365U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16306175266267657791U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3339898380394883600U;
            aOrbiterE = RotL64((aOrbiterE * 7105436590182982373U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15017076663742800002U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8973064296077602496U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 9309462227233615761U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 17580319233338139859U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14063208878807603874U;
            aOrbiterJ = RotL64((aOrbiterJ * 16601475239075164585U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13326130855721009942U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12843186026737544416U;
            aOrbiterK = RotL64((aOrbiterK * 4975848122837321619U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 58U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterI, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterA, 58U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9777U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11984U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10234U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 11113U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 7960325128608297381U) + aNonceWordE;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 12773836012104052042U) + aNonceWordA;
            aOrbiterF = (aWandererE + RotL64(aScatter, 29U)) + 3173972621347773016U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + 3708401356314308171U) + aNonceWordC;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 43U)) + 950774285720019449U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 4170092315705438265U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 58U)) + 17000449130864980747U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8793910540062893860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 520277969543516469U;
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12762214857389827271U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2932451184340207695U;
            aOrbiterC = RotL64((aOrbiterC * 7513337346940091655U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11062179998786293839U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7919119215271524178U;
            aOrbiterK = RotL64((aOrbiterK * 9053677007180081359U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1774988449597115155U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3799792889466518953U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1815062051307896589U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 15260373951371654483U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 2208604434669491625U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12867546628945676853U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7772820973895846946U;
            aOrbiterA = RotL64((aOrbiterA * 7581704643538761985U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14213957831821966834U) + aNonceWordI;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 16561105721170419454U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 2540533987337175367U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 56U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23308U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22111U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23217U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17698U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 29U)) + 14499676118633326000U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 3U)) + 17191273593018552288U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 36U)) + RotL64(aCarry, 11U)) + 4085176294948097737U) + aNonceWordG;
            aOrbiterG = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 11112671474158908186U) + aNonceWordO;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 57U)) + 8745787969012266485U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 18074049663777707948U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 51U)) + 2543758649719164688U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4659584749412700523U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 974639159259871273U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17918719351847605523U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9211220687971081987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8567024626862182714U;
            aOrbiterJ = RotL64((aOrbiterJ * 7755874089832496393U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5803002132294840900U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11968489432878148467U;
            aOrbiterH = RotL64((aOrbiterH * 4501441062617123165U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9470807228394903442U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1692347973120388469U;
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16510815732690193145U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterI = RotL64((aOrbiterI * 14091736464659561165U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1518824876475937620U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 701225390867330446U;
            aOrbiterB = RotL64((aOrbiterB * 12264618860580199927U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8425976693733003889U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7182176375442410367U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8860605703761731859U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 11U)) + aNonceWordL);
            aWandererF = aWandererF + ((((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterG, 60U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27059U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 29524U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27834U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 28586U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 48U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 12122689833405846292U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 9640400270962766788U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 5U)) + 9141937998266739071U;
            aOrbiterC = ((((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 51U)) + 12899395770434090537U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + 13457918115408031842U) + aNonceWordM;
            aOrbiterA = ((aWandererI + RotL64(aCross, 19U)) + 15134784483576000943U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 41U)) + 12540961268790055438U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6306886773092764230U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13573343491337243121U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15893457012357368707U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8545588657348974413U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10891410570357275120U;
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2877137119767060151U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9178097682386595144U;
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15528007881855616978U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11368419529245281435U;
            aOrbiterK = RotL64((aOrbiterK * 12433207037378339309U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5932738914934356645U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 5551842263864055419U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 16093776759971522681U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3824433359595690603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17184628855571662441U;
            aOrbiterC = RotL64((aOrbiterC * 691208053136187317U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8724462245014132623U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7481349499528092352U;
            aOrbiterI = RotL64((aOrbiterI * 8212182934509617583U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 44U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 6U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 54U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_Rugby_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x91793EBB99C92FEBULL + 0xB34A741D22613EE0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD0C64B9D85A349F5ULL + 0xBD225A2682C5C82FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x95D9F171F764A2CBULL + 0x99C0FBDD0F6D38B8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC945208F7A577F95ULL + 0xC07E4529D79150BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x98A0C755E76DD757ULL + 0x9105CEFCA988B2DCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x98576C0A68E62953ULL + 0xEEEF2916EC00DE6CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCA3902C872B4E92FULL + 0xB36A316129C78D65ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x90954BD477576FEDULL + 0xD3974406046678E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBF17633EC0635555ULL + 0x8223C7DE3909A743ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF0B672EC64FF9143ULL + 0xF60436A2EB7C2D7FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDEE03CB02566CAA1ULL + 0x97B87BDBFDD7208BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBC8775FB28911E25ULL + 0xB75AF45DA12CBC82ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA05DA00BF3115FD1ULL + 0xD8E75C3C5EC3F7D6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB72030CDCA88C6B5ULL + 0x8525A9EBF837EB21ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDE3875AE371B1ACBULL + 0xCAD3DFE6F4671BEEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF16BBB032D384A11ULL + 0x98AD628BA3856990ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2628U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6969U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5539U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7405U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 12980104182836602177U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 51U)) + 3172622203188863995U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + 1170974132219980203U) + aNonceWordH;
            aOrbiterG = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 6035201940965047490U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 18033907118424996722U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 57U)) + 14604813424800580304U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 39U)) + 13720232492851066035U) + aNonceWordA;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 3902659710585257448U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8331560652661619868U;
            aOrbiterI = RotL64((aOrbiterI * 11418103770615560205U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4485014147538689794U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 168202636924512424U;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16227825670092707848U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4792781933944671365U;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12636865372722601282U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18198291399585556632U;
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3650053185419807206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5897288963905408776U;
            aOrbiterD = RotL64((aOrbiterD * 3706949366974086151U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9922308113622901726U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4025213180483632557U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14969461950939646117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10231661776135056651U;
            aOrbiterK = RotL64((aOrbiterK * 11284575051455238501U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 19U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 44U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterI) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 12936U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10763U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10852U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15672U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 1457104756581596530U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 37U)) + 6127240317844622874U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 46U)) + 16492290056044189421U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 27U)) + 10963676850938416468U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 11U)) + 4872917367399752405U;
            aOrbiterC = ((((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 15218882377875616148U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 5934166612122118251U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14215280930872003003U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11428034799044600979U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 12162528943733976177U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5453003654321728726U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14273775120265649389U;
            aOrbiterE = RotL64((aOrbiterE * 5139018128323795309U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 328723770018440271U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13032190719588211088U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2386881543033598494U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1649501123340887116U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 16462401546754210583U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1510579201823042227U;
            aOrbiterA = RotL64((aOrbiterA * 16287912400104043275U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 6889066000014251983U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 11324594596597724357U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15344987814648586023U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12237796033168436537U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17306069670330000343U;
            aOrbiterF = RotL64((aOrbiterF * 3167451351403385259U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 20U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21752U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20386U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21195U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20072U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aCross, 19U)) + 13442819395490639310U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 37U)) + 8187292523194120936U) + aNonceWordL;
            aOrbiterA = (aWandererI + RotL64(aScatter, 5U)) + 11469697159823131388U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 51U)) + 13414083692375929653U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 11404010733687907517U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 6783212827186218247U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 8561131439340372614U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6252609642004429113U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12804867444200448952U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3114688959081972615U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2739648749603690781U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14808861217017399752U;
            aOrbiterF = RotL64((aOrbiterF * 373911885694012101U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17588866502571268888U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5882260142735642980U;
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15493099088132862949U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5175647411532429582U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14279707376173642767U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6826363572161275158U;
            aOrbiterG = RotL64((aOrbiterG * 5263708315440161809U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13267185753040999992U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9980987858092888720U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13210290848800728635U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3582972937645514549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10140409019562890804U;
            aOrbiterC = RotL64((aOrbiterC * 6944490201647678479U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 23U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 50U)) + aOrbiterG) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25442U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32621U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25973U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30580U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 48U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 23U)) + 17019646486641172469U) + aNonceWordK;
            aOrbiterE = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 12276141179299971572U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aIngress, 13U)) + 3617241694029841555U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 37U)) + 6967963401259371737U) + aNonceWordN;
            aOrbiterK = (aWandererI + RotL64(aCross, 51U)) + 6340709284279891017U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 43U)) + 456065368903896482U) + aNonceWordJ;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 17686765719908116203U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1322045955429785736U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5163772703302372887U;
            aOrbiterD = RotL64((aOrbiterD * 3193272189179082313U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 13268431135020363252U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6538789950366849332U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 5352960308459065837U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10390344544314544893U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5087084271300584267U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15149302947570776165U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13423071121590981727U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 15814349432207734533U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4129091815978464507U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17024797553831962245U;
            aOrbiterB = RotL64((aOrbiterB * 3137753479364378175U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6501545108779991661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11930037791867597447U;
            aOrbiterA = RotL64((aOrbiterA * 4904739567549702851U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4667298703308315851U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6315980380900062127U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12080555704907924637U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterH, 20U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Rugby_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA554171835A64A3BULL + 0xE6AC5F96DAAFFBADULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8970E0D8D31D9633ULL + 0x887AA6E6F19EC7DBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDA021714F9639595ULL + 0x9C031C0BE8F6208BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB15DE9A087E3E2E9ULL + 0xF11A358CF69B8286ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA1DAE4271FEC6CBFULL + 0xF82BC5773DBF7E89ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8D572A6E4EE090D5ULL + 0x9DBE74152D5982C4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAA5C54F1CF918F39ULL + 0xFE62FCEBE8540F41ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x86D148A3B7258DBFULL + 0xE231535A211BE96EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8218957B8880FA2BULL + 0xF10F976FF5880FD3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x99B07EA9BFFEEF63ULL + 0xD35FB92B6DDD65F0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8519D1D43E8DC043ULL + 0xF00B9E0496A7C814ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF6DDFA6A88E86CE9ULL + 0xAA1DEAF3D641D74FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD7E53293167810B9ULL + 0x9DF3F520C3856F71ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDFA36B557F8DC329ULL + 0x8A7A034E438190FAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDAED8BE4AC371E2BULL + 0xF87C57BA640BAEB1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8EC8BEA16473C6D9ULL + 0x96CC763B8BFBA449ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6002U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1015U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 918U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 5513U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 42U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 3612110001869385068U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 47U)) + 16340824141280225936U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererC + RotL64(aScatter, 38U)) + 15222338965130765231U;
            aOrbiterE = (aWandererF + RotL64(aCross, 53U)) + 6649270508107155041U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 27U)) + 768217258655426384U) + aNonceWordP;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 29U)) + 4481855259658861851U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 35U)) + 18318041934562434016U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 51U)) + 4212457153804401807U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 23U)) + 16143621095636987628U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2095664232866642086U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 53U)) + 4339527736737366572U) + aNonceWordE;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13679353177869884790U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11582168502846418236U;
            aOrbiterK = RotL64((aOrbiterK * 135539430034462861U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10451330452898542191U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12951448817640617841U;
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15389161934419370747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4754886272708253014U;
            aOrbiterD = RotL64((aOrbiterD * 16638243718191281597U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11746389873929280688U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 12042680172517298768U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3814780289755857543U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2648103752465009244U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 451594673632597973U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 8496763663271072425U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5696534794094099710U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14609435045257077395U;
            aOrbiterI = RotL64((aOrbiterI * 14658408563237468407U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11599395126850950133U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12699598504604446664U;
            aOrbiterG = RotL64((aOrbiterG * 14313494063098111823U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9398465148537154745U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12139736860648011256U;
            aOrbiterJ = RotL64((aOrbiterJ * 15257503229375247987U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5390816291244486383U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2797988892316486895U;
            aOrbiterF = RotL64((aOrbiterF * 14668138881285892065U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18356290434261054712U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16582824574485822826U;
            aOrbiterA = RotL64((aOrbiterA * 7207935384746719969U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9858803484150150915U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3612110001869385068U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2862887443435821143U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 60U)) + aOrbiterC) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 54U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 21U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9593U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9947U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9825U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14529U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 19U)) + 13481227414590594621U) + aNonceWordA;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 13U)) + 17425964381118918026U;
            aOrbiterI = (aWandererK + RotL64(aCross, 3U)) + 4792004356135956581U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 5U)) + 11926849936000639098U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 46U)) + 990697329347742142U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 43U)) + 9307721505373076588U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 11U)) + 17605732738841908719U) + aNonceWordE;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 13110764518634187439U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 26U)) + 17970109897810645911U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 10273133817644703654U) + aNonceWordC;
            aOrbiterE = (aWandererC + RotL64(aScatter, 37U)) + 11239046688920468137U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8355821483275763145U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15522151127786049345U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5381663179722418112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9551368011768104906U;
            aOrbiterF = RotL64((aOrbiterF * 14202470972121732997U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16264476585232221270U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7721417776432288282U;
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 339418090653475277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3247926250495935511U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 16824669543765729097U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3390560045236418590U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3894024951542543635U;
            aOrbiterC = RotL64((aOrbiterC * 10599637790900418767U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3878539166189668154U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5617705593218220843U;
            aOrbiterG = RotL64((aOrbiterG * 82771190372750823U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12320861089148474544U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14943790251625519550U;
            aOrbiterB = RotL64((aOrbiterB * 13758322022902008313U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18119213517612562775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1413193144229486646U;
            aOrbiterJ = RotL64((aOrbiterJ * 14562375280658115687U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14810150213456844196U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8468712395797520201U;
            aOrbiterD = RotL64((aOrbiterD * 8167911669632436949U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13501570100536254566U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15409772061478100850U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 955182899606655851U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8621805947309982779U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13481227414590594621U;
            aOrbiterE = RotL64((aOrbiterE * 9591362493722704105U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 26U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterK, 34U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + ((RotL64(aScatter, 40U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 26U)) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 22U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16625U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 19578U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17796U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21220U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 41U)) + 4773124477323378268U) + aNonceWordN;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 16848723289435796005U;
            aOrbiterG = (aWandererH + RotL64(aCross, 50U)) + 13846642134917107058U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + 6472057872482789939U) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + 2747019500690707226U) + aNonceWordJ;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 9003965289739733880U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 3013390651936257377U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 3331004709895625067U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 13U)) + 15355010435553517129U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 36U)) + 7709870658004280052U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 27U)) + 13568728443963926564U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12409548853419307131U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 969183352023661537U;
            aOrbiterG = RotL64((aOrbiterG * 5549220554838837145U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15370309834426476775U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3896803894396631184U;
            aOrbiterA = RotL64((aOrbiterA * 11018830202891911603U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10848873633291935766U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12885336509190543440U;
            aOrbiterJ = RotL64((aOrbiterJ * 1487357252619221365U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8252290890093788010U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9201553615601641350U;
            aOrbiterH = RotL64((aOrbiterH * 420321130559162915U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14014209645503188472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4015071464301844550U;
            aOrbiterF = RotL64((aOrbiterF * 17444195018239904971U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16173085647514027347U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16916627014974363360U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7699587344277490953U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1591680303404522110U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16499606051269327916U;
            aOrbiterC = RotL64((aOrbiterC * 814405848002794813U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6932673635509444619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8745681160108707944U;
            aOrbiterI = RotL64((aOrbiterI * 14565255558668084787U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10387263947888920455U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2553335462317280031U;
            aOrbiterD = RotL64((aOrbiterD * 7253573275397985211U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17449861295444216249U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15716408844914738774U;
            aOrbiterK = RotL64((aOrbiterK * 10132631423215542589U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 16974370193820578179U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4773124477323378268U;
            aOrbiterB = RotL64((aOrbiterB * 8982190762960590543U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 50U) + aOrbiterF) + RotL64(aOrbiterA, 6U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterG, 56U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 20U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26095U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 31159U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25494U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 30431U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aScatter, 27U)) + 15813325389431304548U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 2223874171125403602U;
            aOrbiterF = (aWandererB + RotL64(aCross, 21U)) + 5510483568496824130U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 23U)) + 15474152493495661876U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 43U)) + 16846339705130829195U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 5U)) + 1289670576865739669U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aIngress, 58U)) + 18017354919647006944U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 39U)) + 8539685539928984921U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + 3333721400836704048U) + aNonceWordN;
            aOrbiterC = (aWandererJ + RotL64(aCross, 3U)) + 2261560416623815491U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 14U)) + RotL64(aCarry, 23U)) + 4377786131746816567U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18047393176583722719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8184724021940434631U;
            aOrbiterF = RotL64((aOrbiterF * 9800116157750921119U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10469895939183324807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14543391765109879223U;
            aOrbiterE = RotL64((aOrbiterE * 4817987697437667225U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5757225781746158178U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3539000495894022869U;
            aOrbiterD = RotL64((aOrbiterD * 1032298408884695925U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11288971092707065923U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2761384065186568294U;
            aOrbiterA = RotL64((aOrbiterA * 3323838837427471051U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7120580145300417101U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6977246291769372866U;
            aOrbiterH = RotL64((aOrbiterH * 15170353875184253779U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17625434527765525937U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3299714663631376190U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6532628892760776767U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10331889953489885250U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8550932256881727932U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13085531621192583719U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11151195711186126257U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2552002192824926483U;
            aOrbiterB = RotL64((aOrbiterB * 9754056316698523849U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8038115194286715268U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16594489591573505305U;
            aOrbiterK = RotL64((aOrbiterK * 1241387574663818247U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13476964484361081681U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2136330439951908303U;
            aOrbiterI = RotL64((aOrbiterI * 12728359054660550527U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 231990686776499700U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15813325389431304548U;
            aOrbiterJ = RotL64((aOrbiterJ * 9155088985405261637U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 36U)) + aOrbiterF) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterD, 60U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Rugby_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF4CC04ED9668AD85ULL + 0x9BF776A8A2CF6BC6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCBDE0D1F9BABFB17ULL + 0xC36CD8974544C2DAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC3B516CE3DBD35EBULL + 0x971D727727E1BDF4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAAE1FFE66C2BAB35ULL + 0xBBA60FB78AD777B1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB658A0666893646BULL + 0x9B523315C3158707ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA74CAE2150F90CD7ULL + 0x91481C640ADD6D97ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAF274EBDD3CC1A61ULL + 0xBEA88C35CA57F9C9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDE514E64F8944167ULL + 0xEB0C43B6E4A14ECEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD7032DA74C3E70EBULL + 0x9A5720198AB615A0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCD859B4F1329E92DULL + 0x8F64383A02EF8CC0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9B267728CDA54E95ULL + 0xA864FE3E75DCB6CFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9F12F08613ABE755ULL + 0xC4AC33367A83D6F2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB924EDD017DC85D9ULL + 0xDC0F8B13627DD3AEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x96549B971246ABC5ULL + 0xC97678570C825568ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9FDCBD9A40584895ULL + 0xA92C5513B23686C8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDEEAFC99C221CF81ULL + 0xD48DC9BC42007B3FULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2080U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 615U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5219U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3846U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererF + RotL64(aIngress, 13U)) + 9023059520606551446U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 39U)) + 662441755115638133U) + aNonceWordE;
            aOrbiterG = (aWandererC + RotL64(aScatter, 27U)) + 16957253361196144712U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 3U)) + 7840955025765308605U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 346855809270395799U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 3U)) + 16099139781586668343U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 57U)) + 3706457327118322098U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 12166825885547622870U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 50U)) + RotL64(aCarry, 51U)) + 7792658665720344200U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7128477606152986326U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11116533962780290084U;
            aOrbiterG = RotL64((aOrbiterG * 11993485572912492297U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 10443889548568288532U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4402387036946561017U;
            aOrbiterE = RotL64((aOrbiterE * 9032964741841833277U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13002706161178447654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13929727277530310708U;
            aOrbiterI = RotL64((aOrbiterI * 7005639090871200285U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10949073760696935106U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15405923432006783533U;
            aOrbiterA = RotL64((aOrbiterA * 17989565878445202495U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 18096057968822208905U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3032155040484574973U;
            aOrbiterF = RotL64((aOrbiterF * 448597307502544605U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17462076466907467134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15471015427013701406U;
            aOrbiterJ = RotL64((aOrbiterJ * 6113474000571976139U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3549031751266594344U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14243218483842508113U;
            aOrbiterB = RotL64((aOrbiterB * 9041601306479302047U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5803147589312920032U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5549470512227427855U;
            aOrbiterK = RotL64((aOrbiterK * 12592362489263862879U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10076661824293832189U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3196799148974716550U;
            aOrbiterC = RotL64((aOrbiterC * 8183276968961467775U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 23U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterE, 58U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE + ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 5U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + (((RotL64(aScatter, 4U) + RotL64(aOrbiterK, 18U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7624U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 8046U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6294U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 7528U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererG + RotL64(aScatter, 29U)) + 6069475454765660321U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererD + RotL64(aCross, 37U)) + 11483704742497268068U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 57U)) + 11055697447388986418U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 5U)) + 10897095046039997004U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 39U)) + 4731637118230457840U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 13855839187084986751U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 51U)) + 5328208115460188239U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 12479538544291412985U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 18U)) + 10740165998792608231U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6492798157284955373U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13056825957483891921U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 14882112110627751751U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2068184064919194657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5656302738780746294U;
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11193756120230763294U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17306750816837208999U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12952818800389361804U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15380412293642628312U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2914662289178925547U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7706090204767242996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17819762117328075515U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4836701121865783029U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 754936290510338717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15510875946573720154U;
            aOrbiterG = RotL64((aOrbiterG * 2994718968852184303U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9245381722813944586U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2629847912019726214U;
            aOrbiterI = RotL64((aOrbiterI * 6718795794951106961U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3909987749797113773U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9277056074757335265U;
            aOrbiterH = RotL64((aOrbiterH * 11580847505996697115U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterG, 52U)) + aOrbiterH) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 24U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13127U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 14639U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11828U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11551U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 3U)) + 14624277139785904404U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 6966977309498165611U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 57U)) + 205536824352530761U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 18U)) + RotL64(aCarry, 41U)) + 16629575265808255692U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 596881340147972746U) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 11944412799107412650U;
            aOrbiterH = (aWandererC + RotL64(aCross, 51U)) + 4615021315668210206U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + 8497630055977606216U) + aNonceWordH;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 12U)) + 11131601107309336885U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5935883479805510099U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15629346719765798174U;
            aOrbiterF = RotL64((aOrbiterF * 8535523790685945275U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5279128339113651273U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16778365912440331821U;
            aOrbiterD = RotL64((aOrbiterD * 705421028266789241U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 16003052937645491524U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6723226158737614764U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 16690657664909260573U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9785784358981219543U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10055457337292292710U;
            aOrbiterE = RotL64((aOrbiterE * 17919129940751761111U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11779163108592974175U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 1177999477942202687U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13475069421684114643U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9190694445141492214U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15605342360346353457U;
            aOrbiterK = RotL64((aOrbiterK * 14547769706392595647U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14877565450677523492U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1074095623308025684U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7884068939436891093U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12803174154216941583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8813356463693637033U;
            aOrbiterI = RotL64((aOrbiterI * 4898237214617563167U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6063909634038581414U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15112191502834052566U;
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 36U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 23U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 58U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19691U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20571U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21352U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((aIndex + 20656U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 26U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 11210042748013785976U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 12U)) + RotL64(aCarry, 13U)) + 4584747303233477454U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 23U)) + 8878765929792969517U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 57U)) + 2172232330280041122U) + aNonceWordG;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 8378937026022264016U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 43U)) + 8683007464695824208U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 39U)) + 9564352997357118134U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 19U)) + 11713878436769887528U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 30U)) + 8052917623074021077U) + aNonceWordK;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7720597162792145185U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2602847785328475621U;
            aOrbiterD = RotL64((aOrbiterD * 14065077077207224525U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17813669222300509724U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8724263063156573013U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3632927017737834359U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6882429835961613492U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13213313479525717359U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2411431247725974895U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2401526093648669573U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3616448566579979749U;
            aOrbiterF = RotL64((aOrbiterF * 13323155103752121393U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18268262471839710401U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5116424918948694752U;
            aOrbiterG = RotL64((aOrbiterG * 7641143782996332069U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11405305689555640431U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12427591396711015574U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8112834135715541223U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16960781161508084626U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12382604781005282628U;
            aOrbiterH = RotL64((aOrbiterH * 17196168631120103115U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10054839091354729292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4167641616532985407U;
            aOrbiterC = RotL64((aOrbiterC * 919291747187787625U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14383737233143309039U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16258779988369405932U;
            aOrbiterB = RotL64((aOrbiterB * 8348773195366160215U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterF, 48U)) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 18U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24130U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23775U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25263U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26975U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 56U)) + 15188686795415908074U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aWandererD + RotL64(aIngress, 51U)) + 17310049041983079779U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 43U)) + 8246925977992441471U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 8644260919918112781U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 18U)) + RotL64(aCarry, 43U)) + 13401663736874819483U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 7940358935238314973U) + aNonceWordO;
            aOrbiterH = (aWandererH + RotL64(aCross, 35U)) + 13278990328548007839U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 11346868298353840706U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 47U)) + 2374077904806833579U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6978903378645019166U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11951633297870965212U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12778236598654492185U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17398460995357409673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1215437945597836770U;
            aOrbiterA = RotL64((aOrbiterA * 9322970054123481621U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1878751468043972239U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5343002808239712390U;
            aOrbiterF = RotL64((aOrbiterF * 11878640995447558811U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 9884918450053276861U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 15894599082080422550U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8359936745539546131U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13917339232771145459U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18101134009493720683U;
            aOrbiterK = RotL64((aOrbiterK * 15835859435306756387U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3830086372356903769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15894394599564584010U;
            aOrbiterI = RotL64((aOrbiterI * 9513921913446609263U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5127590955274245812U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9410946933309720054U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14507476989423060561U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15544384157294987085U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 998801294460434123U;
            aOrbiterE = RotL64((aOrbiterE * 5946968142746472745U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16442095194965452163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14294936349037516932U;
            aOrbiterC = RotL64((aOrbiterC * 14655345374740882581U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 24U));
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterE, 20U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31670U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31474U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29209U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 28758U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 21U) + RotL64(aPrevious, 34U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 11U)) + 7722279280863371124U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 11584220561732385598U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 53U)) + 7834679350105534657U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 35U)) + 11347994382444180879U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + 9449903188047063431U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + 6516243976652795170U) + aNonceWordA;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 57U)) + 8420815253991184777U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 9081386852515170937U) + aNonceWordO;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 46U)) + 14375955191735286867U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 880757589768436072U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3349856625725164229U;
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7826309957607577207U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8057435761214313635U;
            aOrbiterH = RotL64((aOrbiterH * 4718430712767038607U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9565237500443303103U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15893066735310588501U;
            aOrbiterB = RotL64((aOrbiterB * 8457633439171452397U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3276844534476430842U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6828644383891274120U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 979580351653410157U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2815676923011504251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5030251870850928417U;
            aOrbiterE = RotL64((aOrbiterE * 7075653570570819253U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13464083008377887034U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8994560761846897590U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 9892839554658865143U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8398813387154468736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8136429428340910892U;
            aOrbiterF = RotL64((aOrbiterF * 3348811490733577295U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 418587250696862341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4111667833838312094U;
            aOrbiterG = RotL64((aOrbiterG * 860949442143849147U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6075478294190926371U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2208124955874142264U;
            aOrbiterA = RotL64((aOrbiterA * 15741988616251072075U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterA, 38U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 43U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Rugby_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDA80327D5D7B2AB5ULL + 0xBE129FEB54DB4CA8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCC4A69D4289DB57DULL + 0xC46D9E8B858ED3FCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x897D59C510C51D2DULL + 0x9AA77D3E45BFF1E9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x80FB5F6A32C57E21ULL + 0xEE7935F3023DC095ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA8C138528EC45577ULL + 0xC95106D7091349D3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCFA6D19AB6CBBEC5ULL + 0x8C46ADFCABC1634EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDCFE300361E678CDULL + 0xC0DB5F5542083CAEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC8107AAEC5092477ULL + 0xCE5E081AA225E264ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x81EFDC5ADC218F97ULL + 0xAF241F6A40FFB167ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8649849A78D1AE91ULL + 0x854AF09E8CA38BAAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBFD5EB6EDDF60F8BULL + 0xA819DD525FF77F53ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE0698017742C790BULL + 0xFD41932AFFE47A6EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA3B84FBE57245EE9ULL + 0xFCCC00D87B7C295AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA858A51D3713879FULL + 0xD6CAA194ED0602B6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE1B6324DE10B261DULL + 0xDB473F0542BE6A5EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8006A00BCBD137F9ULL + 0xD7B7170A05CE7DE4ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5309U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5104U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3802U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 1444U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 18U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 5088525177670191619U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 9966456257813932112U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 7707646574027146307U) + aNonceWordC;
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + 75480203757681173U) + aPhaseAOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 384659134071835163U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 53U)) + 3158769775373307778U) + aPhaseAOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 46U)) + 17360830943513941272U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5317278822721604586U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1371427105215954781U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10956603063464438611U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3162710551223553423U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5332921933853550756U;
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10572462410297815854U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10234389605554817892U;
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13421365517991380605U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10186643614984034083U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 8554471709467808453U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4742438973260817120U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 6081590345899008846U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 7069396301823124931U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15360092808493795340U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12186413069553132646U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3815981440611914267U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 16756221656224451552U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12232880965861373143U;
            aOrbiterF = RotL64((aOrbiterF * 14196910735715726471U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aNonceWordF) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10413U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8437U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8210U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 6866U)) & W_KEY1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 4179952823252098240U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 28U)) + RotL64(aCarry, 29U)) + 3745613452332101749U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 2955689793395307176U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 5639060180251322019U) + aNonceWordI;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 41U)) + 7901969163853586463U) + aNonceWordE;
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + 2242166787816318119U) + aPhaseAOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + 5239936443960750064U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13939136954732185558U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17058884136712717463U;
            aOrbiterE = RotL64((aOrbiterE * 7222348891215482977U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 18148618660054585941U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7022023484530327814U;
            aOrbiterF = RotL64((aOrbiterF * 650100011311048589U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7722084537340095637U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11764151879690934182U;
            aOrbiterC = RotL64((aOrbiterC * 12264384877711365655U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16412785901758144708U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9666718667728274824U;
            aOrbiterG = RotL64((aOrbiterG * 10865799822751771795U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4307127540152109364U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2457646804702647606U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 6340030928007058595U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3179394870088602208U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 504977947273774249U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16190282058883481551U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16182729401018310837U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7110817020445860609U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 13371352088428584087U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 54U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 10U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 19U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15065U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 14378U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15893U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 16340U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 26U)) + (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 13880995121909552664U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 14534942818069300546U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 17745973100886007133U) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 19U)) + 2249805580771946872U) + aPhaseAOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 58U)) + 4460116116396439410U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 3378683994078106878U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 5U)) + 3992996501048809123U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12057768808864451929U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4115362079047921130U;
            aOrbiterC = RotL64((aOrbiterC * 12263015903331031345U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15297384955502206698U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17623548383481905636U;
            aOrbiterJ = RotL64((aOrbiterJ * 7487278217901483685U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3559213898000162417U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12311605719074507335U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 14807313864347885885U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11222085523291581822U;
            aOrbiterD = RotL64((aOrbiterD * 12580941911587215653U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 916681229436292462U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2441350114032314686U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 7336079498999018067U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7361470539894653271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12153585147213579808U;
            aOrbiterA = RotL64((aOrbiterA * 3040327545467672961U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13566300726101613579U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14875254144748509128U;
            aOrbiterH = RotL64((aOrbiterH * 13699179902908972403U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterK) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18631U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 17440U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19367U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17926U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 40U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 9133751643283278896U) + aPhaseAOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 8971581804375380408U) + aNonceWordC;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 13U)) + 12559650383714566592U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 57U)) + 15753206088872859163U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 46U)) + 7640756270450762350U;
            aOrbiterF = ((((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 7340073357551376125U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererA + RotL64(aScatter, 21U)) + 5270256573644196046U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3567367996479995928U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11939634537492733738U;
            aOrbiterI = RotL64((aOrbiterI * 5640541900117183639U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7051817732424527120U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1730487669951837941U;
            aOrbiterF = RotL64((aOrbiterF * 15191634337956285841U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18009252467909454817U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2361024272031696442U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15215151562500226027U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15902755877642960397U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12243517544704116184U;
            aOrbiterD = RotL64((aOrbiterD * 2576071074148141447U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 16846181962302186187U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 636121425116506681U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6887385655828217318U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3705834550934775862U;
            aOrbiterE = RotL64((aOrbiterE * 11275428284929594435U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11165142437077969438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6426659930331618269U;
            aOrbiterK = RotL64((aOrbiterK * 17170640810530893705U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22745U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 26575U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26512U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27076U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 12380376990224645149U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 20U)) + 18296928500297384014U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3550626816361145100U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 2667792936946706027U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 11U)) + 12020969779370926953U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 29U)) + 737340727886903447U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 41U)) + 1681797651799760502U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2956186342689489064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1876852870402977177U;
            aOrbiterG = RotL64((aOrbiterG * 8875540081346621757U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6433205819353555071U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9065076854974222998U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5459675878087242021U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3254410578766789992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2005081975473815576U;
            aOrbiterJ = RotL64((aOrbiterJ * 9947701153722014085U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15992999234834560419U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3458344156815120948U;
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17069783053664877727U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1260234710193913099U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 4561226779897414381U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3825186451876061335U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2905344294992827535U;
            aOrbiterI = RotL64((aOrbiterI * 2469896090698580795U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 18141402347899180617U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8760129857609925066U;
            aOrbiterB = RotL64((aOrbiterB * 2507999156108123047U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 44U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterD, 37U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31308U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 30593U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27724U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31148U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 479672811032092393U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 60U)) + 18061121631394564425U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 14237400452740566065U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 6723123812257706134U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 19U)) + 4247997188026499248U;
            aOrbiterC = (aWandererE + RotL64(aCross, 41U)) + 1939107415066134869U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 53U)) + 3912640123546395979U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8295478436553964298U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3218960600711526885U;
            aOrbiterG = RotL64((aOrbiterG * 15443507655470278069U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5874096203353388890U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10294536533673023358U;
            aOrbiterF = RotL64((aOrbiterF * 15561710414949058923U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11268561953904130747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16693201256788898423U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16291987237693567209U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7550969634681894654U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9501647424602245869U;
            aOrbiterD = RotL64((aOrbiterD * 11265865222096866605U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 8881869255994319423U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16770136406906800016U;
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16185384746435761363U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13841034186650721627U;
            aOrbiterK = RotL64((aOrbiterK * 12000155593277035447U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15229062695864608309U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3576122704615303733U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2433987493885779279U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseAWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 6U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Rugby_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB310CFA3C955A2BFULL + 0xB6303FF8ADB3D921ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC102F91BD725CD2FULL + 0xAB87B83AE0813016ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8D7B349B435A016BULL + 0xFAF801D7112C6AFCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDC9BA67137C123A7ULL + 0xFB149E5083BB217AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9137365023C8C021ULL + 0x8DA8484295B8F4CAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xDB864E77428F21C1ULL + 0xA1F86FFAFE282784ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB74069A53AF53D97ULL + 0xFDFEB075DAC313E0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x80E8DA26DF6EA2E1ULL + 0xFBA970C8D9DEF811ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCB34DFD4D41C1D83ULL + 0xCF57DB773EF5F4D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD543605DCC99C623ULL + 0xA83571661E654B4BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE51358863A44FA1BULL + 0xF0EC6361671411A3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCB39A9B326E3E671ULL + 0xD39865E3D4E288BCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC0DB75CDD5FD0CE5ULL + 0xCEBB743E7108B144ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE1D97F608CBEE2C5ULL + 0x8733E40CFAAB3639ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDD4370EB40E80477ULL + 0xF96AF5BB79385F11ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDFE83DCE728F0AABULL + 0xFF4CDD31B164A2C1ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2755U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 809U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5193U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 1139U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 13960289014350612206U) + aPhaseBOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 3483331015269589730U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 13U)) + 6873299241002444518U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 48U)) + 3562094007125534229U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 11422367439932782705U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 532453428514259816U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 17810941465810193088U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2830829128884590275U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11869759058631106331U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8837581071876177566U;
            aOrbiterJ = RotL64((aOrbiterJ * 15329827515970522213U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17185378327053837778U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7578253375676981500U;
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17112646434432814442U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14949096407295697881U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4259590620758467836U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6534899413644542303U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 28U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 40U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8653U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8358U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7188U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10495U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 44U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 35U)) + 11177787645248006236U) + aNonceWordB;
            aOrbiterC = ((((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 35U)) + 3808340254579817169U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 3U)) + 828030667598518279U;
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 16177835921238398371U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 5518747735458708741U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17346319082399995165U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6397156921893030937U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 11203064569634132929U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 15559381654710713582U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 940404446491415088U;
            aOrbiterJ = RotL64((aOrbiterJ * 16401260971303026881U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8047166032048732645U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4688468645859470491U;
            aOrbiterD = RotL64((aOrbiterD * 14383536431614496369U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3710878044770337260U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 116343189456629220U;
            aOrbiterC = RotL64((aOrbiterC * 5637725064169289339U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 883908030159391659U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18058691521694880482U;
            aOrbiterG = RotL64((aOrbiterG * 3132200449123497619U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD);
            aWandererH = aWandererH + (((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 37U)) + aNonceWordE) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aNonceWordO) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16016U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 16021U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12519U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13203U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 7896237440058555694U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 11870529476037558635U) + aNonceWordG;
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 9158983227801569448U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 4710172270996950329U) + aPhaseBOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 58U)) + 14634482800356647630U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8822207952170610891U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13755891414028982553U;
            aOrbiterA = RotL64((aOrbiterA * 5173750624716006485U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4555293067488040719U) + aNonceWordK;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 2816805148093762081U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 16838149138341713943U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2122631477965135190U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4592922416380416071U;
            aOrbiterC = RotL64((aOrbiterC * 11644507904538573165U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7102471666524164715U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17274623547879474204U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5443572270546181789U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 938587316977094680U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18258015823797023523U;
            aOrbiterG = RotL64((aOrbiterG * 6068819567674605919U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 46U) + aOrbiterK) + RotL64(aOrbiterA, 56U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + aNonceWordE) + aPhaseBWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18204U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 17398U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19225U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19937U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 19U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 15652862298542575895U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 41U)) + 16925323928418184554U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 4413861484961668394U) + aNonceWordN;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 21U)) + 2215946422098155969U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aCross, 11U)) + 14975185533513111110U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9711613814905834552U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13154957291850149471U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17049677190793844477U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5058313016418534840U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 15011423472941211620U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 6125316151731105673U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2030053257469580168U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 150530795186791193U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 11106050063717096073U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10878237472104183427U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11724672539469573109U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 16158741837357985395U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9589700906445846956U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 1367381624958248949U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8459515089081211977U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 39U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 53U)) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 40U)) + aOrbiterD) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22521U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25388U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23197U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22505U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 40U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 4068921616130916949U) + aPhaseBOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 60U)) + 12077715273915151726U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 16047546802670596833U) + aNonceWordI;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 39U)) + 9690277462716999763U) + aPhaseBOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 14484814700447992628U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17089267243053958210U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9138746214446211147U;
            aOrbiterA = RotL64((aOrbiterA * 8244950097712975043U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10181001536979097045U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6657458969093373191U;
            aOrbiterB = RotL64((aOrbiterB * 4311019792293202747U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7515983477876590988U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3039935555863947600U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12511160550780270119U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16209389224740851136U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 725253312098083182U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17535989492095522597U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13307041115748941383U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7159572004825238263U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterA, 4U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aNonceWordA) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27490U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 29399U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31583U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28292U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 12029393034357490020U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 47U)) + 4526754731580694987U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 20U)) + RotL64(aCarry, 39U)) + 17060419646421271853U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 11U)) + 4128488893837059683U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 12706894827547160110U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12506324593645825056U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12581344490649250025U;
            aOrbiterK = RotL64((aOrbiterK * 16311882267466003291U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14357032418199130132U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15341977701796331249U;
            aOrbiterF = RotL64((aOrbiterF * 6332369248718076031U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7086602307544733241U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12398300065276832486U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 18157408831225635333U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 2499745046076601988U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7249361592814001829U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 14597139848072319685U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3254456186337366437U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3472973415969046680U;
            aOrbiterE = RotL64((aOrbiterE * 14583566953969168353U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordM);
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

void TwistExpander_Rugby_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x91C9C6A09511F673ULL + 0xAD42EFE3C0B77077ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA67ACC7832EAD45BULL + 0xDD66555B0D94C334ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x98A5C761098BD2C3ULL + 0x917865C490373CC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFAF45D42BD25B631ULL + 0xB4B8D9341CFD8DEDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD9E8A32A64FC0DADULL + 0xB081CB6785358B1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFE97E9828FC2EBABULL + 0x9B71667A18964C77ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF32FFAE52287F881ULL + 0xFEC861D967992147ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB896A071E331E297ULL + 0xCEBE88CD0A390144ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF40B87BD8F4BA97FULL + 0xE48828396F70BCF7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE2F51D41FAC924BDULL + 0xCB8AE692CD0EB912ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC5F41206E61A4DDDULL + 0xB3E1E0339711838CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA6EAC042E8B32925ULL + 0xB84A2C287069CFBBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFFFC25D3138D17D9ULL + 0xDE5B0685B417DFBBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA2CDA53084B54E9BULL + 0xD472ACDE83CB5D38ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBE7545C9B0A4AD61ULL + 0x8D4E582C2D75EB6FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFE37918AEA44035FULL + 0x9CF041B6CA65DBE7ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7798U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 1106U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3486U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 56U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 48U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 30U)) + 15920462086654025436U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 43U)) + 487844076858004017U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 14502883786442630566U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 21U)) + 3787107318658233674U) + aNonceWordI;
            aOrbiterC = (aWandererB + RotL64(aCross, 35U)) + 12548777544693755491U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 47U)) + 4907309444075181683U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 18342396700266492072U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 13U)) + 13503051997624242670U) + aPhaseCOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 17845742460521374571U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8640887211877858169U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5273913123709097537U;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17756844173695563883U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6713055830729302951U;
            aOrbiterH = RotL64((aOrbiterH * 2832836748513174311U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5106468334224035972U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10228769728713526172U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9760310686414358435U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7687649520668883142U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7757480627354711605U;
            aOrbiterB = RotL64((aOrbiterB * 7222553727737349209U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10876291698508634557U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterE = RotL64((aOrbiterE * 8577133863470695381U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15592893988925610485U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8639028256640537165U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 1880655276432963955U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 475660347892196219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1903736092401853832U;
            aOrbiterD = RotL64((aOrbiterD * 8486318978769094799U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12463250192809450953U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7253918448601703982U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3821034106528009129U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5171661020093804486U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11627344933828324146U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 5388047063152043277U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterK, 38U));
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 52U) + RotL64(aOrbiterK, 11U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordB) + aPhaseCWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterB, 58U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15191U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 15173U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12894U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14431U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aIngress, 35U)) + 17264605017518259932U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 15209184354580778643U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 3299527965014731384U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 24U)) + RotL64(aCarry, 5U)) + 16293096431816127821U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 41U)) + 11031983436878828337U) + aPhaseCOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 13U)) + 9188018632448236358U;
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 13420816400363406556U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 46U)) + 2485063384097917101U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 3089135816938128264U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10730544971770435788U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10431767565618874806U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4723078464590561545U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14883796491656899074U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterK = RotL64((aOrbiterK * 14311686051108108503U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13322163435314643713U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterC = RotL64((aOrbiterC * 12337846092069506365U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4950101626975919939U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2596253994220103666U;
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17961706029559914243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18146616411403012772U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterF = RotL64((aOrbiterF * 14879448948196182863U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11739172334166341121U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7936637782633487291U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 14940929920543800413U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3160044627483874242U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16816384076887379704U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5052772186568301951U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8101560104988710226U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8851416379738817624U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16767420038937389027U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 14U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 24U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterA, 39U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 34U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aNonceWordE) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 56U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16965U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 23498U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21708U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17471U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 15383045568644941552U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 10U)) + 17452811657750910067U) + aNonceWordB;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 29U)) + 15660117718455155603U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 10396441207743665753U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 51U)) + 3708971058200841442U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 35U)) + 7000673057768598750U) + aNonceWordM;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 9886354469011131596U;
            aOrbiterH = (aWandererD + RotL64(aCross, 4U)) + 16018065329058043467U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 19U)) + 5024756166109352320U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6587818720728886652U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3652672354944162319U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 10807121230791716109U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6307315649915348048U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16405347331742979258U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 7183142442906743699U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5427299664054601957U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4983381733483185898U;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10182995521328377487U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8694282877540593550U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14614602561910403893U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6966742100601433005U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9920952446921247521U;
            aOrbiterI = RotL64((aOrbiterI * 1879821050131820933U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11958734477518336014U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2058335903640404380U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6986170159285417789U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 77366119537297816U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12072894199692855000U;
            aOrbiterH = RotL64((aOrbiterH * 9083781120514635987U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11874297832446385377U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13715562531763053196U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12822488258322963187U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterD, 39U)) + aNonceWordI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 42U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 48U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28553U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27415U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30592U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26980U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 53U)) + 15549114274303128055U;
            aOrbiterK = (aWandererD + RotL64(aCross, 5U)) + 16466750056388063241U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 23U)) + 12209449840836787142U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 10U)) + 14551496099734294336U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 6266576428679808622U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 16892841575635668152U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 35U)) + 7375966221423362125U) + aNonceWordF;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 30U)) + RotL64(aCarry, 41U)) + 11926105302821753530U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 57U)) + 16219253791550461124U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7299056065319248160U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15234001484933728439U;
            aOrbiterB = RotL64((aOrbiterB * 8182244796017018911U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6615802589932632120U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5481176858895819247U;
            aOrbiterA = RotL64((aOrbiterA * 3604590158551984877U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17220507586542139380U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14137921473739415340U;
            aOrbiterC = RotL64((aOrbiterC * 10634645686035907603U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16981960446540932787U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10897565927079518588U;
            aOrbiterH = RotL64((aOrbiterH * 418843936329303571U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2746889569299593263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4894117146736361379U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 2656750612042673191U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18294823016957137777U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 86828501068883383U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6322053762209547826U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6754524552483363820U;
            aOrbiterF = RotL64((aOrbiterF * 1746163087826694641U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7306452650619361017U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12717201204443785828U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6121251603905574991U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10422327053543898585U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 14786413282036348183U;
            aOrbiterK = RotL64((aOrbiterK * 8713024293107068275U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 60U)) + aPhaseCWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordM) + aPhaseCWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterE, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordJ);
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

void TwistExpander_Rugby_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCEB609C9BEC3F651ULL + 0xC3E5FACEF43BA58FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDA0F07E603D14791ULL + 0xACB2CE88817F62BAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x868D848A02C2DC95ULL + 0xDDA9CBA10B4303D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEF3C96A9E5DE159DULL + 0xC31AEE6CABCBB453ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCE2B91915F4E1ABBULL + 0xE54D12C601863141ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC89ABC8C6079B4ABULL + 0xBA60ED4DBB78942BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB09AFC0DF4FEB4BDULL + 0xF12530DD35C9D6B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x991024759D5FD3FFULL + 0x89D2E546C098C0E4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8EC7ED6CA35ACCE3ULL + 0x8A75DB7E4AB6D45CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB5992E5DDB9F779DULL + 0xB4AB6ED76456E28CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEEAE16C6C7DDC591ULL + 0xDAE015863291E3DFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC84E33D9C3167BA3ULL + 0xE4CFCC93D3F14152ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x89A8F4BF992DD101ULL + 0x9F39437E19533439ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8560DBDAB158144DULL + 0xA5CA33C38839FCFBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8241A2CD84ED8CEFULL + 0xEBEF0FF9B51F481EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8FB725A705B54CCBULL + 0xEE059F52481EFD1CULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 507U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 4464U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2820U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1914U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 27U)) + 1210605127156905516U) + aNonceWordM;
            aOrbiterD = (aWandererF + RotL64(aCross, 41U)) + 11964595428173569519U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 39U)) + 16277319029916258482U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 12369497463101824572U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 53U)) + 6201248574067068202U) + aPhaseDOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 51U)) + 1727477025667206661U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 35U)) + 1404510627789806851U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 6948213591282018925U;
            aOrbiterC = (aWandererH + RotL64(aCross, 29U)) + 6688865181284421478U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 3351130769402360855U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 12681032488906270823U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3591412591193726763U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16153817571210878589U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4165137036092246349U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3808228354421006630U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1427373776207504205U;
            aOrbiterF = RotL64((aOrbiterF * 4534374093769595531U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1831554180932501132U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1114853085120949215U;
            aOrbiterK = RotL64((aOrbiterK * 4264176108298812905U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2080935638828366835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16104777999646489828U;
            aOrbiterA = RotL64((aOrbiterA * 15205199362011777473U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9782806013673440791U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3721620299829386454U;
            aOrbiterE = RotL64((aOrbiterE * 6286765834910272409U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4013706412064296527U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5751022780695158579U;
            aOrbiterC = RotL64((aOrbiterC * 13766736471646116397U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17684546333240329338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1106947111128020920U;
            aOrbiterB = RotL64((aOrbiterB * 3158839453318658951U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11564229705849500598U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1585817314460274286U;
            aOrbiterD = RotL64((aOrbiterD * 12687162159791577431U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13549147977354138518U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5148731385622182707U;
            aOrbiterJ = RotL64((aOrbiterJ * 11016443961557395981U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17048442399822433365U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13772472534194030098U;
            aOrbiterI = RotL64((aOrbiterI * 13155895389652826889U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9982971300679888388U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1210605127156905516U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9183351854400012949U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 58U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 41U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 44U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10150U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 10098U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8014U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10432U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 29U)) + 5697928251815176134U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 11U)) + 337587740689259575U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 47U)) + 4927686903263973950U) + aNonceWordN;
            aOrbiterB = (aWandererH + RotL64(aScatter, 21U)) + 3742409032569801033U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 52U)) + RotL64(aCarry, 5U)) + 1608092659172197650U;
            aOrbiterK = ((((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 15848744267145717509U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 15300174177963339253U) + aNonceWordJ;
            aOrbiterE = (aWandererJ + RotL64(aCross, 23U)) + 14162868453323648628U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 34U)) + 12020167069983729869U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 3U)) + 16259538291658723956U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 19U)) + 8516686212464112245U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3722184575520553132U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15265344442454471986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3050323350098829515U;
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1093356813820599238U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15167726103772238440U;
            aOrbiterI = RotL64((aOrbiterI * 5719466863561311069U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15170797965325981472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14710892030473425181U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 397194787697553904U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1273724124862533034U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13018397560392545616U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9638716186445643730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7255587739807843785U;
            aOrbiterB = RotL64((aOrbiterB * 6055682981584011189U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9272350563697399628U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1040729335295009339U;
            aOrbiterK = RotL64((aOrbiterK * 17825687660830291443U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12128124729613601747U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2285238815562202219U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15398840993074390573U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6339113298619163493U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5911895708485037040U;
            aOrbiterJ = RotL64((aOrbiterJ * 3271006139923200439U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7601399508218901328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5697928251815176134U;
            aOrbiterF = RotL64((aOrbiterF * 8184257916861355735U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 36U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 34U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 42U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterK, 39U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterA, 50U)) + aNonceWordF) + aPhaseDWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererF, 48U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13683U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 13945U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14577U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12218U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 26U)) ^ (RotL64(aCross, 13U) + RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 35U)) + 17470880031634374199U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 757565846006937746U) + aNonceWordH;
            aOrbiterK = (aWandererD + RotL64(aScatter, 43U)) + 9419282475801345674U;
            aOrbiterD = (aWandererF + RotL64(aCross, 29U)) + 2014248014107898196U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 27U)) + 15113928519446490441U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 10U)) + 7346126964886259935U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererB + RotL64(aCross, 57U)) + 5594123113093162359U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 47U)) + 5659237263369402005U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 21U)) + 11565709683423969703U) + aNonceWordF;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 50U)) + RotL64(aCarry, 27U)) + 16782863743534856287U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 37U)) + 13499100900072115907U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11414447651044205242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7545993795121430538U;
            aOrbiterK = RotL64((aOrbiterK * 10758488381206257261U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11778229237616454988U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2544793391976514665U;
            aOrbiterE = RotL64((aOrbiterE * 4021060413798523299U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9972156716619459164U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17651030383827445664U;
            aOrbiterJ = RotL64((aOrbiterJ * 6742914240706775487U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17439147296849134543U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10021926927948343656U;
            aOrbiterC = RotL64((aOrbiterC * 18139540407315440909U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9309867875882669289U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14951424455944346337U;
            aOrbiterI = RotL64((aOrbiterI * 10569523948169951309U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2166343974068770659U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11386993629011562026U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3091639433512536097U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5747849744680120960U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4019290369160113026U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 5567515306039646735U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3820540009554769592U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8210747198363020939U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 16215133106542452509U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3006494852696036003U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2736305345451919450U;
            aOrbiterA = RotL64((aOrbiterA * 11993452696344358247U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6148431711118275178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6986633012691940738U;
            aOrbiterH = RotL64((aOrbiterH * 15672039482523804893U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7837859154831245165U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17470880031634374199U;
            aOrbiterB = RotL64((aOrbiterB * 2153299273348512243U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 6U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterH, 26U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 21U)) + aOrbiterB) + aNonceWordP);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterG, 14U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21620U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18820U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19162U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18223U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 9914837590440975587U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 27U)) + 6706125076401958051U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + 16570817772679258409U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 44U)) + 6843705658115186948U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 11U)) + 16099930446791572351U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 29U)) + 5420550009556030459U;
            aOrbiterE = (aWandererC + RotL64(aCross, 51U)) + 5729549069420177477U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 35U)) + 15590601126188675834U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 13044027390998620029U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 23U)) + 11068338135659636772U) + aNonceWordN;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 6584988841809544332U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8516813219883915404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10647314042912492785U;
            aOrbiterF = RotL64((aOrbiterF * 15559481057047148785U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3883760518944464145U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13861805129175491145U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12019138626550801486U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 13030350224959652248U;
            aOrbiterE = RotL64((aOrbiterE * 11724200983306280107U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 2643807255422544248U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4127143302485631794U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 5441038881111578487U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6343143902997169834U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10404783711336491985U;
            aOrbiterJ = RotL64((aOrbiterJ * 6235474458879439079U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7406959231434835393U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6684368109277850196U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 8760360417572331159U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4835889355927954728U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7917682889852676712U;
            aOrbiterC = RotL64((aOrbiterC * 9045350756570117327U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10268055422944417055U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5563744562922937643U;
            aOrbiterD = RotL64((aOrbiterD * 12442484191329795173U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17244672945880141679U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9914837590440975587U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12269340309792850489U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 12U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24375U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25564U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26326U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25667U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 51U)) + 15188686795415908074U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 26U)) + 17310049041983079779U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 8246925977992441471U) + aNonceWordM;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 41U)) + 8644260919918112781U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 39U)) + 13401663736874819483U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 7940358935238314973U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 23U)) + 13278990328548007839U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 11346868298353840706U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 19U)) + 2374077904806833579U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 60U)) + 6978903378645019166U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 57U)) + 11951633297870965212U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17398460995357409673U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1215437945597836770U;
            aOrbiterH = RotL64((aOrbiterH * 9322970054123481621U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1878751468043972239U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5343002808239712390U;
            aOrbiterA = RotL64((aOrbiterA * 11878640995447558811U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9884918450053276861U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15894599082080422550U;
            aOrbiterI = RotL64((aOrbiterI * 8359936745539546131U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13917339232771145459U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18101134009493720683U;
            aOrbiterE = RotL64((aOrbiterE * 15835859435306756387U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3830086372356903769U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15894394599564584010U;
            aOrbiterB = RotL64((aOrbiterB * 9513921913446609263U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5127590955274245812U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9410946933309720054U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 14507476989423060561U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15544384157294987085U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 998801294460434123U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 5946968142746472745U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16442095194965452163U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14294936349037516932U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 14655345374740882581U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16680659892463349201U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10921918150041635666U;
            aOrbiterD = RotL64((aOrbiterD * 2908474941036821745U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15350264522133299871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16413848767507968239U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10226942289998651355U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11963105565077056299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15188686795415908074U;
            aOrbiterF = RotL64((aOrbiterF * 13002484121826831091U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 22U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + aNonceWordD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterA, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterD, 36U));
            aWandererA = aWandererA + (((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30400U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 31246U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32234U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31837U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 58U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 13U)) + 9654059367478508868U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 41U)) + 6473006635864677427U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 5U)) + 6944184481315853243U) + aNonceWordI;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 4061496421939102306U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 23U)) + 15791809275719085463U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 47U)) + 14050798802646323055U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 53U)) + 12072905924741758266U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 17639076509231343896U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 47U)) + 12195388285571234715U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 18U)) + 4325404419499496529U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + 5910567888204238382U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13092940059929942699U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13381962590820308761U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 6345904465930943295U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15622862439323440527U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 14027151901132249793U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4584410023907605157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15763755180625487157U;
            aOrbiterA = RotL64((aOrbiterA * 6755736130607297639U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17023059745666559199U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5298529579288492971U;
            aOrbiterK = RotL64((aOrbiterK * 2483562793328357721U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2870152867331654736U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12017191100173748848U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9958191466506480519U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15899529176182436062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16482713846343388735U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 719465695044265601U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12943393531812774449U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9881108254540483225U;
            aOrbiterE = RotL64((aOrbiterE * 8011108108007885059U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3532054586199716750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7142230313294797435U;
            aOrbiterH = RotL64((aOrbiterH * 14154176174768868421U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 733958394016131587U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2060800099014517137U;
            aOrbiterB = RotL64((aOrbiterB * 12988885554457108631U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2278498033811574812U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15342071118593803929U;
            aOrbiterF = RotL64((aOrbiterF * 7842196613533603835U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12987212219357101955U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9654059367478508868U;
            aOrbiterD = RotL64((aOrbiterD * 11796100167917742307U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 30U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterB, 39U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 26U) + aOrbiterJ) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterF, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterD, 34U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordI;
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

void TwistExpander_Rugby_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDBE7CF4F56394381ULL + 0xF59416A3C0C048BEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA3BFF152C301DB5FULL + 0xE79760858380F5EDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAA911614954CFEC7ULL + 0xBB0588134DB1AA48ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC947801559298865ULL + 0x8F0715D45BF6BA64ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x88F43F0D411F08F1ULL + 0x93E3D196DD422C7FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9CD8D4F8E8F2D201ULL + 0xF172B065EFFBF689ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA2B4CD556B5359E3ULL + 0x880168BBDF7515BCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF3D75258CD0D1467ULL + 0xAC22D1345B30B06EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFE6CA3D5821180C7ULL + 0x892A0B4078612B11ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC385908CF6FE94D9ULL + 0xABCBB8B56CB10E55ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF0C2AA57CDB09431ULL + 0xBB83BC42B94742DEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8582687DBF80395BULL + 0x895BC77783C62798ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFCAE63BA086B835BULL + 0x904422F00FABD100ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE6DA19BFD5420607ULL + 0x812B5AD5CE4B472CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9FC4784B946B494DULL + 0xFF54C48490FEE8B9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB03375D6E9044F61ULL + 0x8EE67146A7DE614AULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3177U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4271U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4997U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4368U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 29U)) + 15813325389431304548U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 40U)) + 2223874171125403602U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 5510483568496824130U) + aNonceWordL;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 57U)) + 15474152493495661876U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + 16846339705130829195U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 48U)) + 1289670576865739669U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 43U)) + 18017354919647006944U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 8539685539928984921U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 3333721400836704048U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 19U)) + 2261560416623815491U) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 5U)) + 4377786131746816567U) + aNonceWordF;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18047393176583722719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8184724021940434631U;
            aOrbiterJ = RotL64((aOrbiterJ * 9800116157750921119U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10469895939183324807U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14543391765109879223U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 4817987697437667225U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5757225781746158178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3539000495894022869U;
            aOrbiterC = RotL64((aOrbiterC * 1032298408884695925U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11288971092707065923U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2761384065186568294U;
            aOrbiterK = RotL64((aOrbiterK * 3323838837427471051U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7120580145300417101U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6977246291769372866U;
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17625434527765525937U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3299714663631376190U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 6532628892760776767U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10331889953489885250U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 8550932256881727932U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13085531621192583719U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11151195711186126257U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2552002192824926483U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9754056316698523849U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8038115194286715268U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16594489591573505305U;
            aOrbiterF = RotL64((aOrbiterF * 1241387574663818247U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13476964484361081681U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2136330439951908303U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12728359054660550527U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 231990686776499700U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15813325389431304548U;
            aOrbiterG = RotL64((aOrbiterG * 9155088985405261637U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 44U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterC, 47U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 21U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + RotL64(aOrbiterD, 57U)) + aOrbiterH) + aNonceWordA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterF, 54U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10823U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8595U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9371U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9593U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 12U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 54U)) + RotL64(aCarry, 43U)) + 13924571355038625040U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 3U)) + 16328300979357156658U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + 3947771961206012461U) + aNonceWordN;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 15428284250569311285U;
            aOrbiterB = (aWandererK + RotL64(aCross, 5U)) + 5777369485254032486U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 37U)) + 16813320300717644673U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 29U)) + 16689933050200758251U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 51U)) + 1856422419049390708U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 13U)) + 18214498743831925517U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 18278550878494094923U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 46U)) + 797712062039591797U) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15854849439012341347U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 996882939768167773U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 14936703950807908575U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3005829974130671692U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8793495343509953906U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 14065479348374612031U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7710453029930631112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9511995836117707047U;
            aOrbiterB = RotL64((aOrbiterB * 7250766204781428201U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 670902975693341744U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9045820304668279777U;
            aOrbiterK = RotL64((aOrbiterK * 18373074917532639027U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12417212387607119470U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12816983560669985622U;
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17245432086377688540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6806521945548502014U;
            aOrbiterE = RotL64((aOrbiterE * 11335859481858640857U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8947500746292365294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4468060468522895852U;
            aOrbiterG = RotL64((aOrbiterG * 7022481284816599797U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9892975931958803992U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3042599331526937836U;
            aOrbiterA = RotL64((aOrbiterA * 3308512896171443645U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12991568221485810891U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8551331172836260315U;
            aOrbiterF = RotL64((aOrbiterF * 4509997595920847057U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 183547209633334407U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17275712817092769452U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15677355290000929085U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12743863879392372723U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13924571355038625040U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11966689345179279407U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 24U) + aOrbiterB) + RotL64(aOrbiterG, 30U));
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterF) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 22U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 28U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aNonceWordP) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12781U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 15234U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13468U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14224U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 22U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + 3339283916456813609U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 60U)) + 11339086426180649584U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 16819191669329316585U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 8361916937762630725U) + aPhaseEOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 23U)) + 18031328374429899857U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 18261756894092897276U;
            aOrbiterB = (aWandererH + RotL64(aCross, 21U)) + 4250319792907645666U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 40U)) + 1492411503643460886U;
            aOrbiterH = (aWandererG + RotL64(aCross, 47U)) + 17369549067879344180U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 43U)) + 7301713524358676722U) + aNonceWordE;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 11U)) + 2985193736033012535U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14086975808140927408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10390516547834639800U;
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18205555540941493267U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16967799565443938873U;
            aOrbiterD = RotL64((aOrbiterD * 3009081009044782443U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9209505304067579944U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3522631966146762306U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8811497120829041188U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14707301680850257294U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11383709499376464085U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10080595991787801029U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6822892187784299166U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1981637172055758689U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16463077485583119324U;
            aOrbiterK = RotL64((aOrbiterK * 2876782050665869121U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8383837717361569465U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2788511294985017326U;
            aOrbiterA = RotL64((aOrbiterA * 2809163242875130677U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3529607472855930041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8850940802020173766U;
            aOrbiterI = RotL64((aOrbiterI * 7821450253655655943U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7469160295100147267U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16973986572163482061U;
            aOrbiterB = RotL64((aOrbiterB * 15660743778376905023U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12371372942863279718U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12098525148034303633U;
            aOrbiterH = RotL64((aOrbiterH * 11234127652230231751U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5138683482859889480U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3339283916456813609U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10975353228235695455U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 56U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterI, 54U)) + aNonceWordI) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21007U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 18552U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20260U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18956U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 38U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 785861751704720606U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 3U)) + 15968088718435606299U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 36U)) + RotL64(aCarry, 39U)) + 1393976526590347151U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 11U)) + 17240750947292745884U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 5U)) + 4921576136163183137U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 3334047873553153032U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 21U)) + 15086509978458408698U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 892391205397581998U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 43U)) + 2965686403183767521U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 46U)) + 14632215393655706170U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 13U)) + 15740589515342377322U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11131164813943086445U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6988080581278900960U;
            aOrbiterJ = RotL64((aOrbiterJ * 6412189142344044255U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16021254613117657178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6183615599897921154U;
            aOrbiterD = RotL64((aOrbiterD * 9976411093264211033U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12533992547026652747U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3104325358982904219U;
            aOrbiterA = RotL64((aOrbiterA * 14977348108778147265U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3878525937957474644U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2120435259884368445U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14928658302694194856U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9121310461310309348U;
            aOrbiterF = RotL64((aOrbiterF * 17304439784647477491U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3715693239100476493U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7336577492932262490U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11074754160002665253U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2312452827448455675U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4322756069651934618U;
            aOrbiterE = RotL64((aOrbiterE * 6908893297397073539U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4962079617577705818U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5072727464750706525U;
            aOrbiterB = RotL64((aOrbiterB * 4947670001221089155U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4553791875259778686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15823770920225774233U;
            aOrbiterK = RotL64((aOrbiterK * 409663191536830375U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9468608484284459072U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8658861660659699947U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 2933359123761406353U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14453429515273506170U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 785861751704720606U;
            aOrbiterG = RotL64((aOrbiterG * 3544627380583668815U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterI, 56U));
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterD, 37U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27000U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26465U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22956U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 22964U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 34U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 51U)) + 18144572925667544139U) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 5659758077574059728U) + aNonceWordI;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 36U)) + RotL64(aCarry, 47U)) + 6343330616999166392U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 29U)) + 17754639838410839447U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 19U)) + 9451843819849581729U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 21U)) + 7957854457197462212U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 1461994799722205010U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 26U)) + 18002214276252170177U;
            aOrbiterD = (aWandererG + RotL64(aCross, 39U)) + 14689869073147027164U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 3978104368003440293U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 3U)) + 8512135845221335386U) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1477533446382953439U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 2166717790929947990U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 6538884492418324461U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8082437060686606995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4363687722464700362U;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15782763348014924206U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8572509150015960728U;
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12248271773316742521U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9602078627638561949U;
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17244849374768558859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1030743048280579012U;
            aOrbiterK = RotL64((aOrbiterK * 10858949914285817051U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17722342363541914280U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15667504059789880034U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15872269872168533709U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12645332941998550794U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9938135244509986497U;
            aOrbiterE = RotL64((aOrbiterE * 16548185968987392957U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4024609904162105979U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6732064218696157303U;
            aOrbiterD = RotL64((aOrbiterD * 3815409766145891393U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14314117137220703583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15244765904057473814U;
            aOrbiterF = RotL64((aOrbiterF * 4034571710808047959U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17441241682018169245U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11958974379114644873U;
            aOrbiterI = RotL64((aOrbiterI * 11315689206845170303U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8310839846793796473U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 18144572925667544139U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11668203295511168011U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 37U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aNonceWordN) + aPhaseEWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 26U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28389U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 27648U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29043U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 29385U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 50U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 15045917390223766480U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 37U)) + 10763054007033668758U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 3U)) + 13190170142593666607U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 43U)) + 9657025731441167065U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 21U)) + 11433367178975954211U;
            aOrbiterC = (aWandererC + RotL64(aCross, 11U)) + 17904920143996810366U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + 3244383020512113283U) + aPhaseEOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 48U)) + 6538815775171139091U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 7195368312757976343U) + aNonceWordL;
            aOrbiterH = (aWandererA + RotL64(aScatter, 41U)) + 18134430713910279374U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 19U)) + 6571776588427107976U) + aNonceWordI;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11830778129647517758U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9793702760907767365U;
            aOrbiterG = RotL64((aOrbiterG * 4096246227968677179U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2287235876793192036U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8951959188326141794U;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7583061790273240157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3571364625022806085U;
            aOrbiterC = RotL64((aOrbiterC * 6238360922735480669U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13869345563551689212U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 277480328952975002U;
            aOrbiterJ = RotL64((aOrbiterJ * 1057564597096163085U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4983735092494677578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9490022869381030928U;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7928039573014765566U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6504190875809407084U;
            aOrbiterI = RotL64((aOrbiterI * 14648214826494826711U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2787985600176307413U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16308785053443116826U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17867565986311256691U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12788128335006767824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1187040019537798339U;
            aOrbiterA = RotL64((aOrbiterA * 10834905007658184183U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10771230162770496645U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6542421559654716320U;
            aOrbiterK = RotL64((aOrbiterK * 16829492790597069373U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 702458690970201679U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2806140783487813070U;
            aOrbiterE = RotL64((aOrbiterE * 7415398198842270381U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 950611302199732036U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15045917390223766480U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9358017420417979347U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aScatter, 48U) + aOrbiterD) + RotL64(aOrbiterK, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI) + aNonceWordP) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterC, 60U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Rugby_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9B0B09B1E72C56EFULL + 0xBF9721ABCE4CF58EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF9F687D0449DD759ULL + 0xDCDCFB477B371749ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x910A4C49A470EC11ULL + 0xD62F03423BD1DCC0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA73151D6AADF478DULL + 0xACEA5287C3B62B3EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD458664A33EB6879ULL + 0xDE417B3506D766E6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB436BF594594D4D9ULL + 0xE75B7BBB7AAD9A6DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE0B51E9FB5A8A2E7ULL + 0xE14CC7876131548CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDBCB4734B5DA861DULL + 0xE99678788BE971E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x80D0131D1729A96BULL + 0x842E862B1C5BD833ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8E4C33BCB57D3135ULL + 0xA07CC3C49FA78144ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDCFD83A3710D1FC1ULL + 0xC4C1CD5D136C852CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBB61169CF752D72FULL + 0x8058EA8335FEA713ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9C0B087D8A3B7E09ULL + 0xBB7F65F4C778BD1FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x926634F2E498C54BULL + 0x9C231A8535F4C41FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC67B66AC08CFCD97ULL + 0xF0A269D482E0ADAFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB31F7A400295B0BDULL + 0x82C666431FFC92E7ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5034U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4064U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1859U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2710U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 58U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 27U)) + 4773124477323378268U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 27U)) + 16848723289435796005U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 53U)) + 13846642134917107058U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 5U)) + 6472057872482789939U;
            aOrbiterB = (aWandererE + RotL64(aCross, 13U)) + 2747019500690707226U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 35U)) + 9003965289739733880U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 3013390651936257377U) + aNonceWordK;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 3331004709895625067U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 15355010435553517129U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 7709870658004280052U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 48U)) + 13568728443963926564U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12409548853419307131U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterF = RotL64((aOrbiterF * 5549220554838837145U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15370309834426476775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3896803894396631184U;
            aOrbiterJ = RotL64((aOrbiterJ * 11018830202891911603U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10848873633291935766U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12885336509190543440U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 1487357252619221365U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8252290890093788010U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9201553615601641350U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 420321130559162915U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14014209645503188472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4015071464301844550U;
            aOrbiterG = RotL64((aOrbiterG * 17444195018239904971U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16173085647514027347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16916627014974363360U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 7699587344277490953U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1591680303404522110U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16499606051269327916U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 814405848002794813U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6932673635509444619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8745681160108707944U;
            aOrbiterE = RotL64((aOrbiterE * 14565255558668084787U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10387263947888920455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2553335462317280031U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 7253573275397985211U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17449861295444216249U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15716408844914738774U;
            aOrbiterK = RotL64((aOrbiterK * 10132631423215542589U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 16974370193820578179U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4773124477323378268U;
            aOrbiterH = RotL64((aOrbiterH * 8982190762960590543U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 46U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 21U)) + aNonceWordL) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 43U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterD, 26U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + aNonceWordO);
            aWandererD = aWandererD + ((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 50U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5503U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 9156U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5993U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 5615U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + 5160910997561396461U) + aNonceWordE;
            aOrbiterC = (aWandererF + RotL64(aCross, 13U)) + 14920764751058512062U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 6080952401749660022U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 17667234330526298627U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 48U)) + 760630072638686756U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 3504157162816997476U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 39U)) + 9489022223422585882U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 1149898536879968964U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 52U)) + RotL64(aCarry, 5U)) + 10492284328940025310U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 3U)) + 13213275606286399312U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 10557118912847180413U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15618980209023994776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5268600749854045564U;
            aOrbiterG = RotL64((aOrbiterG * 3849660559223919613U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8011552687609649990U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3148133096349525066U;
            aOrbiterC = RotL64((aOrbiterC * 5245156554959620007U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12032847944237867285U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14999005703490824673U;
            aOrbiterH = RotL64((aOrbiterH * 6631584955208646049U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5426735969392906710U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3593177531650386729U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12997284886192717043U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1701444719333347373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15928731228196894960U;
            aOrbiterA = RotL64((aOrbiterA * 1919318226904213433U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5960179456039157036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5716434224061596483U;
            aOrbiterF = RotL64((aOrbiterF * 3731976564761202801U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2136841536293340279U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12969550408652728526U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7612191387451455137U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3641997570461447114U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4677572491523684525U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 2730358077882211651U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2741372094325164504U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4998631511811832690U;
            aOrbiterD = RotL64((aOrbiterD * 10619395395977372695U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 6260464862798783617U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16489087874167346533U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11278053967185244867U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7043760915859224327U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5160910997561396461U;
            aOrbiterK = RotL64((aOrbiterK * 15260149870590431675U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 10U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterK, 48U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11517U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 11852U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12163U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14094U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 23U)) + (RotL64(aPrevious, 40U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 37U)) + 6318740973868639425U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 44U)) + 5487840061430920881U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 10258706763248072672U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 53U)) + 18356875269730338208U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 35U)) + 12883160282903147010U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 27U)) + 1010140474942697730U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererF + RotL64(aCross, 39U)) + 17733939421700898293U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 41U)) + 13693055887924981201U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 24U)) + RotL64(aCarry, 47U)) + 14574732452793385269U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 10832873941223609012U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 51U)) + 8212600587135328040U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5312744319781971178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6173741211706546923U;
            aOrbiterC = RotL64((aOrbiterC * 12854414066390848249U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3693249147883790810U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 18365859989736602556U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3348463719324104997U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10645056678337549771U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1175668356822251045U;
            aOrbiterJ = RotL64((aOrbiterJ * 6579675292775345579U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13556844570541823717U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4790355739411849736U;
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14905575502272644116U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterE = RotL64((aOrbiterE * 2356386971503880047U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10161614295718414869U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13413914082651612468U;
            aOrbiterF = RotL64((aOrbiterF * 16224039093981079491U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6072693130156927774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4333656233793103787U;
            aOrbiterG = RotL64((aOrbiterG * 9374745547133955709U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17209776289202130250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11752001118070361543U;
            aOrbiterB = RotL64((aOrbiterB * 4416523594812872339U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15367365111105608277U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8650687767097460704U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 11430451559660578667U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18074648514448405693U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10857586858462237581U;
            aOrbiterI = RotL64((aOrbiterI * 3722891011080095849U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17219932344278345591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6318740973868639425U;
            aOrbiterH = RotL64((aOrbiterH * 8846295038878812229U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 24U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 47U));
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 54U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterG, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18021U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 17525U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17857U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 20079U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 3U)) + 4384716820085860551U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 35U)) + 9715780315942116888U;
            aOrbiterI = (aWandererG + RotL64(aCross, 23U)) + 15963520052789178632U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 14346700690686392938U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 6005518012489966643U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 47U)) + 2506732930310252119U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 21U)) + 16782163084851775826U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 27U)) + 823673076571076303U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 41U)) + 1634084509064077736U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 36U)) + 1288134975466877686U) + aNonceWordF;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + 2998220403162908444U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 220430672180734911U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10223923547068528867U;
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 79691451831797107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8971444023498649419U;
            aOrbiterC = RotL64((aOrbiterC * 7148919880477390009U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5624403902454498793U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9468064161002030997U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8243560528100864595U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4619361544913629805U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12682446273369750704U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10879074713156075641U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8728730962617599223U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9099675924074253030U;
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3298303921318288541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5953276499411658358U;
            aOrbiterG = RotL64((aOrbiterG * 10565471305001292693U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6725769507592688539U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1057277456510215817U;
            aOrbiterJ = RotL64((aOrbiterJ * 8269412198279297075U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11317925732206917722U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17814749417006079067U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4369209051015735925U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9258362135343403308U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4873837345446960113U;
            aOrbiterA = RotL64((aOrbiterA * 14223381466269503273U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7863380865835889675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4384716820085860551U;
            aOrbiterH = RotL64((aOrbiterH * 2003891033298374621U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 46U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 21U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 20U) + aOrbiterA) + RotL64(aOrbiterB, 14U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 53U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 60U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26642U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25022U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23134U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24160U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 29U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 37U)) + 12775735908960052604U;
            aOrbiterA = ((((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 11791373812080296887U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 42U)) + RotL64(aCarry, 13U)) + 5537362877706057303U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 23U)) + 2023912048504189380U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 35U)) + 17668828109963766893U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 53U)) + 558908629933941224U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 29U)) + 1479633119685446888U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 21U)) + 15460320397843364063U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 50U)) + RotL64(aCarry, 57U)) + 10059749397555469054U;
            aOrbiterE = (aWandererF + RotL64(aCross, 19U)) + 9987633811929693924U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 10087337844580228269U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4446204415503364254U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15106063243302192717U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9430197906134676162U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterK = RotL64((aOrbiterK * 14247538885252664127U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10611580584157624739U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3137391249289641509U;
            aOrbiterH = RotL64((aOrbiterH * 5462682413239873181U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10675114832750356941U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8804440385852327267U;
            aOrbiterI = RotL64((aOrbiterI * 8520671775587260601U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12871947817782057116U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11015991745792051390U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17152451500505815031U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6320437975845673731U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 702457937087191287U;
            aOrbiterD = RotL64((aOrbiterD * 17491257114676739589U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 16629064896250312921U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6054107387816339103U;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13274874838094190290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12211422735294360321U;
            aOrbiterB = RotL64((aOrbiterB * 5113738196151089817U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15338616110718583619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1475787183754511373U;
            aOrbiterA = RotL64((aOrbiterA * 10904607643785840003U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15486810401396777742U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12775735908960052604U;
            aOrbiterJ = RotL64((aOrbiterJ * 7478156942468930207U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterG, 46U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 50U)) + aOrbiterI) + aNonceWordJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 23U)) + aNonceWordO) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 38U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 40U) + RotL64(aOrbiterF, 4U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30637U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((aIndex + 27984U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31775U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 28952U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 3U)) + 10881271196314989997U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 35U)) + 6406461249988567558U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 11U)) + 17255067918280095959U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 47U)) + 16690850682497718411U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 5576201059361086866U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 58U)) + 11991259685693687554U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 14652535244217836909U) + aNonceWordJ;
            aOrbiterD = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 1701789037170782122U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 37U)) + 953429054903473833U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 13U)) + 12064513610469714211U) + aNonceWordM;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 30U)) + 7993881398822002424U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14421313768013320050U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11112386845630998889U;
            aOrbiterF = RotL64((aOrbiterF * 11771526352030371669U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17069630896535699015U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterJ = RotL64((aOrbiterJ * 10449509484417835159U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17615529807112933619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11782807146851563541U;
            aOrbiterA = RotL64((aOrbiterA * 12992075832343669221U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14401645829607611983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6736397344219993532U;
            aOrbiterH = RotL64((aOrbiterH * 1667287547938175641U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6446974060524700550U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7840991992443308254U;
            aOrbiterD = RotL64((aOrbiterD * 6891023544882740107U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10362169906019794305U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4503700997923168911U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15066164494038852559U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13492041134973259041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14337899277551397976U;
            aOrbiterE = RotL64((aOrbiterE * 5966740718899290915U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13693100781608180748U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16177545026405910052U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6019231448444020563U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9641191118119415680U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 735491776764667034U;
            aOrbiterI = RotL64((aOrbiterI * 11305930862759869997U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2225714710491247284U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16906789796765378455U;
            aOrbiterC = RotL64((aOrbiterC * 4341667316266234469U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9451961177946601088U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10881271196314989997U;
            aOrbiterB = RotL64((aOrbiterB * 10929686721061541543U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 29U)) + aOrbiterD) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 52U)) + aOrbiterB) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aNonceWordA);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 42U) + aOrbiterI) + RotL64(aOrbiterC, 24U));
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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

void TwistExpander_Rugby_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC5843B6AA52A3215ULL + 0xDDFBA78AC88A09D7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE838EFFF954FC143ULL + 0xDB87F45B9A68087EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEEDEF45073D5943BULL + 0xE723F0162BCADCA4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x876156C081A34E17ULL + 0xD0C06C7538EDEB94ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCE3905147EBABB0DULL + 0xC00959FC1723E14FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCCC3C72E8D10AA59ULL + 0xE22B2B04ABBB6A81ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x87312B2AC808FA0DULL + 0xCB28D90B0BE7C7B1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8DD97584A252FD6FULL + 0x83DD3225034C48FAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB8F5A4AA67FBA97BULL + 0xF31BF1FCD80E1446ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB53818A709B24885ULL + 0xBF5CED79081DF804ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCEC1D257483213A7ULL + 0x97252B42C55A45B2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x85428936E5A27FA3ULL + 0xABC0AB321ED44771ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC16BEC962221ADEFULL + 0xBBF91871553A92AAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9D51405E991F38AFULL + 0xD03F1D849A9A0CCBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEC9F8DE1A3D73A51ULL + 0x8D57A674D585080FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAC324EEEC1513A89ULL + 0xAD03A0E9878CD99AULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 364U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 1786U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3248U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4425U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 47U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 34U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 11U)) + 785861751704720606U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 15968088718435606299U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 53U)) + 1393976526590347151U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 37U)) + 17240750947292745884U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 58U)) + 4921576136163183137U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 35U)) + 3334047873553153032U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 15086509978458408698U;
            aOrbiterD = (aWandererK + RotL64(aCross, 43U)) + 892391205397581998U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 23U)) + 2965686403183767521U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 26U)) + RotL64(aCarry, 51U)) + 14632215393655706170U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 15740589515342377322U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11131164813943086445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6988080581278900960U;
            aOrbiterJ = RotL64((aOrbiterJ * 6412189142344044255U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16021254613117657178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6183615599897921154U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12533992547026652747U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3104325358982904219U;
            aOrbiterK = RotL64((aOrbiterK * 14977348108778147265U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 3878525937957474644U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2120435259884368445U;
            aOrbiterB = RotL64((aOrbiterB * 15964718652193073177U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 14928658302694194856U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9121310461310309348U;
            aOrbiterH = RotL64((aOrbiterH * 17304439784647477491U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3715693239100476493U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7336577492932262490U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11074754160002665253U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2312452827448455675U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4322756069651934618U;
            aOrbiterG = RotL64((aOrbiterG * 6908893297397073539U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4962079617577705818U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5072727464750706525U;
            aOrbiterE = RotL64((aOrbiterE * 4947670001221089155U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4553791875259778686U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15823770920225774233U;
            aOrbiterA = RotL64((aOrbiterA * 409663191536830375U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9468608484284459072U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8658861660659699947U;
            aOrbiterD = RotL64((aOrbiterD * 2933359123761406353U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14453429515273506170U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 785861751704720606U;
            aOrbiterI = RotL64((aOrbiterI * 3544627380583668815U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 54U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 50U) + aOrbiterH) + RotL64(aOrbiterK, 40U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + aNonceWordL);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 38U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aIngress, 48U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8653U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10098U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8944U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6618U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aIngress, 24U)) + 5131645209694953015U;
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 12070391048835379854U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 41U)) + 2604295836242338724U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 5U)) + 14042039029284001596U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 51U)) + 8914654543854559327U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 47U)) + 2185619407969359869U) + aPhaseFOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 5187406295103352574U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 5U)) + 8022832481290871217U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 8783061916740573472U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 21U)) + 10711028365596196301U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 39U)) + 13387065038269133571U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11187001318931801582U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14191473173276034019U;
            aOrbiterJ = RotL64((aOrbiterJ * 2491253922434756431U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16207761776716426435U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9677408414452078760U;
            aOrbiterH = RotL64((aOrbiterH * 5487303383095129949U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17812460332794370649U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7736423148554132028U;
            aOrbiterE = RotL64((aOrbiterE * 15588733747232852555U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17293203944059014763U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 13487243633338010243U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 9468688858740539095U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15979293016815060755U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17645215484691359547U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1449450767288733995U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11635961468586927692U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10530136578329059784U;
            aOrbiterC = RotL64((aOrbiterC * 8785021493374398437U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4900370530116992731U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15952900504821599445U;
            aOrbiterI = RotL64((aOrbiterI * 5413316082800365261U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9938000151832814778U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14170277411106520726U;
            aOrbiterB = RotL64((aOrbiterB * 5058343552974910737U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14091010427448547620U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13658560822164111421U;
            aOrbiterK = RotL64((aOrbiterK * 9523184040517290629U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13954269172267844623U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3921811946419945868U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 6839440867046147039U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14296483810577739898U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5131645209694953015U;
            aOrbiterD = RotL64((aOrbiterD * 10190969526209064367U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 52U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15628U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11455U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14444U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 12683U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 38U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 5960680319644404115U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + 16050752633567034185U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 8447503223226854741U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 14176813813397917591U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 14U)) + 10534915376130006644U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 6866224454375302514U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 37U)) + 16506374165041008396U) + aNonceWordI;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 53U)) + 7167814023968794098U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 39U)) + 13870852197416596664U;
            aOrbiterI = (aWandererH + RotL64(aCross, 18U)) + 18064038854848993105U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 11U)) + 9869630811507771691U) + aNonceWordA;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 863613100452759380U) + aNonceWordL;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 16597969741225436529U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 2680793528887208903U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6575347108051310653U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17062262265485019063U;
            aOrbiterH = RotL64((aOrbiterH * 7601045488473620019U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7193399224636409133U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14146747818810433849U;
            aOrbiterE = RotL64((aOrbiterE * 5273185769989530041U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9441449106442431427U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4303295336545399503U;
            aOrbiterC = RotL64((aOrbiterC * 8829695296836242587U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12604760768543193458U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15779327512379787715U;
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15553000781122708728U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17162740616060079717U;
            aOrbiterI = RotL64((aOrbiterI * 9458662233556750239U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1032374679817715156U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16413393156165548232U;
            aOrbiterA = RotL64((aOrbiterA * 549659738811935015U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14056855000013992045U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7399202019042538829U;
            aOrbiterJ = RotL64((aOrbiterJ * 6103508549612077695U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 2218389473339103389U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4679497280975967770U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9228353578259815023U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7620538119914173747U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3118355627808424159U;
            aOrbiterK = RotL64((aOrbiterK * 12481319980496032783U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16787092219237931175U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 5960680319644404115U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 10727217147056112401U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aNonceWordN);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 34U)) + aNonceWordM) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 26U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 13U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 44U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 38U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17884U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 18693U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17838U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20367U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 13U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 48U)) + 6342299552323486695U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 21U)) + 12692748514781367538U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + 8202639945493229155U) + aNonceWordF;
            aOrbiterD = (aWandererF + RotL64(aScatter, 23U)) + 4439975701793231639U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + 16774235182859553759U) + aNonceWordN;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 27U)) + 8764155413335405667U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 7167848811974967685U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 35U)) + 16768278912125334220U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 9090838954826296201U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 53U)) + 7644075729758006298U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 27U)) + 17326182797908071215U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16158809721888137555U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8029938783858263694U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 12628072435324195483U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8716553521415553404U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7012599977009208840U;
            aOrbiterI = RotL64((aOrbiterI * 8775355876188948851U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13250558696578541499U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13705957059101025396U;
            aOrbiterG = RotL64((aOrbiterG * 16889495686487056367U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2796775206291902461U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13741676263512390669U;
            aOrbiterK = RotL64((aOrbiterK * 10455782033465595947U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1691908360612389252U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4114939415206031540U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2797401802892718297U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2374911514440738727U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12377616933668803091U;
            aOrbiterF = RotL64((aOrbiterF * 2505164835116651215U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 681094033415259645U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13841322124900463362U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4210414203856902329U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18082983557580381338U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15731122225678626778U;
            aOrbiterC = RotL64((aOrbiterC * 7785999919955613789U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2084336993254383330U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3600882019682875370U;
            aOrbiterH = RotL64((aOrbiterH * 2977569829649654329U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11436602278656592334U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5775886971784627864U;
            aOrbiterJ = RotL64((aOrbiterJ * 6765942246225582787U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17120308925134658794U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6342299552323486695U;
            aOrbiterD = RotL64((aOrbiterD * 5788669985396507227U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 58U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterC, 6U)) + aNonceWordH) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterA) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26093U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 27239U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22888U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23942U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 14U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 26U)) + RotL64(aCarry, 21U)) + 5906639480605353429U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 19U)) + 5293518570213287605U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 15383185501428521377U;
            aOrbiterC = (aWandererF + RotL64(aCross, 3U)) + 15364072512743978902U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 57U)) + 4525473357144014271U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 29U)) + 10400911938125603074U) + aNonceWordG;
            aOrbiterA = (aWandererK + RotL64(aIngress, 47U)) + 16417506293824627550U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 11U)) + 2419329331753341815U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 21U)) + 14929222427923332069U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 44U)) + RotL64(aCarry, 47U)) + 16771573504983922586U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 13U)) + 1863466450051787622U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12895350137096692415U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3700979086526298327U;
            aOrbiterD = RotL64((aOrbiterD * 10279730254867618193U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1977099106211282426U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6144698304096915742U;
            aOrbiterF = RotL64((aOrbiterF * 5039822990560519609U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3858895556659724975U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1283646340363435327U;
            aOrbiterB = RotL64((aOrbiterB * 11622421841377018069U), 43U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 6240532051889108891U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 757364889381634634U;
            aOrbiterH = RotL64((aOrbiterH * 943852137901972945U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5272945693977418174U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6850528198786172283U;
            aOrbiterJ = RotL64((aOrbiterJ * 1966383079897679953U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14431587733859573714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16124590257870999553U;
            aOrbiterC = RotL64((aOrbiterC * 7755796211433191143U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14912695018110241411U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11098623474413346520U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 15167688959990872051U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 3484847683376368686U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2295388097292719800U;
            aOrbiterI = RotL64((aOrbiterI * 1240808318176106909U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 923199510066894111U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 311875852510926196U;
            aOrbiterG = RotL64((aOrbiterG * 9797881750305289335U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3543141837224843684U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12889943043568922084U;
            aOrbiterK = RotL64((aOrbiterK * 8682278766727990427U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6105656539077757510U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5906639480605353429U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9555916235293954383U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK + ((RotL64(aCross, 30U) + aOrbiterE) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aNonceWordF) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE + (((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterF, 56U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32144U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 27376U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30299U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 32027U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 47U)) + 13174219512651137892U) + aNonceWordL;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 18U)) + 2715455762789269341U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 41U)) + 1338018183235594313U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 16566866551729552930U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 35U)) + 6901845297307236726U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 23U)) + 2476078302049201718U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 14U)) + 15531109473927052260U) + aNonceWordP;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 4087849380858572351U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 43U)) + 5167830630098599644U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 7275995452428627217U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 14794340370010024117U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8509217403041662849U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2321522025240806996U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 113568101672878697U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5676672952755594051U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2304681269233504384U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8383399721062437300U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13181984036942227666U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 1648761328771932069U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13602604532551684210U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12725687663616352843U;
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5831790822416009806U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 4535048543735457407U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12076777878870257053U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 10617608605149381858U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5244225377862618630U;
            aOrbiterG = RotL64((aOrbiterG * 15307177251167023999U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18229989093139888456U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9728120630096192811U;
            aOrbiterH = RotL64((aOrbiterH * 16052574428163231023U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1312233443099767304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8043115602160128619U;
            aOrbiterE = RotL64((aOrbiterE * 9365756845731616963U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4679339316686216023U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 211799535650113758U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1478368466990144107U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13307123762743628190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7093673238704478497U;
            aOrbiterI = RotL64((aOrbiterI * 13273906568866802561U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 16396459072175632290U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13174219512651137892U;
            aOrbiterF = RotL64((aOrbiterF * 7581008806810219369U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 26U)) + aNonceWordB) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterI, 28U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Rugby_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3695U)) & S_BLOCK1], 40U) ^ RotL64(aKeyRowReadA[((aIndex + 4956U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2813U)) & W_KEY1], 24U) ^ RotL64(mSource[((aIndex + 7017U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 19U)) + 13583136155674166402U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 12830472187484919497U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 18081197909484522509U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 53U)) + 8680634051297891550U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 5U)) + 13939998767458656823U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 1795730579103692594U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 24U)) + 17369751719734069999U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 35U)) + 224769585901248068U) + aPhaseCOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 39U)) + 4133547085925268180U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7022512056309567391U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10319484359046945495U;
            aOrbiterK = RotL64((aOrbiterK * 3400140531307001933U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10483878349412282069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6481381149199985736U;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13721077228796934509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9704818014314175007U;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6253040047758584339U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16890211690273641226U;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6216227831265032436U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2023609047004658739U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3252332895698310147U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9201669637050388263U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5106927540934338576U;
            aOrbiterA = RotL64((aOrbiterA * 6368134569042291431U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10080368957861445998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10784789383436485808U;
            aOrbiterB = RotL64((aOrbiterB * 3794918350254445939U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15426339824951793026U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17637144549368340331U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10971293914614704441U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9941300382181962134U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8118046374121322097U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8481945819050983127U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 34U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterI, 40U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 30U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aPhaseCWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 56U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15546U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((aIndex + 12958U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12592U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 9918U)) & W_KEY1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 47U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 16124889768301047791U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 57U)) + 11912338587186717280U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 8594012868813114354U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 13U)) + 18281043566156682815U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 28U)) + 16853106130200942302U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 3U)) + 2611212958619673086U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 18039472325066855180U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 51U)) + 14495785571345122046U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 46U)) + 4556063793412832418U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14896419970271244358U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 880028529183500036U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2379557167489415783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11854373946064529806U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 150755294320438887U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1487252775956449964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12777924204511625545U;
            aOrbiterB = RotL64((aOrbiterB * 1366019527386994789U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15998631485222477969U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8864212892296191613U;
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17069347835763226743U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7443008171694679791U;
            aOrbiterC = RotL64((aOrbiterC * 748894368884566607U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17334256152350782002U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8986626119086556393U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2258172145924120235U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8528180968228358674U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12702290928064582589U;
            aOrbiterE = RotL64((aOrbiterE * 15673603224146737631U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7742438100860023610U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3729687240959702198U;
            aOrbiterF = RotL64((aOrbiterF * 3756794766163746783U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 426129097367382096U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16782175452274911213U;
            aOrbiterI = RotL64((aOrbiterI * 1041477289638333659U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22728U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18724U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 23468U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 22719U)) & W_KEY1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 60U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 43U)) + 15036852811491820366U) + aPhaseCOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 43U)) + 305637140752898475U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 11948631574496129610U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 5321623592482991426U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 58U)) + 4075270159062690728U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 19U)) + 15111580500356908928U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 47U)) + 7244150695504160363U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 35U)) + 5131563519577488862U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 23U)) + 5881954992088651371U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12780935808751507998U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12599159643925470226U;
            aOrbiterB = RotL64((aOrbiterB * 17690046932587062701U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9466589929741834066U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6093158735705189789U;
            aOrbiterI = RotL64((aOrbiterI * 7453778295800853653U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17461243886150519249U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15456408913739900718U;
            aOrbiterE = RotL64((aOrbiterE * 16093292401746174671U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11260643903290392780U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7870342756041882616U;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 134484990005888936U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10626896209992890407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12034131076645285597U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14031164129515132292U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1771835705730244212U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 186981668443596623U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16395472745067254664U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1455944290845294254U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6757824754363319079U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17866422769075350837U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10226884082632410805U;
            aOrbiterD = RotL64((aOrbiterD * 206035536985843815U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14474587247775371703U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8501763445324525303U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5298694643596784007U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 4U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aIngress, 24U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterH, 46U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterF, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30940U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24651U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25732U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((aIndex + 29606U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 42U)) + 14249093584376402677U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 8756965951816492264U;
            aOrbiterA = (aWandererG + RotL64(aCross, 5U)) + 11221139480258176330U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 17218894445564194851U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 53U)) + 8064642692524949490U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 57U)) + 5822093203710704646U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 28U)) + 3217799620158102238U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 2613757677892120843U) + aPhaseCOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 35U)) + 13647481499551657237U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3545714196663685016U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9735422670576621521U;
            aOrbiterA = RotL64((aOrbiterA * 7276207208162697249U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3911046580637583767U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9315984027042049203U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12568550776487242469U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8926367674641729058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11035347490524961446U;
            aOrbiterG = RotL64((aOrbiterG * 10948288997163592463U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10748158733051120339U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2467801787989056455U;
            aOrbiterC = RotL64((aOrbiterC * 12621934274702358977U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9244415080474351390U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8517784887959492079U;
            aOrbiterH = RotL64((aOrbiterH * 17022899813765884147U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8409307332803038455U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11043806021873232950U;
            aOrbiterF = RotL64((aOrbiterF * 8294888329708842989U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17512395828450251457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16849067939795823992U;
            aOrbiterK = RotL64((aOrbiterK * 9361991804481514337U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17541946638063238056U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11430501673960586718U;
            aOrbiterE = RotL64((aOrbiterE * 15074409630605450091U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 78307505705383302U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4834528975263832983U;
            aOrbiterJ = RotL64((aOrbiterJ * 17245673681686752861U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 14U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 4U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 34U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Rugby_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4882U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 2788U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1628U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 3944U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 13U)) + 5480870806135400132U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 5U)) + 8034874599430768743U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 21U)) + 4006919843736863767U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 2988069748674633718U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 12347295651973135786U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14152683894431568192U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15765143815254196598U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8948877544291035189U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10473067082331244233U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1089466925383677249U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17334888609179149753U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13215039929873682230U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3957997712247961479U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7631186240013784703U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10023907397941685546U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14593012591254614353U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17111300092082154687U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13353797968154036726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9259966668512102858U;
            aOrbiterD = RotL64((aOrbiterD * 8326732574268308221U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 56U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10125U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 11494U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13629U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 8983U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 6024062041314952357U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 39U)) + 18340757093658015585U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 11911120493880346751U) + aPhaseDOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + 17428074353884654439U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 12790849760814795936U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12633397052172117800U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11946150433665237945U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10324089534873171291U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16842157900909419285U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14186235783224155962U;
            aOrbiterF = RotL64((aOrbiterF * 10521157787073684417U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13284904542579767591U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11609181965078844357U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5455780554452453513U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9628562297095374984U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7850281529011259759U;
            aOrbiterJ = RotL64((aOrbiterJ * 17611485102925470357U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 257458718073794527U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10693404545773519306U;
            aOrbiterG = RotL64((aOrbiterG * 14821443722828498323U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE + (((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 22U)) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17684U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21236U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22816U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 19747U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 3U)) + 13915875634607599122U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 20U)) + RotL64(aCarry, 43U)) + 1695770381382411673U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 3709105579778295511U) + aPhaseDOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 7673376335333251804U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 8814147709738503518U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13451412605350381172U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6447870234069609538U;
            aOrbiterE = RotL64((aOrbiterE * 4016219229618539433U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13419487997946496825U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5478309847615220345U;
            aOrbiterJ = RotL64((aOrbiterJ * 12953043149543448765U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3635184969215610049U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12527903812035294828U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12540800512035534967U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1684685110885338814U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12860354576326835090U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12743745087733307255U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9081823570147481835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14369321778210049109U;
            aOrbiterF = RotL64((aOrbiterF * 17865953349448767035U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 42U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 24U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31566U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 31880U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26022U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32586U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 35U)) + 12809562813316740345U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 27U)) + 17084212535326321199U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 11U)) + 16074921689983846769U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 14027986153007120145U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 7633455951809250227U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 340989348513370174U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5307820377645020116U;
            aOrbiterC = RotL64((aOrbiterC * 8402492604131262157U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5605285015771527274U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5293500434746182790U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17674669610895537063U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7263156475892261811U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10672879570907433005U;
            aOrbiterE = RotL64((aOrbiterE * 2506338667179450741U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16659226780900986107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9774892622769850665U;
            aOrbiterF = RotL64((aOrbiterF * 7487477727543183211U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10728057184108279042U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5032485856947407217U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16651577903809154285U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 3U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 34U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
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

void TwistExpander_Rugby_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7723U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 3234U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7011U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 2822U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 52U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 41U)) + 966899917801652720U) + aPhaseEOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 10996327672320748649U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 4188171566846621107U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 5886209243097387959U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 14940428957136728111U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 12U)) + 179187285531914832U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 5U)) + 6685351948936817752U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1894506461704029700U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4182760368636977082U;
            aOrbiterD = RotL64((aOrbiterD * 972988091869133921U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12523318028514940790U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5059306166973366892U;
            aOrbiterK = RotL64((aOrbiterK * 2857409765717296483U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5890872367917643851U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17747338389865221534U;
            aOrbiterA = RotL64((aOrbiterA * 5306740664798049267U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13906227834259884100U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7152105382899756368U;
            aOrbiterF = RotL64((aOrbiterF * 6772157117358310485U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17868101884759619240U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11758843266314148347U;
            aOrbiterB = RotL64((aOrbiterB * 5919135169337501485U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13950566197090324859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17278105609930477854U;
            aOrbiterG = RotL64((aOrbiterG * 11431842718945107359U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9556785965646738355U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 841298436857932987U;
            aOrbiterI = RotL64((aOrbiterI * 15077843186688841797U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 12U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 20U) + aOrbiterK) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 12U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10920U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8936U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11701U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10705U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 34U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aPrevious, 18U)) + 13924571355038625040U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 51U)) + 16328300979357156658U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 3947771961206012461U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 15428284250569311285U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 11U)) + 5777369485254032486U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 16813320300717644673U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 16689933050200758251U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1856422419049390708U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 18214498743831925517U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10744120577560529379U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18278550878494094923U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 797712062039591797U;
            aOrbiterK = RotL64((aOrbiterK * 7212998747080137625U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15854849439012341347U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 996882939768167773U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14936703950807908575U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3005829974130671692U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8793495343509953906U;
            aOrbiterC = RotL64((aOrbiterC * 14065479348374612031U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7710453029930631112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9511995836117707047U;
            aOrbiterE = RotL64((aOrbiterE * 7250766204781428201U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 670902975693341744U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9045820304668279777U;
            aOrbiterI = RotL64((aOrbiterI * 18373074917532639027U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12417212387607119470U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12816983560669985622U;
            aOrbiterD = RotL64((aOrbiterD * 8406003970221889847U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 10U)) + aPhaseEWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22349U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22913U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19756U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22099U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 51U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 8020711767807230555U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 43U)) + 15368693777246341570U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 19U)) + 5117523734225562401U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 56U)) + RotL64(aCarry, 3U)) + 13155269151097507808U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 5U)) + 9879303753623578272U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 1165799257173794826U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 930641942062732091U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11330571332221123153U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2862963158282518899U;
            aOrbiterJ = RotL64((aOrbiterJ * 13782195862525974199U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6019186399361476659U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1924419843785161958U;
            aOrbiterI = RotL64((aOrbiterI * 9485557122500346869U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12618629043591380461U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9334176504266512405U;
            aOrbiterD = RotL64((aOrbiterD * 18239109235362925739U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16829692481030013551U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5604784396927022709U;
            aOrbiterC = RotL64((aOrbiterC * 2833893610883508353U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16124030106598549644U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16571659812830230677U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4668250364992383549U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15171089673591843703U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2826755560293849328U;
            aOrbiterH = RotL64((aOrbiterH * 9397017963457655287U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 30U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 38U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27614U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25471U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30419U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 27114U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 30U)) + RotL64(aCarry, 11U)) + 8793908991006073956U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 21U)) + 2932916283348441943U;
            aOrbiterK = (aWandererB + RotL64(aCross, 11U)) + 11069042087940968262U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 14369628676782894441U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 8602903272780978282U) + aPhaseEOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 43U)) + 3827036107178568820U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 37U)) + 8905245209036772489U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13331387530760017893U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9880107580289737823U;
            aOrbiterK = RotL64((aOrbiterK * 10302652857542703753U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10199619040626900278U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2466307560891374281U;
            aOrbiterG = RotL64((aOrbiterG * 6295342978834217571U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13973403407981259448U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2851460278409385243U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11226902976321781743U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10365453393815690776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2382382358987358791U;
            aOrbiterI = RotL64((aOrbiterI * 481563628980705781U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5058198848163792422U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10500434740387593487U;
            aOrbiterC = RotL64((aOrbiterC * 5946747708776079787U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11289798395177667084U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14327152153231286666U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18155778059595245561U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 8065137263811956313U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3865153574847924816U;
            aOrbiterJ = RotL64((aOrbiterJ * 9495741102667755161U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterE, 50U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 34U);
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

void TwistExpander_Rugby_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 283U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3987U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7569U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 5237U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 13650869943246163567U) + aPhaseFOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 3435284932011770999U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aCross, 19U)) + 12388155658186776579U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 2374345913955712039U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 27U)) + 6095094526980292156U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4965147025852444174U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3261881216269075298U;
            aOrbiterH = RotL64((aOrbiterH * 4874733445914960785U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4939780217097329222U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3019862009792676287U;
            aOrbiterB = RotL64((aOrbiterB * 2452316208025448747U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 901910626217143974U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3647055146712366383U;
            aOrbiterI = RotL64((aOrbiterI * 1792602402476450009U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7731765438957392967U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13409819457393479741U;
            aOrbiterC = RotL64((aOrbiterC * 3345078200262410715U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5415832109107794258U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8876738832313114471U;
            aOrbiterE = RotL64((aOrbiterE * 1304277600444504135U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 30U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 20U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 36U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10716U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((aIndex + 9671U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13439U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 13274U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 16462052553719977502U) + aPhaseFOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 12337064059566619581U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 21U)) + 15801005007094515447U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 8228706742665081656U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 50U)) + 11006723027845190869U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18173765337829177450U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 530215083653542558U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8938680024265564887U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6608611827035564511U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2246051826221626809U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6333352641495253539U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5228575308895381421U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10999213210689606857U;
            aOrbiterB = RotL64((aOrbiterB * 5467601259546342925U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3773371037240485696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8887985779436152504U;
            aOrbiterG = RotL64((aOrbiterG * 698713082830739677U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11150566414723818350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8336366151003049546U;
            aOrbiterK = RotL64((aOrbiterK * 9033771197242493699U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 42U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 36U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21181U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19140U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20398U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17239U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 3U)) + 8866844335448071821U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 15159698739856430085U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 52U)) + 9582805772989594633U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 1438538239931588373U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 10862044156620436139U) + aPhaseFOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13682173320058164615U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8351013291045977592U;
            aOrbiterB = RotL64((aOrbiterB * 5722336275651615473U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15777857431516633916U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16178966745333885377U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7545129923202147703U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9031889187993001617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6308472367425865347U;
            aOrbiterD = RotL64((aOrbiterD * 17118710301967158153U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 642109145903321046U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9186268569255318035U;
            aOrbiterC = RotL64((aOrbiterC * 10714674348507516749U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6091345356803675860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13218507921880873749U;
            aOrbiterF = RotL64((aOrbiterF * 15415157927185637717U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 38U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31639U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 26281U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24949U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25818U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aIngress, 54U)) + 3236820517816085022U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 41U)) + 741288875914097926U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 8417246926007729580U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 9715717805774537170U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 14360243844821619482U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10760908100206775334U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3434641779946167811U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3305698324169010803U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7885568822756234567U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3041563437672051294U;
            aOrbiterF = RotL64((aOrbiterF * 11440300917533482297U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15761355327564963516U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1158633562785937421U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15511324886867188235U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9338581575871970653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14653924713599790081U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3854497592598563309U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11737111068815795303U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Rugby_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 2285U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 6583U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 419U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5211U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 785861751704720606U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 15968088718435606299U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 1393976526590347151U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 17240750947292745884U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 34U)) + 4921576136163183137U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3334047873553153032U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15086509978458408698U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2162818176367899893U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 892391205397581998U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2965686403183767521U;
            aOrbiterC = RotL64((aOrbiterC * 709160942482770225U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14632215393655706170U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15740589515342377322U;
            aOrbiterI = RotL64((aOrbiterI * 15677716942904794913U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11131164813943086445U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6988080581278900960U;
            aOrbiterB = RotL64((aOrbiterB * 6412189142344044255U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16021254613117657178U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6183615599897921154U;
            aOrbiterJ = RotL64((aOrbiterJ * 9976411093264211033U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 39U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 38U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 56U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15280U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12376U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13612U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10893U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 15920462086654025436U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 487844076858004017U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 14502883786442630566U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 58U)) + 3787107318658233674U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 29U)) + 12548777544693755491U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4907309444075181683U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18342396700266492072U;
            aOrbiterK = RotL64((aOrbiterK * 14842961036061482089U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13503051997624242670U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17845742460521374571U;
            aOrbiterI = RotL64((aOrbiterI * 1366356786138085155U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8640887211877858169U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5273913123709097537U;
            aOrbiterG = RotL64((aOrbiterG * 1661149444148461791U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17756844173695563883U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6713055830729302951U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2832836748513174311U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5106468334224035972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10228769728713526172U;
            aOrbiterA = RotL64((aOrbiterA * 9760310686414358435U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 36U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterG, 40U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterB) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererD, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24466U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19927U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18077U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 22627U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 30U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 12809562813316740345U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 27U)) + 17084212535326321199U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 16074921689983846769U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 57U)) + 14027986153007120145U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 7633455951809250227U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 340989348513370174U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5307820377645020116U;
            aOrbiterA = RotL64((aOrbiterA * 8402492604131262157U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5605285015771527274U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5293500434746182790U;
            aOrbiterG = RotL64((aOrbiterG * 17674669610895537063U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7263156475892261811U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10672879570907433005U;
            aOrbiterI = RotL64((aOrbiterI * 2506338667179450741U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16659226780900986107U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9774892622769850665U;
            aOrbiterK = RotL64((aOrbiterK * 7487477727543183211U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10728057184108279042U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5032485856947407217U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16651577903809154285U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 48U)) + aPhaseGWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 60U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26934U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 26138U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28464U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 26270U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + 5568146815535263910U) + aPhaseGOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 7736084960873834666U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 29U)) + 1336413621817562093U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 5218462026934984692U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 27U)) + 7048890985969555935U) + aPhaseGOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 13415955213864702118U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5657023257021528548U;
            aOrbiterC = RotL64((aOrbiterC * 5200798937081797819U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14338310943137497116U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12305161641833950473U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11949964304435964395U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14514226578370459131U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12692904083266024340U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14800805065279908839U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11012959130001327964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7106471380403489078U;
            aOrbiterD = RotL64((aOrbiterD * 515626559384817223U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3718101961355280891U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13364192077222322664U;
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 30U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 58U)) + aPhaseGWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aIngress, 56U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 58U);
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

void TwistExpander_Rugby_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 514U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((aIndex + 4781U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3773U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6092U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 15652862298542575895U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 11U)) + 16925323928418184554U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 4413861484961668394U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 23U)) + 2215946422098155969U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 14975185533513111110U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9711613814905834552U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13154957291850149471U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17049677190793844477U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5058313016418534840U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15011423472941211620U;
            aOrbiterD = RotL64((aOrbiterD * 6125316151731105673U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2030053257469580168U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 150530795186791193U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10878237472104183427U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11724672539469573109U;
            aOrbiterE = RotL64((aOrbiterE * 16158741837357985395U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9589700906445846956U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1367381624958248949U;
            aOrbiterF = RotL64((aOrbiterF * 8459515089081211977U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 4U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 28U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterD, 44U)) + aPhaseHWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10309U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10177U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11974U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15328U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 7825479804710770560U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 5298124167101358123U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 17774541024369233726U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 14U)) + 7679371833537454082U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 53U)) + 5385914900748772224U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3879781930908486531U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 659110346638873236U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17439162088869824407U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10749021728538539749U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3631252455767429457U;
            aOrbiterE = RotL64((aOrbiterE * 8552825360915119613U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2271978810960685021U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 5963558780692551176U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4772055335210781149U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 974909966119198104U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9296998242911152296U;
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2245318466901521959U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13391076374843288568U;
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 36U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterG, 56U)) + aPhaseHWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20522U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 21931U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20525U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22545U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 966899917801652720U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 35U)) + 10996327672320748649U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 11U)) + 4188171566846621107U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 5886209243097387959U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 14940428957136728111U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 179187285531914832U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6685351948936817752U;
            aOrbiterC = RotL64((aOrbiterC * 15533370414711696803U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1894506461704029700U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 4182760368636977082U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 972988091869133921U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12523318028514940790U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5059306166973366892U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2857409765717296483U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5890872367917643851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17747338389865221534U;
            aOrbiterH = RotL64((aOrbiterH * 5306740664798049267U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13906227834259884100U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7152105382899756368U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6772157117358310485U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 48U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 28154U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27491U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27560U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 28364U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 50U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 15920462086654025436U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 28U)) + RotL64(aCarry, 11U)) + 487844076858004017U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 19U)) + 14502883786442630566U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 43U)) + 3787107318658233674U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 47U)) + 12548777544693755491U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4907309444075181683U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 18342396700266492072U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14842961036061482089U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13503051997624242670U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17845742460521374571U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1366356786138085155U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8640887211877858169U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5273913123709097537U;
            aOrbiterI = RotL64((aOrbiterI * 1661149444148461791U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17756844173695563883U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6713055830729302951U;
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5106468334224035972U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10228769728713526172U;
            aOrbiterF = RotL64((aOrbiterF * 9760310686414358435U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 4U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 22U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
