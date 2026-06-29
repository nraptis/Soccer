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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD8D1FC195CC4ED87ULL + 0x8B110A06DF2988F2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBAF7D0D3534516C1ULL + 0xEB0EFE2156E9A502ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9A4D558E35F5FC83ULL + 0xF6C7E0113FFCFF16ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF01567C7C7152E97ULL + 0xA20708B446043C7CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEBA3683E7BD0FC77ULL + 0xCB6A0278169506D7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9E02E457D0FBCDBDULL + 0xE8745298786088A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC758F050CBE7DA3FULL + 0xB96DEF81F96A12A9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE20F66E4C4F6A445ULL + 0xDAC9AFA4764335E0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD9F39EC25EFE4473ULL + 0x97852941AA0D064FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEFC08BA6FB8EE043ULL + 0x9A81CE3F5ADA5A58ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF3A515B09736EAE3ULL + 0xEDBCA4DD4817B2B7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD1D24C7B19E24F8BULL + 0xFF0CA21782AFFD12ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB8BF5DCD1C7ADDD3ULL + 0xD0AE8B36DE6E370CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xFAAC4DA25B2DB555ULL + 0x828D581DFEDE2423ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFC034566CE4F33A1ULL + 0xFAE229F7A6A8D528ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCFB84D02AA09A32BULL + 0xD0094D0AEA24CDC9ULL);
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
            aIngress = RotL64(mSource[((aIndex + 1032U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((aIndex + 3519U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 999U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3664U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 24U)) + 3973833383430652211U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 3U)) + 5760227042747169187U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 21U)) + 4923009065139227286U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 1477807307009107590U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 13U)) + 5707194514329007301U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 5340439728375269724U) + aNonceWordG;
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 17080457898946572387U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 18U)) + 281559150259472813U;
            aOrbiterG = (((aWandererE + RotL64(aCross, 57U)) + 16160633048230910560U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 35U)) + 9003989610509592121U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 10579322462808454333U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15059383289528723069U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10417647757852880956U;
            aOrbiterC = RotL64((aOrbiterC * 1457919230286043137U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14484665027393813330U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12344463053485837974U;
            aOrbiterH = RotL64((aOrbiterH * 5762654194001525041U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5826453246659297805U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12547902286376986223U;
            aOrbiterK = RotL64((aOrbiterK * 2982850000322672789U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9637855144278126174U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2132744427444501938U;
            aOrbiterG = RotL64((aOrbiterG * 5911587798564836199U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9248933938130311231U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13274297928717090383U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 2901398809555237563U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3690262236918560930U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3626005326410800344U;
            aOrbiterF = RotL64((aOrbiterF * 13030443356669355355U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10801089744186148218U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5446653082176311031U;
            aOrbiterD = RotL64((aOrbiterD * 4594267575901248321U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3205541585889107366U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4532327942368884436U;
            aOrbiterI = RotL64((aOrbiterI * 16287094987689326229U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9755333481079721632U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 722154154363571049U;
            aOrbiterE = RotL64((aOrbiterE * 11002432494248958957U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8071668483354405205U) + aNonceWordI;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 8770466248803121315U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 12780438190628717807U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1999251593502332271U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 3973833383430652211U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 5325244982474631559U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 48U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterD, 14U)) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 35U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterF, 48U));
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 6848U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 8276U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9500U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7627U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 52U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 23U)) + 9855743441035905047U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 19U)) + 8426286937143990276U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 27U)) + 7146752367170267002U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 12947210066678101726U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 15902163559925328965U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 8506649889346449469U) + aNonceWordN;
            aOrbiterE = (aWandererK + RotL64(aCross, 50U)) + 8226286036430263052U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 41U)) + 2703047093452420216U) + aNonceWordL;
            aOrbiterD = (aWandererD + RotL64(aScatter, 21U)) + 6769351326360139560U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 53U)) + 9857025533281333281U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 30U)) + RotL64(aCarry, 41U)) + 238297452132277585U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7203572312072908931U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12497027346166575632U;
            aOrbiterB = RotL64((aOrbiterB * 1703586436725662307U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 473851890609048879U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1664484956453886047U;
            aOrbiterK = RotL64((aOrbiterK * 8566500756326590209U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4635095143004754116U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17695676150967345793U;
            aOrbiterA = RotL64((aOrbiterA * 5780416541584439301U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15628965269863402796U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9190117464399730235U;
            aOrbiterI = RotL64((aOrbiterI * 5586437438425999715U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17835918238346011086U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 4398005402429282682U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 14828737209913317463U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10902589938246551273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15124274429081385923U;
            aOrbiterE = RotL64((aOrbiterE * 13524180348258805367U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8747233520702236018U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5445611443463112371U;
            aOrbiterD = RotL64((aOrbiterD * 10294109295823410447U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16296005217836151910U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6468336224317602364U;
            aOrbiterG = RotL64((aOrbiterG * 7369779919748367133U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3827976387089403774U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7773383658122100111U;
            aOrbiterF = RotL64((aOrbiterF * 9784711300597525161U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18273794621528918389U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8401424792700263455U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13003420427441089595U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11402828934846813949U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9855743441035905047U;
            aOrbiterH = RotL64((aOrbiterH * 7339549576423555273U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 29U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterC, 46U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterF, 48U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 13890U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15859U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15861U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 15665U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (aWandererB + RotL64(aScatter, 29U)) + 15316464782468770057U;
            aOrbiterB = (aWandererG + RotL64(aCross, 24U)) + 6642872057476351588U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 41U)) + 660732654689529192U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 27U)) + 7235418086884000655U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 13U)) + 14784518476694580493U) + aNonceWordE;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 35U)) + 12222433977933449375U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 8573001207708329927U;
            aOrbiterE = (aWandererF + RotL64(aCross, 53U)) + 16035256260815013172U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 15767726974121910203U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 19U)) + 17712217935322939971U) + aNonceWordO;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 22U)) + RotL64(aCarry, 39U)) + 13488963456923357159U) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10222949131965611079U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 1495561412321657209U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16156530750584361434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11544578291333360613U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3665587867634242865U;
            aOrbiterB = RotL64((aOrbiterB * 4840528190844842595U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15248434984650998090U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15487979645426567581U;
            aOrbiterJ = RotL64((aOrbiterJ * 10868107809356766183U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6972347795052712690U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16074994810010431338U;
            aOrbiterD = RotL64((aOrbiterD * 1262655238856775853U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16851139687900415292U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14630026837021552812U;
            aOrbiterK = RotL64((aOrbiterK * 9577900853521254603U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14236330619137368169U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17778707026111136216U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 16239561893843454747U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9390961969105999083U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1174881758316573228U;
            aOrbiterF = RotL64((aOrbiterF * 6602061268277529311U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3025148570039849574U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2813499258480831171U;
            aOrbiterE = RotL64((aOrbiterE * 12272555492688861861U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15397952138592662354U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10394648143430175275U;
            aOrbiterA = RotL64((aOrbiterA * 18195627209519212303U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3043205345760158739U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15316464782468770057U;
            aOrbiterI = RotL64((aOrbiterI * 8162506622688910545U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterD, 4U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterG, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18194U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 21471U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19271U)) & S_BLOCK1], 21U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17445U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20900U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 40U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + 3255291173184001106U) + aNonceWordM;
            aOrbiterH = ((aWandererC + RotL64(aCross, 27U)) + 15308468160116255528U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + 18186972408589866656U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 60U)) + 4439324265978331914U) + aNonceWordL;
            aOrbiterB = (aWandererK + RotL64(aIngress, 5U)) + 13099263173016322486U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 7041561081767500660U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 6196422612687812971U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 23U)) + 7664260932541281413U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 37U)) + 17802347823020441056U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 11U)) + 4253107484061190446U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 51U)) + 13799496534030645312U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14252892847595951926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5663527578664291422U;
            aOrbiterF = RotL64((aOrbiterF * 18314294235895182465U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11148755959699137661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17036900929333594592U;
            aOrbiterA = RotL64((aOrbiterA * 16041243617369003291U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2403828181385259549U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17813580350434928194U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 13666780980793857831U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 5623611126885414523U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7293224381174846969U;
            aOrbiterE = RotL64((aOrbiterE * 7032561584670788117U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10602620906929686163U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 18015916257203385982U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10684090189688871993U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 13592915735376305773U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13995866908043417505U;
            aOrbiterJ = RotL64((aOrbiterJ * 3802175869395887331U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8200465989447697618U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9866671660800629464U;
            aOrbiterI = RotL64((aOrbiterI * 2138851839905326265U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11557528777230608777U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 131060617338185060U;
            aOrbiterD = RotL64((aOrbiterD * 11068705423012265209U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13404720733342982167U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13128574378042136042U;
            aOrbiterG = RotL64((aOrbiterG * 5805270317312187011U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15879295432652112238U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9433361543323748909U;
            aOrbiterK = RotL64((aOrbiterK * 3592390041363796221U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6262775775981534941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3255291173184001106U;
            aOrbiterH = RotL64((aOrbiterH * 2748492753337241005U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 38U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aNonceWordG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 5U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 46U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 22U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 34U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 24437U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((aIndex + 23445U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26572U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25484U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25877U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25028U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 13350544654542863236U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 24U)) + 12364346790125404372U) + aNonceWordO;
            aOrbiterK = (aWandererH + RotL64(aScatter, 19U)) + 9738750172849512764U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 53U)) + 3781373837635491421U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 3U)) + 16635020317512702337U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 5383653921676231276U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 47U)) + 10181959815492056493U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 44U)) + RotL64(aCarry, 53U)) + 10005510924273927017U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 21U)) + 9524687662265740565U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 29U)) + 4259138552009771014U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 57U)) + 8973051213213726023U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17602611840127337490U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8218984546932905269U;
            aOrbiterK = RotL64((aOrbiterK * 17504305273683304231U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 18102186122213487888U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2629927500298092976U;
            aOrbiterG = RotL64((aOrbiterG * 6983280164448292723U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 2491581597835795234U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 9506602492971620955U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9559829640915637163U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13422942713680612924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15037354693234876601U;
            aOrbiterD = RotL64((aOrbiterD * 12692376075738621447U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 12896066842192894694U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2202952306291905855U;
            aOrbiterJ = RotL64((aOrbiterJ * 6779368532763429997U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12160313482450599313U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10812986281270407756U;
            aOrbiterI = RotL64((aOrbiterI * 7786608700746771809U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 12474638293190144525U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5882870951276225224U;
            aOrbiterE = RotL64((aOrbiterE * 15532427302173572457U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3782896138051179209U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10965680631059882311U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14060923998307082385U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15650420683333746952U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4110674660963676864U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11724979274890265275U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 694817156953099464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4402927404825116007U;
            aOrbiterH = RotL64((aOrbiterH * 579586789292520113U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6849178151532923489U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13350544654542863236U;
            aOrbiterB = RotL64((aOrbiterB * 2416097748778941523U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 48U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 41U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 54U)) + aOrbiterI) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            aWandererH = aWandererH + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 32651U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((aIndex + 32585U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31046U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28739U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32276U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28792U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 6467297102954816305U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + 7921154109831114952U) + aNonceWordL;
            aOrbiterE = (aWandererI + RotL64(aScatter, 21U)) + 5701131763215638919U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 27U)) + 10022999076719002684U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 41U)) + 4367135243038982316U) + aNonceWordP;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 44U)) + 14445846824810383592U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 13U)) + 7683697954545773253U;
            aOrbiterH = ((((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 23U)) + 17517006750428030899U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 2052484792684025476U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 11U)) + 6279463052085808926U) + aNonceWordO;
            aOrbiterI = (aWandererB + RotL64(aCross, 4U)) + 679280153651813684U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 2939516520188460569U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1960616434964712325U;
            aOrbiterE = RotL64((aOrbiterE * 15145998415466343039U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12273819390719947361U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5685033154709449397U;
            aOrbiterC = RotL64((aOrbiterC * 9845666295874714959U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9314494172199500653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15757631834636427621U;
            aOrbiterK = RotL64((aOrbiterK * 15483543888965744529U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10878078046389399574U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3583495913766365232U;
            aOrbiterA = RotL64((aOrbiterA * 2913540984990155225U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7385544065754622301U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16839599460207922881U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 240651605910592561U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 13038163804940349251U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2587538594933924000U;
            aOrbiterH = RotL64((aOrbiterH * 3091149760401278671U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 13109518583364738004U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 2447689055742474261U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 12100180201235703193U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5752044906692668618U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6637725371036522120U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6021986525167161115U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16549229877442298618U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12825651879441561108U;
            aOrbiterJ = RotL64((aOrbiterJ * 9079931351967033993U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16088338999978085987U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12584648360998154782U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 2109996837220975261U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7526256599938771686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6467297102954816305U;
            aOrbiterI = RotL64((aOrbiterI * 9289442676936248653U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 56U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA + (((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 29U)) + aNonceWordI) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordA) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 38U)) + aOrbiterG) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA3724BBDB23C6DF5ULL + 0xA1E9195268C791C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC8729635640D3DFBULL + 0xF9975E953800BD1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE65085BC903AD127ULL + 0xA79EF4841D47A22CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8C877335F36ACBE9ULL + 0x9A323C105F6CB309ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9665102704A3B94FULL + 0xC8833188E5660342ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x96E523F0BF998F2DULL + 0xF4AE0335800E269BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB22763424F490D35ULL + 0x90C0F5E3F44B358BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB187D68664BDE5BDULL + 0xF3D6568F0AD89DD8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF2D07E64D90C2261ULL + 0xE1AC455D0ABE97AFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8D45560FB325F3B5ULL + 0xA522F270A9BCD853ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA2A346695736722BULL + 0x9EB41C1CA181D6F2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x90AD4CF2CBEB4F9DULL + 0x9CDC11960997ADB4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8E05A3609D0BE717ULL + 0x8F805717AE5C14F8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x921EA224764CBD63ULL + 0x8977B3136A9CA104ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8A9A96ED54645429ULL + 0xDF69EEA9704653BCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB8E9DB72E4D1F363ULL + 0xC23DB84A5E39AB2BULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6753U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1380U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2657U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4550U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 34U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 40U)) + RotL64(aCarry, 37U)) + 13204735390996728477U;
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 851171359595647173U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 16745304202825290723U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 562392736584913979U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 58U)) + 3244267012529053918U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 19U)) + 17282536111067869133U) + aNonceWordK;
            aOrbiterE = (aWandererH + RotL64(aCross, 53U)) + 14851130066471729068U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 11U)) + 5256130407952363129U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 23U)) + 2904742485828362001U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3723346325449225387U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5344621093694027341U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9044881458629673499U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12919263300833603026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17989801264160996071U;
            aOrbiterC = RotL64((aOrbiterC * 15468293047311883751U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 5022175042377172157U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16684822380107847758U;
            aOrbiterF = RotL64((aOrbiterF * 2834049270263837537U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2740326510600876682U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13981423865219318820U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14593082145080056441U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 231945878229848395U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14139797734944312580U;
            aOrbiterE = RotL64((aOrbiterE * 6492256080432266407U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 16704102101387552373U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8506734780526852552U;
            aOrbiterA = RotL64((aOrbiterA * 4684566118627414659U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2774630043988894695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12490034334296488127U;
            aOrbiterK = RotL64((aOrbiterK * 16765455396278233145U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 545238171291436006U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1023872898002379590U;
            aOrbiterI = RotL64((aOrbiterI * 8626333831510136515U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5065187021047872560U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10391809965648089863U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10912471108849550469U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterF);
            aWandererG = aWandererG + (((((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 37U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterK, 38U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 42U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8297U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 12879U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 12731U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12021U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 12735U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 28U)) + 2177539223979303669U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 3962004686551521471U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 51U)) + 8457602312617147662U) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 18011802451816510632U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 19U)) + 9046101759168876832U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 12U)) + 11135620637431969597U) + aNonceWordK;
            aOrbiterI = (aWandererA + RotL64(aCross, 5U)) + 15913029940697999701U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 23U)) + 16304193109948135982U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 13208892298820080981U) + aNonceWordE;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 4182377898949419225U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13970137023071326151U;
            aOrbiterJ = RotL64((aOrbiterJ * 9075061559681739865U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8402396284835248583U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8859190834060657829U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9760005337757990392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14108277760135744897U;
            aOrbiterH = RotL64((aOrbiterH * 4474681104256093885U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12226316121949012350U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3456392186754113960U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 8704729827929941215U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5004087958637038973U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7176881295123125567U;
            aOrbiterA = RotL64((aOrbiterA * 15272157962928021009U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10889800478505074438U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13728832441482547824U;
            aOrbiterI = RotL64((aOrbiterI * 17588477761978646139U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17345665880706866772U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 301139993853297566U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5812445396758354505U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2061389844760610160U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13631862266139238355U;
            aOrbiterF = RotL64((aOrbiterF * 143613352104722701U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10767186080827509622U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4893486019456886013U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5194746459545610901U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 44U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 38U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 39U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterC, 12U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterK, 23U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17265U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 24241U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 21942U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23312U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23787U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19762U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 54U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + 4773124477323378268U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aPrevious, 35U)) + 16848723289435796005U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 13846642134917107058U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 6472057872482789939U) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 18U)) + 2747019500690707226U) + aNonceWordO;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 9003965289739733880U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 27U)) + 3013390651936257377U) + aNonceWordP;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 23U)) + 3331004709895625067U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 10U)) + 15355010435553517129U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7709870658004280052U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13568728443963926564U;
            aOrbiterG = RotL64((aOrbiterG * 6736090830113688981U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12409548853419307131U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 969183352023661537U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5549220554838837145U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 15370309834426476775U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3896803894396631184U;
            aOrbiterD = RotL64((aOrbiterD * 11018830202891911603U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10848873633291935766U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12885336509190543440U;
            aOrbiterA = RotL64((aOrbiterA * 1487357252619221365U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8252290890093788010U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9201553615601641350U;
            aOrbiterF = RotL64((aOrbiterF * 420321130559162915U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14014209645503188472U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4015071464301844550U;
            aOrbiterJ = RotL64((aOrbiterJ * 17444195018239904971U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16173085647514027347U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16916627014974363360U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 7699587344277490953U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1591680303404522110U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16499606051269327916U;
            aOrbiterH = RotL64((aOrbiterH * 814405848002794813U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6932673635509444619U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8745681160108707944U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 14565255558668084787U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 48U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterF, 10U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterH, 34U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32138U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 32428U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27168U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26024U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32453U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27672U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 20U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererG + RotL64(aScatter, 40U)) + RotL64(aCarry, 3U)) + 5906639480605353429U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 51U)) + 5293518570213287605U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 47U)) + 15383185501428521377U) + aNonceWordE;
            aOrbiterB = (aWandererF + RotL64(aCross, 35U)) + 15364072512743978902U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 41U)) + 4525473357144014271U) + aNonceWordI;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 3U)) + 10400911938125603074U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 16417506293824627550U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 2419329331753341815U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 11U)) + 14929222427923332069U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16771573504983922586U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1863466450051787622U;
            aOrbiterE = RotL64((aOrbiterE * 2585626547126027053U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12895350137096692415U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3700979086526298327U;
            aOrbiterA = RotL64((aOrbiterA * 10279730254867618193U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1977099106211282426U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6144698304096915742U;
            aOrbiterG = RotL64((aOrbiterG * 5039822990560519609U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3858895556659724975U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 1283646340363435327U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 11622421841377018069U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6240532051889108891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 757364889381634634U;
            aOrbiterK = RotL64((aOrbiterK * 943852137901972945U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5272945693977418174U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6850528198786172283U;
            aOrbiterI = RotL64((aOrbiterI * 1966383079897679953U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14431587733859573714U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16124590257870999553U;
            aOrbiterB = RotL64((aOrbiterB * 7755796211433191143U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14912695018110241411U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11098623474413346520U;
            aOrbiterJ = RotL64((aOrbiterJ * 15167688959990872051U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3484847683376368686U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2295388097292719800U;
            aOrbiterC = RotL64((aOrbiterC * 1240808318176106909U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 28U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 60U)) + aOrbiterB) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 44U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 12U)) + aOrbiterH) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aCross, 28U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x96FB035DB2BE52D1ULL + 0xE721BBB351DFE499ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEA429422F9DC410FULL + 0xC905A3B319618D1FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE70677A6D5093A61ULL + 0xA3ACAA290945CB0BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEE0CAB77AF0B9D53ULL + 0x80BAB7E1C7140FEDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAA8B96570478530DULL + 0xDCCBCE398A34FFF9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9E7A2364AC3A711DULL + 0xB86BA9D3502C2C2BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA86EBD4A3F2E9145ULL + 0xAC9E5FFEA422DA09ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xED13C1AB30550217ULL + 0xB0195EB4BB8DFA03ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA89363106F330029ULL + 0xB8240D0DAFF7193DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC09963421CE4AFB7ULL + 0xC96F741BE0EAB7CCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF95B90C299FAF2C5ULL + 0xE8C086ECA03D7D7FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDD76194F1AACE125ULL + 0xCDC9FB9BD1162475ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9382B8E6CD014C7DULL + 0xCB0560E1C4A1A462ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFA9889D8D3D45CF9ULL + 0xE3B510B3DFF7A3C0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xABB7FDE4E8967107ULL + 0xB6350083025E81F3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8028A2F96C1EE511ULL + 0x8D07C8920BA0C7A8ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5540U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((aIndex + 962U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 843U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2005U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 4233U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 11410829607777684449U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 7502698839700975347U) + aNonceWordB;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 38U)) + 13267685058252106173U) + aNonceWordO;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 21U)) + 238242706996630625U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 8184695499511454281U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12767823220461985403U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 12293198423143850330U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 5073886956792823825U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11149495229952495939U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7556992689338382800U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 18232398462716803063U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3431338808774134649U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16863099140844995099U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 752376661101787919U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17872458049880677604U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16760153457252546974U;
            aOrbiterB = RotL64((aOrbiterB * 11225037229069712805U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3115544493537438408U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4359882942759752958U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aNonceWordN);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 52U) + aOrbiterG) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 11U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 58U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8507U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 11401U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 9732U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13892U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8537U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15954U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 28U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererJ + RotL64(aCross, 18U)) + 3236820517816085022U) + aNonceWordJ;
            aOrbiterB = ((((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 741288875914097926U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 29U)) + 8417246926007729580U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 9715717805774537170U) + aNonceWordO;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 14360243844821619482U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10760908100206775334U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3434641779946167811U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 3305698324169010803U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7885568822756234567U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3041563437672051294U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 11440300917533482297U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15761355327564963516U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1158633562785937421U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15511324886867188235U), 37U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 9338581575871970653U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 9172038894262857354U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14653924713599790081U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3854497592598563309U;
            aOrbiterI = RotL64((aOrbiterI * 11737111068815795303U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterB, 53U)) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + aOrbiterB) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 10U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23434U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 21108U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24318U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17371U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16807U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17773U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 19U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 13U)) + 9446153639709651566U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 58U)) + 10550762260670758167U) + aNonceWordE;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 7062634922142578383U) + aNonceWordG;
            aOrbiterI = ((((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 9178499097812764515U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 6887103379773525538U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6239750312052010257U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17645022614523287959U;
            aOrbiterG = RotL64((aOrbiterG * 14448140327044053545U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3639618183259408272U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3131737117548745095U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 6585057380704940395U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7253994382396406554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15217993711938379561U;
            aOrbiterK = RotL64((aOrbiterK * 17853313384747259923U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 12594152227603630033U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 546800378327864723U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12936942656624279424U) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10990736056052106149U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7123916809953459187U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 36U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA + ((((RotL64(aCross, 40U) + aOrbiterK) + RotL64(aOrbiterG, 36U)) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31626U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 27388U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 27933U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32244U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28325U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29659U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28555U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 5131645209694953015U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aScatter, 44U)) + RotL64(aCarry, 51U)) + 12070391048835379854U) + aNonceWordA;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 2604295836242338724U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 53U)) + 14042039029284001596U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 19U)) + 8914654543854559327U) + aNonceWordG;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 2185619407969359869U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5187406295103352574U;
            aOrbiterB = RotL64((aOrbiterB * 10497064008152537837U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8022832481290871217U) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3309891377744201773U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10711028365596196301U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13387065038269133571U;
            aOrbiterE = RotL64((aOrbiterE * 12444578026365205255U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11187001318931801582U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14191473173276034019U;
            aOrbiterD = RotL64((aOrbiterD * 2491253922434756431U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 16207761776716426435U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9677408414452078760U;
            aOrbiterF = RotL64((aOrbiterF * 5487303383095129949U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 44U) + RotL64(aOrbiterF, 18U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + aNonceWordE);
            aWandererF = aWandererF + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9FDDD6E884E83E07ULL + 0xA94920CA30B32485ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93A694364FCF5579ULL + 0xB617DBCDC1142E3FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD02F0F8FE1CDEDF1ULL + 0xCCEC4B055CA193D6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8C630030D2F7E839ULL + 0x93E8B04DD485F7D8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF72AD74066C657F9ULL + 0xA857D45A3DFCF262ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFC37507AEFD3156BULL + 0xB93D46354CC78173ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC0D531E376E1E5CBULL + 0xB0C9F6C4337B8837ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC8C54C0BD7CAD1D7ULL + 0xE36CD79316519AD4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE0D42AF114696F45ULL + 0xB6B782FF85988731ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x88C1E170322AAE77ULL + 0xE4B98F6AFBF7D160ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x88D17094CAE76665ULL + 0xD21EBD4318C2637BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5BA09B5AAFABF85ULL + 0xEE29B4653FB20A16ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC66016AE381199ADULL + 0xB05A808BFCF76BDDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA141909B85FDD45FULL + 0xCB55D46F28757351ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xAC6CA2CC6E50492FULL + 0x8D83A5A10C54D3A5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCA9C2EA0F191C567ULL + 0xC49949696B7739ECULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneC, aFireLaneD, aWorkLaneB, aOperationLaneB, aFireLaneB, aWorkLaneC, aOperationLaneD, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 48U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 138U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 480U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 49U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7012U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 6551U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 41U)) + 826930775230515406U) + aNonceWordN;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 3U)) + 5137814617363250861U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 54U)) + RotL64(aCarry, 53U)) + 14761561947426681616U;
            aOrbiterB = (aWandererI + RotL64(aCross, 23U)) + 12773023438753662590U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 11U)) + 7331345852207096322U;
            aOrbiterA = ((((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 3899381212671247460U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 10072004147620068599U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3424585039401897560U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8246760141625966321U;
            aOrbiterG = RotL64((aOrbiterG * 11478879365443736383U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3655992860610853290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11154618022505863898U;
            aOrbiterF = RotL64((aOrbiterF * 4791494171286145231U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15629361991059709973U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10842068502278489664U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5571312349016336686U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 589313823745748879U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 1356685926549786027U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13633457935771935260U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12684602052812183096U;
            aOrbiterH = RotL64((aOrbiterH * 4689206269919806711U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 5711307583717354204U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7181854170553728211U;
            aOrbiterC = RotL64((aOrbiterC * 9835601115561325911U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1884620014396115821U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1471516373272364262U;
            aOrbiterB = RotL64((aOrbiterB * 5126319375714848029U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 12U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11003U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 16125U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14670U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9284U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9326U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14592U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 13U)) + (RotL64(aCarry, 56U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererC + RotL64(aScatter, 38U)) + 17225673071833726819U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 13U)) + 10301458382103627331U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 19U)) + 3960233050857362414U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 17768665685046605837U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 29U)) + 14471018461213959767U) + aNonceWordL;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 10730597892721340453U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 14863394003122760542U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 9948587274816688296U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3573569431435100993U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2303922230056523077U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8153670675740450590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16438856577722561424U;
            aOrbiterG = RotL64((aOrbiterG * 4689247488336908827U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15765587867581925041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4202521649260798876U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15877659681260461141U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11369910758551088173U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 2551560426129646123U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3005102326163906320U;
            aOrbiterC = RotL64((aOrbiterC * 4241583192662435107U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1675501058857208089U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12774812270956702043U;
            aOrbiterD = RotL64((aOrbiterD * 5488437008504905105U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1044886020922563597U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4857445127457225171U;
            aOrbiterB = RotL64((aOrbiterB * 13223560654459705259U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 34U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aNonceWordH) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 36U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 30U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21967U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 18079U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 22049U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23906U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23054U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16950U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 35U)) + 17454559218352016650U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 8005709669325164803U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 13U)) + 13393741948412816357U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 48U)) + 3665865624348875553U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 3U)) + 8334142570031883436U) + aNonceWordD;
            aOrbiterI = ((((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 17226066128706139657U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 3319093033121522613U) + aNonceWordJ;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 6657535603401588798U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5469746182326331147U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 11315450342347794329U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17846791786050221418U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15939541003714896288U;
            aOrbiterK = RotL64((aOrbiterK * 1400351482213119809U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12076763190461077406U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3594038213596405284U;
            aOrbiterC = RotL64((aOrbiterC * 10244002692575821495U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8301291631324464622U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8460406137668390582U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9117147929757711595U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 7612394867020871200U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8525076134853103975U;
            aOrbiterA = RotL64((aOrbiterA * 5790440201072204659U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11929899088215090379U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7119509166360685726U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1662341427992528823U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5081078459225240607U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17149991983909906705U;
            aOrbiterH = RotL64((aOrbiterH * 950223374568067343U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 12U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterA, 10U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25842U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((aIndex + 31908U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 32674U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26738U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26790U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 28463U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 53U)) + 2672739400294801233U) + aNonceWordH;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 5U)) + 8475624545015101850U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererF + RotL64(aIngress, 51U)) + 1252755112289831257U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 58U)) + RotL64(aCarry, 37U)) + 7938039507649183387U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 37U)) + 8167413146948861022U;
            aOrbiterI = (aWandererG + RotL64(aCross, 27U)) + 17712313989694374353U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 7637042279892596975U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15770412950033467341U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3951812021898608685U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6623127125223204737U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterD) + 8656983621098246507U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17943342344730687317U;
            aOrbiterI = RotL64((aOrbiterI * 16495519451034883813U), 39U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 3087677463651608668U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16493240011924342788U;
            aOrbiterD = RotL64((aOrbiterD * 16898479041530771871U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7750923317452683057U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2185924841611106546U;
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14676868738946722416U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6849098251696302393U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 2599806275837778069U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17817755047153606419U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9900465270314068757U;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11380000891112113701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15930503831156546113U;
            aOrbiterJ = RotL64((aOrbiterJ * 14450535035065393845U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterJ, 60U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x96A708906AABF951ULL + 0xA4C9DFEF5EB59DF4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C8C05FCF6385525ULL + 0xCF142AA67A30E097ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x88C38EFE80427313ULL + 0xAABB65776C82EA53ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB416D3FB9B182409ULL + 0x9CF135AFBBAD6DDFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x837A5328B9F743F5ULL + 0x938F86946D748EDCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA15351CBACFCCFA7ULL + 0xAFAF7379A91AE137ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF898C397220C533FULL + 0xCB84CF0F97CA9532ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC1281C877D98F5BBULL + 0xA6E921A9CC461B0CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEEEF3132FD981387ULL + 0x86F35F145D13E5C9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE9ED6E8ECE8D2839ULL + 0xE4289437F31B3D67ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE9BA76E55826E009ULL + 0xB1C6000171D74740ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF6F7004694105F57ULL + 0xD264251FCBFE63FCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB4E0607B2F220D19ULL + 0xF6285723AADD9DF0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAE2A26BE20E4B865ULL + 0xD745CA9102E2CF8EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8D56A62DB264E457ULL + 0x8E7937FF0308288BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x956551216A45404BULL + 0x94C7D7546F13B2DAULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneB, aOperationLaneA, aExpandLaneB, aOperationLaneB, aOperationLaneC, aExpandLaneC, aFireLaneD, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4364U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 6396U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 1986U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 772U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6850U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3846U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 19U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 2974056819475622600U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 7345051759236356098U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 12738468816846628882U) + aNonceWordM;
            aOrbiterD = (aWandererB + RotL64(aScatter, 47U)) + 7694520596043297922U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 12U)) + 5530753590015084774U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 53U)) + 3776309161718383105U) + aNonceWordB;
            aOrbiterF = ((aWandererI + RotL64(aCross, 41U)) + 784780304358106404U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8999942326995036509U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5194986506064092779U;
            aOrbiterJ = RotL64((aOrbiterJ * 15070787038006135963U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7920040007459652762U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 11311997270710107937U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 6227571709361790209U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5365231114813547251U) + aNonceWordP;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8630110234623825263U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2735881715888325759U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2358235238039571072U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 18059414891616491807U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17150786106857185467U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14526050556461782864U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6937282036603272474U;
            aOrbiterB = RotL64((aOrbiterB * 14954512365270028029U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10105832250694931310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3884223553012098137U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10385284339549648087U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1257633893341505930U;
            aOrbiterF = RotL64((aOrbiterF * 2669950791270500977U), 53U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 50U);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterJ, 26U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9134U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((aIndex + 15765U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 15731U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14223U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13605U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 16104U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 14U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 27U)) + 10915618884692072446U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aScatter, 34U)) + 12634922308499254909U) + aNonceWordC;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 6533934734564499389U) + aNonceWordJ;
            aOrbiterB = (aWandererH + RotL64(aIngress, 41U)) + 6744203303756105181U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 13086782386652045658U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 5693840533331397822U) + aNonceWordB;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 11U)) + 1803663542535024611U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3597219300593287708U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1429753448204448904U;
            aOrbiterE = RotL64((aOrbiterE * 10927459251773273143U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17229017825587322715U) + aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1137574712801062932U;
            aOrbiterF = RotL64((aOrbiterF * 3645832160939819415U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2401991077004083378U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1332473247826139292U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 15029831858261506447U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11730946340796899885U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15319163439700390962U;
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 13U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 4744141870145159917U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6067132201862688684U;
            aOrbiterI = RotL64((aOrbiterI * 6046100687757836027U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14991509179286371800U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4342608825699398682U;
            aOrbiterA = RotL64((aOrbiterA * 10240526103933275875U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3727521409410742075U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3302027219498304367U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12153634588200479559U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 34U)) + aWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 27U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23376U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((aIndex + 16563U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 19586U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20346U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20112U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20228U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 20U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 13296600294247799698U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 5818503518080877515U) + aNonceWordJ;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 27U)) + 6735784238734173597U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 7368398209488856201U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 57U)) + 961734029066455638U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 50U)) + 797011946660892011U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 43U)) + 12841876018396622350U) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16213253970483895623U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15186950557113470375U;
            aOrbiterD = RotL64((aOrbiterD * 4647470430467908107U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5117930310827477341U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12265429373166094162U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13920531346698601568U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14695405206998211456U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13950964363414164279U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7851960904825938443U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9501511171732550190U;
            aOrbiterK = RotL64((aOrbiterK * 5614164120361489613U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5663365182245722077U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9607860124321315555U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 3461820361914280601U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18171052650586819280U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 3442698321538580861U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 6317525514963824829U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1491052813469258970U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3956599824067616133U;
            aOrbiterJ = RotL64((aOrbiterJ * 2928600779267623085U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 52U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI + ((((RotL64(aCross, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 6U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 56U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32643U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 25161U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 26671U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28745U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29815U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 32386U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 5131645209694953015U) + aNonceWordJ;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 11U)) + 12070391048835379854U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 27U)) + 2604295836242338724U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 14042039029284001596U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 43U)) + 8914654543854559327U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 4U)) + RotL64(aCarry, 19U)) + 2185619407969359869U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 37U)) + 5187406295103352574U) + aNonceWordM;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8022832481290871217U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8783061916740573472U;
            aOrbiterB = RotL64((aOrbiterB * 3309891377744201773U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10711028365596196301U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13387065038269133571U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 12444578026365205255U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 11187001318931801582U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14191473173276034019U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 2491253922434756431U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16207761776716426435U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 9677408414452078760U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5487303383095129949U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17812460332794370649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7736423148554132028U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15588733747232852555U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17293203944059014763U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 13487243633338010243U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 9468688858740539095U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15979293016815060755U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17645215484691359547U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1449450767288733995U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 40U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterB, 12U));
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aNonceWordD) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF8B00DBDA0CAE5B7ULL + 0x8918C60BEF16762EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD0AAAF161ED7CA4BULL + 0x9CF5A06A0F4DC427ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD7BAB3190EB30D79ULL + 0xCEF45592CAF60DCAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDDF8BAEBB3420537ULL + 0xDF231B8C7833D8D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB47B3C3660752D4FULL + 0xF8E7F57EB7950AC7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC86C42CAFEE56063ULL + 0x9DAB3A1390879880ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x822B167FCE9FF259ULL + 0xD1542146AAC200BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA09EAB90E421B02FULL + 0x924B4BD6E9F0C95FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE3FD31A37A3D2DDBULL + 0xF255D98959334076ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC4B25D2682A2EDA9ULL + 0xE235CC05729D2C02ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xED7419201D38FFF7ULL + 0xB18DD09FB646783DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD836BD37380DDBA1ULL + 0x8065B59E661CCF9EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB6D211DBB9AF41B7ULL + 0x92F91F1D1F52116AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDBD160D69EC3E6AFULL + 0x9E4B428C8F59F616ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBC7CE77BB1C06C6FULL + 0xB1957EE0106AB4F3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE80B995891EA5273ULL + 0xEA4462017B73B23FULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD, aWorkLaneB, aOperationLaneA, aFireLaneC, aFireLaneB, aOperationLaneB, aWorkLaneA, aWorkLaneD, aOperationLaneC, aFireLaneA, aFireLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3915U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 2016U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8078U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8086U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6568U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 2393U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterB = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 6068543441070417854U) + aNonceWordD;
            aOrbiterG = (aWandererD + RotL64(aCross, 20U)) + 2995980468193441856U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 47U)) + 18020277482171594003U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 23U)) + 4293807434721230702U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 3U)) + 7980599111583893156U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 43U)) + 8593141111851052016U) + aNonceWordI;
            aOrbiterF = ((aWandererI + RotL64(aCross, 13U)) + 5903487523900084325U) + aNonceWordC;
            aOrbiterH = (aWandererG + RotL64(aScatter, 35U)) + 15112035513447930209U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 9854037263057006439U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 30U)) + RotL64(aCarry, 3U)) + 16759760289688823193U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 37U)) + 12622628933030601390U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1264668857268123425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16087995784896123610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7970269262800468363U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14924752223305807461U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5331477046030959632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16534913204255550893U;
            aOrbiterB = RotL64((aOrbiterB * 1013433634373673565U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11042821902537871209U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8069677512345031660U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 13622218526054132397U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 5737130058129936372U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1076627182956662997U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13911061091801078190U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15397603151098990373U;
            aOrbiterG = RotL64((aOrbiterG * 1802890451633592245U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15137326716738637972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11248737008959896786U;
            aOrbiterJ = RotL64((aOrbiterJ * 90789374131547005U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1847847987633923657U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10560748778679145431U;
            aOrbiterH = RotL64((aOrbiterH * 2919333327817231099U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2703726238610290251U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12950671360471467310U;
            aOrbiterC = RotL64((aOrbiterC * 7490327691501537047U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10331504168520449467U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1541527607705280906U;
            aOrbiterD = RotL64((aOrbiterD * 14197400812600186171U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9135056476214341809U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6068543441070417854U;
            aOrbiterI = RotL64((aOrbiterI * 14102524444094948875U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterA, 30U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 21U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 14U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13178U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 13868U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11573U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14622U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8276U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9048U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 26U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 5U)) + 9446153639709651566U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 13U)) + 10550762260670758167U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 7062634922142578383U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 60U)) + 9178499097812764515U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 19U)) + 6887103379773525538U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 6239750312052010257U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 39U)) + 17645022614523287959U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 3639618183259408272U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 3U)) + 3131737117548745095U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 48U)) + 7253994382396406554U) + aNonceWordP;
            aOrbiterF = (aWandererC + RotL64(aCross, 41U)) + 15217993711938379561U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12594152227603630033U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11250170200489647869U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 546800378327864723U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12936942656624279424U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10990736056052106149U;
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12787293075893090465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17154990205620778151U;
            aOrbiterJ = RotL64((aOrbiterJ * 10031369940028159521U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1270827262969060301U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17337623431665013136U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1517262088236356107U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 830330490987911853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6828309232554560547U;
            aOrbiterG = RotL64((aOrbiterG * 9742464176986145819U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11470087853413986203U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10470148870747884420U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 6766079738799967443U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 18315536891901859637U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12264670822285914271U;
            aOrbiterI = RotL64((aOrbiterI * 5841574505408674119U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10931842095884524879U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11134871340959676257U;
            aOrbiterF = RotL64((aOrbiterF * 11714837622285605745U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11484168476761306078U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5964766416973454097U;
            aOrbiterD = RotL64((aOrbiterD * 14721123403032510803U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10646362765367117994U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8994267196877016381U;
            aOrbiterB = RotL64((aOrbiterB * 17386417559346134797U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16797547458402042464U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9446153639709651566U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 567585472220695323U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterE, 20U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aNonceWordA);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 30U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 27U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17332U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 19338U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 19383U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21030U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21139U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 21331U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 47U)) ^ (RotL64(aIngress, 60U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 13442819395490639310U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 36U)) + 8187292523194120936U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + 11469697159823131388U) + aNonceWordH;
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 13414083692375929653U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 11404010733687907517U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 13U)) + 6783212827186218247U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + 8561131439340372614U) + aNonceWordF;
            aOrbiterB = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 6252609642004429113U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 29U)) + 12804867444200448952U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 60U)) + 2739648749603690781U) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 57U)) + 14808861217017399752U) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17588866502571268888U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5882260142735642980U;
            aOrbiterF = RotL64((aOrbiterF * 7688252946143263869U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15493099088132862949U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5175647411532429582U;
            aOrbiterI = RotL64((aOrbiterI * 15226544495598541883U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14279707376173642767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6826363572161275158U;
            aOrbiterK = RotL64((aOrbiterK * 5263708315440161809U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13267185753040999992U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 9980987858092888720U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13210290848800728635U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3582972937645514549U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10140409019562890804U;
            aOrbiterA = RotL64((aOrbiterA * 6944490201647678479U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6160444117287330557U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16344602960561293113U;
            aOrbiterC = RotL64((aOrbiterC * 2319964919335633293U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3497141036108337171U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 91269118352540308U;
            aOrbiterD = RotL64((aOrbiterD * 5160060720189045505U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12739932748793144857U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12820180915064791197U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 5843849637411948699U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17572075652083359962U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10684041099654982701U;
            aOrbiterH = RotL64((aOrbiterH * 7121293375756263771U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10739534650885677354U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9731206787727954809U;
            aOrbiterB = RotL64((aOrbiterB * 3730875775588585547U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9655432616347117764U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13442819395490639310U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 3650859301708619119U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 60U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 42U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30255U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 25038U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 29159U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25079U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28995U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 27686U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 11U)) + 12615321415808640429U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 37U)) + 15712784676459931207U) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 21U)) + 11013335427004930046U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 41U)) + 8298733856304768806U) + aNonceWordC;
            aOrbiterE = (aWandererE + RotL64(aIngress, 58U)) + 6207732959150824216U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 9769864876127544038U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 10782181918651152563U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 39U)) + 5790454015845620939U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 51U)) + 15606578025386733803U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 54U)) + RotL64(aCarry, 51U)) + 5522352539991175304U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 5993355818572869649U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 10864534396947622047U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12090053126235913528U;
            aOrbiterK = RotL64((aOrbiterK * 7250801471645972261U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14191181677234981396U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2258570108233924592U;
            aOrbiterE = RotL64((aOrbiterE * 8307541155393855209U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8448114811381534603U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2702389315763499817U;
            aOrbiterG = RotL64((aOrbiterG * 6710443836432274393U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17202184076718780200U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 150549910056015002U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 195034681254956335U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4910512055808124967U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4783477997418403079U;
            aOrbiterH = RotL64((aOrbiterH * 861977492146512865U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13842899106208709771U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 7930112618036681468U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 8609551859830858419U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8790107242863198659U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6882768826643279144U;
            aOrbiterI = RotL64((aOrbiterI * 13745521454063360763U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12136498871759890015U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8120456314755584336U;
            aOrbiterB = RotL64((aOrbiterB * 1830725195528043575U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14425711740351183016U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15907406009196323049U;
            aOrbiterJ = RotL64((aOrbiterJ * 8599371693260686839U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4878521420367891861U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1184672056055028939U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5963961755367831967U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10126736568567000180U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12615321415808640429U;
            aOrbiterD = RotL64((aOrbiterD * 11663715449073755137U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 53U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterC, 5U)) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 10U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterD) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8DB2FC7ACE9890C5ULL + 0xC6B0E0B568D3A293ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x90D1FFC539C14967ULL + 0xAD477A7227DE206EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAC0233B0F2F14B17ULL + 0xF3B42DC4C33A2515ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC1291BA99523F68DULL + 0xB7DF79B75BCB9B9EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFA01A063FCD80733ULL + 0x9F50460B8D13CB80ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD58BB414DE862FD9ULL + 0xC4FF1712DA5DF65BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE61C2EC0D95B0F1BULL + 0xADF41324E2DA293CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x937D13DF9275251BULL + 0xB20C7937268DBD36ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCC9EB7F96E1BDBCBULL + 0xF35652604C6C2AB4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF09C1D6CA030633FULL + 0xA361205548D8862EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA26B3AC52D85CC21ULL + 0xB833EC714CA9C51AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC917D287404104F9ULL + 0x97C404555E76D5F4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA8585A977812EA5BULL + 0xADCC4D8C0071BFA0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8CF80B066F0F72D5ULL + 0xA97DB8101318C949ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFF87EA1C6C46CF67ULL + 0xD5E6B5A7F889B6CCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC9ED2FB7D100D393ULL + 0xBD378665EA475A90ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneB, aOperationLaneC, aOperationLaneD, aWorkLaneA, aExpandLaneA, aFireLaneD, aWorkLaneD, aExpandLaneB, aFireLaneC, aFireLaneB, aExpandLaneC, aWorkLaneC, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 147U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 160U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 4868U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5201U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1767U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 8104U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 5U)) + 2101601659597850213U) + aNonceWordA;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 2759794072560720121U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 41U)) + 9443562552411269339U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 43U)) + 10801360546699857975U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 39U)) + 8020716394829332019U) + aNonceWordI;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + 1021894212367773801U) + aNonceWordK;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 35U)) + 13346855534622490176U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 16359309548462953836U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 29U)) + 12642446944680783519U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8197424982767553380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14346334610901859094U;
            aOrbiterG = RotL64((aOrbiterG * 16982899923227935679U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14171304260534233539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 334531601308283605U;
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10707856298471572695U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 18364775750091914766U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8531394793118363836U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15352876929406908882U;
            aOrbiterC = RotL64((aOrbiterC * 475199047053777179U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 567682016232278157U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2068146551757663119U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1557877740957797555U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7776122587613256525U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4540270493783593257U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11912000645055436094U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16800749242578741498U;
            aOrbiterI = RotL64((aOrbiterI * 17804584625034241737U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5909199180260499150U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5751089915336865588U;
            aOrbiterA = RotL64((aOrbiterA * 15376689503142397927U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3478216857728853008U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18007567146937338241U;
            aOrbiterB = RotL64((aOrbiterB * 6620498877303917855U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 20U) + RotL64(aOrbiterI, 36U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterA, 5U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 40U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 57U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 56U) + RotL64(aOrbiterB, 53U)) + aOrbiterK) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11435U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 14769U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14552U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10899U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16126U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 11262U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 27U)) + 11450949896247900941U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 3905542253538116335U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 34U)) + RotL64(aCarry, 19U)) + 9529740545977785305U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 5U)) + 1856876631533143492U) + aNonceWordJ;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 51U)) + 84253466320181686U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 23U)) + 12577480918745432444U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 18U)) + 5625703170397704029U;
            aOrbiterF = ((((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 694608607323629282U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aCross, 11U)) + 3993981243536262204U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4119215953484892051U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8785040118556157146U;
            aOrbiterJ = RotL64((aOrbiterJ * 17113521266125471625U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16234403619456882890U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10398727475672860610U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 5086871400049644715U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18327987141759096769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2645964788056875452U;
            aOrbiterI = RotL64((aOrbiterI * 8778681366114628045U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2859452497983106129U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7196557924940881076U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 14415389907490256711U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 930127943984174668U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15673596916054795749U;
            aOrbiterK = RotL64((aOrbiterK * 7505660488733199479U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16673140529110941163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2258448294877833760U;
            aOrbiterF = RotL64((aOrbiterF * 1821550319748977445U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6870209259643931219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12749790107942194104U;
            aOrbiterC = RotL64((aOrbiterC * 4871407285968611725U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17131374134617173866U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6426448390733751612U;
            aOrbiterG = RotL64((aOrbiterG * 12490559588384058417U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15592826434339731146U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 14182944418026376183U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7218860482893476233U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 24U) + aOrbiterK) + RotL64(aOrbiterI, 26U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 44U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23728U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 24515U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24066U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19009U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22508U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23313U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 3U)) + 10038936806177516123U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 1773168435195292638U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 10655711161526628072U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 47U)) + 14422295664639740437U) + aNonceWordC;
            aOrbiterI = ((aWandererH + RotL64(aCross, 3U)) + 4125228715513159576U) + aNonceWordA;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 29U)) + 3670449653158650845U) + aNonceWordH;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 24U)) + 17553727567180813057U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 35U)) + 5111401772713882743U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 39U)) + 7688573124662314413U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9438375825507814395U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14177477039902118886U;
            aOrbiterD = RotL64((aOrbiterD * 6467406626985022537U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 16329942595859623928U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3990536794006836672U;
            aOrbiterI = RotL64((aOrbiterI * 579024714339065373U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5072881436583180756U) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16789727877867289997U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17313956922306689438U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11530878396329822041U;
            aOrbiterK = RotL64((aOrbiterK * 11356860047841383129U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3612616532321160196U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4172189825359187763U;
            aOrbiterE = RotL64((aOrbiterE * 12938945495299393177U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8677279703778052804U) + aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1912172980909479362U;
            aOrbiterB = RotL64((aOrbiterB * 10053289257955474143U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1460085850227494500U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12116763868122868147U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6076945628020280957U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17571840610366424432U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15581362592611080868U;
            aOrbiterH = RotL64((aOrbiterH * 1129054058044872003U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14434700039977611666U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 4534294602623329152U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 5860911553425182045U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 40U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 60U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aNonceWordI);
            aWandererB = aWandererB + (((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25842U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 29623U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30411U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26004U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32303U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25515U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 10404808878585437255U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 40U)) + RotL64(aCarry, 43U)) + 10587858736301591439U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 35U)) + 1430530909801644435U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aWandererH + RotL64(aIngress, 13U)) + 9090938022430118902U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 19U)) + 12936604311751121235U) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 23U)) + 1000583006020232032U) + aNonceWordJ;
            aOrbiterF = (aWandererB + RotL64(aCross, 27U)) + 12352532088997042232U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 3U)) + 16723410947058502564U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 16614089235313154270U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 4245553025593349277U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3353146318549477494U;
            aOrbiterI = RotL64((aOrbiterI * 14246377408238318091U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5935727336135635196U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10312187090293319667U;
            aOrbiterE = RotL64((aOrbiterE * 1395964500396711899U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12192843181244744484U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2542570124502586365U;
            aOrbiterH = RotL64((aOrbiterH * 17222847847573534963U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3315472769469002444U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17512858811783071174U;
            aOrbiterJ = RotL64((aOrbiterJ * 9070400454074283765U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16633218007427888082U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2502077714838858460U;
            aOrbiterB = RotL64((aOrbiterB * 970762420815997725U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14792910273226469214U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15739513291150783151U;
            aOrbiterD = RotL64((aOrbiterD * 11896279674116906915U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2192903544350345992U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 844428341223009295U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4768368713974002539U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2998511458298901402U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7790789639864783373U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4540735375055164995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13700342877362633034U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14730797752841670505U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterI, 30U)) + aNonceWordP);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 26U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC4F30F8181A579C7ULL + 0xCF8F08A7FBE1C559ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD41891BEF1B5D1A7ULL + 0xECF9AEABCA34737AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8969850C7B8AA8DFULL + 0x84D08223DC9EA8DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCBDED12D8734D991ULL + 0x9291C94EFAE3174AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBDAEB7FAED123979ULL + 0xB7EF0436B6FCA66BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF61EEE7BAF58865BULL + 0xF4E61F74EDAFD3F1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8DB7AE9D734E128BULL + 0x9CFDF6D26D4827B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA4459B888B6D312FULL + 0xB8CF03ADE8D70599ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x928F0A1AC0A302B1ULL + 0xE077805EF7AA543AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC726F0FE2A4CC5EFULL + 0xE0B3D2C196909700ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9FFAF70CDE013617ULL + 0xEE937A9627DB95DCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB504DCF74246407FULL + 0x921A086325163A71ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF295FE186F6D4CD7ULL + 0xCB11EF706CF67D5EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9259446DB6BEA7C9ULL + 0xF72D683BA89482FAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEF6E14573D0A7291ULL + 0xB3D37FB5BAC270ABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC856F437AE26F3FBULL + 0xFEA1B1E097189BCAULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneD, aFireLaneD, aExpandLaneB, aOperationLaneA, aFireLaneB, aExpandLaneC, aOperationLaneC, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneB
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2361U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 7151U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6088U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6785U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5535U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 2440U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 23U)) + 2974056819475622600U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 7345051759236356098U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 53U)) + 12738468816846628882U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 7694520596043297922U) + aNonceWordN;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 5530753590015084774U) + aNonceWordG;
            aOrbiterD = ((((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 3776309161718383105U) + aOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 29U)) + 784780304358106404U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8999942326995036509U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5194986506064092779U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 15070787038006135963U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7920040007459652762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11311997270710107937U;
            aOrbiterI = RotL64((aOrbiterI * 6227571709361790209U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5365231114813547251U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8630110234623825263U;
            aOrbiterJ = RotL64((aOrbiterJ * 2735881715888325759U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2358235238039571072U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18059414891616491807U;
            aOrbiterK = RotL64((aOrbiterK * 17150786106857185467U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 14526050556461782864U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6937282036603272474U;
            aOrbiterD = RotL64((aOrbiterD * 14954512365270028029U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10105832250694931310U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3884223553012098137U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16340956813003906195U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 10385284339549648087U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1257633893341505930U;
            aOrbiterH = RotL64((aOrbiterH * 2669950791270500977U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 26U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 58U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 19U)) + aOrbiterH) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11731U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneC[((aIndex + 14176U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 9615U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12948U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10116U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10243U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 21U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 4259993311776766595U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aIngress, 22U)) + RotL64(aCarry, 53U)) + 2857813330021126753U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 29U)) + 1345396841329442896U) + aNonceWordD;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 320992148982301024U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 57U)) + 5619109532065293074U) + aNonceWordI;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 11U)) + 10380157329426706345U) + aNonceWordC;
            aOrbiterF = ((aWandererA + RotL64(aCross, 37U)) + 12449831150625409695U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7847096607042268396U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11707184096803214678U;
            aOrbiterE = RotL64((aOrbiterE * 1959476948106553973U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 9893643746186827088U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 333687403830908774U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 17911256836121454271U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13837360705077441580U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4367119682175710689U;
            aOrbiterB = RotL64((aOrbiterB * 10295744669174603401U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 1193493435041306784U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 15062951612027370606U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 2509383510565136549U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 16000173839235429105U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15294482444605409961U;
            aOrbiterI = RotL64((aOrbiterI * 1031800997944302665U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5720749055549773527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17248674962996093668U;
            aOrbiterF = RotL64((aOrbiterF * 15730637462755795591U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16956840483882091059U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9637715107943515594U;
            aOrbiterH = RotL64((aOrbiterH * 8878362378343603463U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 37U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 14U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aNonceWordH);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 30U)) + aOrbiterE) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21703U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 21759U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22862U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24572U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19941U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 23338U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 39U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 5U)) + 2101601659597850213U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 12U)) + 2759794072560720121U) + aNonceWordK;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 9443562552411269339U) + aNonceWordJ;
            aOrbiterD = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 10801360546699857975U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 8020716394829332019U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 27U)) + 1021894212367773801U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 57U)) + 13346855534622490176U) + aNonceWordA;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16359309548462953836U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 12642446944680783519U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 12197935153255283321U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8197424982767553380U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14346334610901859094U;
            aOrbiterA = RotL64((aOrbiterA * 16982899923227935679U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14171304260534233539U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 334531601308283605U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5012968232749075075U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10707856298471572695U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18364775750091914766U;
            aOrbiterG = RotL64((aOrbiterG * 15735143943129143265U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 8531394793118363836U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 475199047053777179U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 567682016232278157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2068146551757663119U;
            aOrbiterJ = RotL64((aOrbiterJ * 1557877740957797555U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7776122587613256525U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 4540270493783593257U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 41U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterH, 34U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26915U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 28474U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29841U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32456U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29911U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 32539U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterK = ((((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 35U)) + 7075016829833562104U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 8783765886115517036U) + aNonceWordE;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 57U)) + 2996723892384565829U) + aNonceWordO;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 9494134707342189476U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 35U)) + 5052642981395679904U) + aNonceWordA;
            aOrbiterD = (aWandererB + RotL64(aScatter, 51U)) + 8766787055127962238U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 4467211954388738079U) + aOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8030255604633658608U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16962408063455702251U;
            aOrbiterB = RotL64((aOrbiterB * 11171737929747471631U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3768222186567699076U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14930990410207899871U;
            aOrbiterJ = RotL64((aOrbiterJ * 10930005786146268241U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14179761938395502502U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1879084742719898108U;
            aOrbiterK = RotL64((aOrbiterK * 16783034788172670121U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5535012408925981515U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12792553516710295939U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 8577530993755159329U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8979253163346099252U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5559189896063990740U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8832485423727331621U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13937564337299044079U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2393376759689394948U;
            aOrbiterE = RotL64((aOrbiterE * 2352815657830413941U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12647519563697356479U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 10946871249960389549U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 6272580371881237173U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterD, 3U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF00A4465EC6A8C4DULL + 0xAEBF2A0D15F2E327ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x97BBC743417F30D5ULL + 0xF5A115BBCD6D0C08ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC6810F4F92621529ULL + 0xEB27B82B0C5FB9AEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDD35164AE13200C5ULL + 0xECF3C468D08CC4E2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCE56FF8D0FDFB677ULL + 0x81841EC61DB6CEA3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC6210859C19A2CD9ULL + 0xABA85DA15A953632ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8489F7D64CE020A9ULL + 0xFA00F3808BA79100ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAA6989083C920F67ULL + 0xAFACA3947C66A07AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB9B50F3CD16903F3ULL + 0x940C60A46400D232ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF2477BF3E2F16451ULL + 0x9DC401B1AAD05C7BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCA9789B7598E98E7ULL + 0x9354A0999A7ED8FFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8BFC627E1D95C9DDULL + 0xD5E76CAEB46907FAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA490700B727BED7DULL + 0xAF1C4D93E6DF597DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8FFD37E875983DB7ULL + 0xA3F74805BA4AD300ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC28A4F9B7F123E4DULL + 0xFB47DAE9352A331EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC72F371E8EBDE2D9ULL + 0xA0C7EDF578C75C86ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2604U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1997U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1523U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 772U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 39U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 51U)) + 8988572360732005217U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 60U)) + RotL64(aCarry, 39U)) + 17889613225105985335U) + aNonceWordC;
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 15563478320513948626U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 3441351228410524816U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 41U)) + 4425592689451435346U) + aPhaseEOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 12733160231627305928U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 3574152157304607854U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15167631896729808783U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15822667973915417055U;
            aOrbiterC = RotL64((aOrbiterC * 5155661648455308057U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17181685481076577637U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9979204751408873468U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1334240485667164762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9190066751460137016U;
            aOrbiterF = RotL64((aOrbiterF * 14585141844653660363U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15465215829109246336U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2305208282453624419U;
            aOrbiterB = RotL64((aOrbiterB * 10257861974108363283U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16951510027310993926U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11117938943423526901U;
            aOrbiterK = RotL64((aOrbiterK * 7805486716716924787U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 12461379120662979432U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11719697049048823897U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 14880996802304818757U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 6843357278142933570U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordI) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 54U)) + aOrbiterB) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            aWandererC = aWandererC + ((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4426U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 3311U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4015U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 2995U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 5U)) + 14499676118633326000U) + aNonceWordB;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 58U)) + 17191273593018552288U;
            aOrbiterG = ((((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 4085176294948097737U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 11112671474158908186U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 8745787969012266485U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + 18074049663777707948U) + aNonceWordH;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 2543758649719164688U) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4659584749412700523U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 974639159259871273U;
            aOrbiterG = RotL64((aOrbiterG * 17918719351847605523U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9211220687971081987U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 8567024626862182714U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 7755874089832496393U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5803002132294840900U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 11968489432878148467U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9470807228394903442U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1692347973120388469U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17433393164156231575U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16510815732690193145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 755159406833096510U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14091736464659561165U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1518824876475937620U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 701225390867330446U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 12264618860580199927U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8425976693733003889U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7182176375442410367U;
            aOrbiterC = RotL64((aOrbiterC * 8860605703761731859U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 27U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterK, 13U)) + aNonceWordK);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 60U)) + aOrbiterB) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5478U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadB[((aIndex + 6227U)) & W_KEY1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5741U)) & W_KEY1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7136U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7009U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 40U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + 701291026547470433U) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + 17283292650462111643U) + aNonceWordB;
            aOrbiterE = (aWandererC + RotL64(aIngress, 13U)) + 9969124091931303406U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + 889176772718046988U) + aNonceWordE;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 6054541844643748084U) + aPhaseEOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 14703226235143028132U) + aNonceWordK;
            aOrbiterB = (((aWandererE + RotL64(aCross, 56U)) + RotL64(aCarry, 29U)) + 7977975878522921062U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16894322614172266274U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12160451749345900570U;
            aOrbiterE = RotL64((aOrbiterE * 18055355572903901749U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10870847008043897470U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8159920947172520247U;
            aOrbiterF = RotL64((aOrbiterF * 4833194641611011805U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2440099120969517932U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2428396147731468007U;
            aOrbiterB = RotL64((aOrbiterB * 9363073341539598441U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2213226274394673479U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7079731443427765333U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 16918930776877030559U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 958896789550478970U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10788682955708075458U;
            aOrbiterI = RotL64((aOrbiterI * 913321215613559729U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2003386579317564870U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8419686358774204999U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6547052526438697621U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 6989167615157578904U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17636634003643824148U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 11038576417283732937U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aNonceWordF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterB) + aNonceWordA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8993U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 9082U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(mSource[((aIndex + 10894U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8846U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10670U)) & W_KEY1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9593U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 35U)) + 17074147006464019918U) + aPhaseFOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 50U)) + RotL64(aCarry, 19U)) + 10559516626129419928U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + 13280363679503946221U) + aNonceWordD;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + 17657115422132457413U) + aNonceWordC;
            aOrbiterC = ((aWandererC + RotL64(aCross, 27U)) + 13325837013304973008U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 3059707750486106037U) + aNonceWordM;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 4529045702503050852U) + aNonceWordA;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10726578475550904292U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14832537837996659885U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 808060368961520519U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 220094417441809246U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15343130035105342194U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7984652435043810845U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16592263353426409884U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15649290906447931918U;
            aOrbiterC = RotL64((aOrbiterC * 8405875177836650731U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11437410545843708269U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5859769136073011444U;
            aOrbiterJ = RotL64((aOrbiterJ * 1065016088086441107U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15188064100307340341U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4367466521843260049U;
            aOrbiterG = RotL64((aOrbiterG * 15916715854192820923U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8482617283860566845U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 2585745804937342972U;
            aOrbiterB = RotL64((aOrbiterB * 8267269625632139809U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1687641344403425541U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 13667916445979421400U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 8191322670355590027U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 51U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 20U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 3U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12857U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadA[((aIndex + 12594U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13308U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 12502U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12769U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12056U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 12194U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 43U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 13481227414590594621U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 51U)) + 17425964381118918026U) + aNonceWordN;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 5U)) + 4792004356135956581U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + 11926849936000639098U) + aNonceWordC;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 990697329347742142U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 9307721505373076588U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 22U)) + 17605732738841908719U) + aPhaseFOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 13110764518634187439U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17970109897810645911U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10395095143998920213U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10273133817644703654U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11239046688920468137U;
            aOrbiterG = RotL64((aOrbiterG * 5197802934333553327U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8355821483275763145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15522151127786049345U;
            aOrbiterA = RotL64((aOrbiterA * 4844278537850520413U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5381663179722418112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9551368011768104906U;
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16264476585232221270U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7721417776432288282U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10267770327791051869U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 339418090653475277U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 3390560045236418590U) + aNonceWordK;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 3894024951542543635U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 10599637790900418767U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 18U);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordF) + aPhaseFWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterC, 29U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 28U) + aOrbiterA) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterE, 44U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13871U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14717U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15141U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14713U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15036U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15331U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13763U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 19U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 11U)) + 10812151398716051703U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 21U)) + 18202551453336003710U) + aNonceWordG;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 9434410809101973752U) + aPhaseFOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 12955829998028534045U) + aNonceWordA;
            aOrbiterG = ((((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 12271740641929640181U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aWandererA + RotL64(aIngress, 48U)) + 14009351527014534752U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 29U)) + 4316296955679133450U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16473324966997442872U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15735123324965019802U;
            aOrbiterI = RotL64((aOrbiterI * 5624078184997601019U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 17656375090484080236U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16066325053456055298U;
            aOrbiterC = RotL64((aOrbiterC * 17912970706985130327U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12908968778503516903U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12761433987676836197U;
            aOrbiterA = RotL64((aOrbiterA * 1023329467480907925U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12737513138040664509U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14535795767570998392U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 15560519667062222269U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14370908061811284364U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7001358781208669795U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 11641248025734015835U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7298578161120090849U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10498302152357484629U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 13144110412179037175U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11447343228638006767U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 18284143620422655675U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 56U)) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17767U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 17494U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(mSource[((aIndex + 17697U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16934U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17660U)) & W_KEY1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17476U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16664U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 19U)) + 12046647397183218524U) + aNonceWordC;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 2760779375026461991U) + aNonceWordI;
            aOrbiterK = ((aWandererB + RotL64(aCross, 53U)) + 13735454443176855650U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 4370377000586647724U) + aNonceWordL;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 37U)) + 14566322384189969094U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 12U)) + 5056565959818422786U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 8795403810686579209U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9625947666256011567U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1703669290934254701U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5763881345676123583U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6664070663184147951U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2104148316797553431U;
            aOrbiterC = RotL64((aOrbiterC * 12887842067180975983U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1197910004222596145U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9922977170060903197U;
            aOrbiterH = RotL64((aOrbiterH * 13047828062605568603U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2048376210852567829U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12568990647075931409U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9860242601194210927U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15026894775772902751U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3439447160137900629U;
            aOrbiterD = RotL64((aOrbiterD * 1813754963043785165U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6532671388552829796U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17261098369835997661U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 568292591215203521U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3171300991007459947U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5935563269327662024U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11271790283157765003U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aPhaseGWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 4U) + aOrbiterH) + RotL64(aOrbiterD, 46U)) + aPhaseGWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19892U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 19148U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20658U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21483U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19388U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20468U)) & W_KEY1], 11U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19892U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20295U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 15920462086654025436U;
            aOrbiterD = ((((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 487844076858004017U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 13U)) + 14502883786442630566U;
            aOrbiterC = (((aWandererA + RotL64(aCross, 43U)) + 3787107318658233674U) + aPhaseGOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 12548777544693755491U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 6U)) + 4907309444075181683U) + aNonceWordD;
            aOrbiterA = (aWandererJ + RotL64(aCross, 37U)) + 18342396700266492072U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13503051997624242670U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17845742460521374571U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1366356786138085155U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8640887211877858169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5273913123709097537U;
            aOrbiterE = RotL64((aOrbiterE * 1661149444148461791U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 17756844173695563883U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6713055830729302951U;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 5106468334224035972U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10228769728713526172U;
            aOrbiterA = RotL64((aOrbiterA * 9760310686414358435U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7687649520668883142U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7757480627354711605U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7222553727737349209U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10876291698508634557U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8149278085586014186U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 8577133863470695381U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15592893988925610485U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8639028256640537165U;
            aOrbiterF = RotL64((aOrbiterF * 1880655276432963955U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 37U)) + aOrbiterD) + aNonceWordH) + aPhaseGWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 57U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 46U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aPhaseGWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterC, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 21941U)) & S_BLOCK1], 20U) ^ RotL64(aKeyRowReadA[((aIndex + 23136U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23795U)) & W_KEY1], 3U) ^ RotL64(aFireLaneC[((aIndex + 24357U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23405U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23993U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22074U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23677U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 47U)) + 15652862298542575895U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 41U)) + 16925323928418184554U) + aNonceWordN;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 4413861484961668394U;
            aOrbiterF = ((((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 2215946422098155969U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 14975185533513111110U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 3U)) + 9711613814905834552U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 54U)) + 13154957291850149471U) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5058313016418534840U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15011423472941211620U;
            aOrbiterJ = RotL64((aOrbiterJ * 6125316151731105673U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2030053257469580168U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 150530795186791193U;
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 10878237472104183427U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11724672539469573109U;
            aOrbiterH = RotL64((aOrbiterH * 16158741837357985395U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9589700906445846956U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1367381624958248949U;
            aOrbiterC = RotL64((aOrbiterC * 8459515089081211977U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12003215666757518106U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11232479330848006729U;
            aOrbiterE = RotL64((aOrbiterE * 10993290955464593033U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13013910456628561621U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6092509838924105265U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 805601154718006061U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11999225836250312801U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 14421271973875748413U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 9529010940887430157U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 42U)) + aOrbiterD) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ) + aNonceWordO) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25404U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 25162U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25497U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26267U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27089U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26132U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25156U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27270U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 13U)) + 6163290588946759209U) + aPhaseHOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererG + RotL64(aIngress, 19U)) + 7342672468560105447U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 41U)) + 11574563167017282321U) + aPhaseHOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 2254820206194758964U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 5U)) + 1469783447473099498U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 47U)) + 14174828900676165088U) + aNonceWordB;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 16277954291890598132U) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14845750668693136766U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 150099699692047766U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7644895634421086357U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1200784917165131703U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9469982764806754302U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17851969334511301943U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10956702761701710182U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7915506894975487807U;
            aOrbiterG = RotL64((aOrbiterG * 8874108311712727983U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 17335794183733623213U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 557028996286989506U;
            aOrbiterB = RotL64((aOrbiterB * 3993359298602424281U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1597385667771002414U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterA = RotL64((aOrbiterA * 4626236858205178149U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 549770198518993876U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 756554555648070919U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 16272320259614325355U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7298557532533152193U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3336802611342112013U;
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 4U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterA, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterA);
            aWandererH = aWandererH + (((((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 43U)) + aNonceWordG) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29482U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 28281U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27436U)) & W_KEY1], 52U) ^ RotL64(aFireLaneC[((aIndex + 29714U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29349U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29840U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29162U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 29388U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 13U)) + (RotL64(aPrevious, 41U) + RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 5U)) + 7948891781097675369U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 13928362874228230226U) + aNonceWordN;
            aOrbiterK = ((((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 10776180542602258926U) + aPhaseHOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 5735115172149470447U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 13U)) + 5353591822981766987U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 29U)) + 562301708107268570U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 20U)) + 10467810247578364868U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14541630141152308564U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2350076897065139429U;
            aOrbiterK = RotL64((aOrbiterK * 12222554362482034393U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17519109078651162228U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15654836633731000065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13723521735153718904U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2849680038315532197U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterJ = RotL64((aOrbiterJ * 10984689101753586739U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 7671010488872356142U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11485114338165600777U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4162584865462407791U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8759060657343458985U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11009137869375286581U;
            aOrbiterE = RotL64((aOrbiterE * 8741417343929809115U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15792999392743144135U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6180808423175992479U;
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 4U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 41U)) + aNonceWordA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 52U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterK, 29U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31548U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[((aIndex + 30601U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32313U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31639U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31405U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31896U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 39U)) + 3236820517816085022U) + aNonceWordJ;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 741288875914097926U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 28U)) + RotL64(aCarry, 39U)) + 8417246926007729580U) + aNonceWordK;
            aOrbiterG = (aWandererI + RotL64(aCross, 57U)) + 9715717805774537170U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 14360243844821619482U;
            aOrbiterK = (aWandererD + RotL64(aCross, 11U)) + 10760908100206775334U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 19U)) + 3434641779946167811U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 7885568822756234567U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3041563437672051294U;
            aOrbiterD = RotL64((aOrbiterD * 11440300917533482297U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15761355327564963516U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1158633562785937421U;
            aOrbiterA = RotL64((aOrbiterA * 15511324886867188235U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9338581575871970653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9172038894262857354U;
            aOrbiterJ = RotL64((aOrbiterJ * 3110871165285625807U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14653924713599790081U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3854497592598563309U;
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16286980180327600557U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 5092583772591249756U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13955105624639442903U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4288397994175567333U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15584236478994873104U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5557463939827483792U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2659814275753280856U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17702430405693184643U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aNonceWordL);
            aWandererD = aWandererD + ((((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 34U)) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterA, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD686CDFDC62CAEF9ULL + 0xAA7313BDFE4EAA62ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCE2EEE63337E3DEBULL + 0xFBA7CAAB4C3E0E4EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDF0B6D3B79D15C2DULL + 0xB9EDC6BE2641085DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB0FAAE9C2EF51D37ULL + 0xAD74C7B458147D54ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDA4CD832A53FBB83ULL + 0x9392741A56626927ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE5028BDBA5BCA25DULL + 0xF73419B9C3281760ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9D88620E54D80023ULL + 0xB69C18BC7CE165DAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFF3F6775E5A078BDULL + 0xB22861D46CD88899ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xECA9FCC7E2F73811ULL + 0xC883DF81D85AD021ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAECC0BB1B2AD78C9ULL + 0xE1B71EECFBBC3AA1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8E46AB356BB0E84DULL + 0xED5EE9FC67EA42D2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8214219246872F77ULL + 0xB4CB326428991319ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9BF40B5FA2935D13ULL + 0xDB879458C073D04CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8666390895A7E133ULL + 0x98065B9EAC4BD3D8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9970192C9CB68A7BULL + 0xA29AAB3B1AF6989AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB4260CF138FB0BD1ULL + 0xC85211278CE3EB16ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneA, aInvestLaneB, aFireLaneB, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3304U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((aIndex + 148U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 759U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2933U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 4233U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 479672811032092393U) + aNonceWordH;
            aOrbiterB = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 18061121631394564425U) + aNonceWordB;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 58U)) + 14237400452740566065U) + aPhaseAOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 6723123812257706134U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 43U)) + 4247997188026499248U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1939107415066134869U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3912640123546395979U;
            aOrbiterG = RotL64((aOrbiterG * 9779626695085572877U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8295478436553964298U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 3218960600711526885U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15443507655470278069U), 23U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 5874096203353388890U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10294536533673023358U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15561710414949058923U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11268561953904130747U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16693201256788898423U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 16291987237693567209U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7550969634681894654U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9501647424602245869U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11265865222096866605U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 34U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 50U) + aOrbiterB) + RotL64(aOrbiterC, 27U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterG, 13U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 52U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7993U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 6910U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6063U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9975U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 10380U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 36U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererD + RotL64(aScatter, 53U)) + 11698283336767769359U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 42U)) + RotL64(aCarry, 23U)) + 13297826354831483872U) + aNonceWordG;
            aOrbiterD = ((aWandererH + RotL64(aCross, 3U)) + 15254999058287530795U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 17474166585085346567U) + aNonceWordI;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 15684783498452840289U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5061229733465216486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15370981279168377944U;
            aOrbiterD = RotL64((aOrbiterD * 15893028157665379361U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17966672773619554092U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14685092893994491068U;
            aOrbiterI = RotL64((aOrbiterI * 1627758964162892429U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12798804186209406389U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2848444181474221574U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13730480364920876877U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8551142075919636146U) + aNonceWordD;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 8833198159158950723U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 7650289040764974737U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7351473160893666232U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14204899612487622222U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6317485031956448029U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterA, 21U)) + aNonceWordC) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 6U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14599U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 13685U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11317U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15928U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14528U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16167U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 15188686795415908074U) + aNonceWordN;
            aOrbiterB = (((aWandererD + RotL64(aCross, 48U)) + RotL64(aCarry, 37U)) + 17310049041983079779U) + aNonceWordE;
            aOrbiterF = (aWandererE + RotL64(aIngress, 29U)) + 8246925977992441471U;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 8644260919918112781U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 3U)) + 13401663736874819483U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7940358935238314973U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13278990328548007839U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 285726811877787411U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterD) + 11346868298353840706U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2374077904806833579U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 1765686942154321425U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 6978903378645019166U) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11951633297870965212U;
            aOrbiterJ = RotL64((aOrbiterJ * 12778236598654492185U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17398460995357409673U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1215437945597836770U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9322970054123481621U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1878751468043972239U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5343002808239712390U;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 46U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + aNonceWordJ) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20147U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneA[((aIndex + 17918U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20653U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17605U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18749U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17110U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererA + RotL64(aScatter, 29U)) + 5480870806135400132U) + aPhaseAOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 46U)) + 8034874599430768743U) + aNonceWordJ;
            aOrbiterC = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 4006919843736863767U) + aNonceWordG;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 2988069748674633718U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 12347295651973135786U) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14152683894431568192U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15765143815254196598U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8948877544291035189U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10473067082331244233U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1089466925383677249U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 17334888609179149753U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13215039929873682230U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3957997712247961479U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7631186240013784703U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10023907397941685546U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 14593012591254614353U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13353797968154036726U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 9259966668512102858U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 8326732574268308221U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 48U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterC, 18U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + aNonceWordD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 53U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21928U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 22140U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 23195U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25468U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26642U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22155U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 6069475454765660321U) + aNonceWordA;
            aOrbiterE = ((((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 11483704742497268068U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + 11055697447388986418U) + aNonceWordO;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 10897095046039997004U) + aNonceWordG;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 6U)) + 4731637118230457840U) + aPhaseAOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 13855839187084986751U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5328208115460188239U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 3800417611141123383U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12479538544291412985U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10740165998792608231U;
            aOrbiterJ = RotL64((aOrbiterJ * 14046827922294477379U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6492798157284955373U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13056825957483891921U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14882112110627751751U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2068184064919194657U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5656302738780746294U;
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 5U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 11193756120230763294U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17306750816837208999U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterE, 43U)) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 52U)) + aOrbiterC) + aNonceWordH) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30787U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 28926U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29184U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29470U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28984U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 32612U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 16189787374324972735U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aCross, 35U)) + 17563763730956242224U) + aNonceWordD;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 10572803498593789385U) + aPhaseAOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 27U)) + 7713105232072974166U;
            aOrbiterD = ((((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 39U)) + 10760839534772718139U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13397069448391230253U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4569255679998375682U;
            aOrbiterE = RotL64((aOrbiterE * 15163488708398248639U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9888769350817876949U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11351796060878856300U;
            aOrbiterD = RotL64((aOrbiterD * 13356749147334008399U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18153775071965707204U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1282846411145853435U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 37U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 16457743979262460660U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3927345926316409630U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5158769729850853623U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 2446452358663812945U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 40U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + aNonceWordM) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 46U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE5D486D8DEDB70E9ULL + 0xB71CDC111FDB7F38ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAA945E73E1040107ULL + 0xAD13F7EC15A776FCULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBA697995CADF6FA7ULL + 0xC62DD5F081A38213ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB29EEDC089F24E97ULL + 0xD89E7D08A192A34FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8C6AC7FA229789FBULL + 0xF2B1B80EDCA7E58BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFF92696C4BD66593ULL + 0xC1790BF906EF1A9DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD5878B7EBBEB05B1ULL + 0x91CADC12AAAE6A9FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC3C7F6A8C97C6D5BULL + 0xF8F97EAFF9CB6895ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD5A1802EC53BCEB5ULL + 0x83639F91B31FE0AFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x981692D977701DBBULL + 0x919A2286CC0F4B93ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x87861864BC3E2EADULL + 0xF156284551E060B8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE5B5F91AB7305EBDULL + 0xEE60F1701640E6EDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB3063A959160EBD5ULL + 0xDC746794801FE25CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCCE8DC9DBECE380DULL + 0xFC31AA5F8F55517AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAC9C043621999BA5ULL + 0xE1CDFC754AAC899EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDCFE526F45215943ULL + 0xF095C028FD5DED2EULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aExpandLaneA, aInvestLaneC, aFireLaneD, aFireLaneC, aInvestLaneD, aFireLaneA, aWorkLaneA, aExpandLaneB, aWorkLaneB, aFireLaneB, aWorkLaneC, aExpandLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 833U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 5306U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 1611U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4318U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1648U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2936U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 43U)) + 5480870806135400132U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 57U)) + 8034874599430768743U;
            aOrbiterA = ((((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 4006919843736863767U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + 2988069748674633718U) + aNonceWordD;
            aOrbiterK = (aWandererA + RotL64(aCross, 10U)) + 12347295651973135786U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 14152683894431568192U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 15765143815254196598U) + aPhaseBOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 53U)) + 10473067082331244233U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 34U)) + 1089466925383677249U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13215039929873682230U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3957997712247961479U;
            aOrbiterA = RotL64((aOrbiterA * 7631186240013784703U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10023907397941685546U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14593012591254614353U;
            aOrbiterK = RotL64((aOrbiterK * 17111300092082154687U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13353797968154036726U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9259966668512102858U;
            aOrbiterE = RotL64((aOrbiterE * 8326732574268308221U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 10757861831070349321U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10530223113483866178U;
            aOrbiterB = RotL64((aOrbiterB * 11269177745265396583U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7554320926405521865U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 6978052067277966996U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 18020134738536217801U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 1053695861967171420U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15980734683539854451U;
            aOrbiterI = RotL64((aOrbiterI * 3208466640010555357U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17041258393808061556U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12846551858751995530U;
            aOrbiterH = RotL64((aOrbiterH * 9303891433380993639U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14617434286683320666U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3999309956180741302U;
            aOrbiterD = RotL64((aOrbiterD * 15037707937050015205U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13452627760403094126U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2633241575260427158U;
            aOrbiterC = RotL64((aOrbiterC * 2638570213290747581U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 22U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 60U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 18U));
            aWandererH = aWandererH + (((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 13U)) + aNonceWordL) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + aOrbiterD) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneD
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8647U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 8484U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9159U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 6172U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6889U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10696U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 8762U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 38U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 47U)) + 8375305456876489425U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 16193562952772453047U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 51U)) + 18088652458594816223U) + aPhaseBOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 11U)) + 767344788620249944U) + aNonceWordC;
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 7705194930396368752U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 39U)) + 3829736891311272834U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 23U)) + 9881681671347640061U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 10U)) + 1721196560190164264U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 3002652618388454213U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9811621464004005202U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5652598941069986530U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4797973356708091621U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6250499348327316328U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16025054277615264530U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16446892258704281903U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13800298546867243172U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12256104592865905782U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 16983140179497142713U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17817225416918329229U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 17738671327352776217U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6816031224188400541U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16989563985059237014U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 8677884225771717797U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16891524847268207549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1833508573940405571U;
            aOrbiterE = RotL64((aOrbiterE * 9709196587703979539U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12729999421507068973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6839758643521968957U;
            aOrbiterD = RotL64((aOrbiterD * 16350557395881283975U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8524167125469267428U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14741523560290472617U;
            aOrbiterI = RotL64((aOrbiterI * 4367850822282205897U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10983798459868424892U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 5649250846622078964U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7149612714806023987U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 60U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 56U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterD) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + aNonceWordL);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 18U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13697U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 16350U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 12676U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 14245U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13744U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 6069475454765660321U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 11483704742497268068U) + aNonceWordJ;
            aOrbiterD = (((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 57U)) + 11055697447388986418U) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 51U)) + 10897095046039997004U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 3U)) + 4731637118230457840U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + 13855839187084986751U) + aNonceWordH;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 60U)) + 5328208115460188239U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 23U)) + 12479538544291412985U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 13U)) + 10740165998792608231U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6492798157284955373U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13056825957483891921U;
            aOrbiterD = RotL64((aOrbiterD * 14882112110627751751U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2068184064919194657U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5656302738780746294U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 16493021179127646345U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11193756120230763294U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17306750816837208999U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 7949360041241439741U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12952818800389361804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15380412293642628312U;
            aOrbiterF = RotL64((aOrbiterF * 2914662289178925547U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7706090204767242996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14598802276412649570U;
            aOrbiterA = RotL64((aOrbiterA * 4821408736292041399U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17819762117328075515U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6481384240915075101U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 4836701121865783029U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 754936290510338717U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15510875946573720154U;
            aOrbiterB = RotL64((aOrbiterB * 2994718968852184303U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9245381722813944586U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2629847912019726214U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6718795794951106961U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3909987749797113773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9277056074757335265U;
            aOrbiterJ = RotL64((aOrbiterJ * 11580847505996697115U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterE, 42U)) + aNonceWordC);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 19U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16467U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 17022U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 16601U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16763U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 19660U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 24U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 13U)) + 3255291173184001106U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 53U)) + 15308468160116255528U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 18186972408589866656U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aCross, 19U)) + 4439324265978331914U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 43U)) + 13099263173016322486U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 7041561081767500660U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 27U)) + 6196422612687812971U) + aNonceWordJ;
            aOrbiterF = (aWandererE + RotL64(aScatter, 39U)) + 7664260932541281413U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 47U)) + 17802347823020441056U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4253107484061190446U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13799496534030645312U;
            aOrbiterG = RotL64((aOrbiterG * 9167675060053848207U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14252892847595951926U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5663527578664291422U;
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11148755959699137661U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17036900929333594592U;
            aOrbiterA = RotL64((aOrbiterA * 16041243617369003291U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2403828181385259549U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17813580350434928194U;
            aOrbiterF = RotL64((aOrbiterF * 13666780980793857831U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5623611126885414523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 10602620906929686163U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18015916257203385982U;
            aOrbiterC = RotL64((aOrbiterC * 10684090189688871993U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13592915735376305773U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13995866908043417505U;
            aOrbiterK = RotL64((aOrbiterK * 3802175869395887331U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8200465989447697618U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9866671660800629464U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2138851839905326265U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11557528777230608777U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 131060617338185060U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 11068705423012265209U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterH, 56U));
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 35U)) + aOrbiterD) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterG, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22634U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneD[((aIndex + 22851U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22948U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22407U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 24677U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 19U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 8988572360732005217U) + aNonceWordD;
            aOrbiterB = ((aWandererH + RotL64(aCross, 39U)) + 17889613225105985335U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 15563478320513948626U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 18U)) + 3441351228410524816U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + 4425592689451435346U) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 57U)) + 12733160231627305928U) + aNonceWordM;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 3574152157304607854U) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 15167631896729808783U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 15822667973915417055U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17181685481076577637U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9979204751408873468U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8244434774754786565U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1334240485667164762U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 9190066751460137016U;
            aOrbiterI = RotL64((aOrbiterI * 14585141844653660363U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15465215829109246336U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2305208282453624419U;
            aOrbiterG = RotL64((aOrbiterG * 10257861974108363283U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 16951510027310993926U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11117938943423526901U;
            aOrbiterB = RotL64((aOrbiterB * 7805486716716924787U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12461379120662979432U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11719697049048823897U;
            aOrbiterA = RotL64((aOrbiterA * 14880996802304818757U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6843357278142933570U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12727898578324702374U;
            aOrbiterF = RotL64((aOrbiterF * 9786435451654365097U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18127999660067652233U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11754709060558683082U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12798744012150745847U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16940151146420516184U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12924950783056761895U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8898170377271926745U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14829713915929878471U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 840466047621042565U;
            aOrbiterD = RotL64((aOrbiterD * 10748511630509529489U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 30U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aNonceWordA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterG, 14U));
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterB, 46U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 3U)) + aOrbiterD) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aPhaseBWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29833U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 27961U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 31966U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32311U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27356U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 26U)) + RotL64(aCarry, 13U)) + 1866656689936219099U) + aNonceWordO;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 5U)) + 2312314528139448289U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + 3554037526469185237U) + aNonceWordF;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 57U)) + 405707755060974111U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 47U)) + 1862976326004007697U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 11U)) + 12992483065443288263U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 20U)) + RotL64(aCarry, 27U)) + 3793854946371595197U) + aNonceWordJ;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 4244007978867369382U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 43U)) + 10280867500312580308U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 472563452959164242U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12041770406895816553U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 17811798500132002631U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6118634015704900486U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13637107920449233307U;
            aOrbiterB = RotL64((aOrbiterB * 17712028184714868053U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16673735670669318830U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 8602681273646630496U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7683264695930369476U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9146674871199188218U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 7403427067419261981U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3012935612827493084U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1259789268731661945U;
            aOrbiterA = RotL64((aOrbiterA * 2372843620327050137U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5623690455471160780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 18355567776031865462U;
            aOrbiterJ = RotL64((aOrbiterJ * 9553862670107886679U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7705134893833304792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4435192506444773834U;
            aOrbiterK = RotL64((aOrbiterK * 5249651218395299501U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6204683785806409075U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 17886971535016484255U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 6047216474762933535U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 4430578901091376829U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 607557685798141547U;
            aOrbiterC = RotL64((aOrbiterC * 12342665567201483107U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterC, 34U)) + aOrbiterI) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterA, 56U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x900A1E830F43D737ULL + 0xFA1539B440B99882ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB514A73734872657ULL + 0xEAFDE3031538CAB9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE946A38BE3981755ULL + 0xF701E4E2AA68A8A6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xED228C554B51CF15ULL + 0xCF7CE7EC89B959DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA535E004A4AA5513ULL + 0xD96332569AE3C129ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC553FBFBB3BB9FA9ULL + 0xA8B231C9899192EFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF07BC189AADE889BULL + 0xFBE16C4D15D4F264ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA974955EAFB1998FULL + 0xBF4D4B34B007CFB5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBABB2B714C81505FULL + 0x839AC4233EB321E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC4DCF7B6BAD21ACFULL + 0xF0A839B1914CED58ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD6547611FFB040CDULL + 0xEBE0824C99AA9C6BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD59C427AF431D175ULL + 0xD26D112B78E417E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA09745158548A9E3ULL + 0xCD9B55673C52E0FCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8B9C5FB9BD2BE78FULL + 0x950B3CEBA061DFD1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC9CE611318933A0DULL + 0xB9BBCEF3EB13FD81ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF21B7AD8E9F94165ULL + 0x876EBD3990A61D69ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3483U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 1775U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2793U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4150U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1153U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 333U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 53U)) + 16802219662864902427U) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 60U)) + 14332033461409490629U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 35U)) + 8781794298640286845U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 8459933908074937264U) + aNonceWordF;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 1883580287986004426U) + aPhaseDOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 17500258188004626118U) + aNonceWordO;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + 7934811305150872870U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6380363892361098905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 12623079132626676910U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 12406671746344127399U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10455208121949202703U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8805532707916767629U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 666082374369701881U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9161544391400377699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3501434325829663268U;
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 651783304096081996U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 441505031509930622U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 8045355432310956143U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1771159983581326424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15227946417377695989U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1563141188972797601U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4153717524193279095U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4404521756523902829U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1410342912973206203U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6231945075461813285U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3864780227164426690U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 18031353247480673617U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aNonceWordK) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 26U)) + aOrbiterB) + aNonceWordI) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6891U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 6283U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10240U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9197U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10550U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10191U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8738U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererD + RotL64(aIngress, 54U)) + RotL64(aCarry, 13U)) + 5041131702736607991U) + aPhaseDOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aScatter, 29U)) + 9295010428212681446U) + aPhaseDOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 6235875895358766017U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 2622227802531866918U) + aNonceWordH;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 3888894734834524972U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 11U)) + 241682012014701753U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 23U)) + 15758000422451568079U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2061944548396976912U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8177144990755754531U;
            aOrbiterG = RotL64((aOrbiterG * 12702392689484397947U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 554978075608818497U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 250408260560714933U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1295379390497107727U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 8700027645880997552U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10026130047465480902U;
            aOrbiterJ = RotL64((aOrbiterJ * 12417270861933696623U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9785843014096326696U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9998582683258411251U;
            aOrbiterE = RotL64((aOrbiterE * 7197956237569462269U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13817734599383455151U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6647207154174092691U;
            aOrbiterH = RotL64((aOrbiterH * 1578528131687283531U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4957715980509035719U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4994885315786213197U;
            aOrbiterD = RotL64((aOrbiterD * 5676683798126497011U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5072908311783966503U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5535039946192891515U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2989412783482309753U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordI);
            aWandererH = aWandererH ^ (((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aNonceWordN);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 46U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordC) + aPhaseDWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aNonceWordK);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 16278U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 13875U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13071U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12457U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15354U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 18U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 35U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 11808423452327465441U) + aNonceWordM;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 57U)) + 8670503858631730886U;
            aOrbiterA = (aWandererG + RotL64(aCross, 41U)) + 2400061067991988544U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 27U)) + 16163118178366229686U) + aNonceWordP;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 3280178595904941068U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 3U)) + 3298683600817047727U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16321624053445183574U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6730229877611375225U;
            aOrbiterB = RotL64((aOrbiterB * 2022290495153519279U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 10162830636713641322U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15646771327759599256U;
            aOrbiterE = RotL64((aOrbiterE * 15333053762177144775U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14841751262270544102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9545541117228834895U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 14676615635857599982U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 1231768638470558855U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1945905595345404833U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1406171421638586846U;
            aOrbiterC = RotL64((aOrbiterC * 4577864352425476233U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1970292335806697198U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12309719390375013297U;
            aOrbiterG = RotL64((aOrbiterG * 16540660957923687327U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5352135521358954576U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterD = RotL64((aOrbiterD * 16385761112921041387U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterH, 23U)) + aPhaseDWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 5U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aNonceWordE) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 14U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18480U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((aIndex + 19130U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18977U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18859U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 18208U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererI + RotL64(aPrevious, 3U)) + 1557680213571812384U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 29U)) + 7387349725778021121U) + aNonceWordO;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 43U)) + 15379264067601586976U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 19U)) + 3730195724576043708U) + aNonceWordH;
            aOrbiterB = (((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 9637070085323827066U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 53U)) + 1170865717363676184U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 2750833653175252030U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15118992811225568305U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4974092922102988451U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 10575977398702460975U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10625719096296719514U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 855167122475471865U;
            aOrbiterF = RotL64((aOrbiterF * 7441090331293158773U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11322911068958340262U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4334591909425429835U;
            aOrbiterC = RotL64((aOrbiterC * 10059025861172038183U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 14263701737208936392U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 678723206735649084U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10823239851733632227U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15652053114252065230U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1705225940224061401U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 3626023093533713579U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 6826394665732900206U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11902946775066981141U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18300629262162694137U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9802212958998591310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14001358545610206524U;
            aOrbiterE = RotL64((aOrbiterE * 13172645840788327099U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aNonceWordC) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25655U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneB[((aIndex + 22191U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24463U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26894U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 22432U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 6381335981879993247U) + aNonceWordB;
            aOrbiterC = ((aWandererG + RotL64(aCross, 47U)) + 15595429101600023172U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 5U)) + 5449234297249826461U) + aPhaseDOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 19U)) + 11213734849329731168U) + aNonceWordD;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 35U)) + 16438473952464514248U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 23U)) + 7357872882115186976U) + aNonceWordH;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 394402075160738643U) + aNonceWordL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11112941985410283532U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14955125011182736212U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10711684773326395603U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14770727009821304070U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11286366598129204910U;
            aOrbiterI = RotL64((aOrbiterI * 15884310771003021989U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7358400908565425780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15635109923749114761U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12415152149408700329U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13826842523738623579U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1072811298828325231U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9662800288646215083U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4017334196009350776U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8812213572751410831U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 12744171921566782795U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6723457786170634403U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9785583533999417673U;
            aOrbiterH = RotL64((aOrbiterH * 7776915427605471097U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10265132640322153964U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8435670887514808087U;
            aOrbiterF = RotL64((aOrbiterF * 2706263045620662131U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 20U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterF, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28294U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 31369U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32656U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 32211U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 30473U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 26U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 11U)) + 13350544654542863236U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 12364346790125404372U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 9738750172849512764U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 3781373837635491421U) + aNonceWordP;
            aOrbiterC = (aWandererI + RotL64(aScatter, 37U)) + 16635020317512702337U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 48U)) + RotL64(aCarry, 53U)) + 5383653921676231276U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 21U)) + 10181959815492056493U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10005510924273927017U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9524687662265740565U;
            aOrbiterF = RotL64((aOrbiterF * 13687380438646756931U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4259138552009771014U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8973051213213726023U;
            aOrbiterB = RotL64((aOrbiterB * 12625091476068190979U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17602611840127337490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18102186122213487888U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2629927500298092976U;
            aOrbiterD = RotL64((aOrbiterD * 6983280164448292723U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2491581597835795234U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9506602492971620955U;
            aOrbiterK = RotL64((aOrbiterK * 9559829640915637163U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13422942713680612924U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15037354693234876601U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12896066842192894694U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2202952306291905855U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6779368532763429997U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 44U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 30U)) + aOrbiterK) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH + ((((RotL64(aCross, 22U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aNonceWordO);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 47U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB1BAB0CB9FF7E8D5ULL + 0xBB7AFA8BB8918998ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC7585AF5F7B3C77ULL + 0x8946F9F1B3E4357EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8AB5D35BBFA4D7FDULL + 0xBDA368A3B2AD40EBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD94A2BC451A5FDC9ULL + 0x9BEE90EE8FB74CDCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC0A82C25C6A4AA89ULL + 0xBFC14F63DBA6C71DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCE686286E6E61DA3ULL + 0xE7F42A835F980208ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9DFEB7CC0E6B5243ULL + 0xB84C7427C5041720ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBE108719ECCD606DULL + 0xE86B98493FAF79FDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x98FBDAC8872AA915ULL + 0xC4EFCCEE91AE3FA0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCE917513BEFD1497ULL + 0x917FC108B807624AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x808B3DC4EE8DB067ULL + 0xE1F6A43123B5D647ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE0EF269F5EDE089BULL + 0xE4D8E537F5BB9F71ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFB947F1528DA26A5ULL + 0xA386019926C2F160ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEE0A3960EE5AA6ADULL + 0xE99A4F90F57049BCULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x895FE91F18CCB985ULL + 0xB17524E44281FF2FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE20D72AF41FF139BULL + 0xD02750410CCC366FULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4764U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 3970U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3456U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 101U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4867U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5165U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 16124889768301047791U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 30U)) + 11912338587186717280U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 8594012868813114354U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 23U)) + 18281043566156682815U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 13U)) + 16853106130200942302U) + aNonceWordJ;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 2611212958619673086U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 27U)) + 18039472325066855180U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 57U)) + 14495785571345122046U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 43U)) + 4556063793412832418U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 40U)) + 14896419970271244358U) + aNonceWordD;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 880028529183500036U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2379557167489415783U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11854373946064529806U;
            aOrbiterB = RotL64((aOrbiterB * 150755294320438887U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 1487252775956449964U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12777924204511625545U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1366019527386994789U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15998631485222477969U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8864212892296191613U;
            aOrbiterI = RotL64((aOrbiterI * 579242788050369815U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17069347835763226743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7443008171694679791U;
            aOrbiterF = RotL64((aOrbiterF * 748894368884566607U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17334256152350782002U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 8986626119086556393U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 2258172145924120235U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8528180968228358674U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12702290928064582589U;
            aOrbiterK = RotL64((aOrbiterK * 15673603224146737631U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7742438100860023610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3729687240959702198U;
            aOrbiterG = RotL64((aOrbiterG * 3756794766163746783U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 426129097367382096U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16782175452274911213U;
            aOrbiterE = RotL64((aOrbiterE * 1041477289638333659U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5942016166948841079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5260815086125551703U;
            aOrbiterA = RotL64((aOrbiterA * 1603799103692438147U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11732742583346900772U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17182924380693084401U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 14858685629471497071U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8539335803784852017U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16124889768301047791U;
            aOrbiterC = RotL64((aOrbiterC * 6607245691919237755U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterA, 56U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aNonceWordF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + aNonceWordO) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 10U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 20U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 51U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9619U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 6469U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7744U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 8610U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9417U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 5981U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7468U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 29U)) + 2571116506511057880U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 48U)) + 13112435411509707292U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 35U)) + 10403251762787357256U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 8461951095541400405U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 57U)) + 9890793478557463815U) + aNonceWordC;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 3030229465991783707U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 7273848154043719247U) + aNonceWordA;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 10681774862516028276U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 22U)) + 7105082755586853104U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + 6588579345319551129U) + aNonceWordL;
            aOrbiterC = ((aWandererH + RotL64(aCross, 27U)) + 14616333550242386092U) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15439666290229654921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 3360304356760164799U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5164191920584106237U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14438730801970761889U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14515616787452085729U;
            aOrbiterJ = RotL64((aOrbiterJ * 2041601927968559821U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4167853822635132419U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8950982233003320239U;
            aOrbiterK = RotL64((aOrbiterK * 887144270884244907U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12391327853728029953U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 7100871010552394421U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 16552349374101955967U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15381697462381887944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6801677551341079401U;
            aOrbiterH = RotL64((aOrbiterH * 13325954438427340703U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 947011315719204867U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6356920162398333481U;
            aOrbiterI = RotL64((aOrbiterI * 5566721941682667419U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8910262020598577378U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8778455415977526457U;
            aOrbiterA = RotL64((aOrbiterA * 4092470497616637283U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5585696961453127223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9670655481681494412U;
            aOrbiterD = RotL64((aOrbiterD * 7863197168965036383U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10713004007087085729U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4036355047492922339U;
            aOrbiterG = RotL64((aOrbiterG * 6923922258047667173U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14580156873863533497U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7049502932205025182U;
            aOrbiterC = RotL64((aOrbiterC * 8665428649262370727U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12707521269341941677U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2571116506511057880U;
            aOrbiterE = RotL64((aOrbiterE * 2388236789245943699U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 38U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterA, 56U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 43U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aCross, 56U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 36U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12563U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 13480U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12399U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13493U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((aIndex + 13810U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 57U)) + 13442819395490639310U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 18U)) + 8187292523194120936U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 41U)) + 11469697159823131388U) + aNonceWordK;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + 13414083692375929653U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 13U)) + 11404010733687907517U;
            aOrbiterH = (aWandererE + RotL64(aCross, 35U)) + 6783212827186218247U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 53U)) + 8561131439340372614U) + aNonceWordJ;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 57U)) + 6252609642004429113U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 3U)) + 12804867444200448952U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 2739648749603690781U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 14808861217017399752U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17588866502571268888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5882260142735642980U;
            aOrbiterB = RotL64((aOrbiterB * 7688252946143263869U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15493099088132862949U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5175647411532429582U;
            aOrbiterE = RotL64((aOrbiterE * 15226544495598541883U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14279707376173642767U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6826363572161275158U;
            aOrbiterI = RotL64((aOrbiterI * 5263708315440161809U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13267185753040999992U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9980987858092888720U;
            aOrbiterK = RotL64((aOrbiterK * 13210290848800728635U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3582972937645514549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10140409019562890804U;
            aOrbiterG = RotL64((aOrbiterG * 6944490201647678479U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6160444117287330557U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16344602960561293113U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2319964919335633293U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3497141036108337171U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 91269118352540308U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5160060720189045505U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12739932748793144857U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12820180915064791197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5843849637411948699U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17572075652083359962U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10684041099654982701U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 7121293375756263771U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10739534650885677354U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9731206787727954809U;
            aOrbiterA = RotL64((aOrbiterA * 3730875775588585547U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9655432616347117764U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13442819395490639310U;
            aOrbiterH = RotL64((aOrbiterH * 3650859301708619119U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 22U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 58U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 54U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterD, 53U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 22U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16530U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneA[((aIndex + 21305U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20112U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21477U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21144U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 13650869943246163567U) + aNonceWordD;
            aOrbiterD = (aWandererA + RotL64(aScatter, 60U)) + 3435284932011770999U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 43U)) + 12388155658186776579U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 2374345913955712039U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 6095094526980292156U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 14U)) + 4965147025852444174U) + aNonceWordC;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 41U)) + 3261881216269075298U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 35U)) + 4939780217097329222U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 21U)) + 3019862009792676287U) + aNonceWordE;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 27U)) + 901910626217143974U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 3647055146712366383U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7731765438957392967U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13409819457393479741U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 3345078200262410715U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5415832109107794258U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8876738832313114471U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1304277600444504135U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 17135570542519390359U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2373193062766802082U;
            aOrbiterK = RotL64((aOrbiterK * 4213691513185791519U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16318403285501718552U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8456043288604687045U;
            aOrbiterI = RotL64((aOrbiterI * 10556964529144571683U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 10572534930284516528U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14616251186735204677U;
            aOrbiterA = RotL64((aOrbiterA * 2048651204265459805U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2837006243817205610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5315917323622194254U;
            aOrbiterJ = RotL64((aOrbiterJ * 4080522050089666599U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12084676282761185907U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7922080344175593788U;
            aOrbiterH = RotL64((aOrbiterH * 7603522302708937379U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17620847289789547792U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 12140386059533463650U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1443266480620969535U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4006608081473218762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3152507055132739011U;
            aOrbiterF = RotL64((aOrbiterF * 11929522909695002321U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10845720206369283181U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16572752872386133133U;
            aOrbiterB = RotL64((aOrbiterB * 2891952650448087211U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15544908026178481075U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13650869943246163567U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 1275090431127426217U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 10U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 36U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + aNonceWordH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterD, 51U)) + aOrbiterF) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 40U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23799U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 24862U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24213U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24127U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23940U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25711U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 10U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 19U)) + 826930775230515406U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 5137814617363250861U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 53U)) + 14761561947426681616U;
            aOrbiterG = (aWandererA + RotL64(aCross, 43U)) + 12773023438753662590U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 53U)) + 7331345852207096322U) + aNonceWordP;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 5U)) + 3899381212671247460U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 10072004147620068599U) + aNonceWordJ;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 10U)) + 3424585039401897560U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 39U)) + 8246760141625966321U;
            aOrbiterI = (aWandererD + RotL64(aCross, 51U)) + 3655992860610853290U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 37U)) + 11154618022505863898U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15629361991059709973U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10842068502278489664U;
            aOrbiterB = RotL64((aOrbiterB * 17223002513104960799U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5571312349016336686U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 589313823745748879U;
            aOrbiterJ = RotL64((aOrbiterJ * 1356685926549786027U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13633457935771935260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12684602052812183096U;
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5711307583717354204U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7181854170553728211U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9835601115561325911U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1884620014396115821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1471516373272364262U;
            aOrbiterG = RotL64((aOrbiterG * 5126319375714848029U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 742739371092077733U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8075893317715227838U;
            aOrbiterK = RotL64((aOrbiterK * 11208274111743259795U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8179547722249281263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15305282712174742323U;
            aOrbiterE = RotL64((aOrbiterE * 7951986906055462929U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1430543231751281079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14585341768267283387U;
            aOrbiterI = RotL64((aOrbiterI * 313213844964269133U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8123889986027932297U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2081696191347150910U;
            aOrbiterA = RotL64((aOrbiterA * 4869653441012615053U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 10166788886199265936U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15927074835525735601U;
            aOrbiterC = RotL64((aOrbiterC * 6747650218540675523U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6997764816848988590U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 826930775230515406U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 9943232461538279601U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 14U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 34U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 60U)) + aOrbiterK) + aNonceWordI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterB, 21U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28958U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 31691U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30097U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32600U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31558U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererG + RotL64(aCross, 51U)) + 6771552164800695068U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + 12131763371571322040U) + aNonceWordH;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 26U)) + 3326182381395522013U) + aNonceWordN;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 12288775097697156383U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 5195948373449796741U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 21U)) + 14404044002250137144U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 11142382920035825426U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 47U)) + 2967149520256475485U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 23U)) + 1470907369577818097U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 3U)) + 9231668148004163910U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 18U)) + 13078929163913892386U) + aNonceWordF;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9485274692075657877U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12216951187543631673U;
            aOrbiterE = RotL64((aOrbiterE * 6571066246507310805U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6933334652581744234U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17260276102423580920U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7796879893790990605U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 387767848169714392U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8597538259308082638U;
            aOrbiterK = RotL64((aOrbiterK * 4888054690557707241U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7996708724489146033U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15357384191688149939U;
            aOrbiterA = RotL64((aOrbiterA * 9827691726832491373U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17739222908739454637U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1614322333281471170U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 7063116837752240891U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4531604274893197209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3453280714992341288U;
            aOrbiterH = RotL64((aOrbiterH * 8390029711127907805U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 116623650872661533U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6565636510115095988U;
            aOrbiterC = RotL64((aOrbiterC * 9691897067492501177U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10303258439817808058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10917642773040237611U;
            aOrbiterJ = RotL64((aOrbiterJ * 10232856828372963363U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2087058228468680821U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3691125545393861889U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1768745056298937903U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9240209357066002219U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7645250700232422804U;
            aOrbiterB = RotL64((aOrbiterB * 6762116797395687607U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9859862257084218280U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6771552164800695068U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 11063630807191661109U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 42U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 5U)) + aNonceWordP) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aNonceWordE);
            aWandererA = aWandererA + ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 60U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 44U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB54CF7B305222045ULL + 0xA09BBA05CF016588ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE336915D83D21871ULL + 0xA88EEAC15EA8422FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB9778656A25908B3ULL + 0xF5050D56955511FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xB7A8E424CD21E30DULL + 0xF46BD0B6E3C8DEFCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8C1B3147AE993C73ULL + 0x90AF1F148C7CF57DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA1AD8AE071ACB959ULL + 0xE5CC529E390BD69CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8A443E44A69F789DULL + 0xC76BBE0D77F5E347ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDB62E377142DC047ULL + 0xE2F9E521DFDBF5CEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF599375FD1FA0595ULL + 0xEC6555F7DE0D4DDEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED86029189396067ULL + 0xC8A856F3542D93C4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB5DFD911654B650BULL + 0xCEC9DC53D92F202DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9E221001977DAA7BULL + 0xCF60996F156A282CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE147C6030BAC5067ULL + 0xB1031DA4773DF606ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFDC334101A63517FULL + 0xCF201EE766D4430AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8704B4F7C40B99AFULL + 0xB73FD544E919489AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDFF3C5FCAE647EE1ULL + 0xEAF985F7FEE4A3D3ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneB, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aWorkLaneD, aInvestLaneB, aSnowLaneD, aWorkLaneC, aExpandLaneA, aInvestLaneC, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3910U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((aIndex + 2497U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 2669U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1844U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 236U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 3927U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 4U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 29U)) + 9133751643283278896U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 60U)) + 8971581804375380408U) + aNonceWordP;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 12559650383714566592U;
            aOrbiterI = (aWandererG + RotL64(aCross, 51U)) + 15753206088872859163U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 7640756270450762350U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 35U)) + 7340073357551376125U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 41U)) + 5270256573644196046U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 3567367996479995928U) + aNonceWordJ;
            aOrbiterK = ((aWandererH + RotL64(aCross, 18U)) + 11939634537492733738U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7051817732424527120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1730487669951837941U;
            aOrbiterD = RotL64((aOrbiterD * 15191634337956285841U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18009252467909454817U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2361024272031696442U;
            aOrbiterH = RotL64((aOrbiterH * 15215151562500226027U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15902755877642960397U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12243517544704116184U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 2576071074148141447U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16846181962302186187U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 636121425116506681U;
            aOrbiterI = RotL64((aOrbiterI * 17075030673338779993U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6887385655828217318U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3705834550934775862U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11275428284929594435U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11165142437077969438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6426659930331618269U;
            aOrbiterB = RotL64((aOrbiterB * 17170640810530893705U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12629082390899315789U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4277510580069574724U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 9829125163412708305U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13814834144170469978U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3698381854100295826U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5126359230872258015U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11623170635983579937U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7247413650388803796U;
            aOrbiterK = RotL64((aOrbiterK * 3403219499465560059U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 28U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 35U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 56U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + aNonceWordH) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 9047U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 10910U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9322U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7062U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10126U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6905U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7378U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 12027839670755583592U;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 20U)) + RotL64(aCarry, 11U)) + 15380130703509859843U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererB + RotL64(aIngress, 29U)) + 4590907433867798074U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + 1754574023602519724U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 3U)) + 9832756659564903767U) + aNonceWordC;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 5035088494491470403U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + 14199170923323644638U) + aNonceWordK;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 39U)) + 8325619421264440438U) + aNonceWordN;
            aOrbiterA = (aWandererI + RotL64(aIngress, 58U)) + 969534320779067977U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 270575869402913847U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13344806516599578910U;
            aOrbiterH = RotL64((aOrbiterH * 10193544126281901579U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15143147951139409101U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14425582489214169238U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16893787086337916355U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13951127523239064584U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14177925225918293579U;
            aOrbiterG = RotL64((aOrbiterG * 13079514031864998485U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8258920744278218901U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7408161179397242453U;
            aOrbiterD = RotL64((aOrbiterD * 975737128100519169U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8581481606764773468U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10078416198417433133U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1102721083915858247U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18299772198826189580U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 18304668908084397946U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10589455451200578687U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16729632621573817223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13362300981585573239U;
            aOrbiterC = RotL64((aOrbiterC * 9824473895535518785U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 8629682832849915380U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6852852009091469641U;
            aOrbiterA = RotL64((aOrbiterA * 11912646687050011915U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7433098156961745198U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10931806208899417308U;
            aOrbiterJ = RotL64((aOrbiterJ * 14699197041038067483U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 30U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 22U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aNonceWordJ);
            aWandererE = aWandererE + (((((RotL64(aScatter, 42U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordB) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 14918U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 13460U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 14977U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12200U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12990U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 6U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 15910560457440369082U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 5U)) + 17953072986407436888U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 14U)) + RotL64(aCarry, 27U)) + 15446940721193538669U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aScatter, 41U)) + 3020785262774422009U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 57U)) + 7001288645424994404U) + aPhaseFOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 23U)) + 13385250665458462689U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 5U)) + 4841895644623005949U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 53U)) + 13053476783239482065U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 19U)) + 641996979335975244U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16211238020928688299U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12715448751323279480U;
            aOrbiterI = RotL64((aOrbiterI * 2116880429675303291U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17784406727699995290U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16626339815786580778U;
            aOrbiterK = RotL64((aOrbiterK * 13940754474750138041U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9035070625716345139U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6085848172494001945U;
            aOrbiterC = RotL64((aOrbiterC * 10405728912339646693U), 13U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 1177103851507561053U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2281901691017816407U;
            aOrbiterG = RotL64((aOrbiterG * 3142197009403602497U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9040984343694325070U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13334258224023902365U;
            aOrbiterE = RotL64((aOrbiterE * 4782523727707164869U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1079824790138592518U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14024082692012948652U;
            aOrbiterH = RotL64((aOrbiterH * 3219489374333737903U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2966776524421278970U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5510281854029308547U;
            aOrbiterB = RotL64((aOrbiterB * 9275402927591867297U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7126632329316720048U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1476827035602733472U;
            aOrbiterA = RotL64((aOrbiterA * 2217671289726794033U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6470212302133184965U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4172257438373147415U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4449314239630366533U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterH, 60U));
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterI, 20U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20325U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 20435U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21588U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19573U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneD[((aIndex + 19994U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 21U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 27U)) + 13583136155674166402U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 12830472187484919497U) + aNonceWordB;
            aOrbiterF = (aWandererE + RotL64(aIngress, 14U)) + 18081197909484522509U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 5U)) + 8680634051297891550U) + aNonceWordD;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 13939998767458656823U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 23U)) + 1795730579103692594U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 53U)) + 17369751719734069999U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 224769585901248068U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 58U)) + RotL64(aCarry, 11U)) + 4133547085925268180U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7022512056309567391U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10319484359046945495U;
            aOrbiterF = RotL64((aOrbiterF * 3400140531307001933U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10483878349412282069U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6481381149199985736U;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13721077228796934509U) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9704818014314175007U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 760445624027740287U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6253040047758584339U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16890211690273641226U;
            aOrbiterA = RotL64((aOrbiterA * 5622534399866057841U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6216227831265032436U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9201669637050388263U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 5106927540934338576U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6368134569042291431U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10080368957861445998U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10784789383436485808U;
            aOrbiterB = RotL64((aOrbiterB * 3794918350254445939U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15426339824951793026U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17637144549368340331U;
            aOrbiterD = RotL64((aOrbiterD * 10971293914614704441U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9941300382181962134U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8118046374121322097U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 8481945819050983127U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 42U) + aOrbiterG) + RotL64(aOrbiterB, 34U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 3U)) + aOrbiterD) + aNonceWordN) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 58U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24357U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneD[((aIndex + 22060U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 27000U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25196U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 24597U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 8101351470141807662U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 47U)) + 6965474099521076705U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 6803828268885684784U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 19U)) + 13454235922950972488U) + aNonceWordD;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 47U)) + 11678091885751244777U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 40U)) + 5307134544628507141U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 57U)) + 4873703518950429353U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 23U)) + 8542156221858586039U) + aNonceWordH;
            aOrbiterI = (aWandererK + RotL64(aCross, 51U)) + 3993726182905296513U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12113047622035464386U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1944244448665721151U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 7010050836758762003U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12914188029425467576U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 2486762763475327024U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 12319769994433811617U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14580191602982245481U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12093414832400135066U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12720286833215690663U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13623906997320021065U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9977356009806428696U;
            aOrbiterG = RotL64((aOrbiterG * 2005536391712733499U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3694954095397810851U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11453812627797091638U;
            aOrbiterD = RotL64((aOrbiterD * 13730420725113907161U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 542311345544726351U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3024285045990499484U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 5153745952148205645U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15397664082460849530U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10716856680110815056U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 13947203772929252823U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 833342121331428547U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1111339940097269219U;
            aOrbiterI = RotL64((aOrbiterI * 17991642769781175473U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9312963978841402871U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8225496710723213204U;
            aOrbiterB = RotL64((aOrbiterB * 894499195498817065U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 56U)) + aOrbiterD) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterA) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterK, 6U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28557U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 27450U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 30710U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29598U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32222U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCarry, 5U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 5906639480605353429U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + 5293518570213287605U) + aNonceWordD;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 42U)) + 15383185501428521377U) + aPhaseFOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + 15364072512743978902U) + aNonceWordJ;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 4525473357144014271U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 10400911938125603074U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 19U)) + 16417506293824627550U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 23U)) + 2419329331753341815U) + aNonceWordN;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 34U)) + 14929222427923332069U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16771573504983922586U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1863466450051787622U;
            aOrbiterC = RotL64((aOrbiterC * 2585626547126027053U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12895350137096692415U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 3700979086526298327U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 10279730254867618193U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1977099106211282426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6144698304096915742U;
            aOrbiterE = RotL64((aOrbiterE * 5039822990560519609U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3858895556659724975U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1283646340363435327U;
            aOrbiterD = RotL64((aOrbiterD * 11622421841377018069U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6240532051889108891U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 757364889381634634U;
            aOrbiterG = RotL64((aOrbiterG * 943852137901972945U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5272945693977418174U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6850528198786172283U;
            aOrbiterA = RotL64((aOrbiterA * 1966383079897679953U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14431587733859573714U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16124590257870999553U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7755796211433191143U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14912695018110241411U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11098623474413346520U;
            aOrbiterI = RotL64((aOrbiterI * 15167688959990872051U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3484847683376368686U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2295388097292719800U;
            aOrbiterK = RotL64((aOrbiterK * 1240808318176106909U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 20U) + RotL64(aOrbiterB, 47U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aNonceWordC);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 52U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 35U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 22U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA9CD8D60ACE0B55ULL + 0x96636D93F5A8FBDBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x916C54BA7A705A29ULL + 0x9BEDC96B593B089BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCE8E472A3EAB1DAFULL + 0xD753CDC1DE69783DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA12CE7E46396C14DULL + 0xA84D1B7A8853F511ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFA8C506B726C5E57ULL + 0x9C7233183D328257ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xED7F7C44082495C5ULL + 0xA5338E8BB4871548ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB97FFDBC6A15DA23ULL + 0x93963FD547D2FB61ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC6CA25C487FAB1B7ULL + 0xE36628FDB0DADB9EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFD7D327C5EC3F5B1ULL + 0xEAC938DDBEEB98DDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD9F0D6E983B5354DULL + 0xE3A373D8AE7AA3A7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF31719395D0FF607ULL + 0xD081507AACEFE7E9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE5282B2DC33F8143ULL + 0x93752344CDE72C63ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x858A1261930C6F29ULL + 0xECAB5E0D08838FFCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC0708A5345CF5EA5ULL + 0xC07E9E44F729C057ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE0318265A79A879DULL + 0x8990025371A9F216ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCB5C77112A1D198DULL + 0xCF3D5FFED66C0AD7ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aFireLaneD, aWorkLaneA, aInvestLaneB, aInvestLaneD, aWorkLaneB, aInvestLaneA, aExpandLaneA, aFireLaneB, aExpandLaneB, aFireLaneA, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 4102U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneB[((aIndex + 40U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2873U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 951U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 1272U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2746U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 14157904117287696136U) + aNonceWordL;
            aOrbiterC = (aWandererF + RotL64(aCross, 37U)) + 7369512677371640676U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 29U)) + 8411250745902073798U) + aNonceWordK;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 5002041814539710275U) + aNonceWordP;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 9538041410816283124U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 21U)) + 5210700103927513061U) + aPhaseHOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 4U)) + 7600709399101287982U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2366369466696580499U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5544575244203019109U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8710073749110329779U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15998211310115361630U;
            aOrbiterA = RotL64((aOrbiterA * 15275657696897688955U), 21U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 15354357553877376422U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10657523549259276169U;
            aOrbiterH = RotL64((aOrbiterH * 13695239532898311073U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10405750198355464768U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3465819693133515142U;
            aOrbiterG = RotL64((aOrbiterG * 14678343718277562799U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16724189641701408630U) + aNonceWordD;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 3484340153620198872U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7420442404884871126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11138445997256757636U;
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1428191560884663125U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16950093140800653985U;
            aOrbiterC = RotL64((aOrbiterC * 4423012306984814805U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 30U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aNonceWordF) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterK, 60U));
            aWandererH = aWandererH + (((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordG) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10785U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((aIndex + 5952U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 5918U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((aIndex + 8775U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7774U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 5498U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 9893U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 12U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 57U)) + 785861751704720606U) + aNonceWordK;
            aOrbiterI = (aWandererE + RotL64(aScatter, 3U)) + 15968088718435606299U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 1393976526590347151U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 35U)) + 17240750947292745884U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 4921576136163183137U) + aNonceWordE;
            aOrbiterE = ((((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 3334047873553153032U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 20U)) + 15086509978458408698U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 892391205397581998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2965686403183767521U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 709160942482770225U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14632215393655706170U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15740589515342377322U;
            aOrbiterB = RotL64((aOrbiterB * 15677716942904794913U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11131164813943086445U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6988080581278900960U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 6412189142344044255U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 16021254613117657178U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6183615599897921154U;
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12533992547026652747U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3104325358982904219U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14977348108778147265U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3878525937957474644U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2120435259884368445U;
            aOrbiterJ = RotL64((aOrbiterJ * 15964718652193073177U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14928658302694194856U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9121310461310309348U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17304439784647477491U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterI, 41U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 10U)) + aOrbiterD) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aNonceWordM);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordF) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13376U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneA[((aIndex + 12031U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15337U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12987U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneC[((aIndex + 12283U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 35U)) + 6733949564325516029U) + aNonceWordE;
            aOrbiterI = (aWandererH + RotL64(aCross, 60U)) + 7304098437143918796U;
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 3923949518391777800U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 13U)) + 14243591003388927124U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 18329498724605410406U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 51U)) + 13118172167747037249U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 5272025143849174212U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16075917179214318424U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15263590648674658399U;
            aOrbiterH = RotL64((aOrbiterH * 9918239923411740337U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13730046728289525921U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7703141464499623408U;
            aOrbiterK = RotL64((aOrbiterK * 5886009900621521987U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1382279753822135359U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2973369221699098292U;
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11578274119583013219U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3419411247737896674U;
            aOrbiterC = RotL64((aOrbiterC * 17814942652262802991U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2582783513078999303U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3959762790273529677U;
            aOrbiterI = RotL64((aOrbiterI * 383974377372162751U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 465795011576934604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17880826624185821135U;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10819659185349413173U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17298208553586835030U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1965860510614222093U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 48U)) + aOrbiterA) + aNonceWordI) + aPhaseHWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterK) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 57U)) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19484U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 20198U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20845U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18695U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 16723U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 57U)) + 6654158889644956636U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 3U)) + 9045779659363991870U) + aNonceWordP;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 47U)) + 3888897662136993491U) + aPhaseHOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 36U)) + 6882016842864459345U;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 15601891715956172291U) + aPhaseHOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 5176811598629335350U) + aNonceWordB;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 12519945150889074325U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4552583214397603278U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14225482701804864688U;
            aOrbiterB = RotL64((aOrbiterB * 8526052833180466359U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 5485298070606280363U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11237713257388094289U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 11032429223099413011U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14340345895626142788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16275167270553643347U;
            aOrbiterD = RotL64((aOrbiterD * 7308578867128951199U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14041860597556520250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 11483155566419547004U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4608508534724289325U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13461385011638899485U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2389196334288832895U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4062682330273866602U;
            aOrbiterE = RotL64((aOrbiterE * 8787682133271101901U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5655656046585592034U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7977947821249746880U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10082104644185964787U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aCross, 34U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterJ, 12U)) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + aNonceWordD) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25273U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 27183U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 26293U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23198U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 23461U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 50U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 15549114274303128055U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 16466750056388063241U) + aNonceWordD;
            aOrbiterI = ((aWandererI + RotL64(aCross, 39U)) + 12209449840836787142U) + aPhaseHOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 14551496099734294336U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 6266576428679808622U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 47U)) + 16892841575635668152U) + aNonceWordP;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 12U)) + 7375966221423362125U) + aNonceWordB;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11926105302821753530U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16219253791550461124U;
            aOrbiterI = RotL64((aOrbiterI * 2117550758226173419U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7299056065319248160U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15234001484933728439U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 8182244796017018911U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6615802589932632120U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5481176858895819247U;
            aOrbiterF = RotL64((aOrbiterF * 3604590158551984877U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17220507586542139380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14137921473739415340U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10634645686035907603U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16981960446540932787U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10897565927079518588U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 418843936329303571U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2746889569299593263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4894117146736361379U;
            aOrbiterG = RotL64((aOrbiterG * 2656750612042673191U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 18294823016957137777U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 86828501068883383U;
            aOrbiterD = RotL64((aOrbiterD * 11432686669235402365U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 60U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 20U));
            aWandererH = aWandererH + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + aNonceWordE);
            aWandererC = aWandererC + (((((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 41U)) + aNonceWordI) + aPhaseHWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28128U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 27843U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 31543U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32181U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneB[((aIndex + 28566U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (((aWandererA + RotL64(aScatter, 40U)) + 15045917390223766480U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 57U)) + 10763054007033668758U) + aNonceWordC;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 19U)) + 13190170142593666607U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 9657025731441167065U;
            aOrbiterB = ((((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 11433367178975954211U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 17904920143996810366U) + aNonceWordI;
            aOrbiterD = (aWandererF + RotL64(aIngress, 13U)) + 3244383020512113283U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6538815775171139091U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7195368312757976343U;
            aOrbiterK = RotL64((aOrbiterK * 10515679176134176565U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 18134430713910279374U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6571776588427107976U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11916502085252589161U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11830778129647517758U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9793702760907767365U;
            aOrbiterI = RotL64((aOrbiterI * 4096246227968677179U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2287235876793192036U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8951959188326141794U;
            aOrbiterA = RotL64((aOrbiterA * 9968356718110753845U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7583061790273240157U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13869345563551689212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 277480328952975002U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 4983735092494677578U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9490022869381030928U;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterB, 34U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterF, 41U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + aNonceWordB) + aPhaseHWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 181U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2041U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 942U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1149U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 43U)) + 12131317914288566437U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 53U)) + 5672805657999385496U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 3581710244233124197U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 19U)) + 15251296040538489436U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 11295008604679904153U;
            aOrbiterC = (aWandererC + RotL64(aCross, 39U)) + 2230897493419504490U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 30U)) + 7109600123297458999U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 53U)) + 13119156643107683803U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 35U)) + 14755160867807355250U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16829363373287496832U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 16981122946707720883U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5394974422201576627U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8806000776958603317U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16810923047720876014U;
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8129657889554436328U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8653100378491974463U;
            aOrbiterA = RotL64((aOrbiterA * 11395283153912468661U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17048985838727432415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10892675550889823573U;
            aOrbiterJ = RotL64((aOrbiterJ * 976298937314081913U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15960158965421254346U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12290011578634850001U;
            aOrbiterK = RotL64((aOrbiterK * 9280475585104357745U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16265047040311479093U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10312956912303656248U;
            aOrbiterC = RotL64((aOrbiterC * 3012584393253845131U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16706890352221352779U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10630955894218491929U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12675937483456206355U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4009352551041162434U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3043810773683888556U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4328135390387997315U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1398071019814944785U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16689766557488135301U;
            aOrbiterI = RotL64((aOrbiterI * 8403881916549404871U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + aPhaseAWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 50U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 20U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 56U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3886U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 4319U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4080U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 4893U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 14U)) + RotL64(aCarry, 35U)) + 10038936806177516123U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 37U)) + 1773168435195292638U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 10655711161526628072U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 14422295664639740437U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 3U)) + 4125228715513159576U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 48U)) + 3670449653158650845U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 57U)) + 17553727567180813057U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 41U)) + 5111401772713882743U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 53U)) + 7688573124662314413U) + aPhaseAOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9438375825507814395U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14177477039902118886U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6467406626985022537U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16329942595859623928U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3990536794006836672U;
            aOrbiterB = RotL64((aOrbiterB * 579024714339065373U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5072881436583180756U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16789727877867289997U;
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17313956922306689438U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11530878396329822041U;
            aOrbiterF = RotL64((aOrbiterF * 11356860047841383129U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3612616532321160196U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterC = RotL64((aOrbiterC * 12938945495299393177U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8677279703778052804U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 1912172980909479362U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10053289257955474143U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1460085850227494500U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 12116763868122868147U;
            aOrbiterG = RotL64((aOrbiterG * 6076945628020280957U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17571840610366424432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15581362592611080868U;
            aOrbiterI = RotL64((aOrbiterI * 1129054058044872003U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14434700039977611666U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4534294602623329152U;
            aOrbiterK = RotL64((aOrbiterK * 5860911553425182045U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterF, 27U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 14U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterK, 43U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterH, 35U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 54U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 8001U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 7260U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6203U)) & W_KEY1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6643U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6753U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 43U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 29U)) + 17668251151213543491U;
            aOrbiterG = (aWandererD + RotL64(aCross, 20U)) + 16101602509895104517U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 13U)) + 9083915270773304935U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 12810720730318214811U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 35U)) + 18113428002071925621U) + aPhaseAOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 53U)) + 1582208899354109878U;
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 4180688104819188154U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 5U)) + 8954598189262820611U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 15360094153175355879U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8383954114668216260U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15626783326234049197U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15058420415480073793U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10609978564404958066U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17656516608997517984U;
            aOrbiterI = RotL64((aOrbiterI * 4590620354119899777U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 760077259110786536U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3597338735888033063U;
            aOrbiterD = RotL64((aOrbiterD * 6548831472863517621U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4431777844935985157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10710423172154671296U;
            aOrbiterE = RotL64((aOrbiterE * 16267496318491473315U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10240882795242085185U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7826053487019825891U;
            aOrbiterA = RotL64((aOrbiterA * 15053729937684375907U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9418883403715727353U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11507423614799075545U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189463984557044693U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11545217316421066655U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 617921402135485341U;
            aOrbiterK = RotL64((aOrbiterK * 8182920764965471653U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14456933220749921009U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7990243583564535387U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5994900368027985469U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14023633125757654751U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11319146808574958827U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13676159969338309307U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 18U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 18U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterD, 34U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 52U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8884U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 10292U)) & W_KEY1], 44U));
            aIngress ^= (RotL64(mSource[((aIndex + 10147U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10456U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9652U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 10735U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 6U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 3U)) + 7270044678408187242U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 47U)) + 10192278965379756766U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 17568666746676060748U;
            aOrbiterA = (aWandererK + RotL64(aCross, 43U)) + 14312927531124963037U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 9825825726152087706U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 57U)) + 9696778570255265896U) + aPhaseBOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 29U)) + 17657841352013417228U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 19U)) + 16207815085909628439U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 39U)) + 1752979206374514227U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10456310689643905854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16127830548663742550U;
            aOrbiterI = RotL64((aOrbiterI * 4355938404839045417U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2940917376003930842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7353596864777649953U;
            aOrbiterK = RotL64((aOrbiterK * 7499468723171042005U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12725092740446150705U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5791296650856037010U;
            aOrbiterH = RotL64((aOrbiterH * 760379251950502133U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1200130368046206150U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16689604428598558547U;
            aOrbiterE = RotL64((aOrbiterE * 13815324235939996623U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14359561591103730856U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3975025843599045263U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5025047888533298617U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14017901732955607601U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10431526786489555196U;
            aOrbiterD = RotL64((aOrbiterD * 10181915874476132407U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7320527073559849223U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15333411223710709907U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3488684905528068775U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14302474063321663801U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2104154521019935187U;
            aOrbiterJ = RotL64((aOrbiterJ * 12944382959742278055U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5167600586916325228U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4566823109447208716U;
            aOrbiterA = RotL64((aOrbiterA * 9997799807454267443U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 10U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterD) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterI, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 42U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11549U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 12796U)) & W_KEY1], 52U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12156U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 12360U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13429U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12966U)) & S_BLOCK1], 20U) ^ RotL64(aInvestLaneA[((aIndex + 11994U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 28U)) + 15036852811491820366U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 305637140752898475U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 53U)) + 11948631574496129610U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 3U)) + 5321623592482991426U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + 4075270159062690728U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 15111580500356908928U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 35U)) + 7244150695504160363U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 5131563519577488862U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 37U)) + 5881954992088651371U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12780935808751507998U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12599159643925470226U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17690046932587062701U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9466589929741834066U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6093158735705189789U;
            aOrbiterH = RotL64((aOrbiterH * 7453778295800853653U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17461243886150519249U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15456408913739900718U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16093292401746174671U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11260643903290392780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7870342756041882616U;
            aOrbiterF = RotL64((aOrbiterF * 2431528656086173419U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 134484990005888936U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10626896209992890407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12034131076645285597U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14031164129515132292U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1771835705730244212U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 186981668443596623U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16395472745067254664U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1455944290845294254U;
            aOrbiterA = RotL64((aOrbiterA * 6757824754363319079U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17866422769075350837U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10226884082632410805U;
            aOrbiterB = RotL64((aOrbiterB * 206035536985843815U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14474587247775371703U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8501763445324525303U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5298694643596784007U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 43U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterG, 54U)) + aPhaseBWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 23U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13737U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15670U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16148U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16353U)) & W_KEY1], 51U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16257U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16194U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15771U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 16016931609704150191U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 14511433515861302636U;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 11691237442613269593U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 34U)) + 16383220587320484649U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 39U)) + 14293015313458219868U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 4407695248205526670U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 11U)) + 1158323195324398372U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 6577683409653864555U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 30U)) + 171080079472863843U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5766333425872228205U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16173508656917582960U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12187968015372936695U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11781450063402219202U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13033139686637576694U;
            aOrbiterC = RotL64((aOrbiterC * 4331137994135472025U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4006310759400926020U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13156817947481574467U;
            aOrbiterA = RotL64((aOrbiterA * 563189239835001483U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12791290558893516411U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 989729955679243234U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8757228712495095017U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 838379839663022790U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2830743864262313606U;
            aOrbiterH = RotL64((aOrbiterH * 10173947177104802797U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2146646527331684652U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4629168181742174906U;
            aOrbiterI = RotL64((aOrbiterI * 9046124907945045131U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 1150129989168501777U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 619659995945229440U;
            aOrbiterK = RotL64((aOrbiterK * 13734821008174603409U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8120315647582116952U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13754584116324996165U;
            aOrbiterF = RotL64((aOrbiterF * 12295486140772079747U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6084566798869999580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5731665119233722504U;
            aOrbiterG = RotL64((aOrbiterG * 5921510209025133639U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 14U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 54U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 44U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17772U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 17534U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 18828U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17300U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16447U)) & W_KEY1], 29U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17844U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17622U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 4U)) + 9774364261626083532U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 18059001521926116420U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 10615626210406381148U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 10536484278007898620U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 48U)) + 13320663045139972700U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 27U)) + 17127001787268166583U) + aPhaseCOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 19U)) + 16742574590844166551U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 11U)) + 8347719720758228053U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 35U)) + 13502468705946051986U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3512687886188904904U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 495660316165795934U;
            aOrbiterI = RotL64((aOrbiterI * 6724596801190194913U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5092722552034477356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15641128019608284015U;
            aOrbiterF = RotL64((aOrbiterF * 3621036395703527059U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15421873776811085458U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 17978775513204574125U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16617179197537669849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1931805387534012528U;
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9544923119559308431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12930999400470173353U;
            aOrbiterH = RotL64((aOrbiterH * 16791006919271490005U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13673733276226249890U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2032263473309124738U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3088728329261360607U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14868502349358414206U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10116495537187552321U;
            aOrbiterJ = RotL64((aOrbiterJ * 1380512121796709469U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5341113995358179244U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8415417980279705731U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8521501372683793821U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2462819265072352463U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7657062767608441931U;
            aOrbiterB = RotL64((aOrbiterB * 15554638801273540163U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 42U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 48U) + RotL64(aOrbiterH, 46U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 21U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 4U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19823U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 19529U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20913U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19252U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19294U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21790U)) & W_KEY1], 52U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20915U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 20329U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 40U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 17711946802293254150U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 57U)) + 16652362590489569378U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 39U)) + 6972810344198183097U) + aPhaseCOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 14U)) + 13117100889782940546U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 5U)) + 13199305696782626591U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 992156184392760945U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 13791265442074543880U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 51U)) + 17057087245252294859U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 10U)) + 13444195995883541046U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6723678233676059420U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7913379431208430475U;
            aOrbiterF = RotL64((aOrbiterF * 2295062944289127123U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4481887195529300665U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11892724101424384078U;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7700902083270424194U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1888001433557140271U;
            aOrbiterK = RotL64((aOrbiterK * 8975562955027025349U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14996753906788986929U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 939004845422123765U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2507090308972292313U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11922230289291941807U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15681187459741147199U;
            aOrbiterD = RotL64((aOrbiterD * 10124947739653819101U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9119043713532718155U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8327697433992362166U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11157657162184304567U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13630755116592440359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 771252613886022889U;
            aOrbiterE = RotL64((aOrbiterE * 2958918915223536519U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8524239721467527770U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17732617735422435572U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13992947983987668631U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5265753270696005619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14456128349522985053U;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 34U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 20U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 60U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 46U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23539U)) & S_BLOCK1], 48U) ^ RotL64(aKeyRowReadA[((aIndex + 23759U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22958U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22875U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22522U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22113U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22713U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneB[((aIndex + 23705U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 10U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 13350544654542863236U;
            aOrbiterE = (aWandererG + RotL64(aCross, 36U)) + 12364346790125404372U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 57U)) + 9738750172849512764U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 29U)) + 3781373837635491421U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 23U)) + 16635020317512702337U) + aPhaseCOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 5383653921676231276U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 10181959815492056493U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 10005510924273927017U;
            aOrbiterK = (aWandererK + RotL64(aCross, 47U)) + 9524687662265740565U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4259138552009771014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8973051213213726023U;
            aOrbiterJ = RotL64((aOrbiterJ * 12625091476068190979U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17602611840127337490U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8218984546932905269U;
            aOrbiterI = RotL64((aOrbiterI * 17504305273683304231U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18102186122213487888U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2629927500298092976U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6983280164448292723U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2491581597835795234U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9506602492971620955U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9559829640915637163U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13422942713680612924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15037354693234876601U;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 12896066842192894694U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2202952306291905855U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6779368532763429997U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12160313482450599313U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10812986281270407756U;
            aOrbiterH = RotL64((aOrbiterH * 7786608700746771809U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12474638293190144525U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5882870951276225224U;
            aOrbiterB = RotL64((aOrbiterB * 15532427302173572457U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3782896138051179209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10965680631059882311U;
            aOrbiterK = RotL64((aOrbiterK * 14060923998307082385U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 18U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 10U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 34U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererD, 50U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26266U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 26708U)) & W_KEY1], 44U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24774U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((aIndex + 27223U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27264U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24899U)) & S_BLOCK1], 36U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26527U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25582U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 52U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 43U)) + 10805654776556844351U;
            aOrbiterC = (aWandererC + RotL64(aCross, 51U)) + 582794182442795335U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 43U)) + 2858343650974681068U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 8189584049022064284U;
            aOrbiterK = (aWandererF + RotL64(aCross, 5U)) + 1565100751996962893U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 47U)) + 8062028016947611891U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 57U)) + 8280504280578451745U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 29U)) + 11326869194491655350U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 14U)) + RotL64(aCarry, 13U)) + 1671695656567777163U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2349843105293943452U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13015545152052004254U;
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 16703354404749291869U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11118401674497783533U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14857556493734710364U;
            aOrbiterH = RotL64((aOrbiterH * 3452566050389715195U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12953419670951660965U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 12666121730825089017U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14049925256934142519U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11075249639473053423U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9374217688244187867U;
            aOrbiterD = RotL64((aOrbiterD * 5261156325627117877U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17608340953291367867U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13159437499327086340U;
            aOrbiterF = RotL64((aOrbiterF * 4882100944453534805U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4304700511322366815U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10172544755256706767U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4013006212154771797U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17340067939877432472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14130447570008179105U;
            aOrbiterE = RotL64((aOrbiterE * 8178075071208718915U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2652532710498072378U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10384945384238518296U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17137694272394304045U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 37U));
            aWandererA = aWandererA + ((RotL64(aIngress, 36U) + aOrbiterK) + RotL64(aOrbiterG, 18U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterF, 22U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 52U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29084U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 27433U)) & S_BLOCK1], 60U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29217U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29914U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28717U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29536U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28408U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29071U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 12632404972795375757U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 5351879979055988456U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 57U)) + 3597737727467443413U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 51U)) + 2830846754917852318U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 18U)) + 17311925960294518018U;
            aOrbiterF = (aWandererI + RotL64(aCross, 43U)) + 2083584640523695383U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 15049343611387010158U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 35U)) + 6443050378205811147U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 30U)) + 6021965178697344070U) + aPhaseDOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5080289878758029976U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 576927745306972983U;
            aOrbiterH = RotL64((aOrbiterH * 16008958833683246115U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4728489691382690859U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 6184355840165758855U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1515043910404156423U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11220539885798595450U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 11091438724966718214U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8225347114759391961U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17184210490020062419U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 2150997767099116408U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8058553821648892499U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 7021953562676903717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17159676348343312834U;
            aOrbiterK = RotL64((aOrbiterK * 13877284519668483549U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10367891770525239784U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11922478487264201233U;
            aOrbiterJ = RotL64((aOrbiterJ * 9195137452661956029U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17815162358981720634U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9582631251085100284U;
            aOrbiterA = RotL64((aOrbiterA * 11838992994130850483U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 872593750259572264U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17832330100262167302U;
            aOrbiterC = RotL64((aOrbiterC * 1114416841510028467U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16601139856969287418U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14931287111691324985U;
            aOrbiterG = RotL64((aOrbiterG * 16757174577841001179U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 42U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 36U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterK, 11U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31527U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32137U)) & W_KEY1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32418U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32324U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30826U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 30782U)) & W_KEY1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 37U)) + (RotL64(aCarry, 18U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 15383045568644941552U;
            aOrbiterA = (aWandererC + RotL64(aCross, 37U)) + 17452811657750910067U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 15660117718455155603U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 42U)) + RotL64(aCarry, 35U)) + 10396441207743665753U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 51U)) + 3708971058200841442U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 19U)) + 7000673057768598750U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 57U)) + 9886354469011131596U;
            aOrbiterD = (aWandererI + RotL64(aCross, 14U)) + 16018065329058043467U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 5024756166109352320U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6587818720728886652U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3652672354944162319U;
            aOrbiterI = RotL64((aOrbiterI * 10807121230791716109U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6307315649915348048U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16405347331742979258U;
            aOrbiterA = RotL64((aOrbiterA * 7183142442906743699U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5427299664054601957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterC = RotL64((aOrbiterC * 14646556236306407673U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10182995521328377487U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8694282877540593550U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14614602561910403893U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6966742100601433005U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9920952446921247521U;
            aOrbiterJ = RotL64((aOrbiterJ * 1879821050131820933U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11958734477518336014U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2058335903640404380U;
            aOrbiterF = RotL64((aOrbiterF * 6986170159285417789U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 77366119537297816U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12072894199692855000U;
            aOrbiterD = RotL64((aOrbiterD * 9083781120514635987U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11874297832446385377U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13715562531763053196U;
            aOrbiterG = RotL64((aOrbiterG * 12822488258322963187U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 18U));
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterH, 23U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 14U)) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4573U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 195U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 433U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3089U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4903U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 5U)) + 6771552164800695068U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 21U)) + 12131763371571322040U;
            aOrbiterA = (aWandererF + RotL64(aCross, 27U)) + 3326182381395522013U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 52U)) + 12288775097697156383U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 5195948373449796741U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 14404044002250137144U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 11142382920035825426U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2967149520256475485U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1470907369577818097U;
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9231668148004163910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13078929163913892386U;
            aOrbiterE = RotL64((aOrbiterE * 7509829068700523627U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9485274692075657877U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12216951187543631673U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6571066246507310805U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6933334652581744234U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17260276102423580920U;
            aOrbiterH = RotL64((aOrbiterH * 7796879893790990605U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 387767848169714392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8597538259308082638U;
            aOrbiterD = RotL64((aOrbiterD * 4888054690557707241U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7996708724489146033U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15357384191688149939U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9827691726832491373U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17739222908739454637U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1614322333281471170U;
            aOrbiterI = RotL64((aOrbiterI * 7063116837752240891U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 36U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterB, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 22U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aInvestLaneC, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8492U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 5584U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6547U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7056U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 6621U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 2915859148137000694U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 210680583721444425U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 6668118118775650387U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 5U)) + 15794200818099010989U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 43U)) + 6565076707062828369U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aIngress, 11U)) + 16323164497808856719U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 51U)) + 7965435318816716560U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7390281030573369017U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2269738866911824875U;
            aOrbiterE = RotL64((aOrbiterE * 1198697877998135567U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9664014216039993873U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18284857398028357633U;
            aOrbiterD = RotL64((aOrbiterD * 8402008251343393737U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 367667619795303009U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7935945060956274197U;
            aOrbiterB = RotL64((aOrbiterB * 5481786693511955209U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16683666162337789540U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10655658270998102390U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15231596813382239841U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8307037916581540297U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3247742749860703524U;
            aOrbiterH = RotL64((aOrbiterH * 15052136713218656641U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10446792483683818139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16374602929344972364U;
            aOrbiterK = RotL64((aOrbiterK * 12599903932725787599U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2411334498322777183U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1093701164116833765U;
            aOrbiterI = RotL64((aOrbiterI * 13129220206835381729U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterI, 46U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15291U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 15073U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 14577U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16370U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11711U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12831U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 12029393034357490020U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 29U)) + 4526754731580694987U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 17060419646421271853U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 21U)) + 4128488893837059683U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 5U)) + 12706894827547160110U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 12506324593645825056U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 57U)) + 12581344490649250025U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14357032418199130132U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15341977701796331249U;
            aOrbiterF = RotL64((aOrbiterF * 6332369248718076031U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7086602307544733241U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 12398300065276832486U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18157408831225635333U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2499745046076601988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7249361592814001829U;
            aOrbiterH = RotL64((aOrbiterH * 14597139848072319685U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3254456186337366437U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3472973415969046680U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14583566953969168353U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7905718972111691591U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15941413652144021522U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3473779492962783565U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10583964125960308762U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13659925272340853715U;
            aOrbiterB = RotL64((aOrbiterB * 16708294803316630743U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9487054537489454887U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13287757570441887517U;
            aOrbiterG = RotL64((aOrbiterG * 17351439045329892107U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 50U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 54U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI + (((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16940U)) & S_BLOCK1], 10U) ^ RotL64(aInvestLaneC[((aIndex + 21052U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19189U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20560U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16769U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17193U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 27U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + 4970414922752555648U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 9462756592787669327U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 3948790686662213095U) + aPhaseEOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 35U)) + 14542857212241578311U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 3387479009827029547U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 1411421370057797877U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 3U)) + 16894451466895681236U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12727136462290223542U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4625389198191960525U;
            aOrbiterK = RotL64((aOrbiterK * 5726474430977810191U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3471881403786164913U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 6433115856048534831U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9363233870194144053U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9825592965466157982U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1553125767261293088U;
            aOrbiterE = RotL64((aOrbiterE * 411535191177308781U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9951616357109647617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11231080382787286889U;
            aOrbiterF = RotL64((aOrbiterF * 14024961994986659187U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13419663264017317947U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4835055642466215566U;
            aOrbiterI = RotL64((aOrbiterI * 17898065852351759171U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14558747666410946768U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13120938960926874504U;
            aOrbiterC = RotL64((aOrbiterC * 5681766019285559739U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11910501376797343986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15074100100781785300U;
            aOrbiterA = RotL64((aOrbiterA * 228976960937473851U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterK, 21U)) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 14U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26131U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 25136U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22961U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26912U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23127U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 22876U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 40U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 10038936806177516123U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 53U)) + 1773168435195292638U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 10655711161526628072U;
            aOrbiterE = (aWandererD + RotL64(aCross, 19U)) + 14422295664639740437U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 37U)) + 4125228715513159576U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 3U)) + 3670449653158650845U) + aPhaseEOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 17553727567180813057U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5111401772713882743U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7688573124662314413U;
            aOrbiterG = RotL64((aOrbiterG * 10846442063022821393U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9438375825507814395U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14177477039902118886U;
            aOrbiterH = RotL64((aOrbiterH * 6467406626985022537U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16329942595859623928U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3990536794006836672U;
            aOrbiterI = RotL64((aOrbiterI * 579024714339065373U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5072881436583180756U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16789727877867289997U;
            aOrbiterA = RotL64((aOrbiterA * 8766246302636197905U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17313956922306689438U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11530878396329822041U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11356860047841383129U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3612616532321160196U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4172189825359187763U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12938945495299393177U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 8677279703778052804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1912172980909479362U;
            aOrbiterD = RotL64((aOrbiterD * 10053289257955474143U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 22U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 46U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31112U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 30993U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 27859U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28809U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28277U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 27972U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 57U)) + (RotL64(aPrevious, 44U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 53U)) + 3561491146322798260U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 29U)) + 7075025056181885339U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 60U)) + 9230910887904171613U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 19U)) + 4119781172609908917U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 17155609083870983149U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 2423018561430181695U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 12957280305617615744U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2461704174772065813U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7907123257849391997U;
            aOrbiterE = RotL64((aOrbiterE * 9416171962847312179U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7257868138318960007U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16425903703085702285U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7996935869077231999U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2990822664594079467U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5654819006718953817U;
            aOrbiterA = RotL64((aOrbiterA * 4465096036756887801U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12183676471235678779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15026286960542123922U;
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12169080607071830522U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2906296852254787499U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6754514406846040163U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3029858695410344584U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14406410317495954566U;
            aOrbiterC = RotL64((aOrbiterC * 9663780721657983421U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11048818178401163861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13622063920319445043U;
            aOrbiterH = RotL64((aOrbiterH * 2516025554421589857U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 6U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneA, aInvestLaneD, aExpandLaneB, aSnowLaneB, aExpandLaneC, aWorkLaneA, aExpandLaneD, aWorkLaneB, aInvestLaneB, aWorkLaneC, aInvestLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1371U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 2180U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 979U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3893U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 878U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2109U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 39U)) + 6068543441070417854U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 3U)) + 2995980468193441856U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 50U)) + 18020277482171594003U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 41U)) + 4293807434721230702U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 7980599111583893156U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 8593141111851052016U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 21U)) + 5903487523900084325U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 15112035513447930209U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 23U)) + 9854037263057006439U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 19U)) + 16759760289688823193U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 47U)) + 12622628933030601390U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1264668857268123425U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16302812053619101593U;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16087995784896123610U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7970269262800468363U;
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5331477046030959632U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16534913204255550893U;
            aOrbiterD = RotL64((aOrbiterD * 1013433634373673565U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11042821902537871209U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8069677512345031660U;
            aOrbiterA = RotL64((aOrbiterA * 13622218526054132397U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5737130058129936372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1076627182956662997U;
            aOrbiterE = RotL64((aOrbiterE * 14342191224014199929U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13911061091801078190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15397603151098990373U;
            aOrbiterG = RotL64((aOrbiterG * 1802890451633592245U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15137326716738637972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11248737008959896786U;
            aOrbiterC = RotL64((aOrbiterC * 90789374131547005U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1847847987633923657U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10560748778679145431U;
            aOrbiterB = RotL64((aOrbiterB * 2919333327817231099U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2703726238610290251U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12950671360471467310U;
            aOrbiterJ = RotL64((aOrbiterJ * 7490327691501537047U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10331504168520449467U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1541527607705280906U;
            aOrbiterK = RotL64((aOrbiterK * 14197400812600186171U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9135056476214341809U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6068543441070417854U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14102524444094948875U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 24U)) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererG = aWandererG + ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 10U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10350U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 8793U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10167U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6704U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8770U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9531U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6790U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 13U)) + 9435962834163239322U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 3U)) + 10524704356081318973U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 7403401305665208680U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 51U)) + 7525414805023556493U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 27U)) + 1116686470029070951U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + 13257612299137802420U) + aPhaseFOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 9181543003986598283U;
            aOrbiterG = (aWandererE + RotL64(aCross, 47U)) + 9739384852307501107U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 18U)) + 11308402900229016057U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 11U)) + 14935167593705272337U;
            aOrbiterA = (aWandererK + RotL64(aCross, 57U)) + 7171824007631943535U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8068411284829563567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17039236343991574134U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18291683592714999632U;
            aOrbiterC = RotL64((aOrbiterC * 7771718817924840713U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6239616841884430968U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10604527977569876774U;
            aOrbiterG = RotL64((aOrbiterG * 6972820410084939637U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1707724300671717658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3802268808625297647U;
            aOrbiterI = RotL64((aOrbiterI * 11296811630387191563U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9423064323799920219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 242153923313096551U;
            aOrbiterB = RotL64((aOrbiterB * 12117679073775630197U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 945801070951928277U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13094814302414492064U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14638176479878969775U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7572219725951040117U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16494986983782503428U;
            aOrbiterF = RotL64((aOrbiterF * 2739189408707408171U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10949497978229234856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11219643352002119905U;
            aOrbiterD = RotL64((aOrbiterD * 16900635614259262873U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14245670385849499678U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 13771155918235018585U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121731385133220921U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15722734439532828816U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11032710342174118366U;
            aOrbiterK = RotL64((aOrbiterK * 16096465375397981585U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2071496769185495150U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9435962834163239322U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10640995428633266765U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 12U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 60U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 38U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterA, 22U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 44U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneC
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneC forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12643U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 13315U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15066U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12175U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12474U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 14U)) ^ (RotL64(aIngress, 29U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 29U)) + 13481227414590594621U;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 17425964381118918026U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 43U)) + 4792004356135956581U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 3U)) + 11926849936000639098U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 990697329347742142U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 13U)) + 9307721505373076588U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 38U)) + 17605732738841908719U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 21U)) + 13110764518634187439U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 11U)) + 17970109897810645911U;
            aOrbiterF = (aWandererB + RotL64(aCross, 41U)) + 10273133817644703654U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 37U)) + 11239046688920468137U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8355821483275763145U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15522151127786049345U;
            aOrbiterJ = RotL64((aOrbiterJ * 4844278537850520413U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5381663179722418112U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 9551368011768104906U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16264476585232221270U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7721417776432288282U;
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 339418090653475277U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3247926250495935511U;
            aOrbiterK = RotL64((aOrbiterK * 16824669543765729097U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3390560045236418590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3894024951542543635U;
            aOrbiterA = RotL64((aOrbiterA * 10599637790900418767U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3878539166189668154U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5617705593218220843U;
            aOrbiterF = RotL64((aOrbiterF * 82771190372750823U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12320861089148474544U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14943790251625519550U;
            aOrbiterG = RotL64((aOrbiterG * 13758322022902008313U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 18119213517612562775U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1413193144229486646U;
            aOrbiterH = RotL64((aOrbiterH * 14562375280658115687U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14810150213456844196U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8468712395797520201U;
            aOrbiterE = RotL64((aOrbiterE * 8167911669632436949U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13501570100536254566U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15409772061478100850U;
            aOrbiterB = RotL64((aOrbiterB * 955182899606655851U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8621805947309982779U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13481227414590594621U;
            aOrbiterC = RotL64((aOrbiterC * 9591362493722704105U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 4U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterI, 29U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterB, 24U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererK = aWandererK + ((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterF, 36U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 34U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17462U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((aIndex + 16647U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 20056U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20260U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17062U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 3U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 56U)) + 18255347001097480328U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 23U)) + 13679246790311505735U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 10565839529765027116U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 19U)) + 14327172566224769901U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 16239024612038195174U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 27U)) + 13800012174212131890U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 60U)) + 13900288860157577583U) + aPhaseFOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 47U)) + 4144386119777112740U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 41U)) + 3154558262670631372U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 7456728543137614001U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 11709519851158935384U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15607438907832240304U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9276575329661725624U;
            aOrbiterC = RotL64((aOrbiterC * 8879744070762412745U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6459435969129449226U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6442382118416542275U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 12117432107282150865U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 6831279293184793243U;
            aOrbiterA = RotL64((aOrbiterA * 2435360641135249073U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9520022957804572889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8322178689474588679U;
            aOrbiterJ = RotL64((aOrbiterJ * 1627707191467537115U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4162401591586869316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8994015844714895961U;
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10038095909727959633U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17756404450592957616U;
            aOrbiterG = RotL64((aOrbiterG * 14255952184627347295U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3379089265413427719U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11341713098678108441U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2500587373161411961U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4030296130743454165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6332387792111212064U;
            aOrbiterD = RotL64((aOrbiterD * 16490982218150897861U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14893209417387662133U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9265457389326311687U;
            aOrbiterK = RotL64((aOrbiterK * 9778404505547862689U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13496086915199406901U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14576555328710787951U;
            aOrbiterE = RotL64((aOrbiterE * 13155395071667672943U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11482324648071976743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18255347001097480328U;
            aOrbiterF = RotL64((aOrbiterF * 10918514878283385643U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 44U) + RotL64(aOrbiterA, 48U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterH, 30U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneB
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26321U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 23371U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 26037U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27255U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 23334U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 27U)) + 13296600294247799698U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 11U)) + 5818503518080877515U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 39U)) + 6735784238734173597U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 7368398209488856201U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 961734029066455638U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 797011946660892011U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 12841876018396622350U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 29U)) + 16213253970483895623U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 11U)) + 15186950557113470375U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 23U)) + 5117930310827477341U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 54U)) + 12265429373166094162U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13920531346698601568U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14695405206998211456U;
            aOrbiterK = RotL64((aOrbiterK * 13950964363414164279U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7851960904825938443U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9501511171732550190U;
            aOrbiterH = RotL64((aOrbiterH * 5614164120361489613U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5663365182245722077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18171052650586819280U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3442698321538580861U;
            aOrbiterI = RotL64((aOrbiterI * 6317525514963824829U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1491052813469258970U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3956599824067616133U;
            aOrbiterJ = RotL64((aOrbiterJ * 2928600779267623085U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10963841237346073453U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2303020125591252534U;
            aOrbiterA = RotL64((aOrbiterA * 9969099842343321981U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14503856057958162356U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11147548150090597694U;
            aOrbiterD = RotL64((aOrbiterD * 11856382308792700441U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9191681438318311481U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13556072770381999852U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18316231099054203683U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10103207278550444685U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10415809965217261104U;
            aOrbiterE = RotL64((aOrbiterE * 16562732599511350217U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17435033201864058457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5540494424887364682U;
            aOrbiterC = RotL64((aOrbiterC * 18230910315317249045U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18020151683897013854U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13296600294247799698U;
            aOrbiterF = RotL64((aOrbiterF * 10000194329456668845U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterE, 10U));
            aWandererH = aWandererH + ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 14U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 21U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30178U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 30108U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 28320U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27491U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29552U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aPrevious, 34U)) + 12669015908335980355U;
            aOrbiterD = (aWandererF + RotL64(aCross, 13U)) + 5438715179868613192U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 39U)) + 13172104448184536460U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 19U)) + 13421421503244744803U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 37U)) + 13327113302994856582U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 4671768205922454413U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 5355759962838579929U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 6691720614265406851U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 56U)) + 7063906424700911378U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 5U)) + 17328616394166672263U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 53U)) + 1542940602574207068U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7203866278803132454U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 993485696233139264U;
            aOrbiterG = RotL64((aOrbiterG * 11609009908810366447U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15659679028507488331U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18321361454094675842U;
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9633319822696783352U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 3496559332232402963U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7772060229838162977U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1918349708324205526U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7701088402761359134U;
            aOrbiterE = RotL64((aOrbiterE * 9649485438465644795U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6006824348814439686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 18088375375347012557U;
            aOrbiterJ = RotL64((aOrbiterJ * 12801082943086128385U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12816533373478543584U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17951880253818836433U;
            aOrbiterB = RotL64((aOrbiterB * 8935839101517220201U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11311632024372748238U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9891349164779752351U;
            aOrbiterC = RotL64((aOrbiterC * 11405973752233193209U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 711130292000437038U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17818800917771709681U;
            aOrbiterA = RotL64((aOrbiterA * 10567029732245868263U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10188714200240109442U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 9745615081760948652U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9321909462220134035U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6508703788527163965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7536038073603467381U;
            aOrbiterH = RotL64((aOrbiterH * 12015514242701199813U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2793951597846756844U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12669015908335980355U;
            aOrbiterK = RotL64((aOrbiterK * 7355285540199760689U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterC, 54U)) + aOrbiterI) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 41U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterI, 35U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + RotL64(aOrbiterJ, 39U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 21U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterG, 58U));
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
        // ingress from: aWorkLaneA, aWorkLaneB, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7223U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 6631U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 4442U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3632U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3594U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 820U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 9220392006207660113U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 27U)) + 11305018553489132882U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 5860373868073513684U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 4U)) + 12319586170883987589U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 14072333614354649021U) + aPhaseGOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9332158529453194608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3860569321145958686U;
            aOrbiterK = RotL64((aOrbiterK * 907977527866467591U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8119005668901240093U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13918259792880333239U;
            aOrbiterE = RotL64((aOrbiterE * 5441062406822088853U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6938856216758228704U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3960905839118710604U;
            aOrbiterB = RotL64((aOrbiterB * 16203746868670689793U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6043879193734253929U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15691425268831319195U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7189195135654636271U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14912209933584715274U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16180183395910618923U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3942858974766467849U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 56U) + aOrbiterB) + RotL64(aOrbiterF, 52U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 19U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 44U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11012U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((aIndex + 15771U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 8721U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9901U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8772U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10454U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 2571116506511057880U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 27U)) + 13112435411509707292U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 10403251762787357256U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 27U)) + 8461951095541400405U) + aPhaseGOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 19U)) + 9890793478557463815U) + aPhaseGOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3030229465991783707U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7273848154043719247U;
            aOrbiterK = RotL64((aOrbiterK * 17562254601517935669U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10681774862516028276U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7105082755586853104U;
            aOrbiterE = RotL64((aOrbiterE * 12217705329504230357U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6588579345319551129U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14616333550242386092U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2934574715879306337U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15439666290229654921U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 3360304356760164799U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5164191920584106237U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 14438730801970761889U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14515616787452085729U;
            aOrbiterG = RotL64((aOrbiterG * 2041601927968559821U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterG, 48U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 17494U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 23925U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 21502U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17719U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19041U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23167U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 21U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aScatter, 47U)) + 8866844335448071821U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 10U)) + RotL64(aCarry, 3U)) + 15159698739856430085U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 9582805772989594633U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 1438538239931588373U) + aPhaseGOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 57U)) + 10862044156620436139U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13682173320058164615U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8351013291045977592U;
            aOrbiterB = RotL64((aOrbiterB * 5722336275651615473U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15777857431516633916U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16178966745333885377U;
            aOrbiterI = RotL64((aOrbiterI * 7545129923202147703U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9031889187993001617U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6308472367425865347U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17118710301967158153U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 642109145903321046U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9186268569255318035U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10714674348507516749U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6091345356803675860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13218507921880873749U;
            aOrbiterH = RotL64((aOrbiterH * 15415157927185637717U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 40U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31527U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 26883U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30081U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27614U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31475U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25669U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 11U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 21U)) + 6243113109470883144U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 3891552123999605832U) + aPhaseGOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aScatter, 47U)) + 8758797898587019128U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 1005891374086408851U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 3713426782180050764U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18358143862391573534U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17504394029693712404U;
            aOrbiterC = RotL64((aOrbiterC * 3391716204095092531U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5312729289027417014U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2560873623431186029U;
            aOrbiterB = RotL64((aOrbiterB * 16843728573219210173U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16309322822806704211U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 10195513918020652600U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14569219741824123715U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2552116263258744287U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7732784879810980089U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15041929399477790999U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16499127570665381507U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10890036715535519036U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9065115450010475187U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterF, 58U)) + aPhaseGWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererK, 38U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2786U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 7605U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5547U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3532U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7510U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 289U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 7722279280863371124U) + aPhaseHOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 58U)) + 11584220561732385598U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 21U)) + 7834679350105534657U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 11347994382444180879U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 9449903188047063431U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6516243976652795170U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8420815253991184777U;
            aOrbiterI = RotL64((aOrbiterI * 1358649408967265415U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9081386852515170937U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14375955191735286867U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2772840314542262283U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 880757589768436072U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3349856625725164229U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 681514212582331781U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7826309957607577207U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8057435761214313635U;
            aOrbiterG = RotL64((aOrbiterG * 4718430712767038607U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9565237500443303103U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterE = RotL64((aOrbiterE * 8457633439171452397U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterI, 4U)) + aPhaseHWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererI, 4U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11155U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 15983U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9939U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15606U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16094U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 13908U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 3U)) + 3248574644570178787U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 4506961512959200024U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 8423739774540738590U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 6593975869641735337U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 34U)) + 16441716090557369103U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7936601450453207914U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13333752583560167065U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5389149472324384311U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8013703284795432973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2349852779887439236U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2422888500648100783U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5318539364763284138U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11450957608502944376U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1957880366707810635U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9058992558327552687U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 632095686920230926U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14734218428913777098U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16344357661370784442U;
            aOrbiterA = RotL64((aOrbiterA * 15049472842002138369U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 38U)) + aPhaseHWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererC, 38U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19520U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 19847U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 20863U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22853U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22542U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 18983U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 52U)) + 11700815697312060726U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 11808423452327465441U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 13U)) + 8670503858631730886U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 2400061067991988544U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 16163118178366229686U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3280178595904941068U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3298683600817047727U;
            aOrbiterC = RotL64((aOrbiterC * 9865649058799255343U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16321624053445183574U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6730229877611375225U;
            aOrbiterK = RotL64((aOrbiterK * 2022290495153519279U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10162830636713641322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15646771327759599256U;
            aOrbiterD = RotL64((aOrbiterD * 15333053762177144775U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14841751262270544102U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9545541117228834895U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11529769874752969377U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14676615635857599982U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1231768638470558855U;
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 38U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 46U)) + aOrbiterC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26930U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 26805U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 24820U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27223U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27694U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26759U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 12809562813316740345U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 46U)) + 16074921689983846769U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 37U)) + 14027986153007120145U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 7633455951809250227U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 340989348513370174U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5307820377645020116U;
            aOrbiterK = RotL64((aOrbiterK * 8402492604131262157U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5605285015771527274U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5293500434746182790U;
            aOrbiterB = RotL64((aOrbiterB * 17674669610895537063U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7263156475892261811U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10672879570907433005U;
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16659226780900986107U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9774892622769850665U;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10728057184108279042U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5032485856947407217U;
            aOrbiterI = RotL64((aOrbiterI * 16651577903809154285U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 60U)) + aOrbiterK) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 42U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
