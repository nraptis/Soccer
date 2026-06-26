#include "TwistExpander_Soccer_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Soccer_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDEE9AD532E49CFD9ULL + 0xF36B45BF3CDD0747ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC8D459AFEB81F47DULL + 0xEC0B27AD36F74A83ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA252BE5470567FEFULL + 0xF64FA38F97A776A0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xED84B7327FB32003ULL + 0xF8D1EFDF682AB3F1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF7EDEB8B18D02DD1ULL + 0xD0D9E3E13C1962E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x87049AA3D534D421ULL + 0xF83930E1ECDCD31AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF4E0AA9F570C7E27ULL + 0xF244567BC4DDABF0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8FCB268625C5DB05ULL + 0xD8B7ACFB40545BE1ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    [[maybe_unused]] std::uint8_t *mSnow = pSnow;
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
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, mSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordE, 41U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3047U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((aIndex + 3092U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordG, 13U)) ^ RotL64(aNonceWordB, 22U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2294U)) & S_BLOCK1], 37U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 1976U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 4U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 5U)) + 1708250618750199233U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 44U)) + 12009147777553691142U) + RotL64(aNonceWordC, 5U);
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 51U)) + 8393982703399156592U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 3247327098356831221U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 37U)) + 3403590155376353737U) + RotL64(aNonceWordG, 4U);
            aOrbiterB = ((aWandererE + RotL64(aIngress, 40U)) + RotL64(aCarry, 37U)) + 18197244558104735044U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 23U)) + 3096253642040701606U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 8012692688785412179U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 17531946907545680745U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 17687695944270225817U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 3U)) + 16147773866007628769U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18244641303026196497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8839160526348897457U;
            aOrbiterJ = RotL64((aOrbiterJ * 14268021129087663397U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10599266240854068246U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13311591601230386375U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4629354220460621284U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9505955649473204942U;
            aOrbiterC = RotL64((aOrbiterC * 17775391885312236187U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17078153810088721310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9470436761716263000U;
            aOrbiterH = RotL64((aOrbiterH * 5431855497250357229U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3305863413630104742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14377172434239576161U;
            aOrbiterI = RotL64((aOrbiterI * 6880176890091033423U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 415687827894226513U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16975319836893760993U) ^ RotL64(aNonceWordH, 41U);
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12707054129431596074U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8974182792497231239U;
            aOrbiterE = RotL64((aOrbiterE * 7874658957269462717U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10826131924322955095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4168545139712703154U;
            aOrbiterA = RotL64((aOrbiterA * 10305904857550051705U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4539070253658625193U) + RotL64(aNonceWordE, 19U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3737870219498561326U;
            aOrbiterD = RotL64((aOrbiterD * 13130847633918921393U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11563084648810555040U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7410695535361901473U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7540855656023807389U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6687453696858775037U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1708250618750199233U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13104250803527718135U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterJ, 44U)) + RotL64(aNonceWordF, 53U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterI, 12U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + RotL64(aNonceWordD, 21U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: mSource, mSnow, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 30U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 9145U)) & S_BLOCK1], 3U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 6006U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordE, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8879U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((aIndex + 9327U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 37U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 17264605017518259932U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 15209184354580778643U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 3299527965014731384U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 51U)) + 16293096431816127821U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 37U)) + 11031983436878828337U) + aOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 3U)) + 9188018632448236358U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 39U)) + 13420816400363406556U) + RotL64(aNonceWordC, 49U);
            aOrbiterB = (aWandererA + RotL64(aIngress, 34U)) + 2485063384097917101U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 3089135816938128264U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 53U)) + 10730544971770435788U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 23U)) + 10431767565618874806U) + RotL64(aNonceWordG, 61U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14883796491656899074U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 13465877783538483706U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordB, 3U);
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13322163435314643713U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3307316600284371955U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4950101626975919939U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7181706961838582889U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17961706029559914243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10321902557977495175U;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 18146616411403012772U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8414050129421955787U;
            aOrbiterH = RotL64((aOrbiterH * 14879448948196182863U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11739172334166341121U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7936637782633487291U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterG = RotL64((aOrbiterG * 14940929920543800413U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3160044627483874242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16816384076887379704U;
            aOrbiterJ = RotL64((aOrbiterJ * 5052772186568301951U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8101560104988710226U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8851416379738817624U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16767420038937389027U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9941784290055185679U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14495651885701938495U;
            aOrbiterB = RotL64((aOrbiterB * 1540692851998143607U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10599676325220702167U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16092000942942971187U;
            aOrbiterK = RotL64((aOrbiterK * 2457268192247656817U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16168470945107928109U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17264605017518259932U;
            aOrbiterI = RotL64((aOrbiterI * 15038386057529909273U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 60U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 52U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aNonceWordD, 50U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordA, 55U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 20U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 40U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordE, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 16368U)) & S_BLOCK1], 57U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 12857U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14895U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11769U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 44U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 37U)) + 9041099828460168106U;
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 12883711604096848454U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 17420968786226443079U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 12U)) + RotL64(aCarry, 13U)) + 3448213891716125104U) + RotL64(aNonceWordD, 50U);
            aOrbiterG = (aWandererG + RotL64(aIngress, 23U)) + 11866455977445336560U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 51U)) + 4119356835384495905U) + RotL64(aNonceWordG, 43U);
            aOrbiterB = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 2186212599698637068U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 21U)) + 6506144898969301620U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 46U)) + 12556800923644051626U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 41U)) + 4075551535185182945U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 35U)) + 17877694808492008749U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5553428900598223316U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14362304852277160675U;
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9174200302876075831U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16110739511917638547U;
            aOrbiterE = RotL64((aOrbiterE * 7004356839428657949U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10189881974519849402U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2128076632642616677U;
            aOrbiterF = RotL64((aOrbiterF * 8860453653433114929U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18133523799074400083U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9916472958834153766U) ^ RotL64(aNonceWordB, 59U);
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 10274457562795569227U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14134814273275356425U;
            aOrbiterH = RotL64((aOrbiterH * 15912501063665343159U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6394306369514735480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4825761192736485643U;
            aOrbiterJ = RotL64((aOrbiterJ * 12534544147331805643U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5672807934779206275U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3881953574159390421U;
            aOrbiterD = RotL64((aOrbiterD * 7448770570912161095U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12012232712634303203U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14176392925893052596U;
            aOrbiterA = RotL64((aOrbiterA * 11288668529893084583U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 307148402076391033U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15380446373458263079U;
            aOrbiterB = RotL64((aOrbiterB * 15228462337097647933U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4654312690816676129U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10818029316701301859U;
            aOrbiterI = RotL64((aOrbiterI * 16245734506125913215U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7340370713289840635U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9041099828460168106U;
            aOrbiterK = RotL64((aOrbiterK * 1807356802142268373U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 28U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 10U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterD, 21U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterK, 54U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 37U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 36U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterA, 51U)) + RotL64(aNonceWordA, 25U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aNonceWordC, 17U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 18230U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20045U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordC, 24U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18012U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17027U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aCross, 58U)) + 77518479758428414U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 21U)) + 4832061802166300011U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 11695291171006574112U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 11U)) + 7467412817843260094U) + RotL64(aNonceWordF, 53U);
            aOrbiterK = (aWandererA + RotL64(aIngress, 5U)) + 17801484124471154757U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 56U)) + 5555455638503958639U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 5669470540733721606U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 37U)) + 3042388456327784163U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + 2236734925228156691U) + RotL64(aNonceWordH, 47U);
            aOrbiterG = (aWandererH + RotL64(aScatter, 41U)) + 14459720401528685450U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 4814967631216658856U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16950679344449075945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6262238639302011050U;
            aOrbiterJ = RotL64((aOrbiterJ * 9942659897425088183U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3522256359074996724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12524717897707074242U;
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13891759914865623828U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11910250571469028666U;
            aOrbiterE = RotL64((aOrbiterE * 12311343917878428995U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2240189915640314069U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5365912986308810837U;
            aOrbiterF = RotL64((aOrbiterF * 15133972552032469957U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9323732721344489753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13087326560957916553U;
            aOrbiterB = RotL64((aOrbiterB * 14659491687401151733U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16398238057564892809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11517870519285159224U;
            aOrbiterD = RotL64((aOrbiterD * 1501848878469712681U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7758285512254776734U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17475149091906684720U;
            aOrbiterG = RotL64((aOrbiterG * 6015816725428299273U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2051631493975035243U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11684740065349595315U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10918975496337269197U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 10575473798991451167U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8267005776169272822U;
            aOrbiterC = RotL64((aOrbiterC * 13166868678285963961U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6249698995716039231U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13808085811784323978U) ^ RotL64(aNonceWordC, 29U);
            aOrbiterH = RotL64((aOrbiterH * 3897731011582061983U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2739364646624876985U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 77518479758428414U;
            aOrbiterI = RotL64((aOrbiterI * 6977724811175035551U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 36U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterG, 10U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 52U) + aOrbiterE) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 46U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aNonceWordA, 55U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 54U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 22003U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 26342U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25423U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25486U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aCross, 29U)) + 13583136155674166402U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 10U)) + 12830472187484919497U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 21U)) + 18081197909484522509U) + RotL64(aNonceWordC, 21U);
            aOrbiterF = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 8680634051297891550U;
            aOrbiterE = (aWandererK + RotL64(aCross, 57U)) + 13939998767458656823U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 23U)) + 1795730579103692594U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 17369751719734069999U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 6U)) + RotL64(aCarry, 3U)) + 224769585901248068U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 41U)) + 4133547085925268180U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 3U)) + 7022512056309567391U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + 10319484359046945495U) + RotL64(aNonceWordH, 10U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10483878349412282069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6481381149199985736U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13721077228796934509U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9704818014314175007U;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6253040047758584339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16890211690273641226U;
            aOrbiterK = RotL64((aOrbiterK * 5622534399866057841U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6216227831265032436U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2023609047004658739U) ^ RotL64(aNonceWordE, 3U);
            aOrbiterC = RotL64((aOrbiterC * 3252332895698310147U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9201669637050388263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5106927540934338576U;
            aOrbiterI = RotL64((aOrbiterI * 6368134569042291431U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10080368957861445998U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10784789383436485808U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3794918350254445939U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15426339824951793026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17637144549368340331U;
            aOrbiterB = RotL64((aOrbiterB * 10971293914614704441U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9941300382181962134U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8118046374121322097U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8481945819050983127U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5138086185042567633U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7279942739248982986U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12911998308338410917U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12135610639038562853U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12945353426409788798U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7434977715954413699U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7534876598022096222U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13583136155674166402U;
            aOrbiterE = RotL64((aOrbiterE * 8194058098043157015U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 26U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + RotL64(aNonceWordA, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 30U)) + RotL64(aNonceWordB, 7U));
            aWandererK = aWandererK + ((((RotL64(aCross, 24U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 32602U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 30641U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 14U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29875U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28451U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 27U)) + 6733949564325516029U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 53U)) + 7304098437143918796U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 3923949518391777800U;
            aOrbiterK = (aWandererE + RotL64(aCross, 22U)) + 14243591003388927124U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 51U)) + 18329498724605410406U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 29U)) + 13118172167747037249U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 41U)) + 5272025143849174212U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 19U)) + 16075917179214318424U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 35U)) + 15263590648674658399U) + RotL64(aNonceWordD, 59U);
            aOrbiterE = (aWandererD + RotL64(aCross, 60U)) + 13730046728289525921U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 7703141464499623408U) + RotL64(aNonceWordH, 56U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1382279753822135359U) + RotL64(aNonceWordE, 3U);
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2973369221699098292U;
            aOrbiterG = RotL64((aOrbiterG * 7440242040663550631U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11578274119583013219U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3419411247737896674U;
            aOrbiterJ = RotL64((aOrbiterJ * 17814942652262802991U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2582783513078999303U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3959762790273529677U;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 465795011576934604U) + RotL64(aNonceWordF, 51U);
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17880826624185821135U;
            aOrbiterC = RotL64((aOrbiterC * 4445949147592860913U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10819659185349413173U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17298208553586835030U;
            aOrbiterA = RotL64((aOrbiterA * 1965860510614222093U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12585880006661489402U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16650193903267408586U;
            aOrbiterB = RotL64((aOrbiterB * 5781132589396936615U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 885882046325991589U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 869560078374809974U;
            aOrbiterE = RotL64((aOrbiterE * 13440973563438747181U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11871305571797951851U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12137095015607196226U;
            aOrbiterH = RotL64((aOrbiterH * 7618152256560808581U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6044048326509186958U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 622564532811968856U;
            aOrbiterF = RotL64((aOrbiterF * 14988345089359014037U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17133994029325040272U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8612895899003926829U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2128664397481732179U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2169081503433534750U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6733949564325516029U;
            aOrbiterK = RotL64((aOrbiterK * 10062179904046311601U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 24U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 36U)) + aOrbiterG) + RotL64(aNonceWordA, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Soccer_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD91283B990D8D7C3ULL + 0xCAEEF14F87E4529DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD4E4BD135AED0FC3ULL + 0x8E8A1B63CD4E12C4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEA3EEDBE70A45299ULL + 0xF1B23E2F74EB46FDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x91E0EF277E686667ULL + 0xC47BAD2A479649D4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD6A87559C0CE5615ULL + 0xE7BB9BFC7AA4111EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFE7EB5520AD88F93ULL + 0xDA562F61FA7CAFE3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9B9DB7F1DB03E743ULL + 0x91312B4365AE8301ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB622C337E465BDADULL + 0xA0B06F16AC7EDB3DULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordB, 60U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4453U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 4929U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2498U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6760U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 51U)) + 9914837590440975587U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 51U);
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 6706125076401958051U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 29U)) + 16570817772679258409U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 24U)) + 6843705658115186948U;
            aOrbiterA = (aWandererH + RotL64(aCross, 19U)) + 16099930446791572351U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 5420550009556030459U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 43U)) + 5729549069420177477U) + RotL64(aNonceWordD, 21U);
            aOrbiterK = ((aWandererD + RotL64(aScatter, 12U)) + RotL64(aCarry, 29U)) + 15590601126188675834U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 13044027390998620029U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11068338135659636772U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6584988841809544332U;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8516813219883915404U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10647314042912492785U;
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 201691689889605304U) + RotL64(aNonceWordA, 27U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3883760518944464145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12019138626550801486U) + RotL64(aNonceWordH, 42U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13030350224959652248U;
            aOrbiterJ = RotL64((aOrbiterJ * 11724200983306280107U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2643807255422544248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14602951930809633069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4555737199162278494U;
            aOrbiterG = RotL64((aOrbiterG * 12415825635220991865U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6343143902997169834U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10404783711336491985U;
            aOrbiterB = RotL64((aOrbiterB * 6235474458879439079U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7406959231434835393U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6684368109277850196U;
            aOrbiterA = RotL64((aOrbiterA * 8760360417572331159U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 12U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 60U)) + aOrbiterK) + RotL64(aNonceWordE, 55U));
            aWandererC = aWandererC + (((RotL64(aCross, 10U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordC, 39U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 44U) + RotL64(aOrbiterB, 56U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordD, 54U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15575U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 14540U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordC, 4U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14713U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8939U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 22U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 19U)) + 14499676118633326000U;
            aOrbiterF = (aWandererG + RotL64(aCross, 3U)) + 17191273593018552288U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 56U)) + 4085176294948097737U) + RotL64(aNonceWordF, 11U);
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 43U)) + 11112671474158908186U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 8745787969012266485U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 11U)) + 18074049663777707948U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 2543758649719164688U) + RotL64(aNonceWordD, 19U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 27U)) + 4659584749412700523U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 41U)) + 974639159259871273U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9211220687971081987U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8567024626862182714U;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5803002132294840900U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterG = RotL64((aOrbiterG * 4501441062617123165U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9470807228394903442U) + RotL64(aNonceWordH, 42U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1692347973120388469U;
            aOrbiterI = RotL64((aOrbiterI * 17433393164156231575U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16510815732690193145U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1518824876475937620U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 701225390867330446U;
            aOrbiterH = RotL64((aOrbiterH * 12264618860580199927U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8425976693733003889U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7182176375442410367U;
            aOrbiterA = RotL64((aOrbiterA * 8860605703761731859U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4546566785167467924U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2593340999038753749U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10152461487764567563U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9756331608356622299U) + RotL64(aNonceWordB, 39U);
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5511625814747641978U;
            aOrbiterK = RotL64((aOrbiterK * 4806076157539829529U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8694400787420160733U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12648969491371382682U;
            aOrbiterF = RotL64((aOrbiterF * 5346585704222643759U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 12U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 45U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterA, 50U)) + RotL64(aNonceWordE, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23054U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((aIndex + 21124U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 60U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21929U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 22456U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aScatter, 51U)) + 13174219512651137892U) + RotL64(aNonceWordE, 23U);
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 39U)) + 2715455762789269341U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 1338018183235594313U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 56U)) + 16566866551729552930U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + 6901845297307236726U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 27U)) + 2476078302049201718U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 15531109473927052260U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 23U)) + 4087849380858572351U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + 5167830630098599644U) + RotL64(aNonceWordF, 20U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 7275995452428627217U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14794340370010024117U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8779497557416568379U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8509217403041662849U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2321522025240806996U;
            aOrbiterB = RotL64((aOrbiterB * 113568101672878697U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5676672952755594051U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2304681269233504384U;
            aOrbiterC = RotL64((aOrbiterC * 15731441084605554497U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8383399721062437300U) + RotL64(aNonceWordB, 51U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13181984036942227666U;
            aOrbiterG = RotL64((aOrbiterG * 1648761328771932069U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13602604532551684210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12725687663616352843U;
            aOrbiterI = RotL64((aOrbiterI * 4684699861686199753U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5831790822416009806U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4535048543735457407U;
            aOrbiterK = RotL64((aOrbiterK * 12076777878870257053U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10617608605149381858U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5244225377862618630U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15307177251167023999U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18229989093139888456U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9728120630096192811U) ^ RotL64(aNonceWordG, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 16052574428163231023U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1312233443099767304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8043115602160128619U;
            aOrbiterH = RotL64((aOrbiterH * 9365756845731616963U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 56U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 48U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + RotL64(aNonceWordC, 31U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterH, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterG, 23U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + RotL64(aNonceWordA, 9U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 18U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordA, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30597U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30923U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 14U) ^ RotL64(aNonceWordE, 29U)) ^ RotL64(aNonceWordB, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25378U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 28790U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 39U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 23U)) + 13960289014350612206U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 11U)) + 3483331015269589730U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 45U);
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + 6873299241002444518U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 60U)) + 3562094007125534229U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 11422367439932782705U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 532453428514259816U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 17810941465810193088U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 4U)) + 11869759058631106331U) + RotL64(aNonceWordF, 25U);
            aOrbiterB = (aWandererI + RotL64(aPrevious, 29U)) + 8837581071876177566U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17185378327053837778U) + RotL64(aNonceWordH, 38U);
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7578253375676981500U;
            aOrbiterF = RotL64((aOrbiterF * 13371647568758721729U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17112646434432814442U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14949096407295697881U;
            aOrbiterA = RotL64((aOrbiterA * 14770977858283051753U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4259590620758467836U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6534899413644542303U;
            aOrbiterJ = RotL64((aOrbiterJ * 7987609419215568661U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2637407498893694243U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 15819295597921425711U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordC, 15U);
            aOrbiterG = RotL64((aOrbiterG * 5202015597375051399U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6373559542002699718U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11694562937392022505U;
            aOrbiterC = RotL64((aOrbiterC * 9311557972331218597U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3308736483775453062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12749929710650475901U;
            aOrbiterK = RotL64((aOrbiterK * 248428400724560945U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1569528215675579656U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1044077933631689572U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6443796233912755143U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8393422728124537471U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2002732612516530754U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13702146823622364279U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13469191942843147943U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7633171368709520560U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9713514012478203047U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterJ, 58U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aNonceWordE, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterB, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 18U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterB) + RotL64(aNonceWordA, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 51U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 38U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Soccer_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x81298D32AE85FD57ULL + 0xFFEE37AB9FB2ED24ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC49339765A4E7975ULL + 0xD26285692D607BF2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE3143EA4157B6C61ULL + 0xEF22A4E7C442BA42ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFC3EC535A0A035AFULL + 0xF8EFB56CDE3B985BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF3720551B442AC1BULL + 0xF47659262F022396ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x90F1FDE155E7849FULL + 0x868348DD74783AA2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9E4609E3682FF3F7ULL + 0xEFA906A37C50A6F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x81BA29BB0040632DULL + 0xB6937D20445E7307ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordB, 12U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3250U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6100U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordG, 34U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5430U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2927U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aCross, 36U)) + 2168513956284366370U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordA, 15U);
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 10290361969974613111U) + RotL64(aNonceWordF, 30U);
            aOrbiterI = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 15673836275828498050U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 16600540024145812236U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 23U)) + 9428052101528111892U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12763657928312763377U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10751286982008662485U;
            aOrbiterI = RotL64((aOrbiterI * 6169084301655877217U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1708230173038057979U) + RotL64(aNonceWordC, 17U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4011389705422783816U;
            aOrbiterH = RotL64((aOrbiterH * 11692237130784795961U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11704428328093077714U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2055336619674699284U;
            aOrbiterF = RotL64((aOrbiterF * 6374289210096410907U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1870865272102705804U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3574214263751923179U;
            aOrbiterC = RotL64((aOrbiterC * 13132083406834413563U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 984611970726966186U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 15207945449947643672U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) ^ RotL64(aNonceWordB, 23U);
            aOrbiterG = RotL64((aOrbiterG * 9539470161576639981U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterG, 40U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + RotL64(aNonceWordH, 43U));
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14385U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13835U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13509U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((aIndex + 10015U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 47U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 19U)) + 1297415699043177788U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 29U)) + 17583786534509260153U) + RotL64(aNonceWordC, 9U);
            aOrbiterH = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 643197858925708798U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 5062653766915694874U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 29U)) + 7034273638367180511U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordB, 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2026909726972916996U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 2785690475553211646U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ RotL64(aNonceWordA, 20U);
            aOrbiterH = RotL64((aOrbiterH * 6612792037861160393U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2910341716302991892U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2834181605200829791U;
            aOrbiterK = RotL64((aOrbiterK * 1510617068750957651U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13323052600571281928U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10434901530315760460U) ^ RotL64(aNonceWordG, 13U);
            aOrbiterE = RotL64((aOrbiterE * 2042210188346767033U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 247903955625194782U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterA = RotL64((aOrbiterA * 1799024689023272275U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7196305682377987476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14777739876892587484U;
            aOrbiterJ = RotL64((aOrbiterJ * 95220583948241581U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 56U) + aOrbiterE) + RotL64(aOrbiterK, 48U)) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE) + RotL64(aCarry, 5U)) + RotL64(aNonceWordE, 29U)) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordD, 7U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20257U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21787U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordA, 19U)) ^ RotL64(aNonceWordE, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16391U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 20796U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 56U)) + 9751314027302668907U;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 12175450995523107056U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 5U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 21U)) + 17519694958730119552U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 9093525527925682263U) + RotL64(aNonceWordG, 61U);
            aOrbiterI = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 3713831321786810138U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10108355209191835040U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12956307447311314768U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9198936928658626667U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 1904298513945877359U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordC, 19U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4658049993308574460U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10482422152074338611U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9826333658248851902U) + RotL64(aNonceWordB, 43U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12058666914724365134U;
            aOrbiterD = RotL64((aOrbiterD * 964233873188373939U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2516574707110528099U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13335308331049750235U;
            aOrbiterA = RotL64((aOrbiterA * 5880227828760598587U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8230749255538495304U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16536559486797811486U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7097036838156464969U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + RotL64(aCarry, 23U)) + RotL64(aNonceWordF, 50U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 44U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + RotL64(aNonceWordD, 31U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 19U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 18U) ^ RotL64(aNonceWordB, 47U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29369U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27668U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 41U) ^ RotL64(aNonceWordG, 53U)) ^ RotL64(aNonceWordA, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31700U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28122U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 29U)) + 964165145848253292U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 43U)) + 10645976767204934746U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 8241612229349212650U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 4159196033256913347U) + RotL64(aNonceWordH, 57U);
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 3U)) + 7194795864620233507U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordE, 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7638928444536778384U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11819105916503968109U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9052440449038441625U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18052213302858186237U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8663575313970041570U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14131073322476609161U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16644136720439299786U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 16930316530442679864U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordC, 23U);
            aOrbiterE = RotL64((aOrbiterE * 2650922074098320859U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 16251107616988250593U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordF, 61U);
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7171986193609401665U;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17885046834432626644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterI = RotL64((aOrbiterI * 15766885299397923879U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aNonceWordG, 60U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 58U)) + aOrbiterG) + RotL64(aCarry, 19U)) + RotL64(aNonceWordB, 53U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC3C3ECBCD1376AAFULL + 0xDA2382123A7A5767ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9263E0DEE4113FF9ULL + 0xF7772F05880037F5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC1CBF8055CAE7931ULL + 0xF197F41EAF0B1D74ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF1B89262D681C479ULL + 0xFA76A6DCF8AE95B0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEBCE6BABE5C1BB3FULL + 0x9CDCD9F312F266E3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9A9C577A4430AFEBULL + 0xC78538DCD57B3BDBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x83AADC81D53DABDDULL + 0xA5496FD9DC4D6ECFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFC64D8CF961EB4A7ULL + 0x9A310F7C8F5DC020ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2998U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7304U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 60U) ^ RotL64(aNonceWordC, 43U)) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3062U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7943U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 27U)) + 5131645209694953015U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 6U)) + 12070391048835379854U;
            aOrbiterK = ((((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 2604295836242338724U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 14042039029284001596U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 8914654543854559327U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 21U)) + 2185619407969359869U) + RotL64(aNonceWordH, 61U);
            aOrbiterA = (aWandererH + RotL64(aIngress, 43U)) + 5187406295103352574U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8022832481290871217U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8783061916740573472U;
            aOrbiterK = RotL64((aOrbiterK * 3309891377744201773U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 10711028365596196301U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13387065038269133571U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12444578026365205255U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11187001318931801582U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14191473173276034019U) ^ RotL64(aNonceWordA, 38U);
            aOrbiterB = RotL64((aOrbiterB * 2491253922434756431U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16207761776716426435U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9677408414452078760U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5487303383095129949U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17812460332794370649U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7736423148554132028U) ^ RotL64(aNonceWordF, 57U);
            aOrbiterF = RotL64((aOrbiterF * 15588733747232852555U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17293203944059014763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13487243633338010243U;
            aOrbiterH = RotL64((aOrbiterH * 9468688858740539095U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15979293016815060755U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17645215484691359547U;
            aOrbiterJ = RotL64((aOrbiterJ * 1449450767288733995U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 36U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 37U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterH, 11U)) + RotL64(aNonceWordD, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 27U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 48U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10625U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 12090U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordF, 44U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9154U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 11231U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 38U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 7270044678408187242U;
            aOrbiterG = (aWandererI + RotL64(aCross, 3U)) + 10192278965379756766U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 17568666746676060748U) + RotL64(aNonceWordH, 43U);
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 30U)) + RotL64(aCarry, 37U)) + 14312927531124963037U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 51U)) + 9825825726152087706U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 57U)) + 9696778570255265896U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + 17657841352013417228U) + RotL64(aNonceWordG, 31U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16207815085909628439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1752979206374514227U;
            aOrbiterA = RotL64((aOrbiterA * 14182667540650694199U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10456310689643905854U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16127830548663742550U) ^ RotL64(aNonceWordC, 20U);
            aOrbiterK = RotL64((aOrbiterK * 4355938404839045417U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2940917376003930842U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7353596864777649953U;
            aOrbiterJ = RotL64((aOrbiterJ * 7499468723171042005U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12725092740446150705U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5791296650856037010U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 760379251950502133U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1200130368046206150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16689604428598558547U;
            aOrbiterE = RotL64((aOrbiterE * 13815324235939996623U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14359561591103730856U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3975025843599045263U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterC = RotL64((aOrbiterC * 5025047888533298617U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14017901732955607601U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10431526786489555196U;
            aOrbiterH = RotL64((aOrbiterH * 10181915874476132407U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordB, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + RotL64(aNonceWordA, 27U));
            aWandererG = aWandererG + ((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordF, 39U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16680U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 18259U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordA, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23259U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16982U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 40U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 3105313968748067810U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 57U)) + 9977249451119627064U;
            aOrbiterK = ((((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 17941392803495349366U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 12U);
            aOrbiterA = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 4279533326705471133U) + RotL64(aNonceWordC, 61U);
            aOrbiterE = (aWandererF + RotL64(aCross, 48U)) + 13983828966811580039U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 29U)) + 3983490984234810378U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 21U)) + 308786542215259956U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8443607695364427037U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14939626441464340668U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16793255020331774983U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9350693577306121110U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1717071159396961752U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11062480662625054525U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15911765265202100610U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14898546272333182767U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterB = RotL64((aOrbiterB * 2674900543810733067U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3560903518513465868U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5367062725726860234U;
            aOrbiterA = RotL64((aOrbiterA * 8521908836601319553U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15233321480618877327U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9288449812290126074U) ^ RotL64(aNonceWordA, 53U);
            aOrbiterE = RotL64((aOrbiterE * 6815298520404038519U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5504840529511585676U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6825598386801620046U;
            aOrbiterC = RotL64((aOrbiterC * 11666542445846250077U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6433024450721339470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 97934156644929458U;
            aOrbiterI = RotL64((aOrbiterI * 8630530773006923215U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aNonceWordD, 31U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 4U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + RotL64(aNonceWordH, 27U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27574U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 27134U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordB, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27474U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((aIndex + 26459U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 4U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 22U)) + RotL64(aCarry, 13U)) + 13854738573712660276U) + RotL64(aNonceWordC, 35U);
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 16835460633412286294U;
            aOrbiterE = (aWandererK + RotL64(aCross, 35U)) + 6785859293758091931U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 3U)) + 126317283127992659U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 51U)) + 7568963536291415413U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordH, 21U);
            aOrbiterI = (aWandererE + RotL64(aCross, 41U)) + 12294016745653004819U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 18269588932920281147U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5872406424994751026U) + RotL64(aNonceWordE, 10U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7764434758831474129U) ^ RotL64(aNonceWordA, 41U);
            aOrbiterE = RotL64((aOrbiterE * 3772146788188420071U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4804168969415573371U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 959601763507651280U;
            aOrbiterI = RotL64((aOrbiterI * 4647396592804833217U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9257644462479293048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14332699366894494579U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10487012596470786004U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 612729229562321440U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11380387280507726003U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7845523921295625315U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12742115479740024747U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15578543510683986421U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10294667720904610944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14369711143154904567U;
            aOrbiterK = RotL64((aOrbiterK * 13753005602288309379U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10918344717497681894U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18136794828308636957U;
            aOrbiterD = RotL64((aOrbiterD * 17899418637978002409U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 20U) + aOrbiterJ) + RotL64(aOrbiterH, 20U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordD, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aNonceWordF, 17U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBBEC6D62F71F82D1ULL + 0xD041739A762CE5E5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9A2FC9302B225C7FULL + 0xCB39D5726C297EEAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDE00BDA752FE9465ULL + 0x8CEC7B335BD3FC75ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF0A0B7268F03DCF3ULL + 0x80BD3EFBEFC346F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD34913E65E6A7BE1ULL + 0xB3B548C849618553ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD8B1BFA0530AEBFBULL + 0xE018FBF5CB726063ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBBED9542739358E3ULL + 0xB1A8FA6E9F79E3DAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB591A5AC229D38E1ULL + 0x8EC72A077D367DB8ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 6183U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7679U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6798U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 185U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 11410829607777684449U;
            aOrbiterA = (aWandererK + RotL64(aCross, 60U)) + 7502698839700975347U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 37U)) + 13267685058252106173U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 238242706996630625U) + RotL64(aNonceWordD, 47U);
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 8184695499511454281U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + 12767823220461985403U) + RotL64(aNonceWordF, 7U);
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 29U)) + 12293198423143850330U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11149495229952495939U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7556992689338382800U;
            aOrbiterC = RotL64((aOrbiterC * 18232398462716803063U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3431338808774134649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16863099140844995099U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 752376661101787919U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17872458049880677604U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16760153457252546974U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11225037229069712805U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3115544493537438408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4359882942759752958U;
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13387113067202396536U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12955690074544490161U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15614054443728226807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1939441328066616114U;
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4599016263007782537U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9962305629016158048U) ^ RotL64(aNonceWordB, 29U);
            aOrbiterA = RotL64((aOrbiterA * 1496184427500037279U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aNonceWordH, 6U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 28U)) + RotL64(aNonceWordC, 9U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererF = aWandererF + ((((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 48U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13232U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11256U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16163U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15324U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 36U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 27U)) + 9654059367478508868U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 6473006635864677427U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 43U)) + 6944184481315853243U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordD, 23U);
            aOrbiterB = (aWandererE + RotL64(aPrevious, 57U)) + 4061496421939102306U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 27U)) + 15791809275719085463U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 19U)) + 14050798802646323055U) + RotL64(aNonceWordF, 43U);
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 12072905924741758266U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17639076509231343896U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12195388285571234715U;
            aOrbiterD = RotL64((aOrbiterD * 4317060502521195769U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4325404419499496529U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5910567888204238382U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11503787177122206937U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13092940059929942699U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6345904465930943295U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 15622862439323440527U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14027151901132249793U) ^ RotL64(aNonceWordC, 31U);
            aOrbiterF = RotL64((aOrbiterF * 2273573821630510087U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4584410023907605157U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15763755180625487157U) ^ RotL64(aNonceWordB, 5U);
            aOrbiterC = RotL64((aOrbiterC * 6755736130607297639U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17023059745666559199U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5298529579288492971U;
            aOrbiterK = RotL64((aOrbiterK * 2483562793328357721U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2870152867331654736U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12017191100173748848U;
            aOrbiterA = RotL64((aOrbiterA * 9958191466506480519U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + RotL64(aNonceWordG, 49U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterD, 29U));
            aWandererD = aWandererD + (((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 36U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordA, 44U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 44U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordC, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20338U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18083U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 42U) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20966U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 21742U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 27U)) + 10404808878585437255U) + RotL64(aNonceWordH, 21U);
            aOrbiterF = ((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 10587858736301591439U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 1430530909801644435U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 3U)) + 9090938022430118902U) + RotL64(aNonceWordD, 57U);
            aOrbiterK = ((aWandererD + RotL64(aCross, 53U)) + 12936604311751121235U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 13U)) + 1000583006020232032U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 12352532088997042232U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16723410947058502564U) + RotL64(aNonceWordB, 23U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16614089235313154270U;
            aOrbiterG = RotL64((aOrbiterG * 11530998303573027827U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 4245553025593349277U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3353146318549477494U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14246377408238318091U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5935727336135635196U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterA = RotL64((aOrbiterA * 1395964500396711899U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12192843181244744484U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2542570124502586365U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3315472769469002444U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17512858811783071174U;
            aOrbiterK = RotL64((aOrbiterK * 9070400454074283765U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16633218007427888082U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2502077714838858460U;
            aOrbiterB = RotL64((aOrbiterB * 970762420815997725U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14792910273226469214U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15739513291150783151U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11896279674116906915U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 35U)) + RotL64(aNonceWordA, 6U));
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterI, 20U)) + RotL64(aNonceWordG, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 4U) ^ RotL64(aNonceWordD, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31212U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26649U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordF, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30562U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32072U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 20U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 29U)) + 16651241552253078315U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 53U)) + 4558144676982478003U) + RotL64(aNonceWordD, 31U);
            aOrbiterA = ((((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 8814884320080367550U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordE, 60U);
            aOrbiterF = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 39U)) + 16011579668555672117U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 11U)) + 4738918668759862438U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 19U)) + 12526083125540985108U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 3U)) + 8048723561746000552U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1082218464034639039U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8432043246965946816U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7801965585991025451U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9982080524048636852U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6720069955755215919U;
            aOrbiterH = RotL64((aOrbiterH * 1025046364205332059U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1019035028070247757U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7360619079463870467U;
            aOrbiterC = RotL64((aOrbiterC * 6623074813047915863U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10893918488381348474U) + RotL64(aNonceWordB, 51U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1390297670907738019U;
            aOrbiterD = RotL64((aOrbiterD * 11909657437658597735U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12512200589031203480U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14741471280748399540U;
            aOrbiterE = RotL64((aOrbiterE * 3012135242889901095U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8543897248359826770U) + RotL64(aNonceWordC, 5U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8545972622733791272U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11793879362775346821U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7049384618581928664U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14730773807906925408U;
            aOrbiterI = RotL64((aOrbiterI * 10711566871536755073U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aNonceWordG, 59U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aNonceWordA, 11U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterA, 58U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererH, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Soccer_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB0ED3ED50D1DE5EFULL + 0xE02EF90D8D4E881CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC19985D689937783ULL + 0x9C5357D0E80E250FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8B083381FC0D2AEFULL + 0x93AD96F86A880D0DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA21E4CCB3865DBB3ULL + 0xCCE6B48364038B7FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD9FD40228A7D972BULL + 0x9ED3C8C67A32EBF8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8A0BEA187953E085ULL + 0xEDA82E4FE13AB872ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF2A33DD5B368A5F3ULL + 0xAFA3A1D919A196E4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEBACD9CCBA322567ULL + 0xD633FFEB5F7A2E94ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 13U) ^ RotL64(aNonceWordB, 30U)) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2647U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 4866U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordG, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3774U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7627U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 53U)) + 4980738603982643969U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 18U)) + 17660278413018470020U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 17598114429859543466U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 51U)) + 10993929335279994739U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 39U)) + 17967203122976322481U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 17U);
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 42U)) + RotL64(aCarry, 21U)) + 1872290205549034384U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 11U)) + 16607778671782810797U;
            aOrbiterI = (aWandererC + RotL64(aCross, 23U)) + 4895226930754394376U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 35U)) + 14960359005982301383U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 13U)) + 9921642352377700630U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 893281964367208693U) + RotL64(aNonceWordE, 7U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8232519988397858732U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4433022122758913407U;
            aOrbiterE = RotL64((aOrbiterE * 834240393225479419U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12689609831247168353U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 404535388957472176U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534020545479806593U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3349108201964013155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4386449511297371730U;
            aOrbiterH = RotL64((aOrbiterH * 9596273264321140229U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14314587717949070586U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10923886625271054985U;
            aOrbiterD = RotL64((aOrbiterD * 7838969002623486809U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17634909585329833520U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2021301459918350372U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterA = RotL64((aOrbiterA * 1388242915918642741U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5219599112498224367U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10641339455385046206U;
            aOrbiterG = RotL64((aOrbiterG * 1022283727595400719U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5003342156562330058U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10951027475628404336U;
            aOrbiterC = RotL64((aOrbiterC * 17836928292555158461U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13040991872592235460U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11149099984302782267U;
            aOrbiterK = RotL64((aOrbiterK * 4248667283139686251U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2202253777854402763U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16679038924474862612U;
            aOrbiterF = RotL64((aOrbiterF * 2624443661523083597U), 5U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 1959650241410955571U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 35U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8415989510614674816U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16340289102832732519U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2344501711730399821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4980738603982643969U;
            aOrbiterB = RotL64((aOrbiterB * 6419275275477478723U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 52U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordA, 22U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 54U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 23U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aNonceWordF, 55U));
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 24U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordB, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16228U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13652U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordE, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11791U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9537U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 43U)) + 18255347001097480328U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 13679246790311505735U;
            aOrbiterE = (aWandererC + RotL64(aCross, 56U)) + 10565839529765027116U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 14327172566224769901U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 21U)) + 16239024612038195174U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 47U)) + 13800012174212131890U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 37U)) + 13900288860157577583U;
            aOrbiterK = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 4144386119777112740U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 4U)) + 3154558262670631372U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 17U);
            aOrbiterI = (aWandererD + RotL64(aPrevious, 53U)) + 7456728543137614001U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 35U)) + 11709519851158935384U) + RotL64(aNonceWordD, 25U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15607438907832240304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9276575329661725624U;
            aOrbiterE = RotL64((aOrbiterE * 8879744070762412745U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6459435969129449226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6442382118416542275U;
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12117432107282150865U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6831279293184793243U;
            aOrbiterG = RotL64((aOrbiterG * 2435360641135249073U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9520022957804572889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8322178689474588679U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1627707191467537115U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4162401591586869316U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8994015844714895961U;
            aOrbiterJ = RotL64((aOrbiterJ * 15421910378057951895U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10038095909727959633U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14255952184627347295U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3379089265413427719U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11341713098678108441U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterA = RotL64((aOrbiterA * 2500587373161411961U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4030296130743454165U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6332387792111212064U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16490982218150897861U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14893209417387662133U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9265457389326311687U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9778404505547862689U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13496086915199406901U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14576555328710787951U) ^ RotL64(aNonceWordB, 34U);
            aOrbiterI = RotL64((aOrbiterI * 13155395071667672943U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11482324648071976743U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18255347001097480328U;
            aOrbiterB = RotL64((aOrbiterB * 10918514878283385643U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterH, 24U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + RotL64(aNonceWordE, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterI, 42U));
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 10U) + aOrbiterI) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordG, 61U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordF, 48U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22854U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 24519U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20170U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19592U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 12136097566601676613U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 56U)) + 7969431322248040056U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 10530676021510553889U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 8740777303075445264U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 3U)) + 13249434169895564739U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 53U)) + 15529577005925628472U) + RotL64(aNonceWordF, 53U);
            aOrbiterB = (((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 344627093687331562U) + RotL64(aNonceWordH, 60U);
            aOrbiterH = (aWandererK + RotL64(aIngress, 29U)) + 8824277416519988893U;
            aOrbiterA = (aWandererC + RotL64(aCross, 39U)) + 5636276438449709875U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 2079413361031851552U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 27U)) + 7807998179168655561U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13589392896232029112U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10733011474804473996U;
            aOrbiterI = RotL64((aOrbiterI * 361749145931578805U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15934162328347805968U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7573511217796245232U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterE = RotL64((aOrbiterE * 10694563909931636155U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4828475187337891975U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13284974329890393113U;
            aOrbiterF = RotL64((aOrbiterF * 10831075817642374287U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13173869918669643112U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15841507674783398167U) ^ RotL64(aNonceWordB, 5U);
            aOrbiterC = RotL64((aOrbiterC * 15632933198136963277U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14168272451055700516U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11134471485501999898U;
            aOrbiterH = RotL64((aOrbiterH * 8019507184494591705U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2611858916687822610U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17863271539727513641U;
            aOrbiterG = RotL64((aOrbiterG * 4987884722174985677U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8874401993454249066U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5131480593493950665U;
            aOrbiterD = RotL64((aOrbiterD * 8585874663602346121U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9366563022381918996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7890729519928340296U;
            aOrbiterK = RotL64((aOrbiterK * 11428572374057899517U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 131774386529223292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4108356674478240148U;
            aOrbiterB = RotL64((aOrbiterB * 2492753294539081613U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7651738365157869789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2745458108574051004U;
            aOrbiterA = RotL64((aOrbiterA * 2175955806036373729U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10492013124307434604U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12136097566601676613U;
            aOrbiterJ = RotL64((aOrbiterJ * 13128652803485742119U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 56U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + RotL64(aCarry, 43U)) + RotL64(aNonceWordG, 31U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 19U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 60U)) + aOrbiterA) + RotL64(aNonceWordA, 9U));
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordG, 20U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25461U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 29246U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 6U) ^ RotL64(aNonceWordF, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30097U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 26405U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 3U)) + 8988572360732005217U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 54U)) + 17889613225105985335U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 23U)) + 15563478320513948626U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 3441351228410524816U) + RotL64(aNonceWordG, 47U);
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 41U)) + 4425592689451435346U) + RotL64(aNonceWordH, 43U);
            aOrbiterE = ((aWandererA + RotL64(aIngress, 28U)) + RotL64(aCarry, 43U)) + 12733160231627305928U;
            aOrbiterK = (aWandererH + RotL64(aCross, 21U)) + 3574152157304607854U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 43U)) + 15167631896729808783U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 15822667973915417055U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + 17181685481076577637U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 19U)) + 9979204751408873468U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1334240485667164762U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 9190066751460137016U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordF, 41U);
            aOrbiterA = RotL64((aOrbiterA * 14585141844653660363U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15465215829109246336U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2305208282453624419U;
            aOrbiterC = RotL64((aOrbiterC * 10257861974108363283U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16951510027310993926U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 11117938943423526901U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7805486716716924787U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12461379120662979432U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11719697049048823897U;
            aOrbiterK = RotL64((aOrbiterK * 14880996802304818757U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6843357278142933570U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12727898578324702374U;
            aOrbiterD = RotL64((aOrbiterD * 9786435451654365097U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 18127999660067652233U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11754709060558683082U;
            aOrbiterG = RotL64((aOrbiterG * 12798744012150745847U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16940151146420516184U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12924950783056761895U;
            aOrbiterJ = RotL64((aOrbiterJ * 8898170377271926745U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14829713915929878471U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 840466047621042565U;
            aOrbiterI = RotL64((aOrbiterI * 10748511630509529489U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11469637840333471085U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5561780312837795893U;
            aOrbiterH = RotL64((aOrbiterH * 11935079844970978957U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1059834104159730610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10122108814456766430U;
            aOrbiterB = RotL64((aOrbiterB * 2184693583782179921U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14857099570072635006U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8988572360732005217U) ^ RotL64(aNonceWordA, 9U);
            aOrbiterF = RotL64((aOrbiterF * 14409836741925393077U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterE, 10U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aNonceWordB, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + RotL64(aNonceWordD, 6U)) + aWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 18U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA86AD6AEC89A54DULL + 0xAE5A0F5FC04D2116ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB7FDC53ACEE2B80DULL + 0xF035137231E626CAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA207DFD5456DFAB9ULL + 0xAF5C267ABC33C5F2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC0CC8D7EABEACEF9ULL + 0x9C3E0B5CCFA37827ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA28E2B6A87059DADULL + 0xF54C76CAC5D8D019ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB954FD485DF377B3ULL + 0xE47A6ED90A1DBCCCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC88E718DE9AB1DFBULL + 0x8F3933DCCFD53390ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFCE5894E3C7774EDULL + 0xCD2C4BCC10ABC100ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordE, 6U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1689U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 791U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordB, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 532U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 213U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 1457104756581596530U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 57U)) + 6127240317844622874U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 3U)) + 16492290056044189421U) + RotL64(aNonceWordC, 57U);
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 39U)) + 10963676850938416468U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 26U)) + 4872917367399752405U) + RotL64(aNonceWordD, 29U);
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 15218882377875616148U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 35U)) + 5934166612122118251U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 14215280930872003003U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 23U)) + 11428034799044600979U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5453003654321728726U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14273775120265649389U;
            aOrbiterG = RotL64((aOrbiterG * 5139018128323795309U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 328723770018440271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13032190719588211088U;
            aOrbiterJ = RotL64((aOrbiterJ * 13363368478932798315U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2386881543033598494U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1649501123340887116U;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16462401546754210583U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1510579201823042227U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16287912400104043275U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6889066000014251983U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11324594596597724357U) ^ RotL64(aNonceWordE, 24U);
            aOrbiterE = RotL64((aOrbiterE * 15344987814648586023U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12237796033168436537U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17306069670330000343U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14197284538008811658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4754134852883071927U;
            aOrbiterK = RotL64((aOrbiterK * 3484427259538998699U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17201907781639753736U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8318419319239859855U;
            aOrbiterD = RotL64((aOrbiterD * 10320390501983802091U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16012488623961565780U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15583721012865354925U) ^ RotL64(aNonceWordH, 51U);
            aOrbiterH = RotL64((aOrbiterH * 10656414363201743961U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aNonceWordF, 5U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 12U)) + aOrbiterJ);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aNonceWordA, 15U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterF, 42U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 60U) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9611U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7250U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordG, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7851U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10047U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 34U)) + (RotL64(aPrevious, 47U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 5960680319644404115U;
            aOrbiterB = (aWandererE + RotL64(aCross, 28U)) + 16050752633567034185U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 47U)) + 8447503223226854741U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 57U)) + 14176813813397917591U) + RotL64(aNonceWordD, 19U);
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 53U)) + 10534915376130006644U) + RotL64(aNonceWordH, 39U);
            aOrbiterE = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 6866224454375302514U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 40U)) + 16506374165041008396U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 13U)) + 7167814023968794098U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 13870852197416596664U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18064038854848993105U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9869630811507771691U;
            aOrbiterC = RotL64((aOrbiterC * 13723164383800461387U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 863613100452759380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16597969741225436529U;
            aOrbiterI = RotL64((aOrbiterI * 2680793528887208903U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6575347108051310653U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17062262265485019063U) ^ RotL64(aNonceWordC, 58U);
            aOrbiterD = RotL64((aOrbiterD * 7601045488473620019U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7193399224636409133U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14146747818810433849U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5273185769989530041U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9441449106442431427U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4303295336545399503U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829695296836242587U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12604760768543193458U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15779327512379787715U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14000905201441272597U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15553000781122708728U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17162740616060079717U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9458662233556750239U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1032374679817715156U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16413393156165548232U) ^ RotL64(aNonceWordE, 43U);
            aOrbiterE = RotL64((aOrbiterE * 549659738811935015U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14056855000013992045U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7399202019042538829U;
            aOrbiterB = RotL64((aOrbiterB * 6103508549612077695U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 38U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + RotL64(aNonceWordF, 9U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 36U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aNonceWordB, 25U)) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15534U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 15931U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordC, 40U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11478U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 14471U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 38U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 6381335981879993247U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 30U)) + RotL64(aCarry, 29U)) + 15595429101600023172U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5449234297249826461U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 19U)) + 11213734849329731168U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 57U)) + 16438473952464514248U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordH, 24U);
            aOrbiterA = (((aWandererE + RotL64(aScatter, 40U)) + 7357872882115186976U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            aOrbiterE = (aWandererA + RotL64(aPrevious, 47U)) + 394402075160738643U;
            aOrbiterD = (aWandererB + RotL64(aCross, 11U)) + 11112941985410283532U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 51U)) + 14955125011182736212U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14770727009821304070U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11286366598129204910U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15884310771003021989U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7358400908565425780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15635109923749114761U;
            aOrbiterJ = RotL64((aOrbiterJ * 12415152149408700329U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13826842523738623579U) + RotL64(aNonceWordA, 21U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1072811298828325231U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4017334196009350776U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8812213572751410831U;
            aOrbiterF = RotL64((aOrbiterF * 12744171921566782795U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6723457786170634403U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9785583533999417673U;
            aOrbiterK = RotL64((aOrbiterK * 7776915427605471097U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10265132640322153964U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8435670887514808087U;
            aOrbiterA = RotL64((aOrbiterA * 2706263045620662131U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4303823386961718326U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 4214384238167491037U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ RotL64(aNonceWordE, 49U);
            aOrbiterE = RotL64((aOrbiterE * 8490707334221154005U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8740835037840799136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5988815405391206280U;
            aOrbiterD = RotL64((aOrbiterD * 17838555472135715929U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15539461383052981747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3743772525784217714U;
            aOrbiterC = RotL64((aOrbiterC * 6352086797545969187U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 36U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 44U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 4U) + aOrbiterF) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordD, 37U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 24U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordF, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20014U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 18747U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordH, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17400U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20664U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 52U)) + RotL64(aCarry, 19U)) + 8101351470141807662U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 6965474099521076705U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 43U)) + 6803828268885684784U) + RotL64(aNonceWordE, 61U);
            aOrbiterI = (((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 13454235922950972488U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 27U)) + 11678091885751244777U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 13U)) + 5307134544628507141U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 57U)) + 4873703518950429353U) + RotL64(aNonceWordB, 5U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 39U)) + 8542156221858586039U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 4U)) + 3993726182905296513U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12113047622035464386U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1944244448665721151U) ^ RotL64(aNonceWordA, 3U);
            aOrbiterC = RotL64((aOrbiterC * 7010050836758762003U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12914188029425467576U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2486762763475327024U;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 14580191602982245481U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12093414832400135066U;
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13623906997320021065U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9977356009806428696U;
            aOrbiterJ = RotL64((aOrbiterJ * 2005536391712733499U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3694954095397810851U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11453812627797091638U;
            aOrbiterI = RotL64((aOrbiterI * 13730420725113907161U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 542311345544726351U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3024285045990499484U;
            aOrbiterA = RotL64((aOrbiterA * 5153745952148205645U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15397664082460849530U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10716856680110815056U;
            aOrbiterF = RotL64((aOrbiterF * 13947203772929252823U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 833342121331428547U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1111339940097269219U;
            aOrbiterG = RotL64((aOrbiterG * 17991642769781175473U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9312963978841402871U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8225496710723213204U;
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 42U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aIngress, 28U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + RotL64(aNonceWordG, 39U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 60U)) + RotL64(aNonceWordF, 36U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 46U) + aOrbiterK) + RotL64(aOrbiterD, 13U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24604U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27200U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 41U) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24797U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27185U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 13714409587461539863U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 14101156723903265839U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 46U)) + 7063754562895369001U) + RotL64(aNonceWordA, 11U);
            aOrbiterB = ((aWandererI + RotL64(aCross, 23U)) + 12320578575245519386U) + RotL64(aNonceWordE, 49U);
            aOrbiterE = (aWandererC + RotL64(aScatter, 57U)) + 11744826789631008424U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 41U)) + 8744816505096675597U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 10U)) + 10405435520084528645U;
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 1463157688070683543U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 12379603577919617703U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1343439118031348146U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16118850268070235540U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11184386483735388257U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14116264435819277136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5251698273012432109U;
            aOrbiterI = RotL64((aOrbiterI * 1495818611622063967U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14806408656041403829U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11569345414052398227U;
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17063874769147888574U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9927420478679581917U;
            aOrbiterD = RotL64((aOrbiterD * 9042782809534196563U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2550285599827162167U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17801534123304996448U;
            aOrbiterJ = RotL64((aOrbiterJ * 2160836889363614721U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6456685241021762041U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17064208177372969289U;
            aOrbiterB = RotL64((aOrbiterB * 13726627607233302493U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18279938244131982650U) + RotL64(aNonceWordD, 21U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8211002229712129419U;
            aOrbiterF = RotL64((aOrbiterF * 12931373380977640645U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12795832560781931767U) + RotL64(aNonceWordC, 35U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 286378504074349650U;
            aOrbiterC = RotL64((aOrbiterC * 85453101173293509U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5835304250436889513U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12704972686724379659U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1198789639656336053U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aNonceWordH, 13U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 46U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK) + RotL64(aCarry, 35U)) + RotL64(aNonceWordF, 30U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterD, 4U));
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 34U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordG, 48U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29180U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 27551U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 54U) ^ RotL64(aNonceWordH, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29077U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 29074U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + 6361545377408870615U) + RotL64(aNonceWordB, 21U);
            aOrbiterF = (aWandererC + RotL64(aPrevious, 39U)) + 2967245486744774933U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 57U)) + 3836634268482850139U) + RotL64(aNonceWordH, 47U);
            aOrbiterI = ((aWandererE + RotL64(aCross, 27U)) + 7691642115360086297U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 4U)) + RotL64(aCarry, 43U)) + 16479280384178279281U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 23U)) + 2901468732552539249U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 11U)) + 2600353867755647475U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 5666596904781510956U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 48U)) + RotL64(aCarry, 53U)) + 16108791609267427553U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8389926875737312112U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1689501721163024426U;
            aOrbiterG = RotL64((aOrbiterG * 6517194895779049139U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11721701506949917719U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3963842745030140473U) ^ RotL64(aNonceWordC, 57U);
            aOrbiterH = RotL64((aOrbiterH * 6692473494944919373U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8510538243472109368U) + RotL64(aNonceWordA, 11U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 18281865214102080387U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1351546966368884609U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2259725140963665123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11652011949557979650U;
            aOrbiterJ = RotL64((aOrbiterJ * 11260100762113295037U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1116085424226174473U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4725260319270802912U;
            aOrbiterA = RotL64((aOrbiterA * 4697109059565450269U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7348945429843437036U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1249234309180653260U;
            aOrbiterC = RotL64((aOrbiterC * 3136745255820405881U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12463505532573389603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2304125977906510386U;
            aOrbiterI = RotL64((aOrbiterI * 9960816714791454421U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2178037443783425551U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11712110130079307683U;
            aOrbiterE = RotL64((aOrbiterE * 9797864956200779505U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10703510612147312252U) + aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18155460326242413483U;
            aOrbiterF = RotL64((aOrbiterF * 6903953708987478723U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 20U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aNonceWordE, 3U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 60U)) + aOrbiterA) + RotL64(aCarry, 27U)) + RotL64(aNonceWordD, 26U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Soccer_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xABE4DC590715D5C7ULL + 0xFB1BEB0FA823BF2EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF79C7BF4B7A21E8DULL + 0xBEC996EAD080D36EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF2D2F124DCFF3237ULL + 0xAE82377DFCB7EED3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA0A80221FDF0F161ULL + 0xD9E827C7D6ECD4D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCCFE89DBEE715CC5ULL + 0xDF4325CA71A98405ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB1BA55D2A23DF435ULL + 0xFB6B699D80F15E74ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB41C21CD223B4393ULL + 0x98C837F53DA4DA08ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA6133C23BD83EF55ULL + 0xEA0FB2E55BC3E18BULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordH, 26U)) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4607U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5329U)) & W_KEY1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordC, 37U)) ^ RotL64(aNonceWordA, 23U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3982U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1139U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 60U)) + 15316464782468770057U) + aPhaseAOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 35U)) + 6642872057476351588U) + RotL64(aNonceWordA, 31U);
            aOrbiterI = (aWandererE + RotL64(aCross, 27U)) + 660732654689529192U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 41U)) + 7235418086884000655U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 14784518476694580493U;
            aOrbiterF = ((((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 12222433977933449375U) + aPhaseAOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordG, 49U);
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 8573001207708329927U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16035256260815013172U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15767726974121910203U;
            aOrbiterI = RotL64((aOrbiterI * 719060452537759331U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17712217935322939971U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13488963456923357159U;
            aOrbiterC = RotL64((aOrbiterC * 16785285630840310405U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10222949131965611079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterF = RotL64((aOrbiterF * 9706305581868526265U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16156530750584361434U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7773792489045606309U;
            aOrbiterK = RotL64((aOrbiterK * 10730624207715601393U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11544578291333360613U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 3665587867634242865U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ RotL64(aNonceWordE, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 4840528190844842595U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15248434984650998090U) + RotL64(aNonceWordD, 56U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15487979645426567581U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10868107809356766183U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 6972347795052712690U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16074994810010431338U;
            aOrbiterG = RotL64((aOrbiterG * 1262655238856775853U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 6U)) + RotL64(aNonceWordB, 61U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 12U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + RotL64(aNonceWordH, 21U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordG, 44U)) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7117U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10328U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 28U) ^ RotL64(aNonceWordF, 53U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6544U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5592U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 8685374557928800912U) + aPhaseAOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 3482312691892161229U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 6948130297389161165U) + RotL64(aNonceWordG, 4U);
            aOrbiterK = (aWandererG + RotL64(aIngress, 3U)) + 5506385663788942690U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 12U)) + 17859982009307397161U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 27U)) + 9178488809207094043U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 19U)) + 1835479501226057169U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordH, 59U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 5368101733632614939U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9050459666576835422U;
            aOrbiterE = RotL64((aOrbiterE * 10351719549990259551U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9042186993119635078U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17528342580198295025U;
            aOrbiterH = RotL64((aOrbiterH * 14316671546614386775U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6495418332558436882U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8834495762667327342U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4364314196965690905U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6357485231062120459U;
            aOrbiterG = RotL64((aOrbiterG * 289429584586504995U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3321488322626415347U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10817330671781848737U;
            aOrbiterJ = RotL64((aOrbiterJ * 15875919466358823335U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17974092279281611763U) + RotL64(aNonceWordE, 31U);
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 2871472057292789157U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordA, 15U);
            aOrbiterF = RotL64((aOrbiterF * 16104199340711015181U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15187929795092006849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13482063681546475923U;
            aOrbiterA = RotL64((aOrbiterA * 14466266308157364963U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 21U)) + RotL64(aNonceWordC, 55U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 56U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordD, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 42U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordE, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14196U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 16238U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordH, 4U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15476U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15767U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 51U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 12980104182836602177U) + RotL64(aNonceWordH, 13U);
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + 3172622203188863995U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 5U)) + 1170974132219980203U;
            aOrbiterE = (aWandererG + RotL64(aCross, 57U)) + 6035201940965047490U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 18033907118424996722U;
            aOrbiterF = ((((aWandererH + RotL64(aCross, 22U)) + RotL64(aCarry, 29U)) + 14604813424800580304U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterB = (aWandererJ + RotL64(aScatter, 29U)) + 13720232492851066035U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3902659710585257448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8331560652661619868U;
            aOrbiterC = RotL64((aOrbiterC * 11418103770615560205U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4485014147538689794U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 168202636924512424U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13711020666131492091U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16227825670092707848U) + RotL64(aNonceWordB, 14U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4792781933944671365U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12636865372722601282U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18198291399585556632U;
            aOrbiterE = RotL64((aOrbiterE * 18155803890313399795U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3650053185419807206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5897288963905408776U;
            aOrbiterJ = RotL64((aOrbiterJ * 3706949366974086151U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9922308113622901726U) + RotL64(aNonceWordC, 39U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13352279749091561510U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4025213180483632557U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14969461950939646117U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10231661776135056651U;
            aOrbiterB = RotL64((aOrbiterB * 11284575051455238501U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 12U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + RotL64(aNonceWordA, 29U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + RotL64(aNonceWordF, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 54U) ^ RotL64(aNonceWordA, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21796U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 18267U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20772U)) & S_BLOCK1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 19124U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 16200278595895089008U) + aPhaseAOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 57U)) + 1029614154810465897U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 13U)) + 7129562468705441295U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 51U)) + 14388903902433951274U) + RotL64(aNonceWordE, 21U);
            aOrbiterF = ((aWandererH + RotL64(aIngress, 4U)) + 1013568949315967455U) + RotL64(aNonceWordD, 51U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 3128823373497815651U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 14525694606889470589U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14443983602196782887U) + RotL64(aNonceWordG, 41U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12244220415328641190U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15052949098014803181U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10477159225338766614U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2842870123078131566U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11522265477555954071U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8621138818955849917U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5038396344400303181U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2768613802894372496U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2027754864051410015U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2461322540050569287U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2848088309172056399U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15017458513904884651U;
            aOrbiterD = RotL64((aOrbiterD * 9926904679902843055U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9079797279596336139U) + RotL64(aNonceWordF, 46U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15424866642305110811U;
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13751764050290602740U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7694557131324740282U;
            aOrbiterH = RotL64((aOrbiterH * 14980807690491467023U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aPhaseAWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterH, 34U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + RotL64(aNonceWordC, 29U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordH, 15U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 6U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aPhaseAWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordC, 50U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26036U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 24025U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordF, 30U)) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24786U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26201U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 26U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 35U)) + 13053031069776604052U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 21U)) + 1331396630251085122U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 15879286043343942393U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 35U)) + 13590365633321406830U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 14U)) + 14569235423040242618U) + RotL64(aNonceWordC, 58U);
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 11397370636618371560U) + RotL64(aNonceWordA, 39U);
            aOrbiterC = (aWandererB + RotL64(aIngress, 57U)) + 3455933494593971847U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1307153376443784593U) + RotL64(aNonceWordH, 27U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10688618762584786871U;
            aOrbiterJ = RotL64((aOrbiterJ * 9503823896874842411U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17746248451153600096U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8512568600755410158U;
            aOrbiterF = RotL64((aOrbiterF * 16648320170768234063U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8950230550112591092U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17790968369472845496U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5104988920132008913U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12583323865381967534U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11243927099685293887U;
            aOrbiterG = RotL64((aOrbiterG * 12867003042486433971U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9690268715525781389U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7466066217365074653U;
            aOrbiterA = RotL64((aOrbiterA * 17565696765505320889U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3673528673209875118U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14079103852360952255U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17449228863409999629U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6747836856132250630U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5027692924422297153U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterC = RotL64((aOrbiterC * 2492421273167124437U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 48U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 41U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordB, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordF, 9U)) + aPhaseAWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 4U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordF, 40U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29099U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32568U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordC, 35U)) ^ RotL64(aNonceWordB, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29577U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 28477U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + 7075016829833562104U) + RotL64(aNonceWordA, 11U);
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 8783765886115517036U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 2996723892384565829U;
            aOrbiterK = ((((aWandererI + RotL64(aCross, 36U)) + RotL64(aCarry, 13U)) + 9494134707342189476U) + aPhaseAOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterH = (aWandererB + RotL64(aScatter, 11U)) + 5052642981395679904U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 43U)) + 8766787055127962238U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 23U)) + 4467211954388738079U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8030255604633658608U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16962408063455702251U;
            aOrbiterI = RotL64((aOrbiterI * 11171737929747471631U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3768222186567699076U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14930990410207899871U) ^ RotL64(aNonceWordE, 43U);
            aOrbiterH = RotL64((aOrbiterH * 10930005786146268241U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14179761938395502502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1879084742719898108U;
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5535012408925981515U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12792553516710295939U;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8979253163346099252U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5559189896063990740U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8832485423727331621U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13937564337299044079U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2393376759689394948U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2352815657830413941U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12647519563697356479U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 10946871249960389549U) ^ RotL64(aNonceWordF, 14U);
            aOrbiterB = RotL64((aOrbiterB * 6272580371881237173U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 12U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 22U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordB, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Soccer_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA23BEEC7762E5A7ULL + 0xAF6C73BE357AA447ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB1DB56AA02C68011ULL + 0xBE8553CA50AFAEFBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9965337456193CC1ULL + 0xB290463EB0C5D942ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9BAE901753283A5DULL + 0x8833439AAD7716D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC8E3C4278D634575ULL + 0xB4DEF5E7AEEC3D49ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCE132FB24DA9A40FULL + 0xA4E3FEC114595092ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDF1E8CA27A7593D9ULL + 0xF7D9C2A8D4BC99BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA1BF5496A9771B99ULL + 0xDBD2CC5E7EB32048ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 34U) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1188U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 318U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 35U)) ^ RotL64(aNonceWordD, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3388U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 4449U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 6469584119078165548U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 48U)) + 14329756366517987910U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 12890831797059772123U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 29U);
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 3164503807500018990U) + aPhaseBOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 39U)) + 177531431387646836U) + RotL64(aNonceWordD, 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 3167421392893561015U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordB, 57U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2813174781844753460U;
            aOrbiterC = RotL64((aOrbiterC * 9760688894575305115U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10953270419153249857U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16911518309710356951U;
            aOrbiterE = RotL64((aOrbiterE * 13162785997686570445U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6616750447844893150U) + RotL64(aNonceWordA, 46U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10276741398025985982U;
            aOrbiterB = RotL64((aOrbiterB * 6824712685896987133U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6206043608461213208U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12021552904553405793U;
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15283586234744144846U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5923238786775948571U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8200882393521882651U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 24U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordG, 55U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 36U)) + aOrbiterI);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + RotL64(aCarry, 51U)) + RotL64(aNonceWordE, 47U)) + aPhaseBWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordB, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8162U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 10074U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordH, 29U)) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8451U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5539U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 60U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 21U)) + 18319689184146942855U) + RotL64(aNonceWordC, 7U);
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 38U)) + RotL64(aCarry, 41U)) + 8041304130090501019U) + RotL64(aNonceWordG, 59U);
            aOrbiterE = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 11347064191990897738U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 15242243470024447468U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + 10619749107163611105U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14795614276221947128U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 1578095288886372393U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordE, 51U);
            aOrbiterE = RotL64((aOrbiterE * 9953192041564147241U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13593906305770501684U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8919815528334599172U;
            aOrbiterC = RotL64((aOrbiterC * 2033810402808238127U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17425548324720065145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11125018338392347335U;
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3779189180734244399U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10958224663276134041U;
            aOrbiterK = RotL64((aOrbiterK * 6206963519509783781U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4317305352561612995U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 4891139433808505355U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1]) ^ RotL64(aNonceWordA, 41U);
            aOrbiterH = RotL64((aOrbiterH * 11507024985663120317U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aNonceWordB, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 24U)) + aOrbiterK) + RotL64(aCarry, 35U)) + RotL64(aNonceWordD, 48U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 35U) ^ RotL64(aNonceWordD, 18U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12108U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12024U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 20U) ^ RotL64(aNonceWordG, 57U)) ^ RotL64(aNonceWordC, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12692U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 12824U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 52U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 5960680319644404115U) + RotL64(aNonceWordC, 23U);
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 54U)) + 16050752633567034185U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordH, 37U);
            aOrbiterA = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 8447503223226854741U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 14176813813397917591U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 35U)) + 10534915376130006644U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6866224454375302514U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16506374165041008396U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1326855300197233833U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7167814023968794098U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13870852197416596664U) ^ RotL64(aNonceWordF, 39U);
            aOrbiterI = RotL64((aOrbiterI * 17015971222069856463U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 18064038854848993105U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9869630811507771691U) ^ RotL64(aNonceWordE, 40U);
            aOrbiterK = RotL64((aOrbiterK * 13723164383800461387U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 863613100452759380U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16597969741225436529U;
            aOrbiterC = RotL64((aOrbiterC * 2680793528887208903U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6575347108051310653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17062262265485019063U;
            aOrbiterJ = RotL64((aOrbiterJ * 7601045488473620019U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordB, 45U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterA, 46U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 54U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + RotL64(aNonceWordG, 5U)) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 53U) ^ RotL64(aNonceWordH, 27U)) ^ RotL64(aNonceWordF, 44U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20537U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 20439U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21353U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 17413U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 14U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 12U)) + 8793908991006073956U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 2932916283348441943U;
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 11069042087940968262U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterC = ((((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 14369628676782894441U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 51U);
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 3U)) + 8602903272780978282U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3827036107178568820U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8905245209036772489U;
            aOrbiterG = RotL64((aOrbiterG * 5744017326197157667U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13331387530760017893U) + RotL64(aNonceWordE, 46U);
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9880107580289737823U;
            aOrbiterF = RotL64((aOrbiterF * 10302652857542703753U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 10199619040626900278U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2466307560891374281U) ^ RotL64(aNonceWordG, 41U);
            aOrbiterC = RotL64((aOrbiterC * 6295342978834217571U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13973403407981259448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10365453393815690776U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2382382358987358791U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 481563628980705781U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aNonceWordF, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterF, 21U)) + RotL64(aNonceWordA, 49U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 60U) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22075U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26832U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 60U) ^ RotL64(aNonceWordD, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22822U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22151U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 5U)) + 2101601659597850213U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterD = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 2759794072560720121U) + RotL64(aNonceWordC, 41U);
            aOrbiterC = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 9443562552411269339U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 57U)) + 10801360546699857975U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 38U)) + RotL64(aCarry, 35U)) + 8020716394829332019U) + aPhaseBOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1021894212367773801U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13346855534622490176U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12668950387932320985U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16359309548462953836U) + RotL64(aNonceWordH, 55U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12642446944680783519U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12197935153255283321U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8197424982767553380U) + RotL64(aNonceWordE, 49U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14346334610901859094U;
            aOrbiterF = RotL64((aOrbiterF * 16982899923227935679U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14171304260534233539U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 334531601308283605U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10707856298471572695U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18364775750091914766U;
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordD, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aNonceWordG, 18U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordD, 54U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31952U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 28758U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30399U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28757U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 54U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aCross, 11U)) + 3255291173184001106U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 44U)) + 18186972408589866656U) + RotL64(aNonceWordE, 27U);
            aOrbiterJ = ((((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 4439324265978331914U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterC = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 13099263173016322486U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7041561081767500660U) + RotL64(aNonceWordD, 46U);
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6196422612687812971U;
            aOrbiterH = RotL64((aOrbiterH * 13359900204297781063U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7664260932541281413U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17802347823020441056U;
            aOrbiterE = RotL64((aOrbiterE * 2220679459017369255U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4253107484061190446U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13799496534030645312U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9167675060053848207U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14252892847595951926U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5663527578664291422U;
            aOrbiterJ = RotL64((aOrbiterJ * 18314294235895182465U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11148755959699137661U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17036900929333594592U) ^ RotL64(aNonceWordC, 3U);
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 44U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterA, 58U));
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordG, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 26U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE43135E046BC5955ULL + 0xAD5110E023DF880EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x831446896F0D3671ULL + 0x85B7FA7498F7AF1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA5DB3DC6905A7951ULL + 0xF942389ABCE9D4FFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF1A439B591AC4441ULL + 0xE36480E9929CD944ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEA61CA3A4E21C7DFULL + 0xA9325C6C088C6C69ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBA1BAA4D9899B0FBULL + 0x93E28910124A7034ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9F9D67F2C2E76D1DULL + 0xBDA4F71053A14F74ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA96877B4F75E47FFULL + 0xD61A6053F9FFE0C8ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 12U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1676U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 382U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordB, 18U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5876U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 2578U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aCross, 24U)) + 18144572925667544139U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 5659758077574059728U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 35U)) + 6343330616999166392U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 43U)) + 17754639838410839447U) + aPhaseCOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 9451843819849581729U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 47U)) + 7957854457197462212U) + RotL64(aNonceWordC, 53U);
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 1461994799722205010U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 29U)) + 18002214276252170177U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterK = (aWandererG + RotL64(aPrevious, 58U)) + 14689869073147027164U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3978104368003440293U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8512135845221335386U) ^ RotL64(aNonceWordB, 15U);
            aOrbiterE = RotL64((aOrbiterE * 10506667163729414667U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1477533446382953439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8082437060686606995U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4363687722464700362U;
            aOrbiterD = RotL64((aOrbiterD * 7199165810993478887U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 15782763348014924206U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordH, 30U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8572509150015960728U;
            aOrbiterK = RotL64((aOrbiterK * 3340528604891897779U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12248271773316742521U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9602078627638561949U;
            aOrbiterH = RotL64((aOrbiterH * 1860631869877427405U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17244849374768558859U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1030743048280579012U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10858949914285817051U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17722342363541914280U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15667504059789880034U;
            aOrbiterC = RotL64((aOrbiterC * 15872269872168533709U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12645332941998550794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9938135244509986497U;
            aOrbiterJ = RotL64((aOrbiterJ * 16548185968987392957U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4024609904162105979U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6732064218696157303U;
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + RotL64(aNonceWordE, 51U));
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aNonceWordF, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordE, 22U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12590U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14767U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordB, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11790U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8720U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 13053031069776604052U) + aPhaseCOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 51U)) + 1331396630251085122U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 15879286043343942393U) + RotL64(aNonceWordD, 11U);
            aOrbiterC = ((aWandererA + RotL64(aIngress, 29U)) + 13590365633321406830U) + RotL64(aNonceWordA, 19U);
            aOrbiterK = (aWandererI + RotL64(aPrevious, 24U)) + 14569235423040242618U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 41U)) + 11397370636618371560U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 3455933494593971847U) + aPhaseCOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 13U)) + 1307153376443784593U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 60U)) + 10688618762584786871U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17746248451153600096U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8512568600755410158U;
            aOrbiterD = RotL64((aOrbiterD * 16648320170768234063U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8950230550112591092U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17790968369472845496U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 12583323865381967534U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordF, 37U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11243927099685293887U;
            aOrbiterI = RotL64((aOrbiterI * 12867003042486433971U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9690268715525781389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 7466066217365074653U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17565696765505320889U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3673528673209875118U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14079103852360952255U;
            aOrbiterA = RotL64((aOrbiterA * 17449228863409999629U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6747836856132250630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5027692924422297153U;
            aOrbiterE = RotL64((aOrbiterE * 2492421273167124437U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11370341866003395776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14013204893442579282U;
            aOrbiterC = RotL64((aOrbiterC * 6602239957997240785U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3436953430697936790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6399073534839993637U;
            aOrbiterJ = RotL64((aOrbiterJ * 14186050072610021241U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 7054057507823631422U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordB, 5U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5752085719673338095U;
            aOrbiterG = RotL64((aOrbiterG * 13252660162476029593U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 54U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 39U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 18U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 23U)) + RotL64(aNonceWordG, 34U)) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererI = aWandererI + (((((RotL64(aCross, 43U) + RotL64(aOrbiterD, 12U)) + aOrbiterA) + RotL64(aCarry, 57U)) + RotL64(aNonceWordH, 17U)) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordB, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18624U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18658U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordH, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16545U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20198U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 58U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 37U)) + 16200278595895089008U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 39U)) + 1029614154810465897U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 35U)) + 7129562468705441295U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 44U)) + 14388903902433951274U) + aPhaseCOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 1013568949315967455U) + RotL64(aNonceWordC, 35U);
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 3128823373497815651U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordF, 61U);
            aOrbiterG = (aWandererJ + RotL64(aCross, 23U)) + 14525694606889470589U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 58U)) + 14443983602196782887U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 5U)) + 12244220415328641190U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10477159225338766614U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2842870123078131566U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11522265477555954071U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8621138818955849917U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5038396344400303181U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2768613802894372496U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2027754864051410015U;
            aOrbiterF = RotL64((aOrbiterF * 2461322540050569287U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2848088309172056399U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15017458513904884651U;
            aOrbiterC = RotL64((aOrbiterC * 9926904679902843055U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9079797279596336139U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15424866642305110811U) ^ RotL64(aNonceWordB, 45U);
            aOrbiterH = RotL64((aOrbiterH * 12912331089970158845U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13751764050290602740U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7694557131324740282U;
            aOrbiterJ = RotL64((aOrbiterJ * 14980807690491467023U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3508673897305667669U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3600868397311393233U;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 1222655844979128996U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordG, 23U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2257342337168905875U;
            aOrbiterD = RotL64((aOrbiterD * 6198995971182272119U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6290990717563682725U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15308494772443447109U;
            aOrbiterE = RotL64((aOrbiterE * 1925593111157842325U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 30U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterK, 12U)) + RotL64(aNonceWordA, 59U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterA, 35U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterD, 60U)) + aOrbiterF) + RotL64(aNonceWordE, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 35U) ^ RotL64(aNonceWordH, 54U)) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24720U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26079U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordA, 26U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30577U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 26499U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 6068543441070417854U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 52U)) + 2995980468193441856U;
            aOrbiterH = (aWandererK + RotL64(aCross, 19U)) + 18020277482171594003U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 4293807434721230702U) + RotL64(aNonceWordB, 49U);
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + 7980599111583893156U) + RotL64(aNonceWordE, 57U);
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + 8593141111851052016U) + aPhaseCOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 5903487523900084325U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 47U)) + 15112035513447930209U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 23U)) + 9854037263057006439U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16759760289688823193U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12622628933030601390U;
            aOrbiterH = RotL64((aOrbiterH * 2151912984825538321U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1264668857268123425U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16302812053619101593U;
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16087995784896123610U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7970269262800468363U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14924752223305807461U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5331477046030959632U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16534913204255550893U;
            aOrbiterK = RotL64((aOrbiterK * 1013433634373673565U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 11042821902537871209U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordC, 61U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8069677512345031660U;
            aOrbiterD = RotL64((aOrbiterD * 13622218526054132397U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5737130058129936372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1076627182956662997U;
            aOrbiterB = RotL64((aOrbiterB * 14342191224014199929U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13911061091801078190U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15397603151098990373U;
            aOrbiterF = RotL64((aOrbiterF * 1802890451633592245U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15137326716738637972U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11248737008959896786U) ^ RotL64(aNonceWordD, 60U);
            aOrbiterJ = RotL64((aOrbiterJ * 90789374131547005U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1847847987633923657U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10560748778679145431U;
            aOrbiterI = RotL64((aOrbiterI * 2919333327817231099U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 6U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 22U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + RotL64(aNonceWordA, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 34U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + aPhaseCWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD) + RotL64(aNonceWordF, 47U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFCA116B6C5E0FCE3ULL + 0x93FD4C42A175AB27ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8D8A5F4EE9A315A5ULL + 0xC84AE3FAD3564D56ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC36600A1AF901A29ULL + 0xC66D1C93AF68AA4DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x82733E97B10A89BDULL + 0x8A5F42A2DF3D12AFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x81082959573752D7ULL + 0xA9545D0790A68345ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB70ED1AE687623F5ULL + 0xAFBAC7F387C6F38AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8D905741394F4015ULL + 0xF51DB082B391C950ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF1DC4F8E237AF7F1ULL + 0x95D3736BCE8C9C95ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordC, 58U)) ^ RotL64(aNonceWordE, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3991U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 2368U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordG, 21U)) ^ RotL64(aNonceWordH, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5068U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 2059U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 44U)) + 7893287783892523139U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 11U)) + 10257331997383491153U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 21U)) + 14562226733652231753U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 14320342577110737851U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 9816717579822880756U) + aPhaseDOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 53U)) + 9558926960095881953U) + RotL64(aNonceWordF, 27U);
            aOrbiterF = ((aWandererK + RotL64(aIngress, 51U)) + 9230371862654338324U) + RotL64(aNonceWordC, 46U);
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 37U)) + 6414274291252913420U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 13868546184398350849U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 34U)) + 16940736952569949038U;
            aOrbiterB = (aWandererI + RotL64(aCross, 27U)) + 2866957764814864371U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7916721976073979724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1602444214978842275U;
            aOrbiterI = RotL64((aOrbiterI * 11072503711308122385U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9529061385251008037U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8402775110887376588U;
            aOrbiterH = RotL64((aOrbiterH * 13980225144628227381U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15003592180290390713U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14195681406520825751U;
            aOrbiterJ = RotL64((aOrbiterJ * 11455000833788877217U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3263577002367714202U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12019422062655581928U;
            aOrbiterG = RotL64((aOrbiterG * 5002313835338447799U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8508638054582582917U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6536618106353552880U;
            aOrbiterF = RotL64((aOrbiterF * 6233964121117511885U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9654542989321430868U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7019594782797863244U;
            aOrbiterD = RotL64((aOrbiterD * 1234877854354279981U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8256061220727519919U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 9232754129467036130U) ^ RotL64(aNonceWordD, 3U);
            aOrbiterB = RotL64((aOrbiterB * 17556001874302369781U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5608829951337740378U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12632120498473345701U;
            aOrbiterK = RotL64((aOrbiterK * 6994794653605831925U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17313364434369677697U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 10147405701828074385U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ RotL64(aNonceWordA, 59U);
            aOrbiterA = RotL64((aOrbiterA * 11544579984323623009U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16853703086012867980U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3591438641820423822U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3570430739475340845U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13974806289212867511U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7893287783892523139U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6648351608953339723U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 44U) + aOrbiterJ) + RotL64(aOrbiterE, 50U)) + RotL64(aNonceWordH, 11U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 58U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + RotL64(aNonceWordB, 7U));
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 38U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordB, 37U)) ^ RotL64(aNonceWordF, 60U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5624U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8770U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordE, 44U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7848U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6662U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 56U)) + 13583136155674166402U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 41U)) + 12830472187484919497U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 3U)) + 18081197909484522509U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 47U)) + 8680634051297891550U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 13939998767458656823U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 1795730579103692594U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 60U)) + 17369751719734069999U) + RotL64(aNonceWordE, 45U);
            aOrbiterG = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 224769585901248068U) + RotL64(aNonceWordC, 25U);
            aOrbiterJ = (aWandererK + RotL64(aCross, 39U)) + 4133547085925268180U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 43U)) + 7022512056309567391U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 10319484359046945495U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10483878349412282069U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6481381149199985736U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13721077228796934509U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9704818014314175007U;
            aOrbiterD = RotL64((aOrbiterD * 760445624027740287U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6253040047758584339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16890211690273641226U;
            aOrbiterB = RotL64((aOrbiterB * 5622534399866057841U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6216227831265032436U) + RotL64(aNonceWordG, 35U);
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2023609047004658739U;
            aOrbiterK = RotL64((aOrbiterK * 3252332895698310147U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9201669637050388263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5106927540934338576U;
            aOrbiterJ = RotL64((aOrbiterJ * 6368134569042291431U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10080368957861445998U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10784789383436485808U;
            aOrbiterI = RotL64((aOrbiterI * 3794918350254445939U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15426339824951793026U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17637144549368340331U;
            aOrbiterE = RotL64((aOrbiterE * 10971293914614704441U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9941300382181962134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8118046374121322097U;
            aOrbiterH = RotL64((aOrbiterH * 8481945819050983127U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 5138086185042567633U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordA, 55U);
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7279942739248982986U;
            aOrbiterG = RotL64((aOrbiterG * 12911998308338410917U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12135610639038562853U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12945353426409788798U;
            aOrbiterF = RotL64((aOrbiterF * 7434977715954413699U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7534876598022096222U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13583136155674166402U;
            aOrbiterA = RotL64((aOrbiterA * 8194058098043157015U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 40U));
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 40U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + RotL64(aNonceWordD, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 47U)) + RotL64(aNonceWordB, 42U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 44U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterK, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordG, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13250U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11498U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 12U) ^ RotL64(aNonceWordB, 41U)) ^ RotL64(aNonceWordA, 23U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15191U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 15185U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 5171470532667965920U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 38U)) + 750549462358682403U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 51U)) + 3325689257577120525U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 18031575461559790826U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 13874739537012288677U;
            aOrbiterA = (aWandererF + RotL64(aCross, 21U)) + 4250029868785016865U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 19U)) + 8211158803112611161U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 41U)) + 1083939790236786027U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 27U)) + 3446525462376962464U) + RotL64(aNonceWordF, 12U);
            aOrbiterE = ((aWandererC + RotL64(aScatter, 58U)) + 6973817815000417325U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 15230876489676945543U) + RotL64(aNonceWordA, 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9359727659738755880U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8775170107816327654U;
            aOrbiterB = RotL64((aOrbiterB * 6910680458261008653U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11958941755525038545U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16966819714283167348U;
            aOrbiterA = RotL64((aOrbiterA * 16363457661846050749U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14556087985619763243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17915047508377045221U;
            aOrbiterH = RotL64((aOrbiterH * 6727635453185130109U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8578745677485367222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3569939503066735457U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2956247934282522184U;
            aOrbiterG = RotL64((aOrbiterG * 9946650822131152531U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4285180013402474041U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5976239869535619811U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3458095419039067465U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2424524955161695463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6849595426583763537U;
            aOrbiterC = RotL64((aOrbiterC * 12727902040238318101U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11414890686374886716U) + RotL64(aNonceWordB, 23U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5668287266836153445U;
            aOrbiterJ = RotL64((aOrbiterJ * 8011885266143066285U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9976985606260445887U) + RotL64(aNonceWordH, 49U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9223940029500676834U;
            aOrbiterD = RotL64((aOrbiterD * 8508023992488499955U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4480967907876921958U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5132766654502526597U;
            aOrbiterF = RotL64((aOrbiterF * 321625389942019245U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12921555132452983464U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5171470532667965920U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9710487797420618879U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aCross, 52U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + RotL64(aCarry, 43U)) + RotL64(aNonceWordE, 55U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aCross, 50U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordD, 3U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterC, 50U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + aPhaseDWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 37U) ^ RotL64(aNonceWordC, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18865U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20876U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 54U) ^ RotL64(aNonceWordA, 21U)) ^ RotL64(aNonceWordD, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21164U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19925U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 12980104182836602177U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 44U)) + 3172622203188863995U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 39U)) + 1170974132219980203U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 6035201940965047490U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 51U)) + 18033907118424996722U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 53U)) + 14604813424800580304U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 29U)) + 13720232492851066035U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 57U)) + 3902659710585257448U) + RotL64(aNonceWordF, 3U);
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 8331560652661619868U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 4485014147538689794U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 3U)) + 168202636924512424U) + RotL64(aNonceWordG, 7U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16227825670092707848U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 4792781933944671365U) ^ RotL64(aNonceWordH, 14U);
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12636865372722601282U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18198291399585556632U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18155803890313399795U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3650053185419807206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5897288963905408776U;
            aOrbiterE = RotL64((aOrbiterE * 3706949366974086151U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9922308113622901726U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13352279749091561510U;
            aOrbiterK = RotL64((aOrbiterK * 4025213180483632557U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14969461950939646117U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10231661776135056651U;
            aOrbiterA = RotL64((aOrbiterA * 11284575051455238501U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10621934544068320859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6029116920305246887U;
            aOrbiterD = RotL64((aOrbiterD * 6087523725059376905U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12887482425168671195U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8351351557123783853U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3839381627914762245U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5405938210926464973U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 385145802287899406U) ^ RotL64(aNonceWordB, 37U);
            aOrbiterI = RotL64((aOrbiterI * 8330751480464271445U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7907749190875916461U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5138733192253468642U;
            aOrbiterF = RotL64((aOrbiterF * 17028325976353263843U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14382272868178763187U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14354777100157531233U;
            aOrbiterG = RotL64((aOrbiterG * 7095764230272037767U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4390647647193363824U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12980104182836602177U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11124472075872147333U), 51U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordC, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aNonceWordE, 31U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 10U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 38U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25057U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27098U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 44U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25806U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 22093U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 27U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (((aWandererF + RotL64(aIngress, 18U)) + 5131645209694953015U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordB, 45U);
            aOrbiterC = (aWandererA + RotL64(aPrevious, 57U)) + 12070391048835379854U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 21U)) + 2604295836242338724U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 14042039029284001596U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 8914654543854559327U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 2185619407969359869U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 53U)) + 5187406295103352574U) + RotL64(aNonceWordC, 21U);
            aOrbiterA = (aWandererC + RotL64(aPrevious, 5U)) + 8022832481290871217U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 47U)) + 8783061916740573472U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 51U)) + 10711028365596196301U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aCross, 40U)) + 13387065038269133571U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11187001318931801582U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14191473173276034019U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2491253922434756431U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16207761776716426435U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 9677408414452078760U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ RotL64(aNonceWordA, 53U);
            aOrbiterB = RotL64((aOrbiterB * 5487303383095129949U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 17812460332794370649U) + RotL64(aNonceWordH, 11U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7736423148554132028U;
            aOrbiterA = RotL64((aOrbiterA * 15588733747232852555U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17293203944059014763U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13487243633338010243U;
            aOrbiterI = RotL64((aOrbiterI * 9468688858740539095U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15979293016815060755U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17645215484691359547U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1449450767288733995U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11635961468586927692U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10530136578329059784U;
            aOrbiterJ = RotL64((aOrbiterJ * 8785021493374398437U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4900370530116992731U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15952900504821599445U;
            aOrbiterF = RotL64((aOrbiterF * 5413316082800365261U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9938000151832814778U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14170277411106520726U;
            aOrbiterE = RotL64((aOrbiterE * 5058343552974910737U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14091010427448547620U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13658560822164111421U;
            aOrbiterK = RotL64((aOrbiterK * 9523184040517290629U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13954269172267844623U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3921811946419945868U;
            aOrbiterC = RotL64((aOrbiterC * 6839440867046147039U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14296483810577739898U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5131645209694953015U;
            aOrbiterH = RotL64((aOrbiterH * 10190969526209064367U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterK, 50U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + RotL64(aNonceWordD, 24U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 14U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordG, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 23U) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30151U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28849U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32237U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 30822U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 19U)) + 12849591986267890852U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 57U)) + 8232614804696815750U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 12141567259210877281U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 21U)) + 2928641981037885644U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 980733350554783938U) + RotL64(aNonceWordA, 49U);
            aOrbiterI = (aWandererF + RotL64(aIngress, 24U)) + 2683985177993350746U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 14532148403815527355U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 13U)) + 7736296629433884203U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 35U)) + 10428437770166310549U) + RotL64(aNonceWordH, 21U);
            aOrbiterA = (aWandererH + RotL64(aPrevious, 29U)) + 18327174144859461029U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 52U)) + 6810436935194432002U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12606153309690753435U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17123256945895150555U;
            aOrbiterG = RotL64((aOrbiterG * 13469111258504672565U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9057777759026189541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 18064460487552100483U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordB, 52U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11477276762421684083U;
            aOrbiterI = RotL64((aOrbiterI * 3886501230380184395U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18318375441973295081U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13849305985380030986U;
            aOrbiterJ = RotL64((aOrbiterJ * 12962140243967824959U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10240409420338313641U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18360586077779529086U;
            aOrbiterB = RotL64((aOrbiterB * 18196875422391501927U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16801797158622424257U) + RotL64(aNonceWordC, 25U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4950305991208513887U;
            aOrbiterH = RotL64((aOrbiterH * 4437082499761416951U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15790878572843321918U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9808781805065559728U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9394280083159162953U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11974996650410830731U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4955004489435232515U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13301966529515483085U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1187569634223338864U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5351017164244226367U;
            aOrbiterC = RotL64((aOrbiterC * 14735674576470803699U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9587142385246940125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16253850371962732943U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3408021872390904463U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14990060157351237661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12849591986267890852U;
            aOrbiterK = RotL64((aOrbiterK * 2158106726261981983U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 58U)) + aOrbiterH) + RotL64(aCarry, 53U)) + RotL64(aNonceWordE, 51U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 39U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 56U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterB, 21U)) + RotL64(aNonceWordD, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD396B76075725D13ULL + 0x98CA0EBCE5D982CDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBA7D1A5F8F803811ULL + 0xD38BA3D20B7337B4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD392F852F814888DULL + 0xE8A6CD5A42114FF7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9EC61C738A7EA965ULL + 0x80F66C2012BC5334ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8A2BB7667B62C30FULL + 0xEEBE16ABCA9571A8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE56A91396AFF6B05ULL + 0xA0F0B88A527ABF44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD2DF88DFC68405CDULL + 0xF082695514325E1AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD1BF174F5B3305FFULL + 0xC482B95545CD5CEAULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5413U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1588U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3250U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2403U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 10U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aPrevious, 51U)) + 16802219662864902427U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 14332033461409490629U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 30U)) + 8781794298640286845U) + RotL64(aNonceWordE, 31U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 41U)) + 8459933908074937264U) + RotL64(aNonceWordG, 19U);
            aOrbiterB = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 1883580287986004426U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 57U)) + 17500258188004626118U;
            aOrbiterK = (aWandererB + RotL64(aCross, 37U)) + 7934811305150872870U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 53U)) + 6380363892361098905U) + aPhaseEOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 12623079132626676910U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 43U)) + 10455208121949202703U) + aPhaseEOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 46U)) + 8805532707916767629U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9161544391400377699U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3501434325829663268U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7933545151293799637U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 651783304096081996U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 441505031509930622U;
            aOrbiterF = RotL64((aOrbiterF * 8045355432310956143U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1771159983581326424U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15227946417377695989U;
            aOrbiterA = RotL64((aOrbiterA * 1563141188972797601U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4153717524193279095U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4404521756523902829U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1410342912973206203U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6231945075461813285U) + RotL64(aNonceWordH, 50U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3864780227164426690U;
            aOrbiterK = RotL64((aOrbiterK * 18031353247480673617U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1509699687948576558U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17316114302489411191U) ^ RotL64(aNonceWordB, 57U);
            aOrbiterE = RotL64((aOrbiterE * 15490661284980281585U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2250572827340157410U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6403966113144372915U;
            aOrbiterI = RotL64((aOrbiterI * 726441947009132383U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2329903609147403156U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2486330017319455238U;
            aOrbiterJ = RotL64((aOrbiterJ * 17427461345935191757U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9333421733051210144U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14779925626161889533U;
            aOrbiterB = RotL64((aOrbiterB * 9120486933147706541U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4343688173541745311U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12686722305368397686U;
            aOrbiterD = RotL64((aOrbiterD * 17484250022537912537U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3745163111502795473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16802219662864902427U;
            aOrbiterH = RotL64((aOrbiterH * 4343730534036919417U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 22U));
            aWandererG = aWandererG + (((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 24U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + RotL64(aNonceWordC, 17U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterC, 27U)) + RotL64(aNonceWordD, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordC, 38U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7777U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 9068U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordB, 36U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7440U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 5998U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 6U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 51U)) + 2177539223979303669U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 6U)) + 3962004686551521471U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 53U)) + 8457602312617147662U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 18011802451816510632U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 9046101759168876832U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 11U)) + 11135620637431969597U) + RotL64(aNonceWordC, 27U);
            aOrbiterC = (aWandererJ + RotL64(aCross, 39U)) + 15913029940697999701U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 16304193109948135982U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 21U)) + 13208892298820080981U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 47U)) + 4182377898949419225U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 44U)) + 13970137023071326151U) + RotL64(aNonceWordH, 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8402396284835248583U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8859190834060657829U) ^ RotL64(aNonceWordE, 31U);
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9760005337757990392U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14108277760135744897U;
            aOrbiterG = RotL64((aOrbiterG * 4474681104256093885U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12226316121949012350U) + RotL64(aNonceWordA, 13U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3456392186754113960U;
            aOrbiterA = RotL64((aOrbiterA * 8704729827929941215U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5004087958637038973U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterC = RotL64((aOrbiterC * 15272157962928021009U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10889800478505074438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13728832441482547824U;
            aOrbiterH = RotL64((aOrbiterH * 17588477761978646139U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17345665880706866772U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 301139993853297566U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5812445396758354505U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2061389844760610160U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13631862266139238355U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 143613352104722701U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10767186080827509622U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4893486019456886013U;
            aOrbiterK = RotL64((aOrbiterK * 5194746459545610901U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11264795916303477037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16013652139405432608U;
            aOrbiterF = RotL64((aOrbiterF * 14924257021089920495U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5209743554932653849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13160179712987277456U;
            aOrbiterE = RotL64((aOrbiterE * 5003755912040281427U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12440615920191945386U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2177539223979303669U;
            aOrbiterB = RotL64((aOrbiterB * 3565122523239344029U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordG, 20U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 36U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterB, 39U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 30U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + RotL64(aNonceWordD, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordG, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13639U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 14530U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordB, 48U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13829U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 14319U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aPrevious, 21U)) + 15036852811491820366U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 46U)) + 305637140752898475U) + RotL64(aNonceWordF, 19U);
            aOrbiterK = (aWandererH + RotL64(aCross, 51U)) + 11948631574496129610U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 29U)) + 5321623592482991426U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 4075270159062690728U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 23U)) + 15111580500356908928U) + RotL64(aNonceWordE, 39U);
            aOrbiterB = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 7244150695504160363U) + aPhaseEOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 5131563519577488862U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 43U)) + 5881954992088651371U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 19U)) + 12780935808751507998U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 36U)) + RotL64(aCarry, 37U)) + 12599159643925470226U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 9466589929741834066U) + RotL64(aNonceWordD, 46U);
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6093158735705189789U;
            aOrbiterK = RotL64((aOrbiterK * 7453778295800853653U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17461243886150519249U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15456408913739900718U;
            aOrbiterD = RotL64((aOrbiterD * 16093292401746174671U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11260643903290392780U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7870342756041882616U;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 134484990005888936U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10626896209992890407U;
            aOrbiterC = RotL64((aOrbiterC * 12034131076645285597U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 14031164129515132292U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16395472745067254664U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1455944290845294254U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6757824754363319079U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17866422769075350837U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10226884082632410805U;
            aOrbiterA = RotL64((aOrbiterA * 206035536985843815U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14474587247775371703U) + RotL64(aNonceWordA, 43U);
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8501763445324525303U;
            aOrbiterE = RotL64((aOrbiterE * 5298694643596784007U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 222650368553738561U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3901452368735982094U;
            aOrbiterB = RotL64((aOrbiterB * 18347115513126660483U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3063093906728331146U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9026710562384443411U;
            aOrbiterF = RotL64((aOrbiterF * 8411243802199203035U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11282041925238364080U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15036852811491820366U;
            aOrbiterJ = RotL64((aOrbiterJ * 18185121326941087841U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 52U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 4U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aCross, 30U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordB, 31U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG) + RotL64(aNonceWordH, 21U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 44U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 34U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 28U) ^ RotL64(aNonceWordH, 51U)) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17353U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16798U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordC, 12U)) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21336U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 18935U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aPrevious, 56U)) + 13333509828310369865U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 35U)) + 7645352517103840797U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + 5310766306660062655U) + RotL64(aNonceWordD, 29U);
            aOrbiterK = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 5165635069832352932U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 15684141764734281849U) + RotL64(aNonceWordC, 21U);
            aOrbiterC = (aWandererG + RotL64(aIngress, 23U)) + 3327963374225061738U;
            aOrbiterI = (aWandererK + RotL64(aCross, 19U)) + 8625811794878848871U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 42U)) + 7598657468430485291U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 2881171216276746485U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 51U)) + 10237691227222918101U;
            aOrbiterB = (aWandererF + RotL64(aCross, 53U)) + 6419254255884834497U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4238455444646479956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14936613353493061492U;
            aOrbiterE = RotL64((aOrbiterE * 3544216916806292273U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15324699725208372627U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3709149613660215641U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1724290199312754307U;
            aOrbiterC = RotL64((aOrbiterC * 12597580418257897965U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13191172833570139194U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3686087945377837886U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10883609557429936283U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10418330386245397022U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5383531313632347245U;
            aOrbiterH = RotL64((aOrbiterH * 2987755379396160073U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7414716553072652212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11301761123966206201U;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8570229732236388847U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 8773754460060264773U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ RotL64(aNonceWordF, 13U);
            aOrbiterF = RotL64((aOrbiterF * 3251360788932563495U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13636929800504199371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5486599841558573720U;
            aOrbiterB = RotL64((aOrbiterB * 2867914211589815153U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13277541451512422776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10409779509190185921U;
            aOrbiterD = RotL64((aOrbiterD * 1926650154570961573U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7268295836403414306U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13815969853235433830U;
            aOrbiterG = RotL64((aOrbiterG * 11603750346752441535U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 9353249174240162324U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13333509828310369865U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10381405217943841655U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterG, 13U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterF, 28U)) + RotL64(aNonceWordH, 49U));
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordA, 20U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 52U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordA, 14U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24727U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 24749U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25846U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22273U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 43U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 57U)) + 4752759164691497960U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 18U)) + 12088872623537639782U) + aPhaseEOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 3734943577379734227U) + RotL64(aNonceWordE, 11U);
            aOrbiterH = (aWandererA + RotL64(aScatter, 29U)) + 8854778183012444234U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 51U)) + 16948373492893967275U) + RotL64(aNonceWordG, 29U);
            aOrbiterK = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 7962415690046184385U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 54U)) + 1872682375669714454U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 3U)) + 7776801806943853566U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 16665439117257230732U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 39U)) + 11088186766134265676U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 37U)) + 10850237991780969350U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6464817712131305812U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 244557182884209844U;
            aOrbiterE = RotL64((aOrbiterE * 2394270354887582889U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13261563971157415841U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2323811103717827362U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11483723582415081925U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12338803568475493422U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2811342930111104982U;
            aOrbiterA = RotL64((aOrbiterA * 5020981755203607757U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5554497011738996057U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12712169745460598698U) ^ RotL64(aNonceWordB, 5U);
            aOrbiterB = RotL64((aOrbiterB * 1985586486150377769U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17415058661427002973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9430421222715343818U;
            aOrbiterI = RotL64((aOrbiterI * 10321140659099470811U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3926618548181233180U) + RotL64(aNonceWordC, 26U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6172453297026957838U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1161551082037835233U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8633288765997226004U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17270881130844274342U;
            aOrbiterF = RotL64((aOrbiterF * 8888559940161770791U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12232950994807835262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15352600312956742750U;
            aOrbiterC = RotL64((aOrbiterC * 6140396356904933003U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5614120002595447983U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1920822446545182835U;
            aOrbiterG = RotL64((aOrbiterG * 17049182594382482085U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 625576652179261739U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2362773059031414585U;
            aOrbiterD = RotL64((aOrbiterD * 17049048587829564949U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16749690978107177915U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4752759164691497960U;
            aOrbiterJ = RotL64((aOrbiterJ * 8442185754037031199U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 37U);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 38U) + RotL64(aOrbiterF, 20U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + RotL64(aNonceWordA, 17U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterD, 18U));
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + RotL64(aNonceWordF, 61U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordA, 10U)) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31304U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 27903U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordC, 12U)) ^ RotL64(aNonceWordF, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28032U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 31720U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 7722279280863371124U) + RotL64(aNonceWordE, 41U);
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 56U)) + 11584220561732385598U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 23U)) + 7834679350105534657U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 11347994382444180879U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 43U)) + 9449903188047063431U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 6516243976652795170U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 11U)) + 8420815253991184777U;
            aOrbiterH = (aWandererD + RotL64(aCross, 51U)) + 9081386852515170937U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 21U)) + 14375955191735286867U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 30U)) + 880757589768436072U) + RotL64(aNonceWordC, 11U);
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + 3349856625725164229U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7826309957607577207U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8057435761214313635U) ^ RotL64(aNonceWordD, 23U);
            aOrbiterE = RotL64((aOrbiterE * 4718430712767038607U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9565237500443303103U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15893066735310588501U;
            aOrbiterJ = RotL64((aOrbiterJ * 8457633439171452397U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3276844534476430842U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6828644383891274120U;
            aOrbiterG = RotL64((aOrbiterG * 979580351653410157U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2815676923011504251U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5030251870850928417U;
            aOrbiterB = RotL64((aOrbiterB * 7075653570570819253U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 13464083008377887034U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8994560761846897590U;
            aOrbiterH = RotL64((aOrbiterH * 9892839554658865143U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8398813387154468736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8136429428340910892U;
            aOrbiterF = RotL64((aOrbiterF * 3348811490733577295U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 418587250696862341U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 4111667833838312094U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterK = RotL64((aOrbiterK * 860949442143849147U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6075478294190926371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2208124955874142264U;
            aOrbiterD = RotL64((aOrbiterD * 15741988616251072075U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4726538724576443010U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6524078248882840425U;
            aOrbiterC = RotL64((aOrbiterC * 9784875566721689069U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14521003220464811621U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16916247868211621303U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1911638054294853877U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18207293125461843123U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7722279280863371124U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14303108475807941791U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aNonceWordA, 20U)) + aPhaseEWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 20U)) + aOrbiterE) + RotL64(aNonceWordH, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 37U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterD, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 6U)) + aOrbiterG) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x96FD78088282A7F3ULL + 0xC8D1BE20BE0C3D71ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBF7DB26546FFB739ULL + 0xE758BBE7591C2F30ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF7F0C352C04729C5ULL + 0xD4924C8738B3F68AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9DB021ABE54AD497ULL + 0xB6E404EAC4463A9FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCF5BCFD1DDC915D1ULL + 0xED1CBB8EF7EE462EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD178E69CBA1EC4BDULL + 0xA688C5FD51B05F98ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA5035BDECDE80073ULL + 0xD8DF9D51CFD37503ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA8CA5C8EFC487147ULL + 0xF153D3FDAFC1933AULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1054U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 173U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 236U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1465U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aCross, 24U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 26U)) + 4259993311776766595U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 41U)) + 2857813330021126753U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 1345396841329442896U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 57U)) + 320992148982301024U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 39U)) + 5619109532065293074U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 13U)) + 10380157329426706345U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + 12449831150625409695U) + RotL64(aNonceWordA, 31U);
            aOrbiterE = (aWandererD + RotL64(aIngress, 3U)) + 7847096607042268396U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 11707184096803214678U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 3U)) + 9893643746186827088U) + RotL64(aNonceWordG, 11U);
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + 333687403830908774U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13837360705077441580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4367119682175710689U;
            aOrbiterG = RotL64((aOrbiterG * 10295744669174603401U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1193493435041306784U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15062951612027370606U;
            aOrbiterB = RotL64((aOrbiterB * 2509383510565136549U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16000173839235429105U) + RotL64(aNonceWordH, 12U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15294482444605409961U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1031800997944302665U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5720749055549773527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17248674962996093668U;
            aOrbiterC = RotL64((aOrbiterC * 15730637462755795591U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16956840483882091059U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9637715107943515594U;
            aOrbiterJ = RotL64((aOrbiterJ * 8878362378343603463U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7147495779349862274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7508890985889484275U;
            aOrbiterK = RotL64((aOrbiterK * 17728368447504622035U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 4407738164617959366U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordB, 7U);
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17027017782352660454U;
            aOrbiterD = RotL64((aOrbiterD * 417183060881259295U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3174658601748235285U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9779053567370714831U;
            aOrbiterI = RotL64((aOrbiterI * 6383245776181968033U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16256981360027888091U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12778335633397105924U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10821225965811763659U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13985909343937844583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14307218309393008729U;
            aOrbiterE = RotL64((aOrbiterE * 12053366452617039877U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15549857305890093491U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4259993311776766595U;
            aOrbiterF = RotL64((aOrbiterF * 13703695714360435719U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + RotL64(aNonceWordC, 53U));
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterF, 37U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aNonceWordE, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 44U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 13U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 60U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 53U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10673U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6351U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6832U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7633U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 9774364261626083532U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 26U)) + 18059001521926116420U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 10615626210406381148U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 10536484278007898620U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 13320663045139972700U) + RotL64(aNonceWordD, 31U);
            aOrbiterI = (aWandererI + RotL64(aScatter, 14U)) + 17127001787268166583U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 35U)) + 16742574590844166551U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 43U)) + 8347719720758228053U) + RotL64(aNonceWordG, 13U);
            aOrbiterJ = (aWandererF + RotL64(aScatter, 41U)) + 13502468705946051986U;
            aOrbiterF = (aWandererB + RotL64(aCross, 19U)) + 3512687886188904904U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 3U)) + 495660316165795934U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5092722552034477356U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15641128019608284015U;
            aOrbiterG = RotL64((aOrbiterG * 3621036395703527059U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15421873776811085458U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17978775513204574125U;
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16617179197537669849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1931805387534012528U;
            aOrbiterH = RotL64((aOrbiterH * 3400139345857733775U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9544923119559308431U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12930999400470173353U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16791006919271490005U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13673733276226249890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2032263473309124738U;
            aOrbiterJ = RotL64((aOrbiterJ * 3088728329261360607U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 14868502349358414206U) + RotL64(aNonceWordA, 47U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10116495537187552321U) ^ RotL64(aNonceWordH, 3U);
            aOrbiterB = RotL64((aOrbiterB * 1380512121796709469U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5341113995358179244U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8415417980279705731U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8521501372683793821U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2462819265072352463U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7657062767608441931U;
            aOrbiterI = RotL64((aOrbiterI * 15554638801273540163U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8153420530633265789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10990681417675210534U;
            aOrbiterA = RotL64((aOrbiterA * 1928509513380702895U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17035995983178569271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2806563871848226777U;
            aOrbiterF = RotL64((aOrbiterF * 4137935663733587867U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6570698907081812011U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9774364261626083532U;
            aOrbiterC = RotL64((aOrbiterC * 1766375419340392741U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterI, 48U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 37U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordE, 36U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + RotL64(aNonceWordB, 11U));
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterF, 42U));
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12013U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11055U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 23U) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11164U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13270U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 23U)) + 12222235191147985484U;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 57U)) + 16367317014523328414U) + RotL64(aNonceWordF, 53U);
            aOrbiterF = (aWandererK + RotL64(aPrevious, 41U)) + 3511378091284703789U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 57U)) + 15247492830966725949U) + RotL64(aNonceWordD, 59U);
            aOrbiterI = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 7745995913390407897U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 38U)) + RotL64(aCarry, 27U)) + 6463593307540108810U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 29U)) + 1101669311005268630U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 21U)) + 12988052764067518580U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 43U)) + 17717179747434679772U;
            aOrbiterH = (aWandererI + RotL64(aCross, 3U)) + 11662190906682400416U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 5U)) + 6563014073547628748U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13099094932059419219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16342730862261868847U;
            aOrbiterF = RotL64((aOrbiterF * 10988124108686164829U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16855346813127524624U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6570063128502306944U;
            aOrbiterB = RotL64((aOrbiterB * 4571570049463124831U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 11328352033809240501U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11640986648833160901U;
            aOrbiterE = RotL64((aOrbiterE * 2895830492089678919U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2675226158571501666U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17700531248266458165U;
            aOrbiterI = RotL64((aOrbiterI * 2231403813970188657U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7729597396731910874U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15172374484412053756U;
            aOrbiterC = RotL64((aOrbiterC * 149009041406406517U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9178769489257842683U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9020154972097834926U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8910504667566521429U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 1317403761217790562U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17151528554929201571U;
            aOrbiterA = RotL64((aOrbiterA * 3735945655450625203U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11621882033959669977U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10289504450815075623U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13365982786836243195U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16178772981106335703U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 16896130772325866910U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordG, 30U);
            aOrbiterD = RotL64((aOrbiterD * 6993524735412868965U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9573223644675562575U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17552463713786507189U;
            aOrbiterK = RotL64((aOrbiterK * 16103431656424881779U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4801852246698369631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12222235191147985484U;
            aOrbiterG = RotL64((aOrbiterG * 2835204872125428065U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 50U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterB) + RotL64(aNonceWordA, 55U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + RotL64(aNonceWordC, 61U));
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 58U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 10U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordG, 24U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20790U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17555U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18442U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20181U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 6U)) + 14214886793361825363U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 27U)) + 17267959031078766320U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 16436067429484887644U) + RotL64(aNonceWordC, 17U);
            aOrbiterK = (aWandererA + RotL64(aScatter, 41U)) + 9885951769332633820U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 57U)) + 12971711341813893304U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordD, 6U);
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 20U)) + RotL64(aCarry, 5U)) + 199970353398450154U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 11U)) + 1237341696444162094U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 43U)) + 7991128854417613360U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 51U)) + 14809029847149045833U;
            aOrbiterB = (aWandererB + RotL64(aCross, 23U)) + 2559509556915775947U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 14336829730147834160U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8853631886733610440U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13346159398673246914U;
            aOrbiterH = RotL64((aOrbiterH * 13660497151446983393U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12121095718571872976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16239781125815589804U;
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9051377033794324106U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13805815136723461780U;
            aOrbiterI = RotL64((aOrbiterI * 571129481747181357U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14849157800322754413U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18116651528452542634U;
            aOrbiterA = RotL64((aOrbiterA * 3638480428016835537U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4105057226952948599U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5911714320560994391U;
            aOrbiterC = RotL64((aOrbiterC * 1796514171654961389U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4439149331729987587U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10278532228230163632U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterD = RotL64((aOrbiterD * 17428224919864716517U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2342456582668741750U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2360578572554664800U) ^ RotL64(aNonceWordF, 39U);
            aOrbiterB = RotL64((aOrbiterB * 1108428466956691925U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12132934875391401246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17213278726790245812U;
            aOrbiterJ = RotL64((aOrbiterJ * 11904899990681410419U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7994340481560109811U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13735851271080138255U;
            aOrbiterG = RotL64((aOrbiterG * 12387076892129731557U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6682417543888875268U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15642799286975840550U;
            aOrbiterE = RotL64((aOrbiterE * 7861250716882028053U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 9839299346094784067U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14214886793361825363U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2103132743364916037U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 44U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 18U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterH, 37U)) + RotL64(aNonceWordA, 37U));
            aWandererD = aWandererD + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 21U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 50U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + RotL64(aNonceWordH, 49U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 52U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 38U) ^ RotL64(aNonceWordG, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22880U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 23722U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordH, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22819U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25290U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 13296600294247799698U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 5818503518080877515U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 41U)) + 6735784238734173597U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 52U)) + 7368398209488856201U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 43U)) + 961734029066455638U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 797011946660892011U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 39U)) + 12841876018396622350U) + RotL64(aNonceWordB, 37U);
            aOrbiterJ = (aWandererD + RotL64(aIngress, 27U)) + 16213253970483895623U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + 15186950557113470375U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 57U)) + 5117930310827477341U) + RotL64(aNonceWordG, 21U);
            aOrbiterK = (((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 37U)) + 12265429373166094162U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13920531346698601568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14695405206998211456U;
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7851960904825938443U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9501511171732550190U) ^ RotL64(aNonceWordA, 30U);
            aOrbiterD = RotL64((aOrbiterD * 5614164120361489613U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5663365182245722077U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9607860124321315555U;
            aOrbiterJ = RotL64((aOrbiterJ * 3461820361914280601U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18171052650586819280U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3442698321538580861U;
            aOrbiterI = RotL64((aOrbiterI * 6317525514963824829U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1491052813469258970U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3956599824067616133U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2928600779267623085U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10963841237346073453U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2303020125591252534U;
            aOrbiterE = RotL64((aOrbiterE * 9969099842343321981U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14503856057958162356U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11147548150090597694U;
            aOrbiterG = RotL64((aOrbiterG * 11856382308792700441U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9191681438318311481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13556072770381999852U;
            aOrbiterH = RotL64((aOrbiterH * 18316231099054203683U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10103207278550444685U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10415809965217261104U) ^ RotL64(aNonceWordE, 39U);
            aOrbiterK = RotL64((aOrbiterK * 16562732599511350217U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17435033201864058457U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5540494424887364682U;
            aOrbiterA = RotL64((aOrbiterA * 18230910315317249045U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 18020151683897013854U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13296600294247799698U;
            aOrbiterB = RotL64((aOrbiterB * 10000194329456668845U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 5U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 52U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordH, 7U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterE, 54U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aNonceWordF, 61U)) + aPhaseFWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordD, 5U)) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27548U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28973U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordB, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32492U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 30662U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 40U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 39U)) + 16183871922837164759U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 53U)) + 7002058258090219055U) + RotL64(aNonceWordC, 25U);
            aOrbiterI = ((aWandererD + RotL64(aScatter, 11U)) + 5650868611888303705U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 21U)) + 11899839660943876690U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 35U)) + 15349649504488111111U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 14060149569086744970U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 12920917574225030112U) + RotL64(aNonceWordD, 19U);
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 2831994965175330135U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 51U)) + 18312543585028439192U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 11657562205118394239U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 58U)) + 10850792819281246052U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 17810371216216125323U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordH, 45U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7963413941144223128U;
            aOrbiterI = RotL64((aOrbiterI * 534217972450595401U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5498715358793875584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterG = RotL64((aOrbiterG * 10498848323914000989U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17246360111302191699U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 18309978718113983369U;
            aOrbiterA = RotL64((aOrbiterA * 18267472694666221077U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3100998994319502921U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8129301860291235970U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17847033539279176187U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1889641029473279114U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16538494307002917945U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8081488217920885783U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 5432230549146849322U) + RotL64(aNonceWordG, 22U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2634437941396090817U;
            aOrbiterB = RotL64((aOrbiterB * 7612999214758935211U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16940172599174185058U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13151669140593952203U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16225319638131723487U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3995064294869931681U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 913081077665768816U;
            aOrbiterH = RotL64((aOrbiterH * 9299514648768060453U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2469001696075411481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2167390955194185443U;
            aOrbiterC = RotL64((aOrbiterC * 11805065572289005223U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1574066406534010796U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8736976961589874013U;
            aOrbiterF = RotL64((aOrbiterF * 5980070607180321955U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 4233621443153132083U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16183871922837164759U;
            aOrbiterD = RotL64((aOrbiterD * 4030569514959370895U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 44U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + RotL64(aNonceWordB, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 30U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterE, 35U));
            aWandererF = aWandererF + (((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBF293B42F9857D75ULL + 0xA0E0E75291E739F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB121158A31726FBFULL + 0x8FF006097EEB056FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x921E844D53742BABULL + 0xD1F0CA0F0F58335BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAE564B1BF674F72BULL + 0x8C8C1E465B8F585EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC29AEA7F58F2F15BULL + 0xAAD4A73E10DC683DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8A0536A71CDFD5ABULL + 0xD8D096392DF6793EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xECB0A8D12BC3FB55ULL + 0xFE15C19FED189D4BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC5A8AD1FD6AE8C53ULL + 0xEAB34D6D026B91D9ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1526U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((aIndex + 826U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 34U) ^ RotL64(aNonceWordG, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4220U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2501U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aCross, 11U)) + 8767379393098711499U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 7168159491580816433U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 9879279829061883406U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 56U)) + 10537167136053399303U) + RotL64(aNonceWordE, 59U);
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 29U)) + 2839070018069188936U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 13844278063968429732U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 11278946626186474646U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 51U)) + 11798425216660557799U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 35U)) + 7618446090703335192U) + RotL64(aNonceWordG, 23U);
            aOrbiterB = (aWandererC + RotL64(aIngress, 47U)) + 695423597006983660U;
            aOrbiterH = (aWandererE + RotL64(aCross, 26U)) + 14344728202803488813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11656100506575697086U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10384358779985773937U;
            aOrbiterK = RotL64((aOrbiterK * 247494692039140973U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17585001605131977341U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9964478171465522911U) ^ RotL64(aNonceWordD, 50U);
            aOrbiterF = RotL64((aOrbiterF * 13484044854790175315U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2710943171829692624U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17809072853457153057U;
            aOrbiterI = RotL64((aOrbiterI * 16341884203303271365U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12814092033910687774U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1743186323268668740U;
            aOrbiterE = RotL64((aOrbiterE * 11150822630624332557U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10750472346626754704U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15925901217078035356U;
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2569102106359362359U) + RotL64(aNonceWordC, 45U);
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8868261301410769739U;
            aOrbiterC = RotL64((aOrbiterC * 3662495603133918101U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2143691008373582476U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10606616796243205921U;
            aOrbiterH = RotL64((aOrbiterH * 15794414817813485643U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16258070651850746855U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11720192793689633315U;
            aOrbiterD = RotL64((aOrbiterD * 14475623219460678021U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8230871037292355675U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16898650748046368353U;
            aOrbiterJ = RotL64((aOrbiterJ * 7368697435476300255U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9071122174426904737U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4506737259011736474U;
            aOrbiterG = RotL64((aOrbiterG * 11903039808814842447U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4545409671845718259U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8767379393098711499U;
            aOrbiterB = RotL64((aOrbiterB * 1210632171306946669U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 34U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterI, 24U));
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 38U) + aOrbiterK) + RotL64(aOrbiterE, 57U));
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 26U)) + aOrbiterE) + RotL64(aNonceWordB, 21U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 44U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aNonceWordA, 37U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordD, 60U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5923U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9514U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordB, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8015U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6658U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 12131317914288566437U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 51U)) + 5672805657999385496U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordH, 53U);
            aOrbiterC = ((aWandererC + RotL64(aCross, 34U)) + RotL64(aCarry, 11U)) + 3581710244233124197U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 39U)) + 15251296040538489436U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 5U)) + 11295008604679904153U;
            aOrbiterF = (aWandererE + RotL64(aCross, 53U)) + 2230897493419504490U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 27U)) + 7109600123297458999U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 47U)) + 13119156643107683803U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 14755160867807355250U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 3U)) + 16829363373287496832U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 18U)) + 16981122946707720883U) + RotL64(aNonceWordB, 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8806000776958603317U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16810923047720876014U;
            aOrbiterC = RotL64((aOrbiterC * 17872735050219539145U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8129657889554436328U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8653100378491974463U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11395283153912468661U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17048985838727432415U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10892675550889823573U) ^ RotL64(aNonceWordG, 59U);
            aOrbiterG = RotL64((aOrbiterG * 976298937314081913U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15960158965421254346U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12290011578634850001U;
            aOrbiterI = RotL64((aOrbiterI * 9280475585104357745U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16265047040311479093U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10312956912303656248U;
            aOrbiterK = RotL64((aOrbiterK * 3012584393253845131U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16706890352221352779U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10630955894218491929U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12675937483456206355U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4009352551041162434U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3043810773683888556U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4328135390387997315U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1398071019814944785U) + RotL64(aNonceWordE, 26U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16689766557488135301U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8403881916549404871U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15934647144489136524U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13521276033614992223U;
            aOrbiterD = RotL64((aOrbiterD * 18003640895553609933U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4281211055727414100U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11848150507497406421U;
            aOrbiterA = RotL64((aOrbiterA * 1107789990317433481U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12022829841608199449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12131317914288566437U;
            aOrbiterB = RotL64((aOrbiterB * 13275753083882829973U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 10U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aNonceWordD, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 6U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + RotL64(aNonceWordA, 31U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordG, 10U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13871U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15935U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13734U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneC[((aIndex + 15079U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 23U)) + 13499155707765393469U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 21U)) + 3740324981823726185U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 57U)) + 5470765363949735652U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aCross, 4U)) + 3446436171274452326U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 29U)) + 1778929412631211933U;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 14666308799855220954U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 11U)) + 4548410236791175055U) + RotL64(aNonceWordD, 43U);
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 5829739767694190372U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 14319231414903675748U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 37U)) + 1513851750246111405U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 37U);
            aOrbiterB = ((aWandererG + RotL64(aCross, 14U)) + RotL64(aCarry, 29U)) + 1685620217748986019U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16284162182006054402U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6271539598462003309U;
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12669312437565969473U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11894755313393001665U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6315983824634946566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17106616474222892782U;
            aOrbiterH = RotL64((aOrbiterH * 167205520766791073U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13350266700180455548U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4608846311203767162U;
            aOrbiterI = RotL64((aOrbiterI * 2504857468837437365U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14195866746143604365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7917977448256795054U;
            aOrbiterJ = RotL64((aOrbiterJ * 5927771378657284557U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10707336923305131629U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17122696159336995392U;
            aOrbiterK = RotL64((aOrbiterK * 13953518568670659191U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5182322763573586116U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6503754948502556246U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterE = RotL64((aOrbiterE * 14749002194140663519U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14907832047832987341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6258064448676621346U;
            aOrbiterF = RotL64((aOrbiterF * 4407960312705621487U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1180234574888070795U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 801686887651085881U) ^ RotL64(aNonceWordF, 30U);
            aOrbiterA = RotL64((aOrbiterA * 433981853631548041U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11810494591997709554U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9343740505955858127U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8733378485648720323U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12816829575386720695U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13499155707765393469U;
            aOrbiterB = RotL64((aOrbiterB * 9937924703928730369U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + RotL64(aNonceWordA, 17U));
            aWandererE = aWandererE + ((RotL64(aScatter, 26U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterI, 22U)) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aNonceWordH, 7U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordC, 14U)) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21370U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21792U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordD, 51U)) ^ RotL64(aNonceWordA, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18145U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 19041U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 12583180859826261500U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 35U)) + 9067093488553721468U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 39U)) + 12173106198862881754U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 54U)) + 11333491014394592654U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 11U);
            aOrbiterK = (aWandererB + RotL64(aPrevious, 11U)) + 3511883526940919554U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 27U)) + 7416810692106273044U) + RotL64(aNonceWordE, 57U);
            aOrbiterF = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 8341174972619784110U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 43U)) + 2220852854836962979U;
            aOrbiterG = (aWandererE + RotL64(aCross, 41U)) + 8090781422229383825U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 13U)) + 2338801236599102223U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 48U)) + RotL64(aCarry, 13U)) + 12484514711848308104U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 13684861340589131816U) + RotL64(aNonceWordB, 31U);
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 12796636819991873058U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ RotL64(aNonceWordF, 35U);
            aOrbiterD = RotL64((aOrbiterD * 5533508014234835669U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7634198650894837690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10240326122201201762U;
            aOrbiterK = RotL64((aOrbiterK * 8758703497719125901U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4162814763739453934U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2766504649149048469U;
            aOrbiterA = RotL64((aOrbiterA * 16731843453895178671U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 11051393030148769655U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17687055068651386665U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3353615315436983420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5971640796220306310U;
            aOrbiterJ = RotL64((aOrbiterJ * 15804313508835034807U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12299773092762384765U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7435804907797063411U;
            aOrbiterG = RotL64((aOrbiterG * 9848139805288165965U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8735783937125735699U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11903126115475835615U;
            aOrbiterI = RotL64((aOrbiterI * 16942088822124940265U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4427166023462475475U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6011733469446008137U;
            aOrbiterC = RotL64((aOrbiterC * 17298067225913923517U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 18341473946127677319U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5423774915753911947U;
            aOrbiterE = RotL64((aOrbiterE * 14985099502923458523U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2384393657884193014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2650593524388493958U;
            aOrbiterB = RotL64((aOrbiterB * 892985816665547945U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15991261431384033176U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12583180859826261500U;
            aOrbiterH = RotL64((aOrbiterH * 14394838775646875599U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 46U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC + (((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 51U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 10U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aNonceWordH, 7U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 38U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + RotL64(aNonceWordG, 56U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordF, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24710U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25397U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordD, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22795U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22469U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 36U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 39U)) + 13481227414590594621U) + aPhaseFOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 17425964381118918026U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + 4792004356135956581U) + RotL64(aNonceWordA, 53U);
            aOrbiterB = (aWandererG + RotL64(aIngress, 41U)) + 11926849936000639098U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 37U)) + 990697329347742142U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 5U)) + 9307721505373076588U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 3U)) + 17605732738841908719U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 28U)) + RotL64(aCarry, 51U)) + 13110764518634187439U;
            aOrbiterE = (aWandererH + RotL64(aCross, 21U)) + 17970109897810645911U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 10273133817644703654U) + aPhaseFOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aScatter, 43U)) + 11239046688920468137U) + RotL64(aNonceWordB, 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8355821483275763145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15522151127786049345U;
            aOrbiterH = RotL64((aOrbiterH * 4844278537850520413U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5381663179722418112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9551368011768104906U;
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16264476585232221270U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7721417776432288282U;
            aOrbiterA = RotL64((aOrbiterA * 10267770327791051869U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 339418090653475277U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3247926250495935511U;
            aOrbiterC = RotL64((aOrbiterC * 16824669543765729097U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3390560045236418590U) + RotL64(aNonceWordH, 41U);
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3894024951542543635U;
            aOrbiterG = RotL64((aOrbiterG * 10599637790900418767U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3878539166189668154U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5617705593218220843U;
            aOrbiterB = RotL64((aOrbiterB * 82771190372750823U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12320861089148474544U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 14943790251625519550U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordF, 11U);
            aOrbiterK = RotL64((aOrbiterK * 13758322022902008313U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18119213517612562775U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1413193144229486646U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14562375280658115687U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14810150213456844196U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8468712395797520201U;
            aOrbiterI = RotL64((aOrbiterI * 8167911669632436949U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13501570100536254566U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15409772061478100850U;
            aOrbiterF = RotL64((aOrbiterF * 955182899606655851U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8621805947309982779U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13481227414590594621U;
            aOrbiterJ = RotL64((aOrbiterJ * 9591362493722704105U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 52U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterB, 22U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterA, 41U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + RotL64(aNonceWordC, 20U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + RotL64(aNonceWordG, 37U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 38U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 20U) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27683U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29250U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 47U) ^ RotL64(aNonceWordC, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32457U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30862U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 21U)) + 14823268998003220191U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 11U)) + 15295237288788213847U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 40U)) + RotL64(aCarry, 27U)) + 16434853402001133899U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 7555911304407871631U) + RotL64(aNonceWordF, 35U);
            aOrbiterI = (aWandererE + RotL64(aScatter, 19U)) + 14977248264994834620U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 27U)) + 9707764144919392380U) + RotL64(aNonceWordH, 34U);
            aOrbiterC = (aWandererJ + RotL64(aIngress, 46U)) + 1277304385464681529U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 3089786220465849395U;
            aOrbiterD = (aWandererI + RotL64(aCross, 43U)) + 3700503853358695085U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 37U)) + 3240054112993517371U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 5U)) + 16897532076915366859U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18167359289798364307U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8870819278575769863U;
            aOrbiterA = RotL64((aOrbiterA * 9334066154398059075U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 15363069206212330251U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordE, 29U);
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14858164441499725158U;
            aOrbiterI = RotL64((aOrbiterI * 14931933411393847915U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5357144808788707522U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2910681277417754860U;
            aOrbiterF = RotL64((aOrbiterF * 13170868582159347059U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9824408699018165151U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 368370224788793300U;
            aOrbiterC = RotL64((aOrbiterC * 14358982366258729959U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7095398304588825115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11418879758164313554U;
            aOrbiterH = RotL64((aOrbiterH * 5983520332639771791U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2171599720681913272U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17593730219647495033U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12926053208918563087U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17755947635188715523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14565740605227022106U;
            aOrbiterG = RotL64((aOrbiterG * 15866418354612945335U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14538017880915584414U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6174566474851449123U;
            aOrbiterB = RotL64((aOrbiterB * 179569008593475683U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3806438394748643441U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13737114463856719285U;
            aOrbiterK = RotL64((aOrbiterK * 13439346068497710151U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3698379331577470045U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1097081284062708554U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3498627643013255777U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 215117138867597766U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14823268998003220191U) ^ RotL64(aNonceWordB, 9U);
            aOrbiterE = RotL64((aOrbiterE * 12131828437975771377U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 28U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterK, 50U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterA, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordA, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterC, 44U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aNonceWordD, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3438U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 170U)) & W_KEY1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1774U)) & W_KEY1], 14U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 6U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 39U)) + 6733949564325516029U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 7304098437143918796U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 43U)) + 3923949518391777800U) + aPhaseCOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 3U)) + 14243591003388927124U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 18329498724605410406U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 38U)) + 13118172167747037249U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 29U)) + 5272025143849174212U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 16075917179214318424U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 13U)) + 15263590648674658399U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13730046728289525921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7703141464499623408U;
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1382279753822135359U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2973369221699098292U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11578274119583013219U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3419411247737896674U;
            aOrbiterA = RotL64((aOrbiterA * 17814942652262802991U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2582783513078999303U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3959762790273529677U;
            aOrbiterK = RotL64((aOrbiterK * 383974377372162751U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 465795011576934604U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10819659185349413173U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17298208553586835030U;
            aOrbiterG = RotL64((aOrbiterG * 1965860510614222093U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12585880006661489402U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16650193903267408586U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5781132589396936615U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 885882046325991589U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 869560078374809974U;
            aOrbiterH = RotL64((aOrbiterH * 13440973563438747181U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11871305571797951851U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12137095015607196226U;
            aOrbiterI = RotL64((aOrbiterI * 7618152256560808581U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 4U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterF, 48U)) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 42U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 57U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterI, 52U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 48U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15169U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13363U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14342U)) & W_KEY1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9986U)) & W_KEY1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 35U)) + 8866844335448071821U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 47U)) + 15159698739856430085U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 23U)) + 9582805772989594633U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 1438538239931588373U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 10862044156620436139U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 29U)) + 13682173320058164615U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 41U)) + 8351013291045977592U) + aPhaseCOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 15777857431516633916U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 12U)) + 16178966745333885377U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9031889187993001617U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 642109145903321046U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9186268569255318035U;
            aOrbiterD = RotL64((aOrbiterD * 10714674348507516749U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6091345356803675860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterA = RotL64((aOrbiterA * 15415157927185637717U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4266652275234474616U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4391422098164506195U;
            aOrbiterG = RotL64((aOrbiterG * 17634679403195085867U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5160682323243635577U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3950932176454814023U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9536466386833427441U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18064984243491293435U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9927425919978776529U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6819384090527481081U;
            aOrbiterC = RotL64((aOrbiterC * 18032965969184368561U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1646274931424218507U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16166524473976135097U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11672192658072663849U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11252501968059485262U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16847854447987609067U;
            aOrbiterF = RotL64((aOrbiterF * 6326299154627028295U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 42U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 4U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterH, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17847U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20451U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17778U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 19904U)) & W_KEY1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 26U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 43U)) + 11177787645248006236U) + aPhaseCOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 58U)) + 3808340254579817169U;
            aOrbiterF = (aWandererA + RotL64(aCross, 5U)) + 828030667598518279U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 23U)) + 16177835921238398371U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 5518747735458708741U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 17346319082399995165U) + aPhaseCOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 18U)) + 6397156921893030937U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 15559381654710713582U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 27U)) + 940404446491415088U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 8047166032048732645U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4688468645859470491U;
            aOrbiterF = RotL64((aOrbiterF * 14383536431614496369U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3710878044770337260U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 116343189456629220U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 883908030159391659U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18058691521694880482U;
            aOrbiterG = RotL64((aOrbiterG * 3132200449123497619U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17521015077103586117U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3668332225435714918U;
            aOrbiterD = RotL64((aOrbiterD * 12658899101297839881U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12229480388278883300U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16206524049491531816U;
            aOrbiterC = RotL64((aOrbiterC * 11122340196620859805U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5743265849441077466U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 2812293020719282236U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8903956475200417109U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13718364781538837074U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 861529717259766236U;
            aOrbiterA = RotL64((aOrbiterA * 17019744777211266685U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4862687502126693872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7722024283321020761U;
            aOrbiterE = RotL64((aOrbiterE * 18086944039541060829U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8205803118233399853U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15130160926615050422U;
            aOrbiterI = RotL64((aOrbiterI * 1454552751453996765U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 6U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 18U)) + aPhaseCWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25597U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 27127U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26863U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28086U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 3248574644570178787U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 19U)) + 4506961512959200024U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 34U)) + RotL64(aCarry, 3U)) + 8423739774540738590U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 23U)) + 6593975869641735337U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 39U)) + 16441716090557369103U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 47U)) + 7936601450453207914U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 28U)) + 13333752583560167065U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 8013703284795432973U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 13U)) + 2349852779887439236U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5318539364763284138U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11450957608502944376U;
            aOrbiterC = RotL64((aOrbiterC * 1957880366707810635U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9058992558327552687U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 632095686920230926U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12460364388358520799U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14734218428913777098U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16344357661370784442U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15049472842002138369U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2981145363531184308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14176472085175714494U;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11198457590069700889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 952584436750426828U;
            aOrbiterE = RotL64((aOrbiterE * 1165713888651280355U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4311591763498985972U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16194341833989936369U;
            aOrbiterB = RotL64((aOrbiterB * 9997934560195932575U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7560794022401107431U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10683789740265711603U;
            aOrbiterG = RotL64((aOrbiterG * 15637823045351977883U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11614366395125937178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10750771385100564416U;
            aOrbiterA = RotL64((aOrbiterA * 4987921274272444283U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2934697034132204529U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4646873794658020363U;
            aOrbiterK = RotL64((aOrbiterK * 10555456865641580175U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 39U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 24U)) + aOrbiterA) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3106U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 7573U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 724U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 1619U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 13278949403988203974U) + aPhaseDOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 3U)) + 9213599924054673756U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 1255746482932381798U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 11575321997144516122U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 19U)) + 15881587525529432437U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9846195809864862707U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12319815691858217670U;
            aOrbiterD = RotL64((aOrbiterD * 14271546305640811091U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16322617427294439587U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16332130810525887437U;
            aOrbiterC = RotL64((aOrbiterC * 7588076439690559343U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4920951156015336794U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16767126455124552329U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4440352337076842603U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 12553595911087945223U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1437522202135436142U;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12313100454852227143U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2761983020631055729U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3874839760378039509U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 56U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterD, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8853U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15264U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12504U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11302U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 29U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 11998579547770778580U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 60U)) + 8409465187298704610U) + aPhaseDOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 3470222286110333500U) + aPhaseDOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 5704486785203069994U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 19U)) + 10334944660253279633U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7626852700722567477U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14631310754943209743U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1958866541508493967U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 807160297237854120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5624154783624196107U;
            aOrbiterD = RotL64((aOrbiterD * 2404066593958052159U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4971444394698940423U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6340057638461027062U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12027586111086798629U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9003019862787819481U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13632057463595873033U;
            aOrbiterK = RotL64((aOrbiterK * 12575202147280216765U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12766104026871797746U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4062118445824915939U;
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterK, 5U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 14U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21200U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21670U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19236U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((aIndex + 21832U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 60U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 4384716820085860551U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 38U)) + 9715780315942116888U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 15963520052789178632U) + aPhaseDOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 19U)) + 14346700690686392938U) + aPhaseDOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 6005518012489966643U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2506732930310252119U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16782163084851775826U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1527050617428162663U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 823673076571076303U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1634084509064077736U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1128407326773234517U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1288134975466877686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2998220403162908444U;
            aOrbiterA = RotL64((aOrbiterA * 4321412662318298283U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 220430672180734911U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10223923547068528867U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 11696469696177647608U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6545430420379636963U;
            aOrbiterH = RotL64((aOrbiterH * 8387163146257553773U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 48U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29055U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30823U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27327U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31402U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 5173905450211892891U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 37U)) + 3555542451908039957U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 11559884700283861559U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 1352524329968738673U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 60U)) + 8914206450420616349U) + aPhaseDOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2251523378498463946U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9541575923299247038U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1066487482799638689U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1239854507907214595U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17698101462598498934U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2304948713665996433U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12305566971683256060U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13804545036303215569U;
            aOrbiterH = RotL64((aOrbiterH * 10359543704152744971U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10239749097704329264U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4212214906286320308U;
            aOrbiterE = RotL64((aOrbiterE * 3661436621615751071U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12192418916967430783U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4475514289326450361U;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 19U));
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 48U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3652U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 1664U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6597U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 393U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 26U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 2672739400294801233U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 8475624545015101850U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + 1252755112289831257U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 7938039507649183387U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 11U)) + 8167413146948861022U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 43U)) + 17712313989694374353U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 4U)) + 7637042279892596975U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15770412950033467341U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3951812021898608685U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6623127125223204737U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8656983621098246507U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17943342344730687317U;
            aOrbiterJ = RotL64((aOrbiterJ * 16495519451034883813U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3087677463651608668U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16493240011924342788U;
            aOrbiterE = RotL64((aOrbiterE * 16898479041530771871U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7750923317452683057U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2185924841611106546U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 708072658250726381U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14676868738946722416U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6849098251696302393U;
            aOrbiterK = RotL64((aOrbiterK * 2599806275837778069U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17817755047153606419U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9900465270314068757U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9267925873983176685U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11380000891112113701U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15930503831156546113U;
            aOrbiterB = RotL64((aOrbiterB * 14450535035065393845U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 51U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterE, 48U));
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF + ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 10U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9937U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16166U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13854U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 13726U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 56U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 13499155707765393469U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 23U)) + 3740324981823726185U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 41U)) + 5470765363949735652U;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 3446436171274452326U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 1778929412631211933U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 29U)) + 14666308799855220954U;
            aOrbiterA = (aWandererC + RotL64(aCross, 53U)) + 4548410236791175055U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5829739767694190372U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14319231414903675748U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4966501102515775601U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1513851750246111405U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1685620217748986019U;
            aOrbiterK = RotL64((aOrbiterK * 9286548037413609445U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16284162182006054402U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6271539598462003309U;
            aOrbiterG = RotL64((aOrbiterG * 13923286694131331137U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12669312437565969473U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11894755313393001665U;
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6315983824634946566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17106616474222892782U;
            aOrbiterB = RotL64((aOrbiterB * 167205520766791073U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13350266700180455548U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4608846311203767162U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2504857468837437365U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14195866746143604365U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7917977448256795054U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 44U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterI, 58U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17882U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 17528U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18567U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19697U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 8020711767807230555U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 3U)) + 15368693777246341570U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 5117523734225562401U;
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 13155269151097507808U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 29U)) + 9879303753623578272U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 1165799257173794826U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 35U)) + 930641942062732091U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11330571332221123153U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2862963158282518899U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13782195862525974199U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6019186399361476659U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1924419843785161958U;
            aOrbiterF = RotL64((aOrbiterF * 9485557122500346869U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12618629043591380461U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterB = RotL64((aOrbiterB * 18239109235362925739U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16829692481030013551U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5604784396927022709U;
            aOrbiterK = RotL64((aOrbiterK * 2833893610883508353U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16124030106598549644U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16571659812830230677U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4668250364992383549U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15171089673591843703U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2826755560293849328U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9397017963457655287U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9976785768283589291U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11845100564714691809U;
            aOrbiterI = RotL64((aOrbiterI * 4935139932585319251U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererD = aWandererD + (((RotL64(aIngress, 6U) + RotL64(aOrbiterK, 20U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30573U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 27971U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25778U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26439U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 44U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 41U)) + 7960325128608297381U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 12773836012104052042U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 41U)) + 3173972621347773016U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 3708401356314308171U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 11U)) + 950774285720019449U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 4170092315705438265U;
            aOrbiterH = (aWandererH + RotL64(aCross, 35U)) + 17000449130864980747U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8793910540062893860U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 520277969543516469U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4150613128885828229U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12762214857389827271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2932451184340207695U;
            aOrbiterA = RotL64((aOrbiterA * 7513337346940091655U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11062179998786293839U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 7919119215271524178U;
            aOrbiterB = RotL64((aOrbiterB * 9053677007180081359U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1774988449597115155U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3799792889466518953U;
            aOrbiterI = RotL64((aOrbiterI * 17512791286490623455U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1815062051307896589U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15260373951371654483U;
            aOrbiterJ = RotL64((aOrbiterJ * 2208604434669491625U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12867546628945676853U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7772820973895846946U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7581704643538761985U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14213957831821966834U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16561105721170419454U;
            aOrbiterH = RotL64((aOrbiterH * 2540533987337175367U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 41U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 34U));
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5721U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 7148U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2385U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 360U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + 14249093584376402677U) + aPhaseFOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 8756965951816492264U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 11221139480258176330U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 17218894445564194851U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + 8064642692524949490U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5822093203710704646U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3217799620158102238U;
            aOrbiterK = RotL64((aOrbiterK * 2806328682494910635U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2613757677892120843U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13647481499551657237U;
            aOrbiterJ = RotL64((aOrbiterJ * 5517563514031899891U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3545714196663685016U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9735422670576621521U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7276207208162697249U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3911046580637583767U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9315984027042049203U;
            aOrbiterI = RotL64((aOrbiterI * 12568550776487242469U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8926367674641729058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11035347490524961446U;
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12365U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((aIndex + 12587U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11530U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14541U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 26U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 37U)) + 4752759164691497960U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 3U)) + 12088872623537639782U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 3734943577379734227U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 8854778183012444234U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 16948373492893967275U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7962415690046184385U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1872682375669714454U;
            aOrbiterE = RotL64((aOrbiterE * 959061892772099785U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7776801806943853566U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16665439117257230732U;
            aOrbiterG = RotL64((aOrbiterG * 6866375628213114965U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11088186766134265676U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10850237991780969350U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7547414856143095121U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6464817712131305812U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 244557182884209844U;
            aOrbiterB = RotL64((aOrbiterB * 2394270354887582889U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13261563971157415841U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2323811103717827362U;
            aOrbiterK = RotL64((aOrbiterK * 11483723582415081925U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aIngress, 12U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19293U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 20237U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16773U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 17654U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererG + RotL64(aCross, 38U)) + RotL64(aCarry, 43U)) + 7960325128608297381U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 11U)) + 12773836012104052042U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + 3173972621347773016U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 3708401356314308171U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 950774285720019449U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4170092315705438265U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17000449130864980747U;
            aOrbiterG = RotL64((aOrbiterG * 7710635557693533263U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8793910540062893860U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 520277969543516469U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4150613128885828229U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12762214857389827271U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2932451184340207695U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7513337346940091655U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11062179998786293839U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7919119215271524178U;
            aOrbiterH = RotL64((aOrbiterH * 9053677007180081359U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1774988449597115155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3799792889466518953U;
            aOrbiterJ = RotL64((aOrbiterJ * 17512791286490623455U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24728U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25330U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27134U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27568U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 50U)) + RotL64(aCarry, 11U)) + 11210042748013785976U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 4584747303233477454U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 8878765929792969517U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 27U)) + 2172232330280041122U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 5U)) + 8378937026022264016U) + aPhaseFOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8683007464695824208U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9564352997357118134U;
            aOrbiterH = RotL64((aOrbiterH * 17869948990449143305U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11713878436769887528U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8052917623074021077U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7450115139081623477U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7720597162792145185U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2602847785328475621U;
            aOrbiterD = RotL64((aOrbiterD * 14065077077207224525U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17813669222300509724U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8724263063156573013U;
            aOrbiterA = RotL64((aOrbiterA * 3632927017737834359U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6882429835961613492U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13213313479525717359U;
            aOrbiterE = RotL64((aOrbiterE * 2411431247725974895U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterG, 4U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6765U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4311U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6630U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 2999U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 5160910997561396461U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 44U)) + RotL64(aCarry, 3U)) + 14920764751058512062U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 53U)) + 6080952401749660022U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 17667234330526298627U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 29U)) + 760630072638686756U) + aPhaseGOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3504157162816997476U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9489022223422585882U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2398110457196177747U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1149898536879968964U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10492284328940025310U;
            aOrbiterG = RotL64((aOrbiterG * 7893416766300156495U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13213275606286399312U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10557118912847180413U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10077877991284587845U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15618980209023994776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5268600749854045564U;
            aOrbiterD = RotL64((aOrbiterD * 3849660559223919613U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8011552687609649990U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3148133096349525066U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5245156554959620007U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12761U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16268U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14128U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13611U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 12222235191147985484U;
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 16367317014523328414U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 3511378091284703789U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 15247492830966725949U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + 7745995913390407897U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6463593307540108810U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1101669311005268630U;
            aOrbiterD = RotL64((aOrbiterD * 10550146460887359369U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12988052764067518580U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17717179747434679772U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10820310705487638793U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11662190906682400416U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6563014073547628748U;
            aOrbiterI = RotL64((aOrbiterI * 16967910471722117761U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13099094932059419219U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16342730862261868847U;
            aOrbiterF = RotL64((aOrbiterF * 10988124108686164829U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16855346813127524624U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6570063128502306944U;
            aOrbiterB = RotL64((aOrbiterB * 4571570049463124831U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 44U) + aOrbiterI) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 21762U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneD[((aIndex + 16708U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16617U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18770U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 13U)) ^ (RotL64(aCross, 30U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 3248574644570178787U) + aPhaseGOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 4506961512959200024U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 8423739774540738590U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 22U)) + 6593975869641735337U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 16441716090557369103U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7936601450453207914U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13333752583560167065U;
            aOrbiterF = RotL64((aOrbiterF * 5389149472324384311U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8013703284795432973U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2349852779887439236U;
            aOrbiterB = RotL64((aOrbiterB * 2422888500648100783U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5318539364763284138U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11450957608502944376U;
            aOrbiterK = RotL64((aOrbiterK * 1957880366707810635U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9058992558327552687U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterI = RotL64((aOrbiterI * 12460364388358520799U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14734218428913777098U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16344357661370784442U;
            aOrbiterJ = RotL64((aOrbiterJ * 15049472842002138369U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 42U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + (((RotL64(aIngress, 44U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 38U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26737U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 32083U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28637U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24611U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 48U)) + 11480359716598965890U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 15431182525482873419U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 13U)) + 11360504974812776707U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 9292576416573382769U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 1549257414531028975U) + aPhaseGOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5347769463033129317U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17019199177478377234U;
            aOrbiterC = RotL64((aOrbiterC * 4336112198640602307U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16558106007323125094U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3976182233825939422U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4392162052317572289U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2889047161195954395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2241831345026962605U;
            aOrbiterJ = RotL64((aOrbiterJ * 5757458560979927857U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12850802412140579294U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13541744735436450160U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 906089290000537439U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2085863085516538212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2969034221711544086U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 3926U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 3990U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1783U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 3343U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 11998579547770778580U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 43U)) + 8409465187298704610U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 3470222286110333500U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 5704486785203069994U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 19U)) + 10334944660253279633U) + aPhaseHOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7626852700722567477U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14631310754943209743U;
            aOrbiterI = RotL64((aOrbiterI * 1958866541508493967U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 807160297237854120U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5624154783624196107U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2404066593958052159U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4971444394698940423U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6340057638461027062U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12027586111086798629U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9003019862787819481U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13632057463595873033U;
            aOrbiterA = RotL64((aOrbiterA * 12575202147280216765U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12766104026871797746U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4062118445824915939U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterB) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 9843U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9245U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9736U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10189U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 2330952702412094686U) + aPhaseHOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 7820188225935060799U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 35U)) + 9347644591709839145U) + aPhaseHOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 2288624878446846870U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 27U)) + 9358977729492824128U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1858511275052455039U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13715478509322292552U;
            aOrbiterG = RotL64((aOrbiterG * 15552121744869003235U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16413396625604260455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17714322215518432705U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1904184102419934333U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16188315436202861122U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5564445841368207813U;
            aOrbiterJ = RotL64((aOrbiterJ * 14125834616162835983U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13717068949900594673U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14143659432287313765U;
            aOrbiterH = RotL64((aOrbiterH * 17281441046722262917U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5729546141908425670U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4297827922736712074U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 4U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 36U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 6U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23568U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19730U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20346U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21709U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 22U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 1557680213571812384U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 5U)) + 7387349725778021121U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 28U)) + RotL64(aCarry, 5U)) + 15379264067601586976U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 3730195724576043708U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 57U)) + 9637070085323827066U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1170865717363676184U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2750833653175252030U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1937822982381882775U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15118992811225568305U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4974092922102988451U;
            aOrbiterB = RotL64((aOrbiterB * 10575977398702460975U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10625719096296719514U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 855167122475471865U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7441090331293158773U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11322911068958340262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14263701737208936392U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 678723206735649084U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10823239851733632227U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 38U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterD, 22U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26398U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28581U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28913U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30536U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 9471546960258473684U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 18050235435948942244U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 11U)) + 3005107102671544641U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 57U)) + 17898396434573801850U) + aPhaseHOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 15071602525497771648U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5780119462702672108U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13301326224151025687U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2868878978993219351U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18129323022260575961U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1199228670638790709U;
            aOrbiterK = RotL64((aOrbiterK * 1780426336211781025U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1839199978088021020U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4999517042246790165U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4585813675677234577U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8788607633376516299U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15143903839930468749U;
            aOrbiterJ = RotL64((aOrbiterJ * 12735914889325422675U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16674732686428431869U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15908873150953195581U;
            aOrbiterD = RotL64((aOrbiterD * 18049755517524334107U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 6U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 39U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
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
