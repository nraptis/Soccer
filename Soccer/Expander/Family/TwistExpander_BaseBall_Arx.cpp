#include "TwistExpander_BaseBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BaseBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF097D43ECC4006F1ULL + 0xE0F4328FB673AF69ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB6DDA908FD8B40FFULL + 0xED3B296C6870A608ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF3A60023F5EDD9BDULL + 0xB9224EA8E973E5C4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8F7D22D739BA87FFULL + 0xD0335AF14AF9ACEFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBE1DBAFC52AD136DULL + 0xD1B51E4AA4CF6B28ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8D5A953DA8B9B507ULL + 0xF3E03EAA32D6B733ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8F0BCFA549CD977BULL + 0x87E84AB8922189E5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9C4ABE7F49E94D47ULL + 0xEB5488B3CCCC4CE7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD1BBEC086E2D7643ULL + 0x831872B6580639FFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAF4A1C552E46D32DULL + 0xD1208CB11BC0AFEBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC9CCA7DBB0EDD62BULL + 0xD504FCDF70FAD41FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC490BB6DBC7EE39DULL + 0xF02BAED295A7DF32ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9758955945C2E4CDULL + 0x8FB7BE19B17DEA97ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE2E28519A601A9E7ULL + 0xF44B0C239E199E30ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9692F376B4791177ULL + 0xF56D4225F99FE2CAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xADF75FB657E9F32DULL + 0xD4FBB0FCCCCC732FULL);
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
            aIngress = RotL64(mSource[((aIndex + 5357U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 2902U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 4715U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((aIndex + 3149U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 44U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 57U)) + 9107326720193244489U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 37U)) + 10868585484401664145U) + aNonceWordJ;
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 13637736741437846622U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 6130725216183918844U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 37U)) + 2063834478521338187U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 10U)) + 8564870627911949158U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 43U)) + 6524015751064086390U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 29U)) + 9874937766875388236U) + aNonceWordI;
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 14723718409522680894U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 21U)) + 13767059954741528279U) + aNonceWordG;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 39U)) + 6387608251033722169U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5391425980008431000U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11524218415655093779U;
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 155510463350385905U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10554591788433641311U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 5412084824127934293U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 8662160162966241542U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5092555636369853727U;
            aOrbiterK = RotL64((aOrbiterK * 433807340167635499U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7163345798448796101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 695089002178413267U;
            aOrbiterI = RotL64((aOrbiterI * 17302689458565434475U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5409173939213468972U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15349690077393827541U;
            aOrbiterB = RotL64((aOrbiterB * 10984681254001609841U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12376011890751302027U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7809614158898158383U;
            aOrbiterA = RotL64((aOrbiterA * 13845113198736843629U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13031938699536449576U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 3983178190194056516U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1341678482929213405U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5567935037909671790U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17137042627663349797U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 13535586899620672373U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8726085717433137208U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13154097637429217548U;
            aOrbiterG = RotL64((aOrbiterG * 5523758597936082363U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4030516340575723215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7121696965917254968U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13569584361980228493U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12079991626282752674U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9107326720193244489U;
            aOrbiterF = RotL64((aOrbiterF * 7225937408665051799U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 48U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 10U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 3U)) + aOrbiterC) + aNonceWordM);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 26U));
            aWandererK = aWandererK + ((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 3U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5892U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 5758U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9777U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 7740U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 50U)) + 9471546960258473684U) + aNonceWordA;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 18050235435948942244U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 5U)) + 3005107102671544641U;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 17898396434573801850U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 15071602525497771648U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 5780119462702672108U;
            aOrbiterB = (aWandererC + RotL64(aCross, 23U)) + 13301326224151025687U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 11U)) + 18129323022260575961U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 18U)) + 1199228670638790709U) + aNonceWordD;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 3U)) + 1839199978088021020U) + aNonceWordK;
            aOrbiterI = (aWandererF + RotL64(aCross, 39U)) + 4999517042246790165U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8788607633376516299U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15143903839930468749U;
            aOrbiterJ = RotL64((aOrbiterJ * 12735914889325422675U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16674732686428431869U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11204775359756474667U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2525984309543939465U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 3988529812023791571U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4566345170476825512U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 14876612901557406267U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 9047956948845135339U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14926290877038883931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12710203178186614846U;
            aOrbiterK = RotL64((aOrbiterK * 14841163494801662515U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7315094513967387996U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 11050116830482816766U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 3702999495721152019U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4505368486032503953U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17905748055257551092U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 14775870175093453197U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5728886950801376350U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17998141690182325170U;
            aOrbiterG = RotL64((aOrbiterG * 16008599930125391379U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4325978018819134558U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13526905108565989379U;
            aOrbiterA = RotL64((aOrbiterA * 14121321495714166291U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10597169665474269506U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7500801022830471869U;
            aOrbiterD = RotL64((aOrbiterD * 3702717219742363777U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17063616328548689935U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9471546960258473684U;
            aOrbiterI = RotL64((aOrbiterI * 3029748230803396737U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 24U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 36U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterF, 39U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 3U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 23U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 26U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 12U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 14328U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13446U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12503U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 13995U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 52U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 13687218104610230596U) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 6841550124960692709U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 51U)) + 17418968668458764131U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 8303537912696948204U;
            aOrbiterC = (aWandererD + RotL64(aCross, 54U)) + 12376614417285936537U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 27U)) + 14215749063579232654U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 13U)) + 4111736931433665347U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 21U)) + 11250375934571631522U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 44U)) + RotL64(aCarry, 21U)) + 5367367837773331275U;
            aOrbiterK = (aWandererG + RotL64(aCross, 41U)) + 15514089192382674434U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 37U)) + 1475991716685034960U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 5531622777788629748U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8363822215908303335U;
            aOrbiterJ = RotL64((aOrbiterJ * 17850203366840994883U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3741256932685720414U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11634667238062155772U;
            aOrbiterC = RotL64((aOrbiterC * 15925089729784547403U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18180546911210417155U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5123234656838556335U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15362857462853398025U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11215734271189250284U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16863747802158398092U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1828035970246160023U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9859050606636646323U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9331300036643654675U;
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15028845665427209759U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8916444839488901676U;
            aOrbiterH = RotL64((aOrbiterH * 6646561894156038791U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8024631140949068570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1116378858490660031U;
            aOrbiterK = RotL64((aOrbiterK * 4247798531910227367U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5066486214537899212U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9346312092322423057U;
            aOrbiterB = RotL64((aOrbiterB * 13443190089768875191U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11651011617027950122U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11308862427412671711U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12167147966934334703U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3850136281462840708U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13461307727665667424U;
            aOrbiterG = RotL64((aOrbiterG * 10788040812090673421U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17824744996404571928U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13687218104610230596U;
            aOrbiterE = RotL64((aOrbiterE * 325803029547254631U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterK, 54U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ) + aNonceWordA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 52U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 6U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterC, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 28U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 40U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18449U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16886U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 19069U)) & S_BLOCK1], 50U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21276U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 20838U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 18U)) + 9914837590440975587U) + aNonceWordJ;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 29U)) + 6706125076401958051U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 51U)) + 16570817772679258409U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 6843705658115186948U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 3U)) + 16099930446791572351U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 5420550009556030459U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = ((((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 11U)) + 5729549069420177477U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererE + RotL64(aCross, 46U)) + 15590601126188675834U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 5U)) + 13044027390998620029U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 13U)) + 11068338135659636772U) + aNonceWordI;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 57U)) + 6584988841809544332U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8516813219883915404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10647314042912492785U;
            aOrbiterK = RotL64((aOrbiterK * 15559481057047148785U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 201691689889605304U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 15512161798401184003U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11473219183982564709U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3883760518944464145U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterB = RotL64((aOrbiterB * 17194438894492581181U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12019138626550801486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13030350224959652248U;
            aOrbiterI = RotL64((aOrbiterI * 11724200983306280107U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 2643807255422544248U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14602951930809633069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4555737199162278494U;
            aOrbiterH = RotL64((aOrbiterH * 12415825635220991865U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 6343143902997169834U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10404783711336491985U;
            aOrbiterJ = RotL64((aOrbiterJ * 6235474458879439079U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7406959231434835393U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6684368109277850196U;
            aOrbiterG = RotL64((aOrbiterG * 8760360417572331159U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4835889355927954728U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7917682889852676712U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 9045350756570117327U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10268055422944417055U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5563744562922937643U;
            aOrbiterF = RotL64((aOrbiterF * 12442484191329795173U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17244672945880141679U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9914837590440975587U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 12269340309792850489U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 22U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 4U) + aOrbiterG) + RotL64(aOrbiterK, 37U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 48U));
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterD) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 6U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 24942U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 24496U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(pSnow[((aIndex + 26488U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 26031U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22665U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25139U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererB + RotL64(aScatter, 10U)) + 7893287783892523139U) + aNonceWordG;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 10257331997383491153U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aIngress, 19U)) + 14562226733652231753U;
            aOrbiterH = (aWandererG + RotL64(aCross, 29U)) + 14320342577110737851U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 23U)) + 9816717579822880756U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 35U)) + 9558926960095881953U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 14U)) + 9230371862654338324U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 43U)) + 6414274291252913420U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 13868546184398350849U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 16940736952569949038U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 37U)) + 2866957764814864371U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7916721976073979724U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1602444214978842275U;
            aOrbiterD = RotL64((aOrbiterD * 11072503711308122385U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9529061385251008037U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8402775110887376588U;
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15003592180290390713U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14195681406520825751U;
            aOrbiterI = RotL64((aOrbiterI * 11455000833788877217U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3263577002367714202U) + aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12019422062655581928U;
            aOrbiterA = RotL64((aOrbiterA * 5002313835338447799U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8508638054582582917U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6536618106353552880U;
            aOrbiterG = RotL64((aOrbiterG * 6233964121117511885U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9654542989321430868U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7019594782797863244U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 1234877854354279981U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8256061220727519919U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9232754129467036130U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17556001874302369781U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5608829951337740378U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12632120498473345701U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6994794653605831925U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17313364434369677697U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10147405701828074385U;
            aOrbiterC = RotL64((aOrbiterC * 11544579984323623009U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16853703086012867980U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3591438641820423822U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 3570430739475340845U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13974806289212867511U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7893287783892523139U;
            aOrbiterJ = RotL64((aOrbiterJ * 6648351608953339723U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 3U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 5U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterG, 30U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28170U)) & S_BLOCK1], 10U) ^ RotL64(pSnow[((aIndex + 31684U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31670U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31415U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32618U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31611U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 42U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 77518479758428414U) + aNonceWordA;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 6U)) + 4832061802166300011U;
            aOrbiterH = (aWandererH + RotL64(aCross, 21U)) + 11695291171006574112U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 57U)) + 7467412817843260094U;
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 17801484124471154757U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererG + RotL64(aIngress, 3U)) + 5555455638503958639U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 35U)) + 5669470540733721606U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 19U)) + 3042388456327784163U) + aNonceWordD;
            aOrbiterE = (aWandererI + RotL64(aIngress, 51U)) + 2236734925228156691U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 23U)) + 14459720401528685450U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 43U)) + 4814967631216658856U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16950679344449075945U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6262238639302011050U;
            aOrbiterH = RotL64((aOrbiterH * 9942659897425088183U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3522256359074996724U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterG = RotL64((aOrbiterG * 6787771338063891989U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 13891759914865623828U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12311343917878428995U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2240189915640314069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5365912986308810837U;
            aOrbiterE = RotL64((aOrbiterE * 15133972552032469957U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9323732721344489753U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13087326560957916553U;
            aOrbiterC = RotL64((aOrbiterC * 14659491687401151733U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16398238057564892809U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11517870519285159224U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 1501848878469712681U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7758285512254776734U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17475149091906684720U;
            aOrbiterJ = RotL64((aOrbiterJ * 6015816725428299273U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2051631493975035243U) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11684740065349595315U;
            aOrbiterD = RotL64((aOrbiterD * 10918975496337269197U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10575473798991451167U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8267005776169272822U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13166868678285963961U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6249698995716039231U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13808085811784323978U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3897731011582061983U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2739364646624876985U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 77518479758428414U;
            aOrbiterF = RotL64((aOrbiterF * 6977724811175035551U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterD, 50U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 39U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 12U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD ^ ((((RotL64(aCross, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + aNonceWordJ) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_BaseBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB0BD6B96F41B1F71ULL + 0xB2DCE1EABDAE6EBFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xAFFED697E0DBD80DULL + 0xFDD5BE212C5BC9B9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEA70D0D2399CD9ADULL + 0xEFF1B9EAD6617D47ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB49BD7A07A40777DULL + 0xC1C9268356F33EA2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x917C9167FB00084DULL + 0xA44DE6DD33C6BBFFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF9CBF79E763AB255ULL + 0xAC6625D6E9920CB1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEFDF902837D22D29ULL + 0xADB6E7FDF4B4DBBEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF0917A929846C86BULL + 0xCD47877B85F4FC16ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE8D41DC3415F143BULL + 0x9B1DC2D646F72100ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC9554A7461599495ULL + 0xB2FD4692ADB3BBAFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xADDB59D156ABF613ULL + 0xFDF20742E715E7EAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x95BC4FEF44AA6B85ULL + 0xAEA12890BC4145F3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x98EE4571C195620FULL + 0xA7D7C8040E6AC088ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8BF2D11781DE8B47ULL + 0xC85EA847450F95E6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA8D7122F42F987B7ULL + 0xA97E2AFA58717EE0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x96E7CC46FD5C2071ULL + 0xF475057A13BFA735ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6118U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((aIndex + 4303U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4033U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7360U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 12615321415808640429U) + aNonceWordD;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 48U)) + 15712784676459931207U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 41U)) + 11013335427004930046U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 23U)) + 8298733856304768806U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 6207732959150824216U) + aNonceWordC;
            aOrbiterE = (aWandererF + RotL64(aCross, 54U)) + 9769864876127544038U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 10782181918651152563U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 35U)) + 5790454015845620939U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 19U)) + 15606578025386733803U) + aNonceWordA;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5522352539991175304U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5993355818572869649U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 15221467311057431139U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10864534396947622047U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12090053126235913528U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7250801471645972261U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14191181677234981396U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2258570108233924592U;
            aOrbiterH = RotL64((aOrbiterH * 8307541155393855209U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8448114811381534603U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2702389315763499817U;
            aOrbiterB = RotL64((aOrbiterB * 6710443836432274393U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17202184076718780200U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 150549910056015002U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 195034681254956335U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4910512055808124967U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4783477997418403079U;
            aOrbiterD = RotL64((aOrbiterD * 861977492146512865U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13842899106208709771U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7930112618036681468U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8609551859830858419U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8790107242863198659U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6882768826643279144U;
            aOrbiterF = RotL64((aOrbiterF * 13745521454063360763U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12136498871759890015U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8120456314755584336U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1830725195528043575U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 4U)) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 40U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 14U));
            aWandererC = aWandererC + (((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterB, 43U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9426U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 10195U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11252U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12317U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 12304U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + 1457104756581596530U) + aNonceWordF;
            aOrbiterF = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 6127240317844622874U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 16492290056044189421U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 28U)) + 10963676850938416468U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 3U)) + 4872917367399752405U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 57U)) + 15218882377875616148U) + aNonceWordP;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 13U)) + 5934166612122118251U) + aNonceWordI;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 53U)) + 14215280930872003003U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 34U)) + RotL64(aCarry, 27U)) + 11428034799044600979U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5453003654321728726U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14273775120265649389U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 5139018128323795309U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 328723770018440271U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 13032190719588211088U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 13363368478932798315U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2386881543033598494U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1649501123340887116U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 11148976582360499033U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16462401546754210583U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1510579201823042227U;
            aOrbiterG = RotL64((aOrbiterG * 16287912400104043275U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6889066000014251983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11324594596597724357U;
            aOrbiterH = RotL64((aOrbiterH * 15344987814648586023U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12237796033168436537U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17306069670330000343U;
            aOrbiterC = RotL64((aOrbiterC * 3167451351403385259U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14197284538008811658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4754134852883071927U;
            aOrbiterD = RotL64((aOrbiterD * 3484427259538998699U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17201907781639753736U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8318419319239859855U;
            aOrbiterJ = RotL64((aOrbiterJ * 10320390501983802091U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16012488623961565780U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 15583721012865354925U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 10656414363201743961U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 14U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 12U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 10U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17518U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 17119U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22660U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18196U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18551U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 24134U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 52U)) + RotL64(aCarry, 41U)) + 4179952823252098240U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 41U)) + 3745613452332101749U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 2955689793395307176U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 5639060180251322019U) + aNonceWordA;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 57U)) + 7901969163853586463U) + aNonceWordM;
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 2242166787816318119U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 5239936443960750064U) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 3U)) + 13939136954732185558U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 48U)) + 17058884136712717463U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18148618660054585941U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7022023484530327814U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 650100011311048589U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7722084537340095637U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11764151879690934182U;
            aOrbiterC = RotL64((aOrbiterC * 12264384877711365655U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16412785901758144708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9666718667728274824U;
            aOrbiterJ = RotL64((aOrbiterJ * 10865799822751771795U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4307127540152109364U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2457646804702647606U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 6340030928007058595U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3179394870088602208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16182729401018310837U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7110817020445860609U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13371352088428584087U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12960656706837391973U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7103806893724395904U;
            aOrbiterD = RotL64((aOrbiterD * 14365984439655979791U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1248300178080633527U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7195473175424961337U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4633558992739305045U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13007951568242991449U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10296811247653636372U;
            aOrbiterI = RotL64((aOrbiterI * 16469682651380549395U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 42U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31101U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 27762U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 30880U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24787U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31313U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 32441U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 18U)) + 17081642665820489793U;
            aOrbiterH = ((((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 14468854040067229623U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 2249450222593057429U;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 14964389079511378664U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 29U)) + 17003491054252360650U) + aNonceWordE;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 11U)) + 12710882240582032588U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 35U)) + 9887078182156755359U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 51U)) + 7665284531810584704U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 56U)) + 7304284015511876717U) + aOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5517927023543751734U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17704756310857362759U;
            aOrbiterK = RotL64((aOrbiterK * 15826832172923213591U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11347400363019508578U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11696395232760991243U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10875780291242873583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7808740614343437672U;
            aOrbiterD = RotL64((aOrbiterD * 8889516201913716283U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3145390996141902032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16080636485642732615U;
            aOrbiterI = RotL64((aOrbiterI * 7445756373012217305U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3929263288176983844U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18210228766683996806U;
            aOrbiterC = RotL64((aOrbiterC * 13178080076505449091U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13948962323541421431U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3037683309790156893U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13406672352222636739U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17827265198532699474U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7270895262023504864U;
            aOrbiterG = RotL64((aOrbiterG * 13467417362477308167U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6431243064980879185U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6680205390976259885U;
            aOrbiterF = RotL64((aOrbiterF * 10421386694108590789U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15910655919164357152U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8046213498216027383U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18061867495824063553U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterG, 18U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordC);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 12U) + aOrbiterF) + RotL64(aOrbiterB, 23U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_BaseBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC3F25D0699DA0027ULL + 0xB66154103B21ACA5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF5667479574EBE21ULL + 0xEE3EC2156A92A925ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9F38BD2BDEC14EA5ULL + 0xE07EE9B5DF891316ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E5CE84BA4A2D369ULL + 0xBF1B7DB0840B64C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB60272EA390C39D7ULL + 0xCCF8959FA4DC76FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x96B2DE7C2A67C261ULL + 0xB9B84F4D684B8DDEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA12F7806D65670FBULL + 0xE67266BD4745A21FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEF26F7001574F627ULL + 0xFF74D2FADDC713E1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x92E92A4EE5713477ULL + 0xEA3C1E164623D03CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEB11E421337A8149ULL + 0xAB489E5205F89E55ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC297536DB7ADC493ULL + 0x9B7219EDD30A12C6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD550998969AF7CC7ULL + 0xFE9D019A33A42030ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBD6AB78D2553BC93ULL + 0x8DEF3A4268896B64ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x93CE44C5C430ACE7ULL + 0xCF6F3FB6278CD41FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xED21B701A5DC0F55ULL + 0xA354CD47A22B89EAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB48307DE4F7DEC8FULL + 0x9D9739090C28AFE9ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3106U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 1806U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4932U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6986U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6151U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 13U)) + 12809562813316740345U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 17084212535326321199U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 58U)) + 16074921689983846769U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 14027986153007120145U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 7633455951809250227U) + aNonceWordG;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 340989348513370174U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5307820377645020116U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8402492604131262157U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5605285015771527274U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5293500434746182790U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 17674669610895537063U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7263156475892261811U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10672879570907433005U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16659226780900986107U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9774892622769850665U;
            aOrbiterK = RotL64((aOrbiterK * 7487477727543183211U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 10728057184108279042U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5032485856947407217U;
            aOrbiterA = RotL64((aOrbiterA * 16651577903809154285U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 39U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterJ, 42U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11848U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 16344U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13640U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13500U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9402U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15642U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = ((((aWandererF + RotL64(aScatter, 26U)) + RotL64(aCarry, 53U)) + 13714409587461539863U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 57U)) + 14101156723903265839U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 13U)) + 7063754562895369001U) + aNonceWordN;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 12320578575245519386U) + aNonceWordA;
            aOrbiterH = (((aWandererE + RotL64(aCross, 13U)) + 11744826789631008424U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 8744816505096675597U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10405435520084528645U;
            aOrbiterG = RotL64((aOrbiterG * 13279521344071568023U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1463157688070683543U) + aNonceWordG;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 12379603577919617703U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 14858901470015109311U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1343439118031348146U) + aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16118850268070235540U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11184386483735388257U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14116264435819277136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5251698273012432109U;
            aOrbiterH = RotL64((aOrbiterH * 1495818611622063967U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14806408656041403829U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 39U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterG, 52U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21620U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 19883U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17593U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18409U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24412U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20832U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 39U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 7722279280863371124U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 57U)) + 11584220561732385598U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + 7834679350105534657U) + aNonceWordF;
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 11347994382444180879U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 26U)) + RotL64(aCarry, 21U)) + 9449903188047063431U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6516243976652795170U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 8420815253991184777U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 1358649408967265415U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9081386852515170937U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14375955191735286867U;
            aOrbiterD = RotL64((aOrbiterD * 2772840314542262283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 880757589768436072U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3349856625725164229U;
            aOrbiterC = RotL64((aOrbiterC * 681514212582331781U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7826309957607577207U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 8057435761214313635U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9565237500443303103U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15893066735310588501U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8457633439171452397U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 14U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterG, 41U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterD, 4U)) + aNonceWordL) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 22U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29086U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 28364U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 31715U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31913U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32623U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30518U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28739U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 56U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererC + RotL64(aScatter, 20U)) + RotL64(aCarry, 35U)) + 11410829607777684449U) + aNonceWordK;
            aOrbiterB = ((((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 7502698839700975347U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 13267685058252106173U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + 238242706996630625U) + aNonceWordB;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 57U)) + 8184695499511454281U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 12767823220461985403U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12293198423143850330U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5073886956792823825U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 11149495229952495939U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7556992689338382800U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 18232398462716803063U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3431338808774134649U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16863099140844995099U;
            aOrbiterB = RotL64((aOrbiterB * 752376661101787919U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17872458049880677604U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16760153457252546974U;
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3115544493537438408U) + aNonceWordP;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 4359882942759752958U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 561477566995575801U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 20U)) + aOrbiterC) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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

