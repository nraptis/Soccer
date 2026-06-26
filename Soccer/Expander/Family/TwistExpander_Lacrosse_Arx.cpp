#include "TwistExpander_Lacrosse_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Lacrosse_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCBBD8979142403E5ULL + 0x9D15EE6970415D76ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8BD84A15AC0541A3ULL + 0xCCBAB3B74BC3B72DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD2752ED35895B1BDULL + 0xB08444C46596D8B9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8070C862B2B20B3DULL + 0xCBFBA1819F12C68AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEA5A019368839AABULL + 0xBA22F96A8F3D7369ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x99FC3D055FABD7DBULL + 0x9E39772F3B6AC926ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEC5E7855DDF3C45DULL + 0xDB3BF98A52B7705EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC942B0ACE6DAD909ULL + 0xC7A7768BD844E75AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB247404E4A46C575ULL + 0xEF1E71E4C9153120ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA6CD99E417CDF115ULL + 0x8BE49F85672B7A89ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x92D8C68B4147DAB7ULL + 0xBE9BF9D57148FE43ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDBAF4C137E1AE3A1ULL + 0x97353D063F33C202ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x84845E7F9A5A4937ULL + 0xC09F0AF849545CCCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFC456C7916063815ULL + 0xFD773F14CE7852D4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x925599B3B1C56C69ULL + 0xF71AE86FF83F676FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA63288CD86732475ULL + 0xB0B925F15DEC0F70ULL);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2929U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((aIndex + 2323U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3566U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2268U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 11U)) + 826930775230515406U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 24U)) + 5137814617363250861U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 14761561947426681616U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 51U)) + 12773023438753662590U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 57U)) + 7331345852207096322U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 37U)) + 3899381212671247460U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererB + RotL64(aCross, 13U)) + 10072004147620068599U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 3424585039401897560U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 42U)) + 8246760141625966321U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 3655992860610853290U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 5U)) + 11154618022505863898U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15629361991059709973U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10842068502278489664U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 17223002513104960799U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5571312349016336686U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 589313823745748879U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13633457935771935260U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12684602052812183096U;
            aOrbiterC = RotL64((aOrbiterC * 4689206269919806711U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5711307583717354204U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterD = RotL64((aOrbiterD * 9835601115561325911U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1884620014396115821U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1471516373272364262U;
            aOrbiterH = RotL64((aOrbiterH * 5126319375714848029U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 742739371092077733U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8075893317715227838U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 11208274111743259795U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8179547722249281263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15305282712174742323U;
            aOrbiterE = RotL64((aOrbiterE * 7951986906055462929U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1430543231751281079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14585341768267283387U;
            aOrbiterJ = RotL64((aOrbiterJ * 313213844964269133U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8123889986027932297U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2081696191347150910U;
            aOrbiterI = RotL64((aOrbiterI * 4869653441012615053U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10166788886199265936U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15927074835525735601U;
            aOrbiterG = RotL64((aOrbiterG * 6747650218540675523U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6997764816848988590U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 826930775230515406U;
            aOrbiterK = RotL64((aOrbiterK * 9943232461538279601U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 46U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 26U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 4U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterH, 37U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordK;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9881U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 7799U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8938U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 10527U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 21U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 21U)) + 14823268998003220191U) + aNonceWordE;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 15295237288788213847U) + aNonceWordB;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 29U)) + 16434853402001133899U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 10U)) + 7555911304407871631U;
            aOrbiterK = (aWandererF + RotL64(aCross, 23U)) + 14977248264994834620U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 9707764144919392380U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 13U)) + 1277304385464681529U) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 19U)) + 3089786220465849395U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 58U)) + 3700503853358695085U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + 3240054112993517371U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 16897532076915366859U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18167359289798364307U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8870819278575769863U;
            aOrbiterJ = RotL64((aOrbiterJ * 9334066154398059075U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15363069206212330251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14858164441499725158U;
            aOrbiterE = RotL64((aOrbiterE * 14931933411393847915U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5357144808788707522U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2910681277417754860U;
            aOrbiterK = RotL64((aOrbiterK * 13170868582159347059U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9824408699018165151U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 368370224788793300U;
            aOrbiterA = RotL64((aOrbiterA * 14358982366258729959U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7095398304588825115U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11418879758164313554U;
            aOrbiterD = RotL64((aOrbiterD * 5983520332639771791U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2171599720681913272U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17593730219647495033U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12926053208918563087U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17755947635188715523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14565740605227022106U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15866418354612945335U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14538017880915584414U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6174566474851449123U;
            aOrbiterI = RotL64((aOrbiterI * 179569008593475683U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3806438394748643441U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13737114463856719285U;
            aOrbiterC = RotL64((aOrbiterC * 13439346068497710151U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3698379331577470045U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1097081284062708554U;
            aOrbiterF = RotL64((aOrbiterF * 3498627643013255777U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 215117138867597766U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14823268998003220191U;
            aOrbiterG = RotL64((aOrbiterG * 12131828437975771377U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 48U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 58U)) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 24U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12117U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13036U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 15711U)) & S_BLOCK1], 12U) ^ RotL64(pSnow[((aIndex + 15582U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 11U)) + 14214886793361825363U;
            aOrbiterH = (aWandererB + RotL64(aCross, 5U)) + 17267959031078766320U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 27U)) + 16436067429484887644U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 9885951769332633820U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 12971711341813893304U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 39U)) + 199970353398450154U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 1237341696444162094U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 7991128854417613360U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + 14809029847149045833U) + aNonceWordF;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 43U)) + 2559509556915775947U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 56U)) + 14336829730147834160U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8853631886733610440U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13346159398673246914U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13660497151446983393U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12121095718571872976U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16239781125815589804U;
            aOrbiterC = RotL64((aOrbiterC * 5157009090454962231U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9051377033794324106U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13805815136723461780U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 571129481747181357U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 14849157800322754413U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18116651528452542634U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3638480428016835537U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4105057226952948599U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5911714320560994391U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1796514171654961389U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4439149331729987587U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10278532228230163632U;
            aOrbiterE = RotL64((aOrbiterE * 17428224919864716517U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2342456582668741750U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2360578572554664800U;
            aOrbiterI = RotL64((aOrbiterI * 1108428466956691925U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12132934875391401246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17213278726790245812U;
            aOrbiterG = RotL64((aOrbiterG * 11904899990681410419U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7994340481560109811U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13735851271080138255U;
            aOrbiterK = RotL64((aOrbiterK * 12387076892129731557U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6682417543888875268U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15642799286975840550U;
            aOrbiterD = RotL64((aOrbiterD * 7861250716882028053U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9839299346094784067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14214886793361825363U;
            aOrbiterJ = RotL64((aOrbiterJ * 2103132743364916037U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 6U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterF, 39U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterK, 44U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 13U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 56U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + aNonceWordB) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 40U));
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18837U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18218U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18562U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 18026U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 12U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 4179952823252098240U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 3U)) + 3745613452332101749U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 12U)) + RotL64(aCarry, 29U)) + 2955689793395307176U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 5639060180251322019U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 57U)) + 7901969163853586463U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 51U)) + 2242166787816318119U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 41U)) + 5239936443960750064U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 13939136954732185558U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 10U)) + 17058884136712717463U) + aNonceWordF;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 5U)) + 18148618660054585941U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 7022023484530327814U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7722084537340095637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11764151879690934182U;
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16412785901758144708U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9666718667728274824U;
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4307127540152109364U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2457646804702647606U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6340030928007058595U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3179394870088602208U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 504977947273774249U;
            aOrbiterK = RotL64((aOrbiterK * 16190282058883481551U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16182729401018310837U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7110817020445860609U;
            aOrbiterH = RotL64((aOrbiterH * 13371352088428584087U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12960656706837391973U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7103806893724395904U;
            aOrbiterI = RotL64((aOrbiterI * 14365984439655979791U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1248300178080633527U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7195473175424961337U;
            aOrbiterD = RotL64((aOrbiterD * 4633558992739305045U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13007951568242991449U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10296811247653636372U;
            aOrbiterF = RotL64((aOrbiterF * 16469682651380549395U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13922797949001028335U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16773545425463040155U;
            aOrbiterB = RotL64((aOrbiterB * 10639282630227832397U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2888887140296117803U) + aNonceWordG;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 10279517418046269817U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 8600355360339461535U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17303373436784809093U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4179952823252098240U;
            aOrbiterE = RotL64((aOrbiterE * 3675754609699406437U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterA, 44U));
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 46U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25218U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 27039U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24276U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 23853U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 2177539223979303669U) + aNonceWordJ;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 30U)) + 3962004686551521471U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + 8457602312617147662U) + aNonceWordF;
            aOrbiterE = (aWandererA + RotL64(aScatter, 11U)) + 18011802451816510632U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 9046101759168876832U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 11135620637431969597U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 23U)) + 15913029940697999701U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 47U)) + 16304193109948135982U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 53U)) + 13208892298820080981U) + aNonceWordP;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 19U)) + 4182377898949419225U;
            aOrbiterG = (aWandererF + RotL64(aCross, 3U)) + 13970137023071326151U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8402396284835248583U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9760005337757990392U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14108277760135744897U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4474681104256093885U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12226316121949012350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3456392186754113960U;
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5004087958637038973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10889800478505074438U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13728832441482547824U;
            aOrbiterC = RotL64((aOrbiterC * 17588477761978646139U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17345665880706866772U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 301139993853297566U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5812445396758354505U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2061389844760610160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13631862266139238355U;
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10767186080827509622U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 4893486019456886013U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 5194746459545610901U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11264795916303477037U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16013652139405432608U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14924257021089920495U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5209743554932653849U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13160179712987277456U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5003755912040281427U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12440615920191945386U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2177539223979303669U;
            aOrbiterJ = RotL64((aOrbiterJ * 3565122523239344029U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterH) + aNonceWordC);
            aWandererC = aWandererC + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 24U) + aOrbiterJ) + RotL64(aOrbiterI, 22U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30381U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30499U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28808U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 30743U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 29U) + RotL64(aPrevious, 12U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 17470880031634374199U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 60U)) + 757565846006937746U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 53U)) + 9419282475801345674U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 2014248014107898196U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 51U)) + 15113928519446490441U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 11U)) + 7346126964886259935U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 5594123113093162359U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 29U)) + 5659237263369402005U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 46U)) + 11565709683423969703U) + aNonceWordB;
            aOrbiterF = (aWandererG + RotL64(aCross, 23U)) + 16782863743534856287U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 39U)) + 13499100900072115907U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11414447651044205242U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7545993795121430538U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10758488381206257261U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11778229237616454988U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2544793391976514665U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4021060413798523299U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9972156716619459164U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17651030383827445664U;
            aOrbiterA = RotL64((aOrbiterA * 6742914240706775487U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17439147296849134543U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10021926927948343656U;
            aOrbiterC = RotL64((aOrbiterC * 18139540407315440909U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9309867875882669289U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14951424455944346337U;
            aOrbiterB = RotL64((aOrbiterB * 10569523948169951309U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2166343974068770659U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11386993629011562026U;
            aOrbiterD = RotL64((aOrbiterD * 3091639433512536097U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5747849744680120960U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4019290369160113026U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 5567515306039646735U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3820540009554769592U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8210747198363020939U;
            aOrbiterE = RotL64((aOrbiterE * 16215133106542452509U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3006494852696036003U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2736305345451919450U;
            aOrbiterK = RotL64((aOrbiterK * 11993452696344358247U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6148431711118275178U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6986633012691940738U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15672039482523804893U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7837859154831245165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17470880031634374199U;
            aOrbiterG = RotL64((aOrbiterG * 2153299273348512243U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterG, 24U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterH, 48U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 3U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
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

void TwistExpander_Lacrosse_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC10558FC40948083ULL + 0x90E6101EC69085CEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFF92316C8EC8FC61ULL + 0xE29EF8327F50BFB1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDA6DFF59E0D9C3F7ULL + 0x891D09D37EB35F8DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC9BC6C6F0F3AA83DULL + 0xDC3958F829F899B4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA92314968E9C18A9ULL + 0x9E057272F0AF2D7AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC18965839CD2B415ULL + 0x81F57311B0D568CDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDB0EAA48C5C6EA71ULL + 0x8CB19DA5635A8A85ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA950BBF12530022BULL + 0x906164A4A5B3BC9DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAA08F9D2816D4B1FULL + 0xEB407E722CF19312ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA118140C466B3395ULL + 0xEC50071E9ABB0B7AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9D331DFE03C4B5E7ULL + 0xEAB1D989FE6CAC11ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB6C0F7A090F13E11ULL + 0xF43B553513390C40ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD94D42BEBE366E2BULL + 0xD417AE6781D02FD6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDDF463A14EEE2107ULL + 0xA02DFD1BB40E9914ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB83ED9DA9C44EA5BULL + 0xC8D31C04D9ABB040ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB88D0EFAA1B85695ULL + 0xF9AE0CA5339A8E5AULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8074U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 5210U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3195U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6442U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 29U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 18U)) + 13174219512651137892U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 2715455762789269341U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 1338018183235594313U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 39U)) + 16566866551729552930U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 53U)) + 6901845297307236726U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 2476078302049201718U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 43U)) + 15531109473927052260U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 4087849380858572351U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 30U)) + RotL64(aCarry, 3U)) + 5167830630098599644U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7275995452428627217U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14794340370010024117U;
            aOrbiterF = RotL64((aOrbiterF * 8779497557416568379U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8509217403041662849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2321522025240806996U;
            aOrbiterA = RotL64((aOrbiterA * 113568101672878697U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5676672952755594051U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2304681269233504384U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8383399721062437300U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13181984036942227666U;
            aOrbiterE = RotL64((aOrbiterE * 1648761328771932069U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13602604532551684210U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12725687663616352843U;
            aOrbiterH = RotL64((aOrbiterH * 4684699861686199753U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5831790822416009806U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4535048543735457407U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12076777878870257053U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10617608605149381858U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5244225377862618630U;
            aOrbiterK = RotL64((aOrbiterK * 15307177251167023999U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18229989093139888456U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9728120630096192811U;
            aOrbiterI = RotL64((aOrbiterI * 16052574428163231023U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1312233443099767304U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8043115602160128619U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9365756845731616963U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 30U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterA, 36U)) + RotL64(aCarry, 21U)) + aNonceWordM) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15575U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9028U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11561U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 9474U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 10U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 56U)) + 9220392006207660113U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 11305018553489132882U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 47U)) + 5860373868073513684U) + aNonceWordN;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 43U)) + 12319586170883987589U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 14072333614354649021U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 24U)) + 9332158529453194608U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 47U)) + 3860569321145958686U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 8119005668901240093U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 13918259792880333239U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6938856216758228704U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3960905839118710604U;
            aOrbiterD = RotL64((aOrbiterD * 16203746868670689793U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6043879193734253929U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15691425268831319195U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7189195135654636271U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14912209933584715274U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16180183395910618923U;
            aOrbiterJ = RotL64((aOrbiterJ * 3942858974766467849U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4966642362507707776U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6962226782462822861U;
            aOrbiterE = RotL64((aOrbiterE * 3647802407741095419U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12409120845092026295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2302946450253872465U;
            aOrbiterF = RotL64((aOrbiterF * 7099576330777297911U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16118304388937163838U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15968419034359049422U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17098982091525008231U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10298979200690822062U;
            aOrbiterC = RotL64((aOrbiterC * 12620028874653521945U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 552826643694256437U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11786560990790695378U;
            aOrbiterK = RotL64((aOrbiterK * 11190309640069208311U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13730399230389329793U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17614226859252305432U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2640019643570222977U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 24U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 56U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 22U)) + aOrbiterD) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18889U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20775U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19881U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22132U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 60U)) + 8975885703279267062U) + aNonceWordB;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 8664844915562660637U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 12281774799736296726U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 15347461352311329726U;
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 12967500561828907834U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 27U)) + 5002833859280402726U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 34U)) + 11908257536954668983U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 51U)) + 17017174811949227162U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 16851323125613931180U) + aNonceWordH;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13469326957728686706U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5228638551056105241U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13369947664646167255U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11945166198089308564U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16268645041872996022U;
            aOrbiterE = RotL64((aOrbiterE * 5391448793718370911U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14781204627695095701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5365325354838101092U;
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 563147416025715953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14660867395395625851U;
            aOrbiterJ = RotL64((aOrbiterJ * 4769458126865307103U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3168989056355712105U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16179131669773665579U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 5641461617066671723U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4160220074225527179U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8597134686962559111U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 639572585431474015U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16811551552456811661U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5827323970423386301U;
            aOrbiterB = RotL64((aOrbiterB * 9328247349730652021U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15583234353262170227U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2950816254621717748U;
            aOrbiterK = RotL64((aOrbiterK * 1102417597476170143U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4426165025104306337U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11871220132164971152U;
            aOrbiterG = RotL64((aOrbiterG * 2366168050042802207U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 58U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 51U)) + aOrbiterE) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterD, 46U));
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aNonceWordD);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28437U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27701U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30649U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26037U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 5U)) + 1364174714924216027U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 19U)) + 13561796874229506613U;
            aOrbiterB = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 11845572344206238305U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 15762708240326773763U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 1157119665207900473U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 11U)) + 6823546624372055260U;
            aOrbiterC = (aWandererB + RotL64(aCross, 51U)) + 14465564210523945121U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 28U)) + 10667464548080807531U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 47U)) + 13445737493224316575U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3009837893785957665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2886920524111083752U;
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10886177449328249656U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15067759884678100433U;
            aOrbiterJ = RotL64((aOrbiterJ * 5724566815989860041U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18307930462682331536U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8791864377579255801U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9265158882471421767U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 805797468642992351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5743305867058244964U;
            aOrbiterD = RotL64((aOrbiterD * 16263000753351131717U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17102025528234481273U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1841579177327486899U;
            aOrbiterK = RotL64((aOrbiterK * 3841603385577825265U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2189493507896508972U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6697069234216868330U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 927471474577415372U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 10680760991009199309U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13155854301197725408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1014625081915435892U;
            aOrbiterG = RotL64((aOrbiterG * 11592754232949990435U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12697209921410914931U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11555096613655648647U;
            aOrbiterF = RotL64((aOrbiterF * 4598821388864997089U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 6U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterF, 42U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 48U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordD);
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

void TwistExpander_Lacrosse_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x87D0E31F7918ADCFULL + 0xAA588A39E589C1A4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBFA4213F23AAC565ULL + 0xD048B26E7B9931BBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC0FA0A3AE19F3FCFULL + 0x8CDF222EA5C32BB3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFA95A6BA3E8FB003ULL + 0x918AF833FF1C6A99ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x879F804B9B05416DULL + 0xDEE0281AED955D85ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD5949931817F9A31ULL + 0x8CCF2967326EC57BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9BA25706416B298FULL + 0x89EC7823F0325783ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF62F6BF8A608AEC3ULL + 0xE7B56EE43370D513ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA9B2536BEDE19CD9ULL + 0x9F1572F060420DBDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFA6A4E1133F1A3F3ULL + 0xDCA7C75099F66F3CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBDC30C0815DB1383ULL + 0xE3FCAC837134AB03ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE04B189C4C3B68F1ULL + 0x9530C5993D736CDCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x88535559F138FD67ULL + 0xC26DED33A38AB356ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB8492AB78B19B283ULL + 0x8B849B9A9A049BFFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB5781AD142F89E4BULL + 0xF78FA7C7EE834AFDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA355987A841276A7ULL + 0xEC5A942EE89DC0DAULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 8091U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7704U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6452U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 2892U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 18U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererA + RotL64(aIngress, 37U)) + 12262991801139086177U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 7963038771924890197U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 15540520327933568896U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 8745565892055020722U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 60U)) + 16619329199683755286U) + aNonceWordN;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 10865705026433867260U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2743368697984518059U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2989232417816919375U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5556006271515473135U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5355833281353498588U;
            aOrbiterF = RotL64((aOrbiterF * 4190140212757841511U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8313616108963479829U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 16657121016801866434U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 331533349428472477U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16532226425013000833U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5800465874932467232U;
            aOrbiterE = RotL64((aOrbiterE * 5966395771690704577U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17882948163883121328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15029375310296563175U;
            aOrbiterB = RotL64((aOrbiterB * 17021415832288477713U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 38U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8343U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15477U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9017U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 8833U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 6654158889644956636U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 9045779659363991870U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 3U)) + 3888897662136993491U;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 24U)) + RotL64(aCarry, 19U)) + 6882016842864459345U) + aNonceWordI;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 35U)) + 15601891715956172291U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 5176811598629335350U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12519945150889074325U;
            aOrbiterD = RotL64((aOrbiterD * 8721098129033306427U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4552583214397603278U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14225482701804864688U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8526052833180466359U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5485298070606280363U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11237713257388094289U;
            aOrbiterA = RotL64((aOrbiterA * 11032429223099413011U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14340345895626142788U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16275167270553643347U;
            aOrbiterC = RotL64((aOrbiterC * 7308578867128951199U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14041860597556520250U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1436068974197066343U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3938460345031496843U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterA, 50U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 4U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22564U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 20035U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24520U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 20575U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 6973892330986118220U) + aNonceWordC;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 21U)) + 9886813896272094864U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 10996306582517553173U) + aNonceWordJ;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 3U)) + 8490648283899856223U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 54U)) + RotL64(aCarry, 41U)) + 105141713530704655U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3114337422810562588U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 980857684690886131U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 17407927633910728721U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6562042345807072665U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15665371138706353619U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8086237578564620623U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18113013571374375028U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17405346422601997299U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11162604605443005253U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5130876096426182506U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 1813821672299154629U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 15478100342425611875U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15793814882743306728U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13925299440495476399U;
            aOrbiterB = RotL64((aOrbiterB * 12049601510660117401U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 4U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aScatter, 42U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U)) + aNonceWordA) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25655U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 31949U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29852U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27378U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 29U)) + 17454559218352016650U) + aNonceWordB;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + 8005709669325164803U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 13393741948412816357U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 3665865624348875553U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 46U)) + RotL64(aCarry, 19U)) + 8334142570031883436U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17226066128706139657U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3319093033121522613U;
            aOrbiterC = RotL64((aOrbiterC * 17961784341097933029U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 6657535603401588798U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5469746182326331147U;
            aOrbiterI = RotL64((aOrbiterI * 11315450342347794329U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17846791786050221418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15939541003714896288U;
            aOrbiterF = RotL64((aOrbiterF * 1400351482213119809U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12076763190461077406U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3594038213596405284U;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8301291631324464622U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8460406137668390582U;
            aOrbiterD = RotL64((aOrbiterD * 9117147929757711595U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aNonceWordM) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 34U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordM);
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

void TwistExpander_Lacrosse_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAD5741AC3A1DD87FULL + 0xD616819378A9DC50ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF9392DFB7E9BFF0FULL + 0xCE49C6122CDAE0ACULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE4476AF8EBFF890BULL + 0xBD10091025B96E5AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCEFE58D9DEF28BEFULL + 0xA21C68B13F5A23A0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9714FE68E206EE45ULL + 0xC49D0C553B3C6997ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x996451E884AB46C3ULL + 0xAE3FE1CB08127678ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDC7F73791D258C4DULL + 0xA9C6C3058BDC8C63ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB53776F7A2EACE77ULL + 0xB25F907E797DF7E9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC42699790AB7218FULL + 0x8CE1520E666F79B2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEA9AF0A8ECAA8D59ULL + 0xAA88E1D04A7303DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9D3DFF15610E60D5ULL + 0xE19B0B802CEE65A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD795A604A7EA2BA3ULL + 0x9A15B05624A3FC9AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD381C9AAA6F8C755ULL + 0x8F3FB6A7C8D153B5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xED57E22984BF9C9FULL + 0x82FC1DB7A03DC48EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD4822D18A3804A41ULL + 0xBAE9B9E59B81737CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDE62C5D6C603343BULL + 0xADA888EB05039097ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 651U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7746U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7499U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 823U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 41U)) + 5576732410244514238U) + aNonceWordE;
            aOrbiterC = (aWandererK + RotL64(aScatter, 57U)) + 2833808925935929629U;
            aOrbiterG = (aWandererD + RotL64(aCross, 47U)) + 3670188682914544792U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 3U)) + 15759072378887814995U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 24U)) + RotL64(aCarry, 53U)) + 13934007231137439994U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 11022225696007690512U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 16989177104453635790U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9256930045263527091U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17788596104417068290U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 675554110563253305U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17044369456673337625U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1310908395523250343U;
            aOrbiterD = RotL64((aOrbiterD * 16305084373037705921U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12067065689034065422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15130844248737512262U;
            aOrbiterA = RotL64((aOrbiterA * 9409499577465934107U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14532689204495587494U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8198147292120244178U;
            aOrbiterB = RotL64((aOrbiterB * 1418356389507740991U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 5485494458627163347U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10830008207150307611U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6526039534042499457U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17770065502486618029U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6397859353395335459U;
            aOrbiterK = RotL64((aOrbiterK * 14286997752368893825U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5128700697381508319U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7103394110057060499U;
            aOrbiterC = RotL64((aOrbiterC * 5053680689949149633U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 21U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 46U)) + aOrbiterG);
            aWandererD = aWandererD + (((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 5U)) + aNonceWordH) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 46U) + RotL64(aOrbiterC, 39U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13939U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 10081U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8734U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 13118U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 12131317914288566437U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 57U)) + 5672805657999385496U) + aNonceWordH;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 21U)) + 3581710244233124197U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 5U)) + 15251296040538489436U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 37U)) + 11295008604679904153U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 2230897493419504490U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 19U)) + 7109600123297458999U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13119156643107683803U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14755160867807355250U;
            aOrbiterJ = RotL64((aOrbiterJ * 10007087518844899239U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16829363373287496832U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5394974422201576627U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8806000776958603317U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16810923047720876014U;
            aOrbiterH = RotL64((aOrbiterH * 17872735050219539145U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8129657889554436328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8653100378491974463U;
            aOrbiterD = RotL64((aOrbiterD * 11395283153912468661U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17048985838727432415U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10892675550889823573U;
            aOrbiterG = RotL64((aOrbiterG * 976298937314081913U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15960158965421254346U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12290011578634850001U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9280475585104357745U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16265047040311479093U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10312956912303656248U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 22U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20188U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 22279U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17470U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20073U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 43U)) + 11210042748013785976U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 4584747303233477454U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + 8878765929792969517U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 2172232330280041122U;
            aOrbiterE = ((((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 8378937026022264016U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 28U)) + 8683007464695824208U) + aNonceWordK;
            aOrbiterD = (aWandererG + RotL64(aIngress, 3U)) + 9564352997357118134U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11713878436769887528U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8052917623074021077U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7450115139081623477U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7720597162792145185U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2602847785328475621U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 14065077077207224525U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17813669222300509724U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8724263063156573013U;
            aOrbiterJ = RotL64((aOrbiterJ * 3632927017737834359U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6882429835961613492U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13213313479525717359U;
            aOrbiterB = RotL64((aOrbiterB * 2411431247725974895U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2401526093648669573U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3616448566579979749U;
            aOrbiterE = RotL64((aOrbiterE * 13323155103752121393U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18268262471839710401U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5116424918948694752U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7641143782996332069U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11405305689555640431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12427591396711015574U;
            aOrbiterD = RotL64((aOrbiterD * 8112834135715541223U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 22U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 53U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27196U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25902U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28239U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 31537U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 12U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 30U)) + 17019646486641172469U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 13U)) + 12276141179299971572U) + aNonceWordB;
            aOrbiterI = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 3617241694029841555U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 23U)) + 6967963401259371737U) + aNonceWordN;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 6340709284279891017U) + aNonceWordO;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 456065368903896482U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 17686765719908116203U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1322045955429785736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5163772703302372887U;
            aOrbiterI = RotL64((aOrbiterI * 3193272189179082313U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13268431135020363252U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6538789950366849332U;
            aOrbiterA = RotL64((aOrbiterA * 5352960308459065837U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10390344544314544893U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5087084271300584267U;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13423071121590981727U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15814349432207734533U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4129091815978464507U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17024797553831962245U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3137753479364378175U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6501545108779991661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4667298703308315851U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6315980380900062127U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 12080555704907924637U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 29U)) + aNonceWordL) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 60U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Lacrosse_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF32592500F47CC2DULL + 0xBE3CE0F845D2AF58ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE2E8AA7DF0DA67FBULL + 0xBCCABE24C71B06F0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9692018096BAD533ULL + 0x8A0056F0E4440951ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x92CE14D57789E951ULL + 0xDBF0DC12F6A87532ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x895C6BD4AB64FDE7ULL + 0xDF628A7832BC5019ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA07E0EBF3F116B3DULL + 0xA511393B18D39960ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC3E9A45F0F5F6129ULL + 0xBAA239FCCFB9C3FDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC5526577EEB8F127ULL + 0xB8FEBDB9B934AB07ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9A00AA8152BABB51ULL + 0xD6EF765FE8C636FEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD657D8024640B931ULL + 0x86FD14E83B9C5B5CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x818B086CE068A001ULL + 0xEC5D03F5A12AE67FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD44E3823B83C17CBULL + 0xFF4091E733BCB333ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA1A9CBF4563E4B13ULL + 0x8797F1A6DD263171ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB8C40CAAAB7B315BULL + 0xDBE1F1D1064CE6B2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB75849FA719BFFD3ULL + 0xBE056C232ED6D907ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE19855B903E2C0BFULL + 0xB95D4337C7455EEAULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6249U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2962U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7612U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 4393U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 11521331427196538632U;
            aOrbiterH = (aWandererE + RotL64(aCross, 3U)) + 16653824187682957632U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 19U)) + 11654676587350088289U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 8010313317412193584U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 1108775560502907471U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 243952321439823521U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 26U)) + 2324945800401240403U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9257554497543369657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16701314607244592540U;
            aOrbiterG = RotL64((aOrbiterG * 8790054741039817107U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3900445848034341782U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 7652316487347103658U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 11480123491361589799U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14980368605272070578U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2001165460948764796U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8110980921827107649U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1911044015666991050U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11366207111147818339U;
            aOrbiterE = RotL64((aOrbiterE * 17234439040652553865U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16469329744002456607U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8062793687044950815U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5856142259851144369U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15364721421972807872U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8979915611483540231U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 10899377466171153383U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7654234623563110457U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1526832460342135008U;
            aOrbiterH = RotL64((aOrbiterH * 12766083052650723051U), 19U);
            //
            aIngress = RotL64(aOrbiterJ, 42U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 14U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 41U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10618U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 16273U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9239U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8680U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 3U)) + 16451272412693907816U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 10099485419723255462U) + aNonceWordF;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 53U)) + 17668900099534923192U) + aNonceWordH;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 5497093724143181753U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 35U)) + 10354044773550071706U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 12728258851198019099U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 26U)) + 4144050505314242618U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14133805325480076530U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 308863673210602899U;
            aOrbiterC = RotL64((aOrbiterC * 2672613556981540433U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11741180130160569753U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12926863156769180448U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 9726030996091054939U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 211920854786494259U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13234608842479411078U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2556747209733759467U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9164711974854618892U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6667377062281954219U;
            aOrbiterE = RotL64((aOrbiterE * 2603737166987437649U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4559040002406721850U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1749875480850675109U) ^ aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15822640067349481089U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9555365165561936366U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 18289733999504213574U;
            aOrbiterB = RotL64((aOrbiterB * 14156217554673229429U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8727162691639622461U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 291406782452963706U;
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterH, 14U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20138U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 16608U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20457U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 20431U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 5088525177670191619U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 9966456257813932112U) + aNonceWordP;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 7707646574027146307U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 75480203757681173U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 35U)) + 384659134071835163U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 51U)) + 3158769775373307778U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 13U)) + 17360830943513941272U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5317278822721604586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1371427105215954781U;
            aOrbiterD = RotL64((aOrbiterD * 10956603063464438611U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3162710551223553423U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5332921933853550756U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11709546145149357887U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10572462410297815854U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10234389605554817892U;
            aOrbiterB = RotL64((aOrbiterB * 2130374833440291193U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13421365517991380605U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10186643614984034083U;
            aOrbiterH = RotL64((aOrbiterH * 8554471709467808453U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4742438973260817120U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6081590345899008846U;
            aOrbiterC = RotL64((aOrbiterC * 7069396301823124931U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15360092808493795340U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12186413069553132646U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 3815981440611914267U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16756221656224451552U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12232880965861373143U;
            aOrbiterE = RotL64((aOrbiterE * 14196910735715726471U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterD, 50U));
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27221U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28908U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30217U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27546U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 12U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 15549114274303128055U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 53U)) + 16466750056388063241U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 12209449840836787142U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 14551496099734294336U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 6266576428679808622U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 60U)) + 16892841575635668152U) + aNonceWordN;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 47U)) + 7375966221423362125U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11926105302821753530U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16219253791550461124U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 2117550758226173419U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7299056065319248160U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15234001484933728439U;
            aOrbiterA = RotL64((aOrbiterA * 8182244796017018911U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6615802589932632120U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5481176858895819247U;
            aOrbiterH = RotL64((aOrbiterH * 3604590158551984877U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17220507586542139380U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14137921473739415340U;
            aOrbiterF = RotL64((aOrbiterF * 10634645686035907603U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16981960446540932787U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10897565927079518588U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 2746889569299593263U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4894117146736361379U;
            aOrbiterJ = RotL64((aOrbiterJ * 2656750612042673191U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 18294823016957137777U) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 86828501068883383U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 11432686669235402365U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 58U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + aNonceWordP) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Lacrosse_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA86E6083DC3D3DB3ULL + 0xCC4C731EECA1EE32ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA406F8E75542AA7FULL + 0xE529BB8DF828CD67ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x92AB35F4D9F6375DULL + 0xB8BF96EEFEF04C8CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA20382F3F732972DULL + 0xCF6D0C2FB68D411CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x846CD0E86BD8FE65ULL + 0x82CC7D3215FAE6BEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBD64482C3353134BULL + 0x8F224C0B45D39D14ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE2AD032D771F940BULL + 0xD2B02C44CD7B74F4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD5EE47B788A7841FULL + 0x81250E27A9570DAFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF1F9FAFBCEBA1423ULL + 0xF630BBE4A7F030B7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD08738495ACDEBA1ULL + 0x951628A02241C6F0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEA3E7BD494014BB3ULL + 0xEB5DBF555DF28BCEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB4FF385A71F620FFULL + 0xE4F7CD07D9622509ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC177CAEFF4146A6DULL + 0x9E12D34CBD00DFC0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8714D042EA9814CFULL + 0xDDF404CA573AE3EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD56629D4815D0029ULL + 0x95045142FB23E11EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x98D7CFC9F89FA691ULL + 0x8476C568A9C23E83ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 621U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7455U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4077U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3973U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 27U)) + 7722279280863371124U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 30U)) + 11584220561732385598U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 47U)) + 7834679350105534657U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 5U)) + 11347994382444180879U;
            aOrbiterK = (aWandererH + RotL64(aCross, 13U)) + 9449903188047063431U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 21U)) + 6516243976652795170U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 11U)) + 8420815253991184777U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 36U)) + RotL64(aCarry, 47U)) + 9081386852515170937U) + aNonceWordG;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 3U)) + 14375955191735286867U) + aNonceWordE;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 880757589768436072U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 3349856625725164229U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7826309957607577207U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8057435761214313635U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4718430712767038607U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9565237500443303103U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15893066735310588501U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3276844534476430842U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6828644383891274120U;
            aOrbiterE = RotL64((aOrbiterE * 979580351653410157U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2815676923011504251U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5030251870850928417U;
            aOrbiterD = RotL64((aOrbiterD * 7075653570570819253U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13464083008377887034U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8994560761846897590U;
            aOrbiterF = RotL64((aOrbiterF * 9892839554658865143U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 8398813387154468736U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8136429428340910892U;
            aOrbiterA = RotL64((aOrbiterA * 3348811490733577295U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 418587250696862341U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4111667833838312094U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 860949442143849147U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6075478294190926371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2208124955874142264U;
            aOrbiterB = RotL64((aOrbiterB * 15741988616251072075U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4726538724576443010U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6524078248882840425U;
            aOrbiterK = RotL64((aOrbiterK * 9784875566721689069U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 14521003220464811621U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16916247868211621303U;
            aOrbiterJ = RotL64((aOrbiterJ * 1911638054294853877U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18207293125461843123U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7722279280863371124U;
            aOrbiterC = RotL64((aOrbiterC * 14303108475807941791U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 58U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + aNonceWordD);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 48U)) + aOrbiterK) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 26U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10391U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10442U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11372U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11015U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 37U)) + 9471546960258473684U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 58U)) + 18050235435948942244U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 3005107102671544641U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 53U)) + 17898396434573801850U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 3U)) + 15071602525497771648U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 5780119462702672108U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 11U)) + 13301326224151025687U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 27U)) + 18129323022260575961U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 1199228670638790709U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 39U)) + 1839199978088021020U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aWandererI + RotL64(aIngress, 23U)) + 4999517042246790165U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8788607633376516299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15143903839930468749U;
            aOrbiterE = RotL64((aOrbiterE * 12735914889325422675U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16674732686428431869U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15908873150953195581U;
            aOrbiterJ = RotL64((aOrbiterJ * 18049755517524334107U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11204775359756474667U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2525984309543939465U;
            aOrbiterA = RotL64((aOrbiterA * 3988529812023791571U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4566345170476825512U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14876612901557406267U;
            aOrbiterG = RotL64((aOrbiterG * 9047956948845135339U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14926290877038883931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12710203178186614846U;
            aOrbiterK = RotL64((aOrbiterK * 14841163494801662515U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7315094513967387996U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11050116830482816766U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3702999495721152019U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4505368486032503953U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17905748055257551092U;
            aOrbiterC = RotL64((aOrbiterC * 14775870175093453197U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5728886950801376350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17998141690182325170U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 16008599930125391379U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4325978018819134558U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13526905108565989379U;
            aOrbiterH = RotL64((aOrbiterH * 14121321495714166291U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10597169665474269506U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7500801022830471869U;
            aOrbiterI = RotL64((aOrbiterI * 3702717219742363777U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17063616328548689935U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9471546960258473684U;
            aOrbiterD = RotL64((aOrbiterD * 3029748230803396737U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterD, 26U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22030U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 20137U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16536U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((aIndex + 18937U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererF + RotL64(aCross, 46U)) + 13854738573712660276U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererE + RotL64(aScatter, 23U)) + 16835460633412286294U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 6785859293758091931U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 27U)) + 126317283127992659U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 5U)) + 7568963536291415413U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 48U)) + 12294016745653004819U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 18269588932920281147U) + aNonceWordL;
            aOrbiterH = (aWandererC + RotL64(aIngress, 37U)) + 5872406424994751026U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 7764434758831474129U) + aNonceWordN;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 43U)) + 4804168969415573371U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 959601763507651280U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 9257644462479293048U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14332699366894494579U;
            aOrbiterK = RotL64((aOrbiterK * 8829304078930625541U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10487012596470786004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 612729229562321440U;
            aOrbiterD = RotL64((aOrbiterD * 11380387280507726003U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7845523921295625315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12742115479740024747U;
            aOrbiterF = RotL64((aOrbiterF * 15578543510683986421U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10294667720904610944U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14369711143154904567U;
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10918344717497681894U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18136794828308636957U;
            aOrbiterH = RotL64((aOrbiterH * 17899418637978002409U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14378638206724886404U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7077588188450008059U;
            aOrbiterE = RotL64((aOrbiterE * 485375960462924335U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8941870012851971932U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15242087859620352399U;
            aOrbiterI = RotL64((aOrbiterI * 4963002810455992839U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10395280254030875387U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6826595516076975980U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6198886240333178001U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10407910809564430664U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6368255889263255730U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3809496492809859731U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6365669830464231626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 596785214258266904U;
            aOrbiterJ = RotL64((aOrbiterJ * 6338109335634389561U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4807438574488830717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13854738573712660276U;
            aOrbiterG = RotL64((aOrbiterG * 6954368463489446551U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 10U) + aOrbiterC) + RotL64(aOrbiterJ, 30U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 42U));
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25085U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 29803U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26291U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25741U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 20U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererE + RotL64(aCross, 43U)) + 15036852811491820366U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererA + RotL64(aIngress, 27U)) + 305637140752898475U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 3U)) + 11948631574496129610U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 5321623592482991426U;
            aOrbiterC = (aWandererH + RotL64(aCross, 60U)) + 4075270159062690728U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 15111580500356908928U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 11U)) + 7244150695504160363U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 53U)) + 5131563519577488862U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 6U)) + 5881954992088651371U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 12780935808751507998U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 29U)) + 12599159643925470226U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9466589929741834066U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6093158735705189789U;
            aOrbiterJ = RotL64((aOrbiterJ * 7453778295800853653U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17461243886150519249U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15456408913739900718U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16093292401746174671U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11260643903290392780U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7870342756041882616U;
            aOrbiterD = RotL64((aOrbiterD * 2431528656086173419U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 134484990005888936U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10626896209992890407U;
            aOrbiterA = RotL64((aOrbiterA * 12034131076645285597U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14031164129515132292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1771835705730244212U;
            aOrbiterB = RotL64((aOrbiterB * 186981668443596623U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16395472745067254664U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1455944290845294254U;
            aOrbiterK = RotL64((aOrbiterK * 6757824754363319079U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17866422769075350837U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10226884082632410805U;
            aOrbiterE = RotL64((aOrbiterE * 206035536985843815U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14474587247775371703U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8501763445324525303U;
            aOrbiterG = RotL64((aOrbiterG * 5298694643596784007U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 222650368553738561U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3901452368735982094U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18347115513126660483U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3063093906728331146U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9026710562384443411U;
            aOrbiterI = RotL64((aOrbiterI * 8411243802199203035U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11282041925238364080U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 15036852811491820366U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 18185121326941087841U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 22U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 40U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterB, 30U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 28U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Lacrosse_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD581D1FA71E8F5AFULL + 0xF32A727E7AF2FD7DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE226483D4686E019ULL + 0x8FE4FA75E68B1229ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFDC320F355167B17ULL + 0xA204CBD190058CFBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCA431F655E935F9DULL + 0xA747FEDEE15386A7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC1C9B83E692A29B1ULL + 0xC3D8B7252BA957D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD9177C0C5B04BD69ULL + 0xC10EC697195172C9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98F602835F45D7B1ULL + 0xF5DEF603AC1EF603ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE81305349F6E18A7ULL + 0xB8F1F97EE97F09F2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA3BF5188EA157FEBULL + 0xEE84E0CD354267A9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xABA52835A51C780FULL + 0xDCA298EFF3B70E61ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB98D6D88C87E7C15ULL + 0xE11AF2E4CA1393CEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD055F6D480FD929DULL + 0xA88D9613728266F6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD7091C455E7CEE7BULL + 0xCB3F20E94E075BC5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x99983393D9F6594BULL + 0xDAE60F22F0B4A6A0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD58D51DE97B20979ULL + 0x997FBA77F4E5426BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBB2EF1C67E486683ULL + 0x939374C4CCD4F337ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2237U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4644U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2371U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3073U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 39U)) + 11410829607777684449U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + 7502698839700975347U) + aNonceWordK;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 50U)) + 13267685058252106173U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 238242706996630625U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 8184695499511454281U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 12767823220461985403U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 28U)) + 12293198423143850330U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 11149495229952495939U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + 7556992689338382800U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3431338808774134649U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16863099140844995099U;
            aOrbiterF = RotL64((aOrbiterF * 752376661101787919U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17872458049880677604U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16760153457252546974U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3115544493537438408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4359882942759752958U;
            aOrbiterK = RotL64((aOrbiterK * 561477566995575801U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13387113067202396536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12955690074544490161U;
            aOrbiterI = RotL64((aOrbiterI * 12449941770827974511U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15614054443728226807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1939441328066616114U;
            aOrbiterH = RotL64((aOrbiterH * 4484917074808974359U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4599016263007782537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9962305629016158048U;
            aOrbiterB = RotL64((aOrbiterB * 1496184427500037279U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8428467674122750557U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3938884087806393439U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 12810531094050481761U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6018636830758044658U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1510372000641305416U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9002834928626918247U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17592782466215337843U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8119921507606870360U;
            aOrbiterD = RotL64((aOrbiterD * 1299795061644535485U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 6U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 40U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6948U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10600U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10196U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 6577U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 18191288703716505885U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 5U)) + 9824014524910417136U) + aNonceWordH;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 11953012029254917548U) + aNonceWordA;
            aOrbiterH = (aWandererK + RotL64(aScatter, 13U)) + 6297568011027199089U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 37U)) + 2576999400457367975U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 47U)) + 13176139160575558254U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 9978408174563621810U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 60U)) + 16765834875061607142U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 43U)) + 16534507305459121344U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 3114710944346151807U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10240517868726718592U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 4645691562915606463U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10721450637990777883U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16689590768796583952U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3046344179729901637U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2427422768928450209U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13495584061816457831U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6670984773768885119U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7058636403765106682U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9897341853944713767U;
            aOrbiterJ = RotL64((aOrbiterJ * 14286816859999869231U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17749559755733386064U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12515645083926326659U;
            aOrbiterG = RotL64((aOrbiterG * 6582878478865838245U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2625692458813609962U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10596240255026143019U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 11605800195771080135U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12374290338067865540U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1507386663796330249U;
            aOrbiterH = RotL64((aOrbiterH * 1210241080424446087U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9288099549484146726U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15159312464747000702U;
            aOrbiterI = RotL64((aOrbiterI * 500055502081347757U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14998608679505446229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17625038109437732009U;
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 4U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11313U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13235U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12033U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14167U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 52U)) + 3238389262925516513U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 12381787182611386995U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 5U)) + 7883885539305181549U;
            aOrbiterK = ((((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 1185413044597727092U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 15219353497204773135U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 7533774715626734082U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 23U)) + 2599930450937763464U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 29U)) + 16074720663961214284U) + aNonceWordJ;
            aOrbiterC = (aWandererF + RotL64(aCross, 12U)) + 15483613196360051221U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9396557867081376268U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9668459976852660245U;
            aOrbiterB = RotL64((aOrbiterB * 11748505665890567063U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9037269914643207212U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16936742640861088240U;
            aOrbiterJ = RotL64((aOrbiterJ * 1040172193161012227U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 16481274825758546398U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 481851372837611166U;
            aOrbiterK = RotL64((aOrbiterK * 2225030139210599207U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13608921517203544108U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16930740723286214636U;
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 902242902582149908U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1510861213079342977U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3309753895727400707U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7116243600304980310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6631412278359709602U;
            aOrbiterE = RotL64((aOrbiterE * 11452627691392637463U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9246698682265275165U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8594373032014031450U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2550138341089957033U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15912837963877821048U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11404583513022627609U;
            aOrbiterG = RotL64((aOrbiterG * 17715204726760125357U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17295214920690244319U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 18315664494984189344U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 17398893532076312945U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 24U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterG, 60U)) + aOrbiterB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 53U)) + aOrbiterC) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 30U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17384U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 21784U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18486U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 21344U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 54U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 44U)) + RotL64(aCarry, 19U)) + 11039986441331892533U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 23U)) + 6256024955965426119U;
            aOrbiterH = (aWandererK + RotL64(aCross, 53U)) + 9857443189988995666U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 3U)) + 11900944813380998208U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 11U)) + 8422577734978875541U) + aNonceWordF;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 35U)) + 3100835100713928724U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 40U)) + 11871553509810206993U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 17614749493763417027U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 3638372131856199916U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6582275259281025770U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 17016882418498941958U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4269869255230867823U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1747214688658984715U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9356088987044015278U;
            aOrbiterE = RotL64((aOrbiterE * 16221733545319753695U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4056238112133473456U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16013150119949532998U;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16076621211111834889U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9940824359571581765U;
            aOrbiterF = RotL64((aOrbiterF * 11624767861336495331U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15624084004784515753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7630989544834680335U;
            aOrbiterA = RotL64((aOrbiterA * 12261063237156822067U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18003586430673313786U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1654118743290334161U;
            aOrbiterG = RotL64((aOrbiterG * 1153250137357176071U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3254189676528343910U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15629083361573065165U;
            aOrbiterI = RotL64((aOrbiterI * 17024833368570949107U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10056859810555674806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15976683222786846254U;
            aOrbiterJ = RotL64((aOrbiterJ * 2801754232182942635U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11872378594829637933U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7633773773528713489U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8218288492011593353U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterA, 58U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 42U)) + aOrbiterA) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterI) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23446U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 25028U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24854U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24061U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 36U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aCross, 52U)) + RotL64(aCarry, 39U)) + 6521330037475130256U) + aNonceWordO;
            aOrbiterK = (aWandererI + RotL64(aScatter, 27U)) + 12611880456055428940U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 39U)) + 12061611078130934708U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 1558112410801116984U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 10509115227850160786U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + 4045915960688792066U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 3U)) + 1196541286513243082U) + aNonceWordG;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 43U)) + 15564991032722373702U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererH + RotL64(aIngress, 34U)) + 4897765238703641798U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12327429514907752733U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6189189797708711636U;
            aOrbiterI = RotL64((aOrbiterI * 9017615866338877651U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6374267075282018852U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 74387714918264257U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14956857689299491800U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14879361107223331957U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 9166712966729591953U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16086885494838105042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterH = RotL64((aOrbiterH * 8878470736758734353U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10854345917959911439U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7078313614360332089U;
            aOrbiterA = RotL64((aOrbiterA * 9864025732292844871U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15083669236062255011U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 594879695916679116U;
            aOrbiterB = RotL64((aOrbiterB * 9852515479152735283U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6721466068234534523U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 475816724162626782U;
            aOrbiterD = RotL64((aOrbiterD * 4799725182757588407U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4341655358154605899U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15477254302340298586U;
            aOrbiterK = RotL64((aOrbiterK * 13961520225881974201U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10179091913200895775U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6310490897546909571U;
            aOrbiterE = RotL64((aOrbiterE * 15080621088825477613U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 22U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 40U) + RotL64(aOrbiterH, 27U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 40U)) + aOrbiterB) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29160U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 29308U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28391U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30213U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 3U)) + 13960289014350612206U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 3483331015269589730U) + aNonceWordO;
            aOrbiterB = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 6873299241002444518U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 39U)) + 3562094007125534229U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 48U)) + 11422367439932782705U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 35U)) + 532453428514259816U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 17810941465810193088U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 57U)) + 11869759058631106331U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 14U)) + 8837581071876177566U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17185378327053837778U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7578253375676981500U;
            aOrbiterB = RotL64((aOrbiterB * 13371647568758721729U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 17112646434432814442U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14949096407295697881U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4259590620758467836U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6534899413644542303U;
            aOrbiterI = RotL64((aOrbiterI * 7987609419215568661U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2637407498893694243U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterK = RotL64((aOrbiterK * 5202015597375051399U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6373559542002699718U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11694562937392022505U;
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3308736483775453062U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12749929710650475901U;
            aOrbiterH = RotL64((aOrbiterH * 248428400724560945U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1569528215675579656U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1044077933631689572U;
            aOrbiterG = RotL64((aOrbiterG * 6443796233912755143U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8393422728124537471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2002732612516530754U;
            aOrbiterJ = RotL64((aOrbiterJ * 13702146823622364279U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13469191942843147943U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7633171368709520560U;
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 58U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 38U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 12U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Lacrosse_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC48C0476AF0EFBC1ULL + 0xFB8D9833A4DC3F4CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8196BC64A2DB8BF9ULL + 0xFBF9F98F83F23905ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF53CDA2B92EC68D1ULL + 0x8098D1B53511458CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E0778A321E90C97ULL + 0x9760D2FC0B1B1E1BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x819A2393070195D7ULL + 0x9BA6507D5CA9EB7EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEFCF4C436F31830DULL + 0xD01B8E8E23777AD3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9343389D0E57D02FULL + 0xFAC53D0D26C6D8EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9689413FE2BD4C6FULL + 0xBC8D87F68139FBDDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDAFAE49D0E495923ULL + 0xFEE76B9CCD8D248CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD6CEE480818B4949ULL + 0xDD6D37702FDB92B8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAFE594A1BF71A309ULL + 0xE98B23495EFB302BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x969EB4F371189A1FULL + 0x80B4615BBED2DC95ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9F1FCC986016E8B1ULL + 0x88363B484B82AFD3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC5ED53180491D89BULL + 0xF65231650B3E954BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9DC59E4AEF9BD147ULL + 0xB4533B0A1375C287ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCD534544CE657023ULL + 0xB85B001DD7B4FCB5ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3349U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 4027U)) & W_KEY1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2388U)) & W_KEY1], 14U) ^ RotL64(mSource[((aIndex + 181U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 13915875634607599122U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 1695770381382411673U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 40U)) + 3709105579778295511U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 7673376335333251804U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 47U)) + 8814147709738503518U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 21U)) + 13451412605350381172U) + aNonceWordL;
            aOrbiterC = (aWandererK + RotL64(aCross, 5U)) + 6447870234069609538U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13419487997946496825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5478309847615220345U;
            aOrbiterD = RotL64((aOrbiterD * 12953043149543448765U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3635184969215610049U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12527903812035294828U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 12540800512035534967U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1684685110885338814U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12860354576326835090U;
            aOrbiterE = RotL64((aOrbiterE * 12743745087733307255U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9081823570147481835U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14369321778210049109U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17865953349448767035U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 11518132079084873250U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterG = RotL64((aOrbiterG * 15751374986135615095U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7084079180579206226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2999676609847603277U;
            aOrbiterB = RotL64((aOrbiterB * 14602698397511266403U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 17683445810614029153U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11576460512964896969U;
            aOrbiterF = RotL64((aOrbiterF * 5243651036457051155U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + aNonceWordO) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + aNonceWordG);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9727U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((aIndex + 6557U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6487U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9482U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 5295352595333316211U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 2341795367042042605U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 10122175780504033663U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 23U)) + 10084612804696198554U) + aNonceWordM;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 43U)) + 16470424309851045971U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 13U)) + 656016130975227994U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 60U)) + 15313268829659834317U) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3795220914993923394U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14044442220988813825U;
            aOrbiterB = RotL64((aOrbiterB * 3270650852546606835U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3804224626734584802U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7980006306010255693U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13958505239726088561U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13746830564584711549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11852212099729274845U;
            aOrbiterE = RotL64((aOrbiterE * 2164880979318247855U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9083223471018084847U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13706723820703853346U;
            aOrbiterG = RotL64((aOrbiterG * 11361854103656219887U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1713819986642275223U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1382000168233902914U;
            aOrbiterK = RotL64((aOrbiterK * 3894160765130198157U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4540474625764565485U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1756168174375757220U;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1409297070183609309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6082750101445444357U;
            aOrbiterI = RotL64((aOrbiterI * 17438740230251860935U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 48U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterB, 28U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13913U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14167U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15487U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 12772U)) & W_KEY1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 4476099022490972343U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 16836423700375760429U) + aNonceWordP;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 8850577488928703557U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 4U)) + 7091631824560042743U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 51U)) + 12560498899956759494U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 35U)) + 7797973377112012161U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = ((aWandererE + RotL64(aCross, 13U)) + 6173820673874805794U) + aNonceWordB;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10805025132310245348U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7139216143268029968U;
            aOrbiterH = RotL64((aOrbiterH * 8349754682635765573U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8241544862261635722U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 4735527016563596150U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6621354217673598381U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5166171126690294033U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11117641762075368393U;
            aOrbiterC = RotL64((aOrbiterC * 4980156869201219393U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6312932356458415421U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1304139291184508668U;
            aOrbiterD = RotL64((aOrbiterD * 90744653170922319U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10085025354842771067U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16745854428789531080U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1945983905747274355U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2497187958708890337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16069701876646548995U;
            aOrbiterJ = RotL64((aOrbiterJ * 16606039730973709495U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17242004368025978091U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12334315722243232121U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aCross, 20U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 4U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17147U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20947U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17728U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 17134U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 54U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 5U)) + 12426357877879529292U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 21U)) + 12604900366173639176U;
            aOrbiterF = (aWandererE + RotL64(aCross, 35U)) + 13511119007338929401U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 9878720081166788060U;
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 15463195409806395076U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 6407922778852833423U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 14U)) + 7690427254160734016U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18030974031722143619U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17983938038322737041U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 12479365337221685413U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16605512170117753884U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 681802273302348322U;
            aOrbiterI = RotL64((aOrbiterI * 14608920184802647123U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15550312921312083819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterE = RotL64((aOrbiterE * 7358612830654795357U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1939207786756735430U) + aNonceWordN;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 3132864634777826569U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 13606281919426730325U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12822929773923954849U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16576106045887115660U;
            aOrbiterC = RotL64((aOrbiterC * 16370914370769903051U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2398825881649235260U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13700821892926092479U;
            aOrbiterJ = RotL64((aOrbiterJ * 10830623703416956043U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2439833784883391606U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15870638514107637833U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3797380922767479287U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 34U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26596U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 26909U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22012U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 26547U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 51U)) + 11210042748013785976U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 3U)) + 4584747303233477454U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 8878765929792969517U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 19U)) + 2172232330280041122U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 27U)) + 8378937026022264016U) + aPhaseAOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererE + RotL64(aCross, 34U)) + RotL64(aCarry, 5U)) + 8683007464695824208U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 9564352997357118134U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11713878436769887528U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8052917623074021077U;
            aOrbiterF = RotL64((aOrbiterF * 7450115139081623477U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7720597162792145185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2602847785328475621U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065077077207224525U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17813669222300509724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8724263063156573013U;
            aOrbiterD = RotL64((aOrbiterD * 3632927017737834359U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6882429835961613492U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13213313479525717359U;
            aOrbiterC = RotL64((aOrbiterC * 2411431247725974895U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2401526093648669573U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3616448566579979749U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13323155103752121393U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18268262471839710401U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5116424918948694752U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 7641143782996332069U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11405305689555640431U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12427591396711015574U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8112834135715541223U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterF, 23U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 6U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28061U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32313U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31996U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 31652U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 10U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 1898718075389870739U) + aNonceWordK;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 5631794889237247403U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 18219714659484524607U) + aNonceWordN;
            aOrbiterC = ((aWandererK + RotL64(aCross, 3U)) + 15419581386225732921U) + aPhaseAOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 58U)) + 9125575431710198210U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 12205871520544965505U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 19U)) + 7617534300497343422U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18017579105368135814U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10693882161946020042U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 2326507900303932855U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11669615701700895306U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11045110212889232165U;
            aOrbiterE = RotL64((aOrbiterE * 5965171269273719849U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18019107802806469913U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12315940560472528716U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4505122470351404065U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4899009736070044310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17412253404253730364U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10791901166391946485U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4826286251927854181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4523455921321845084U;
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4132514462154182215U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7164745605985109269U;
            aOrbiterC = RotL64((aOrbiterC * 14107325508977225261U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6297434295807635654U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8813887638672996646U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 17495632530773158201U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + aNonceWordH) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 58U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererE, 18U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEA3720A6E93038B1ULL + 0x98899F11BDE78CDFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCB8A3BC661F8F2C9ULL + 0xA5174F020E2292C5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAE5DE1161299F055ULL + 0xD17E7AA4C7F81C1CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB4E56D08E72D56BULL + 0xB227F5EA764CCD18ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF50195B97FB293DDULL + 0xF956DAE1443CE445ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC66ED1D8DF95FE19ULL + 0xE03BAA406C3E12E2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBF2813CA9CDCF59BULL + 0xD859FEF34689CE35ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDA3B6DB06B8C8BBFULL + 0xEEE4682143F96E82ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC9CF61DD6C3F0433ULL + 0xAE791166077EF267ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBB9C641E1433194BULL + 0xEB56C1B53A9C987DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC943FF38B28AF9FFULL + 0xCBA3AC2AD70BDDB9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8F99C6314B13F2F3ULL + 0xE81123E40E35CFFDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x882A3F2D712FFFDFULL + 0xFD3333764E9A1271ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCC4EB55DA5C8995DULL + 0xC75D8F284C3E02C3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBFA1675963F4B735ULL + 0x9FC2AB090039D123ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEA602D8BAA4DFDD3ULL + 0xBDB7DD9AD83C542BULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1187U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 1431U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2859U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 1430U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 10U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 29U)) + 17074147006464019918U;
            aOrbiterK = ((((aWandererK + RotL64(aCross, 4U)) + RotL64(aCarry, 29U)) + 10559516626129419928U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 13280363679503946221U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 17657115422132457413U;
            aOrbiterB = (aWandererA + RotL64(aCross, 13U)) + 13325837013304973008U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3059707750486106037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4529045702503050852U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 12889277842182219673U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10726578475550904292U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14832537837996659885U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 808060368961520519U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 220094417441809246U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15343130035105342194U;
            aOrbiterI = RotL64((aOrbiterI * 7984652435043810845U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16592263353426409884U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15649290906447931918U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8405875177836650731U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11437410545843708269U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5859769136073011444U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1065016088086441107U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + aNonceWordD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + aPhaseBWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7682U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8225U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7657U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5562U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 37U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + 13278949403988203974U) + aNonceWordI;
            aOrbiterI = ((((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 9213599924054673756U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 1255746482932381798U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 11575321997144516122U) + aNonceWordN;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 14U)) + 15881587525529432437U) + aPhaseBOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9846195809864862707U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12319815691858217670U;
            aOrbiterH = RotL64((aOrbiterH * 14271546305640811091U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16322617427294439587U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16332130810525887437U;
            aOrbiterF = RotL64((aOrbiterF * 7588076439690559343U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4920951156015336794U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16767126455124552329U;
            aOrbiterB = RotL64((aOrbiterB * 4440352337076842603U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 12553595911087945223U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1437522202135436142U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12313100454852227143U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 2761983020631055729U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 14U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 27U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 44U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterB, 38U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13882U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 14652U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13940U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12131U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 22U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 3236820517816085022U) + aNonceWordA;
            aOrbiterD = ((aWandererK + RotL64(aCross, 47U)) + 741288875914097926U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 26U)) + RotL64(aCarry, 39U)) + 8417246926007729580U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aScatter, 5U)) + 9715717805774537170U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 14360243844821619482U) + aNonceWordF;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10760908100206775334U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3434641779946167811U;
            aOrbiterA = RotL64((aOrbiterA * 3305698324169010803U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 7885568822756234567U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3041563437672051294U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11440300917533482297U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15761355327564963516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1158633562785937421U;
            aOrbiterJ = RotL64((aOrbiterJ * 15511324886867188235U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9338581575871970653U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9172038894262857354U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3110871165285625807U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14653924713599790081U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3854497592598563309U;
            aOrbiterF = RotL64((aOrbiterF * 11737111068815795303U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 52U)) + aNonceWordI) + aPhaseBWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aNonceWordJ) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16710U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 20129U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18632U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 21107U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 51U)) + 1364174714924216027U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 19U)) + 13561796874229506613U) + aPhaseBOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 11845572344206238305U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 15762708240326773763U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 21U)) + 1157119665207900473U) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6823546624372055260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14465564210523945121U;
            aOrbiterD = RotL64((aOrbiterD * 10957323253786161255U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10667464548080807531U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13445737493224316575U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 12137295000900795711U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3009837893785957665U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 2886920524111083752U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 15308180928967762543U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10886177449328249656U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15067759884678100433U;
            aOrbiterH = RotL64((aOrbiterH * 5724566815989860041U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18307930462682331536U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8791864377579255801U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 9265158882471421767U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 43U)) + aNonceWordB) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordC);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 4U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 38U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordI);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25839U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 26277U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25807U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25004U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 36U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 11210042748013785976U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 20U)) + 4584747303233477454U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 23U)) + 8878765929792969517U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 2172232330280041122U) + aPhaseBOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 11U)) + 8378937026022264016U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 8683007464695824208U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9564352997357118134U;
            aOrbiterK = RotL64((aOrbiterK * 17869948990449143305U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11713878436769887528U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 8052917623074021077U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 7450115139081623477U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7720597162792145185U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2602847785328475621U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065077077207224525U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17813669222300509724U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8724263063156573013U;
            aOrbiterE = RotL64((aOrbiterE * 3632927017737834359U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6882429835961613492U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13213313479525717359U;
            aOrbiterH = RotL64((aOrbiterH * 2411431247725974895U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aNonceWordC) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 60U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 10U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31243U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 28401U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30341U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27314U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 38U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 7896237440058555694U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 35U)) + 11870529476037558635U) + aPhaseBOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 9158983227801569448U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 4710172270996950329U) + aNonceWordB;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 48U)) + 14634482800356647630U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8822207952170610891U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 13755891414028982553U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5173750624716006485U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 4555293067488040719U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2816805148093762081U;
            aOrbiterB = RotL64((aOrbiterB * 16838149138341713943U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2122631477965135190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7102471666524164715U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17274623547879474204U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5443572270546181789U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 938587316977094680U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18258015823797023523U;
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aNonceWordO) + aPhaseBWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterB, 56U)) + aPhaseBWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Lacrosse_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9F776EF01F73A581ULL + 0xF41FCBB070C49C88ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x976F6000E2E8A1E5ULL + 0xD15A52578AF0731EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEE20710693B3CCE7ULL + 0xD42295FBA69B0BDFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBF56A5522CEC04BDULL + 0xDC8A6897E9E50E54ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDEFAA5E9D49B8869ULL + 0xCAF5CA46EC0A23F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBB4B294C3C752EC3ULL + 0x955E6410106C3F87ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8A8515BB6AD16DDFULL + 0x8B0102008DE32A96ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x99668C22DB3DD3B5ULL + 0x817B4A7BBEA2149EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x87E9F05E607437BBULL + 0xA11FC51C724957D1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x959D7FF88C2C3229ULL + 0xEF263030C1015A40ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9ECA4053324AD325ULL + 0xABD9B2BDB5FE0439ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF928D6DDFB8BD2C5ULL + 0xD86BA1E5713CEF9AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8903F2CB933C5F41ULL + 0xD2653E1947DCBD53ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE6D05BF6A27A4AFFULL + 0xADD54FF4CE62B7F5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCB2E8A7B816F8C2DULL + 0xCCEE01A607902D59ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA73A6A91FD551453ULL + 0xDDA3B6560694C711ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7727U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 1078U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4252U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7865U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 13U)) + (RotL64(aIngress, 54U) ^ RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 12849591986267890852U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 8232614804696815750U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + 12141567259210877281U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 5U)) + 2928641981037885644U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 43U)) + 980733350554783938U) + aNonceWordH;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 2683985177993350746U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 39U)) + 14532148403815527355U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + 7736296629433884203U) + aNonceWordK;
            aOrbiterE = (aWandererH + RotL64(aScatter, 56U)) + 10428437770166310549U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 18327174144859461029U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6810436935194432002U;
            aOrbiterH = RotL64((aOrbiterH * 2715987179577753597U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12606153309690753435U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17123256945895150555U;
            aOrbiterI = RotL64((aOrbiterI * 13469111258504672565U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9057777759026189541U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16478485918911194442U;
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 18064460487552100483U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11477276762421684083U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3886501230380184395U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18318375441973295081U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13849305985380030986U;
            aOrbiterA = RotL64((aOrbiterA * 12962140243967824959U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10240409420338313641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18360586077779529086U;
            aOrbiterD = RotL64((aOrbiterD * 18196875422391501927U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16801797158622424257U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4950305991208513887U;
            aOrbiterJ = RotL64((aOrbiterJ * 4437082499761416951U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15790878572843321918U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9808781805065559728U;
            aOrbiterF = RotL64((aOrbiterF * 9394280083159162953U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 11974996650410830731U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4955004489435232515U;
            aOrbiterC = RotL64((aOrbiterC * 13301966529515483085U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 10U)) + aOrbiterJ) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 5U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 14U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12275U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 12080U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14499U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13706U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + 6771552164800695068U) + aNonceWordE;
            aOrbiterJ = (aWandererH + RotL64(aCross, 43U)) + 12131763371571322040U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + 3326182381395522013U) + aPhaseCOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 10U)) + 12288775097697156383U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 5195948373449796741U) + aNonceWordM;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 14404044002250137144U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 11142382920035825426U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 22U)) + 2967149520256475485U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 51U)) + 1470907369577818097U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9231668148004163910U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13078929163913892386U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7509829068700523627U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9485274692075657877U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12216951187543631673U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6933334652581744234U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17260276102423580920U;
            aOrbiterE = RotL64((aOrbiterE * 7796879893790990605U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 387767848169714392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8597538259308082638U;
            aOrbiterH = RotL64((aOrbiterH * 4888054690557707241U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7996708724489146033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15357384191688149939U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9827691726832491373U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 17739222908739454637U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1614322333281471170U;
            aOrbiterG = RotL64((aOrbiterG * 7063116837752240891U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4531604274893197209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3453280714992341288U;
            aOrbiterI = RotL64((aOrbiterI * 8390029711127907805U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 116623650872661533U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6565636510115095988U;
            aOrbiterD = RotL64((aOrbiterD * 9691897067492501177U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10303258439817808058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10917642773040237611U;
            aOrbiterJ = RotL64((aOrbiterJ * 10232856828372963363U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 30U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 46U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aPhaseCWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterH, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 34U));
            aWandererH = aWandererH + (((((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 35U)) + aNonceWordP) + aPhaseCWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aIngress, 44U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16499U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 24377U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16905U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 21102U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 5573188770530340913U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 1431772230889897111U) + aNonceWordI;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 30U)) + 4809192776429682319U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 43U)) + 5576603692574369341U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 21U)) + 2720143226007220386U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 51U)) + 17220328778565331629U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 10U)) + 9629485808442089423U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 1136998437010390983U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + 11893390497814523841U) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1764986431917532370U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1741014798007010376U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 13414914086049500731U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12221368453236547044U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7694538641172350430U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8439120733670016501U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17472344518811560603U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9535358833412446771U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11192312491731312451U;
            aOrbiterG = RotL64((aOrbiterG * 17405609148475445743U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14850451970047190039U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11932493299452443256U;
            aOrbiterF = RotL64((aOrbiterF * 7964808728820467795U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5972619895614731870U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 17174497535809891690U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15471084511364572533U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17412894714378898351U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14675615208706549810U;
            aOrbiterA = RotL64((aOrbiterA * 7864845089606499769U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16116792108013658523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9702262005960966336U;
            aOrbiterB = RotL64((aOrbiterB * 970452849653781703U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17337264966818542841U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7004462033775827275U;
            aOrbiterH = RotL64((aOrbiterH * 11943575980344402681U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 50U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterE, 27U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 60U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererB = aWandererB + (((RotL64(aScatter, 26U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + aNonceWordH) + aPhaseCWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterI, 20U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererD, 14U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordF);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26710U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 29020U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30638U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((aIndex + 31724U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 40U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = (((aWandererD + RotL64(aIngress, 28U)) + 13960289014350612206U) + aPhaseCOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aWandererA + RotL64(aCross, 43U)) + 3483331015269589730U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + 6873299241002444518U) + aNonceWordA;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 3562094007125534229U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 11422367439932782705U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 10U)) + 532453428514259816U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 17810941465810193088U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 47U)) + 11869759058631106331U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 8837581071876177566U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 17185378327053837778U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7578253375676981500U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 13371647568758721729U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17112646434432814442U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14949096407295697881U;
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4259590620758467836U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6534899413644542303U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7987609419215568661U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2637407498893694243U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15819295597921425711U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5202015597375051399U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6373559542002699718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11694562937392022505U;
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3308736483775453062U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12749929710650475901U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 248428400724560945U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1569528215675579656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1044077933631689572U;
            aOrbiterB = RotL64((aOrbiterB * 6443796233912755143U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8393422728124537471U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2002732612516530754U;
            aOrbiterA = RotL64((aOrbiterA * 13702146823622364279U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13469191942843147943U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7633171368709520560U;
            aOrbiterH = RotL64((aOrbiterH * 9713514012478203047U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 36U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterC, 60U)) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 51U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterE, 26U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordF;
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

void TwistExpander_Lacrosse_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xADB9793020C97D7DULL + 0xAFE1C71D084C6EFFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF5309BC704A87D45ULL + 0xED70AD609E022F16ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xED74F942F9DA4DCBULL + 0xEEA06D188647ACCEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA2852C8B845466D5ULL + 0xF1F566181CD1B5FCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE71E4A767A18568DULL + 0x8C0B45366061DF83ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC526860D48379B49ULL + 0xB5F52626B57279A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCD1122D79B1023C9ULL + 0x97B9F9E4E6E7EED1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBB45C5A42FACCBB9ULL + 0x8814277E917D4C31ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF399DE6E62138311ULL + 0x8D69FE955731E7E0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF2538813EF8E0861ULL + 0xF3FB43E6FDF607C7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x83CB2C8B25110897ULL + 0xB8949D858CE83B45ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE3DB71EF2E4422BFULL + 0xC8529271A4B01258ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD84D17F905D5432BULL + 0xB429D519FAE0C662ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBB36763B60416989ULL + 0xC32D70EB981E8750ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x892E914388B75E85ULL + 0x849FE93AC2718AC2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA1C57565105AE96DULL + 0xD1991051302060A8ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4043U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 2510U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3543U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3440U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 26U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aScatter, 41U)) + 13174219512651137892U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 2715455762789269341U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 26U)) + 1338018183235594313U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 16566866551729552930U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 6901845297307236726U) + aNonceWordE;
            aOrbiterG = (aWandererF + RotL64(aCross, 23U)) + 2476078302049201718U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 35U)) + 15531109473927052260U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 29U)) + 4087849380858572351U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + 5167830630098599644U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 7275995452428627217U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 14U)) + 14794340370010024117U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8509217403041662849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2321522025240806996U;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5676672952755594051U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2304681269233504384U;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8383399721062437300U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13181984036942227666U;
            aOrbiterC = RotL64((aOrbiterC * 1648761328771932069U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13602604532551684210U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12725687663616352843U;
            aOrbiterI = RotL64((aOrbiterI * 4684699861686199753U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5831790822416009806U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4535048543735457407U;
            aOrbiterA = RotL64((aOrbiterA * 12076777878870257053U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10617608605149381858U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5244225377862618630U;
            aOrbiterH = RotL64((aOrbiterH * 15307177251167023999U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18229989093139888456U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9728120630096192811U;
            aOrbiterJ = RotL64((aOrbiterJ * 16052574428163231023U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1312233443099767304U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8043115602160128619U;
            aOrbiterF = RotL64((aOrbiterF * 9365756845731616963U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4679339316686216023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 211799535650113758U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1478368466990144107U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13307123762743628190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7093673238704478497U;
            aOrbiterB = RotL64((aOrbiterB * 13273906568866802561U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16396459072175632290U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13174219512651137892U;
            aOrbiterK = RotL64((aOrbiterK * 7581008806810219369U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 36U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 40U)) + aOrbiterB) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aNonceWordA);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 30U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + aNonceWordK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterH, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6133U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6644U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8019U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 8853U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 5960680319644404115U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererI + RotL64(aScatter, 29U)) + 16050752633567034185U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 8447503223226854741U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 26U)) + 14176813813397917591U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 51U)) + 10534915376130006644U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + 6866224454375302514U) + aNonceWordO;
            aOrbiterE = (aWandererG + RotL64(aCross, 13U)) + 16506374165041008396U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 7167814023968794098U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 13870852197416596664U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 43U)) + 18064038854848993105U) + aNonceWordP;
            aOrbiterJ = (aWandererC + RotL64(aCross, 47U)) + 9869630811507771691U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 863613100452759380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16597969741225436529U;
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6575347108051310653U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17062262265485019063U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 7601045488473620019U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7193399224636409133U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 14146747818810433849U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 5273185769989530041U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9441449106442431427U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4303295336545399503U;
            aOrbiterE = RotL64((aOrbiterE * 8829695296836242587U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12604760768543193458U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15779327512379787715U;
            aOrbiterC = RotL64((aOrbiterC * 14000905201441272597U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15553000781122708728U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17162740616060079717U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9458662233556750239U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1032374679817715156U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16413393156165548232U;
            aOrbiterD = RotL64((aOrbiterD * 549659738811935015U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14056855000013992045U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7399202019042538829U;
            aOrbiterI = RotL64((aOrbiterI * 6103508549612077695U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2218389473339103389U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4679497280975967770U;
            aOrbiterG = RotL64((aOrbiterG * 9228353578259815023U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7620538119914173747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3118355627808424159U;
            aOrbiterB = RotL64((aOrbiterB * 12481319980496032783U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16787092219237931175U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5960680319644404115U;
            aOrbiterJ = RotL64((aOrbiterJ * 10727217147056112401U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + aNonceWordJ);
            aWandererK = aWandererK + ((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 54U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordH) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterG, 18U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 24U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13077U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 11801U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14317U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 12980U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aIngress, 57U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 11450949896247900941U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 24U)) + 3905542253538116335U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 11U)) + 9529740545977785305U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 21U)) + 1856876631533143492U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 27U)) + 84253466320181686U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 30U)) + 12577480918745432444U) + aNonceWordP;
            aOrbiterA = (aWandererH + RotL64(aIngress, 5U)) + 5625703170397704029U;
            aOrbiterD = (aWandererK + RotL64(aCross, 41U)) + 694608607323629282U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 27U)) + 3993981243536262204U;
            aOrbiterG = (aWandererI + RotL64(aCross, 13U)) + 4119215953484892051U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 8785040118556157146U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16234403619456882890U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10398727475672860610U;
            aOrbiterF = RotL64((aOrbiterF * 5086871400049644715U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18327987141759096769U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2645964788056875452U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8778681366114628045U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2859452497983106129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7196557924940881076U;
            aOrbiterI = RotL64((aOrbiterI * 14415389907490256711U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 930127943984174668U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15673596916054795749U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 7505660488733199479U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16673140529110941163U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2258448294877833760U;
            aOrbiterD = RotL64((aOrbiterD * 1821550319748977445U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6870209259643931219U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12749790107942194104U;
            aOrbiterG = RotL64((aOrbiterG * 4871407285968611725U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17131374134617173866U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6426448390733751612U;
            aOrbiterK = RotL64((aOrbiterK * 12490559588384058417U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15592826434339731146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14182944418026376183U;
            aOrbiterE = RotL64((aOrbiterE * 7218860482893476233U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17447476498234456596U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 972861017466618022U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9610670431280153921U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13185309156950240549U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14442284480744008537U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2907844852105175837U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7816745313858811117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11450949896247900941U;
            aOrbiterH = RotL64((aOrbiterH * 18317765298694454463U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 58U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG) + aNonceWordC) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterH, 23U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 44U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17969U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17386U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18900U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21276U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 47U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 12583180859826261500U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 11U)) + 9067093488553721468U;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 12173106198862881754U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 39U)) + 11333491014394592654U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 21U)) + 3511883526940919554U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 30U)) + 7416810692106273044U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 8341174972619784110U) + aNonceWordI;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 2220852854836962979U;
            aOrbiterF = (aWandererE + RotL64(aCross, 19U)) + 8090781422229383825U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 51U)) + 2338801236599102223U) + aNonceWordF;
            aOrbiterE = (aWandererF + RotL64(aIngress, 60U)) + 12484514711848308104U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13684861340589131816U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12796636819991873058U;
            aOrbiterG = RotL64((aOrbiterG * 5533508014234835669U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7634198650894837690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10240326122201201762U;
            aOrbiterI = RotL64((aOrbiterI * 8758703497719125901U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4162814763739453934U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 2766504649149048469U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16731843453895178671U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11051393030148769655U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17687055068651386665U;
            aOrbiterK = RotL64((aOrbiterK * 1042927176246229537U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3353615315436983420U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5971640796220306310U;
            aOrbiterC = RotL64((aOrbiterC * 15804313508835034807U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12299773092762384765U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7435804907797063411U;
            aOrbiterF = RotL64((aOrbiterF * 9848139805288165965U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 8735783937125735699U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11903126115475835615U;
            aOrbiterJ = RotL64((aOrbiterJ * 16942088822124940265U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4427166023462475475U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6011733469446008137U;
            aOrbiterE = RotL64((aOrbiterE * 17298067225913923517U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 18341473946127677319U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5423774915753911947U;
            aOrbiterB = RotL64((aOrbiterB * 14985099502923458523U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2384393657884193014U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2650593524388493958U;
            aOrbiterD = RotL64((aOrbiterD * 892985816665547945U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15991261431384033176U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12583180859826261500U;
            aOrbiterH = RotL64((aOrbiterH * 14394838775646875599U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 36U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 34U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 6U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 26732U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 27186U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24046U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23447U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + 8866844335448071821U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 11U)) + 15159698739856430085U) + aNonceWordB;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 36U)) + 9582805772989594633U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 47U)) + 1438538239931588373U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 10862044156620436139U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 13682173320058164615U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 21U)) + 8351013291045977592U) + aNonceWordF;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 50U)) + 15777857431516633916U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 3U)) + 16178966745333885377U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 5U)) + 9031889187993001617U;
            aOrbiterH = ((((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 6308472367425865347U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 642109145903321046U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9186268569255318035U;
            aOrbiterG = RotL64((aOrbiterG * 10714674348507516749U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6091345356803675860U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13218507921880873749U;
            aOrbiterK = RotL64((aOrbiterK * 15415157927185637717U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4266652275234474616U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4391422098164506195U;
            aOrbiterI = RotL64((aOrbiterI * 17634679403195085867U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5160682323243635577U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10351728852161347404U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3950932176454814023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9536466386833427441U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 18064984243491293435U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9927425919978776529U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6819384090527481081U;
            aOrbiterA = RotL64((aOrbiterA * 18032965969184368561U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1646274931424218507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16166524473976135097U;
            aOrbiterD = RotL64((aOrbiterD * 11672192658072663849U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11252501968059485262U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16847854447987609067U;
            aOrbiterJ = RotL64((aOrbiterJ * 6326299154627028295U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16723218285355036446U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13870211254243048975U;
            aOrbiterH = RotL64((aOrbiterH * 10203222183774624097U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11401147367366049493U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4266628469244269926U;
            aOrbiterC = RotL64((aOrbiterC * 2409934496621365221U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11578385782347296942U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8866844335448071821U;
            aOrbiterF = RotL64((aOrbiterF * 6456956795450036515U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 42U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 56U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 22U)) + aOrbiterD) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 48U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 46U) + RotL64(aOrbiterI, 41U)) + aOrbiterC) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 28U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32177U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 28826U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30404U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32709U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 30U) ^ RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 47U)) + 3917730204724097072U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 1874642340716212824U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 6900165757434854160U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 12750946097023807161U) + aNonceWordC;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 57U)) + 6563216048479513594U) + aNonceWordG;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 28U)) + 14960240191349450795U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aCross, 23U)) + 16306180275951788289U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 43U)) + 6502066618271045547U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 37U)) + 6219852857850888738U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 40U)) + 2272931312452845850U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 21U)) + 3028929882263199463U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6067393030073568112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10094809900437037258U;
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5962414178157074575U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15755563045799129417U;
            aOrbiterH = RotL64((aOrbiterH * 3692603590609922031U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 6321455513889880590U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1197435601998121700U;
            aOrbiterC = RotL64((aOrbiterC * 17693996266260557625U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12496949381666299968U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6357070235648527030U;
            aOrbiterA = RotL64((aOrbiterA * 2931486644220862433U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8423760160877540210U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8090246492554850768U;
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11436635942985063755U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17086363141014359856U;
            aOrbiterB = RotL64((aOrbiterB * 10504127577318206801U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10734017887545474935U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 375515325165740779U;
            aOrbiterF = RotL64((aOrbiterF * 9980486695448151709U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5217148491945389821U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14696058217023530058U;
            aOrbiterI = RotL64((aOrbiterI * 11026674782236654799U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11869055287836412650U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16951500118659983436U;
            aOrbiterG = RotL64((aOrbiterG * 4304372681583055077U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7866300390953569803U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18017335943787362993U;
            aOrbiterK = RotL64((aOrbiterK * 15683049583437004889U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2477944286851267725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3917730204724097072U;
            aOrbiterD = RotL64((aOrbiterD * 6617615984203047419U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 48U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + ((RotL64(aIngress, 24U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 12U)) + aPhaseDWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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

void TwistExpander_Lacrosse_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9886BD8019610C95ULL + 0xCF04328D2F4F1E64ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x870A940996D98C79ULL + 0xC9805D8707A1335FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD4990ECE0BF2C359ULL + 0xDB85609D6E4E0A6CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE27F2BFA60DE56C3ULL + 0xEB36A704267E7D02ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8962C4E03543A691ULL + 0x9A2123C7CC1CB1C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDAFC1D20EB9690B7ULL + 0xD343B110335F46E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD88DBDDB283DF873ULL + 0xF96A23FFE8E63A60ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA02B35AC7BB26E03ULL + 0x8F716A58D0AAE97BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA80A2D6C08814E1FULL + 0x9F263F17C3CBA3A4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE182D9865FB0F549ULL + 0xD2A7C248EC19D7FEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF444583D9068396FULL + 0xBDC7F36BD1B902D1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8FCE7710F1106FC3ULL + 0x810173149D6070C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFA09441B8025D5A1ULL + 0x8B81FC7ED0331787ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEE8FC32241D51025ULL + 0xE4640409D551A66BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9ED67F6D008484C5ULL + 0x98C7E7EEF33D797EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFF22205C441F6421ULL + 0x980AB7F3FE8E425DULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 152U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((aIndex + 2105U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 5056U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 12046647397183218524U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 41U)) + 2760779375026461991U) + aNonceWordH;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 13U)) + 13735454443176855650U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererI + RotL64(aCross, 30U)) + 4370377000586647724U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 14566322384189969094U) + aPhaseEOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 3U)) + 5056565959818422786U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 8795403810686579209U) + aNonceWordB;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 39U)) + 9625947666256011567U;
            aOrbiterF = (aWandererB + RotL64(aCross, 10U)) + 1703669290934254701U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 37U)) + 6664070663184147951U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 2104148316797553431U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1197910004222596145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9922977170060903197U;
            aOrbiterJ = RotL64((aOrbiterJ * 13047828062605568603U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2048376210852567829U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12568990647075931409U;
            aOrbiterA = RotL64((aOrbiterA * 9860242601194210927U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15026894775772902751U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3439447160137900629U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1813754963043785165U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6532671388552829796U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17261098369835997661U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 568292591215203521U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3171300991007459947U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5935563269327662024U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 11271790283157765003U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14290941734320455612U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12371794745736518824U;
            aOrbiterF = RotL64((aOrbiterF * 12208762336145168647U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8782840145467637373U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4067525421190366741U;
            aOrbiterH = RotL64((aOrbiterH * 6671002797916227485U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11854812920571789853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17564890418553131451U;
            aOrbiterK = RotL64((aOrbiterK * 16657184504366731805U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6250004085193517531U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2362659992682660827U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4365619310373869859U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4597159873252831182U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13197238269207675773U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 379653377172816575U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8552479493772820372U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12046647397183218524U;
            aOrbiterD = RotL64((aOrbiterD * 17918033655125400323U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterI, 24U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + aNonceWordL) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterK, 42U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9662U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 10395U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9556U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5837U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (((aWandererH + RotL64(aScatter, 34U)) + RotL64(aCarry, 11U)) + 4970414922752555648U) + aNonceWordG;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 9462756592787669327U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 19U)) + 3948790686662213095U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 14542857212241578311U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 41U)) + 3387479009827029547U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 29U)) + 1411421370057797877U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 3U)) + 16894451466895681236U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aCross, 44U)) + 12727136462290223542U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 51U)) + 4625389198191960525U) + aNonceWordB;
            aOrbiterE = (aWandererK + RotL64(aCross, 27U)) + 3471881403786164913U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 39U)) + 6433115856048534831U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9825592965466157982U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1553125767261293088U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 411535191177308781U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9951616357109647617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11231080382787286889U;
            aOrbiterH = RotL64((aOrbiterH * 14024961994986659187U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13419663264017317947U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4835055642466215566U;
            aOrbiterG = RotL64((aOrbiterG * 17898065852351759171U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14558747666410946768U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13120938960926874504U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 5681766019285559739U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11910501376797343986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15074100100781785300U;
            aOrbiterC = RotL64((aOrbiterC * 228976960937473851U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12415377930578091821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14882039078390681802U;
            aOrbiterI = RotL64((aOrbiterI * 13855446647753150713U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8094338361713756895U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5478280604704108822U;
            aOrbiterA = RotL64((aOrbiterA * 18062931724700600993U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6977017654546871841U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4131602217285988962U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11865422227883712419U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9619228479582032318U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13506679497441415586U;
            aOrbiterJ = RotL64((aOrbiterJ * 5789932662418992799U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10180259475831448124U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4721628773773094283U;
            aOrbiterE = RotL64((aOrbiterE * 10834196399754443771U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7898137727558813688U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4970414922752555648U;
            aOrbiterK = RotL64((aOrbiterK * 6651835668618579479U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 36U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterH, 28U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterI, 10U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 12U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12899U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 15451U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16260U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15157U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 14214886793361825363U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 17267959031078766320U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 56U)) + 16436067429484887644U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 3U)) + 9885951769332633820U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 37U)) + 12971711341813893304U) + aNonceWordG;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 199970353398450154U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 23U)) + 1237341696444162094U;
            aOrbiterH = (aWandererD + RotL64(aCross, 35U)) + 7991128854417613360U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 14809029847149045833U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 5U)) + 2559509556915775947U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 10U)) + 14336829730147834160U) + aPhaseEOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8853631886733610440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13346159398673246914U;
            aOrbiterG = RotL64((aOrbiterG * 13660497151446983393U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12121095718571872976U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16239781125815589804U;
            aOrbiterE = RotL64((aOrbiterE * 5157009090454962231U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9051377033794324106U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13805815136723461780U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14849157800322754413U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18116651528452542634U;
            aOrbiterB = RotL64((aOrbiterB * 3638480428016835537U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4105057226952948599U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5911714320560994391U;
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4439149331729987587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10278532228230163632U;
            aOrbiterI = RotL64((aOrbiterI * 17428224919864716517U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2342456582668741750U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2360578572554664800U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1108428466956691925U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12132934875391401246U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17213278726790245812U;
            aOrbiterD = RotL64((aOrbiterD * 11904899990681410419U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7994340481560109811U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13735851271080138255U;
            aOrbiterC = RotL64((aOrbiterC * 12387076892129731557U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6682417543888875268U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15642799286975840550U;
            aOrbiterK = RotL64((aOrbiterK * 7861250716882028053U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9839299346094784067U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 14214886793361825363U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 2103132743364916037U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 12U) + aOrbiterA) + RotL64(aOrbiterF, 29U)) + aPhaseEWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 46U)) + aOrbiterH) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20869U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21013U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17230U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20851U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 30U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 5131645209694953015U;
            aOrbiterK = (aWandererD + RotL64(aCross, 43U)) + 12070391048835379854U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 35U)) + 2604295836242338724U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 14042039029284001596U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 54U)) + 8914654543854559327U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 3U)) + 2185619407969359869U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + 5187406295103352574U) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 21U)) + 8022832481290871217U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 13U)) + 8783061916740573472U) + aNonceWordL;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 19U)) + 10711028365596196301U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 19U)) + 13387065038269133571U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11187001318931801582U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14191473173276034019U;
            aOrbiterC = RotL64((aOrbiterC * 2491253922434756431U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16207761776716426435U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9677408414452078760U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5487303383095129949U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17812460332794370649U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7736423148554132028U;
            aOrbiterF = RotL64((aOrbiterF * 15588733747232852555U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17293203944059014763U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13487243633338010243U;
            aOrbiterB = RotL64((aOrbiterB * 9468688858740539095U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15979293016815060755U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17645215484691359547U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1449450767288733995U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11635961468586927692U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10530136578329059784U;
            aOrbiterD = RotL64((aOrbiterD * 8785021493374398437U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4900370530116992731U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15952900504821599445U;
            aOrbiterJ = RotL64((aOrbiterJ * 5413316082800365261U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9938000151832814778U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14170277411106520726U;
            aOrbiterG = RotL64((aOrbiterG * 5058343552974910737U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14091010427448547620U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13658560822164111421U;
            aOrbiterA = RotL64((aOrbiterA * 9523184040517290629U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13954269172267844623U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3921811946419945868U;
            aOrbiterK = RotL64((aOrbiterK * 6839440867046147039U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14296483810577739898U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5131645209694953015U;
            aOrbiterI = RotL64((aOrbiterI * 10190969526209064367U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 58U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterA, 27U));
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterI, 18U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterE, 6U)) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24126U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24374U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23868U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 25393U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 9751314027302668907U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 21U)) + 12175450995523107056U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 17519694958730119552U) + aNonceWordE;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 19U)) + 9093525527925682263U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 10U)) + 3713831321786810138U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 10108355209191835040U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 23U)) + 12956307447311314768U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 1904298513945877359U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 4658049993308574460U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 12U)) + 9826333658248851902U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 41U)) + 12058666914724365134U) + aNonceWordF;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2516574707110528099U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13335308331049750235U;
            aOrbiterF = RotL64((aOrbiterF * 5880227828760598587U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8230749255538495304U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16536559486797811486U;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 12387639130570188998U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8459259798142872020U;
            aOrbiterA = RotL64((aOrbiterA * 8001346480955847013U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16083784052002800300U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1957284290736468379U;
            aOrbiterE = RotL64((aOrbiterE * 5046501301740813065U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7349538179311335863U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16395170077006105258U;
            aOrbiterK = RotL64((aOrbiterK * 4230485452156662763U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 3317652065873784068U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5517155804799120700U;
            aOrbiterG = RotL64((aOrbiterG * 9789270651974719183U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5568525912112200094U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9334250662962319598U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5034887614541768961U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5641394627075994165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13524971148931512745U;
            aOrbiterI = RotL64((aOrbiterI * 3699457147759854357U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15124425790244392471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7896294947517723306U;
            aOrbiterB = RotL64((aOrbiterB * 7526632360108129915U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15241686066829586263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12099799118961857495U;
            aOrbiterD = RotL64((aOrbiterD * 10456171163074630861U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17529688916595727188U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9751314027302668907U;
            aOrbiterH = RotL64((aOrbiterH * 521888849578281715U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 24U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterK, 58U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 23U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 48U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31419U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 32704U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30272U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 28966U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 13U)) + 7948891781097675369U) + aNonceWordF;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + 13928362874228230226U) + aNonceWordA;
            aOrbiterF = (aWandererH + RotL64(aScatter, 34U)) + 10776180542602258926U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 5735115172149470447U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 53U)) + 5353591822981766987U;
            aOrbiterB = (aWandererF + RotL64(aCross, 51U)) + 562301708107268570U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 10467810247578364868U) + aPhaseEOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 14541630141152308564U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 47U)) + 2350076897065139429U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aWandererB + RotL64(aScatter, 38U)) + 17519109078651162228U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 11U)) + 6061035173339902910U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15654836633731000065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13723521735153718904U;
            aOrbiterF = RotL64((aOrbiterF * 14459516479283070563U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2849680038315532197U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17336102435576647923U;
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7671010488872356142U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11485114338165600777U;
            aOrbiterB = RotL64((aOrbiterB * 4162584865462407791U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8759060657343458985U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11009137869375286581U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8741417343929809115U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15792999392743144135U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 361487389591183005U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15292753806514404853U;
            aOrbiterD = RotL64((aOrbiterD * 17478232597253311153U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14929153438443362045U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7904556383593914086U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2484130486635511403U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3793180909904286848U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10391957637467171320U;
            aOrbiterA = RotL64((aOrbiterA * 505484041943467117U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11648765065563798353U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17601185776537566611U;
            aOrbiterC = RotL64((aOrbiterC * 4753179291885740011U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2907499704986356444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17048858067202291241U;
            aOrbiterH = RotL64((aOrbiterH * 2607549567999666889U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4340465159886930775U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7948891781097675369U;
            aOrbiterI = RotL64((aOrbiterI * 12913104720552907335U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 14U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 54U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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

void TwistExpander_Lacrosse_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x89DEA3816681C51DULL + 0xBF8E449FE624D093ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC24009B89A790769ULL + 0xA8AF9BF874D1A084ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83624146DF026EC7ULL + 0xB2D8584FB59E9939ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE488027AF784AE03ULL + 0xF36AED984ECBA5B3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x974917E22C420B83ULL + 0xE9F2B12CB3796B17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xABAE80DE2A257483ULL + 0x9E22E6958F07B666ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE16D33612B5C11E9ULL + 0xAA2F8A4AACEC202DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC10A11AAB7E621F1ULL + 0xE4C63DA54CE8DBEAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8E04725CD2A00299ULL + 0xAD08F5F871BC4789ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x83CD5C9BDEAB4AB7ULL + 0x934DA5B9F5DA37FDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF5EEF30FBADC0611ULL + 0xD77E682B9C37084CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xDB25A2F16B8D6B81ULL + 0xA0F2B0AA981BE40EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x95799639E6EB6A21ULL + 0x821DE190472F4F6DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDF2DF1F902DBD165ULL + 0x930B3FA67E4408EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFB56C4D4985022BBULL + 0xAC2F14D146EFA0A2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE3AECAC7417A757BULL + 0x8FC730AF360E2C19ULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5297U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2699U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1188U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 237U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 14U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aScatter, 21U)) + 1142447269198373880U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 56U)) + 10581460640040336191U) + aNonceWordK;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 29U)) + 14703062773878202900U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 15737525756286914746U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 16178774478273186999U) + aPhaseFOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + 2514897053906809160U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 53U)) + 13702496607592508464U;
            aOrbiterK = (aWandererA + RotL64(aCross, 36U)) + 18030885275418337965U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 5241783876161655984U;
            aOrbiterF = (aWandererC + RotL64(aCross, 13U)) + 2807052676283587925U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 39U)) + 8022804576763271327U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15597099852232205860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1538435607932096400U;
            aOrbiterA = RotL64((aOrbiterA * 7900752511710516981U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11147868774413615365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9325213746830411568U;
            aOrbiterJ = RotL64((aOrbiterJ * 561819005818948769U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13792300423550555634U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3134856508983945719U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4271845067763664863U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8654966018053784882U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8937113935476779267U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7386875687217705855U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4135676350355234788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11407912615743682678U;
            aOrbiterD = RotL64((aOrbiterD * 2773506587480714695U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10966950663872392059U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6686634993700944582U;
            aOrbiterI = RotL64((aOrbiterI * 2509459942163678241U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14154407529749257990U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18054640398549782388U;
            aOrbiterH = RotL64((aOrbiterH * 7830759861389060149U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14623473030642960240U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1857945571104460086U;
            aOrbiterB = RotL64((aOrbiterB * 18039903315045620079U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17650774450811065797U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9458168381246672881U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 3452665113988737563U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 16604923466236483242U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12447748535184711684U;
            aOrbiterK = RotL64((aOrbiterK * 5982708155382249061U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9589720286549780720U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1142447269198373880U;
            aOrbiterF = RotL64((aOrbiterF * 8176719948031280789U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 21U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterH, 58U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 10U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9097U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 7282U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7625U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8547U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 4U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 51U)) + 17225673071833726819U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 53U)) + 10301458382103627331U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 20U)) + RotL64(aCarry, 11U)) + 3960233050857362414U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 29U)) + 17768665685046605837U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 14471018461213959767U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 13U)) + 10730597892721340453U) + aNonceWordK;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 14863394003122760542U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 11U)) + 9948587274816688296U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 27U)) + 3573569431435100993U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 41U)) + 8153670675740450590U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 46U)) + 16438856577722561424U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15765587867581925041U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1082039522061775213U;
            aOrbiterC = RotL64((aOrbiterC * 17023740047246402641U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4202521649260798876U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15877659681260461141U;
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2551560426129646123U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3005102326163906320U;
            aOrbiterK = RotL64((aOrbiterK * 4241583192662435107U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1675501058857208089U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 12774812270956702043U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5488437008504905105U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1044886020922563597U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4857445127457225171U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13223560654459705259U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11548725551787560962U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2434677823189765161U;
            aOrbiterJ = RotL64((aOrbiterJ * 4283026044563670969U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9606875320524736294U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13732615866277657704U;
            aOrbiterA = RotL64((aOrbiterA * 3905528919281629775U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13921743663803299567U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13350829301153929899U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 11858642286713079795U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9473349030551400156U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7446792050826434742U;
            aOrbiterH = RotL64((aOrbiterH * 6619682184124713031U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17970527747978977453U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2326714817603921480U;
            aOrbiterG = RotL64((aOrbiterG * 14581676978186226887U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7875511075130474136U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17225673071833726819U;
            aOrbiterE = RotL64((aOrbiterE * 1196024136909896027U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterE, 34U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 53U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 26U)) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14140U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 11591U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14916U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14615U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 52U) + RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 12849591986267890852U;
            aOrbiterF = (aWandererG + RotL64(aCross, 13U)) + 8232614804696815750U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 11U)) + 12141567259210877281U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 41U)) + 2928641981037885644U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 30U)) + 980733350554783938U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 43U)) + 2683985177993350746U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 14532148403815527355U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 57U)) + 7736296629433884203U) + aNonceWordO;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + 10428437770166310549U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 18327174144859461029U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 18U)) + RotL64(aCarry, 5U)) + 6810436935194432002U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12606153309690753435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17123256945895150555U;
            aOrbiterG = RotL64((aOrbiterG * 13469111258504672565U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9057777759026189541U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16478485918911194442U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18064460487552100483U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11477276762421684083U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3886501230380184395U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18318375441973295081U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13849305985380030986U;
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10240409420338313641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18360586077779529086U;
            aOrbiterK = RotL64((aOrbiterK * 18196875422391501927U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16801797158622424257U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4950305991208513887U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4437082499761416951U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15790878572843321918U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9808781805065559728U;
            aOrbiterD = RotL64((aOrbiterD * 9394280083159162953U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11974996650410830731U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4955004489435232515U;
            aOrbiterH = RotL64((aOrbiterH * 13301966529515483085U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1187569634223338864U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5351017164244226367U;
            aOrbiterI = RotL64((aOrbiterI * 14735674576470803699U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9587142385246940125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16253850371962732943U;
            aOrbiterJ = RotL64((aOrbiterJ * 3408021872390904463U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14990060157351237661U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12849591986267890852U;
            aOrbiterC = RotL64((aOrbiterC * 2158106726261981983U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 60U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterD) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterG, 56U)) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19082U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 19222U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18737U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16614U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 7825479804710770560U) + aNonceWordK;
            aOrbiterE = (aWandererI + RotL64(aCross, 21U)) + 5298124167101358123U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 19U)) + 17774541024369233726U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 7679371833537454082U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 39U)) + 5385914900748772224U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 3879781930908486531U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 11U)) + 659110346638873236U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 13U)) + 10749021728538539749U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + 3631252455767429457U) + aNonceWordF;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 35U)) + 2271978810960685021U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 30U)) + 5963558780692551176U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 974909966119198104U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9296998242911152296U;
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2245318466901521959U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13391076374843288568U;
            aOrbiterJ = RotL64((aOrbiterJ * 18094558036982107419U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6184487746594236737U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1563385912137291418U;
            aOrbiterD = RotL64((aOrbiterD * 4805455299959232321U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1744840092006498629U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2100927276837188416U;
            aOrbiterF = RotL64((aOrbiterF * 3541788262067077997U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9998911862807246338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12239948725635220096U;
            aOrbiterB = RotL64((aOrbiterB * 7098620484129489129U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3307447094994950246U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12746613971448298932U;
            aOrbiterK = RotL64((aOrbiterK * 9463975886346934681U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11577488293733790649U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 191108997585598809U;
            aOrbiterA = RotL64((aOrbiterA * 9574978681405356871U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 18096145693841273722U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10026281133603934071U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17261343107314203471U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2346682418062064668U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2996178204018644206U;
            aOrbiterI = RotL64((aOrbiterI * 2552965800703390909U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15085425896818988223U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1589593231782852588U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1535556765195388675U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17170695588248383518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7825479804710770560U;
            aOrbiterH = RotL64((aOrbiterH * 7434218282170150533U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 44U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 14U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererC = aWandererC + ((RotL64(aScatter, 24U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26178U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 23157U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26151U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 23751U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 50U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 3U)) + 4476099022490972343U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 16836423700375760429U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 8850577488928703557U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 48U)) + 7091631824560042743U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + 12560498899956759494U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 53U)) + 7797973377112012161U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 6173820673874805794U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 57U)) + 10805025132310245348U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 22U)) + 7139216143268029968U) + aNonceWordG;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 13U)) + 8241544862261635722U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 41U)) + 4735527016563596150U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5166171126690294033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11117641762075368393U;
            aOrbiterC = RotL64((aOrbiterC * 4980156869201219393U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6312932356458415421U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1304139291184508668U;
            aOrbiterG = RotL64((aOrbiterG * 90744653170922319U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10085025354842771067U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16745854428789531080U;
            aOrbiterE = RotL64((aOrbiterE * 1945983905747274355U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2497187958708890337U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16069701876646548995U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16606039730973709495U), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 17242004368025978091U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12334315722243232121U;
            aOrbiterF = RotL64((aOrbiterF * 16528598396696346719U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8007042082518126895U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5665686359038811484U;
            aOrbiterD = RotL64((aOrbiterD * 11289316305875751813U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3913477186958600592U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16918984318564170343U;
            aOrbiterA = RotL64((aOrbiterA * 5128293326494417281U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10227611546502931418U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7187623463085447228U;
            aOrbiterJ = RotL64((aOrbiterJ * 8479839369622163181U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16655159122037336519U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9844145011519243346U;
            aOrbiterK = RotL64((aOrbiterK * 16512883184116277583U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8660130685326542506U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 16192687259641294851U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 2882649237163668499U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15208432734447317310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4476099022490972343U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7447168142776253041U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 23U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterA, 30U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 34U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32687U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 32672U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28636U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30544U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 48U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 23U)) + 15904465836916519864U) + aNonceWordB;
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 17725629806317789307U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + 13794170125914914828U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 2149055907476874332U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 5342047776745074649U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 56U)) + 8268148484060546838U) + aNonceWordC;
            aOrbiterF = (aWandererH + RotL64(aIngress, 39U)) + 10821151364028563719U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 4294213820894407378U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 41U)) + 10884726101307943090U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 34U)) + 16432210042202444824U;
            aOrbiterK = (aWandererI + RotL64(aCross, 29U)) + 15196602644336228055U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14117787670220328165U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 219833877949480215U;
            aOrbiterA = RotL64((aOrbiterA * 10736293047771972173U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3326396981881473962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14918513066311426279U;
            aOrbiterE = RotL64((aOrbiterE * 14269763278564574663U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11795234681370163206U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3068267285352664813U;
            aOrbiterB = RotL64((aOrbiterB * 15746255933920904619U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 245233356957999496U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 709926406353796673U;
            aOrbiterF = RotL64((aOrbiterF * 13627039596842073595U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5378105439430271038U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10114555061122044430U;
            aOrbiterI = RotL64((aOrbiterI * 5351295043424885549U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13233010815716769713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8231291294833548389U;
            aOrbiterG = RotL64((aOrbiterG * 10840516135212753869U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7160760224172419829U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14767926435411546785U;
            aOrbiterD = RotL64((aOrbiterD * 1643485739468851073U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4464245330038080103U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15778166658285494712U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 13980891936095282989U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2426340576450960905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6030631392508241438U;
            aOrbiterJ = RotL64((aOrbiterJ * 13921288910299408423U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15990180955119402476U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8707879851984546959U;
            aOrbiterC = RotL64((aOrbiterC * 13794027045755532979U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11665969506971636052U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15904465836916519864U;
            aOrbiterH = RotL64((aOrbiterH * 17042355185093585101U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 38U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterI, 34U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 21U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 54U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordI);
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

void TwistExpander_Lacrosse_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCDAA3CF7423DC9E7ULL + 0xA30679E3C1CFFA4FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC3F1C0ADB93339FULL + 0x96485742D242605BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF91D3B24BB68A665ULL + 0x922F20FC1F3BE6F6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A2DA41DEDE569FDULL + 0xE6F20E7744AC7191ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA427221FAA9AF09DULL + 0x8C6F20EE3AE8D6A0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD53B49A32D49D169ULL + 0xCDF12B7BAB360242ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA804B5F59F203165ULL + 0x8A641E00F6CEF5E2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x81B9BF460AB4C455ULL + 0xA348E91728F3D812ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB4866F8FF9B89755ULL + 0xF78AFE09E7D1B325ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x94AB09425E62150BULL + 0xE8DE425D4730D582ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE6D2BAF550D81BE7ULL + 0xEA12A215381CC96CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA22A83FFC13A42CDULL + 0x9AF841ACE32711E1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF6B8578E5760A9F9ULL + 0xED9FD2DFBFB8A242ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD12D2ACAE3D4BA2DULL + 0xFDBF02D6816EDE87ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC366974E55D67CA7ULL + 0xC9B42A27146B8CA4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEAE5E16951AA0F91ULL + 0x9D82EC2F28DED59FULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1481U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 3132U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5286U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 780U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 44U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 35U)) + 12669015908335980355U;
            aOrbiterB = ((((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 5438715179868613192U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererF + RotL64(aIngress, 19U)) + 13172104448184536460U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 13421421503244744803U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 39U)) + 13327113302994856582U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 27U)) + 4671768205922454413U;
            aOrbiterJ = ((((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 5355759962838579929U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 6691720614265406851U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 51U)) + 7063906424700911378U) + aNonceWordJ;
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 17328616394166672263U;
            aOrbiterG = (aWandererE + RotL64(aCross, 58U)) + 1542940602574207068U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7203866278803132454U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 993485696233139264U;
            aOrbiterC = RotL64((aOrbiterC * 11609009908810366447U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15659679028507488331U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18321361454094675842U;
            aOrbiterA = RotL64((aOrbiterA * 3966860765622641843U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9633319822696783352U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3496559332232402963U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 7772060229838162977U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1918349708324205526U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7701088402761359134U;
            aOrbiterE = RotL64((aOrbiterE * 9649485438465644795U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6006824348814439686U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 18088375375347012557U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 12801082943086128385U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12816533373478543584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17951880253818836433U;
            aOrbiterF = RotL64((aOrbiterF * 8935839101517220201U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11311632024372748238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9891349164779752351U;
            aOrbiterG = RotL64((aOrbiterG * 11405973752233193209U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 711130292000437038U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17818800917771709681U;
            aOrbiterB = RotL64((aOrbiterB * 10567029732245868263U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10188714200240109442U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9745615081760948652U;
            aOrbiterH = RotL64((aOrbiterH * 9321909462220134035U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6508703788527163965U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7536038073603467381U;
            aOrbiterK = RotL64((aOrbiterK * 12015514242701199813U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2793951597846756844U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12669015908335980355U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7355285540199760689U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 27U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterI, 35U));
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 22U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterA, 44U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6470U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9010U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5871U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 6843U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 44U) + RotL64(aCross, 57U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 50U)) + RotL64(aCarry, 21U)) + 4204560462077827182U) + aNonceWordA;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 57U)) + 6572370199668594039U) + aNonceWordJ;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 41U)) + 15958999876732622825U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 9969349486879280377U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 5U)) + 15450238998293956181U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 30U)) + 9128619863683138259U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 5691270563628979565U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + 5901029710568933106U) + aPhaseFOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 13U)) + 10442738941988588834U;
            aOrbiterB = ((((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 3508116020325721993U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 13221917083569767259U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11627915460377128176U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17858261365514253433U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7535577636975884641U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4294837988806295989U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11242915481585070249U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17540688242763829319U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13030663829236027109U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7451948220723185149U;
            aOrbiterA = RotL64((aOrbiterA * 5191778587712222029U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5575508866505031037U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5161096033789876794U;
            aOrbiterI = RotL64((aOrbiterI * 16843827915802461797U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3980482740649505122U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11188906150207270241U;
            aOrbiterD = RotL64((aOrbiterD * 408550837615188413U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4435504916461645189U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9970252853543702833U;
            aOrbiterC = RotL64((aOrbiterC * 5829143716916091997U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3766347619186305854U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11004616087340082895U;
            aOrbiterG = RotL64((aOrbiterG * 14469267845747063735U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17600791542296175812U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2556224430252009744U;
            aOrbiterF = RotL64((aOrbiterF * 14469426539907112137U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8575243768637573595U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9439245636611632007U;
            aOrbiterK = RotL64((aOrbiterK * 7519813655810877223U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8376104683205641052U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16877378648551624650U;
            aOrbiterB = RotL64((aOrbiterB * 13806644088125335467U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8060622208866138617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4204560462077827182U;
            aOrbiterH = RotL64((aOrbiterH * 8407034104111382011U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 43U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 6U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterF, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 56U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererA = aWandererA + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16208U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 15999U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15277U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 12199U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 18U)) + 1708250618750199233U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 57U)) + 12009147777553691142U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 53U)) + 8393982703399156592U;
            aOrbiterH = (aWandererI + RotL64(aCross, 5U)) + 3247327098356831221U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 43U)) + 3403590155376353737U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 29U)) + 18197244558104735044U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 3096253642040701606U;
            aOrbiterC = (aWandererH + RotL64(aCross, 11U)) + 8012692688785412179U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 23U)) + 17531946907545680745U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 17687695944270225817U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 48U)) + 16147773866007628769U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18244641303026196497U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10599266240854068246U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2056723540756216155U;
            aOrbiterI = RotL64((aOrbiterI * 13311591601230386375U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4629354220460621284U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9505955649473204942U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 17775391885312236187U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17078153810088721310U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9470436761716263000U;
            aOrbiterK = RotL64((aOrbiterK * 5431855497250357229U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3305863413630104742U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14377172434239576161U;
            aOrbiterC = RotL64((aOrbiterC * 6880176890091033423U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 415687827894226513U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 16975319836893760993U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12707054129431596074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8974182792497231239U;
            aOrbiterB = RotL64((aOrbiterB * 7874658957269462717U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10826131924322955095U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4168545139712703154U;
            aOrbiterH = RotL64((aOrbiterH * 10305904857550051705U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4539070253658625193U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3737870219498561326U;
            aOrbiterF = RotL64((aOrbiterF * 13130847633918921393U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11563084648810555040U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7410695535361901473U;
            aOrbiterJ = RotL64((aOrbiterJ * 7540855656023807389U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6687453696858775037U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1708250618750199233U;
            aOrbiterD = RotL64((aOrbiterD * 13104250803527718135U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterF, 24U));
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterI, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterJ, 34U));
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 26U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererC, 36U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17311U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 21520U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20654U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18211U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 54U)) + RotL64(aCarry, 21U)) + 8367680518550579791U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 11491674725611181241U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 41U)) + 16673861720782164214U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 43U)) + 9786610124108350855U) + aPhaseFOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 5745080601557577637U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 5U)) + 1959402215131684684U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 57U)) + 6121650036079196522U) + aNonceWordE;
            aOrbiterA = (aWandererI + RotL64(aScatter, 11U)) + 12016309761037342392U;
            aOrbiterG = (aWandererH + RotL64(aCross, 35U)) + 5986936646177049603U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 24U)) + 1000367700904043468U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 39U)) + 17425288243569101032U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4856917474950325209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16312111093223166419U;
            aOrbiterJ = RotL64((aOrbiterJ * 11046477664487805241U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 456110002032422270U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11393724374787795662U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 1176984359123668389U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8378176867715697176U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8086186452345234815U;
            aOrbiterE = RotL64((aOrbiterE * 8450438271765985235U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8470349167474173245U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2528229938740192694U;
            aOrbiterC = RotL64((aOrbiterC * 8717790851266520943U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13247168811545753141U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8745293957516815264U;
            aOrbiterA = RotL64((aOrbiterA * 14270617180621072619U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6165915500564961987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12015407798844173213U;
            aOrbiterG = RotL64((aOrbiterG * 3913451986559154153U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 545006684939922156U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16366753936267185001U;
            aOrbiterD = RotL64((aOrbiterD * 6495185976430013201U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3097605623436091728U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15950167830259022926U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4415538963984293323U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8356327899232213426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10183421678251169945U;
            aOrbiterB = RotL64((aOrbiterB * 9474380650337109299U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16327340177970834683U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7086901180933495535U;
            aOrbiterI = RotL64((aOrbiterI * 1276521829484494857U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13421211370092080006U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8367680518550579791U;
            aOrbiterH = RotL64((aOrbiterH * 12256662446176946163U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterI, 38U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterG, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 6U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22625U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26948U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22634U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 26337U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 16183871922837164759U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 7002058258090219055U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 23U)) + 5650868611888303705U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 58U)) + 11899839660943876690U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 3U)) + 15349649504488111111U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 11U)) + 14060149569086744970U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 12920917574225030112U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 2831994965175330135U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 54U)) + 18312543585028439192U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 39U)) + 11657562205118394239U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 37U)) + 10850792819281246052U) + aNonceWordM;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17810371216216125323U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7963413941144223128U;
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5498715358793875584U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9256727548911651373U;
            aOrbiterE = RotL64((aOrbiterE * 10498848323914000989U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17246360111302191699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 18309978718113983369U;
            aOrbiterC = RotL64((aOrbiterC * 18267472694666221077U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3100998994319502921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8129301860291235970U;
            aOrbiterI = RotL64((aOrbiterI * 17847033539279176187U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1889641029473279114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16538494307002917945U;
            aOrbiterF = RotL64((aOrbiterF * 8081488217920885783U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5432230549146849322U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2634437941396090817U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7612999214758935211U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16940172599174185058U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13151669140593952203U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16225319638131723487U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3995064294869931681U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 913081077665768816U;
            aOrbiterA = RotL64((aOrbiterA * 9299514648768060453U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2469001696075411481U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 2167390955194185443U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11805065572289005223U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1574066406534010796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8736976961589874013U;
            aOrbiterJ = RotL64((aOrbiterJ * 5980070607180321955U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4233621443153132083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16183871922837164759U;
            aOrbiterG = RotL64((aOrbiterG * 4030569514959370895U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 41U)) + aOrbiterF) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 56U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((RotL64(aScatter, 6U) + aOrbiterF) + RotL64(aOrbiterH, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterF, 50U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30250U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32298U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30166U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30224U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 1457104756581596530U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 23U)) + 6127240317844622874U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 53U)) + 16492290056044189421U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 10963676850938416468U) + aNonceWordE;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 41U)) + 4872917367399752405U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 39U)) + 15218882377875616148U;
            aOrbiterG = (aWandererB + RotL64(aCross, 13U)) + 5934166612122118251U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 10U)) + 14215280930872003003U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 11428034799044600979U) + aPhaseFOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 35U)) + 5453003654321728726U;
            aOrbiterK = (aWandererA + RotL64(aCross, 27U)) + 14273775120265649389U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 328723770018440271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13032190719588211088U;
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2386881543033598494U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1649501123340887116U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11148976582360499033U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16462401546754210583U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1510579201823042227U;
            aOrbiterE = RotL64((aOrbiterE * 16287912400104043275U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6889066000014251983U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11324594596597724357U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15344987814648586023U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12237796033168436537U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17306069670330000343U;
            aOrbiterA = RotL64((aOrbiterA * 3167451351403385259U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14197284538008811658U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4754134852883071927U;
            aOrbiterJ = RotL64((aOrbiterJ * 3484427259538998699U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17201907781639753736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8318419319239859855U;
            aOrbiterC = RotL64((aOrbiterC * 10320390501983802091U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16012488623961565780U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15583721012865354925U;
            aOrbiterK = RotL64((aOrbiterK * 10656414363201743961U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14680351201973315018U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14483973292275372321U;
            aOrbiterF = RotL64((aOrbiterF * 9279222721410811027U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16324317860030681248U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7038506963317910910U;
            aOrbiterI = RotL64((aOrbiterI * 2960451734542956767U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12767672960346001218U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1457104756581596530U;
            aOrbiterB = RotL64((aOrbiterB * 1560375242310194691U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 26U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 28U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterB, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 14U) + RotL64(aOrbiterH, 14U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 52U)) + aOrbiterJ) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 839U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 4835U)) & W_KEY1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2417U)) & W_KEY1], 18U) ^ RotL64(mSource[((aIndex + 3029U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 28U) + RotL64(aCross, 13U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 15316464782468770057U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 6642872057476351588U;
            aOrbiterI = (aWandererK + RotL64(aCross, 58U)) + 660732654689529192U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 7235418086884000655U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 53U)) + 14784518476694580493U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 43U)) + 12222433977933449375U;
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 8573001207708329927U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 13U)) + 16035256260815013172U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 18U)) + 15767726974121910203U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17712217935322939971U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13488963456923357159U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16785285630840310405U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10222949131965611079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1495561412321657209U;
            aOrbiterE = RotL64((aOrbiterE * 9706305581868526265U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16156530750584361434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11544578291333360613U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3665587867634242865U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15248434984650998090U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15487979645426567581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6972347795052712690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16074994810010431338U;
            aOrbiterA = RotL64((aOrbiterA * 1262655238856775853U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16851139687900415292U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14630026837021552812U;
            aOrbiterB = RotL64((aOrbiterB * 9577900853521254603U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14236330619137368169U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17778707026111136216U;
            aOrbiterD = RotL64((aOrbiterD * 16239561893843454747U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9390961969105999083U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1174881758316573228U;
            aOrbiterK = RotL64((aOrbiterK * 6602061268277529311U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 14U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15625U)) & S_BLOCK1], 6U) ^ RotL64(mSource[((aIndex + 11276U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16140U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10285U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 34U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 10915618884692072446U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 12634922308499254909U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 60U)) + 6533934734564499389U) + aPhaseCOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 21U)) + 6744203303756105181U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 11U)) + 13086782386652045658U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 29U)) + 5693840533331397822U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 34U)) + 1803663542535024611U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 51U)) + 3597219300593287708U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 1429753448204448904U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17229017825587322715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1137574712801062932U;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2401991077004083378U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1332473247826139292U;
            aOrbiterF = RotL64((aOrbiterF * 15029831858261506447U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11730946340796899885U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4744141870145159917U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6067132201862688684U;
            aOrbiterD = RotL64((aOrbiterD * 6046100687757836027U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14991509179286371800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 4342608825699398682U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10240526103933275875U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3727521409410742075U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3302027219498304367U;
            aOrbiterK = RotL64((aOrbiterK * 12153634588200479559U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6039539483340398858U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2902581519976937051U;
            aOrbiterA = RotL64((aOrbiterA * 2057584328877854239U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12332784713738947242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13761272577223712786U;
            aOrbiterC = RotL64((aOrbiterC * 14930145045480030821U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2947946397617043735U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11107014023853644521U;
            aOrbiterH = RotL64((aOrbiterH * 15030903626191481831U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterI, 10U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterA, 37U));
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterG, 22U)) + aPhaseCWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19354U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24463U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17481U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 23795U)) & W_KEY1], 52U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + 6654158889644956636U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 11U)) + 9045779659363991870U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 3888897662136993491U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 21U)) + 6882016842864459345U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 52U)) + 15601891715956172291U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 5176811598629335350U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 12519945150889074325U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 5U)) + 4552583214397603278U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 14225482701804864688U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5485298070606280363U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11237713257388094289U;
            aOrbiterG = RotL64((aOrbiterG * 11032429223099413011U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14340345895626142788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16275167270553643347U;
            aOrbiterH = RotL64((aOrbiterH * 7308578867128951199U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14041860597556520250U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1436068974197066343U;
            aOrbiterE = RotL64((aOrbiterE * 3938460345031496843U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 11483155566419547004U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4608508534724289325U;
            aOrbiterJ = RotL64((aOrbiterJ * 13461385011638899485U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2389196334288832895U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4062682330273866602U;
            aOrbiterI = RotL64((aOrbiterI * 8787682133271101901U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5655656046585592034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7977947821249746880U;
            aOrbiterB = RotL64((aOrbiterB * 10082104644185964787U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11653718118543974168U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5456429682072377614U;
            aOrbiterK = RotL64((aOrbiterK * 12504180638665296649U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12457179652004203574U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 445821754230182952U;
            aOrbiterD = RotL64((aOrbiterD * 16043092621697786393U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12429505513284703263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12480745784412363537U;
            aOrbiterC = RotL64((aOrbiterC * 643617210585287593U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 34U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 29U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 48U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29490U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 26306U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28267U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 30018U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 11U)) + 8685374557928800912U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 30U)) + 3482312691892161229U) + aPhaseCOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 6948130297389161165U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 23U)) + 5506385663788942690U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 17859982009307397161U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 46U)) + RotL64(aCarry, 41U)) + 9178488809207094043U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 19U)) + 1835479501226057169U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 35U)) + 5368101733632614939U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 39U)) + 9050459666576835422U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9042186993119635078U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17528342580198295025U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6495418332558436882U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8834495762667327342U;
            aOrbiterA = RotL64((aOrbiterA * 10783141541937645995U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4364314196965690905U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6357485231062120459U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 289429584586504995U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3321488322626415347U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10817330671781848737U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15875919466358823335U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17974092279281611763U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2871472057292789157U;
            aOrbiterD = RotL64((aOrbiterD * 16104199340711015181U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15187929795092006849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13482063681546475923U;
            aOrbiterE = RotL64((aOrbiterE * 14466266308157364963U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6232152545071397380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17488906002621373262U;
            aOrbiterH = RotL64((aOrbiterH * 4719340606442742577U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12444819880507588549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13808941689757772497U;
            aOrbiterK = RotL64((aOrbiterK * 6541360905282412317U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8049361354387692374U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7137831335606542401U;
            aOrbiterG = RotL64((aOrbiterG * 11022231291507235007U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + (((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 18U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 22U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Lacrosse_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2133U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7623U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1293U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 6687U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 14U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 43U)) + 18255347001097480328U) + aPhaseDOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 13679246790311505735U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 51U)) + 10565839529765027116U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 21U)) + 14327172566224769901U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 16239024612038195174U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13800012174212131890U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13900288860157577583U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13177682776510523095U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4144386119777112740U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3154558262670631372U;
            aOrbiterB = RotL64((aOrbiterB * 13236911910092437063U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7456728543137614001U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11709519851158935384U;
            aOrbiterG = RotL64((aOrbiterG * 7016689518570071587U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15607438907832240304U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9276575329661725624U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8879744070762412745U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6459435969129449226U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6442382118416542275U;
            aOrbiterJ = RotL64((aOrbiterJ * 2921027306686588233U), 19U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 20U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13413U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((aIndex + 11353U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13053U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16259U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 6469584119078165548U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 14U)) + 14329756366517987910U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 12890831797059772123U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 3164503807500018990U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 43U)) + 177531431387646836U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3167421392893561015U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2813174781844753460U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9760688894575305115U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10953270419153249857U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16911518309710356951U;
            aOrbiterB = RotL64((aOrbiterB * 13162785997686570445U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6616750447844893150U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10276741398025985982U;
            aOrbiterJ = RotL64((aOrbiterJ * 6824712685896987133U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6206043608461213208U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12021552904553405793U;
            aOrbiterA = RotL64((aOrbiterA * 10023362889960174909U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15283586234744144846U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5923238786775948571U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8200882393521882651U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterB, 4U)) + aPhaseDWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17803U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22218U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21792U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 16508U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 50U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 13583136155674166402U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 11U)) + 12830472187484919497U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 29U)) + 18081197909484522509U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 8680634051297891550U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 27U)) + 13939998767458656823U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1795730579103692594U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17369751719734069999U;
            aOrbiterD = RotL64((aOrbiterD * 2633464694273697123U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 224769585901248068U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4133547085925268180U;
            aOrbiterA = RotL64((aOrbiterA * 2611561365156544735U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7022512056309567391U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10319484359046945495U;
            aOrbiterF = RotL64((aOrbiterF * 3400140531307001933U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10483878349412282069U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6481381149199985736U;
            aOrbiterK = RotL64((aOrbiterK * 9701719367082506253U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13721077228796934509U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9704818014314175007U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 30U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31986U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32300U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30562U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26108U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 17454559218352016650U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 46U)) + RotL64(aCarry, 35U)) + 8005709669325164803U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 13393741948412816357U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 27U)) + 3665865624348875553U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 37U)) + 8334142570031883436U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17226066128706139657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3319093033121522613U;
            aOrbiterC = RotL64((aOrbiterC * 17961784341097933029U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6657535603401588798U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5469746182326331147U;
            aOrbiterF = RotL64((aOrbiterF * 11315450342347794329U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17846791786050221418U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15939541003714896288U;
            aOrbiterH = RotL64((aOrbiterH * 1400351482213119809U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12076763190461077406U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3594038213596405284U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10244002692575821495U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8301291631324464622U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8460406137668390582U;
            aOrbiterI = RotL64((aOrbiterI * 9117147929757711595U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 53U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 14U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Lacrosse_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5326U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1771U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7998U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 5301U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + 785861751704720606U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 27U)) + 15968088718435606299U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 42U)) + RotL64(aCarry, 29U)) + 1393976526590347151U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 17240750947292745884U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 5U)) + 4921576136163183137U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 19U)) + 3334047873553153032U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 15086509978458408698U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 892391205397581998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2965686403183767521U;
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14632215393655706170U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15740589515342377322U;
            aOrbiterH = RotL64((aOrbiterH * 15677716942904794913U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11131164813943086445U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6988080581278900960U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6412189142344044255U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 16021254613117657178U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6183615599897921154U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12533992547026652747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3878525937957474644U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2120435259884368445U;
            aOrbiterK = RotL64((aOrbiterK * 15964718652193073177U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14928658302694194856U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9121310461310309348U;
            aOrbiterB = RotL64((aOrbiterB * 17304439784647477491U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 46U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8447U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8683U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13241U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10609U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 27U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + 9471546960258473684U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 57U)) + 18050235435948942244U;
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 3005107102671544641U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 17898396434573801850U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 15071602525497771648U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 5780119462702672108U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 36U)) + RotL64(aCarry, 21U)) + 13301326224151025687U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 18129323022260575961U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1199228670638790709U;
            aOrbiterK = RotL64((aOrbiterK * 1780426336211781025U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1839199978088021020U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4999517042246790165U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4585813675677234577U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8788607633376516299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16674732686428431869U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15908873150953195581U;
            aOrbiterF = RotL64((aOrbiterF * 18049755517524334107U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11204775359756474667U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2525984309543939465U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3988529812023791571U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4566345170476825512U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14876612901557406267U;
            aOrbiterD = RotL64((aOrbiterD * 9047956948845135339U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14926290877038883931U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12710203178186614846U;
            aOrbiterG = RotL64((aOrbiterG * 14841163494801662515U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 36U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23245U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21690U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21046U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 19757U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 47U)) + 7893287783892523139U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 10257331997383491153U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 27U)) + 14562226733652231753U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 4U)) + 14320342577110737851U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 9816717579822880756U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 9558926960095881953U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 21U)) + 9230371862654338324U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6414274291252913420U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 13868546184398350849U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1547986864837497409U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16940736952569949038U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2866957764814864371U;
            aOrbiterJ = RotL64((aOrbiterJ * 3554702178644797003U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7916721976073979724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1602444214978842275U;
            aOrbiterD = RotL64((aOrbiterD * 11072503711308122385U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9529061385251008037U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8402775110887376588U;
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15003592180290390713U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14195681406520825751U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11455000833788877217U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3263577002367714202U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12019422062655581928U;
            aOrbiterK = RotL64((aOrbiterK * 5002313835338447799U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8508638054582582917U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6536618106353552880U;
            aOrbiterF = RotL64((aOrbiterF * 6233964121117511885U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 28U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 44U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 48U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32194U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25385U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26026U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31863U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 42U)) + (RotL64(aPrevious, 29U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 27U)) + 5510690816044082200U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 15967820875033940530U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 539348720848176221U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 10U)) + 15779318183635560817U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14511058534424187469U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + 5811130556873428391U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 1085928476499444025U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6973335316600768130U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10747243745475009744U;
            aOrbiterI = RotL64((aOrbiterI * 17322489216048017061U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1072260008981349754U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2018772405352495753U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10840562112080574241U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1092091597048996547U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15103140149542167197U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13194619321108681542U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16749188603268621850U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9575408950550922039U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7427959503086895166U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9895804051379551393U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2701997336201570715U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4526020800679774259U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4484850928870048176U;
            aOrbiterB = RotL64((aOrbiterB * 17556987520625677313U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1837404844299040155U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15213208978489570694U;
            aOrbiterK = RotL64((aOrbiterK * 7062740584650274133U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 34U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Lacrosse_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6749U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2962U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5297U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 5373U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 5510690816044082200U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 15967820875033940530U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 22U)) + RotL64(aCarry, 53U)) + 539348720848176221U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 15779318183635560817U) + aPhaseFOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 39U)) + 14511058534424187469U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5811130556873428391U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1085928476499444025U;
            aOrbiterC = RotL64((aOrbiterC * 13965845678632598921U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6973335316600768130U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10747243745475009744U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17322489216048017061U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1072260008981349754U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2018772405352495753U;
            aOrbiterD = RotL64((aOrbiterD * 10840562112080574241U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1092091597048996547U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15103140149542167197U;
            aOrbiterJ = RotL64((aOrbiterJ * 621856991658027989U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 13194619321108681542U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16749188603268621850U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9575408950550922039U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererG, 28U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13014U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9496U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12741U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 16350U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 3684295017013759987U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 6740408842457292881U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 4563975890702399441U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 11U)) + 797804144825287940U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 20U)) + 2763779540450101303U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13211846164102089685U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15214578447281401982U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12107189619131483661U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13745208628754232427U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17358621225969190747U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5325024317338823061U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 779739369960480023U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4370963533701407813U;
            aOrbiterF = RotL64((aOrbiterF * 3123135216876641039U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6061333005507739975U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3589705340762734456U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16499293983611196967U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10607697666369230567U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9356757995305239271U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10945513661439954731U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 22U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 28U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 18U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23253U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22914U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22469U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 20428U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 9023059520606551446U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 27U)) + 662441755115638133U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 41U)) + 16957253361196144712U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 7840955025765308605U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 346855809270395799U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16099139781586668343U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3706457327118322098U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7810030620470889591U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12166825885547622870U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7792658665720344200U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7128477606152986326U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11116533962780290084U;
            aOrbiterB = RotL64((aOrbiterB * 11993485572912492297U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10443889548568288532U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4402387036946561017U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9032964741841833277U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13002706161178447654U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13929727277530310708U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7005639090871200285U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 4U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28797U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27539U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28649U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 32397U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 40U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 11039986441331892533U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 48U)) + 6256024955965426119U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 9857443189988995666U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 11900944813380998208U;
            aOrbiterA = (aWandererH + RotL64(aCross, 13U)) + 8422577734978875541U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3100835100713928724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11871553509810206993U;
            aOrbiterG = RotL64((aOrbiterG * 15501681886909921677U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17614749493763417027U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 3638372131856199916U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 480683274898147025U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6582275259281025770U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17016882418498941958U;
            aOrbiterB = RotL64((aOrbiterB * 4269869255230867823U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1747214688658984715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9356088987044015278U;
            aOrbiterD = RotL64((aOrbiterD * 16221733545319753695U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4056238112133473456U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16013150119949532998U;
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 12U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Lacrosse_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7736U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 3959U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 172U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5395U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 42U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 14U)) + RotL64(aCarry, 27U)) + 5960680319644404115U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 16050752633567034185U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 8447503223226854741U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 14176813813397917591U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 43U)) + 10534915376130006644U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6866224454375302514U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16506374165041008396U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1326855300197233833U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7167814023968794098U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13870852197416596664U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17015971222069856463U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18064038854848993105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9869630811507771691U;
            aOrbiterI = RotL64((aOrbiterI * 13723164383800461387U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 863613100452759380U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16597969741225436529U;
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6575347108051310653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterC = RotL64((aOrbiterC * 7601045488473620019U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 30U)) + aOrbiterE) + aPhaseGWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 24U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15018U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 12827U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8239U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10492U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 4U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 50U)) + RotL64(aCarry, 51U)) + 7948891781097675369U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 13928362874228230226U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 10776180542602258926U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 3U)) + 5735115172149470447U) + aPhaseGOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 19U)) + 5353591822981766987U) + aPhaseGOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 562301708107268570U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10467810247578364868U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10449089554007059823U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14541630141152308564U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2350076897065139429U;
            aOrbiterF = RotL64((aOrbiterF * 12222554362482034393U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17519109078651162228U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6061035173339902910U;
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15654836633731000065U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13723521735153718904U;
            aOrbiterC = RotL64((aOrbiterC * 14459516479283070563U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2849680038315532197U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17336102435576647923U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 44U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 17624U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22531U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17445U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21524U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 1042610313571524121U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 35U)) + 3505725321008825582U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 12584654563843782991U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 6645399144515770935U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 11U)) + 3608978423753715584U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8089198857670370983U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15207251813516399879U;
            aOrbiterG = RotL64((aOrbiterG * 7596841660069752069U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9579268660105824516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16055044469473802812U;
            aOrbiterB = RotL64((aOrbiterB * 2269649280637188723U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 583811872609805949U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7027491967970873942U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12686754713465826139U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18256061823189677508U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12708429127816136937U;
            aOrbiterH = RotL64((aOrbiterH * 12593886633108075321U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 12169216645156306078U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12694325407567795065U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3711789483877261899U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 56U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 56U)) + aOrbiterG) + aPhaseGWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26425U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26420U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30439U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 27664U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 29U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 9751314027302668907U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 12175450995523107056U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 17519694958730119552U;
            aOrbiterA = (aWandererI + RotL64(aCross, 13U)) + 9093525527925682263U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 4U)) + 3713831321786810138U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10108355209191835040U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12956307447311314768U;
            aOrbiterC = RotL64((aOrbiterC * 9198936928658626667U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1904298513945877359U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4658049993308574460U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10482422152074338611U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9826333658248851902U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12058666914724365134U;
            aOrbiterA = RotL64((aOrbiterA * 964233873188373939U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2516574707110528099U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13335308331049750235U;
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8230749255538495304U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16536559486797811486U;
            aOrbiterK = RotL64((aOrbiterK * 7097036838156464969U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterA, 37U)) + aPhaseGWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 46U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Lacrosse_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7800U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4672U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1153U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 1794U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 12311607308490066301U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 13100864684740679846U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 37U)) + 13697304189274329704U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 9047976902871216732U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 29U)) + 2147897579538537888U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2072444829390996142U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2129307836981020908U;
            aOrbiterG = RotL64((aOrbiterG * 8065769537670939667U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10663145333751112064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15019844390503785459U;
            aOrbiterD = RotL64((aOrbiterD * 7442321463110790449U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5460865577557928142U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15806522559993224197U;
            aOrbiterB = RotL64((aOrbiterB * 8722932687972240099U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6361113778657833389U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8306013884615042570U;
            aOrbiterK = RotL64((aOrbiterK * 8234258702656728667U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4038420580499706912U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11908091484457158973U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3964111175645156719U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterK, 21U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterK, 44U)) + aPhaseHWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15028U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((aIndex + 13633U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9927U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 9115U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 34U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aCross, 22U)) + RotL64(aCarry, 27U)) + 7075016829833562104U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 8783765886115517036U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 13U)) + 2996723892384565829U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 9494134707342189476U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 47U)) + 5052642981395679904U) + aPhaseHOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8766787055127962238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4467211954388738079U;
            aOrbiterJ = RotL64((aOrbiterJ * 8599295330343804047U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8030255604633658608U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16962408063455702251U;
            aOrbiterA = RotL64((aOrbiterA * 11171737929747471631U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3768222186567699076U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14930990410207899871U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14179761938395502502U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterF = RotL64((aOrbiterF * 16783034788172670121U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5535012408925981515U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12792553516710295939U;
            aOrbiterD = RotL64((aOrbiterD * 8577530993755159329U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterF) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 18U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererF = aWandererF + (((RotL64(aCross, 56U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18116U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 21054U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20760U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 22263U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 39U)) + 6771552164800695068U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 29U)) + 12131763371571322040U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 12U)) + RotL64(aCarry, 3U)) + 3326182381395522013U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 12288775097697156383U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 5195948373449796741U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14404044002250137144U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11142382920035825426U;
            aOrbiterC = RotL64((aOrbiterC * 8134413822789107595U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2967149520256475485U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1470907369577818097U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9398653295177725883U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9231668148004163910U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13078929163913892386U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7509829068700523627U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9485274692075657877U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12216951187543631673U;
            aOrbiterI = RotL64((aOrbiterI * 6571066246507310805U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6933334652581744234U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17260276102423580920U;
            aOrbiterF = RotL64((aOrbiterF * 7796879893790990605U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterD, 48U));
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererD, 36U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26153U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((aIndex + 28676U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26936U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32357U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 44U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 4068921616130916949U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 39U)) + 12077715273915151726U) + aPhaseHOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 16047546802670596833U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 57U)) + 9690277462716999763U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 3U)) + 14484814700447992628U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17089267243053958210U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9138746214446211147U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8244950097712975043U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10181001536979097045U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6657458969093373191U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4311019792293202747U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7515983477876590988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3039935555863947600U;
            aOrbiterI = RotL64((aOrbiterI * 12511160550780270119U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16209389224740851136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 725253312098083182U;
            aOrbiterH = RotL64((aOrbiterH * 17535989492095522597U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13307041115748941383U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7159572004825238263U;
            aOrbiterG = RotL64((aOrbiterG * 4855009895002398449U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 4U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
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
