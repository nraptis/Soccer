#include "TwistExpander_PickleBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_PickleBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBD8FFF1F70198249ULL + 0x9F2B9F19865813E6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD953C5804F61C5EFULL + 0x808AD4116DD3CA27ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x985A21751785E631ULL + 0xA1EC51E7F0847BAEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBBDB884116D0FD19ULL + 0x98B04EC408810608ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFA7B96C3134EFEE1ULL + 0x8F6B8BDD32A272B0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFADC29448C7B9C91ULL + 0xB951AEA434CE176CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9BA99729DEE9F8A5ULL + 0xEA5FED3CE36FA448ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD90839F57F3776DFULL + 0xAAC26DD26AED00A1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8F256773807F98ABULL + 0xDF9AAF42CCCDCEEDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x84B7D74F12D48811ULL + 0xF9250FCB81105221ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB36DAF9BB2B6FBE3ULL + 0x9C3D2A5ED7C001E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD36CB0C6441BA965ULL + 0x9D75BF665DDBFA0AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x893CA200AC19FC6DULL + 0xE23C63ACF64B78A2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8D89474C1CF6794FULL + 0xE1A587E1E8C23702ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAB4D7D2DE2837A13ULL + 0x9C77EF56EFD5000CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE7DA4A27260DF7DBULL + 0xCA4A13806E3A7215ULL);
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
            aIngress = RotL64(mSource[((aIndex + 165U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 1823U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1662U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2892U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 7948891781097675369U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 43U)) + 13928362874228230226U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 35U)) + 10776180542602258926U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 26U)) + RotL64(aCarry, 39U)) + 5735115172149470447U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 13U)) + 5353591822981766987U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 21U)) + 562301708107268570U;
            aOrbiterI = (aWandererG + RotL64(aCross, 3U)) + 10467810247578364868U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 29U)) + 14541630141152308564U) + aNonceWordN;
            aOrbiterF = (aWandererE + RotL64(aScatter, 51U)) + 2350076897065139429U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 10U)) + 17519109078651162228U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 6061035173339902910U) + aNonceWordE;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 15654836633731000065U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13723521735153718904U;
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8759060657343458985U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11009137869375286581U;
            aOrbiterE = RotL64((aOrbiterE * 8741417343929809115U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15792999392743144135U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6180808423175992479U;
            aOrbiterF = RotL64((aOrbiterF * 13681230339693676907U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 361487389591183005U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15292753806514404853U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 17478232597253311153U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14929153438443362045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7904556383593914086U;
            aOrbiterK = RotL64((aOrbiterK * 2484130486635511403U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3793180909904286848U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10391957637467171320U;
            aOrbiterC = RotL64((aOrbiterC * 505484041943467117U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11648765065563798353U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 17601185776537566611U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4753179291885740011U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2907499704986356444U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17048858067202291241U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 2607549567999666889U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4340465159886930775U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7948891781097675369U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12913104720552907335U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 18U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 53U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 10U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aNonceWordP) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 37U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 52U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 26U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10680U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8364U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7212U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((aIndex + 8375U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 35U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 39U)) + 3973833383430652211U;
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 5760227042747169187U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 4923009065139227286U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 1477807307009107590U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 54U)) + 5707194514329007301U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 43U)) + 5340439728375269724U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 17080457898946572387U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + 281559150259472813U) + aNonceWordN;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 50U)) + 16160633048230910560U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 27U)) + 9003989610509592121U) + aNonceWordL;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 37U)) + 10579322462808454333U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15059383289528723069U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10417647757852880956U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 1457919230286043137U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14484665027393813330U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12344463053485837974U;
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5826453246659297805U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12547902286376986223U;
            aOrbiterE = RotL64((aOrbiterE * 2982850000322672789U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9637855144278126174U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2132744427444501938U;
            aOrbiterH = RotL64((aOrbiterH * 5911587798564836199U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9248933938130311231U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13274297928717090383U;
            aOrbiterB = RotL64((aOrbiterB * 2901398809555237563U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3690262236918560930U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3626005326410800344U;
            aOrbiterD = RotL64((aOrbiterD * 13030443356669355355U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10801089744186148218U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5446653082176311031U;
            aOrbiterI = RotL64((aOrbiterI * 4594267575901248321U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3205541585889107366U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4532327942368884436U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16287094987689326229U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9755333481079721632U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 722154154363571049U;
            aOrbiterA = RotL64((aOrbiterA * 11002432494248958957U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8071668483354405205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8770466248803121315U;
            aOrbiterC = RotL64((aOrbiterC * 12780438190628717807U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1999251593502332271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3973833383430652211U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5325244982474631559U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 44U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 24U)) + aOrbiterD) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 39U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterD, 6U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 11U)) + aNonceWordM);
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 14064U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 10977U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 11515U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 11161U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 36U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 50U)) + 5576732410244514238U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 2833808925935929629U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 47U)) + 3670188682914544792U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 15759072378887814995U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 53U)) + 13934007231137439994U;
            aOrbiterA = (aWandererD + RotL64(aCross, 41U)) + 11022225696007690512U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 28U)) + 16989177104453635790U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 39U)) + 9256930045263527091U) + aNonceWordC;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 19U)) + 17788596104417068290U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 23U)) + 17044369456673337625U) + aNonceWordD;
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 1310908395523250343U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12067065689034065422U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15130844248737512262U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 9409499577465934107U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14532689204495587494U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8198147292120244178U;
            aOrbiterH = RotL64((aOrbiterH * 1418356389507740991U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5485494458627163347U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10830008207150307611U;
            aOrbiterK = RotL64((aOrbiterK * 6526039534042499457U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17770065502486618029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6397859353395335459U;
            aOrbiterI = RotL64((aOrbiterI * 14286997752368893825U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5128700697381508319U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7103394110057060499U;
            aOrbiterJ = RotL64((aOrbiterJ * 5053680689949149633U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16024401282261796979U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12818445221897253410U;
            aOrbiterA = RotL64((aOrbiterA * 11450004517784155405U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13386978409145916350U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16740821954556699503U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 5376430209628515105U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 313978038530994953U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1355733685461795345U;
            aOrbiterF = RotL64((aOrbiterF * 15955927322082619735U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12590581077253956064U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2298195367575496005U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17512801361187006363U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11847450675712272468U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5914296379577670282U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 14574813500616811367U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16901317262621287065U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5576732410244514238U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4514943876091531567U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 34U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 10U)) + aOrbiterI) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 22U)) + aOrbiterG) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI + ((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18631U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 19818U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18950U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 16718U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17875U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 22U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 5U)) + 7722279280863371124U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 11584220561732385598U;
            aOrbiterF = (aWandererH + RotL64(aCross, 47U)) + 7834679350105534657U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 13U)) + 11347994382444180879U) + aNonceWordO;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 41U)) + 9449903188047063431U) + aNonceWordE;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 24U)) + 6516243976652795170U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 8420815253991184777U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 9081386852515170937U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 21U)) + 14375955191735286867U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 57U)) + 880757589768436072U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 51U)) + 3349856625725164229U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7826309957607577207U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8057435761214313635U;
            aOrbiterF = RotL64((aOrbiterF * 4718430712767038607U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9565237500443303103U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15893066735310588501U;
            aOrbiterK = RotL64((aOrbiterK * 8457633439171452397U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3276844534476430842U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6828644383891274120U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2815676923011504251U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5030251870850928417U;
            aOrbiterG = RotL64((aOrbiterG * 7075653570570819253U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13464083008377887034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8994560761846897590U;
            aOrbiterB = RotL64((aOrbiterB * 9892839554658865143U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8398813387154468736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8136429428340910892U;
            aOrbiterE = RotL64((aOrbiterE * 3348811490733577295U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 418587250696862341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4111667833838312094U;
            aOrbiterD = RotL64((aOrbiterD * 860949442143849147U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6075478294190926371U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2208124955874142264U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15741988616251072075U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4726538724576443010U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6524078248882840425U;
            aOrbiterH = RotL64((aOrbiterH * 9784875566721689069U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14521003220464811621U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16916247868211621303U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1911638054294853877U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18207293125461843123U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7722279280863371124U;
            aOrbiterI = RotL64((aOrbiterI * 14303108475807941791U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 12U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 28U) + aOrbiterI) + RotL64(aOrbiterD, 34U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25720U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 26590U)) & S_BLOCK1], 46U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24519U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 25707U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25302U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25420U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 26U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 27U)) + 7825479804710770560U) + aNonceWordD;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 13U)) + 5298124167101358123U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 50U)) + 17774541024369233726U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 7679371833537454082U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 5385914900748772224U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 3879781930908486531U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 34U)) + 659110346638873236U) + aNonceWordH;
            aOrbiterH = (aWandererE + RotL64(aCross, 53U)) + 10749021728538539749U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 29U)) + 3631252455767429457U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 5U)) + 2271978810960685021U) + aNonceWordP;
            aOrbiterB = (aWandererI + RotL64(aCross, 37U)) + 5963558780692551176U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 974909966119198104U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9296998242911152296U;
            aOrbiterC = RotL64((aOrbiterC * 2613629915877957661U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2245318466901521959U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13391076374843288568U;
            aOrbiterJ = RotL64((aOrbiterJ * 18094558036982107419U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6184487746594236737U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1563385912137291418U;
            aOrbiterA = RotL64((aOrbiterA * 4805455299959232321U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1744840092006498629U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2100927276837188416U;
            aOrbiterI = RotL64((aOrbiterI * 3541788262067077997U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9998911862807246338U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12239948725635220096U;
            aOrbiterG = RotL64((aOrbiterG * 7098620484129489129U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3307447094994950246U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12746613971448298932U;
            aOrbiterK = RotL64((aOrbiterK * 9463975886346934681U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11577488293733790649U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 191108997585598809U;
            aOrbiterB = RotL64((aOrbiterB * 9574978681405356871U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 18096145693841273722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10026281133603934071U;
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2346682418062064668U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2996178204018644206U;
            aOrbiterH = RotL64((aOrbiterH * 2552965800703390909U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15085425896818988223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1589593231782852588U;
            aOrbiterF = RotL64((aOrbiterF * 1535556765195388675U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17170695588248383518U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 7825479804710770560U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 7434218282170150533U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 42U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterA, 35U)) + aNonceWordE) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 6U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29064U)) & S_BLOCK1], 10U) ^ RotL64(pSnow[((aIndex + 31240U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28422U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28194U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27358U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 32371U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 35U)) + 15910560457440369082U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 17953072986407436888U) + aNonceWordH;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 43U)) + 15446940721193538669U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 23U)) + 3020785262774422009U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 39U)) + 7001288645424994404U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 13385250665458462689U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 41U)) + 4841895644623005949U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 27U)) + 13053476783239482065U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 51U)) + 641996979335975244U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 60U)) + 16211238020928688299U) + aNonceWordD;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 12715448751323279480U) + aNonceWordF;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17784406727699995290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16626339815786580778U;
            aOrbiterE = RotL64((aOrbiterE * 13940754474750138041U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9035070625716345139U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6085848172494001945U;
            aOrbiterK = RotL64((aOrbiterK * 10405728912339646693U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1177103851507561053U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2281901691017816407U;
            aOrbiterC = RotL64((aOrbiterC * 3142197009403602497U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9040984343694325070U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 13334258224023902365U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1079824790138592518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14024082692012948652U;
            aOrbiterH = RotL64((aOrbiterH * 3219489374333737903U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2966776524421278970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5510281854029308547U;
            aOrbiterI = RotL64((aOrbiterI * 9275402927591867297U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7126632329316720048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1476827035602733472U;
            aOrbiterJ = RotL64((aOrbiterJ * 2217671289726794033U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6470212302133184965U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4172257438373147415U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4449314239630366533U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11445212164224402184U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1779825157413363285U;
            aOrbiterF = RotL64((aOrbiterF * 15393425495668107155U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7561888690947559866U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14440989817038856852U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5799807036762859679U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10618807050937260814U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15910560457440369082U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10902491688248464465U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 28U)) + aOrbiterI) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterJ, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 18U));
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 4U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_PickleBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE48A0DB4F05E76EFULL + 0xD0819DC6D1675785ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFE62DFD04F6B0DD5ULL + 0xD11A193D58F948E0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE2DF1E576F535B0DULL + 0xE90752D6F27E478CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE7DB31F592654FB5ULL + 0xC9191462243C0020ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE08A206D0792EE81ULL + 0xD9B77059FC9F22A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBC57D01F15581B47ULL + 0xE6504ABB4A1FFE56ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDF4CD7D1AF85F557ULL + 0x9C60FF9890AF2C10ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFBE5DA8D6A7D269FULL + 0xBE995AD86698130EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD749EE6FEF456A4DULL + 0xC5A9FBDEE660F39BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB75F3439B2DE9B15ULL + 0x9CA6A096BCC7CFE7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA3A2D69D95D4EE7DULL + 0xC4E7C4967DB8BAF0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x97EBCBA0DA30CADDULL + 0xD4E2692E96CAA649ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF6C37DF94AE6433FULL + 0xE8B473D687C577D6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB5385AE20E98B7B7ULL + 0x99166E03ED1C3D5FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFA9363995440883DULL + 0xFB49E13CBE7C098CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB198DE451F07BDE7ULL + 0x9EAE9A5C27CAE0FCULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4602U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((aIndex + 7397U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 1638U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4772U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 10U)) + RotL64(aCarry, 35U)) + 18302975933754610273U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 16736972646771456082U) + aNonceWordI;
            aOrbiterJ = (aWandererF + RotL64(aCross, 35U)) + 17389406266488137442U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 57U)) + 5252511566486165539U) + aNonceWordG;
            aOrbiterE = ((((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 5730715427422747640U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + 6412695646456045825U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 47U)) + 9539701605708994494U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 6U)) + 18355107116412945722U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 11735742491750132942U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12363819388562658842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5861430292304371543U;
            aOrbiterJ = RotL64((aOrbiterJ * 12989055611235382695U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15027487084595017708U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7012850020745791926U;
            aOrbiterE = RotL64((aOrbiterE * 15952928839355613939U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11904871669287886120U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11199760114477343208U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7156374911847525867U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3856004502263742700U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3705931243173921893U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 10334871178498711485U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12305785390539209389U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 18057980996551978823U;
            aOrbiterG = RotL64((aOrbiterG * 4850564181113470859U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3229431819292153014U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2994716629242460094U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1029427328395257917U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9796307843453735512U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2957260393651252432U;
            aOrbiterB = RotL64((aOrbiterB * 7261055869794739609U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4060469664218866340U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17462081697889685330U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7712009170974461225U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13638660073917821172U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15202349592659062565U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 4514326257446024301U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 52U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 36U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 42U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12750U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneB[((aIndex + 9181U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11161U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11130U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12666U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 57U)) + 13583136155674166402U) + aNonceWordJ;
            aOrbiterA = (aWandererC + RotL64(aIngress, 5U)) + 12830472187484919497U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 18081197909484522509U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 24U)) + 8680634051297891550U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 13939998767458656823U) + aNonceWordL;
            aOrbiterD = (aWandererB + RotL64(aCross, 35U)) + 1795730579103692594U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 47U)) + 17369751719734069999U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 43U)) + 224769585901248068U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 30U)) + 4133547085925268180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7022512056309567391U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 10319484359046945495U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3400140531307001933U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10483878349412282069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6481381149199985736U;
            aOrbiterD = RotL64((aOrbiterD * 9701719367082506253U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13721077228796934509U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9704818014314175007U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 760445624027740287U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6253040047758584339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16890211690273641226U;
            aOrbiterB = RotL64((aOrbiterB * 5622534399866057841U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6216227831265032436U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2023609047004658739U;
            aOrbiterA = RotL64((aOrbiterA * 3252332895698310147U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9201669637050388263U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5106927540934338576U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6368134569042291431U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10080368957861445998U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10784789383436485808U;
            aOrbiterK = RotL64((aOrbiterK * 3794918350254445939U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15426339824951793026U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17637144549368340331U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10971293914614704441U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9941300382181962134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8118046374121322097U;
            aOrbiterJ = RotL64((aOrbiterJ * 8481945819050983127U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterB, 28U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 11U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 56U) + aOrbiterK) + RotL64(aOrbiterF, 12U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23301U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneD[((aIndex + 18020U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23977U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24521U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20085U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17473U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 26U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = (aWandererH + RotL64(aPrevious, 23U)) + 6771552164800695068U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 35U)) + 12131763371571322040U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 48U)) + 3326182381395522013U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 12288775097697156383U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 5195948373449796741U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 39U)) + 14404044002250137144U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 52U)) + RotL64(aCarry, 53U)) + 11142382920035825426U) + aNonceWordK;
            aOrbiterA = ((aWandererF + RotL64(aCross, 43U)) + 2967149520256475485U) + aNonceWordN;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 29U)) + 1470907369577818097U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9231668148004163910U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13078929163913892386U;
            aOrbiterJ = RotL64((aOrbiterJ * 7509829068700523627U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9485274692075657877U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12216951187543631673U;
            aOrbiterB = RotL64((aOrbiterB * 6571066246507310805U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6933334652581744234U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17260276102423580920U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 387767848169714392U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8597538259308082638U;
            aOrbiterG = RotL64((aOrbiterG * 4888054690557707241U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7996708724489146033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15357384191688149939U;
            aOrbiterF = RotL64((aOrbiterF * 9827691726832491373U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17739222908739454637U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 1614322333281471170U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 7063116837752240891U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 4531604274893197209U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3453280714992341288U;
            aOrbiterK = RotL64((aOrbiterK * 8390029711127907805U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 116623650872661533U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6565636510115095988U;
            aOrbiterA = RotL64((aOrbiterA * 9691897067492501177U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10303258439817808058U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10917642773040237611U;
            aOrbiterE = RotL64((aOrbiterE * 10232856828372963363U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 54U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterB, 34U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 48U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28912U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneC[((aIndex + 25836U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 29445U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31981U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32158U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29517U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 54U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 39U)) + 13442819395490639310U) + aNonceWordN;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + 8187292523194120936U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 13U)) + 11469697159823131388U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 48U)) + RotL64(aCarry, 13U)) + 13414083692375929653U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 11404010733687907517U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 3U)) + 6783212827186218247U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 8561131439340372614U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 19U)) + 6252609642004429113U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aIngress, 52U)) + 12804867444200448952U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2739648749603690781U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14808861217017399752U;
            aOrbiterC = RotL64((aOrbiterC * 373911885694012101U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 17588866502571268888U) + aNonceWordL;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 5882260142735642980U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15493099088132862949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5175647411532429582U;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14279707376173642767U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6826363572161275158U;
            aOrbiterD = RotL64((aOrbiterD * 5263708315440161809U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13267185753040999992U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9980987858092888720U;
            aOrbiterG = RotL64((aOrbiterG * 13210290848800728635U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3582972937645514549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 10140409019562890804U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 6944490201647678479U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6160444117287330557U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16344602960561293113U;
            aOrbiterK = RotL64((aOrbiterK * 2319964919335633293U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3497141036108337171U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 91269118352540308U;
            aOrbiterF = RotL64((aOrbiterF * 5160060720189045505U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12739932748793144857U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12820180915064791197U;
            aOrbiterB = RotL64((aOrbiterB * 5843849637411948699U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 56U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 6U));
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 41U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterB, 60U)) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 18U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_PickleBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA8A4CE399AC97D19ULL + 0xABA31A80B8B7405BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB398B299AB568FDFULL + 0xB782BC489BBB2E89ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEF511C1E639654A9ULL + 0xF83CCBB5DC15756EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDFE3F741A747675DULL + 0xDB84D2422643D016ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBD4B660B6CC4B50DULL + 0x8BA22ACB90CE59EAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x95019A84750B1787ULL + 0x9B0A8586888E6444ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA754C0A452981243ULL + 0xACD36CA11BAA5840ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF118C29A4B72B2DBULL + 0xEC23C2FF092F6AFFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC78E88F1AD3EF84DULL + 0xD35E701599EE5594ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAFCCA4304EB217A3ULL + 0xE77AB1EC42408171ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x810303F6B936A485ULL + 0xEFC770583A85E243ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC730FAAF69EE09B3ULL + 0xE1853914C80F60F3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x87C6D1213CD14F35ULL + 0xAEC1D65F5E5176C8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD783F7801E356BCFULL + 0x834C21F46F02D45BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x926F89CEFAA4CAC5ULL + 0xEDACA9A2AA334052ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD1C68612D55E461DULL + 0x8A92411096072789ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneD, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2394U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 1795U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7064U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2336U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 3576U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 1042610313571524121U) + aNonceWordJ;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + 3505725321008825582U) + aNonceWordC;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 12584654563843782991U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 6645399144515770935U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 38U)) + 3608978423753715584U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8089198857670370983U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15207251813516399879U;
            aOrbiterK = RotL64((aOrbiterK * 7596841660069752069U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9579268660105824516U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2269649280637188723U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 583811872609805949U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 12686754713465826139U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18256061823189677508U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12708429127816136937U;
            aOrbiterB = RotL64((aOrbiterB * 12593886633108075321U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12169216645156306078U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12694325407567795065U;
            aOrbiterC = RotL64((aOrbiterC * 3711789483877261899U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 52U)) + aOrbiterB) + aNonceWordM);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 11U)) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13677U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 9135U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11049U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15469U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11762U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11434U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 4622023259121087483U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 37U)) + 10253505250223501352U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aWandererB + RotL64(aCross, 3U)) + 17133877904420462669U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 24U)) + RotL64(aCarry, 51U)) + 6162827793741796700U) + aNonceWordM;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 9610986424765907615U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11210747154264753754U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16554205219580654546U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 12754735039924859911U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 10352576357413766388U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3651845783283479752U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1011289824180799641U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18145542190463500476U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5415609566767162857U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6474184559323816389U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2033734872464201570U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3507213117125813345U;
            aOrbiterB = RotL64((aOrbiterB * 5453058336688881113U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8716253393049851856U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 695984869565941856U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8377921610764044735U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterB, 58U)) + aNonceWordJ) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24485U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 23998U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20632U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19406U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19297U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 21638U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 18U)) + 1210605127156905516U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 11964595428173569519U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 16277319029916258482U;
            aOrbiterK = ((((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 12369497463101824572U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 3U)) + 6201248574067068202U) + aNonceWordM;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1727477025667206661U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1404510627789806851U;
            aOrbiterB = RotL64((aOrbiterB * 4810039298122529021U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6948213591282018925U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6688865181284421478U;
            aOrbiterA = RotL64((aOrbiterA * 12619122841662247279U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 3351130769402360855U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12681032488906270823U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3680893896579741263U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 3591412591193726763U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16153817571210878589U;
            aOrbiterK = RotL64((aOrbiterK * 4165137036092246349U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 3808228354421006630U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1427373776207504205U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 4534374093769595531U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 60U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 54U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 21U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27846U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 25682U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 29505U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30877U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25287U)) & S_BLOCK1], 22U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30807U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 28295U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 57U)) + 6318740973868639425U) + aNonceWordK;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 5487840061430920881U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 28U)) + RotL64(aCarry, 21U)) + 10258706763248072672U) + aNonceWordC;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 18356875269730338208U;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 12883160282903147010U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1010140474942697730U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17733939421700898293U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 9233534157871885251U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13693055887924981201U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14574732452793385269U;
            aOrbiterE = RotL64((aOrbiterE * 9373765929885750185U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10832873941223609012U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8212600587135328040U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 5334613996794796145U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5312744319781971178U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6173741211706546923U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3693249147883790810U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 18365859989736602556U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterF, 46U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_PickleBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCFB42B50A81961A5ULL + 0xBD1A30F3330BB8ABULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC1566296AA5BAD21ULL + 0x9F5BE6DE92FA7938ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAAD1B584585A658BULL + 0xF333E05471D996D9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x92F2FED98CCC1EE7ULL + 0xF127056D592431F3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE65330FA6937A67BULL + 0xA0414EC00DABB490ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC8D9E2BAF874D81BULL + 0x87C96B446B6DBD4AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF4BC5AD3CC5413DFULL + 0x811FE2FB28CEA2C3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDB3620588A4F657BULL + 0x8BCA1595690301C4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDD26BBBD2BD5BABFULL + 0xE2AFEC9EF01ACF41ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9E9B8941D5C9D0E7ULL + 0xD69B9DEA774C2D81ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC7118F15EA76541FULL + 0xAE0DDE0D90B9DF3AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE2F2177C5C597467ULL + 0xBE055C48C00B1ADDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE2E1F94538D78D99ULL + 0xD79E064E363C80C3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x93507D04FF139231ULL + 0xAFA69D8A6B2F143DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8B949E4D8CC55CDBULL + 0xC53F45D693BEAE85ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE542EEC18CADEC45ULL + 0x8DFA5AF6B4694005ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneA, aWorkLaneA, aOperationLaneA, aFireLaneD, aWorkLaneB, aFireLaneC, aOperationLaneD, aWorkLaneC, aFireLaneB, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6761U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 4517U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5920U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7769U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5304U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6075U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 11U)) + 6467297102954816305U) + aNonceWordP;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 7921154109831114952U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 5701131763215638919U) + aNonceWordF;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 34U)) + 10022999076719002684U) + aNonceWordI;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + 4367135243038982316U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 14445846824810383592U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 53U)) + 7683697954545773253U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17517006750428030899U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2052484792684025476U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 12463117571122469643U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6279463052085808926U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 679280153651813684U;
            aOrbiterK = RotL64((aOrbiterK * 3047031560593583881U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2939516520188460569U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1960616434964712325U;
            aOrbiterD = RotL64((aOrbiterD * 15145998415466343039U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 12273819390719947361U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5685033154709449397U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9845666295874714959U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9314494172199500653U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15757631834636427621U;
            aOrbiterE = RotL64((aOrbiterE * 15483543888965744529U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10878078046389399574U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3583495913766365232U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 2913540984990155225U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7385544065754622301U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16839599460207922881U;
            aOrbiterC = RotL64((aOrbiterC * 240651605910592561U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 30U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 36U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12839U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 14068U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13927U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14150U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8727U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16141U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 35U)) + 12426357877879529292U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 12604900366173639176U) + aNonceWordE;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 19U)) + 13511119007338929401U) + aNonceWordL;
            aOrbiterI = (((aWandererF + RotL64(aCross, 10U)) + RotL64(aCarry, 5U)) + 9878720081166788060U) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 15463195409806395076U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 43U)) + 6407922778852833423U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererB + RotL64(aCross, 27U)) + 7690427254160734016U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 18030974031722143619U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17983938038322737041U;
            aOrbiterG = RotL64((aOrbiterG * 12479365337221685413U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16605512170117753884U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 681802273302348322U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14608920184802647123U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15550312921312083819U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17824154101711884508U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7358612830654795357U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1939207786756735430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3132864634777826569U;
            aOrbiterC = RotL64((aOrbiterC * 13606281919426730325U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12822929773923954849U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 16576106045887115660U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 16370914370769903051U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2398825881649235260U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13700821892926092479U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2439833784883391606U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15870638514107637833U;
            aOrbiterJ = RotL64((aOrbiterJ * 3797380922767479287U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 48U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 19U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 54U)) + aOrbiterG);
            aWandererK = aWandererK + (((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 27U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 47U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22032U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 21087U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 19024U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22931U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21475U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 20346U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 9220392006207660113U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + 11305018553489132882U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 51U)) + 5860373868073513684U) + aNonceWordH;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 12319586170883987589U) + aNonceWordO;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 14072333614354649021U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 14U)) + 9332158529453194608U;
            aOrbiterK = (aWandererE + RotL64(aCross, 3U)) + 3860569321145958686U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8119005668901240093U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13918259792880333239U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 5441062406822088853U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6938856216758228704U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3960905839118710604U;
            aOrbiterC = RotL64((aOrbiterC * 16203746868670689793U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6043879193734253929U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15691425268831319195U;
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14912209933584715274U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16180183395910618923U;
            aOrbiterI = RotL64((aOrbiterI * 3942858974766467849U), 39U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 4966642362507707776U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aOrbiterA ^ aOrbiterG) ^ 6962226782462822861U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 3647802407741095419U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12409120845092026295U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2302946450253872465U;
            aOrbiterK = RotL64((aOrbiterK * 7099576330777297911U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16118304388937163838U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15968419034359049422U;
            aOrbiterG = RotL64((aOrbiterG * 11736207775827080165U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 58U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 20U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28611U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 24991U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31516U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26445U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26495U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29048U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 54U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 39U)) + 9914837590440975587U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 6706125076401958051U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 5U)) + 16570817772679258409U) + aNonceWordI;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + 6843705658115186948U) + aNonceWordE;
            aOrbiterB = (aWandererI + RotL64(aCross, 27U)) + 16099930446791572351U;
            aOrbiterG = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 5420550009556030459U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 5729549069420177477U) + aNonceWordM;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15590601126188675834U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13044027390998620029U;
            aOrbiterJ = RotL64((aOrbiterJ * 16845199115313444123U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11068338135659636772U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6584988841809544332U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8516813219883915404U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10647314042912492785U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 15559481057047148785U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 201691689889605304U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3883760518944464145U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13861805129175491145U;
            aOrbiterA = RotL64((aOrbiterA * 17194438894492581181U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12019138626550801486U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13030350224959652248U;
            aOrbiterB = RotL64((aOrbiterB * 11724200983306280107U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2643807255422544248U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4127143302485631794U;
            aOrbiterF = RotL64((aOrbiterF * 5441038881111578487U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aNonceWordJ);
            aWandererF = aWandererF + (((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 35U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_PickleBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x91BE7842A0A4C9A7ULL + 0xBF3C136ACCDCDCC0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAFF972B444D0D5A5ULL + 0xA68666F1AAACCA00ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x89A5156FD2370627ULL + 0x80EE3360243C7CDFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE356BACAAD8498DDULL + 0xC58BB23180283528ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEE491DD26389D983ULL + 0xFFD93A531C350B7BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB1872D5AF13010E7ULL + 0xD48B4358748F72DDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xADB863A20AFD67DDULL + 0xF817F6E1BBCDFD1AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC9A1FB02BA594055ULL + 0xEBFF522499BE07B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8F0D7E661D4DFABDULL + 0xE2B980F68F54602FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB13925579455BB25ULL + 0x87B0BE4A1AAAB47CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x820BEBBCEB5F1399ULL + 0xB6E4FC4184DB084BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD34CE32D1F48A857ULL + 0x85FFFD1FF59FCBEAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAFC5F0917EBDC409ULL + 0xF638CDD15924A475ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCACF896047AC5FA7ULL + 0xC591358DFBF75563ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE8815C5B174A36B3ULL + 0xF934969A1C499509ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xABF310565CF80261ULL + 0xA37FE0DEB5FCBF55ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneB, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aOperationLaneB, aFireLaneD, aExpandLaneB, aFireLaneC, aFireLaneA, aExpandLaneC, aOperationLaneC, aOperationLaneD
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2711U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 6733U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 5678U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6915U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3082U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 5496U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 4384716820085860551U;
            aOrbiterK = (aWandererK + RotL64(aCross, 11U)) + 9715780315942116888U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 51U)) + 15963520052789178632U) + aNonceWordD;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 21U)) + 14346700690686392938U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 6005518012489966643U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 2506732930310252119U) + aNonceWordM;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 16782163084851775826U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 823673076571076303U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1634084509064077736U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1128407326773234517U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 1288134975466877686U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4321412662318298283U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 220430672180734911U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 10223923547068528867U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 12577370238343872139U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11696469696177647608U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6545430420379636963U;
            aOrbiterK = RotL64((aOrbiterK * 8387163146257553773U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 79691451831797107U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8971444023498649419U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 7148919880477390009U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5624403902454498793U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9468064161002030997U;
            aOrbiterD = RotL64((aOrbiterD * 8243560528100864595U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 42U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 60U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 27U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 35U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10291U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((aIndex + 8589U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13900U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8761U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15211U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11819U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 12669015908335980355U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 13U)) + 5438715179868613192U) + aNonceWordA;
            aOrbiterD = (aWandererJ + RotL64(aCross, 35U)) + 13172104448184536460U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 13421421503244744803U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 20U)) + RotL64(aCarry, 53U)) + 13327113302994856582U) + aNonceWordI;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 5U)) + 4671768205922454413U) + aNonceWordM;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + 5355759962838579929U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6691720614265406851U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7063906424700911378U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 17091734375516280675U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17328616394166672263U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1542940602574207068U;
            aOrbiterC = RotL64((aOrbiterC * 8981679306319627975U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7203866278803132454U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 993485696233139264U;
            aOrbiterF = RotL64((aOrbiterF * 11609009908810366447U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15659679028507488331U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 18321361454094675842U;
            aOrbiterG = RotL64((aOrbiterG * 3966860765622641843U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9633319822696783352U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3496559332232402963U;
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1918349708324205526U) + aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7701088402761359134U;
            aOrbiterK = RotL64((aOrbiterK * 9649485438465644795U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6006824348814439686U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18088375375347012557U;
            aOrbiterE = RotL64((aOrbiterE * 12801082943086128385U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 35U)) + aOrbiterD) + aNonceWordC);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 58U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17935U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 20552U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 18074U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22601U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22554U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23042U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 13915875634607599122U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 40U)) + RotL64(aCarry, 51U)) + 1695770381382411673U) + aNonceWordG;
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + 3709105579778295511U) + aNonceWordM;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 5U)) + 7673376335333251804U;
            aOrbiterE = ((((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 8814147709738503518U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (((aWandererD + RotL64(aIngress, 13U)) + 13451412605350381172U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 6447870234069609538U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13419487997946496825U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5478309847615220345U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12953043149543448765U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3635184969215610049U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12527903812035294828U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12540800512035534967U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1684685110885338814U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 12860354576326835090U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 12743745087733307255U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9081823570147481835U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14369321778210049109U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17865953349448767035U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11518132079084873250U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11893535026126957389U;
            aOrbiterH = RotL64((aOrbiterH * 15751374986135615095U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7084079180579206226U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2999676609847603277U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 14602698397511266403U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17683445810614029153U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11576460512964896969U;
            aOrbiterE = RotL64((aOrbiterE * 5243651036457051155U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 36U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 47U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 41U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 29U)) + aNonceWordC);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 4U)) + aOrbiterA) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32288U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 25186U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26355U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30849U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30358U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30676U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aIngress, 53U)) + (RotL64(aCross, 5U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 1557680213571812384U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 51U)) + 7387349725778021121U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 15379264067601586976U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 3730195724576043708U) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 10U)) + 9637070085323827066U) + aNonceWordP;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 19U)) + 1170865717363676184U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + 2750833653175252030U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15118992811225568305U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4974092922102988451U;
            aOrbiterD = RotL64((aOrbiterD * 10575977398702460975U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10625719096296719514U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 855167122475471865U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7441090331293158773U), 13U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 11322911068958340262U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4334591909425429835U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14263701737208936392U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 678723206735649084U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 10823239851733632227U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15652053114252065230U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1705225940224061401U;
            aOrbiterK = RotL64((aOrbiterK * 3626023093533713579U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6826394665732900206U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11902946775066981141U;
            aOrbiterF = RotL64((aOrbiterF * 18300629262162694137U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9802212958998591310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14001358545610206524U;
            aOrbiterH = RotL64((aOrbiterH * 13172645840788327099U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 39U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aNonceWordJ) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 30U);
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

void TwistExpander_PickleBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xECA18727AAB7F443ULL + 0xB261549E96DEFDB7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA42D662D956B6C8FULL + 0x9172633F440BB63EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x944C0E2E771E0AD3ULL + 0xE91C866963ABF368ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA7E268135AEBCF39ULL + 0xDBE0AE0CB7C6C513ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC3D2AE2049D893FULL + 0xE8AE949F76C04441ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xFF8E8ADBF1C96CD9ULL + 0xA909329371D191D2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBD9CD919351DCD3BULL + 0x8DEFE79122367599ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE407DE63235EE3DBULL + 0x87389E0B15D573D3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBD56B5068B3FFDE3ULL + 0xCD6AF762B6227739ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8C006E02F9E2765DULL + 0xE8627EE86EF8E030ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE1B65F8CA94C1EEDULL + 0xD22CBB19C0BE9073ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC3B15564A583724BULL + 0xAEF44C0AA53686EFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDA7F31488E33A001ULL + 0xE75BB8FE0501AACEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE4693DA5E02875ABULL + 0x8DA6CEB6080C7AEBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x80BD60A317C47233ULL + 0x9757348E4E73CAAFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x80152623F914037FULL + 0xBA0D3DA09853698CULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneD, aOperationLaneA, aFireLaneA, aFireLaneD, aOperationLaneB, aFireLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneA, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6519U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 3414U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 2386U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6309U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5727U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4672U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 37U)) + 6467297102954816305U) + aNonceWordL;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 12U)) + RotL64(aCarry, 19U)) + 7921154109831114952U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 5701131763215638919U;
            aOrbiterE = (aWandererF + RotL64(aCross, 43U)) + 10022999076719002684U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 23U)) + 4367135243038982316U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 14445846824810383592U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 57U)) + 7683697954545773253U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererG + RotL64(aIngress, 41U)) + 17517006750428030899U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 21U)) + 2052484792684025476U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 54U)) + 6279463052085808926U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 679280153651813684U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2939516520188460569U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1960616434964712325U;
            aOrbiterF = RotL64((aOrbiterF * 15145998415466343039U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12273819390719947361U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5685033154709449397U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9845666295874714959U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9314494172199500653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15757631834636427621U;
            aOrbiterC = RotL64((aOrbiterC * 15483543888965744529U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10878078046389399574U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 3583495913766365232U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2913540984990155225U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7385544065754622301U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16839599460207922881U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 240651605910592561U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13038163804940349251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2587538594933924000U;
            aOrbiterE = RotL64((aOrbiterE * 3091149760401278671U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13109518583364738004U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2447689055742474261U;
            aOrbiterB = RotL64((aOrbiterB * 12100180201235703193U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5752044906692668618U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6637725371036522120U;
            aOrbiterJ = RotL64((aOrbiterJ * 6021986525167161115U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16549229877442298618U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12825651879441561108U;
            aOrbiterA = RotL64((aOrbiterA * 9079931351967033993U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16088338999978085987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12584648360998154782U;
            aOrbiterG = RotL64((aOrbiterG * 2109996837220975261U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 7526256599938771686U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6467297102954816305U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 9289442676936248653U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 44U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterG, 43U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10709U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 15742U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14288U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8342U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13457U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15991U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 50U)) + RotL64(aCarry, 5U)) + 11177787645248006236U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 3U)) + 3808340254579817169U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 828030667598518279U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 16177835921238398371U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 5518747735458708741U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 20U)) + 17346319082399995165U) + aNonceWordE;
            aOrbiterK = (aWandererG + RotL64(aScatter, 13U)) + 6397156921893030937U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 39U)) + 15559381654710713582U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 35U)) + 940404446491415088U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 23U)) + 8047166032048732645U;
            aOrbiterD = (((aWandererK + RotL64(aIngress, 27U)) + 4688468645859470491U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3710878044770337260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 116343189456629220U;
            aOrbiterH = RotL64((aOrbiterH * 5637725064169289339U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 883908030159391659U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18058691521694880482U;
            aOrbiterA = RotL64((aOrbiterA * 3132200449123497619U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17521015077103586117U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3668332225435714918U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12658899101297839881U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12229480388278883300U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 16206524049491531816U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 11122340196620859805U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5743265849441077466U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 8903956475200417109U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13718364781538837074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 861529717259766236U;
            aOrbiterI = RotL64((aOrbiterI * 17019744777211266685U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4862687502126693872U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7722024283321020761U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 18086944039541060829U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8205803118233399853U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15130160926615050422U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1454552751453996765U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 667469191899263617U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18048970185163843471U;
            aOrbiterE = RotL64((aOrbiterE * 1800698970568737425U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 508102841337488721U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3803840516662727630U;
            aOrbiterK = RotL64((aOrbiterK * 8477778555284121637U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17055028117762299436U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11177787645248006236U;
            aOrbiterD = RotL64((aOrbiterD * 12457019014051206805U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 14U)) + aOrbiterJ) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterK, 43U)) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterH, 46U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22257U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 24317U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 24145U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23656U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17378U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19819U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 52U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 44U)) + 12615321415808640429U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 47U)) + 15712784676459931207U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 11013335427004930046U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 8298733856304768806U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 3U)) + 6207732959150824216U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 5U)) + 9769864876127544038U;
            aOrbiterA = (aWandererD + RotL64(aCross, 23U)) + 10782181918651152563U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 14U)) + RotL64(aCarry, 47U)) + 5790454015845620939U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 15606578025386733803U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 21U)) + 5522352539991175304U) + aNonceWordI;
            aOrbiterI = (aWandererB + RotL64(aCross, 41U)) + 5993355818572869649U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10864534396947622047U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12090053126235913528U;
            aOrbiterC = RotL64((aOrbiterC * 7250801471645972261U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14191181677234981396U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2258570108233924592U;
            aOrbiterK = RotL64((aOrbiterK * 8307541155393855209U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8448114811381534603U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2702389315763499817U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17202184076718780200U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 150549910056015002U;
            aOrbiterD = RotL64((aOrbiterD * 195034681254956335U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4910512055808124967U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13842899106208709771U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7930112618036681468U;
            aOrbiterB = RotL64((aOrbiterB * 8609551859830858419U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8790107242863198659U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6882768826643279144U;
            aOrbiterF = RotL64((aOrbiterF * 13745521454063360763U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12136498871759890015U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8120456314755584336U;
            aOrbiterJ = RotL64((aOrbiterJ * 1830725195528043575U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14425711740351183016U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15907406009196323049U;
            aOrbiterH = RotL64((aOrbiterH * 8599371693260686839U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4878521420367891861U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1184672056055028939U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 5963961755367831967U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10126736568567000180U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12615321415808640429U;
            aOrbiterI = RotL64((aOrbiterI * 11663715449073755137U), 41U);
            //
            aIngress = RotL64(aOrbiterK, 26U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 48U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 40U) + RotL64(aOrbiterD, 39U)) + aOrbiterB) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 46U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterH, 51U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31238U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 30109U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26737U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29268U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31400U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 31867U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 18U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 17019646486641172469U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 12276141179299971572U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 13U)) + 3617241694029841555U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 6967963401259371737U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 36U)) + 6340709284279891017U) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aScatter, 27U)) + 456065368903896482U;
            aOrbiterF = (aWandererA + RotL64(aCross, 5U)) + 17686765719908116203U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 39U)) + 1322045955429785736U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 48U)) + 5163772703302372887U) + aNonceWordA;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + 13268431135020363252U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 29U)) + 6538789950366849332U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10390344544314544893U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5087084271300584267U;
            aOrbiterD = RotL64((aOrbiterD * 15149302947570776165U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13423071121590981727U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15814349432207734533U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4129091815978464507U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17024797553831962245U;
            aOrbiterE = RotL64((aOrbiterE * 3137753479364378175U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6501545108779991661U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11930037791867597447U;
            aOrbiterK = RotL64((aOrbiterK * 4904739567549702851U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4667298703308315851U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6315980380900062127U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 12080555704907924637U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12732382340390769888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7792095326183864547U;
            aOrbiterC = RotL64((aOrbiterC * 12645556660611824631U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17428384983571405782U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3193205313177048443U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14488006565106259731U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2813743367131107264U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2742138679703780981U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 18356569025783532225U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6270291142961043031U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3490174937775044998U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13879285210885619613U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13182535825771438942U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13047228760732694484U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 10365428317468779549U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17926326514553542739U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17019646486641172469U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 13978838314848228053U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 42U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 10U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 37U)) + aOrbiterI) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 50U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterG, 43U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_PickleBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF38C5E9CC1B7001BULL + 0x94402443C218530FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8B3B8290A8A370C5ULL + 0xDC5CFB02E68F0B8BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCAE9E3994932A007ULL + 0xE29C825B249F5336ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x96E6E58E599DA715ULL + 0xFA42E76CB925FAEDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF6F54B1C21C22A1FULL + 0x85170ECAE9080CC8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF6265B3C12DC7945ULL + 0xF2AA2DC105A03BC5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB1290F56953ED4A7ULL + 0xA887D3EEC75EDEADULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA302E7160CFB3A39ULL + 0xEC8035553133C598ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA37343780434ED05ULL + 0xFC38908C0F8ECFDDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD5753F6A5BB98173ULL + 0xDBBAF29522DB5B26ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD8848C4C00496065ULL + 0x80F12B527BF47EEFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x83835DFCDFC7E985ULL + 0x82E9628AFF42C1F3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBC2574AD60262B83ULL + 0xB3255E1615165E6DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE1F58921807C77BULL + 0xF86C7968D38AF8CBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE84E3983D25EC49DULL + 0xF178D7956BE3400FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB23F0AE4B23C8D7DULL + 0xE12470E6DAA7907BULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA, aExpandLaneA, aFireLaneD, aWorkLaneD, aExpandLaneB, aFireLaneB, aWorkLaneB, aExpandLaneC, aWorkLaneA, aWorkLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4491U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 5649U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4162U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7163U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8138U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 3744U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 14U)) + 10881271196314989997U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 5U)) + 6406461249988567558U) + aNonceWordC;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 17255067918280095959U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 19U)) + 16690850682497718411U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 38U)) + 5576201059361086866U;
            aOrbiterA = ((((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 11991259685693687554U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 14652535244217836909U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 43U)) + 1701789037170782122U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 953429054903473833U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12064513610469714211U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7993881398822002424U;
            aOrbiterJ = RotL64((aOrbiterJ * 11572884842788918377U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14421313768013320050U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11112386845630998889U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11771526352030371669U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17069630896535699015U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3308240081138623373U;
            aOrbiterF = RotL64((aOrbiterF * 10449509484417835159U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17615529807112933619U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11782807146851563541U;
            aOrbiterH = RotL64((aOrbiterH * 12992075832343669221U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14401645829607611983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6736397344219993532U;
            aOrbiterI = RotL64((aOrbiterI * 1667287547938175641U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6446974060524700550U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7840991992443308254U;
            aOrbiterE = RotL64((aOrbiterE * 6891023544882740107U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10362169906019794305U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4503700997923168911U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15066164494038852559U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13492041134973259041U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14337899277551397976U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 5966740718899290915U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13693100781608180748U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16177545026405910052U;
            aOrbiterD = RotL64((aOrbiterD * 6019231448444020563U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 36U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterI, 18U));
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + aNonceWordK);
            aWandererG = aWandererG + (((((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 53U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterH, 28U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9587U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 8296U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 13473U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14332U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16229U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15695U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + 11410829607777684449U) + aNonceWordA;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 21U)) + 7502698839700975347U;
            aOrbiterD = (aWandererH + RotL64(aCross, 60U)) + 13267685058252106173U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 238242706996630625U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 43U)) + 8184695499511454281U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + 12767823220461985403U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 11U)) + 12293198423143850330U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 11149495229952495939U) + aNonceWordM;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 35U)) + 7556992689338382800U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3431338808774134649U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16863099140844995099U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 752376661101787919U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17872458049880677604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16760153457252546974U;
            aOrbiterF = RotL64((aOrbiterF * 11225037229069712805U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3115544493537438408U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4359882942759752958U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 13387113067202396536U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12955690074544490161U;
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15614054443728226807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1939441328066616114U;
            aOrbiterJ = RotL64((aOrbiterJ * 4484917074808974359U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4599016263007782537U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9962305629016158048U;
            aOrbiterG = RotL64((aOrbiterG * 1496184427500037279U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8428467674122750557U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3938884087806393439U;
            aOrbiterE = RotL64((aOrbiterE * 12810531094050481761U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6018636830758044658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1510372000641305416U;
            aOrbiterB = RotL64((aOrbiterB * 9002834928626918247U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17592782466215337843U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8119921507606870360U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1299795061644535485U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 22U) + aOrbiterE) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + aNonceWordC);
            aWandererC = aWandererC + (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 4U)) + aOrbiterJ) + aNonceWordL);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22109U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 18861U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 22227U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20843U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19424U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20225U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererB + RotL64(aIngress, 5U)) + 12690502671561165478U) + aNonceWordC;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 38U)) + 17519943923428102801U) + aNonceWordE;
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 10705515807975331385U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 43U)) + 16586447272278538179U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 19U)) + 8006560996840971798U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 13U)) + 12928600185788857701U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 14240723153798267172U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 8636219177994872072U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 7586790235186467512U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1103807034179512424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7547526530239498693U;
            aOrbiterI = RotL64((aOrbiterI * 3360295583636013509U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8380239679344786397U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5690809173787433519U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5354724308093372953U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8390902801141804609U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3507306189192059486U;
            aOrbiterG = RotL64((aOrbiterG * 18336280496510253103U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6190745292098482871U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8065418693975056902U;
            aOrbiterJ = RotL64((aOrbiterJ * 6414621418430102589U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12111755051718111803U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7605877769709909297U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17525248694315944599U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5969794501112646237U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5127559299360591476U;
            aOrbiterF = RotL64((aOrbiterF * 4521563633438853069U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10593847754747739786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4401750688524310121U;
            aOrbiterC = RotL64((aOrbiterC * 14265829318976633707U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 6927893132508779499U) + aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4874009978647014479U;
            aOrbiterE = RotL64((aOrbiterE * 13340466017023540755U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13146693487138744677U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3298472134223595298U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2145005258008477281U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aScatter, 18U) + RotL64(aOrbiterC, 38U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 23U));
            aWandererE = aWandererE + ((RotL64(aIngress, 22U) + aOrbiterF) + RotL64(aOrbiterA, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 40U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30007U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 25969U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 32034U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31854U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25212U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29567U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 56U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 24U)) + 9888431329297626900U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 35U)) + 2937735167534624403U;
            aOrbiterC = (aWandererB + RotL64(aCross, 5U)) + 17626022970343789617U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 5665660859333693743U) + aNonceWordI;
            aOrbiterH = (aWandererE + RotL64(aCross, 43U)) + 1060537034632076669U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 19U)) + 743777763907175800U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 5744905970181808845U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 3545351394494002180U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 10U)) + 4877547088414106007U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11669378338379598445U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2961072441706158212U;
            aOrbiterC = RotL64((aOrbiterC * 2677988507090705371U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13984945589234919765U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1433097875470903205U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 451996840039906781U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 716415411025451152U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8542286150858297810U;
            aOrbiterE = RotL64((aOrbiterE * 9139015340823332449U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12932391786479661299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14005503313299177013U;
            aOrbiterJ = RotL64((aOrbiterJ * 802663466907819743U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9382792812676318046U) + aNonceWordB;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 5138554251079724724U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8522380066269546172U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11825536408101906458U;
            aOrbiterD = RotL64((aOrbiterD * 17042837108792016849U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15504062350899452495U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1219010998820336744U;
            aOrbiterI = RotL64((aOrbiterI * 10650635772711590803U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 6442717843380349632U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1047843426279085117U;
            aOrbiterG = RotL64((aOrbiterG * 4074561571072878005U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10611039527108679173U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5092816736177358221U;
            aOrbiterB = RotL64((aOrbiterB * 14342779343820140833U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 60U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aCross, 28U) + aOrbiterF) + RotL64(aOrbiterD, 18U)) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_PickleBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDDB27EC8BB4D9781ULL + 0xF4C3AEFA1BB6BE44ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF7AF99C9AF588073ULL + 0x993F819F28A6E944ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x861886E39A56ED9DULL + 0x853794B7E0C81A31ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE926A623846E308FULL + 0xC7B28F831556187EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDF514146560D3B75ULL + 0xF3486E37C041B86DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x99DC37E42D63D12DULL + 0xA482A092E3CAF155ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8900E024C2234229ULL + 0xAAF533F4ED54B092ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDC8BF846FB28EE6FULL + 0xCD42E64F7899CB82ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB46379CF8C222B87ULL + 0xE535E5873DF69900ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFC47DC0C081137CFULL + 0x8EEEC8B3C48C23DCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8D599CC2C6C8F565ULL + 0xD66F60CBC185CF2DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9AD76D664BCDA95BULL + 0xFCE5E5F772A82B02ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x992C1DCD5FBC655BULL + 0xBABB3310B26682D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCA46B221418C8A4DULL + 0xC1AC065A846C7434ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCD0CF5CDDFBA832DULL + 0xE188A6B3471BBB0CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEC68AD5BF6832BA9ULL + 0xEE633806CE2A78EDULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneD, aOperationLaneC, aExpandLaneB, aOperationLaneD, aFireLaneA, aExpandLaneC, aOperationLaneB, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7007U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 1996U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4790U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7339U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5553U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5963U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 37U)) + 701291026547470433U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 17283292650462111643U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 9969124091931303406U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 889176772718046988U) + aNonceWordI;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 29U)) + 6054541844643748084U) + aOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aWandererG + RotL64(aScatter, 43U)) + 14703226235143028132U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + 7977975878522921062U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16894322614172266274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12160451749345900570U;
            aOrbiterK = RotL64((aOrbiterK * 18055355572903901749U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10870847008043897470U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8159920947172520247U;
            aOrbiterI = RotL64((aOrbiterI * 4833194641611011805U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 2440099120969517932U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2428396147731468007U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9363073341539598441U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2213226274394673479U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7079731443427765333U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 16918930776877030559U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 958896789550478970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10788682955708075458U;
            aOrbiterB = RotL64((aOrbiterB * 913321215613559729U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 2003386579317564870U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8419686358774204999U;
            aOrbiterE = RotL64((aOrbiterE * 6547052526438697621U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6989167615157578904U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17636634003643824148U;
            aOrbiterC = RotL64((aOrbiterC * 11038576417283732937U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 44U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15656U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((aIndex + 11870U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10244U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14144U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10740U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 12905U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 11998579547770778580U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 35U)) + 8409465187298704610U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 3470222286110333500U) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 13U)) + 5704486785203069994U) + aNonceWordA;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 20U)) + 10334944660253279633U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 7626852700722567477U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 5U)) + 14631310754943209743U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 807160297237854120U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5624154783624196107U;
            aOrbiterA = RotL64((aOrbiterA * 2404066593958052159U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4971444394698940423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6340057638461027062U;
            aOrbiterJ = RotL64((aOrbiterJ * 12027586111086798629U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12766104026871797746U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5258212525426469978U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9956946981015983939U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8106382657040497669U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 10837606223056473999U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13292864885504191134U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4445739587553669471U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 166087925900318658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6786842221885441388U;
            aOrbiterE = RotL64((aOrbiterE * 4411147600413147773U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 56U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 56U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 29U)) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterF, 41U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23659U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 18044U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 21397U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20894U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22934U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20639U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 7825479804710770560U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 5298124167101358123U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 17774541024369233726U) + aNonceWordH;
            aOrbiterB = ((aWandererB + RotL64(aCross, 57U)) + 7679371833537454082U) + aNonceWordN;
            aOrbiterF = (aWandererG + RotL64(aScatter, 47U)) + 5385914900748772224U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 41U)) + 3879781930908486531U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 11U)) + 659110346638873236U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10749021728538539749U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3631252455767429457U;
            aOrbiterD = RotL64((aOrbiterD * 8552825360915119613U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2271978810960685021U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5963558780692551176U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 4772055335210781149U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 974909966119198104U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9296998242911152296U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2245318466901521959U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13391076374843288568U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18094558036982107419U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6184487746594236737U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1563385912137291418U;
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1744840092006498629U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 2100927276837188416U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3541788262067077997U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 9998911862807246338U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12239948725635220096U;
            aOrbiterF = RotL64((aOrbiterF * 7098620484129489129U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 20U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterI, 53U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterD, 4U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 19U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererH = aWandererH + (((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 5U)) + aNonceWordO) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32376U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 25366U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 31731U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31574U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29509U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24780U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 43U)) + 9023059520606551446U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 11U)) + 662441755115638133U) + aOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 35U)) + 16957253361196144712U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 7840955025765308605U) + aNonceWordB;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 346855809270395799U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 27U)) + 16099139781586668343U) + aNonceWordO;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 3706457327118322098U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12166825885547622870U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7792658665720344200U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16305542632794270697U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 7128477606152986326U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11116533962780290084U;
            aOrbiterK = RotL64((aOrbiterK * 11993485572912492297U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10443889548568288532U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4402387036946561017U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9032964741841833277U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13002706161178447654U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13929727277530310708U;
            aOrbiterC = RotL64((aOrbiterC * 7005639090871200285U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10949073760696935106U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15405923432006783533U;
            aOrbiterF = RotL64((aOrbiterF * 17989565878445202495U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18096057968822208905U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3032155040484574973U;
            aOrbiterG = RotL64((aOrbiterG * 448597307502544605U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17462076466907467134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15471015427013701406U;
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 39U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterC, 20U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PickleBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x81FE0F237387E6C9ULL + 0xA96066B3C8B04AC3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xABE4E7A1FFA1BAA5ULL + 0xEA494ADBD5FC105DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD67EDEB7D6006685ULL + 0xF385564752AC0CFFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xACF2799BB9F50457ULL + 0xE605742AA57A4898ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF73000BB74E64749ULL + 0xA22E760A808A5BD2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8E84A19476CDBB63ULL + 0xF9176106F5D22D7BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA202824635BFC2A9ULL + 0xE80F72666E89C48CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD6ABDC58E3486ADBULL + 0xC8942C79C00A6F3EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9A1B396970BE3B45ULL + 0xDDC9E8F12D2BBA79ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB13E26013F4021F5ULL + 0xDB841BFBE68CE657ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB2098FCCE8F32909ULL + 0xF2B6AB343E19DBDFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDA39E4240FD5CFABULL + 0xF9C49232A5D51541ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCA366BF2D8D7634DULL + 0x82363ACD4B71D829ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCAA0F68D2C8B14A5ULL + 0x8A0BEF72582C1F18ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x954C6BDA39033105ULL + 0xF40E67B845A1CCCEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8D3EACB806644E65ULL + 0xC2DDF0D8150115FBULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2574U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1118U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 422U)) & W_KEY1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1471U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 26U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + 13924571355038625040U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 16328300979357156658U) + aNonceWordD;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 20U)) + 3947771961206012461U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 15428284250569311285U) + aNonceWordN;
            aOrbiterI = (aWandererF + RotL64(aIngress, 39U)) + 5777369485254032486U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 16813320300717644673U) + aNonceWordA;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 47U)) + 16689933050200758251U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1856422419049390708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18214498743831925517U;
            aOrbiterD = RotL64((aOrbiterD * 10744120577560529379U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 18278550878494094923U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 797712062039591797U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 7212998747080137625U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15854849439012341347U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 996882939768167773U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14936703950807908575U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3005829974130671692U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8793495343509953906U;
            aOrbiterC = RotL64((aOrbiterC * 14065479348374612031U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7710453029930631112U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9511995836117707047U;
            aOrbiterF = RotL64((aOrbiterF * 7250766204781428201U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 670902975693341744U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9045820304668279777U;
            aOrbiterA = RotL64((aOrbiterA * 18373074917532639027U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12417212387607119470U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 12816983560669985622U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8406003970221889847U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 6U);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterG, 20U));
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5172U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4520U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3597U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 4144U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 19U)) + 479672811032092393U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 18061121631394564425U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 14237400452740566065U) + aNonceWordK;
            aOrbiterA = (aWandererK + RotL64(aIngress, 11U)) + 6723123812257706134U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 57U)) + 4247997188026499248U) + aPhaseEOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 1939107415066134869U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 3U)) + 3912640123546395979U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8295478436553964298U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3218960600711526885U;
            aOrbiterI = RotL64((aOrbiterI * 15443507655470278069U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5874096203353388890U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10294536533673023358U;
            aOrbiterG = RotL64((aOrbiterG * 15561710414949058923U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11268561953904130747U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16693201256788898423U;
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7550969634681894654U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9501647424602245869U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8881869255994319423U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16770136406906800016U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 1782039587385512923U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16185384746435761363U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13841034186650721627U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12000155593277035447U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15229062695864608309U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 3576122704615303733U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2433987493885779279U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 44U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + aNonceWordH) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7124U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5575U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7617U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6406U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6670U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 3684295017013759987U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 27U)) + 6740408842457292881U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 4563975890702399441U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 3U)) + 797804144825287940U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 11U)) + 2763779540450101303U) + aNonceWordE;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 21U)) + 13211846164102089685U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 15214578447281401982U) + aNonceWordL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13745208628754232427U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17358621225969190747U;
            aOrbiterG = RotL64((aOrbiterG * 5325024317338823061U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 779739369960480023U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4370963533701407813U;
            aOrbiterI = RotL64((aOrbiterI * 3123135216876641039U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6061333005507739975U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3589705340762734456U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16499293983611196967U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10607697666369230567U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 9356757995305239271U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 10945513661439954731U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10093033335903048138U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 558431161176115540U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17795680919453449358U;
            aOrbiterJ = RotL64((aOrbiterJ * 3910117359996283803U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 6096779391116214109U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17594243286880690775U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12655610181937429915U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererA = aWandererA + (((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterI, 21U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 12U)) + aOrbiterG) + aNonceWordC);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 43U)) + aNonceWordO) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 10529U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 8517U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 8597U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10429U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9798U)) & W_KEY1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8568U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 57U)) + 16016931609704150191U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 14511433515861302636U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 11691237442613269593U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + 16383220587320484649U) + aNonceWordJ;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 29U)) + 14293015313458219868U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 4407695248205526670U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 40U)) + 1158323195324398372U) + aNonceWordH;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6577683409653864555U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 171080079472863843U;
            aOrbiterD = RotL64((aOrbiterD * 3063978974927752653U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5766333425872228205U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16173508656917582960U;
            aOrbiterG = RotL64((aOrbiterG * 12187968015372936695U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11781450063402219202U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13033139686637576694U;
            aOrbiterF = RotL64((aOrbiterF * 4331137994135472025U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4006310759400926020U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13156817947481574467U;
            aOrbiterJ = RotL64((aOrbiterJ * 563189239835001483U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12791290558893516411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 989729955679243234U;
            aOrbiterC = RotL64((aOrbiterC * 8757228712495095017U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 838379839663022790U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2830743864262313606U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 10173947177104802797U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2146646527331684652U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4629168181742174906U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9046124907945045131U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 36U)) + aOrbiterF);
            aWandererB = aWandererB + (((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 23U)) + aNonceWordB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aCross, 46U) + RotL64(aOrbiterF, 29U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13520U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 12727U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12407U)) & W_KEY1], 27U) ^ RotL64(mSource[((aIndex + 11500U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13519U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13168U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12806U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (((aWandererE + RotL64(aCross, 13U)) + 11998579547770778580U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 8409465187298704610U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 3470222286110333500U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 5704486785203069994U) + aNonceWordL;
            aOrbiterC = (aWandererC + RotL64(aIngress, 51U)) + 10334944660253279633U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 19U)) + 7626852700722567477U) + aNonceWordO;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 23U)) + 14631310754943209743U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 807160297237854120U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 5624154783624196107U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 2404066593958052159U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4971444394698940423U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6340057638461027062U;
            aOrbiterF = RotL64((aOrbiterF * 12027586111086798629U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9003019862787819481U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12766104026871797746U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4062118445824915939U;
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5258212525426469978U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 9956946981015983939U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 8106382657040497669U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10837606223056473999U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 13292864885504191134U;
            aOrbiterK = RotL64((aOrbiterK * 4445739587553669471U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 166087925900318658U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6786842221885441388U;
            aOrbiterB = RotL64((aOrbiterB * 4411147600413147773U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 46U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 26U)) + aNonceWordH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15284U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 14976U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16344U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15395U)) & W_KEY1], 56U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16213U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16142U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 16371U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 6973892330986118220U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 12U)) + 9886813896272094864U) + aNonceWordB;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 29U)) + 10996306582517553173U) + aPhaseFOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + 8490648283899856223U) + aNonceWordL;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 19U)) + 105141713530704655U;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 3114337422810562588U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 980857684690886131U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6562042345807072665U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15665371138706353619U;
            aOrbiterC = RotL64((aOrbiterC * 8086237578564620623U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 18113013571374375028U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17405346422601997299U;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 5130876096426182506U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1813821672299154629U;
            aOrbiterK = RotL64((aOrbiterK * 15478100342425611875U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15793814882743306728U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13925299440495476399U;
            aOrbiterH = RotL64((aOrbiterH * 12049601510660117401U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9924458846049579438U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7810034662781768090U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10310594595026622513U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12812586478656872854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5709576448057435237U;
            aOrbiterJ = RotL64((aOrbiterJ * 9101555233909853025U), 43U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 7839807649914541516U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4717944526755429647U;
            aOrbiterF = RotL64((aOrbiterF * 8515229146471335721U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 12U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterE, 12U)) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18579U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 18613U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 17250U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16511U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17566U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17415U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17469U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = (aWandererA + RotL64(aIngress, 21U)) + 6318740973868639425U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 13U)) + 5487840061430920881U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 36U)) + 10258706763248072672U) + aPhaseGOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 18356875269730338208U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 12883160282903147010U) + aNonceWordM;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 1010140474942697730U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 17733939421700898293U) + aPhaseGOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13693055887924981201U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14574732452793385269U;
            aOrbiterF = RotL64((aOrbiterF * 9373765929885750185U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10832873941223609012U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8212600587135328040U;
            aOrbiterH = RotL64((aOrbiterH * 5334613996794796145U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5312744319781971178U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6173741211706546923U;
            aOrbiterE = RotL64((aOrbiterE * 12854414066390848249U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3693249147883790810U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 18365859989736602556U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 3348463719324104997U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 10645056678337549771U) + aNonceWordG;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 1175668356822251045U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6579675292775345579U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13556844570541823717U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4790355739411849736U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4083544011788850307U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14905575502272644116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17047244574558476634U;
            aOrbiterK = RotL64((aOrbiterK * 2356386971503880047U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 20U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aNonceWordL) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aNonceWordN) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 38U)) + aOrbiterH) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20525U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 20281U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20282U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 19868U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21786U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20062U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19252U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 21458U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 23U)) + 1557680213571812384U) + aNonceWordE;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 54U)) + 7387349725778021121U;
            aOrbiterG = ((((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 15379264067601586976U) + aPhaseGOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aCross, 35U)) + 3730195724576043708U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 9637070085323827066U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 1170865717363676184U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 2750833653175252030U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15118992811225568305U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4974092922102988451U;
            aOrbiterG = RotL64((aOrbiterG * 10575977398702460975U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10625719096296719514U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 855167122475471865U;
            aOrbiterC = RotL64((aOrbiterC * 7441090331293158773U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11322911068958340262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4334591909425429835U;
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14263701737208936392U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 678723206735649084U;
            aOrbiterJ = RotL64((aOrbiterJ * 10823239851733632227U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15652053114252065230U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1705225940224061401U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 3626023093533713579U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6826394665732900206U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11902946775066981141U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18300629262162694137U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9802212958998591310U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14001358545610206524U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13172645840788327099U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 56U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + aNonceWordB) + aPhaseGWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 46U)) + aPhaseGWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24265U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 22087U)) & W_KEY1], 54U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23051U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23686U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22539U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23843U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22663U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22049U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 13U)) + 13687218104610230596U) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 6841550124960692709U;
            aOrbiterD = ((((aWandererI + RotL64(aPrevious, 20U)) + RotL64(aCarry, 23U)) + 17418968668458764131U) + aPhaseGOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 8303537912696948204U) + aNonceWordJ;
            aOrbiterG = (aWandererK + RotL64(aIngress, 47U)) + 12376614417285936537U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 3U)) + 14215749063579232654U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 53U)) + 4111736931433665347U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11250375934571631522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5367367837773331275U;
            aOrbiterD = RotL64((aOrbiterD * 7262723007545807179U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15514089192382674434U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1475991716685034960U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17720681295551650891U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5531622777788629748U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8363822215908303335U;
            aOrbiterK = RotL64((aOrbiterK * 17850203366840994883U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3741256932685720414U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11634667238062155772U;
            aOrbiterF = RotL64((aOrbiterF * 15925089729784547403U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18180546911210417155U) + aNonceWordK;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 5123234656838556335U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 15362857462853398025U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 11215734271189250284U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16863747802158398092U;
            aOrbiterA = RotL64((aOrbiterA * 1828035970246160023U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9859050606636646323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9331300036643654675U;
            aOrbiterJ = RotL64((aOrbiterJ * 2502263410556166281U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 48U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 26U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + aNonceWordF) + aPhaseGWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 34U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26479U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 26363U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24995U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 26260U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26743U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27162U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25013U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27109U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 57U)) + 3561491146322798260U) + aNonceWordH;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 7075025056181885339U) + aNonceWordJ;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 27U)) + 9230910887904171613U) + aNonceWordK;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 13U)) + 4119781172609908917U;
            aOrbiterC = ((((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 17155609083870983149U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 6U)) + RotL64(aCarry, 29U)) + 2423018561430181695U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 47U)) + 12957280305617615744U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2461704174772065813U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7907123257849391997U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9416171962847312179U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7257868138318960007U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16425903703085702285U;
            aOrbiterI = RotL64((aOrbiterI * 7996935869077231999U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2990822664594079467U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5654819006718953817U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 4465096036756887801U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 12183676471235678779U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15026286960542123922U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17199049329995315279U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12169080607071830522U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2906296852254787499U;
            aOrbiterC = RotL64((aOrbiterC * 6754514406846040163U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3029858695410344584U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14406410317495954566U;
            aOrbiterA = RotL64((aOrbiterA * 9663780721657983421U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11048818178401163861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13622063920319445043U;
            aOrbiterH = RotL64((aOrbiterH * 2516025554421589857U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterH, 27U)) + aNonceWordL) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 34U)) + aNonceWordF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27819U)) & S_BLOCK1], 28U) ^ RotL64(aFireLaneD[((aIndex + 27696U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28871U)) & W_KEY1], 53U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29332U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28714U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29125U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29222U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 28250U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 4U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 2571116506511057880U) + aNonceWordJ;
            aOrbiterF = (aWandererG + RotL64(aCross, 56U)) + 13112435411509707292U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 10403251762787357256U) + aNonceWordC;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 8461951095541400405U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 5U)) + 9890793478557463815U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererB + RotL64(aCross, 19U)) + 3030229465991783707U) + aNonceWordM;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 35U)) + 7273848154043719247U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10681774862516028276U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7105082755586853104U;
            aOrbiterH = RotL64((aOrbiterH * 12217705329504230357U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 6588579345319551129U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14616333550242386092U;
            aOrbiterJ = RotL64((aOrbiterJ * 2934574715879306337U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15439666290229654921U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3360304356760164799U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 5164191920584106237U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14438730801970761889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14515616787452085729U;
            aOrbiterE = RotL64((aOrbiterE * 2041601927968559821U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4167853822635132419U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8950982233003320239U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 887144270884244907U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12391327853728029953U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7100871010552394421U;
            aOrbiterK = RotL64((aOrbiterK * 16552349374101955967U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15381697462381887944U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6801677551341079401U;
            aOrbiterF = RotL64((aOrbiterF * 13325954438427340703U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 44U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterD, 12U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aNonceWordP) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 50U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32526U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadA[((aIndex + 30391U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30174U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32183U)) & S_BLOCK1], 26U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30408U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 30455U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 20U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 29U)) + 17912271996338180948U) + aNonceWordC;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 47U)) + 13259276608841847058U) + aNonceWordB;
            aOrbiterF = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 16225936008657276089U) + aNonceWordE;
            aOrbiterB = (aWandererC + RotL64(aIngress, 13U)) + 2243058962151834071U;
            aOrbiterI = ((((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 10637439274127347861U) + aPhaseHOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 54U)) + 15312219216405992627U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 2393933972129878613U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4327069337247976513U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8307656353434167837U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 11386588389133096705U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17299145556933889336U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14458100581172798164U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16543734663677070509U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6410095654927998067U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6168964796264687686U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16218071040190475953U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3667999465041020730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16021552859323602007U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12941668202330045095U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4222032891850449934U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17292856787431308097U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1346342592002730785U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16860611785008118820U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 384963420804756607U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3193572711804730241U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5866881282680588589U;
            aOrbiterC = RotL64((aOrbiterC * 9226331800853634597U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aNonceWordK) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 60U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 51U);
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

void TwistExpander_PickleBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8528EF0C8D1E9EFDULL + 0xDFDE427F11A410F7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA7B363CDB2A6D2E5ULL + 0x8E2D71ED44B3C7BCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAE1C48D32D416E73ULL + 0x97284F4048F1D16DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFA3DC80197E2E4ABULL + 0xD01F3C2F42B7A51BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE197972C8EF50F75ULL + 0x9135FFAEB07B0F4AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA15BB7E998E33947ULL + 0x8A3EAC0799AFE271ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCAA19358F2292049ULL + 0xCC4E190E43477C4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC7F0054F4E9E6F4FULL + 0x810A0626F29A1A02ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE3B7A2050DB7A413ULL + 0xB44BBDBC234B4FBBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFF9C0B03919A2239ULL + 0xF68479025F19A003ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC321EA4CEA140C4FULL + 0xD55D1F29C74D8DC4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC96DA4348035A93FULL + 0xB77D02FDC3480447ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE97FEF1D7E09E8A7ULL + 0xECF26829B72DBEC6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCD32B1B7D6508A9FULL + 0xD3234876AFD6B949ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFB8644078FC11D43ULL + 0xBBF0101FA465DC8AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAA1D76241F43C07BULL + 0xFA8A18E5F1F8F3C9ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneD, aInvestLaneB, aFireLaneC, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3827U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 4137U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 34U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4273U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 2515U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 58U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 9220392006207660113U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 11305018553489132882U) + aNonceWordK;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 35U)) + 5860373868073513684U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 19U)) + 12319586170883987589U) + aNonceWordI;
            aOrbiterF = ((aWandererF + RotL64(aCross, 13U)) + 14072333614354649021U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9332158529453194608U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3860569321145958686U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 907977527866467591U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8119005668901240093U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13918259792880333239U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 5441062406822088853U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6938856216758228704U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3960905839118710604U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16203746868670689793U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6043879193734253929U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15691425268831319195U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 7189195135654636271U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14912209933584715274U) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16180183395910618923U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3942858974766467849U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 30U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterH, 5U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + aPhaseAWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8731U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 8783U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9411U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7722U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5815U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 18U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 56U)) + RotL64(aCarry, 37U)) + 1142447269198373880U) + aNonceWordM;
            aOrbiterG = (aWandererD + RotL64(aScatter, 3U)) + 10581460640040336191U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 11U)) + 14703062773878202900U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 15737525756286914746U) + aNonceWordH;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 16178774478273186999U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2514897053906809160U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13702496607592508464U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 16540143680974064057U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18030885275418337965U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5241783876161655984U;
            aOrbiterB = RotL64((aOrbiterB * 10970981186787227937U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2807052676283587925U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8022804576763271327U;
            aOrbiterG = RotL64((aOrbiterG * 11727096043219370577U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 15597099852232205860U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 1538435607932096400U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 7900752511710516981U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11147868774413615365U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9325213746830411568U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 561819005818948769U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 47U)) + aNonceWordI) + aPhaseAWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aNonceWordD) + aPhaseAWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14711U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 11970U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11665U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 16067U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14417U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14637U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 13333509828310369865U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 42U)) + 7645352517103840797U) + aNonceWordD;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 29U)) + 5310766306660062655U) + aPhaseAOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 5165635069832352932U;
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 15684141764734281849U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 3327963374225061738U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8625811794878848871U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16327750494894125333U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7598657468430485291U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 2881171216276746485U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 3331350584102843605U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10237691227222918101U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6419254255884834497U;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4238455444646479956U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14936613353493061492U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 3544216916806292273U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15324699725208372627U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9506640480601832011U;
            aOrbiterC = RotL64((aOrbiterC * 12819564111348390227U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 28U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18622U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((aIndex + 17351U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 20400U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18961U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21548U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17786U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 54U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = (((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 12669015908335980355U) + aNonceWordE;
            aOrbiterG = ((((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 5438715179868613192U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 13172104448184536460U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 13421421503244744803U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 3U)) + 13327113302994856582U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4671768205922454413U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5355759962838579929U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15080379163499722187U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6691720614265406851U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7063906424700911378U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17091734375516280675U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17328616394166672263U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1542940602574207068U;
            aOrbiterG = RotL64((aOrbiterG * 8981679306319627975U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 7203866278803132454U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 993485696233139264U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11609009908810366447U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15659679028507488331U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18321361454094675842U;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 12U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordL) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aNonceWordC) + aPhaseAWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererE, 20U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23637U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 24521U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23312U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26667U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23127U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 26956U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 43U)) + 8685374557928800912U) + aNonceWordC;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 3482312691892161229U) + aNonceWordB;
            aOrbiterE = ((((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 51U)) + 6948130297389161165U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 5506385663788942690U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererD + RotL64(aIngress, 23U)) + 17859982009307397161U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9178488809207094043U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1835479501226057169U;
            aOrbiterE = RotL64((aOrbiterE * 5671861318767342087U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5368101733632614939U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9050459666576835422U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10351719549990259551U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9042186993119635078U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17528342580198295025U;
            aOrbiterJ = RotL64((aOrbiterJ * 14316671546614386775U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 6495418332558436882U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8834495762667327342U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 10783141541937645995U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4364314196965690905U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6357485231062120459U;
            aOrbiterD = RotL64((aOrbiterD * 289429584586504995U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + aNonceWordE) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29706U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 29346U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28588U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31103U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32547U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 29018U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 14U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 2330952702412094686U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 13U)) + 7820188225935060799U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 11U)) + 9347644591709839145U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 2288624878446846870U) + aNonceWordJ;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 3U)) + 9358977729492824128U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1858511275052455039U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13715478509322292552U;
            aOrbiterE = RotL64((aOrbiterE * 15552121744869003235U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16413396625604260455U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17714322215518432705U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 1904184102419934333U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16188315436202861122U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5564445841368207813U;
            aOrbiterG = RotL64((aOrbiterG * 14125834616162835983U), 19U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 13717068949900594673U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 5729546141908425670U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 4297827922736712074U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 13631630436759768885U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + aNonceWordI);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + aNonceWordK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 4U) + RotL64(aOrbiterK, 58U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_PickleBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF6B9A86284ACDE09ULL + 0xDCB210E51D90B3CDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C60A7BB1F0329D3ULL + 0xED1932374BDFA73EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB21C53335996D2BFULL + 0xCFAC382CCB7D3C1FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD19B8D75F6F95A2DULL + 0xAAF2CB1C211AD6CDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE20EBCF787C49DF3ULL + 0xB19CA26E725FDF91ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9B038343E53A78BFULL + 0xFC25D0CDF5F1439EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC6C6B4D865EFEEFFULL + 0x94650F58D30A2C8EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xABA4A27BC2C54271ULL + 0x83D3C7C14A3A6285ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDAC4E57DEFC6C961ULL + 0xD531AA9AD8478878ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD7DD5765357DB8C1ULL + 0xCE27B8A3CC28B650ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xED2E72FB6C470317ULL + 0x8D6E3A22C4D65B76ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC3A6D98C8D30284DULL + 0xB7B36D08E75D736EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFD1CEC99FA0CE661ULL + 0xA4959D8E5C5E445BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCB960D5B622398B3ULL + 0x89438F9BA7B900EAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8E838E42487FFF4BULL + 0x9D58E2FB82A2F12EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE0906363B0655083ULL + 0x8799FB89FBA9FA4AULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aFireLaneC, aInvestLaneC, aFireLaneB, aExpandLaneC, aInvestLaneD, aFireLaneA, aWorkLaneA, aExpandLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1137U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 4279U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 2117U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2377U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 292U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 4624U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 14U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 35U)) + 2558105147674438050U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 12U)) + 15856662514774702561U) + aNonceWordJ;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 13346869226246584582U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + 7632111846116243973U) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + 2102101361626976279U) + aNonceWordF;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 50U)) + 5605968705067851563U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 6842483186584326681U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 5559797213819425064U) + aNonceWordH;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 3U)) + 12422313931331576759U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2751024420047872601U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11031320239359798610U;
            aOrbiterE = RotL64((aOrbiterE * 8607639453141148025U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14366375309473793217U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11971479429768505316U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3947595951884469542U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterH = RotL64((aOrbiterH * 3361906348965810211U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 513871456983509223U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 5951677013597794294U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 8508629569649935293U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 437626309049021931U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 466674061172005705U;
            aOrbiterD = RotL64((aOrbiterD * 1310502572084891157U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12362602809233133718U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10525852878882195702U;
            aOrbiterK = RotL64((aOrbiterK * 17755022180514914325U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17927000184308583095U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 566723721423470052U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17710534355278632573U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9504585484034413577U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4614306037721859929U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 170807293799483539U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1463218357720031588U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4036696102163560633U;
            aOrbiterJ = RotL64((aOrbiterJ * 15389914226155130065U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterJ, 48U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordC);
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aNonceWordL) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 14U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8786U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneC[((aIndex + 7878U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10501U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8342U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9235U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7964U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8093U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 39U)) + 11700815697312060726U) + aNonceWordB;
            aOrbiterC = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 11808423452327465441U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 51U)) + 8670503858631730886U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 2400061067991988544U) + aNonceWordK;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 16163118178366229686U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 23U)) + 3280178595904941068U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 18U)) + 3298683600817047727U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 11U)) + 16321624053445183574U) + aNonceWordI;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 47U)) + 6730229877611375225U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10162830636713641322U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15646771327759599256U;
            aOrbiterE = RotL64((aOrbiterE * 15333053762177144775U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14841751262270544102U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9545541117228834895U;
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14676615635857599982U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 1231768638470558855U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1945905595345404833U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterJ = RotL64((aOrbiterJ * 4577864352425476233U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1970292335806697198U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12309719390375013297U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16540660957923687327U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5352135521358954576U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15465675376193501658U;
            aOrbiterA = RotL64((aOrbiterA * 16385761112921041387U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2842123638916600369U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3544764287036748668U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 3360772950777850115U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6038297172906492282U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10249342332287140970U;
            aOrbiterD = RotL64((aOrbiterD * 16701083081566042277U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1662076777040529446U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1949705569959740274U;
            aOrbiterH = RotL64((aOrbiterH * 11340691546658994529U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 56U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterF, 43U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + aNonceWordD) + aPhaseBWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterJ, 14U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneA
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13512U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 16152U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15127U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11272U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 11992U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 6U)) + 77518479758428414U) + aNonceWordH;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 4832061802166300011U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 43U)) + 11695291171006574112U) + aPhaseBOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 7467412817843260094U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 47U)) + 17801484124471154757U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aIngress, 35U)) + 5555455638503958639U) + aNonceWordI;
            aOrbiterB = (aWandererC + RotL64(aCross, 14U)) + 5669470540733721606U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 19U)) + 3042388456327784163U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 2236734925228156691U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14459720401528685450U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4814967631216658856U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 18288097536171386643U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16950679344449075945U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterC = RotL64((aOrbiterC * 9942659897425088183U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3522256359074996724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterJ = RotL64((aOrbiterJ * 6787771338063891989U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13891759914865623828U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11910250571469028666U;
            aOrbiterB = RotL64((aOrbiterB * 12311343917878428995U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2240189915640314069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5365912986308810837U;
            aOrbiterE = RotL64((aOrbiterE * 15133972552032469957U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 9323732721344489753U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13087326560957916553U;
            aOrbiterF = RotL64((aOrbiterF * 14659491687401151733U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16398238057564892809U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11517870519285159224U;
            aOrbiterK = RotL64((aOrbiterK * 1501848878469712681U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7758285512254776734U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17475149091906684720U;
            aOrbiterH = RotL64((aOrbiterH * 6015816725428299273U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2051631493975035243U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11684740065349595315U;
            aOrbiterG = RotL64((aOrbiterG * 10918975496337269197U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 6U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + aNonceWordM) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterA, 19U));
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 12U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterB, 60U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneA
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16695U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneC[((aIndex + 19700U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 19747U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16407U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20302U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 23U)) + 5171470532667965920U) + aNonceWordC;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 35U)) + 750549462358682403U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 58U)) + 3325689257577120525U;
            aOrbiterB = ((((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 18031575461559790826U) + aPhaseBOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 29U)) + 13874739537012288677U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 4250029868785016865U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 3U)) + 8211158803112611161U) + aNonceWordL;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 1083939790236786027U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 48U)) + 3446525462376962464U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6973817815000417325U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15230876489676945543U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7737039082964537651U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9359727659738755880U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterJ = RotL64((aOrbiterJ * 6910680458261008653U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11958941755525038545U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16966819714283167348U;
            aOrbiterI = RotL64((aOrbiterI * 16363457661846050749U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14556087985619763243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17915047508377045221U;
            aOrbiterE = RotL64((aOrbiterE * 6727635453185130109U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8578745677485367222U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7002181668717618866U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12329703532414955235U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3569939503066735457U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2956247934282522184U;
            aOrbiterK = RotL64((aOrbiterK * 9946650822131152531U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4285180013402474041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5976239869535619811U;
            aOrbiterF = RotL64((aOrbiterF * 3458095419039067465U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 2424524955161695463U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6849595426583763537U;
            aOrbiterC = RotL64((aOrbiterC * 12727902040238318101U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11414890686374886716U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5668287266836153445U;
            aOrbiterB = RotL64((aOrbiterB * 8011885266143066285U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 28U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 47U)) + aOrbiterD) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 12U) + RotL64(aOrbiterK, 52U)) + aOrbiterG) + aNonceWordO);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + aNonceWordD) + aPhaseBWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + aNonceWordI) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22666U)) & S_BLOCK1], 50U) ^ RotL64(aInvestLaneD[((aIndex + 26011U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23018U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24877U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 24205U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 6U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererK + RotL64(aIngress, 6U)) + 15316464782468770057U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 29U)) + 6642872057476351588U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 43U)) + 660732654689529192U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 51U)) + 7235418086884000655U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14784518476694580493U;
            aOrbiterA = (((aWandererD + RotL64(aCross, 24U)) + RotL64(aCarry, 29U)) + 12222433977933449375U) + aNonceWordL;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 8573001207708329927U) + aPhaseBOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 19U)) + 16035256260815013172U) + aNonceWordD;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 13U)) + 15767726974121910203U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17712217935322939971U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13488963456923357159U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16785285630840310405U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10222949131965611079U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1495561412321657209U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9706305581868526265U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16156530750584361434U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7773792489045606309U;
            aOrbiterA = RotL64((aOrbiterA * 10730624207715601393U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11544578291333360613U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3665587867634242865U;
            aOrbiterG = RotL64((aOrbiterG * 4840528190844842595U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15248434984650998090U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15487979645426567581U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 10868107809356766183U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6972347795052712690U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16074994810010431338U;
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16851139687900415292U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14630026837021552812U;
            aOrbiterH = RotL64((aOrbiterH * 9577900853521254603U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14236330619137368169U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17778707026111136216U;
            aOrbiterC = RotL64((aOrbiterC * 16239561893843454747U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9390961969105999083U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1174881758316573228U;
            aOrbiterD = RotL64((aOrbiterD * 6602061268277529311U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 42U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + aNonceWordI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 11U)) + aPhaseBWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 37U));
            aWandererB = aWandererB + ((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterG, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterC, 30U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + aNonceWordC) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32117U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 29960U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 30781U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29351U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31106U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 5U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 3550722402315312207U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 14U)) + 16724184551669522754U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 23U)) + 981751330116773021U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 43U)) + 7891159229704944868U) + aPhaseBOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 5U)) + 13618396711464799841U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 5969291018449003648U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 14595540413313640042U) + aNonceWordE;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 3287990436916111762U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 52U)) + 12534369400200483704U) + aPhaseBOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2277312067930392274U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10026320559261334353U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11020464940995912637U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11258082063135659551U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1445958517675746990U;
            aOrbiterC = RotL64((aOrbiterC * 10062265337488757971U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1011298251290970844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9966279022928268335U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10285993486057704393U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15965714363201157535U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16005362468813966136U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 223843444699390781U;
            aOrbiterF = RotL64((aOrbiterF * 665392038954573081U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 18178876294968532775U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12490136112181806806U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16380841616662993709U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8775696166557913635U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16464340319444310842U;
            aOrbiterA = RotL64((aOrbiterA * 18111632334728200721U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6296039992673546227U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7152939277656436037U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 15183918431501487319U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14066791413416223271U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5026743227399908016U;
            aOrbiterD = RotL64((aOrbiterD * 5891343232759075675U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 56U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordA);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aPhaseBWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 14U)) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 41U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
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

void TwistExpander_PickleBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x87C36D806364D261ULL + 0xB4A0DB3A3EEE1F71ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE2875133E7A9CE8BULL + 0x8CB2DEE0445684A0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCD2F48023B7FAE4DULL + 0xDE537F02E9D6C8CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB76FC5A21C6DEEE1ULL + 0x847C0E4FDD2927FFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCB6EBB20120932DFULL + 0x827EC0C33F177845ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE143E6767E8DE913ULL + 0xA5A3C0414C152440ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCE75FDE6CFA44A87ULL + 0xC1398D2D7F09A813ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8219C7BCB0F4D5B1ULL + 0xFEBCA57578AF402CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x98C4FEA2BE2BD2C3ULL + 0xEB6CD83E599214D5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF24838696B457B8DULL + 0xB71DF4BAC217A33AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8817D7F0220DFB51ULL + 0x9FE798B1B03FE5A4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8EC8EAD6B02FD14BULL + 0xAEC0C8BDCD8DEC11ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD7AA4FB141CEE1C1ULL + 0xB2483DF8B2006A77ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x87772E3A1147645DULL + 0xE528E793270C6402ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8F135835E9967ED3ULL + 0x934701836604E102ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCF8CAF9DCFE05821ULL + 0x83B99E021B031D10ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 426U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 3255U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 3931U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 446U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5241U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 4556U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 34U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 5U)) + 15316464782468770057U) + aPhaseDOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererH + RotL64(aCross, 27U)) + 6642872057476351588U) + aNonceWordF;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 660732654689529192U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 7235418086884000655U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 37U)) + 14784518476694580493U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aCross, 56U)) + RotL64(aCarry, 5U)) + 12222433977933449375U) + aNonceWordM;
            aOrbiterG = (aWandererI + RotL64(aIngress, 47U)) + 8573001207708329927U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16035256260815013172U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15767726974121910203U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 719060452537759331U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17712217935322939971U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13488963456923357159U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16785285630840310405U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10222949131965611079U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1495561412321657209U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9706305581868526265U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16156530750584361434U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7773792489045606309U;
            aOrbiterB = RotL64((aOrbiterB * 10730624207715601393U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11544578291333360613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3665587867634242865U;
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15248434984650998090U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 15487979645426567581U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 10868107809356766183U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6972347795052712690U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16074994810010431338U;
            aOrbiterC = RotL64((aOrbiterC * 1262655238856775853U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + aNonceWordP) + aPhaseDWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 58U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 13U)) + aOrbiterA) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6559U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 6283U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5521U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 10629U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9386U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9464U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 8866U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 3U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 18255347001097480328U) + aNonceWordM;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 13679246790311505735U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 23U)) + 10565839529765027116U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 53U)) + 14327172566224769901U) + aNonceWordI;
            aOrbiterB = ((aWandererH + RotL64(aCross, 35U)) + 16239024612038195174U) + aNonceWordK;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 47U)) + 13800012174212131890U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 13900288860157577583U) + aNonceWordE;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4144386119777112740U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3154558262670631372U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 13236911910092437063U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7456728543137614001U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11709519851158935384U;
            aOrbiterB = RotL64((aOrbiterB * 7016689518570071587U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15607438907832240304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9276575329661725624U;
            aOrbiterK = RotL64((aOrbiterK * 8879744070762412745U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6459435969129449226U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6442382118416542275U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2921027306686588233U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12117432107282150865U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6831279293184793243U;
            aOrbiterC = RotL64((aOrbiterC * 2435360641135249073U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9520022957804572889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8322178689474588679U;
            aOrbiterD = RotL64((aOrbiterD * 1627707191467537115U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4162401591586869316U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 8994015844714895961U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15421910378057951895U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 28U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 36U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aNonceWordB) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12943U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 16058U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11926U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12083U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 12255U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 29U)) + 6733949564325516029U) + aNonceWordL;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 7304098437143918796U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 20U)) + 3923949518391777800U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 37U)) + 14243591003388927124U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 5U)) + 18329498724605410406U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 13118172167747037249U) + aPhaseDOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 5272025143849174212U) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16075917179214318424U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 15263590648674658399U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 9918239923411740337U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13730046728289525921U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7703141464499623408U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5886009900621521987U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1382279753822135359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2973369221699098292U;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11578274119583013219U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3419411247737896674U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2582783513078999303U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3959762790273529677U;
            aOrbiterK = RotL64((aOrbiterK * 383974377372162751U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 465795011576934604U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17880826624185821135U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4445949147592860913U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 10819659185349413173U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17298208553586835030U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 1965860510614222093U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 39U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aNonceWordD);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aNonceWordG) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 60U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20135U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneA[((aIndex + 20627U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19960U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20317U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 17047U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 35U)) + 16124889768301047791U) + aNonceWordH;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 56U)) + RotL64(aCarry, 41U)) + 11912338587186717280U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 29U)) + 8594012868813114354U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 3U)) + 18281043566156682815U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 19U)) + 16853106130200942302U) + aNonceWordK;
            aOrbiterK = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 2611212958619673086U;
            aOrbiterD = ((((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 18039472325066855180U) + aPhaseDOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 14495785571345122046U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4556063793412832418U;
            aOrbiterJ = RotL64((aOrbiterJ * 13166927543135467627U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14896419970271244358U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 880028529183500036U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14228281807461251361U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 2379557167489415783U) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11854373946064529806U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 150755294320438887U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1487252775956449964U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12777924204511625545U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1366019527386994789U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15998631485222477969U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8864212892296191613U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 579242788050369815U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17069347835763226743U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7443008171694679791U;
            aOrbiterB = RotL64((aOrbiterB * 748894368884566607U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17334256152350782002U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8986626119086556393U;
            aOrbiterK = RotL64((aOrbiterK * 2258172145924120235U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ) + aNonceWordO);
            aWandererI = aWandererI + (((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + aNonceWordN) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 54U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26981U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 25421U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26848U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26951U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((aIndex + 26988U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 14U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 13U)) + 7075016829833562104U) + aNonceWordN;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 8783765886115517036U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 3U)) + 2996723892384565829U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 29U)) + 9494134707342189476U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 21U)) + 5052642981395679904U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 8766787055127962238U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 4467211954388738079U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8030255604633658608U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16962408063455702251U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11171737929747471631U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 3768222186567699076U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14930990410207899871U;
            aOrbiterB = RotL64((aOrbiterB * 10930005786146268241U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14179761938395502502U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1879084742719898108U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16783034788172670121U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5535012408925981515U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12792553516710295939U;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8979253163346099252U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 5559189896063990740U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8832485423727331621U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13937564337299044079U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2393376759689394948U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12647519563697356479U) + aNonceWordA;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 10946871249960389549U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 6272580371881237173U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 22U)) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aNonceWordB) + aPhaseDWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32128U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((aIndex + 29209U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 27788U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31699U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32313U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 43U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 4751694786009671052U) + aNonceWordD;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 12U)) + 16362725160370844224U) + aPhaseDOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererG + RotL64(aCross, 53U)) + 6360885380915941057U;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 5154536007972297036U) + aNonceWordJ;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 47U)) + 9362540581874808253U) + aNonceWordL;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 39U)) + 13902493871525612934U) + aPhaseDOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 10208452885367546542U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3117030377279160998U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17286247690414027870U;
            aOrbiterC = RotL64((aOrbiterC * 4896931759653832095U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3930314320040949141U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 7289525252391668404U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15452162299105112187U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3434167955466809185U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17852573095128575663U;
            aOrbiterA = RotL64((aOrbiterA * 1485660158767033425U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6137259687928853253U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13992510605237574698U;
            aOrbiterH = RotL64((aOrbiterH * 15346263295995333395U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6470556523400123474U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4333255670390099293U;
            aOrbiterI = RotL64((aOrbiterI * 11089933812030082647U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 7700424876430257995U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16920736951239453071U;
            aOrbiterE = RotL64((aOrbiterE * 8920407493132380497U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1635071690430295730U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9966700845966398620U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17210048121896546867U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 50U)) + aOrbiterA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_PickleBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9D4563D5C0D5E819ULL + 0xBC9FBB0533774548ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9322CC05646775B5ULL + 0xEFC162ACD4348656ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x82AB7D92329E0D27ULL + 0xF7D0F3B9D04E5D45ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF7719E5DAAAE6831ULL + 0x847F5DA683B599FCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBAF38A8DDD0E0FE5ULL + 0xC86E0A30BA12F59AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD6DA3E7A8F1C7631ULL + 0xD9928EE1BF4F8CDBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBB220D4C8BA332CFULL + 0x90C9EF3E8566BC2EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB3475D5C687770C1ULL + 0xACAFD495E4E7F421ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA24127B4A5117DC5ULL + 0xF98AFFCA8F7C1A0BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC0C310AC3FA9E1CBULL + 0xDBCD88EB6390FBC4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF1696C27F4EE26C9ULL + 0xC2A94478B1C91DABULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFA5EF08B59E2112DULL + 0xD5F0E0473331991FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB84799333E1E8257ULL + 0xAA1A00C21A0B1368ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD6B7B614CAD3DE71ULL + 0x878D48BCC69B9E40ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x93D0510C1C63979FULL + 0x92EB6E9A1F68E935ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD9EFB45C387E666BULL + 0xB92440C7DEA63502ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5353U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((aIndex + 4603U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 70U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3921U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4145U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5294U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 24U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = ((aWandererH + RotL64(aCross, 30U)) + 3248574644570178787U) + aPhaseEOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 11U)) + 4506961512959200024U) + aPhaseEOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 8423739774540738590U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 6593975869641735337U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 20U)) + RotL64(aCarry, 39U)) + 16441716090557369103U) + aNonceWordO;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 57U)) + 7936601450453207914U;
            aOrbiterI = (aWandererG + RotL64(aCross, 41U)) + 13333752583560167065U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 37U)) + 8013703284795432973U;
            aOrbiterA = (aWandererC + RotL64(aCross, 39U)) + 2349852779887439236U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 35U)) + 5318539364763284138U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 53U)) + 11450957608502944376U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9058992558327552687U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 632095686920230926U;
            aOrbiterF = RotL64((aOrbiterF * 12460364388358520799U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14734218428913777098U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16344357661370784442U;
            aOrbiterH = RotL64((aOrbiterH * 15049472842002138369U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2981145363531184308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 11198457590069700889U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 952584436750426828U;
            aOrbiterA = RotL64((aOrbiterA * 1165713888651280355U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4311591763498985972U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16194341833989936369U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7560794022401107431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10683789740265711603U;
            aOrbiterD = RotL64((aOrbiterD * 15637823045351977883U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11614366395125937178U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10750771385100564416U;
            aOrbiterI = RotL64((aOrbiterI * 4987921274272444283U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2934697034132204529U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 4646873794658020363U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 10555456865641580175U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7913681837683568905U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17603563535330106340U;
            aOrbiterB = RotL64((aOrbiterB * 17882943067522319671U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15375641415139193079U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17059712718085411887U;
            aOrbiterE = RotL64((aOrbiterE * 13722089235751208215U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14022558453716067200U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3248574644570178787U;
            aOrbiterJ = RotL64((aOrbiterJ * 15249135451439374621U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 39U));
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG + ((RotL64(aScatter, 12U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 58U)) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 5U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 42U)) + aOrbiterI) + aNonceWordJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererB, 12U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8201U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 7057U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7881U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 8861U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5679U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8985U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 8349U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 54U)) + 8866844335448071821U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 15159698739856430085U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 29U)) + 9582805772989594633U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 41U)) + 1438538239931588373U) + aNonceWordP;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 60U)) + 10862044156620436139U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 13682173320058164615U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 21U)) + 8351013291045977592U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 13U)) + 15777857431516633916U) + aPhaseEOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 27U)) + 16178966745333885377U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 9031889187993001617U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 19U)) + 6308472367425865347U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 642109145903321046U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9186268569255318035U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 10714674348507516749U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6091345356803675860U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13218507921880873749U;
            aOrbiterA = RotL64((aOrbiterA * 15415157927185637717U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4266652275234474616U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4391422098164506195U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17634679403195085867U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5160682323243635577U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterK = RotL64((aOrbiterK * 11105410036471745951U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3950932176454814023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9536466386833427441U;
            aOrbiterE = RotL64((aOrbiterE * 18064984243491293435U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9927425919978776529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6819384090527481081U;
            aOrbiterD = RotL64((aOrbiterD * 18032965969184368561U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1646274931424218507U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16166524473976135097U;
            aOrbiterI = RotL64((aOrbiterI * 11672192658072663849U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11252501968059485262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16847854447987609067U;
            aOrbiterB = RotL64((aOrbiterB * 6326299154627028295U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16723218285355036446U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13870211254243048975U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10203222183774624097U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11401147367366049493U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 4266628469244269926U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 2409934496621365221U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11578385782347296942U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8866844335448071821U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6456956795450036515U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterA, 40U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aCross, 20U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterK, 42U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12359U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneA[((aIndex + 11273U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13279U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11665U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13726U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererE + RotL64(aPrevious, 11U)) + 12690502671561165478U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 43U)) + 17519943923428102801U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aIngress, 14U)) + 10705515807975331385U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererB + RotL64(aScatter, 51U)) + 16586447272278538179U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 35U)) + 8006560996840971798U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 23U)) + 12928600185788857701U) + aNonceWordJ;
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 14240723153798267172U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 8636219177994872072U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 19U)) + 7586790235186467512U) + aNonceWordK;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 39U)) + 1103807034179512424U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 7547526530239498693U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8380239679344786397U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5690809173787433519U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 5354724308093372953U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6190745292098482871U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8065418693975056902U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 6414621418430102589U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12111755051718111803U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7605877769709909297U;
            aOrbiterF = RotL64((aOrbiterF * 17525248694315944599U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5969794501112646237U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5127559299360591476U;
            aOrbiterK = RotL64((aOrbiterK * 4521563633438853069U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10593847754747739786U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4401750688524310121U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 14265829318976633707U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6927893132508779499U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4874009978647014479U;
            aOrbiterB = RotL64((aOrbiterB * 13340466017023540755U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 13146693487138744677U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3298472134223595298U;
            aOrbiterG = RotL64((aOrbiterG * 2145005258008477281U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8729305340729268734U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18347161842033439538U;
            aOrbiterI = RotL64((aOrbiterI * 7952715248988302017U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 166831495912855225U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4943633045563697271U;
            aOrbiterH = RotL64((aOrbiterH * 1809857625425000137U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2460623715340753589U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12690502671561165478U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16421139715633515623U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 40U) + aOrbiterB) + RotL64(aOrbiterE, 26U)) + aNonceWordL);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 34U)) + aOrbiterI) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20866U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((aIndex + 19998U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19611U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16500U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((aIndex + 20000U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 30U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterE = ((aWandererC + RotL64(aCross, 35U)) + 9041099828460168106U) + aNonceWordO;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 47U)) + 12883711604096848454U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 17420968786226443079U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 54U)) + 3448213891716125104U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 37U)) + 11866455977445336560U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 11U)) + 4119356835384495905U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 43U)) + 2186212599698637068U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 41U)) + 6506144898969301620U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 12556800923644051626U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 4075551535185182945U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 13U)) + 17877694808492008749U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5553428900598223316U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14362304852277160675U;
            aOrbiterD = RotL64((aOrbiterD * 11415103199856419303U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9174200302876075831U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16110739511917638547U;
            aOrbiterA = RotL64((aOrbiterA * 7004356839428657949U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10189881974519849402U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2128076632642616677U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8860453653433114929U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18133523799074400083U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9916472958834153766U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10274457562795569227U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14134814273275356425U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 15912501063665343159U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6394306369514735480U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4825761192736485643U;
            aOrbiterJ = RotL64((aOrbiterJ * 12534544147331805643U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5672807934779206275U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3881953574159390421U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7448770570912161095U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12012232712634303203U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14176392925893052596U;
            aOrbiterI = RotL64((aOrbiterI * 11288668529893084583U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 307148402076391033U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15380446373458263079U;
            aOrbiterF = RotL64((aOrbiterF * 15228462337097647933U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4654312690816676129U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10818029316701301859U;
            aOrbiterH = RotL64((aOrbiterH * 16245734506125913215U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7340370713289840635U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9041099828460168106U;
            aOrbiterE = RotL64((aOrbiterE * 1807356802142268373U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 35U)) + aNonceWordC) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 48U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 11U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + aNonceWordL) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 26U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25120U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((aIndex + 23348U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22893U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25073U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22134U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 22750U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 15920462086654025436U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 6U)) + 487844076858004017U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 14502883786442630566U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 37U)) + 3787107318658233674U;
            aOrbiterG = (aWandererD + RotL64(aCross, 39U)) + 12548777544693755491U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 11U)) + 4907309444075181683U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 51U)) + 18342396700266492072U) + aNonceWordC;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 37U)) + 13503051997624242670U) + aNonceWordP;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 35U)) + 17845742460521374571U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 21U)) + 8640887211877858169U) + aNonceWordK;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 56U)) + 5273913123709097537U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17756844173695563883U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6713055830729302951U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2832836748513174311U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5106468334224035972U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10228769728713526172U;
            aOrbiterE = RotL64((aOrbiterE * 9760310686414358435U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7687649520668883142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7757480627354711605U;
            aOrbiterF = RotL64((aOrbiterF * 7222553727737349209U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10876291698508634557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8149278085586014186U;
            aOrbiterJ = RotL64((aOrbiterJ * 8577133863470695381U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15592893988925610485U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8639028256640537165U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 1880655276432963955U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 475660347892196219U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1903736092401853832U;
            aOrbiterD = RotL64((aOrbiterD * 8486318978769094799U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12463250192809450953U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7253918448601703982U;
            aOrbiterK = RotL64((aOrbiterK * 3821034106528009129U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5171661020093804486U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11627344933828324146U;
            aOrbiterH = RotL64((aOrbiterH * 5388047063152043277U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6206801139131132815U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9221302203943031377U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12912049016813367241U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1798857939965423979U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5476854168685641232U;
            aOrbiterA = RotL64((aOrbiterA * 3884216989250294213U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2816659151953455230U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15920462086654025436U;
            aOrbiterG = RotL64((aOrbiterG * 17843161654734820613U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + aNonceWordD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterK, 26U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 18U)) + aOrbiterC) + aPhaseEWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32018U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 32032U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29622U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31485U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31626U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererI + RotL64(aIngress, 60U)) + 12669015908335980355U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aCross, 27U)) + 5438715179868613192U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 13172104448184536460U) + aNonceWordC;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 37U)) + 13421421503244744803U) + aNonceWordK;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 41U)) + 13327113302994856582U) + aNonceWordA;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 21U)) + 4671768205922454413U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 5355759962838579929U) + aNonceWordP;
            aOrbiterI = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 6691720614265406851U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 47U)) + 7063906424700911378U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 19U)) + 17328616394166672263U;
            aOrbiterD = (aWandererG + RotL64(aCross, 54U)) + 1542940602574207068U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7203866278803132454U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 993485696233139264U;
            aOrbiterE = RotL64((aOrbiterE * 11609009908810366447U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15659679028507488331U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18321361454094675842U;
            aOrbiterA = RotL64((aOrbiterA * 3966860765622641843U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9633319822696783352U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3496559332232402963U;
            aOrbiterI = RotL64((aOrbiterI * 7772060229838162977U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1918349708324205526U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7701088402761359134U;
            aOrbiterG = RotL64((aOrbiterG * 9649485438465644795U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6006824348814439686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 18088375375347012557U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12816533373478543584U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17951880253818836433U;
            aOrbiterK = RotL64((aOrbiterK * 8935839101517220201U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11311632024372748238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9891349164779752351U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 11405973752233193209U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 711130292000437038U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17818800917771709681U;
            aOrbiterF = RotL64((aOrbiterF * 10567029732245868263U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10188714200240109442U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9745615081760948652U;
            aOrbiterD = RotL64((aOrbiterD * 9321909462220134035U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6508703788527163965U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 7536038073603467381U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12015514242701199813U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2793951597846756844U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12669015908335980355U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 7355285540199760689U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aNonceWordH) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 6U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 34U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + aNonceWordE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 21U)) + aOrbiterI) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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

void TwistExpander_PickleBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFCB99C06D49B927DULL + 0xC213173A46CE2863ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8C8B96432D8D7677ULL + 0x9D7FA8666DB07C31ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9B4288D304644F3BULL + 0xDCCB0C25662D175EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDEA5477625EFD421ULL + 0xB0AB3E9EBD773831ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8EDCC6245F024D1DULL + 0xEF3887FDE8A26353ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFF6B8899CEF97F75ULL + 0xFFE7447774113377ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE2D56098848E3553ULL + 0x9E4CE6C8CF77DE22ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x85506D894F007765ULL + 0xBD0ADA395AC516F8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC3BA39A87BF10FB5ULL + 0x9D216829146B50AEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE1F91255610F6A77ULL + 0xFAF137321692FD63ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE5990CE6EA5020BBULL + 0xC6A1BDA9675391DCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9AF30AC08D4A4849ULL + 0xEE401A8A241165CEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8D2BA0D7C539CB69ULL + 0x9C37D291B915CEF1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8E1E746F684B6CF7ULL + 0xD3623FC3ADB10D47ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCE9B14EB63BB3C79ULL + 0x8D799351073C9FF8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9536BD53F3D59BC7ULL + 0xD51281DAA3154D55ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aOperationLaneD, aSnowLaneB, aSnowLaneC, aInvestLaneC, aInvestLaneD, aSnowLaneD, aWorkLaneC, aExpandLaneA, aSnowLaneA, aExpandLaneB, aInvestLaneA, aExpandLaneC, aWorkLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3611U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 3392U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 2801U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5231U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2270U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 2096U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 26U)) + 7825479804710770560U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 5298124167101358123U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 17774541024369233726U;
            aOrbiterD = (aWandererF + RotL64(aCross, 5U)) + 7679371833537454082U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 21U)) + 5385914900748772224U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 41U)) + 3879781930908486531U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 51U)) + 659110346638873236U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + 10749021728538539749U) + aNonceWordB;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 47U)) + 3631252455767429457U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2271978810960685021U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5963558780692551176U;
            aOrbiterH = RotL64((aOrbiterH * 4772055335210781149U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 974909966119198104U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9296998242911152296U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 2613629915877957661U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2245318466901521959U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13391076374843288568U;
            aOrbiterF = RotL64((aOrbiterF * 18094558036982107419U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6184487746594236737U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1563385912137291418U;
            aOrbiterC = RotL64((aOrbiterC * 4805455299959232321U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1744840092006498629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2100927276837188416U;
            aOrbiterB = RotL64((aOrbiterB * 3541788262067077997U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9998911862807246338U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12239948725635220096U;
            aOrbiterE = RotL64((aOrbiterE * 7098620484129489129U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3307447094994950246U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12746613971448298932U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9463975886346934681U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11577488293733790649U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 191108997585598809U;
            aOrbiterG = RotL64((aOrbiterG * 9574978681405356871U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 18096145693841273722U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10026281133603934071U;
            aOrbiterA = RotL64((aOrbiterA * 17261343107314203471U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 58U)) + aOrbiterF) + aNonceWordP) + aPhaseFWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 39U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 28U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 6132U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 9696U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7419U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7133U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10658U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10191U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 5771U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 28U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 9630214189402543339U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + 4072576573737526819U) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 53U)) + 15994787452709618869U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 23U)) + 6403240137132259482U) + aNonceWordD;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 10229266900170507720U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 19U)) + 5025294577989748989U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 5U)) + 16696461238217956883U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 9878318855341719119U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 12U)) + 16086635438116177346U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 12295437783084203730U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7681150419912842402U;
            aOrbiterI = RotL64((aOrbiterI * 7289497379725191451U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2639104034287637448U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12298170009332243573U;
            aOrbiterH = RotL64((aOrbiterH * 9397919591171238575U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3485932317267669626U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16569551670038752475U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 8139802826402217631U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4448490103784103954U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14510534073046885941U;
            aOrbiterA = RotL64((aOrbiterA * 7777192047386438305U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4286195398675733451U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15790355933840266463U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13342257823027075501U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6362891510370156055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15121822034579983174U;
            aOrbiterK = RotL64((aOrbiterK * 7268045994574844937U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13817341015719915628U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14113474087906143783U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 12838910141533126059U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9988301252236121106U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11287477288382171758U;
            aOrbiterB = RotL64((aOrbiterB * 4979297247881426383U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9491727010910328644U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7961202721830514030U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 16300364540313620767U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterE, 36U)) + aOrbiterK) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterI) + aNonceWordO) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 23U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 48U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15511U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 13965U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13117U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 14337U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12461U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 58U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = (((aWandererD + RotL64(aScatter, 60U)) + 5906639480605353429U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererF + RotL64(aCross, 3U)) + 5293518570213287605U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 53U)) + 15383185501428521377U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 19U)) + 15364072512743978902U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 23U)) + 4525473357144014271U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 10400911938125603074U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 27U)) + 16417506293824627550U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 2419329331753341815U) + aNonceWordJ;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 14929222427923332069U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16771573504983922586U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1863466450051787622U;
            aOrbiterB = RotL64((aOrbiterB * 2585626547126027053U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12895350137096692415U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3700979086526298327U;
            aOrbiterC = RotL64((aOrbiterC * 10279730254867618193U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1977099106211282426U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6144698304096915742U;
            aOrbiterA = RotL64((aOrbiterA * 5039822990560519609U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3858895556659724975U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1283646340363435327U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 11622421841377018069U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6240532051889108891U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 757364889381634634U;
            aOrbiterF = RotL64((aOrbiterF * 943852137901972945U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5272945693977418174U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6850528198786172283U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1966383079897679953U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14431587733859573714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16124590257870999553U;
            aOrbiterK = RotL64((aOrbiterK * 7755796211433191143U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14912695018110241411U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11098623474413346520U;
            aOrbiterD = RotL64((aOrbiterD * 15167688959990872051U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3484847683376368686U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2295388097292719800U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 1240808318176106909U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterH, 10U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aNonceWordO) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 14U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aSnowLaneA
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aSnowLaneA forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20172U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 17490U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aSnowLaneA[((aIndex + 20971U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19949U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 20169U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U)) ^ (RotL64(aIngress, 10U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 4751694786009671052U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 43U)) + 16362725160370844224U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 57U)) + 6360885380915941057U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 21U)) + 5154536007972297036U) + aNonceWordC;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 51U)) + 9362540581874808253U) + aNonceWordE;
            aOrbiterG = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 13902493871525612934U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 39U)) + 10208452885367546542U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 60U)) + 3117030377279160998U) + aNonceWordL;
            aOrbiterB = (aWandererH + RotL64(aScatter, 29U)) + 17286247690414027870U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3930314320040949141U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7289525252391668404U;
            aOrbiterJ = RotL64((aOrbiterJ * 15452162299105112187U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3434167955466809185U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 17852573095128575663U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 1485660158767033425U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6137259687928853253U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13992510605237574698U;
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6470556523400123474U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4333255670390099293U;
            aOrbiterK = RotL64((aOrbiterK * 11089933812030082647U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7700424876430257995U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16920736951239453071U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8920407493132380497U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1635071690430295730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9966700845966398620U;
            aOrbiterB = RotL64((aOrbiterB * 17210048121896546867U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9833458070123027075U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1990346556486746432U;
            aOrbiterG = RotL64((aOrbiterG * 8704943923474148699U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 13339523466436517327U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5018264760406215603U;
            aOrbiterA = RotL64((aOrbiterA * 2769197961801783627U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 123427497520755346U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4535841104215792886U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 1417676310539177131U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 14U) + aOrbiterC) + RotL64(aOrbiterK, 30U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 35U)) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterD, 39U)) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 44U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneA
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24814U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneD[((aIndex + 26347U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 23401U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23303U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneC[((aIndex + 26419U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 60U)) + 17454559218352016650U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 8005709669325164803U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 39U)) + 13393741948412816357U) + aNonceWordN;
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 3665865624348875553U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 11U)) + 8334142570031883436U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 6U)) + RotL64(aCarry, 51U)) + 17226066128706139657U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 3319093033121522613U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + 6657535603401588798U) + aNonceWordG;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 29U)) + 5469746182326331147U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17846791786050221418U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15939541003714896288U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1400351482213119809U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 12076763190461077406U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3594038213596405284U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10244002692575821495U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8301291631324464622U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8460406137668390582U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9117147929757711595U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7612394867020871200U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8525076134853103975U;
            aOrbiterC = RotL64((aOrbiterC * 5790440201072204659U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11929899088215090379U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7119509166360685726U;
            aOrbiterE = RotL64((aOrbiterE * 1662341427992528823U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5081078459225240607U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17149991983909906705U;
            aOrbiterK = RotL64((aOrbiterK * 950223374568067343U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8817303295675241994U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7962039282652745113U;
            aOrbiterI = RotL64((aOrbiterI * 12773588587795522121U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13596273086338032370U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8186297702278180956U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 6226504769888753861U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1696277861691580263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17360461831507082959U;
            aOrbiterF = RotL64((aOrbiterF * 1651378456022210983U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 60U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 19U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 47U)) + aNonceWordA);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 14U) + aOrbiterI) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 57U)) + aNonceWordC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29452U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 30031U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30195U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30571U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32489U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 19U)) + 1557680213571812384U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 13U)) + 7387349725778021121U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 15379264067601586976U) + aNonceWordE;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 39U)) + 3730195724576043708U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 27U)) + 9637070085323827066U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 37U)) + 1170865717363676184U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 41U)) + 2750833653175252030U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 23U)) + 15118992811225568305U) + aNonceWordF;
            aOrbiterF = ((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 4974092922102988451U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10625719096296719514U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 855167122475471865U;
            aOrbiterD = RotL64((aOrbiterD * 7441090331293158773U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11322911068958340262U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4334591909425429835U;
            aOrbiterJ = RotL64((aOrbiterJ * 10059025861172038183U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14263701737208936392U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 678723206735649084U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 10823239851733632227U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15652053114252065230U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1705225940224061401U;
            aOrbiterB = RotL64((aOrbiterB * 3626023093533713579U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6826394665732900206U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11902946775066981141U;
            aOrbiterF = RotL64((aOrbiterF * 18300629262162694137U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9802212958998591310U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 14001358545610206524U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 13172645840788327099U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4299184726135884309U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7288757011999872416U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16806027820468277393U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 233801262480580205U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 14208660347238680268U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 6299693448313154603U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9217797359740446104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18165073197136050838U;
            aOrbiterI = RotL64((aOrbiterI * 11677479094709512887U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 34U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterA, 38U));
            aWandererI = aWandererI + (((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_PickleBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAD054ABF49646A27ULL + 0x8A7EBA3EC6D7317DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC0FA453C7843517ULL + 0xA075D0AB6C325C0FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8D7015B46BD9A139ULL + 0x8F4297F3B670199CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC8CA08C9BAE38EF3ULL + 0xE297268DE8CF38F5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD792985D76A91FB9ULL + 0xD223AA4ECBF3AA33ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xBA7EF8545A41BA71ULL + 0xDBA7A0B7AB80B524ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD92B9A3BA291F597ULL + 0xCF74658142FD1A1BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFF3ED5EB1814A6B9ULL + 0x8346C81813BFA6DFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFABEC2503C1D7C11ULL + 0xCF04DEC0A19E6C34ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBF94F5911E126393ULL + 0xC7DBEDC9281175B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBBA1C23F62F59D5BULL + 0xEE30112F2FA158AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA2CE210D77CFA119ULL + 0x8061477C34FF16DEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDB26905C0F5CC611ULL + 0xCE8DCCE15BF9A8A2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8EEE0F9B03B7E059ULL + 0xF90D378EFD52C06FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC6C9F1A6F30EE94DULL + 0x86686F8C7CF81D0BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCFA1BC060AB40349ULL + 0xB844335A43C75DC5ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneB, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aFireLaneA, aInvestLaneD, aWorkLaneB, aFireLaneB, aExpandLaneA, aFireLaneD, aExpandLaneB, aFireLaneC, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 111U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 2140U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 1357U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1148U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1906U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 548U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 12U)) + 5960680319644404115U) + aNonceWordI;
            aOrbiterF = (aWandererH + RotL64(aCross, 47U)) + 16050752633567034185U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 29U)) + 8447503223226854741U) + aNonceWordJ;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 14176813813397917591U) + aNonceWordC;
            aOrbiterD = ((aWandererK + RotL64(aCross, 3U)) + 10534915376130006644U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 6866224454375302514U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 27U)) + 16506374165041008396U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7167814023968794098U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 13870852197416596664U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17015971222069856463U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18064038854848993105U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9869630811507771691U;
            aOrbiterE = RotL64((aOrbiterE * 13723164383800461387U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 863613100452759380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16597969741225436529U;
            aOrbiterH = RotL64((aOrbiterH * 2680793528887208903U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6575347108051310653U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17062262265485019063U;
            aOrbiterD = RotL64((aOrbiterD * 7601045488473620019U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7193399224636409133U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14146747818810433849U;
            aOrbiterF = RotL64((aOrbiterF * 5273185769989530041U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 9441449106442431427U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4303295336545399503U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 8829695296836242587U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12604760768543193458U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15779327512379787715U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14000905201441272597U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterB, 36U));
            aWandererA = aWandererA + (((((RotL64(aCross, 4U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordD) + aPhaseHWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7881U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneC[((aIndex + 7491U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 8819U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7815U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8868U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 9000U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6206U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 14U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 3561491146322798260U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 11U)) + 7075025056181885339U;
            aOrbiterA = ((((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 9230910887904171613U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 3U)) + 4119781172609908917U) + aNonceWordE;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 17155609083870983149U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + 2423018561430181695U) + aPhaseHOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 12957280305617615744U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2461704174772065813U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7907123257849391997U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9416171962847312179U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7257868138318960007U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 16425903703085702285U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 7996935869077231999U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2990822664594079467U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 5654819006718953817U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4465096036756887801U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12183676471235678779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15026286960542123922U;
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12169080607071830522U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2906296852254787499U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 6754514406846040163U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3029858695410344584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11048818178401163861U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13622063920319445043U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 42U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 51U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 5U)) + aOrbiterI) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterA, 19U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 34U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + aNonceWordI) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15469U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 11552U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14353U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16287U)) & S_BLOCK1], 28U) ^ RotL64(aSnowLaneC[((aIndex + 13853U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 10U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterC = (((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 2974056819475622600U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aPrevious, 54U)) + 7345051759236356098U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 12738468816846628882U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 29U)) + 7694520596043297922U) + aPhaseHOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + 5530753590015084774U) + aNonceWordM;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 13U)) + 3776309161718383105U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 784780304358106404U) + aNonceWordE;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8999942326995036509U) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5194986506064092779U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15070787038006135963U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7920040007459652762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11311997270710107937U;
            aOrbiterI = RotL64((aOrbiterI * 6227571709361790209U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5365231114813547251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8630110234623825263U;
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2358235238039571072U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 18059414891616491807U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 17150786106857185467U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14526050556461782864U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 6937282036603272474U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 14954512365270028029U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10105832250694931310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3884223553012098137U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10385284339549648087U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1257633893341505930U;
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 4U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterC, 58U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 12U) + aOrbiterB) + RotL64(aOrbiterE, 27U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16550U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 18037U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20732U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18643U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21283U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 12809562813316740345U) + aNonceWordP;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 27U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 16074921689983846769U) + aNonceWordE;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 21U)) + 14027986153007120145U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 7633455951809250227U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 35U)) + 340989348513370174U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 58U)) + RotL64(aCarry, 41U)) + 5307820377645020116U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5605285015771527274U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5293500434746182790U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7263156475892261811U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10672879570907433005U;
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 16659226780900986107U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9774892622769850665U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10728057184108279042U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5032485856947407217U;
            aOrbiterI = RotL64((aOrbiterI * 16651577903809154285U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14642241075374862345U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8386481273395203518U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11649977733867003445U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2874153265304098104U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11519900149177261000U;
            aOrbiterK = RotL64((aOrbiterK * 2010158758971864505U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8885690878540115768U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4482143389870987714U;
            aOrbiterA = RotL64((aOrbiterA * 7105332459437434281U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 28U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aNonceWordL);
            aWandererI = aWandererI + (((((RotL64(aCross, 36U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 41U)) + aNonceWordG) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24467U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 24417U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25030U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24630U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23384U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 57U)) + 7896237440058555694U) + aNonceWordP;
            aOrbiterI = (aWandererK + RotL64(aScatter, 11U)) + 11870529476037558635U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 9158983227801569448U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 43U)) + 4710172270996950329U) + aNonceWordK;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 14634482800356647630U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 8822207952170610891U) + aPhaseHOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 26U)) + 13755891414028982553U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4555293067488040719U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2816805148093762081U;
            aOrbiterB = RotL64((aOrbiterB * 16838149138341713943U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2122631477965135190U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4592922416380416071U;
            aOrbiterH = RotL64((aOrbiterH * 11644507904538573165U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7102471666524164715U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17274623547879474204U;
            aOrbiterI = RotL64((aOrbiterI * 5443572270546181789U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 938587316977094680U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 18258015823797023523U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6068819567674605919U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5809987756043471595U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5083075160112581620U;
            aOrbiterC = RotL64((aOrbiterC * 3313957222154937503U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5960021727750946496U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5967477320950630150U;
            aOrbiterE = RotL64((aOrbiterE * 330964768256424655U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6578428711689296132U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5601728218197771276U;
            aOrbiterF = RotL64((aOrbiterF * 9552559022315971847U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordN) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aNonceWordH);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordI) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 58U)) + aOrbiterE) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30009U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 30014U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 29262U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32240U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28149U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererK + RotL64(aScatter, 11U)) + 5173905450211892891U) + aPhaseHOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 35U)) + 3555542451908039957U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 11559884700283861559U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 1352524329968738673U) + aNonceWordG;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 47U)) + 8914206450420616349U) + aNonceWordH;
            aOrbiterA = (((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 2251523378498463946U) + aNonceWordD;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 53U)) + 9541575923299247038U) + aPhaseHOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1239854507907214595U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17698101462598498934U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 2304948713665996433U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 12305566971683256060U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13804545036303215569U;
            aOrbiterF = RotL64((aOrbiterF * 10359543704152744971U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10239749097704329264U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4212214906286320308U;
            aOrbiterA = RotL64((aOrbiterA * 3661436621615751071U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12192418916967430783U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4475514289326450361U;
            aOrbiterK = RotL64((aOrbiterK * 17497164630368757887U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17376102613298827459U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 18129393209955439341U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6404089025014118979U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4014763724300253568U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17325007199676828814U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 1420888274815627083U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15480474849292388685U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 14357924730184375449U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16723492259068034209U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 4U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 37U)) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 52U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
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

void TwistExpander_PickleBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1952U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 1234U)) & W_KEY1], 54U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 959U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 1887U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aScatter, 43U)) + 2786079456995203065U) + aPhaseAOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 51U)) + 7237256119153857253U;
            aOrbiterC = (aWandererC + RotL64(aCross, 12U)) + 9310834010563647604U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 19U)) + 17361734905706517877U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 39U)) + 15837111231884647451U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + 18065431964418026445U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 3U)) + 3029123922999952652U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 5166926595573507837U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 1918425684273807598U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4724551751012661440U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1818014487579644390U;
            aOrbiterC = RotL64((aOrbiterC * 14904092108647864911U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6670090372241084216U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8485757110007268693U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4928130251509514742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2528788422725346792U;
            aOrbiterK = RotL64((aOrbiterK * 1855982047967756661U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2860387120895147503U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12927802338151379368U;
            aOrbiterA = RotL64((aOrbiterA * 8876144125458603029U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 18029699867733207083U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13361836994951253312U;
            aOrbiterD = RotL64((aOrbiterD * 5349767426256597073U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11957294454794128079U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3755417922063414648U;
            aOrbiterF = RotL64((aOrbiterF * 13896364063651241401U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18001157153447913032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16214145724690286854U;
            aOrbiterB = RotL64((aOrbiterB * 5874139687703360515U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3860958772090975562U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12395621524459640173U;
            aOrbiterG = RotL64((aOrbiterG * 722817135977510161U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3402035664910754484U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2139099117325745602U;
            aOrbiterH = RotL64((aOrbiterH * 14008983756425796029U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 18U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 29U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 24U));
            aWandererB = aWandererB + (((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4072U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 4627U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3454U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 4278U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 58U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 13583136155674166402U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 39U)) + 12830472187484919497U) + aPhaseAOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 18081197909484522509U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 43U)) + 8680634051297891550U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 52U)) + 13939998767458656823U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 19U)) + 1795730579103692594U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 11U)) + 17369751719734069999U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 224769585901248068U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 48U)) + 4133547085925268180U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7022512056309567391U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10319484359046945495U;
            aOrbiterD = RotL64((aOrbiterD * 3400140531307001933U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10483878349412282069U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6481381149199985736U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9701719367082506253U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13721077228796934509U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9704818014314175007U;
            aOrbiterE = RotL64((aOrbiterE * 760445624027740287U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6253040047758584339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16890211690273641226U;
            aOrbiterI = RotL64((aOrbiterI * 5622534399866057841U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6216227831265032436U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2023609047004658739U;
            aOrbiterJ = RotL64((aOrbiterJ * 3252332895698310147U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9201669637050388263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5106927540934338576U;
            aOrbiterH = RotL64((aOrbiterH * 6368134569042291431U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10080368957861445998U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10784789383436485808U;
            aOrbiterK = RotL64((aOrbiterK * 3794918350254445939U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15426339824951793026U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 17637144549368340331U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10971293914614704441U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9941300382181962134U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8118046374121322097U;
            aOrbiterF = RotL64((aOrbiterF * 8481945819050983127U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 52U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + aPhaseAWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 56U));
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 12U));
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5618U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5974U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7993U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6347U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7305U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 6243113109470883144U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 18U)) + 3891552123999605832U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + 8758797898587019128U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 35U)) + 1005891374086408851U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 3713426782180050764U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 18358143862391573534U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 40U)) + 17504394029693712404U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 5312729289027417014U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 5U)) + 2560873623431186029U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16309322822806704211U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 10195513918020652600U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14569219741824123715U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2552116263258744287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7732784879810980089U;
            aOrbiterG = RotL64((aOrbiterG * 15041929399477790999U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16499127570665381507U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10890036715535519036U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9065115450010475187U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16288944603478791554U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14542766121469312846U;
            aOrbiterA = RotL64((aOrbiterA * 8435383464425875209U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5973595239494084696U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1820492719977197097U;
            aOrbiterI = RotL64((aOrbiterI * 16164917159141304405U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10489529555776381736U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6392552206958240484U;
            aOrbiterK = RotL64((aOrbiterK * 11761477994533503307U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10163241948999404556U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16054678853554707148U;
            aOrbiterE = RotL64((aOrbiterE * 10570418210789350091U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3606021702108590330U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16920568417324295852U;
            aOrbiterJ = RotL64((aOrbiterJ * 5222656554577625385U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13889995689147406315U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7908387312354285092U;
            aOrbiterB = RotL64((aOrbiterB * 7995682580514280949U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 44U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 48U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10400U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 10838U)) & W_KEY1], 10U));
            aIngress ^= (RotL64(mSource[((aIndex + 8922U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 10474U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10782U)) & W_KEY1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9971U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 22U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 1393781663398437180U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 17414594746688585273U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 43U)) + 2823888497053071250U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 3U)) + 17032631958617884859U;
            aOrbiterK = (aWandererF + RotL64(aCross, 51U)) + 15222697630461125019U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 13U)) + 15737414920751551780U) + aPhaseBOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 34U)) + 1357196111055783001U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 5315122321649251691U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 7893744655508595974U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16721939414324611738U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3444375866323610848U;
            aOrbiterH = RotL64((aOrbiterH * 10874157227815775661U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1825716513674511632U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15582066843912467318U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12765146555943757373U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15673590949193923915U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13887365046280406413U;
            aOrbiterF = RotL64((aOrbiterF * 3169061375011420121U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12730414371734709356U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4819112390640821927U;
            aOrbiterG = RotL64((aOrbiterG * 8782547948627685451U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3089925954422937464U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7180179304678622530U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17030269962085008657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6675917351883004046U;
            aOrbiterE = RotL64((aOrbiterE * 14134335325316949687U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12572022803491077491U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2801421744689267375U;
            aOrbiterB = RotL64((aOrbiterB * 315045745990934023U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4335148696780313055U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12526298573395110141U;
            aOrbiterC = RotL64((aOrbiterC * 11276803410698178607U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6984239833558496091U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 12195433952105336808U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8642600547427664495U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 58U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 43U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 14U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12206U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 13218U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13527U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 11654U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13094U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13318U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneA[((aIndex + 11522U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 40U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 57U)) + 15316464782468770057U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 13U)) + 6642872057476351588U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 34U)) + 660732654689529192U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 47U)) + 7235418086884000655U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 19U)) + 14784518476694580493U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 12222433977933449375U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 8573001207708329927U) + aPhaseBOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 16035256260815013172U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 4U)) + RotL64(aCarry, 37U)) + 15767726974121910203U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17712217935322939971U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13488963456923357159U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16785285630840310405U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10222949131965611079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1495561412321657209U;
            aOrbiterF = RotL64((aOrbiterF * 9706305581868526265U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16156530750584361434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7773792489045606309U;
            aOrbiterD = RotL64((aOrbiterD * 10730624207715601393U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11544578291333360613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3665587867634242865U;
            aOrbiterI = RotL64((aOrbiterI * 4840528190844842595U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15248434984650998090U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15487979645426567581U;
            aOrbiterG = RotL64((aOrbiterG * 10868107809356766183U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6972347795052712690U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16074994810010431338U;
            aOrbiterJ = RotL64((aOrbiterJ * 1262655238856775853U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16851139687900415292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14630026837021552812U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9577900853521254603U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14236330619137368169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17778707026111136216U;
            aOrbiterK = RotL64((aOrbiterK * 16239561893843454747U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9390961969105999083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1174881758316573228U;
            aOrbiterC = RotL64((aOrbiterC * 6602061268277529311U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterJ, 51U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 6U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + aPhaseBWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 13U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 48U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 34U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13723U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15222U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13658U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15363U)) & W_KEY1], 51U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 13682U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13866U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14356U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aScatter, 43U)) + 4259993311776766595U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 2857813330021126753U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 39U)) + 1345396841329442896U;
            aOrbiterC = (aWandererD + RotL64(aCross, 18U)) + 320992148982301024U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 35U)) + 5619109532065293074U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 10380157329426706345U) + aPhaseBOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 12449831150625409695U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + 7847096607042268396U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 28U)) + 11707184096803214678U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9893643746186827088U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 333687403830908774U;
            aOrbiterG = RotL64((aOrbiterG * 17911256836121454271U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13837360705077441580U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4367119682175710689U;
            aOrbiterH = RotL64((aOrbiterH * 10295744669174603401U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1193493435041306784U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15062951612027370606U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2509383510565136549U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16000173839235429105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15294482444605409961U;
            aOrbiterD = RotL64((aOrbiterD * 1031800997944302665U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5720749055549773527U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17248674962996093668U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15730637462755795591U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16956840483882091059U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9637715107943515594U;
            aOrbiterJ = RotL64((aOrbiterJ * 8878362378343603463U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7147495779349862274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7508890985889484275U;
            aOrbiterK = RotL64((aOrbiterK * 17728368447504622035U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4407738164617959366U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17027017782352660454U;
            aOrbiterF = RotL64((aOrbiterF * 417183060881259295U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3174658601748235285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9779053567370714831U;
            aOrbiterA = RotL64((aOrbiterA * 6383245776181968033U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 12U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterD, 24U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 47U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 28U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 53U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 39U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterJ, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 22U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17175U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 17265U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 18608U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18604U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16963U)) & W_KEY1], 52U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17361U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19105U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aIngress, 36U)) + 439898681482066326U) + aPhaseCOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 17362083676671776094U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 6418499837265155024U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 17262244253027454972U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 60U)) + 2382066162993139503U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 19U)) + 14345808395587174135U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 13U)) + 7534743166385552851U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 16994453324688523966U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 27U)) + 7079553728544045092U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3562822704508440641U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13990892681975857821U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8352929306654078795U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1796728922368577238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6605161260520067178U;
            aOrbiterC = RotL64((aOrbiterC * 8147537646591674091U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 13994083795942328918U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6144523182899107711U;
            aOrbiterI = RotL64((aOrbiterI * 4153879991344611283U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12247462325297436642U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1065809332002012789U;
            aOrbiterA = RotL64((aOrbiterA * 5496601177032953251U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10147919864511540753U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17138553441127273354U;
            aOrbiterF = RotL64((aOrbiterF * 5773875596275267871U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2653924016109573974U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 813046408080197079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9624466135414123483U;
            aOrbiterK = RotL64((aOrbiterK * 6960320253124395015U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 972586705850825744U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 155283774901960223U;
            aOrbiterG = RotL64((aOrbiterG * 9928051687724257041U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18200100644751360406U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1168426822045686004U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5867027156069481313U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 58U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterA, 34U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterC, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 56U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20104U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 20191U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21356U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21571U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21573U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20848U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19643U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 19690U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aIngress, 27U)) + 4752759164691497960U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 47U)) + 12088872623537639782U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 3734943577379734227U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 60U)) + 8854778183012444234U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 3U)) + 16948373492893967275U;
            aOrbiterH = (aWandererE + RotL64(aCross, 43U)) + 7962415690046184385U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 1872682375669714454U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aIngress, 56U)) + RotL64(aCarry, 35U)) + 7776801806943853566U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 35U)) + 16665439117257230732U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11088186766134265676U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10850237991780969350U;
            aOrbiterC = RotL64((aOrbiterC * 7547414856143095121U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6464817712131305812U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 244557182884209844U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2394270354887582889U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13261563971157415841U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2323811103717827362U;
            aOrbiterA = RotL64((aOrbiterA * 11483723582415081925U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12338803568475493422U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2811342930111104982U;
            aOrbiterD = RotL64((aOrbiterD * 5020981755203607757U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5554497011738996057U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12712169745460598698U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1985586486150377769U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17415058661427002973U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9430421222715343818U;
            aOrbiterB = RotL64((aOrbiterB * 10321140659099470811U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3926618548181233180U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6172453297026957838U;
            aOrbiterJ = RotL64((aOrbiterJ * 1161551082037835233U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8633288765997226004U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 17270881130844274342U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8888559940161770791U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12232950994807835262U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15352600312956742750U;
            aOrbiterF = RotL64((aOrbiterF * 6140396356904933003U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 28U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 42U) + aOrbiterI) + RotL64(aOrbiterB, 56U));
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22526U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 23017U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23273U)) & W_KEY1], 23U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23575U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23435U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24122U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23115U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 23560U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 6361545377408870615U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 2967245486744774933U;
            aOrbiterF = (aWandererB + RotL64(aCross, 11U)) + 3836634268482850139U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 38U)) + RotL64(aCarry, 13U)) + 7691642115360086297U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + 16479280384178279281U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 2901468732552539249U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 3U)) + 2600353867755647475U) + aPhaseCOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 51U)) + 5666596904781510956U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 58U)) + 16108791609267427553U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8389926875737312112U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1689501721163024426U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6517194895779049139U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11721701506949917719U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3963842745030140473U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8510538243472109368U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 18281865214102080387U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1351546966368884609U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2259725140963665123U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11652011949557979650U;
            aOrbiterI = RotL64((aOrbiterI * 11260100762113295037U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1116085424226174473U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4725260319270802912U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4697109059565450269U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7348945429843437036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1249234309180653260U;
            aOrbiterJ = RotL64((aOrbiterJ * 3136745255820405881U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12463505532573389603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2304125977906510386U;
            aOrbiterA = RotL64((aOrbiterA * 9960816714791454421U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2178037443783425551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11712110130079307683U;
            aOrbiterB = RotL64((aOrbiterB * 9797864956200779505U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10703510612147312252U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18155460326242413483U;
            aOrbiterD = RotL64((aOrbiterD * 6903953708987478723U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 14U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 10U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 50U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterI, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 14U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 57U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26503U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 27299U)) & W_KEY1], 42U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26718U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 27213U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26646U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25470U)) & S_BLOCK1], 22U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26159U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25109U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 26U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 48U)) + 4068921616130916949U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 11U)) + 12077715273915151726U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 57U)) + 16047546802670596833U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 35U)) + 9690277462716999763U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 14484814700447992628U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 17089267243053958210U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 19U)) + 9138746214446211147U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 35U)) + 10181001536979097045U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 53U)) + 6657458969093373191U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7515983477876590988U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3039935555863947600U;
            aOrbiterC = RotL64((aOrbiterC * 12511160550780270119U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16209389224740851136U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 725253312098083182U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17535989492095522597U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13307041115748941383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7159572004825238263U;
            aOrbiterF = RotL64((aOrbiterF * 4855009895002398449U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12027236743251643820U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8717826175991286553U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1175614802543098451U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4769096034227659937U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11201226563992939616U;
            aOrbiterD = RotL64((aOrbiterD * 15595355978388159931U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17295978531215563256U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11850923890626719833U;
            aOrbiterA = RotL64((aOrbiterA * 3854851059897397075U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14139441565288097706U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 988684899382304485U;
            aOrbiterK = RotL64((aOrbiterK * 11929090869999700891U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6159251276942253175U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4849529993914550651U;
            aOrbiterI = RotL64((aOrbiterI * 18240712676783671317U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6679745455842119497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15838404437552215214U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17357853511591350887U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 56U)) + aOrbiterC) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 60U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29077U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 28696U)) & S_BLOCK1], 10U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28865U)) & W_KEY1], 43U) ^ RotL64(aFireLaneC[((aIndex + 29063U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29260U)) & W_KEY1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28122U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28415U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 27311U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 44U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 27U)) + 16424657151168221875U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 17150123681886380361U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 5U)) + 16041993588694572757U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 47U)) + 9871185846434828537U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 11227236398354430757U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 5399325217402192631U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 57U)) + 9248828789282890454U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 43U)) + 9041370494203701062U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 36U)) + 14944424084524970764U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 5481938174456671041U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14783648629543752715U;
            aOrbiterJ = RotL64((aOrbiterJ * 7260164783191886395U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12355573914530445723U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9863991559011968318U;
            aOrbiterH = RotL64((aOrbiterH * 8495251211794343179U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16149688605937250965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterE = RotL64((aOrbiterE * 12199934305374582599U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8076098639554567792U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11155119311895580013U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1495180896564818647U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6847612160595917702U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16094377920388017367U;
            aOrbiterD = RotL64((aOrbiterD * 4875801863643206333U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13584719866672696684U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13446209321646234607U;
            aOrbiterI = RotL64((aOrbiterI * 9945349065094781529U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15829806645369560988U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12573767256739062550U;
            aOrbiterF = RotL64((aOrbiterF * 5649504278826069077U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3850030870300393809U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11857593987748189858U;
            aOrbiterK = RotL64((aOrbiterK * 15942863910931814193U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5505918410521728373U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12949653497121247860U;
            aOrbiterG = RotL64((aOrbiterG * 90944913639560027U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 56U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 18U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterJ, 52U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30753U)) & S_BLOCK1], 26U) ^ RotL64(aKeyRowReadA[((aIndex + 31451U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32475U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30785U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31493U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30677U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 10U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 13650869943246163567U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 3435284932011770999U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 29U)) + 12388155658186776579U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 57U)) + 2374345913955712039U) + aPhaseDOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 51U)) + 6095094526980292156U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 5U)) + 4965147025852444174U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 13U)) + 3261881216269075298U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 24U)) + 4939780217097329222U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 3019862009792676287U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 901910626217143974U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3647055146712366383U;
            aOrbiterE = RotL64((aOrbiterE * 1792602402476450009U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7731765438957392967U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13409819457393479741U;
            aOrbiterA = RotL64((aOrbiterA * 3345078200262410715U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5415832109107794258U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8876738832313114471U;
            aOrbiterD = RotL64((aOrbiterD * 1304277600444504135U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17135570542519390359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2373193062766802082U;
            aOrbiterH = RotL64((aOrbiterH * 4213691513185791519U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16318403285501718552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8456043288604687045U;
            aOrbiterB = RotL64((aOrbiterB * 10556964529144571683U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10572534930284516528U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14616251186735204677U;
            aOrbiterG = RotL64((aOrbiterG * 2048651204265459805U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 2837006243817205610U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5315917323622194254U;
            aOrbiterI = RotL64((aOrbiterI * 4080522050089666599U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12084676282761185907U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7922080344175593788U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7603522302708937379U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17620847289789547792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12140386059533463650U;
            aOrbiterF = RotL64((aOrbiterF * 1443266480620969535U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 30U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 60U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 41U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterI, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_PickleBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2254U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 4206U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4816U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1037U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3605U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aScatter, 14U)) + 10038936806177516123U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 43U)) + 1773168435195292638U) + aPhaseEOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 5U)) + 10655711161526628072U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 35U)) + 14422295664639740437U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 4125228715513159576U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 3670449653158650845U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 17553727567180813057U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5111401772713882743U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7688573124662314413U;
            aOrbiterI = RotL64((aOrbiterI * 10846442063022821393U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9438375825507814395U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14177477039902118886U;
            aOrbiterE = RotL64((aOrbiterE * 6467406626985022537U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16329942595859623928U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3990536794006836672U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 579024714339065373U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5072881436583180756U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 16789727877867289997U;
            aOrbiterJ = RotL64((aOrbiterJ * 8766246302636197905U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17313956922306689438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11530878396329822041U;
            aOrbiterH = RotL64((aOrbiterH * 11356860047841383129U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3612616532321160196U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4172189825359187763U;
            aOrbiterB = RotL64((aOrbiterB * 12938945495299393177U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8677279703778052804U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1912172980909479362U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10053289257955474143U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aPhaseEWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 18U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF + ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10751U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 7928U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 10060U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8700U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7675U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 60U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererC + RotL64(aScatter, 29U)) + 3105313968748067810U;
            aOrbiterB = (aWandererK + RotL64(aCross, 35U)) + 9977249451119627064U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 53U)) + 17941392803495349366U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 4279533326705471133U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 47U)) + 13983828966811580039U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 41U)) + 3983490984234810378U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 308786542215259956U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8443607695364427037U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14939626441464340668U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16793255020331774983U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9350693577306121110U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1717071159396961752U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11062480662625054525U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15911765265202100610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14898546272333182767U;
            aOrbiterG = RotL64((aOrbiterG * 2674900543810733067U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 3560903518513465868U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5367062725726860234U;
            aOrbiterI = RotL64((aOrbiterI * 8521908836601319553U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15233321480618877327U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9288449812290126074U;
            aOrbiterD = RotL64((aOrbiterD * 6815298520404038519U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5504840529511585676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6825598386801620046U;
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 6433024450721339470U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 97934156644929458U;
            aOrbiterB = RotL64((aOrbiterB * 8630530773006923215U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 48U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 30U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterI, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15890U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 11362U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11241U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13534U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13441U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 15683U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 5480870806135400132U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 8034874599430768743U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 51U)) + 4006919843736863767U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 2988069748674633718U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 12347295651973135786U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 27U)) + 14152683894431568192U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 20U)) + 15765143815254196598U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10473067082331244233U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1089466925383677249U;
            aOrbiterG = RotL64((aOrbiterG * 17334888609179149753U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13215039929873682230U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3957997712247961479U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7631186240013784703U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10023907397941685546U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14593012591254614353U;
            aOrbiterF = RotL64((aOrbiterF * 17111300092082154687U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13353797968154036726U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9259966668512102858U;
            aOrbiterE = RotL64((aOrbiterE * 8326732574268308221U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10757861831070349321U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10530223113483866178U;
            aOrbiterD = RotL64((aOrbiterD * 11269177745265396583U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7554320926405521865U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6978052067277966996U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18020134738536217801U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1053695861967171420U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15980734683539854451U;
            aOrbiterI = RotL64((aOrbiterI * 3208466640010555357U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 3U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 28U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterB, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17820U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 18055U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17169U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21685U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18382U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19875U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aScatter, 47U)) + 16922357079016918108U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 13U)) + 11771749797137599131U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 41U)) + 4635668433708036077U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 15827952719230577008U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 1495675306110023086U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 29U)) + 7294835466949728365U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 179122461212041978U) + aPhaseEOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 545981421632236251U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15338259639814630535U;
            aOrbiterI = RotL64((aOrbiterI * 14895421566334357871U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12924313840290895215U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 17846785921286020610U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18309347016029917133U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5721472794107057875U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16359630793856870319U;
            aOrbiterJ = RotL64((aOrbiterJ * 14186771515526698907U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10614102110239037308U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16421992251278236531U;
            aOrbiterB = RotL64((aOrbiterB * 2561232904676068089U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8668149834861244963U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12699331834360948734U;
            aOrbiterA = RotL64((aOrbiterA * 2249360824172616357U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4470693178142950471U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 526000656022724741U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16688501462334673493U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6880246132270094141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7126466778855297013U;
            aOrbiterD = RotL64((aOrbiterD * 5692237926830293205U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterB, 14U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterE, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23763U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 26455U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24807U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22267U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22001U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24700U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 52U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 7790166497945719700U;
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 7136208896846119188U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 11U)) + 12123156943355100886U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 5095546037880875199U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 29U)) + 17642705393916765992U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 47U)) + 9918479837334416990U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 4890009823843176466U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17652590786213674124U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 870002527644696135U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 915408393979165539U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12545429703552643682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5310272867406182581U;
            aOrbiterF = RotL64((aOrbiterF * 10420003334833925011U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3264719049050179440U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1967241238180278937U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 773883832927040736U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12766817190261232485U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7448864556802318431U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 260069382395598265U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15462103891287350123U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5029268763635635753U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4072032867513289827U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17153061419083897076U;
            aOrbiterK = RotL64((aOrbiterK * 11934532169271718913U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6207264270332656966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18048064697837314947U;
            aOrbiterE = RotL64((aOrbiterE * 13632594619404208489U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterI, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterB, 12U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterJ, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 28U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32246U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((aIndex + 27590U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28298U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29891U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32245U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 29461U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 4970414922752555648U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 9462756592787669327U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 41U)) + 3948790686662213095U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 57U)) + 14542857212241578311U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 12U)) + 3387479009827029547U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 1411421370057797877U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 16894451466895681236U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12727136462290223542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4625389198191960525U;
            aOrbiterF = RotL64((aOrbiterF * 5726474430977810191U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3471881403786164913U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6433115856048534831U;
            aOrbiterD = RotL64((aOrbiterD * 9363233870194144053U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9825592965466157982U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1553125767261293088U;
            aOrbiterC = RotL64((aOrbiterC * 411535191177308781U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9951616357109647617U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterB = RotL64((aOrbiterB * 14024961994986659187U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13419663264017317947U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 4835055642466215566U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17898065852351759171U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14558747666410946768U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13120938960926874504U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11910501376797343986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15074100100781785300U;
            aOrbiterG = RotL64((aOrbiterG * 228976960937473851U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 12U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 50U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + (((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterD, 29U)) + aPhaseEWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_PickleBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA, aSnowLaneA, aInvestLaneB, aInvestLaneD, aSnowLaneB, aExpandLaneB, aWorkLaneA, aExpandLaneD, aWorkLaneB, aInvestLaneA, aWorkLaneC, aInvestLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2385U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((aIndex + 3194U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 4679U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4884U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4644U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3147U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 47U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 3255291173184001106U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 26U)) + 15308468160116255528U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 37U)) + 18186972408589866656U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 4439324265978331914U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 13099263173016322486U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 21U)) + 7041561081767500660U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + 6196422612687812971U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 3U)) + 7664260932541281413U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 43U)) + 17802347823020441056U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 18U)) + 4253107484061190446U;
            aOrbiterC = (aWandererH + RotL64(aCross, 5U)) + 13799496534030645312U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14252892847595951926U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5663527578664291422U;
            aOrbiterB = RotL64((aOrbiterB * 18314294235895182465U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11148755959699137661U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17036900929333594592U;
            aOrbiterD = RotL64((aOrbiterD * 16041243617369003291U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2403828181385259549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17813580350434928194U;
            aOrbiterG = RotL64((aOrbiterG * 13666780980793857831U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5623611126885414523U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7293224381174846969U;
            aOrbiterK = RotL64((aOrbiterK * 7032561584670788117U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10602620906929686163U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18015916257203385982U;
            aOrbiterH = RotL64((aOrbiterH * 10684090189688871993U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13592915735376305773U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13995866908043417505U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3802175869395887331U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8200465989447697618U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9866671660800629464U;
            aOrbiterA = RotL64((aOrbiterA * 2138851839905326265U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11557528777230608777U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 131060617338185060U;
            aOrbiterC = RotL64((aOrbiterC * 11068705423012265209U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13404720733342982167U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13128574378042136042U;
            aOrbiterF = RotL64((aOrbiterF * 5805270317312187011U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15879295432652112238U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9433361543323748909U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3592390041363796221U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6262775775981534941U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3255291173184001106U;
            aOrbiterJ = RotL64((aOrbiterJ * 2748492753337241005U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 36U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 50U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneB
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8455U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 6161U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10783U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneB[((aIndex + 8691U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9274U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5530U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 9674U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 16200278595895089008U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 5U)) + 1029614154810465897U;
            aOrbiterC = (aWandererH + RotL64(aCross, 57U)) + 7129562468705441295U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 47U)) + 14388903902433951274U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 44U)) + 1013568949315967455U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 3128823373497815651U;
            aOrbiterA = (aWandererK + RotL64(aCross, 11U)) + 14525694606889470589U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 14443983602196782887U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 21U)) + 12244220415328641190U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 10477159225338766614U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 30U)) + 2842870123078131566U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8621138818955849917U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5038396344400303181U;
            aOrbiterC = RotL64((aOrbiterC * 14636756322207385447U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2768613802894372496U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2848088309172056399U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15017458513904884651U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9926904679902843055U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9079797279596336139U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15424866642305110811U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12912331089970158845U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13751764050290602740U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7694557131324740282U;
            aOrbiterI = RotL64((aOrbiterI * 14980807690491467023U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3508673897305667669U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3600868397311393233U;
            aOrbiterG = RotL64((aOrbiterG * 5165032044164139165U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1222655844979128996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2257342337168905875U;
            aOrbiterE = RotL64((aOrbiterE * 6198995971182272119U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6290990717563682725U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15308494772443447109U;
            aOrbiterD = RotL64((aOrbiterD * 1925593111157842325U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4065385272074155855U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17216369169581934516U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16172589962950781777U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15683161334290612079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4197626901960576264U;
            aOrbiterA = RotL64((aOrbiterA * 2822547214684481747U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4400047838649306704U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16200278595895089008U;
            aOrbiterF = RotL64((aOrbiterF * 6603195071605635697U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 36U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 56U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 26U) + RotL64(aOrbiterF, 41U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 58U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 38U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11593U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 13862U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15047U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13658U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((aIndex + 16247U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 24U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererK + RotL64(aCross, 42U)) + RotL64(aCarry, 13U)) + 3448371607470865612U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 3743742913651580573U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 13069491287948807280U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 13U)) + 16872779275586545632U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 60U)) + 17945792656755062795U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 57U)) + 18199747196793731853U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 15953311878379809513U;
            aOrbiterC = (aWandererG + RotL64(aCross, 23U)) + 941268763494588338U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 19U)) + 10090221530365796809U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 29U)) + 8335698093307607001U) + aPhaseFOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 51U)) + 6147498804734306100U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5980246079567570090U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4152167624425912978U;
            aOrbiterF = RotL64((aOrbiterF * 10019421651535123573U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14990418790239735916U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3418668387496597219U;
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4206650904177199425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3905470780938996069U;
            aOrbiterI = RotL64((aOrbiterI * 16030122739273137005U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9968672788233080924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterH = RotL64((aOrbiterH * 2615726693066300065U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17751667243048041383U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2414054413585296027U;
            aOrbiterG = RotL64((aOrbiterG * 1049512574773201893U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6523322402744047752U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6729901917767398779U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8039939871405367139U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11460169185076814539U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7559640379553110573U;
            aOrbiterB = RotL64((aOrbiterB * 9864654321914036135U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17271150091827475028U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3541809324556914646U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12655168871428868639U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10332471447306597185U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12580133010006951091U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1159183486084705865U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17333553613777910945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14179392055698682109U;
            aOrbiterJ = RotL64((aOrbiterJ * 17675559451285279251U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3996830751779338356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3448371607470865612U;
            aOrbiterE = RotL64((aOrbiterE * 5375529914102609947U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterB, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterC, 21U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 10U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 44U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 54U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererF, 14U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18732U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 21408U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 19933U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17801U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19346U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 19U)) + 8367680518550579791U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 11491674725611181241U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 37U)) + 16673861720782164214U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 51U)) + 9786610124108350855U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 27U)) + 5745080601557577637U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + 1959402215131684684U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 41U)) + 6121650036079196522U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 36U)) + 12016309761037342392U;
            aOrbiterE = (aWandererI + RotL64(aCross, 23U)) + 5986936646177049603U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 53U)) + 1000367700904043468U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 17425288243569101032U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4856917474950325209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16312111093223166419U;
            aOrbiterH = RotL64((aOrbiterH * 11046477664487805241U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 456110002032422270U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11393724374787795662U;
            aOrbiterB = RotL64((aOrbiterB * 1176984359123668389U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8378176867715697176U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8086186452345234815U;
            aOrbiterA = RotL64((aOrbiterA * 8450438271765985235U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8470349167474173245U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterK = RotL64((aOrbiterK * 8717790851266520943U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13247168811545753141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8745293957516815264U;
            aOrbiterD = RotL64((aOrbiterD * 14270617180621072619U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6165915500564961987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12015407798844173213U;
            aOrbiterI = RotL64((aOrbiterI * 3913451986559154153U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 545006684939922156U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16366753936267185001U;
            aOrbiterG = RotL64((aOrbiterG * 6495185976430013201U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3097605623436091728U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15950167830259022926U;
            aOrbiterJ = RotL64((aOrbiterJ * 4415538963984293323U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8356327899232213426U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10183421678251169945U;
            aOrbiterF = RotL64((aOrbiterF * 9474380650337109299U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16327340177970834683U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7086901180933495535U;
            aOrbiterC = RotL64((aOrbiterC * 1276521829484494857U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13421211370092080006U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8367680518550579791U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12256662446176946163U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterC, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 40U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 28U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24955U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneB[((aIndex + 25938U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 23152U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22839U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25202U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aCross, 29U)) + 11521331427196538632U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 56U)) + 16653824187682957632U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 11U)) + 11654676587350088289U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 19U)) + 8010313317412193584U;
            aOrbiterI = (aWandererH + RotL64(aCross, 43U)) + 1108775560502907471U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 243952321439823521U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 2324945800401240403U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 35U)) + 9257554497543369657U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 37U)) + 16701314607244592540U;
            aOrbiterA = (aWandererB + RotL64(aCross, 53U)) + 3900445848034341782U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 40U)) + RotL64(aCarry, 11U)) + 7652316487347103658U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14980368605272070578U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2001165460948764796U;
            aOrbiterJ = RotL64((aOrbiterJ * 8110980921827107649U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1911044015666991050U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11366207111147818339U;
            aOrbiterI = RotL64((aOrbiterI * 17234439040652553865U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16469329744002456607U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8062793687044950815U;
            aOrbiterC = RotL64((aOrbiterC * 5856142259851144369U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15364721421972807872U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8979915611483540231U;
            aOrbiterF = RotL64((aOrbiterF * 10899377466171153383U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7654234623563110457U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1526832460342135008U;
            aOrbiterG = RotL64((aOrbiterG * 12766083052650723051U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1596625448797520938U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15723912914858523080U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6003857787643420337U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7664226719746532168U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13767298788411473401U;
            aOrbiterB = RotL64((aOrbiterB * 15663266144965532019U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8371251860069346385U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10143279934304029980U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12764966547132248131U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10034920090729616747U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14450253491131954914U;
            aOrbiterD = RotL64((aOrbiterD * 15877567779079226909U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9450697155749555210U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14051719612902917300U;
            aOrbiterH = RotL64((aOrbiterH * 7659810299163085295U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 659383614060726993U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11521331427196538632U;
            aOrbiterE = RotL64((aOrbiterE * 1068009283450923005U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 19U));
            aWandererD = aWandererD + ((RotL64(aIngress, 24U) + aOrbiterE) + RotL64(aOrbiterA, 56U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 42U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aInvestLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30419U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 29979U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 31222U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30256U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 27426U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 2101601659597850213U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 23U)) + 2759794072560720121U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 9443562552411269339U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 37U)) + 10801360546699857975U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aIngress, 35U)) + 8020716394829332019U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 57U)) + 1021894212367773801U;
            aOrbiterF = (aWandererH + RotL64(aCross, 39U)) + 13346855534622490176U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 41U)) + 16359309548462953836U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 47U)) + 12642446944680783519U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 3U)) + 8197424982767553380U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 3U)) + 14346334610901859094U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14171304260534233539U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 334531601308283605U;
            aOrbiterJ = RotL64((aOrbiterJ * 5012968232749075075U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10707856298471572695U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 18364775750091914766U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15735143943129143265U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8531394793118363836U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15352876929406908882U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 475199047053777179U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 567682016232278157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2068146551757663119U;
            aOrbiterE = RotL64((aOrbiterE * 1557877740957797555U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7776122587613256525U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16430938890724272256U;
            aOrbiterA = RotL64((aOrbiterA * 4540270493783593257U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11912000645055436094U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 16800749242578741498U;
            aOrbiterK = RotL64((aOrbiterK * 17804584625034241737U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5909199180260499150U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5751089915336865588U;
            aOrbiterD = RotL64((aOrbiterD * 15376689503142397927U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3478216857728853008U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18007567146937338241U;
            aOrbiterH = RotL64((aOrbiterH * 6620498877303917855U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17454259424163653490U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6276120962018305311U;
            aOrbiterB = RotL64((aOrbiterB * 7560618224285018801U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3839336239901666431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6230149015045237670U;
            aOrbiterF = RotL64((aOrbiterF * 1838983748994340883U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17552095486612766544U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2101601659597850213U;
            aOrbiterG = RotL64((aOrbiterG * 2915330118061857271U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 28U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 44U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 14U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_PickleBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 831U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 931U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 536U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4858U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7502U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6114U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 2177539223979303669U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 5U)) + 3962004686551521471U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 54U)) + RotL64(aCarry, 37U)) + 8457602312617147662U) + aPhaseGOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 18011802451816510632U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 21U)) + 9046101759168876832U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11135620637431969597U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15913029940697999701U;
            aOrbiterK = RotL64((aOrbiterK * 646524659942693491U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16304193109948135982U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13208892298820080981U;
            aOrbiterA = RotL64((aOrbiterA * 15093751072618884859U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4182377898949419225U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13970137023071326151U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8402396284835248583U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8859190834060657829U;
            aOrbiterC = RotL64((aOrbiterC * 13552418608113716117U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9760005337757990392U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14108277760135744897U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 26U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15194U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 9845U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 10833U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13840U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13391U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 9888U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 3236820517816085022U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 27U)) + 741288875914097926U) + aPhaseGOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 58U)) + 8417246926007729580U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 9715717805774537170U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 14360243844821619482U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10760908100206775334U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3434641779946167811U;
            aOrbiterA = RotL64((aOrbiterA * 3305698324169010803U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7885568822756234567U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3041563437672051294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11440300917533482297U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15761355327564963516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1158633562785937421U;
            aOrbiterK = RotL64((aOrbiterK * 15511324886867188235U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9338581575871970653U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9172038894262857354U;
            aOrbiterE = RotL64((aOrbiterE * 3110871165285625807U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14653924713599790081U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3854497592598563309U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11737111068815795303U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 54U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 56U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18950U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 16818U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22565U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16727U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17057U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 22166U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 8402620908307642697U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 56U)) + RotL64(aCarry, 5U)) + 11347672014525086047U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 27U)) + 2816462912503401876U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 6940159795470696093U;
            aOrbiterA = (aWandererD + RotL64(aCross, 19U)) + 9134692490095883851U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4999455497008026526U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5992451460350651332U;
            aOrbiterC = RotL64((aOrbiterC * 12796550245322491401U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3417087346651371924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3612773820086198270U;
            aOrbiterI = RotL64((aOrbiterI * 5519856345435871169U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 463398077083428570U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11249391303705089012U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7106735772303292983U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17027535139825739501U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 568131384979596481U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5683451044852895957U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4793712537158004047U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10415170179135963622U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13729564030210361415U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            aWandererB = aWandererB + (((RotL64(aScatter, 54U) + aOrbiterI) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25461U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((aIndex + 28863U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 32523U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28855U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28409U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24995U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 9446153639709651566U;
            aOrbiterK = (aWandererG + RotL64(aCross, 39U)) + 10550762260670758167U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 7062634922142578383U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 9178499097812764515U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + 6887103379773525538U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6239750312052010257U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17645022614523287959U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14448140327044053545U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3639618183259408272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3131737117548745095U;
            aOrbiterD = RotL64((aOrbiterD * 6585057380704940395U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 7253994382396406554U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15217993711938379561U;
            aOrbiterK = RotL64((aOrbiterK * 17853313384747259923U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12594152227603630033U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11250170200489647869U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 546800378327864723U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12936942656624279424U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10990736056052106149U;
            aOrbiterF = RotL64((aOrbiterF * 7123916809953459187U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 22U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 35U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_PickleBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2388U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 3831U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 1381U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4341U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7016U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4341U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 13U)) + 2571116506511057880U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 3U)) + 13112435411509707292U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 10403251762787357256U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 8461951095541400405U) + aPhaseHOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 21U)) + 9890793478557463815U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3030229465991783707U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 7273848154043719247U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17562254601517935669U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10681774862516028276U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7105082755586853104U;
            aOrbiterB = RotL64((aOrbiterB * 12217705329504230357U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 6588579345319551129U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14616333550242386092U;
            aOrbiterG = RotL64((aOrbiterG * 2934574715879306337U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15439666290229654921U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3360304356760164799U;
            aOrbiterF = RotL64((aOrbiterF * 5164191920584106237U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14438730801970761889U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14515616787452085729U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 58U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11457U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 15824U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10305U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9569U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9767U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 11724U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 6521330037475130256U;
            aOrbiterK = (aWandererF + RotL64(aCross, 54U)) + 12611880456055428940U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 12061611078130934708U) + aPhaseHOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 1558112410801116984U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 10509115227850160786U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4045915960688792066U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1196541286513243082U;
            aOrbiterA = RotL64((aOrbiterA * 5454309408259753479U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15564991032722373702U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4897765238703641798U;
            aOrbiterI = RotL64((aOrbiterI * 9693901276712946763U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12327429514907752733U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6189189797708711636U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9017615866338877651U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6374267075282018852U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1888758503831341439U;
            aOrbiterC = RotL64((aOrbiterC * 74387714918264257U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14956857689299491800U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14879361107223331957U;
            aOrbiterE = RotL64((aOrbiterE * 9166712966729591953U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 38U) + aOrbiterA) + RotL64(aOrbiterC, 37U)) + aPhaseHWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21555U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 21965U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23224U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23518U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20424U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 18625U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 12809562813316740345U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 11U)) + 17084212535326321199U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 38U)) + 16074921689983846769U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 14027986153007120145U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 7633455951809250227U) + aPhaseHOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 340989348513370174U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5307820377645020116U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8402492604131262157U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5605285015771527274U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5293500434746182790U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17674669610895537063U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7263156475892261811U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10672879570907433005U;
            aOrbiterH = RotL64((aOrbiterH * 2506338667179450741U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16659226780900986107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9774892622769850665U;
            aOrbiterB = RotL64((aOrbiterB * 7487477727543183211U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10728057184108279042U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5032485856947407217U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16651577903809154285U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 54U));
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 38U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 52U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27021U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 30597U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26204U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32076U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26971U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 28945U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 43U)) + 12690502671561165478U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 17519943923428102801U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + 10705515807975331385U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 16586447272278538179U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 8006560996840971798U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12928600185788857701U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14240723153798267172U;
            aOrbiterE = RotL64((aOrbiterE * 7446040187505339853U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8636219177994872072U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7586790235186467512U;
            aOrbiterJ = RotL64((aOrbiterJ * 15052686382507614169U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1103807034179512424U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7547526530239498693U;
            aOrbiterF = RotL64((aOrbiterF * 3360295583636013509U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8380239679344786397U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5354724308093372953U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8390902801141804609U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3507306189192059486U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18336280496510253103U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 36U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 14U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
