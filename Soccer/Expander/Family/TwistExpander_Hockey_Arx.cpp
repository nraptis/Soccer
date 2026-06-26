#include "TwistExpander_Hockey_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Hockey_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD14A554288B6A23DULL + 0xA44943491E5C28C2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF413C1B377F096A1ULL + 0xE9719776545802FAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x868190F9919CC08BULL + 0xA433EF3799CCA996ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEF046D0A1F40E743ULL + 0xC9C4966401C43D80ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC7D2E4D4C260E551ULL + 0x848CD8AB0531A8DDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE18FDCC9E693B4A3ULL + 0x8C831F48409FB4A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC0525DB1DC08AF45ULL + 0xC8C85D984078A4D7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCED60B9789CC0D1BULL + 0xF8853934F9E39BB9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9DB29A4B7622D483ULL + 0xC3814F0380996B39ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE95A651AA19DA7C5ULL + 0xED8159EFB6FFEE25ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE2D6F75465EAE1B1ULL + 0xFFDB40712C6970CFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB95580DDA60AC445ULL + 0xCA06B63D87F357E8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC5EC21A919AEE9AFULL + 0x8FEC02D2718C1D6BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB77199D4A99FA721ULL + 0xECA55A7564811B65ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE9EB015C39CA9E6BULL + 0xF42513F6DB553169ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA3251A5C29B964B9ULL + 0xEFE4D261811A9B1BULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3724U)) & S_BLOCK1], 35U) ^ RotL64(pSnow[((aIndex + 3308U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 24U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3922U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 11U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 47U)) + 9471546960258473684U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 18050235435948942244U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 3005107102671544641U;
            aOrbiterD = (aWandererD + RotL64(aCross, 43U)) + 17898396434573801850U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 3U)) + 15071602525497771648U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 5780119462702672108U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 60U)) + 13301326224151025687U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 18129323022260575961U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 21U)) + 1199228670638790709U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 39U)) + 1839199978088021020U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aScatter, 56U)) + 4999517042246790165U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8788607633376516299U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15143903839930468749U;
            aOrbiterE = RotL64((aOrbiterE * 12735914889325422675U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16674732686428431869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15908873150953195581U;
            aOrbiterA = RotL64((aOrbiterA * 18049755517524334107U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11204775359756474667U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2525984309543939465U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 3988529812023791571U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4566345170476825512U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14876612901557406267U;
            aOrbiterD = RotL64((aOrbiterD * 9047956948845135339U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14926290877038883931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12710203178186614846U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14841163494801662515U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7315094513967387996U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11050116830482816766U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 3702999495721152019U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4505368486032503953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17905748055257551092U;
            aOrbiterB = RotL64((aOrbiterB * 14775870175093453197U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5728886950801376350U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17998141690182325170U;
            aOrbiterG = RotL64((aOrbiterG * 16008599930125391379U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4325978018819134558U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13526905108565989379U;
            aOrbiterJ = RotL64((aOrbiterJ * 14121321495714166291U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 10597169665474269506U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7500801022830471869U;
            aOrbiterK = RotL64((aOrbiterK * 3702717219742363777U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17063616328548689935U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9471546960258473684U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3029748230803396737U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 26U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterG, 14U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 35U)) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterC, 52U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6967U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 7779U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 9132U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 10677U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 56U)) + 5510690816044082200U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 15967820875033940530U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 539348720848176221U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 15779318183635560817U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 37U)) + 14511058534424187469U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 30U)) + 5811130556873428391U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 21U)) + 1085928476499444025U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 53U)) + 6973335316600768130U) + aNonceWordB;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 35U)) + 10747243745475009744U) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aCross, 39U)) + 1072260008981349754U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 2018772405352495753U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1092091597048996547U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 15103140149542167197U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 621856991658027989U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13194619321108681542U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16749188603268621850U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 9575408950550922039U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7427959503086895166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9895804051379551393U;
            aOrbiterC = RotL64((aOrbiterC * 2701997336201570715U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4526020800679774259U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4484850928870048176U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17556987520625677313U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1837404844299040155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15213208978489570694U;
            aOrbiterF = RotL64((aOrbiterF * 7062740584650274133U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9615231781751396800U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15872192167825648096U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2900526493682580729U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12530672039655918903U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10617836782870315804U;
            aOrbiterI = RotL64((aOrbiterI * 9716778004909794973U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 550750725406860977U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3498554352021622907U;
            aOrbiterG = RotL64((aOrbiterG * 9846933294851238495U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4059346317776216057U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14161853870874499023U;
            aOrbiterJ = RotL64((aOrbiterJ * 8601560894939097781U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4088411647683253905U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9321241420172776158U;
            aOrbiterH = RotL64((aOrbiterH * 4167888281125330225U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8527337525861632945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5510690816044082200U;
            aOrbiterD = RotL64((aOrbiterD * 12464836001483233379U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 60U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 6U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 48U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13350U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 14785U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11774U)) & S_BLOCK1], 42U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 16378U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 27U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aIngress, 13U)) + 964165145848253292U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 41U)) + 10645976767204934746U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 35U)) + 8241612229349212650U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 5U)) + 4159196033256913347U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 7194795864620233507U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 50U)) + RotL64(aCarry, 35U)) + 7638928444536778384U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 11819105916503968109U) + aNonceWordI;
            aOrbiterC = ((aWandererC + RotL64(aCross, 43U)) + 18052213302858186237U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + 8663575313970041570U) + aNonceWordA;
            aOrbiterH = (aWandererG + RotL64(aIngress, 19U)) + 16644136720439299786U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 52U)) + 16930316530442679864U) + aNonceWordN;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16251107616988250593U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7171986193609401665U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 3543709971414550087U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17885046834432626644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7757069274715713557U;
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2212805322061155615U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6368539134638838822U;
            aOrbiterB = RotL64((aOrbiterB * 13383744883433594259U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5264326094252925613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6126345334815012938U;
            aOrbiterF = RotL64((aOrbiterF * 17180934809764905307U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13826731214018407061U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6621261811613643620U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2823596473596114171U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5964406317285863781U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2167324450276308078U;
            aOrbiterH = RotL64((aOrbiterH * 1098346374733634905U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 16740710162977859724U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8236083581048717923U;
            aOrbiterE = RotL64((aOrbiterE * 4364887787000704039U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13967473987446124012U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5136051802217149813U;
            aOrbiterI = RotL64((aOrbiterI * 13997246005108872883U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5842999397215390366U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 8621394946580065499U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 11658023035736362355U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18086875424872976900U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7429246355923896047U;
            aOrbiterD = RotL64((aOrbiterD * 5077079237334961761U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18123753993386959014U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 964165145848253292U;
            aOrbiterK = RotL64((aOrbiterK * 3178072569980307307U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 54U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterE, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK + (((RotL64(aCross, 46U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 34U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17854U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 21093U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21410U)) & S_BLOCK1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18821U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 8767379393098711499U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 27U)) + 7168159491580816433U) + aNonceWordN;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 6U)) + 9879279829061883406U;
            aOrbiterC = (aWandererI + RotL64(aCross, 39U)) + 10537167136053399303U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 11U)) + 2839070018069188936U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 41U)) + 13844278063968429732U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 11278946626186474646U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 19U)) + 11798425216660557799U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 7618446090703335192U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 35U)) + 695423597006983660U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 14U)) + 14344728202803488813U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11656100506575697086U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10384358779985773937U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 247494692039140973U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17585001605131977341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9964478171465522911U;
            aOrbiterG = RotL64((aOrbiterG * 13484044854790175315U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2710943171829692624U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17809072853457153057U;
            aOrbiterF = RotL64((aOrbiterF * 16341884203303271365U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12814092033910687774U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1743186323268668740U;
            aOrbiterI = RotL64((aOrbiterI * 11150822630624332557U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10750472346626754704U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15925901217078035356U;
            aOrbiterA = RotL64((aOrbiterA * 9276504171291801637U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2569102106359362359U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8868261301410769739U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3662495603133918101U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2143691008373582476U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10606616796243205921U;
            aOrbiterK = RotL64((aOrbiterK * 15794414817813485643U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16258070651850746855U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11720192793689633315U;
            aOrbiterB = RotL64((aOrbiterB * 14475623219460678021U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8230871037292355675U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16898650748046368353U;
            aOrbiterH = RotL64((aOrbiterH * 7368697435476300255U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 9071122174426904737U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4506737259011736474U;
            aOrbiterD = RotL64((aOrbiterD * 11903039808814842447U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4545409671845718259U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8767379393098711499U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 1210632171306946669U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 42U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterI, 58U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterG, 21U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterE, 60U));
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26262U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 22350U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24483U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24607U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 12U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 21U)) + 1866656689936219099U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 19U)) + 2312314528139448289U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 41U)) + 3554037526469185237U;
            aOrbiterA = (aWandererA + RotL64(aCross, 51U)) + 405707755060974111U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 5U)) + 1862976326004007697U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 12992483065443288263U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 14U)) + 3793854946371595197U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 4244007978867369382U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 10280867500312580308U;
            aOrbiterE = (aWandererB + RotL64(aCross, 23U)) + 472563452959164242U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 10U)) + 12041770406895816553U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6118634015704900486U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13637107920449233307U;
            aOrbiterH = RotL64((aOrbiterH * 17712028184714868053U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16673735670669318830U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8602681273646630496U;
            aOrbiterF = RotL64((aOrbiterF * 6995213887710749241U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7683264695930369476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9146674871199188218U;
            aOrbiterI = RotL64((aOrbiterI * 7403427067419261981U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3012935612827493084U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 1259789268731661945U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 2372843620327050137U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5623690455471160780U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18355567776031865462U;
            aOrbiterJ = RotL64((aOrbiterJ * 9553862670107886679U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7705134893833304792U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4435192506444773834U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5249651218395299501U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6204683785806409075U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17886971535016484255U;
            aOrbiterD = RotL64((aOrbiterD * 6047216474762933535U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4430578901091376829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 607557685798141547U;
            aOrbiterK = RotL64((aOrbiterK * 12342665567201483107U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18258994761911545002U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 634391404805006992U;
            aOrbiterC = RotL64((aOrbiterC * 5761143438450180463U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8528044138264666860U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3867692060293315964U;
            aOrbiterB = RotL64((aOrbiterB * 8285164562893231087U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8333438209201978886U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1866656689936219099U;
            aOrbiterG = RotL64((aOrbiterG * 3935928308329865425U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 56U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterK, 53U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 34U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 44U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 40U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29901U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29776U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30804U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29102U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 58U)) + 12131317914288566437U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 29U)) + 5672805657999385496U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 51U)) + 3581710244233124197U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 15251296040538489436U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 11295008604679904153U;
            aOrbiterK = (aWandererE + RotL64(aCross, 35U)) + 2230897493419504490U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 7109600123297458999U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 20U)) + 13119156643107683803U) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 14755160867807355250U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 16829363373287496832U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 11U)) + 16981122946707720883U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8806000776958603317U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16810923047720876014U;
            aOrbiterG = RotL64((aOrbiterG * 17872735050219539145U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8129657889554436328U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8653100378491974463U;
            aOrbiterD = RotL64((aOrbiterD * 11395283153912468661U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17048985838727432415U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10892675550889823573U;
            aOrbiterK = RotL64((aOrbiterK * 976298937314081913U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15960158965421254346U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12290011578634850001U;
            aOrbiterJ = RotL64((aOrbiterJ * 9280475585104357745U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16265047040311479093U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10312956912303656248U;
            aOrbiterI = RotL64((aOrbiterI * 3012584393253845131U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16706890352221352779U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10630955894218491929U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12675937483456206355U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 4009352551041162434U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3043810773683888556U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4328135390387997315U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1398071019814944785U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 16689766557488135301U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 8403881916549404871U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15934647144489136524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13521276033614992223U;
            aOrbiterF = RotL64((aOrbiterF * 18003640895553609933U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4281211055727414100U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11848150507497406421U;
            aOrbiterH = RotL64((aOrbiterH * 1107789990317433481U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12022829841608199449U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12131317914288566437U;
            aOrbiterA = RotL64((aOrbiterA * 13275753083882829973U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterH, 28U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererC = aWandererC + ((RotL64(aIngress, 30U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Hockey_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD673D7EC21A62E35ULL + 0xC6B906993785F998ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x922A6CE8A1527809ULL + 0xFB44FF7751549248ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC0F93EB224910E8DULL + 0x97A37F07406B715BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEB32D67FB9F28B87ULL + 0xD71284FBA40007F1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE4BC3E449A234B5FULL + 0x8BC300959B6E25A4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x944F1FA7635D94DDULL + 0xFA37DAA8A04043B9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE6C910973C4EADE1ULL + 0x9B7D863A4C3136B3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAB9AB1FD5E36F965ULL + 0xCAA02780FA4DAC32ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDD353C8827FA3F49ULL + 0x905A7C6F2318AB43ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDF8566F7E8FE7D23ULL + 0xC4F8F3D67878CBC3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE0A752C583C5FCF9ULL + 0xAC5CA073AA22378BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE2F04B4FB16E8075ULL + 0xE16CC68E136C0864ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xADFC0FD8ADD7FCEBULL + 0xD7CE539B37017058ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x82ACD6BA13A83E09ULL + 0xAE141DA3A9F42680ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9FDDCE1B030D2ED3ULL + 0xE384CFF69ACE24FDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x95B027DB941CC671ULL + 0xE10C0DCD0A3F6A06ULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7374U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 5274U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5215U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 989U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 4U)) + 5088525177670191619U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 13U)) + 9966456257813932112U;
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 7707646574027146307U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 75480203757681173U;
            aOrbiterG = (aWandererH + RotL64(aCross, 53U)) + 384659134071835163U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 3158769775373307778U) + aNonceWordO;
            aOrbiterD = (aWandererF + RotL64(aScatter, 35U)) + 17360830943513941272U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 37U)) + 5317278822721604586U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + 1371427105215954781U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3162710551223553423U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5332921933853550756U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10572462410297815854U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10234389605554817892U;
            aOrbiterB = RotL64((aOrbiterB * 2130374833440291193U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13421365517991380605U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10186643614984034083U;
            aOrbiterH = RotL64((aOrbiterH * 8554471709467808453U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4742438973260817120U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6081590345899008846U;
            aOrbiterC = RotL64((aOrbiterC * 7069396301823124931U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15360092808493795340U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12186413069553132646U;
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16756221656224451552U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12232880965861373143U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14196910735715726471U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10090954323470840557U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15615770271463853537U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13544181592829027283U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 556029032505658411U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13311879111583579039U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 3924744868168749003U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8646360871497847336U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2064833941982069154U;
            aOrbiterG = RotL64((aOrbiterG * 10016546852137913163U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 18U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 12U)) + aOrbiterD) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aIngress, 30U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12553U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 13726U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15575U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 12571U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererJ + RotL64(aIngress, 23U)) + 8367680518550579791U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 11491674725611181241U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + 16673861720782164214U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 3U)) + 9786610124108350855U) + aNonceWordL;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 5745080601557577637U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 1959402215131684684U;
            aOrbiterG = (aWandererD + RotL64(aCross, 29U)) + 6121650036079196522U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 48U)) + 12016309761037342392U;
            aOrbiterK = (aWandererC + RotL64(aCross, 43U)) + 5986936646177049603U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1000367700904043468U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17425288243569101032U;
            aOrbiterD = RotL64((aOrbiterD * 2174614006719048535U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4856917474950325209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 16312111093223166419U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 456110002032422270U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11393724374787795662U;
            aOrbiterG = RotL64((aOrbiterG * 1176984359123668389U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8378176867715697176U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8086186452345234815U;
            aOrbiterE = RotL64((aOrbiterE * 8450438271765985235U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8470349167474173245U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2528229938740192694U;
            aOrbiterK = RotL64((aOrbiterK * 8717790851266520943U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13247168811545753141U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8745293957516815264U;
            aOrbiterB = RotL64((aOrbiterB * 14270617180621072619U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6165915500564961987U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12015407798844173213U;
            aOrbiterJ = RotL64((aOrbiterJ * 3913451986559154153U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 545006684939922156U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16366753936267185001U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6495185976430013201U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 3097605623436091728U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 15950167830259022926U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 4415538963984293323U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 34U) + aOrbiterI) + RotL64(aOrbiterJ, 42U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterG, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterE, 34U));
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17354U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 18251U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19049U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 16770U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 41U)) + 3621877681473089725U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 18U)) + RotL64(aCarry, 21U)) + 4451752751536414717U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 57U)) + 11371625415377772117U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 27U)) + 6046792758881150619U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 8213166120394461682U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 4343156661140422645U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 37U)) + 11105271483234947905U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 46U)) + 348904609985341372U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 23U)) + 12924652822526858767U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7461211697358520287U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16551553555297890558U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16432952324635746293U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11908056404140782995U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9147367258259948715U;
            aOrbiterI = RotL64((aOrbiterI * 10777628928376261667U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8876461054692728610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10546855952702525404U;
            aOrbiterK = RotL64((aOrbiterK * 10071104785895309677U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4748636139110443794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 783046909529525098U;
            aOrbiterD = RotL64((aOrbiterD * 8969157702460927215U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 16683965945838696665U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12385412690177109575U;
            aOrbiterE = RotL64((aOrbiterE * 10795062772707143187U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8210546822184469023U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13146493623236979963U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13199947810161148155U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13857628148804187115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7241297989337473475U;
            aOrbiterH = RotL64((aOrbiterH * 16223448508809614229U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 773904571213804946U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7660676598236419707U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14467390638468925567U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16822672435156055469U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6514707119190640433U;
            aOrbiterF = RotL64((aOrbiterF * 7097496727567460535U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 34U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 18U)) + aOrbiterI) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31523U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 28254U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28883U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29395U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 36U)) + RotL64(aCarry, 13U)) + 16922357079016918108U;
            aOrbiterK = (aWandererE + RotL64(aCross, 5U)) + 11771749797137599131U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 23U)) + 4635668433708036077U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 27U)) + 15827952719230577008U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 1495675306110023086U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 60U)) + 7294835466949728365U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 51U)) + 179122461212041978U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererK + RotL64(aIngress, 19U)) + 545981421632236251U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 15338259639814630535U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12924313840290895215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 17846785921286020610U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18309347016029917133U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5721472794107057875U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16359630793856870319U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14186771515526698907U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10614102110239037308U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16421992251278236531U;
            aOrbiterI = RotL64((aOrbiterI * 2561232904676068089U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8668149834861244963U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12699331834360948734U;
            aOrbiterA = RotL64((aOrbiterA * 2249360824172616357U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4470693178142950471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 526000656022724741U;
            aOrbiterE = RotL64((aOrbiterE * 16688501462334673493U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6880246132270094141U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7126466778855297013U;
            aOrbiterH = RotL64((aOrbiterH * 5692237926830293205U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6436404501390442054U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1213633065612242699U;
            aOrbiterG = RotL64((aOrbiterG * 17604454985534439259U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8186529105901185854U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10607460957358250935U;
            aOrbiterD = RotL64((aOrbiterD * 17172191011625677861U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9743278964993305169U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14007577681873418075U) ^ aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4231122580398039133U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererK = aWandererK + (((((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 3U)) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aIngress, 34U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 29U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 22U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Hockey_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCC4ECD102A2840BDULL + 0xA0513AB25AA863E9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C241CCA3868A691ULL + 0x8F941B89F489B885ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD725645809345C39ULL + 0xAE41738B6A4AA311ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xABAC009FAF8BE06BULL + 0xF8D99727BF0F5C28ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCB69813CB5A0EC21ULL + 0x97A48F122AE2FF71ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x83C3D5D2CFC4376BULL + 0xC9B97318203050DAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD066C76231D24323ULL + 0xC20A2A50C990A999ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCD9B0BBB3F8008CBULL + 0x8BF4FAF92F988B1CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x84CAD35CF196B599ULL + 0xB280103C674DAF31ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x84E9818414A28BFFULL + 0xDE431760FE24D93DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB94EECA9D74B6387ULL + 0xAB76D000C50E0CDCULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE4936729B6B9CB15ULL + 0xF5BDFA6F6A786A53ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBA38F1C5B2661CE7ULL + 0x840CC844278097A9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAF417DA83768396DULL + 0xD232654F0CB3F291ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC5C72F1E65B7B3FDULL + 0xA68070F12D2AB8D5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x857F943FB124BF4DULL + 0xF678BCE7AAB4962BULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6586U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7434U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7862U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 4222U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 60U) ^ RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 16424657151168221875U) + aNonceWordC;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 21U)) + 17150123681886380361U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 13U)) + 16041993588694572757U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 9871185846434828537U) + aNonceWordE;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 37U)) + 11227236398354430757U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5399325217402192631U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9248828789282890454U;
            aOrbiterD = RotL64((aOrbiterD * 6733832755349139621U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9041370494203701062U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14944424084524970764U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 10283363059424655079U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5481938174456671041U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14783648629543752715U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7260164783191886395U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12355573914530445723U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9863991559011968318U;
            aOrbiterE = RotL64((aOrbiterE * 8495251211794343179U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16149688605937250965U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 106041828692026825U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 12199934305374582599U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterG, 10U));
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11510U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9324U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16039U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 14391U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 18319689184146942855U) + aNonceWordP;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 37U)) + 8041304130090501019U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 11347064191990897738U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 15242243470024447468U;
            aOrbiterH = ((((aWandererG + RotL64(aScatter, 10U)) + RotL64(aCarry, 51U)) + 10619749107163611105U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14795614276221947128U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1578095288886372393U;
            aOrbiterJ = RotL64((aOrbiterJ * 9953192041564147241U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13593906305770501684U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8919815528334599172U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2033810402808238127U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17425548324720065145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11125018338392347335U;
            aOrbiterK = RotL64((aOrbiterK * 4377887040461528587U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3779189180734244399U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10958224663276134041U;
            aOrbiterI = RotL64((aOrbiterI * 6206963519509783781U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4317305352561612995U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4891139433808505355U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 40U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16488U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19930U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19559U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19467U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 27U)) + 7632760812370906911U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 6007174525479723089U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 57U)) + 3362829642521821048U) + aNonceWordB;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 18009548556107978286U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 54U)) + 17880909432272697327U) + aNonceWordM;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15961567935420752568U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10136559064656837921U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14473810261421912849U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 17622019364405410277U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6927494824421416306U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 2686290883767829973U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7125170407794874847U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12342273503071032250U;
            aOrbiterJ = RotL64((aOrbiterJ * 867417849555857179U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14997696377476124836U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14874498694181230698U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4026127545746010937U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2549397729130885686U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4217995818662767955U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5525525344485251063U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterH, 57U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32726U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28448U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30020U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27736U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 5131645209694953015U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 51U)) + 12070391048835379854U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + 2604295836242338724U) + aNonceWordA;
            aOrbiterC = ((aWandererK + RotL64(aCross, 23U)) + 14042039029284001596U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 8914654543854559327U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 2185619407969359869U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5187406295103352574U;
            aOrbiterF = RotL64((aOrbiterF * 10497064008152537837U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8022832481290871217U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8783061916740573472U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3309891377744201773U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10711028365596196301U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13387065038269133571U;
            aOrbiterC = RotL64((aOrbiterC * 12444578026365205255U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11187001318931801582U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14191473173276034019U;
            aOrbiterB = RotL64((aOrbiterB * 2491253922434756431U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16207761776716426435U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 9677408414452078760U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 5487303383095129949U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterC, 4U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Hockey_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8A4FF87DA5813977ULL + 0xEB19BEA1B48C39D8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFC2DF09FDAFF941DULL + 0xD4BD8CF9070C66D2ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC0004A3947914213ULL + 0xA343ED8F9F374DC8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x87BE07F68A353CFDULL + 0x93397A0EB88AE221ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8D90388F03D70957ULL + 0x8B6B3CD6336B059DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE7CC76417C0C20C5ULL + 0x8ACF2BD4C3C54106ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE0B1DD7D3EB04339ULL + 0xCB09DC15C2FF1093ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAA1814EE76A77B65ULL + 0xBF011239A5930181ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x851667D83B78D861ULL + 0xD1F03F5D3AC47C20ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC36F8F6E5C0927D9ULL + 0xB00468D42B0A9F30ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85AD8E558545BD3DULL + 0xD9A1A7788C92C1C8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFF9AA35434C1B919ULL + 0xC07109962ADA98AEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9D6F750E5DA4E2CFULL + 0xE30E4CEED0C03E04ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDC0CD153BF6CD519ULL + 0xC81EABCD954BE202ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD2D5456A90141583ULL + 0xD8F7EB3BB55504DCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD8677F5DBA46034FULL + 0xC3ACED966BD79BA7ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4358U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 7377U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6847U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4329U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 51U)) + 4980738603982643969U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 17660278413018470020U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 17598114429859543466U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 60U)) + 10993929335279994739U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 27U)) + 17967203122976322481U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 1872290205549034384U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 21U)) + 16607778671782810797U) + aNonceWordK;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4895226930754394376U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14960359005982301383U;
            aOrbiterJ = RotL64((aOrbiterJ * 8546231310054433721U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9921642352377700630U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 893281964367208693U;
            aOrbiterF = RotL64((aOrbiterF * 2345509157333444217U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8232519988397858732U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4433022122758913407U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 834240393225479419U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12689609831247168353U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 404535388957472176U;
            aOrbiterB = RotL64((aOrbiterB * 14534020545479806593U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3349108201964013155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4386449511297371730U;
            aOrbiterA = RotL64((aOrbiterA * 9596273264321140229U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14314587717949070586U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10923886625271054985U;
            aOrbiterH = RotL64((aOrbiterH * 7838969002623486809U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17634909585329833520U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2021301459918350372U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 20U)) + aOrbiterB) + aNonceWordD);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 44U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13589U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10977U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15471U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10194U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 12U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 13350544654542863236U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 11U)) + 12364346790125404372U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 60U)) + 9738750172849512764U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 3781373837635491421U) + aNonceWordL;
            aOrbiterD = (aWandererI + RotL64(aIngress, 27U)) + 16635020317512702337U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 5383653921676231276U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 43U)) + 10181959815492056493U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10005510924273927017U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9524687662265740565U;
            aOrbiterJ = RotL64((aOrbiterJ * 13687380438646756931U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 4259138552009771014U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8973051213213726023U;
            aOrbiterB = RotL64((aOrbiterB * 12625091476068190979U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17602611840127337490U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 8218984546932905269U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 17504305273683304231U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18102186122213487888U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2629927500298092976U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2491581597835795234U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9506602492971620955U;
            aOrbiterD = RotL64((aOrbiterD * 9559829640915637163U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13422942713680612924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15037354693234876601U;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12896066842192894694U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2202952306291905855U;
            aOrbiterH = RotL64((aOrbiterH * 6779368532763429997U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 58U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 50U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 14U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 41U)) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 5U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordE);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19533U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18756U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21240U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21275U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 37U)) + 13854738573712660276U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aCross, 20U)) + RotL64(aCarry, 51U)) + 16835460633412286294U) + aNonceWordI;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 6785859293758091931U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 126317283127992659U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 7568963536291415413U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 53U)) + 12294016745653004819U) + aNonceWordP;
            aOrbiterA = (aWandererK + RotL64(aCross, 47U)) + 18269588932920281147U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5872406424994751026U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7764434758831474129U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3772146788188420071U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4804168969415573371U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 959601763507651280U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 4647396592804833217U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9257644462479293048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14332699366894494579U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10487012596470786004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 612729229562321440U;
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7845523921295625315U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12742115479740024747U;
            aOrbiterD = RotL64((aOrbiterD * 15578543510683986421U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10294667720904610944U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14369711143154904567U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10918344717497681894U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 18136794828308636957U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 50U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28618U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 29677U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26243U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 32077U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aScatter, 20U)) + RotL64(aCarry, 11U)) + 12669015908335980355U;
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 29U)) + 5438715179868613192U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 13172104448184536460U) + aNonceWordP;
            aOrbiterK = (aWandererK + RotL64(aCross, 3U)) + 13421421503244744803U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 57U)) + 13327113302994856582U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 13U)) + 4671768205922454413U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 35U)) + 5355759962838579929U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6691720614265406851U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7063906424700911378U;
            aOrbiterI = RotL64((aOrbiterI * 17091734375516280675U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17328616394166672263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1542940602574207068U;
            aOrbiterG = RotL64((aOrbiterG * 8981679306319627975U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 7203866278803132454U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 993485696233139264U;
            aOrbiterJ = RotL64((aOrbiterJ * 11609009908810366447U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15659679028507488331U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18321361454094675842U;
            aOrbiterE = RotL64((aOrbiterE * 3966860765622641843U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9633319822696783352U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3496559332232402963U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 7772060229838162977U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1918349708324205526U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 7701088402761359134U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 9649485438465644795U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6006824348814439686U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 18088375375347012557U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12801082943086128385U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterK, 36U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Hockey_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE56FAE3DC01DB625ULL + 0xFB80938CFA9E4C02ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x84BBA017A68B4B91ULL + 0x9C26E277C2B0F12BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEADBCD8A3EC41C75ULL + 0xE29931BF5862ECBFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD7951957E39D2F8FULL + 0xBDF40BD9D0EC696AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9285778D64BADB3DULL + 0xED34E1D707403CA4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x965B3F4AE37D55B9ULL + 0xE6480FA5BDF6A034ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEA16246E24775CADULL + 0xA1442DD4AE5CE6EBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB6F1690C15E51481ULL + 0xBB9DE75B3FCFDE0DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFF80552F29E78943ULL + 0xB76BAED03FEFBA6DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDDE53EFA1C539C3BULL + 0x877BC18386A9DCCEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xAA07218DC0D7890FULL + 0xACF35508CAA572CFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5BC701EB63EC197ULL + 0xD1F1D662FA8B607DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE5A5332D1B8DB1E7ULL + 0xCEFB1C4FD12FF7FBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE2CE31C8C114B43FULL + 0xE24BDA641C23F415ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8B61C5E3C529F4EFULL + 0xB82CD2F6F86F18E8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA276494163BE25DFULL + 0xB1F8C7D323FBD564ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7096U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 2251U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5509U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5234U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 10U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 15383045568644941552U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 14U)) + RotL64(aCarry, 23U)) + 17452811657750910067U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 5U)) + 15660117718455155603U) + aNonceWordM;
            aOrbiterB = ((aWandererC + RotL64(aCross, 29U)) + 10396441207743665753U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 57U)) + 3708971058200841442U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 7000673057768598750U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 35U)) + 9886354469011131596U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16018065329058043467U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5024756166109352320U;
            aOrbiterE = RotL64((aOrbiterE * 11660932185479046483U), 23U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 6587818720728886652U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3652672354944162319U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10807121230791716109U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6307315649915348048U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16405347331742979258U;
            aOrbiterG = RotL64((aOrbiterG * 7183142442906743699U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5427299664054601957U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4983381733483185898U;
            aOrbiterI = RotL64((aOrbiterI * 14646556236306407673U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10182995521328377487U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8694282877540593550U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14614602561910403893U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6966742100601433005U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9920952446921247521U;
            aOrbiterC = RotL64((aOrbiterC * 1879821050131820933U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 28U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 19U)) + aOrbiterC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 35U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 14871U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 16373U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16310U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 14589U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 12136097566601676613U) + aNonceWordC;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 10U)) + 7969431322248040056U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 10530676021510553889U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aCross, 3U)) + 8740777303075445264U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 19U)) + 13249434169895564739U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 27U)) + 15529577005925628472U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 344627093687331562U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8824277416519988893U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5636276438449709875U;
            aOrbiterA = RotL64((aOrbiterA * 222817930773618893U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2079413361031851552U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7807998179168655561U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 961456853699784753U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13589392896232029112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10733011474804473996U;
            aOrbiterK = RotL64((aOrbiterK * 361749145931578805U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 15934162328347805968U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7573511217796245232U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10694563909931636155U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4828475187337891975U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13284974329890393113U;
            aOrbiterI = RotL64((aOrbiterI * 10831075817642374287U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13173869918669643112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15841507674783398167U;
            aOrbiterD = RotL64((aOrbiterD * 15632933198136963277U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14168272451055700516U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 11134471485501999898U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 8019507184494591705U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + aNonceWordP);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterJ, 28U)) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17386U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24236U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17642U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneC[((aIndex + 17107U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aScatter, 29U)) + 14686411261024919129U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + 7514582233957632005U) + aNonceWordO;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 6520710480103365552U) + aNonceWordI;
            aOrbiterE = (aWandererC + RotL64(aCross, 47U)) + 1983621978676188036U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 39U)) + 9003524602590749672U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 6428568234045228995U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 53U)) + 8656552687136446989U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16916248288415922490U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9740237548002535784U;
            aOrbiterH = RotL64((aOrbiterH * 7970729853948983849U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 907561000814618339U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4751108900841197631U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 4545395964730641957U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 167774899400732287U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11907484918310854962U;
            aOrbiterB = RotL64((aOrbiterB * 7213139491146402985U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14910318613649863924U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11394136445442060201U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16175942562693781908U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11022373758481651102U;
            aOrbiterF = RotL64((aOrbiterF * 6836331461393816027U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12548405399045031548U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10850926364556828443U;
            aOrbiterG = RotL64((aOrbiterG * 16231561687709867431U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13391684887911141790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14648937281264822988U;
            aOrbiterC = RotL64((aOrbiterC * 6533299316940026059U), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterI, 5U));
            aWandererA = aWandererA + ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 54U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32488U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29412U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30645U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29615U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 5088525177670191619U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 9966456257813932112U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 4U)) + 7707646574027146307U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 75480203757681173U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 27U)) + 384659134071835163U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 57U)) + 3158769775373307778U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 47U)) + 17360830943513941272U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5317278822721604586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1371427105215954781U;
            aOrbiterE = RotL64((aOrbiterE * 10956603063464438611U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3162710551223553423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5332921933853550756U;
            aOrbiterJ = RotL64((aOrbiterJ * 11709546145149357887U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10572462410297815854U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13421365517991380605U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10186643614984034083U;
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4742438973260817120U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6081590345899008846U;
            aOrbiterI = RotL64((aOrbiterI * 7069396301823124931U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15360092808493795340U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12186413069553132646U;
            aOrbiterF = RotL64((aOrbiterF * 3815981440611914267U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16756221656224451552U) + aNonceWordM;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 12232880965861373143U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 14196910735715726471U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 34U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 50U) + aOrbiterG) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 6U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordA);
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

void TwistExpander_Hockey_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB12D5E22A43ACF8BULL + 0x9D4FC71A718C02D4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD767B6D7D0EBD48FULL + 0xF3F688D31FA06904ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x87749B443A1CF513ULL + 0xB85542C0A9691825ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF7A8E6F80C33EE61ULL + 0x9DF816B5845E5F1BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8603CF06F4BC4203ULL + 0xAF84BCF5ACB87B3DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC22D1AAD5FBC691FULL + 0xFE99D6AF102A3C59ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB04B221A1E19CD5DULL + 0x847EB7227E644203ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC08DA03771760663ULL + 0xD7E0788623337B70ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE58913494F86F52BULL + 0x975930C805A5622EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFE44D194BC858F33ULL + 0x823AED3CC2ABEB4BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9A87E26590B2FC4DULL + 0xA4348C667EF729A0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB612E37BAC206D45ULL + 0xE55509819A92D7C0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA79E44DCA96F5473ULL + 0xB96F8482AB208753ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF9ECB59A37BC1CCBULL + 0xF59A8F47FBD4DAA2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x816BF6FF178F89D5ULL + 0xE7DB84D667C5B774ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCAF8AAFE8EEA6EA3ULL + 0xFB95A12F15237D0EULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1009U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 7462U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2479U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 1537U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 8101351470141807662U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 44U)) + 6965474099521076705U;
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 6803828268885684784U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 13454235922950972488U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + 11678091885751244777U) + aNonceWordO;
            aOrbiterD = (aWandererI + RotL64(aIngress, 13U)) + 5307134544628507141U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 27U)) + 4873703518950429353U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 10U)) + RotL64(aCarry, 53U)) + 8542156221858586039U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 3U)) + 3993726182905296513U;
            aOrbiterG = (aWandererC + RotL64(aCross, 5U)) + 12113047622035464386U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 23U)) + 1944244448665721151U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12914188029425467576U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2486762763475327024U;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14580191602982245481U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12093414832400135066U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13623906997320021065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9977356009806428696U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 2005536391712733499U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3694954095397810851U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11453812627797091638U;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 542311345544726351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3024285045990499484U;
            aOrbiterE = RotL64((aOrbiterE * 5153745952148205645U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15397664082460849530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10716856680110815056U;
            aOrbiterJ = RotL64((aOrbiterJ * 13947203772929252823U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 833342121331428547U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1111339940097269219U;
            aOrbiterA = RotL64((aOrbiterA * 17991642769781175473U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9312963978841402871U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8225496710723213204U;
            aOrbiterI = RotL64((aOrbiterI * 894499195498817065U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7947419530949269753U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5028446114139808517U;
            aOrbiterB = RotL64((aOrbiterB * 5593084899736787263U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9818957208200746975U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17549192719666647522U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4705007748877441833U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16389708540378477737U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8101351470141807662U;
            aOrbiterG = RotL64((aOrbiterG * 9858235486537441981U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 22U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterB, 30U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 6U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterA, 26U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 36U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11596U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12887U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14554U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15276U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 13U)) + 8402620908307642697U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 41U)) + 11347672014525086047U) + aNonceWordA;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 19U)) + 2816462912503401876U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 6940159795470696093U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 27U)) + 9134692490095883851U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 29U)) + 4999455497008026526U) + aNonceWordM;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 58U)) + 5992451460350651332U) + aNonceWordI;
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 3417087346651371924U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 37U)) + 3612773820086198270U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 47U)) + 463398077083428570U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 39U)) + 11249391303705089012U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17027535139825739501U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 568131384979596481U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5683451044852895957U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4793712537158004047U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10415170179135963622U;
            aOrbiterA = RotL64((aOrbiterA * 13729564030210361415U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2391473979460065630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4240058362680064261U;
            aOrbiterH = RotL64((aOrbiterH * 12375884373396400889U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9963957011090031698U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 3325305624067445525U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 3128542681461806309U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2094945647665114693U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10703615640774042674U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 12641986098450423751U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3768738815518590289U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15021301790376706827U;
            aOrbiterI = RotL64((aOrbiterI * 14445850924223550339U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10571246886181608316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5130325144599151793U;
            aOrbiterE = RotL64((aOrbiterE * 3185251943547657467U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8617523421720966373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16574597770835250074U;
            aOrbiterB = RotL64((aOrbiterB * 1759209403428937799U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17474733286551120355U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17914672092861237776U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13657291990878792267U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12856557371623447773U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1636296609747335898U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 9286345529656087313U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12588848560509679821U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8402620908307642697U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2269772223506258147U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 38U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterK, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 26U)) + aOrbiterD) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18288U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 19930U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16833U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23232U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 18U) + RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 57U)) + 9133751643283278896U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 30U)) + RotL64(aCarry, 53U)) + 8971581804375380408U) + aNonceWordI;
            aOrbiterI = (aWandererF + RotL64(aScatter, 19U)) + 12559650383714566592U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + 15753206088872859163U) + aNonceWordM;
            aOrbiterE = (aWandererH + RotL64(aScatter, 5U)) + 7640756270450762350U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 11U)) + 7340073357551376125U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 21U)) + 5270256573644196046U;
            aOrbiterG = (aWandererC + RotL64(aCross, 51U)) + 3567367996479995928U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 54U)) + 11939634537492733738U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aScatter, 23U)) + 7051817732424527120U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 1730487669951837941U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18009252467909454817U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2361024272031696442U;
            aOrbiterI = RotL64((aOrbiterI * 15215151562500226027U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15902755877642960397U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12243517544704116184U;
            aOrbiterJ = RotL64((aOrbiterJ * 2576071074148141447U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 16846181962302186187U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 636121425116506681U;
            aOrbiterH = RotL64((aOrbiterH * 17075030673338779993U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6887385655828217318U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3705834550934775862U;
            aOrbiterE = RotL64((aOrbiterE * 11275428284929594435U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11165142437077969438U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6426659930331618269U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17170640810530893705U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12629082390899315789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 4277510580069574724U;
            aOrbiterD = RotL64((aOrbiterD * 9829125163412708305U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13814834144170469978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3698381854100295826U;
            aOrbiterF = RotL64((aOrbiterF * 5126359230872258015U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11623170635983579937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7247413650388803796U;
            aOrbiterC = RotL64((aOrbiterC * 3403219499465560059U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3129755194359521145U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4081016725582134919U;
            aOrbiterK = RotL64((aOrbiterK * 11564414998539605389U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15878346077922215753U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2974440187796944059U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 783253926537018373U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3922344163443096356U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9133751643283278896U;
            aOrbiterA = RotL64((aOrbiterA * 16887991698415418429U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 29U));
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 34U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterE, 39U)) + aNonceWordK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 52U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30236U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25589U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27477U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27317U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 23U)) + 11998579547770778580U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 57U)) + 8409465187298704610U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 44U)) + 3470222286110333500U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 5U)) + 5704486785203069994U) + aNonceWordM;
            aOrbiterC = ((((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 10334944660253279633U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aWandererC + RotL64(aScatter, 39U)) + 7626852700722567477U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 14631310754943209743U) + aNonceWordF;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 29U)) + 807160297237854120U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 5624154783624196107U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 27U)) + 4971444394698940423U;
            aOrbiterF = (aWandererD + RotL64(aCross, 10U)) + 6340057638461027062U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9003019862787819481U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13632057463595873033U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12766104026871797746U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4062118445824915939U;
            aOrbiterC = RotL64((aOrbiterC * 13130770039048080701U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5258212525426469978U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9956946981015983939U;
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 10837606223056473999U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13292864885504191134U;
            aOrbiterA = RotL64((aOrbiterA * 4445739587553669471U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 166087925900318658U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4411147600413147773U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16888086378070246404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5240855484445974002U;
            aOrbiterB = RotL64((aOrbiterB * 402652898573422271U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6874866669211571608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 732890824978127460U;
            aOrbiterE = RotL64((aOrbiterE * 3776365957702257453U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5541380495707308058U) + aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 17947326584411475765U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 10920952349981652899U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15060679340045767910U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1675974028461383576U;
            aOrbiterK = RotL64((aOrbiterK * 15127962310365242819U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 226889112033170368U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4290719734244011388U;
            aOrbiterJ = RotL64((aOrbiterJ * 6453598182035414143U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7712233480730639084U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11998579547770778580U;
            aOrbiterI = RotL64((aOrbiterI * 11599893373156816375U), 5U);
            //
            aIngress = RotL64(aOrbiterK, 22U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 24U) + aOrbiterF) + RotL64(aOrbiterI, 19U));
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 50U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 5U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 14U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 26U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordE);
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

void TwistExpander_Hockey_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB30DAF3D097C3B71ULL + 0xD94F2136A496A668ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF2C4E9226A67BF91ULL + 0x8011D3CC340D5349ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE8BDA34A59EE203BULL + 0xA9988EA4CDC6D102ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF4FF75EF2EF8F135ULL + 0x8FE6302617BDE990ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x868AD3DAAC7D71F9ULL + 0xF27043D6D2E4277DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE909FEBFEC2BD6C3ULL + 0xAFAB5BEEF63FAF61ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x909FB25C0520AF87ULL + 0xC2963B38E0A1979AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xAEB4EF1E04E375F9ULL + 0x89DDFBF7D470C0BDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB3618A6945E715E1ULL + 0x880F5E56EA2EF592ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAEF9ED5865BF4C29ULL + 0x9CDEFF2DB15DB39BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE29CAA6B0C8C235DULL + 0xDD5F41F0BC16D05EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8258D769E2A77007ULL + 0x963B80B61298B808ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC04E74E34DF1A941ULL + 0x9919034590E6F83CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF321B66B722053FBULL + 0xE0C2EC8774582EC6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB3E81DAAA3D8EF71ULL + 0xC1CCB02600024E9EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x99F96C30568B2B7DULL + 0xB79790E0118A319EULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2573U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneC[((aIndex + 5135U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5350U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2076U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 18180797995100240808U;
            aOrbiterF = (aWandererB + RotL64(aCross, 53U)) + 6585906608223552885U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 37U)) + 14088708930575939855U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 60U)) + 468974153311516044U) + aNonceWordK;
            aOrbiterD = (aWandererF + RotL64(aIngress, 41U)) + 12481951025619894110U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 17227987923860711763U) + aNonceWordA;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 27U)) + 4373962756657477139U) + aNonceWordG;
            aOrbiterC = (((aWandererE + RotL64(aCross, 46U)) + RotL64(aCarry, 47U)) + 2077576476565420951U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 23U)) + 17435011300234663764U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4118039398293246896U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13724716599855216683U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 17556333902751079677U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12391461204689596339U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 9900605191533799627U) ^ aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13553565332531046301U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 972946858824366125U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17247681919694541215U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 2974639094630445643U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15442851427306771601U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7303586227288294037U;
            aOrbiterH = RotL64((aOrbiterH * 15406402525021428799U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12650358753454105119U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 1483710933373510492U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 6531763256577221891U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 18065810162229740788U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2355285311890287611U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1287783821903407734U;
            aOrbiterA = RotL64((aOrbiterA * 8054011680932255985U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9282654686791135654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15488608017745542551U;
            aOrbiterF = RotL64((aOrbiterF * 7858866274035085123U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13296835576073421802U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7127700236018338741U;
            aOrbiterD = RotL64((aOrbiterD * 11246173563106014149U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 56U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterF, 51U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 3U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 60U)) + aOrbiterD) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8089U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((aIndex + 10521U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10082U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 10542U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 26U) + RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 12980104182836602177U) + aNonceWordF;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 3172622203188863995U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 60U)) + 1170974132219980203U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 6035201940965047490U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 3U)) + 18033907118424996722U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + 14604813424800580304U) + aNonceWordB;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 13720232492851066035U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 27U)) + 3902659710585257448U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + 8331560652661619868U) + aNonceWordH;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4485014147538689794U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 168202636924512424U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13711020666131492091U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16227825670092707848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4792781933944671365U;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12636865372722601282U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 18198291399585556632U;
            aOrbiterB = RotL64((aOrbiterB * 18155803890313399795U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3650053185419807206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5897288963905408776U;
            aOrbiterG = RotL64((aOrbiterG * 3706949366974086151U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9922308113622901726U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 13352279749091561510U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4025213180483632557U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14969461950939646117U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10231661776135056651U;
            aOrbiterJ = RotL64((aOrbiterJ * 11284575051455238501U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10621934544068320859U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6029116920305246887U;
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 12887482425168671195U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8351351557123783853U;
            aOrbiterC = RotL64((aOrbiterC * 3839381627914762245U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5405938210926464973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 385145802287899406U;
            aOrbiterF = RotL64((aOrbiterF * 8330751480464271445U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 60U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 5U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 56U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14333U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15918U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12657U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 14272U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 22U)) + RotL64(aCarry, 37U)) + 17668251151213543491U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 16101602509895104517U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 9083915270773304935U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 43U)) + 12810720730318214811U) + aNonceWordA;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 11U)) + 18113428002071925621U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 3U)) + 1582208899354109878U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 56U)) + 4180688104819188154U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 51U)) + 8954598189262820611U) + aNonceWordG;
            aOrbiterI = (aWandererD + RotL64(aScatter, 39U)) + 15360094153175355879U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8383954114668216260U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15626783326234049197U;
            aOrbiterE = RotL64((aOrbiterE * 15058420415480073793U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10609978564404958066U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterF = RotL64((aOrbiterF * 4590620354119899777U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 760077259110786536U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3597338735888033063U;
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4431777844935985157U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10710423172154671296U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10240882795242085185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7826053487019825891U;
            aOrbiterG = RotL64((aOrbiterG * 15053729937684375907U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9418883403715727353U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11507423614799075545U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16189463984557044693U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11545217316421066655U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 617921402135485341U;
            aOrbiterA = RotL64((aOrbiterA * 8182920764965471653U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14456933220749921009U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7990243583564535387U;
            aOrbiterC = RotL64((aOrbiterC * 5994900368027985469U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14023633125757654751U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11319146808574958827U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 13676159969338309307U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 46U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 10U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 34U)) + aOrbiterF) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 52U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19417U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 20319U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18298U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 19929U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 54U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 52U)) + RotL64(aCarry, 13U)) + 6916817163240024692U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 23U)) + 14554930751292077817U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 43U)) + 1098305064484336101U) + aNonceWordA;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 3U)) + 12192821172420471527U) + aNonceWordF;
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 29U)) + 2435134991707318845U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 1896745368738512624U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + 1114996424222923873U) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aCross, 35U)) + 9839135798371512656U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 39U)) + 8037967239603177043U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15185468738487237432U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4912098316394854543U;
            aOrbiterI = RotL64((aOrbiterI * 3072785550384399929U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13142688607850380888U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4507379759608945839U;
            aOrbiterH = RotL64((aOrbiterH * 2989332387754215967U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterH) + 7299006009652289342U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 5390655277207053627U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 10973744708856143715U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6744737023577785725U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15539737698867067285U;
            aOrbiterC = RotL64((aOrbiterC * 4686092035261336911U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 13329866734681377952U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13284937458969166257U;
            aOrbiterF = RotL64((aOrbiterF * 3965985432462699445U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8695002088915702168U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3858059421620839286U;
            aOrbiterE = RotL64((aOrbiterE * 9559783727301092937U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6609163873243179836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9416165620556710540U;
            aOrbiterB = RotL64((aOrbiterB * 240385043740268229U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1578449067529000433U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14309000104419489303U;
            aOrbiterD = RotL64((aOrbiterD * 7599078306153684729U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15785180680737461320U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10099222679918382021U;
            aOrbiterK = RotL64((aOrbiterK * 2012232597046182581U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 46U));
            aWandererC = aWandererC + (((RotL64(aIngress, 46U) + RotL64(aOrbiterD, 27U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 23U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 22U) + RotL64(aOrbiterB, 35U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterE, 58U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26086U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23632U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22929U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23392U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 41U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 4068921616130916949U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 12077715273915151726U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + 16047546802670596833U) + aNonceWordE;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 12U)) + RotL64(aCarry, 13U)) + 9690277462716999763U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 14484814700447992628U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 43U)) + 17089267243053958210U) + aNonceWordI;
            aOrbiterE = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 9138746214446211147U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 5U)) + 10181001536979097045U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 52U)) + 6657458969093373191U) + aNonceWordM;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7515983477876590988U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3039935555863947600U;
            aOrbiterA = RotL64((aOrbiterA * 12511160550780270119U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16209389224740851136U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 725253312098083182U;
            aOrbiterK = RotL64((aOrbiterK * 17535989492095522597U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13307041115748941383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7159572004825238263U;
            aOrbiterB = RotL64((aOrbiterB * 4855009895002398449U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12027236743251643820U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8717826175991286553U;
            aOrbiterC = RotL64((aOrbiterC * 1175614802543098451U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4769096034227659937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11201226563992939616U;
            aOrbiterH = RotL64((aOrbiterH * 15595355978388159931U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17295978531215563256U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11850923890626719833U;
            aOrbiterI = RotL64((aOrbiterI * 3854851059897397075U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14139441565288097706U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 988684899382304485U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11929090869999700891U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6159251276942253175U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 4849529993914550651U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 18240712676783671317U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6679745455842119497U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15838404437552215214U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17357853511591350887U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 6U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterG, 12U)) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 36U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32344U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28893U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27644U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30659U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 29U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + 1898718075389870739U) + aNonceWordG;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 23U)) + 5631794889237247403U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 47U)) + 18219714659484524607U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 58U)) + 15419581386225732921U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 11U)) + 9125575431710198210U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 12205871520544965505U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 43U)) + 7617534300497343422U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 18017579105368135814U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 6U)) + 10693882161946020042U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11669615701700895306U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11045110212889232165U;
            aOrbiterB = RotL64((aOrbiterB * 5965171269273719849U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18019107802806469913U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4899009736070044310U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17412253404253730364U;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4826286251927854181U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4523455921321845084U;
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4132514462154182215U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7164745605985109269U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 14107325508977225261U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6297434295807635654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8813887638672996646U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 17495632530773158201U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11086381278955626084U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5660733992573928887U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 11248164458720777889U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14851044686208609882U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12707776386060264479U;
            aOrbiterA = RotL64((aOrbiterA * 4470919091467313071U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11508023384209716657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11752973809740920034U;
            aOrbiterJ = RotL64((aOrbiterJ * 10212754472298834769U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 26U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 10U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 29U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 43U)) + aOrbiterI) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 56U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 12U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Hockey_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCDB3630B886F6229ULL + 0xD7F93FF55D238965ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFAF10146373412F7ULL + 0xA686C4FA1753AD1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x8C82453466C3D515ULL + 0xE11AC07B9A6833DAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD59BD0045A143DA5ULL + 0xC859E3526B80A716ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xED2DCFFB5F29608FULL + 0xFAC72322792CF954ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCCD061E67C6D5059ULL + 0xF22D41354DDFE1A3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE31DD67EC4BC59FDULL + 0x9F3DD470F9DDE01DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCFA0B1FAA548FA4FULL + 0xB70B86EB5BE15C50ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFF4C9B24EF090CCDULL + 0xA749890BA2C53F4CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA4CDE68CF4B6A3D1ULL + 0xACBC4DB8174F1112ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD3B697D414316273ULL + 0x84179FCB2F88E3D9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA7BA9B7D46521B71ULL + 0xC1ABE8056182A83BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCEC7548064FF1ADFULL + 0xB8A9F3B1A75DE5D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA6F9CA12823BC4EBULL + 0xDD9D4369629C0AF1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8073630D6A4C0615ULL + 0x8523ED8403A10038ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA78681595309C1FDULL + 0xD914D0885FDC3E53ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4087U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 5208U)) & W_KEY1], 12U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1884U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 994U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 20U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 8367680518550579791U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 11491674725611181241U) + aNonceWordG;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 11U)) + 16673861720782164214U) + aPhaseAOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 9786610124108350855U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 5745080601557577637U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aPrevious, 35U)) + 1959402215131684684U;
            aOrbiterE = (aWandererG + RotL64(aCross, 58U)) + 6121650036079196522U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12016309761037342392U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5986936646177049603U;
            aOrbiterH = RotL64((aOrbiterH * 3585650475703294895U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1000367700904043468U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17425288243569101032U;
            aOrbiterD = RotL64((aOrbiterD * 2174614006719048535U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4856917474950325209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16312111093223166419U;
            aOrbiterG = RotL64((aOrbiterG * 11046477664487805241U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 456110002032422270U) + aNonceWordD;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 11393724374787795662U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 1176984359123668389U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8378176867715697176U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8086186452345234815U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8450438271765985235U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8470349167474173245U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2528229938740192694U;
            aOrbiterA = RotL64((aOrbiterA * 8717790851266520943U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13247168811545753141U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8745293957516815264U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14270617180621072619U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 20U);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterJ, 53U)) + aNonceWordP) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5738U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 6790U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7198U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8507U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 50U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 19U)) + 77518479758428414U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 4832061802166300011U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 58U)) + 11695291171006574112U) + aNonceWordH;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 43U)) + 7467412817843260094U) + aNonceWordB;
            aOrbiterA = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 17801484124471154757U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 35U)) + 5555455638503958639U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 5669470540733721606U) + aPhaseAOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3042388456327784163U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2236734925228156691U;
            aOrbiterF = RotL64((aOrbiterF * 10076582424701705531U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14459720401528685450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4814967631216658856U;
            aOrbiterD = RotL64((aOrbiterD * 18288097536171386643U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16950679344449075945U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6262238639302011050U;
            aOrbiterJ = RotL64((aOrbiterJ * 9942659897425088183U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3522256359074996724U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12524717897707074242U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13891759914865623828U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11910250571469028666U;
            aOrbiterA = RotL64((aOrbiterA * 12311343917878428995U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2240189915640314069U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5365912986308810837U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15133972552032469957U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9323732721344489753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterI = RotL64((aOrbiterI * 14659491687401151733U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aPhaseAWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aNonceWordL);
            aWandererG = aWandererG + (((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 11U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterE, 58U));
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14770U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 12217U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13605U)) & W_KEY1], 36U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16173U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 42U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 29U)) + 1364174714924216027U) + aNonceWordE;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 13561796874229506613U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 6U)) + 11845572344206238305U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 41U)) + 15762708240326773763U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 1157119665207900473U) + aNonceWordA;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 6823546624372055260U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 57U)) + 14465564210523945121U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10667464548080807531U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13445737493224316575U;
            aOrbiterF = RotL64((aOrbiterF * 12137295000900795711U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 3009837893785957665U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2886920524111083752U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 15308180928967762543U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10886177449328249656U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15067759884678100433U;
            aOrbiterC = RotL64((aOrbiterC * 5724566815989860041U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 18307930462682331536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8791864377579255801U;
            aOrbiterK = RotL64((aOrbiterK * 9265158882471421767U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 805797468642992351U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5743305867058244964U;
            aOrbiterB = RotL64((aOrbiterB * 16263000753351131717U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 17102025528234481273U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1841579177327486899U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3841603385577825265U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2189493507896508972U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18209567010094914374U;
            aOrbiterH = RotL64((aOrbiterH * 3737080408976852351U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + aNonceWordO) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17857U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 19491U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20806U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 16986U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 23U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 51U)) + 7270044678408187242U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 10192278965379756766U) + aNonceWordD;
            aOrbiterC = ((((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 17568666746676060748U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aCross, 44U)) + 14312927531124963037U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 9825825726152087706U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 21U)) + 9696778570255265896U;
            aOrbiterG = (aWandererG + RotL64(aCross, 3U)) + 17657841352013417228U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16207815085909628439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1752979206374514227U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14182667540650694199U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10456310689643905854U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16127830548663742550U;
            aOrbiterE = RotL64((aOrbiterE * 4355938404839045417U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2940917376003930842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7353596864777649953U;
            aOrbiterI = RotL64((aOrbiterI * 7499468723171042005U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12725092740446150705U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5791296650856037010U;
            aOrbiterF = RotL64((aOrbiterF * 760379251950502133U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 1200130368046206150U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 16689604428598558547U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 13815324235939996623U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14359561591103730856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3975025843599045263U;
            aOrbiterD = RotL64((aOrbiterD * 5025047888533298617U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14017901732955607601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10431526786489555196U;
            aOrbiterG = RotL64((aOrbiterG * 10181915874476132407U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + aOrbiterE) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 43U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25405U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 23258U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22794U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 26384U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + 6467297102954816305U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 11U)) + 7921154109831114952U) + aNonceWordJ;
            aOrbiterA = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 5701131763215638919U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 3U)) + 10022999076719002684U) + aNonceWordC;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 4367135243038982316U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 43U)) + 14445846824810383592U) + aPhaseAOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 51U)) + 7683697954545773253U) + aNonceWordE;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17517006750428030899U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2052484792684025476U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 12463117571122469643U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6279463052085808926U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 679280153651813684U;
            aOrbiterD = RotL64((aOrbiterD * 3047031560593583881U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 2939516520188460569U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1960616434964712325U;
            aOrbiterI = RotL64((aOrbiterI * 15145998415466343039U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12273819390719947361U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5685033154709449397U;
            aOrbiterC = RotL64((aOrbiterC * 9845666295874714959U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9314494172199500653U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15757631834636427621U;
            aOrbiterF = RotL64((aOrbiterF * 15483543888965744529U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10878078046389399574U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3583495913766365232U;
            aOrbiterJ = RotL64((aOrbiterJ * 2913540984990155225U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7385544065754622301U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16839599460207922881U;
            aOrbiterE = RotL64((aOrbiterE * 240651605910592561U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aNonceWordB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 10U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31441U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 27735U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29098U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 28811U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 37U)) + 1557680213571812384U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 19U)) + 7387349725778021121U) + aNonceWordG;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 15379264067601586976U) + aNonceWordA;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 3730195724576043708U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 9637070085323827066U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 1170865717363676184U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 5U)) + 2750833653175252030U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15118992811225568305U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4974092922102988451U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10575977398702460975U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10625719096296719514U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 855167122475471865U;
            aOrbiterD = RotL64((aOrbiterD * 7441090331293158773U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11322911068958340262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4334591909425429835U;
            aOrbiterB = RotL64((aOrbiterB * 10059025861172038183U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 14263701737208936392U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 678723206735649084U;
            aOrbiterA = RotL64((aOrbiterA * 10823239851733632227U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15652053114252065230U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1705225940224061401U;
            aOrbiterJ = RotL64((aOrbiterJ * 3626023093533713579U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6826394665732900206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11902946775066981141U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 18300629262162694137U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9802212958998591310U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14001358545610206524U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13172645840788327099U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterI, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterF) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Hockey_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFEC49A7E2ABC52DFULL + 0xCBC95FA1F29DB811ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE35C3D3894FF1FB1ULL + 0xEC834528A5E73105ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE4F4DD0A816952EDULL + 0xB6D4529B439BB518ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE441C90B815BBFDFULL + 0xA264ECE72E6147A2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFF21113C9C650557ULL + 0xA47CD1D59213C870ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD9D61AE530BFB02FULL + 0xFC556A4901BED8E1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x84FC7619C6C3F0F7ULL + 0xC4650AC2ECA995B9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8B81524FC5A55079ULL + 0xA494F082A75F108FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFC619628A85A6F2BULL + 0xED5CB47996F7B488ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCF629E845684F9D7ULL + 0xEACDCD04889A8B62ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x988E3713625B2641ULL + 0xD5F7376BF7C4F23DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF9E5F8B512C2AB7BULL + 0xB44D931582026DE9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDF40D7937A892A91ULL + 0xCC9B92C34C42E3DAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB3E33BFE3500C1B1ULL + 0xD9D8894DF44B2F2EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF82BFA8C94EB206BULL + 0xDF8FBF4B16768036ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD2F39EBAB99B56F1ULL + 0xBCBD7216C010EBE0ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3114U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1070U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1592U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2558U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 42U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + 10812151398716051703U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 18202551453336003710U) + aNonceWordH;
            aOrbiterK = ((aWandererC + RotL64(aCross, 29U)) + 9434410809101973752U) + aNonceWordM;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 52U)) + RotL64(aCarry, 29U)) + 12955829998028534045U) + aPhaseBOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 12271740641929640181U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14009351527014534752U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4316296955679133450U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11582128345511775161U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16473324966997442872U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15735123324965019802U;
            aOrbiterJ = RotL64((aOrbiterJ * 5624078184997601019U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17656375090484080236U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16066325053456055298U;
            aOrbiterF = RotL64((aOrbiterF * 17912970706985130327U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12908968778503516903U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 12761433987676836197U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 1023329467480907925U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12737513138040664509U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14535795767570998392U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 15560519667062222269U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 23U)) + aNonceWordK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10536U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6200U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8278U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 8480U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 57U)) + 1708250618750199233U) + aPhaseBOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 28U)) + RotL64(aCarry, 3U)) + 12009147777553691142U) + aNonceWordL;
            aOrbiterB = (((aWandererA + RotL64(aScatter, 3U)) + 8393982703399156592U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 3247327098356831221U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 41U)) + 3403590155376353737U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18197244558104735044U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3096253642040701606U;
            aOrbiterB = RotL64((aOrbiterB * 6656168712438620783U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8012692688785412179U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17531946907545680745U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16510602981731506381U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17687695944270225817U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16147773866007628769U;
            aOrbiterA = RotL64((aOrbiterA * 16926442582711557877U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18244641303026196497U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 8839160526348897457U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10599266240854068246U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2056723540756216155U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13311591601230386375U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 54U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 42U));
            aWandererG = aWandererG + (((((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 51U)) + aNonceWordC) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 29U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12454U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 14456U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16206U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14116U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 54U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 12849591986267890852U) + aNonceWordB;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 8232614804696815750U) + aNonceWordH;
            aOrbiterI = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 12141567259210877281U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 44U)) + 2928641981037885644U) + aPhaseBOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 19U)) + 980733350554783938U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2683985177993350746U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14532148403815527355U;
            aOrbiterI = RotL64((aOrbiterI * 15985362037094864225U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7736296629433884203U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 10428437770166310549U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 326634742742373401U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 18327174144859461029U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 6810436935194432002U;
            aOrbiterD = RotL64((aOrbiterD * 2715987179577753597U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12606153309690753435U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 17123256945895150555U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13469111258504672565U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9057777759026189541U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16478485918911194442U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11054247078884894131U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 42U) + aOrbiterJ) + RotL64(aOrbiterD, 30U)) + aNonceWordF);
            aWandererD = aWandererD + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U)) + aNonceWordG) + aPhaseBWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17458U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21037U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19265U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 19158U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 47U)) ^ (RotL64(aIngress, 4U) + RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 39U)) + 13650869943246163567U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 3435284932011770999U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 41U)) + 12388155658186776579U) + aNonceWordM;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 2374345913955712039U) + aPhaseBOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aCross, 30U)) + 6095094526980292156U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4965147025852444174U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 3261881216269075298U;
            aOrbiterF = RotL64((aOrbiterF * 4874733445914960785U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4939780217097329222U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3019862009792676287U;
            aOrbiterG = RotL64((aOrbiterG * 2452316208025448747U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 901910626217143974U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3647055146712366383U;
            aOrbiterH = RotL64((aOrbiterH * 1792602402476450009U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7731765438957392967U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 13409819457393479741U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5415832109107794258U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8876738832313114471U;
            aOrbiterA = RotL64((aOrbiterA * 1304277600444504135U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aNonceWordG);
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE + ((((RotL64(aCross, 44U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 20U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27126U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 21962U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26927U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25415U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 18U) ^ RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aScatter, 38U)) + RotL64(aCarry, 53U)) + 17936518874386450467U) + aNonceWordN;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 13722737841589910344U) + aNonceWordI;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 11774969167948715796U;
            aOrbiterK = ((((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 3640101505680493777U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 51U)) + 1369495382725650822U) + aPhaseBOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11827310354654653345U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 186037671377175394U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 829791264853993897U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11428829344234627340U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2275016369870029068U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14936799202145280833U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15471646673734798328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12172082573115640145U;
            aOrbiterA = RotL64((aOrbiterA * 9629417882787847753U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6626736341348283154U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12220614992483863623U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8137086205714097487U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 13157102324253760215U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4143587482368093601U;
            aOrbiterK = RotL64((aOrbiterK * 5060677690991506895U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + aNonceWordG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterI, 6U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + aPhaseBWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererD, 28U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31089U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27339U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31371U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32264U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 40U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aScatter, 51U)) + 15045917390223766480U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 10763054007033668758U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 13190170142593666607U) + aNonceWordL;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 28U)) + RotL64(aCarry, 43U)) + 9657025731441167065U) + aPhaseBOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 37U)) + 11433367178975954211U) + aPhaseBOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17904920143996810366U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3244383020512113283U;
            aOrbiterC = RotL64((aOrbiterC * 552521443123433353U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6538815775171139091U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7195368312757976343U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10515679176134176565U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18134430713910279374U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6571776588427107976U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11830778129647517758U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9793702760907767365U;
            aOrbiterB = RotL64((aOrbiterB * 4096246227968677179U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2287235876793192036U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8951959188326141794U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9968356718110753845U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 54U) + aOrbiterE) + RotL64(aOrbiterB, 21U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 48U)) + aOrbiterB) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Hockey_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD12AA8E54691BF65ULL + 0xFC46E1117A6516A6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEF088187E6EBB389ULL + 0x80D5DE88572EBD23ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83BA08C5AA37939DULL + 0xBC0B6227B352AB40ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE6C7BAB5D1118543ULL + 0xC4D7021F6987192BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x870D2D2C7E9649ADULL + 0xA20860F84FDAF302ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD3B924F1FB6D1525ULL + 0xFFE1BDBAB0AA9B81ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x90BDFAE1D3BE72F7ULL + 0xB5992842B7AEBE67ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x89FEAA4DC01CD179ULL + 0xD3EEF95EB749F188ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA029645FACC75373ULL + 0xF62ED96484E06754ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB97F572E39743983ULL + 0xE4EB2069C3D27BEDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD457B3FBDE24DFFBULL + 0xAEC10BD720608D0EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE7AC927EB2DF4A6BULL + 0xBC242EE134864A5CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC5DBB6DC35700DC9ULL + 0xB8342F57A1ED837CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x875C8979CB9F89BDULL + 0xEEA54F7EB44E5F29ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFBBF3F60A5298D97ULL + 0xE46135C98F5A8744ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAF7B8BBCB0657239ULL + 0xC4B805A3A04A16CBULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2666U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 2289U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4072U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 8016U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 37U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 3U)) + 826930775230515406U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 29U)) + 5137814617363250861U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 14761561947426681616U) + aNonceWordI;
            aOrbiterI = (aWandererH + RotL64(aCross, 38U)) + 12773023438753662590U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 47U)) + 7331345852207096322U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 43U)) + 3899381212671247460U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 19U)) + 10072004147620068599U) + aPhaseCOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 51U)) + 3424585039401897560U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 8246760141625966321U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3655992860610853290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11154618022505863898U;
            aOrbiterF = RotL64((aOrbiterF * 4791494171286145231U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15629361991059709973U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10842068502278489664U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 17223002513104960799U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5571312349016336686U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 589313823745748879U;
            aOrbiterD = RotL64((aOrbiterD * 1356685926549786027U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13633457935771935260U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12684602052812183096U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4689206269919806711U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5711307583717354204U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7181854170553728211U;
            aOrbiterG = RotL64((aOrbiterG * 9835601115561325911U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1884620014396115821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1471516373272364262U;
            aOrbiterI = RotL64((aOrbiterI * 5126319375714848029U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 742739371092077733U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8075893317715227838U;
            aOrbiterC = RotL64((aOrbiterC * 11208274111743259795U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8179547722249281263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15305282712174742323U;
            aOrbiterH = RotL64((aOrbiterH * 7951986906055462929U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1430543231751281079U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14585341768267283387U;
            aOrbiterK = RotL64((aOrbiterK * 313213844964269133U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 56U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + aNonceWordA) + aPhaseCWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 18U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterF, 53U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 12U)) + aOrbiterF) + aNonceWordJ);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11999U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 13392U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11710U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12855U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 5U)) + 4259993311776766595U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 2857813330021126753U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 41U)) + 1345396841329442896U) + aNonceWordE;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 30U)) + 320992148982301024U) + aPhaseCOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 47U)) + 5619109532065293074U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 10380157329426706345U;
            aOrbiterI = (aWandererF + RotL64(aCross, 35U)) + 12449831150625409695U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 58U)) + 7847096607042268396U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 11707184096803214678U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9893643746186827088U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 333687403830908774U;
            aOrbiterJ = RotL64((aOrbiterJ * 17911256836121454271U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13837360705077441580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4367119682175710689U;
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1193493435041306784U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15062951612027370606U;
            aOrbiterI = RotL64((aOrbiterI * 2509383510565136549U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16000173839235429105U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 15294482444605409961U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 1031800997944302665U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5720749055549773527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17248674962996093668U;
            aOrbiterH = RotL64((aOrbiterH * 15730637462755795591U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16956840483882091059U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9637715107943515594U;
            aOrbiterG = RotL64((aOrbiterG * 8878362378343603463U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7147495779349862274U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7508890985889484275U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17728368447504622035U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4407738164617959366U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17027017782352660454U;
            aOrbiterF = RotL64((aOrbiterF * 417183060881259295U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3174658601748235285U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9779053567370714831U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6383245776181968033U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 12U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 60U)) + aOrbiterD) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordP) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererA, 46U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24160U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18915U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20998U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 18541U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererA + RotL64(aIngress, 57U)) + 4752759164691497960U) + aNonceWordK;
            aOrbiterG = (aWandererG + RotL64(aScatter, 43U)) + 12088872623537639782U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 34U)) + 3734943577379734227U) + aPhaseCOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 8854778183012444234U) + aNonceWordC;
            aOrbiterC = (aWandererE + RotL64(aCross, 39U)) + 16948373492893967275U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 19U)) + 7962415690046184385U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 13U)) + 1872682375669714454U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 24U)) + RotL64(aCarry, 43U)) + 7776801806943853566U) + aPhaseCOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 16665439117257230732U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11088186766134265676U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterK) ^ 10850237991780969350U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 7547414856143095121U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6464817712131305812U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 244557182884209844U;
            aOrbiterK = RotL64((aOrbiterK * 2394270354887582889U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13261563971157415841U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2323811103717827362U;
            aOrbiterD = RotL64((aOrbiterD * 11483723582415081925U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12338803568475493422U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2811342930111104982U;
            aOrbiterG = RotL64((aOrbiterG * 5020981755203607757U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5554497011738996057U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12712169745460598698U;
            aOrbiterC = RotL64((aOrbiterC * 1985586486150377769U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17415058661427002973U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9430421222715343818U;
            aOrbiterA = RotL64((aOrbiterA * 10321140659099470811U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3926618548181233180U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6172453297026957838U;
            aOrbiterH = RotL64((aOrbiterH * 1161551082037835233U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8633288765997226004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 17270881130844274342U;
            aOrbiterI = RotL64((aOrbiterI * 8888559940161770791U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12232950994807835262U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15352600312956742750U;
            aOrbiterF = RotL64((aOrbiterF * 6140396356904933003U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 5U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aCross, 52U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aPhaseCWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 18U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 22U)) + aOrbiterA) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29307U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27304U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30494U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 27937U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 16016931609704150191U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 47U)) + 14511433515861302636U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 11691237442613269593U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 6U)) + 16383220587320484649U) + aNonceWordC;
            aOrbiterK = (aWandererA + RotL64(aScatter, 11U)) + 14293015313458219868U;
            aOrbiterH = (aWandererK + RotL64(aCross, 57U)) + 4407695248205526670U;
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 1158323195324398372U) + aPhaseCOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 24U)) + 6577683409653864555U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 43U)) + 171080079472863843U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5766333425872228205U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16173508656917582960U;
            aOrbiterD = RotL64((aOrbiterD * 12187968015372936695U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11781450063402219202U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13033139686637576694U;
            aOrbiterK = RotL64((aOrbiterK * 4331137994135472025U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4006310759400926020U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13156817947481574467U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 563189239835001483U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12791290558893516411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 989729955679243234U;
            aOrbiterA = RotL64((aOrbiterA * 8757228712495095017U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 838379839663022790U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2830743864262313606U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10173947177104802797U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2146646527331684652U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4629168181742174906U;
            aOrbiterH = RotL64((aOrbiterH * 9046124907945045131U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1150129989168501777U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 619659995945229440U;
            aOrbiterI = RotL64((aOrbiterI * 13734821008174603409U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8120315647582116952U) + aNonceWordI;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13754584116324996165U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12295486140772079747U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6084566798869999580U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5731665119233722504U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5921510209025133639U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 28U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterB, 6U)) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 24U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterB, 39U)) + aPhaseCWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 58U)) + aOrbiterC) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
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

void TwistExpander_Hockey_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9A5752C4443332ADULL + 0xB464D4538DFB87F1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC31B5B673FA6A9F7ULL + 0xBB094F7AA27398BBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD721836FC625A53FULL + 0xA59447324986DA6AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x981615BE0C0DDAF9ULL + 0xEFC261093157A790ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x851D4250CD08CBB7ULL + 0xF2D037208E80748CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC974A2D2F96511CFULL + 0xA6B59857CFB1F167ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF01005840B312023ULL + 0x983518DF7F6BAAC1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x80D45E53E64F948FULL + 0x8789FD36FDBA2D01ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x925EAD9AF078081DULL + 0xC419C52ADC877513ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE490F239DF3D124BULL + 0xBF70F5D75391545AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE00173F971703301ULL + 0xDE491984A2D8848BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDA30C03D98240C09ULL + 0xA231D58DC56D60D9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x843F965D1E0650CBULL + 0xEAAEB9AA2D9A5D17ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBB2FD157C1F72DF1ULL + 0xC640DD5BF5C56FCFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC1DB22FBB1F37013ULL + 0xCD257B142285AD45ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8362F9516E9782C5ULL + 0xF4CB673603912064ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2324U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3835U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2743U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 123U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 29U)) + 16200278595895089008U) + aPhaseDOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 1029614154810465897U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 7129562468705441295U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 58U)) + 14388903902433951274U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 1013568949315967455U;
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 3128823373497815651U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 51U)) + 14525694606889470589U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 43U)) + 14443983602196782887U;
            aOrbiterB = (aWandererF + RotL64(aCross, 26U)) + 12244220415328641190U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 37U)) + 10477159225338766614U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + 2842870123078131566U) + aNonceWordL;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8621138818955849917U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5038396344400303181U;
            aOrbiterJ = RotL64((aOrbiterJ * 14636756322207385447U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2768613802894372496U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2027754864051410015U;
            aOrbiterH = RotL64((aOrbiterH * 2461322540050569287U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2848088309172056399U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15017458513904884651U;
            aOrbiterA = RotL64((aOrbiterA * 9926904679902843055U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 9079797279596336139U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15424866642305110811U;
            aOrbiterD = RotL64((aOrbiterD * 12912331089970158845U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13751764050290602740U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7694557131324740282U;
            aOrbiterE = RotL64((aOrbiterE * 14980807690491467023U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3508673897305667669U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3600868397311393233U;
            aOrbiterB = RotL64((aOrbiterB * 5165032044164139165U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1222655844979128996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2257342337168905875U;
            aOrbiterC = RotL64((aOrbiterC * 6198995971182272119U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6290990717563682725U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15308494772443447109U;
            aOrbiterI = RotL64((aOrbiterI * 1925593111157842325U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4065385272074155855U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17216369169581934516U;
            aOrbiterK = RotL64((aOrbiterK * 16172589962950781777U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 15683161334290612079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4197626901960576264U;
            aOrbiterF = RotL64((aOrbiterF * 2822547214684481747U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 4400047838649306704U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16200278595895089008U;
            aOrbiterG = RotL64((aOrbiterG * 6603195071605635697U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 28U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterD) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterH, 44U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9384U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 5988U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10188U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5863U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aIngress, 27U)) + 16160838483846078448U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 5U)) + 15404960896190227946U) + aPhaseDOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 47U)) + 16904160594024977199U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 41U)) + 17790460246821031802U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 16395168254086971959U;
            aOrbiterD = (aWandererE + RotL64(aCross, 18U)) + 7484373204039901786U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 18026814691322913510U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 11U)) + 15244817793136966450U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + 5795491730356335666U) + aNonceWordF;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 14U)) + 3163873518027801504U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 2690791759507349172U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17898067251167087906U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8028010015006604239U;
            aOrbiterB = RotL64((aOrbiterB * 5601629670521300241U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7304739457289910555U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6476837815096530043U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 16380545138701113267U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14242499233467960602U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17305645693017634630U;
            aOrbiterI = RotL64((aOrbiterI * 14442976693206929569U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9772864059444171908U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7897200728282156408U;
            aOrbiterE = RotL64((aOrbiterE * 816306719390807411U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4890999319172950996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9342923520083533265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7213639583505088067U;
            aOrbiterK = RotL64((aOrbiterK * 1349251979649428909U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4079475132684197272U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3350998022472827283U;
            aOrbiterA = RotL64((aOrbiterA * 948841791460066265U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2479140576609216238U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 7703147534931674972U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 11419116495223970801U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9050277787914448469U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13295888852307317371U;
            aOrbiterJ = RotL64((aOrbiterJ * 3027097172772140975U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15380254190549884741U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17653690414528791774U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15923958179714368315U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6825072759468337036U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16160838483846078448U;
            aOrbiterG = RotL64((aOrbiterG * 11690325563580492415U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 48U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 12U)) + aOrbiterB) + aNonceWordP);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aNonceWordL) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterG, 23U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 48U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 46U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11433U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12506U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13052U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 10949U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 18U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 57U)) + 7075016829833562104U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 8783765886115517036U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 2996723892384565829U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 9494134707342189476U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aPrevious, 48U)) + 5052642981395679904U;
            aOrbiterA = (aWandererB + RotL64(aCross, 5U)) + 8766787055127962238U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 4467211954388738079U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 19U)) + 8030255604633658608U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 13U)) + 16962408063455702251U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 41U)) + 3768222186567699076U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 46U)) + 14930990410207899871U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14179761938395502502U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1879084742719898108U;
            aOrbiterE = RotL64((aOrbiterE * 16783034788172670121U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5535012408925981515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12792553516710295939U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8979253163346099252U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5559189896063990740U;
            aOrbiterD = RotL64((aOrbiterD * 8832485423727331621U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13937564337299044079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2393376759689394948U;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12647519563697356479U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10946871249960389549U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6272580371881237173U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13376798695582123147U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10958115913599631271U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18233981473003345217U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4283914227806672773U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 910842005516235816U;
            aOrbiterC = RotL64((aOrbiterC * 6722229871617873429U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1509644316619370324U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 165987596716078174U;
            aOrbiterB = RotL64((aOrbiterB * 13600064054240185123U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12491315345199091186U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 5982431705686495125U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 2547243804779022665U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 231183123382412440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2872632389683254396U;
            aOrbiterI = RotL64((aOrbiterI * 1972278820468847241U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15259314110008210315U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7075016829833562104U;
            aOrbiterJ = RotL64((aOrbiterJ * 8350093877370898869U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterF, 35U));
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 26U)) + aOrbiterD) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 53U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterC, 38U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterE) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19666U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 17638U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20113U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18631U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 38U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 56U)) + RotL64(aCarry, 37U)) + 16183871922837164759U) + aNonceWordO;
            aOrbiterG = (aWandererG + RotL64(aIngress, 3U)) + 7002058258090219055U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 29U)) + 5650868611888303705U) + aNonceWordG;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 39U)) + 11899839660943876690U) + aPhaseDOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 60U)) + 15349649504488111111U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 14060149569086744970U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 13U)) + 12920917574225030112U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 2831994965175330135U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 35U)) + 18312543585028439192U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 47U)) + 11657562205118394239U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 10850792819281246052U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17810371216216125323U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7963413941144223128U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5498715358793875584U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 9256727548911651373U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17246360111302191699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 18309978718113983369U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 18267472694666221077U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3100998994319502921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8129301860291235970U;
            aOrbiterE = RotL64((aOrbiterE * 17847033539279176187U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1889641029473279114U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16538494307002917945U;
            aOrbiterA = RotL64((aOrbiterA * 8081488217920885783U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5432230549146849322U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2634437941396090817U;
            aOrbiterF = RotL64((aOrbiterF * 7612999214758935211U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16940172599174185058U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13151669140593952203U;
            aOrbiterK = RotL64((aOrbiterK * 16225319638131723487U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3995064294869931681U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 913081077665768816U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9299514648768060453U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2469001696075411481U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2167390955194185443U;
            aOrbiterI = RotL64((aOrbiterI * 11805065572289005223U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1574066406534010796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8736976961589874013U;
            aOrbiterG = RotL64((aOrbiterG * 5980070607180321955U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4233621443153132083U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16183871922837164759U;
            aOrbiterJ = RotL64((aOrbiterJ * 4030569514959370895U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 22U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 6U)) + aOrbiterK) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterF, 43U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 18U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterH, 50U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterA) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22269U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 24346U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24963U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25333U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 12690502671561165478U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 47U)) + 17519943923428102801U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 21U)) + 10705515807975331385U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererG + RotL64(aCross, 14U)) + 16586447272278538179U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 8006560996840971798U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + 12928600185788857701U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 5U)) + 14240723153798267172U) + aNonceWordH;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 8636219177994872072U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 50U)) + RotL64(aCarry, 43U)) + 7586790235186467512U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 1103807034179512424U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 29U)) + 7547526530239498693U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8380239679344786397U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5690809173787433519U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5354724308093372953U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8390902801141804609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3507306189192059486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18336280496510253103U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6190745292098482871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8065418693975056902U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6414621418430102589U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12111755051718111803U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 7605877769709909297U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 17525248694315944599U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5969794501112646237U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5127559299360591476U;
            aOrbiterB = RotL64((aOrbiterB * 4521563633438853069U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10593847754747739786U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4401750688524310121U;
            aOrbiterD = RotL64((aOrbiterD * 14265829318976633707U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6927893132508779499U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4874009978647014479U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13340466017023540755U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13146693487138744677U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3298472134223595298U;
            aOrbiterA = RotL64((aOrbiterA * 2145005258008477281U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8729305340729268734U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18347161842033439538U;
            aOrbiterF = RotL64((aOrbiterF * 7952715248988302017U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 166831495912855225U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4943633045563697271U;
            aOrbiterC = RotL64((aOrbiterC * 1809857625425000137U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2460623715340753589U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12690502671561165478U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 16421139715633515623U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterA, 56U)) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 26U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterB, 11U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31377U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28269U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32466U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32595U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 47U) + RotL64(aCross, 60U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 23U)) + 13204735390996728477U) + aNonceWordO;
            aOrbiterA = (aWandererK + RotL64(aCross, 51U)) + 851171359595647173U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 16745304202825290723U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 37U)) + 562392736584913979U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 41U)) + 3244267012529053918U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 17282536111067869133U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 12U)) + RotL64(aCarry, 3U)) + 14851130066471729068U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 5U)) + 5256130407952363129U;
            aOrbiterK = (aWandererA + RotL64(aCross, 39U)) + 2904742485828362001U;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 57U)) + 3723346325449225387U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 10U)) + 5344621093694027341U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12919263300833603026U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17989801264160996071U;
            aOrbiterC = RotL64((aOrbiterC * 15468293047311883751U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5022175042377172157U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16684822380107847758U;
            aOrbiterF = RotL64((aOrbiterF * 2834049270263837537U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2740326510600876682U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13981423865219318820U;
            aOrbiterE = RotL64((aOrbiterE * 14593082145080056441U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 231945878229848395U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14139797734944312580U;
            aOrbiterG = RotL64((aOrbiterG * 6492256080432266407U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16704102101387552373U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8506734780526852552U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4684566118627414659U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2774630043988894695U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12490034334296488127U;
            aOrbiterK = RotL64((aOrbiterK * 16765455396278233145U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 545238171291436006U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1023872898002379590U;
            aOrbiterH = RotL64((aOrbiterH * 8626333831510136515U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5065187021047872560U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10391809965648089863U;
            aOrbiterJ = RotL64((aOrbiterJ * 10912471108849550469U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5576919045471579002U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9761904001375034639U;
            aOrbiterI = RotL64((aOrbiterI * 8612901811320541361U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2001472279505185946U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11576457012366242134U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 1070815118051466731U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17713147845216099336U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13204735390996728477U;
            aOrbiterD = RotL64((aOrbiterD * 10889281795183444943U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 30U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 34U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 26U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterH, 53U)) + aOrbiterA) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordB;
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

void TwistExpander_Hockey_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC36FA172144813E1ULL + 0xF86F526E79318063ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEAA534ABF13E20FFULL + 0x9C4142CD80FC95E8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD1E35D099B55E9CFULL + 0xE6F7F8EEA40EA7B1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA1998497B366658BULL + 0xF1DB6314BAD01E2EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA58D25B6061CFB35ULL + 0x826279CA630F78F0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF79C0E8565E8C139ULL + 0xB7F73E2EBC07ACC5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDDBF902E98D68FABULL + 0xD088371D78EC1FDBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEA88D4AD77E3B1F7ULL + 0x96B91C13D35E68E3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9CE744E0234148AFULL + 0xA692477C0AB8A68FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBD937F310C048503ULL + 0x8A330427F73D0F96ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC89280A43CE2B497ULL + 0xAEFBE3788F23FAC7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x828385BA41ACE7D7ULL + 0xCB1567AA3C23A35DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC38EDAD76855CE85ULL + 0xE394F09EB0B961D6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF7CEE319F912CD99ULL + 0x95379DD68236CFE5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD507B49F462103C9ULL + 0xA2B5A1509F0CB652ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x907329CB11827A11ULL + 0xDD0A825F011F886BULL);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3629U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 723U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3520U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 3598U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 30U)) + 6318740973868639425U) + aNonceWordN;
            aOrbiterF = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 41U)) + 5487840061430920881U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 10258706763248072672U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 23U)) + 18356875269730338208U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 42U)) + 12883160282903147010U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 3U)) + 1010140474942697730U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 53U)) + 17733939421700898293U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 27U)) + 13693055887924981201U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 35U)) + 14574732452793385269U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + 10832873941223609012U) + aNonceWordO;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 8212600587135328040U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5312744319781971178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6173741211706546923U;
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3693249147883790810U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18365859989736602556U;
            aOrbiterI = RotL64((aOrbiterI * 3348463719324104997U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10645056678337549771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1175668356822251045U;
            aOrbiterA = RotL64((aOrbiterA * 6579675292775345579U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13556844570541823717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4790355739411849736U;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14905575502272644116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 17047244574558476634U;
            aOrbiterJ = RotL64((aOrbiterJ * 2356386971503880047U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10161614295718414869U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13413914082651612468U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 16224039093981079491U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6072693130156927774U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4333656233793103787U;
            aOrbiterB = RotL64((aOrbiterB * 9374745547133955709U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17209776289202130250U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11752001118070361543U;
            aOrbiterF = RotL64((aOrbiterF * 4416523594812872339U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15367365111105608277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8650687767097460704U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11430451559660578667U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18074648514448405693U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10857586858462237581U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 3722891011080095849U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17219932344278345591U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6318740973868639425U;
            aOrbiterD = RotL64((aOrbiterD * 8846295038878812229U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 18U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 40U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 28U) + aOrbiterD) + RotL64(aOrbiterE, 14U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8283U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((aIndex + 6796U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7059U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 7519U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 41U)) + 6069475454765660321U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 21U)) + 11483704742497268068U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + 11055697447388986418U) + aNonceWordE;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 21U)) + 10897095046039997004U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 35U)) + 4731637118230457840U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 10U)) + 13855839187084986751U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 5U)) + 5328208115460188239U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 3U)) + 12479538544291412985U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 37U)) + 10740165998792608231U;
            aOrbiterC = ((((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 6492798157284955373U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 47U)) + 13056825957483891921U) + aNonceWordK;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2068184064919194657U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5656302738780746294U;
            aOrbiterB = RotL64((aOrbiterB * 16493021179127646345U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11193756120230763294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17306750816837208999U;
            aOrbiterI = RotL64((aOrbiterI * 7949360041241439741U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12952818800389361804U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15380412293642628312U;
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7706090204767242996U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17819762117328075515U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6481384240915075101U;
            aOrbiterE = RotL64((aOrbiterE * 4836701121865783029U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 754936290510338717U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 15510875946573720154U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2994718968852184303U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9245381722813944586U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2629847912019726214U;
            aOrbiterA = RotL64((aOrbiterA * 6718795794951106961U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 3909987749797113773U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9277056074757335265U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 11580847505996697115U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12577180954515966707U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 9144513680789115458U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8880777678193004979U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1544232962956974411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2658275904714859636U;
            aOrbiterC = RotL64((aOrbiterC * 1926083316365175327U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5733515391293514025U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6069475454765660321U;
            aOrbiterJ = RotL64((aOrbiterJ * 9627476106108146391U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 52U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordN) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 23U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 50U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterB, 53U));
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterC, 27U)) + aNonceWordF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 11660U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15210U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14637U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 12829U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 8020711767807230555U) + aPhaseEOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 15368693777246341570U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 35U)) + 5117523734225562401U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 19U)) + 13155269151097507808U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 37U)) + 9879303753623578272U) + aNonceWordE;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 1165799257173794826U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aCross, 41U)) + 930641942062732091U) + aNonceWordL;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 27U)) + 11330571332221123153U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 3U)) + 2862963158282518899U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 50U)) + RotL64(aCarry, 13U)) + 6019186399361476659U) + aNonceWordJ;
            aOrbiterD = (aWandererJ + RotL64(aCross, 53U)) + 1924419843785161958U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12618629043591380461U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterK = RotL64((aOrbiterK * 18239109235362925739U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16829692481030013551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5604784396927022709U;
            aOrbiterG = RotL64((aOrbiterG * 2833893610883508353U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16124030106598549644U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16571659812830230677U;
            aOrbiterC = RotL64((aOrbiterC * 4668250364992383549U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15171089673591843703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2826755560293849328U;
            aOrbiterB = RotL64((aOrbiterB * 9397017963457655287U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9976785768283589291U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11845100564714691809U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4935139932585319251U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7318560453127859950U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3039196878830506712U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 3140508261330698717U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8850992055588337843U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4219373528176869146U;
            aOrbiterJ = RotL64((aOrbiterJ * 1310964742529956743U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1341474458715938799U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15937557372891732898U;
            aOrbiterE = RotL64((aOrbiterE * 11437307017920192915U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7512741986101399499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4304636545688233645U;
            aOrbiterF = RotL64((aOrbiterF * 1948671766238131953U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11460886069492094055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2019818350627642126U;
            aOrbiterI = RotL64((aOrbiterI * 9802784763505584769U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3190374588085859096U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8020711767807230555U;
            aOrbiterD = RotL64((aOrbiterD * 12055760672321414929U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterE, 40U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterD, 53U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 51U));
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + aOrbiterG) + RotL64(aOrbiterA, 26U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererB, 24U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17209U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17912U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21810U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18188U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 35U)) + 11521331427196538632U;
            aOrbiterF = (aWandererE + RotL64(aCross, 27U)) + 16653824187682957632U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 11654676587350088289U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 30U)) + 8010313317412193584U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 1108775560502907471U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 43U)) + 243952321439823521U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 21U)) + 2324945800401240403U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 9257554497543369657U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 48U)) + 16701314607244592540U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 23U)) + 3900445848034341782U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 41U)) + 7652316487347103658U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14980368605272070578U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2001165460948764796U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8110980921827107649U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1911044015666991050U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11366207111147818339U;
            aOrbiterD = RotL64((aOrbiterD * 17234439040652553865U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 16469329744002456607U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8062793687044950815U;
            aOrbiterJ = RotL64((aOrbiterJ * 5856142259851144369U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15364721421972807872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8979915611483540231U;
            aOrbiterC = RotL64((aOrbiterC * 10899377466171153383U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7654234623563110457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1526832460342135008U;
            aOrbiterK = RotL64((aOrbiterK * 12766083052650723051U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1596625448797520938U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15723912914858523080U;
            aOrbiterB = RotL64((aOrbiterB * 6003857787643420337U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7664226719746532168U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13767298788411473401U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 15663266144965532019U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8371251860069346385U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10143279934304029980U;
            aOrbiterI = RotL64((aOrbiterI * 12764966547132248131U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10034920090729616747U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14450253491131954914U;
            aOrbiterA = RotL64((aOrbiterA * 15877567779079226909U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9450697155749555210U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14051719612902917300U;
            aOrbiterF = RotL64((aOrbiterF * 7659810299163085295U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 659383614060726993U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11521331427196538632U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1068009283450923005U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 46U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 51U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterC, 38U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24074U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 26271U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25180U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 23287U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 35U)) + (RotL64(aIngress, 19U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aIngress, 58U)) + 12426357877879529292U) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 19U)) + 12604900366173639176U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 21U)) + 13511119007338929401U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 51U)) + 9878720081166788060U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 13U)) + 15463195409806395076U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 35U)) + 6407922778852833423U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 7690427254160734016U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 24U)) + 18030974031722143619U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 17983938038322737041U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 11U)) + 16605512170117753884U) + aNonceWordE;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 681802273302348322U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15550312921312083819U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17824154101711884508U;
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1939207786756735430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3132864634777826569U;
            aOrbiterB = RotL64((aOrbiterB * 13606281919426730325U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12822929773923954849U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16576106045887115660U;
            aOrbiterD = RotL64((aOrbiterD * 16370914370769903051U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2398825881649235260U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13700821892926092479U;
            aOrbiterI = RotL64((aOrbiterI * 10830623703416956043U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2439833784883391606U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15870638514107637833U;
            aOrbiterA = RotL64((aOrbiterA * 3797380922767479287U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9165457123134229670U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8736642509192659417U;
            aOrbiterE = RotL64((aOrbiterE * 16219277537523484065U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9232719746484835693U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7826680628853322541U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12578050118133526187U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14323652326982518782U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2254524512851399313U;
            aOrbiterK = RotL64((aOrbiterK * 4119339547645451149U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14459632243829356472U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8591197056749497716U;
            aOrbiterJ = RotL64((aOrbiterJ * 13053836520694721881U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17220196418897000411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7186579019945992185U;
            aOrbiterF = RotL64((aOrbiterF * 12406048515179065691U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7554005180895698880U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12426357877879529292U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5090046967147694465U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 56U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 24U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 48U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29960U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 29306U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30657U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 32658U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aCross, 11U)) + 6733949564325516029U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 7304098437143918796U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 35U)) + 3923949518391777800U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 30U)) + 14243591003388927124U;
            aOrbiterK = ((((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 18329498724605410406U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 43U)) + 13118172167747037249U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 5U)) + 5272025143849174212U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 35U)) + 16075917179214318424U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 57U)) + 15263590648674658399U;
            aOrbiterB = (aWandererH + RotL64(aCross, 23U)) + 13730046728289525921U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 26U)) + 7703141464499623408U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1382279753822135359U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2973369221699098292U;
            aOrbiterI = RotL64((aOrbiterI * 7440242040663550631U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11578274119583013219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3419411247737896674U;
            aOrbiterK = RotL64((aOrbiterK * 17814942652262802991U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2582783513078999303U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3959762790273529677U;
            aOrbiterH = RotL64((aOrbiterH * 383974377372162751U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 465795011576934604U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterA = RotL64((aOrbiterA * 4445949147592860913U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10819659185349413173U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 17298208553586835030U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1965860510614222093U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12585880006661489402U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16650193903267408586U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 5781132589396936615U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 885882046325991589U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 869560078374809974U;
            aOrbiterB = RotL64((aOrbiterB * 13440973563438747181U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11871305571797951851U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12137095015607196226U;
            aOrbiterJ = RotL64((aOrbiterJ * 7618152256560808581U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6044048326509186958U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 622564532811968856U;
            aOrbiterF = RotL64((aOrbiterF * 14988345089359014037U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17133994029325040272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8612895899003926829U;
            aOrbiterD = RotL64((aOrbiterD * 2128664397481732179U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2169081503433534750U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6733949564325516029U;
            aOrbiterE = RotL64((aOrbiterE * 10062179904046311601U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 46U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + aNonceWordN) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + aPhaseEWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterD, 27U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 40U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 48U)) + aNonceWordK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 50U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordL;
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

void TwistExpander_Hockey_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD136EEFE80ACC885ULL + 0xF922886549120F2EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC0CEA7D2E449C7A5ULL + 0xB30936D54996F96CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEAEC53E7C5D785D3ULL + 0xB98B9E45B46535AEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD266E8FA9A8FA68BULL + 0xAD37D8EC1C73C26DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9829ADBB6A861963ULL + 0x978F639F19825D09ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF806A3B4B9F61849ULL + 0x86FCC18BA688A560ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCAF970FB56D1F7C5ULL + 0xD1DD7408B14FDDE6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x94CAD47FC56A2CA3ULL + 0xF0A2FF1D89566622ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEA79C4101BA05C87ULL + 0x9B9D8066D5920E91ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x805144F915FD3519ULL + 0x999646BDB0FF2A64ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x90095B0798302AE5ULL + 0xF639344F7A9E963DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF7627ED8DA8D35B1ULL + 0x9D904EC742E78BFDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC19CDC0364F2697ULL + 0xAD58140D1491D394ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF887BF7BECAC2B75ULL + 0xAB7269F21C258723ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE28A8790155EDAB7ULL + 0x89F91227EA86DCE4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF2CE4BB8391BA071ULL + 0xE60D8A3316FD23F3ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3668U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 2531U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3286U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 1548U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 18180797995100240808U) + aNonceWordL;
            aOrbiterI = ((aWandererA + RotL64(aCross, 53U)) + 6585906608223552885U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 14088708930575939855U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 5U)) + 468974153311516044U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 26U)) + 12481951025619894110U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 3U)) + 17227987923860711763U) + aNonceWordO;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 41U)) + 4373962756657477139U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 47U)) + 2077576476565420951U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + 17435011300234663764U) + aNonceWordN;
            aOrbiterH = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 4118039398293246896U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 34U)) + 13724716599855216683U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12391461204689596339U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 9900605191533799627U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 972946858824366125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17247681919694541215U;
            aOrbiterF = RotL64((aOrbiterF * 2974639094630445643U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15442851427306771601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7303586227288294037U;
            aOrbiterG = RotL64((aOrbiterG * 15406402525021428799U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12650358753454105119U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1483710933373510492U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 6531763256577221891U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18065810162229740788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2355285311890287611U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1287783821903407734U;
            aOrbiterA = RotL64((aOrbiterA * 8054011680932255985U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9282654686791135654U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15488608017745542551U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7858866274035085123U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13296835576073421802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7127700236018338741U;
            aOrbiterI = RotL64((aOrbiterI * 11246173563106014149U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1365928843264598789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7777790578813003657U;
            aOrbiterE = RotL64((aOrbiterE * 10121688100505628161U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2104270617375082523U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13363764449819651164U;
            aOrbiterK = RotL64((aOrbiterK * 2685452132715528975U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2008038686059197988U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18180797995100240808U;
            aOrbiterH = RotL64((aOrbiterH * 8978998151475372047U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 4U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 54U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 38U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10222U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 8082U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10198U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6362U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 4U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 41U)) + 11698283336767769359U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 44U)) + 13297826354831483872U) + aNonceWordM;
            aOrbiterI = (aWandererK + RotL64(aScatter, 51U)) + 15254999058287530795U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 23U)) + 17474166585085346567U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 15684783498452840289U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 27U)) + 5061229733465216486U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 21U)) + 15370981279168377944U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 35U)) + 17966672773619554092U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 48U)) + RotL64(aCarry, 47U)) + 14685092893994491068U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 12798804186209406389U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 39U)) + 2848444181474221574U) + aNonceWordD;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8551142075919636146U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8833198159158950723U;
            aOrbiterI = RotL64((aOrbiterI * 7650289040764974737U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7351473160893666232U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14204899612487622222U;
            aOrbiterF = RotL64((aOrbiterF * 6317485031956448029U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 7008985178526543258U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13576796403863120356U;
            aOrbiterH = RotL64((aOrbiterH * 13745839827679114077U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5769784656937900699U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14075925808204936705U;
            aOrbiterC = RotL64((aOrbiterC * 5844894088757604713U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17818667502858010896U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16016922065572683130U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7525645833898085373U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1582458237855075977U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10830440354527138227U;
            aOrbiterA = RotL64((aOrbiterA * 10499386926982228251U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10653964151654643772U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11218475491129483859U;
            aOrbiterJ = RotL64((aOrbiterJ * 3338108067044357141U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9863649760189649255U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13790281439048354358U;
            aOrbiterB = RotL64((aOrbiterB * 4682098083538482849U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14846954923718136337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 522207783972623813U;
            aOrbiterE = RotL64((aOrbiterE * 14299798934454852811U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 426829715716262697U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7482977730216354509U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 6317437989422015173U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10736099808538972990U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11698283336767769359U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 17230175904095995929U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 14U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 6U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 37U));
            aWandererE = aWandererE + ((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 23U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 18U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14264U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11057U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14362U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 11357U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 60U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 1142447269198373880U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 53U)) + 10581460640040336191U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 21U)) + 14703062773878202900U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 24U)) + 15737525756286914746U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 57U)) + 16178774478273186999U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 2514897053906809160U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 13702496607592508464U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 37U)) + 18030885275418337965U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 5241783876161655984U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 13U)) + 2807052676283587925U) + aNonceWordK;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 42U)) + 8022804576763271327U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15597099852232205860U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1538435607932096400U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 7900752511710516981U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11147868774413615365U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9325213746830411568U;
            aOrbiterA = RotL64((aOrbiterA * 561819005818948769U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13792300423550555634U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3134856508983945719U;
            aOrbiterE = RotL64((aOrbiterE * 4271845067763664863U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8654966018053784882U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8937113935476779267U;
            aOrbiterC = RotL64((aOrbiterC * 7386875687217705855U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4135676350355234788U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11407912615743682678U;
            aOrbiterG = RotL64((aOrbiterG * 2773506587480714695U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10966950663872392059U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6686634993700944582U) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 2509459942163678241U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14154407529749257990U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18054640398549782388U;
            aOrbiterF = RotL64((aOrbiterF * 7830759861389060149U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14623473030642960240U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1857945571104460086U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18039903315045620079U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17650774450811065797U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9458168381246672881U;
            aOrbiterB = RotL64((aOrbiterB * 3452665113988737563U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16604923466236483242U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12447748535184711684U;
            aOrbiterK = RotL64((aOrbiterK * 5982708155382249061U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 9589720286549780720U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1142447269198373880U;
            aOrbiterH = RotL64((aOrbiterH * 8176719948031280789U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 46U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + aNonceWordL);
            aWandererA = aWandererA + (((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19986U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 19628U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17670U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 19992U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 28U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererE + RotL64(aCross, 27U)) + 5906639480605353429U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 5293518570213287605U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 22U)) + 15383185501428521377U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 15364072512743978902U;
            aOrbiterB = (aWandererC + RotL64(aCross, 19U)) + 4525473357144014271U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 10400911938125603074U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 30U)) + 16417506293824627550U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 47U)) + 2419329331753341815U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 53U)) + 14929222427923332069U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 16771573504983922586U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 35U)) + 1863466450051787622U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12895350137096692415U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3700979086526298327U;
            aOrbiterG = RotL64((aOrbiterG * 10279730254867618193U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1977099106211282426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6144698304096915742U;
            aOrbiterB = RotL64((aOrbiterB * 5039822990560519609U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3858895556659724975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1283646340363435327U;
            aOrbiterJ = RotL64((aOrbiterJ * 11622421841377018069U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6240532051889108891U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 757364889381634634U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 943852137901972945U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5272945693977418174U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6850528198786172283U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1966383079897679953U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14431587733859573714U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16124590257870999553U;
            aOrbiterI = RotL64((aOrbiterI * 7755796211433191143U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14912695018110241411U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11098623474413346520U;
            aOrbiterK = RotL64((aOrbiterK * 15167688959990872051U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3484847683376368686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2295388097292719800U;
            aOrbiterH = RotL64((aOrbiterH * 1240808318176106909U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 923199510066894111U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 311875852510926196U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 9797881750305289335U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3543141837224843684U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12889943043568922084U;
            aOrbiterD = RotL64((aOrbiterD * 8682278766727990427U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6105656539077757510U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5906639480605353429U;
            aOrbiterF = RotL64((aOrbiterF * 9555916235293954383U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 30U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 6U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22262U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 26177U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21916U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25655U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 36U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 5295352595333316211U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 2341795367042042605U) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aCross, 11U)) + 10122175780504033663U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 6U)) + 10084612804696198554U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 51U)) + 16470424309851045971U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererD + RotL64(aScatter, 27U)) + 656016130975227994U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + 15313268829659834317U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 4U)) + 3795220914993923394U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 14044442220988813825U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 13U)) + 3804224626734584802U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 47U)) + 7980006306010255693U) + aNonceWordG;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13746830564584711549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 11852212099729274845U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2164880979318247855U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9083223471018084847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13706723820703853346U;
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1713819986642275223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 1382000168233902914U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3894160765130198157U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4540474625764565485U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1756168174375757220U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1409297070183609309U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6082750101445444357U;
            aOrbiterF = RotL64((aOrbiterF * 17438740230251860935U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1113239890859479202U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10932192439503964363U;
            aOrbiterG = RotL64((aOrbiterG * 5915660289913324281U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3732595033748508428U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5117760372351117286U;
            aOrbiterE = RotL64((aOrbiterE * 2671510075176315761U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7399968659654088641U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14835608167871904147U;
            aOrbiterB = RotL64((aOrbiterB * 8312521710415756159U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7851355416751467648U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 262169565276199916U;
            aOrbiterJ = RotL64((aOrbiterJ * 11801419425408657509U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1771847554312299305U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15588805765521695222U;
            aOrbiterK = RotL64((aOrbiterK * 8541206691371972017U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6162696602553964144U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5295352595333316211U;
            aOrbiterI = RotL64((aOrbiterI * 8368226841948931873U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterC, 41U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterB, 50U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + aNonceWordD) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterA, 60U)) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterB) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 20U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30460U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31144U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30390U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 32528U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 57U)) + 5131645209694953015U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 12070391048835379854U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 48U)) + 2604295836242338724U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 14042039029284001596U;
            aOrbiterI = (aWandererC + RotL64(aCross, 53U)) + 8914654543854559327U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 3U)) + 2185619407969359869U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 51U)) + 5187406295103352574U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 39U)) + 8022832481290871217U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + 8783061916740573472U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 42U)) + RotL64(aCarry, 37U)) + 10711028365596196301U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 13U)) + 13387065038269133571U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11187001318931801582U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14191473173276034019U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2491253922434756431U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16207761776716426435U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9677408414452078760U;
            aOrbiterI = RotL64((aOrbiterI * 5487303383095129949U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17812460332794370649U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7736423148554132028U;
            aOrbiterA = RotL64((aOrbiterA * 15588733747232852555U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17293203944059014763U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13487243633338010243U;
            aOrbiterF = RotL64((aOrbiterF * 9468688858740539095U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15979293016815060755U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17645215484691359547U;
            aOrbiterC = RotL64((aOrbiterC * 1449450767288733995U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11635961468586927692U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10530136578329059784U;
            aOrbiterG = RotL64((aOrbiterG * 8785021493374398437U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4900370530116992731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15952900504821599445U;
            aOrbiterB = RotL64((aOrbiterB * 5413316082800365261U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9938000151832814778U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14170277411106520726U;
            aOrbiterH = RotL64((aOrbiterH * 5058343552974910737U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14091010427448547620U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13658560822164111421U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9523184040517290629U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13954269172267844623U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3921811946419945868U;
            aOrbiterD = RotL64((aOrbiterD * 6839440867046147039U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14296483810577739898U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5131645209694953015U;
            aOrbiterE = RotL64((aOrbiterE * 10190969526209064367U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 42U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 10U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterH, 14U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 35U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 26U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aNonceWordO) + aPhaseFWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Hockey_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFAC287039A6EADF5ULL + 0x939AD939E15D822AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF5BBD716F4A93D53ULL + 0xEE2DBFB3E6A27A87ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD21BF66C14478447ULL + 0xB109B689B6175D6CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8B3A28D00588CF33ULL + 0xD011D59661DBEAF5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB3DB1222033D66A3ULL + 0xE57F056AB1E498D6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF658AA7E81133BB3ULL + 0xE43A9192284FD378ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9C8E84AEE25159A3ULL + 0xDCC9AEA1A64E4E5EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9C92231DAC16811DULL + 0xFA36DCEEAA2E16EDULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9ABE292C001287E5ULL + 0xF324D036BAB9099EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBABF7F0F42BA4E15ULL + 0x9D1280E4C07B9CD2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE371F62F3EFDB735ULL + 0xA66F705E3DD3A28FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD7A784A70268D09FULL + 0xFE388CA73581AE87ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBFB1F1DBC4B85CA7ULL + 0xF90F243F9D7526FDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE1233B381B9613E7ULL + 0xF19DDEBA82121B71ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCD262150BA92D96FULL + 0xCA587D47578ECEAAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAAA9E155241A3BD1ULL + 0x9583C6DC601367A0ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1967U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3488U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5275U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1177U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 24U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 53U)) + 7270044678408187242U) + aNonceWordJ;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 14U)) + 10192278965379756766U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 17568666746676060748U;
            aOrbiterC = (aWandererC + RotL64(aCross, 23U)) + 14312927531124963037U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 9825825726152087706U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 27U)) + 9696778570255265896U) + aNonceWordG;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 19U)) + 17657841352013417228U) + aNonceWordF;
            aOrbiterD = (aWandererK + RotL64(aCross, 29U)) + 16207815085909628439U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 11U)) + 1752979206374514227U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 4U)) + 10456310689643905854U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 19U)) + 16127830548663742550U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2940917376003930842U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7353596864777649953U;
            aOrbiterB = RotL64((aOrbiterB * 7499468723171042005U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12725092740446150705U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5791296650856037010U;
            aOrbiterF = RotL64((aOrbiterF * 760379251950502133U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1200130368046206150U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16689604428598558547U;
            aOrbiterE = RotL64((aOrbiterE * 13815324235939996623U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14359561591103730856U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3975025843599045263U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5025047888533298617U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14017901732955607601U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10431526786489555196U;
            aOrbiterG = RotL64((aOrbiterG * 10181915874476132407U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7320527073559849223U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15333411223710709907U;
            aOrbiterJ = RotL64((aOrbiterJ * 3488684905528068775U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14302474063321663801U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2104154521019935187U;
            aOrbiterH = RotL64((aOrbiterH * 12944382959742278055U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5167600586916325228U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4566823109447208716U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9997799807454267443U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12475580453805083495U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15461491763911887974U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 13548865386159287481U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11000532703581114393U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7815822789941347770U;
            aOrbiterD = RotL64((aOrbiterD * 1476638214324946775U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2166336159928211562U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7270044678408187242U;
            aOrbiterK = RotL64((aOrbiterK * 10648564933168714815U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 60U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 38U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + aOrbiterH) + RotL64(aOrbiterI, 5U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8916U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8786U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7407U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((aIndex + 10211U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 8020711767807230555U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 36U)) + 15368693777246341570U) + aNonceWordF;
            aOrbiterH = ((aWandererG + RotL64(aCross, 47U)) + 5117523734225562401U) + aNonceWordD;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 23U)) + 13155269151097507808U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 9879303753623578272U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 43U)) + 1165799257173794826U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 930641942062732091U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 34U)) + 11330571332221123153U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 21U)) + 2862963158282518899U;
            aOrbiterA = (aWandererH + RotL64(aCross, 29U)) + 6019186399361476659U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 13U)) + 1924419843785161958U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12618629043591380461U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9334176504266512405U;
            aOrbiterH = RotL64((aOrbiterH * 18239109235362925739U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16829692481030013551U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5604784396927022709U;
            aOrbiterK = RotL64((aOrbiterK * 2833893610883508353U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16124030106598549644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16571659812830230677U;
            aOrbiterG = RotL64((aOrbiterG * 4668250364992383549U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15171089673591843703U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2826755560293849328U;
            aOrbiterE = RotL64((aOrbiterE * 9397017963457655287U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9976785768283589291U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11845100564714691809U;
            aOrbiterC = RotL64((aOrbiterC * 4935139932585319251U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7318560453127859950U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3039196878830506712U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3140508261330698717U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8850992055588337843U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4219373528176869146U;
            aOrbiterF = RotL64((aOrbiterF * 1310964742529956743U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 1341474458715938799U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15937557372891732898U;
            aOrbiterD = RotL64((aOrbiterD * 11437307017920192915U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 7512741986101399499U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4304636545688233645U;
            aOrbiterI = RotL64((aOrbiterI * 1948671766238131953U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11460886069492094055U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2019818350627642126U;
            aOrbiterA = RotL64((aOrbiterA * 9802784763505584769U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3190374588085859096U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8020711767807230555U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 12055760672321414929U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 48U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterK) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterC, 34U)) + aOrbiterB) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterJ) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 38U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 14U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 22U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordB);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15369U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15029U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11044U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15275U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 54U)) + RotL64(aCarry, 37U)) + 9914837590440975587U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 27U)) + 6706125076401958051U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 5U)) + 16570817772679258409U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 6843705658115186948U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 16099930446791572351U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 5420550009556030459U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 21U)) + 5729549069420177477U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 15590601126188675834U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 18U)) + 13044027390998620029U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 29U)) + 11068338135659636772U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 39U)) + 6584988841809544332U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8516813219883915404U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10647314042912492785U;
            aOrbiterC = RotL64((aOrbiterC * 15559481057047148785U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 201691689889605304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15512161798401184003U;
            aOrbiterK = RotL64((aOrbiterK * 11473219183982564709U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3883760518944464145U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterH = RotL64((aOrbiterH * 17194438894492581181U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12019138626550801486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2643807255422544248U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4127143302485631794U;
            aOrbiterB = RotL64((aOrbiterB * 5441038881111578487U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14602951930809633069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4555737199162278494U;
            aOrbiterD = RotL64((aOrbiterD * 12415825635220991865U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6343143902997169834U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10404783711336491985U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6235474458879439079U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7406959231434835393U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6684368109277850196U;
            aOrbiterJ = RotL64((aOrbiterJ * 8760360417572331159U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4835889355927954728U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7917682889852676712U;
            aOrbiterI = RotL64((aOrbiterI * 9045350756570117327U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10268055422944417055U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 5563744562922937643U;
            aOrbiterE = RotL64((aOrbiterE * 12442484191329795173U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17244672945880141679U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9914837590440975587U;
            aOrbiterF = RotL64((aOrbiterF * 12269340309792850489U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 5U)) + aOrbiterK) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aCross, 18U) + RotL64(aOrbiterH, 3U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 44U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterI, 34U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + aNonceWordK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21530U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16481U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18259U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 21639U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererC + RotL64(aCross, 21U)) + 10805654776556844351U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aScatter, 19U)) + 582794182442795335U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 52U)) + 2858343650974681068U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 8189584049022064284U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 1565100751996962893U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 39U)) + 8062028016947611891U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 11U)) + 8280504280578451745U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 11326869194491655350U) + aNonceWordM;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 56U)) + 1671695656567777163U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 3U)) + 2349843105293943452U;
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 13015545152052004254U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16703354404749291869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8713231044374305801U;
            aOrbiterE = RotL64((aOrbiterE * 9242480982197688625U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11118401674497783533U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14857556493734710364U;
            aOrbiterG = RotL64((aOrbiterG * 3452566050389715195U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12953419670951660965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12666121730825089017U;
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11075249639473053423U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9374217688244187867U;
            aOrbiterK = RotL64((aOrbiterK * 5261156325627117877U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17608340953291367867U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13159437499327086340U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4882100944453534805U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4304700511322366815U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 10172544755256706767U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 4013006212154771797U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17340067939877432472U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14130447570008179105U;
            aOrbiterC = RotL64((aOrbiterC * 8178075071208718915U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2652532710498072378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10384945384238518296U;
            aOrbiterH = RotL64((aOrbiterH * 17137694272394304045U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15292159041119433363U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12103644911645285108U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4565615406415614103U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16307525158627275744U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3786908390177579447U;
            aOrbiterB = RotL64((aOrbiterB * 6592585847755318801U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13595883419843505634U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10805654776556844351U;
            aOrbiterI = RotL64((aOrbiterI * 10956465099104915639U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 46U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 23U)) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterI, 6U)) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 51U)) + aOrbiterG) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 26U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22773U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 26841U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26162U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27040U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 24U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 51U)) + 5160910997561396461U) + aNonceWordF;
            aOrbiterF = ((aWandererE + RotL64(aCross, 53U)) + 14920764751058512062U) + aNonceWordI;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 41U)) + 6080952401749660022U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 37U)) + 17667234330526298627U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 19U)) + 760630072638686756U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 3504157162816997476U) + aNonceWordJ;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 35U)) + 9489022223422585882U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 39U)) + 1149898536879968964U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 43U)) + 10492284328940025310U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 28U)) + RotL64(aCarry, 35U)) + 13213275606286399312U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 21U)) + 10557118912847180413U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15618980209023994776U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5268600749854045564U;
            aOrbiterI = RotL64((aOrbiterI * 3849660559223919613U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8011552687609649990U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3148133096349525066U;
            aOrbiterE = RotL64((aOrbiterE * 5245156554959620007U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12032847944237867285U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 14999005703490824673U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 6631584955208646049U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5426735969392906710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3593177531650386729U;
            aOrbiterK = RotL64((aOrbiterK * 12997284886192717043U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1701444719333347373U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15928731228196894960U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 1919318226904213433U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5960179456039157036U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5716434224061596483U;
            aOrbiterH = RotL64((aOrbiterH * 3731976564761202801U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2136841536293340279U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12969550408652728526U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7612191387451455137U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3641997570461447114U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4677572491523684525U;
            aOrbiterB = RotL64((aOrbiterB * 2730358077882211651U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2741372094325164504U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4998631511811832690U;
            aOrbiterA = RotL64((aOrbiterA * 10619395395977372695U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6260464862798783617U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16489087874167346533U;
            aOrbiterF = RotL64((aOrbiterF * 11278053967185244867U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7043760915859224327U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5160910997561396461U;
            aOrbiterD = RotL64((aOrbiterD * 15260149870590431675U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 34U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 60U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 40U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29512U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32343U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30311U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27749U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 3U)) + 16451272412693907816U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 6U)) + 10099485419723255462U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 17668900099534923192U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 23U)) + 5497093724143181753U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 13U)) + 10354044773550071706U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 12728258851198019099U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 29U)) + 4144050505314242618U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 14133805325480076530U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 19U)) + 308863673210602899U;
            aOrbiterK = (aWandererB + RotL64(aCross, 53U)) + 11741180130160569753U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 21U)) + 12926863156769180448U) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 211920854786494259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13234608842479411078U;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9164711974854618892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6667377062281954219U;
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 4559040002406721850U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1749875480850675109U;
            aOrbiterB = RotL64((aOrbiterB * 15822640067349481089U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9555365165561936366U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18289733999504213574U;
            aOrbiterJ = RotL64((aOrbiterJ * 14156217554673229429U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8727162691639622461U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 291406782452963706U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8294911802626492257U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15853578397277298548U;
            aOrbiterG = RotL64((aOrbiterG * 13256191781365357747U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11535146194939658681U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2177540476748375661U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15791341922007841029U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2705306323728084136U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17617871830709148043U;
            aOrbiterF = RotL64((aOrbiterF * 3449981219502809255U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3699834746313613206U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17952609181629473245U;
            aOrbiterE = RotL64((aOrbiterE * 6103160209028988839U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 8016694658897707674U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6971251395823324489U;
            aOrbiterH = RotL64((aOrbiterH * 13483776115929040277U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17467528888050817915U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16451272412693907816U;
            aOrbiterC = RotL64((aOrbiterC * 13689734638238895071U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 56U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 40U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 24U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 54U) + RotL64(aOrbiterH, 35U)) + aOrbiterE) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Hockey_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2384U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 1785U)) & W_KEY1], 4U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 857U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1866U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 39U)) + 12775735908960052604U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 11791373812080296887U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 27U)) + 5537362877706057303U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 2023912048504189380U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 19U)) + 17668828109963766893U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 13U)) + 558908629933941224U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 1479633119685446888U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 4U)) + 15460320397843364063U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 53U)) + 10059749397555469054U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 9987633811929693924U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10087337844580228269U;
            aOrbiterE = RotL64((aOrbiterE * 13817142288940843815U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4446204415503364254U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15106063243302192717U;
            aOrbiterF = RotL64((aOrbiterF * 13273756657334709803U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9430197906134676162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10611580584157624739U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3137391249289641509U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5462682413239873181U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9327201928815412810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterK = RotL64((aOrbiterK * 13827717178378062047U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10675114832750356941U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterA = RotL64((aOrbiterA * 8520671775587260601U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12871947817782057116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11015991745792051390U;
            aOrbiterI = RotL64((aOrbiterI * 17152451500505815031U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6320437975845673731U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 702457937087191287U;
            aOrbiterH = RotL64((aOrbiterH * 17491257114676739589U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16629064896250312921U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6054107387816339103U;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 44U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererH = aWandererH + (((RotL64(aIngress, 22U) + RotL64(aOrbiterA, 11U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 60U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + aOrbiterF) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15230U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((aIndex + 9405U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10541U)) & W_KEY1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 13870U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 60U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 39U)) + 5480870806135400132U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 13U)) + 8034874599430768743U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 19U)) + 4006919843736863767U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 24U)) + 2988069748674633718U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 12347295651973135786U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 14152683894431568192U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 51U)) + 15765143815254196598U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 10473067082331244233U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 44U)) + 1089466925383677249U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13215039929873682230U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3957997712247961479U;
            aOrbiterH = RotL64((aOrbiterH * 7631186240013784703U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10023907397941685546U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14593012591254614353U;
            aOrbiterG = RotL64((aOrbiterG * 17111300092082154687U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13353797968154036726U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9259966668512102858U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8326732574268308221U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10757861831070349321U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10530223113483866178U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11269177745265396583U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7554320926405521865U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6978052067277966996U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18020134738536217801U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1053695861967171420U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15980734683539854451U;
            aOrbiterJ = RotL64((aOrbiterJ * 3208466640010555357U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17041258393808061556U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12846551858751995530U;
            aOrbiterD = RotL64((aOrbiterD * 9303891433380993639U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14617434286683320666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3999309956180741302U;
            aOrbiterC = RotL64((aOrbiterC * 15037707937050015205U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13452627760403094126U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2633241575260427158U;
            aOrbiterA = RotL64((aOrbiterA * 2638570213290747581U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 36U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererC = aWandererC + (((RotL64(aIngress, 18U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterD, 36U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 29U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24239U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22002U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 22570U)) & W_KEY1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 18163U)) & W_KEY1], 6U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 52U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 4739486756133131180U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 10U)) + RotL64(aCarry, 51U)) + 16089707555501328184U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 47U)) + 15310047330238536453U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 19U)) + 7901411596386834955U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 23U)) + 4357555491060982163U) + aPhaseCOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 58U)) + 15667085602825720102U) + aPhaseCOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 8520635334382269253U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 5U)) + 1772509779231068315U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 53U)) + 15336170957886025677U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8628770833489469980U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15469234024247246228U;
            aOrbiterH = RotL64((aOrbiterH * 8905266995119987947U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10796430900884288328U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10660110397012853289U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9140007610912037461U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11202284258711214794U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17509491802893182994U;
            aOrbiterI = RotL64((aOrbiterI * 9329107599972703671U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16212572740740103554U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2190030203761579226U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3101886685668871045U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12014337082293041909U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3733531010807001506U;
            aOrbiterG = RotL64((aOrbiterG * 5797362244066062299U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7100994963061975529U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17837541162838600258U;
            aOrbiterE = RotL64((aOrbiterE * 8745987361678166553U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3311518938023146951U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7709505172646831553U;
            aOrbiterK = RotL64((aOrbiterK * 7121143171245765213U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4979968094554018443U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16822214821463034107U;
            aOrbiterJ = RotL64((aOrbiterJ * 8618262120451291765U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8376124175020587079U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11084586282092424876U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5835632742522563537U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterH, 22U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 14U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 46U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25978U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 27591U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25265U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((aIndex + 29181U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 54U)) + 1042610313571524121U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 3505725321008825582U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 47U)) + 12584654563843782991U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 6645399144515770935U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + 3608978423753715584U) + aPhaseCOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 8089198857670370983U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 37U)) + 15207251813516399879U;
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 9579268660105824516U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 18U)) + 16055044469473802812U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 583811872609805949U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7027491967970873942U;
            aOrbiterB = RotL64((aOrbiterB * 12686754713465826139U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18256061823189677508U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterD = RotL64((aOrbiterD * 12593886633108075321U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 12169216645156306078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12694325407567795065U;
            aOrbiterA = RotL64((aOrbiterA * 3711789483877261899U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16109994660203297503U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4234704064165718913U;
            aOrbiterJ = RotL64((aOrbiterJ * 730085881474787681U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14119541943554602878U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8777769004811352951U;
            aOrbiterC = RotL64((aOrbiterC * 2556957257736134223U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15642663488392549609U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11594468530833278624U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6639306656361601143U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7365350535791499871U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5965170981970155956U;
            aOrbiterK = RotL64((aOrbiterK * 1898702752753066851U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9115232101451815522U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9433983580038990072U;
            aOrbiterF = RotL64((aOrbiterF * 1951249217843992179U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8810565477444156140U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12081286530401844859U;
            aOrbiterI = RotL64((aOrbiterI * 1991383259486140229U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 34U)) + RotL64(aCarry, 21U)) + aPhaseCWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 60U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Hockey_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1145U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3608U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1804U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1901U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 41U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 18U)) + RotL64(aCarry, 53U)) + 4622023259121087483U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 10253505250223501352U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + 17133877904420462669U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 6162827793741796700U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 51U)) + 9610986424765907615U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11210747154264753754U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16554205219580654546U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12754735039924859911U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10352576357413766388U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3651845783283479752U;
            aOrbiterJ = RotL64((aOrbiterJ * 1011289824180799641U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18145542190463500476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5415609566767162857U;
            aOrbiterH = RotL64((aOrbiterH * 6474184559323816389U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2033734872464201570U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3507213117125813345U;
            aOrbiterK = RotL64((aOrbiterK * 5453058336688881113U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8716253393049851856U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 695984869565941856U;
            aOrbiterD = RotL64((aOrbiterD * 8377921610764044735U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 40U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 42U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + aPhaseDWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 24U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9753U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14749U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13129U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9679U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 15813325389431304548U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 2223874171125403602U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 3U)) + 5510483568496824130U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 46U)) + RotL64(aCarry, 5U)) + 15474152493495661876U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 11U)) + 16846339705130829195U) + aPhaseDOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1289670576865739669U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18017354919647006944U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13103155460891498469U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8539685539928984921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3333721400836704048U;
            aOrbiterA = RotL64((aOrbiterA * 3745286323481400085U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2261560416623815491U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4377786131746816567U;
            aOrbiterD = RotL64((aOrbiterD * 9164777834392621157U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18047393176583722719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 8184724021940434631U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9800116157750921119U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10469895939183324807U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14543391765109879223U;
            aOrbiterE = RotL64((aOrbiterE * 4817987697437667225U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 57U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 4U)) + aOrbiterA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23145U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22429U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18522U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23852U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 12206125048349568300U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 39U)) + 5843520589343188818U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 12195046124287121687U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 30U)) + RotL64(aCarry, 21U)) + 16769779119214020640U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 21U)) + 5257603646260695833U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8523523946234886745U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7316024684200084096U;
            aOrbiterJ = RotL64((aOrbiterJ * 11620083021691341337U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11996978575084115207U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15491711479085513628U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15136690392026011819U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6036648530996821484U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 926323222234121863U;
            aOrbiterD = RotL64((aOrbiterD * 6639661141258803779U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2700323841295743492U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5852273765810284935U;
            aOrbiterF = RotL64((aOrbiterF * 16665696735016345215U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11697397483133538067U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17777142964957007194U;
            aOrbiterC = RotL64((aOrbiterC * 6338967222543284999U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 10U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25593U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneB[((aIndex + 27376U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32232U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31278U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 37U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aIngress, 3U)) + 8793908991006073956U) + aPhaseDOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 2932916283348441943U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 11069042087940968262U;
            aOrbiterF = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 14369628676782894441U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 39U)) + 8602903272780978282U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3827036107178568820U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8905245209036772489U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5744017326197157667U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13331387530760017893U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 9880107580289737823U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10302652857542703753U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10199619040626900278U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2466307560891374281U;
            aOrbiterF = RotL64((aOrbiterF * 6295342978834217571U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13973403407981259448U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2851460278409385243U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11226902976321781743U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10365453393815690776U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2382382358987358791U;
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 54U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 29U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
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

void TwistExpander_Hockey_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1524U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3646U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3997U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((aIndex + 1341U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 14U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 23U)) + 14179205183062705133U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 51U)) + 210032324058740920U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 7387115089142500152U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 17583362781238061430U;
            aOrbiterB = (aWandererB + RotL64(aCross, 36U)) + 4991442849150005943U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 11U)) + 2891376254689854555U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 10523274382407446239U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3861893764676218667U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3366674459852093746U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14005994095369483813U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5898492634386601145U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7047353571244768721U;
            aOrbiterB = RotL64((aOrbiterB * 2257518291062508467U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14374108805453186316U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8763667021501226510U;
            aOrbiterA = RotL64((aOrbiterA * 7694695426430267863U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18261523829316379575U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 650477532238860965U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2162326554604894042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5776546692501825278U;
            aOrbiterH = RotL64((aOrbiterH * 14911545784585246537U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3501863793638415049U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14853789267425352958U;
            aOrbiterK = RotL64((aOrbiterK * 10590325397179928739U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15399673014671329743U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12253428583438990426U;
            aOrbiterF = RotL64((aOrbiterF * 12052855472196447849U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 36U));
            aWandererG = aWandererG + (((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 21U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 43U)) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererH, 28U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16165U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 13784U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9104U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((aIndex + 13871U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 16424657151168221875U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 17150123681886380361U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 21U)) + 16041993588694572757U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 9871185846434828537U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 4U)) + 11227236398354430757U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 29U)) + 5399325217402192631U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 43U)) + 9248828789282890454U) + aPhaseEOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9041370494203701062U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14944424084524970764U;
            aOrbiterA = RotL64((aOrbiterA * 10283363059424655079U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5481938174456671041U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14783648629543752715U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7260164783191886395U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12355573914530445723U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9863991559011968318U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8495251211794343179U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16149688605937250965U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 106041828692026825U;
            aOrbiterH = RotL64((aOrbiterH * 12199934305374582599U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8076098639554567792U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11155119311895580013U;
            aOrbiterK = RotL64((aOrbiterK * 1495180896564818647U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6847612160595917702U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16094377920388017367U;
            aOrbiterG = RotL64((aOrbiterG * 4875801863643206333U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13584719866672696684U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13446209321646234607U;
            aOrbiterF = RotL64((aOrbiterF * 9945349065094781529U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 14U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 24U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16819U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24106U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20538U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneC[((aIndex + 23685U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 9774364261626083532U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 51U)) + 18059001521926116420U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 44U)) + 10615626210406381148U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 10536484278007898620U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 11U)) + 13320663045139972700U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 37U)) + 17127001787268166583U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 16742574590844166551U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8347719720758228053U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13502468705946051986U;
            aOrbiterJ = RotL64((aOrbiterJ * 13822952083584784695U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3512687886188904904U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 495660316165795934U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6724596801190194913U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5092722552034477356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15641128019608284015U;
            aOrbiterI = RotL64((aOrbiterI * 3621036395703527059U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15421873776811085458U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 17978775513204574125U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18359600395119440183U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16617179197537669849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1931805387534012528U;
            aOrbiterE = RotL64((aOrbiterE * 3400139345857733775U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9544923119559308431U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12930999400470173353U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16791006919271490005U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13673733276226249890U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2032263473309124738U;
            aOrbiterB = RotL64((aOrbiterB * 3088728329261360607U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterK, 30U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 41U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterE, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32271U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29901U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30741U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 28914U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 14823268998003220191U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 53U)) + 15295237288788213847U;
            aOrbiterI = (aWandererF + RotL64(aCross, 47U)) + 16434853402001133899U;
            aOrbiterJ = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 7555911304407871631U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 14977248264994834620U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 60U)) + 9707764144919392380U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 5U)) + 1277304385464681529U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3089786220465849395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3700503853358695085U;
            aOrbiterI = RotL64((aOrbiterI * 2079089949442685421U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3240054112993517371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16897532076915366859U;
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 18167359289798364307U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8870819278575769863U;
            aOrbiterA = RotL64((aOrbiterA * 9334066154398059075U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15363069206212330251U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14858164441499725158U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14931933411393847915U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5357144808788707522U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2910681277417754860U;
            aOrbiterG = RotL64((aOrbiterG * 13170868582159347059U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9824408699018165151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14358982366258729959U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7095398304588825115U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11418879758164313554U;
            aOrbiterC = RotL64((aOrbiterC * 5983520332639771791U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 60U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterC, 53U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Hockey_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1119U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5488U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 264U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3343U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 18U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 54U)) + RotL64(aCarry, 23U)) + 3973833383430652211U) + aPhaseFOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 5760227042747169187U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 4923009065139227286U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 3U)) + 1477807307009107590U;
            aOrbiterB = (aWandererE + RotL64(aCross, 21U)) + 5707194514329007301U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5340439728375269724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17080457898946572387U;
            aOrbiterK = RotL64((aOrbiterK * 17719588880215414933U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 281559150259472813U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16160633048230910560U;
            aOrbiterD = RotL64((aOrbiterD * 16883442583309073785U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9003989610509592121U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10579322462808454333U;
            aOrbiterJ = RotL64((aOrbiterJ * 100832431598087235U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15059383289528723069U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10417647757852880956U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1457919230286043137U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 14484665027393813330U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12344463053485837974U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5762654194001525041U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13396U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 8247U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8558U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 12358U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 12U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 27U)) + 18319689184146942855U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 8041304130090501019U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 11347064191990897738U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 21U)) + 15242243470024447468U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aPrevious, 11U)) + 10619749107163611105U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14795614276221947128U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1578095288886372393U;
            aOrbiterJ = RotL64((aOrbiterJ * 9953192041564147241U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 13593906305770501684U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8919815528334599172U;
            aOrbiterF = RotL64((aOrbiterF * 2033810402808238127U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17425548324720065145U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 11125018338392347335U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4377887040461528587U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3779189180734244399U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10958224663276134041U;
            aOrbiterD = RotL64((aOrbiterD * 6206963519509783781U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4317305352561612995U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4891139433808505355U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16908U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 20543U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19722U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16650U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 60U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 17081642665820489793U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 51U)) + 14468854040067229623U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 13U)) + 2249450222593057429U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 14964389079511378664U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 47U)) + 17003491054252360650U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12710882240582032588U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9887078182156755359U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8205865025853482573U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7665284531810584704U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7304284015511876717U;
            aOrbiterF = RotL64((aOrbiterF * 6193179739025093929U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5517927023543751734U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17704756310857362759U;
            aOrbiterA = RotL64((aOrbiterA * 15826832172923213591U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11347400363019508578U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11696395232760991243U;
            aOrbiterI = RotL64((aOrbiterI * 9725231749679442003U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10875780291242873583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7808740614343437672U;
            aOrbiterD = RotL64((aOrbiterD * 8889516201913716283U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 56U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterI, 4U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26148U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31233U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26657U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25431U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererJ + RotL64(aCross, 30U)) + RotL64(aCarry, 13U)) + 13583136155674166402U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 12830472187484919497U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 47U)) + 18081197909484522509U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 57U)) + 8680634051297891550U) + aPhaseFOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 11U)) + 13939998767458656823U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1795730579103692594U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17369751719734069999U;
            aOrbiterI = RotL64((aOrbiterI * 2633464694273697123U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 224769585901248068U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4133547085925268180U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2611561365156544735U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7022512056309567391U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10319484359046945495U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3400140531307001933U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10483878349412282069U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6481381149199985736U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9701719367082506253U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13721077228796934509U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9704818014314175007U;
            aOrbiterA = RotL64((aOrbiterA * 760445624027740287U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 40U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Hockey_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5396U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1264U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5829U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7364U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 12U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 9888431329297626900U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 2937735167534624403U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 4U)) + RotL64(aCarry, 5U)) + 17626022970343789617U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aIngress, 21U)) + 5665660859333693743U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 29U)) + 1060537034632076669U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 743777763907175800U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5744905970181808845U;
            aOrbiterI = RotL64((aOrbiterI * 17426701505806885785U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3545351394494002180U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 4877547088414106007U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5416792889338547109U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11669378338379598445U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2961072441706158212U;
            aOrbiterH = RotL64((aOrbiterH * 2677988507090705371U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13984945589234919765U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1433097875470903205U;
            aOrbiterG = RotL64((aOrbiterG * 451996840039906781U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 716415411025451152U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8542286150858297810U;
            aOrbiterD = RotL64((aOrbiterD * 9139015340823332449U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14997U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((aIndex + 10129U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16379U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 9963U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 48U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aIngress, 29U)) + 2617613537256538553U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 5U)) + 16642868916835132715U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 10860291124337073254U) + aPhaseGOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 6432511273906902472U) + aPhaseGOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 37U)) + 7505375005848241910U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11086616004678821329U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3298830587569881951U;
            aOrbiterH = RotL64((aOrbiterH * 4304047944073454489U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9775143140064220979U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4147601326580823120U;
            aOrbiterG = RotL64((aOrbiterG * 13462244678782260871U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12245920269898100415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8391940489176734499U;
            aOrbiterF = RotL64((aOrbiterF * 9119606167674098007U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17876893379544668477U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 18301882058180370541U;
            aOrbiterA = RotL64((aOrbiterA * 16680384667098921309U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 6869225862715140102U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 18U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 16420U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18439U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16436U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17411U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 4U)) + RotL64(aCarry, 3U)) + 17936518874386450467U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 53U)) + 13722737841589910344U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 11774969167948715796U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 3640101505680493777U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 41U)) + 1369495382725650822U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11827310354654653345U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 186037671377175394U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 829791264853993897U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11428829344234627340U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 2275016369870029068U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14936799202145280833U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15471646673734798328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12172082573115640145U;
            aOrbiterB = RotL64((aOrbiterB * 9629417882787847753U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6626736341348283154U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12220614992483863623U;
            aOrbiterE = RotL64((aOrbiterE * 8137086205714097487U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13157102324253760215U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4143587482368093601U;
            aOrbiterG = RotL64((aOrbiterG * 5060677690991506895U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererC = aWandererC + (((RotL64(aCross, 30U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 48U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30576U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 30234U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29835U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 28084U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 24U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 54U)) + RotL64(aCarry, 35U)) + 4980738603982643969U) + aPhaseGOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 17660278413018470020U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 17598114429859543466U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 29U)) + 10993929335279994739U) + aPhaseGOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 5U)) + 17967203122976322481U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1872290205549034384U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16607778671782810797U;
            aOrbiterH = RotL64((aOrbiterH * 340054507611349681U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4895226930754394376U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14960359005982301383U;
            aOrbiterI = RotL64((aOrbiterI * 8546231310054433721U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9921642352377700630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 893281964367208693U;
            aOrbiterG = RotL64((aOrbiterG * 2345509157333444217U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8232519988397858732U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4433022122758913407U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 834240393225479419U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12689609831247168353U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 404535388957472176U;
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 20U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 36U)) + aOrbiterG) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Hockey_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 3224U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 7409U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 140U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 3864U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 6521330037475130256U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 12611880456055428940U;
            aOrbiterF = (aWandererK + RotL64(aCross, 26U)) + 12061611078130934708U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 1558112410801116984U) + aPhaseHOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + 10509115227850160786U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4045915960688792066U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1196541286513243082U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5454309408259753479U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15564991032722373702U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4897765238703641798U;
            aOrbiterK = RotL64((aOrbiterK * 9693901276712946763U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12327429514907752733U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6189189797708711636U;
            aOrbiterE = RotL64((aOrbiterE * 9017615866338877651U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6374267075282018852U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1888758503831341439U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 74387714918264257U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14956857689299491800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14879361107223331957U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 60U));
            aWandererK = aWandererK + ((((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10068U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 13056U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9242U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 15931U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 37U)) + 15904465836916519864U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 22U)) + RotL64(aCarry, 39U)) + 17725629806317789307U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 47U)) + 13794170125914914828U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 2149055907476874332U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 5342047776745074649U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8268148484060546838U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10821151364028563719U;
            aOrbiterB = RotL64((aOrbiterB * 13626634259250509711U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4294213820894407378U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10884726101307943090U;
            aOrbiterI = RotL64((aOrbiterI * 1116128870387229159U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16432210042202444824U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 15196602644336228055U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12680438355124070237U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14117787670220328165U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 219833877949480215U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10736293047771972173U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3326396981881473962U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14918513066311426279U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14269763278564574663U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterB, 39U)) + aPhaseHWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 56U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23046U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 17411U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20924U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16759U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 3U)) + 15549114274303128055U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 42U)) + RotL64(aCarry, 57U)) + 16466750056388063241U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 12209449840836787142U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 14551496099734294336U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aPrevious, 23U)) + 6266576428679808622U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16892841575635668152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7375966221423362125U;
            aOrbiterH = RotL64((aOrbiterH * 15338878556107177587U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11926105302821753530U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16219253791550461124U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2117550758226173419U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7299056065319248160U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15234001484933728439U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8182244796017018911U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6615802589932632120U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5481176858895819247U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3604590158551984877U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17220507586542139380U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterB = RotL64((aOrbiterB * 10634645686035907603U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterG, 60U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 31226U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25093U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32218U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 30392U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 58U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 3550722402315312207U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 16724184551669522754U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 18U)) + 981751330116773021U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 7891159229704944868U) + aPhaseHOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 37U)) + 13618396711464799841U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5969291018449003648U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14595540413313640042U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8151104319012840963U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3287990436916111762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12534369400200483704U;
            aOrbiterD = RotL64((aOrbiterD * 2345945228434740707U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2277312067930392274U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10026320559261334353U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11020464940995912637U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11258082063135659551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1445958517675746990U;
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1011298251290970844U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6487834862470043744U;
            aOrbiterK = RotL64((aOrbiterK * 15477913837027179675U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 60U)) + aOrbiterC) + aPhaseHWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererE, 42U);
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