void TwistExpander_BaseBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC351FA73BD5C266FULL + 0xF7ACC5DEF284B70DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCB030C93BBB9C993ULL + 0xC9D12F15D1460684ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x863BEEF76F08D3ADULL + 0xD5E96F7DC67B8504ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA0D3037D57066F8DULL + 0xF65DEDB73F096231ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB874ED2DBBE9E641ULL + 0xBFEEE2210E0F97F8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8BFF98F5A62508B1ULL + 0xC0AB15983E87B02DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x88DBC517B3013BD9ULL + 0xFE1D1567344843BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x947A2649038745EFULL + 0xBBB736409CA0E40CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xED586D9F6148E645ULL + 0xCEBD1B8BB8E4059EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE0EBAAF86E3220E3ULL + 0xCBF13B91FBC65C61ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE7B6045357CCD7ABULL + 0xC1A6D2A2DA54FDFAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFDD1E5DD09C04B53ULL + 0x908011FF93846A1FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC345A4E8FD30C835ULL + 0xACA03291E02F8E9AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xBA5B0E504054A9E3ULL + 0xFC144E42C9E9BEB9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x95ABFD5F587F83CDULL + 0x8C56F2213C5D73A6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC9319A1244C94ED9ULL + 0xE2F8B7B80C69D77DULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aFireLaneD, aWorkLaneA, aFireLaneB, aOperationLaneD, aWorkLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneC, aFireLaneA, aOperationLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4863U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 2903U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 226U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1793U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8037U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5986U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (aWandererA + RotL64(aIngress, 51U)) + 8020711767807230555U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 3U)) + 15368693777246341570U) + aNonceWordL;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 5117523734225562401U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 38U)) + RotL64(aCarry, 57U)) + 13155269151097507808U) + aNonceWordH;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 9879303753623578272U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 1165799257173794826U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 27U)) + 930641942062732091U) + aNonceWordB;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11330571332221123153U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2862963158282518899U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13782195862525974199U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6019186399361476659U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1924419843785161958U;
            aOrbiterG = RotL64((aOrbiterG * 9485557122500346869U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12618629043591380461U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9334176504266512405U;
            aOrbiterE = RotL64((aOrbiterE * 18239109235362925739U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16829692481030013551U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5604784396927022709U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2833893610883508353U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16124030106598549644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16571659812830230677U;
            aOrbiterA = RotL64((aOrbiterA * 4668250364992383549U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15171089673591843703U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2826755560293849328U;
            aOrbiterK = RotL64((aOrbiterK * 9397017963457655287U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9976785768283589291U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11845100564714691809U;
            aOrbiterC = RotL64((aOrbiterC * 4935139932585319251U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 30U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aCross, 44U) + RotL64(aOrbiterA, 43U)) + aOrbiterE) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11297U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 11538U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 15905U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12519U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9793U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9688U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 10U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 30U)) + RotL64(aCarry, 35U)) + 4970414922752555648U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 37U)) + 9462756592787669327U;
            aOrbiterD = (aWandererB + RotL64(aCross, 5U)) + 3948790686662213095U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 14542857212241578311U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 11U)) + 3387479009827029547U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 53U)) + 1411421370057797877U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 16894451466895681236U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12727136462290223542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4625389198191960525U;
            aOrbiterD = RotL64((aOrbiterD * 5726474430977810191U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3471881403786164913U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6433115856048534831U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9363233870194144053U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 9825592965466157982U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1553125767261293088U;
            aOrbiterI = RotL64((aOrbiterI * 411535191177308781U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9951616357109647617U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11231080382787286889U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14024961994986659187U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13419663264017317947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4835055642466215566U;
            aOrbiterE = RotL64((aOrbiterE * 17898065852351759171U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14558747666410946768U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13120938960926874504U;
            aOrbiterH = RotL64((aOrbiterH * 5681766019285559739U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11910501376797343986U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15074100100781785300U;
            aOrbiterK = RotL64((aOrbiterK * 228976960937473851U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 12U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 58U)) + aOrbiterF) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aCross, 4U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + aNonceWordK) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 40U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16941U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 17109U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23655U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19177U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17312U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 17007U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 47U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 41U)) + 77518479758428414U) + aNonceWordF;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 23U)) + 4832061802166300011U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 11695291171006574112U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 60U)) + 7467412817843260094U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 17801484124471154757U) + aNonceWordP;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 53U)) + 5555455638503958639U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 5669470540733721606U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3042388456327784163U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2236734925228156691U;
            aOrbiterI = RotL64((aOrbiterI * 10076582424701705531U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 14459720401528685450U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4814967631216658856U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18288097536171386643U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16950679344449075945U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6262238639302011050U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3522256359074996724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13891759914865623828U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12311343917878428995U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2240189915640314069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5365912986308810837U;
            aOrbiterH = RotL64((aOrbiterH * 15133972552032469957U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9323732721344489753U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterK = RotL64((aOrbiterK * 14659491687401151733U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 23U)) + aOrbiterH) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 14U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aOperationLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28659U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 32366U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27429U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29893U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31656U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 28789U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 35U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + 6733949564325516029U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aIngress, 13U)) + 7304098437143918796U) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 58U)) + 3923949518391777800U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 14243591003388927124U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 18329498724605410406U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 51U)) + 13118172167747037249U) + aNonceWordN;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 5272025143849174212U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16075917179214318424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15263590648674658399U;
            aOrbiterK = RotL64((aOrbiterK * 9918239923411740337U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 13730046728289525921U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 7703141464499623408U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 5886009900621521987U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1382279753822135359U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2973369221699098292U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 7440242040663550631U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11578274119583013219U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3419411247737896674U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17814942652262802991U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2582783513078999303U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3959762790273529677U;
            aOrbiterD = RotL64((aOrbiterD * 383974377372162751U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 465795011576934604U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17880826624185821135U;
            aOrbiterF = RotL64((aOrbiterF * 4445949147592860913U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10819659185349413173U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17298208553586835030U;
            aOrbiterB = RotL64((aOrbiterB * 1965860510614222093U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterI, 11U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 35U)) + aNonceWordP) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 36U));
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_BaseBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x92D3A5BA613B74D9ULL + 0xCAE30E4552EA8A18ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE91915142C18B9A5ULL + 0xD6CF29849A41667FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x88DB6A9C5A5E8E61ULL + 0xFB3DA7691477EE46ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFEBC71F1C2CE4B43ULL + 0xF552E91107AF2D9EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x97E3D21C778CA8FFULL + 0x87B1D5C923AD39D9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE42A26572F624A49ULL + 0xFA22B5CE741B0ED7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC59FC7B8CCBC59C5ULL + 0x9F1C168ED9CCF315ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD62E377A477743D7ULL + 0xE5AD8FB5EB67B865ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAA33EA5032AB1BD7ULL + 0xF744A052B2CBB16CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x947461E234EB554BULL + 0xAB606F86F38596AAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE830432E3E1B4887ULL + 0xBEB5E1612CBD2788ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD2485E811E521D23ULL + 0xBF7AC9E827AED57EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA2D66CE5109BC5D3ULL + 0x98D9A5D8C25A10DDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x94604AA800BCFB19ULL + 0x9012A3E85085EE10ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA6690128615CBBA1ULL + 0xB6B9D1DFE9EAA53CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFA03543E86F1D587ULL + 0xF3A3E2E8862D7922ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneC, aFireLaneB, aExpandLaneB, aOperationLaneD, aFireLaneA, aExpandLaneC, aFireLaneD, aOperationLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7850U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 5800U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7220U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4060U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5940U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5113U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 22U)) + RotL64(aCarry, 37U)) + 2558105147674438050U;
            aOrbiterJ = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 51U)) + 15856662514774702561U) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 47U)) + 13346869226246584582U) + aNonceWordL;
            aOrbiterA = (aWandererD + RotL64(aIngress, 41U)) + 7632111846116243973U;
            aOrbiterB = (aWandererK + RotL64(aCross, 29U)) + 2102101361626976279U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 11U)) + 5605968705067851563U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 6842483186584326681U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5559797213819425064U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12422313931331576759U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7399849122565913401U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2751024420047872601U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11031320239359798610U;
            aOrbiterI = RotL64((aOrbiterI * 8607639453141148025U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14366375309473793217U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11971479429768505316U;
            aOrbiterJ = RotL64((aOrbiterJ * 10063001532313098203U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3947595951884469542U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 17882767922372770896U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 3361906348965810211U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 513871456983509223U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5951677013597794294U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 8508629569649935293U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 437626309049021931U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 466674061172005705U;
            aOrbiterC = RotL64((aOrbiterC * 1310502572084891157U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 12362602809233133718U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10525852878882195702U;
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 22U) + aOrbiterC) + RotL64(aOrbiterJ, 37U)) + aNonceWordO);
            aWandererG = aWandererG + (((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 47U)) + aNonceWordM) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + aNonceWordJ);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 44U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13206U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 13183U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10878U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9150U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13590U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10479U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 58U)) + 3248574644570178787U) + aNonceWordJ;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 4506961512959200024U;
            aOrbiterI = ((((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 8423739774540738590U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 6593975869641735337U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 41U)) + 16441716090557369103U) + aNonceWordI;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 19U)) + 7936601450453207914U) + aNonceWordG;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 11U)) + 13333752583560167065U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8013703284795432973U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2349852779887439236U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2422888500648100783U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5318539364763284138U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11450957608502944376U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 1957880366707810635U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9058992558327552687U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 632095686920230926U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 12460364388358520799U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14734218428913777098U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15049472842002138369U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2981145363531184308U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14176472085175714494U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2584623327412130939U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11198457590069700889U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 952584436750426828U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1165713888651280355U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4311591763498985972U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16194341833989936369U;
            aOrbiterK = RotL64((aOrbiterK * 9997934560195932575U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 57U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 48U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 53U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19391U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((aIndex + 19298U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16601U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23673U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24092U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 23869U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 13U)) + (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 51U)) + 1393781663398437180U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 17414594746688585273U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 58U)) + 2823888497053071250U) + aNonceWordB;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 17032631958617884859U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 41U)) + 15222697630461125019U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 15737414920751551780U) + aNonceWordA;
            aOrbiterH = (aWandererI + RotL64(aScatter, 13U)) + 1357196111055783001U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5315122321649251691U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7893744655508595974U;
            aOrbiterD = RotL64((aOrbiterD * 17863000246694319149U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16721939414324611738U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3444375866323610848U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10874157227815775661U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1825716513674511632U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15582066843912467318U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15673590949193923915U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13887365046280406413U;
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12730414371734709356U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4819112390640821927U;
            aOrbiterF = RotL64((aOrbiterF * 8782547948627685451U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3089925954422937464U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7180179304678622530U;
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17030269962085008657U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6675917351883004046U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14134335325316949687U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 4U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + aNonceWordC);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterF, 58U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28946U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 30791U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26036U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27092U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28222U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 32286U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 6U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + 6024062041314952357U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 18340757093658015585U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 11911120493880346751U) + aNonceWordB;
            aOrbiterH = (aWandererF + RotL64(aScatter, 56U)) + 17428074353884654439U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 12790849760814795936U) + aNonceWordC;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 41U)) + 12633397052172117800U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 11946150433665237945U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16842157900909419285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14186235783224155962U;
            aOrbiterG = RotL64((aOrbiterG * 10521157787073684417U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13284904542579767591U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11609181965078844357U;
            aOrbiterB = RotL64((aOrbiterB * 5455780554452453513U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9628562297095374984U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 7850281529011259759U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17611485102925470357U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 257458718073794527U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10693404545773519306U;
            aOrbiterE = RotL64((aOrbiterE * 14821443722828498323U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 3430519236533871460U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6183054506953198055U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 6121082743789970911U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2905610989884221654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16870142883133769663U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1403692060594816451U;
            aOrbiterA = RotL64((aOrbiterA * 9740854430251597879U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 4U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 20U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 57U)) + aOrbiterF) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 29U);
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

void TwistExpander_BaseBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x97C5510BC9409EDDULL + 0x8ACD21B0A8D8FA93ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFB57F30D95885DB1ULL + 0xBA35B72222B16654ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC82BCB562289FAE9ULL + 0xF2F2FE70B7C811B2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8A6F669BFDA79675ULL + 0xDF1BC3C098874A33ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x88E42DC9D94A0B6DULL + 0xCE0FFB2882783A84ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC4B85A920472746DULL + 0xCC694FFE03C2AA7EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC2AC60E9C67B9D99ULL + 0xB61C30DCA055FE73ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA6DD3EE8101AF555ULL + 0xF04C0571D5C55A2CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC9488460C6DD1077ULL + 0x9A871A3316227EDAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB84A705360EC0D7FULL + 0x9CCC15AE056DA23EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC2330A78BFFAA74FULL + 0x92E119C6D650FDDAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x85EA5D8F907D46C7ULL + 0xFF341E9736152759ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA044645723715E35ULL + 0xA04DC49B07E5A088ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x99BA3EE3907C3B13ULL + 0x9A4DDF35FFF5A8CDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9F3C999A12DA8255ULL + 0xE2189D0693EC7AD5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBF231BA98EB24E19ULL + 0xC85D06AFC846FFB7ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneB, aOperationLaneA, aFireLaneA, aWorkLaneD, aOperationLaneB, aFireLaneB, aWorkLaneC, aOperationLaneC, aFireLaneC, aFireLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 132U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 4777U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5315U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6528U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2085U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7258U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 48U)) + 4739486756133131180U) + aNonceWordD;
            aOrbiterB = (aWandererG + RotL64(aScatter, 51U)) + 16089707555501328184U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 15310047330238536453U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 37U)) + 7901411596386834955U) + aNonceWordL;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 4357555491060982163U) + aNonceWordH;
            aOrbiterA = (aWandererK + RotL64(aCross, 23U)) + 15667085602825720102U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 26U)) + 8520635334382269253U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 11U)) + 1772509779231068315U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 15336170957886025677U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 53U)) + 8628770833489469980U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 21U)) + 15469234024247246228U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10796430900884288328U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10660110397012853289U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 9140007610912037461U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11202284258711214794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17509491802893182994U;
            aOrbiterA = RotL64((aOrbiterA * 9329107599972703671U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16212572740740103554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2190030203761579226U;
            aOrbiterG = RotL64((aOrbiterG * 3101886685668871045U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12014337082293041909U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3733531010807001506U;
            aOrbiterB = RotL64((aOrbiterB * 5797362244066062299U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7100994963061975529U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17837541162838600258U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 8745987361678166553U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3311518938023146951U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7709505172646831553U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 7121143171245765213U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4979968094554018443U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16822214821463034107U;
            aOrbiterF = RotL64((aOrbiterF * 8618262120451291765U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8376124175020587079U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11084586282092424876U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5835632742522563537U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7816368455027681621U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10893292019060642422U;
            aOrbiterE = RotL64((aOrbiterE * 3995821210667317677U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13602875505184178486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5425735673005681983U;
            aOrbiterK = RotL64((aOrbiterK * 12667085597129312079U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5995385043278810987U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4739486756133131180U;
            aOrbiterH = RotL64((aOrbiterH * 15709273328685013399U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 52U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 48U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 48U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + aNonceWordB);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 43U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 60U)) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10117U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 10931U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 12294U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15662U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15621U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 8733U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + 3612110001869385068U) + aNonceWordB;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 19U)) + 16340824141280225936U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererB + RotL64(aCross, 37U)) + 15222338965130765231U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 43U)) + 6649270508107155041U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aWandererG + RotL64(aScatter, 50U)) + 768217258655426384U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 35U)) + 4481855259658861851U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 18318041934562434016U) + aNonceWordL;
            aOrbiterG = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 43U)) + 4212457153804401807U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 29U)) + 16143621095636987628U;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 2095664232866642086U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 58U)) + RotL64(aCarry, 27U)) + 4339527736737366572U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13679353177869884790U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11582168502846418236U;
            aOrbiterF = RotL64((aOrbiterF * 135539430034462861U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10451330452898542191U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12951448817640617841U;
            aOrbiterH = RotL64((aOrbiterH * 4141870904192742091U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15389161934419370747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 4754886272708253014U;
            aOrbiterB = RotL64((aOrbiterB * 16638243718191281597U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11746389873929280688U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12042680172517298768U;
            aOrbiterJ = RotL64((aOrbiterJ * 3814780289755857543U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2648103752465009244U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 451594673632597973U;
            aOrbiterE = RotL64((aOrbiterE * 8496763663271072425U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5696534794094099710U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14609435045257077395U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 14658408563237468407U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11599395126850950133U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12699598504604446664U;
            aOrbiterA = RotL64((aOrbiterA * 14313494063098111823U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9398465148537154745U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12139736860648011256U;
            aOrbiterD = RotL64((aOrbiterD * 15257503229375247987U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5390816291244486383U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2797988892316486895U;
            aOrbiterC = RotL64((aOrbiterC * 14668138881285892065U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18356290434261054712U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16582824574485822826U;
            aOrbiterG = RotL64((aOrbiterG * 7207935384746719969U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9858803484150150915U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3612110001869385068U;
            aOrbiterK = RotL64((aOrbiterK * 2862887443435821143U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 18U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 30U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + aNonceWordO);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 20U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 36U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 19416U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 20801U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20353U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18940U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16783U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21033U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 18U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 39U)) + 8101351470141807662U) + aNonceWordD;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 19U)) + 6965474099521076705U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 27U)) + 6803828268885684784U) + aNonceWordC;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 13454235922950972488U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 37U)) + 11678091885751244777U) + aNonceWordN;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 5307134544628507141U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 4873703518950429353U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 8542156221858586039U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 6U)) + 3993726182905296513U;
            aOrbiterD = (aWandererI + RotL64(aCross, 47U)) + 12113047622035464386U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 51U)) + 1944244448665721151U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12914188029425467576U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 2486762763475327024U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14580191602982245481U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12093414832400135066U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12720286833215690663U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13623906997320021065U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9977356009806428696U;
            aOrbiterB = RotL64((aOrbiterB * 2005536391712733499U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3694954095397810851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11453812627797091638U;
            aOrbiterG = RotL64((aOrbiterG * 13730420725113907161U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 542311345544726351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3024285045990499484U;
            aOrbiterD = RotL64((aOrbiterD * 5153745952148205645U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15397664082460849530U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10716856680110815056U;
            aOrbiterF = RotL64((aOrbiterF * 13947203772929252823U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 833342121331428547U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1111339940097269219U;
            aOrbiterH = RotL64((aOrbiterH * 17991642769781175473U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9312963978841402871U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8225496710723213204U;
            aOrbiterK = RotL64((aOrbiterK * 894499195498817065U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7947419530949269753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5028446114139808517U;
            aOrbiterA = RotL64((aOrbiterA * 5593084899736787263U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9818957208200746975U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17549192719666647522U;
            aOrbiterC = RotL64((aOrbiterC * 4705007748877441833U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16389708540378477737U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8101351470141807662U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9858235486537441981U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 48U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 26U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27196U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 29550U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30379U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28396U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29322U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 31344U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 24U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 18U)) + 16160838483846078448U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 53U)) + 15404960896190227946U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 16904160594024977199U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 37U)) + 17790460246821031802U) + aOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 57U)) + 16395168254086971959U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 7484373204039901786U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 18026814691322913510U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 11U)) + 15244817793136966450U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 5795491730356335666U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 39U)) + 3163873518027801504U) + aNonceWordI;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 29U)) + 2690791759507349172U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17898067251167087906U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8028010015006604239U;
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7304739457289910555U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6476837815096530043U;
            aOrbiterH = RotL64((aOrbiterH * 16380545138701113267U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 14242499233467960602U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17305645693017634630U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14442976693206929569U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9772864059444171908U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7897200728282156408U;
            aOrbiterA = RotL64((aOrbiterA * 816306719390807411U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4890999319172950996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8165132649356094963U;
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9342923520083533265U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7213639583505088067U;
            aOrbiterF = RotL64((aOrbiterF * 1349251979649428909U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4079475132684197272U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3350998022472827283U;
            aOrbiterD = RotL64((aOrbiterD * 948841791460066265U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2479140576609216238U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7703147534931674972U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 11419116495223970801U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9050277787914448469U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13295888852307317371U;
            aOrbiterJ = RotL64((aOrbiterJ * 3027097172772140975U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15380254190549884741U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 17653690414528791774U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 15923958179714368315U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6825072759468337036U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16160838483846078448U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 11690325563580492415U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 6U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterC, 19U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterD, 56U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterE, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 48U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterI, 14U));
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 28U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_BaseBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDDA2303B99CD685FULL + 0xBCD5DD1C9D7F3C5AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9FD5A6E260422FFDULL + 0x951799FF36986CECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFF416273C6730FDBULL + 0xE1E7875B143C5A49ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF2380159AFFE199FULL + 0xB496C5DF52B8142BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB3722A1FE0491293ULL + 0xAA7EB2974B78F7EDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC7D89EE187D96D0FULL + 0xC0D2009FEDF557E1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDAECCDAEDC3B4975ULL + 0x92C26303100FBD6CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE8E5DCEC2B813EC1ULL + 0xBDE2E6992CEA1E6CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA700AF93BFAF6FBBULL + 0x8575C677011F9860ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA433266AC6E8ABC1ULL + 0xC51D8ED7706F0A27ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xCD6AF95CCB3CDA33ULL + 0xEB1C4AA0173BA322ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD22F94AA72728A3BULL + 0xD5BBF6E5811E668AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA104A4B9625116E3ULL + 0xAD8D9AC824A29FDBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9DC46B8DE68F1343ULL + 0x911EBDE5B9445995ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x85166DD0919E2741ULL + 0xDE86DF244ABD380EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF570A3F552E4F365ULL + 0x9C979494AACCA334ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aWorkLaneA, aFireLaneC, aExpandLaneB, aFireLaneB, aWorkLaneB, aExpandLaneC, aFireLaneA, aWorkLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6660U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 5408U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2105U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 931U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6029U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3892U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 24U)) + 14008824488073394623U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 35U)) + 13317978415866411468U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 5U)) + 13209180141897453900U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 11870521586865233578U) + aNonceWordL;
            aOrbiterF = (aWandererE + RotL64(aIngress, 51U)) + 8052156380448047385U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 12158131176743680605U;
            aOrbiterI = (aWandererK + RotL64(aCross, 44U)) + 14674467487607719347U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 39U)) + 18055496790566231147U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 3838105585041578784U) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2839568255183054418U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11933612922864258179U;
            aOrbiterH = RotL64((aOrbiterH * 7571964469321160347U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6289849094151630580U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2640344350528492271U;
            aOrbiterE = RotL64((aOrbiterE * 16197726750829369365U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16306175266267657791U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 3339898380394883600U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 7105436590182982373U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15017076663742800002U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8973064296077602496U;
            aOrbiterD = RotL64((aOrbiterD * 9309462227233615761U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17580319233338139859U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14063208878807603874U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 16601475239075164585U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13326130855721009942U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12843186026737544416U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4975848122837321619U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14102887715772847499U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14495942314329085733U;
            aOrbiterJ = RotL64((aOrbiterJ * 4236795312917583565U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11564857125101669667U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17435970784822000464U;
            aOrbiterC = RotL64((aOrbiterC * 1472691848852381173U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16561390130356833062U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 9952805588514363872U;
            aOrbiterK = RotL64((aOrbiterK * 3720874990001086597U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 22U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 13U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterE, 37U));
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14694U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((aIndex + 15349U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12170U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12927U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10417U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11781U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 27U)) + 3339283916456813609U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 50U)) + 11339086426180649584U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 16819191669329316585U) + aNonceWordD;
            aOrbiterG = (aWandererK + RotL64(aCross, 3U)) + 8361916937762630725U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 13U)) + 18031328374429899857U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 18261756894092897276U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + 4250319792907645666U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 18U)) + 1492411503643460886U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 17369549067879344180U) + aNonceWordN;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7301713524358676722U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2985193736033012535U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 7473297294949338265U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14086975808140927408U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11441293212275890819U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18205555540941493267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterB = RotL64((aOrbiterB * 3009081009044782443U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9209505304067579944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8811497120829041188U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 11383709499376464085U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10080595991787801029U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterB) ^ 6822892187784299166U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 7417016898027778287U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 1981637172055758689U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8383837717361569465U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2788511294985017326U;
            aOrbiterI = RotL64((aOrbiterI * 2809163242875130677U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3529607472855930041U) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7821450253655655943U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 56U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aNonceWordM);
            aWandererE = aWandererE + ((RotL64(aIngress, 18U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 60U)) + aOrbiterB) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16560U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((aIndex + 22767U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 21756U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17401U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22960U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18575U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 34U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 11U)) + 18255347001097480328U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aScatter, 58U)) + 13679246790311505735U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 10565839529765027116U) + aNonceWordM;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 14327172566224769901U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 53U)) + 16239024612038195174U) + aNonceWordE;
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 13800012174212131890U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 47U)) + 13900288860157577583U) + aNonceWordN;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 34U)) + 4144386119777112740U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 3154558262670631372U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7456728543137614001U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11709519851158935384U;
            aOrbiterI = RotL64((aOrbiterI * 7016689518570071587U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15607438907832240304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9276575329661725624U;
            aOrbiterG = RotL64((aOrbiterG * 8879744070762412745U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6459435969129449226U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6442382118416542275U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2921027306686588233U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12117432107282150865U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6831279293184793243U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 2435360641135249073U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9520022957804572889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8322178689474588679U;
            aOrbiterK = RotL64((aOrbiterK * 1627707191467537115U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4162401591586869316U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8994015844714895961U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 15421910378057951895U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10038095909727959633U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 17756404450592957616U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14255952184627347295U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3379089265413427719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11341713098678108441U;
            aOrbiterJ = RotL64((aOrbiterJ * 2500587373161411961U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4030296130743454165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6332387792111212064U;
            aOrbiterE = RotL64((aOrbiterE * 16490982218150897861U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterE, 29U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 52U)) + aOrbiterJ) + aNonceWordG);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + aNonceWordK);
            aWandererA = aWandererA + ((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterJ, 12U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29776U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 32736U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32404U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28446U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32128U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32550U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 46U)) + RotL64(aCarry, 13U)) + 7960325128608297381U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + 12773836012104052042U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + 3173972621347773016U) + aOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 51U)) + 3708401356314308171U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 950774285720019449U) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 4170092315705438265U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 58U)) + 17000449130864980747U) + aNonceWordI;
            aOrbiterC = (aWandererF + RotL64(aIngress, 35U)) + 8793910540062893860U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 23U)) + 520277969543516469U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12762214857389827271U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2932451184340207695U;
            aOrbiterA = RotL64((aOrbiterA * 7513337346940091655U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11062179998786293839U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7919119215271524178U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9053677007180081359U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1774988449597115155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3799792889466518953U;
            aOrbiterJ = RotL64((aOrbiterJ * 17512791286490623455U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1815062051307896589U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15260373951371654483U;
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12867546628945676853U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 7772820973895846946U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 7581704643538761985U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14213957831821966834U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16561105721170419454U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 2540533987337175367U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16556502948339949526U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9706742922075498974U;
            aOrbiterH = RotL64((aOrbiterH * 8527361328901355457U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13455756934917486016U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9107769876332723454U;
            aOrbiterB = RotL64((aOrbiterB * 1722386100852683783U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15793099079168487016U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7968278803691283365U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11644765391940099387U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + aNonceWordJ);
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 52U)) + aNonceWordO);
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 23U)) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 22U) + RotL64(aOrbiterB, 6U)) + aOrbiterF) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererA, 4U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_BaseBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBE70B3F0B38D3823ULL + 0xF6EE03637D6D50C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBD484AFF87489209ULL + 0x838914677AAD05B9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xADA6652C747A9EC1ULL + 0xCDCB356E27885549ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xECD13CAE9618CFF5ULL + 0xDCA5CECAC33CCCCBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA944A62B0D92027FULL + 0xF4083069EBAAA0E1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB3C9B77C2114BAD9ULL + 0xC937899F2BA8F8C8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBB3891CF6773AC6BULL + 0xD467CFD930B5D126ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8A38DDB95113E10FULL + 0x83C2DCAF5B929DA4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x93646E2514D7EC7FULL + 0xE7BDB094D850927FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9510E09E09DFC0E1ULL + 0xD43B7812C15F0BDCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF6AFC72B719C9275ULL + 0xD239C28E0CAC6CBAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8FA32B78826CB839ULL + 0xAF5ECAB20E494028ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB8F2CFD9B4BE957BULL + 0xCB4D08B624E4D9CAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9C7292CC16225D1DULL + 0xFEF9902A58F78E98ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDBC0E02A602BF22BULL + 0xCF7383ECBE6CD62DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC651B8DBDE3A05D3ULL + 0xA56D3B61E290959EULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aOperationLaneD, aOperationLaneB, aExpandLaneB, aFireLaneD, aFireLaneC, aExpandLaneC, aFireLaneA, aOperationLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 1606U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 2807U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2186U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3638U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 577U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6446U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 6U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 18191288703716505885U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 41U)) + 9824014524910417136U) + aNonceWordJ;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 29U)) + 11953012029254917548U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 6297568011027199089U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 13U)) + 2576999400457367975U) + aNonceWordC;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 13176139160575558254U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 19U)) + 9978408174563621810U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 16765834875061607142U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16534507305459121344U;
            aOrbiterJ = RotL64((aOrbiterJ * 8943988574248229067U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3114710944346151807U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10240517868726718592U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 10721450637990777883U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16689590768796583952U;
            aOrbiterD = RotL64((aOrbiterD * 3046344179729901637U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2427422768928450209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13495584061816457831U;
            aOrbiterK = RotL64((aOrbiterK * 6670984773768885119U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7058636403765106682U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9897341853944713767U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 14286816859999869231U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17749559755733386064U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 12515645083926326659U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 6582878478865838245U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2625692458813609962U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10596240255026143019U;
            aOrbiterG = RotL64((aOrbiterG * 11605800195771080135U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterB, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 20U)) + aOrbiterK) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 4U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9640U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 15171U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 8944U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9472U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10204U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11959U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 53U)) + 13442819395490639310U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 4U)) + RotL64(aCarry, 11U)) + 8187292523194120936U) + aNonceWordB;
            aOrbiterE = (aWandererG + RotL64(aIngress, 41U)) + 11469697159823131388U;
            aOrbiterG = ((((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 13414083692375929653U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 11404010733687907517U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 13U)) + 6783212827186218247U) + aNonceWordK;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 47U)) + 8561131439340372614U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6252609642004429113U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 12804867444200448952U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 3114688959081972615U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2739648749603690781U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14808861217017399752U;
            aOrbiterC = RotL64((aOrbiterC * 373911885694012101U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17588866502571268888U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5882260142735642980U;
            aOrbiterK = RotL64((aOrbiterK * 7688252946143263869U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15493099088132862949U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5175647411532429582U;
            aOrbiterF = RotL64((aOrbiterF * 15226544495598541883U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 14279707376173642767U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 6826363572161275158U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 5263708315440161809U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13267185753040999992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9980987858092888720U;
            aOrbiterG = RotL64((aOrbiterG * 13210290848800728635U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3582972937645514549U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10140409019562890804U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6944490201647678479U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 52U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23566U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 24195U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 18024U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 21335U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19785U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17008U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 37U)) + 12615321415808640429U) + aNonceWordL;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 51U)) + 15712784676459931207U;
            aOrbiterJ = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 11013335427004930046U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 3U)) + 8298733856304768806U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 6207732959150824216U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 9769864876127544038U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 27U)) + 10782181918651152563U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5790454015845620939U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15606578025386733803U;
            aOrbiterJ = RotL64((aOrbiterJ * 7079287329365566355U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5522352539991175304U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5993355818572869649U;
            aOrbiterE = RotL64((aOrbiterE * 15221467311057431139U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10864534396947622047U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12090053126235913528U;
            aOrbiterC = RotL64((aOrbiterC * 7250801471645972261U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14191181677234981396U) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2258570108233924592U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 8307541155393855209U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8448114811381534603U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2702389315763499817U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6710443836432274393U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17202184076718780200U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 150549910056015002U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4910512055808124967U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4783477997418403079U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 861977492146512865U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 28U)) + aOrbiterA) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30025U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 32056U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 27703U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31053U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31035U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 31630U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 40U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 60U)) + 1952750591494698524U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 4488270851303332830U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 2738763375328927635U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 13U)) + 6728843649480454340U) + aNonceWordP;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 3U)) + 10490717875258865358U) + aNonceWordA;
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 1429288737812910205U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aWandererH + RotL64(aCross, 29U)) + 2761375016998907636U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1088988605204499835U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6829840407300289709U;
            aOrbiterC = RotL64((aOrbiterC * 13101432880030791787U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9267240337867690471U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8120113021183975703U;
            aOrbiterJ = RotL64((aOrbiterJ * 14296504593187173107U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1340980511302566784U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11874452169979878835U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 8638486178860092537U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1872314794140971426U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6013952618696225751U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3644011378086236002U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8501867691997891731U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 7115282675461711509U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2493546555198066143U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 5179240189571799179U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1267579130962756135U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11273348247858394197U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4577476419423118925U;
            aOrbiterG = RotL64((aOrbiterG * 8427261005061162673U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 48U) + RotL64(aOrbiterA, 4U)) + aOrbiterE) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 5U)) + aNonceWordM) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BaseBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFEE10DDAD2BD3067ULL + 0xFA99FABE30F4D0F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCDC6E726CB9E2ADBULL + 0xD040311500C13987ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC09B7EA564064F25ULL + 0xFE4B7EAFAF8811A3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAE30243AD16B4AB5ULL + 0xFE777334874576F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE799525AF1494D6BULL + 0xD945827CFD602E5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x835A62B4840688BFULL + 0xCC47148E53FB09B7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBD301E15FED9A00DULL + 0xBCF9C8FE2E8D5270ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x924EE76BDCB9C685ULL + 0x99AE67157D38363BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDFF5F41F91AD15ADULL + 0x93DB48880C83EFA9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE68493564680B397ULL + 0xB69DA6CC293371E2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDE004379EDADAAA5ULL + 0xC30A2B6407695405ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x847C87E1199FDABDULL + 0xC01C5AAEE318CC6AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8BD964B300C224ABULL + 0xF0C3F1A4C316D73DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9BB88070A1A6AA9BULL + 0x95798A2644742D74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBDDF027CFF9C1A5BULL + 0xF2C2B7A9A05861B4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x962089333CD8C73BULL + 0xD1381A0831851C54ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 144U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 2616U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1306U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2003U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 28U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 57U)) + 11177787645248006236U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 11U)) + 3808340254579817169U) + aNonceWordK;
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 44U)) + RotL64(aCarry, 19U)) + 828030667598518279U) + aPhaseEOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 23U)) + 16177835921238398371U) + aNonceWordI;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 5518747735458708741U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 51U)) + 17346319082399995165U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 6397156921893030937U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15559381654710713582U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 940404446491415088U;
            aOrbiterH = RotL64((aOrbiterH * 16401260971303026881U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8047166032048732645U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4688468645859470491U;
            aOrbiterD = RotL64((aOrbiterD * 14383536431614496369U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3710878044770337260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 116343189456629220U;
            aOrbiterB = RotL64((aOrbiterB * 5637725064169289339U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 883908030159391659U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18058691521694880482U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3132200449123497619U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17521015077103586117U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3668332225435714918U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12658899101297839881U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12229480388278883300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16206524049491531816U;
            aOrbiterK = RotL64((aOrbiterK * 11122340196620859805U), 57U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterB) + 5743265849441077466U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2812293020719282236U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 8903956475200417109U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 23U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 4U) + aOrbiterD) + RotL64(aOrbiterH, 47U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterD) + aNonceWordC) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 38U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4822U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2849U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2765U)) & W_KEY1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3709U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 24U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = (aWandererE + RotL64(aCross, 27U)) + 11521331427196538632U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 16653824187682957632U) + aNonceWordN;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 11654676587350088289U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 43U)) + 8010313317412193584U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 19U)) + 1108775560502907471U) + aNonceWordC;
            aOrbiterK = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 243952321439823521U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((((aWandererH + RotL64(aPrevious, 36U)) + RotL64(aCarry, 3U)) + 2324945800401240403U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9257554497543369657U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16701314607244592540U;
            aOrbiterA = RotL64((aOrbiterA * 8790054741039817107U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 3900445848034341782U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 7652316487347103658U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11480123491361589799U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14980368605272070578U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 2001165460948764796U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8110980921827107649U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1911044015666991050U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11366207111147818339U;
            aOrbiterE = RotL64((aOrbiterE * 17234439040652553865U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16469329744002456607U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8062793687044950815U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5856142259851144369U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15364721421972807872U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8979915611483540231U;
            aOrbiterH = RotL64((aOrbiterH * 10899377466171153383U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7654234623563110457U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1526832460342135008U;
            aOrbiterK = RotL64((aOrbiterK * 12766083052650723051U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 34U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 36U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aPhaseEWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7915U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 7320U)) & W_KEY1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6759U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7095U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7728U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 44U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 57U)) + 16922357079016918108U;
            aOrbiterD = ((((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 11771749797137599131U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 38U)) + 4635668433708036077U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 15827952719230577008U) + aNonceWordI;
            aOrbiterG = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 1495675306110023086U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 7294835466949728365U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 29U)) + 179122461212041978U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 545981421632236251U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15338259639814630535U;
            aOrbiterC = RotL64((aOrbiterC * 14895421566334357871U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12924313840290895215U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17846785921286020610U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 18309347016029917133U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5721472794107057875U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16359630793856870319U;
            aOrbiterF = RotL64((aOrbiterF * 14186771515526698907U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10614102110239037308U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16421992251278236531U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 2561232904676068089U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8668149834861244963U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12699331834360948734U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 2249360824172616357U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4470693178142950471U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 526000656022724741U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16688501462334673493U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6880246132270094141U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7126466778855297013U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5692237926830293205U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 36U) + RotL64(aOrbiterD, 37U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 39U)) + aNonceWordN) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 6U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9638U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[((aIndex + 9016U)) & W_KEY1], 26U));
            aIngress ^= (RotL64(mSource[((aIndex + 10225U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 10847U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9893U)) & W_KEY1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9023U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 21U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 5131645209694953015U) + aNonceWordJ;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 29U)) + 12070391048835379854U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 2604295836242338724U) + aNonceWordB;
            aOrbiterC = (aWandererA + RotL64(aCross, 27U)) + 14042039029284001596U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 36U)) + 8914654543854559327U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 13U)) + 2185619407969359869U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 47U)) + 5187406295103352574U) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8022832481290871217U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8783061916740573472U;
            aOrbiterH = RotL64((aOrbiterH * 3309891377744201773U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10711028365596196301U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13387065038269133571U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12444578026365205255U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11187001318931801582U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14191473173276034019U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2491253922434756431U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16207761776716426435U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9677408414452078760U;
            aOrbiterJ = RotL64((aOrbiterJ * 5487303383095129949U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17812460332794370649U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7736423148554132028U;
            aOrbiterC = RotL64((aOrbiterC * 15588733747232852555U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 17293203944059014763U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13487243633338010243U;
            aOrbiterD = RotL64((aOrbiterD * 9468688858740539095U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15979293016815060755U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17645215484691359547U;
            aOrbiterE = RotL64((aOrbiterE * 1449450767288733995U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 43U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 5U)) + aOrbiterD) + aNonceWordN);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 60U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11469U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 11639U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12120U)) & W_KEY1], 50U) ^ RotL64(mSource[((aIndex + 11318U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13215U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12621U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13310U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 13U)) + 10038936806177516123U) + aNonceWordG;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 1773168435195292638U) + aNonceWordL;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 3U)) + 10655711161526628072U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 14422295664639740437U) + aNonceWordO;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + 4125228715513159576U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 27U)) + 3670449653158650845U) + aNonceWordD;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 17553727567180813057U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5111401772713882743U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7688573124662314413U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10846442063022821393U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9438375825507814395U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 14177477039902118886U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6467406626985022537U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16329942595859623928U) + aNonceWordN;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3990536794006836672U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 579024714339065373U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5072881436583180756U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16789727877867289997U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8766246302636197905U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17313956922306689438U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11530878396329822041U;
            aOrbiterG = RotL64((aOrbiterG * 11356860047841383129U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3612616532321160196U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4172189825359187763U;
            aOrbiterK = RotL64((aOrbiterK * 12938945495299393177U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 8677279703778052804U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1912172980909479362U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 10053289257955474143U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 60U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16147U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 14150U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15121U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14368U)) & W_KEY1], 56U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15611U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14042U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14656U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 37U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 21U)) + 11998579547770778580U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 27U)) + 8409465187298704610U) + aNonceWordP;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 11U)) + 3470222286110333500U) + aNonceWordL;
            aOrbiterG = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 5704486785203069994U) + aNonceWordF;
            aOrbiterA = (aWandererK + RotL64(aIngress, 27U)) + 10334944660253279633U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 13U)) + 7626852700722567477U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 37U)) + 14631310754943209743U) + aNonceWordN;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 807160297237854120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5624154783624196107U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2404066593958052159U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 4971444394698940423U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6340057638461027062U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 12027586111086798629U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9003019862787819481U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13632057463595873033U;
            aOrbiterF = RotL64((aOrbiterF * 12575202147280216765U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12766104026871797746U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4062118445824915939U;
            aOrbiterI = RotL64((aOrbiterI * 13130770039048080701U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5258212525426469978U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9956946981015983939U;
            aOrbiterD = RotL64((aOrbiterD * 8106382657040497669U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10837606223056473999U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13292864885504191134U;
            aOrbiterG = RotL64((aOrbiterG * 4445739587553669471U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 166087925900318658U) + aNonceWordG;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6786842221885441388U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 4411147600413147773U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterI, 18U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18303U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 17587U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(mSource[((aIndex + 17277U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17345U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17632U)) & W_KEY1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18282U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17294U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 7790166497945719700U;
            aOrbiterA = ((((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 7136208896846119188U) + aPhaseGOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aWandererF + RotL64(aScatter, 35U)) + 12123156943355100886U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 5095546037880875199U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 17642705393916765992U) + aNonceWordA;
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + 9918479837334416990U) + aNonceWordE;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 43U)) + 4890009823843176466U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 17652590786213674124U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 870002527644696135U;
            aOrbiterI = RotL64((aOrbiterI * 915408393979165539U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12545429703552643682U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5310272867406182581U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 10420003334833925011U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3264719049050179440U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 1967241238180278937U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13004319774269457957U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 773883832927040736U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12766817190261232485U;
            aOrbiterF = RotL64((aOrbiterF * 7448864556802318431U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 260069382395598265U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15462103891287350123U;
            aOrbiterD = RotL64((aOrbiterD * 5029268763635635753U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4072032867513289827U) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17153061419083897076U;
            aOrbiterH = RotL64((aOrbiterH * 11934532169271718913U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6207264270332656966U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 18048064697837314947U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13632594619404208489U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 22U)) + aOrbiterJ) + aNonceWordJ) + aPhaseGWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20383U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 20655U)) & S_BLOCK1], 58U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21162U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 19114U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20941U)) & W_KEY1], 12U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19647U)) & W_KEY1], 43U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20104U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 19860U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 14U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererE + RotL64(aIngress, 58U)) + 3105313968748067810U) + aPhaseGOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 9977249451119627064U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererD + RotL64(aCross, 23U)) + 17941392803495349366U) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 39U)) + 4279533326705471133U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 5U)) + 13983828966811580039U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 29U)) + 3983490984234810378U) + aNonceWordJ;
            aOrbiterD = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 308786542215259956U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8443607695364427037U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 14939626441464340668U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 16793255020331774983U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9350693577306121110U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1717071159396961752U;
            aOrbiterA = RotL64((aOrbiterA * 11062480662625054525U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15911765265202100610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14898546272333182767U;
            aOrbiterD = RotL64((aOrbiterD * 2674900543810733067U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3560903518513465868U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterH) ^ 5367062725726860234U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 8521908836601319553U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 15233321480618877327U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9288449812290126074U;
            aOrbiterF = RotL64((aOrbiterF * 6815298520404038519U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5504840529511585676U) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6825598386801620046U;
            aOrbiterH = RotL64((aOrbiterH * 11666542445846250077U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 6433024450721339470U) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 97934156644929458U;
            aOrbiterI = RotL64((aOrbiterI * 8630530773006923215U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 13U)) + aNonceWordN) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterI, 29U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aPhaseGWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 42U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22971U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 22687U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24371U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23478U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23193U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23534U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22608U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 23889U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 3U)) + 18144572925667544139U) + aPhaseGOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 37U)) + 5659758077574059728U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 6343330616999166392U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 27U)) + 17754639838410839447U) + aNonceWordB;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 43U)) + 9451843819849581729U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 7957854457197462212U) + aNonceWordN;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 1461994799722205010U) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 18002214276252170177U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 14689869073147027164U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12242482963989582191U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3978104368003440293U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8512135845221335386U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 10506667163729414667U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1477533446382953439U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterE = RotL64((aOrbiterE * 6538884492418324461U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8082437060686606995U) + aNonceWordM;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 4363687722464700362U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 7199165810993478887U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15782763348014924206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8572509150015960728U;
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12248271773316742521U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9602078627638561949U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17244849374768558859U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1030743048280579012U;
            aOrbiterH = RotL64((aOrbiterH * 10858949914285817051U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 50U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 40U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterA, 42U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24736U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 25156U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27126U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 25270U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25880U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25553U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26597U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26055U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 60U)) + 16462052553719977502U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 53U)) + 12337064059566619581U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 37U)) + 15801005007094515447U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 8228706742665081656U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 5U)) + 11006723027845190869U) + aNonceWordL;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 47U)) + 18173765337829177450U) + aNonceWordE;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 530215083653542558U) + aPhaseHOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6608611827035564511U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2246051826221626809U;
            aOrbiterG = RotL64((aOrbiterG * 6333352641495253539U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5228575308895381421U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 10999213210689606857U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 5467601259546342925U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3773371037240485696U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8887985779436152504U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 698713082830739677U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11150566414723818350U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 8336366151003049546U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13233968794237090787U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8172558473508478819U;
            aOrbiterB = RotL64((aOrbiterB * 17837070423649268435U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 133564480283347997U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15104810248883567064U;
            aOrbiterD = RotL64((aOrbiterD * 706802420642303533U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9138629520201127075U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 13993086066341664080U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4875046427147105077U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 47U)) + aNonceWordF) + aPhaseHWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 4U)) + aOrbiterH) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29676U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 29615U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29419U)) & W_KEY1], 57U) ^ RotL64(aFireLaneC[((aIndex + 28816U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27986U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29278U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28330U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 29467U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 47U)) + 16200278595895089008U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 1029614154810465897U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 41U)) + 7129562468705441295U;
            aOrbiterH = ((((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 14388903902433951274U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 1013568949315967455U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 3128823373497815651U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 23U)) + 14525694606889470589U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14443983602196782887U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12244220415328641190U;
            aOrbiterD = RotL64((aOrbiterD * 15052949098014803181U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10477159225338766614U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2842870123078131566U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 11522265477555954071U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8621138818955849917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5038396344400303181U;
            aOrbiterH = RotL64((aOrbiterH * 14636756322207385447U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2768613802894372496U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2027754864051410015U;
            aOrbiterJ = RotL64((aOrbiterJ * 2461322540050569287U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2848088309172056399U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15017458513904884651U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9926904679902843055U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 9079797279596336139U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15424866642305110811U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12912331089970158845U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 13751764050290602740U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7694557131324740282U;
            aOrbiterA = RotL64((aOrbiterA * 14980807690491467023U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 37U)) + aNonceWordN) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 36U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterH, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30613U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31546U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30539U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31172U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32514U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31760U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 11U)) + 13350544654542863236U) + aNonceWordC;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 35U)) + 12364346790125404372U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 9738750172849512764U) + aPhaseHOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 3781373837635491421U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 27U)) + 16635020317512702337U) + aNonceWordL;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 43U)) + 5383653921676231276U) + aPhaseHOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 37U)) + 10181959815492056493U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10005510924273927017U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9524687662265740565U;
            aOrbiterJ = RotL64((aOrbiterJ * 13687380438646756931U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4259138552009771014U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8973051213213726023U;
            aOrbiterD = RotL64((aOrbiterD * 12625091476068190979U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17602611840127337490U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8218984546932905269U;
            aOrbiterE = RotL64((aOrbiterE * 17504305273683304231U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 18102186122213487888U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2629927500298092976U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 2491581597835795234U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9506602492971620955U;
            aOrbiterC = RotL64((aOrbiterC * 9559829640915637163U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13422942713680612924U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15037354693234876601U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12692376075738621447U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12896066842192894694U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 2202952306291905855U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 6779368532763429997U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 57U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + aNonceWordB);
            aWandererG = aWandererG + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + aNonceWordM) + aPhaseHWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_BaseBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE95399CAEEAD3E5DULL + 0xE65AD3EBD97D46BAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCFF7521365C7488BULL + 0xA6E2924E79538CBFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x83A43FF335F19C43ULL + 0x88BA8AC9659F9036ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDBF74C560643D6FFULL + 0xFF4329ED972546CEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF3929483503AC287ULL + 0xED04A7560A57EA15ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9F0A3A7C4152ECA7ULL + 0x93CCB1C0981D9DBBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA62C8CFFCAB458CFULL + 0xCD5FE7D617ABFE3DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9782CCC9C0A2F4B3ULL + 0xE2C034D13C7E4032ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDBBFD886EBE6190DULL + 0xF212F1DE02EB5D7FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xEBA13C76CCDD7D4DULL + 0x9B8BBDE005E9ADDFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB177F4BD9AA4B263ULL + 0xDEE5722CD74EBCDAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCA4D985D190926F9ULL + 0xA862DDBD09E434B2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF96F1E9A2B6AE387ULL + 0xC6094E91CDB9C4A7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xA4DF7E8B4F259905ULL + 0xAA0F558D7799D9AAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x87E213849D1380FFULL + 0xEEAFA0D564752E1CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD56CD93636B26257ULL + 0xF0D84047679FB255ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5273U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 5224U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4421U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2152U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4490U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 24U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 42U)) + RotL64(aCarry, 51U)) + 4980738603982643969U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 17660278413018470020U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 17598114429859543466U;
            aOrbiterE = ((((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 10993929335279994739U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + 17967203122976322481U) + aNonceWordC;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1872290205549034384U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16607778671782810797U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 340054507611349681U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4895226930754394376U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14960359005982301383U;
            aOrbiterI = RotL64((aOrbiterI * 8546231310054433721U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9921642352377700630U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 893281964367208693U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2345509157333444217U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8232519988397858732U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4433022122758913407U;
            aOrbiterE = RotL64((aOrbiterE * 834240393225479419U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12689609831247168353U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 404535388957472176U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14534020545479806593U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 60U)) + aNonceWordD);
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aNonceWordP) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 20U) + aOrbiterE) + RotL64(aOrbiterA, 21U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8946U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 10011U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5802U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7750U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 6337U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 8975885703279267062U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + 8664844915562660637U) + aNonceWordM;
            aOrbiterA = ((aWandererE + RotL64(aCross, 30U)) + 12281774799736296726U) + aNonceWordK;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 15347461352311329726U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 12967500561828907834U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 5002833859280402726U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11908257536954668983U;
            aOrbiterA = RotL64((aOrbiterA * 4384790916151202785U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17017174811949227162U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16851323125613931180U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12446990992858763577U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13469326957728686706U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 5228638551056105241U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 13369947664646167255U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11945166198089308564U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16268645041872996022U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 5391448793718370911U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14781204627695095701U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5365325354838101092U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 8017284997946310807U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 24U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterD, 11U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG + (((RotL64(aCross, 38U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12355U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 14619U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14787U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13161U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15732U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12871U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 44U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 43U)) + 1142447269198373880U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 11U)) + 10581460640040336191U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 14703062773878202900U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 27U)) + 15737525756286914746U) + aNonceWordJ;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 16178774478273186999U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2514897053906809160U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 13702496607592508464U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16540143680974064057U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 18030885275418337965U) + aNonceWordD;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 5241783876161655984U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 10970981186787227937U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2807052676283587925U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8022804576763271327U;
            aOrbiterC = RotL64((aOrbiterC * 11727096043219370577U), 29U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 15597099852232205860U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1538435607932096400U;
            aOrbiterI = RotL64((aOrbiterI * 7900752511710516981U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 11147868774413615365U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9325213746830411568U;
            aOrbiterB = RotL64((aOrbiterB * 561819005818948769U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 6U) + aOrbiterB) + RotL64(aOrbiterC, 60U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterE) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16667U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((aIndex + 19606U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18631U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20241U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20876U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21507U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 24U)) + 7651355040951791298U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 13988210277931659312U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 9846849412579537783U;
            aOrbiterJ = ((((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 12746719939495876158U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 39U)) + 11498066185182895284U) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11101058955193080232U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 15513734459555672046U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 6974281215677538561U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15711108675349394643U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 4771231759949468556U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11449258010811305256U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17036938391509986723U;
            aOrbiterJ = RotL64((aOrbiterJ * 7411466953205347639U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6999245666776654250U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2106819066263369528U;
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12716183358903477216U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 16752724547046059889U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 11475905692393034141U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aPhaseAWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aScatter, 34U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 57U)) + aNonceWordN) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 52U)) + aOrbiterF) + aNonceWordF);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 5U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26782U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 22890U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22742U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23402U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22974U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 27249U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 51U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 3U)) + 11210042748013785976U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 4584747303233477454U) + aPhaseAOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 8878765929792969517U) + aNonceWordF;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 2172232330280041122U) + aNonceWordH;
            aOrbiterE = (aWandererE + RotL64(aCross, 44U)) + 8378937026022264016U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8683007464695824208U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9564352997357118134U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17869948990449143305U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11713878436769887528U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8052917623074021077U;
            aOrbiterE = RotL64((aOrbiterE * 7450115139081623477U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7720597162792145185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2602847785328475621U;
            aOrbiterJ = RotL64((aOrbiterJ * 14065077077207224525U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 17813669222300509724U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 8724263063156573013U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 3632927017737834359U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6882429835961613492U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13213313479525717359U;
            aOrbiterA = RotL64((aOrbiterA * 2411431247725974895U), 37U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aPhaseAWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 28U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + aNonceWordJ);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 29U)) + aNonceWordO) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31888U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 32655U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31360U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28272U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31536U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28022U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 18U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + 18191288703716505885U) + aNonceWordB;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 3U)) + 9824014524910417136U) + aNonceWordC;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 11953012029254917548U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 6297568011027199089U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 21U)) + 2576999400457367975U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13176139160575558254U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 9978408174563621810U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1399052522159751531U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16765834875061607142U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16534507305459121344U;
            aOrbiterK = RotL64((aOrbiterK * 8943988574248229067U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3114710944346151807U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 10240517868726718592U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10721450637990777883U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16689590768796583952U;
            aOrbiterD = RotL64((aOrbiterD * 3046344179729901637U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 2427422768928450209U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 13495584061816457831U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 6670984773768885119U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aNonceWordO) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 22U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + aNonceWordJ);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + aNonceWordP) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_BaseBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8CBAC0233E6E5713ULL + 0xA495AB984665CAD3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA1CA0C9BAFEB385DULL + 0xEF3B02EA2E5D0449ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE31B60DF56150AC3ULL + 0xE04D304A88BFF35DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD704658959A813BDULL + 0xEFC338AA7B8776F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAC18E43EEC87A557ULL + 0xC0EE21BE910889CDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEA60C0D152457FCDULL + 0xD8758130F40BDFEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCBE6151492E78705ULL + 0x8A44A38709957A9EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA6B681BB7A4A2BB1ULL + 0xD2B0000DEA58650BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x83306262082665DFULL + 0x8736FA0E328BD7B3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE833DA0AD4042371ULL + 0xF2085798F9817220ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAFEB6BE867477049ULL + 0x9C8181E4701A33B1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAEC26CE6DEC9DDE7ULL + 0x85CF8915251DFA56ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x958E0633FACA3559ULL + 0xF34870E6A6C3B8B9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE025914E66300C63ULL + 0xB10071E4B2B61D1EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF765F59A5F50BC09ULL + 0x8F87E986DFBBF95FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC8F66927331623B7ULL + 0x93C58D3E397EAFA1ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aFireLaneA, aInvestLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD, aFireLaneB, aWorkLaneA, aExpandLaneD, aWorkLaneB, aFireLaneC, aWorkLaneC, aExpandLaneC
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2010U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 4213U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 907U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5167U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2789U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 2369U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 46U)) + 12775735908960052604U) + aNonceWordF;
            aOrbiterE = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 11791373812080296887U) + aNonceWordM;
            aOrbiterC = (aWandererH + RotL64(aIngress, 41U)) + 5537362877706057303U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 2023912048504189380U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 3U)) + 17668828109963766893U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + 558908629933941224U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aPrevious, 21U)) + 1479633119685446888U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 15460320397843364063U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 13U)) + 10059749397555469054U) + aNonceWordC;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9987633811929693924U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10087337844580228269U;
            aOrbiterC = RotL64((aOrbiterC * 13817142288940843815U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9430197906134676162U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1226048679997253363U;
            aOrbiterB = RotL64((aOrbiterB * 14247538885252664127U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 10611580584157624739U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3137391249289641509U;
            aOrbiterE = RotL64((aOrbiterE * 5462682413239873181U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9327201928815412810U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7890659377013147073U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 13827717178378062047U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10675114832750356941U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterA = RotL64((aOrbiterA * 8520671775587260601U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12871947817782057116U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11015991745792051390U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17152451500505815031U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6320437975845673731U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 702457937087191287U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16629064896250312921U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6054107387816339103U;
            aOrbiterH = RotL64((aOrbiterH * 6983767878966747219U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 56U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterH, 30U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + aPhaseBWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 40U)) + aOrbiterG) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererD, 58U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5698U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10468U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8674U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 10654U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10548U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10529U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7909U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 60U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 11U)) + 12535417189990029950U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 47U)) + 6204401443676390273U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 22U)) + 869613505613154672U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 15053590879563855802U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 51U)) + 13338989605204591428U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aWandererD + RotL64(aCross, 43U)) + 18306470022403825392U) + aNonceWordH;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 1150696349434090218U) + aPhaseBOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 13549541786420596437U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 56U)) + 14302878430259588461U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4660437084477165225U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1653628537860912069U;
            aOrbiterH = RotL64((aOrbiterH * 2624835201155303123U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5594199757006711631U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11008472193138708891U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 13645764762027798301U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6378674346113979108U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11438762460659123362U;
            aOrbiterK = RotL64((aOrbiterK * 2733309638158283953U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10624263004446482910U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12546839706919241411U;
            aOrbiterJ = RotL64((aOrbiterJ * 11468326687628079347U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8466639576503293921U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5828694979857951504U;
            aOrbiterF = RotL64((aOrbiterF * 7835487310289634515U), 39U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 16496305151014092976U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 589464613876410567U;
            aOrbiterB = RotL64((aOrbiterB * 13190816610718051897U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4168532743415647825U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15944887793736489375U;
            aOrbiterD = RotL64((aOrbiterD * 17273403561158196717U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11642456814106259483U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1609897693632334867U;
            aOrbiterE = RotL64((aOrbiterE * 12912773555616819941U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 54U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 34U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 40U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 47U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aNonceWordM) + aPhaseBWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterD, 28U)) + aOrbiterE) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11530U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 13293U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15486U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 16096U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 11034U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 60U)) + 13583136155674166402U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aWandererH + RotL64(aCross, 11U)) + 12830472187484919497U) + aNonceWordK;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 27U)) + 18081197909484522509U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 8680634051297891550U) + aNonceWordL;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 13939998767458656823U) + aNonceWordJ;
            aOrbiterA = (aWandererG + RotL64(aIngress, 47U)) + 1795730579103692594U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 17369751719734069999U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 42U)) + 224769585901248068U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 35U)) + 4133547085925268180U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7022512056309567391U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10319484359046945495U;
            aOrbiterI = RotL64((aOrbiterI * 3400140531307001933U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10483878349412282069U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6481381149199985736U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 9701719367082506253U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13721077228796934509U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9704818014314175007U;
            aOrbiterB = RotL64((aOrbiterB * 760445624027740287U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6253040047758584339U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16890211690273641226U;
            aOrbiterE = RotL64((aOrbiterE * 5622534399866057841U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6216227831265032436U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2023609047004658739U;
            aOrbiterC = RotL64((aOrbiterC * 3252332895698310147U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9201669637050388263U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5106927540934338576U;
            aOrbiterF = RotL64((aOrbiterF * 6368134569042291431U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10080368957861445998U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 10784789383436485808U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 3794918350254445939U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15426339824951793026U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17637144549368340331U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10971293914614704441U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9941300382181962134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8118046374121322097U;
            aOrbiterH = RotL64((aOrbiterH * 8481945819050983127U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 46U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 36U)) + aOrbiterJ);
            aWandererE = aWandererE + (((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordA) + aPhaseBWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 56U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 28U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aExpandLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aExpandLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 20238U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneC[((aIndex + 18133U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21543U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19310U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 17245U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 15652862298542575895U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 58U)) + 16925323928418184554U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aWandererC + RotL64(aIngress, 53U)) + 4413861484961668394U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 2215946422098155969U) + aNonceWordJ;
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 14975185533513111110U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 11U)) + 9711613814905834552U) + aPhaseBOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 13154957291850149471U;
            aOrbiterD = (aWandererB + RotL64(aCross, 27U)) + 5058313016418534840U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + 15011423472941211620U) + aNonceWordK;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 2030053257469580168U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 150530795186791193U;
            aOrbiterH = RotL64((aOrbiterH * 11106050063717096073U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10878237472104183427U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11724672539469573109U;
            aOrbiterE = RotL64((aOrbiterE * 16158741837357985395U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9589700906445846956U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1367381624958248949U;
            aOrbiterJ = RotL64((aOrbiterJ * 8459515089081211977U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12003215666757518106U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11232479330848006729U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 10993290955464593033U), 13U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 13013910456628561621U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6092509838924105265U;
            aOrbiterK = RotL64((aOrbiterK * 805601154718006061U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11999225836250312801U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14421271973875748413U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9529010940887430157U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 15536288285741825272U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2071793889925436679U;
            aOrbiterG = RotL64((aOrbiterG * 1526376970151714589U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5622386476463436967U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16147972771639168516U;
            aOrbiterD = RotL64((aOrbiterD * 11826916832825159095U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4519892856053952290U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12059500374938843538U;
            aOrbiterI = RotL64((aOrbiterI * 14987533625537956299U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterG, 30U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aNonceWordE) + aPhaseBWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterD, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterI, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aFireLaneC
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24192U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneD[((aIndex + 22769U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25346U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27261U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26409U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 54U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 3U)) + 11700815697312060726U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 11808423452327465441U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 35U)) + 8670503858631730886U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererF + RotL64(aIngress, 19U)) + 2400061067991988544U;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 16163118178366229686U) + aPhaseBOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 60U)) + 3280178595904941068U) + aNonceWordF;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 53U)) + 3298683600817047727U;
            aOrbiterF = (aWandererB + RotL64(aCross, 47U)) + 16321624053445183574U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 3U)) + 6730229877611375225U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10162830636713641322U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15646771327759599256U;
            aOrbiterB = RotL64((aOrbiterB * 15333053762177144775U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14841751262270544102U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9545541117228834895U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14676615635857599982U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 1231768638470558855U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2716808508509014677U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 1945905595345404833U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterG = RotL64((aOrbiterG * 4577864352425476233U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 1970292335806697198U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5352135521358954576U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15465675376193501658U;
            aOrbiterH = RotL64((aOrbiterH * 16385761112921041387U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2842123638916600369U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3544764287036748668U;
            aOrbiterF = RotL64((aOrbiterF * 3360772950777850115U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6038297172906492282U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10249342332287140970U;
            aOrbiterJ = RotL64((aOrbiterJ * 16701083081566042277U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1662076777040529446U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1949705569959740274U;
            aOrbiterA = RotL64((aOrbiterA * 11340691546658994529U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 22U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterI, 14U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 3U));
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 26U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 53U)) + aOrbiterB) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29832U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 31233U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 29858U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32648U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29306U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 28U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 39U)) + 12380376990224645149U) + aNonceWordD;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 60U)) + RotL64(aCarry, 57U)) + 18296928500297384014U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 3550626816361145100U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 13U)) + 2667792936946706027U;
            aOrbiterI = (aWandererH + RotL64(aCross, 29U)) + 12020969779370926953U;
            aOrbiterJ = ((((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 737340727886903447U) + aPhaseBOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 3U)) + 1681797651799760502U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 23U)) + 2956186342689489064U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 52U)) + 1876852870402977177U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6433205819353555071U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9065076854974222998U;
            aOrbiterC = RotL64((aOrbiterC * 5459675878087242021U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3254410578766789992U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2005081975473815576U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15992999234834560419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3458344156815120948U;
            aOrbiterG = RotL64((aOrbiterG * 1668460113964608051U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17069783053664877727U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1260234710193913099U;
            aOrbiterJ = RotL64((aOrbiterJ * 4561226779897414381U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3825186451876061335U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 2905344294992827535U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2469896090698580795U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18141402347899180617U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8760129857609925066U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 2507999156108123047U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 594052473780678210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13216719212966128379U;
            aOrbiterK = RotL64((aOrbiterK * 10691355329696722303U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10029948739466316169U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11912428807431992996U;
            aOrbiterH = RotL64((aOrbiterH * 85016510811938307U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8735634019801417287U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12785916159063273545U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1161917531260663357U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 36U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterH, 4U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterB, 22U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
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

void TwistExpander_BaseBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDACCE9A78790A5D9ULL + 0xE4B70154EAAE6CC0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC4E1E880D78B3E89ULL + 0xF0473C5780A21DBFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCEA72A51F0800423ULL + 0x87039B7DA591481CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE6DB71FA704409F5ULL + 0xF34FF5A6587199D9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAEC1DBA337B3681BULL + 0xC390E759CB7ABCFEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAAD53E1528494119ULL + 0xDE0F0C05FD5921F4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9264B60B45986341ULL + 0xA58101D0B5DD3639ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFE73F76205B76809ULL + 0x8C32C82EEDE8F4A5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x835B323151E3426FULL + 0xDAB6C4A9B8AC7F2FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA4B0F2E53E517ADDULL + 0xA2FDF6FCC7054784ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x88230381D8C29263ULL + 0xF03B51ECEC942DDFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE25C9B2A57850345ULL + 0xB5774B9BE8ACCC64ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8B354539620A9553ULL + 0xE5FB113552920420ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB6FEC7EFE38BDC4DULL + 0xD46C222F6F92C7BDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAB7E5866263B1B75ULL + 0xD506783D928EF54AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEF311E6130906EC5ULL + 0xF09AD195E327F251ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3258U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 621U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2696U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2341U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4421U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 753U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 40U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 1042610313571524121U) + aNonceWordP;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 3505725321008825582U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 35U)) + 12584654563843782991U) + aNonceWordA;
            aOrbiterF = (aWandererK + RotL64(aCross, 46U)) + 6645399144515770935U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 11U)) + 3608978423753715584U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 8089198857670370983U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 15207251813516399879U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9579268660105824516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16055044469473802812U;
            aOrbiterG = RotL64((aOrbiterG * 2269649280637188723U), 21U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 583811872609805949U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7027491967970873942U;
            aOrbiterA = RotL64((aOrbiterA * 12686754713465826139U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 18256061823189677508U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12708429127816136937U;
            aOrbiterE = RotL64((aOrbiterE * 12593886633108075321U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12169216645156306078U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 12694325407567795065U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16109994660203297503U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 4234704064165718913U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 730085881474787681U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14119541943554602878U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8777769004811352951U;
            aOrbiterK = RotL64((aOrbiterK * 2556957257736134223U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15642663488392549609U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11594468530833278624U;
            aOrbiterH = RotL64((aOrbiterH * 6639306656361601143U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + aNonceWordL) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 44U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + aNonceWordB) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9785U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 5939U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5894U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6759U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5777U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6505U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8430U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 3199575576585871314U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 2533378188975571824U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 53U)) + 6819782112558312658U) + aPhaseDOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 5U)) + 12690060987724798497U) + aNonceWordG;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 29U)) + 7088375139715629606U) + aNonceWordD;
            aOrbiterC = (aWandererF + RotL64(aCross, 39U)) + 17785618677423695666U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 5U)) + 1714999280296491277U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17611338506932491624U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6475727359297421201U;
            aOrbiterA = RotL64((aOrbiterA * 15133348244242438069U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2347744591204119530U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2739317903351401068U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15435029315209475631U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8663535261373274338U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8205245127823536479U;
            aOrbiterC = RotL64((aOrbiterC * 13857005110466856439U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8916510616749754516U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3944805940148512932U;
            aOrbiterB = RotL64((aOrbiterB * 18082271583211389701U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14094751253118853302U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14094299829196076311U;
            aOrbiterE = RotL64((aOrbiterE * 6370012560657108493U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3940673811518673802U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3015106523254484839U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 9655401190755573379U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15404103131982599922U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1828655763233900875U;
            aOrbiterH = RotL64((aOrbiterH * 13024358077740310049U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + aNonceWordF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 21U)) + aNonceWordB) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12650U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 15671U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13867U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16050U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16010U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 10U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 27U)) + 10812151398716051703U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 34U)) + 18202551453336003710U) + aNonceWordH;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 9434410809101973752U) + aNonceWordF;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 19U)) + 12955829998028534045U) + aNonceWordO;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 11U)) + 12271740641929640181U) + aNonceWordC;
            aOrbiterH = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 21U)) + 14009351527014534752U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 4316296955679133450U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16473324966997442872U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15735123324965019802U;
            aOrbiterC = RotL64((aOrbiterC * 5624078184997601019U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17656375090484080236U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 16066325053456055298U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 17912970706985130327U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12908968778503516903U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 12761433987676836197U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 1023329467480907925U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12737513138040664509U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 14535795767570998392U;
            aOrbiterE = RotL64((aOrbiterE * 15560519667062222269U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14370908061811284364U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7001358781208669795U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11641248025734015835U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7298578161120090849U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10498302152357484629U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13144110412179037175U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11447343228638006767U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 18284143620422655675U;
            aOrbiterA = RotL64((aOrbiterA * 572862190073605651U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 20U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterC, 18U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aScatter, 54U) + aOrbiterG) + RotL64(aOrbiterB, 11U)) + aNonceWordK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 41U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordB) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 18590U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneA[((aIndex + 17742U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18000U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20473U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19135U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U)) + (RotL64(aCross, 60U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 50U)) + RotL64(aCarry, 29U)) + 8988572360732005217U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererI + RotL64(aIngress, 3U)) + 17889613225105985335U;
            aOrbiterH = (aWandererB + RotL64(aCross, 19U)) + 15563478320513948626U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 3441351228410524816U) + aNonceWordN;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 4425592689451435346U) + aNonceWordE;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 29U)) + 12733160231627305928U) + aNonceWordP;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 35U)) + 3574152157304607854U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15167631896729808783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15822667973915417055U;
            aOrbiterH = RotL64((aOrbiterH * 5155661648455308057U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17181685481076577637U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 9979204751408873468U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 8244434774754786565U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1334240485667164762U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9190066751460137016U;
            aOrbiterC = RotL64((aOrbiterC * 14585141844653660363U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15465215829109246336U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2305208282453624419U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10257861974108363283U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16951510027310993926U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11117938943423526901U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 7805486716716924787U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12461379120662979432U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 11719697049048823897U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14880996802304818757U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6843357278142933570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12727898578324702374U;
            aOrbiterK = RotL64((aOrbiterK * 9786435451654365097U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 28U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + aNonceWordK) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aNonceWordA) + aPhaseDWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25163U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 23198U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26473U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25256U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24952U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 37U)) + 11700815697312060726U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 11U)) + 11808423452327465441U) + aNonceWordI;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 8670503858631730886U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 2400061067991988544U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 54U)) + RotL64(aCarry, 21U)) + 16163118178366229686U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 3280178595904941068U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 21U)) + 3298683600817047727U) + aNonceWordK;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16321624053445183574U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterA = RotL64((aOrbiterA * 2022290495153519279U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10162830636713641322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15646771327759599256U;
            aOrbiterD = RotL64((aOrbiterD * 15333053762177144775U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14841751262270544102U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9545541117228834895U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11529769874752969377U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14676615635857599982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1231768638470558855U;
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 1945905595345404833U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1406171421638586846U;
            aOrbiterK = RotL64((aOrbiterK * 4577864352425476233U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1970292335806697198U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5352135521358954576U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15465675376193501658U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 16385761112921041387U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aNonceWordE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 50U)) + aNonceWordL);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterD, 5U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29019U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneA[((aIndex + 29591U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31556U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29244U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30143U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 37U)) + 4970414922752555648U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 13U)) + 9462756592787669327U) + aNonceWordP;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 3948790686662213095U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 51U)) + 14542857212241578311U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 3387479009827029547U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 60U)) + 1411421370057797877U) + aNonceWordC;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 16894451466895681236U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 12727136462290223542U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4625389198191960525U;
            aOrbiterK = RotL64((aOrbiterK * 5726474430977810191U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3471881403786164913U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 6433115856048534831U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9363233870194144053U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9825592965466157982U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1553125767261293088U;
            aOrbiterJ = RotL64((aOrbiterJ * 411535191177308781U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9951616357109647617U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11231080382787286889U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14024961994986659187U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13419663264017317947U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4835055642466215566U;
            aOrbiterA = RotL64((aOrbiterA * 17898065852351759171U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 14558747666410946768U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterB = RotL64((aOrbiterB * 5681766019285559739U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11910501376797343986U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15074100100781785300U;
            aOrbiterG = RotL64((aOrbiterG * 228976960937473851U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 41U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ) + aNonceWordG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_BaseBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD270A1F861089891ULL + 0xF77422BC1D055A3DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDE61DDCA5FCB1F31ULL + 0xAE1AD7970C8A9379ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEB8DB914427FEC33ULL + 0xC00A618B3AC059E2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB5FC4B608A606CF1ULL + 0xD85BB747D0739CBFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFDC793E14CB26A7BULL + 0x981FA342F9D8E094ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB6C115D129175885ULL + 0xDEFF60AFA6706216ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE8FBE2B629CD4D4BULL + 0x81D3DCE8000A2CC5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCAE32747911278C3ULL + 0xD966E36C670807F7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8290A5C46BB0F5D7ULL + 0xEA94B28D57C80DB9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD396395FA479161BULL + 0xE04B93134053049BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x91CA1B74A1A31655ULL + 0x9AD01E543029EF36ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD0475187BA509703ULL + 0xA9CA49A423FDC9C9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAB21C282CCB9306FULL + 0xF6F18891E58900F8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDA3E9B1525D3993BULL + 0xE393C92A807AA0D3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE33D7F6DA41354B9ULL + 0xED4A6A7A0F4E7A0FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB89632CC4947FB57ULL + 0xF2C0699013F80F1BULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 644U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((aIndex + 1402U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3857U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2751U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1617U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 778U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (aWandererD + RotL64(aPrevious, 60U)) + 1457104756581596530U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 47U)) + 6127240317844622874U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 13U)) + 16492290056044189421U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 39U)) + 10963676850938416468U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 4872917367399752405U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 10U)) + RotL64(aCarry, 19U)) + 15218882377875616148U) + aNonceWordE;
            aOrbiterK = (((aWandererC + RotL64(aCross, 19U)) + 5934166612122118251U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 53U)) + 14215280930872003003U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 41U)) + 11428034799044600979U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 37U)) + 5453003654321728726U) + aNonceWordH;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 14273775120265649389U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 328723770018440271U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13032190719588211088U;
            aOrbiterH = RotL64((aOrbiterH * 13363368478932798315U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2386881543033598494U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1649501123340887116U;
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16462401546754210583U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1510579201823042227U;
            aOrbiterI = RotL64((aOrbiterI * 16287912400104043275U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6889066000014251983U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11324594596597724357U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 15344987814648586023U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12237796033168436537U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17306069670330000343U;
            aOrbiterA = RotL64((aOrbiterA * 3167451351403385259U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14197284538008811658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4754134852883071927U;
            aOrbiterK = RotL64((aOrbiterK * 3484427259538998699U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17201907781639753736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8318419319239859855U;
            aOrbiterJ = RotL64((aOrbiterJ * 10320390501983802091U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16012488623961565780U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15583721012865354925U;
            aOrbiterB = RotL64((aOrbiterB * 10656414363201743961U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14680351201973315018U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14483973292275372321U;
            aOrbiterE = RotL64((aOrbiterE * 9279222721410811027U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16324317860030681248U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7038506963317910910U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 2960451734542956767U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12767672960346001218U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1457104756581596530U;
            aOrbiterF = RotL64((aOrbiterF * 1560375242310194691U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 50U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 3U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterC, 30U)) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterG, 60U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9538U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneC[((aIndex + 7663U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7343U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9261U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5851U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7692U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7875U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 12046647397183218524U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 2760779375026461991U;
            aOrbiterI = (aWandererE + RotL64(aCross, 53U)) + 13735454443176855650U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 60U)) + 4370377000586647724U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aScatter, 29U)) + 14566322384189969094U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 5056565959818422786U) + aNonceWordK;
            aOrbiterG = (aWandererB + RotL64(aIngress, 37U)) + 8795403810686579209U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 9625947666256011567U) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 1703669290934254701U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 11U)) + 6664070663184147951U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 46U)) + 2104148316797553431U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1197910004222596145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9922977170060903197U;
            aOrbiterI = RotL64((aOrbiterI * 13047828062605568603U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2048376210852567829U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12568990647075931409U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 9860242601194210927U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15026894775772902751U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 3439447160137900629U;
            aOrbiterE = RotL64((aOrbiterE * 1813754963043785165U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6532671388552829796U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17261098369835997661U;
            aOrbiterF = RotL64((aOrbiterF * 568292591215203521U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 3171300991007459947U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5935563269327662024U;
            aOrbiterA = RotL64((aOrbiterA * 11271790283157765003U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14290941734320455612U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12371794745736518824U;
            aOrbiterG = RotL64((aOrbiterG * 12208762336145168647U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8782840145467637373U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4067525421190366741U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6671002797916227485U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11854812920571789853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17564890418553131451U;
            aOrbiterK = RotL64((aOrbiterK * 16657184504366731805U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6250004085193517531U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 2362659992682660827U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4365619310373869859U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4597159873252831182U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13197238269207675773U;
            aOrbiterJ = RotL64((aOrbiterJ * 379653377172816575U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8552479493772820372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12046647397183218524U;
            aOrbiterB = RotL64((aOrbiterB * 17918033655125400323U), 23U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 10U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterB, 51U)) + aNonceWordG) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 40U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13600U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneA[((aIndex + 13641U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11640U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13783U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneC[((aIndex + 15937U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 13650869943246163567U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 6U)) + 3435284932011770999U) + aNonceWordN;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 12388155658186776579U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 11U)) + 2374345913955712039U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 39U)) + 6095094526980292156U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 35U)) + 4965147025852444174U) + aPhaseEOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 60U)) + 3261881216269075298U;
            aOrbiterK = (aWandererA + RotL64(aCross, 29U)) + 4939780217097329222U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 13U)) + 3019862009792676287U) + aNonceWordA;
            aOrbiterA = (aWandererI + RotL64(aScatter, 51U)) + 901910626217143974U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 3647055146712366383U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7731765438957392967U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13409819457393479741U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3345078200262410715U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5415832109107794258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8876738832313114471U;
            aOrbiterC = RotL64((aOrbiterC * 1304277600444504135U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17135570542519390359U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2373193062766802082U;
            aOrbiterD = RotL64((aOrbiterD * 4213691513185791519U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16318403285501718552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8456043288604687045U;
            aOrbiterB = RotL64((aOrbiterB * 10556964529144571683U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10572534930284516528U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14616251186735204677U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2048651204265459805U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2837006243817205610U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5315917323622194254U;
            aOrbiterG = RotL64((aOrbiterG * 4080522050089666599U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12084676282761185907U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7922080344175593788U;
            aOrbiterK = RotL64((aOrbiterK * 7603522302708937379U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17620847289789547792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12140386059533463650U;
            aOrbiterJ = RotL64((aOrbiterJ * 1443266480620969535U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4006608081473218762U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3152507055132739011U;
            aOrbiterE = RotL64((aOrbiterE * 11929522909695002321U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10845720206369283181U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 16572752872386133133U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2891952650448087211U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15544908026178481075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13650869943246163567U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1275090431127426217U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 14U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 3U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 26U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 10U) + RotL64(aOrbiterG, 21U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererG, 30U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17470U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((aIndex + 18733U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19916U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17662U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17806U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 48U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererG + RotL64(aPrevious, 11U)) + 13960289014350612206U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + 3483331015269589730U) + aNonceWordB;
            aOrbiterC = (aWandererB + RotL64(aIngress, 5U)) + 6873299241002444518U;
            aOrbiterD = (aWandererA + RotL64(aCross, 47U)) + 3562094007125534229U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 36U)) + 11422367439932782705U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 21U)) + 532453428514259816U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 17810941465810193088U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 11869759058631106331U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 8837581071876177566U) + aNonceWordF;
            aOrbiterJ = (aWandererD + RotL64(aCross, 14U)) + 17185378327053837778U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 3U)) + 7578253375676981500U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17112646434432814442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14949096407295697881U;
            aOrbiterC = RotL64((aOrbiterC * 14770977858283051753U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4259590620758467836U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6534899413644542303U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7987609419215568661U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2637407498893694243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15819295597921425711U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5202015597375051399U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6373559542002699718U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11694562937392022505U;
            aOrbiterB = RotL64((aOrbiterB * 9311557972331218597U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3308736483775453062U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12749929710650475901U;
            aOrbiterJ = RotL64((aOrbiterJ * 248428400724560945U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1569528215675579656U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1044077933631689572U;
            aOrbiterH = RotL64((aOrbiterH * 6443796233912755143U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8393422728124537471U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2002732612516530754U;
            aOrbiterF = RotL64((aOrbiterF * 13702146823622364279U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13469191942843147943U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7633171368709520560U;
            aOrbiterE = RotL64((aOrbiterE * 9713514012478203047U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4023206337737491091U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15990323932023596968U;
            aOrbiterD = RotL64((aOrbiterD * 4816480271959713463U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 837005729394899591U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9692088757104339973U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 17971548293495807419U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18039464962413134616U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 13960289014350612206U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 931609478642506411U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterH) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 54U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 48U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 54U)) + aNonceWordL) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererB, 44U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26939U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((aIndex + 24819U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24768U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22354U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27201U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 22977U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 37U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (aWandererC + RotL64(aPrevious, 29U)) + 6361545377408870615U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 23U)) + 2967245486744774933U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 5U)) + 3836634268482850139U;
            aOrbiterF = (aWandererI + RotL64(aCross, 51U)) + 7691642115360086297U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 11U)) + 16479280384178279281U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 26U)) + RotL64(aCarry, 41U)) + 2901468732552539249U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 47U)) + 2600353867755647475U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 5666596904781510956U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 16108791609267427553U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 42U)) + 8389926875737312112U) + aNonceWordM;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 19U)) + 1689501721163024426U) + aNonceWordL;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11721701506949917719U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3963842745030140473U;
            aOrbiterC = RotL64((aOrbiterC * 6692473494944919373U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2259725140963665123U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11652011949557979650U;
            aOrbiterA = RotL64((aOrbiterA * 11260100762113295037U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1116085424226174473U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4725260319270802912U;
            aOrbiterJ = RotL64((aOrbiterJ * 4697109059565450269U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7348945429843437036U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1249234309180653260U;
            aOrbiterK = RotL64((aOrbiterK * 3136745255820405881U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12463505532573389603U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2304125977906510386U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9960816714791454421U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2178037443783425551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11712110130079307683U;
            aOrbiterF = RotL64((aOrbiterF * 9797864956200779505U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10703510612147312252U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 18155460326242413483U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6903953708987478723U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5753486645345036069U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2314216774606770444U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 14002639533287566667U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9662599462788305323U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3805101172359199209U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 10669315962181581543U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1073926575064224947U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6361545377408870615U;
            aOrbiterH = RotL64((aOrbiterH * 10685650563722188837U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 44U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterH, 48U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 46U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererE = aWandererE + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 58U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + aNonceWordN);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 36U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30090U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 28323U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 32648U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28338U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31914U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 51U)) + 12131317914288566437U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 5672805657999385496U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 3581710244233124197U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 19U)) + 15251296040538489436U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 57U)) + 11295008604679904153U) + aNonceWordB;
            aOrbiterI = (aWandererI + RotL64(aIngress, 54U)) + 2230897493419504490U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 11U)) + 7109600123297458999U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 41U)) + 13119156643107683803U) + aNonceWordN;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + 14755160867807355250U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 16829363373287496832U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 38U)) + 16981122946707720883U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8806000776958603317U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16810923047720876014U;
            aOrbiterB = RotL64((aOrbiterB * 17872735050219539145U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8129657889554436328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8653100378491974463U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11395283153912468661U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17048985838727432415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10892675550889823573U;
            aOrbiterF = RotL64((aOrbiterF * 976298937314081913U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15960158965421254346U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12290011578634850001U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9280475585104357745U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16265047040311479093U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10312956912303656248U;
            aOrbiterD = RotL64((aOrbiterD * 3012584393253845131U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16706890352221352779U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10630955894218491929U;
            aOrbiterJ = RotL64((aOrbiterJ * 12675937483456206355U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4009352551041162434U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 3043810773683888556U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 4328135390387997315U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 1398071019814944785U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16689766557488135301U;
            aOrbiterE = RotL64((aOrbiterE * 8403881916549404871U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15934647144489136524U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13521276033614992223U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 18003640895553609933U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4281211055727414100U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11848150507497406421U;
            aOrbiterK = RotL64((aOrbiterK * 1107789990317433481U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12022829841608199449U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12131317914288566437U;
            aOrbiterG = RotL64((aOrbiterG * 13275753083882829973U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aCross, 20U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterC, 39U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 30U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC + (((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterE, 27U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererA, 60U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_BaseBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB9A3B4256911AED1ULL + 0xB9AD8D7B851D2BD0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDFEDE328D0E0391DULL + 0xFAE70F11B94B76EBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBD0869D7DDDD8865ULL + 0x9C6DC2FACEDDF902ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA652B08E033DC343ULL + 0xC1DC90A6A558F832ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF91CDC68560B9777ULL + 0xB43D4899B89863B9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA55298C64C83E15ULL + 0x91722AAB38455C76ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x89D2BB2ADCEF4D75ULL + 0x818010C7150EBA60ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xCCCD27918565B301ULL + 0xA1AFED366521B558ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC5F26C0C757CE4ADULL + 0xDA78F933885DF9AEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD9A56B84AC70059DULL + 0xD01052130BC9527CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB285A27C11F5BD8BULL + 0xE3D5E17585AFB858ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF0EF2DC22C6F291BULL + 0xE23621DF3EBD7849ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE1F22F694C574347ULL + 0xA90A56ED60A4A4EAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x933410C65F2F65CFULL + 0xA3921FA9DF1C832AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCA3284AC0BA6D8C1ULL + 0x88E17BE15254D567ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB619313DBFDDA17FULL + 0xBD5F2F41F0B00407ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB, aSnowLaneC, aInvestLaneD, aWorkLaneD, aSnowLaneD, aSnowLaneB, aExpandLaneA, aSnowLaneA, aExpandLaneB, aInvestLaneA, aExpandLaneC, aInvestLaneC
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 91U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 1885U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 322U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4132U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3368U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 704U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 24U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 5160910997561396461U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 19U)) + 14920764751058512062U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 27U)) + 6080952401749660022U) + aNonceWordI;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 17667234330526298627U) + aNonceWordN;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 23U)) + 760630072638686756U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 41U)) + 3504157162816997476U) + aNonceWordK;
            aOrbiterG = (((aWandererG + RotL64(aCross, 14U)) + 9489022223422585882U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 1149898536879968964U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 51U)) + 10492284328940025310U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13213275606286399312U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 10557118912847180413U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 10077877991284587845U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15618980209023994776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5268600749854045564U;
            aOrbiterA = RotL64((aOrbiterA * 3849660559223919613U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8011552687609649990U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3148133096349525066U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 5245156554959620007U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12032847944237867285U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14999005703490824673U;
            aOrbiterE = RotL64((aOrbiterE * 6631584955208646049U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5426735969392906710U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3593177531650386729U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12997284886192717043U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1701444719333347373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15928731228196894960U;
            aOrbiterI = RotL64((aOrbiterI * 1919318226904213433U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5960179456039157036U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5716434224061596483U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 3731976564761202801U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 2136841536293340279U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12969550408652728526U;
            aOrbiterK = RotL64((aOrbiterK * 7612191387451455137U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3641997570461447114U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4677572491523684525U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2730358077882211651U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 26U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 28U));
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterF, 5U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordC);
            aWandererG = aWandererG + ((RotL64(aIngress, 36U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 44U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 8218U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 7804U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10472U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 6545U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9539U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7669U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 10879U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (((aWandererG + RotL64(aCross, 5U)) + 8685374557928800912U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 3482312691892161229U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 10U)) + 6948130297389161165U) + aNonceWordA;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 29U)) + 5506385663788942690U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 41U)) + 17859982009307397161U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + 9178488809207094043U) + aNonceWordK;
            aOrbiterK = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 1835479501226057169U;
            aOrbiterB = ((((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 5368101733632614939U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 14U)) + 9050459666576835422U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9042186993119635078U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17528342580198295025U;
            aOrbiterI = RotL64((aOrbiterI * 14316671546614386775U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6495418332558436882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8834495762667327342U;
            aOrbiterD = RotL64((aOrbiterD * 10783141541937645995U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4364314196965690905U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6357485231062120459U;
            aOrbiterG = RotL64((aOrbiterG * 289429584586504995U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 3321488322626415347U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10817330671781848737U;
            aOrbiterB = RotL64((aOrbiterB * 15875919466358823335U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17974092279281611763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2871472057292789157U;
            aOrbiterE = RotL64((aOrbiterE * 16104199340711015181U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15187929795092006849U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13482063681546475923U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14466266308157364963U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6232152545071397380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17488906002621373262U;
            aOrbiterH = RotL64((aOrbiterH * 4719340606442742577U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12444819880507588549U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13808941689757772497U;
            aOrbiterK = RotL64((aOrbiterK * 6541360905282412317U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8049361354387692374U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7137831335606542401U;
            aOrbiterJ = RotL64((aOrbiterJ * 11022231291507235007U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 46U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 14U) + aOrbiterA) + RotL64(aOrbiterJ, 42U)) + aNonceWordJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 34U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aSnowLaneB
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aSnowLaneB forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13878U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 11173U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 14025U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12755U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 13395U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 18U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = (((aWandererI + RotL64(aIngress, 47U)) + 16802219662864902427U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 14332033461409490629U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 60U)) + 8781794298640286845U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 35U)) + 8459933908074937264U) + aNonceWordM;
            aOrbiterG = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 51U)) + 1883580287986004426U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 39U)) + 17500258188004626118U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 4U)) + 7934811305150872870U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 21U)) + 6380363892361098905U) + aNonceWordL;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 12623079132626676910U) + aNonceWordG;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10455208121949202703U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8805532707916767629U;
            aOrbiterC = RotL64((aOrbiterC * 666082374369701881U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9161544391400377699U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3501434325829663268U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7933545151293799637U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 651783304096081996U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 441505031509930622U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 8045355432310956143U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1771159983581326424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15227946417377695989U;
            aOrbiterI = RotL64((aOrbiterI * 1563141188972797601U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4153717524193279095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4404521756523902829U;
            aOrbiterJ = RotL64((aOrbiterJ * 1410342912973206203U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6231945075461813285U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3864780227164426690U;
            aOrbiterA = RotL64((aOrbiterA * 18031353247480673617U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1509699687948576558U) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17316114302489411191U;
            aOrbiterE = RotL64((aOrbiterE * 15490661284980281585U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2250572827340157410U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6403966113144372915U;
            aOrbiterH = RotL64((aOrbiterH * 726441947009132383U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2329903609147403156U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 2486330017319455238U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17427461345935191757U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterF, 21U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 36U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + aNonceWordK) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterC, 6U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16988U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneC[((aIndex + 19480U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 19364U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18135U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 20878U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 43U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterI = ((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 13583136155674166402U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 5U)) + 12830472187484919497U;
            aOrbiterA = (aWandererC + RotL64(aCross, 51U)) + 18081197909484522509U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 58U)) + 8680634051297891550U) + aNonceWordN;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 19U)) + 13939998767458656823U) + aPhaseFOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 13U)) + 1795730579103692594U) + aPhaseFOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 27U)) + 17369751719734069999U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 224769585901248068U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 4133547085925268180U) + aNonceWordE;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7022512056309567391U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10319484359046945495U;
            aOrbiterA = RotL64((aOrbiterA * 3400140531307001933U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10483878349412282069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6481381149199985736U;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13721077228796934509U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9704818014314175007U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 760445624027740287U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6253040047758584339U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16890211690273641226U;
            aOrbiterD = RotL64((aOrbiterD * 5622534399866057841U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6216227831265032436U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2023609047004658739U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3252332895698310147U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9201669637050388263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5106927540934338576U;
            aOrbiterC = RotL64((aOrbiterC * 6368134569042291431U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 10080368957861445998U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 10784789383436485808U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3794918350254445939U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 15426339824951793026U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17637144549368340331U;
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9941300382181962134U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 8118046374121322097U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8481945819050983127U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 22U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 48U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 60U)) + aOrbiterH) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22599U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneD[((aIndex + 24708U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 22362U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24982U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneC[((aIndex + 24366U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 44U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (aWandererC + RotL64(aScatter, 43U)) + 12535417189990029950U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 10U)) + 6204401443676390273U;
            aOrbiterI = ((((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 869613505613154672U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 15053590879563855802U) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 35U)) + 13338989605204591428U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 18306470022403825392U;
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 1150696349434090218U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + 13549541786420596437U) + aNonceWordM;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 24U)) + 14302878430259588461U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5594199757006711631U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11008472193138708891U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3668516817279364310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 128159531749679984U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6378674346113979108U) + aNonceWordC;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 11438762460659123362U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 2733309638158283953U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10624263004446482910U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12546839706919241411U;
            aOrbiterF = RotL64((aOrbiterF * 11468326687628079347U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8466639576503293921U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5828694979857951504U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7835487310289634515U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16496305151014092976U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 589464613876410567U;
            aOrbiterE = RotL64((aOrbiterE * 13190816610718051897U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4168532743415647825U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15944887793736489375U;
            aOrbiterA = RotL64((aOrbiterA * 17273403561158196717U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11642456814106259483U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1609897693632334867U;
            aOrbiterG = RotL64((aOrbiterG * 12912773555616819941U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 42U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 18U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32258U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 29819U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 30401U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32371U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27807U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 58U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 23U)) + 11039986441331892533U) + aNonceWordB;
            aOrbiterH = (aWandererC + RotL64(aIngress, 43U)) + 6256024955965426119U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 57U)) + 9857443189988995666U) + aNonceWordP;
            aOrbiterB = ((aWandererB + RotL64(aCross, 19U)) + 11900944813380998208U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 27U)) + 8422577734978875541U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 3100835100713928724U;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 11871553509810206993U) + aNonceWordH;
            aOrbiterA = (aWandererE + RotL64(aCross, 53U)) + 17614749493763417027U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 38U)) + 3638372131856199916U) + aNonceWordG;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 6582275259281025770U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 17016882418498941958U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 4269869255230867823U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1747214688658984715U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9356088987044015278U;
            aOrbiterI = RotL64((aOrbiterI * 16221733545319753695U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4056238112133473456U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16013150119949532998U;
            aOrbiterB = RotL64((aOrbiterB * 12913648646318115315U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16076621211111834889U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9940824359571581765U;
            aOrbiterH = RotL64((aOrbiterH * 11624767861336495331U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15624084004784515753U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7630989544834680335U;
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18003586430673313786U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1654118743290334161U;
            aOrbiterG = RotL64((aOrbiterG * 1153250137357176071U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3254189676528343910U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15629083361573065165U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17024833368570949107U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10056859810555674806U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15976683222786846254U;
            aOrbiterA = RotL64((aOrbiterA * 2801754232182942635U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11872378594829637933U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7633773773528713489U;
            aOrbiterF = RotL64((aOrbiterF * 8218288492011593353U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 28U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aNonceWordC);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordD);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 36U) + RotL64(aOrbiterK, 46U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordM) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
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

void TwistExpander_BaseBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9EA24D6864FE1345ULL + 0xACD5E84FC56FBD63ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA5491471FA4E7E05ULL + 0x8462889DDFA20EBFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE7342253E4E055F1ULL + 0xD032CB2FCAA75FAAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA11DFE74D7D19FF5ULL + 0xF67375147C412E50ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD5154A338A1EFBE7ULL + 0xBDD9499A0C7C5736ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD17882DACD3255F1ULL + 0xACB3AEA059688650ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA8DC30EC48FF9A57ULL + 0xC3EBB3582BA4B3EFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC37CBD0C9C1528A7ULL + 0xD86362629A04E4D1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA596DB4EDCAA525FULL + 0xE6EE7C6ABBE9F3CFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC33923FB88B96A3BULL + 0x99E8A48D5EB194F1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA74496D25BE78E01ULL + 0xD2C65DDBE70A9787ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD90FC4EB9E23CB3BULL + 0xC4A9CD215C786199ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC64FEDD3EF916DABULL + 0x9D092DADF1F444E5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x832C7F0C4780A07DULL + 0xC786188AF0A4EBD9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD6B606CC0AD8A5AFULL + 0xBD4F3CF057916606ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE1B525CB5EAE0619ULL + 0xCB433211DF04C55FULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneC, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aFireLaneD, aInvestLaneA, aWorkLaneB, aFireLaneA, aExpandLaneA, aInvestLaneD, aExpandLaneB, aInvestLaneB, aExpandLaneC, aInvestLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5118U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 1322U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 2090U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2148U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 2932U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1030U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 41U)) + (RotL64(aCross, 56U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 51U)) + 5906639480605353429U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 43U)) + 5293518570213287605U) + aNonceWordF;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 11U)) + 15383185501428521377U) + aNonceWordG;
            aOrbiterF = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 15364072512743978902U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 3U)) + 4525473357144014271U) + aNonceWordJ;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 10400911938125603074U) + aNonceWordC;
            aOrbiterB = ((aWandererA + RotL64(aCross, 20U)) + 16417506293824627550U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2419329331753341815U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14929222427923332069U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 11596261802662514979U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 16771573504983922586U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1863466450051787622U;
            aOrbiterJ = RotL64((aOrbiterJ * 2585626547126027053U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12895350137096692415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3700979086526298327U;
            aOrbiterF = RotL64((aOrbiterF * 10279730254867618193U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1977099106211282426U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6144698304096915742U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5039822990560519609U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3858895556659724975U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1283646340363435327U;
            aOrbiterB = RotL64((aOrbiterB * 11622421841377018069U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 6240532051889108891U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 757364889381634634U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 943852137901972945U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5272945693977418174U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6850528198786172283U;
            aOrbiterK = RotL64((aOrbiterK * 1966383079897679953U), 53U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 6U)) + aOrbiterK) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aPhaseHWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordH) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 36U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9894U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((aIndex + 10789U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7836U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneD[((aIndex + 9241U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8876U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10796U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 5676U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 47U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 4U)) + 13481227414590594621U) + aNonceWordF;
            aOrbiterC = (aWandererD + RotL64(aIngress, 47U)) + 17425964381118918026U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 4792004356135956581U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 11926849936000639098U) + aPhaseHOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 990697329347742142U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 41U)) + 9307721505373076588U) + aNonceWordN;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + 17605732738841908719U) + aNonceWordO;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13110764518634187439U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17970109897810645911U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10395095143998920213U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10273133817644703654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11239046688920468137U;
            aOrbiterF = RotL64((aOrbiterF * 5197802934333553327U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8355821483275763145U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15522151127786049345U;
            aOrbiterB = RotL64((aOrbiterB * 4844278537850520413U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5381663179722418112U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9551368011768104906U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14202470972121732997U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 16264476585232221270U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7721417776432288282U;
            aOrbiterC = RotL64((aOrbiterC * 10267770327791051869U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 339418090653475277U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 3247926250495935511U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 16824669543765729097U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3390560045236418590U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3894024951542543635U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 10599637790900418767U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 22U)) + aNonceWordE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16224U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneA[((aIndex + 13955U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13902U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11324U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 14016U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((((aWandererJ + RotL64(aPrevious, 28U)) + RotL64(aCarry, 51U)) + 3970829908171131502U) + aPhaseHOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 7040283759419531991U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 11856292169397052901U) + aNonceWordP;
            aOrbiterG = (aWandererC + RotL64(aCross, 5U)) + 819598588791819022U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 37U)) + 2176451710970866848U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 53U)) + 6454704928613390494U) + aPhaseHOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = (aWandererB + RotL64(aIngress, 47U)) + 11792122387218053841U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9254780213489752211U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16591812589999846482U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 5425771603523423167U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1471246223935074832U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 1424843083106386453U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15020536982657410783U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1856469958050891629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6331743690452052712U;
            aOrbiterH = RotL64((aOrbiterH * 15327924647897459645U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 10351075711345476487U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 9518585245330480185U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 3792179827396760391U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17787514620244712033U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14182328067398162557U;
            aOrbiterC = RotL64((aOrbiterC * 18107337388659070197U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12798088948801072444U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9563215159275202323U;
            aOrbiterG = RotL64((aOrbiterG * 7058145016617349141U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9904919772580498232U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16579777394992143043U;
            aOrbiterI = RotL64((aOrbiterI * 10516761340320196661U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 20U) + aOrbiterF) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17545U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 20567U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19512U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19183U)) & S_BLOCK1], 26U) ^ RotL64(aSnowLaneD[((aIndex + 18200U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 4259993311776766595U) + aPhaseHOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 2857813330021126753U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 21U)) + 1345396841329442896U) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aCross, 58U)) + 320992148982301024U) + aNonceWordN;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 5619109532065293074U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 10380157329426706345U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 51U)) + 12449831150625409695U) + aNonceWordM;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 7847096607042268396U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11707184096803214678U;
            aOrbiterD = RotL64((aOrbiterD * 1959476948106553973U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9893643746186827088U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 333687403830908774U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 17911256836121454271U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13837360705077441580U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4367119682175710689U;
            aOrbiterB = RotL64((aOrbiterB * 10295744669174603401U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1193493435041306784U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15062951612027370606U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2509383510565136549U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16000173839235429105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15294482444605409961U;
            aOrbiterJ = RotL64((aOrbiterJ * 1031800997944302665U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5720749055549773527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17248674962996093668U;
            aOrbiterK = RotL64((aOrbiterK * 15730637462755795591U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16956840483882091059U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 9637715107943515594U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 8878362378343603463U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + aNonceWordF) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ) + aNonceWordL);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 6U)) + aOrbiterI) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24224U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 25032U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25771U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24555U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 25408U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 35U)) + 4476099022490972343U) + aNonceWordJ;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 16836423700375760429U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 41U)) + 8850577488928703557U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 12U)) + 7091631824560042743U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 47U)) + 12560498899956759494U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 7797973377112012161U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 6173820673874805794U) + aNonceWordA;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10805025132310245348U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7139216143268029968U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 8349754682635765573U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 8241544862261635722U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4735527016563596150U;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5166171126690294033U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11117641762075368393U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6312932356458415421U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1304139291184508668U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 90744653170922319U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10085025354842771067U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16745854428789531080U;
            aOrbiterB = RotL64((aOrbiterB * 1945983905747274355U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2497187958708890337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16069701876646548995U;
            aOrbiterJ = RotL64((aOrbiterJ * 16606039730973709495U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17242004368025978091U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12334315722243232121U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16528598396696346719U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 48U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + aNonceWordN) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterK, 22U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29524U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 28457U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 31881U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32180U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 30537U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U)) + (RotL64(aIngress, 50U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererG + RotL64(aCross, 41U)) + 15652862298542575895U) + aNonceWordP;
            aOrbiterB = (aWandererA + RotL64(aScatter, 53U)) + 16925323928418184554U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 13U)) + 4413861484961668394U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 2215946422098155969U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 14975185533513111110U;
            aOrbiterA = ((((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 9711613814905834552U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 27U)) + 13154957291850149471U) + aNonceWordH;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 5058313016418534840U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15011423472941211620U;
            aOrbiterF = RotL64((aOrbiterF * 6125316151731105673U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 2030053257469580168U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 150530795186791193U;
            aOrbiterK = RotL64((aOrbiterK * 11106050063717096073U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10878237472104183427U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11724672539469573109U;
            aOrbiterA = RotL64((aOrbiterA * 16158741837357985395U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9589700906445846956U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1367381624958248949U;
            aOrbiterB = RotL64((aOrbiterB * 8459515089081211977U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 12003215666757518106U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11232479330848006729U;
            aOrbiterG = RotL64((aOrbiterG * 10993290955464593033U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13013910456628561621U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6092509838924105265U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 805601154718006061U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11999225836250312801U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 14421271973875748413U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9529010940887430157U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 58U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + aNonceWordN);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterB, 56U)) + aNonceWordC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + RotL64(aOrbiterD, 35U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordO) + aPhaseHWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
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

void TwistExpander_BaseBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2723U)) & W_KEY1], 26U) ^ RotL64(aKeyRowReadB[((aIndex + 990U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2192U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 2328U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 51U)) + (RotL64(aPrevious, 12U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 5480870806135400132U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 42U)) + 8034874599430768743U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 4006919843736863767U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 2988069748674633718U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 35U)) + 12347295651973135786U;
            aOrbiterC = (aWandererH + RotL64(aCross, 3U)) + 14152683894431568192U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 43U)) + 15765143815254196598U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 51U)) + 10473067082331244233U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 47U)) + 1089466925383677249U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13215039929873682230U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3957997712247961479U;
            aOrbiterK = RotL64((aOrbiterK * 7631186240013784703U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10023907397941685546U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13353797968154036726U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 9259966668512102858U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8326732574268308221U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10757861831070349321U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10530223113483866178U;
            aOrbiterD = RotL64((aOrbiterD * 11269177745265396583U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7554320926405521865U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6978052067277966996U;
            aOrbiterF = RotL64((aOrbiterF * 18020134738536217801U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1053695861967171420U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15980734683539854451U;
            aOrbiterC = RotL64((aOrbiterC * 3208466640010555357U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17041258393808061556U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12846551858751995530U;
            aOrbiterG = RotL64((aOrbiterG * 9303891433380993639U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14617434286683320666U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3999309956180741302U;
            aOrbiterJ = RotL64((aOrbiterJ * 15037707937050015205U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13452627760403094126U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2633241575260427158U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2638570213290747581U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterA, 22U));
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + (((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterI, 18U));
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4118U)) & S_BLOCK1], 44U) ^ RotL64(aKeyRowReadA[((aIndex + 4714U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4947U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 4495U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 39U)) + 6973892330986118220U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 3U)) + 9886813896272094864U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 10996306582517553173U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 8490648283899856223U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 19U)) + 105141713530704655U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 3114337422810562588U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 23U)) + 980857684690886131U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 48U)) + 6562042345807072665U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 11U)) + 15665371138706353619U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18113013571374375028U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17405346422601997299U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11162604605443005253U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5130876096426182506U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1813821672299154629U;
            aOrbiterC = RotL64((aOrbiterC * 15478100342425611875U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15793814882743306728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13925299440495476399U;
            aOrbiterK = RotL64((aOrbiterK * 12049601510660117401U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9924458846049579438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7810034662781768090U;
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 12812586478656872854U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5709576448057435237U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9101555233909853025U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7839807649914541516U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4717944526755429647U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8515229146471335721U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3933911971504256022U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4814079680865379831U;
            aOrbiterI = RotL64((aOrbiterI * 15100740696230557391U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 18352577312212175569U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9670612998448920742U;
            aOrbiterB = RotL64((aOrbiterB * 5743579439303300553U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 72737302703035726U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10032869372369626210U;
            aOrbiterA = RotL64((aOrbiterA * 7449905669249993731U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 14U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aPhaseAWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterI, 58U));
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5568U)) & S_BLOCK1], 34U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6956U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6232U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5719U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6650U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 60U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 29U)) + 701291026547470433U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 17283292650462111643U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 9969124091931303406U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 889176772718046988U;
            aOrbiterA = (aWandererB + RotL64(aCross, 19U)) + 6054541844643748084U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 5U)) + 14703226235143028132U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aScatter, 51U)) + 7977975878522921062U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 58U)) + 16894322614172266274U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 39U)) + 12160451749345900570U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10870847008043897470U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8159920947172520247U;
            aOrbiterD = RotL64((aOrbiterD * 4833194641611011805U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2440099120969517932U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2428396147731468007U;
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 2213226274394673479U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7079731443427765333U;
            aOrbiterA = RotL64((aOrbiterA * 16918930776877030559U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 958896789550478970U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10788682955708075458U;
            aOrbiterH = RotL64((aOrbiterH * 913321215613559729U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2003386579317564870U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8419686358774204999U;
            aOrbiterB = RotL64((aOrbiterB * 6547052526438697621U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6989167615157578904U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17636634003643824148U;
            aOrbiterE = RotL64((aOrbiterE * 11038576417283732937U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13824962118933907859U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9543912892587859646U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14736710162285997415U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15729878041027706114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9542137475454825463U;
            aOrbiterF = RotL64((aOrbiterF * 11420547128115090491U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5327302277575009955U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2707383132257428583U;
            aOrbiterJ = RotL64((aOrbiterJ * 6120763309390182129U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 12U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 53U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 24U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + aPhaseAWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterC, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9893U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 10214U)) & W_KEY1], 22U));
            aIngress ^= (RotL64(mSource[((aIndex + 10093U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 10340U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8445U)) & W_KEY1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10741U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 34U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 37U)) + 17081642665820489793U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 29U)) + 14468854040067229623U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 60U)) + 2249450222593057429U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 21U)) + 14964389079511378664U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 17003491054252360650U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 43U)) + 12710882240582032588U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 27U)) + 9887078182156755359U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 7665284531810584704U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 11U)) + 7304284015511876717U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5517927023543751734U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17704756310857362759U;
            aOrbiterF = RotL64((aOrbiterF * 15826832172923213591U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11347400363019508578U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11696395232760991243U;
            aOrbiterD = RotL64((aOrbiterD * 9725231749679442003U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 10875780291242873583U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7808740614343437672U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8889516201913716283U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3145390996141902032U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16080636485642732615U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7445756373012217305U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3929263288176983844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 18210228766683996806U;
            aOrbiterC = RotL64((aOrbiterC * 13178080076505449091U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13948962323541421431U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3037683309790156893U;
            aOrbiterG = RotL64((aOrbiterG * 13406672352222636739U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17827265198532699474U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7270895262023504864U;
            aOrbiterK = RotL64((aOrbiterK * 13467417362477308167U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6431243064980879185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6680205390976259885U;
            aOrbiterI = RotL64((aOrbiterI * 10421386694108590789U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15910655919164357152U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8046213498216027383U;
            aOrbiterH = RotL64((aOrbiterH * 18061867495824063553U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 36U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 58U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 6U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 14U)) + aOrbiterI) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13269U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 13364U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11110U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 11787U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11046U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13437U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 12809U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 13915875634607599122U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 34U)) + 1695770381382411673U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 5U)) + 3709105579778295511U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 51U)) + 7673376335333251804U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 57U)) + 8814147709738503518U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 13451412605350381172U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 27U)) + 6447870234069609538U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 12U)) + 13419487997946496825U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 5478309847615220345U) + aPhaseBOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3635184969215610049U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12527903812035294828U;
            aOrbiterJ = RotL64((aOrbiterJ * 12540800512035534967U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1684685110885338814U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12860354576326835090U;
            aOrbiterK = RotL64((aOrbiterK * 12743745087733307255U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9081823570147481835U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14369321778210049109U;
            aOrbiterG = RotL64((aOrbiterG * 17865953349448767035U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11518132079084873250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11893535026126957389U;
            aOrbiterB = RotL64((aOrbiterB * 15751374986135615095U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7084079180579206226U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2999676609847603277U;
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17683445810614029153U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11576460512964896969U;
            aOrbiterH = RotL64((aOrbiterH * 5243651036457051155U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13429800604736567949U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14661785761747367546U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4765843989277333421U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12837164345582888950U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6222666313184669392U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17402483466567712319U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5358647039491079457U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12459911673401497180U;
            aOrbiterD = RotL64((aOrbiterD * 13605465035256188065U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 44U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterG, 20U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 39U));
            aWandererD = aWandererD + ((((RotL64(aCross, 24U) + RotL64(aOrbiterC, 43U)) + aOrbiterG) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 14U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15259U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14984U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14956U)) & W_KEY1], 24U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15290U)) & W_KEY1], 51U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15479U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15478U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15157U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererB + RotL64(aIngress, 52U)) + RotL64(aCarry, 27U)) + 16160838483846078448U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + 15404960896190227946U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 16904160594024977199U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 11U)) + 17790460246821031802U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 19U)) + 16395168254086971959U) + aPhaseBOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 7484373204039901786U;
            aOrbiterH = (aWandererG + RotL64(aCross, 30U)) + 18026814691322913510U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 15244817793136966450U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 35U)) + 5795491730356335666U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3163873518027801504U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2690791759507349172U;
            aOrbiterA = RotL64((aOrbiterA * 16677948635136515083U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17898067251167087906U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 8028010015006604239U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5601629670521300241U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7304739457289910555U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6476837815096530043U;
            aOrbiterH = RotL64((aOrbiterH * 16380545138701113267U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14242499233467960602U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17305645693017634630U;
            aOrbiterD = RotL64((aOrbiterD * 14442976693206929569U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9772864059444171908U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7897200728282156408U;
            aOrbiterF = RotL64((aOrbiterF * 816306719390807411U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4890999319172950996U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8165132649356094963U;
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9342923520083533265U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7213639583505088067U;
            aOrbiterE = RotL64((aOrbiterE * 1349251979649428909U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4079475132684197272U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3350998022472827283U;
            aOrbiterB = RotL64((aOrbiterB * 948841791460066265U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2479140576609216238U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7703147534931674972U;
            aOrbiterJ = RotL64((aOrbiterJ * 11419116495223970801U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 4U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 20U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 38U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 51U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterC, 42U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16679U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[((aIndex + 16494U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(mSource[((aIndex + 17085U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18035U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18730U)) & W_KEY1], 13U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17886U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16609U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 39U)) + 13174219512651137892U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 2715455762789269341U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 1338018183235594313U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 48U)) + 16566866551729552930U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 53U)) + 6901845297307236726U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 57U)) + 2476078302049201718U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 3U)) + 15531109473927052260U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 11U)) + 4087849380858572351U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 11U)) + 5167830630098599644U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7275995452428627217U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14794340370010024117U;
            aOrbiterD = RotL64((aOrbiterD * 8779497557416568379U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8509217403041662849U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2321522025240806996U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5676672952755594051U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2304681269233504384U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8383399721062437300U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13181984036942227666U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1648761328771932069U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 13602604532551684210U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12725687663616352843U;
            aOrbiterH = RotL64((aOrbiterH * 4684699861686199753U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5831790822416009806U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4535048543735457407U;
            aOrbiterE = RotL64((aOrbiterE * 12076777878870257053U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10617608605149381858U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5244225377862618630U;
            aOrbiterK = RotL64((aOrbiterK * 15307177251167023999U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18229989093139888456U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9728120630096192811U;
            aOrbiterB = RotL64((aOrbiterB * 16052574428163231023U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1312233443099767304U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8043115602160128619U;
            aOrbiterA = RotL64((aOrbiterA * 9365756845731616963U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 46U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 26U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 12U)) + aOrbiterB) + aPhaseCWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 47U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aCross, 56U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererB, 38U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20708U)) & S_BLOCK1], 35U) ^ RotL64(mSource[((aIndex + 19994U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20630U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19668U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19208U)) & W_KEY1], 60U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19955U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21557U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20844U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 40U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 24U)) + 16183871922837164759U) + aPhaseCOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 35U)) + 7002058258090219055U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 57U)) + 5650868611888303705U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 47U)) + 11899839660943876690U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 35U)) + 15349649504488111111U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 5U)) + 14060149569086744970U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 12920917574225030112U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 52U)) + 2831994965175330135U;
            aOrbiterI = (aWandererI + RotL64(aCross, 47U)) + 18312543585028439192U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11657562205118394239U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10850792819281246052U;
            aOrbiterE = RotL64((aOrbiterE * 10663100544207879337U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 17810371216216125323U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7963413941144223128U;
            aOrbiterD = RotL64((aOrbiterD * 534217972450595401U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5498715358793875584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9256727548911651373U;
            aOrbiterK = RotL64((aOrbiterK * 10498848323914000989U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17246360111302191699U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18309978718113983369U;
            aOrbiterG = RotL64((aOrbiterG * 18267472694666221077U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3100998994319502921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8129301860291235970U;
            aOrbiterA = RotL64((aOrbiterA * 17847033539279176187U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1889641029473279114U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16538494307002917945U;
            aOrbiterH = RotL64((aOrbiterH * 8081488217920885783U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5432230549146849322U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2634437941396090817U;
            aOrbiterI = RotL64((aOrbiterI * 7612999214758935211U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16940172599174185058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13151669140593952203U;
            aOrbiterB = RotL64((aOrbiterB * 16225319638131723487U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3995064294869931681U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 913081077665768816U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9299514648768060453U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 46U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 58U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 51U)) + aOrbiterH) + aPhaseCWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 39U)) + aOrbiterD) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23450U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 22582U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24307U)) & W_KEY1], 52U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23573U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23457U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22184U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23287U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 22417U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 57U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 21U)) + 3917730204724097072U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 46U)) + RotL64(aCarry, 23U)) + 1874642340716212824U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 3U)) + 6900165757434854160U) + aPhaseCOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 12750946097023807161U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 51U)) + 6563216048479513594U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 57U)) + 14960240191349450795U;
            aOrbiterB = (aWandererF + RotL64(aCross, 12U)) + 16306180275951788289U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 35U)) + 6502066618271045547U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 41U)) + 6219852857850888738U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2272931312452845850U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3028929882263199463U;
            aOrbiterE = RotL64((aOrbiterE * 11005324285856805069U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6067393030073568112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10094809900437037258U;
            aOrbiterC = RotL64((aOrbiterC * 18095564940730322769U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5962414178157074575U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15755563045799129417U;
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6321455513889880590U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1197435601998121700U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17693996266260557625U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12496949381666299968U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6357070235648527030U;
            aOrbiterJ = RotL64((aOrbiterJ * 2931486644220862433U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8423760160877540210U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8090246492554850768U;
            aOrbiterB = RotL64((aOrbiterB * 2949407491181921633U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11436635942985063755U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17086363141014359856U;
            aOrbiterD = RotL64((aOrbiterD * 10504127577318206801U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10734017887545474935U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 375515325165740779U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9980486695448151709U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5217148491945389821U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14696058217023530058U;
            aOrbiterA = RotL64((aOrbiterA * 11026674782236654799U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 22U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 22U) + aOrbiterD) + RotL64(aOrbiterG, 34U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 29U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 39U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterC, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 46U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26365U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 26150U)) & W_KEY1], 56U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24967U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26154U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26600U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25521U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25498U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25127U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 43U)) + 13714409587461539863U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 14101156723903265839U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 29U)) + 7063754562895369001U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 12320578575245519386U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 5U)) + 11744826789631008424U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 53U)) + 8744816505096675597U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 4U)) + 10405435520084528645U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 47U)) + 1463157688070683543U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 19U)) + 12379603577919617703U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1343439118031348146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16118850268070235540U;
            aOrbiterC = RotL64((aOrbiterC * 11184386483735388257U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14116264435819277136U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5251698273012432109U;
            aOrbiterD = RotL64((aOrbiterD * 1495818611622063967U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 14806408656041403829U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11569345414052398227U;
            aOrbiterE = RotL64((aOrbiterE * 9913158908301414861U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17063874769147888574U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9927420478679581917U;
            aOrbiterI = RotL64((aOrbiterI * 9042782809534196563U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 2550285599827162167U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17801534123304996448U;
            aOrbiterG = RotL64((aOrbiterG * 2160836889363614721U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6456685241021762041U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17064208177372969289U;
            aOrbiterJ = RotL64((aOrbiterJ * 13726627607233302493U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18279938244131982650U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8211002229712129419U;
            aOrbiterK = RotL64((aOrbiterK * 12931373380977640645U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12795832560781931767U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 286378504074349650U;
            aOrbiterB = RotL64((aOrbiterB * 85453101173293509U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5835304250436889513U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12704972686724379659U;
            aOrbiterH = RotL64((aOrbiterH * 1198789639656336053U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 60U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 52U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 23U));
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterC, 4U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterK, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 44U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28492U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneD[((aIndex + 29018U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27976U)) & W_KEY1], 35U) ^ RotL64(aFireLaneC[((aIndex + 27409U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29440U)) & W_KEY1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28147U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29310U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27936U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 20U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 19U)) + 12222235191147985484U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 16367317014523328414U;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 3511378091284703789U) + aPhaseDOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 15247492830966725949U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 7745995913390407897U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 56U)) + 6463593307540108810U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 1101669311005268630U;
            aOrbiterC = (aWandererG + RotL64(aCross, 27U)) + 12988052764067518580U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 3U)) + 17717179747434679772U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11662190906682400416U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6563014073547628748U;
            aOrbiterK = RotL64((aOrbiterK * 16967910471722117761U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13099094932059419219U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16342730862261868847U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10988124108686164829U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16855346813127524624U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6570063128502306944U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4571570049463124831U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11328352033809240501U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11640986648833160901U;
            aOrbiterD = RotL64((aOrbiterD * 2895830492089678919U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2675226158571501666U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17700531248266458165U;
            aOrbiterJ = RotL64((aOrbiterJ * 2231403813970188657U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7729597396731910874U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15172374484412053756U;
            aOrbiterC = RotL64((aOrbiterC * 149009041406406517U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9178769489257842683U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9020154972097834926U;
            aOrbiterB = RotL64((aOrbiterB * 8910504667566521429U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1317403761217790562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17151528554929201571U;
            aOrbiterE = RotL64((aOrbiterE * 3735945655450625203U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11621882033959669977U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10289504450815075623U;
            aOrbiterH = RotL64((aOrbiterH * 13365982786836243195U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 18U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 26U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aPhaseDWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 6U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 30U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31347U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30904U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30876U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31995U)) & S_BLOCK1], 39U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32005U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31191U)) & W_KEY1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 9133751643283278896U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 4U)) + 8971581804375380408U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 23U)) + 12559650383714566592U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 47U)) + 15753206088872859163U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 7640756270450762350U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 10U)) + 7340073357551376125U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 5270256573644196046U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 3567367996479995928U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 27U)) + 11939634537492733738U) + aPhaseDOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7051817732424527120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1730487669951837941U;
            aOrbiterB = RotL64((aOrbiterB * 15191634337956285841U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18009252467909454817U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2361024272031696442U;
            aOrbiterF = RotL64((aOrbiterF * 15215151562500226027U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 15902755877642960397U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12243517544704116184U;
            aOrbiterC = RotL64((aOrbiterC * 2576071074148141447U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16846181962302186187U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 636121425116506681U;
            aOrbiterG = RotL64((aOrbiterG * 17075030673338779993U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6887385655828217318U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3705834550934775862U;
            aOrbiterH = RotL64((aOrbiterH * 11275428284929594435U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11165142437077969438U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6426659930331618269U;
            aOrbiterD = RotL64((aOrbiterD * 17170640810530893705U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12629082390899315789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4277510580069574724U;
            aOrbiterE = RotL64((aOrbiterE * 9829125163412708305U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13814834144170469978U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3698381854100295826U;
            aOrbiterK = RotL64((aOrbiterK * 5126359230872258015U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11623170635983579937U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7247413650388803796U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3403219499465560059U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 22U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 18U) + RotL64(aOrbiterH, 29U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + aPhaseDWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + RotL64(aOrbiterF, 4U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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

void TwistExpander_BaseBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1325U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 534U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3758U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4210U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 4120U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 14008824488073394623U) + aPhaseEOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 13U)) + 13317978415866411468U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 13209180141897453900U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 44U)) + RotL64(aCarry, 53U)) + 11870521586865233578U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 29U)) + 8052156380448047385U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 23U)) + 12158131176743680605U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 35U)) + 14674467487607719347U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18055496790566231147U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3838105585041578784U;
            aOrbiterJ = RotL64((aOrbiterJ * 1075709247574580091U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2839568255183054418U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11933612922864258179U;
            aOrbiterE = RotL64((aOrbiterE * 7571964469321160347U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6289849094151630580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2640344350528492271U;
            aOrbiterI = RotL64((aOrbiterI * 16197726750829369365U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16306175266267657791U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3339898380394883600U;
            aOrbiterA = RotL64((aOrbiterA * 7105436590182982373U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15017076663742800002U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8973064296077602496U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9309462227233615761U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17580319233338139859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14063208878807603874U;
            aOrbiterC = RotL64((aOrbiterC * 16601475239075164585U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13326130855721009942U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12843186026737544416U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4975848122837321619U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 28U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 44U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 13U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10350U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 8174U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 7792U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9487U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8825U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 11U)) + 12311607308490066301U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 47U)) + 13100864684740679846U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 53U)) + 13697304189274329704U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 38U)) + RotL64(aCarry, 5U)) + 9047976902871216732U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 2147897579538537888U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 5U)) + 2072444829390996142U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 2129307836981020908U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10663145333751112064U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15019844390503785459U;
            aOrbiterD = RotL64((aOrbiterD * 7442321463110790449U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5460865577557928142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15806522559993224197U;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6361113778657833389U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8306013884615042570U;
            aOrbiterJ = RotL64((aOrbiterJ * 8234258702656728667U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 4038420580499706912U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11908091484457158973U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3964111175645156719U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11133912466611921250U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2469227904206936928U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2704438771198001599U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13234017916788297295U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9061117693840451988U;
            aOrbiterG = RotL64((aOrbiterG * 3637440416741459419U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12013423690843812324U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14371779015144617412U;
            aOrbiterK = RotL64((aOrbiterK * 3359568073302062667U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 26U) + RotL64(aOrbiterK, 38U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14946U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 15677U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 11879U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15449U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12472U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12987U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 36U)) + RotL64(aCarry, 39U)) + 10038936806177516123U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 1773168435195292638U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aCross, 5U)) + 10655711161526628072U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 53U)) + 14422295664639740437U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 23U)) + 4125228715513159576U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 3670449653158650845U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 47U)) + 17553727567180813057U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5111401772713882743U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7688573124662314413U;
            aOrbiterI = RotL64((aOrbiterI * 10846442063022821393U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9438375825507814395U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14177477039902118886U;
            aOrbiterF = RotL64((aOrbiterF * 6467406626985022537U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16329942595859623928U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3990536794006836672U;
            aOrbiterC = RotL64((aOrbiterC * 579024714339065373U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5072881436583180756U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16789727877867289997U;
            aOrbiterH = RotL64((aOrbiterH * 8766246302636197905U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17313956922306689438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11530878396329822041U;
            aOrbiterB = RotL64((aOrbiterB * 11356860047841383129U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3612616532321160196U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterA = RotL64((aOrbiterA * 12938945495299393177U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8677279703778052804U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1912172980909479362U;
            aOrbiterJ = RotL64((aOrbiterJ * 10053289257955474143U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + RotL64(aOrbiterI, 18U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20179U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneC[((aIndex + 16537U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 17797U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17401U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20994U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21836U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 10881271196314989997U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 58U)) + 6406461249988567558U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 17255067918280095959U) + aPhaseEOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 16690850682497718411U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 35U)) + 5576201059361086866U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 11991259685693687554U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 21U)) + 14652535244217836909U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1701789037170782122U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 953429054903473833U;
            aOrbiterH = RotL64((aOrbiterH * 13482379459700651427U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12064513610469714211U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7993881398822002424U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11572884842788918377U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14421313768013320050U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11112386845630998889U;
            aOrbiterA = RotL64((aOrbiterA * 11771526352030371669U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17069630896535699015U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3308240081138623373U;
            aOrbiterC = RotL64((aOrbiterC * 10449509484417835159U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17615529807112933619U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11782807146851563541U;
            aOrbiterF = RotL64((aOrbiterF * 12992075832343669221U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14401645829607611983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6736397344219993532U;
            aOrbiterI = RotL64((aOrbiterI * 1667287547938175641U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6446974060524700550U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7840991992443308254U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6891023544882740107U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 12U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 41U));
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 29U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22272U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 24150U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22751U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22097U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22489U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 26141U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 56U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + 14823268998003220191U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 57U)) + 15295237288788213847U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 16434853402001133899U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 7555911304407871631U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 14977248264994834620U;
            aOrbiterH = (aWandererF + RotL64(aCross, 12U)) + 9707764144919392380U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 29U)) + 1277304385464681529U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3089786220465849395U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3700503853358695085U;
            aOrbiterI = RotL64((aOrbiterI * 2079089949442685421U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3240054112993517371U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16897532076915366859U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18167359289798364307U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8870819278575769863U;
            aOrbiterC = RotL64((aOrbiterC * 9334066154398059075U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15363069206212330251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14858164441499725158U;
            aOrbiterH = RotL64((aOrbiterH * 14931933411393847915U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5357144808788707522U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2910681277417754860U;
            aOrbiterB = RotL64((aOrbiterB * 13170868582159347059U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9824408699018165151U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 368370224788793300U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14358982366258729959U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7095398304588825115U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11418879758164313554U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5983520332639771791U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterE, 13U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 29U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterE, 60U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32415U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30274U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27708U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32749U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28072U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 30934U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 19U)) + 7790166497945719700U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 7136208896846119188U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 35U)) + 12123156943355100886U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 5095546037880875199U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 17642705393916765992U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 27U)) + 9918479837334416990U) + aPhaseEOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 6U)) + 4890009823843176466U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17652590786213674124U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 870002527644696135U;
            aOrbiterH = RotL64((aOrbiterH * 915408393979165539U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12545429703552643682U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5310272867406182581U;
            aOrbiterF = RotL64((aOrbiterF * 10420003334833925011U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3264719049050179440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1967241238180278937U;
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 773883832927040736U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12766817190261232485U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7448864556802318431U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 260069382395598265U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15462103891287350123U;
            aOrbiterA = RotL64((aOrbiterA * 5029268763635635753U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4072032867513289827U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17153061419083897076U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11934532169271718913U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6207264270332656966U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 18048064697837314947U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13632594619404208489U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterA, 47U));
            aWandererG = aWandererG + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 58U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 30U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_BaseBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneC, aSnowLaneA, aInvestLaneD, aInvestLaneB, aSnowLaneB, aExpandLaneA, aWorkLaneA, aInvestLaneA, aWorkLaneB, aExpandLaneD, aWorkLaneC, aExpandLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 961U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneB[((aIndex + 2919U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 4545U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3090U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3531U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 3480U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 37U)) + 1393781663398437180U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 17414594746688585273U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 21U)) + 2823888497053071250U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 19U)) + 17032631958617884859U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 39U)) + 15222697630461125019U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 46U)) + RotL64(aCarry, 43U)) + 15737414920751551780U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 35U)) + 1357196111055783001U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + 5315122321649251691U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aCross, 23U)) + 7893744655508595974U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 53U)) + 16721939414324611738U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 13U)) + 3444375866323610848U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1825716513674511632U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15582066843912467318U;
            aOrbiterI = RotL64((aOrbiterI * 12765146555943757373U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15673590949193923915U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13887365046280406413U;
            aOrbiterB = RotL64((aOrbiterB * 3169061375011420121U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12730414371734709356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3089925954422937464U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7180179304678622530U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16118051565147747413U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17030269962085008657U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6675917351883004046U;
            aOrbiterD = RotL64((aOrbiterD * 14134335325316949687U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12572022803491077491U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2801421744689267375U;
            aOrbiterJ = RotL64((aOrbiterJ * 315045745990934023U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4335148696780313055U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12526298573395110141U;
            aOrbiterF = RotL64((aOrbiterF * 11276803410698178607U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6984239833558496091U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12195433952105336808U;
            aOrbiterA = RotL64((aOrbiterA * 8642600547427664495U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6392683095502982341U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 18047201953488013325U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16151795290455603489U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15433458942878109208U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1700365768743794306U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16151638348775286903U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10951473638533187729U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1393781663398437180U;
            aOrbiterG = RotL64((aOrbiterG * 2661447713922232789U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 5U) + RotL64(aOrbiterK, 18U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 29U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 10U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 40U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7408U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 5519U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9496U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneD[((aIndex + 5844U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6665U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10836U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 5584U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 21U)) + (RotL64(aCarry, 38U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aScatter, 43U)) + 16183871922837164759U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 34U)) + RotL64(aCarry, 51U)) + 7002058258090219055U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 5650868611888303705U;
            aOrbiterF = (aWandererC + RotL64(aCross, 41U)) + 11899839660943876690U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 5U)) + 15349649504488111111U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 37U)) + 14060149569086744970U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 26U)) + 12920917574225030112U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 2831994965175330135U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 51U)) + 18312543585028439192U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 23U)) + 11657562205118394239U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 21U)) + 10850792819281246052U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17810371216216125323U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7963413941144223128U;
            aOrbiterE = RotL64((aOrbiterE * 534217972450595401U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5498715358793875584U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterB = RotL64((aOrbiterB * 10498848323914000989U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17246360111302191699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3100998994319502921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8129301860291235970U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17847033539279176187U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1889641029473279114U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16538494307002917945U;
            aOrbiterD = RotL64((aOrbiterD * 8081488217920885783U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5432230549146849322U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2634437941396090817U;
            aOrbiterH = RotL64((aOrbiterH * 7612999214758935211U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16940172599174185058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13151669140593952203U;
            aOrbiterI = RotL64((aOrbiterI * 16225319638131723487U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3995064294869931681U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 913081077665768816U;
            aOrbiterC = RotL64((aOrbiterC * 9299514648768060453U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2469001696075411481U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2167390955194185443U;
            aOrbiterG = RotL64((aOrbiterG * 11805065572289005223U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1574066406534010796U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8736976961589874013U;
            aOrbiterA = RotL64((aOrbiterA * 5980070607180321955U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4233621443153132083U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16183871922837164759U;
            aOrbiterJ = RotL64((aOrbiterJ * 4030569514959370895U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 10U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 14U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterB, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 48U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 57U)) + aOrbiterA) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15577U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 15570U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 10993U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13181U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((aIndex + 16337U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 9023059520606551446U;
            aOrbiterA = (aWandererI + RotL64(aCross, 11U)) + 662441755115638133U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 16957253361196144712U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 7840955025765308605U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 47U)) + 346855809270395799U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 57U)) + 16099139781586668343U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 36U)) + 3706457327118322098U;
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 12166825885547622870U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 3U)) + 7792658665720344200U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aIngress, 51U)) + 7128477606152986326U;
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 34U)) + 11116533962780290084U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10443889548568288532U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4402387036946561017U;
            aOrbiterF = RotL64((aOrbiterF * 9032964741841833277U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13002706161178447654U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13929727277530310708U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7005639090871200285U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10949073760696935106U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15405923432006783533U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17989565878445202495U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18096057968822208905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 3032155040484574973U;
            aOrbiterJ = RotL64((aOrbiterJ * 448597307502544605U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17462076466907467134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15471015427013701406U;
            aOrbiterI = RotL64((aOrbiterI * 6113474000571976139U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3549031751266594344U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 14243218483842508113U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9041601306479302047U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5803147589312920032U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5549470512227427855U;
            aOrbiterA = RotL64((aOrbiterA * 12592362489263862879U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10076661824293832189U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3196799148974716550U;
            aOrbiterK = RotL64((aOrbiterK * 8183276968961467775U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5245559903456662243U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5907555542861339984U;
            aOrbiterG = RotL64((aOrbiterG * 10224549416454347583U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12670710096595941569U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 655047039452620836U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9717552134857988153U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2654837870443908572U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9023059520606551446U;
            aOrbiterC = RotL64((aOrbiterC * 170905364378771841U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 42U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 41U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterA, 10U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterH, 56U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneA
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17987U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 18019U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21252U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20904U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 21103U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 36U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 23U)) + 2786079456995203065U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 41U)) + 7237256119153857253U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 3U)) + 9310834010563647604U;
            aOrbiterD = (aWandererE + RotL64(aCross, 23U)) + 17361734905706517877U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 27U)) + 15837111231884647451U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 19U)) + 18065431964418026445U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 21U)) + 3029123922999952652U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 6U)) + 5166926595573507837U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 1918425684273807598U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 4724551751012661440U;
            aOrbiterH = (aWandererD + RotL64(aCross, 51U)) + 1818014487579644390U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6670090372241084216U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8485757110007268693U;
            aOrbiterG = RotL64((aOrbiterG * 11876760095108618363U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4928130251509514742U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2528788422725346792U;
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2860387120895147503U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12927802338151379368U;
            aOrbiterK = RotL64((aOrbiterK * 8876144125458603029U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18029699867733207083U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13361836994951253312U;
            aOrbiterD = RotL64((aOrbiterD * 5349767426256597073U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11957294454794128079U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3755417922063414648U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13896364063651241401U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 18001157153447913032U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16214145724690286854U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5874139687703360515U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3860958772090975562U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12395621524459640173U;
            aOrbiterE = RotL64((aOrbiterE * 722817135977510161U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3402035664910754484U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2139099117325745602U;
            aOrbiterF = RotL64((aOrbiterF * 14008983756425796029U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 7769274487425053026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6492669707749367728U;
            aOrbiterB = RotL64((aOrbiterB * 5149771861620757839U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14963366447884375043U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11398874662567519691U;
            aOrbiterA = RotL64((aOrbiterA * 8221521452475029835U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7168445485232814860U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2786079456995203065U;
            aOrbiterH = RotL64((aOrbiterH * 14258367164534307955U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterK, 26U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 43U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 58U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26630U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 25630U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24277U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27030U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 22378U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 4U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 10881271196314989997U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 6406461249988567558U;
            aOrbiterI = (aWandererF + RotL64(aCross, 6U)) + 17255067918280095959U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 16690850682497718411U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 37U)) + 5576201059361086866U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 23U)) + 11991259685693687554U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 13U)) + 14652535244217836909U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 60U)) + 1701789037170782122U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 27U)) + 953429054903473833U;
            aOrbiterF = (aWandererE + RotL64(aCross, 43U)) + 12064513610469714211U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 7993881398822002424U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14421313768013320050U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11112386845630998889U;
            aOrbiterI = RotL64((aOrbiterI * 11771526352030371669U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17069630896535699015U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3308240081138623373U;
            aOrbiterA = RotL64((aOrbiterA * 10449509484417835159U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17615529807112933619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11782807146851563541U;
            aOrbiterE = RotL64((aOrbiterE * 12992075832343669221U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14401645829607611983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6736397344219993532U;
            aOrbiterC = RotL64((aOrbiterC * 1667287547938175641U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6446974060524700550U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7840991992443308254U;
            aOrbiterG = RotL64((aOrbiterG * 6891023544882740107U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10362169906019794305U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4503700997923168911U;
            aOrbiterD = RotL64((aOrbiterD * 15066164494038852559U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13492041134973259041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14337899277551397976U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5966740718899290915U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13693100781608180748U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16177545026405910052U;
            aOrbiterH = RotL64((aOrbiterH * 6019231448444020563U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9641191118119415680U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 735491776764667034U;
            aOrbiterF = RotL64((aOrbiterF * 11305930862759869997U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2225714710491247284U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16906789796765378455U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4341667316266234469U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9451961177946601088U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10881271196314989997U;
            aOrbiterK = RotL64((aOrbiterK * 10929686721061541543U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 28U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 6U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterF, 41U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29290U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 32600U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28569U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32593U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((aIndex + 31445U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 21U)) + 12615321415808640429U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 37U)) + 15712784676459931207U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 26U)) + 11013335427004930046U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 51U)) + 8298733856304768806U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 29U)) + 6207732959150824216U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 9769864876127544038U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 10782181918651152563U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 11U)) + 5790454015845620939U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 19U)) + 15606578025386733803U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 21U)) + 5522352539991175304U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 14U)) + 5993355818572869649U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10864534396947622047U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12090053126235913528U;
            aOrbiterD = RotL64((aOrbiterD * 7250801471645972261U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14191181677234981396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2258570108233924592U;
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8448114811381534603U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2702389315763499817U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6710443836432274393U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17202184076718780200U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 150549910056015002U;
            aOrbiterH = RotL64((aOrbiterH * 195034681254956335U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4910512055808124967U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4783477997418403079U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 861977492146512865U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13842899106208709771U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7930112618036681468U;
            aOrbiterK = RotL64((aOrbiterK * 8609551859830858419U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8790107242863198659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6882768826643279144U;
            aOrbiterC = RotL64((aOrbiterC * 13745521454063360763U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12136498871759890015U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8120456314755584336U;
            aOrbiterG = RotL64((aOrbiterG * 1830725195528043575U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14425711740351183016U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15907406009196323049U;
            aOrbiterB = RotL64((aOrbiterB * 8599371693260686839U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4878521420367891861U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1184672056055028939U;
            aOrbiterJ = RotL64((aOrbiterJ * 5963961755367831967U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 10126736568567000180U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12615321415808640429U;
            aOrbiterI = RotL64((aOrbiterI * 11663715449073755137U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 24U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 42U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 10U)) + aOrbiterG);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererH, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_BaseBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4088U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 6245U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7946U)) & S_BLOCK1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7298U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7128U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 1610U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 12U)) + 1142447269198373880U;
            aOrbiterD = (aWandererI + RotL64(aCross, 21U)) + 10581460640040336191U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 14703062773878202900U) + aPhaseGOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15737525756286914746U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 16178774478273186999U) + aPhaseGOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2514897053906809160U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13702496607592508464U;
            aOrbiterB = RotL64((aOrbiterB * 16540143680974064057U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 18030885275418337965U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5241783876161655984U;
            aOrbiterD = RotL64((aOrbiterD * 10970981186787227937U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2807052676283587925U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8022804576763271327U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11727096043219370577U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15597099852232205860U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1538435607932096400U;
            aOrbiterG = RotL64((aOrbiterG * 7900752511710516981U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11147868774413615365U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9325213746830411568U;
            aOrbiterI = RotL64((aOrbiterI * 561819005818948769U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 60U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11131U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 8200U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 13258U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14682U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13598U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 15417U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 20U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 19U)) + 18255347001097480328U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 52U)) + RotL64(aCarry, 5U)) + 13679246790311505735U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 10565839529765027116U) + aPhaseGOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 14327172566224769901U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 5U)) + 16239024612038195174U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13800012174212131890U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13900288860157577583U;
            aOrbiterE = RotL64((aOrbiterE * 13177682776510523095U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4144386119777112740U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3154558262670631372U;
            aOrbiterJ = RotL64((aOrbiterJ * 13236911910092437063U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7456728543137614001U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11709519851158935384U;
            aOrbiterC = RotL64((aOrbiterC * 7016689518570071587U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15607438907832240304U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9276575329661725624U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8879744070762412745U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6459435969129449226U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6442382118416542275U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2921027306686588233U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 50U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18817U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 18518U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23817U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18423U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18132U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23398U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 12222235191147985484U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 16367317014523328414U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 38U)) + 3511378091284703789U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 15247492830966725949U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + 7745995913390407897U) + aPhaseGOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6463593307540108810U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1101669311005268630U;
            aOrbiterK = RotL64((aOrbiterK * 10550146460887359369U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12988052764067518580U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17717179747434679772U;
            aOrbiterD = RotL64((aOrbiterD * 10820310705487638793U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11662190906682400416U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6563014073547628748U;
            aOrbiterI = RotL64((aOrbiterI * 16967910471722117761U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13099094932059419219U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 16342730862261868847U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10988124108686164829U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16855346813127524624U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6570063128502306944U;
            aOrbiterE = RotL64((aOrbiterE * 4571570049463124831U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 36U) + aOrbiterI) + RotL64(aOrbiterK, 28U)) + aPhaseGWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31407U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 24780U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27532U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27832U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32195U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25601U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererA + RotL64(aScatter, 39U)) + 13880995121909552664U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 56U)) + 14534942818069300546U) + aPhaseGOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 17745973100886007133U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 2249805580771946872U;
            aOrbiterG = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 4460116116396439410U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3378683994078106878U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3992996501048809123U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273544260537223797U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12057768808864451929U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4115362079047921130U;
            aOrbiterG = RotL64((aOrbiterG * 12263015903331031345U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15297384955502206698U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17623548383481905636U;
            aOrbiterE = RotL64((aOrbiterE * 7487278217901483685U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3559213898000162417U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12311605719074507335U;
            aOrbiterB = RotL64((aOrbiterB * 3982199462062847697U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14807313864347885885U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11222085523291581822U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12580941911587215653U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterG, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + ((((RotL64(aCross, 48U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB) + aPhaseGWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
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

void TwistExpander_BaseBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4307U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 962U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 3761U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6186U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7192U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 5105U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 3612110001869385068U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 11U)) + 16340824141280225936U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 15222338965130765231U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 6649270508107155041U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 21U)) + 768217258655426384U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4481855259658861851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18318041934562434016U;
            aOrbiterG = RotL64((aOrbiterG * 14913761339765234979U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4212457153804401807U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16143621095636987628U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6576072860505961427U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2095664232866642086U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4339527736737366572U;
            aOrbiterI = RotL64((aOrbiterI * 17503569508822244125U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13679353177869884790U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11582168502846418236U;
            aOrbiterE = RotL64((aOrbiterE * 135539430034462861U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10451330452898542191U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12951448817640617841U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4141870904192742091U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 26U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 40U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15938U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 8378U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 11479U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12606U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9741U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15697U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 29U)) + 1393781663398437180U) + aPhaseHOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 3U)) + 17414594746688585273U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 2823888497053071250U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 23U)) + 17032631958617884859U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 37U)) + 15222697630461125019U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15737414920751551780U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1357196111055783001U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8225423829221938165U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5315122321649251691U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7893744655508595974U;
            aOrbiterI = RotL64((aOrbiterI * 17863000246694319149U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16721939414324611738U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3444375866323610848U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10874157227815775661U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1825716513674511632U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15582066843912467318U;
            aOrbiterJ = RotL64((aOrbiterJ * 12765146555943757373U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15673590949193923915U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13887365046280406413U;
            aOrbiterE = RotL64((aOrbiterE * 3169061375011420121U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + aPhaseHWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 46U)) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23217U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 22764U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 21535U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17379U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20070U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 23136U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 29U)) + 11521331427196538632U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 5U)) + 16653824187682957632U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 11654676587350088289U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 8010313317412193584U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 1108775560502907471U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 243952321439823521U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2324945800401240403U;
            aOrbiterA = RotL64((aOrbiterA * 9471328582043504473U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9257554497543369657U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16701314607244592540U;
            aOrbiterG = RotL64((aOrbiterG * 8790054741039817107U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3900445848034341782U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7652316487347103658U;
            aOrbiterD = RotL64((aOrbiterD * 11480123491361589799U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 14980368605272070578U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2001165460948764796U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8110980921827107649U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1911044015666991050U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11366207111147818339U;
            aOrbiterF = RotL64((aOrbiterF * 17234439040652553865U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 14U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 52U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25575U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 31487U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27860U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27967U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27569U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 26756U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aIngress, 14U)) + RotL64(aCarry, 51U)) + 3561491146322798260U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 7075025056181885339U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 51U)) + 9230910887904171613U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 35U)) + 4119781172609908917U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 17155609083870983149U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2423018561430181695U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12957280305617615744U;
            aOrbiterH = RotL64((aOrbiterH * 17696410107705645631U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2461704174772065813U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7907123257849391997U;
            aOrbiterF = RotL64((aOrbiterF * 9416171962847312179U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7257868138318960007U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16425903703085702285U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7996935869077231999U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2990822664594079467U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5654819006718953817U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4465096036756887801U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12183676471235678779U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15026286960542123922U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17199049329995315279U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 23U)) + aOrbiterF) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
