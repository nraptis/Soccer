#include "TwistExpander_VolleyBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_VolleyBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9D0D6333A7357675ULL + 0xF28799AB60C9D1CBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDB3EDE1B4AED60A7ULL + 0xF0633003DA3BB958ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD65F800476F407D9ULL + 0xB5E76E7E736C0B84ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC858B4F1B64D5F89ULL + 0xA57C0DF3C51C5F03ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x992FA008990524E1ULL + 0xA6D6173E6E8B7F6BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC39C44BA788385ABULL + 0xDF6DCB4756D31A0FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8370C5B16A1B78F1ULL + 0x978A96CC26BF23F4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9A39CBAC24CB1F89ULL + 0xE89157EB68447537ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB371E8E3C39A30EFULL + 0xE7A942C190D156D7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8FA53676F51D54EBULL + 0x9109AAE04D60BA17ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9C9C0AD5D292EFD1ULL + 0xEA2851140EA76C7CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFF2BF9D47A15C1D1ULL + 0xA61C2538EA8BAA5DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8E9E94C7E9F2C257ULL + 0xF1755C6CD05838B9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD6C698F720ECE3C5ULL + 0xC53432FCCF95DB01ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9671A35D84A4B099ULL + 0xBD0E50D1D901B29BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE225199CE634B48BULL + 0x95CCC2F1B5D5AC1CULL);
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
            aIngress = RotL64(mSource[((aIndex + 3849U)) & S_BLOCK1], 34U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3642U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1624U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1108U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 43U)) + (RotL64(aCross, 13U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 39U)) + 1210605127156905516U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 11964595428173569519U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 12U)) + 16277319029916258482U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 27U)) + 12369497463101824572U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 6201248574067068202U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 1727477025667206661U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 43U)) + 1404510627789806851U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 47U)) + 6948213591282018925U) + aNonceWordG;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 6688865181284421478U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aCross, 4U)) + 3351130769402360855U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererE + RotL64(aIngress, 37U)) + 12681032488906270823U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3591412591193726763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16153817571210878589U;
            aOrbiterH = RotL64((aOrbiterH * 4165137036092246349U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3808228354421006630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1427373776207504205U;
            aOrbiterD = RotL64((aOrbiterD * 4534374093769595531U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1831554180932501132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2080935638828366835U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16104777999646489828U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15205199362011777473U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9782806013673440791U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3721620299829386454U;
            aOrbiterC = RotL64((aOrbiterC * 6286765834910272409U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 4013706412064296527U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 5751022780695158579U;
            aOrbiterI = RotL64((aOrbiterI * 13766736471646116397U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17684546333240329338U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1106947111128020920U;
            aOrbiterK = RotL64((aOrbiterK * 3158839453318658951U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11564229705849500598U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1585817314460274286U;
            aOrbiterB = RotL64((aOrbiterB * 12687162159791577431U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 13549147977354138518U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5148731385622182707U;
            aOrbiterG = RotL64((aOrbiterG * 11016443961557395981U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17048442399822433365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13772472534194030098U;
            aOrbiterJ = RotL64((aOrbiterJ * 13155895389652826889U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9982971300679888388U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1210605127156905516U;
            aOrbiterA = RotL64((aOrbiterA * 9183351854400012949U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aNonceWordP);
            aWandererI = aWandererI + (((((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 50U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordM) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 47U)) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 18U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 12U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7316U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8806U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9221U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 8141U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 53U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 11U)) + 14214886793361825363U) + aNonceWordN;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 48U)) + 17267959031078766320U) + aNonceWordE;
            aOrbiterG = (aWandererK + RotL64(aCross, 13U)) + 16436067429484887644U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 27U)) + 9885951769332633820U) + aOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 12971711341813893304U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 41U)) + 199970353398450154U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 37U)) + 1237341696444162094U) + aNonceWordF;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 7991128854417613360U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 43U)) + 14809029847149045833U;
            aOrbiterB = (aWandererG + RotL64(aCross, 39U)) + 2559509556915775947U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 56U)) + 14336829730147834160U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8853631886733610440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13346159398673246914U;
            aOrbiterG = RotL64((aOrbiterG * 13660497151446983393U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12121095718571872976U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 16239781125815589804U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 5157009090454962231U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9051377033794324106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13805815136723461780U;
            aOrbiterE = RotL64((aOrbiterE * 571129481747181357U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14849157800322754413U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18116651528452542634U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4105057226952948599U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 5911714320560994391U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1796514171654961389U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4439149331729987587U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10278532228230163632U;
            aOrbiterA = RotL64((aOrbiterA * 17428224919864716517U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2342456582668741750U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2360578572554664800U;
            aOrbiterK = RotL64((aOrbiterK * 1108428466956691925U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12132934875391401246U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17213278726790245812U;
            aOrbiterH = RotL64((aOrbiterH * 11904899990681410419U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 7994340481560109811U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13735851271080138255U;
            aOrbiterC = RotL64((aOrbiterC * 12387076892129731557U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6682417543888875268U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15642799286975840550U;
            aOrbiterF = RotL64((aOrbiterF * 7861250716882028053U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9839299346094784067U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14214886793361825363U;
            aOrbiterD = RotL64((aOrbiterD * 2103132743364916037U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterA, 6U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterB, 51U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterK, 39U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterB, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterG, 56U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11905U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 11968U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 13676U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14563U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 47U)) + (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (((aWandererG + RotL64(aCross, 24U)) + RotL64(aCarry, 39U)) + 11274974230580265396U) + aNonceWordN;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 29U)) + 16658438747342741547U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + 16612986966106053844U) + aNonceWordA;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 51U)) + 9329502236843231290U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 35U)) + 14088261356708344656U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 54U)) + RotL64(aCarry, 13U)) + 13692608802007789581U) + aOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 39U)) + 6824473946645682398U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 27U)) + 2072915876348570040U;
            aOrbiterC = (aWandererI + RotL64(aCross, 3U)) + 7420507753044460759U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 47U)) + 4677557318688502593U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 47U)) + 15081678577055628459U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 7026792817486507482U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14871665922943969918U;
            aOrbiterB = RotL64((aOrbiterB * 694073180313083145U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6807734532159292872U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17882797335141303280U;
            aOrbiterH = RotL64((aOrbiterH * 15439872930381050291U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9233542707022629190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1205501586581350876U;
            aOrbiterG = RotL64((aOrbiterG * 2596053290311090589U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10878718669747466677U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8066049063548639241U;
            aOrbiterC = RotL64((aOrbiterC * 3031382633089381605U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 861295180226875235U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9134969787937288583U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6726642007159809594U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8061661744643240470U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 6703498926835391813U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13541412083111962884U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8617442758729315637U;
            aOrbiterE = RotL64((aOrbiterE * 15471862889276160953U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16884403561131293362U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 9490680911678221233U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 15988763830018001033U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10486145044311386738U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10200001044821063684U;
            aOrbiterD = RotL64((aOrbiterD * 16149790736141571017U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6997073594007878034U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13585783612009989767U;
            aOrbiterK = RotL64((aOrbiterK * 11425303157774550449U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3847846040256340653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11274974230580265396U;
            aOrbiterA = RotL64((aOrbiterA * 13970270689108369205U), 5U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 60U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 24U) + RotL64(aOrbiterF, 13U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 54U));
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 34U) + aOrbiterJ) + RotL64(aOrbiterH, 4U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 37U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16544U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19568U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17941U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 19999U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21833U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 26U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererE + RotL64(aPrevious, 13U)) + 6733949564325516029U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 7304098437143918796U;
            aOrbiterF = (aWandererC + RotL64(aCross, 48U)) + 3923949518391777800U;
            aOrbiterI = ((((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 14243591003388927124U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererA + RotL64(aScatter, 53U)) + 18329498724605410406U;
            aOrbiterK = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 13118172167747037249U) + aNonceWordH;
            aOrbiterB = (aWandererG + RotL64(aIngress, 11U)) + 5272025143849174212U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 21U)) + 16075917179214318424U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 27U)) + 15263590648674658399U) + aNonceWordG;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 57U)) + 13730046728289525921U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererH + RotL64(aScatter, 34U)) + 7703141464499623408U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1382279753822135359U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2973369221699098292U;
            aOrbiterF = RotL64((aOrbiterF * 7440242040663550631U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11578274119583013219U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3419411247737896674U;
            aOrbiterK = RotL64((aOrbiterK * 17814942652262802991U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2582783513078999303U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3959762790273529677U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 383974377372162751U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 465795011576934604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17880826624185821135U;
            aOrbiterG = RotL64((aOrbiterG * 4445949147592860913U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10819659185349413173U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17298208553586835030U;
            aOrbiterB = RotL64((aOrbiterB * 1965860510614222093U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12585880006661489402U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16650193903267408586U;
            aOrbiterI = RotL64((aOrbiterI * 5781132589396936615U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 885882046325991589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 869560078374809974U;
            aOrbiterE = RotL64((aOrbiterE * 13440973563438747181U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11871305571797951851U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12137095015607196226U;
            aOrbiterA = RotL64((aOrbiterA * 7618152256560808581U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6044048326509186958U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 622564532811968856U;
            aOrbiterJ = RotL64((aOrbiterJ * 14988345089359014037U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17133994029325040272U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8612895899003926829U;
            aOrbiterC = RotL64((aOrbiterC * 2128664397481732179U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2169081503433534750U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6733949564325516029U;
            aOrbiterD = RotL64((aOrbiterD * 10062179904046311601U), 39U);
            //
            aIngress = RotL64(aOrbiterC, 44U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 10U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 40U)) + aOrbiterA) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 58U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aCross, 38U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22626U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 25481U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23010U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 27277U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26575U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26908U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 37U)) + 15036852811491820366U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 3U)) + 305637140752898475U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 11948631574496129610U) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aCross, 29U)) + 5321623592482991426U) + aNonceWordB;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 4075270159062690728U;
            aOrbiterG = (aWandererF + RotL64(aCross, 42U)) + 15111580500356908928U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 19U)) + 7244150695504160363U;
            aOrbiterB = ((((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 5131563519577488862U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 5U)) + 5881954992088651371U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 57U)) + 12780935808751507998U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 10U)) + 12599159643925470226U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9466589929741834066U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6093158735705189789U;
            aOrbiterD = RotL64((aOrbiterD * 7453778295800853653U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17461243886150519249U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15456408913739900718U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11260643903290392780U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7870342756041882616U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 2431528656086173419U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 134484990005888936U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10626896209992890407U;
            aOrbiterF = RotL64((aOrbiterF * 12034131076645285597U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14031164129515132292U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1771835705730244212U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16395472745067254664U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1455944290845294254U;
            aOrbiterK = RotL64((aOrbiterK * 6757824754363319079U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17866422769075350837U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10226884082632410805U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 206035536985843815U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14474587247775371703U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8501763445324525303U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 5298694643596784007U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 222650368553738561U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3901452368735982094U;
            aOrbiterJ = RotL64((aOrbiterJ * 18347115513126660483U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3063093906728331146U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9026710562384443411U;
            aOrbiterB = RotL64((aOrbiterB * 8411243802199203035U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11282041925238364080U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15036852811491820366U;
            aOrbiterE = RotL64((aOrbiterE * 18185121326941087841U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterC, 30U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + aNonceWordN);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterC, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31431U)) & S_BLOCK1], 39U) ^ RotL64(pSnow[((aIndex + 29734U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27577U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27754U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28100U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30739U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererD + RotL64(aIngress, 13U)) + 10038936806177516123U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 11U)) + 1773168435195292638U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 10655711161526628072U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 53U)) + 14422295664639740437U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 5U)) + 4125228715513159576U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 28U)) + 3670449653158650845U) + aNonceWordC;
            aOrbiterE = ((aWandererC + RotL64(aCross, 41U)) + 17553727567180813057U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 43U)) + 5111401772713882743U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 43U)) + 7688573124662314413U) + aNonceWordJ;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 3U)) + 9438375825507814395U) + aNonceWordB;
            aOrbiterB = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 27U)) + 14177477039902118886U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16329942595859623928U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3990536794006836672U;
            aOrbiterD = RotL64((aOrbiterD * 579024714339065373U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5072881436583180756U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16789727877867289997U;
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17313956922306689438U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11530878396329822041U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 11356860047841383129U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3612616532321160196U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4172189825359187763U;
            aOrbiterF = RotL64((aOrbiterF * 12938945495299393177U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8677279703778052804U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1912172980909479362U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10053289257955474143U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1460085850227494500U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12116763868122868147U;
            aOrbiterH = RotL64((aOrbiterH * 6076945628020280957U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17571840610366424432U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15581362592611080868U;
            aOrbiterE = RotL64((aOrbiterE * 1129054058044872003U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14434700039977611666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4534294602623329152U;
            aOrbiterC = RotL64((aOrbiterC * 5860911553425182045U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 865998255725903702U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16407778704555344108U;
            aOrbiterB = RotL64((aOrbiterB * 15571344643129797977U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1948990288894429805U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 18218556219056835250U;
            aOrbiterK = RotL64((aOrbiterK * 16574160087642377293U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1309229265173143398U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10038936806177516123U;
            aOrbiterJ = RotL64((aOrbiterJ * 12954594462760207923U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aNonceWordI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 14U)) + aOrbiterJ) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterC, 3U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 5U)) + aNonceWordE) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF8DA39EB0EC76103ULL + 0xC79F495361DC3C21ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8D5FFD4BC01DC4CFULL + 0xFC785E7E18F468C5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAF93D044DEE0262DULL + 0xEB69C5A2F3E3BF84ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCA9CA3433024AE09ULL + 0xE6239C554ADCFC84ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAED0CB3192A88225ULL + 0xB1555DC7610F1285ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB9CFAD0284D29FE5ULL + 0xFF60E1551C971AE4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9F7EFACBAF7A12ADULL + 0xBECCB65E692CAE69ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD2045BEA06A88427ULL + 0xE5636548C013834CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA536BF455CC83D01ULL + 0xCFE238920E1C9930ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDCFC2CBBC0038F1DULL + 0x8D59C86FDCF17106ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x843C42915F925911ULL + 0xBDC19A8F543E0D0BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBA15B503C5031FC3ULL + 0xC124B50B3D1B134BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF41494F4A187D3AFULL + 0xDCAC7F0D006C27ABULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9DA3EC1433C46DADULL + 0xAC52CBABF203BA68ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC12EBB0B8F610E1DULL + 0xA951E2CEC456724CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x81DE27E3F3FC67F3ULL + 0xC3DAF0E5DEC30919ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 880U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7719U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 2344U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1685U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 20U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 47U)) + 12775735908960052604U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 5U)) + 11791373812080296887U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 5537362877706057303U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 18U)) + 2023912048504189380U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 17668828109963766893U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 43U)) + 558908629933941224U) + aNonceWordN;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 29U)) + 1479633119685446888U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 15460320397843364063U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 10U)) + 10059749397555469054U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9987633811929693924U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10087337844580228269U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4446204415503364254U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15106063243302192717U;
            aOrbiterG = RotL64((aOrbiterG * 13273756657334709803U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9430197906134676162U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterH = RotL64((aOrbiterH * 14247538885252664127U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10611580584157624739U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 3137391249289641509U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 5462682413239873181U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9327201928815412810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7890659377013147073U;
            aOrbiterI = RotL64((aOrbiterI * 13827717178378062047U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10675114832750356941U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8804440385852327267U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12871947817782057116U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11015991745792051390U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 17152451500505815031U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6320437975845673731U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 702457937087191287U;
            aOrbiterB = RotL64((aOrbiterB * 17491257114676739589U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16629064896250312921U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6054107387816339103U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 6983767878966747219U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 27U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterI, 52U));
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterD, 10U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11810U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 14532U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 11723U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14869U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 15020U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 4U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 37U)) + 3650233661228036955U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 11607036400067735729U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 41U)) + 3899614406903883035U) + aNonceWordD;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 5U)) + 8159156925629965143U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 7148903913967261270U) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aIngress, 29U)) + 9161665622287517848U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 57U)) + 2981535013474059469U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 23U)) + 15812469008200319549U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aIngress, 10U)) + RotL64(aCarry, 23U)) + 14687469489893270300U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6025209349511417063U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12964750392311112676U;
            aOrbiterB = RotL64((aOrbiterB * 12955480283032701843U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6572355895765394340U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3542300121890027981U;
            aOrbiterA = RotL64((aOrbiterA * 11201491178181273935U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6477175684045398359U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 1081388388827929314U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8752188637514143529U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13754328481584620771U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3684673342659575917U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 6139923312873039143U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6542045150319909445U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 5352102692424060388U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 7385758355501860261U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9110100774657340354U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2813273684436269057U;
            aOrbiterE = RotL64((aOrbiterE * 10468759062594022273U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5860425751137403755U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1598622981888978548U;
            aOrbiterH = RotL64((aOrbiterH * 651816500461718345U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14710305692377606725U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 16280545617802383463U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 12541767206978802063U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6849565243667718750U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12152381961996750050U;
            aOrbiterG = RotL64((aOrbiterG * 11185935780063403807U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 52U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aNonceWordA);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterE, 60U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            aWandererK = aWandererK + ((((RotL64(aCross, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 14U) + aOrbiterA) + RotL64(aOrbiterB, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23493U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneD[((aIndex + 20384U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17252U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22494U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21583U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 22932U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 12U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 39U)) + 77518479758428414U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + 4832061802166300011U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 18U)) + 11695291171006574112U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 7467412817843260094U) + aNonceWordG;
            aOrbiterE = ((aWandererA + RotL64(aCross, 29U)) + 17801484124471154757U) + aNonceWordD;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 5555455638503958639U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 23U)) + 5669470540733721606U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererD + RotL64(aIngress, 43U)) + 3042388456327784163U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 51U)) + 2236734925228156691U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14459720401528685450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4814967631216658856U;
            aOrbiterD = RotL64((aOrbiterD * 18288097536171386643U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16950679344449075945U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6262238639302011050U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 9942659897425088183U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3522256359074996724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12524717897707074242U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13891759914865623828U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12311343917878428995U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2240189915640314069U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5365912986308810837U;
            aOrbiterB = RotL64((aOrbiterB * 15133972552032469957U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9323732721344489753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterJ = RotL64((aOrbiterJ * 14659491687401151733U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16398238057564892809U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 11517870519285159224U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1501848878469712681U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7758285512254776734U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17475149091906684720U;
            aOrbiterK = RotL64((aOrbiterK * 6015816725428299273U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2051631493975035243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11684740065349595315U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 10918975496337269197U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterG, 23U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 28U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterB, 19U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28479U)) & S_BLOCK1], 40U) ^ RotL64(aFireLaneC[((aIndex + 29670U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28504U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29426U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31444U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 31050U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = (aWandererJ + RotL64(aIngress, 51U)) + 7948891781097675369U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 57U)) + 13928362874228230226U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererA + RotL64(aScatter, 34U)) + 10776180542602258926U;
            aOrbiterD = (aWandererE + RotL64(aCross, 5U)) + 5735115172149470447U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 5353591822981766987U) + aNonceWordB;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 19U)) + 562301708107268570U) + aNonceWordF;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 10467810247578364868U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 39U)) + 14541630141152308564U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 47U)) + 2350076897065139429U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17519109078651162228U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6061035173339902910U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 10021905773432907835U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15654836633731000065U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13723521735153718904U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2849680038315532197U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterI = RotL64((aOrbiterI * 10984689101753586739U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7671010488872356142U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11485114338165600777U;
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8759060657343458985U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11009137869375286581U;
            aOrbiterE = RotL64((aOrbiterE * 8741417343929809115U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15792999392743144135U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6180808423175992479U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 361487389591183005U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15292753806514404853U;
            aOrbiterD = RotL64((aOrbiterD * 17478232597253311153U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14929153438443362045U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7904556383593914086U;
            aOrbiterB = RotL64((aOrbiterB * 2484130486635511403U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3793180909904286848U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10391957637467171320U;
            aOrbiterK = RotL64((aOrbiterK * 505484041943467117U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 60U)) + aOrbiterK) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 42U) + aOrbiterC) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterJ) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD4A76E96C8E54DAFULL + 0x98BC565805BE3CE6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD727D481A8AC55A1ULL + 0xF4CE4988A3F59CDDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9263ED4715DDDD0FULL + 0xAA5DF493429820CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCC30181AB25E161BULL + 0xDA369C3FEB7F37BFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD3DA161806E4519BULL + 0xD80D3FCBB0155651ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x98A00DE9D30CE96FULL + 0xCA874E13AE365017ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFA02B0017D396BADULL + 0xD396BDF8652E7F93ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE76F44F8E6898B3BULL + 0x8DC07FCADDEBE042ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBDFAFC95273046C3ULL + 0xDC2B5FB5BD0D2477ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE1BD967AC137B585ULL + 0xB6CB7917789D64BEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8B584BA01C271C7DULL + 0x99E91D8FA87061A6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8ECF88074F8783BDULL + 0xA51AAB0E973CC433ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC7891C683A23AADULL + 0xDE8AADF7A1A96164ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEB0332818E1D2EBFULL + 0xF97977234297FB30ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD673CE2B45B18109ULL + 0xBE98E2C8538D2372ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x81EB1D6A80DBE2DFULL + 0xF6D674C9F61C1FFEULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2369U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 4947U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2014U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4793U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 5791U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 12U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 17668251151213543491U) + aOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 60U)) + 16101602509895104517U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 5U)) + 9083915270773304935U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 12810720730318214811U) + aNonceWordC;
            aOrbiterD = ((((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 18113428002071925621U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1582208899354109878U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4180688104819188154U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3391785441902730815U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8954598189262820611U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15360094153175355879U;
            aOrbiterK = RotL64((aOrbiterK * 8177798855402983685U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8383954114668216260U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 15626783326234049197U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 15058420415480073793U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 10609978564404958066U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17656516608997517984U;
            aOrbiterD = RotL64((aOrbiterD * 4590620354119899777U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 760077259110786536U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3597338735888033063U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6548831472863517621U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 44U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterD, 50U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterB, 39U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 11U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13016U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 13621U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 14792U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11626U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14539U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13990U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 52U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 13278949403988203974U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 47U)) + 9213599924054673756U) + aNonceWordK;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 1255746482932381798U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((((aWandererA + RotL64(aIngress, 4U)) + RotL64(aCarry, 3U)) + 11575321997144516122U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 15881587525529432437U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 9846195809864862707U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12319815691858217670U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 14271546305640811091U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 16322617427294439587U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16332130810525887437U;
            aOrbiterH = RotL64((aOrbiterH * 7588076439690559343U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4920951156015336794U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16767126455124552329U;
            aOrbiterF = RotL64((aOrbiterF * 4440352337076842603U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12553595911087945223U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1437522202135436142U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 2001992794165550905U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12313100454852227143U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3874839760378039509U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 30U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23263U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((aIndex + 23490U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20802U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19062U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16487U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17119U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 38U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 57U)) + 3621877681473089725U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererF + RotL64(aCross, 5U)) + 4451752751536414717U) + aNonceWordG;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 11371625415377772117U) + aOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 47U)) + 6046792758881150619U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 8213166120394461682U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4343156661140422645U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11105271483234947905U;
            aOrbiterH = RotL64((aOrbiterH * 853531080115819287U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 348904609985341372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12924652822526858767U;
            aOrbiterA = RotL64((aOrbiterA * 2801892489296408735U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7461211697358520287U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16551553555297890558U;
            aOrbiterI = RotL64((aOrbiterI * 16432952324635746293U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11908056404140782995U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9147367258259948715U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 8876461054692728610U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 10546855952702525404U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10071104785895309677U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 56U) + aOrbiterH) + RotL64(aOrbiterK, 5U)) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 52U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26435U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 25725U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 32486U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30027U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32584U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30182U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30882U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 44U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererE + RotL64(aCross, 51U)) + 12380376990224645149U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 51U)) + 18296928500297384014U) + aNonceWordL;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 3550626816361145100U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 2667792936946706027U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 13U)) + 12020969779370926953U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 737340727886903447U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1681797651799760502U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11923920414802777451U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2956186342689489064U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1876852870402977177U;
            aOrbiterH = RotL64((aOrbiterH * 8875540081346621757U), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 6433205819353555071U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9065076854974222998U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 5459675878087242021U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3254410578766789992U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2005081975473815576U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15992999234834560419U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3458344156815120948U;
            aOrbiterI = RotL64((aOrbiterI * 1668460113964608051U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 52U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 44U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_VolleyBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBC7239BBDB0FAE47ULL + 0x9A8F490E5631E3C1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF26CBB078CB7F1E3ULL + 0xE9C251C4FD50331DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA27CB39A5A62A5B1ULL + 0xA06023263300ECD6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA42E14858D420881ULL + 0xD12E037D3A08BFA5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB3BD9962D7045E93ULL + 0x8B895EAACBF7C15EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC6CA240882791F21ULL + 0xB40BA54BDC02BB12ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x95C43C49218D7387ULL + 0x9FFC04C5D168C1BFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBDF02556F6EE5029ULL + 0x8704DF57A22B65FAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE9C89BCA54C84523ULL + 0xA078DFFF8EC388F5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB5C6F191DAC9588DULL + 0x878741B8B7EED56CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x90D08B361296D05BULL + 0x8B4B7A4F11CC594BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE71B9097A8D389A3ULL + 0x9DD8CFFA4DADCD65ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x98805057DDD86B8DULL + 0xE613577997FCCC12ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAB5006F7900EA35DULL + 0xE8DCD8B8FCB670B9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE91893D77DA9A7A3ULL + 0xDA15F0B647D44AADULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE0372FAA54B7B427ULL + 0xF9843D81AF818E3EULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aFireLaneD, aOperationLaneB, aWorkLaneB, aOperationLaneD, aOperationLaneA, aWorkLaneC, aOperationLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 765U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 4513U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4535U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3029U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2358U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 874U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 4U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 15188686795415908074U) + aNonceWordK;
            aOrbiterG = (aWandererH + RotL64(aCross, 27U)) + 17310049041983079779U;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 8246925977992441471U) + aNonceWordA;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 42U)) + 8644260919918112781U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 13401663736874819483U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + 7940358935238314973U) + aNonceWordO;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 11U)) + 13278990328548007839U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 11346868298353840706U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2374077904806833579U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1765686942154321425U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6978903378645019166U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 11951633297870965212U;
            aOrbiterH = RotL64((aOrbiterH * 12778236598654492185U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17398460995357409673U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1215437945597836770U;
            aOrbiterJ = RotL64((aOrbiterJ * 9322970054123481621U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1878751468043972239U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5343002808239712390U;
            aOrbiterC = RotL64((aOrbiterC * 11878640995447558811U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9884918450053276861U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15894599082080422550U;
            aOrbiterE = RotL64((aOrbiterE * 8359936745539546131U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13917339232771145459U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 18101134009493720683U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15835859435306756387U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 3830086372356903769U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15894394599564584010U;
            aOrbiterK = RotL64((aOrbiterK * 9513921913446609263U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 28U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 58U)) + aOrbiterF) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 36U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13083U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 15800U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 11334U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9420U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9831U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12449U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (((aWandererC + RotL64(aIngress, 51U)) + 12692813903177772178U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 7112496446691277899U) + aNonceWordE;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 29U)) + 2112247138290568813U;
            aOrbiterK = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 3699421080882855947U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 21U)) + 13761832028354380922U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 9243822514887600214U;
            aOrbiterE = (aWandererE + RotL64(aCross, 39U)) + 6863833516853046129U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8863897995943098018U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 13346785686701467520U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 18074843497158380703U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15309543066305531619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17515530938817919111U;
            aOrbiterG = RotL64((aOrbiterG * 16625193986319048245U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 760493237816424254U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7282586354117620860U;
            aOrbiterE = RotL64((aOrbiterE * 2327153408185290635U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4129706068526969105U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7020175432730888755U;
            aOrbiterH = RotL64((aOrbiterH * 10095158356907592239U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9102258982216515596U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10822031305361453690U;
            aOrbiterK = RotL64((aOrbiterK * 2036205056490578491U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12571477440964330246U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8436347026653095199U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17930734781213681573U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14214789872073941940U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12915911919403385001U;
            aOrbiterB = RotL64((aOrbiterB * 13161681603528031511U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 56U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterF) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18321U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 24250U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20807U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20602U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18741U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 24478U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 11U)) + 7896237440058555694U) + aNonceWordP;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 19U)) + 11870529476037558635U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 41U)) + 9158983227801569448U) + aNonceWordD;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 41U)) + 4710172270996950329U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 14634482800356647630U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 8822207952170610891U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 27U)) + 13755891414028982553U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4555293067488040719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2816805148093762081U;
            aOrbiterD = RotL64((aOrbiterD * 16838149138341713943U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2122631477965135190U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4592922416380416071U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 11644507904538573165U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7102471666524164715U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17274623547879474204U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5443572270546181789U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 938587316977094680U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18258015823797023523U;
            aOrbiterG = RotL64((aOrbiterG * 6068819567674605919U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5809987756043471595U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5083075160112581620U;
            aOrbiterJ = RotL64((aOrbiterJ * 3313957222154937503U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5960021727750946496U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5967477320950630150U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 330964768256424655U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6578428711689296132U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 5601728218197771276U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 9552559022315971847U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aNonceWordG);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterB, 29U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 44U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31780U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 32134U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26261U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24642U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32558U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25972U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 6U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 34U)) + 15726877954695761686U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 14187652171881943587U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 8420423151313882782U) + aNonceWordI;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 14942322692433259283U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 23U)) + 7272331475919796255U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 3U)) + 154504365041805840U) + aNonceWordC;
            aOrbiterD = (aWandererD + RotL64(aCross, 13U)) + 17475491222554948786U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5759181483165339605U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5993060214499322845U;
            aOrbiterB = RotL64((aOrbiterB * 10799489831896153301U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10901786237875941844U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17135786595614068473U;
            aOrbiterC = RotL64((aOrbiterC * 15923538730142047043U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5208202073886811165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6821452921018900631U;
            aOrbiterE = RotL64((aOrbiterE * 13119330055184115669U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13348064837402206969U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8967943922403445136U;
            aOrbiterK = RotL64((aOrbiterK * 300168481725373093U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 8130283784171430891U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6351113882502502876U;
            aOrbiterF = RotL64((aOrbiterF * 15960622823993072903U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6894708729226455769U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12065058511247133944U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17138279326229372741U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 12987698199066890628U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12665716655177320977U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 58U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterE, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterD, 19U)) + aNonceWordG);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterC, 41U)) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA2EEFC9ED9B3EABBULL + 0xA6EA4CCD192D9412ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF8CB665ADC821015ULL + 0xEB15297A8B9A2E4EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE4A7CA3CE2FA3561ULL + 0x860F7AA32F088EBDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x98CE9E0B97E90549ULL + 0xE6CD9A1509C02E43ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC3BD6EC0C0273BC3ULL + 0xB5FDF364CE37CB17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC4654B6356777DD3ULL + 0xF9AF5FAE75F944B4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB8AB4F931DE05EE7ULL + 0xFC423DCECF825F56ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE7926D51B07C4F2DULL + 0xB4677B9E694B5197ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC226011167FE5069ULL + 0xF0CE8348041C9870ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x909194F1ECB24311ULL + 0x950D727A466F03C9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA63DFA98C6EEA06FULL + 0xE4475827C4002061ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x92B1AA5E326E5EE9ULL + 0xFEB94B20DCE862B1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9B693A3E20B9579BULL + 0xD453F9F794A425E7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD99FD0F47BB9AE89ULL + 0x97CAFE0CB4C03E66ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x81E021117EC11257ULL + 0xB6891A5321E0C40EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x97C4968D9DEAC9D7ULL + 0xA7346EC741D74F8BULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneC, aFireLaneC, aExpandLaneB, aOperationLaneB, aOperationLaneA, aExpandLaneC, aFireLaneB, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5349U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 1678U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1593U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5382U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5142U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4972U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 6467297102954816305U) + aNonceWordM;
            aOrbiterH = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 7921154109831114952U) + aNonceWordC;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 3U)) + 5701131763215638919U) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 35U)) + 10022999076719002684U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 41U)) + 4367135243038982316U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 37U)) + 14445846824810383592U;
            aOrbiterD = (aWandererG + RotL64(aCross, 13U)) + 7683697954545773253U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17517006750428030899U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2052484792684025476U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12463117571122469643U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6279463052085808926U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 679280153651813684U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3047031560593583881U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2939516520188460569U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1960616434964712325U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 15145998415466343039U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12273819390719947361U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5685033154709449397U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9845666295874714959U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9314494172199500653U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15757631834636427621U;
            aOrbiterF = RotL64((aOrbiterF * 15483543888965744529U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10878078046389399574U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3583495913766365232U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2913540984990155225U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7385544065754622301U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16839599460207922881U;
            aOrbiterD = RotL64((aOrbiterD * 240651605910592561U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 56U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16228U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 9214U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 10637U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10386U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15943U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 16346U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 20U)) + 13960289014350612206U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 3483331015269589730U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 5U)) + 6873299241002444518U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 3562094007125534229U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 11422367439932782705U) + aNonceWordE;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 13U)) + 532453428514259816U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + 17810941465810193088U) + aNonceWordA;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11869759058631106331U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8837581071876177566U;
            aOrbiterA = RotL64((aOrbiterA * 15329827515970522213U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17185378327053837778U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7578253375676981500U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13371647568758721729U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17112646434432814442U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14949096407295697881U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 14770977858283051753U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4259590620758467836U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6534899413644542303U;
            aOrbiterE = RotL64((aOrbiterE * 7987609419215568661U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2637407498893694243U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 15819295597921425711U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5202015597375051399U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6373559542002699718U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11694562937392022505U;
            aOrbiterJ = RotL64((aOrbiterJ * 9311557972331218597U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3308736483775453062U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12749929710650475901U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 248428400724560945U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterA, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterK, 43U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + aNonceWordL) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 22U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19011U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 24073U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 20593U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20076U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20788U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 23561U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 10U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 27U)) + 12849591986267890852U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 8232614804696815750U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 21U)) + 12141567259210877281U) + aNonceWordP;
            aOrbiterH = ((aWandererB + RotL64(aCross, 41U)) + 2928641981037885644U) + aNonceWordE;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 27U)) + 980733350554783938U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 2683985177993350746U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 14532148403815527355U) + aNonceWordM;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7736296629433884203U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10428437770166310549U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 326634742742373401U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18327174144859461029U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6810436935194432002U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12606153309690753435U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterH = RotL64((aOrbiterH * 13469111258504672565U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9057777759026189541U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16478485918911194442U;
            aOrbiterE = RotL64((aOrbiterE * 11054247078884894131U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 18064460487552100483U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11477276762421684083U;
            aOrbiterA = RotL64((aOrbiterA * 3886501230380184395U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 18318375441973295081U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13849305985380030986U;
            aOrbiterF = RotL64((aOrbiterF * 12962140243967824959U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10240409420338313641U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18360586077779529086U;
            aOrbiterG = RotL64((aOrbiterG * 18196875422391501927U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterA, 30U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + aNonceWordI);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererA, 58U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28994U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((aIndex + 24814U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 31535U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29910U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31748U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27402U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 1364174714924216027U) + aNonceWordI;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 57U)) + 13561796874229506613U) + aNonceWordP;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 29U)) + 11845572344206238305U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aCross, 50U)) + RotL64(aCarry, 39U)) + 15762708240326773763U) + aNonceWordA;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 37U)) + 1157119665207900473U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 23U)) + 6823546624372055260U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 14465564210523945121U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 10667464548080807531U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13445737493224316575U;
            aOrbiterH = RotL64((aOrbiterH * 12137295000900795711U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3009837893785957665U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2886920524111083752U;
            aOrbiterC = RotL64((aOrbiterC * 15308180928967762543U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10886177449328249656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15067759884678100433U;
            aOrbiterB = RotL64((aOrbiterB * 5724566815989860041U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 18307930462682331536U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8791864377579255801U;
            aOrbiterF = RotL64((aOrbiterF * 9265158882471421767U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 805797468642992351U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5743305867058244964U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17102025528234481273U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1841579177327486899U;
            aOrbiterA = RotL64((aOrbiterA * 3841603385577825265U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2189493507896508972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 47U)) + aOrbiterB) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterF, 30U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterI, 53U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + RotL64(aOrbiterB, 39U)) + aOrbiterG) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE77A7B0DC1B7FD0BULL + 0x896C467026E56299ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xECFE3E9091EE8041ULL + 0x9822DC754FE3D48BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBF060B69D6024C03ULL + 0x9C1C7609C0745B9BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC402B8066C6924A1ULL + 0xADBB40B49E75958BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9AFA89AE486C9D69ULL + 0xDE44A8AFA054D753ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB63EDCDC84B35EF7ULL + 0xD628EF9354098D4AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD95D39132C3168E3ULL + 0x855D46F15C4F7644ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD1AC6DB69597E7F7ULL + 0xA3D6D0B691E4AB8CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x837B76472DD68ED5ULL + 0xF9311C63A039C026ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB382AD458B578C07ULL + 0xBBF59C1DC7AF5B16ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF616178024EDAC19ULL + 0xFB0325C33A93647AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD30F82134CBE236BULL + 0xB8979E2D12B56D18ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8B48D2E1518767CDULL + 0xEE4AEF2B142264F3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAF7728F5D7AC4CFDULL + 0xEC7A910E57966C95ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x97B9826F193C7C93ULL + 0xFA630A67567E34EDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC648BDB10E93058BULL + 0xD6F97F1B617979D5ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aOperationLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneB, aFireLaneD, aWorkLaneB, aOperationLaneC, aFireLaneB, aFireLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2781U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 1215U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 6157U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3877U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2218U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4815U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 10U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererJ + RotL64(aCross, 11U)) + 2101601659597850213U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 43U)) + 2759794072560720121U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 41U)) + 9443562552411269339U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 29U)) + 10801360546699857975U) + aNonceWordN;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 8020716394829332019U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + 1021894212367773801U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 13U)) + 13346855534622490176U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 16359309548462953836U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 46U)) + 12642446944680783519U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 57U)) + 8197424982767553380U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 3U)) + 14346334610901859094U) + aNonceWordA;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14171304260534233539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 334531601308283605U;
            aOrbiterE = RotL64((aOrbiterE * 5012968232749075075U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10707856298471572695U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18364775750091914766U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 15735143943129143265U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8531394793118363836U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 475199047053777179U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 567682016232278157U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2068146551757663119U;
            aOrbiterB = RotL64((aOrbiterB * 1557877740957797555U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7776122587613256525U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 4540270493783593257U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11912000645055436094U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16800749242578741498U;
            aOrbiterC = RotL64((aOrbiterC * 17804584625034241737U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5909199180260499150U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5751089915336865588U;
            aOrbiterK = RotL64((aOrbiterK * 15376689503142397927U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3478216857728853008U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18007567146937338241U;
            aOrbiterH = RotL64((aOrbiterH * 6620498877303917855U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17454259424163653490U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6276120962018305311U;
            aOrbiterD = RotL64((aOrbiterD * 7560618224285018801U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3839336239901666431U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6230149015045237670U;
            aOrbiterG = RotL64((aOrbiterG * 1838983748994340883U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17552095486612766544U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2101601659597850213U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2915330118061857271U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 44U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterD, 19U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 46U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 4U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11763U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 15230U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15413U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11218U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12268U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8741U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 29U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererG + RotL64(aCross, 43U)) + 252059974543142812U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererA + RotL64(aScatter, 21U)) + 11690823093681457368U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 14U)) + 13282189752890971123U) + aNonceWordA;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 53U)) + 9507416294305708435U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + 14053038174390776539U) + aNonceWordF;
            aOrbiterG = (aWandererK + RotL64(aScatter, 51U)) + 14605253312318725009U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 18138286582677863671U) + aNonceWordB;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 8530091235978489988U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 60U)) + 14381731677571170073U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 41U)) + 13316413456378978456U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 3910529530149320706U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6302070286831566901U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12324134652758551396U;
            aOrbiterH = RotL64((aOrbiterH * 17136438281540250165U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4773478557638475048U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4031153435446078944U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3876928995240982769U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3114794895962903899U) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3552936509969106796U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16823186892738820299U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5828754613946145627U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17985241114076114558U;
            aOrbiterE = RotL64((aOrbiterE * 1986669631395606833U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11319331046368072261U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6104267020171882160U;
            aOrbiterI = RotL64((aOrbiterI * 12525117969211576177U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7662668379725735125U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6583034411403600735U;
            aOrbiterK = RotL64((aOrbiterK * 262095656452193889U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5569865728026310280U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 4176065898330374039U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 11305749530796963967U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13677146592276526676U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2734371113158117596U;
            aOrbiterD = RotL64((aOrbiterD * 13146444882662731975U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14890607377967461739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3110674898918355049U;
            aOrbiterC = RotL64((aOrbiterC * 9637837600671200315U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15329760212453783067U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 18214263442264013242U;
            aOrbiterJ = RotL64((aOrbiterJ * 9139354822936682953U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6727267537859989206U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 252059974543142812U;
            aOrbiterA = RotL64((aOrbiterA * 9559128226993261041U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 18U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterG) + aNonceWordG);
            aWandererD = aWandererD + (((((RotL64(aCross, 42U) + RotL64(aOrbiterH, 60U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA + ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17332U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 20457U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 21731U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23526U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19189U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22396U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 52U)) + 964165145848253292U) + aNonceWordL;
            aOrbiterC = ((aWandererC + RotL64(aCross, 43U)) + 10645976767204934746U) + aNonceWordJ;
            aOrbiterK = (aWandererA + RotL64(aIngress, 23U)) + 8241612229349212650U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 4159196033256913347U;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 7194795864620233507U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 29U)) + 7638928444536778384U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 11819105916503968109U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 27U)) + 18052213302858186237U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 18U)) + 8663575313970041570U) + aOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 16644136720439299786U;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 16930316530442679864U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16251107616988250593U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7171986193609401665U;
            aOrbiterK = RotL64((aOrbiterK * 3543709971414550087U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17885046834432626644U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7757069274715713557U;
            aOrbiterC = RotL64((aOrbiterC * 15766885299397923879U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 2212805322061155615U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6368539134638838822U;
            aOrbiterA = RotL64((aOrbiterA * 13383744883433594259U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5264326094252925613U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6126345334815012938U;
            aOrbiterF = RotL64((aOrbiterF * 17180934809764905307U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13826731214018407061U) + aNonceWordN;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6621261811613643620U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2823596473596114171U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5964406317285863781U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2167324450276308078U;
            aOrbiterI = RotL64((aOrbiterI * 1098346374733634905U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16740710162977859724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8236083581048717923U;
            aOrbiterJ = RotL64((aOrbiterJ * 4364887787000704039U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13967473987446124012U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5136051802217149813U;
            aOrbiterE = RotL64((aOrbiterE * 13997246005108872883U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5842999397215390366U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8621394946580065499U;
            aOrbiterB = RotL64((aOrbiterB * 11658023035736362355U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18086875424872976900U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7429246355923896047U;
            aOrbiterH = RotL64((aOrbiterH * 5077079237334961761U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18123753993386959014U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 964165145848253292U;
            aOrbiterD = RotL64((aOrbiterD * 3178072569980307307U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 28U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 14U)) + aOrbiterB) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aCross, 50U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 51U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 41U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererK, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneB
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25618U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 24793U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 24693U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28895U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32365U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 31202U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 41U)) + 2225397913940961213U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 51U)) + 8342544893601343643U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 41U)) + 162922186381417187U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 43U)) + 11660218373710972210U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 58U)) + 14909034764605802354U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 16776955237009701511U) + aNonceWordE;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 21U)) + 5834487809188925253U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 27U)) + 1498492772767040320U) + aNonceWordD;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 37U)) + 4161765458781579617U) + aNonceWordI;
            aOrbiterE = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 10511923076962447765U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 13U)) + 8575954471692620021U) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6536325446331340573U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1790628986900286346U;
            aOrbiterD = RotL64((aOrbiterD * 5262997114200816715U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2623814807619278590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11676970995834706612U;
            aOrbiterG = RotL64((aOrbiterG * 10057461115132434901U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13836786354224256591U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 6293096163612129260U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8977954126326217153U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4271144764978661248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15938494256992560202U;
            aOrbiterC = RotL64((aOrbiterC * 10004841288382726739U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11038155227307702976U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12408749795071243930U;
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1673665849053496882U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12866353361497103629U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 6041125499398924871U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10673935802381580966U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8946776538955520352U;
            aOrbiterH = RotL64((aOrbiterH * 12293084177712710021U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16294935203370452805U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 4697759331563852212U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14407806317275373043U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 17633118874112283386U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 89602424202721105U;
            aOrbiterF = RotL64((aOrbiterF * 1010654844008668685U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4019154066191316616U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15029609435149173243U;
            aOrbiterJ = RotL64((aOrbiterJ * 3522168783248806167U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11765990698273078458U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2225397913940961213U;
            aOrbiterA = RotL64((aOrbiterA * 8471538922288466221U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 60U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 24U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 4U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 37U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 54U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD60BECB490973D8DULL + 0xDEF631E6850DB07BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCBE5B4854C8B12DFULL + 0xE3F1B8CE9819E992ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9ACB1F6855830F37ULL + 0xC2FFF17F38000671ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6F3EA12B4180499ULL + 0xCB1DC6DC6C603804ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x887F5FC4E6F3C7B7ULL + 0x8FEA4A2A4DC299D5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9DC2218979FCE24DULL + 0xDD0F850515849858ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED25F17799626F81ULL + 0xF0E5C60F2FA0CD23ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF8C7EE70FAD09975ULL + 0x9AA6870E819B2417ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x8D51712D992DF7C5ULL + 0xA6A05A8814A28098ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA7B8B0E01DF2DC7DULL + 0xA1427D486CB80BC3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDF2D3D7DDC0FDD15ULL + 0xBF6143A1E2C45AEFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAEEF64BF1CD02D25ULL + 0xF2AE3FB32A2AE957ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC517370157182535ULL + 0xE12AB3B8293836D9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8842852F1E987641ULL + 0xF34440BC0B2F8969ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEDD977EFBBF60DD9ULL + 0x957977ECAB8CD027ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE1F8C07FAF4A323ULL + 0xE67D80ECCB908F33ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aFireLaneA, aWorkLaneB, aExpandLaneB, aWorkLaneC, aFireLaneB, aExpandLaneC, aFireLaneC, aWorkLaneA
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 861U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 178U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7341U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2486U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1967U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5832U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 46U)) + 15383045568644941552U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 17452811657750910067U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 35U)) + 15660117718455155603U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 19U)) + 10396441207743665753U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 50U)) + 3708971058200841442U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 7000673057768598750U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 41U)) + 9886354469011131596U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 16018065329058043467U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 5U)) + 5024756166109352320U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6587818720728886652U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3652672354944162319U;
            aOrbiterG = RotL64((aOrbiterG * 10807121230791716109U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6307315649915348048U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16405347331742979258U;
            aOrbiterH = RotL64((aOrbiterH * 7183142442906743699U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5427299664054601957U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 4983381733483185898U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10182995521328377487U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8694282877540593550U;
            aOrbiterA = RotL64((aOrbiterA * 14614602561910403893U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4085927978153269932U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6176195962815240877U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16792916528959579875U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 6966742100601433005U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9920952446921247521U;
            aOrbiterC = RotL64((aOrbiterC * 1879821050131820933U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11958734477518336014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2058335903640404380U;
            aOrbiterJ = RotL64((aOrbiterJ * 6986170159285417789U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 77366119537297816U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12072894199692855000U;
            aOrbiterF = RotL64((aOrbiterF * 9083781120514635987U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11874297832446385377U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13715562531763053196U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 12822488258322963187U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 6U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 12U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 37U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 58U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9853U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 8885U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11916U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11825U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9849U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 15171U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 58U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 9220392006207660113U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 23U)) + 11305018553489132882U) + aNonceWordN;
            aOrbiterA = (aWandererE + RotL64(aCross, 60U)) + 5860373868073513684U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 12319586170883987589U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 14072333614354649021U) + aNonceWordH;
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 9332158529453194608U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 39U)) + 3860569321145958686U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 27U)) + 8119005668901240093U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 18U)) + 13918259792880333239U) + aOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6938856216758228704U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 3960905839118710604U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16203746868670689793U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6043879193734253929U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15691425268831319195U;
            aOrbiterJ = RotL64((aOrbiterJ * 7189195135654636271U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14912209933584715274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16180183395910618923U;
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4966642362507707776U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6962226782462822861U;
            aOrbiterG = RotL64((aOrbiterG * 3647802407741095419U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12409120845092026295U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2302946450253872465U;
            aOrbiterC = RotL64((aOrbiterC * 7099576330777297911U), 21U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 16118304388937163838U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15968419034359049422U;
            aOrbiterB = RotL64((aOrbiterB * 11736207775827080165U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17098982091525008231U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10298979200690822062U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12620028874653521945U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 552826643694256437U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11786560990790695378U;
            aOrbiterD = RotL64((aOrbiterD * 11190309640069208311U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 13730399230389329793U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17614226859252305432U;
            aOrbiterI = RotL64((aOrbiterI * 2640019643570222977U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 38U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterC) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 38U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24058U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((aIndex + 22487U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23141U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18230U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23546U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16760U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 18U)) + RotL64(aCarry, 43U)) + 12535417189990029950U) + aNonceWordB;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + 6204401443676390273U) + aNonceWordI;
            aOrbiterI = (aWandererA + RotL64(aScatter, 29U)) + 869613505613154672U;
            aOrbiterK = (aWandererI + RotL64(aCross, 39U)) + 15053590879563855802U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 19U)) + 13338989605204591428U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + 18306470022403825392U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 1150696349434090218U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 13549541786420596437U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 13U)) + 14302878430259588461U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4660437084477165225U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1653628537860912069U;
            aOrbiterI = RotL64((aOrbiterI * 2624835201155303123U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5594199757006711631U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11008472193138708891U;
            aOrbiterE = RotL64((aOrbiterE * 13645764762027798301U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 3668516817279364310U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 128159531749679984U;
            aOrbiterB = RotL64((aOrbiterB * 4523246859249826987U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6378674346113979108U) + aNonceWordD;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11438762460659123362U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2733309638158283953U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10624263004446482910U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12546839706919241411U;
            aOrbiterC = RotL64((aOrbiterC * 11468326687628079347U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8466639576503293921U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5828694979857951504U;
            aOrbiterG = RotL64((aOrbiterG * 7835487310289634515U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 16496305151014092976U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 589464613876410567U;
            aOrbiterA = RotL64((aOrbiterA * 13190816610718051897U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4168532743415647825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15944887793736489375U;
            aOrbiterD = RotL64((aOrbiterD * 17273403561158196717U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11642456814106259483U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1609897693632334867U;
            aOrbiterK = RotL64((aOrbiterK * 12912773555616819941U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 35U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aScatter, 58U) + RotL64(aOrbiterG, 21U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + aNonceWordN);
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 60U)) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26971U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((aIndex + 27829U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 32486U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27093U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26258U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 26028U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 9023059520606551446U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 19U)) + 662441755115638133U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 3U)) + 16957253361196144712U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 7840955025765308605U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 43U)) + 346855809270395799U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 23U)) + 16099139781586668343U) + aNonceWordJ;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 58U)) + 3706457327118322098U) + aNonceWordN;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 13U)) + 12166825885547622870U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 7792658665720344200U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 7128477606152986326U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11116533962780290084U;
            aOrbiterJ = RotL64((aOrbiterJ * 11993485572912492297U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10443889548568288532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4402387036946561017U;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 13002706161178447654U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13929727277530310708U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7005639090871200285U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10949073760696935106U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15405923432006783533U;
            aOrbiterD = RotL64((aOrbiterD * 17989565878445202495U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18096057968822208905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3032155040484574973U;
            aOrbiterK = RotL64((aOrbiterK * 448597307502544605U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17462076466907467134U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 15471015427013701406U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 6113474000571976139U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3549031751266594344U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14243218483842508113U;
            aOrbiterE = RotL64((aOrbiterE * 9041601306479302047U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5803147589312920032U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5549470512227427855U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12592362489263862879U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10076661824293832189U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3196799148974716550U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8183276968961467775U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 28U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterF, 44U));
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + aNonceWordB) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 27U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 60U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

void TwistExpander_VolleyBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9A5D137DD39247F1ULL + 0xABA1FE88DA93C4F7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA614C64FAF33C373ULL + 0xD5DE52781B2B909EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x92B3B38A59728B13ULL + 0xB541FB31D40A4DBFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB36841CB7259ED5DULL + 0xF0A9DE0AF3CB4AABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEED8AD136F021565ULL + 0xAF58F6432BAECD45ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB516887D3E5FFE21ULL + 0xB1B2E5D237EF5818ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x86F177F887E4BCABULL + 0xB3C2875DBBDBCBCEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x830986485A54A429ULL + 0xDF95CE0C76EFC818ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCDF4EE407CF2AE15ULL + 0xA286BF91CEA2D344ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x948BCE13372FCCEFULL + 0x86D3CC0226EE6742ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCF0F9C0859421AF9ULL + 0x86CD301B87CE0D28ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBAF4FF16B2A04A9FULL + 0xDF0DC7CBD0C50E7EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9593F89F0E7858A5ULL + 0x99BCB3DF858C1C65ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAB1F216D3614AC81ULL + 0x8FF3EAB5300F442CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB1CF706CB9B0D591ULL + 0xC59EDEB757B8E62BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x979A014DFC3CFD33ULL + 0xFEB5F38B01DFA97EULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneD, aFireLaneA, aExpandLaneB, aOperationLaneD, aFireLaneB, aExpandLaneC, aOperationLaneA, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7738U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 4382U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 914U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2201U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5429U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3149U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 18180797995100240808U) + aOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 27U)) + 6585906608223552885U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 11U)) + 14088708930575939855U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 3U)) + 468974153311516044U) + aNonceWordC;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 44U)) + RotL64(aCarry, 39U)) + 12481951025619894110U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 17227987923860711763U) + aNonceWordA;
            aOrbiterC = (aWandererC + RotL64(aIngress, 21U)) + 4373962756657477139U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2077576476565420951U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17435011300234663764U;
            aOrbiterA = RotL64((aOrbiterA * 8910133867294004711U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4118039398293246896U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13724716599855216683U;
            aOrbiterH = RotL64((aOrbiterH * 17556333902751079677U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12391461204689596339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9900605191533799627U;
            aOrbiterK = RotL64((aOrbiterK * 13553565332531046301U), 53U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 972946858824366125U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17247681919694541215U;
            aOrbiterE = RotL64((aOrbiterE * 2974639094630445643U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15442851427306771601U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 7303586227288294037U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15406402525021428799U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 12650358753454105119U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1483710933373510492U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 6531763256577221891U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 18065810162229740788U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11311677121338794007U;
            aOrbiterC = RotL64((aOrbiterC * 15116367961682119467U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            aWandererF = aWandererF + (((((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 57U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + aNonceWordL);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 52U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14702U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 10672U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 11031U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14012U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13902U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11020U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 44U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 7075016829833562104U;
            aOrbiterH = (aWandererK + RotL64(aCross, 58U)) + 8783765886115517036U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 2996723892384565829U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 27U)) + 9494134707342189476U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 5052642981395679904U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 43U)) + 8766787055127962238U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 4467211954388738079U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8030255604633658608U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16962408063455702251U;
            aOrbiterD = RotL64((aOrbiterD * 11171737929747471631U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3768222186567699076U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14930990410207899871U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10930005786146268241U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14179761938395502502U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1879084742719898108U;
            aOrbiterE = RotL64((aOrbiterE * 16783034788172670121U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5535012408925981515U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12792553516710295939U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 8577530993755159329U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8979253163346099252U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5559189896063990740U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8832485423727331621U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13937564337299044079U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2393376759689394948U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 2352815657830413941U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12647519563697356479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10946871249960389549U;
            aOrbiterC = RotL64((aOrbiterC * 6272580371881237173U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterD, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + aNonceWordA);
            aWandererH = aWandererH + (((((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24384U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 20770U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19446U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16618U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22119U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 22098U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererK + RotL64(aCross, 11U)) + 3550722402315312207U;
            aOrbiterD = ((((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 16724184551669522754U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 981751330116773021U) + aNonceWordG;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 28U)) + 7891159229704944868U) + aNonceWordN;
            aOrbiterF = (aWandererH + RotL64(aCross, 5U)) + 13618396711464799841U;
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 5969291018449003648U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 19U)) + 14595540413313640042U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3287990436916111762U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 12534369400200483704U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 2345945228434740707U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2277312067930392274U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10026320559261334353U;
            aOrbiterG = RotL64((aOrbiterG * 11020464940995912637U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11258082063135659551U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1445958517675746990U;
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1011298251290970844U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6487834862470043744U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15477913837027179675U), 47U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 9966279022928268335U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10285993486057704393U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15965714363201157535U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16005362468813966136U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 223843444699390781U;
            aOrbiterB = RotL64((aOrbiterB * 665392038954573081U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 18178876294968532775U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12490136112181806806U;
            aOrbiterF = RotL64((aOrbiterF * 16380841616662993709U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + aNonceWordM);
            aWandererD = aWandererD + (((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 50U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25427U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 24849U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 32734U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26816U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29814U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28100U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 18U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 4773124477323378268U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 35U)) + 16848723289435796005U;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 19U)) + 13846642134917107058U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 6472057872482789939U) + aNonceWordJ;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 13U)) + 2747019500690707226U) + aNonceWordF;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 50U)) + RotL64(aCarry, 13U)) + 9003965289739733880U) + aNonceWordG;
            aOrbiterC = (aWandererF + RotL64(aCross, 27U)) + 3013390651936257377U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3331004709895625067U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15355010435553517129U;
            aOrbiterG = RotL64((aOrbiterG * 8322759117004876831U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7709870658004280052U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13568728443963926564U;
            aOrbiterF = RotL64((aOrbiterF * 6736090830113688981U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12409548853419307131U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 969183352023661537U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5549220554838837145U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15370309834426476775U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 3896803894396631184U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 11018830202891911603U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10848873633291935766U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12885336509190543440U;
            aOrbiterE = RotL64((aOrbiterE * 1487357252619221365U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8252290890093788010U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9201553615601641350U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 420321130559162915U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14014209645503188472U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4015071464301844550U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterE, 23U)) + aNonceWordI) + aWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterA, 6U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x98BC942B551323DBULL + 0xDCF1222A2B8653D0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB64BF3A77B765F89ULL + 0xDCFF0E71178A6A33ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCB5A554D8B821E39ULL + 0xAC529B1F2E9FD73BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x88C593FEC866F0ABULL + 0xCCF25CCA8A0E7319ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9928BE0173B639C7ULL + 0xE0E7053BB86B0843ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9F5A5B049BE8D42FULL + 0xDA652970EA07AE7BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBBD35313FCF10545ULL + 0x90CDEF6C2BA6797EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC578B6DB77A08FC1ULL + 0xE0525DAFF322BB03ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCD2299AE519AFA5BULL + 0xBF555E782B848CBAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC0827E31DECEFC0DULL + 0xF20EADD052713002ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDD859E2D5EED889BULL + 0xBB83D7153CD56BE4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE14F4DA91E3E5F95ULL + 0xA910AB0BE981C1C4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBB72F2437BBA4F09ULL + 0xC74CCF9909A0FADCULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB94E3CECEEB291D5ULL + 0xF96F5D70C5AAEC74ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC937D312D2A0B775ULL + 0x99B6CC254F9B6A36ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD140100F8E6B8307ULL + 0xDA46132DABDD7556ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 847U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1178U)) & W_KEY1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 407U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 1187U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererE + RotL64(aIngress, 18U)) + 6469584119078165548U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 11U)) + 14329756366517987910U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 12890831797059772123U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 57U)) + 3164503807500018990U) + aNonceWordL;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 177531431387646836U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 3167421392893561015U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 37U)) + 2813174781844753460U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10953270419153249857U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16911518309710356951U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 13162785997686570445U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6616750447844893150U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10276741398025985982U;
            aOrbiterC = RotL64((aOrbiterC * 6824712685896987133U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6206043608461213208U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12021552904553405793U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 10023362889960174909U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15283586234744144846U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5923238786775948571U;
            aOrbiterJ = RotL64((aOrbiterJ * 8200882393521882651U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11044014510971660078U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9351141024085076044U;
            aOrbiterI = RotL64((aOrbiterI * 13316079344614432317U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17703395981862992420U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10154548848376027087U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12324478347590509035U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 8836420852291617425U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10193385413543886344U;
            aOrbiterA = RotL64((aOrbiterA * 824935982418585449U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 50U)) + aOrbiterF) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterC, 43U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 3690U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 3768U)) & W_KEY1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3069U)) & W_KEY1], 56U) ^ RotL64(mSource[((aIndex + 2774U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 18U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 3970829908171131502U) + aNonceWordG;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 21U)) + 7040283759419531991U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererI + RotL64(aScatter, 35U)) + 11856292169397052901U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 819598588791819022U;
            aOrbiterI = (aWandererG + RotL64(aCross, 3U)) + 2176451710970866848U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 6454704928613390494U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 42U)) + 11792122387218053841U) + aNonceWordK;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9254780213489752211U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16591812589999846482U;
            aOrbiterB = RotL64((aOrbiterB * 5425771603523423167U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1471246223935074832U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1424843083106386453U;
            aOrbiterI = RotL64((aOrbiterI * 15020536982657410783U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1856469958050891629U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6331743690452052712U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15327924647897459645U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10351075711345476487U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9518585245330480185U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 3792179827396760391U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17787514620244712033U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14182328067398162557U;
            aOrbiterG = RotL64((aOrbiterG * 18107337388659070197U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12798088948801072444U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9563215159275202323U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 7058145016617349141U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9904919772580498232U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16579777394992143043U;
            aOrbiterK = RotL64((aOrbiterK * 10516761340320196661U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterC) + aNonceWordI);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 28U)) + aOrbiterG) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aNonceWordF) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7334U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5959U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6178U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6698U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7223U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 13481227414590594621U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 17425964381118918026U) + aNonceWordB;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 4792004356135956581U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 11926849936000639098U) + aNonceWordP;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 57U)) + 990697329347742142U) + aPhaseEOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 9307721505373076588U) + aNonceWordI;
            aOrbiterH = ((aWandererK + RotL64(aCross, 6U)) + 17605732738841908719U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13110764518634187439U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17970109897810645911U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 10395095143998920213U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10273133817644703654U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11239046688920468137U;
            aOrbiterA = RotL64((aOrbiterA * 5197802934333553327U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8355821483275763145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15522151127786049345U;
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5381663179722418112U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9551368011768104906U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14202470972121732997U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16264476585232221270U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7721417776432288282U;
            aOrbiterH = RotL64((aOrbiterH * 10267770327791051869U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 339418090653475277U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3247926250495935511U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 16824669543765729097U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3390560045236418590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3894024951542543635U;
            aOrbiterE = RotL64((aOrbiterE * 10599637790900418767U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + aNonceWordK);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterH, 10U)) + aNonceWordA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8335U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 9724U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 9591U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 8948U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9937U)) & W_KEY1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 9699U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 12U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 13U)) + 13350544654542863236U) + aNonceWordM;
            aOrbiterB = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 12364346790125404372U) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aIngress, 30U)) + 9738750172849512764U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 3781373837635491421U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 41U)) + 16635020317512702337U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 5383653921676231276U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 10181959815492056493U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10005510924273927017U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9524687662265740565U;
            aOrbiterD = RotL64((aOrbiterD * 13687380438646756931U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4259138552009771014U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8973051213213726023U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17602611840127337490U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8218984546932905269U;
            aOrbiterH = RotL64((aOrbiterH * 17504305273683304231U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18102186122213487888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2629927500298092976U;
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2491581597835795234U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9506602492971620955U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9559829640915637163U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13422942713680612924U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15037354693234876601U;
            aOrbiterF = RotL64((aOrbiterF * 12692376075738621447U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12896066842192894694U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 2202952306291905855U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 6779368532763429997U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterB, 6U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 27U)) + aOrbiterD) + aNonceWordO);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11601U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 12833U)) & W_KEY1], 38U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12664U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 13069U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11864U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12021U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 11864U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 54U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 3U)) + 13650869943246163567U) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 27U)) + 3435284932011770999U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 46U)) + RotL64(aCarry, 37U)) + 12388155658186776579U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 57U)) + 2374345913955712039U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 6095094526980292156U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 13U)) + 4965147025852444174U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 3261881216269075298U) + aNonceWordJ;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4939780217097329222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3019862009792676287U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2452316208025448747U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 901910626217143974U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3647055146712366383U;
            aOrbiterJ = RotL64((aOrbiterJ * 1792602402476450009U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7731765438957392967U) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13409819457393479741U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3345078200262410715U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5415832109107794258U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 8876738832313114471U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1304277600444504135U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17135570542519390359U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2373193062766802082U;
            aOrbiterA = RotL64((aOrbiterA * 4213691513185791519U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16318403285501718552U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8456043288604687045U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 10556964529144571683U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10572534930284516528U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14616251186735204677U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 2048651204265459805U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 39U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 43U)) + aNonceWordA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 4U)) + aOrbiterK) + aNonceWordE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15724U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 16320U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15523U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14744U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16197U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14699U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14438U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 36U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 11998579547770778580U;
            aOrbiterK = ((((aWandererG + RotL64(aIngress, 44U)) + RotL64(aCarry, 5U)) + 8409465187298704610U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 3470222286110333500U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 35U)) + 5704486785203069994U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 3U)) + 10334944660253279633U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + 7626852700722567477U) + aNonceWordA;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 14631310754943209743U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 807160297237854120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5624154783624196107U;
            aOrbiterB = RotL64((aOrbiterB * 2404066593958052159U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4971444394698940423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6340057638461027062U;
            aOrbiterF = RotL64((aOrbiterF * 12027586111086798629U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9003019862787819481U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 13632057463595873033U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 12575202147280216765U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 12766104026871797746U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4062118445824915939U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 13130770039048080701U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5258212525426469978U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9956946981015983939U;
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10837606223056473999U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13292864885504191134U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4445739587553669471U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 166087925900318658U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6786842221885441388U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 4411147600413147773U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterA, 30U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 37U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aNonceWordO);
            aWandererG = aWandererG + (((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 51U)) + aNonceWordP) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16678U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 16711U)) & W_KEY1], 4U));
            aIngress ^= (RotL64(mSource[((aIndex + 18754U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 18397U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17555U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18534U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18787U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 24U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererF + RotL64(aScatter, 27U)) + 9080426856729228705U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 7851218321653539276U) + aPhaseGOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 51U)) + 7023344692919298036U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 4U)) + 9772846154227440734U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 41U)) + 12008298632429608431U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 12201090455849562875U) + aNonceWordL;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 9498721803411445471U) + aNonceWordI;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 351203764023093632U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4966360430644539250U;
            aOrbiterJ = RotL64((aOrbiterJ * 10138518378274592739U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 9194167899071345693U) + aNonceWordJ;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 4922477697284269116U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 8444814161720407881U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15742625291642356429U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7528703106518431730U;
            aOrbiterK = RotL64((aOrbiterK * 11530049278751507567U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15279053574704935317U) + aNonceWordB;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2425839793660355555U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11486964816849830667U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13209849392400008898U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9041500097716231309U;
            aOrbiterF = RotL64((aOrbiterF * 340661035700748739U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 7885423750878814599U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1992993999902904603U;
            aOrbiterA = RotL64((aOrbiterA * 1478629826632201617U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6120758615019314102U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 8529621625846992066U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 8485991471612862467U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 44U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterK, 35U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 41U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + aNonceWordK) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + aNonceWordG) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20599U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 21832U)) & S_BLOCK1], 4U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20863U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21364U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19191U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20344U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21241U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 19549U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 18U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 42U)) + 5480870806135400132U) + aNonceWordP;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 8034874599430768743U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 57U)) + 4006919843736863767U) + aNonceWordD;
            aOrbiterC = ((((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 2988069748674633718U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererD + RotL64(aIngress, 13U)) + 12347295651973135786U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 5U)) + 14152683894431568192U) + aNonceWordF;
            aOrbiterH = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 15765143815254196598U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10473067082331244233U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1089466925383677249U;
            aOrbiterI = RotL64((aOrbiterI * 17334888609179149753U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 13215039929873682230U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3957997712247961479U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 7631186240013784703U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10023907397941685546U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14593012591254614353U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17111300092082154687U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13353797968154036726U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9259966668512102858U;
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10757861831070349321U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10530223113483866178U;
            aOrbiterH = RotL64((aOrbiterH * 11269177745265396583U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7554320926405521865U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6978052067277966996U;
            aOrbiterK = RotL64((aOrbiterK * 18020134738536217801U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1053695861967171420U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15980734683539854451U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3208466640010555357U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordE) + aPhaseGWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + aPhaseGWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 11U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 60U)) + aOrbiterH) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22799U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[((aIndex + 22537U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22691U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 22980U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21902U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24565U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23216U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23330U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 37U)) + 15904465836916519864U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 43U)) + 17725629806317789307U) + aPhaseGOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 13794170125914914828U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 3U)) + 2149055907476874332U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 5342047776745074649U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 10U)) + 8268148484060546838U) + aNonceWordK;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 11U)) + 10821151364028563719U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4294213820894407378U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10884726101307943090U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1116128870387229159U), 11U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 16432210042202444824U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15196602644336228055U;
            aOrbiterE = RotL64((aOrbiterE * 12680438355124070237U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 14117787670220328165U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 219833877949480215U;
            aOrbiterK = RotL64((aOrbiterK * 10736293047771972173U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3326396981881473962U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14918513066311426279U;
            aOrbiterD = RotL64((aOrbiterD * 14269763278564574663U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 11795234681370163206U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3068267285352664813U;
            aOrbiterA = RotL64((aOrbiterA * 15746255933920904619U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 245233356957999496U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 709926406353796673U;
            aOrbiterJ = RotL64((aOrbiterJ * 13627039596842073595U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5378105439430271038U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10114555061122044430U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5351295043424885549U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 10U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + aPhaseGWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 37U)) + aNonceWordH) + aPhaseGWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 24713U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 26800U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26917U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneB[((aIndex + 24954U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26134U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27253U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26312U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((aIndex + 25101U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 37U)) + 16451272412693907816U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 10099485419723255462U) + aNonceWordO;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 17668900099534923192U) + aNonceWordP;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 5497093724143181753U) + aNonceWordK;
            aOrbiterD = (aWandererH + RotL64(aCross, 43U)) + 10354044773550071706U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 5U)) + 12728258851198019099U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 23U)) + 4144050505314242618U) + aPhaseHOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14133805325480076530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 308863673210602899U;
            aOrbiterJ = RotL64((aOrbiterJ * 2672613556981540433U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11741180130160569753U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12926863156769180448U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9726030996091054939U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 211920854786494259U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13234608842479411078U;
            aOrbiterI = RotL64((aOrbiterI * 2556747209733759467U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9164711974854618892U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 6667377062281954219U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2603737166987437649U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4559040002406721850U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1749875480850675109U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 15822640067349481089U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 9555365165561936366U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18289733999504213574U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8727162691639622461U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 291406782452963706U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 8413500075082350243U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 50U)) + aNonceWordM) + aPhaseHWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 41U)) + aOrbiterD) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28321U)) & S_BLOCK1], 47U) ^ RotL64(aFireLaneD[((aIndex + 29364U)) & S_BLOCK1], 6U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27575U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((aIndex + 29090U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29201U)) & W_KEY1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28154U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28634U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 27862U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 4752759164691497960U;
            aOrbiterI = ((((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 12088872623537639782U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 3734943577379734227U) + aNonceWordA;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 8854778183012444234U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 3U)) + 16948373492893967275U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 41U)) + 7962415690046184385U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 60U)) + 1872682375669714454U) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7776801806943853566U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16665439117257230732U;
            aOrbiterD = RotL64((aOrbiterD * 6866375628213114965U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11088186766134265676U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10850237991780969350U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 7547414856143095121U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6464817712131305812U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 244557182884209844U;
            aOrbiterA = RotL64((aOrbiterA * 2394270354887582889U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13261563971157415841U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2323811103717827362U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11483723582415081925U), 19U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 12338803568475493422U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2811342930111104982U;
            aOrbiterC = RotL64((aOrbiterC * 5020981755203607757U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5554497011738996057U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12712169745460598698U;
            aOrbiterH = RotL64((aOrbiterH * 1985586486150377769U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17415058661427002973U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9430421222715343818U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10321140659099470811U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterA) + aNonceWordD) + aPhaseHWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aNonceWordF);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterI, 28U)) + RotL64(aCarry, 41U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32673U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32237U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31681U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31266U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30598U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30366U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 3U)) + 9446153639709651566U) + aNonceWordI;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 13U)) + 10550762260670758167U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 7062634922142578383U;
            aOrbiterC = ((((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 9178499097812764515U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 30U)) + 6887103379773525538U) + aNonceWordJ;
            aOrbiterK = (aWandererH + RotL64(aCross, 47U)) + 6239750312052010257U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 17645022614523287959U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3639618183259408272U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 3131737117548745095U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6585057380704940395U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7253994382396406554U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15217993711938379561U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 21U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 12594152227603630033U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11250170200489647869U;
            aOrbiterF = RotL64((aOrbiterF * 546800378327864723U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12936942656624279424U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10990736056052106149U;
            aOrbiterJ = RotL64((aOrbiterJ * 7123916809953459187U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12787293075893090465U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17154990205620778151U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10031369940028159521U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1270827262969060301U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17337623431665013136U;
            aOrbiterK = RotL64((aOrbiterK * 1517262088236356107U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 830330490987911853U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6828309232554560547U;
            aOrbiterG = RotL64((aOrbiterG * 9742464176986145819U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterE, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterK, 23U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U)) + aNonceWordM) + aPhaseHWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterA, 10U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererH, 4U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE37D1C8D4486AF51ULL + 0xF89E1C51546FB951ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE1634281711D2197ULL + 0xD9609B7E299E5CF3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB07D6EFB21A46D9FULL + 0xD0A62198F2F5D799ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA8C63869E289531DULL + 0xA45223EBE9C4856AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFAC3B88508634BDBULL + 0xAC717D7387D501DFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF268231AB422F131ULL + 0xE9B9F3B11AC3ABF6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE7FC2BD220C2B9AFULL + 0xE939975E4F0EF92EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD07127600D48D28BULL + 0xB35AADD0D33F34C1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCE89C8590E0595E5ULL + 0xC6B707B0E77DE91EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA1348E7243FC8CD1ULL + 0xC910E28C16B1E1F0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x92A44F75F9D1521DULL + 0xB931D25EEAEE6A2BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCC851C092D0B0DD7ULL + 0xDEB523E524657EE4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCB53B8A0C9D55761ULL + 0x8544D99409C7812EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x94BDEB6843482FA7ULL + 0xABE65C2AE9B1D45BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x991186E1B6D34473ULL + 0x872503BB27522B0CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD90E1FFAE6BCF433ULL + 0x819A3A460B18EF1BULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneD, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1820U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 1950U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2177U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 201U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 1254U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererE + RotL64(aScatter, 47U)) + 3621877681473089725U) + aNonceWordF;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 21U)) + 4451752751536414717U;
            aOrbiterI = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 5U)) + 11371625415377772117U) + aNonceWordA;
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 6046792758881150619U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 8213166120394461682U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4343156661140422645U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11105271483234947905U;
            aOrbiterI = RotL64((aOrbiterI * 853531080115819287U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 348904609985341372U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12924652822526858767U;
            aOrbiterJ = RotL64((aOrbiterJ * 2801892489296408735U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 7461211697358520287U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 16551553555297890558U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16432952324635746293U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11908056404140782995U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9147367258259948715U;
            aOrbiterF = RotL64((aOrbiterF * 10777628928376261667U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8876461054692728610U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 10546855952702525404U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 10071104785895309677U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 13U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 44U)) + aOrbiterJ);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + aNonceWordM) + aPhaseAWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6536U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 8478U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 5904U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8197U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 6031U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 10038936806177516123U) + aNonceWordO;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + 1773168435195292638U) + aNonceWordK;
            aOrbiterG = ((((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 10655711161526628072U) + aPhaseAOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 14422295664639740437U;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 58U)) + 4125228715513159576U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3670449653158650845U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17553727567180813057U;
            aOrbiterG = RotL64((aOrbiterG * 11814335762020146785U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5111401772713882743U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 7688573124662314413U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 10846442063022821393U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9438375825507814395U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14177477039902118886U;
            aOrbiterD = RotL64((aOrbiterD * 6467406626985022537U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16329942595859623928U) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3990536794006836672U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 579024714339065373U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5072881436583180756U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16789727877867289997U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 8766246302636197905U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aNonceWordL) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 12U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13783U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 13360U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15896U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15024U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14103U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 11089U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 18U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 7960325128608297381U) + aNonceWordO;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 12U)) + RotL64(aCarry, 35U)) + 12773836012104052042U) + aPhaseAOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 3173972621347773016U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 3U)) + 3708401356314308171U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 21U)) + 950774285720019449U) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4170092315705438265U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17000449130864980747U;
            aOrbiterF = RotL64((aOrbiterF * 7710635557693533263U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8793910540062893860U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 520277969543516469U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4150613128885828229U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12762214857389827271U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2932451184340207695U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 7513337346940091655U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11062179998786293839U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7919119215271524178U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9053677007180081359U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1774988449597115155U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 3799792889466518953U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 17512791286490623455U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 3U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterF) + aNonceWordK) + aPhaseAWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + aNonceWordI) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 39U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 30U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17705U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneA[((aIndex + 17530U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 18866U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20425U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19979U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19974U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 17074147006464019918U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 5U)) + 10559516626129419928U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 39U)) + 13280363679503946221U) + aNonceWordJ;
            aOrbiterD = ((((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 17657115422132457413U) + aPhaseAOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererH + RotL64(aIngress, 51U)) + 13325837013304973008U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 3059707750486106037U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4529045702503050852U;
            aOrbiterB = RotL64((aOrbiterB * 12889277842182219673U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10726578475550904292U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14832537837996659885U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 808060368961520519U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 220094417441809246U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15343130035105342194U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 7984652435043810845U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16592263353426409884U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15649290906447931918U;
            aOrbiterJ = RotL64((aOrbiterJ * 8405875177836650731U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11437410545843708269U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5859769136073011444U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1065016088086441107U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 40U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterB, 40U)) + RotL64(aCarry, 27U)) + aNonceWordF) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 21U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26676U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 23210U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27094U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26133U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26703U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25312U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 54U)) + (RotL64(aCross, 41U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 12262991801139086177U) + aNonceWordG;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 7963038771924890197U) + aNonceWordD;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 3U)) + 15540520327933568896U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererD + RotL64(aCross, 20U)) + 8745565892055020722U) + aNonceWordJ;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 16619329199683755286U) + aPhaseAOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10865705026433867260U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2743368697984518059U;
            aOrbiterE = RotL64((aOrbiterE * 2989232417816919375U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5556006271515473135U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5355833281353498588U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4190140212757841511U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 8313616108963479829U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16657121016801866434U;
            aOrbiterB = RotL64((aOrbiterB * 331533349428472477U), 37U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 16532226425013000833U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5800465874932467232U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5966395771690704577U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17882948163883121328U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15029375310296563175U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17021415832288477713U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 30U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 37U)) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordM);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordL) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterA, 48U)) + aNonceWordK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32163U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 28823U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27378U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29977U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30363U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 32178U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 28U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 3561491146322798260U) + aNonceWordF;
            aOrbiterI = ((((aWandererK + RotL64(aPrevious, 34U)) + RotL64(aCarry, 41U)) + 7075025056181885339U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 9230910887904171613U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aWandererA + RotL64(aScatter, 5U)) + 4119781172609908917U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 57U)) + 17155609083870983149U) + aNonceWordC;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2423018561430181695U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12957280305617615744U;
            aOrbiterJ = RotL64((aOrbiterJ * 17696410107705645631U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2461704174772065813U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7907123257849391997U;
            aOrbiterH = RotL64((aOrbiterH * 9416171962847312179U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 7257868138318960007U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16425903703085702285U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7996935869077231999U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2990822664594079467U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5654819006718953817U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4465096036756887801U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12183676471235678779U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15026286960542123922U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17199049329995315279U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 52U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterI) + aPhaseAWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 14U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9B0C53C02684AA49ULL + 0x89AD13E41BCB53EFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC15CCD8C0B753CE7ULL + 0xFE00393D8B9D1487ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD8CFA02DB539AB39ULL + 0xD261C48A31617357ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAF0EEAEC6E28C855ULL + 0xA3DF733E6A59BBCEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x86B1C2C7BBF58A11ULL + 0xA3DA0F438BFCCF46ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9EC5CED3D90F3939ULL + 0x91E7D446D30A33C2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFDD07A2ABEE3C061ULL + 0xF6084AA9BDD3CA15ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF39BF6725E331FEBULL + 0x91975DB60365FB4AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF7C47EEF9378DC6FULL + 0xBAC7976B56FF24C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD095DC287AA7987DULL + 0xA53C6CC0399B84A3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEBED9171ABE53D77ULL + 0xB5CF0B68CEBE3E72ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8731A30B8CBFD163ULL + 0xC881D79494BC5CDEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC1FD38C004A0103DULL + 0xB594241DB0D8D8C7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB21324F27753CDDBULL + 0xB338D97E5F015A4CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x949D018405D0C4CBULL + 0xCBD14A28823F35E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF90B75B4AA12D6B7ULL + 0xC12AF01C0BC1FF45ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC, aInvestLaneC, aExpandLaneC, aExpandLaneA, aInvestLaneD, aFireLaneB, aWorkLaneA, aFireLaneD, aWorkLaneB, aExpandLaneB, aWorkLaneC, aExpandLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneC backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4350U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 2410U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1599U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5332U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1047U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 4542U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = (aWandererF + RotL64(aCross, 57U)) + 17912271996338180948U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + 13259276608841847058U) + aNonceWordE;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 16225936008657276089U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 24U)) + 2243058962151834071U) + aNonceWordG;
            aOrbiterC = (aWandererG + RotL64(aScatter, 5U)) + 10637439274127347861U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 41U)) + 15312219216405992627U) + aNonceWordA;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 2393933972129878613U) + aPhaseBOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 4327069337247976513U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 29U)) + 8307656353434167837U) + aPhaseBOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17299145556933889336U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14458100581172798164U;
            aOrbiterI = RotL64((aOrbiterI * 16543734663677070509U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6410095654927998067U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6168964796264687686U;
            aOrbiterD = RotL64((aOrbiterD * 16218071040190475953U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3667999465041020730U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16021552859323602007U;
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 12941668202330045095U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 4222032891850449934U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 17292856787431308097U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1346342592002730785U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16860611785008118820U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 384963420804756607U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3193572711804730241U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 5866881282680588589U;
            aOrbiterH = RotL64((aOrbiterH * 9226331800853634597U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17180332731328479126U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10222097519535882241U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 9422887302872778795U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8863502179821584859U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14872318155712512999U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11830641277356873233U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16478790641892781150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8414944141232294781U;
            aOrbiterC = RotL64((aOrbiterC * 17443775794621154023U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 56U) + aOrbiterB) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 10U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            aWandererK = aWandererK + (((((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 47U)) + aNonceWordF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 38U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9396U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 7655U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5632U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5898U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7305U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5751U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6325U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 20U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 23U)) + 16922357079016918108U) + aNonceWordK;
            aOrbiterK = (aWandererA + RotL64(aScatter, 11U)) + 11771749797137599131U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 60U)) + 4635668433708036077U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 53U)) + 15827952719230577008U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 1495675306110023086U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 3U)) + 7294835466949728365U;
            aOrbiterJ = ((((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 179122461212041978U) + aPhaseBOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 57U)) + 545981421632236251U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 29U)) + 15338259639814630535U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 12924313840290895215U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17846785921286020610U;
            aOrbiterA = RotL64((aOrbiterA * 18309347016029917133U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5721472794107057875U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16359630793856870319U;
            aOrbiterK = RotL64((aOrbiterK * 14186771515526698907U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10614102110239037308U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16421992251278236531U;
            aOrbiterF = RotL64((aOrbiterF * 2561232904676068089U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8668149834861244963U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 12699331834360948734U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2249360824172616357U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4470693178142950471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 526000656022724741U;
            aOrbiterB = RotL64((aOrbiterB * 16688501462334673493U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 6880246132270094141U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7126466778855297013U;
            aOrbiterJ = RotL64((aOrbiterJ * 5692237926830293205U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6436404501390442054U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1213633065612242699U;
            aOrbiterG = RotL64((aOrbiterG * 17604454985534439259U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8186529105901185854U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10607460957358250935U;
            aOrbiterH = RotL64((aOrbiterH * 17172191011625677861U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9743278964993305169U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14007577681873418075U;
            aOrbiterC = RotL64((aOrbiterC * 4231122580398039133U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 44U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 29U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 56U)) + aOrbiterJ) + aNonceWordG);
            aWandererK = aWandererK + ((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 37U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterK, 18U)) + aOrbiterC) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + aPhaseBWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12804U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 14616U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15202U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11088U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 13101U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererH + RotL64(aIngress, 39U)) + 2225397913940961213U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 57U)) + 8342544893601343643U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 19U)) + 162922186381417187U) + aNonceWordB;
            aOrbiterB = (aWandererA + RotL64(aCross, 48U)) + 11660218373710972210U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 14909034764605802354U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 35U)) + 16776955237009701511U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 5834487809188925253U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 28U)) + 1498492772767040320U) + aNonceWordG;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 4161765458781579617U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10511923076962447765U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8575954471692620021U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12526744988828982731U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6536325446331340573U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1790628986900286346U;
            aOrbiterH = RotL64((aOrbiterH * 5262997114200816715U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2623814807619278590U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11676970995834706612U;
            aOrbiterD = RotL64((aOrbiterD * 10057461115132434901U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13836786354224256591U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6293096163612129260U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8977954126326217153U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4271144764978661248U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15938494256992560202U;
            aOrbiterI = RotL64((aOrbiterI * 10004841288382726739U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11038155227307702976U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12408749795071243930U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5527720475032868855U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1673665849053496882U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12866353361497103629U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 6041125499398924871U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10673935802381580966U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8946776538955520352U;
            aOrbiterF = RotL64((aOrbiterF * 12293084177712710021U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16294935203370452805U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4697759331563852212U;
            aOrbiterA = RotL64((aOrbiterA * 14407806317275373043U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 5U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 41U)) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 23U)) + aPhaseBWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16881U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((aIndex + 16970U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19763U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17774U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18921U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 26U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 53U)) + 8020711767807230555U) + aPhaseBOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 6U)) + RotL64(aCarry, 27U)) + 15368693777246341570U;
            aOrbiterI = (aWandererC + RotL64(aCross, 39U)) + 5117523734225562401U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 29U)) + 13155269151097507808U) + aNonceWordD;
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 9879303753623578272U;
            aOrbiterJ = ((((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 43U)) + 1165799257173794826U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + 930641942062732091U) + aNonceWordM;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 43U)) + 11330571332221123153U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 57U)) + 2862963158282518899U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6019186399361476659U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1924419843785161958U;
            aOrbiterI = RotL64((aOrbiterI * 9485557122500346869U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12618629043591380461U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9334176504266512405U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16829692481030013551U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 5604784396927022709U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2833893610883508353U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16124030106598549644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16571659812830230677U;
            aOrbiterG = RotL64((aOrbiterG * 4668250364992383549U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15171089673591843703U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2826755560293849328U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9397017963457655287U), 5U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 9976785768283589291U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 11845100564714691809U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4935139932585319251U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7318560453127859950U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3039196878830506712U;
            aOrbiterE = RotL64((aOrbiterE * 3140508261330698717U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8850992055588337843U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4219373528176869146U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 1310964742529956743U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1341474458715938799U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15937557372891732898U;
            aOrbiterH = RotL64((aOrbiterH * 11437307017920192915U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 10U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterC) + aNonceWordG);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 58U)) + aOrbiterI) + aNonceWordN) + aPhaseBWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aPhaseBWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + aOrbiterG) + RotL64(aOrbiterK, 12U));
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22265U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 22728U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22586U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21845U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((aIndex + 22943U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 24U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (aWandererE + RotL64(aIngress, 3U)) + 3339283916456813609U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 60U)) + 11339086426180649584U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 43U)) + 16819191669329316585U) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 8361916937762630725U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 18031328374429899857U) + aNonceWordP;
            aOrbiterI = (aWandererK + RotL64(aIngress, 35U)) + 18261756894092897276U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 4250319792907645666U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + 1492411503643460886U) + aPhaseBOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 39U)) + 17369549067879344180U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7301713524358676722U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterJ = RotL64((aOrbiterJ * 7473297294949338265U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14086975808140927408U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11441293212275890819U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18205555540941493267U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9209505304067579944U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3522631966146762306U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3441982898533162599U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8811497120829041188U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14707301680850257294U;
            aOrbiterG = RotL64((aOrbiterG * 11383709499376464085U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10080595991787801029U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6822892187784299166U;
            aOrbiterB = RotL64((aOrbiterB * 7417016898027778287U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1981637172055758689U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16463077485583119324U;
            aOrbiterC = RotL64((aOrbiterC * 2876782050665869121U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8383837717361569465U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2788511294985017326U;
            aOrbiterE = RotL64((aOrbiterE * 2809163242875130677U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3529607472855930041U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8850940802020173766U;
            aOrbiterF = RotL64((aOrbiterF * 7821450253655655943U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterC, 60U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterF, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterF, 13U)) + aPhaseBWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 34U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 37U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29178U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 28589U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 29232U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32657U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32545U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 23U)) + 15036852811491820366U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 305637140752898475U;
            aOrbiterJ = ((((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 11948631574496129610U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 5321623592482991426U;
            aOrbiterC = (aWandererC + RotL64(aCross, 51U)) + 4075270159062690728U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 15111580500356908928U) + aNonceWordF;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 46U)) + 7244150695504160363U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 19U)) + 5131563519577488862U;
            aOrbiterF = (aWandererB + RotL64(aCross, 3U)) + 5881954992088651371U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12780935808751507998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12599159643925470226U;
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9466589929741834066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6093158735705189789U;
            aOrbiterC = RotL64((aOrbiterC * 7453778295800853653U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17461243886150519249U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15456408913739900718U;
            aOrbiterK = RotL64((aOrbiterK * 16093292401746174671U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 11260643903290392780U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7870342756041882616U;
            aOrbiterG = RotL64((aOrbiterG * 2431528656086173419U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 134484990005888936U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10626896209992890407U;
            aOrbiterH = RotL64((aOrbiterH * 12034131076645285597U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14031164129515132292U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1771835705730244212U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 186981668443596623U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16395472745067254664U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 1455944290845294254U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 6757824754363319079U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17866422769075350837U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10226884082632410805U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 206035536985843815U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 14474587247775371703U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8501763445324525303U;
            aOrbiterI = RotL64((aOrbiterI * 5298694643596784007U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 44U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aNonceWordM);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aPhaseBWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterC, 44U)) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 19U)) + aOrbiterH) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterK, 34U));
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_VolleyBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA31AC8ECD859FF99ULL + 0xB0537B1630F3ECFFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA6B99508DA081B39ULL + 0x8155EC938C4CF7DBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB5FE134A08E45E5DULL + 0xB4592826D5BE3EF4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFEE513510DE17EF7ULL + 0x865402E11120DD0EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8512BED825BFD631ULL + 0xEF97F8B8C1512704ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA38F9A5827B6ED69ULL + 0xF2702406FE757B4AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC9468C976CAFD6C1ULL + 0xFB4D3276F827A335ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8D646D8FE4547DB9ULL + 0xB1452930028B05E4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD14E0ED0B5C8AB3DULL + 0xD85EE55951EA37EAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED32A0B6BFCE8D2DULL + 0xEE3995B9134B7200ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB55A67357A437EC7ULL + 0xFD49F88BABB3169DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x89DE764EA98D89FDULL + 0xD9976B2AA2D4BCC8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEFEC96293A878D4DULL + 0x9B1E357F1C97A5FBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC46BA940C80EBE49ULL + 0xA725E3B4461B9726ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8C54CC20885DE975ULL + 0xF7E922C1F22EB4F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDFEDDF33DD716CE3ULL + 0xDA04DD82D9172D1CULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1976U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 3460U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 4621U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 257U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 830U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 3272U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 7651355040951791298U) + aNonceWordC;
            aOrbiterC = (aWandererB + RotL64(aScatter, 3U)) + 13988210277931659312U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 47U)) + 9846849412579537783U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 37U)) + 12746719939495876158U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 11498066185182895284U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 57U)) + 11101058955193080232U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 30U)) + RotL64(aCarry, 43U)) + 15513734459555672046U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 15711108675349394643U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4771231759949468556U;
            aOrbiterH = RotL64((aOrbiterH * 9806191054594333615U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11449258010811305256U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17036938391509986723U;
            aOrbiterG = RotL64((aOrbiterG * 7411466953205347639U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6999245666776654250U) + aNonceWordP;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 2106819066263369528U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13005885810757743129U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12716183358903477216U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16752724547046059889U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11475905692393034141U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17623077680983093163U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6726003022297274986U;
            aOrbiterC = RotL64((aOrbiterC * 14709385877103232653U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2842410225096524740U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9235178377537910514U;
            aOrbiterB = RotL64((aOrbiterB * 11813751114775673845U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2619888019860844610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6295481948199619613U;
            aOrbiterK = RotL64((aOrbiterK * 15429161806953951205U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 4U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 58U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ) + aNonceWordF);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 51U)) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 6578U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 9366U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7673U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 8332U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7015U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10864U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8544U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 22U) ^ RotL64(aCarry, 51U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = (((aWandererC + RotL64(aScatter, 54U)) + RotL64(aCarry, 51U)) + 13278949403988203974U) + aNonceWordC;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 27U)) + 9213599924054673756U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 1255746482932381798U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 11575321997144516122U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 13U)) + 15881587525529432437U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 5U)) + 9846195809864862707U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 37U)) + 12319815691858217670U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16322617427294439587U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16332130810525887437U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7588076439690559343U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4920951156015336794U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16767126455124552329U;
            aOrbiterE = RotL64((aOrbiterE * 4440352337076842603U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12553595911087945223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1437522202135436142U;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 12313100454852227143U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2761983020631055729U;
            aOrbiterA = RotL64((aOrbiterA * 3874839760378039509U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17635303588421554367U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 788212489507463763U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 17896475584538528059U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5192552894670654434U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6784748488807738811U;
            aOrbiterD = RotL64((aOrbiterD * 8077237651953896479U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16113417046719114943U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1096874945215225916U;
            aOrbiterH = RotL64((aOrbiterH * 17308604412622879833U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 34U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + aNonceWordA) + aPhaseDWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12252U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 13262U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13059U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11209U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 15920U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 16424657151168221875U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 35U)) + 17150123681886380361U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 57U)) + 16041993588694572757U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 9871185846434828537U) + aPhaseDOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 20U)) + 11227236398354430757U) + aNonceWordD;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 5399325217402192631U) + aNonceWordF;
            aOrbiterC = (aWandererG + RotL64(aIngress, 27U)) + 9248828789282890454U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9041370494203701062U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14944424084524970764U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 10283363059424655079U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5481938174456671041U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14783648629543752715U;
            aOrbiterG = RotL64((aOrbiterG * 7260164783191886395U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12355573914530445723U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9863991559011968318U;
            aOrbiterH = RotL64((aOrbiterH * 8495251211794343179U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16149688605937250965U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 106041828692026825U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 12199934305374582599U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 8076098639554567792U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11155119311895580013U;
            aOrbiterJ = RotL64((aOrbiterJ * 1495180896564818647U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6847612160595917702U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 16094377920388017367U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 4875801863643206333U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 13584719866672696684U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13446209321646234607U;
            aOrbiterB = RotL64((aOrbiterB * 9945349065094781529U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 56U) + aOrbiterJ) + RotL64(aOrbiterH, 60U)) + aNonceWordJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 5U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 16461U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 18354U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18044U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17237U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18857U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 964165145848253292U) + aNonceWordK;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 35U)) + 10645976767204934746U) + aPhaseDOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 51U)) + 8241612229349212650U) + aNonceWordA;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 60U)) + 4159196033256913347U) + aPhaseDOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 13U)) + 7194795864620233507U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 7638928444536778384U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 11819105916503968109U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18052213302858186237U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8663575313970041570U;
            aOrbiterB = RotL64((aOrbiterB * 14131073322476609161U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16644136720439299786U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16930316530442679864U;
            aOrbiterK = RotL64((aOrbiterK * 2650922074098320859U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16251107616988250593U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7171986193609401665U;
            aOrbiterF = RotL64((aOrbiterF * 3543709971414550087U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17885046834432626644U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7757069274715713557U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 15766885299397923879U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 2212805322061155615U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 6368539134638838822U;
            aOrbiterC = RotL64((aOrbiterC * 13383744883433594259U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5264326094252925613U) + aNonceWordE;
            aOrbiterA = (((aOrbiterA ^ aOrbiterK) ^ 6126345334815012938U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 17180934809764905307U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13826731214018407061U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6621261811613643620U;
            aOrbiterD = RotL64((aOrbiterD * 2823596473596114171U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 36U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterF, 5U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aCarry, 23U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22844U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 23269U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24436U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24919U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25151U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 53U)) + 8767379393098711499U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 47U)) + 7168159491580816433U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + 9879279829061883406U) + aNonceWordA;
            aOrbiterH = (aWandererD + RotL64(aCross, 3U)) + 10537167136053399303U;
            aOrbiterB = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 2839070018069188936U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 13844278063968429732U) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 11278946626186474646U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11798425216660557799U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7618446090703335192U;
            aOrbiterK = RotL64((aOrbiterK * 7168757300685156779U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 695423597006983660U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14344728202803488813U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5168825904902285909U), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 11656100506575697086U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10384358779985773937U;
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17585001605131977341U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9964478171465522911U;
            aOrbiterC = RotL64((aOrbiterC * 13484044854790175315U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2710943171829692624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17809072853457153057U;
            aOrbiterJ = RotL64((aOrbiterJ * 16341884203303271365U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12814092033910687774U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1743186323268668740U;
            aOrbiterI = RotL64((aOrbiterI * 11150822630624332557U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 10750472346626754704U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15925901217078035356U;
            aOrbiterH = RotL64((aOrbiterH * 9276504171291801637U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + aPhaseDWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterH, 58U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 28505U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneA[((aIndex + 32182U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27463U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29915U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 31945U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 7893287783892523139U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 35U)) + 10257331997383491153U) + aPhaseDOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererD + RotL64(aCross, 29U)) + 14562226733652231753U) + aNonceWordF;
            aOrbiterI = (aWandererK + RotL64(aScatter, 47U)) + 14320342577110737851U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 9816717579822880756U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 9558926960095881953U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 13U)) + 9230371862654338324U) + aPhaseDOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6414274291252913420U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13868546184398350849U;
            aOrbiterG = RotL64((aOrbiterG * 1547986864837497409U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16940736952569949038U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2866957764814864371U;
            aOrbiterA = RotL64((aOrbiterA * 3554702178644797003U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7916721976073979724U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1602444214978842275U;
            aOrbiterK = RotL64((aOrbiterK * 11072503711308122385U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9529061385251008037U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8402775110887376588U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13980225144628227381U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 15003592180290390713U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14195681406520825751U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11455000833788877217U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 3263577002367714202U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12019422062655581928U;
            aOrbiterH = RotL64((aOrbiterH * 5002313835338447799U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8508638054582582917U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6536618106353552880U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6233964121117511885U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aNonceWordA) + aPhaseDWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 53U)) + aOrbiterC) + aNonceWordM) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterA, 60U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD8878B2E46E1B249ULL + 0xA0BCCEDF681F3216ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBBC9F4965D4240BDULL + 0xC42324C01C7CDA0DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE53547EF81014A31ULL + 0xC28560C88E6ED4BBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBF2375F442258063ULL + 0xBA9B87FC9BB7E77EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB01E2D082A4555A3ULL + 0xFDC3E8960BCAFF7BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB97929F7DD1DD077ULL + 0x89259CE170AA3344ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC93F56A57B410161ULL + 0xDB8CF8FB8D9B0F12ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x802C00714E868097ULL + 0xF45A276626543680ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDAD21F35E16E0699ULL + 0x8B2AC77183669F1CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBFB721FAEB5183D5ULL + 0xEDB4D94CDEFE7D1FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF6888FBC8A367F6FULL + 0xE08E3EE4C4DEF363ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC12D5ACCB943EA39ULL + 0xA8DD95D0BF88474AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBC1CC265CC79BB1DULL + 0xDC340298017C7656ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB6D0268685709279ULL + 0xA6D0DDB023579140ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE5B69E2562E079E7ULL + 0xE352BBB93FCA8096ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x846197F1F9A8DD6DULL + 0x837966334976EF56ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 5428U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 634U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 678U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 1134U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2129U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4526U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + 12136097566601676613U) + aNonceWordB;
            aOrbiterE = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 7969431322248040056U) + aNonceWordO;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 3U)) + 10530676021510553889U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 35U)) + 8740777303075445264U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 51U)) + 13249434169895564739U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 13U)) + 15529577005925628472U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + 344627093687331562U) + aNonceWordA;
            aOrbiterF = (aWandererC + RotL64(aIngress, 57U)) + 8824277416519988893U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 11U)) + 5636276438449709875U;
            aOrbiterH = (aWandererA + RotL64(aCross, 28U)) + 2079413361031851552U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 7807998179168655561U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13589392896232029112U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10733011474804473996U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 361749145931578805U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15934162328347805968U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterA) ^ 7573511217796245232U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 10694563909931636155U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4828475187337891975U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13284974329890393113U;
            aOrbiterJ = RotL64((aOrbiterJ * 10831075817642374287U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13173869918669643112U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15841507674783398167U;
            aOrbiterC = RotL64((aOrbiterC * 15632933198136963277U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14168272451055700516U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11134471485501999898U;
            aOrbiterG = RotL64((aOrbiterG * 8019507184494591705U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2611858916687822610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17863271539727513641U;
            aOrbiterH = RotL64((aOrbiterH * 4987884722174985677U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8874401993454249066U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5131480593493950665U;
            aOrbiterK = RotL64((aOrbiterK * 8585874663602346121U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9366563022381918996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7890729519928340296U;
            aOrbiterF = RotL64((aOrbiterF * 11428572374057899517U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 131774386529223292U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4108356674478240148U;
            aOrbiterD = RotL64((aOrbiterD * 2492753294539081613U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7651738365157869789U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2745458108574051004U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 2175955806036373729U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10492013124307434604U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 12136097566601676613U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13128652803485742119U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 58U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 35U)) + aPhaseEWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterA) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 11U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 5569U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 6414U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7609U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 6445U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9358U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9912U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6259U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 19U)) + 6771552164800695068U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + 12131763371571322040U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aIngress, 27U)) + 3326182381395522013U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 29U)) + 12288775097697156383U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 46U)) + RotL64(aCarry, 39U)) + 5195948373449796741U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 5U)) + 14404044002250137144U) + aNonceWordG;
            aOrbiterB = (aWandererG + RotL64(aScatter, 13U)) + 11142382920035825426U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + 2967149520256475485U) + aNonceWordI;
            aOrbiterC = (aWandererE + RotL64(aScatter, 51U)) + 1470907369577818097U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 11U)) + 9231668148004163910U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 40U)) + RotL64(aCarry, 47U)) + 13078929163913892386U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9485274692075657877U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12216951187543631673U;
            aOrbiterK = RotL64((aOrbiterK * 6571066246507310805U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6933334652581744234U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17260276102423580920U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7796879893790990605U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 387767848169714392U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8597538259308082638U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4888054690557707241U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7996708724489146033U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15357384191688149939U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9827691726832491373U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17739222908739454637U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1614322333281471170U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 7063116837752240891U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4531604274893197209U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3453280714992341288U;
            aOrbiterD = RotL64((aOrbiterD * 8390029711127907805U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 116623650872661533U) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6565636510115095988U;
            aOrbiterF = RotL64((aOrbiterF * 9691897067492501177U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10303258439817808058U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10917642773040237611U;
            aOrbiterC = RotL64((aOrbiterC * 10232856828372963363U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2087058228468680821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3691125545393861889U;
            aOrbiterG = RotL64((aOrbiterG * 1768745056298937903U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9240209357066002219U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7645250700232422804U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6762116797395687607U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9859862257084218280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6771552164800695068U;
            aOrbiterA = RotL64((aOrbiterA * 11063630807191661109U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 14U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterA, 48U));
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 12035U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((aIndex + 12477U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12432U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11597U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13598U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 29U)) + 12775735908960052604U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aCross, 57U)) + 11791373812080296887U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 19U)) + 5537362877706057303U) + aNonceWordF;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 24U)) + 2023912048504189380U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 17668828109963766893U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 11U)) + 558908629933941224U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 1479633119685446888U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 15460320397843364063U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 3U)) + 10059749397555469054U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 5U)) + 9987633811929693924U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 48U)) + 10087337844580228269U) + aNonceWordO;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4446204415503364254U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15106063243302192717U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13273756657334709803U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9430197906134676162U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1226048679997253363U;
            aOrbiterF = RotL64((aOrbiterF * 14247538885252664127U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10611580584157624739U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3137391249289641509U;
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9327201928815412810U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 7890659377013147073U;
            aOrbiterE = RotL64((aOrbiterE * 13827717178378062047U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10675114832750356941U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8804440385852327267U;
            aOrbiterH = RotL64((aOrbiterH * 8520671775587260601U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12871947817782057116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11015991745792051390U;
            aOrbiterJ = RotL64((aOrbiterJ * 17152451500505815031U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6320437975845673731U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 702457937087191287U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 17491257114676739589U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16629064896250312921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6054107387816339103U;
            aOrbiterA = RotL64((aOrbiterA * 6983767878966747219U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13274874838094190290U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12211422735294360321U;
            aOrbiterB = RotL64((aOrbiterB * 5113738196151089817U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15338616110718583619U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1475787183754511373U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10904607643785840003U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15486810401396777742U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12775735908960052604U;
            aOrbiterI = RotL64((aOrbiterI * 7478156942468930207U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterA, 39U));
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterI, 50U));
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 57U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 48U)) + aOrbiterA) + aNonceWordM) + aPhaseEWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterJ, 23U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 17482U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((aIndex + 20489U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20019U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20723U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneD[((aIndex + 19645U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 10U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (aWandererC + RotL64(aScatter, 11U)) + 3199575576585871314U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 18U)) + 2533378188975571824U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 43U)) + 6819782112558312658U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aCross, 51U)) + 12690060987724798497U) + aNonceWordI;
            aOrbiterI = ((((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 7088375139715629606U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 17785618677423695666U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 6U)) + 1714999280296491277U;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 17611338506932491624U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 47U)) + 6475727359297421201U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 39U)) + 2347744591204119530U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 2739317903351401068U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 8663535261373274338U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8205245127823536479U;
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8916510616749754516U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3944805940148512932U;
            aOrbiterI = RotL64((aOrbiterI * 18082271583211389701U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14094751253118853302U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14094299829196076311U;
            aOrbiterG = RotL64((aOrbiterG * 6370012560657108493U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3940673811518673802U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3015106523254484839U;
            aOrbiterJ = RotL64((aOrbiterJ * 9655401190755573379U), 43U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 15404103131982599922U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1828655763233900875U;
            aOrbiterE = RotL64((aOrbiterE * 13024358077740310049U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1236981890899916502U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 18208975564570342697U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 4577109989465876801U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17882273895471449661U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16196010765612713713U;
            aOrbiterF = RotL64((aOrbiterF * 15624856645134182005U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14639250100311162559U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9139027997336903273U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1853126389565574293U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16848571995585465845U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 15901000078517800358U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11617866400577762383U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9405166641274108606U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6776079798531281127U;
            aOrbiterD = RotL64((aOrbiterD * 6914644957401512339U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15056085197286596847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3199575576585871314U;
            aOrbiterA = RotL64((aOrbiterA * 15940936753708416817U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 56U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + aNonceWordN) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 57U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterB, 37U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterG);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 54U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aNonceWordG);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterF) + aNonceWordB) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterE, 50U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25534U)) & S_BLOCK1], 24U) ^ RotL64(aFireLaneB[((aIndex + 22392U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 26751U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25985U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23431U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 22344U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 3U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (aWandererK + RotL64(aCross, 30U)) + 6361545377408870615U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 5U)) + 2967245486744774933U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 13U)) + 3836634268482850139U) + aNonceWordM;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 35U)) + 7691642115360086297U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 16479280384178279281U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 35U)) + 2901468732552539249U;
            aOrbiterB = (aWandererH + RotL64(aCross, 21U)) + 2600353867755647475U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 5666596904781510956U) + aNonceWordO;
            aOrbiterH = (aWandererA + RotL64(aScatter, 57U)) + 16108791609267427553U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 23U)) + 8389926875737312112U) + aPhaseEOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererG + RotL64(aCross, 51U)) + 1689501721163024426U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11721701506949917719U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3963842745030140473U;
            aOrbiterA = RotL64((aOrbiterA * 6692473494944919373U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2259725140963665123U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11652011949557979650U;
            aOrbiterB = RotL64((aOrbiterB * 11260100762113295037U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1116085424226174473U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 4725260319270802912U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 4697109059565450269U), 21U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 7348945429843437036U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1249234309180653260U;
            aOrbiterH = RotL64((aOrbiterH * 3136745255820405881U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12463505532573389603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2304125977906510386U;
            aOrbiterI = RotL64((aOrbiterI * 9960816714791454421U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2178037443783425551U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11712110130079307683U;
            aOrbiterK = RotL64((aOrbiterK * 9797864956200779505U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10703510612147312252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18155460326242413483U;
            aOrbiterG = RotL64((aOrbiterG * 6903953708987478723U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 5753486645345036069U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2314216774606770444U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 14002639533287566667U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9662599462788305323U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3805101172359199209U;
            aOrbiterF = RotL64((aOrbiterF * 10669315962181581543U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1073926575064224947U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6361545377408870615U;
            aOrbiterD = RotL64((aOrbiterD * 10685650563722188837U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterA, 4U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 38U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29516U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 29256U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28654U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30660U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((aIndex + 29628U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 19U)) + 7948891781097675369U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 36U)) + 13928362874228230226U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 10776180542602258926U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aIngress, 3U)) + 5735115172149470447U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 5353591822981766987U) + aNonceWordF;
            aOrbiterK = (aWandererF + RotL64(aIngress, 43U)) + 562301708107268570U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 11U)) + 10467810247578364868U;
            aOrbiterC = (aWandererH + RotL64(aCross, 13U)) + 14541630141152308564U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 50U)) + 2350076897065139429U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 17519109078651162228U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 41U)) + 6061035173339902910U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15654836633731000065U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13723521735153718904U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14459516479283070563U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2849680038315532197U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17336102435576647923U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7671010488872356142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11485114338165600777U;
            aOrbiterF = RotL64((aOrbiterF * 4162584865462407791U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 8759060657343458985U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11009137869375286581U;
            aOrbiterB = RotL64((aOrbiterB * 8741417343929809115U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15792999392743144135U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 361487389591183005U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15292753806514404853U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 17478232597253311153U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14929153438443362045U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterA = RotL64((aOrbiterA * 2484130486635511403U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3793180909904286848U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10391957637467171320U;
            aOrbiterK = RotL64((aOrbiterK * 505484041943467117U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11648765065563798353U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17601185776537566611U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4753179291885740011U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2907499704986356444U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17048858067202291241U;
            aOrbiterG = RotL64((aOrbiterG * 2607549567999666889U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4340465159886930775U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7948891781097675369U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 12913104720552907335U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterK, 26U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 37U)) + aOrbiterH) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aNonceWordA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_VolleyBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE4B265B16CED5D6BULL + 0xD5632053F88F69DAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x98FC32FE540D9C75ULL + 0xC713E8E918AC7EF0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xAD923DE4216FA5B1ULL + 0x9407D0AE9357D769ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x851DB5BF4DDD9D71ULL + 0xEFEE8E71621FAFDFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xED297D7E21C2E163ULL + 0xB0C7C031185E2243ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAE8D64886FAA8935ULL + 0xDFFA55F1FDAE779CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB8745756473C12AFULL + 0xA76B18D4496F398FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC6DAEB6D06B6B85DULL + 0xF9FB52AA69E78879ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD54E839380E9D861ULL + 0xDD9CA84A1135DEE6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDFEE9B786ED636A3ULL + 0xB75ED9A694B15348ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAC369F802EFB6459ULL + 0xF3388E13F32783EEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBC44DBB86B9F1DD7ULL + 0xB1A1CF7DF1D1AE39ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB303C0C729BCD665ULL + 0xE9BC5DC6100F243BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9438E3B72D395C15ULL + 0xFFD590D5B495E8AEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC4856EB5B637F5CBULL + 0x9DE2BA9DD54C682DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xBE34671CC4249229ULL + 0x9EBE89ED6A688AD9ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneC, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aWorkLaneC, aInvestLaneB, aSnowLaneD, aSnowLaneB, aExpandLaneA, aWorkLaneD, aExpandLaneB, aInvestLaneD, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 43U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 13U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3846U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3202U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4371U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 2412U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 13U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 29U)) + 12027839670755583592U) + aNonceWordL;
            aOrbiterH = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 15380130703509859843U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 38U)) + 4590907433867798074U) + aNonceWordG;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 47U)) + 1754574023602519724U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 9832756659564903767U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 5035088494491470403U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 24U)) + 14199170923323644638U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 43U)) + 8325619421264440438U) + aNonceWordH;
            aOrbiterA = (aWandererF + RotL64(aIngress, 53U)) + 969534320779067977U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 270575869402913847U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13344806516599578910U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10193544126281901579U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15143147951139409101U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14425582489214169238U;
            aOrbiterD = RotL64((aOrbiterD * 16893787086337916355U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13951127523239064584U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14177925225918293579U;
            aOrbiterB = RotL64((aOrbiterB * 13079514031864998485U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8258920744278218901U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7408161179397242453U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 975737128100519169U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8581481606764773468U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10078416198417433133U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 1102721083915858247U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18299772198826189580U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18304668908084397946U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 10589455451200578687U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16729632621573817223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13362300981585573239U;
            aOrbiterH = RotL64((aOrbiterH * 9824473895535518785U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8629682832849915380U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 6852852009091469641U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11912646687050011915U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7433098156961745198U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10931806208899417308U;
            aOrbiterK = RotL64((aOrbiterK * 14699197041038067483U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 42U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 10U) + aOrbiterI) + RotL64(aOrbiterH, 43U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterG, 52U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterI, 28U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 7328U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 10543U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10009U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 6078U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6804U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8251U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9803U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 15652862298542575895U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 47U)) + 16925323928418184554U) + aNonceWordD;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 24U)) + 4413861484961668394U) + aPhaseFOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 2215946422098155969U) + aNonceWordL;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 14975185533513111110U;
            aOrbiterF = (aWandererH + RotL64(aCross, 57U)) + 9711613814905834552U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 29U)) + 13154957291850149471U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 14U)) + 5058313016418534840U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 15011423472941211620U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2030053257469580168U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 150530795186791193U;
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10878237472104183427U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11724672539469573109U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 16158741837357985395U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9589700906445846956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1367381624958248949U;
            aOrbiterB = RotL64((aOrbiterB * 8459515089081211977U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 12003215666757518106U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11232479330848006729U;
            aOrbiterK = RotL64((aOrbiterK * 10993290955464593033U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13013910456628561621U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6092509838924105265U;
            aOrbiterF = RotL64((aOrbiterF * 805601154718006061U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11999225836250312801U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14421271973875748413U;
            aOrbiterD = RotL64((aOrbiterD * 9529010940887430157U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15536288285741825272U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2071793889925436679U;
            aOrbiterC = RotL64((aOrbiterC * 1526376970151714589U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5622386476463436967U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 16147972771639168516U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11826916832825159095U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4519892856053952290U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12059500374938843538U;
            aOrbiterG = RotL64((aOrbiterG * 14987533625537956299U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterB, 34U)) + aNonceWordM) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterI) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + aNonceWordN);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterI, 14U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordH) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterF, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 11703U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 14361U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 15523U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11681U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 14477U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererG + RotL64(aIngress, 58U)) + RotL64(aCarry, 41U)) + 9471546960258473684U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 5U)) + 18050235435948942244U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 53U)) + 3005107102671544641U) + aNonceWordC;
            aOrbiterA = ((aWandererE + RotL64(aCross, 21U)) + 17898396434573801850U) + aNonceWordD;
            aOrbiterI = (aWandererF + RotL64(aIngress, 37U)) + 15071602525497771648U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 27U)) + 5780119462702672108U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 13301326224151025687U) + aPhaseFOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 18129323022260575961U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 48U)) + 1199228670638790709U) + aNonceWordM;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1839199978088021020U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4999517042246790165U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 8788607633376516299U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15143903839930468749U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12735914889325422675U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16674732686428431869U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15908873150953195581U;
            aOrbiterG = RotL64((aOrbiterG * 18049755517524334107U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11204775359756474667U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2525984309543939465U;
            aOrbiterI = RotL64((aOrbiterI * 3988529812023791571U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4566345170476825512U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14876612901557406267U;
            aOrbiterJ = RotL64((aOrbiterJ * 9047956948845135339U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14926290877038883931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12710203178186614846U;
            aOrbiterA = RotL64((aOrbiterA * 14841163494801662515U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7315094513967387996U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11050116830482816766U;
            aOrbiterF = RotL64((aOrbiterF * 3702999495721152019U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 4505368486032503953U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17905748055257551092U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14775870175093453197U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5728886950801376350U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17998141690182325170U;
            aOrbiterB = RotL64((aOrbiterB * 16008599930125391379U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterB, 60U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 28U) + aOrbiterK) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 36U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 24U)) + aOrbiterD) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 21463U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneC[((aIndex + 19467U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 17675U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18376U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 17296U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 23U)) + 6068543441070417854U) + aNonceWordI;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 27U)) + 2995980468193441856U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 40U)) + RotL64(aCarry, 41U)) + 18020277482171594003U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 51U)) + 4293807434721230702U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 13U)) + 7980599111583893156U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 8593141111851052016U;
            aOrbiterD = ((((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 5903487523900084325U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 19U)) + 15112035513447930209U) + aNonceWordD;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 36U)) + 9854037263057006439U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16759760289688823193U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 12622628933030601390U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 2151912984825538321U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1264668857268123425U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16087995784896123610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7970269262800468363U;
            aOrbiterD = RotL64((aOrbiterD * 14924752223305807461U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5331477046030959632U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16534913204255550893U;
            aOrbiterG = RotL64((aOrbiterG * 1013433634373673565U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11042821902537871209U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8069677512345031660U;
            aOrbiterA = RotL64((aOrbiterA * 13622218526054132397U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5737130058129936372U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1076627182956662997U;
            aOrbiterK = RotL64((aOrbiterK * 14342191224014199929U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13911061091801078190U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 15397603151098990373U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 1802890451633592245U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15137326716738637972U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11248737008959896786U;
            aOrbiterC = RotL64((aOrbiterC * 90789374131547005U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1847847987633923657U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10560748778679145431U;
            aOrbiterJ = RotL64((aOrbiterJ * 2919333327817231099U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ);
            aWandererC = aWandererC + ((((RotL64(aCross, 53U) + RotL64(aOrbiterK, 14U)) + aOrbiterG) + aNonceWordM) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 10U)) + aOrbiterG) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24706U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 23755U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 22837U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22921U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneC[((aIndex + 22613U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 10U)) + 5041131702736607991U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 9295010428212681446U) + aPhaseFOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 35U)) + 6235875895358766017U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 47U)) + 2622227802531866918U;
            aOrbiterF = (aWandererG + RotL64(aCross, 19U)) + 3888894734834524972U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 23U)) + 241682012014701753U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 43U)) + 15758000422451568079U) + aNonceWordC;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 2061944548396976912U) + aNonceWordN;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 8177144990755754531U) + aNonceWordI;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 554978075608818497U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 250408260560714933U;
            aOrbiterH = RotL64((aOrbiterH * 1295379390497107727U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8700027645880997552U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10026130047465480902U;
            aOrbiterF = RotL64((aOrbiterF * 12417270861933696623U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 9785843014096326696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9998582683258411251U;
            aOrbiterI = RotL64((aOrbiterI * 7197956237569462269U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13817734599383455151U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 6647207154174092691U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 1578528131687283531U), 19U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 4957715980509035719U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4994885315786213197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5676683798126497011U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5072908311783966503U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5535039946192891515U;
            aOrbiterK = RotL64((aOrbiterK * 2989412783482309753U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6594577050344146271U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8750154123258714856U;
            aOrbiterG = RotL64((aOrbiterG * 6942158167127532003U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3514769314840874873U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8626045200273524281U;
            aOrbiterB = RotL64((aOrbiterB * 4315441782689789689U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8524870284841706517U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1841819423572964209U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 9802481758007234681U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 40U) + RotL64(aOrbiterI, 21U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 10U)) + aOrbiterF) + aNonceWordJ) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 52U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 50U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30689U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((aIndex + 29253U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 30631U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31626U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28700U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 4751694786009671052U) + aNonceWordF;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 19U)) + 16362725160370844224U) + aNonceWordH;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 6360885380915941057U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 5154536007972297036U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 4U)) + 9362540581874808253U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 27U)) + 13902493871525612934U;
            aOrbiterG = (aWandererF + RotL64(aCross, 11U)) + 10208452885367546542U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 23U)) + 3117030377279160998U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 60U)) + 17286247690414027870U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3930314320040949141U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7289525252391668404U;
            aOrbiterK = RotL64((aOrbiterK * 15452162299105112187U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3434167955466809185U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterE = RotL64((aOrbiterE * 1485660158767033425U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6137259687928853253U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13992510605237574698U;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6470556523400123474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4333255670390099293U;
            aOrbiterA = RotL64((aOrbiterA * 11089933812030082647U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7700424876430257995U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16920736951239453071U;
            aOrbiterF = RotL64((aOrbiterF * 8920407493132380497U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1635071690430295730U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9966700845966398620U;
            aOrbiterH = RotL64((aOrbiterH * 17210048121896546867U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9833458070123027075U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1990346556486746432U;
            aOrbiterD = RotL64((aOrbiterD * 8704943923474148699U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13339523466436517327U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5018264760406215603U;
            aOrbiterI = RotL64((aOrbiterI * 2769197961801783627U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 123427497520755346U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4535841104215792886U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1417676310539177131U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 44U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 18U)) + aOrbiterH) + aNonceWordD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 37U)) + aOrbiterF) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 58U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 14U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_VolleyBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC24EDE440BBA419DULL + 0xF314D1AD50718E9CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF300D0137B4EB729ULL + 0xA7FFDE6E50AA0EF4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9A18AFD679401DFFULL + 0xCA69DB1E8C196CEDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC1AC6AEF32C30949ULL + 0x87B9EA8B7E3555CAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB2C21F657F80BDDBULL + 0xC74D936C52198927ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC59193406E408049ULL + 0xD201A912B8B220A9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x98B90EFBFB05AD23ULL + 0xD70A3084869A8CAAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE6EDB27AA1EF9E15ULL + 0xA1F415726FBCB6ECULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x823D696D1BAC4DFDULL + 0xFA1AAD324EFF9454ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC4E78471B15CEE51ULL + 0xE4613126C39B2E6CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC1F7F5D7D71C208FULL + 0xB76C8FC787F2E347ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDBF30152205933CFULL + 0xA726A5924CB2BECEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD94BE8F4723ACB8FULL + 0xA30EEE173E8E8892ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA11461DE1D4C9301ULL + 0xAE11B83AD35ECFF5ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC51E9EDE68975F39ULL + 0xBA74545D73D04376ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD61803D4A7A2D7D1ULL + 0xCC64F72A1B8BE9A7ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneD, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aInvestLaneD, aInvestLaneA, aWorkLaneB, aFireLaneC, aExpandLaneA, aFireLaneA, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3540U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((aIndex + 1445U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 2765U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 5083U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 435U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3084U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 24U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 29U)) + 11700815697312060726U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 43U)) + 11808423452327465441U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 8670503858631730886U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 51U)) + 2400061067991988544U;
            aOrbiterK = (aWandererE + RotL64(aCross, 35U)) + 16163118178366229686U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 3280178595904941068U) + aNonceWordI;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 53U)) + 3298683600817047727U) + aPhaseHOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16321624053445183574U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6730229877611375225U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2022290495153519279U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10162830636713641322U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15646771327759599256U;
            aOrbiterF = RotL64((aOrbiterF * 15333053762177144775U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14841751262270544102U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9545541117228834895U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14676615635857599982U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1231768638470558855U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1945905595345404833U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1406171421638586846U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4577864352425476233U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1970292335806697198U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12309719390375013297U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 16540660957923687327U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5352135521358954576U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 15465675376193501658U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 16385761112921041387U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterH, 50U));
            aWandererC = aWandererC + (((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordN) + aPhaseHWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneA
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5767U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 9397U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10319U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneD[((aIndex + 8294U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8527U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10435U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 8726U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 48U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 23U)) + 4384716820085860551U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 9715780315942116888U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 35U)) + 15963520052789178632U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 14346700690686392938U) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 56U)) + 6005518012489966643U) + aNonceWordH;
            aOrbiterK = (aWandererC + RotL64(aIngress, 27U)) + 2506732930310252119U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 3U)) + 16782163084851775826U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 823673076571076303U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1634084509064077736U;
            aOrbiterI = RotL64((aOrbiterI * 1128407326773234517U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1288134975466877686U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2998220403162908444U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4321412662318298283U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 220430672180734911U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10223923547068528867U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 12577370238343872139U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11696469696177647608U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6545430420379636963U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 8387163146257553773U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 79691451831797107U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8971444023498649419U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7148919880477390009U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5624403902454498793U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9468064161002030997U;
            aOrbiterH = RotL64((aOrbiterH * 8243560528100864595U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4619361544913629805U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 12682446273369750704U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 34U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aPhaseHWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 20U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 50U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + aNonceWordO) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15583U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 12900U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15000U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14270U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11616U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 36U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = ((((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 15188686795415908074U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 17310049041983079779U) + aNonceWordL;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 8246925977992441471U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 57U)) + 8644260919918112781U) + aNonceWordB;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 20U)) + RotL64(aCarry, 53U)) + 13401663736874819483U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aIngress, 35U)) + 7940358935238314973U;
            aOrbiterC = (aWandererI + RotL64(aCross, 5U)) + 13278990328548007839U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11346868298353840706U) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2374077904806833579U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 1765686942154321425U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 6978903378645019166U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11951633297870965212U;
            aOrbiterI = RotL64((aOrbiterI * 12778236598654492185U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17398460995357409673U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1215437945597836770U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9322970054123481621U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1878751468043972239U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5343002808239712390U;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9884918450053276861U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 15894599082080422550U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8359936745539546131U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13917339232771145459U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 18101134009493720683U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15835859435306756387U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3830086372356903769U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15894394599564584010U;
            aOrbiterA = RotL64((aOrbiterA * 9513921913446609263U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 40U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterG, 58U)) + aOrbiterI) + aNonceWordI);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordP) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aPhaseHWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16631U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 17928U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 16610U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21380U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneD[((aIndex + 17384U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 40U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererG + RotL64(aIngress, 60U)) + 11410829607777684449U;
            aOrbiterA = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 7502698839700975347U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererJ + RotL64(aCross, 5U)) + 13267685058252106173U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + 238242706996630625U) + aNonceWordE;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 8184695499511454281U) + aPhaseHOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 53U)) + 12767823220461985403U) + aNonceWordH;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 12293198423143850330U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11149495229952495939U) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7556992689338382800U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18232398462716803063U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3431338808774134649U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16863099140844995099U;
            aOrbiterA = RotL64((aOrbiterA * 752376661101787919U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17872458049880677604U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16760153457252546974U;
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3115544493537438408U) + aNonceWordN;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 4359882942759752958U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 561477566995575801U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13387113067202396536U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12955690074544490161U;
            aOrbiterK = RotL64((aOrbiterK * 12449941770827974511U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15614054443728226807U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1939441328066616114U;
            aOrbiterD = RotL64((aOrbiterD * 4484917074808974359U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4599016263007782537U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9962305629016158048U;
            aOrbiterI = RotL64((aOrbiterI * 1496184427500037279U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 43U)) + aNonceWordL);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 20U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27139U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 25102U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23484U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24818U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21977U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 21U)) + 12690502671561165478U) + aNonceWordM;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 17519943923428102801U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 10705515807975331385U;
            aOrbiterF = (((aWandererE + RotL64(aCross, 50U)) + RotL64(aCarry, 53U)) + 16586447272278538179U) + aNonceWordL;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 35U)) + 8006560996840971798U) + aNonceWordB;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 3U)) + 12928600185788857701U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + 14240723153798267172U) + aPhaseHOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 8636219177994872072U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7586790235186467512U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15052686382507614169U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1103807034179512424U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 8380239679344786397U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5690809173787433519U;
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 8390902801141804609U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3507306189192059486U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18336280496510253103U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6190745292098482871U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8065418693975056902U;
            aOrbiterF = RotL64((aOrbiterF * 6414621418430102589U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12111755051718111803U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7605877769709909297U;
            aOrbiterJ = RotL64((aOrbiterJ * 17525248694315944599U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5969794501112646237U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5127559299360591476U;
            aOrbiterA = RotL64((aOrbiterA * 4521563633438853069U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 58U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 42U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 13U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            aWandererG = aWandererG + ((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            aWandererE = aWandererE ^ ((((RotL64(aCross, 41U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + aNonceWordA) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29517U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 27488U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 31744U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28815U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28192U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 9435962834163239322U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 11U)) + 10524704356081318973U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((((aWandererJ + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 7403401305665208680U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 7525414805023556493U) + aNonceWordJ;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 35U)) + 1116686470029070951U) + aNonceWordB;
            aOrbiterF = ((aWandererB + RotL64(aCross, 27U)) + 13257612299137802420U) + aNonceWordA;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 44U)) + 9181543003986598283U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9739384852307501107U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11308402900229016057U;
            aOrbiterB = RotL64((aOrbiterB * 12690186771773188967U), 3U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterB) + 14935167593705272337U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7171824007631943535U;
            aOrbiterC = RotL64((aOrbiterC * 4839974427616194289U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8068411284829563567U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12350207458513447578U;
            aOrbiterI = RotL64((aOrbiterI * 813973258659041895U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17039236343991574134U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 18291683592714999632U;
            aOrbiterF = RotL64((aOrbiterF * 7771718817924840713U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 6239616841884430968U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10604527977569876774U;
            aOrbiterJ = RotL64((aOrbiterJ * 6972820410084939637U), 29U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 1707724300671717658U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3802268808625297647U;
            aOrbiterG = RotL64((aOrbiterG * 11296811630387191563U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9423064323799920219U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 242153923313096551U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12117679073775630197U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 38U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterG, 30U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterG) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterI, 57U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_VolleyBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 220U)) & W_KEY1], 10U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 966U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 874U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 71U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 57U)) + 10915618884692072446U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 28U)) + RotL64(aCarry, 21U)) + 12634922308499254909U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 43U)) + 6533934734564499389U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 6744203303756105181U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 13086782386652045658U) + aPhaseAOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + 5693840533331397822U) + aPhaseAOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 53U)) + 1803663542535024611U;
            aOrbiterB = (aWandererK + RotL64(aCross, 18U)) + 3597219300593287708U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 13U)) + 1429753448204448904U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17229017825587322715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1137574712801062932U;
            aOrbiterK = RotL64((aOrbiterK * 3645832160939819415U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2401991077004083378U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1332473247826139292U;
            aOrbiterC = RotL64((aOrbiterC * 15029831858261506447U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11730946340796899885U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15319163439700390962U;
            aOrbiterB = RotL64((aOrbiterB * 1349242001887975499U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 4744141870145159917U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6067132201862688684U;
            aOrbiterG = RotL64((aOrbiterG * 6046100687757836027U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14991509179286371800U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4342608825699398682U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10240526103933275875U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3727521409410742075U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3302027219498304367U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12153634588200479559U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6039539483340398858U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2902581519976937051U;
            aOrbiterA = RotL64((aOrbiterA * 2057584328877854239U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12332784713738947242U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13761272577223712786U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14930145045480030821U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2947946397617043735U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11107014023853644521U;
            aOrbiterD = RotL64((aOrbiterD * 15030903626191481831U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 6U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterC, 43U)) + aPhaseAWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 36U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5307U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4809U)) & W_KEY1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5413U)) & W_KEY1], 34U) ^ RotL64(mSource[((aIndex + 3394U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 53U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 9107326720193244489U) + aPhaseAOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 37U)) + 10868585484401664145U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 23U)) + 13637736741437846622U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 6130725216183918844U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 35U)) + 2063834478521338187U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 39U)) + 8564870627911949158U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 5U)) + 6524015751064086390U;
            aOrbiterK = (aWandererE + RotL64(aCross, 29U)) + 9874937766875388236U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 44U)) + 14723718409522680894U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13767059954741528279U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6387608251033722169U;
            aOrbiterF = RotL64((aOrbiterF * 6601902195707980693U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5391425980008431000U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11524218415655093779U;
            aOrbiterC = RotL64((aOrbiterC * 12508457981779189389U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 155510463350385905U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10554591788433641311U;
            aOrbiterI = RotL64((aOrbiterI * 5412084824127934293U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8662160162966241542U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5092555636369853727U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7163345798448796101U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 695089002178413267U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17302689458565434475U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5409173939213468972U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15349690077393827541U;
            aOrbiterG = RotL64((aOrbiterG * 10984681254001609841U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12376011890751302027U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7809614158898158383U;
            aOrbiterB = RotL64((aOrbiterB * 13845113198736843629U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13031938699536449576U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3983178190194056516U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1341678482929213405U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5567935037909671790U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17137042627663349797U;
            aOrbiterJ = RotL64((aOrbiterJ * 13535586899620672373U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 42U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterI, 34U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 57U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterC, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 18U) + RotL64(aOrbiterB, 39U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 28U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7263U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadB[((aIndex + 6657U)) & W_KEY1], 58U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6116U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6382U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5501U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aCross, 13U)) + 16424657151168221875U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 6U)) + 17150123681886380361U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 16041993588694572757U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 9871185846434828537U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 35U)) + 11227236398354430757U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 43U)) + 5399325217402192631U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 57U)) + 9248828789282890454U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 23U)) + 9041370494203701062U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 14944424084524970764U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5481938174456671041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14783648629543752715U;
            aOrbiterD = RotL64((aOrbiterD * 7260164783191886395U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12355573914530445723U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9863991559011968318U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16149688605937250965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 106041828692026825U;
            aOrbiterG = RotL64((aOrbiterG * 12199934305374582599U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8076098639554567792U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11155119311895580013U;
            aOrbiterI = RotL64((aOrbiterI * 1495180896564818647U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6847612160595917702U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16094377920388017367U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875801863643206333U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13584719866672696684U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13446209321646234607U;
            aOrbiterE = RotL64((aOrbiterE * 9945349065094781529U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15829806645369560988U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12573767256739062550U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5649504278826069077U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3850030870300393809U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11857593987748189858U;
            aOrbiterB = RotL64((aOrbiterB * 15942863910931814193U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5505918410521728373U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12949653497121247860U;
            aOrbiterH = RotL64((aOrbiterH * 90944913639560027U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 48U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aScatter, 24U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 27U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aCross, 58U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 34U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9845U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 8253U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 8950U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 8268U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10784U)) & W_KEY1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9171U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aCross, 41U)) + 2571116506511057880U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 13112435411509707292U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 10U)) + 10403251762787357256U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 19U)) + 8461951095541400405U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 9890793478557463815U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 5U)) + 3030229465991783707U) + aPhaseBOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 7273848154043719247U) + aPhaseBOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 51U)) + 10681774862516028276U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 7105082755586853104U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6588579345319551129U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14616333550242386092U;
            aOrbiterF = RotL64((aOrbiterF * 2934574715879306337U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15439666290229654921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3360304356760164799U;
            aOrbiterA = RotL64((aOrbiterA * 5164191920584106237U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14438730801970761889U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14515616787452085729U;
            aOrbiterH = RotL64((aOrbiterH * 2041601927968559821U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4167853822635132419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8950982233003320239U;
            aOrbiterD = RotL64((aOrbiterD * 887144270884244907U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12391327853728029953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7100871010552394421U;
            aOrbiterG = RotL64((aOrbiterG * 16552349374101955967U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15381697462381887944U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6801677551341079401U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13325954438427340703U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 947011315719204867U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6356920162398333481U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5566721941682667419U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8910262020598577378U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8778455415977526457U;
            aOrbiterC = RotL64((aOrbiterC * 4092470497616637283U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5585696961453127223U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 9670655481681494412U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7863197168965036383U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 42U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterB, 58U)) + aPhaseBWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + aPhaseBWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 42U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterG, 51U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13110U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[((aIndex + 11996U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11952U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 11578U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13372U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13096U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 11098U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aCross, 39U)) + 7893287783892523139U) + aPhaseBOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 24U)) + 10257331997383491153U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 14562226733652231753U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 47U)) + 14320342577110737851U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 9816717579822880756U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + 9558926960095881953U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 43U)) + 9230371862654338324U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 56U)) + 6414274291252913420U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 13868546184398350849U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16940736952569949038U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2866957764814864371U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3554702178644797003U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7916721976073979724U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1602444214978842275U;
            aOrbiterJ = RotL64((aOrbiterJ * 11072503711308122385U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9529061385251008037U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8402775110887376588U;
            aOrbiterD = RotL64((aOrbiterD * 13980225144628227381U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15003592180290390713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14195681406520825751U;
            aOrbiterB = RotL64((aOrbiterB * 11455000833788877217U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3263577002367714202U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12019422062655581928U;
            aOrbiterK = RotL64((aOrbiterK * 5002313835338447799U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8508638054582582917U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6536618106353552880U;
            aOrbiterF = RotL64((aOrbiterF * 6233964121117511885U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9654542989321430868U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7019594782797863244U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1234877854354279981U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8256061220727519919U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9232754129467036130U;
            aOrbiterA = RotL64((aOrbiterA * 17556001874302369781U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5608829951337740378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12632120498473345701U;
            aOrbiterH = RotL64((aOrbiterH * 6994794653605831925U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterF, 48U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterC, 10U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 23U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14840U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15526U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14293U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13766U)) & W_KEY1], 6U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15739U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14569U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14769U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aPrevious, 52U)) + 8685374557928800912U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 11U)) + 3482312691892161229U;
            aOrbiterC = (aWandererI + RotL64(aCross, 37U)) + 6948130297389161165U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 5506385663788942690U) + aPhaseBOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 17859982009307397161U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 9178488809207094043U) + aPhaseBOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 23U)) + 1835479501226057169U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 41U)) + 5368101733632614939U;
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 9050459666576835422U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9042186993119635078U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 17528342580198295025U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14316671546614386775U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6495418332558436882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8834495762667327342U;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 4364314196965690905U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6357485231062120459U;
            aOrbiterE = RotL64((aOrbiterE * 289429584586504995U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3321488322626415347U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10817330671781848737U;
            aOrbiterG = RotL64((aOrbiterG * 15875919466358823335U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17974092279281611763U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 2871472057292789157U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16104199340711015181U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15187929795092006849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13482063681546475923U;
            aOrbiterJ = RotL64((aOrbiterJ * 14466266308157364963U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6232152545071397380U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 17488906002621373262U;
            aOrbiterH = RotL64((aOrbiterH * 4719340606442742577U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12444819880507588549U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13808941689757772497U;
            aOrbiterI = RotL64((aOrbiterI * 6541360905282412317U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8049361354387692374U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7137831335606542401U;
            aOrbiterF = RotL64((aOrbiterF * 11022231291507235007U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 4U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + aOrbiterB) + RotL64(aOrbiterH, 48U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16986U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 17505U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(mSource[((aIndex + 18295U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17871U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17802U)) & W_KEY1], 3U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17586U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18851U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 6318740973868639425U;
            aOrbiterK = (aWandererD + RotL64(aCross, 42U)) + 5487840061430920881U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 29U)) + 10258706763248072672U) + aPhaseCOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aScatter, 13U)) + 18356875269730338208U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 35U)) + 12883160282903147010U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 23U)) + 1010140474942697730U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 52U)) + RotL64(aCarry, 35U)) + 17733939421700898293U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 47U)) + 13693055887924981201U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 14574732452793385269U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10832873941223609012U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8212600587135328040U;
            aOrbiterE = RotL64((aOrbiterE * 5334613996794796145U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5312744319781971178U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6173741211706546923U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12854414066390848249U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3693249147883790810U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 18365859989736602556U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3348463719324104997U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10645056678337549771U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1175668356822251045U;
            aOrbiterH = RotL64((aOrbiterH * 6579675292775345579U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13556844570541823717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4790355739411849736U;
            aOrbiterG = RotL64((aOrbiterG * 4083544011788850307U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14905575502272644116U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17047244574558476634U;
            aOrbiterB = RotL64((aOrbiterB * 2356386971503880047U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10161614295718414869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13413914082651612468U;
            aOrbiterC = RotL64((aOrbiterC * 16224039093981079491U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6072693130156927774U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4333656233793103787U;
            aOrbiterA = RotL64((aOrbiterA * 9374745547133955709U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17209776289202130250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11752001118070361543U;
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 22U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterG, 14U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 48U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21219U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 20679U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20910U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19770U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19676U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20219U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21459U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20808U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 50U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aPrevious, 19U)) + 1210605127156905516U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 11964595428173569519U) + aPhaseCOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aCross, 34U)) + 16277319029916258482U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 12369497463101824572U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 6201248574067068202U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 13U)) + 1727477025667206661U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 60U)) + 1404510627789806851U) + aPhaseCOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aIngress, 3U)) + 6948213591282018925U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 6688865181284421478U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3351130769402360855U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12681032488906270823U;
            aOrbiterJ = RotL64((aOrbiterJ * 3680893896579741263U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3591412591193726763U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16153817571210878589U;
            aOrbiterB = RotL64((aOrbiterB * 4165137036092246349U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 3808228354421006630U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1427373776207504205U;
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1831554180932501132U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1114853085120949215U;
            aOrbiterE = RotL64((aOrbiterE * 4264176108298812905U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2080935638828366835U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16104777999646489828U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15205199362011777473U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9782806013673440791U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3721620299829386454U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6286765834910272409U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4013706412064296527U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5751022780695158579U;
            aOrbiterF = RotL64((aOrbiterF * 13766736471646116397U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17684546333240329338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1106947111128020920U;
            aOrbiterI = RotL64((aOrbiterI * 3158839453318658951U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11564229705849500598U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1585817314460274286U;
            aOrbiterH = RotL64((aOrbiterH * 12687162159791577431U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 14U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 12U)) + aOrbiterJ);
            aWandererA = aWandererA + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 52U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24206U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 22250U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22101U)) & W_KEY1], 27U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23838U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21994U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24514U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23285U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneB[((aIndex + 23946U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 50U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 6U)) + RotL64(aCarry, 11U)) + 12046647397183218524U;
            aOrbiterK = (aWandererG + RotL64(aCross, 35U)) + 2760779375026461991U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 13735454443176855650U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 4370377000586647724U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + 14566322384189969094U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 43U)) + 5056565959818422786U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 13U)) + 8795403810686579209U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 30U)) + 9625947666256011567U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 19U)) + 1703669290934254701U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6664070663184147951U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2104148316797553431U;
            aOrbiterH = RotL64((aOrbiterH * 12887842067180975983U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1197910004222596145U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9922977170060903197U;
            aOrbiterD = RotL64((aOrbiterD * 13047828062605568603U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2048376210852567829U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12568990647075931409U;
            aOrbiterI = RotL64((aOrbiterI * 9860242601194210927U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15026894775772902751U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3439447160137900629U;
            aOrbiterF = RotL64((aOrbiterF * 1813754963043785165U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6532671388552829796U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17261098369835997661U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 568292591215203521U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3171300991007459947U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5935563269327662024U;
            aOrbiterA = RotL64((aOrbiterA * 11271790283157765003U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14290941734320455612U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12371794745736518824U;
            aOrbiterG = RotL64((aOrbiterG * 12208762336145168647U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8782840145467637373U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4067525421190366741U;
            aOrbiterJ = RotL64((aOrbiterJ * 6671002797916227485U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11854812920571789853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17564890418553131451U;
            aOrbiterK = RotL64((aOrbiterK * 16657184504366731805U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 22U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 18U) + aOrbiterA) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterH, 14U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterA, 10U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26947U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 26924U)) & W_KEY1], 40U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26869U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27110U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25052U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26314U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25079U)) & S_BLOCK1], 44U) ^ RotL64(aInvestLaneB[((aIndex + 25217U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 4U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 6381335981879993247U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 56U)) + RotL64(aCarry, 39U)) + 15595429101600023172U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 37U)) + 5449234297249826461U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 51U)) + 11213734849329731168U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 13U)) + 16438473952464514248U) + aPhaseDOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 7357872882115186976U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 18U)) + 394402075160738643U;
            aOrbiterE = (aWandererA + RotL64(aCross, 43U)) + 11112941985410283532U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 14955125011182736212U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14770727009821304070U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11286366598129204910U;
            aOrbiterF = RotL64((aOrbiterF * 15884310771003021989U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7358400908565425780U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15635109923749114761U;
            aOrbiterG = RotL64((aOrbiterG * 12415152149408700329U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13826842523738623579U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1072811298828325231U;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4017334196009350776U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8812213572751410831U;
            aOrbiterA = RotL64((aOrbiterA * 12744171921566782795U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6723457786170634403U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9785583533999417673U;
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10265132640322153964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8435670887514808087U;
            aOrbiterE = RotL64((aOrbiterE * 2706263045620662131U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4303823386961718326U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4214384238167491037U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8490707334221154005U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8740835037840799136U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5988815405391206280U;
            aOrbiterK = RotL64((aOrbiterK * 17838555472135715929U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15539461383052981747U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 3743772525784217714U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6352086797545969187U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 40U) + aOrbiterG) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 48U) + aOrbiterG) + RotL64(aOrbiterK, 6U));
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29301U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 29037U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29859U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27814U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29949U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28988U)) & S_BLOCK1], 41U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28309U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28235U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 6069475454765660321U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 11483704742497268068U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 44U)) + 11055697447388986418U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 13U)) + 10897095046039997004U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 3U)) + 4731637118230457840U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 13855839187084986751U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 24U)) + RotL64(aCarry, 37U)) + 5328208115460188239U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 57U)) + 12479538544291412985U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 53U)) + 10740165998792608231U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6492798157284955373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13056825957483891921U;
            aOrbiterB = RotL64((aOrbiterB * 14882112110627751751U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2068184064919194657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5656302738780746294U;
            aOrbiterC = RotL64((aOrbiterC * 16493021179127646345U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 11193756120230763294U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17306750816837208999U;
            aOrbiterE = RotL64((aOrbiterE * 7949360041241439741U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12952818800389361804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15380412293642628312U;
            aOrbiterA = RotL64((aOrbiterA * 2914662289178925547U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7706090204767242996U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14598802276412649570U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4821408736292041399U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17819762117328075515U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6481384240915075101U;
            aOrbiterF = RotL64((aOrbiterF * 4836701121865783029U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 754936290510338717U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15510875946573720154U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2994718968852184303U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9245381722813944586U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2629847912019726214U;
            aOrbiterG = RotL64((aOrbiterG * 6718795794951106961U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3909987749797113773U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9277056074757335265U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11580847505996697115U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 47U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 30U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 50U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 26U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32463U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 32007U)) & W_KEY1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32408U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30409U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30882U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31598U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 11U)) + 3105313968748067810U) + aPhaseDOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 52U)) + 9977249451119627064U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 35U)) + 17941392803495349366U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 3U)) + 4279533326705471133U;
            aOrbiterH = (((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 13983828966811580039U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 3983490984234810378U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 29U)) + 308786542215259956U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 57U)) + 8443607695364427037U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 18U)) + RotL64(aCarry, 37U)) + 14939626441464340668U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9350693577306121110U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1717071159396961752U;
            aOrbiterJ = RotL64((aOrbiterJ * 11062480662625054525U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15911765265202100610U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14898546272333182767U;
            aOrbiterF = RotL64((aOrbiterF * 2674900543810733067U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3560903518513465868U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5367062725726860234U;
            aOrbiterB = RotL64((aOrbiterB * 8521908836601319553U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15233321480618877327U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9288449812290126074U;
            aOrbiterA = RotL64((aOrbiterA * 6815298520404038519U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5504840529511585676U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6825598386801620046U;
            aOrbiterE = RotL64((aOrbiterE * 11666542445846250077U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6433024450721339470U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 97934156644929458U;
            aOrbiterC = RotL64((aOrbiterC * 8630530773006923215U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3260053604798744515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16539416623243059076U;
            aOrbiterD = RotL64((aOrbiterD * 12199577351166064503U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9814290051339038920U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13280156404507444041U;
            aOrbiterH = RotL64((aOrbiterH * 15269010043398910061U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11853942590993546833U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13207869904312989977U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15503461937625795969U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 52U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 36U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 34U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 4U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererG = aWandererG + (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneA, aInvestLaneD, aFireLaneC, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1823U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 1657U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 1314U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1612U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 3673U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 21U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 6771552164800695068U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 21U)) + 12131763371571322040U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 10U)) + 3326182381395522013U) + aPhaseEOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 3U)) + 12288775097697156383U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 5195948373449796741U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 27U)) + 14404044002250137144U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 11142382920035825426U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2967149520256475485U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1470907369577818097U;
            aOrbiterH = RotL64((aOrbiterH * 9398653295177725883U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9231668148004163910U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13078929163913892386U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7509829068700523627U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9485274692075657877U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12216951187543631673U;
            aOrbiterF = RotL64((aOrbiterF * 6571066246507310805U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6933334652581744234U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17260276102423580920U;
            aOrbiterA = RotL64((aOrbiterA * 7796879893790990605U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 387767848169714392U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8597538259308082638U;
            aOrbiterD = RotL64((aOrbiterD * 4888054690557707241U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7996708724489146033U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15357384191688149939U;
            aOrbiterC = RotL64((aOrbiterC * 9827691726832491373U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17739222908739454637U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1614322333281471170U;
            aOrbiterG = RotL64((aOrbiterG * 7063116837752240891U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterG, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 4U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 10144U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 7911U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5480U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8699U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((aIndex + 10890U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 37U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 27U)) + 13714409587461539863U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 14101156723903265839U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 7063754562895369001U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 37U)) + 12320578575245519386U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aPrevious, 3U)) + 11744826789631008424U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 8744816505096675597U;
            aOrbiterA = (aWandererB + RotL64(aCross, 51U)) + 10405435520084528645U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1463157688070683543U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12379603577919617703U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14858901470015109311U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1343439118031348146U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16118850268070235540U;
            aOrbiterC = RotL64((aOrbiterC * 11184386483735388257U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14116264435819277136U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5251698273012432109U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1495818611622063967U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14806408656041403829U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11569345414052398227U;
            aOrbiterH = RotL64((aOrbiterH * 9913158908301414861U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17063874769147888574U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9927420478679581917U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9042782809534196563U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2550285599827162167U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17801534123304996448U;
            aOrbiterF = RotL64((aOrbiterF * 2160836889363614721U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6456685241021762041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17064208177372969289U;
            aOrbiterA = RotL64((aOrbiterA * 13726627607233302493U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 37U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 58U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 3U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterF, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 13790U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 13395U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 14855U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13238U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14598U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15128U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) + RotL64(aCarry, 57U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 50U)) + 7722279280863371124U;
            aOrbiterF = (((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 11584220561732385598U) + aPhaseEOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 7834679350105534657U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 11347994382444180879U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 41U)) + 9449903188047063431U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aCross, 57U)) + 6516243976652795170U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 21U)) + 8420815253991184777U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9081386852515170937U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14375955191735286867U;
            aOrbiterE = RotL64((aOrbiterE * 2772840314542262283U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 880757589768436072U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3349856625725164229U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 681514212582331781U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7826309957607577207U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8057435761214313635U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4718430712767038607U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9565237500443303103U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterD = RotL64((aOrbiterD * 8457633439171452397U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3276844534476430842U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6828644383891274120U;
            aOrbiterH = RotL64((aOrbiterH * 979580351653410157U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2815676923011504251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5030251870850928417U;
            aOrbiterA = RotL64((aOrbiterA * 7075653570570819253U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13464083008377887034U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8994560761846897590U;
            aOrbiterC = RotL64((aOrbiterC * 9892839554658865143U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterF, 14U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18266U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 21740U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 17329U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19578U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18763U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21138U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 18U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 5173905450211892891U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 3555542451908039957U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 3U)) + 11559884700283861559U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 1352524329968738673U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 41U)) + 8914206450420616349U) + aPhaseEOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 47U)) + 2251523378498463946U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 24U)) + 9541575923299247038U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1239854507907214595U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17698101462598498934U;
            aOrbiterC = RotL64((aOrbiterC * 2304948713665996433U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 12305566971683256060U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13804545036303215569U;
            aOrbiterG = RotL64((aOrbiterG * 10359543704152744971U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10239749097704329264U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4212214906286320308U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3661436621615751071U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12192418916967430783U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4475514289326450361U;
            aOrbiterK = RotL64((aOrbiterK * 17497164630368757887U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17376102613298827459U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 18129393209955439341U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6404089025014118979U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4014763724300253568U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17325007199676828814U;
            aOrbiterD = RotL64((aOrbiterD * 1420888274815627083U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15480474849292388685U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14357924730184375449U;
            aOrbiterE = RotL64((aOrbiterE * 16723492259068034209U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterF, 56U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23594U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 25168U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 22282U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25971U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23071U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23256U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 6U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 3973833383430652211U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 29U)) + 5760227042747169187U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 57U)) + 4923009065139227286U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 57U)) + 1477807307009107590U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 14U)) + 5707194514329007301U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 23U)) + 5340439728375269724U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 17080457898946572387U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 281559150259472813U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16160633048230910560U;
            aOrbiterG = RotL64((aOrbiterG * 16883442583309073785U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9003989610509592121U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10579322462808454333U;
            aOrbiterE = RotL64((aOrbiterE * 100832431598087235U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 15059383289528723069U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10417647757852880956U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 14484665027393813330U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12344463053485837974U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5762654194001525041U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5826453246659297805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 12547902286376986223U;
            aOrbiterB = RotL64((aOrbiterB * 2982850000322672789U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9637855144278126174U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2132744427444501938U;
            aOrbiterC = RotL64((aOrbiterC * 5911587798564836199U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9248933938130311231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13274297928717090383U;
            aOrbiterK = RotL64((aOrbiterK * 2901398809555237563U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29610U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 28745U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31583U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32712U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30087U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30682U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCarry, 60U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererG + RotL64(aCross, 43U)) + 6163290588946759209U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 7342672468560105447U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + 11574563167017282321U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 50U)) + 2254820206194758964U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 1469783447473099498U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 14174828900676165088U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 11U)) + 16277954291890598132U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14845750668693136766U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 150099699692047766U;
            aOrbiterG = RotL64((aOrbiterG * 7644895634421086357U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1200784917165131703U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9469982764806754302U;
            aOrbiterI = RotL64((aOrbiterI * 17851969334511301943U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10956702761701710182U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7915506894975487807U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17335794183733623213U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 557028996286989506U;
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1597385667771002414U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4376417959915162639U;
            aOrbiterF = RotL64((aOrbiterF * 4626236858205178149U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 549770198518993876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 756554555648070919U;
            aOrbiterB = RotL64((aOrbiterB * 16272320259614325355U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7298557532533152193U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3336802611342112013U;
            aOrbiterE = RotL64((aOrbiterE * 14679103452120080499U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 11U)) + aOrbiterG);
            aWandererH = aWandererH + ((((RotL64(aCross, 52U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterB, 60U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_VolleyBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aInvestLaneD, aExpandLaneB, aSnowLaneB, aExpandLaneD, aWorkLaneA, aInvestLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aInvestLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2699U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 5425U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2004U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 784U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1212U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 5171U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 43U)) + 1557680213571812384U;
            aOrbiterF = (aWandererC + RotL64(aCross, 10U)) + 7387349725778021121U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 15379264067601586976U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 3730195724576043708U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 5U)) + 9637070085323827066U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 56U)) + 1170865717363676184U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 13U)) + 2750833653175252030U;
            aOrbiterI = (aWandererF + RotL64(aCross, 47U)) + 15118992811225568305U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 4974092922102988451U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 10625719096296719514U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 39U)) + 855167122475471865U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11322911068958340262U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4334591909425429835U;
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14263701737208936392U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 678723206735649084U;
            aOrbiterE = RotL64((aOrbiterE * 10823239851733632227U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15652053114252065230U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1705225940224061401U;
            aOrbiterB = RotL64((aOrbiterB * 3626023093533713579U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6826394665732900206U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11902946775066981141U;
            aOrbiterC = RotL64((aOrbiterC * 18300629262162694137U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9802212958998591310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14001358545610206524U;
            aOrbiterD = RotL64((aOrbiterD * 13172645840788327099U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4299184726135884309U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7288757011999872416U;
            aOrbiterI = RotL64((aOrbiterI * 16806027820468277393U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 233801262480580205U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 14208660347238680268U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6299693448313154603U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9217797359740446104U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 18165073197136050838U;
            aOrbiterH = RotL64((aOrbiterH * 11677479094709512887U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9101905235436427482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2884224555227870272U;
            aOrbiterK = RotL64((aOrbiterK * 12085235281782370391U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13118509728421714433U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1385390888603164704U;
            aOrbiterG = RotL64((aOrbiterG * 6927424835779289199U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 9621084561183039538U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1557680213571812384U;
            aOrbiterJ = RotL64((aOrbiterJ * 3202327770291862207U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 38U) + aOrbiterE) + RotL64(aOrbiterC, 24U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + aPhaseFWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterF, 26U));
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterG, 37U)) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7180U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 6051U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5971U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((aIndex + 6902U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5521U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7302U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8742U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 29U)) + 4848316479321533394U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 6919360256662636195U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 29U)) + 9897013582181108544U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 51U)) + 7319353809896158678U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 23U)) + 2848175435514849859U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 34U)) + 6967780718720437934U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 21U)) + 10143884766603388136U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 5U)) + 8675965006150972051U) + aPhaseFOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 27U)) + 16350117755560994281U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 57U)) + 17976597517118423760U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 1399631141355370237U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3590613762034716792U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 5134624314245932157U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13077589037975283371U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10082236952942943654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4015535035905433450U;
            aOrbiterK = RotL64((aOrbiterK * 4961808568701908559U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 611474103801573800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5786708483794098001U;
            aOrbiterC = RotL64((aOrbiterC * 7694007039340089267U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5201943497363274455U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9282160506938328489U;
            aOrbiterA = RotL64((aOrbiterA * 5368182164239021367U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4932320527498940158U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11576526341731392916U;
            aOrbiterD = RotL64((aOrbiterD * 1712051774729439363U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10790691517638887125U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16280649213607464422U;
            aOrbiterJ = RotL64((aOrbiterJ * 10756733801499471873U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 9553716940667712810U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11827518270964003341U;
            aOrbiterI = RotL64((aOrbiterI * 1322489827908132831U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16777463701235809321U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3375489084588454149U;
            aOrbiterH = RotL64((aOrbiterH * 3335010977457647307U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 8129898095524287632U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14496406641486541929U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10077246205532940301U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17968163292907132345U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2431407778543471402U;
            aOrbiterG = RotL64((aOrbiterG * 407105842057624537U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18330313613898211889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4848316479321533394U;
            aOrbiterE = RotL64((aOrbiterE * 3462735144109152811U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 42U) + aOrbiterA) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterK, 44U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 52U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterH, 52U)) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneD
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneD forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 14232U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 12198U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 14004U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16065U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 10981U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 6U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aCross, 29U)) + 6243113109470883144U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 26U)) + 3891552123999605832U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 8758797898587019128U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 1005891374086408851U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 23U)) + 3713426782180050764U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 39U)) + 18358143862391573534U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 13U)) + 17504394029693712404U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 5312729289027417014U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 53U)) + 2560873623431186029U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 48U)) + 16309322822806704211U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 10195513918020652600U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2552116263258744287U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7732784879810980089U;
            aOrbiterG = RotL64((aOrbiterG * 15041929399477790999U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16499127570665381507U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10890036715535519036U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9065115450010475187U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16288944603478791554U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14542766121469312846U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8435383464425875209U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5973595239494084696U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1820492719977197097U;
            aOrbiterD = RotL64((aOrbiterD * 16164917159141304405U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10489529555776381736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6392552206958240484U;
            aOrbiterH = RotL64((aOrbiterH * 11761477994533503307U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10163241948999404556U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16054678853554707148U;
            aOrbiterE = RotL64((aOrbiterE * 10570418210789350091U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3606021702108590330U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16920568417324295852U;
            aOrbiterA = RotL64((aOrbiterA * 5222656554577625385U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13889995689147406315U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7908387312354285092U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7995682580514280949U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14161911472715334589U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12386100977925313406U;
            aOrbiterK = RotL64((aOrbiterK * 17136336570895231639U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14408470657696841139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7466281699619513012U;
            aOrbiterF = RotL64((aOrbiterF * 2706710684289882025U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11125044052260579351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6243113109470883144U;
            aOrbiterC = RotL64((aOrbiterC * 17390954549755941181U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 26U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterA, 21U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterJ, 51U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterA, 4U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterF, 35U)) + aPhaseFWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18441U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 16590U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 20135U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18306U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18690U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 57U)) + 15036852811491820366U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 29U)) + 305637140752898475U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 11948631574496129610U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 43U)) + 5321623592482991426U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 20U)) + 4075270159062690728U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 41U)) + 15111580500356908928U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 7244150695504160363U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 47U)) + 5131563519577488862U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 12U)) + 5881954992088651371U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 12780935808751507998U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 27U)) + 12599159643925470226U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9466589929741834066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17461243886150519249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15456408913739900718U;
            aOrbiterF = RotL64((aOrbiterF * 16093292401746174671U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11260643903290392780U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7870342756041882616U;
            aOrbiterI = RotL64((aOrbiterI * 2431528656086173419U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 134484990005888936U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10626896209992890407U;
            aOrbiterD = RotL64((aOrbiterD * 12034131076645285597U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14031164129515132292U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16395472745067254664U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1455944290845294254U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6757824754363319079U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17866422769075350837U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10226884082632410805U;
            aOrbiterJ = RotL64((aOrbiterJ * 206035536985843815U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14474587247775371703U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8501763445324525303U;
            aOrbiterB = RotL64((aOrbiterB * 5298694643596784007U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 222650368553738561U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3901452368735982094U;
            aOrbiterC = RotL64((aOrbiterC * 18347115513126660483U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3063093906728331146U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9026710562384443411U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8411243802199203035U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11282041925238364080U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15036852811491820366U;
            aOrbiterA = RotL64((aOrbiterA * 18185121326941087841U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 40U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterA, 47U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 56U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 41U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 38U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 19U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererE, 50U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aExpandLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25018U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 23103U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26170U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22889U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26557U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 18U)) ^ (RotL64(aCarry, 47U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 57U)) + 18319689184146942855U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 8041304130090501019U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 39U)) + 11347064191990897738U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 15242243470024447468U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 10U)) + 10619749107163611105U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 43U)) + 14795614276221947128U;
            aOrbiterK = (aWandererB + RotL64(aCross, 47U)) + 1578095288886372393U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 53U)) + 13593906305770501684U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 4U)) + 8919815528334599172U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 17425548324720065145U) + aPhaseFOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 47U)) + 11125018338392347335U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3779189180734244399U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10958224663276134041U;
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4317305352561612995U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 4891139433808505355U;
            aOrbiterG = RotL64((aOrbiterG * 11507024985663120317U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5166074784835930965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10080890270621589202U;
            aOrbiterK = RotL64((aOrbiterK * 13170894418184288695U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4501071771615514619U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6486573807774431753U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 324029625116648669U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15714881857668975753U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3506619392820235900U;
            aOrbiterI = RotL64((aOrbiterI * 5707033870161224499U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5295711072762443783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11192836530396570648U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4361810118382207039U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7993389678399774574U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12551394763541226695U;
            aOrbiterB = RotL64((aOrbiterB * 11903486656172026403U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11553674370322129668U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4459881583199320245U;
            aOrbiterC = RotL64((aOrbiterC * 2805857426321555685U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3053507713574219459U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15458441755058850309U;
            aOrbiterA = RotL64((aOrbiterA * 7296609957819165877U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17429750026356459756U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17114614857181230304U;
            aOrbiterD = RotL64((aOrbiterD * 10541235280918902739U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8958993884028672039U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18319689184146942855U;
            aOrbiterE = RotL64((aOrbiterE * 5430881344386342703U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 24U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 58U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 38U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterD, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 20U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 4U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32433U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 28572U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 31810U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27870U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31830U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCarry, 22U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 5U)) + 13278949403988203974U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 21U)) + 9213599924054673756U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 41U)) + 1255746482932381798U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 11U)) + 11575321997144516122U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 15881587525529432437U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 19U)) + 9846195809864862707U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 19U)) + 12319815691858217670U;
            aOrbiterG = (aWandererI + RotL64(aCross, 39U)) + 16322617427294439587U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 16332130810525887437U) + aPhaseFOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 4920951156015336794U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 47U)) + 16767126455124552329U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12553595911087945223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1437522202135436142U;
            aOrbiterJ = RotL64((aOrbiterJ * 2001992794165550905U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12313100454852227143U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2761983020631055729U;
            aOrbiterI = RotL64((aOrbiterI * 3874839760378039509U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17635303588421554367U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 788212489507463763U;
            aOrbiterE = RotL64((aOrbiterE * 17896475584538528059U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5192552894670654434U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6784748488807738811U;
            aOrbiterC = RotL64((aOrbiterC * 8077237651953896479U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16113417046719114943U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1096874945215225916U;
            aOrbiterA = RotL64((aOrbiterA * 17308604412622879833U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7610274704570171595U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10466070212284342550U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6449728258497920613U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6777845928873855221U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5251515022021984126U;
            aOrbiterG = RotL64((aOrbiterG * 9018277343404261611U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13849343158824111498U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7977711210181714021U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4182053966171053577U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6494539818728106982U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11314590450226080781U;
            aOrbiterD = RotL64((aOrbiterD * 12455979257225599157U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 552687702594328012U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14961304171192292246U;
            aOrbiterH = RotL64((aOrbiterH * 846375892915484717U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 9771874402848476494U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13278949403988203974U;
            aOrbiterF = RotL64((aOrbiterF * 2119203863777871233U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 48U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterI, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 53U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 58U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_VolleyBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5860U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 8140U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6749U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5492U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5364U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4623U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 7632760812370906911U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 11U)) + 6007174525479723089U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 3362829642521821048U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 18009548556107978286U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 20U)) + 17880909432272697327U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15961567935420752568U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 10136559064656837921U;
            aOrbiterD = RotL64((aOrbiterD * 14473810261421912849U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17622019364405410277U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6927494824421416306U;
            aOrbiterF = RotL64((aOrbiterF * 2686290883767829973U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7125170407794874847U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12342273503071032250U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 867417849555857179U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14997696377476124836U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14874498694181230698U;
            aOrbiterB = RotL64((aOrbiterB * 4026127545746010937U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2549397729130885686U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4217995818662767955U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5525525344485251063U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterI, 35U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 56U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14873U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneC[((aIndex + 13344U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 12820U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15085U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15792U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 14417U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 36U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aPrevious, 41U)) + 5160910997561396461U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 14920764751058512062U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 53U)) + 6080952401749660022U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 18U)) + RotL64(aCarry, 3U)) + 17667234330526298627U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 51U)) + 760630072638686756U) + aPhaseGOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3504157162816997476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9489022223422585882U;
            aOrbiterB = RotL64((aOrbiterB * 2398110457196177747U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1149898536879968964U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10492284328940025310U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7893416766300156495U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13213275606286399312U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 10557118912847180413U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10077877991284587845U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15618980209023994776U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5268600749854045564U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3849660559223919613U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8011552687609649990U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3148133096349525066U;
            aOrbiterK = RotL64((aOrbiterK * 5245156554959620007U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 30U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 57U)) + aPhaseGWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19998U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 21825U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 18010U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23751U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17692U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17603U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 39U)) + 2672739400294801233U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 29U)) + 8475624545015101850U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 1252755112289831257U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 7938039507649183387U) + aPhaseGOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 10U)) + 8167413146948861022U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17712313989694374353U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 7637042279892596975U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13056020836704050293U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15770412950033467341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3951812021898608685U;
            aOrbiterE = RotL64((aOrbiterE * 6623127125223204737U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8656983621098246507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3087677463651608668U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 16493240011924342788U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7750923317452683057U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2185924841611106546U;
            aOrbiterA = RotL64((aOrbiterA * 708072658250726381U), 21U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 38U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32135U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 27434U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 32060U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26433U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27757U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 29024U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 14214886793361825363U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 13U)) + 17267959031078766320U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 16436067429484887644U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 9885951769332633820U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 48U)) + 12971711341813893304U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 199970353398450154U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1237341696444162094U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2850125642665515751U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7991128854417613360U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14809029847149045833U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5940857360838299105U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2559509556915775947U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14336829730147834160U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15103242520064900873U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8853631886733610440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13346159398673246914U;
            aOrbiterG = RotL64((aOrbiterG * 13660497151446983393U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12121095718571872976U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 16239781125815589804U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 26U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_VolleyBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 610U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 2052U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 3558U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4910U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1513U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1996U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 57U)) + 15904465836916519864U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 12U)) + 17725629806317789307U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 13794170125914914828U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 2149055907476874332U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 5342047776745074649U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8268148484060546838U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10821151364028563719U;
            aOrbiterG = RotL64((aOrbiterG * 13626634259250509711U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4294213820894407378U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 10884726101307943090U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1116128870387229159U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16432210042202444824U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15196602644336228055U;
            aOrbiterB = RotL64((aOrbiterB * 12680438355124070237U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14117787670220328165U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 219833877949480215U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10736293047771972173U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3326396981881473962U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14918513066311426279U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14269763278564574663U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 58U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 26U) + aOrbiterG) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11394U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 13760U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 14140U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10049U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12156U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16174U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 2974056819475622600U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 26U)) + RotL64(aCarry, 51U)) + 7345051759236356098U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 39U)) + 12738468816846628882U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 7694520596043297922U) + aPhaseHOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 5530753590015084774U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3776309161718383105U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 784780304358106404U;
            aOrbiterG = RotL64((aOrbiterG * 1503119308251871519U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8999942326995036509U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5194986506064092779U;
            aOrbiterK = RotL64((aOrbiterK * 15070787038006135963U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7920040007459652762U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 11311997270710107937U;
            aOrbiterF = RotL64((aOrbiterF * 6227571709361790209U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5365231114813547251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8630110234623825263U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2358235238039571072U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 18059414891616491807U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17150786106857185467U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 20U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 56U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21142U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 23830U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23055U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23006U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19916U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24005U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aCross, 34U)) + 3550722402315312207U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 16724184551669522754U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 3U)) + 981751330116773021U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 7891159229704944868U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 13618396711464799841U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5969291018449003648U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14595540413313640042U;
            aOrbiterJ = RotL64((aOrbiterJ * 8151104319012840963U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3287990436916111762U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12534369400200483704U;
            aOrbiterC = RotL64((aOrbiterC * 2345945228434740707U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2277312067930392274U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10026320559261334353U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11020464940995912637U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 11258082063135659551U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1445958517675746990U;
            aOrbiterB = RotL64((aOrbiterB * 10062265337488757971U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1011298251290970844U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6487834862470043744U;
            aOrbiterH = RotL64((aOrbiterH * 15477913837027179675U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 44U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 11U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30453U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 26216U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 27325U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32615U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29097U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25822U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 24U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 2672739400294801233U) + aPhaseHOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 8475624545015101850U;
            aOrbiterE = (aWandererA + RotL64(aCross, 41U)) + 1252755112289831257U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 14U)) + 7938039507649183387U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 8167413146948861022U) + aPhaseHOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17712313989694374353U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7637042279892596975U;
            aOrbiterE = RotL64((aOrbiterE * 13056020836704050293U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15770412950033467341U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3951812021898608685U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6623127125223204737U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8656983621098246507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17943342344730687317U;
            aOrbiterC = RotL64((aOrbiterC * 16495519451034883813U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 3087677463651608668U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16493240011924342788U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16898479041530771871U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7750923317452683057U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2185924841611106546U;
            aOrbiterK = RotL64((aOrbiterK * 708072658250726381U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 52U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterK, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
