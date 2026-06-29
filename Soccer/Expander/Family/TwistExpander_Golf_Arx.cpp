#include "TwistExpander_Golf_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Golf_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAA75EE75C5BCE4C3ULL + 0xC30F41DBDDA0884BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFCDB04827293B0A9ULL + 0xBF77A8A9F44A762EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEAB9B72F81B3F1A3ULL + 0xFBDC6A3BA5B31FE5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x913073CD0EC95B0FULL + 0x8EC49DDCE675FEBFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8D0ECCAEAD2B7757ULL + 0xFE6BC354789EEFC9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9D47E2B915B2527FULL + 0xF30F2762D3A98455ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEBD0A1D02B618DB7ULL + 0x8C47A156E4636F41ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC31758B3546E36BDULL + 0xF3E76695AA7B077CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x87E771E4F6166B75ULL + 0xFD31244DBF0391C1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC823BE1822BAB147ULL + 0xE57750992D41AAE2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEE0B9D90A80BC2B1ULL + 0x9CB24952D8C6EB2FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8D06D5B6382D56EDULL + 0xC781D628EB4BF68CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE67A364BCB6335BBULL + 0x9B850551176D88B6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9FFF345A44BCAD0DULL + 0x93004960D9A0CCBBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBA1172A3D109EF21ULL + 0xF97C2A88C05C383BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB79479F90FF90A69ULL + 0x90863CBBB0557C4BULL);
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
            aIngress = RotL64(mSource[((aIndex + 2438U)) & S_BLOCK1], 24U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2097U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4305U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 4803U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 36U)) + RotL64(aCarry, 13U)) + 3199575576585871314U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 39U)) + 2533378188975571824U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 21U)) + 6819782112558312658U) + aNonceWordH;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 12690060987724798497U) + aNonceWordC;
            aOrbiterD = (aWandererE + RotL64(aScatter, 43U)) + 7088375139715629606U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 19U)) + 17785618677423695666U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 27U)) + 1714999280296491277U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 17611338506932491624U) + aNonceWordG;
            aOrbiterH = (aWandererK + RotL64(aScatter, 4U)) + 6475727359297421201U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 2347744591204119530U) + aNonceWordF;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 41U)) + 2739317903351401068U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8663535261373274338U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8205245127823536479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13857005110466856439U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8916510616749754516U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3944805940148512932U;
            aOrbiterE = RotL64((aOrbiterE * 18082271583211389701U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14094751253118853302U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14094299829196076311U;
            aOrbiterD = RotL64((aOrbiterD * 6370012560657108493U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3940673811518673802U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3015106523254484839U;
            aOrbiterB = RotL64((aOrbiterB * 9655401190755573379U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15404103131982599922U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 1828655763233900875U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 13024358077740310049U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1236981890899916502U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18208975564570342697U;
            aOrbiterG = RotL64((aOrbiterG * 4577109989465876801U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17882273895471449661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16196010765612713713U;
            aOrbiterK = RotL64((aOrbiterK * 15624856645134182005U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14639250100311162559U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9139027997336903273U) ^ aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1853126389565574293U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16848571995585465845U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15901000078517800358U;
            aOrbiterA = RotL64((aOrbiterA * 11617866400577762383U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9405166641274108606U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6776079798531281127U;
            aOrbiterH = RotL64((aOrbiterH * 6914644957401512339U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15056085197286596847U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3199575576585871314U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15940936753708416817U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterH) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 20U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 42U) + aOrbiterF) + RotL64(aOrbiterB, 42U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9323U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10690U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8188U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7007U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 18U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererD + RotL64(aIngress, 43U)) + 8975885703279267062U;
            aOrbiterG = (aWandererH + RotL64(aCross, 24U)) + 8664844915562660637U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 53U)) + 12281774799736296726U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererG + RotL64(aScatter, 39U)) + 15347461352311329726U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 35U)) + 12967500561828907834U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 5002833859280402726U) + aNonceWordN;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 13U)) + 11908257536954668983U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 17017174811949227162U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 57U)) + 16851323125613931180U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 13469326957728686706U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 46U)) + 5228638551056105241U) + aNonceWordA;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11945166198089308564U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16268645041872996022U;
            aOrbiterA = RotL64((aOrbiterA * 5391448793718370911U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14781204627695095701U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5365325354838101092U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 563147416025715953U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14660867395395625851U;
            aOrbiterE = RotL64((aOrbiterE * 4769458126865307103U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3168989056355712105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16179131669773665579U;
            aOrbiterK = RotL64((aOrbiterK * 5641461617066671723U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4160220074225527179U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8597134686962559111U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 639572585431474015U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16811551552456811661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5827323970423386301U;
            aOrbiterG = RotL64((aOrbiterG * 9328247349730652021U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15583234353262170227U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2950816254621717748U;
            aOrbiterI = RotL64((aOrbiterI * 1102417597476170143U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4426165025104306337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11871220132164971152U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2366168050042802207U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3832424136113939717U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17673885217916768611U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10887063696370811871U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3479289844909914390U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9498461576098567546U;
            aOrbiterD = RotL64((aOrbiterD * 8734492074299676555U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10645314291190544864U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8975885703279267062U;
            aOrbiterF = RotL64((aOrbiterF * 16584086014947250551U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterG, 21U));
            aWandererB = aWandererB + (((RotL64(aCross, 22U) + aOrbiterE) + RotL64(aOrbiterG, 34U)) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererE = aWandererE + ((RotL64(aIngress, 50U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 28U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 13400U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15863U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14319U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 14248U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 28U) + RotL64(aPrevious, 41U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 11U)) + 12027839670755583592U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 36U)) + RotL64(aCarry, 57U)) + 15380130703509859843U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 4590907433867798074U;
            aOrbiterE = (aWandererC + RotL64(aCross, 41U)) + 1754574023602519724U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 9832756659564903767U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 13U)) + 5035088494491470403U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 14199170923323644638U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 29U)) + 8325619421264440438U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 39U)) + 969534320779067977U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + 270575869402913847U) + aNonceWordD;
            aOrbiterD = (aWandererF + RotL64(aScatter, 22U)) + 13344806516599578910U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15143147951139409101U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14425582489214169238U;
            aOrbiterF = RotL64((aOrbiterF * 16893787086337916355U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13951127523239064584U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14177925225918293579U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 13079514031864998485U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8258920744278218901U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7408161179397242453U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8581481606764773468U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10078416198417433133U;
            aOrbiterH = RotL64((aOrbiterH * 1102721083915858247U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18299772198826189580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18304668908084397946U;
            aOrbiterK = RotL64((aOrbiterK * 10589455451200578687U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 16729632621573817223U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13362300981585573239U;
            aOrbiterE = RotL64((aOrbiterE * 9824473895535518785U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8629682832849915380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6852852009091469641U;
            aOrbiterG = RotL64((aOrbiterG * 11912646687050011915U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7433098156961745198U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10931806208899417308U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14699197041038067483U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 629604718211675247U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1487372736719237118U;
            aOrbiterJ = RotL64((aOrbiterJ * 705192821277928909U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3567439893461603384U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11143068753134694333U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15529326960229305389U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14242098279913980463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12027839670755583592U;
            aOrbiterA = RotL64((aOrbiterA * 6630014752150544153U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterA, 10U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 43U));
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 54U) + RotL64(aOrbiterF, 36U)) + aOrbiterI) + aNonceWordG) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 19929U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 17301U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 16432U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 19529U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17750U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 6U)) + 9220392006207660113U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 53U)) + 11305018553489132882U) + aNonceWordM;
            aOrbiterA = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 5860373868073513684U) + aNonceWordE;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 51U)) + 12319586170883987589U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 14072333614354649021U;
            aOrbiterG = (aWandererE + RotL64(aCross, 21U)) + 9332158529453194608U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 35U)) + 3860569321145958686U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 8119005668901240093U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 37U)) + 13918259792880333239U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 41U)) + 6938856216758228704U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 60U)) + 3960905839118710604U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6043879193734253929U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15691425268831319195U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 7189195135654636271U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14912209933584715274U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16180183395910618923U;
            aOrbiterH = RotL64((aOrbiterH * 3942858974766467849U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4966642362507707776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6962226782462822861U;
            aOrbiterB = RotL64((aOrbiterB * 3647802407741095419U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12409120845092026295U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2302946450253872465U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7099576330777297911U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16118304388937163838U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15968419034359049422U;
            aOrbiterI = RotL64((aOrbiterI * 11736207775827080165U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17098982091525008231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10298979200690822062U;
            aOrbiterK = RotL64((aOrbiterK * 12620028874653521945U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 552826643694256437U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11786560990790695378U;
            aOrbiterJ = RotL64((aOrbiterJ * 11190309640069208311U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13730399230389329793U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17614226859252305432U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2640019643570222977U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1062738267846296283U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13959480457644980835U;
            aOrbiterC = RotL64((aOrbiterC * 1194145909157002977U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4635071137794189167U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13374502212707796180U;
            aOrbiterF = RotL64((aOrbiterF * 129680788767298945U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11479902881487238033U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9220392006207660113U;
            aOrbiterD = RotL64((aOrbiterD * 1437457810224888809U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordN);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 40U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 50U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 26U) + aOrbiterD) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 6U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 23513U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((aIndex + 26462U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25054U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23964U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24936U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25424U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererJ + RotL64(aScatter, 23U)) + 479672811032092393U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 19U)) + 18061121631394564425U;
            aOrbiterG = (aWandererE + RotL64(aCross, 39U)) + 14237400452740566065U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 13U)) + 6723123812257706134U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 4247997188026499248U) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aCross, 37U)) + 1939107415066134869U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 47U)) + 3912640123546395979U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 43U)) + 8295478436553964298U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 20U)) + RotL64(aCarry, 53U)) + 3218960600711526885U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 29U)) + 5874096203353388890U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 57U)) + 10294536533673023358U) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11268561953904130747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16693201256788898423U;
            aOrbiterG = RotL64((aOrbiterG * 16291987237693567209U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7550969634681894654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9501647424602245869U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11265865222096866605U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8881869255994319423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16770136406906800016U;
            aOrbiterD = RotL64((aOrbiterD * 1782039587385512923U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16185384746435761363U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13841034186650721627U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 12000155593277035447U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15229062695864608309U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3576122704615303733U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2433987493885779279U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13898167174453181224U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12878032061609524049U;
            aOrbiterF = RotL64((aOrbiterF * 18104665741338251495U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12719156051299028649U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8640980843376950769U;
            aOrbiterC = RotL64((aOrbiterC * 10242616778390983333U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12133332160916004365U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8743563985229104484U;
            aOrbiterI = RotL64((aOrbiterI * 4575129690615054691U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7362223873479167793U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4230720394788635807U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3658720603716856293U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5095842824285329272U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7483469517256234638U;
            aOrbiterK = RotL64((aOrbiterK * 9782114499878763883U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17426017004856399653U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 479672811032092393U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14921028515589317919U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 40U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aCross, 10U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + aNonceWordD);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 50U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 36U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28492U)) & S_BLOCK1], 35U) ^ RotL64(pSnow[((aIndex + 29630U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 28194U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28626U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29621U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28262U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 2101601659597850213U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 27U)) + 2759794072560720121U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 50U)) + 9443562552411269339U) + aNonceWordO;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 10801360546699857975U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 47U)) + 8020716394829332019U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 3U)) + 1021894212367773801U) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aScatter, 54U)) + 13346855534622490176U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 16359309548462953836U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 12642446944680783519U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 8197424982767553380U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 11U)) + 14346334610901859094U) + aNonceWordD;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14171304260534233539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 334531601308283605U;
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10707856298471572695U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18364775750091914766U;
            aOrbiterJ = RotL64((aOrbiterJ * 15735143943129143265U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8531394793118363836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15352876929406908882U;
            aOrbiterB = RotL64((aOrbiterB * 475199047053777179U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 567682016232278157U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2068146551757663119U;
            aOrbiterF = RotL64((aOrbiterF * 1557877740957797555U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7776122587613256525U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16430938890724272256U;
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11912000645055436094U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16800749242578741498U;
            aOrbiterA = RotL64((aOrbiterA * 17804584625034241737U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5909199180260499150U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5751089915336865588U;
            aOrbiterI = RotL64((aOrbiterI * 15376689503142397927U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3478216857728853008U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18007567146937338241U;
            aOrbiterE = RotL64((aOrbiterE * 6620498877303917855U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17454259424163653490U) + aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6276120962018305311U;
            aOrbiterH = RotL64((aOrbiterH * 7560618224285018801U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3839336239901666431U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6230149015045237670U;
            aOrbiterC = RotL64((aOrbiterC * 1838983748994340883U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17552095486612766544U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2101601659597850213U;
            aOrbiterK = RotL64((aOrbiterK * 2915330118061857271U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 42U)) + aOrbiterD) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterH, 44U));
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_Golf_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF6E41208C7627129ULL + 0xDE2EE1C49009E469ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x819F98FFDCD8BAD3ULL + 0x939DC7FC7D5F373EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDE439F6EE65A81FBULL + 0xBFD768E5DB3E00C5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFFF210D40C2186A3ULL + 0x9DA22CCE5C3700AFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9D206D835812E277ULL + 0xB6E7DAA02E47B0DFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAA12EC2B3462F72DULL + 0xF38F4B9038AD5BE0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCBFCD2068EE4AC2BULL + 0x9C7FEB0DE0E39F7EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAFCBC79F19BF529DULL + 0xC80A2D31DE068B09ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA659DEAF9E2CC9ABULL + 0xD2473A13E0716159ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB695FC46D46FAF21ULL + 0xF562801E55B63BFBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9B5060BBD35CB111ULL + 0xDEE00FF4C2E99FF8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE3281A105FCF98B3ULL + 0x9691482D216288D6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x90BA834AF1BD7CDDULL + 0xF59EA7BBF919BF13ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x921504B37CDF7AABULL + 0x88F8E777038F75ABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA327B6FB79079E35ULL + 0xDF4C10F9940C2342ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x935B8365762CA651ULL + 0x96FFCB36460B7136ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 7898U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 982U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4463U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 6095U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 51U)) + 15036852811491820366U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 305637140752898475U;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 60U)) + 11948631574496129610U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 35U)) + 5321623592482991426U;
            aOrbiterD = (aWandererG + RotL64(aCross, 3U)) + 4075270159062690728U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 15111580500356908928U) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 30U)) + 7244150695504160363U) + aNonceWordI;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 13U)) + 5131563519577488862U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 5881954992088651371U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12780935808751507998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12599159643925470226U;
            aOrbiterA = RotL64((aOrbiterA * 17690046932587062701U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9466589929741834066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6093158735705189789U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17461243886150519249U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15456408913739900718U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 16093292401746174671U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11260643903290392780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7870342756041882616U;
            aOrbiterE = RotL64((aOrbiterE * 2431528656086173419U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 134484990005888936U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10626896209992890407U;
            aOrbiterB = RotL64((aOrbiterB * 12034131076645285597U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14031164129515132292U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1771835705730244212U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 186981668443596623U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16395472745067254664U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 1455944290845294254U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6757824754363319079U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17866422769075350837U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10226884082632410805U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 206035536985843815U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14474587247775371703U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8501763445324525303U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5298694643596784007U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 36U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 51U)) + aOrbiterD) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererG = aWandererG + (((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterF, 28U)) + RotL64(aCarry, 47U)) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 47U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8821U)) & S_BLOCK1], 46U) ^ RotL64(aFireLaneB[((aIndex + 9747U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 9093U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10867U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12057U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 22U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 39U)) + 9471546960258473684U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 21U)) + 18050235435948942244U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + 3005107102671544641U) + aNonceWordO;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 47U)) + 17898396434573801850U) + aNonceWordN;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 43U)) + 15071602525497771648U) + aOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 5780119462702672108U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 11U)) + 13301326224151025687U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 18129323022260575961U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 1199228670638790709U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1839199978088021020U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 4999517042246790165U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 4585813675677234577U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16674732686428431869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15908873150953195581U;
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11204775359756474667U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2525984309543939465U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3988529812023791571U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4566345170476825512U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 14876612901557406267U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 9047956948845135339U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14926290877038883931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12710203178186614846U;
            aOrbiterI = RotL64((aOrbiterI * 14841163494801662515U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7315094513967387996U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11050116830482816766U;
            aOrbiterB = RotL64((aOrbiterB * 3702999495721152019U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4505368486032503953U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17905748055257551092U;
            aOrbiterD = RotL64((aOrbiterD * 14775870175093453197U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5728886950801376350U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 17998141690182325170U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 16008599930125391379U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 44U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterI, 14U)) + aOrbiterE) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 34U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24182U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 17184U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17707U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21245U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21883U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 18731U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 23U)) + 8402620908307642697U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 58U)) + 11347672014525086047U) + aNonceWordE;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 43U)) + 2816462912503401876U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 6940159795470696093U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 37U)) + 9134692490095883851U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 4999455497008026526U) + aNonceWordH;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 6U)) + 5992451460350651332U) + aNonceWordK;
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 3417087346651371924U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + 3612773820086198270U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 463398077083428570U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11249391303705089012U;
            aOrbiterH = RotL64((aOrbiterH * 7106735772303292983U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 17027535139825739501U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 568131384979596481U;
            aOrbiterC = RotL64((aOrbiterC * 5683451044852895957U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4793712537158004047U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10415170179135963622U;
            aOrbiterK = RotL64((aOrbiterK * 13729564030210361415U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2391473979460065630U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4240058362680064261U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12375884373396400889U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9963957011090031698U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3325305624067445525U;
            aOrbiterJ = RotL64((aOrbiterJ * 3128542681461806309U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2094945647665114693U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10703615640774042674U;
            aOrbiterG = RotL64((aOrbiterG * 12641986098450423751U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3768738815518590289U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15021301790376706827U;
            aOrbiterI = RotL64((aOrbiterI * 14445850924223550339U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10571246886181608316U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5130325144599151793U;
            aOrbiterB = RotL64((aOrbiterB * 3185251943547657467U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8617523421720966373U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16574597770835250074U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 1759209403428937799U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 12U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterK, 52U)) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterG, 56U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31305U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 26765U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30793U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28291U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30786U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31175U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 13U)) + 13924571355038625040U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 42U)) + 16328300979357156658U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 57U)) + 3947771961206012461U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 15428284250569311285U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 35U)) + 5777369485254032486U) + aNonceWordJ;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 16813320300717644673U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 29U)) + 16689933050200758251U;
            aOrbiterD = (aWandererF + RotL64(aCross, 18U)) + 1856422419049390708U;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 18214498743831925517U) + aOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18278550878494094923U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 797712062039591797U;
            aOrbiterB = RotL64((aOrbiterB * 7212998747080137625U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15854849439012341347U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 996882939768167773U;
            aOrbiterA = RotL64((aOrbiterA * 14936703950807908575U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3005829974130671692U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8793495343509953906U;
            aOrbiterD = RotL64((aOrbiterD * 14065479348374612031U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7710453029930631112U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 9511995836117707047U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 7250766204781428201U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 670902975693341744U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9045820304668279777U;
            aOrbiterI = RotL64((aOrbiterI * 18373074917532639027U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12417212387607119470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12816983560669985622U;
            aOrbiterE = RotL64((aOrbiterE * 8406003970221889847U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17245432086377688540U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6806521945548502014U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11335859481858640857U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 8947500746292365294U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4468060468522895852U) ^ aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7022481284816599797U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9892975931958803992U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3042599331526937836U;
            aOrbiterK = RotL64((aOrbiterK * 3308512896171443645U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 18U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 57U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 50U)) + aOrbiterJ) + aNonceWordA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aCross, 26U) + aOrbiterA) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Golf_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF4E656440A6D7457ULL + 0x9DF6AF40F3940FB9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9A52C3386D600183ULL + 0x9398073D72A66C98ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9384AEFCDA5EC1E7ULL + 0xFCBFB5A3858D1638ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB6C5655F722C74C9ULL + 0xCCAA642E93BB6D19ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x91264B22F6869C75ULL + 0xCDAF76771EBCD835ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x865001AE57DBE201ULL + 0xD7C595A807A61E21ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF67B597E683B6FB5ULL + 0xF8D060E39D36A06CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF9853888EFEA015ULL + 0xBE24CF417E185514ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD6728A46B813370BULL + 0x99EA3AB4744584F4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA555797C36336F87ULL + 0xF583D03168278F2DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x95A3A0288D6310E3ULL + 0xCA0624227D6E42CAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8AD03B020853226BULL + 0x91CE1ACBA9797819ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x94B354A2333D4375ULL + 0x9E1D1AF296CB44E4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA5F79626421749EFULL + 0xF1906533D474667EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCCB40C713AA88051ULL + 0xAD8D70E474150A73ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE1CF27FF23BEF1D3ULL + 0x9BECE2182CC4E625ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneD
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7151U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 7429U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4445U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4177U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7979U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 4U)) + 12131317914288566437U) + aNonceWordB;
            aOrbiterH = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 5672805657999385496U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aScatter, 37U)) + 3581710244233124197U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 15251296040538489436U) + aNonceWordE;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 11295008604679904153U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 2230897493419504490U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7109600123297458999U;
            aOrbiterB = RotL64((aOrbiterB * 8267799351136506307U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13119156643107683803U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14755160867807355250U;
            aOrbiterH = RotL64((aOrbiterH * 10007087518844899239U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16829363373287496832U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16981122946707720883U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 5394974422201576627U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8806000776958603317U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16810923047720876014U;
            aOrbiterE = RotL64((aOrbiterE * 17872735050219539145U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8129657889554436328U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8653100378491974463U;
            aOrbiterA = RotL64((aOrbiterA * 11395283153912468661U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterB, 56U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13237U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((aIndex + 12649U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8594U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12851U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12202U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14164U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 18302975933754610273U) + aNonceWordO;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 5U)) + 16736972646771456082U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 23U)) + 17389406266488137442U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 5252511566486165539U) + aNonceWordL;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 50U)) + RotL64(aCarry, 11U)) + 5730715427422747640U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6412695646456045825U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9539701605708994494U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 6511935168278632407U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18355107116412945722U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11735742491750132942U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 18129835093627763685U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12363819388562658842U) + aNonceWordE;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5861430292304371543U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12989055611235382695U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15027487084595017708U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7012850020745791926U;
            aOrbiterC = RotL64((aOrbiterC * 15952928839355613939U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 11904871669287886120U) + aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11199760114477343208U;
            aOrbiterA = RotL64((aOrbiterA * 7156374911847525867U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 36U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 14U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24013U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 20564U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21961U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23832U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23733U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22679U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 8988572360732005217U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 17889613225105985335U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + 15563478320513948626U) + aNonceWordB;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 3441351228410524816U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 34U)) + 4425592689451435346U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 12733160231627305928U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3574152157304607854U;
            aOrbiterG = RotL64((aOrbiterG * 3488682351509384035U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15167631896729808783U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 15822667973915417055U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 5155661648455308057U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17181685481076577637U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9979204751408873468U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 8244434774754786565U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1334240485667164762U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9190066751460137016U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14585141844653660363U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15465215829109246336U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2305208282453624419U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10257861974108363283U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterK, 4U)) + aOrbiterB) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32502U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 30793U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25502U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27927U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25848U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26169U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 28161U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 6342299552323486695U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 5U)) + 12692748514781367538U) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8202639945493229155U;
            aOrbiterE = ((((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 4439975701793231639U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aCross, 50U)) + 16774235182859553759U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8764155413335405667U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 7167848811974967685U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1052856924757654735U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16768278912125334220U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9090838954826296201U;
            aOrbiterB = RotL64((aOrbiterB * 5459329624017272077U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 7644075729758006298U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17326182797908071215U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2408330168749256075U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16158809721888137555U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 8029938783858263694U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8716553521415553404U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7012599977009208840U;
            aOrbiterD = RotL64((aOrbiterD * 8775355876188948851U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 42U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Golf_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF954BB81D5D9A393ULL + 0x90BD1DF1245B4063ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD742EE6396DB7263ULL + 0xC64463888955AFA5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x808624A060F40ACBULL + 0xD6C2CC674DF1C08AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA838171748674123ULL + 0xDC1E8C9D3DC51C59ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF0AA8E002D525CBDULL + 0xFEF89C699898A790ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA7430D19B52A7FE1ULL + 0xADE1A26F23BD3810ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDBE7875112DF3E11ULL + 0xC48434CB5016A8B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x91CFC2310986DBDFULL + 0xDEB9442CE32873B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA7A6E52807BC14F3ULL + 0xACC9A9259280215DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA8B509F4255F0457ULL + 0xA9F6B27F478C48A7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x99797BE4707E3EEFULL + 0x904721AB910BBF2AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD84D97376E63323DULL + 0xEC7B9ADE7567BCC6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCD580B38094EADC9ULL + 0x8238EF77958D0C36ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE288EA7C4802DDBFULL + 0xC7DD822A9A8EB219ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC038AF5E0D20C4C9ULL + 0x92517C10B19732ACULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAF6988B6AA0FB425ULL + 0xA1C9D29547CB0BDFULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneC, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneB, aFireLaneA, aWorkLaneC, aOperationLaneD, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1982U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 6716U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 1012U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5686U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7192U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4188U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 14U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (aWandererF + RotL64(aIngress, 13U)) + 9888431329297626900U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 54U)) + RotL64(aCarry, 29U)) + 2937735167534624403U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 17626022970343789617U) + aNonceWordI;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 5665660859333693743U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 35U)) + 1060537034632076669U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + 743777763907175800U) + aNonceWordH;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + 5744905970181808845U) + aNonceWordG;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3545351394494002180U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4877547088414106007U;
            aOrbiterD = RotL64((aOrbiterD * 5416792889338547109U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11669378338379598445U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 2961072441706158212U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2677988507090705371U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13984945589234919765U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1433097875470903205U;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 716415411025451152U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8542286150858297810U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9139015340823332449U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12932391786479661299U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14005503313299177013U;
            aOrbiterB = RotL64((aOrbiterB * 802663466907819743U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9382792812676318046U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5138554251079724724U;
            aOrbiterA = RotL64((aOrbiterA * 6386016499265056247U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8522380066269546172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterJ = RotL64((aOrbiterJ * 17042837108792016849U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 41U)) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterF, 29U)) + aOrbiterA) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15273U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 8988U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12748U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11200U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11624U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8551U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 29U)) + 8767379393098711499U) + aNonceWordB;
            aOrbiterK = ((((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 7168159491580816433U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 36U)) + 9879279829061883406U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererF + RotL64(aScatter, 51U)) + 10537167136053399303U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 19U)) + 2839070018069188936U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 13844278063968429732U) + aNonceWordI;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 11278946626186474646U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11798425216660557799U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 7618446090703335192U) ^ aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7168757300685156779U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 695423597006983660U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14344728202803488813U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 5168825904902285909U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11656100506575697086U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10384358779985773937U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 247494692039140973U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17585001605131977341U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9964478171465522911U;
            aOrbiterK = RotL64((aOrbiterK * 13484044854790175315U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2710943171829692624U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12814092033910687774U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1743186323268668740U;
            aOrbiterG = RotL64((aOrbiterG * 11150822630624332557U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10750472346626754704U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15925901217078035356U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9276504171291801637U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterA, 50U)) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 58U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18933U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 20188U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22706U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21398U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18477U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23211U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 21U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 12311607308490066301U) + aNonceWordI;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 20U)) + 13100864684740679846U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 29U)) + 13697304189274329704U) + aNonceWordP;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 57U)) + 9047976902871216732U) + aNonceWordF;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 2147897579538537888U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 2072444829390996142U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 3U)) + 2129307836981020908U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10663145333751112064U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15019844390503785459U;
            aOrbiterI = RotL64((aOrbiterI * 7442321463110790449U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5460865577557928142U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15806522559993224197U;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6361113778657833389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8306013884615042570U;
            aOrbiterK = RotL64((aOrbiterK * 8234258702656728667U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4038420580499706912U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11908091484457158973U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 3964111175645156719U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11133912466611921250U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 2469227904206936928U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 2704438771198001599U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13234017916788297295U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9061117693840451988U;
            aOrbiterG = RotL64((aOrbiterG * 3637440416741459419U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12013423690843812324U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14371779015144617412U;
            aOrbiterE = RotL64((aOrbiterE * 3359568073302062667U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 18U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterC) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25812U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 25298U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30694U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32412U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31772U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 31573U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 9080426856729228705U) + aNonceWordB;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 7851218321653539276U) + aNonceWordJ;
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + 7023344692919298036U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 19U)) + 9772846154227440734U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 12008298632429608431U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 56U)) + 12201090455849562875U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 9498721803411445471U) + aNonceWordF;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 351203764023093632U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4966360430644539250U;
            aOrbiterK = RotL64((aOrbiterK * 10138518378274592739U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9194167899071345693U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4922477697284269116U;
            aOrbiterA = RotL64((aOrbiterA * 8444814161720407881U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15742625291642356429U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7528703106518431730U;
            aOrbiterC = RotL64((aOrbiterC * 11530049278751507567U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 15279053574704935317U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2425839793660355555U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11486964816849830667U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13209849392400008898U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9041500097716231309U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 340661035700748739U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7885423750878814599U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1992993999902904603U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 1478629826632201617U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6120758615019314102U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8529621625846992066U;
            aOrbiterF = RotL64((aOrbiterF * 8485991471612862467U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterI) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterK, 43U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCC090F5BF1000691ULL + 0xF19262122DA418E8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF59E5EE6409680A5ULL + 0xF01A99DCEB1557E2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEDD0415C14C778F5ULL + 0xF731BC68119F4470ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x94CB6A806536AB97ULL + 0xDECCE4D740B39155ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x829555FCE9A8B867ULL + 0x99593084A5CB8969ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9E4E8FDDBEB5D3F5ULL + 0xDBDC2F93347C017DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x953C1E1087606A03ULL + 0xD905CF9B8731BB04ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9A6D598CFF3E598BULL + 0xEE868FD50C3B288FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA295BD7FB0724CC5ULL + 0x9F2E7576BFC82D9EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA65FB189838525F9ULL + 0xA73A73603E7BEB58ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8F7445FBC4AB52A9ULL + 0xED25383019992A19ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8DC89B52C29D1E23ULL + 0xC548311BB67B20E1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCB697AE2C1DE0E7BULL + 0xB0161F69F46CB986ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAEC49F25757E6CA7ULL + 0xCFA51427AB1DD301ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC23A5AA77BED707FULL + 0xF436F7A7D7986C75ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC9C0A821F1DE328FULL + 0xB2F0E0A4D38C7522ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aFireLaneD, aOperationLaneB, aExpandLaneB, aFireLaneC, aOperationLaneD, aExpandLaneC, aFireLaneA, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 64U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 5972U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 84U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4498U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2808U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5236U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 26U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 785861751704720606U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 13U)) + 15968088718435606299U) + aNonceWordH;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + 1393976526590347151U) + aNonceWordB;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 17240750947292745884U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 4U)) + 4921576136163183137U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 3334047873553153032U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 15086509978458408698U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 892391205397581998U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2965686403183767521U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 709160942482770225U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14632215393655706170U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15740589515342377322U;
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11131164813943086445U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6988080581278900960U;
            aOrbiterJ = RotL64((aOrbiterJ * 6412189142344044255U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16021254613117657178U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6183615599897921154U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12533992547026652747U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3104325358982904219U;
            aOrbiterB = RotL64((aOrbiterB * 14977348108778147265U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3878525937957474644U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2120435259884368445U;
            aOrbiterF = RotL64((aOrbiterF * 15964718652193073177U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14928658302694194856U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9121310461310309348U;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 23U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 29U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aNonceWordE) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 22U)) + aOrbiterF) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12649U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 14202U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12777U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9393U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9220U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10254U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 4U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + 14499676118633326000U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 44U)) + RotL64(aCarry, 51U)) + 17191273593018552288U) + aNonceWordN;
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 4085176294948097737U;
            aOrbiterF = (aWandererA + RotL64(aCross, 51U)) + 11112671474158908186U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 37U)) + 8745787969012266485U) + aNonceWordA;
            aOrbiterI = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 18074049663777707948U) + aNonceWordL;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 2543758649719164688U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4659584749412700523U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 974639159259871273U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 17918719351847605523U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9211220687971081987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8567024626862182714U;
            aOrbiterG = RotL64((aOrbiterG * 7755874089832496393U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5803002132294840900U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11968489432878148467U;
            aOrbiterF = RotL64((aOrbiterF * 4501441062617123165U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9470807228394903442U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1692347973120388469U;
            aOrbiterC = RotL64((aOrbiterC * 17433393164156231575U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16510815732690193145U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 755159406833096510U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14091736464659561165U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1518824876475937620U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 701225390867330446U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8425976693733003889U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7182176375442410367U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 8860605703761731859U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 44U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + RotL64(aWandererA, 46U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23278U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 24441U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24031U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21473U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24576U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19931U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 4980738603982643969U;
            aOrbiterB = (aWandererG + RotL64(aCross, 35U)) + 17660278413018470020U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + 17598114429859543466U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aIngress, 24U)) + RotL64(aCarry, 3U)) + 10993929335279994739U) + aNonceWordN;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 53U)) + 17967203122976322481U) + aNonceWordJ;
            aOrbiterA = ((((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 1872290205549034384U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererI + RotL64(aIngress, 13U)) + 16607778671782810797U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4895226930754394376U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14960359005982301383U;
            aOrbiterH = RotL64((aOrbiterH * 8546231310054433721U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9921642352377700630U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 893281964367208693U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 2345509157333444217U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8232519988397858732U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4433022122758913407U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 834240393225479419U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12689609831247168353U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 404535388957472176U;
            aOrbiterF = RotL64((aOrbiterF * 14534020545479806593U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3349108201964013155U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4386449511297371730U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14314587717949070586U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10923886625271054985U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7838969002623486809U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17634909585329833520U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2021301459918350372U;
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 22U)) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 41U)) + aOrbiterA) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 14U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aNonceWordF) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27803U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 30646U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29365U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31503U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31811U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 26483U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + 380024772508948442U) + aNonceWordK;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 57U)) + 7649029098162567210U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 5329304598870421851U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + 12306118665045151326U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 43U)) + 960751560457324256U) + aNonceWordI;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 3244070254386191876U) + aNonceWordO;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 26U)) + RotL64(aCarry, 5U)) + 15733408571609521746U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17623448932647018544U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8787759896149035829U;
            aOrbiterJ = RotL64((aOrbiterJ * 7092515868845497573U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 14741681792348288162U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8801731213568307302U;
            aOrbiterD = RotL64((aOrbiterD * 12127126999570616489U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9872248187499779222U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15407371518644528235U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1245102406469471673U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4242060317152943062U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9942784962409917541U;
            aOrbiterC = RotL64((aOrbiterC * 888649755587764533U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7296348796484458631U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15061417216070157797U;
            aOrbiterA = RotL64((aOrbiterA * 10349554676953256231U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3233185810644297433U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9241229457641024287U;
            aOrbiterI = RotL64((aOrbiterI * 2728237515724597517U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8464051359381554575U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3307872165699029375U;
            aOrbiterK = RotL64((aOrbiterK * 4859663401033023433U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterC, 35U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 14U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_Golf_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE509EDC8A6B61FCBULL + 0x91BFC71F4C35248FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF35260AA6B927BB7ULL + 0xC73946191A47F163ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEA324A22A6B92311ULL + 0xBADC4F291B668CABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA3B13C42532408ABULL + 0xA9D4E8BBB2C43286ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEDFC6FFA82A98985ULL + 0xA1F098FA7EAFDD24ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA36678C98C7FCD79ULL + 0xF7AB52B65C213D50ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE19B46510249E09DULL + 0x83229C37D915246BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFC42E33A0F2DA38DULL + 0xDED95555868528C6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEF19CAD293B9493BULL + 0xA8A684C2549F5584ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA2758F8EFD08E45FULL + 0xD36DEAE565DBF601ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE70D470C33A082A5ULL + 0x8C901ECB839C33E9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC794AA3635ADD9D7ULL + 0x8D5B5ACC692F9A5AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC4A467A59014CB17ULL + 0xC1FA78AA1083CCA6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF85D4335B20CAED9ULL + 0xBE879A8396149BA5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB4D0D04A5A3FD36DULL + 0xFB5113D692CD57D2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBAE77936C338C387ULL + 0xAAB3A9B9C847AA44ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aOperationLaneA, aWorkLaneB, aWorkLaneC, aOperationLaneB, aFireLaneD, aWorkLaneD, aOperationLaneC, aFireLaneB, aWorkLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5071U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 3262U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1730U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5810U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6378U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4139U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 50U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 13U)) + 8375305456876489425U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 3U)) + 16193562952772453047U;
            aOrbiterB = (aWandererD + RotL64(aCross, 58U)) + 18088652458594816223U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 767344788620249944U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 7705194930396368752U) + aNonceWordD;
            aOrbiterC = (aWandererB + RotL64(aScatter, 41U)) + 3829736891311272834U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 19U)) + 9881681671347640061U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 29U)) + 1721196560190164264U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 11U)) + 3002652618388454213U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 48U)) + RotL64(aCarry, 29U)) + 9811621464004005202U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 27U)) + 5652598941069986530U) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6250499348327316328U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16025054277615264530U;
            aOrbiterB = RotL64((aOrbiterB * 16446892258704281903U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13800298546867243172U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12256104592865905782U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16983140179497142713U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17817225416918329229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17738671327352776217U;
            aOrbiterD = RotL64((aOrbiterD * 393488251327705063U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6816031224188400541U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16989563985059237014U;
            aOrbiterG = RotL64((aOrbiterG * 8677884225771717797U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16891524847268207549U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1833508573940405571U;
            aOrbiterI = RotL64((aOrbiterI * 9709196587703979539U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12729999421507068973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6839758643521968957U;
            aOrbiterA = RotL64((aOrbiterA * 16350557395881283975U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8524167125469267428U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14741523560290472617U;
            aOrbiterJ = RotL64((aOrbiterJ * 4367850822282205897U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10983798459868424892U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5649250846622078964U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7149612714806023987U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8587302028325090061U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17457129226030333666U;
            aOrbiterH = RotL64((aOrbiterH * 18107356450566915215U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15600113588474915690U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6595247491374683783U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 1432432381540098765U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13246325856585534283U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8375305456876489425U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8331406038795786099U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 52U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 56U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aNonceWordC) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 15168U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 13070U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11552U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11921U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10660U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 15528U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererK + RotL64(aIngress, 35U)) + 4739486756133131180U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 19U)) + 16089707555501328184U) + aNonceWordO;
            aOrbiterK = (aWandererG + RotL64(aCross, 10U)) + 15310047330238536453U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 7901411596386834955U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aPrevious, 53U)) + 4357555491060982163U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 47U)) + 15667085602825720102U) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 27U)) + 8520635334382269253U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 1772509779231068315U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 44U)) + RotL64(aCarry, 57U)) + 15336170957886025677U;
            aOrbiterE = (aWandererF + RotL64(aCross, 29U)) + 8628770833489469980U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 5U)) + 15469234024247246228U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10796430900884288328U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10660110397012853289U;
            aOrbiterK = RotL64((aOrbiterK * 9140007610912037461U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11202284258711214794U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17509491802893182994U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9329107599972703671U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16212572740740103554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2190030203761579226U;
            aOrbiterG = RotL64((aOrbiterG * 3101886685668871045U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12014337082293041909U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3733531010807001506U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 5797362244066062299U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7100994963061975529U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17837541162838600258U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8745987361678166553U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3311518938023146951U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7709505172646831553U;
            aOrbiterD = RotL64((aOrbiterD * 7121143171245765213U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4979968094554018443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16822214821463034107U;
            aOrbiterC = RotL64((aOrbiterC * 8618262120451291765U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8376124175020587079U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11084586282092424876U;
            aOrbiterJ = RotL64((aOrbiterJ * 5835632742522563537U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7816368455027681621U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10893292019060642422U;
            aOrbiterH = RotL64((aOrbiterH * 3995821210667317677U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13602875505184178486U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5425735673005681983U;
            aOrbiterA = RotL64((aOrbiterA * 12667085597129312079U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5995385043278810987U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4739486756133131180U;
            aOrbiterB = RotL64((aOrbiterB * 15709273328685013399U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 28U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererC = aWandererC + ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22329U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 16966U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19156U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23950U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24322U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 23992U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 3U)) + 4204560462077827182U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 54U)) + 6572370199668594039U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 23U)) + 15958999876732622825U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 13U)) + 9969349486879280377U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 15450238998293956181U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 5U)) + 9128619863683138259U) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 51U)) + 5691270563628979565U) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aIngress, 43U)) + 5901029710568933106U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 57U)) + 10442738941988588834U) + aNonceWordP;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 3508116020325721993U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 13221917083569767259U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11627915460377128176U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 17858261365514253433U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7535577636975884641U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4294837988806295989U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11242915481585070249U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17540688242763829319U), 41U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 13030663829236027109U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7451948220723185149U;
            aOrbiterK = RotL64((aOrbiterK * 5191778587712222029U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5575508866505031037U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5161096033789876794U;
            aOrbiterF = RotL64((aOrbiterF * 16843827915802461797U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3980482740649505122U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11188906150207270241U;
            aOrbiterG = RotL64((aOrbiterG * 408550837615188413U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4435504916461645189U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9970252853543702833U;
            aOrbiterA = RotL64((aOrbiterA * 5829143716916091997U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3766347619186305854U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11004616087340082895U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14469267845747063735U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17600791542296175812U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2556224430252009744U;
            aOrbiterI = RotL64((aOrbiterI * 14469426539907112137U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8575243768637573595U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9439245636611632007U;
            aOrbiterJ = RotL64((aOrbiterJ * 7519813655810877223U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8376104683205641052U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16877378648551624650U;
            aOrbiterE = RotL64((aOrbiterE * 13806644088125335467U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8060622208866138617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4204560462077827182U;
            aOrbiterB = RotL64((aOrbiterB * 8407034104111382011U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 42U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 46U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterB, 3U)) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 14U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 48U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26050U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 25947U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 32721U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31796U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29191U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 26410U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 43U)) + 6381335981879993247U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 60U)) + 15595429101600023172U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 5449234297249826461U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + 11213734849329731168U) + aNonceWordP;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 23U)) + 16438473952464514248U) + aNonceWordM;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 11U)) + 7357872882115186976U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 46U)) + 394402075160738643U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 11112941985410283532U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 57U)) + 14955125011182736212U;
            aOrbiterH = (aWandererE + RotL64(aCross, 53U)) + 14770727009821304070U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 11286366598129204910U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7358400908565425780U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15635109923749114761U;
            aOrbiterC = RotL64((aOrbiterC * 12415152149408700329U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13826842523738623579U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1072811298828325231U;
            aOrbiterJ = RotL64((aOrbiterJ * 9662800288646215083U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4017334196009350776U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8812213572751410831U;
            aOrbiterF = RotL64((aOrbiterF * 12744171921566782795U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6723457786170634403U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9785583533999417673U;
            aOrbiterG = RotL64((aOrbiterG * 7776915427605471097U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10265132640322153964U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 8435670887514808087U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2706263045620662131U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4303823386961718326U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4214384238167491037U;
            aOrbiterE = RotL64((aOrbiterE * 8490707334221154005U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8740835037840799136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5988815405391206280U;
            aOrbiterH = RotL64((aOrbiterH * 17838555472135715929U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15539461383052981747U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3743772525784217714U;
            aOrbiterB = RotL64((aOrbiterB * 6352086797545969187U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16283379107488103386U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2677085736169305444U;
            aOrbiterD = RotL64((aOrbiterD * 5034373635279045467U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16961352880910247821U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7475807604144212417U;
            aOrbiterA = RotL64((aOrbiterA * 5016987646810330727U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10187131329357526073U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6381335981879993247U;
            aOrbiterK = RotL64((aOrbiterK * 15277168748093112841U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 48U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aNonceWordE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 46U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 36U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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

void TwistExpander_Golf_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x90CC54DA1EA5713BULL + 0xF993198F2A12F7CAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCD3B2B725E51AA9BULL + 0xA30C3CA6C96337ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA475FE23D05B15D7ULL + 0xE64F3AA6DC941999ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9845177197A27C2BULL + 0x916039FDAD74BC16ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCEC5DA067761CF87ULL + 0xC124E9FB40833BC7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD7896975CDB9649FULL + 0x9E3A16FDB2141FC4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8BFFC058AEDA7779ULL + 0xF124AA67DC34AE3EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA8AD87F347AB7E51ULL + 0xD9F8DA53BA2D1BF3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBA6FCD52AD6545B9ULL + 0xA48E579C0EFB0DEFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x972698D194555439ULL + 0xFF82033E93B92733ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9B1FE84ED865782DULL + 0xA334BE5093143EA0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA3A848BA190D00D3ULL + 0xAB289201595228F4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA5F21491949610E1ULL + 0xDB06ACE4E7E5137BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9F3B610F859812D1ULL + 0xF06049D2765B84CFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF3A19B5A21048C6BULL + 0xF5C62AB8A7ABD77AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD72599E80768DD01ULL + 0xCB67F5CD943DE088ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneC, aExpandLaneA, aWorkLaneB, aWorkLaneD, aExpandLaneB, aFireLaneB, aWorkLaneA, aExpandLaneC, aFireLaneC, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2810U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 4984U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3661U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2574U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8129U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 7940U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 40U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + 6069475454765660321U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 11483704742497268068U;
            aOrbiterA = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 11055697447388986418U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 4U)) + 10897095046039997004U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 19U)) + 4731637118230457840U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 13855839187084986751U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 5328208115460188239U) + aNonceWordK;
            aOrbiterG = (aWandererK + RotL64(aCross, 35U)) + 12479538544291412985U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 60U)) + 10740165998792608231U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6492798157284955373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13056825957483891921U;
            aOrbiterA = RotL64((aOrbiterA * 14882112110627751751U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2068184064919194657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5656302738780746294U;
            aOrbiterC = RotL64((aOrbiterC * 16493021179127646345U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11193756120230763294U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17306750816837208999U;
            aOrbiterJ = RotL64((aOrbiterJ * 7949360041241439741U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12952818800389361804U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15380412293642628312U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2914662289178925547U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7706090204767242996U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14598802276412649570U;
            aOrbiterB = RotL64((aOrbiterB * 4821408736292041399U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17819762117328075515U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 6481384240915075101U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 4836701121865783029U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 754936290510338717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15510875946573720154U;
            aOrbiterE = RotL64((aOrbiterE * 2994718968852184303U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9245381722813944586U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2629847912019726214U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6718795794951106961U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3909987749797113773U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9277056074757335265U;
            aOrbiterD = RotL64((aOrbiterD * 11580847505996697115U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + aOrbiterF) + RotL64(aOrbiterJ, 12U));
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 34U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 52U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16263U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 8465U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11251U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8751U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14029U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12692U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 34U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 35U)) + 9888431329297626900U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 23U)) + 2937735167534624403U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 60U)) + 17626022970343789617U) + aNonceWordH;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 5665660859333693743U) + aNonceWordL;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 43U)) + 1060537034632076669U) + aNonceWordC;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 39U)) + 743777763907175800U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 5744905970181808845U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 43U)) + 3545351394494002180U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 47U)) + 4877547088414106007U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11669378338379598445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13984945589234919765U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1433097875470903205U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 451996840039906781U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 716415411025451152U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8542286150858297810U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12932391786479661299U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 14005503313299177013U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 802663466907819743U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9382792812676318046U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 5138554251079724724U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 6386016499265056247U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8522380066269546172U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11825536408101906458U;
            aOrbiterK = RotL64((aOrbiterK * 17042837108792016849U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15504062350899452495U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1219010998820336744U;
            aOrbiterE = RotL64((aOrbiterE * 10650635772711590803U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6442717843380349632U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1047843426279085117U;
            aOrbiterA = RotL64((aOrbiterA * 4074561571072878005U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10611039527108679173U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5092816736177358221U;
            aOrbiterI = RotL64((aOrbiterI * 14342779343820140833U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 42U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19432U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 24292U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17692U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21571U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17340U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23524U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 34U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 30U)) + 16922357079016918108U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 11771749797137599131U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 57U)) + 4635668433708036077U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 47U)) + 15827952719230577008U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 37U)) + 1495675306110023086U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 43U)) + 7294835466949728365U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 23U)) + 179122461212041978U) + aNonceWordK;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 545981421632236251U) + aNonceWordL;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 13U)) + 15338259639814630535U) + aNonceWordJ;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12924313840290895215U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17846785921286020610U;
            aOrbiterJ = RotL64((aOrbiterJ * 18309347016029917133U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 5721472794107057875U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16359630793856870319U;
            aOrbiterI = RotL64((aOrbiterI * 14186771515526698907U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10614102110239037308U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16421992251278236531U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 2561232904676068089U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8668149834861244963U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12699331834360948734U;
            aOrbiterC = RotL64((aOrbiterC * 2249360824172616357U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4470693178142950471U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 526000656022724741U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16688501462334673493U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6880246132270094141U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7126466778855297013U;
            aOrbiterB = RotL64((aOrbiterB * 5692237926830293205U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6436404501390442054U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1213633065612242699U;
            aOrbiterD = RotL64((aOrbiterD * 17604454985534439259U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8186529105901185854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10607460957358250935U;
            aOrbiterF = RotL64((aOrbiterF * 17172191011625677861U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9743278964993305169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14007577681873418075U;
            aOrbiterE = RotL64((aOrbiterE * 4231122580398039133U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 10U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 23U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterF, 18U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + aNonceWordN);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aNonceWordC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 30U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27925U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 31664U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32377U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30691U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29094U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 32097U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 12980104182836602177U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 40U)) + 3172622203188863995U) + aNonceWordK;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 1170974132219980203U) + aNonceWordH;
            aOrbiterI = (aWandererE + RotL64(aCross, 3U)) + 6035201940965047490U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 18033907118424996722U) + aNonceWordI;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 13U)) + 14604813424800580304U) + aNonceWordB;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 51U)) + 13720232492851066035U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 3902659710585257448U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 23U)) + 8331560652661619868U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4485014147538689794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 168202636924512424U;
            aOrbiterG = RotL64((aOrbiterG * 13711020666131492091U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16227825670092707848U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4792781933944671365U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 15859849676231455283U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12636865372722601282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3650053185419807206U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5897288963905408776U;
            aOrbiterJ = RotL64((aOrbiterJ * 3706949366974086151U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9922308113622901726U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13352279749091561510U;
            aOrbiterB = RotL64((aOrbiterB * 4025213180483632557U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14969461950939646117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10231661776135056651U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11284575051455238501U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10621934544068320859U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6029116920305246887U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6087523725059376905U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12887482425168671195U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8351351557123783853U;
            aOrbiterK = RotL64((aOrbiterK * 3839381627914762245U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5405938210926464973U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 385145802287899406U;
            aOrbiterC = RotL64((aOrbiterC * 8330751480464271445U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 46U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 42U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterG, 42U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 36U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Golf_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x846F76340C232FBFULL + 0xB29B571769998B14ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF21D5BCF1D517B85ULL + 0x9F60B2809079A0C3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC7EF8C8CBC3400F3ULL + 0xCEA1D66C99437186ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x943B6111B8A4774DULL + 0x9ECCC8B6281BD95FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDD09FB59CD086831ULL + 0xEECA88890AB0C42EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBF654954DBA873E7ULL + 0xAF0E352D9394AD08ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9476F134DEEF6E93ULL + 0xC3D1BBE19A1640D2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBCFE887731C750A1ULL + 0xEE5A0A96C0D95D2BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEFBD5C9F66FA2FB9ULL + 0xC584A118ED7180BBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE548FE3E19D6F67DULL + 0xCEF66A76832867FBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBB654DB82B880DEBULL + 0xBAE4DA78751C8FB1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBABB6F420D0571EDULL + 0xA35F2EB990B5D962ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB9399631358F7A67ULL + 0xB10A7BD095E47166ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCB5D656FFC6C7239ULL + 0xD402C43C2CDC9B98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAD2482F51AD7A0A7ULL + 0xD07A0456CB915AABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xADE82EE2E0A16A6BULL + 0xE85EF8D2D998FFC4ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneA, aOperationLaneD, aExpandLaneB, aFireLaneB, aOperationLaneA, aExpandLaneC, aOperationLaneC, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5915U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 6336U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6090U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7439U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3847U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 2519U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 29U)) + (RotL64(aIngress, 14U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = ((aWandererJ + RotL64(aCross, 47U)) + 4622023259121087483U) + aNonceWordA;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 10253505250223501352U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 60U)) + 17133877904420462669U) + aNonceWordI;
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 6162827793741796700U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 9610986424765907615U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 11210747154264753754U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aWandererG + RotL64(aIngress, 21U)) + 16554205219580654546U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 10352576357413766388U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3651845783283479752U;
            aOrbiterH = RotL64((aOrbiterH * 1011289824180799641U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 18145542190463500476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5415609566767162857U;
            aOrbiterJ = RotL64((aOrbiterJ * 6474184559323816389U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2033734872464201570U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3507213117125813345U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8716253393049851856U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 695984869565941856U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 8377921610764044735U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7661578828878284931U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 906654265099155956U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8117625377607536949U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6050049984731254612U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17882717590338190821U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 10807367411402733215U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4996521991532815957U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4246460672800604436U;
            aOrbiterK = RotL64((aOrbiterK * 12047466401960824903U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 22U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterK, 60U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 20U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 37U));
            aWandererI = aWandererI + (((((RotL64(aCross, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10934U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 8947U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 13815U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10519U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8399U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11613U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 3621877681473089725U) + aNonceWordM;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 34U)) + 4451752751536414717U) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 43U)) + 11371625415377772117U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 19U)) + 6046792758881150619U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 8213166120394461682U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 27U)) + 4343156661140422645U;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 11105271483234947905U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 348904609985341372U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12924652822526858767U;
            aOrbiterF = RotL64((aOrbiterF * 2801892489296408735U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7461211697358520287U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16551553555297890558U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16432952324635746293U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11908056404140782995U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9147367258259948715U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 10777628928376261667U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8876461054692728610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10546855952702525404U;
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4748636139110443794U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 783046909529525098U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 8969157702460927215U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16683965945838696665U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 12385412690177109575U;
            aOrbiterC = RotL64((aOrbiterC * 10795062772707143187U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8210546822184469023U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13146493623236979963U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13199947810161148155U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterC, 34U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18687U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 20213U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 23079U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23403U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20178U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21421U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 6U)) + 14624277139785904404U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 57U)) + 6966977309498165611U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 35U)) + 205536824352530761U) + aNonceWordP;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 29U)) + 16629575265808255692U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 596881340147972746U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 11944412799107412650U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 4615021315668210206U) + aNonceWordK;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8497630055977606216U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11131601107309336885U;
            aOrbiterI = RotL64((aOrbiterI * 18028349768453554935U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5935883479805510099U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15629346719765798174U;
            aOrbiterA = RotL64((aOrbiterA * 8535523790685945275U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5279128339113651273U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16778365912440331821U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 705421028266789241U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16003052937645491524U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6723226158737614764U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 16690657664909260573U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9785784358981219543U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10055457337292292710U;
            aOrbiterF = RotL64((aOrbiterF * 17919129940751761111U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11779163108592974175U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1177999477942202687U;
            aOrbiterE = RotL64((aOrbiterE * 13475069421684114643U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9190694445141492214U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 15605342360346353457U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 14547769706392595647U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 12U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + aNonceWordD) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 52U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31094U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 31723U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25171U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24814U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26967U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30306U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 37U)) + 17264605017518259932U) + aNonceWordG;
            aOrbiterH = (aWandererJ + RotL64(aCross, 23U)) + 15209184354580778643U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 3299527965014731384U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 29U)) + 16293096431816127821U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 52U)) + RotL64(aCarry, 13U)) + 11031983436878828337U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 3U)) + 9188018632448236358U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 13420816400363406556U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2485063384097917101U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 3089135816938128264U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8813152992957361153U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10730544971770435788U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14883796491656899074U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13465877783538483706U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 14311686051108108503U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13322163435314643713U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3307316600284371955U;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 4950101626975919939U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 2596253994220103666U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7181706961838582889U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17961706029559914243U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10321902557977495175U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18146616411403012772U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8414050129421955787U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 14879448948196182863U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordH) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterG, 27U)) + aNonceWordB);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 34U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x977BA2F37E972681ULL + 0xE76CE589BA62F1B4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB54BF8D8AC113A2FULL + 0x931B9067F10C36A8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF535F5994AD9037DULL + 0xCAF26573BB0C28EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD8B72FA612BED07FULL + 0x9974FD825181EC61ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x81F1F9035FF87687ULL + 0xA9C8494738FD790FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC1A49525EB389F71ULL + 0x87F76751C7C737FBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC4D8E2959D282FA1ULL + 0xFE6E7E0F09069B9DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x83414421E78993CFULL + 0xAEF5C28DAEF5BC05ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFCA052DCD54B6291ULL + 0xCB48D18310EF9804ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFBC8E76303E2B4A1ULL + 0xFAC779413E676FC9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC44041B161849D55ULL + 0x8C323256F794755FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE95E3CA8117C32B9ULL + 0xC34D95DE6F9CE463ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x903E6C390A7FC541ULL + 0x90E196894AF0CCD4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDEF7FF03704C1CD3ULL + 0xE2C805B42D4EDF55ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBD923AC13FF32EA5ULL + 0xD2A0BBEF3037DA6BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB424204DE5457C49ULL + 0xB1C8F768743E929AULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 483U)) & W_KEY1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 2023U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1323U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 144U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 58U)) + 9446153639709651566U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 10550762260670758167U) + aNonceWordP;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 7062634922142578383U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 27U)) + 9178499097812764515U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 6887103379773525538U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + 6239750312052010257U) + aNonceWordK;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 35U)) + 17645022614523287959U) + aNonceWordH;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3639618183259408272U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3131737117548745095U;
            aOrbiterJ = RotL64((aOrbiterJ * 6585057380704940395U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7253994382396406554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15217993711938379561U;
            aOrbiterK = RotL64((aOrbiterK * 17853313384747259923U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12594152227603630033U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11250170200489647869U;
            aOrbiterC = RotL64((aOrbiterC * 546800378327864723U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12936942656624279424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10990736056052106149U;
            aOrbiterD = RotL64((aOrbiterD * 7123916809953459187U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12787293075893090465U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 17154990205620778151U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 10031369940028159521U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1270827262969060301U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17337623431665013136U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1517262088236356107U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 830330490987911853U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6828309232554560547U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9742464176986145819U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 4U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5047U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2962U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4959U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 3570U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 16189787374324972735U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 17563763730956242224U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 3U)) + 10572803498593789385U;
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 11U)) + 7713105232072974166U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aWandererK + RotL64(aScatter, 29U)) + 10760839534772718139U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 13397069448391230253U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 44U)) + 4569255679998375682U) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9888769350817876949U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 11351796060878856300U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13356749147334008399U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18153775071965707204U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1282846411145853435U;
            aOrbiterI = RotL64((aOrbiterI * 12294455920906257823U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16457743979262460660U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 173493260775251032U;
            aOrbiterH = RotL64((aOrbiterH * 4935807229040883505U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3927345926316409630U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5158769729850853623U;
            aOrbiterG = RotL64((aOrbiterG * 2446452358663812945U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12331351600010165154U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3940794200348684050U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13248997263062075043U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 11248514843822945425U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1391497323278226522U;
            aOrbiterA = RotL64((aOrbiterA * 8376841806072565005U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13265623528678787307U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterJ = RotL64((aOrbiterJ * 3437626962562016147U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 58U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aNonceWordM) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aNonceWordB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5675U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadB[((aIndex + 6776U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6371U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6152U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 8075U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererC + RotL64(aIngress, 57U)) + 15045917390223766480U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 10763054007033668758U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 23U)) + 13190170142593666607U) + aNonceWordJ;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 9657025731441167065U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + 11433367178975954211U) + aNonceWordH;
            aOrbiterE = (aWandererE + RotL64(aIngress, 13U)) + 17904920143996810366U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 40U)) + RotL64(aCarry, 21U)) + 3244383020512113283U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6538815775171139091U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7195368312757976343U;
            aOrbiterF = RotL64((aOrbiterF * 10515679176134176565U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18134430713910279374U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6571776588427107976U;
            aOrbiterE = RotL64((aOrbiterE * 11916502085252589161U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11830778129647517758U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9793702760907767365U;
            aOrbiterK = RotL64((aOrbiterK * 4096246227968677179U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2287235876793192036U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8951959188326141794U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9968356718110753845U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7583061790273240157U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3571364625022806085U;
            aOrbiterD = RotL64((aOrbiterD * 6238360922735480669U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13869345563551689212U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 277480328952975002U;
            aOrbiterJ = RotL64((aOrbiterJ * 1057564597096163085U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4983735092494677578U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9490022869381030928U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12926352917961703123U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aNonceWordM) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aNonceWordC) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8998U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 9274U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(mSource[((aIndex + 10142U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8726U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10471U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 10747U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 48U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (aWandererJ + RotL64(aCross, 51U)) + 2786079456995203065U;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 7237256119153857253U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 9310834010563647604U) + aNonceWordP;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + 17361734905706517877U) + aNonceWordG;
            aOrbiterK = ((aWandererE + RotL64(aCross, 41U)) + 15837111231884647451U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 21U)) + 18065431964418026445U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 3029123922999952652U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5166926595573507837U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1918425684273807598U;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4724551751012661440U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterI) ^ 1818014487579644390U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6670090372241084216U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8485757110007268693U;
            aOrbiterE = RotL64((aOrbiterE * 11876760095108618363U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4928130251509514742U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2528788422725346792U;
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2860387120895147503U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12927802338151379368U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 8876144125458603029U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18029699867733207083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13361836994951253312U;
            aOrbiterF = RotL64((aOrbiterF * 5349767426256597073U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 11957294454794128079U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 3755417922063414648U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 13896364063651241401U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 22U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 51U)) + aOrbiterK) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterK, 12U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + aNonceWordD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12622U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 10960U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11695U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 12134U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12864U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12658U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11453U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 16519040829220310189U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 6888002778416941825U) + aNonceWordE;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 51U)) + 1310832187746534025U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + 5890888009051281674U) + aNonceWordM;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 13U)) + 5143864838362464857U) + aPhaseFOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 15591534069452660003U) + aNonceWordF;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 27U)) + 1466867671765325096U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13931443680107902488U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15400747367673245552U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7011651369456453127U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 2836975369734495759U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2370720358274970117U;
            aOrbiterD = RotL64((aOrbiterD * 4615571902817575375U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3470677184188006133U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7175584278499266723U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10067096593682482345U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 6095078817776863055U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2176637999243513070U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12215701810843975501U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5580391239754903129U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15196125567953871184U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 12686361960729564519U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12787014151503209931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1523153207064063495U;
            aOrbiterF = RotL64((aOrbiterF * 3113907543551927561U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12973289026485937829U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9087439766232078173U;
            aOrbiterB = RotL64((aOrbiterB * 5817029335999350327U), 37U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 40U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aNonceWordD) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 28U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15454U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16017U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14803U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13745U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14435U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16080U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15148U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 42U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 13924571355038625040U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 46U)) + 16328300979357156658U) + aNonceWordI;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 3947771961206012461U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 15428284250569311285U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 3U)) + 5777369485254032486U) + aNonceWordC;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 21U)) + 16813320300717644673U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 39U)) + 16689933050200758251U) + aNonceWordE;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1856422419049390708U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 18214498743831925517U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10744120577560529379U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18278550878494094923U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 797712062039591797U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7212998747080137625U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 15854849439012341347U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3005829974130671692U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8793495343509953906U;
            aOrbiterI = RotL64((aOrbiterI * 14065479348374612031U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7710453029930631112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9511995836117707047U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7250766204781428201U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 670902975693341744U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9045820304668279777U;
            aOrbiterF = RotL64((aOrbiterF * 18373074917532639027U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12417212387607119470U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12816983560669985622U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 8406003970221889847U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + aNonceWordM);
            aWandererA = aWandererA + (((((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererI = aWandererI + (((RotL64(aScatter, 14U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 26U)) + aOrbiterK) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16433U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 18645U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 16639U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17691U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18614U)) & W_KEY1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16851U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17055U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 36U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 19U)) + 1364174714924216027U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 13U)) + 13561796874229506613U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererI + RotL64(aIngress, 43U)) + 11845572344206238305U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 29U)) + 15762708240326773763U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 35U)) + 1157119665207900473U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 6823546624372055260U) + aNonceWordI;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 14465564210523945121U) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 10667464548080807531U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13445737493224316575U;
            aOrbiterG = RotL64((aOrbiterG * 12137295000900795711U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3009837893785957665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2886920524111083752U;
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10886177449328249656U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15067759884678100433U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18307930462682331536U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 8791864377579255801U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 805797468642992351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5743305867058244964U;
            aOrbiterC = RotL64((aOrbiterC * 16263000753351131717U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17102025528234481273U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1841579177327486899U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 3841603385577825265U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2189493507896508972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18209567010094914374U;
            aOrbiterD = RotL64((aOrbiterD * 3737080408976852351U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aNonceWordC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterG, 53U)) + aNonceWordA) + aPhaseGWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21553U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 20858U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20377U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 21697U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19236U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21259U)) & W_KEY1], 58U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21118U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19729U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 13499155707765393469U) + aNonceWordJ;
            aOrbiterA = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 3740324981823726185U) + aNonceWordF;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 35U)) + 5470765363949735652U) + aNonceWordP;
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 3446436171274452326U) + aPhaseGOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererI + RotL64(aCross, 41U)) + 1778929412631211933U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 60U)) + 14666308799855220954U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 21U)) + 4548410236791175055U) + aPhaseGOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5829739767694190372U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14319231414903675748U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 1513851750246111405U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1685620217748986019U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9286548037413609445U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16284162182006054402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6271539598462003309U;
            aOrbiterC = RotL64((aOrbiterC * 13923286694131331137U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12669312437565969473U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11894755313393001665U;
            aOrbiterK = RotL64((aOrbiterK * 12556759675372354075U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6315983824634946566U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17106616474222892782U;
            aOrbiterH = RotL64((aOrbiterH * 167205520766791073U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13350266700180455548U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4608846311203767162U;
            aOrbiterJ = RotL64((aOrbiterJ * 2504857468837437365U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14195866746143604365U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7917977448256795054U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 5927771378657284557U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 6U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + aNonceWordB) + aPhaseGWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aNonceWordE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 46U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22153U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 24432U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22489U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22479U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23280U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23204U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22727U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 22969U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 21U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 13174219512651137892U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 2715455762789269341U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 11U)) + 1338018183235594313U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 19U)) + 16566866551729552930U) + aNonceWordN;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 29U)) + 6901845297307236726U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 2476078302049201718U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aCross, 5U)) + 15531109473927052260U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4087849380858572351U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5167830630098599644U;
            aOrbiterK = RotL64((aOrbiterK * 1982835131228146099U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7275995452428627217U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14794340370010024117U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 8779497557416568379U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8509217403041662849U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2321522025240806996U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5676672952755594051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2304681269233504384U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8383399721062437300U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13181984036942227666U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1648761328771932069U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 13602604532551684210U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12725687663616352843U;
            aOrbiterA = RotL64((aOrbiterA * 4684699861686199753U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5831790822416009806U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4535048543735457407U;
            aOrbiterI = RotL64((aOrbiterI * 12076777878870257053U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 14U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterF, 57U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordL) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25729U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 26900U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25356U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27134U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27246U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27177U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25649U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 25192U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 13880995121909552664U) + aPhaseHOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 29U)) + 14534942818069300546U) + aNonceWordA;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 17745973100886007133U) + aNonceWordE;
            aOrbiterK = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 2249805580771946872U) + aNonceWordH;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 23U)) + 4460116116396439410U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 12U)) + 3378683994078106878U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 47U)) + 3992996501048809123U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12057768808864451929U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4115362079047921130U;
            aOrbiterF = RotL64((aOrbiterF * 12263015903331031345U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15297384955502206698U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17623548383481905636U;
            aOrbiterA = RotL64((aOrbiterA * 7487278217901483685U), 11U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 3559213898000162417U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 12311605719074507335U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14807313864347885885U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11222085523291581822U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 12580941911587215653U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 916681229436292462U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2441350114032314686U;
            aOrbiterD = RotL64((aOrbiterD * 7336079498999018067U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7361470539894653271U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12153585147213579808U;
            aOrbiterI = RotL64((aOrbiterI * 3040327545467672961U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13566300726101613579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14875254144748509128U;
            aOrbiterG = RotL64((aOrbiterG * 13699179902908972403U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 44U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordL) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 58U) + RotL64(aOrbiterH, 37U)) + aOrbiterK) + aNonceWordF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 13U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29609U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 27969U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28265U)) & W_KEY1], 21U) ^ RotL64(aFireLaneC[((aIndex + 28247U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27581U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28099U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27727U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 28129U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 16200278595895089008U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 1029614154810465897U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 7129562468705441295U) + aNonceWordH;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 41U)) + 14388903902433951274U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 13U)) + 1013568949315967455U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 6U)) + 3128823373497815651U) + aPhaseHOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 35U)) + 14525694606889470589U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14443983602196782887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12244220415328641190U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15052949098014803181U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10477159225338766614U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2842870123078131566U;
            aOrbiterE = RotL64((aOrbiterE * 11522265477555954071U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8621138818955849917U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5038396344400303181U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14636756322207385447U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2768613802894372496U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2027754864051410015U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2848088309172056399U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15017458513904884651U;
            aOrbiterK = RotL64((aOrbiterK * 9926904679902843055U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9079797279596336139U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15424866642305110811U;
            aOrbiterI = RotL64((aOrbiterI * 12912331089970158845U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13751764050290602740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7694557131324740282U;
            aOrbiterD = RotL64((aOrbiterD * 14980807690491467023U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC + (((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 53U)) + aNonceWordI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterE, 40U));
            aWandererD = aWandererD + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordA) + aPhaseHWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30347U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32728U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31099U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32627U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32381U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 31428U)) & W_KEY1], 58U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 11177787645248006236U) + aNonceWordG;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 30U)) + 3808340254579817169U) + aNonceWordF;
            aOrbiterB = ((((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 828030667598518279U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 16177835921238398371U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 51U)) + 5518747735458708741U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 37U)) + 17346319082399995165U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 23U)) + 6397156921893030937U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15559381654710713582U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 940404446491415088U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16401260971303026881U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8047166032048732645U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4688468645859470491U;
            aOrbiterE = RotL64((aOrbiterE * 14383536431614496369U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3710878044770337260U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 116343189456629220U;
            aOrbiterG = RotL64((aOrbiterG * 5637725064169289339U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 883908030159391659U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 18058691521694880482U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3132200449123497619U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17521015077103586117U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3668332225435714918U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12658899101297839881U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12229480388278883300U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16206524049491531816U;
            aOrbiterC = RotL64((aOrbiterC * 11122340196620859805U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5743265849441077466U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2812293020719282236U;
            aOrbiterJ = RotL64((aOrbiterJ * 8903956475200417109U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + aNonceWordC) + aPhaseHWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 60U)) + aOrbiterB) + aNonceWordM) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Golf_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEC48EBFB719B5F81ULL + 0xA3EAB0FA8EA4058AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB7E4A017571A94E9ULL + 0xC66A72E91B6AEE7DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEF8D7791C1D4C0F1ULL + 0xC3A797DC6E5FFCE8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB3870E0962802591ULL + 0x91733E56AEBB841FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB2455B8E7F5AD83DULL + 0xD09599408C823852ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF4384C3F24D9CDF1ULL + 0xF6D127EB98F1FB0CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF303791E53BB8AC7ULL + 0x843F0D01239F2E01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFC8C114F6F1DEE21ULL + 0x9F1DD490C7DAD9BCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFED2E2D317B4B0B3ULL + 0xE2D6E900FA934B97ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE8206DCA6FAAC6DFULL + 0x9E296469D08BBB2BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD24A71A578503D07ULL + 0xF8934EC43406C892ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF6635BA4DD15AFADULL + 0xAE9E74CB5E35A2B8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC914682CA3FFADE7ULL + 0x98FD509CA4E7DB36ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFC24D175AFD42789ULL + 0x9B8D76758E71C238ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x804D2067FBC1A803ULL + 0x866C0987F7E4F45CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA001C88C6FB1B797ULL + 0xDB597CA846A9C062ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4868U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 3868U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 161U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 90U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 225U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 19U)) + 6318740973868639425U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 5487840061430920881U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 53U)) + 10258706763248072672U) + aPhaseAOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 18356875269730338208U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 27U)) + 12883160282903147010U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1010140474942697730U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17733939421700898293U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9233534157871885251U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13693055887924981201U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14574732452793385269U;
            aOrbiterI = RotL64((aOrbiterI * 9373765929885750185U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10832873941223609012U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8212600587135328040U;
            aOrbiterK = RotL64((aOrbiterK * 5334613996794796145U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5312744319781971178U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6173741211706546923U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 12854414066390848249U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3693249147883790810U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 18365859989736602556U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 3348463719324104997U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 53U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 5U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterK, 10U)) + aNonceWordO);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7973U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 6887U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 8071U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7405U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 9792U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 21U)) + 16922357079016918108U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 11771749797137599131U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 4635668433708036077U) + aNonceWordO;
            aOrbiterE = ((((aWandererG + RotL64(aCross, 38U)) + RotL64(aCarry, 47U)) + 15827952719230577008U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + 1495675306110023086U) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7294835466949728365U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 179122461212041978U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 14467072888722097971U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 545981421632236251U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15338259639814630535U;
            aOrbiterK = RotL64((aOrbiterK * 14895421566334357871U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12924313840290895215U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 17846785921286020610U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 18309347016029917133U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5721472794107057875U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16359630793856870319U;
            aOrbiterE = RotL64((aOrbiterE * 14186771515526698907U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10614102110239037308U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16421992251278236531U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 2561232904676068089U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 18U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordF) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12656U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 13641U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13756U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10923U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15685U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14259U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererI + RotL64(aCross, 46U)) + 7270044678408187242U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 10192278965379756766U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 3U)) + 17568666746676060748U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 14312927531124963037U) + aNonceWordO;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 9825825726152087706U) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9696778570255265896U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17657841352013417228U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 17562220176018833833U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16207815085909628439U) + aNonceWordH;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 1752979206374514227U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 14182667540650694199U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10456310689643905854U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16127830548663742550U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4355938404839045417U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2940917376003930842U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7353596864777649953U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7499468723171042005U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12725092740446150705U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5791296650856037010U;
            aOrbiterG = RotL64((aOrbiterG * 760379251950502133U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + aOrbiterE) + RotL64(aOrbiterA, 56U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 21U)) + aNonceWordG) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterG) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21774U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 18371U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20812U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19959U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17965U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 19196U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 58U)) + 17225673071833726819U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 10301458382103627331U) + aPhaseAOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 3U)) + 3960233050857362414U) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 17768665685046605837U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 14471018461213959767U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10730597892721340453U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14863394003122760542U;
            aOrbiterB = RotL64((aOrbiterB * 17731557030589257169U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9948587274816688296U) + aNonceWordC;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 3573569431435100993U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 2303922230056523077U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8153670675740450590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16438856577722561424U;
            aOrbiterG = RotL64((aOrbiterG * 4689247488336908827U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15765587867581925041U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4202521649260798876U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15877659681260461141U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 11369910758551088173U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterH, 44U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 5U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 27U)) + aNonceWordN) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23100U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 22541U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 26237U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24443U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26299U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26871U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 14U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 3105313968748067810U) + aNonceWordJ;
            aOrbiterI = ((aWandererA + RotL64(aCross, 35U)) + 9977249451119627064U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 26U)) + RotL64(aCarry, 37U)) + 17941392803495349366U;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 4279533326705471133U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + 13983828966811580039U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3983490984234810378U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 308786542215259956U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 4366245356597769425U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8443607695364427037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14939626441464340668U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16793255020331774983U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9350693577306121110U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1717071159396961752U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11062480662625054525U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15911765265202100610U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14898546272333182767U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 2674900543810733067U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3560903518513465868U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5367062725726860234U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 54U) + aOrbiterB) + RotL64(aOrbiterC, 3U)) + aNonceWordK);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 53U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 29U)) + aNonceWordP) + aPhaseAWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterF) + aNonceWordO) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28936U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 27457U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 30116U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30168U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31940U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31144U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 11U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 19U)) + 14214886793361825363U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aIngress, 38U)) + RotL64(aCarry, 53U)) + 17267959031078766320U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 16436067429484887644U;
            aOrbiterK = ((((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 9885951769332633820U) + aPhaseAOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + 12971711341813893304U) + aNonceWordI;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 199970353398450154U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 1237341696444162094U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 2850125642665515751U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7991128854417613360U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14809029847149045833U;
            aOrbiterF = RotL64((aOrbiterF * 5940857360838299105U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2559509556915775947U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 14336829730147834160U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 15103242520064900873U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8853631886733610440U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13346159398673246914U;
            aOrbiterK = RotL64((aOrbiterK * 13660497151446983393U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12121095718571872976U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16239781125815589804U;
            aOrbiterI = RotL64((aOrbiterI * 5157009090454962231U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 48U)) + aOrbiterD) + aNonceWordG);
            aWandererG = aWandererG + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aPhaseAWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Golf_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8168395614307F7FULL + 0xB06153FCD1E50A8AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE4FB9DCB5E2F7FD7ULL + 0xDA1FC62755B1F17CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC5F387ACC439921FULL + 0xC28F3983C615939DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBFF2E5AF1C217F1FULL + 0xCBA3A032F22DA68FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDA6C3DAF90FA7C5FULL + 0xB5E90EFE917AF16AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA57C243942DB527FULL + 0xDD96E3CCC1240764ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCC24D97CE6CE8FBFULL + 0xCD2F1053C26670A7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFA9294B9D701DBABULL + 0xA44ECA6CAD302110ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF8F607B50FB73F4FULL + 0xD03175217632DA0CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE006CC87B5C42A3DULL + 0xE2F2DAF1FE043152ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC5B884BB04FBF18BULL + 0x80B1152E9E4BF366ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE0E7622EB9EB7487ULL + 0xE0879C2EEA38154CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8BF613B922F82287ULL + 0x85446A50F2214A3BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9161B4E2E3E0F73DULL + 0xC2A8479EA4BCE92EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD052995A96D72DA9ULL + 0xF0AC525CD79A8958ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAEC7946659683C61ULL + 0xFBBCA0D9F235A57FULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneA, aInvestLaneC, aFireLaneA, aFireLaneD, aInvestLaneD, aExpandLaneC, aWorkLaneA, aFireLaneC, aWorkLaneB, aExpandLaneD, aWorkLaneC, aFireLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1702U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 709U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 3366U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3615U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4331U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2982U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 47U)) + (RotL64(aCross, 22U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 9888431329297626900U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 43U)) + 2937735167534624403U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 39U)) + 17626022970343789617U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 35U)) + 5665660859333693743U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 1060537034632076669U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 51U)) + 743777763907175800U) + aNonceWordE;
            aOrbiterC = (aWandererE + RotL64(aIngress, 13U)) + 5744905970181808845U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 18U)) + 3545351394494002180U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 35U)) + 4877547088414106007U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11669378338379598445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2961072441706158212U;
            aOrbiterD = RotL64((aOrbiterD * 2677988507090705371U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13984945589234919765U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1433097875470903205U;
            aOrbiterG = RotL64((aOrbiterG * 451996840039906781U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 716415411025451152U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8542286150858297810U;
            aOrbiterC = RotL64((aOrbiterC * 9139015340823332449U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12932391786479661299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14005503313299177013U;
            aOrbiterF = RotL64((aOrbiterF * 802663466907819743U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9382792812676318046U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 5138554251079724724U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 6386016499265056247U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8522380066269546172U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11825536408101906458U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 17042837108792016849U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 15504062350899452495U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1219010998820336744U;
            aOrbiterJ = RotL64((aOrbiterJ * 10650635772711590803U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6442717843380349632U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 1047843426279085117U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 4074561571072878005U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10611039527108679173U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5092816736177358221U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14342779343820140833U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 4U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aPhaseBWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8896U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 9875U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8986U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((aIndex + 8489U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5889U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7975U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5722U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererF + RotL64(aCross, 34U)) + 12122689833405846292U;
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 9640400270962766788U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + 9141937998266739071U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 57U)) + 12899395770434090537U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 13457918115408031842U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 11U)) + 15134784483576000943U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 23U)) + 12540961268790055438U) + aNonceWordE;
            aOrbiterA = (aWandererH + RotL64(aScatter, 51U)) + 6306886773092764230U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 38U)) + RotL64(aCarry, 27U)) + 13573343491337243121U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8545588657348974413U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10891410570357275120U;
            aOrbiterE = RotL64((aOrbiterE * 5399310978367842841U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2877137119767060151U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9178097682386595144U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3524486002084427513U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15528007881855616978U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11368419529245281435U;
            aOrbiterI = RotL64((aOrbiterI * 12433207037378339309U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5932738914934356645U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5551842263864055419U;
            aOrbiterK = RotL64((aOrbiterK * 16093776759971522681U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3824433359595690603U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17184628855571662441U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 691208053136187317U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8724462245014132623U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7481349499528092352U;
            aOrbiterC = RotL64((aOrbiterC * 8212182934509617583U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6908362960248294718U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5354057969992655314U;
            aOrbiterA = RotL64((aOrbiterA * 16586084885820679343U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11138301629323903147U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14164180536320940750U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9099767681053390287U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 709942920176922902U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17128241237359414945U;
            aOrbiterF = RotL64((aOrbiterF * 14063385518459963529U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 52U) + aOrbiterE) + RotL64(aOrbiterA, 37U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 41U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 53U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 14U));
            aWandererF = aWandererF + (((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + aNonceWordO) + aPhaseBWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 27U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterC, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aExpandLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15373U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 11932U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13632U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11835U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 15818U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 47U)) + 14157904117287696136U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 7369512677371640676U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 58U)) + 8411250745902073798U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 5002041814539710275U) + aNonceWordM;
            aOrbiterB = (aWandererE + RotL64(aIngress, 23U)) + 9538041410816283124U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + 5210700103927513061U) + aNonceWordH;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 4U)) + 7600709399101287982U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 43U)) + 2366369466696580499U) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 5544575244203019109U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8710073749110329779U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15998211310115361630U;
            aOrbiterE = RotL64((aOrbiterE * 15275657696897688955U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15354357553877376422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10657523549259276169U;
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10405750198355464768U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3465819693133515142U;
            aOrbiterB = RotL64((aOrbiterB * 14678343718277562799U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16724189641701408630U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3484340153620198872U;
            aOrbiterC = RotL64((aOrbiterC * 17247547677520703125U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7420442404884871126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11138445997256757636U;
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1428191560884663125U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16950093140800653985U;
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17288299075036481960U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13793597915359681028U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9639204979982125757U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5017972942710079726U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12409957957614320964U;
            aOrbiterA = RotL64((aOrbiterA * 10273295741911545745U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12487994181992095174U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1573393166996612118U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 13364311829104520751U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 27U)) + aOrbiterI) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterC, 58U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 52U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 18U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17245U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 21215U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16832U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19176U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 16880U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 13960289014350612206U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 3483331015269589730U) + aPhaseBOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + 6873299241002444518U) + aNonceWordK;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 54U)) + 3562094007125534229U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererG + RotL64(aIngress, 37U)) + 11422367439932782705U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 532453428514259816U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 29U)) + 17810941465810193088U) + aNonceWordA;
            aOrbiterC = (aWandererD + RotL64(aScatter, 13U)) + 11869759058631106331U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 60U)) + 8837581071876177566U) + aNonceWordI;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17185378327053837778U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7578253375676981500U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 13371647568758721729U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17112646434432814442U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14949096407295697881U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14770977858283051753U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4259590620758467836U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6534899413644542303U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2637407498893694243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15819295597921425711U;
            aOrbiterG = RotL64((aOrbiterG * 5202015597375051399U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6373559542002699718U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11694562937392022505U;
            aOrbiterE = RotL64((aOrbiterE * 9311557972331218597U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3308736483775453062U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12749929710650475901U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 248428400724560945U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1569528215675579656U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1044077933631689572U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6443796233912755143U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8393422728124537471U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2002732612516530754U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13702146823622364279U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13469191942843147943U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7633171368709520560U;
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 14U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 18U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23438U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneD[((aIndex + 27268U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 25500U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24153U)) & S_BLOCK1], 54U) ^ RotL64(aInvestLaneC[((aIndex + 25976U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 53U)) + 5960680319644404115U) + aNonceWordD;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 19U)) + 16050752633567034185U;
            aOrbiterF = (aWandererA + RotL64(aCross, 28U)) + 8447503223226854741U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 14176813813397917591U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 10534915376130006644U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 5U)) + 6866224454375302514U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 24U)) + 16506374165041008396U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 7167814023968794098U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 13U)) + 13870852197416596664U) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18064038854848993105U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9869630811507771691U;
            aOrbiterF = RotL64((aOrbiterF * 13723164383800461387U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 863613100452759380U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16597969741225436529U;
            aOrbiterD = RotL64((aOrbiterD * 2680793528887208903U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6575347108051310653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17062262265485019063U;
            aOrbiterB = RotL64((aOrbiterB * 7601045488473620019U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7193399224636409133U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14146747818810433849U;
            aOrbiterJ = RotL64((aOrbiterJ * 5273185769989530041U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9441449106442431427U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4303295336545399503U;
            aOrbiterK = RotL64((aOrbiterK * 8829695296836242587U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12604760768543193458U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 15779327512379787715U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 14000905201441272597U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 15553000781122708728U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17162740616060079717U;
            aOrbiterH = RotL64((aOrbiterH * 9458662233556750239U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1032374679817715156U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16413393156165548232U;
            aOrbiterE = RotL64((aOrbiterE * 549659738811935015U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 14056855000013992045U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7399202019042538829U;
            aOrbiterI = RotL64((aOrbiterI * 6103508549612077695U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 42U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 56U));
            aWandererH = aWandererH + (((((RotL64(aScatter, 6U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordM) + aPhaseBWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aNonceWordL) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterB, 44U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31547U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 29878U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 28051U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27903U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 30406U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 18U)) + 8402620908307642697U) + aPhaseBOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 5U)) + 11347672014525086047U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 2816462912503401876U) + aNonceWordB;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 6940159795470696093U) + aNonceWordN;
            aOrbiterF = (aWandererI + RotL64(aCross, 37U)) + 9134692490095883851U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 29U)) + 4999455497008026526U) + aNonceWordI;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 5992451460350651332U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 23U)) + 3417087346651371924U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 60U)) + 3612773820086198270U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 463398077083428570U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 11249391303705089012U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 7106735772303292983U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17027535139825739501U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 568131384979596481U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5683451044852895957U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4793712537158004047U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 10415170179135963622U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 13729564030210361415U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2391473979460065630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4240058362680064261U;
            aOrbiterG = RotL64((aOrbiterG * 12375884373396400889U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9963957011090031698U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3325305624067445525U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3128542681461806309U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2094945647665114693U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10703615640774042674U;
            aOrbiterK = RotL64((aOrbiterK * 12641986098450423751U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3768738815518590289U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15021301790376706827U;
            aOrbiterD = RotL64((aOrbiterD * 14445850924223550339U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10571246886181608316U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5130325144599151793U;
            aOrbiterJ = RotL64((aOrbiterJ * 3185251943547657467U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8617523421720966373U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16574597770835250074U;
            aOrbiterC = RotL64((aOrbiterC * 1759209403428937799U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 14U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 34U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterE) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Golf_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF9B50713F283757ULL + 0xECD438835B732116ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x81BAD41DD3A908ABULL + 0x9C61FDC8F1AB5B9FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAAC3D183F1D8964DULL + 0x808B15F0DFDF4305ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDC5C45E94331B33BULL + 0xF04697B87C7DCC72ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAEDAF9A69A6A7FBBULL + 0xD73F3AB5078C1966ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE39E1E35AC4F9449ULL + 0xB8622C047A7FC469ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFDF6DA80C355EDFFULL + 0x8566E543030226D8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDF44A69889C13115ULL + 0xE35EE84D2331BF66ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEC9B434CBAB631D3ULL + 0xD6E8F2B3EF87E9ABULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC6D531E0B981DC7FULL + 0xB8656F94C6B82400ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x93692EBD8A7C91C7ULL + 0xE4E57F05CFC4D2F2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB0B6810E4742C51BULL + 0xE6E88E3D471538D7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9E2EB67FA4F185A5ULL + 0xCD1CE715A7809657ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDD1BD2CE5A866455ULL + 0xD226F7A65EED047EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB027A9E3CA4D51EDULL + 0xA8801D795E5B699AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF0D89A251428477DULL + 0xF964C90DA3CCF72BULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5301U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 1769U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 282U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2484U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 851U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3746U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 12U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 13174219512651137892U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 13U)) + 2715455762789269341U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + 1338018183235594313U) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 5U)) + 16566866551729552930U) + aNonceWordM;
            aOrbiterF = (((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 27U)) + 6901845297307236726U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 39U)) + 2476078302049201718U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 15531109473927052260U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4087849380858572351U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 5167830630098599644U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1982835131228146099U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7275995452428627217U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14794340370010024117U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 8779497557416568379U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8509217403041662849U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2321522025240806996U;
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5676672952755594051U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2304681269233504384U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8383399721062437300U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13181984036942227666U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1648761328771932069U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13602604532551684210U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12725687663616352843U;
            aOrbiterE = RotL64((aOrbiterE * 4684699861686199753U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5831790822416009806U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4535048543735457407U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 12076777878870257053U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 4U)) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterF, 29U)) + aPhaseDWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 38U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10407U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 8902U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 8091U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 5834U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7769U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8932U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8988U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = (((aWandererB + RotL64(aCross, 29U)) + 12583180859826261500U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 13U)) + 9067093488553721468U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 50U)) + 12173106198862881754U) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 57U)) + 11333491014394592654U) + aNonceWordM;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 3511883526940919554U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 7416810692106273044U) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 8341174972619784110U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2220852854836962979U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8090781422229383825U;
            aOrbiterA = RotL64((aOrbiterA * 578293950675644397U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2338801236599102223U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12484514711848308104U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10364216764253366067U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13684861340589131816U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12796636819991873058U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 5533508014234835669U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7634198650894837690U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10240326122201201762U;
            aOrbiterJ = RotL64((aOrbiterJ * 8758703497719125901U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4162814763739453934U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2766504649149048469U;
            aOrbiterB = RotL64((aOrbiterB * 16731843453895178671U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11051393030148769655U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17687055068651386665U;
            aOrbiterF = RotL64((aOrbiterF * 1042927176246229537U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3353615315436983420U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5971640796220306310U;
            aOrbiterD = RotL64((aOrbiterD * 15804313508835034807U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + RotL64(aOrbiterB, 37U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 12U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12878U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 11887U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15830U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11858U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13456U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 17936518874386450467U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 60U)) + 13722737841589910344U) + aNonceWordF;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 19U)) + 11774969167948715796U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 41U)) + 3640101505680493777U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 35U)) + 1369495382725650822U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 11827310354654653345U) + aNonceWordG;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 186037671377175394U) + aNonceWordP;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11428829344234627340U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2275016369870029068U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 14936799202145280833U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15471646673734798328U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12172082573115640145U;
            aOrbiterH = RotL64((aOrbiterH * 9629417882787847753U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6626736341348283154U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12220614992483863623U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8137086205714097487U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13157102324253760215U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4143587482368093601U;
            aOrbiterA = RotL64((aOrbiterA * 5060677690991506895U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11007575246013796426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11721585930088637162U;
            aOrbiterG = RotL64((aOrbiterG * 15009627907125738519U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 5720789204450196217U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3094696226821431648U;
            aOrbiterB = RotL64((aOrbiterB * 4412033981712165541U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14675830108100986773U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9444071495289719645U;
            aOrbiterF = RotL64((aOrbiterF * 10983136361953366557U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 28U) + aOrbiterJ) + RotL64(aOrbiterB, 44U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21670U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 21448U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19652U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20254U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17958U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 43U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererA + RotL64(aCross, 37U)) + 3650233661228036955U) + aNonceWordC;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 19U)) + 11607036400067735729U) + aNonceWordK;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 3899614406903883035U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 12U)) + 8159156925629965143U;
            aOrbiterE = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 7148903913967261270U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 9161665622287517848U) + aNonceWordF;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 43U)) + 2981535013474059469U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15812469008200319549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14687469489893270300U;
            aOrbiterK = RotL64((aOrbiterK * 14142363399696670451U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6025209349511417063U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12964750392311112676U;
            aOrbiterF = RotL64((aOrbiterF * 12955480283032701843U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6572355895765394340U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3542300121890027981U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6477175684045398359U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1081388388827929314U;
            aOrbiterG = RotL64((aOrbiterG * 8752188637514143529U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13754328481584620771U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3684673342659575917U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6139923312873039143U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6542045150319909445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5352102692424060388U;
            aOrbiterH = RotL64((aOrbiterH * 7385758355501860261U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9110100774657340354U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 2813273684436269057U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 10468759062594022273U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 37U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 43U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25145U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 24072U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22502U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25238U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneA[((aIndex + 25961U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 35U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + 6733949564325516029U) + aNonceWordF;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 7304098437143918796U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + 3923949518391777800U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 14243591003388927124U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aWandererF + RotL64(aScatter, 11U)) + 18329498724605410406U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 13118172167747037249U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 5272025143849174212U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16075917179214318424U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15263590648674658399U;
            aOrbiterA = RotL64((aOrbiterA * 9918239923411740337U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13730046728289525921U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7703141464499623408U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5886009900621521987U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1382279753822135359U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2973369221699098292U;
            aOrbiterD = RotL64((aOrbiterD * 7440242040663550631U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 2582783513078999303U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3959762790273529677U;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 465795011576934604U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17880826624185821135U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4445949147592860913U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10819659185349413173U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17298208553586835030U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 1965860510614222093U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 12U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 56U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterH) + aNonceWordJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterI, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 27531U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 27368U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30835U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29112U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31632U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 42U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 19U)) + 1457104756581596530U) + aNonceWordL;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 6127240317844622874U;
            aOrbiterE = ((((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 16492290056044189421U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererC + RotL64(aIngress, 26U)) + 10963676850938416468U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 4872917367399752405U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 15218882377875616148U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + 5934166612122118251U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 14215280930872003003U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 11428034799044600979U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12162528943733976177U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5453003654321728726U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14273775120265649389U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5139018128323795309U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 328723770018440271U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13032190719588211088U;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2386881543033598494U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1649501123340887116U;
            aOrbiterG = RotL64((aOrbiterG * 11148976582360499033U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 16462401546754210583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1510579201823042227U;
            aOrbiterJ = RotL64((aOrbiterJ * 16287912400104043275U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6889066000014251983U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11324594596597724357U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15344987814648586023U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12237796033168436537U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17306069670330000343U;
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 46U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 43U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 22U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + aNonceWordE) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 36U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Golf_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFA205A712379558BULL + 0x98267AA7FDE3AA9EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB8B17CE77F4A730BULL + 0xD4B4F55D6D828A8BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE0392A47BCAD4975ULL + 0xCC3BDA19227F080FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB0A33587D3CD944FULL + 0xADD2E2FE4EFBFBFFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE54651E69D533393ULL + 0xE3098E6560504A81ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB12E995169210C5BULL + 0xCF40839D072E2C2BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF5E3F370CED75E09ULL + 0xB5AB2921CC72FCD1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xABF76E72E6A6E8C1ULL + 0xCFBB608BBA75F09EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEB8DFF507F540887ULL + 0xED00D29583E0E623ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC88A0ECFA2C7E0BFULL + 0xB6E660B6444C808FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE998B2526A215EC1ULL + 0x86791095DD7927E7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEB5D27972BDAD5E1ULL + 0x8A2A1AA98B167C2EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBAF31F6B865E42FFULL + 0xDE890977FB700AD8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDE9527E2AF5B53F9ULL + 0x9A3A660385948C78ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB383EA57EF904F4FULL + 0xD8440A2F3CF92BBDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAC2E35835B48B181ULL + 0xB9E56C2134832818ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4008U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneB[((aIndex + 3959U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3246U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4312U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2027U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2311U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 11U)) + 9774364261626083532U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 14U)) + 18059001521926116420U) + aNonceWordD;
            aOrbiterF = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 10615626210406381148U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 41U)) + 10536484278007898620U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 13320663045139972700U;
            aOrbiterI = (aWandererF + RotL64(aCross, 58U)) + 17127001787268166583U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 35U)) + 16742574590844166551U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 19U)) + 8347719720758228053U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 13502468705946051986U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 51U)) + 3512687886188904904U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + 495660316165795934U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5092722552034477356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15641128019608284015U;
            aOrbiterF = RotL64((aOrbiterF * 3621036395703527059U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15421873776811085458U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17978775513204574125U;
            aOrbiterI = RotL64((aOrbiterI * 18359600395119440183U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16617179197537669849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1931805387534012528U;
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9544923119559308431U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12930999400470173353U;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13673733276226249890U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2032263473309124738U;
            aOrbiterC = RotL64((aOrbiterC * 3088728329261360607U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14868502349358414206U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10116495537187552321U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 1380512121796709469U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5341113995358179244U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8415417980279705731U;
            aOrbiterE = RotL64((aOrbiterE * 8521501372683793821U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2462819265072352463U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7657062767608441931U;
            aOrbiterH = RotL64((aOrbiterH * 15554638801273540163U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8153420530633265789U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10990681417675210534U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1928509513380702895U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17035995983178569271U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2806563871848226777U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4137935663733587867U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6570698907081812011U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9774364261626083532U;
            aOrbiterD = RotL64((aOrbiterD * 1766375419340392741U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 20U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 40U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + aNonceWordF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 43U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterK, 6U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 13U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8312U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneC[((aIndex + 5708U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 9533U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 5905U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6719U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6155U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5588U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 898812731947995389U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 37U)) + 8677347622525527167U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 19U)) + 770321564027567654U) + aNonceWordB;
            aOrbiterG = (aWandererK + RotL64(aCross, 56U)) + 11020474858081526395U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + 17289793580414993470U) + aNonceWordH;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 10111912559295118444U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 21U)) + 8083622125544542011U) + aPhaseEOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 41U)) + 7149858558922988240U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 60U)) + 5919683821379905699U) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 6860902846079238714U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 15083517836867542075U) + aNonceWordD;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14852868368708376381U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9860233289028878323U;
            aOrbiterK = RotL64((aOrbiterK * 13418143547952204667U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 772406119079116272U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7971141501337627589U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10168120622976358617U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8478568022896691911U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 4027604850785607101U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 4826627523578901467U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17199331557841535430U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7515957656979776361U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5468950152869656599U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17138249294921502391U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16236812863923234668U;
            aOrbiterB = RotL64((aOrbiterB * 2925542836624164807U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16941524155859123682U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11240343728857342866U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 7281012444214294659U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15163914964139858328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6673576554415729652U;
            aOrbiterC = RotL64((aOrbiterC * 1558880328574736975U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5399050402101642989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11806006719060024615U;
            aOrbiterI = RotL64((aOrbiterI * 15782156615926092159U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9812148913932011655U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4737919734590584193U;
            aOrbiterJ = RotL64((aOrbiterJ * 2739737604370936959U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3415477403346468057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5922725868927615919U;
            aOrbiterF = RotL64((aOrbiterF * 12390148483052777871U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17435294951520465659U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 898812731947995389U;
            aOrbiterG = RotL64((aOrbiterG * 17248379279729365007U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 48U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 38U) + aOrbiterG) + RotL64(aOrbiterJ, 39U)) + aNonceWordG);
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterI, 14U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterH, 37U)) + aNonceWordA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 58U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15439U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneA[((aIndex + 13180U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12697U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13920U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneC[((aIndex + 11866U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 58U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 18255347001097480328U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 13679246790311505735U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 19U)) + 10565839529765027116U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 14327172566224769901U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 16239024612038195174U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 13800012174212131890U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 46U)) + 13900288860157577583U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererG + RotL64(aScatter, 35U)) + 4144386119777112740U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 51U)) + 3154558262670631372U) + aNonceWordO;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 43U)) + 7456728543137614001U) + aNonceWordD;
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 11709519851158935384U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15607438907832240304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9276575329661725624U;
            aOrbiterG = RotL64((aOrbiterG * 8879744070762412745U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6459435969129449226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6442382118416542275U;
            aOrbiterA = RotL64((aOrbiterA * 2921027306686588233U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12117432107282150865U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6831279293184793243U;
            aOrbiterE = RotL64((aOrbiterE * 2435360641135249073U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9520022957804572889U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8322178689474588679U;
            aOrbiterI = RotL64((aOrbiterI * 1627707191467537115U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4162401591586869316U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8994015844714895961U;
            aOrbiterF = RotL64((aOrbiterF * 15421910378057951895U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10038095909727959633U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17756404450592957616U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14255952184627347295U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3379089265413427719U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11341713098678108441U;
            aOrbiterJ = RotL64((aOrbiterJ * 2500587373161411961U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4030296130743454165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6332387792111212064U;
            aOrbiterC = RotL64((aOrbiterC * 16490982218150897861U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14893209417387662133U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9265457389326311687U;
            aOrbiterK = RotL64((aOrbiterK * 9778404505547862689U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13496086915199406901U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14576555328710787951U;
            aOrbiterB = RotL64((aOrbiterB * 13155395071667672943U), 37U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 11482324648071976743U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18255347001097480328U;
            aOrbiterH = RotL64((aOrbiterH * 10918514878283385643U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 56U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 12U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterG, 27U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterF, 44U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19931U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((aIndex + 18526U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 18925U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17122U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneD[((aIndex + 17358U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 21U)) + 8367680518550579791U) + aNonceWordD;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 11491674725611181241U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + 16673861720782164214U) + aNonceWordK;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 57U)) + 9786610124108350855U) + aNonceWordB;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 5745080601557577637U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 46U)) + 1959402215131684684U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 23U)) + 6121650036079196522U) + aNonceWordI;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 37U)) + 12016309761037342392U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 41U)) + 5986936646177049603U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 48U)) + 1000367700904043468U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 17425288243569101032U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4856917474950325209U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16312111093223166419U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 11046477664487805241U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 456110002032422270U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11393724374787795662U;
            aOrbiterB = RotL64((aOrbiterB * 1176984359123668389U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8378176867715697176U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8086186452345234815U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8470349167474173245U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2528229938740192694U;
            aOrbiterK = RotL64((aOrbiterK * 8717790851266520943U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13247168811545753141U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8745293957516815264U;
            aOrbiterG = RotL64((aOrbiterG * 14270617180621072619U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6165915500564961987U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12015407798844173213U;
            aOrbiterA = RotL64((aOrbiterA * 3913451986559154153U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 545006684939922156U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16366753936267185001U;
            aOrbiterF = RotL64((aOrbiterF * 6495185976430013201U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3097605623436091728U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15950167830259022926U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4415538963984293323U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8356327899232213426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10183421678251169945U;
            aOrbiterE = RotL64((aOrbiterE * 9474380650337109299U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16327340177970834683U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7086901180933495535U;
            aOrbiterI = RotL64((aOrbiterI * 1276521829484494857U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13421211370092080006U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8367680518550579791U;
            aOrbiterJ = RotL64((aOrbiterJ * 12256662446176946163U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 48U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 12U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 46U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25050U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 26600U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23079U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24752U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23194U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21943U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 42U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 48U)) + 4259993311776766595U;
            aOrbiterK = (aWandererC + RotL64(aCross, 53U)) + 2857813330021126753U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 1345396841329442896U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 19U)) + 320992148982301024U;
            aOrbiterG = (aWandererA + RotL64(aCross, 21U)) + 5619109532065293074U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 10380157329426706345U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 51U)) + 12449831150625409695U) + aNonceWordM;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 37U)) + 7847096607042268396U) + aNonceWordI;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 35U)) + 11707184096803214678U) + aNonceWordA;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 9893643746186827088U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aCross, 28U)) + 333687403830908774U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13837360705077441580U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4367119682175710689U;
            aOrbiterA = RotL64((aOrbiterA * 10295744669174603401U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1193493435041306784U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15062951612027370606U;
            aOrbiterI = RotL64((aOrbiterI * 2509383510565136549U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16000173839235429105U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15294482444605409961U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 1031800997944302665U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5720749055549773527U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17248674962996093668U;
            aOrbiterC = RotL64((aOrbiterC * 15730637462755795591U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16956840483882091059U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9637715107943515594U;
            aOrbiterJ = RotL64((aOrbiterJ * 8878362378343603463U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7147495779349862274U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7508890985889484275U;
            aOrbiterB = RotL64((aOrbiterB * 17728368447504622035U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 4407738164617959366U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 17027017782352660454U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 417183060881259295U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3174658601748235285U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9779053567370714831U;
            aOrbiterF = RotL64((aOrbiterF * 6383245776181968033U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16256981360027888091U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12778335633397105924U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10821225965811763659U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13985909343937844583U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14307218309393008729U;
            aOrbiterG = RotL64((aOrbiterG * 12053366452617039877U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15549857305890093491U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4259993311776766595U;
            aOrbiterH = RotL64((aOrbiterH * 13703695714360435719U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 24U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 10U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterJ, 48U)) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + aNonceWordG) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30137U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 28263U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30359U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30088U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28623U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 42U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 380024772508948442U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 35U)) + 7649029098162567210U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 5329304598870421851U) + aPhaseEOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 4U)) + RotL64(aCarry, 35U)) + 12306118665045151326U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 37U)) + 960751560457324256U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 57U)) + 3244070254386191876U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 39U)) + 15733408571609521746U) + aNonceWordK;
            aOrbiterK = (aWandererG + RotL64(aCross, 43U)) + 17623448932647018544U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 11U)) + 8787759896149035829U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 26U)) + 14741681792348288162U) + aNonceWordE;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 53U)) + 8801731213568307302U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9872248187499779222U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15407371518644528235U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1245102406469471673U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4242060317152943062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9942784962409917541U;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7296348796484458631U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15061417216070157797U;
            aOrbiterK = RotL64((aOrbiterK * 10349554676953256231U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3233185810644297433U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9241229457641024287U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2728237515724597517U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8464051359381554575U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3307872165699029375U;
            aOrbiterB = RotL64((aOrbiterB * 4859663401033023433U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5482617843966711997U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4442149210462943872U;
            aOrbiterD = RotL64((aOrbiterD * 8979352218576515647U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10591636597580147381U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14925122230279312217U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 15038171961638724013U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9772367878232735350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15800661165607190092U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 10493976952980533589U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1571665862499272194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3162847040693387901U;
            aOrbiterC = RotL64((aOrbiterC * 2747235335326991399U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4868791925868749848U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13134549226315884613U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3551955270718495869U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7830447320021657240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 380024772508948442U;
            aOrbiterG = RotL64((aOrbiterG * 5143324968958616357U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 3U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterK, 48U));
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 51U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Golf_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF330FB4D62530745ULL + 0x8C4B139F86977419ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCB015699C705DF25ULL + 0xB001873035B3835AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB4124CCFE72AD843ULL + 0xF6DD3F791A7DEA7CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBC067DB7932641E3ULL + 0xCAE910E3CA090951ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCF66EC645960FDC1ULL + 0xE67F2E669AC853C0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEEA3D188243AB581ULL + 0xF85EAFC8AC9040F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFA09EB5C72915293ULL + 0xAD3010CAC2713603ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3F8F2516E565323ULL + 0xF14A6C1BBE679460ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x966DBB039B776771ULL + 0xF775EC7A1D886477ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCC5D67726B9B140FULL + 0x9184DE96FB861A4EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x82245D2CFBA0186BULL + 0xE678B594EEC878B2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAD50E561570FAF81ULL + 0xEE6D06AFEA6DAC9AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x846321CD19E14051ULL + 0xCA4DD2CB75B9F19CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x89B00E722ADC6D1DULL + 0x8DE280871B47AEB8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD603070A01504501ULL + 0xDD71A54E11F040BFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC8E5D83F27DA617BULL + 0xE76A5AFBD3808B65ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneC, aWorkLaneC, aInvestLaneC, aSnowLaneD, aWorkLaneD, aExpandLaneA, aInvestLaneB, aExpandLaneB, aSnowLaneB, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 520U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 4685U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 5167U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3204U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4620U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 2996U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 57U)) + 12849591986267890852U) + aPhaseFOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 8232614804696815750U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 29U)) + 12141567259210877281U) + aNonceWordM;
            aOrbiterA = ((aWandererC + RotL64(aCross, 22U)) + RotL64(aCarry, 41U)) + 2928641981037885644U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 37U)) + 980733350554783938U) + aNonceWordN;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 2683985177993350746U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 5U)) + 14532148403815527355U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 11U)) + 7736296629433884203U) + aNonceWordJ;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 18U)) + 10428437770166310549U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18327174144859461029U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6810436935194432002U;
            aOrbiterF = RotL64((aOrbiterF * 2715987179577753597U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 12606153309690753435U) + aNonceWordB;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 17123256945895150555U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 13469111258504672565U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9057777759026189541U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16478485918911194442U;
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18064460487552100483U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11477276762421684083U;
            aOrbiterA = RotL64((aOrbiterA * 3886501230380184395U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 18318375441973295081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13849305985380030986U;
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10240409420338313641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18360586077779529086U;
            aOrbiterD = RotL64((aOrbiterD * 18196875422391501927U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16801797158622424257U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4950305991208513887U;
            aOrbiterH = RotL64((aOrbiterH * 4437082499761416951U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15790878572843321918U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9808781805065559728U;
            aOrbiterI = RotL64((aOrbiterI * 9394280083159162953U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11974996650410830731U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4955004489435232515U;
            aOrbiterE = RotL64((aOrbiterE * 13301966529515483085U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 50U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterC, 6U)) + RotL64(aCarry, 47U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 40U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8029U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 9841U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10269U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 8179U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6547U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10038U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 5540U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 38U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 16451272412693907816U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + 10099485419723255462U) + aNonceWordI;
            aOrbiterE = (aWandererI + RotL64(aCross, 47U)) + 17668900099534923192U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 23U)) + 5497093724143181753U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 28U)) + 10354044773550071706U) + aNonceWordC;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 12728258851198019099U) + aNonceWordA;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 19U)) + 4144050505314242618U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 14133805325480076530U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 60U)) + 308863673210602899U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11741180130160569753U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12926863156769180448U;
            aOrbiterE = RotL64((aOrbiterE * 9726030996091054939U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 211920854786494259U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13234608842479411078U;
            aOrbiterJ = RotL64((aOrbiterJ * 2556747209733759467U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9164711974854618892U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6667377062281954219U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2603737166987437649U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4559040002406721850U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1749875480850675109U;
            aOrbiterF = RotL64((aOrbiterF * 15822640067349481089U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9555365165561936366U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18289733999504213574U;
            aOrbiterD = RotL64((aOrbiterD * 14156217554673229429U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8727162691639622461U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 291406782452963706U;
            aOrbiterC = RotL64((aOrbiterC * 8413500075082350243U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8294911802626492257U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15853578397277298548U;
            aOrbiterH = RotL64((aOrbiterH * 13256191781365357747U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11535146194939658681U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2177540476748375661U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15791341922007841029U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2705306323728084136U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17617871830709148043U;
            aOrbiterB = RotL64((aOrbiterB * 3449981219502809255U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + aNonceWordE);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 42U)) + aOrbiterG) + aNonceWordJ);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneD
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14791U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 12994U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12566U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13596U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 15754U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 1393781663398437180U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 5U)) + 17414594746688585273U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 2823888497053071250U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 51U)) + 17032631958617884859U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 29U)) + 15222697630461125019U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 41U)) + 15737414920751551780U) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 47U)) + 1357196111055783001U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 35U)) + 5315122321649251691U) + aNonceWordK;
            aOrbiterG = (aWandererG + RotL64(aIngress, 35U)) + 7893744655508595974U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16721939414324611738U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3444375866323610848U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10874157227815775661U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1825716513674511632U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15582066843912467318U;
            aOrbiterF = RotL64((aOrbiterF * 12765146555943757373U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15673590949193923915U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13887365046280406413U;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12730414371734709356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterK = RotL64((aOrbiterK * 8782547948627685451U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3089925954422937464U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7180179304678622530U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 16118051565147747413U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17030269962085008657U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6675917351883004046U;
            aOrbiterH = RotL64((aOrbiterH * 14134335325316949687U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12572022803491077491U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2801421744689267375U;
            aOrbiterG = RotL64((aOrbiterG * 315045745990934023U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4335148696780313055U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12526298573395110141U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 11276803410698178607U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 6984239833558496091U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12195433952105336808U;
            aOrbiterD = RotL64((aOrbiterD * 8642600547427664495U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 56U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterB, 34U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 52U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterF) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 44U) + aOrbiterD) + RotL64(aOrbiterA, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21720U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((aIndex + 19286U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17285U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20352U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21179U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 34U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 13854738573712660276U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 29U)) + 16835460633412286294U;
            aOrbiterK = (aWandererI + RotL64(aCross, 41U)) + 6785859293758091931U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 20U)) + 126317283127992659U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 7568963536291415413U) + aNonceWordO;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + 12294016745653004819U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 18269588932920281147U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 13U)) + 5872406424994751026U) + aNonceWordL;
            aOrbiterA = (aWandererH + RotL64(aIngress, 36U)) + 7764434758831474129U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4804168969415573371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 959601763507651280U;
            aOrbiterK = RotL64((aOrbiterK * 4647396592804833217U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9257644462479293048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14332699366894494579U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 10487012596470786004U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 612729229562321440U;
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7845523921295625315U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12742115479740024747U;
            aOrbiterE = RotL64((aOrbiterE * 15578543510683986421U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10294667720904610944U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14369711143154904567U;
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10918344717497681894U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18136794828308636957U;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14378638206724886404U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7077588188450008059U;
            aOrbiterG = RotL64((aOrbiterG * 485375960462924335U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8941870012851971932U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 15242087859620352399U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 4963002810455992839U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10395280254030875387U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6826595516076975980U;
            aOrbiterD = RotL64((aOrbiterD * 6198886240333178001U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 50U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + (((((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 48U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 44U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22697U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 22809U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 22188U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26973U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneC[((aIndex + 23097U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 2101601659597850213U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aCross, 57U)) + 2759794072560720121U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 36U)) + 9443562552411269339U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 10801360546699857975U) + aNonceWordP;
            aOrbiterA = (aWandererF + RotL64(aCross, 29U)) + 8020716394829332019U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 19U)) + 1021894212367773801U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 6U)) + RotL64(aCarry, 11U)) + 13346855534622490176U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 13U)) + 16359309548462953836U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aCross, 51U)) + 12642446944680783519U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8197424982767553380U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14346334610901859094U;
            aOrbiterJ = RotL64((aOrbiterJ * 16982899923227935679U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14171304260534233539U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 334531601308283605U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 5012968232749075075U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10707856298471572695U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 18364775750091914766U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 15735143943129143265U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8531394793118363836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15352876929406908882U;
            aOrbiterG = RotL64((aOrbiterG * 475199047053777179U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 567682016232278157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2068146551757663119U;
            aOrbiterI = RotL64((aOrbiterI * 1557877740957797555U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7776122587613256525U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16430938890724272256U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4540270493783593257U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11912000645055436094U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16800749242578741498U;
            aOrbiterK = RotL64((aOrbiterK * 17804584625034241737U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5909199180260499150U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5751089915336865588U;
            aOrbiterE = RotL64((aOrbiterE * 15376689503142397927U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3478216857728853008U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 18007567146937338241U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 6620498877303917855U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 10U)) + aOrbiterG) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterH, 53U));
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterG, 46U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30861U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 30660U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29789U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30788U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32600U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 36U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererA + RotL64(aPrevious, 51U)) + 9855743441035905047U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 8426286937143990276U) + aNonceWordM;
            aOrbiterB = (aWandererF + RotL64(aScatter, 47U)) + 7146752367170267002U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 12947210066678101726U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 11U)) + 15902163559925328965U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 8506649889346449469U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 18U)) + 8226286036430263052U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + 2703047093452420216U) + aNonceWordD;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 39U)) + 6769351326360139560U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9857025533281333281U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 238297452132277585U;
            aOrbiterB = RotL64((aOrbiterB * 12974709749856065985U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7203572312072908931U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12497027346166575632U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 1703586436725662307U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 473851890609048879U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 4635095143004754116U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17695676150967345793U;
            aOrbiterC = RotL64((aOrbiterC * 5780416541584439301U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15628965269863402796U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9190117464399730235U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17835918238346011086U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4398005402429282682U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10902589938246551273U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15124274429081385923U;
            aOrbiterJ = RotL64((aOrbiterJ * 13524180348258805367U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8747233520702236018U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5445611443463112371U;
            aOrbiterG = RotL64((aOrbiterG * 10294109295823410447U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16296005217836151910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6468336224317602364U;
            aOrbiterE = RotL64((aOrbiterE * 7369779919748367133U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 26U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 58U)) + aOrbiterG) + aNonceWordI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + aNonceWordG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + aNonceWordB);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterB, 10U)) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Golf_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC950EF8A6DDE68C1ULL + 0x96B458264BFEA6E0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA89438ABA4F40281ULL + 0x9E97FE8BE88F8E49ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEC2B15EA7873176DULL + 0xCE1909AAB92DED8EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBEF4B43A561A0E25ULL + 0x939910E296EB78E9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA139F86033210AADULL + 0xB8C75E807F2CCE76ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBC19E9DCF9896491ULL + 0xC3664328B278775FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC86ACA87AADBBE0DULL + 0xE762A590D799C3ABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA7B1A0DEA912BF0FULL + 0xEB2193BB57821172ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x876DB019BC84EF81ULL + 0xD76D993B0D833737ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEC90907E679875D5ULL + 0xFDA673D0FD1D6487ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xFAEB59A914F119B9ULL + 0xD1641629C1A631D6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9B734F312CD818ADULL + 0xAC9E342F5483B5B6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE985F361D279C8C9ULL + 0x92587170F7CE9567ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD21BD089183DE143ULL + 0xB381398201FAF06BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x95445BF840C4B021ULL + 0xB58AF3DEAE3E4713ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC6C5ECD924268ED5ULL + 0x94A8A5F48A708E59ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aFireLaneB, aFireLaneD, aWorkLaneB, aFireLaneC, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2595U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneB[((aIndex + 810U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4128U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3822U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3712U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2553U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (aWandererK + RotL64(aScatter, 13U)) + 15036852811491820366U;
            aOrbiterG = (aWandererH + RotL64(aCross, 58U)) + 305637140752898475U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 11948631574496129610U) + aNonceWordK;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 27U)) + 5321623592482991426U) + aPhaseHOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 4075270159062690728U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 15111580500356908928U) + aNonceWordD;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 51U)) + 7244150695504160363U) + aPhaseHOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5131563519577488862U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5881954992088651371U;
            aOrbiterB = RotL64((aOrbiterB * 2424421828597294607U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12780935808751507998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12599159643925470226U;
            aOrbiterG = RotL64((aOrbiterG * 17690046932587062701U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9466589929741834066U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6093158735705189789U;
            aOrbiterJ = RotL64((aOrbiterJ * 7453778295800853653U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 17461243886150519249U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15456408913739900718U;
            aOrbiterH = RotL64((aOrbiterH * 16093292401746174671U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11260643903290392780U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7870342756041882616U;
            aOrbiterI = RotL64((aOrbiterI * 2431528656086173419U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 134484990005888936U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10626896209992890407U;
            aOrbiterK = RotL64((aOrbiterK * 12034131076645285597U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 14031164129515132292U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1771835705730244212U;
            aOrbiterD = RotL64((aOrbiterD * 186981668443596623U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterD, 44U)) + aPhaseHWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + aNonceWordP) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7164U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((aIndex + 10040U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9822U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8716U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10102U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 8657U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10543U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 24U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 2101601659597850213U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 27U)) + 2759794072560720121U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 9443562552411269339U) + aNonceWordB;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 12U)) + 10801360546699857975U) + aPhaseHOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 8020716394829332019U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 1021894212367773801U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 41U)) + 13346855534622490176U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16359309548462953836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12642446944680783519U;
            aOrbiterC = RotL64((aOrbiterC * 12197935153255283321U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8197424982767553380U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14346334610901859094U;
            aOrbiterD = RotL64((aOrbiterD * 16982899923227935679U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14171304260534233539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 334531601308283605U;
            aOrbiterE = RotL64((aOrbiterE * 5012968232749075075U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10707856298471572695U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18364775750091914766U;
            aOrbiterG = RotL64((aOrbiterG * 15735143943129143265U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8531394793118363836U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15352876929406908882U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 475199047053777179U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 567682016232278157U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 2068146551757663119U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1557877740957797555U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7776122587613256525U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16430938890724272256U;
            aOrbiterA = RotL64((aOrbiterA * 4540270493783593257U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 34U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aScatter, 12U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 10968U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 12577U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11159U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13693U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((aIndex + 13002U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 28U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererI + RotL64(aCross, 41U)) + 16200278595895089008U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 21U)) + 1029614154810465897U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 57U)) + 7129562468705441295U) + aNonceWordA;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + 14388903902433951274U) + aNonceWordK;
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 39U)) + 1013568949315967455U) + aPhaseHOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 3128823373497815651U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 14525694606889470589U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14443983602196782887U) + aNonceWordF;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 12244220415328641190U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 15052949098014803181U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10477159225338766614U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2842870123078131566U;
            aOrbiterE = RotL64((aOrbiterE * 11522265477555954071U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 8621138818955849917U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5038396344400303181U;
            aOrbiterH = RotL64((aOrbiterH * 14636756322207385447U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2768613802894372496U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2027754864051410015U;
            aOrbiterA = RotL64((aOrbiterA * 2461322540050569287U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2848088309172056399U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15017458513904884651U;
            aOrbiterB = RotL64((aOrbiterB * 9926904679902843055U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9079797279596336139U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15424866642305110811U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12912331089970158845U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13751764050290602740U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7694557131324740282U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14980807690491467023U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aNonceWordJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterK, 21U)) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + aNonceWordL) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 37U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 50U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16582U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 18082U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 21810U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17087U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21079U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 17454559218352016650U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 8005709669325164803U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 13393741948412816357U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 43U)) + 3665865624348875553U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 28U)) + 8334142570031883436U) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 57U)) + 17226066128706139657U) + aNonceWordN;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 3319093033121522613U) + aPhaseHOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6657535603401588798U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5469746182326331147U;
            aOrbiterK = RotL64((aOrbiterK * 11315450342347794329U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17846791786050221418U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15939541003714896288U;
            aOrbiterJ = RotL64((aOrbiterJ * 1400351482213119809U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12076763190461077406U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3594038213596405284U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 10244002692575821495U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 8301291631324464622U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8460406137668390582U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9117147929757711595U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7612394867020871200U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8525076134853103975U;
            aOrbiterE = RotL64((aOrbiterE * 5790440201072204659U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11929899088215090379U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7119509166360685726U;
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5081078459225240607U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17149991983909906705U;
            aOrbiterC = RotL64((aOrbiterC * 950223374568067343U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordP) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterK, 60U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aNonceWordI) + aPhaseHWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 50U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24241U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 23030U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 22489U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26688U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26533U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 35U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 5U)) + 7825479804710770560U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 19U)) + 5298124167101358123U) + aNonceWordG;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 17774541024369233726U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 13U)) + 7679371833537454082U;
            aOrbiterE = ((((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 5385914900748772224U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 50U)) + RotL64(aCarry, 41U)) + 3879781930908486531U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 57U)) + 659110346638873236U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 10749021728538539749U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3631252455767429457U;
            aOrbiterD = RotL64((aOrbiterD * 8552825360915119613U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 2271978810960685021U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5963558780692551176U;
            aOrbiterE = RotL64((aOrbiterE * 4772055335210781149U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 974909966119198104U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9296998242911152296U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2245318466901521959U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13391076374843288568U;
            aOrbiterH = RotL64((aOrbiterH * 18094558036982107419U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6184487746594236737U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1563385912137291418U;
            aOrbiterK = RotL64((aOrbiterK * 4805455299959232321U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1744840092006498629U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2100927276837188416U;
            aOrbiterG = RotL64((aOrbiterG * 3541788262067077997U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9998911862807246338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12239948725635220096U;
            aOrbiterA = RotL64((aOrbiterA * 7098620484129489129U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 28U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aNonceWordE) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 36U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aPhaseHWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aNonceWordL);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29671U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 29867U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 27751U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29365U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28251U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 47U)) + 11410829607777684449U) + aNonceWordO;
            aOrbiterI = (aWandererD + RotL64(aScatter, 53U)) + 7502698839700975347U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 13267685058252106173U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 238242706996630625U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 21U)) + 8184695499511454281U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 3U)) + 12767823220461985403U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 41U)) + 12293198423143850330U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11149495229952495939U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7556992689338382800U;
            aOrbiterD = RotL64((aOrbiterD * 18232398462716803063U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3431338808774134649U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16863099140844995099U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 752376661101787919U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17872458049880677604U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16760153457252546974U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3115544493537438408U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4359882942759752958U;
            aOrbiterI = RotL64((aOrbiterI * 561477566995575801U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13387113067202396536U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12955690074544490161U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12449941770827974511U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15614054443728226807U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1939441328066616114U;
            aOrbiterG = RotL64((aOrbiterG * 4484917074808974359U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4599016263007782537U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9962305629016158048U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1496184427500037279U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 21U));
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 52U) + aOrbiterJ) + RotL64(aOrbiterK, 60U)) + aNonceWordL) + aPhaseHWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Golf_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1061U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 343U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 696U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1919U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 17668251151213543491U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 56U)) + 16101602509895104517U;
            aOrbiterH = (aWandererI + RotL64(aCross, 35U)) + 9083915270773304935U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 51U)) + 12810720730318214811U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 18113428002071925621U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 1582208899354109878U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 3U)) + 4180688104819188154U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + 8954598189262820611U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 60U)) + 15360094153175355879U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8383954114668216260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15626783326234049197U;
            aOrbiterH = RotL64((aOrbiterH * 15058420415480073793U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10609978564404958066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17656516608997517984U;
            aOrbiterE = RotL64((aOrbiterE * 4590620354119899777U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 760077259110786536U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3597338735888033063U;
            aOrbiterA = RotL64((aOrbiterA * 6548831472863517621U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4431777844935985157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10710423172154671296U;
            aOrbiterG = RotL64((aOrbiterG * 16267496318491473315U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10240882795242085185U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7826053487019825891U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15053729937684375907U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9418883403715727353U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11507423614799075545U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16189463984557044693U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11545217316421066655U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 617921402135485341U;
            aOrbiterD = RotL64((aOrbiterD * 8182920764965471653U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14456933220749921009U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7990243583564535387U;
            aOrbiterI = RotL64((aOrbiterI * 5994900368027985469U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14023633125757654751U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11319146808574958827U;
            aOrbiterF = RotL64((aOrbiterF * 13676159969338309307U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 51U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 6U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3795U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 5100U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4992U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4739U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 14823268998003220191U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 15295237288788213847U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 43U)) + 16434853402001133899U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 34U)) + 7555911304407871631U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 13U)) + 14977248264994834620U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 19U)) + 9707764144919392380U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + 1277304385464681529U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 38U)) + RotL64(aCarry, 35U)) + 3089786220465849395U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 3700503853358695085U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3240054112993517371U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16897532076915366859U;
            aOrbiterK = RotL64((aOrbiterK * 4120874717534309035U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 18167359289798364307U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8870819278575769863U;
            aOrbiterB = RotL64((aOrbiterB * 9334066154398059075U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15363069206212330251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5357144808788707522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2910681277417754860U;
            aOrbiterI = RotL64((aOrbiterI * 13170868582159347059U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9824408699018165151U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 368370224788793300U;
            aOrbiterD = RotL64((aOrbiterD * 14358982366258729959U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7095398304588825115U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11418879758164313554U;
            aOrbiterE = RotL64((aOrbiterE * 5983520332639771791U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2171599720681913272U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17593730219647495033U;
            aOrbiterH = RotL64((aOrbiterH * 12926053208918563087U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17755947635188715523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14565740605227022106U;
            aOrbiterF = RotL64((aOrbiterF * 15866418354612945335U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14538017880915584414U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6174566474851449123U;
            aOrbiterG = RotL64((aOrbiterG * 179569008593475683U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterK, 24U));
            aWandererF = aWandererF + ((RotL64(aIngress, 54U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aPhaseAWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 30U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6437U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadB[((aIndex + 6376U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7147U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5709U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6456U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 58U)) + 6318740973868639425U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 23U)) + 5487840061430920881U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 10258706763248072672U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 18356875269730338208U) + aPhaseAOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 18U)) + 12883160282903147010U;
            aOrbiterE = (aWandererI + RotL64(aCross, 53U)) + 1010140474942697730U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 27U)) + 17733939421700898293U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 13693055887924981201U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 39U)) + 14574732452793385269U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10832873941223609012U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8212600587135328040U;
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5312744319781971178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3693249147883790810U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 18365859989736602556U;
            aOrbiterC = RotL64((aOrbiterC * 3348463719324104997U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10645056678337549771U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1175668356822251045U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6579675292775345579U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13556844570541823717U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4790355739411849736U;
            aOrbiterA = RotL64((aOrbiterA * 4083544011788850307U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14905575502272644116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterI = RotL64((aOrbiterI * 2356386971503880047U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10161614295718414869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13413914082651612468U;
            aOrbiterD = RotL64((aOrbiterD * 16224039093981079491U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6072693130156927774U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4333656233793103787U;
            aOrbiterG = RotL64((aOrbiterG * 9374745547133955709U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17209776289202130250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11752001118070361543U;
            aOrbiterJ = RotL64((aOrbiterJ * 4416523594812872339U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 28U));
            aWandererB = aWandererB + (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 6U)) + aOrbiterE) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10743U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 10262U)) & W_KEY1], 44U));
            aIngress ^= (RotL64(mSource[((aIndex + 10202U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 8872U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9483U)) & W_KEY1], 34U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8834U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aIngress, 57U)) + 3238389262925516513U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 12381787182611386995U;
            aOrbiterI = (aWandererI + RotL64(aCross, 47U)) + 7883885539305181549U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 18U)) + 1185413044597727092U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 51U)) + 15219353497204773135U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 7533774715626734082U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 2599930450937763464U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 43U)) + 16074720663961214284U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 34U)) + 15483613196360051221U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9396557867081376268U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9668459976852660245U;
            aOrbiterI = RotL64((aOrbiterI * 11748505665890567063U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9037269914643207212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16936742640861088240U;
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16481274825758546398U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13608921517203544108U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16930740723286214636U;
            aOrbiterE = RotL64((aOrbiterE * 2605108503821980865U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 902242902582149908U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1510861213079342977U;
            aOrbiterA = RotL64((aOrbiterA * 3309753895727400707U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7116243600304980310U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6631412278359709602U;
            aOrbiterG = RotL64((aOrbiterG * 11452627691392637463U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9246698682265275165U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8594373032014031450U;
            aOrbiterB = RotL64((aOrbiterB * 2550138341089957033U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15912837963877821048U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11404583513022627609U;
            aOrbiterH = RotL64((aOrbiterH * 17715204726760125357U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17295214920690244319U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 18315664494984189344U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17398893532076312945U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 21U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aPhaseBWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterG, 48U)) + aPhaseBWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 40U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12609U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 13636U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12467U)) & W_KEY1], 29U) ^ RotL64(mSource[((aIndex + 11304U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12718U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11129U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneA[((aIndex + 11109U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 48U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 18180797995100240808U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 10U)) + RotL64(aCarry, 29U)) + 6585906608223552885U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 57U)) + 14088708930575939855U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + 468974153311516044U) + aPhaseBOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 12481951025619894110U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 18U)) + 17227987923860711763U;
            aOrbiterG = (aWandererF + RotL64(aCross, 23U)) + 4373962756657477139U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 37U)) + 2077576476565420951U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 43U)) + 17435011300234663764U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4118039398293246896U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 13724716599855216683U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17556333902751079677U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12391461204689596339U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9900605191533799627U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13553565332531046301U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 972946858824366125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15442851427306771601U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7303586227288294037U;
            aOrbiterF = RotL64((aOrbiterF * 15406402525021428799U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12650358753454105119U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1483710933373510492U;
            aOrbiterI = RotL64((aOrbiterI * 6531763256577221891U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18065810162229740788U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11311677121338794007U;
            aOrbiterE = RotL64((aOrbiterE * 15116367961682119467U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2355285311890287611U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1287783821903407734U;
            aOrbiterH = RotL64((aOrbiterH * 8054011680932255985U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9282654686791135654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15488608017745542551U;
            aOrbiterB = RotL64((aOrbiterB * 7858866274035085123U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13296835576073421802U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7127700236018338741U;
            aOrbiterD = RotL64((aOrbiterD * 11246173563106014149U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 34U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aPhaseBWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 48U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15322U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 15603U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15587U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14875U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13843U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16145U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15952U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 36U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 13174219512651137892U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 23U)) + 2715455762789269341U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 18U)) + 1338018183235594313U;
            aOrbiterG = (aWandererF + RotL64(aCross, 27U)) + 16566866551729552930U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 6901845297307236726U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 35U)) + 2476078302049201718U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 15531109473927052260U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 3U)) + 4087849380858572351U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 60U)) + 5167830630098599644U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7275995452428627217U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14794340370010024117U;
            aOrbiterB = RotL64((aOrbiterB * 8779497557416568379U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8509217403041662849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2321522025240806996U;
            aOrbiterJ = RotL64((aOrbiterJ * 113568101672878697U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5676672952755594051U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2304681269233504384U;
            aOrbiterI = RotL64((aOrbiterI * 15731441084605554497U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8383399721062437300U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterC = RotL64((aOrbiterC * 1648761328771932069U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13602604532551684210U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12725687663616352843U;
            aOrbiterA = RotL64((aOrbiterA * 4684699861686199753U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5831790822416009806U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4535048543735457407U;
            aOrbiterK = RotL64((aOrbiterK * 12076777878870257053U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 10617608605149381858U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5244225377862618630U;
            aOrbiterH = RotL64((aOrbiterH * 15307177251167023999U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 18229989093139888456U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9728120630096192811U;
            aOrbiterG = RotL64((aOrbiterG * 16052574428163231023U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1312233443099767304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8043115602160128619U;
            aOrbiterE = RotL64((aOrbiterE * 9365756845731616963U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 54U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterB, 46U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 14U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 19100U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 18852U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 18709U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 17071U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 19026U)) & W_KEY1], 60U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18454U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17255U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 29U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aIngress, 58U)) + 252059974543142812U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 11690823093681457368U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 51U)) + 13282189752890971123U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 39U)) + 9507416294305708435U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 14053038174390776539U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 11U)) + 14605253312318725009U;
            aOrbiterF = (aWandererA + RotL64(aCross, 30U)) + 18138286582677863671U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 8530091235978489988U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + 14381731677571170073U) + aPhaseCOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13316413456378978456U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3910529530149320706U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16000139333493588429U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6302070286831566901U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12324134652758551396U;
            aOrbiterG = RotL64((aOrbiterG * 17136438281540250165U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4773478557638475048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4031153435446078944U;
            aOrbiterJ = RotL64((aOrbiterJ * 3876928995240982769U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3114794895962903899U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3552936509969106796U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16823186892738820299U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5828754613946145627U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17985241114076114558U;
            aOrbiterD = RotL64((aOrbiterD * 1986669631395606833U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11319331046368072261U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6104267020171882160U;
            aOrbiterC = RotL64((aOrbiterC * 12525117969211576177U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7662668379725735125U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6583034411403600735U;
            aOrbiterE = RotL64((aOrbiterE * 262095656452193889U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5569865728026310280U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 4176065898330374039U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11305749530796963967U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13677146592276526676U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2734371113158117596U;
            aOrbiterA = RotL64((aOrbiterA * 13146444882662731975U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 56U)) + aOrbiterD);
            aWandererI = aWandererI + ((((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterF, 12U));
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21756U)) & S_BLOCK1], 60U) ^ RotL64(mSource[((aIndex + 20261U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21648U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21441U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20122U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19571U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20021U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 19253U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 19U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 27U)) + 12849591986267890852U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 12U)) + RotL64(aCarry, 51U)) + 8232614804696815750U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 39U)) + 12141567259210877281U) + aPhaseCOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 57U)) + 2928641981037885644U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 980733350554783938U;
            aOrbiterE = (aWandererB + RotL64(aCross, 44U)) + 2683985177993350746U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + 14532148403815527355U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 7736296629433884203U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 23U)) + 10428437770166310549U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 18327174144859461029U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6810436935194432002U;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12606153309690753435U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17123256945895150555U;
            aOrbiterF = RotL64((aOrbiterF * 13469111258504672565U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9057777759026189541U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16478485918911194442U;
            aOrbiterA = RotL64((aOrbiterA * 11054247078884894131U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18064460487552100483U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11477276762421684083U;
            aOrbiterD = RotL64((aOrbiterD * 3886501230380184395U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18318375441973295081U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13849305985380030986U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12962140243967824959U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10240409420338313641U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 18360586077779529086U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18196875422391501927U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16801797158622424257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4950305991208513887U;
            aOrbiterI = RotL64((aOrbiterI * 4437082499761416951U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15790878572843321918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9808781805065559728U;
            aOrbiterH = RotL64((aOrbiterH * 9394280083159162953U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11974996650410830731U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4955004489435232515U;
            aOrbiterE = RotL64((aOrbiterE * 13301966529515483085U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 6U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 34U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 18U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 52U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23693U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[((aIndex + 22579U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23958U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((aIndex + 24109U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24553U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22474U)) & S_BLOCK1], 50U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22035U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 22039U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 41U)) + 14624277139785904404U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 6966977309498165611U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 13U)) + 205536824352530761U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 16629575265808255692U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 47U)) + 596881340147972746U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 37U)) + 11944412799107412650U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 27U)) + 4615021315668210206U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 23U)) + 8497630055977606216U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 56U)) + 11131601107309336885U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5935883479805510099U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15629346719765798174U;
            aOrbiterD = RotL64((aOrbiterD * 8535523790685945275U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5279128339113651273U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16778365912440331821U;
            aOrbiterJ = RotL64((aOrbiterJ * 705421028266789241U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16003052937645491524U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6723226158737614764U;
            aOrbiterK = RotL64((aOrbiterK * 16690657664909260573U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9785784358981219543U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10055457337292292710U;
            aOrbiterB = RotL64((aOrbiterB * 17919129940751761111U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11779163108592974175U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1177999477942202687U;
            aOrbiterE = RotL64((aOrbiterE * 13475069421684114643U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9190694445141492214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15605342360346353457U;
            aOrbiterG = RotL64((aOrbiterG * 14547769706392595647U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14877565450677523492U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1074095623308025684U;
            aOrbiterI = RotL64((aOrbiterI * 7884068939436891093U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12803174154216941583U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8813356463693637033U;
            aOrbiterA = RotL64((aOrbiterA * 4898237214617563167U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6063909634038581414U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15112191502834052566U;
            aOrbiterC = RotL64((aOrbiterC * 6780741782103553485U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterD, 12U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 34U));
            aWandererD = aWandererD + (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererH, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27029U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 27075U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25442U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 25881U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26088U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24772U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25853U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 26311U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 7075016829833562104U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 51U)) + 8783765886115517036U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 37U)) + 2996723892384565829U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 47U)) + 9494134707342189476U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 5052642981395679904U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 28U)) + 8766787055127962238U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 11U)) + 4467211954388738079U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 8030255604633658608U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 23U)) + 16962408063455702251U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3768222186567699076U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14930990410207899871U;
            aOrbiterD = RotL64((aOrbiterD * 10930005786146268241U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14179761938395502502U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1879084742719898108U;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5535012408925981515U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12792553516710295939U;
            aOrbiterF = RotL64((aOrbiterF * 8577530993755159329U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8979253163346099252U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5559189896063990740U;
            aOrbiterK = RotL64((aOrbiterK * 8832485423727331621U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13937564337299044079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2393376759689394948U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12647519563697356479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10946871249960389549U;
            aOrbiterC = RotL64((aOrbiterC * 6272580371881237173U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13376798695582123147U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10958115913599631271U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18233981473003345217U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4283914227806672773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 910842005516235816U;
            aOrbiterJ = RotL64((aOrbiterJ * 6722229871617873429U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1509644316619370324U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 165987596716078174U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13600064054240185123U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 48U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterH, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 6U));
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 39U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + ((RotL64(aIngress, 38U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29243U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 27998U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27721U)) & W_KEY1], 20U) ^ RotL64(aFireLaneC[((aIndex + 27481U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28690U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27935U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28487U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((aIndex + 29265U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 42U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 7896237440058555694U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 35U)) + 11870529476037558635U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 19U)) + 9158983227801569448U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 4710172270996950329U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 23U)) + 14634482800356647630U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 27U)) + 8822207952170610891U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 11U)) + 13755891414028982553U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 57U)) + 4555293067488040719U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 6U)) + 2816805148093762081U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2122631477965135190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7102471666524164715U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17274623547879474204U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5443572270546181789U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 938587316977094680U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18258015823797023523U;
            aOrbiterG = RotL64((aOrbiterG * 6068819567674605919U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5809987756043471595U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5083075160112581620U;
            aOrbiterD = RotL64((aOrbiterD * 3313957222154937503U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5960021727750946496U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5967477320950630150U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 330964768256424655U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6578428711689296132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5601728218197771276U;
            aOrbiterE = RotL64((aOrbiterE * 9552559022315971847U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7923809409017855241U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16479366540906497019U;
            aOrbiterF = RotL64((aOrbiterF * 7118578387798460919U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17000467091738009736U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6801634573655508028U;
            aOrbiterK = RotL64((aOrbiterK * 10584635770060137089U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 123668445682719574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14462802805503986316U;
            aOrbiterH = RotL64((aOrbiterH * 12398236364304875941U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 18U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterG) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 28U)) + aOrbiterG) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32193U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32274U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31025U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31313U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32326U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 32354U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 42U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 11U)) + 9751314027302668907U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 12175450995523107056U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 19U)) + 17519694958730119552U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 42U)) + 9093525527925682263U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 3713831321786810138U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 10108355209191835040U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 12956307447311314768U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 51U)) + 1904298513945877359U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 4U)) + 4658049993308574460U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9826333658248851902U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12058666914724365134U;
            aOrbiterJ = RotL64((aOrbiterJ * 964233873188373939U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2516574707110528099U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13335308331049750235U;
            aOrbiterB = RotL64((aOrbiterB * 5880227828760598587U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8230749255538495304U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16536559486797811486U;
            aOrbiterH = RotL64((aOrbiterH * 7097036838156464969U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12387639130570188998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8459259798142872020U;
            aOrbiterD = RotL64((aOrbiterD * 8001346480955847013U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16083784052002800300U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1957284290736468379U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5046501301740813065U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7349538179311335863U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16395170077006105258U;
            aOrbiterK = RotL64((aOrbiterK * 4230485452156662763U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3317652065873784068U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterI = RotL64((aOrbiterI * 9789270651974719183U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5568525912112200094U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9334250662962319598U;
            aOrbiterG = RotL64((aOrbiterG * 5034887614541768961U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5641394627075994165U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 4U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 36U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterF) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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

void TwistExpander_Golf_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneC, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3699U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 3069U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 1822U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4299U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 4630U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 30U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 3448371607470865612U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 51U)) + 3743742913651580573U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 13069491287948807280U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 57U)) + 16872779275586545632U) + aPhaseEOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 17945792656755062795U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 41U)) + 18199747196793731853U;
            aOrbiterC = (aWandererA + RotL64(aCross, 3U)) + 15953311878379809513U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 941268763494588338U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10090221530365796809U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14035236086292997613U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8335698093307607001U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6147498804734306100U;
            aOrbiterH = RotL64((aOrbiterH * 6904444049941211327U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5980246079567570090U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4152167624425912978U;
            aOrbiterE = RotL64((aOrbiterE * 10019421651535123573U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 14990418790239735916U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3418668387496597219U;
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4206650904177199425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3905470780938996069U;
            aOrbiterK = RotL64((aOrbiterK * 16030122739273137005U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9968672788233080924U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterB = RotL64((aOrbiterB * 2615726693066300065U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17751667243048041383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2414054413585296027U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1049512574773201893U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterF, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterG, 60U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10909U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((aIndex + 10588U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 8946U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9109U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10360U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aScatter, 57U)) + 7948891781097675369U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 13928362874228230226U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 21U)) + 10776180542602258926U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 35U)) + 5735115172149470447U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aPrevious, 47U)) + 5353591822981766987U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 14U)) + RotL64(aCarry, 41U)) + 562301708107268570U) + aPhaseEOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 10467810247578364868U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14541630141152308564U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2350076897065139429U;
            aOrbiterE = RotL64((aOrbiterE * 12222554362482034393U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17519109078651162228U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6061035173339902910U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10021905773432907835U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15654836633731000065U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13723521735153718904U;
            aOrbiterJ = RotL64((aOrbiterJ * 14459516479283070563U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2849680038315532197U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterG = RotL64((aOrbiterG * 10984689101753586739U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7671010488872356142U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11485114338165600777U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4162584865462407791U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8759060657343458985U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11009137869375286581U;
            aOrbiterF = RotL64((aOrbiterF * 8741417343929809115U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15792999392743144135U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6180808423175992479U;
            aOrbiterB = RotL64((aOrbiterB * 13681230339693676907U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 60U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 41U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15176U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 14319U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12845U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12260U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14959U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12810U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 12U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 29U)) + 3684295017013759987U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 54U)) + RotL64(aCarry, 27U)) + 6740408842457292881U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 41U)) + 4563975890702399441U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 797804144825287940U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 35U)) + 2763779540450101303U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 11U)) + 13211846164102089685U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 15214578447281401982U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13745208628754232427U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17358621225969190747U;
            aOrbiterK = RotL64((aOrbiterK * 5325024317338823061U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 779739369960480023U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4370963533701407813U;
            aOrbiterB = RotL64((aOrbiterB * 3123135216876641039U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6061333005507739975U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3589705340762734456U;
            aOrbiterE = RotL64((aOrbiterE * 16499293983611196967U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10607697666369230567U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9356757995305239271U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10945513661439954731U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10093033335903048138U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11037328061699834100U;
            aOrbiterJ = RotL64((aOrbiterJ * 11189760551792389605U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 558431161176115540U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17795680919453449358U;
            aOrbiterG = RotL64((aOrbiterG * 3910117359996283803U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6096779391116214109U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17594243286880690775U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12655610181937429915U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + ((((RotL64(aCross, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17835U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneC[((aIndex + 16524U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 20217U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18600U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17885U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21008U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 36U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 9471546960258473684U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 18050235435948942244U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 27U)) + 3005107102671544641U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 13U)) + 17898396434573801850U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 4U)) + 15071602525497771648U;
            aOrbiterI = (aWandererD + RotL64(aCross, 43U)) + 5780119462702672108U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 13301326224151025687U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18129323022260575961U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1199228670638790709U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1780426336211781025U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 1839199978088021020U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4999517042246790165U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4585813675677234577U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8788607633376516299U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15143903839930468749U;
            aOrbiterH = RotL64((aOrbiterH * 12735914889325422675U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16674732686428431869U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterF = RotL64((aOrbiterF * 18049755517524334107U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11204775359756474667U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2525984309543939465U;
            aOrbiterD = RotL64((aOrbiterD * 3988529812023791571U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4566345170476825512U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14876612901557406267U;
            aOrbiterC = RotL64((aOrbiterC * 9047956948845135339U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14926290877038883931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12710203178186614846U;
            aOrbiterE = RotL64((aOrbiterE * 14841163494801662515U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 56U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25219U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 24431U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23706U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24045U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25451U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 22589U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 6733949564325516029U;
            aOrbiterD = (aWandererD + RotL64(aCross, 13U)) + 7304098437143918796U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 3923949518391777800U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 39U)) + 14243591003388927124U) + aPhaseEOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 5U)) + 18329498724605410406U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 13118172167747037249U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 30U)) + 5272025143849174212U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16075917179214318424U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15263590648674658399U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9918239923411740337U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 13730046728289525921U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7703141464499623408U;
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1382279753822135359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2973369221699098292U;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11578274119583013219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3419411247737896674U;
            aOrbiterD = RotL64((aOrbiterD * 17814942652262802991U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2582783513078999303U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3959762790273529677U;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 465795011576934604U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17880826624185821135U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4445949147592860913U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10819659185349413173U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17298208553586835030U;
            aOrbiterH = RotL64((aOrbiterH * 1965860510614222093U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterH, 58U)) + aPhaseEWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30679U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 30817U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29672U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31638U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31209U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27870U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 4U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 17081642665820489793U;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 53U)) + 14468854040067229623U) + aPhaseEOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 2249450222593057429U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 37U)) + 14964389079511378664U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 17003491054252360650U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 12710882240582032588U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 13U)) + 9887078182156755359U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7665284531810584704U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7304284015511876717U;
            aOrbiterF = RotL64((aOrbiterF * 6193179739025093929U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5517927023543751734U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17704756310857362759U;
            aOrbiterE = RotL64((aOrbiterE * 15826832172923213591U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11347400363019508578U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11696395232760991243U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10875780291242873583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7808740614343437672U;
            aOrbiterC = RotL64((aOrbiterC * 8889516201913716283U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3145390996141902032U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16080636485642732615U;
            aOrbiterJ = RotL64((aOrbiterJ * 7445756373012217305U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3929263288176983844U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18210228766683996806U;
            aOrbiterA = RotL64((aOrbiterA * 13178080076505449091U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13948962323541421431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3037683309790156893U;
            aOrbiterH = RotL64((aOrbiterH * 13406672352222636739U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterE, 6U));
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Golf_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aExpandLaneC, aInvestLaneA, aSnowLaneB, aInvestLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneD, aWorkLaneC, aInvestLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2752U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 215U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 5182U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1714U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3838U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 861U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 12615321415808640429U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 15712784676459931207U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 11013335427004930046U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 35U)) + 8298733856304768806U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 30U)) + 6207732959150824216U;
            aOrbiterI = (aWandererA + RotL64(aCross, 3U)) + 9769864876127544038U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 53U)) + 10782181918651152563U;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 5790454015845620939U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 43U)) + 15606578025386733803U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 5522352539991175304U;
            aOrbiterF = (aWandererD + RotL64(aCross, 38U)) + 5993355818572869649U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10864534396947622047U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12090053126235913528U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14191181677234981396U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2258570108233924592U;
            aOrbiterG = RotL64((aOrbiterG * 8307541155393855209U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8448114811381534603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2702389315763499817U;
            aOrbiterH = RotL64((aOrbiterH * 6710443836432274393U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17202184076718780200U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 150549910056015002U;
            aOrbiterD = RotL64((aOrbiterD * 195034681254956335U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4910512055808124967U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4783477997418403079U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 861977492146512865U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13842899106208709771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7930112618036681468U;
            aOrbiterA = RotL64((aOrbiterA * 8609551859830858419U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8790107242863198659U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6882768826643279144U;
            aOrbiterE = RotL64((aOrbiterE * 13745521454063360763U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12136498871759890015U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8120456314755584336U;
            aOrbiterC = RotL64((aOrbiterC * 1830725195528043575U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14425711740351183016U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15907406009196323049U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8599371693260686839U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4878521420367891861U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1184672056055028939U;
            aOrbiterF = RotL64((aOrbiterF * 5963961755367831967U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10126736568567000180U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12615321415808640429U;
            aOrbiterB = RotL64((aOrbiterB * 11663715449073755137U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterF, 34U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 4U) + aOrbiterG) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 40U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 22U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5849U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 9797U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9960U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6565U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9754U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5809U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6812U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 41U)) + 5573188770530340913U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 1431772230889897111U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 57U)) + 4809192776429682319U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 5U)) + 5576603692574369341U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 2720143226007220386U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 26U)) + 17220328778565331629U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 39U)) + 9629485808442089423U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 19U)) + 1136998437010390983U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 11893390497814523841U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 1764986431917532370U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 52U)) + 1741014798007010376U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12221368453236547044U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7694538641172350430U;
            aOrbiterJ = RotL64((aOrbiterJ * 8439120733670016501U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17472344518811560603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9535358833412446771U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11192312491731312451U;
            aOrbiterF = RotL64((aOrbiterF * 17405609148475445743U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14850451970047190039U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11932493299452443256U;
            aOrbiterB = RotL64((aOrbiterB * 7964808728820467795U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5972619895614731870U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17174497535809891690U;
            aOrbiterA = RotL64((aOrbiterA * 15471084511364572533U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17412894714378898351U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14675615208706549810U;
            aOrbiterD = RotL64((aOrbiterD * 7864845089606499769U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16116792108013658523U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9702262005960966336U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 970452849653781703U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17337264966818542841U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7004462033775827275U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11943575980344402681U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17499850384482055438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1839357713256560566U;
            aOrbiterG = RotL64((aOrbiterG * 12943750650487416281U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8144238113917577524U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 888195876227325908U;
            aOrbiterC = RotL64((aOrbiterC * 7941506708630993709U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5081763359501717653U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5573188770530340913U;
            aOrbiterK = RotL64((aOrbiterK * 9699901099898698965U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterB, 18U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 56U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 37U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterI, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16310U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 13063U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 13831U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11175U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12500U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 43U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 41U)) + 3550722402315312207U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 16724184551669522754U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 5U)) + 981751330116773021U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 53U)) + 7891159229704944868U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 24U)) + 13618396711464799841U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 5969291018449003648U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 14595540413313640042U;
            aOrbiterE = (aWandererD + RotL64(aCross, 51U)) + 3287990436916111762U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 35U)) + 12534369400200483704U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 2277312067930392274U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 46U)) + 10026320559261334353U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11258082063135659551U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1445958517675746990U;
            aOrbiterJ = RotL64((aOrbiterJ * 10062265337488757971U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1011298251290970844U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6487834862470043744U;
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9966279022928268335U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 10285993486057704393U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15965714363201157535U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16005362468813966136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 223843444699390781U;
            aOrbiterG = RotL64((aOrbiterG * 665392038954573081U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18178876294968532775U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12490136112181806806U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16380841616662993709U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8775696166557913635U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16464340319444310842U;
            aOrbiterK = RotL64((aOrbiterK * 18111632334728200721U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6296039992673546227U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7152939277656436037U;
            aOrbiterF = RotL64((aOrbiterF * 15183918431501487319U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14066791413416223271U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterH = RotL64((aOrbiterH * 5891343232759075675U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12923870516588764609U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2509970166609982397U;
            aOrbiterB = RotL64((aOrbiterB * 10708677957633925007U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15155802288437422950U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15615656627428205711U;
            aOrbiterC = RotL64((aOrbiterC * 6199439196177598589U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17233751123865498186U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3550722402315312207U;
            aOrbiterD = RotL64((aOrbiterD * 2247546626523919155U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterF, 27U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterK, 24U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 46U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aExpandLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19401U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((aIndex + 19863U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16576U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18562U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 21011U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 4U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 47U)) + 6163290588946759209U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 20U)) + 7342672468560105447U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 3U)) + 11574563167017282321U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 53U)) + 2254820206194758964U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 5U)) + 1469783447473099498U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 13U)) + 14174828900676165088U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 10U)) + 16277954291890598132U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 14845750668693136766U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 150099699692047766U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 29U)) + 1200784917165131703U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 9469982764806754302U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10956702761701710182U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7915506894975487807U;
            aOrbiterF = RotL64((aOrbiterF * 8874108311712727983U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17335794183733623213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 557028996286989506U;
            aOrbiterI = RotL64((aOrbiterI * 3993359298602424281U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1597385667771002414U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterH = RotL64((aOrbiterH * 4626236858205178149U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 549770198518993876U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 756554555648070919U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16272320259614325355U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7298557532533152193U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3336802611342112013U;
            aOrbiterG = RotL64((aOrbiterG * 14679103452120080499U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2314938232094714365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12215066333571149153U;
            aOrbiterK = RotL64((aOrbiterK * 10747052773052630601U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7762752719356805046U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7556691736109752918U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13731245903412646404U;
            aOrbiterA = RotL64((aOrbiterA * 15581965016668635409U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5910925625723735162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16037704866415841869U;
            aOrbiterJ = RotL64((aOrbiterJ * 11628217027073824759U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12605882248192797360U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9579778913978981884U;
            aOrbiterC = RotL64((aOrbiterC * 5372577227818787957U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6063171520266734946U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6163290588946759209U;
            aOrbiterB = RotL64((aOrbiterB * 291843698316138251U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterD, 52U));
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterF, 58U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25885U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 22585U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25551U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25249U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((aIndex + 27023U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 35U)) + 4970414922752555648U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 13U)) + 9462756592787669327U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 29U)) + 3948790686662213095U;
            aOrbiterF = (aWandererE + RotL64(aCross, 47U)) + 14542857212241578311U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 58U)) + 3387479009827029547U;
            aOrbiterD = (aWandererA + RotL64(aCross, 41U)) + 1411421370057797877U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 11U)) + 16894451466895681236U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 12727136462290223542U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 4625389198191960525U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 19U)) + 3471881403786164913U;
            aOrbiterC = (aWandererG + RotL64(aCross, 56U)) + 6433115856048534831U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9825592965466157982U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1553125767261293088U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 411535191177308781U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9951616357109647617U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterD = RotL64((aOrbiterD * 14024961994986659187U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13419663264017317947U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4835055642466215566U;
            aOrbiterA = RotL64((aOrbiterA * 17898065852351759171U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14558747666410946768U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11910501376797343986U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15074100100781785300U;
            aOrbiterI = RotL64((aOrbiterI * 228976960937473851U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12415377930578091821U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14882039078390681802U;
            aOrbiterJ = RotL64((aOrbiterJ * 13855446647753150713U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8094338361713756895U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5478280604704108822U;
            aOrbiterH = RotL64((aOrbiterH * 18062931724700600993U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6977017654546871841U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4131602217285988962U;
            aOrbiterG = RotL64((aOrbiterG * 11865422227883712419U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9619228479582032318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13506679497441415586U;
            aOrbiterC = RotL64((aOrbiterC * 5789932662418992799U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10180259475831448124U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4721628773773094283U;
            aOrbiterF = RotL64((aOrbiterF * 10834196399754443771U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7898137727558813688U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4970414922752555648U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6651835668618579479U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterK, 58U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterA, 35U));
            aWandererE = aWandererE + ((RotL64(aScatter, 22U) + aOrbiterG) + RotL64(aOrbiterD, 44U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterF, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29560U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 28750U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32041U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30873U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((aIndex + 27500U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 29U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 11410829607777684449U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 7502698839700975347U;
            aOrbiterG = (aWandererD + RotL64(aCross, 19U)) + 13267685058252106173U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 58U)) + 238242706996630625U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 3U)) + 8184695499511454281U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 11U)) + 12767823220461985403U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 29U)) + 12293198423143850330U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 11149495229952495939U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 6U)) + 7556992689338382800U;
            aOrbiterC = (aWandererI + RotL64(aCross, 51U)) + 3431338808774134649U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 53U)) + 16863099140844995099U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17872458049880677604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16760153457252546974U;
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3115544493537438408U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4359882942759752958U;
            aOrbiterH = RotL64((aOrbiterH * 561477566995575801U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13387113067202396536U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12955690074544490161U;
            aOrbiterB = RotL64((aOrbiterB * 12449941770827974511U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15614054443728226807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1939441328066616114U;
            aOrbiterK = RotL64((aOrbiterK * 4484917074808974359U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4599016263007782537U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9962305629016158048U;
            aOrbiterA = RotL64((aOrbiterA * 1496184427500037279U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8428467674122750557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3938884087806393439U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12810531094050481761U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6018636830758044658U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1510372000641305416U;
            aOrbiterJ = RotL64((aOrbiterJ * 9002834928626918247U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17592782466215337843U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8119921507606870360U;
            aOrbiterI = RotL64((aOrbiterI * 1299795061644535485U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8753237702359236964U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12389957327067768090U;
            aOrbiterD = RotL64((aOrbiterD * 4586786761936601607U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17791633199762408683U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11606494383812053915U;
            aOrbiterC = RotL64((aOrbiterC * 13041480602055778521U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4418614662439151979U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11410829607777684449U;
            aOrbiterE = RotL64((aOrbiterE * 3342270212301058781U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 56U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 4U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 46U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Golf_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
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
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2148U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 28U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 7543U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4455U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 463U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5333U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 13U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 13U)) + 16200278595895089008U) + aPhaseGOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 1029614154810465897U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 21U)) + 7129562468705441295U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 23U)) + 14388903902433951274U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 1013568949315967455U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3128823373497815651U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14525694606889470589U;
            aOrbiterB = RotL64((aOrbiterB * 12053226114431679195U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14443983602196782887U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12244220415328641190U;
            aOrbiterD = RotL64((aOrbiterD * 15052949098014803181U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10477159225338766614U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2842870123078131566U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11522265477555954071U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8621138818955849917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterC = RotL64((aOrbiterC * 14636756322207385447U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2768613802894372496U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2027754864051410015U;
            aOrbiterI = RotL64((aOrbiterI * 2461322540050569287U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 4U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // grow_key_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10082U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 9544U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 14789U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9335U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14701U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14855U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 27U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 6469584119078165548U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 14329756366517987910U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 12890831797059772123U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 43U)) + 3164503807500018990U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 58U)) + 177531431387646836U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3167421392893561015U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2813174781844753460U;
            aOrbiterG = RotL64((aOrbiterG * 9760688894575305115U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10953270419153249857U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16911518309710356951U;
            aOrbiterK = RotL64((aOrbiterK * 13162785997686570445U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6616750447844893150U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10276741398025985982U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6824712685896987133U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6206043608461213208U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12021552904553405793U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10023362889960174909U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15283586234744144846U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5923238786775948571U;
            aOrbiterF = RotL64((aOrbiterF * 8200882393521882651U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 26U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + aPhaseGWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 60U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18534U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 21945U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 17894U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19534U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22989U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17738U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 14U) + RotL64(aCarry, 41U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 48U)) + 12122689833405846292U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 9640400270962766788U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 9141937998266739071U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 12899395770434090537U;
            aOrbiterD = (aWandererG + RotL64(aCross, 19U)) + 13457918115408031842U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15134784483576000943U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12540961268790055438U;
            aOrbiterJ = RotL64((aOrbiterJ * 3295706140418040089U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6306886773092764230U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13573343491337243121U;
            aOrbiterD = RotL64((aOrbiterD * 15893457012357368707U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8545588657348974413U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10891410570357275120U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5399310978367842841U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2877137119767060151U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9178097682386595144U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3524486002084427513U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15528007881855616978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11368419529245281435U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12433207037378339309U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 36U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterC, 60U));
            aWandererH = aWandererH + (((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aPhaseGWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // grow_key_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneA, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneA backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28537U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 27230U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26816U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26488U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25951U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 26210U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 57U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 1210605127156905516U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 5U)) + 11964595428173569519U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 13U)) + 16277319029916258482U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 19U)) + 12369497463101824572U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 6201248574067068202U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 1727477025667206661U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1404510627789806851U;
            aOrbiterF = RotL64((aOrbiterF * 4810039298122529021U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6948213591282018925U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6688865181284421478U;
            aOrbiterH = RotL64((aOrbiterH * 12619122841662247279U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3351130769402360855U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12681032488906270823U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3680893896579741263U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3591412591193726763U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16153817571210878589U;
            aOrbiterC = RotL64((aOrbiterC * 4165137036092246349U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3808228354421006630U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1427373776207504205U;
            aOrbiterD = RotL64((aOrbiterD * 4534374093769595531U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + aPhaseGWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 58U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Golf_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3305U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 311U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4731U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5887U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7906U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3000U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 13U)) + 13960289014350612206U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 27U)) + 3483331015269589730U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 6873299241002444518U) + aPhaseHOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 3562094007125534229U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 3U)) + 11422367439932782705U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 532453428514259816U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17810941465810193088U;
            aOrbiterJ = RotL64((aOrbiterJ * 2830829128884590275U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11869759058631106331U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8837581071876177566U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15329827515970522213U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17185378327053837778U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7578253375676981500U;
            aOrbiterI = RotL64((aOrbiterI * 13371647568758721729U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17112646434432814442U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14949096407295697881U;
            aOrbiterB = RotL64((aOrbiterB * 14770977858283051753U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4259590620758467836U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6534899413644542303U;
            aOrbiterE = RotL64((aOrbiterE * 7987609419215568661U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 40U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // grow_key_b loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14821U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 10838U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16032U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11037U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10370U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10107U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 35U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aIngress, 5U)) + 14157904117287696136U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 51U)) + 7369512677371640676U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 8411250745902073798U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 5002041814539710275U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 51U)) + 9538041410816283124U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5210700103927513061U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7600709399101287982U;
            aOrbiterI = RotL64((aOrbiterI * 6777896926889560889U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2366369466696580499U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 5544575244203019109U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16231219246786333057U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8710073749110329779U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15998211310115361630U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15275657696897688955U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15354357553877376422U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10405750198355464768U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3465819693133515142U;
            aOrbiterH = RotL64((aOrbiterH * 14678343718277562799U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 58U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterK, 58U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // grow_key_b loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19140U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((aIndex + 19757U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 18576U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23586U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24117U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17712U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 48U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aScatter, 41U)) + 6342299552323486695U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 43U)) + 12692748514781367538U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 8202639945493229155U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 4439975701793231639U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 53U)) + 16774235182859553759U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8764155413335405667U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7167848811974967685U;
            aOrbiterA = RotL64((aOrbiterA * 1052856924757654735U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16768278912125334220U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9090838954826296201U;
            aOrbiterK = RotL64((aOrbiterK * 5459329624017272077U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7644075729758006298U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17326182797908071215U;
            aOrbiterH = RotL64((aOrbiterH * 2408330168749256075U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16158809721888137555U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8029938783858263694U;
            aOrbiterC = RotL64((aOrbiterC * 12628072435324195483U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8716553521415553404U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7012599977009208840U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // grow_key_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26905U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((aIndex + 30590U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 32555U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27524U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28624U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25404U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 3U)) + 9023059520606551446U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 29U)) + 662441755115638133U) + aPhaseHOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 16957253361196144712U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 46U)) + RotL64(aCarry, 51U)) + 7840955025765308605U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 346855809270395799U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16099139781586668343U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3706457327118322098U;
            aOrbiterA = RotL64((aOrbiterA * 7810030620470889591U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12166825885547622870U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7792658665720344200U;
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 7128477606152986326U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterC = RotL64((aOrbiterC * 11993485572912492297U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10443889548568288532U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4402387036946561017U;
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13002706161178447654U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13929727277530310708U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7005639090871200285U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterJ, 14U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
