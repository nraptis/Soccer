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
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8383AC91A9CBC8FBULL + 0xB239F80C778FEB6BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF562A24913C68C4FULL + 0xECA962102636DDB3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC18B1BC8B16FC3F3ULL + 0xD5A345E5CE2301EDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9928433972674295ULL + 0xDCEE303655DB2D34ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD47879A3833AE189ULL + 0x9F4261A8FF013C1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA059F7C56C625701ULL + 0xDF2D7C289E4E659FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9BA842CB0A95871FULL + 0x9A4FEE9847AFED6AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE031D2A3B9748A59ULL + 0xF400D55B85AD06B2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEC609CFD6BD1694FULL + 0xE9F05EE44D8D7A7BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xCEBCC6993B54FEDBULL + 0xDE2ECB56B3D8B758ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB58796B9103C5907ULL + 0xE7B1C6AB03A4CA7FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFDDBFE89F9783543ULL + 0x9180B5AB99104E08ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9019CCAF774E2C03ULL + 0xFB48BA4A444D60BDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDE93D6B2CAF260FULL + 0x9269712491D31698ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB01C8FEBA640680FULL + 0x857A454ACF89B053ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE86EB6D87BBB11FFULL + 0xD3D665F7CC247E82ULL);
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
        // read from: mSource, pSnow, aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // ingress from: mSource, pSnow
        // ingress directions: mSource forward forced, pSnow forward/backward random
        // cross from: pSnow, mSource
        // cross directions: pSnow backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(mSource[((aIndex + 5109U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 1193U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 581U)) & S_BLOCK1], 53U) ^ RotL64(mSource[((aIndex + 4577U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = (aWandererG + RotL64(aScatter, 43U)) + 13687218104610230596U;
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 6841550124960692709U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 57U)) + 17418968668458764131U) + aNonceWordP;
            aOrbiterD = ((aWandererB + RotL64(aCross, 60U)) + 8303537912696948204U) + aNonceWordD;
            aOrbiterH = (aWandererD + RotL64(aScatter, 47U)) + 12376614417285936537U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 39U)) + 14215749063579232654U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 41U)) + RotL64(aCarry, 37U)) + 4111736931433665347U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 11250375934571631522U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 5367367837773331275U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 53U)) + 15514089192382674434U) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 34U)) + 1475991716685034960U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5531622777788629748U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8363822215908303335U;
            aOrbiterC = RotL64((aOrbiterC * 17850203366840994883U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3741256932685720414U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11634667238062155772U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 15925089729784547403U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18180546911210417155U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5123234656838556335U;
            aOrbiterI = RotL64((aOrbiterI * 15362857462853398025U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11215734271189250284U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16863747802158398092U;
            aOrbiterH = RotL64((aOrbiterH * 1828035970246160023U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9859050606636646323U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9331300036643654675U;
            aOrbiterG = RotL64((aOrbiterG * 2502263410556166281U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 15028845665427209759U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8916444839488901676U;
            aOrbiterF = RotL64((aOrbiterF * 6646561894156038791U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8024631140949068570U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1116378858490660031U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4247798531910227367U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5066486214537899212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9346312092322423057U;
            aOrbiterE = RotL64((aOrbiterE * 13443190089768875191U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11651011617027950122U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11308862427412671711U;
            aOrbiterB = RotL64((aOrbiterB * 12167147966934334703U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3850136281462840708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13461307727665667424U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 10788040812090673421U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17824744996404571928U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13687218104610230596U;
            aOrbiterA = RotL64((aOrbiterA * 325803029547254631U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 42U)) + aOrbiterK);
            aWandererB = aWandererB + (((((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterI, 40U));
            aWandererI = aWandererI + (((RotL64(aIngress, 20U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // ingress from: aFireLaneA, pSnow
        // ingress directions: aFireLaneA forward forced, pSnow forward/backward random
        // cross from: aFireLaneA, mSource
        // cross directions: aFireLaneA backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 10297U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 6984U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10357U)) & S_BLOCK1], 10U) ^ RotL64(mSource[((aIndex + 7846U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 37U)) + 5697928251815176134U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 337587740689259575U;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 30U)) + 4927686903263973950U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 41U)) + 3742409032569801033U) + aNonceWordM;
            aOrbiterC = (aWandererC + RotL64(aScatter, 5U)) + 1608092659172197650U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 47U)) + 15848744267145717509U) + aNonceWordO;
            aOrbiterJ = (aWandererI + RotL64(aCross, 43U)) + 15300174177963339253U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 51U)) + 14162868453323648628U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 13U)) + 12020167069983729869U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aPrevious, 11U)) + 16259538291658723956U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 18U)) + 8516686212464112245U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3722184575520553132U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5663609293306386784U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15265344442454471986U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1093356813820599238U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15167726103772238440U;
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15170797965325981472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17826286701992981628U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14710892030473425181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 397194787697553904U;
            aOrbiterD = RotL64((aOrbiterD * 14368930300818752833U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1273724124862533034U) + aNonceWordC;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13018397560392545616U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 4644812473262395329U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9638716186445643730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7255587739807843785U;
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9272350563697399628U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1040729335295009339U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17825687660830291443U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12128124729613601747U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2285238815562202219U;
            aOrbiterJ = RotL64((aOrbiterJ * 15398840993074390573U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6339113298619163493U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5911895708485037040U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 3271006139923200439U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 7601399508218901328U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5697928251815176134U;
            aOrbiterI = RotL64((aOrbiterI * 8184257916861355735U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 22U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterB, 26U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + aNonceWordJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 34U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererC, 38U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // ingress from: aFireLaneB, mSource
        // ingress directions: aFireLaneB forward forced, mSource forward/backward random
        // cross from: aFireLaneA, pSnow
        // cross directions: aFireLaneA backward forced, pSnow backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 13910U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13639U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14300U)) & S_BLOCK1], 6U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13692U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 34U)) + RotL64(aCarry, 11U)) + 18144572925667544139U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 27U)) + 5659758077574059728U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 5U)) + 6343330616999166392U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + 17754639838410839447U) + aNonceWordL;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 9451843819849581729U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 57U)) + 7957854457197462212U) + aNonceWordE;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 60U)) + 1461994799722205010U) + aNonceWordK;
            aOrbiterH = (aWandererG + RotL64(aCross, 37U)) + 18002214276252170177U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 41U)) + 14689869073147027164U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aIngress, 21U)) + 3978104368003440293U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 8512135845221335386U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1477533446382953439U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2166717790929947990U;
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8082437060686606995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 4363687722464700362U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7199165810993478887U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15782763348014924206U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8572509150015960728U;
            aOrbiterH = RotL64((aOrbiterH * 3340528604891897779U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12248271773316742521U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9602078627638561949U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1860631869877427405U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17244849374768558859U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 1030743048280579012U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 10858949914285817051U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17722342363541914280U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15667504059789880034U;
            aOrbiterE = RotL64((aOrbiterE * 15872269872168533709U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12645332941998550794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9938135244509986497U;
            aOrbiterC = RotL64((aOrbiterC * 16548185968987392957U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4024609904162105979U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6732064218696157303U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 3815409766145891393U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 14314117137220703583U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15244765904057473814U;
            aOrbiterG = RotL64((aOrbiterG * 4034571710808047959U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17441241682018169245U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11958974379114644873U;
            aOrbiterK = RotL64((aOrbiterK * 11315689206845170303U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8310839846793796473U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18144572925667544139U;
            aOrbiterA = RotL64((aOrbiterA * 11668203295511168011U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 24U);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 34U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 54U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 51U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 30U)) + aNonceWordC);
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterB, 41U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // ingress from: aExpandLaneA, pSnow, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: mSource, aFireLaneB
        // cross directions: mSource backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18889U)) & S_BLOCK1], 13U) ^ RotL64(pSnow[((aIndex + 20890U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21537U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 19748U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 18760U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 18U)) + RotL64(aCarry, 11U)) + 10404808878585437255U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 10587858736301591439U) + aNonceWordB;
            aOrbiterA = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 1430530909801644435U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 53U)) + 9090938022430118902U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 37U)) + 12936604311751121235U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 43U)) + 1000583006020232032U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 27U)) + 12352532088997042232U) + aNonceWordM;
            aOrbiterD = (aWandererK + RotL64(aCross, 13U)) + 16723410947058502564U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 41U)) + 16614089235313154270U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 46U)) + 4245553025593349277U) + aNonceWordL;
            aOrbiterB = (((aWandererA + RotL64(aCross, 5U)) + 3353146318549477494U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5935727336135635196U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10312187090293319667U;
            aOrbiterA = RotL64((aOrbiterA * 1395964500396711899U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12192843181244744484U) + aNonceWordF;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2542570124502586365U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17222847847573534963U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3315472769469002444U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17512858811783071174U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 9070400454074283765U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16633218007427888082U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2502077714838858460U;
            aOrbiterG = RotL64((aOrbiterG * 970762420815997725U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14792910273226469214U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15739513291150783151U;
            aOrbiterD = RotL64((aOrbiterD * 11896279674116906915U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2192903544350345992U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 844428341223009295U;
            aOrbiterK = RotL64((aOrbiterK * 4768368713974002539U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2998511458298901402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7790789639864783373U;
            aOrbiterH = RotL64((aOrbiterH * 9173097618440495497U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4540735375055164995U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13700342877362633034U;
            aOrbiterI = RotL64((aOrbiterI * 14730797752841670505U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16966725424259324323U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5945539295893015935U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12226268057062268981U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12560355243513521281U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2104086086480258265U;
            aOrbiterJ = RotL64((aOrbiterJ * 17989755118752755577U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4476697099257280568U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10404808878585437255U;
            aOrbiterB = RotL64((aOrbiterB * 6245415417832089357U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 18U)) + aNonceWordN);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 26U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // ingress from: aExpandLaneB, mSource, pSnow, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, mSource forward forced, pSnow forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aFireLaneB
        // cross directions: aExpandLaneA backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25175U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 24755U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23080U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneA[((aIndex + 24213U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23694U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneB[((aIndex + 22991U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 13350544654542863236U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 11U)) + 12364346790125404372U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 9738750172849512764U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 40U)) + 3781373837635491421U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + 16635020317512702337U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 27U)) + 5383653921676231276U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 13U)) + 10181959815492056493U) + aNonceWordN;
            aOrbiterF = (((aWandererI + RotL64(aCross, 21U)) + 10005510924273927017U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aWandererE + RotL64(aScatter, 47U)) + 9524687662265740565U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 6U)) + 4259138552009771014U;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 8973051213213726023U) + aNonceWordD;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17602611840127337490U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8218984546932905269U;
            aOrbiterJ = RotL64((aOrbiterJ * 17504305273683304231U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 18102186122213487888U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2629927500298092976U;
            aOrbiterI = RotL64((aOrbiterI * 6983280164448292723U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 2491581597835795234U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9506602492971620955U;
            aOrbiterG = RotL64((aOrbiterG * 9559829640915637163U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13422942713680612924U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15037354693234876601U;
            aOrbiterF = RotL64((aOrbiterF * 12692376075738621447U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12896066842192894694U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 2202952306291905855U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 6779368532763429997U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12160313482450599313U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10812986281270407756U;
            aOrbiterD = RotL64((aOrbiterD * 7786608700746771809U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12474638293190144525U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5882870951276225224U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15532427302173572457U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3782896138051179209U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10965680631059882311U;
            aOrbiterC = RotL64((aOrbiterC * 14060923998307082385U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15650420683333746952U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4110674660963676864U;
            aOrbiterE = RotL64((aOrbiterE * 11724979274890265275U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 694817156953099464U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 4402927404825116007U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 579586789292520113U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6849178151532923489U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13350544654542863236U;
            aOrbiterH = RotL64((aOrbiterH * 2416097748778941523U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 52U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 60U)) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 24U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + aNonceWordG) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, mSource, pSnow, aFireLaneB
        // cross directions: aExpandLaneB backward forced, mSource backward forced, pSnow backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30348U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 28819U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32252U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29950U)) & S_BLOCK1], 43U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29517U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 27816U)) & S_BLOCK1], 14U) ^ RotL64(aFireLaneB[((aIndex + 32624U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 24U)) + 11039986441331892533U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 6256024955965426119U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 37U)) + 9857443189988995666U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 11900944813380998208U) + aOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 53U)) + 8422577734978875541U) + aNonceWordO;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 3100835100713928724U) + aNonceWordB;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 13U)) + 11871553509810206993U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 30U)) + 17614749493763417027U;
            aOrbiterF = (aWandererK + RotL64(aCross, 39U)) + 3638372131856199916U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 47U)) + 6582275259281025770U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 19U)) + 17016882418498941958U) + aNonceWordL;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1747214688658984715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9356088987044015278U;
            aOrbiterB = RotL64((aOrbiterB * 16221733545319753695U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4056238112133473456U) + aNonceWordM;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16013150119949532998U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16076621211111834889U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9940824359571581765U;
            aOrbiterJ = RotL64((aOrbiterJ * 11624767861336495331U), 39U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 15624084004784515753U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7630989544834680335U;
            aOrbiterF = RotL64((aOrbiterF * 12261063237156822067U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18003586430673313786U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1654118743290334161U;
            aOrbiterG = RotL64((aOrbiterG * 1153250137357176071U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3254189676528343910U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15629083361573065165U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 17024833368570949107U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10056859810555674806U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15976683222786846254U;
            aOrbiterC = RotL64((aOrbiterC * 2801754232182942635U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11872378594829637933U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7633773773528713489U;
            aOrbiterK = RotL64((aOrbiterK * 8218288492011593353U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16305188578382203720U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13293036594949754170U;
            aOrbiterE = RotL64((aOrbiterE * 1300645662609848183U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15185013801659166674U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11562899709899198100U;
            aOrbiterD = RotL64((aOrbiterD * 9115495024409604629U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 1525205566739385260U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 11039986441331892533U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 9802284050237622047U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 48U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterE, 56U)) + aNonceWordG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 24U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x923AFDDAA3995CF3ULL + 0xBE49F69F7D6C8841ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8D90D319B0FAF7DDULL + 0xE483B3B34838C279ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC9B1B2DDA8A04B01ULL + 0xA283614189AC28CCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF3D9D9A526285953ULL + 0xE52276E8244612DDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x97511420D9817323ULL + 0x864D550BA42E5734ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEBAE372971CEBE97ULL + 0xDE65A49183BD7475ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB2E294D3C9A9EAB7ULL + 0xBFCE2AA635796D41ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x905575ED663DE20DULL + 0xB83CC339EC115F61ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x83C9B33FBE24941DULL + 0x832D7EB5038AF065ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA044F3807798DC0DULL + 0xA4206FC06C149680ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD361B0179DBCA349ULL + 0xA36E517664576CC5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBB197F00EC64A107ULL + 0xF6EFAED96180187DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFE2A0ED9EC1364D7ULL + 0x997042E818938295ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x941098AB3494D60DULL + 0xCA949EABDE849170ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF55A9FCA280C9D49ULL + 0x9F4BA65F0D6B9A6DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF35313F4C6D1E923ULL + 0xB2F751BB60E004DAULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC
        // write to: aFireLaneC, aFireLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_a_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneA[((aIndex + 4092U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 259U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2337U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 1795U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U)) + (RotL64(aCross, 48U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 35U)) + 3255291173184001106U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 15308468160116255528U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 30U)) + 18186972408589866656U) + aNonceWordD;
            aOrbiterG = (aWandererA + RotL64(aIngress, 11U)) + 4439324265978331914U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 37U)) + 13099263173016322486U;
            aOrbiterB = (aWandererK + RotL64(aCross, 23U)) + 7041561081767500660U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 6196422612687812971U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 18U)) + 7664260932541281413U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 57U)) + 17802347823020441056U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4253107484061190446U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13799496534030645312U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14252892847595951926U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5663527578664291422U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11148755959699137661U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17036900929333594592U;
            aOrbiterB = RotL64((aOrbiterB * 16041243617369003291U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2403828181385259549U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17813580350434928194U;
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5623611126885414523U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7293224381174846969U;
            aOrbiterH = RotL64((aOrbiterH * 7032561584670788117U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10602620906929686163U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 18015916257203385982U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13592915735376305773U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 13995866908043417505U;
            aOrbiterJ = RotL64((aOrbiterJ * 3802175869395887331U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8200465989447697618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9866671660800629464U;
            aOrbiterF = RotL64((aOrbiterF * 2138851839905326265U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11557528777230608777U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 131060617338185060U;
            aOrbiterI = RotL64((aOrbiterI * 11068705423012265209U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterA, 39U)) + aNonceWordJ) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 50U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterG, 35U)) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 51U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterH, 18U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 48U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 2
        // ingress from: aFireLaneC, aExpandLaneB, aExpandLaneC
        // ingress directions: aFireLaneC forward forced, aExpandLaneB forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 5829U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 9083U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7914U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6490U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 10701U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 24U)) + 14249093584376402677U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 19U)) + 8756965951816492264U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 43U)) + 11221139480258176330U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 17218894445564194851U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 8064642692524949490U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 5822093203710704646U) + aNonceWordE;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 34U)) + 3217799620158102238U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 53U)) + 2613757677892120843U) + aNonceWordD;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 39U)) + 13647481499551657237U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3545714196663685016U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9735422670576621521U;
            aOrbiterJ = RotL64((aOrbiterJ * 7276207208162697249U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3911046580637583767U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9315984027042049203U;
            aOrbiterB = RotL64((aOrbiterB * 12568550776487242469U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8926367674641729058U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 11035347490524961446U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 10948288997163592463U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10748158733051120339U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2467801787989056455U;
            aOrbiterH = RotL64((aOrbiterH * 12621934274702358977U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9244415080474351390U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8517784887959492079U;
            aOrbiterK = RotL64((aOrbiterK * 17022899813765884147U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8409307332803038455U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11043806021873232950U;
            aOrbiterF = RotL64((aOrbiterF * 8294888329708842989U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17512395828450251457U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 16849067939795823992U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 9361991804481514337U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17541946638063238056U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11430501673960586718U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15074409630605450091U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 78307505705383302U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4834528975263832983U;
            aOrbiterC = RotL64((aOrbiterC * 17245673681686752861U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 30U) + RotL64(aOrbiterA, 54U)) + aOrbiterF) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterC, 47U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterC, 18U));
            aWandererA = aWandererA + (((((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 5U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 3
        // ingress from: aFireLaneD, aExpandLaneD, aExpandLaneC
        // ingress directions: aFireLaneD forward forced, aExpandLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aExpandLaneB, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aFireLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 15981U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 14832U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11504U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15421U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12541U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 18U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (aWandererH + RotL64(aPrevious, 42U)) + 4634399531433127141U;
            aOrbiterF = (aWandererA + RotL64(aCross, 35U)) + 16961792729406903200U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 13U)) + 4105280732301137738U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 15692013501147331191U) + aNonceWordO;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 23U)) + 1252216715968780587U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 7958289043012473752U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 6611577301818896615U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 28U)) + 8506226754305949140U) + aNonceWordB;
            aOrbiterE = (aWandererG + RotL64(aCross, 3U)) + 3648813120449403353U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5195245426245535735U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 542948051600803051U;
            aOrbiterA = RotL64((aOrbiterA * 4631106308856448475U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11974253551208964789U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10596463592332655367U;
            aOrbiterK = RotL64((aOrbiterK * 10941161258815714641U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12015129484061440159U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8254944355710109060U;
            aOrbiterC = RotL64((aOrbiterC * 3233697992479357615U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 2754858806943915419U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5007802002906662779U;
            aOrbiterD = RotL64((aOrbiterD * 15613733948331639723U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6262190752136523216U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10528977986487821428U;
            aOrbiterB = RotL64((aOrbiterB * 1184258264034585525U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8511097226098211854U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12091864735686692582U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6128140528141411237U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4970966265236842566U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10728884018459718341U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18205183219769602827U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13760057185629905360U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6590269178744829056U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 14482684769712170123U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 765826377665103262U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9364759196106579706U;
            aOrbiterJ = RotL64((aOrbiterJ * 10315111163659289329U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 46U) + RotL64(aOrbiterJ, 6U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 60U)) + aOrbiterD) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 4
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16887U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 16555U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19760U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21329U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 18451U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 30U)) + 15726877954695761686U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 57U)) + 14187652171881943587U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 47U)) + 8420423151313882782U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 23U)) + 14942322692433259283U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 12U)) + RotL64(aCarry, 27U)) + 7272331475919796255U;
            aOrbiterH = (aWandererB + RotL64(aCross, 3U)) + 154504365041805840U;
            aOrbiterJ = ((((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 17475491222554948786U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 5759181483165339605U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 35U)) + 5993060214499322845U) + aNonceWordK;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10901786237875941844U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 17135786595614068473U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 15923538730142047043U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5208202073886811165U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6821452921018900631U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13348064837402206969U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8967943922403445136U;
            aOrbiterD = RotL64((aOrbiterD * 300168481725373093U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8130283784171430891U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6351113882502502876U;
            aOrbiterB = RotL64((aOrbiterB * 15960622823993072903U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6894708729226455769U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12065058511247133944U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 5432601727436935831U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17138279326229372741U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12987698199066890628U;
            aOrbiterK = RotL64((aOrbiterK * 12665716655177320977U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13688833537574196675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4211971980434000618U;
            aOrbiterJ = RotL64((aOrbiterJ * 1374411763361518851U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10376917117582537592U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4807742522197923516U;
            aOrbiterC = RotL64((aOrbiterC * 15257251453302090961U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 18038296468177121243U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6879666349379745258U;
            aOrbiterG = RotL64((aOrbiterG * 15819475269715810555U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterA, 40U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordN);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterH, 20U)) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aNonceWordF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 47U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 5
        // ingress from: aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneB[((aIndex + 24918U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 24372U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22807U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 24208U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + 9446153639709651566U) + aNonceWordF;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 10550762260670758167U) + aNonceWordK;
            aOrbiterC = (aWandererD + RotL64(aCross, 35U)) + 7062634922142578383U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 11U)) + 9178499097812764515U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 27U)) + 6887103379773525538U) + aNonceWordN;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 6239750312052010257U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 23U)) + 17645022614523287959U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 41U)) + 3639618183259408272U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 60U)) + 3131737117548745095U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7253994382396406554U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15217993711938379561U;
            aOrbiterC = RotL64((aOrbiterC * 17853313384747259923U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12594152227603630033U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11250170200489647869U;
            aOrbiterB = RotL64((aOrbiterB * 546800378327864723U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12936942656624279424U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10990736056052106149U;
            aOrbiterA = RotL64((aOrbiterA * 7123916809953459187U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 12787293075893090465U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17154990205620778151U;
            aOrbiterD = RotL64((aOrbiterD * 10031369940028159521U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1270827262969060301U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17337623431665013136U;
            aOrbiterK = RotL64((aOrbiterK * 1517262088236356107U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 830330490987911853U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6828309232554560547U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9742464176986145819U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11470087853413986203U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10470148870747884420U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6766079738799967443U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18315536891901859637U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12264670822285914271U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 5841574505408674119U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10931842095884524879U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11134871340959676257U;
            aOrbiterE = RotL64((aOrbiterE * 11714837622285605745U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterE, 46U)) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterD, 50U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_b loop 6
        // ingress from: aOperationLaneC, aOperationLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aOperationLaneC[((aIndex + 29434U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29128U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29604U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30210U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 56U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 6U)) + RotL64(aCarry, 37U)) + 1042610313571524121U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 3505725321008825582U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 47U)) + 12584654563843782991U) + aNonceWordE;
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 6645399144515770935U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 23U)) + 3608978423753715584U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 19U)) + 8089198857670370983U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 51U)) + 15207251813516399879U) + aNonceWordC;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 9579268660105824516U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 11U)) + 16055044469473802812U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 583811872609805949U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7027491967970873942U;
            aOrbiterH = RotL64((aOrbiterH * 12686754713465826139U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 18256061823189677508U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12708429127816136937U;
            aOrbiterE = RotL64((aOrbiterE * 12593886633108075321U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12169216645156306078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16109994660203297503U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4234704064165718913U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 730085881474787681U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14119541943554602878U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8777769004811352951U;
            aOrbiterB = RotL64((aOrbiterB * 2556957257736134223U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15642663488392549609U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11594468530833278624U;
            aOrbiterG = RotL64((aOrbiterG * 6639306656361601143U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7365350535791499871U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 5965170981970155956U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 1898702752753066851U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9115232101451815522U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9433983580038990072U;
            aOrbiterI = RotL64((aOrbiterI * 1951249217843992179U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8810565477444156140U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12081286530401844859U;
            aOrbiterC = RotL64((aOrbiterC * 1991383259486140229U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 36U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 47U)) + aNonceWordM) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterH, 51U)) + aNonceWordB);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + aNonceWordP) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 40U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 44U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9BE02923BFA6EDEFULL + 0xC76563C4AF6DC02FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDCD9285389017CD5ULL + 0x90012BC6AB856B0FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCF77F03DB51CB75BULL + 0xBBB3154BF87AADBBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF2F9D1CCB850E74DULL + 0xF00393CF2734B36FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEE97DB3D1745FBDFULL + 0x926388C6BB526F40ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8B4A871ADCCC16CDULL + 0xC7A78621E3871F15ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC565D42E9E2DD0E5ULL + 0xA0E016D5165505D0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEFB90784795113FFULL + 0xAEBA7B3015F135A6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB6F6CD1878D21279ULL + 0xB286DC28CB781E98ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE0ACCE97B06BEA19ULL + 0xF07340361EA9AAADULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF226EDFD26A86923ULL + 0xA57B7C009CC7228DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xA076C63DD861B2F5ULL + 0xF3FF20CC20353783ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xBDA842389A6CEF8BULL + 0x88B62616AA2C9CD4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC8F94C291991ECCBULL + 0x860792E224023181ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE857B4B61AC42BF7ULL + 0xE0B289A7CF9FC053ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAE6923CA5C122AEDULL + 0xAFA03327FF6231F7ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 5312U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 3524U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3088U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6946U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 211U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4049U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 1898718075389870739U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 5631794889237247403U) + aNonceWordI;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 18219714659484524607U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 29U)) + 15419581386225732921U) + aNonceWordL;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 20U)) + 9125575431710198210U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12205871520544965505U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7617534300497343422U;
            aOrbiterC = RotL64((aOrbiterC * 10052675719887595625U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18017579105368135814U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10693882161946020042U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2326507900303932855U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11669615701700895306U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 11045110212889232165U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5965171269273719849U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18019107802806469913U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 12315940560472528716U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4899009736070044310U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 17412253404253730364U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 10791901166391946485U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 40U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 22U)) + aOrbiterC);
            aWandererI = aWandererI + (((((RotL64(aCross, 58U) + RotL64(aOrbiterB, 43U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordE);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10203U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 9499U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13942U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 11878U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16181U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14157U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11430U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 13174219512651137892U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 11U)) + 2715455762789269341U;
            aOrbiterI = (aWandererF + RotL64(aCross, 56U)) + 1338018183235594313U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 16566866551729552930U) + aNonceWordE;
            aOrbiterC = ((((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 6901845297307236726U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 2476078302049201718U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15531109473927052260U;
            aOrbiterI = RotL64((aOrbiterI * 1078804000420970559U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4087849380858572351U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5167830630098599644U;
            aOrbiterC = RotL64((aOrbiterC * 1982835131228146099U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 7275995452428627217U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14794340370010024117U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 8779497557416568379U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8509217403041662849U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2321522025240806996U;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5676672952755594051U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2304681269233504384U;
            aOrbiterJ = RotL64((aOrbiterJ * 15731441084605554497U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 14U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 44U)) + aOrbiterH) + aNonceWordP);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 3U)) + aNonceWordC) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordH) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16932U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((aIndex + 22449U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 18600U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 21684U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17834U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24066U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16552U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 3U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 13278949403988203974U) + aNonceWordP;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 9213599924054673756U) + aNonceWordC;
            aOrbiterH = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 1255746482932381798U) + aNonceWordO;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 37U)) + 11575321997144516122U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 46U)) + 15881587525529432437U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9846195809864862707U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12319815691858217670U;
            aOrbiterH = RotL64((aOrbiterH * 14271546305640811091U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 16322617427294439587U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 16332130810525887437U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 7588076439690559343U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 4920951156015336794U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16767126455124552329U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4440352337076842603U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12553595911087945223U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1437522202135436142U;
            aOrbiterE = RotL64((aOrbiterE * 2001992794165550905U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12313100454852227143U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 2761983020631055729U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterA, 47U)) + aNonceWordD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 60U)) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32314U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 30863U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26535U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26715U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26404U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25064U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 27421U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 14U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = (((aWandererD + RotL64(aScatter, 24U)) + RotL64(aCarry, 57U)) + 17019646486641172469U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 5U)) + 12276141179299971572U) + aNonceWordC;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 3617241694029841555U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 6967963401259371737U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 51U)) + 6340709284279891017U) + aNonceWordI;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 456065368903896482U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17686765719908116203U;
            aOrbiterJ = RotL64((aOrbiterJ * 4451942512173336609U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1322045955429785736U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5163772703302372887U;
            aOrbiterG = RotL64((aOrbiterG * 3193272189179082313U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 13268431135020363252U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6538789950366849332U;
            aOrbiterA = RotL64((aOrbiterA * 5352960308459065837U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10390344544314544893U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 5087084271300584267U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 15149302947570776165U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13423071121590981727U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15814349432207734533U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 47U)) + aNonceWordL);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterA, 43U)) + aNonceWordG);
            aWandererI = aWandererI + (((((RotL64(aIngress, 42U) + aOrbiterD) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 23U)) + aNonceWordM) + aWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 56U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAB7246B01A06B1CFULL + 0x9F20789FEC1FCB94ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAF10B39AD4782C63ULL + 0xB63976E6CE8BA82DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA49C5055C9606095ULL + 0xCD41C8342593F477ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x96C8854BD51B02DFULL + 0x91581716FF4128C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD31DBFC2958A3E17ULL + 0xF68A8BD9DFDAA011ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8767AE5A8DFC25A7ULL + 0xE6F3711321354CEFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x92D4A2182B678D1DULL + 0xA74E8C23E32350F2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x93FACBDBECDF86A9ULL + 0x87BE255EB22A62AFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x91E3F422B1501931ULL + 0xA8E34B18C60D12C3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB03C1474F97931A3ULL + 0xAE15E93B32BAEB35ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE6AD4414F633763DULL + 0xDE6309BAF0AF3AB5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDD4E591B4F54D61FULL + 0xC25CF20C87130801ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC78EB6DF9D9E0637ULL + 0xC9A9080C730C53F6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x898681405C053895ULL + 0x9954F6E3A8B2E634ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8A92ED02FCE2926FULL + 0xACB106DB60BE038AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEC40DCB2465EB523ULL + 0xDA892E19D51EB963ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1728U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 3493U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 106U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2841U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6618U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 314U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 3U)) + 13854738573712660276U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 21U)) + 16835460633412286294U) + aNonceWordI;
            aOrbiterG = (((aWandererD + RotL64(aCross, 10U)) + RotL64(aCarry, 41U)) + 6785859293758091931U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 126317283127992659U) + aNonceWordE;
            aOrbiterE = (aWandererE + RotL64(aCross, 35U)) + 7568963536291415413U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 12294016745653004819U) + aNonceWordN;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 47U)) + 18269588932920281147U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5872406424994751026U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7764434758831474129U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3772146788188420071U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4804168969415573371U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 959601763507651280U;
            aOrbiterK = RotL64((aOrbiterK * 4647396592804833217U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9257644462479293048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14332699366894494579U;
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10487012596470786004U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 612729229562321440U;
            aOrbiterJ = RotL64((aOrbiterJ * 11380387280507726003U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 7845523921295625315U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 12742115479740024747U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10294667720904610944U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14369711143154904567U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 13753005602288309379U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10918344717497681894U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 18136794828308636957U;
            aOrbiterE = RotL64((aOrbiterE * 17899418637978002409U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterF, 43U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 54U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8875U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 13656U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9984U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneC[((aIndex + 12005U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11927U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14628U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15769U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 51U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererA + RotL64(aIngress, 51U)) + 14624277139785904404U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 6966977309498165611U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 205536824352530761U) + aNonceWordO;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 30U)) + 16629575265808255692U) + aNonceWordF;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 596881340147972746U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 11U)) + 11944412799107412650U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 4615021315668210206U) + aNonceWordC;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8497630055977606216U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11131601107309336885U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18028349768453554935U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5935883479805510099U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15629346719765798174U;
            aOrbiterK = RotL64((aOrbiterK * 8535523790685945275U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5279128339113651273U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 16778365912440331821U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 705421028266789241U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16003052937645491524U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6723226158737614764U;
            aOrbiterB = RotL64((aOrbiterB * 16690657664909260573U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9785784358981219543U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10055457337292292710U;
            aOrbiterI = RotL64((aOrbiterI * 17919129940751761111U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11779163108592974175U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1177999477942202687U;
            aOrbiterF = RotL64((aOrbiterF * 13475069421684114643U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9190694445141492214U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15605342360346353457U;
            aOrbiterH = RotL64((aOrbiterH * 14547769706392595647U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 47U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 12U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 40U)) + aNonceWordD) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23376U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 18565U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20577U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 20379U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24086U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20379U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 20721U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 13174219512651137892U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 19U)) + 2715455762789269341U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 1338018183235594313U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 51U)) + 16566866551729552930U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 35U)) + 6901845297307236726U) + aNonceWordI;
            aOrbiterB = ((((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 2476078302049201718U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 3U)) + 15531109473927052260U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4087849380858572351U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5167830630098599644U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1982835131228146099U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7275995452428627217U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14794340370010024117U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 8779497557416568379U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8509217403041662849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2321522025240806996U;
            aOrbiterH = RotL64((aOrbiterH * 113568101672878697U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5676672952755594051U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2304681269233504384U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15731441084605554497U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8383399721062437300U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13181984036942227666U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13602604532551684210U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12725687663616352843U;
            aOrbiterG = RotL64((aOrbiterG * 4684699861686199753U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5831790822416009806U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4535048543735457407U;
            aOrbiterJ = RotL64((aOrbiterJ * 12076777878870257053U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterG, 43U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 3U)) + aNonceWordA);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 20U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneB, aOperationLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26001U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 26830U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 25592U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 32219U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27208U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28706U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32110U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 4848316479321533394U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 6919360256662636195U) + aNonceWordL;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 4U)) + 9897013582181108544U) + aNonceWordG;
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 7319353809896158678U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 2848175435514849859U) + aNonceWordF;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 6967780718720437934U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aIngress, 27U)) + 10143884766603388136U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8675965006150972051U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 16350117755560994281U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15072308930382994425U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17976597517118423760U) + aNonceWordJ;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 1399631141355370237U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 16537788276543236833U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3590613762034716792U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5134624314245932157U;
            aOrbiterH = RotL64((aOrbiterH * 13077589037975283371U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10082236952942943654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4015535035905433450U;
            aOrbiterC = RotL64((aOrbiterC * 4961808568701908559U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 611474103801573800U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5786708483794098001U;
            aOrbiterI = RotL64((aOrbiterI * 7694007039340089267U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 5201943497363274455U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9282160506938328489U;
            aOrbiterG = RotL64((aOrbiterG * 5368182164239021367U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4932320527498940158U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11576526341731392916U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 1712051774729439363U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 4U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterK, 21U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterI, 57U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCE8469B2D40176C9ULL + 0xE005D0F39AB9947DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEA33D5182B513CF1ULL + 0x8832EC91F941B29DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF209CC9D92ADB415ULL + 0x9F522134CA0BFE99ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF5DA2197C9CD023DULL + 0xBA039A99F7C3BEB2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB5D4450FEEF77649ULL + 0xA6463089142A971FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE8F9AF552E8BC97FULL + 0x8D7EFB7EFFA5C628ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB6BE6C8E6099C997ULL + 0xE393CC439183D274ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA4D5CEE4F7940707ULL + 0xCCBB259EE14323DAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB299B78C01862737ULL + 0x841A8BD132018AD8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9FA8B496B8A65425ULL + 0x8D3A49AD811714BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF4F74EAEF5738CFDULL + 0xCD568C2C90271674ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB03C1216EDC747C1ULL + 0xEAC35546A2EF1841ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE4B10803F350A30FULL + 0xC2DBA085455CFBCFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD037C48B136D9FD3ULL + 0x9B02BE6A53538993ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x955F5A0210AD786DULL + 0xE147C079C9C8CE5AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE504BD7E0273CE55ULL + 0xA02EBB43850E8113ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aExpandLaneA, aOperationLaneD, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4387U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 5454U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 2131U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5232U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 2603U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 8975885703279267062U) + aNonceWordG;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 11U)) + 8664844915562660637U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 4U)) + 12281774799736296726U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 29U)) + 15347461352311329726U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 12967500561828907834U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 5002833859280402726U) + aNonceWordK;
            aOrbiterE = (aWandererA + RotL64(aIngress, 19U)) + 11908257536954668983U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17017174811949227162U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16851323125613931180U;
            aOrbiterH = RotL64((aOrbiterH * 12446990992858763577U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13469326957728686706U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5228638551056105241U;
            aOrbiterI = RotL64((aOrbiterI * 13369947664646167255U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11945166198089308564U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16268645041872996022U;
            aOrbiterF = RotL64((aOrbiterF * 5391448793718370911U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14781204627695095701U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 5365325354838101092U;
            aOrbiterJ = RotL64((aOrbiterJ * 8017284997946310807U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 563147416025715953U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14660867395395625851U;
            aOrbiterG = RotL64((aOrbiterG * 4769458126865307103U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3168989056355712105U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16179131669773665579U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5641461617066671723U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4160220074225527179U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8597134686962559111U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 639572585431474015U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterE, 50U));
            aWandererA = aWandererA + (((((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 3U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterI, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aFireLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aFireLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aWorkLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aWorkLaneB backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneA[((aIndex + 9091U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 6867U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7994U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8523U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9695U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10243U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 38U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (((aWandererA + RotL64(aCross, 46U)) + RotL64(aCarry, 5U)) + 6469584119078165548U) + aNonceWordB;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 14329756366517987910U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 3U)) + 12890831797059772123U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 35U)) + 3164503807500018990U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 27U)) + 177531431387646836U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 3167421392893561015U) + aNonceWordF;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 11U)) + 2813174781844753460U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10953270419153249857U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16911518309710356951U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 13162785997686570445U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6616750447844893150U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10276741398025985982U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6824712685896987133U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6206043608461213208U) + aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12021552904553405793U;
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15283586234744144846U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5923238786775948571U;
            aOrbiterC = RotL64((aOrbiterC * 8200882393521882651U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11044014510971660078U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9351141024085076044U;
            aOrbiterB = RotL64((aOrbiterB * 13316079344614432317U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17703395981862992420U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10154548848376027087U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 12324478347590509035U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8836420852291617425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10193385413543886344U;
            aOrbiterJ = RotL64((aOrbiterJ * 824935982418585449U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 23U)) + aNonceWordE) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aFireLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aFireLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aFireLaneA
        // cross directions: aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneB[((aIndex + 14871U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 14762U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15384U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14834U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11137U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 11480359716598965890U) + aNonceWordN;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 5U)) + 15431182525482873419U) + aNonceWordL;
            aOrbiterB = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 11360504974812776707U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 9292576416573382769U;
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 1549257414531028975U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 5347769463033129317U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 27U)) + 17019199177478377234U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16558106007323125094U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3976182233825939422U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4392162052317572289U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2889047161195954395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2241831345026962605U;
            aOrbiterJ = RotL64((aOrbiterJ * 5757458560979927857U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 12850802412140579294U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13541744735436450160U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 906089290000537439U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2085863085516538212U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2969034221711544086U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 7768528124408400403U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6482666944512391472U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16969153556875844613U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 9483462388353216219U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5161314086757363678U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7150282484670673211U;
            aOrbiterF = RotL64((aOrbiterF * 8522427002337918663U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5465304381272305847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2344610773390354017U;
            aOrbiterK = RotL64((aOrbiterK * 17010258514288089191U), 21U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 42U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 37U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterB, 5U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 52U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aFireLaneB, aWorkLaneD
        // cross directions: aFireLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19375U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 19125U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 19855U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20031U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19927U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 6069475454765660321U) + aNonceWordA;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 29U)) + 11483704742497268068U;
            aOrbiterE = ((((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 11055697447388986418U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 23U)) + 10897095046039997004U) + aNonceWordJ;
            aOrbiterC = (aWandererC + RotL64(aIngress, 60U)) + 4731637118230457840U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 53U)) + 13855839187084986751U) + aNonceWordD;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 47U)) + 5328208115460188239U) + aOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12479538544291412985U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10740165998792608231U;
            aOrbiterE = RotL64((aOrbiterE * 14046827922294477379U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6492798157284955373U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 13056825957483891921U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 14882112110627751751U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2068184064919194657U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5656302738780746294U;
            aOrbiterK = RotL64((aOrbiterK * 16493021179127646345U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11193756120230763294U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17306750816837208999U;
            aOrbiterF = RotL64((aOrbiterF * 7949360041241439741U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12952818800389361804U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15380412293642628312U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 2914662289178925547U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7706090204767242996U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14598802276412649570U;
            aOrbiterB = RotL64((aOrbiterB * 4821408736292041399U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17819762117328075515U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6481384240915075101U;
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((((RotL64(aCross, 35U) + RotL64(aOrbiterB, 6U)) + aOrbiterC) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 37U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 53U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 5
        // ingress from: aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneB[((aIndex + 22331U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((aIndex + 26229U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27209U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 24626U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 39U)) + 8367680518550579791U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 53U)) + 11491674725611181241U) + aNonceWordD;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 16673861720782164214U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 23U)) + 9786610124108350855U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 5745080601557577637U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 60U)) + 1959402215131684684U) + aNonceWordA;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 6121650036079196522U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12016309761037342392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5986936646177049603U;
            aOrbiterF = RotL64((aOrbiterF * 3585650475703294895U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1000367700904043468U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 17425288243569101032U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 2174614006719048535U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4856917474950325209U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16312111093223166419U;
            aOrbiterK = RotL64((aOrbiterK * 11046477664487805241U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 456110002032422270U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11393724374787795662U;
            aOrbiterC = RotL64((aOrbiterC * 1176984359123668389U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8378176867715697176U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8086186452345234815U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 8450438271765985235U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8470349167474173245U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2528229938740192694U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8717790851266520943U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13247168811545753141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8745293957516815264U;
            aOrbiterD = RotL64((aOrbiterD * 14270617180621072619U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 37U)) + aOrbiterD) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aCross, 40U) + RotL64(aOrbiterH, 10U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 6
        // ingress from: aExpandLaneC, aExpandLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 29336U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 32205U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31725U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29308U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 30U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 1952750591494698524U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 21U)) + 4488270851303332830U) + aNonceWordP;
            aOrbiterK = (aWandererK + RotL64(aIngress, 42U)) + 2738763375328927635U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 11U)) + 6728843649480454340U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 35U)) + 10490717875258865358U) + aNonceWordH;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 1429288737812910205U) + aOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 11U)) + 2761375016998907636U) + aNonceWordK;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1088988605204499835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6829840407300289709U;
            aOrbiterK = RotL64((aOrbiterK * 13101432880030791787U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 9267240337867690471U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8120113021183975703U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 14296504593187173107U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1340980511302566784U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11874452169979878835U;
            aOrbiterG = RotL64((aOrbiterG * 8638486178860092537U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 1872314794140971426U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6013952618696225751U;
            aOrbiterI = RotL64((aOrbiterI * 7994863587373565715U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 3644011378086236002U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8501867691997891731U;
            aOrbiterC = RotL64((aOrbiterC * 7115282675461711509U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2493546555198066143U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5179240189571799179U;
            aOrbiterA = RotL64((aOrbiterA * 1267579130962756135U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 11273348247858394197U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4577476419423118925U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 8427261005061162673U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 54U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterK, 11U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + aNonceWordO);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA0704228644183D7ULL + 0x93C216D0DFA11B1BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB790681819A83A37ULL + 0x90747BF9026F1B41ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDABD9F493949819FULL + 0xA579EE04F7E8D7C7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFEA117D015668BABULL + 0xE854237C56B02548ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD5601A8764BA6F19ULL + 0xC928EB470CF46920ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB9A36F2BB2F2AB6BULL + 0xD09A138F3E0A36B4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDA8DBAF88B05F9D7ULL + 0x90FE870E3D351353ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA5750E7342DAE2B9ULL + 0x984B71CF13E00E47ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x81FBAB4C2F67BD2DULL + 0xBCFC742E3D7A9273ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xFEC01248BA3F329DULL + 0xBF46B1C60F79DF31ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9C7707CB05E346B3ULL + 0xBD699CCE38C69CFBULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD2913A8F5826D9E7ULL + 0x93A66940A98E90CDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCF6F4255D12224F1ULL + 0xD39369688F7EB6D6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBEBA29CCAAD823C3ULL + 0xC0D6DF2F266C7037ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x95BBA6DC2EE8EA21ULL + 0xD31D9E7F158BF520ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9438F4A8294F5F4DULL + 0xAA68BDCE636F0A89ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3308U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 1736U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 7923U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3783U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3846U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2092U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 21U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 2783898056762489197U) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 7177192902873343053U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 12U)) + 12254703232691980774U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 27U)) + 15446547245691219559U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 888475203006174856U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 37U)) + 3649183529366307877U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 56U)) + 4642631047518805167U;
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 6108329730724782250U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 5U)) + 8334054653023816636U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 5891895375031474350U) + aNonceWordF;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 53U)) + 3176720746238477862U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6111038696865301675U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11914998302228682704U;
            aOrbiterC = RotL64((aOrbiterC * 11738924766359642853U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17005063057791320948U) + aNonceWordE;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 18333780598768130670U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 5416759844884107303U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2056115016443263153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10245512728872962677U;
            aOrbiterA = RotL64((aOrbiterA * 707106795383284903U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4810366069422162351U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3051442983125942469U;
            aOrbiterI = RotL64((aOrbiterI * 13558537578054436423U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9285068547223654308U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13067251130180968842U;
            aOrbiterG = RotL64((aOrbiterG * 7000687697769766605U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3203670242792002165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1770881716916463461U;
            aOrbiterE = RotL64((aOrbiterE * 13870229847371882171U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16286823712870537410U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13067191141829694202U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15629974528467350445U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3414576315085336932U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8979691827341555245U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 15971594804040295757U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11370607523115189596U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1346943598249651668U;
            aOrbiterB = RotL64((aOrbiterB * 4994794423314630209U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2441719135451272926U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3347272129827184676U;
            aOrbiterF = RotL64((aOrbiterF * 10434510775894776597U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1116857329130532047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2783898056762489197U;
            aOrbiterK = RotL64((aOrbiterK * 9504855173533274401U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 22U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 12U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterK, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterK) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + aNonceWordD);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 28U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 10202U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 9416U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 14638U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneC[((aIndex + 13887U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13217U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15228U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8400U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 18U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + 18302975933754610273U) + aNonceWordJ;
            aOrbiterB = (aWandererB + RotL64(aCross, 23U)) + 16736972646771456082U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 3U)) + 17389406266488137442U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 5252511566486165539U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 5730715427422747640U) + aNonceWordK;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 5U)) + 6412695646456045825U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 21U)) + 9539701605708994494U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 18355107116412945722U) + aNonceWordF;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 29U)) + 11735742491750132942U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 12363819388562658842U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 34U)) + 5861430292304371543U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15027487084595017708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7012850020745791926U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15952928839355613939U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11904871669287886120U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11199760114477343208U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 7156374911847525867U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 3856004502263742700U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3705931243173921893U;
            aOrbiterI = RotL64((aOrbiterI * 10334871178498711485U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12305785390539209389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 18057980996551978823U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4850564181113470859U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3229431819292153014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2994716629242460094U;
            aOrbiterB = RotL64((aOrbiterB * 1029427328395257917U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9796307843453735512U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2957260393651252432U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 7261055869794739609U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4060469664218866340U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17462081697889685330U;
            aOrbiterC = RotL64((aOrbiterC * 7712009170974461225U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13638660073917821172U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15202349592659062565U;
            aOrbiterE = RotL64((aOrbiterE * 4514326257446024301U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12071949111168967041U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11930843273199806728U;
            aOrbiterF = RotL64((aOrbiterF * 16229663295689525137U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11294220104731500296U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 440743185210586759U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14810195235168807229U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8514240764798061804U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18302975933754610273U;
            aOrbiterJ = RotL64((aOrbiterJ * 1972439346780950873U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 10U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 54U) + aOrbiterJ) + RotL64(aOrbiterK, 39U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 10U)) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 5U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 30U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 17116U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 18976U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 20623U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17103U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20306U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23436U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 22300U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 50U)) + 2786079456995203065U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 13U)) + 7237256119153857253U;
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 9310834010563647604U;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 3U)) + 17361734905706517877U) + aNonceWordP;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 21U)) + 15837111231884647451U) + aNonceWordJ;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 18065431964418026445U) + aNonceWordM;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 47U)) + 3029123922999952652U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 11U)) + 5166926595573507837U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 1918425684273807598U;
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 4724551751012661440U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 4U)) + RotL64(aCarry, 27U)) + 1818014487579644390U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6670090372241084216U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8485757110007268693U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 11876760095108618363U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4928130251509514742U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2528788422725346792U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1855982047967756661U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2860387120895147503U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12927802338151379368U;
            aOrbiterE = RotL64((aOrbiterE * 8876144125458603029U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18029699867733207083U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13361836994951253312U;
            aOrbiterG = RotL64((aOrbiterG * 5349767426256597073U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11957294454794128079U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3755417922063414648U;
            aOrbiterD = RotL64((aOrbiterD * 13896364063651241401U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18001157153447913032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16214145724690286854U;
            aOrbiterC = RotL64((aOrbiterC * 5874139687703360515U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3860958772090975562U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12395621524459640173U;
            aOrbiterH = RotL64((aOrbiterH * 722817135977510161U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3402035664910754484U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2139099117325745602U;
            aOrbiterI = RotL64((aOrbiterI * 14008983756425796029U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 7769274487425053026U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6492669707749367728U;
            aOrbiterJ = RotL64((aOrbiterJ * 5149771861620757839U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14963366447884375043U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11398874662567519691U;
            aOrbiterK = RotL64((aOrbiterK * 8221521452475029835U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7168445485232814860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2786079456995203065U;
            aOrbiterF = RotL64((aOrbiterF * 14258367164534307955U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 26U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterE, 10U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterG, 4U));
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + aNonceWordE) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31774U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 31994U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26324U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 28875U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31478U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30187U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 31327U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 53U)) + 14249093584376402677U) + aNonceWordN;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 11U)) + 8756965951816492264U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 11221139480258176330U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 19U)) + 17218894445564194851U) + aNonceWordC;
            aOrbiterD = ((((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 8064642692524949490U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 51U)) + 5822093203710704646U) + aNonceWordP;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 24U)) + 3217799620158102238U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 37U)) + 2613757677892120843U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 35U)) + 13647481499551657237U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 27U)) + 3545714196663685016U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 30U)) + RotL64(aCarry, 19U)) + 9735422670576621521U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3911046580637583767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9315984027042049203U;
            aOrbiterH = RotL64((aOrbiterH * 12568550776487242469U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8926367674641729058U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11035347490524961446U;
            aOrbiterI = RotL64((aOrbiterI * 10948288997163592463U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10748158733051120339U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2467801787989056455U;
            aOrbiterA = RotL64((aOrbiterA * 12621934274702358977U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9244415080474351390U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8517784887959492079U;
            aOrbiterF = RotL64((aOrbiterF * 17022899813765884147U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8409307332803038455U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11043806021873232950U) ^ aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8294888329708842989U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17512395828450251457U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16849067939795823992U;
            aOrbiterJ = RotL64((aOrbiterJ * 9361991804481514337U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 17541946638063238056U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11430501673960586718U;
            aOrbiterB = RotL64((aOrbiterB * 15074409630605450091U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 78307505705383302U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4834528975263832983U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 17245673681686752861U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9647985402149698269U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6610247710757518931U;
            aOrbiterC = RotL64((aOrbiterC * 8672486173272686859U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 2706696306041774372U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9519896513600816252U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7468605169665549731U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14647351223431646222U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14249093584376402677U;
            aOrbiterD = RotL64((aOrbiterD * 8296105266618697281U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterA, 36U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 13U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterI, 38U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB51260EB33B25FDDULL + 0xFADD841F1730D996ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFA024F059865E8D9ULL + 0xC703304C0E2A9BA5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8A0E135A9CCBF4EBULL + 0xF847103BE689F445ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAA3A72ED690D14E7ULL + 0xF2B544322B27657AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE65DD3E3F86BA885ULL + 0xA9E412A8EE8088FFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x97547AFBD27394C7ULL + 0xC410A041AC0BCD56ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB69FF81585E4B257ULL + 0xD366B441F562F336ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9ECEE12857FA46B1ULL + 0xEAA391DBA67FDC3CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9062C7171407F8A9ULL + 0xFD4AF79AAAF6313AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFD50D640E733F03FULL + 0xCF4D47745188F780ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xECC745C74B3909D3ULL + 0x8D811C1FE0C9E4BEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9A9B12B793BDC4D3ULL + 0xF99123EE003766C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x87FB1B4D3A119749ULL + 0xE8B6716907717464ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA25C439F28D44C6BULL + 0xF8957C9143CC765FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x9A36E85E80F9C60BULL + 0xD602C2798FBBEE86ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF06DEEA2DBECECD1ULL + 0x914A145EDCFF0256ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aWorkLaneA, aWorkLaneB, aExpandLaneC, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1636U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((aIndex + 7835U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3838U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8178U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6180U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 294U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 17936518874386450467U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 3U)) + 13722737841589910344U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aCross, 18U)) + 11774969167948715796U) + aNonceWordN;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 3640101505680493777U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 47U)) + 1369495382725650822U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 11827310354654653345U) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aCross, 57U)) + 186037671377175394U) + aNonceWordL;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 13U)) + 11428829344234627340U) + aNonceWordP;
            aOrbiterH = (aWandererA + RotL64(aCross, 30U)) + 2275016369870029068U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15471646673734798328U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 12172082573115640145U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 9629417882787847753U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 6626736341348283154U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12220614992483863623U;
            aOrbiterJ = RotL64((aOrbiterJ * 8137086205714097487U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13157102324253760215U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4143587482368093601U;
            aOrbiterG = RotL64((aOrbiterG * 5060677690991506895U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11007575246013796426U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11721585930088637162U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15009627907125738519U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5720789204450196217U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3094696226821431648U;
            aOrbiterA = RotL64((aOrbiterA * 4412033981712165541U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14675830108100986773U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 9444071495289719645U;
            aOrbiterE = RotL64((aOrbiterE * 10983136361953366557U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5106753847015199956U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7585421898593510010U;
            aOrbiterB = RotL64((aOrbiterB * 140996914192351011U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11746948407655524690U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16336323220286344483U;
            aOrbiterH = RotL64((aOrbiterH * 6590417628835864497U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8030445186765781136U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 276034088015165891U;
            aOrbiterK = RotL64((aOrbiterK * 7626025612710225099U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 22U)) + aOrbiterK) + aNonceWordO);
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterE, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 35U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + aNonceWordG);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 18U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13094U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 9164U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 12176U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 9572U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12864U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8402U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14576U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 34U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 3448371607470865612U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 3743742913651580573U) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 58U)) + 13069491287948807280U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 16872779275586545632U) + aNonceWordI;
            aOrbiterA = (aWandererF + RotL64(aScatter, 13U)) + 17945792656755062795U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 23U)) + 18199747196793731853U) + aNonceWordL;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 46U)) + 15953311878379809513U;
            aOrbiterB = (aWandererE + RotL64(aCross, 5U)) + 941268763494588338U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + 10090221530365796809U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8335698093307607001U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6147498804734306100U;
            aOrbiterD = RotL64((aOrbiterD * 6904444049941211327U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5980246079567570090U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4152167624425912978U;
            aOrbiterI = RotL64((aOrbiterI * 10019421651535123573U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14990418790239735916U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3418668387496597219U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4206650904177199425U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3905470780938996069U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 16030122739273137005U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9968672788233080924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 602258075661864866U;
            aOrbiterJ = RotL64((aOrbiterJ * 2615726693066300065U), 53U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 17751667243048041383U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2414054413585296027U;
            aOrbiterF = RotL64((aOrbiterF * 1049512574773201893U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6523322402744047752U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6729901917767398779U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8039939871405367139U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11460169185076814539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7559640379553110573U;
            aOrbiterH = RotL64((aOrbiterH * 9864654321914036135U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17271150091827475028U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3541809324556914646U;
            aOrbiterC = RotL64((aOrbiterC * 12655168871428868639U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 5U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterA, 58U)) + aNonceWordC);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterC, 12U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneC, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23940U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 18556U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21991U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 23558U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20068U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19430U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16474U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aCarry, 38U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 14U)) + 8793908991006073956U) + aNonceWordI;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 37U)) + 2932916283348441943U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 11069042087940968262U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 14369628676782894441U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 23U)) + 8602903272780978282U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 3827036107178568820U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aIngress, 44U)) + 8905245209036772489U) + aNonceWordF;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 19U)) + 13331387530760017893U;
            aOrbiterI = (aWandererF + RotL64(aCross, 53U)) + 9880107580289737823U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10199619040626900278U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2466307560891374281U;
            aOrbiterA = RotL64((aOrbiterA * 6295342978834217571U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13973403407981259448U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2851460278409385243U;
            aOrbiterD = RotL64((aOrbiterD * 11226902976321781743U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10365453393815690776U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2382382358987358791U;
            aOrbiterH = RotL64((aOrbiterH * 481563628980705781U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5058198848163792422U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10500434740387593487U;
            aOrbiterF = RotL64((aOrbiterF * 5946747708776079787U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 11289798395177667084U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14327152153231286666U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 18155778059595245561U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8065137263811956313U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3865153574847924816U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9495741102667755161U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 18102279969722473375U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6306428427188742325U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 17826782872351406167U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16953348204663693724U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11950791817032898613U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 1498946055469611133U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11980823193543752994U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17845490308799454871U;
            aOrbiterG = RotL64((aOrbiterG * 16385153013485463791U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 18U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 57U)) + aOrbiterK);
            aWandererG = aWandererG + (((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 39U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 48U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterB, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB, aWorkLaneD
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25867U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 32440U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 25668U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 28452U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31559U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27232U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 28889U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (aWandererJ + RotL64(aIngress, 47U)) + 2168513956284366370U;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 10290361969974613111U) + aNonceWordC;
            aOrbiterA = (((aWandererB + RotL64(aCross, 30U)) + RotL64(aCarry, 39U)) + 15673836275828498050U) + aNonceWordD;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 23U)) + 16600540024145812236U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aCross, 57U)) + 9428052101528111892U) + aNonceWordK;
            aOrbiterC = (aWandererE + RotL64(aScatter, 41U)) + 12763657928312763377U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 51U)) + 10751286982008662485U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 14U)) + 1708230173038057979U) + aNonceWordP;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 4011389705422783816U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11704428328093077714U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2055336619674699284U;
            aOrbiterA = RotL64((aOrbiterA * 6374289210096410907U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 1870865272102705804U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 3574214263751923179U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 984611970726966186U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4181398506373973169U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15222345431506025949U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6925143692628659467U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15023513452326240962U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14965669361708810699U;
            aOrbiterI = RotL64((aOrbiterI * 587008860996713147U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7985755518735406360U) + aNonceWordG;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 225592097619240187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3659537916566939383U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17043668033610689611U;
            aOrbiterE = RotL64((aOrbiterE * 10797634709118100773U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10217321522161675848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8013663869536146842U;
            aOrbiterH = RotL64((aOrbiterH * 2293233079384777175U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13762445330867496042U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2692400019659269106U;
            aOrbiterG = RotL64((aOrbiterG * 167704184292219399U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 14U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 57U)) + aOrbiterC) + aNonceWordO);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterK, 36U)) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 43U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC132759586FAFA8DULL + 0x88332B8A5C1F6ADCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFDE592856715054DULL + 0xF21819117AD6096BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC9299996C91D5D0FULL + 0xEB5575604F3EE48BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x92464DE599B9479BULL + 0xB9735DCCD5754D29ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD36561EED60D909DULL + 0x9F92A17D272EA2E8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC1B43E160DB8DA9BULL + 0xA096C30712A8851DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x92A194B9AB292C71ULL + 0xCC80B74980B2E95AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDC61D716A1D4EECBULL + 0xD6A76A84FD219B33ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x88707BD859231EB3ULL + 0xCD73F205814B5D86ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD8656061422D0F79ULL + 0xE11FDB3A92D26CEFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF5F9B53DFE039581ULL + 0xD3263F78915D68D6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAD2287EE01F94B6BULL + 0xBD1FAE513BC63142ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD2DB1A012706A56BULL + 0x8F4FE68B61A4FE5EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB59EEE4C7614C497ULL + 0xB9A7C9E467FD711FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF5AC4D384B4A4A01ULL + 0xB7A6681C69B0CF87ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA65F1D9C3BA93B69ULL + 0xFDEC8EDC2E08CD33ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aFireLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneC, aOperationLaneC, aOperationLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 597U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 5041U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 1840U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6346U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5754U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 7619U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 11698283336767769359U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 13297826354831483872U) + aNonceWordC;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 13U)) + 15254999058287530795U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aIngress, 57U)) + 17474166585085346567U) + aNonceWordF;
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 15684783498452840289U;
            aOrbiterG = (((aWandererK + RotL64(aIngress, 26U)) + RotL64(aCarry, 29U)) + 5061229733465216486U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 5U)) + 15370981279168377944U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 17966672773619554092U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14685092893994491068U;
            aOrbiterI = RotL64((aOrbiterI * 1627758964162892429U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12798804186209406389U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 2848444181474221574U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 13730480364920876877U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8551142075919636146U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8833198159158950723U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7650289040764974737U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7351473160893666232U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14204899612487622222U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6317485031956448029U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7008985178526543258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13576796403863120356U;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5769784656937900699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14075925808204936705U;
            aOrbiterK = RotL64((aOrbiterK * 5844894088757604713U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 17818667502858010896U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16016922065572683130U;
            aOrbiterF = RotL64((aOrbiterF * 7525645833898085373U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 43U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterG, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aWorkLaneD, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aWorkLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9570U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((aIndex + 15949U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 12754U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14769U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14704U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8987U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9827U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 57U)) + 2101601659597850213U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 34U)) + 2759794072560720121U) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 53U)) + 9443562552411269339U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 47U)) + 10801360546699857975U) + aNonceWordK;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 19U)) + 8020716394829332019U) + aNonceWordO;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 1021894212367773801U;
            aOrbiterK = ((((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 13346855534622490176U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16359309548462953836U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12642446944680783519U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12197935153255283321U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8197424982767553380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14346334610901859094U;
            aOrbiterI = RotL64((aOrbiterI * 16982899923227935679U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14171304260534233539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 334531601308283605U;
            aOrbiterE = RotL64((aOrbiterE * 5012968232749075075U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10707856298471572695U) + aNonceWordP;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 18364775750091914766U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15735143943129143265U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8531394793118363836U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15352876929406908882U;
            aOrbiterC = RotL64((aOrbiterC * 475199047053777179U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 567682016232278157U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2068146551757663119U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1557877740957797555U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 7776122587613256525U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16430938890724272256U;
            aOrbiterA = RotL64((aOrbiterA * 4540270493783593257U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 60U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneC backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20866U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneA[((aIndex + 21734U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 17439U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 18747U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17318U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21081U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 22710U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 16183871922837164759U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 6U)) + 7002058258090219055U) + aNonceWordA;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 35U)) + 5650868611888303705U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 11899839660943876690U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 41U)) + 15349649504488111111U;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 14060149569086744970U) + aNonceWordD;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 27U)) + 12920917574225030112U) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2831994965175330135U) + aNonceWordF;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 18312543585028439192U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 11618182708195744321U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11657562205118394239U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10850792819281246052U;
            aOrbiterH = RotL64((aOrbiterH * 10663100544207879337U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17810371216216125323U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7963413941144223128U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 534217972450595401U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5498715358793875584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9256727548911651373U;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17246360111302191699U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18309978718113983369U;
            aOrbiterK = RotL64((aOrbiterK * 18267472694666221077U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3100998994319502921U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterG) ^ 8129301860291235970U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 17847033539279176187U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1889641029473279114U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16538494307002917945U;
            aOrbiterF = RotL64((aOrbiterF * 8081488217920885783U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 36U) + aOrbiterG) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterC, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererH = aWandererH + (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterD, 28U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31719U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 28499U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 24786U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28685U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31616U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26848U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 25729U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + 9774364261626083532U) + aNonceWordC;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 13U)) + 18059001521926116420U) + aNonceWordA;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 53U)) + 10615626210406381148U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 10536484278007898620U) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 13320663045139972700U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 60U)) + 17127001787268166583U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16742574590844166551U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8347719720758228053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13502468705946051986U;
            aOrbiterI = RotL64((aOrbiterI * 13822952083584784695U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3512687886188904904U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 495660316165795934U;
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 5092722552034477356U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15641128019608284015U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 3621036395703527059U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15421873776811085458U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 17978775513204574125U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16617179197537669849U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 1931805387534012528U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3400139345857733775U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9544923119559308431U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12930999400470173353U;
            aOrbiterK = RotL64((aOrbiterK * 16791006919271490005U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 13673733276226249890U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2032263473309124738U;
            aOrbiterE = RotL64((aOrbiterE * 3088728329261360607U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 54U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordE);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + aNonceWordF);
            aWandererF = aWandererF + ((((RotL64(aScatter, 22U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterD, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCE2DF5D899855F9BULL + 0xB14F3C3289912FBCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB05627AA6027EA83ULL + 0xC32DBB059CC83940ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA197DA8CB4C4EFAFULL + 0xCAFD2F4AE75A1FAAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF77D88B90B7C0117ULL + 0xA365074A26A8A555ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE62AF9C780A725C1ULL + 0x80303629E074D86EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE4603D761082A23DULL + 0xCF4855ED23A4D11BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCFE1C2340A75D127ULL + 0xC8602252D88C05ECULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA108EA5859712EB5ULL + 0xCAF249D99B40C9B7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF6932A532621B439ULL + 0xA5EDCDA435D50ABBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB1CD363FC6D63C55ULL + 0xCA325915483C7FAEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBA9DC6B205752B87ULL + 0xC79E5D74DB31DD4EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC53D3C37D0B2C61DULL + 0xE160503500D246BDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x96D4750D2E00F4B7ULL + 0x8D5C03878D8566C3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC77F05EB11D83A6FULL + 0xF032D4E40E02C30EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAD041DDF284DAC5FULL + 0xE7C425436B03CA00ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEB15D66497A50DCDULL + 0xC55DC729B6EFE955ULL);
    // GSeedRunSeed_A seed_loop_a (start)
    {
        // GSeedRunSeed_A seed_loop_a lane group
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1422U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1537U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2677U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 2013U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 21U)) + 9774364261626083532U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 51U)) + 18059001521926116420U) + aNonceWordC;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 10615626210406381148U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 10536484278007898620U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 13U)) + 13320663045139972700U) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 17127001787268166583U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 51U)) + 16742574590844166551U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8347719720758228053U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13502468705946051986U;
            aOrbiterI = RotL64((aOrbiterI * 13822952083584784695U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3512687886188904904U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 495660316165795934U;
            aOrbiterB = RotL64((aOrbiterB * 6724596801190194913U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5092722552034477356U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15641128019608284015U;
            aOrbiterC = RotL64((aOrbiterC * 3621036395703527059U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15421873776811085458U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 17978775513204574125U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18359600395119440183U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16617179197537669849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterF = RotL64((aOrbiterF * 3400139345857733775U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9544923119559308431U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12930999400470173353U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16791006919271490005U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13673733276226249890U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2032263473309124738U;
            aOrbiterJ = RotL64((aOrbiterJ * 3088728329261360607U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterF, 60U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 5247U)) & S_BLOCK1], 51U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2910U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4192U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 4941U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 5295352595333316211U) + aNonceWordJ;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 11U)) + 2341795367042042605U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 37U)) + 10122175780504033663U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 22U)) + 10084612804696198554U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 47U)) + 16470424309851045971U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 37U)) + 656016130975227994U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 51U)) + 15313268829659834317U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3795220914993923394U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14044442220988813825U;
            aOrbiterE = RotL64((aOrbiterE * 3270650852546606835U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 3804224626734584802U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7980006306010255693U;
            aOrbiterB = RotL64((aOrbiterB * 13958505239726088561U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13746830564584711549U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11852212099729274845U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2164880979318247855U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 9083223471018084847U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13706723820703853346U;
            aOrbiterA = RotL64((aOrbiterA * 11361854103656219887U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1713819986642275223U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1382000168233902914U;
            aOrbiterD = RotL64((aOrbiterD * 3894160765130198157U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4540474625764565485U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1756168174375757220U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 12739160208010092017U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1409297070183609309U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6082750101445444357U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17438740230251860935U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + aNonceWordA);
            aWandererG = aWandererG + (((((RotL64(aCross, 12U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 47U)) + aNonceWordP);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 58U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 5479U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadB[((aIndex + 5569U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7028U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6785U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 6905U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 27U)) + (RotL64(aCarry, 58U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 6521330037475130256U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 12611880456055428940U;
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 12061611078130934708U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 1558112410801116984U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 41U)) + 10509115227850160786U) + aNonceWordG;
            aOrbiterK = ((aWandererK + RotL64(aCross, 30U)) + 4045915960688792066U) + aNonceWordC;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 19U)) + 1196541286513243082U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15564991032722373702U) + aNonceWordE;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 4897765238703641798U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 9693901276712946763U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12327429514907752733U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6189189797708711636U;
            aOrbiterE = RotL64((aOrbiterE * 9017615866338877651U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6374267075282018852U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 1888758503831341439U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 74387714918264257U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14956857689299491800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14879361107223331957U;
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16086885494838105042U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8069724185844303923U;
            aOrbiterK = RotL64((aOrbiterK * 8878470736758734353U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10854345917959911439U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7078313614360332089U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9864025732292844871U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15083669236062255011U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 594879695916679116U;
            aOrbiterD = RotL64((aOrbiterD * 9852515479152735283U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 12U) + aOrbiterE) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aNonceWordH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 34U)) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 10109U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 9050U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(mSource[((aIndex + 8660U)) & S_BLOCK1], 50U) ^ RotL64(aFireLaneA[((aIndex + 9402U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9115U)) & W_KEY1], 37U) ^ RotL64(aFireLaneB[((aIndex + 8589U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 23U)) + 964165145848253292U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 10645976767204934746U) + aNonceWordO;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 29U)) + 8241612229349212650U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 53U)) + 4159196033256913347U) + aNonceWordA;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 38U)) + 7194795864620233507U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 7638928444536778384U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 11819105916503968109U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 18052213302858186237U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8663575313970041570U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14131073322476609161U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterJ) + 16644136720439299786U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 16930316530442679864U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 2650922074098320859U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 16251107616988250593U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7171986193609401665U;
            aOrbiterC = RotL64((aOrbiterC * 3543709971414550087U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 17885046834432626644U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterJ = RotL64((aOrbiterJ * 15766885299397923879U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 2212805322061155615U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6368539134638838822U;
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5264326094252925613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6126345334815012938U;
            aOrbiterK = RotL64((aOrbiterK * 17180934809764905307U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13826731214018407061U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 6621261811613643620U;
            aOrbiterH = RotL64((aOrbiterH * 2823596473596114171U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 12U)) + aOrbiterK);
            aWandererA = aWandererA + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterH) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 42U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 11397U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[((aIndex + 11129U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11882U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 11759U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13032U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12752U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 11207U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 7948891781097675369U;
            aOrbiterB = ((((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 51U)) + 13928362874228230226U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (aWandererE + RotL64(aScatter, 35U)) + 10776180542602258926U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 53U)) + 5735115172149470447U) + aNonceWordF;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 5U)) + 5353591822981766987U) + aNonceWordI;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 5U)) + 562301708107268570U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aWandererG + RotL64(aCross, 29U)) + 10467810247578364868U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14541630141152308564U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 2350076897065139429U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12222554362482034393U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17519109078651162228U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6061035173339902910U;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 15654836633731000065U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 13723521735153718904U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2849680038315532197U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17336102435576647923U;
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7671010488872356142U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11485114338165600777U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4162584865462407791U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 8759060657343458985U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11009137869375286581U;
            aOrbiterB = RotL64((aOrbiterB * 8741417343929809115U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15792999392743144135U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 41U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterB, 20U)) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterD, 11U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterK, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 15380U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16264U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15035U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15417U)) & W_KEY1], 47U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14196U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15291U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15720U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 11700815697312060726U) + aNonceWordK;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 47U)) + 11808423452327465441U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 35U)) + 8670503858631730886U) + aNonceWordA;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + 2400061067991988544U) + aNonceWordI;
            aOrbiterB = ((aWandererB + RotL64(aCross, 26U)) + RotL64(aCarry, 5U)) + 16163118178366229686U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 3280178595904941068U) + aPhaseFOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aIngress, 11U)) + 3298683600817047727U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16321624053445183574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6730229877611375225U;
            aOrbiterJ = RotL64((aOrbiterJ * 2022290495153519279U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10162830636713641322U) + aNonceWordL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15646771327759599256U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15333053762177144775U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14841751262270544102U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9545541117228834895U;
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14676615635857599982U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1231768638470558855U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2716808508509014677U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1945905595345404833U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1406171421638586846U;
            aOrbiterD = RotL64((aOrbiterD * 4577864352425476233U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1970292335806697198U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12309719390375013297U;
            aOrbiterI = RotL64((aOrbiterI * 16540660957923687327U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 5352135521358954576U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15465675376193501658U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16385761112921041387U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aNonceWordE) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 44U)) + aOrbiterI) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 12U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16926U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadA[((aIndex + 16883U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 17886U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((aIndex + 18819U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17550U)) & W_KEY1], 3U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18612U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 18453U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 43U)) ^ (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 5U)) + 6069475454765660321U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererJ + RotL64(aCross, 57U)) + 11483704742497268068U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 13U)) + 11055697447388986418U) + aNonceWordJ;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 5U)) + 10897095046039997004U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 21U)) + 4731637118230457840U) + aNonceWordO;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 13855839187084986751U) + aPhaseGOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 19U)) + 5328208115460188239U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12479538544291412985U) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10740165998792608231U;
            aOrbiterB = RotL64((aOrbiterB * 14046827922294477379U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6492798157284955373U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13056825957483891921U;
            aOrbiterK = RotL64((aOrbiterK * 14882112110627751751U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2068184064919194657U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5656302738780746294U;
            aOrbiterD = RotL64((aOrbiterD * 16493021179127646345U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11193756120230763294U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17306750816837208999U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7949360041241439741U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12952818800389361804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15380412293642628312U;
            aOrbiterA = RotL64((aOrbiterA * 2914662289178925547U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7706090204767242996U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 14598802276412649570U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 4821408736292041399U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17819762117328075515U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6481384240915075101U;
            aOrbiterF = RotL64((aOrbiterF * 4836701121865783029U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterF, 36U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseGWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE + ((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20603U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 21211U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19371U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneA[((aIndex + 20372U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21739U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19526U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20309U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((aIndex + 20910U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 16451272412693907816U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 37U)) + 10099485419723255462U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 17668900099534923192U;
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 5497093724143181753U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + 10354044773550071706U) + aNonceWordE;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 29U)) + 12728258851198019099U;
            aOrbiterH = (aWandererA + RotL64(aCross, 50U)) + 4144050505314242618U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14133805325480076530U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 308863673210602899U;
            aOrbiterJ = RotL64((aOrbiterJ * 2672613556981540433U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11741180130160569753U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12926863156769180448U;
            aOrbiterE = RotL64((aOrbiterE * 9726030996091054939U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 211920854786494259U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13234608842479411078U;
            aOrbiterI = RotL64((aOrbiterI * 2556747209733759467U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 9164711974854618892U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6667377062281954219U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 2603737166987437649U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4559040002406721850U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1749875480850675109U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15822640067349481089U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9555365165561936366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 18289733999504213574U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8727162691639622461U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 291406782452963706U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8413500075082350243U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aNonceWordK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterC, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterC) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 6U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23096U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 22692U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22386U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 24217U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24214U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22506U)) & S_BLOCK1], 52U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24007U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneD[((aIndex + 21963U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 51U)) + (RotL64(aIngress, 3U) + RotL64(aCarry, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 3U)) + 8020711767807230555U) + aNonceWordC;
            aOrbiterK = ((((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 15368693777246341570U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 5117523734225562401U) + aPhaseGOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 13155269151097507808U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 12U)) + 9879303753623578272U) + aNonceWordN;
            aOrbiterF = (aWandererI + RotL64(aIngress, 41U)) + 1165799257173794826U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 930641942062732091U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11330571332221123153U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2862963158282518899U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 13782195862525974199U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6019186399361476659U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1924419843785161958U;
            aOrbiterI = RotL64((aOrbiterI * 9485557122500346869U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12618629043591380461U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9334176504266512405U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 18239109235362925739U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 16829692481030013551U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5604784396927022709U;
            aOrbiterH = RotL64((aOrbiterH * 2833893610883508353U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16124030106598549644U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16571659812830230677U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 4668250364992383549U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15171089673591843703U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 2826755560293849328U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9397017963457655287U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9976785768283589291U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11845100564714691809U;
            aOrbiterD = RotL64((aOrbiterD * 4935139932585319251U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 14U)) + aNonceWordK) + aPhaseGWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterI, 47U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + aNonceWordI);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 22U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26133U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 25776U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 26329U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 26731U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25656U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26541U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25049U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 25628U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 13U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 13U)) + 7893287783892523139U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 10257331997383491153U) + aNonceWordH;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 14562226733652231753U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 14320342577110737851U) + aNonceWordP;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 37U)) + 9816717579822880756U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 50U)) + 9558926960095881953U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 5U)) + 9230371862654338324U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 6414274291252913420U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13868546184398350849U;
            aOrbiterF = RotL64((aOrbiterF * 1547986864837497409U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16940736952569949038U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2866957764814864371U;
            aOrbiterK = RotL64((aOrbiterK * 3554702178644797003U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7916721976073979724U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1602444214978842275U;
            aOrbiterG = RotL64((aOrbiterG * 11072503711308122385U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9529061385251008037U) + aNonceWordJ;
            aOrbiterC = (((aOrbiterC ^ aOrbiterA) ^ 8402775110887376588U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15003592180290390713U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14195681406520825751U;
            aOrbiterH = RotL64((aOrbiterH * 11455000833788877217U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3263577002367714202U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 12019422062655581928U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5002313835338447799U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8508638054582582917U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6536618106353552880U;
            aOrbiterI = RotL64((aOrbiterI * 6233964121117511885U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 57U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterG, 34U)) + aPhaseHWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterK, 11U));
            aWandererF = aWandererF + ((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29977U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((aIndex + 28702U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29313U)) & W_KEY1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 28668U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29187U)) & W_KEY1], 6U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29963U)) & S_BLOCK1], 53U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29374U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 27969U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 57U)) + 18180797995100240808U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + 6585906608223552885U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 37U)) + 14088708930575939855U) + aNonceWordA;
            aOrbiterK = ((((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 468974153311516044U) + aPhaseHOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 12481951025619894110U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 17227987923860711763U) + aNonceWordI;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 11U)) + 4373962756657477139U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2077576476565420951U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17435011300234663764U;
            aOrbiterF = RotL64((aOrbiterF * 8910133867294004711U), 11U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 4118039398293246896U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13724716599855216683U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 17556333902751079677U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12391461204689596339U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9900605191533799627U;
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 972946858824366125U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17247681919694541215U;
            aOrbiterE = RotL64((aOrbiterE * 2974639094630445643U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 15442851427306771601U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7303586227288294037U;
            aOrbiterJ = RotL64((aOrbiterJ * 15406402525021428799U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12650358753454105119U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1483710933373510492U;
            aOrbiterG = RotL64((aOrbiterG * 6531763256577221891U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18065810162229740788U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11311677121338794007U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15116367961682119467U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + aNonceWordP);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 54U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterD, 47U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aNonceWordB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30518U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32044U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30370U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31947U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31387U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 32278U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 57U)) + 2617613537256538553U) + aNonceWordO;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 16642868916835132715U) + aNonceWordH;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + 10860291124337073254U) + aPhaseHOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aScatter, 27U)) + 6432511273906902472U) + aNonceWordP;
            aOrbiterI = (((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 7505375005848241910U) + aNonceWordK;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 47U)) + 11086616004678821329U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 21U)) + 3298830587569881951U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 9775143140064220979U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4147601326580823120U;
            aOrbiterJ = RotL64((aOrbiterJ * 13462244678782260871U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12245920269898100415U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8391940489176734499U;
            aOrbiterH = RotL64((aOrbiterH * 9119606167674098007U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17876893379544668477U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 18301882058180370541U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 16680384667098921309U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 6869225862715140102U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 41U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 17757381020518233814U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17677969146092374455U;
            aOrbiterE = RotL64((aOrbiterE * 3469432916562405063U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15783378556632870114U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5792858258663697864U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 12008981883482080427U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11737803388202260296U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterE, 38U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aNonceWordF) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aPhaseHWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 44U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEEA9E8F8474FB283ULL + 0x9CF655541C0F1EB4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA3C479FE777D15CDULL + 0xCDF85C9F2D8AE0AFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9DA829BECF86D9A3ULL + 0x9AE5A870114BDA22ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFF2B0318CB4AEF6DULL + 0xFEEF45B4D97096D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE5BA4A6A3ABCD029ULL + 0xA342A5E6132A86B8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8B7B1D1B97DCCC83ULL + 0xADF22C2A3EF85FB0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAAC8BC1FF53207FFULL + 0xEA5D5AD0DEF1A066ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x834762C7C93B9023ULL + 0xE128D96F6CAD98CBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAA3BA8A81FC0ED03ULL + 0xC8AC41F0FF1C04CBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC3608BF1A746AC69ULL + 0x83C7E18C17CA8F1EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF003E49C3C5F48D3ULL + 0xBF87F7431D622615ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFE448707B7551743ULL + 0xBA87A9A10B27E6F7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xDC1F3F94821AEDAFULL + 0xC4507FE7EB943A4FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF0A4A70216045753ULL + 0xC50B4AB765B67381ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF43F1AC216C64747ULL + 0xBD97EB961AF1EB41ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x89E242EDC0AF204FULL + 0xE805751CB1A8DD0FULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aInvestLaneA, aFireLaneC, aFireLaneD, aInvestLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1488U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 4815U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4063U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2670U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4845U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 4185U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererF + RotL64(aScatter, 19U)) + 252059974543142812U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 11690823093681457368U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (((aWandererE + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 13282189752890971123U) + aNonceWordN;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 9507416294305708435U) + aNonceWordF;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 57U)) + 14053038174390776539U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14605253312318725009U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 18138286582677863671U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 10595905899691011321U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8530091235978489988U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14381731677571170073U;
            aOrbiterK = RotL64((aOrbiterK * 11675896999665768253U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 13316413456378978456U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3910529530149320706U;
            aOrbiterH = RotL64((aOrbiterH * 16000139333493588429U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6302070286831566901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12324134652758551396U;
            aOrbiterA = RotL64((aOrbiterA * 17136438281540250165U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 4773478557638475048U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4031153435446078944U;
            aOrbiterE = RotL64((aOrbiterE * 3876928995240982769U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 39U)) + aOrbiterH) + aNonceWordP) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 52U) + aOrbiterE) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 4U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9656U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 9251U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5990U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8117U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10839U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9278U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5744U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 27U)) + 7075016829833562104U;
            aOrbiterA = (aWandererH + RotL64(aCross, 34U)) + 8783765886115517036U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 2996723892384565829U) + aNonceWordP;
            aOrbiterF = ((((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 9494134707342189476U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 11U)) + 5052642981395679904U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8766787055127962238U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4467211954388738079U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 8599295330343804047U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8030255604633658608U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16962408063455702251U;
            aOrbiterD = RotL64((aOrbiterD * 11171737929747471631U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3768222186567699076U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 14930990410207899871U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 10930005786146268241U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14179761938395502502U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1879084742719898108U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16783034788172670121U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5535012408925981515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12792553516710295939U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 12U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 54U) + RotL64(aOrbiterD, 35U)) + aOrbiterI) + aNonceWordL) + aPhaseAWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 29U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + aNonceWordB) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneA, aWorkLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneC
        // cross directions: aInvestLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12527U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 13654U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 11359U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 15457U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 15055U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 17225673071833726819U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 10301458382103627331U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aScatter, 13U)) + 3960233050857362414U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 34U)) + RotL64(aCarry, 3U)) + 17768665685046605837U) + aNonceWordA;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 21U)) + 14471018461213959767U) + aNonceWordG;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10730597892721340453U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14863394003122760542U;
            aOrbiterC = RotL64((aOrbiterC * 17731557030589257169U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 9948587274816688296U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3573569431435100993U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2303922230056523077U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 8153670675740450590U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 16438856577722561424U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 4689247488336908827U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15765587867581925041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1082039522061775213U;
            aOrbiterI = RotL64((aOrbiterI * 17023740047246402641U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4202521649260798876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15877659681260461141U;
            aOrbiterB = RotL64((aOrbiterB * 11369910758551088173U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 52U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + aNonceWordM);
            aWandererF = aWandererF + (((((RotL64(aIngress, 48U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U)) + aNonceWordL) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 35U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 4
        // ingress from: aOperationLaneA, aInvestLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aInvestLaneB, aExpandLaneD
        // cross directions: aInvestLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16414U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 21388U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19546U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19541U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 21642U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + 1888427424966603593U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aIngress, 34U)) + RotL64(aCarry, 5U)) + 5436761445660415091U) + aNonceWordC;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 57U)) + 17322876217962143270U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 9728299982740564979U) + aNonceWordH;
            aOrbiterK = ((((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 301720335271716921U) + aPhaseAOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8069685428854814396U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1973715500949100991U;
            aOrbiterA = RotL64((aOrbiterA * 7940531594430629427U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 87666408799854155U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 12195436904339035245U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 15427739165893738105U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4578742069143400295U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7828776048774876484U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 4047964518501081039U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17203146364542781833U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16913369550858890466U;
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 9632761514552265402U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9106637671877341286U;
            aOrbiterG = RotL64((aOrbiterG * 9073709119482640391U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterA, 22U)) + RotL64(aCarry, 5U)) + aNonceWordG) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aPhaseAWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 5
        // ingress from: aOperationLaneB, aInvestLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aInvestLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aInvestLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26818U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((aIndex + 25621U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23237U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24482U)) & S_BLOCK1], 57U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22010U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 36U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + 3684295017013759987U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 6740408842457292881U) + aNonceWordA;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 50U)) + RotL64(aCarry, 57U)) + 4563975890702399441U) + aNonceWordB;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 797804144825287940U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 37U)) + 2763779540450101303U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 13211846164102089685U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15214578447281401982U;
            aOrbiterI = RotL64((aOrbiterI * 12107189619131483661U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 13745208628754232427U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17358621225969190747U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5325024317338823061U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 779739369960480023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4370963533701407813U;
            aOrbiterE = RotL64((aOrbiterE * 3123135216876641039U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6061333005507739975U) + aNonceWordJ;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 3589705340762734456U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 16499293983611196967U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10607697666369230567U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9356757995305239271U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10945513661439954731U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aCross, 11U) + RotL64(aOrbiterE, 47U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordO) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 21U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 4U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28213U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 31458U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32149U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27772U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 31413U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 29U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 14U)) + 1210605127156905516U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 41U)) + 11964595428173569519U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 16277319029916258482U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 12369497463101824572U) + aNonceWordC;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 6201248574067068202U) + aNonceWordA;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1727477025667206661U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1404510627789806851U;
            aOrbiterF = RotL64((aOrbiterF * 4810039298122529021U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6948213591282018925U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6688865181284421478U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 12619122841662247279U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3351130769402360855U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12681032488906270823U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 3680893896579741263U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 3591412591193726763U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16153817571210878589U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4165137036092246349U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3808228354421006630U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1427373776207504205U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4534374093769595531U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 23U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + aPhaseAWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 13U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + aNonceWordG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xB92356A8C6D03DF5ULL + 0xBA06E732B60ADA4DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDBFA889E73512C29ULL + 0x98A1CADDFF81DAD8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF12B583D01BD8173ULL + 0xE399CEBC69F23B59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD3A70C8C4BB48D0BULL + 0xADB2BB74E335724DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA60369A3A4AA6EEFULL + 0x97F1A5C6801B8844ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCD6C25BD5AC50C73ULL + 0xF2B11560A841D479ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF55FAF960676FBB5ULL + 0xA80610ADCCBD9220ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC45AB512995327FDULL + 0xC7663B5E9DD46BB0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC76DAF5C31BBEE2BULL + 0x9B08D21F8BF361B3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC4A9B0A85132548DULL + 0xD0F64B5FCC013918ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA5B0A60815D36CFDULL + 0xBEDF277DD7FF1051ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEA6440A4FA93185DULL + 0xF4BA1829F221722BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8BD222A54627D909ULL + 0xCC9D175AB55B58FAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE991E6F84F6DD92FULL + 0x820C9DE305D35837ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBED156D5715B80F1ULL + 0x8BE55C1B5F99701CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA92A43F09D960F13ULL + 0xC3C079A0367461C6ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1700U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 5763U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 350U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 614U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1145U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8003U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 17454559218352016650U) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aCross, 47U)) + 8005709669325164803U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 13393741948412816357U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 3665865624348875553U;
            aOrbiterA = (aWandererE + RotL64(aCross, 40U)) + 8334142570031883436U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 29U)) + 17226066128706139657U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 3U)) + 3319093033121522613U) + aPhaseBOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 57U)) + 6657535603401588798U) + aNonceWordP;
            aOrbiterF = (aWandererI + RotL64(aScatter, 36U)) + 5469746182326331147U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17846791786050221418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15939541003714896288U;
            aOrbiterH = RotL64((aOrbiterH * 1400351482213119809U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12076763190461077406U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3594038213596405284U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 10244002692575821495U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 8301291631324464622U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8460406137668390582U;
            aOrbiterI = RotL64((aOrbiterI * 9117147929757711595U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7612394867020871200U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 8525076134853103975U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5790440201072204659U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 11929899088215090379U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7119509166360685726U;
            aOrbiterA = RotL64((aOrbiterA * 1662341427992528823U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5081078459225240607U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17149991983909906705U;
            aOrbiterK = RotL64((aOrbiterK * 950223374568067343U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8817303295675241994U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7962039282652745113U;
            aOrbiterC = RotL64((aOrbiterC * 12773588587795522121U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13596273086338032370U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8186297702278180956U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6226504769888753861U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1696277861691580263U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17360461831507082959U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 1651378456022210983U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 14U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterF, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + aPhaseBWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aNonceWordB);
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 60U)) + aOrbiterH) + aNonceWordJ);
            aWandererG = aWandererG + ((((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9963U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 12568U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11309U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 11143U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15534U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9231U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 12821U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 58U)) + 13174219512651137892U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 2715455762789269341U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 1338018183235594313U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 16566866551729552930U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 47U)) + 6901845297307236726U) + aNonceWordE;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 37U)) + 2476078302049201718U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + 15531109473927052260U) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 27U)) + 4087849380858572351U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 12U)) + 5167830630098599644U) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7275995452428627217U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14794340370010024117U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8779497557416568379U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8509217403041662849U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2321522025240806996U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5676672952755594051U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2304681269233504384U;
            aOrbiterF = RotL64((aOrbiterF * 15731441084605554497U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8383399721062437300U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13181984036942227666U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 1648761328771932069U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13602604532551684210U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12725687663616352843U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 4684699861686199753U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5831790822416009806U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4535048543735457407U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12076777878870257053U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10617608605149381858U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5244225377862618630U;
            aOrbiterB = RotL64((aOrbiterB * 15307177251167023999U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18229989093139888456U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9728120630096192811U;
            aOrbiterI = RotL64((aOrbiterI * 16052574428163231023U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1312233443099767304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8043115602160128619U;
            aOrbiterJ = RotL64((aOrbiterJ * 9365756845731616963U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 43U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 54U)) + aOrbiterF) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterC, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17686U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((aIndex + 20892U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 17180U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 19454U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21755U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18172U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 21354U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 11998579547770778580U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 30U)) + RotL64(aCarry, 13U)) + 8409465187298704610U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 47U)) + 3470222286110333500U) + aNonceWordG;
            aOrbiterC = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 5704486785203069994U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 41U)) + 10334944660253279633U) + aNonceWordE;
            aOrbiterE = (((aWandererD + RotL64(aCross, 26U)) + 7626852700722567477U) + aPhaseBOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 21U)) + 14631310754943209743U) + aNonceWordB;
            aOrbiterG = (aWandererF + RotL64(aIngress, 13U)) + 807160297237854120U;
            aOrbiterK = (aWandererG + RotL64(aCross, 5U)) + 5624154783624196107U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4971444394698940423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6340057638461027062U;
            aOrbiterJ = RotL64((aOrbiterJ * 12027586111086798629U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9003019862787819481U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13632057463595873033U;
            aOrbiterE = RotL64((aOrbiterE * 12575202147280216765U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12766104026871797746U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4062118445824915939U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13130770039048080701U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5258212525426469978U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 9956946981015983939U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 8106382657040497669U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10837606223056473999U) + aNonceWordO;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 13292864885504191134U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 4445739587553669471U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 166087925900318658U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6786842221885441388U;
            aOrbiterH = RotL64((aOrbiterH * 4411147600413147773U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16888086378070246404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5240855484445974002U;
            aOrbiterK = RotL64((aOrbiterK * 402652898573422271U), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 6874866669211571608U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 732890824978127460U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3776365957702257453U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5541380495707308058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 17947326584411475765U;
            aOrbiterB = RotL64((aOrbiterB * 10920952349981652899U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 6U);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterF, 48U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 36U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32010U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 32031U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27421U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30747U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30931U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32000U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24950U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCarry, 35U)) + (RotL64(aCross, 21U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 19U)) + 6163290588946759209U) + aNonceWordL;
            aOrbiterE = ((aWandererE + RotL64(aCross, 26U)) + 7342672468560105447U) + aPhaseBOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 11574563167017282321U;
            aOrbiterH = ((((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 2254820206194758964U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aWandererI + RotL64(aScatter, 51U)) + 1469783447473099498U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 14174828900676165088U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 47U)) + 16277954291890598132U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 13U)) + 14845750668693136766U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 6U)) + 150099699692047766U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1200784917165131703U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9469982764806754302U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 17851969334511301943U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10956702761701710182U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 7915506894975487807U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8874108311712727983U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17335794183733623213U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 557028996286989506U;
            aOrbiterD = RotL64((aOrbiterD * 3993359298602424281U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1597385667771002414U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4376417959915162639U;
            aOrbiterI = RotL64((aOrbiterI * 4626236858205178149U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 549770198518993876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 756554555648070919U;
            aOrbiterB = RotL64((aOrbiterB * 16272320259614325355U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7298557532533152193U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 3336802611342112013U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 14679103452120080499U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2314938232094714365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12215066333571149153U;
            aOrbiterJ = RotL64((aOrbiterJ * 10747052773052630601U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 7762752719356805046U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6519429915769040078U;
            aOrbiterA = RotL64((aOrbiterA * 15548676502167938513U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7556691736109752918U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13731245903412646404U;
            aOrbiterE = RotL64((aOrbiterE * 15581965016668635409U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 48U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 23U)) + aOrbiterF) + aNonceWordI) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aNonceWordM);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 60U)) + aOrbiterK) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDD58B72C13A61009ULL + 0x83940EBB13424A90ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC19EF79F3CE3B107ULL + 0x9369BB9AFD228109ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA61455C405407A3DULL + 0xA2EFC8B20DA995C9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9CE9CDCC34F7FE43ULL + 0x8B3FACB425AA1F99ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8442DA9D66D51049ULL + 0xA5BD28430086C44CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA01090B515E26113ULL + 0xC5531ACD46FAF093ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF1EBAF24B91F1A37ULL + 0x8B160784CA2738C7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC6DCADCD2DB7B345ULL + 0xDE5BA4F105C605CCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBC7588726DB02AA9ULL + 0x887FBC8DE634D475ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC513A3AC76B0D471ULL + 0x9C8C733A550EE113ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFF19E4A7C8260B87ULL + 0xBEF082DF266FADF9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB4E10FD52BB0824DULL + 0xDBCD3A53AA7E292BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFF1602518C64188FULL + 0xF70B8ADECEA32036ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE768948CA997F833ULL + 0xA93F58CEC3950C29ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x840A79932B27BA47ULL + 0xA6D73428F22A58E1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB44EAE2075B16D2BULL + 0xFAFEF15389EA1599ULL);
    // GSeedRunSeed_D seed_loop_d (start)
    {
        // GSeedRunSeed_D seed_loop_d lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aInvestLaneA, aOperationLaneB, aInvestLaneB, aOperationLaneC, aInvestLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aInvestLaneA, aInvestLaneB, aInvestLaneC, aInvestLaneD
    
        // seed_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5266U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 2463U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 766U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 827U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 260U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3404U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 19U)) + 12849591986267890852U) + aPhaseDOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 8232614804696815750U) + aNonceWordH;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 12141567259210877281U) + aNonceWordN;
            aOrbiterD = (aWandererE + RotL64(aCross, 56U)) + 2928641981037885644U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 29U)) + 980733350554783938U) + aNonceWordJ;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 2683985177993350746U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 47U)) + 14532148403815527355U) + aNonceWordP;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7736296629433884203U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10428437770166310549U;
            aOrbiterA = RotL64((aOrbiterA * 326634742742373401U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18327174144859461029U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6810436935194432002U;
            aOrbiterK = RotL64((aOrbiterK * 2715987179577753597U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12606153309690753435U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17123256945895150555U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 13469111258504672565U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9057777759026189541U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 16478485918911194442U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18064460487552100483U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11477276762421684083U;
            aOrbiterB = RotL64((aOrbiterB * 3886501230380184395U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 18318375441973295081U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13849305985380030986U;
            aOrbiterF = RotL64((aOrbiterF * 12962140243967824959U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10240409420338313641U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18360586077779529086U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 18196875422391501927U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 58U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ) + aNonceWordO);
            aWandererF = aWandererF + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordE) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8331U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 5511U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6111U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10232U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6938U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7625U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8707U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 439898681482066326U) + aNonceWordO;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 29U)) + 17362083676671776094U) + aPhaseDOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 36U)) + 6418499837265155024U) + aNonceWordA;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 11U)) + 17262244253027454972U;
            aOrbiterG = (aWandererH + RotL64(aCross, 3U)) + 2382066162993139503U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 14345808395587174135U) + aNonceWordL;
            aOrbiterE = ((((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 7534743166385552851U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16994453324688523966U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7079553728544045092U;
            aOrbiterC = RotL64((aOrbiterC * 10104892188895367489U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3562822704508440641U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13990892681975857821U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8352929306654078795U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1796728922368577238U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6605161260520067178U;
            aOrbiterG = RotL64((aOrbiterG * 8147537646591674091U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13994083795942328918U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6144523182899107711U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 4153879991344611283U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12247462325297436642U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1065809332002012789U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5496601177032953251U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10147919864511540753U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 17138553441127273354U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 5773875596275267871U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2653924016109573974U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6254416952351699582U;
            aOrbiterK = RotL64((aOrbiterK * 12756861659704947257U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 47U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 10U)) + aOrbiterG) + aNonceWordN) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aExpandLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 12788U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 11102U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12233U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16347U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15485U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 27U)) + 3612110001869385068U) + aNonceWordK;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 16340824141280225936U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 57U)) + 15222338965130765231U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 19U)) + 6649270508107155041U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 47U)) + 768217258655426384U) + aNonceWordG;
            aOrbiterD = (((aWandererE + RotL64(aCross, 12U)) + RotL64(aCarry, 3U)) + 4481855259658861851U) + aPhaseDOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 18318041934562434016U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4212457153804401807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16143621095636987628U;
            aOrbiterC = RotL64((aOrbiterC * 6576072860505961427U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 2095664232866642086U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4339527736737366572U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17503569508822244125U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13679353177869884790U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11582168502846418236U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 135539430034462861U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10451330452898542191U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 12951448817640617841U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4141870904192742091U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15389161934419370747U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4754886272708253014U;
            aOrbiterI = RotL64((aOrbiterI * 16638243718191281597U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11746389873929280688U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 12042680172517298768U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 3814780289755857543U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2648103752465009244U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 451594673632597973U;
            aOrbiterE = RotL64((aOrbiterE * 8496763663271072425U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 57U)) + aNonceWordF) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 26U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterA, 56U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 4
        // ingress from: aInvestLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aInvestLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 17356U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 19604U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 17151U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16667U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18657U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 380024772508948442U) + aNonceWordJ;
            aOrbiterA = (aWandererA + RotL64(aIngress, 4U)) + 7649029098162567210U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 23U)) + 5329304598870421851U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 12306118665045151326U) + aNonceWordI;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 51U)) + 960751560457324256U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 3244070254386191876U) + aNonceWordM;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 11U)) + 15733408571609521746U) + aPhaseDOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 17623448932647018544U) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8787759896149035829U;
            aOrbiterG = RotL64((aOrbiterG * 7092515868845497573U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14741681792348288162U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 8801731213568307302U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 12127126999570616489U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9872248187499779222U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15407371518644528235U;
            aOrbiterA = RotL64((aOrbiterA * 1245102406469471673U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4242060317152943062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9942784962409917541U;
            aOrbiterI = RotL64((aOrbiterI * 888649755587764533U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7296348796484458631U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15061417216070157797U;
            aOrbiterK = RotL64((aOrbiterK * 10349554676953256231U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3233185810644297433U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 9241229457641024287U;
            aOrbiterH = RotL64((aOrbiterH * 2728237515724597517U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8464051359381554575U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 3307872165699029375U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 4859663401033023433U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 20U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordH);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + aNonceWordA) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aCross, 52U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordF) + aPhaseDWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 30U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_d loop 5
        // ingress from: aInvestLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aInvestLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aInvestLaneA, aWorkLaneA
        // cross directions: aInvestLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 23992U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 26851U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 24359U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22446U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23061U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererF + RotL64(aIngress, 47U)) + 8402620908307642697U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 11347672014525086047U;
            aOrbiterK = (aWandererH + RotL64(aCross, 29U)) + 2816462912503401876U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 51U)) + 6940159795470696093U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 9134692490095883851U) + aNonceWordK;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 3U)) + 4999455497008026526U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 35U)) + 5992451460350651332U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3417087346651371924U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3612773820086198270U;
            aOrbiterK = RotL64((aOrbiterK * 5519856345435871169U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 463398077083428570U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11249391303705089012U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7106735772303292983U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17027535139825739501U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 568131384979596481U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5683451044852895957U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4793712537158004047U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10415170179135963622U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13729564030210361415U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2391473979460065630U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4240058362680064261U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 12375884373396400889U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9963957011090031698U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3325305624067445525U;
            aOrbiterB = RotL64((aOrbiterB * 3128542681461806309U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2094945647665114693U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10703615640774042674U;
            aOrbiterJ = RotL64((aOrbiterJ * 12641986098450423751U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 54U)) + aOrbiterF) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE + (((((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aCarry, 57U)) + aNonceWordB) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererI, 14U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_d loop 6
        // ingress from: aInvestLaneC, aInvestLaneA, aOperationLaneD
        // ingress directions: aInvestLaneC forward forced, aInvestLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aInvestLaneB, aExpandLaneB
        // cross directions: aInvestLaneB backward forced, aExpandLaneB backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29921U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 28591U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 29491U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31916U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 29046U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 50U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 16016931609704150191U) + aNonceWordN;
            aOrbiterF = (aWandererK + RotL64(aScatter, 19U)) + 14511433515861302636U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 11691237442613269593U) + aNonceWordB;
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 16383220587320484649U) + aNonceWordM;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 52U)) + 14293015313458219868U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 11U)) + 4407695248205526670U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 35U)) + 1158323195324398372U) + aPhaseDOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6577683409653864555U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 171080079472863843U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 3063978974927752653U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5766333425872228205U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16173508656917582960U;
            aOrbiterA = RotL64((aOrbiterA * 12187968015372936695U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11781450063402219202U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13033139686637576694U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4331137994135472025U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4006310759400926020U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13156817947481574467U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 563189239835001483U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12791290558893516411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 989729955679243234U;
            aOrbiterI = RotL64((aOrbiterI * 8757228712495095017U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 838379839663022790U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2830743864262313606U;
            aOrbiterH = RotL64((aOrbiterH * 10173947177104802797U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2146646527331684652U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 4629168181742174906U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 9046124907945045131U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 22U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + aNonceWordC);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aNonceWordG) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordD) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD4FA9D50B5A3C37FULL + 0xB6C1B2C240A736E0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x949CFCB0A5B28E6FULL + 0x888145ACF42AA0F5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAE52DF2B5A3F752FULL + 0xF5AD8549591BD4C0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBAE67DE43F27CE19ULL + 0x8017D18E1704E47DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xADA56E3C759F292FULL + 0xC9961956382BC2D6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB7030EA13CF4DEEFULL + 0xAE6C5EF2638ABD85ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB63E3CFCDF8893F5ULL + 0xEC6916E34E587B62ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9CF2D065F23C42F9ULL + 0xA9918436D6DE07D0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFC6B7EAFA50E6113ULL + 0xB1F90FA494E7700CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8ADFA73C36FB4A9DULL + 0xB54DA81FA628428FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9B2508CD2F6C5FA9ULL + 0x8FBAD128DF79729CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAA538C8413DEEC5BULL + 0xA76DA4C6709C4C7AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD20874B83CABBA17ULL + 0xEC1AAB17D66D90C2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x84278BB4DBA6BE3FULL + 0xB5D7D0AAEB1CAB43ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD3B43292FE293273ULL + 0x98860937E8C724C7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE45DBCC6D206FFA9ULL + 0xFF890FDEB3932863ULL);
    // GSeedRunSeed_E seed_loop_e (start)
    {
        // GSeedRunSeed_E seed_loop_e lane group
        // read from: aInvestLaneA, aInvestLaneB, aFireLaneA, aInvestLaneC, aInvestLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aWorkLaneA, aOperationLaneA, aWorkLaneB, aOperationLaneB, aWorkLaneC, aOperationLaneC, aWorkLaneD
        // write to: aSnowLaneA, aSnowLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_e loop 1
        // ingress from: aInvestLaneA, aInvestLaneB, aFireLaneA
        // ingress directions: aInvestLaneA forward forced, aInvestLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aInvestLaneD, aFireLaneB
        // cross directions: aInvestLaneC backward forced, aInvestLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 4361U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneB[((aIndex + 422U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1917U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 5081U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3276U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4767U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 4622023259121087483U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 21U)) + 10253505250223501352U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 57U)) + 17133877904420462669U) + aNonceWordG;
            aOrbiterC = ((aWandererH + RotL64(aCross, 39U)) + 6162827793741796700U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 23U)) + 9610986424765907615U) + aNonceWordO;
            aOrbiterE = (aWandererD + RotL64(aCross, 34U)) + 11210747154264753754U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 37U)) + 16554205219580654546U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 10352576357413766388U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 3651845783283479752U;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 54U)) + 18145542190463500476U;
            aOrbiterA = (aWandererK + RotL64(aCross, 47U)) + 5415609566767162857U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2033734872464201570U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3507213117125813345U;
            aOrbiterG = RotL64((aOrbiterG * 5453058336688881113U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8716253393049851856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 695984869565941856U;
            aOrbiterK = RotL64((aOrbiterK * 8377921610764044735U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7661578828878284931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 906654265099155956U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 8117625377607536949U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6050049984731254612U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17882717590338190821U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10807367411402733215U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4996521991532815957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8700148116452518842U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10039050281847466206U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 11884791271239660157U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4513844680425845372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3037563127442815153U;
            aOrbiterB = RotL64((aOrbiterB * 18363509277992292407U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1005237931570968724U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 1373258132025712065U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10458020799382532395U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12759144329395682277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5139371668116336931U;
            aOrbiterE = RotL64((aOrbiterE * 10761543179345026943U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterB) + 3211005174890625715U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18045286961878287418U;
            aOrbiterJ = RotL64((aOrbiterJ * 4536094526540761611U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4454078771279674978U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 4622023259121087483U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8991756794989027019U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterH, 42U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterH, 36U));
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterD, 48U)) + aOrbiterB) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aNonceWordB);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aNonceWordP);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 2
        // ingress from: aSnowLaneA, aInvestLaneC, aInvestLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aInvestLaneC forward forced, aInvestLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneA, aInvestLaneB, aFireLaneD
        // cross directions: aInvestLaneA backward forced, aInvestLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10891U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((aIndex + 6565U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 10398U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((aIndex + 7524U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 6178U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10458U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10214U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 18U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 60U)) + 1393781663398437180U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 43U)) + 17414594746688585273U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 2823888497053071250U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 17032631958617884859U) + aNonceWordJ;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 21U)) + 15222697630461125019U;
            aOrbiterA = ((((aWandererJ + RotL64(aCross, 26U)) + RotL64(aCarry, 39U)) + 15737414920751551780U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererC + RotL64(aIngress, 13U)) + 1357196111055783001U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 5315122321649251691U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 19U)) + 7893744655508595974U) + aNonceWordB;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 47U)) + 16721939414324611738U) + aNonceWordH;
            aOrbiterD = (aWandererI + RotL64(aCross, 29U)) + 3444375866323610848U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1825716513674511632U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15582066843912467318U;
            aOrbiterC = RotL64((aOrbiterC * 12765146555943757373U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15673590949193923915U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13887365046280406413U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3169061375011420121U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 12730414371734709356U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4819112390640821927U;
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3089925954422937464U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7180179304678622530U;
            aOrbiterB = RotL64((aOrbiterB * 16118051565147747413U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17030269962085008657U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6675917351883004046U;
            aOrbiterD = RotL64((aOrbiterD * 14134335325316949687U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12572022803491077491U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 2801421744689267375U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 315045745990934023U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4335148696780313055U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12526298573395110141U;
            aOrbiterF = RotL64((aOrbiterF * 11276803410698178607U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6984239833558496091U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 12195433952105336808U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 8642600547427664495U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6392683095502982341U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18047201953488013325U;
            aOrbiterK = RotL64((aOrbiterK * 16151795290455603489U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15433458942878109208U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1700365768743794306U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 16151638348775286903U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10951473638533187729U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 1393781663398437180U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 2661447713922232789U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterI, 4U)) + aNonceWordA) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 18U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 35U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 54U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 3
        // ingress from: aSnowLaneB, aInvestLaneA, aWorkLaneA
        // ingress directions: aSnowLaneB forward forced, aInvestLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aSnowLaneA, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 11748U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneA[((aIndex + 13453U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13312U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12784U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15104U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 53U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (aWandererK + RotL64(aPrevious, 51U)) + 4751694786009671052U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 36U)) + 16362725160370844224U) + aNonceWordO;
            aOrbiterB = (aWandererE + RotL64(aIngress, 19U)) + 6360885380915941057U;
            aOrbiterI = (aWandererG + RotL64(aCross, 21U)) + 5154536007972297036U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 9362540581874808253U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 41U)) + 13902493871525612934U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 10208452885367546542U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 10U)) + 3117030377279160998U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 17286247690414027870U) + aPhaseEOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 43U)) + 3930314320040949141U) + aNonceWordA;
            aOrbiterD = ((aWandererB + RotL64(aCross, 3U)) + 7289525252391668404U) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3434167955466809185U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17852573095128575663U;
            aOrbiterB = RotL64((aOrbiterB * 1485660158767033425U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6137259687928853253U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13992510605237574698U;
            aOrbiterC = RotL64((aOrbiterC * 15346263295995333395U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6470556523400123474U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7700424876430257995U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16920736951239453071U;
            aOrbiterF = RotL64((aOrbiterF * 8920407493132380497U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1635071690430295730U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9966700845966398620U;
            aOrbiterG = RotL64((aOrbiterG * 17210048121896546867U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 9833458070123027075U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1990346556486746432U;
            aOrbiterE = RotL64((aOrbiterE * 8704943923474148699U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13339523466436517327U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5018264760406215603U;
            aOrbiterK = RotL64((aOrbiterK * 2769197961801783627U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 123427497520755346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4535841104215792886U;
            aOrbiterA = RotL64((aOrbiterA * 1417676310539177131U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3525925567359163763U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3273741481392187986U;
            aOrbiterJ = RotL64((aOrbiterJ * 16116160744647235811U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6230742908784102407U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7578784912496239362U;
            aOrbiterI = RotL64((aOrbiterI * 2614448818452560369U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14669810330213234082U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4751694786009671052U;
            aOrbiterD = RotL64((aOrbiterD * 9583151676882991817U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 14U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 50U)) + aOrbiterH) + aNonceWordE);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 26U) + RotL64(aOrbiterG, 43U)) + aOrbiterH) + aNonceWordB) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 20U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 4
        // ingress from: aOperationLaneA, aSnowLaneA, aWorkLaneB
        // ingress directions: aOperationLaneA forward forced, aSnowLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18450U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneA[((aIndex + 20226U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16741U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 17741U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20526U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 41U)) + 11210042748013785976U) + aNonceWordA;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 41U)) + 4584747303233477454U) + aNonceWordB;
            aOrbiterF = (((aWandererC + RotL64(aCross, 19U)) + 8878765929792969517U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 2172232330280041122U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 8378937026022264016U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 53U)) + 8683007464695824208U;
            aOrbiterK = (aWandererI + RotL64(aCross, 22U)) + 9564352997357118134U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 11U)) + 11713878436769887528U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 29U)) + 8052917623074021077U) + aPhaseEOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 7720597162792145185U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 5U)) + 2602847785328475621U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 17813669222300509724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8724263063156573013U;
            aOrbiterF = RotL64((aOrbiterF * 3632927017737834359U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6882429835961613492U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13213313479525717359U) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 2411431247725974895U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2401526093648669573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3616448566579979749U;
            aOrbiterA = RotL64((aOrbiterA * 13323155103752121393U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18268262471839710401U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5116424918948694752U;
            aOrbiterK = RotL64((aOrbiterK * 7641143782996332069U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11405305689555640431U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 12427591396711015574U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 8112834135715541223U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16960781161508084626U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 12382604781005282628U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17196168631120103115U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10054839091354729292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 4167641616532985407U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 919291747187787625U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14383737233143309039U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16258779988369405932U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 8348773195366160215U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4777263172049970723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12498046021142146499U;
            aOrbiterC = RotL64((aOrbiterC * 5941015011162130901U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7435001955334177144U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4100235545173125433U;
            aOrbiterG = RotL64((aOrbiterG * 5046572784117638909U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1981704568071298614U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11210042748013785976U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17889749044418386565U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 60U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 58U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterJ, 53U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + aNonceWordK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 48U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 50U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 4U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_e loop 5
        // ingress from: aOperationLaneB, aSnowLaneB, aWorkLaneC
        // ingress directions: aOperationLaneB forward forced, aSnowLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneA, aSnowLaneA
        // cross directions: aOperationLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24563U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((aIndex + 24543U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 25249U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22000U)) & S_BLOCK1], 54U) ^ RotL64(aSnowLaneA[((aIndex + 25434U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 37U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 19U)) + 8767379393098711499U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 26U)) + 7168159491580816433U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 47U)) + 9879279829061883406U;
            aOrbiterA = ((((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 10537167136053399303U) + aPhaseEOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 2839070018069188936U;
            aOrbiterG = (aWandererC + RotL64(aCross, 13U)) + 13844278063968429732U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + 11278946626186474646U) + aNonceWordM;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 57U)) + 11798425216660557799U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 29U)) + 7618446090703335192U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 13U)) + 695423597006983660U) + aNonceWordJ;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 41U)) + 14344728202803488813U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11656100506575697086U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10384358779985773937U;
            aOrbiterJ = RotL64((aOrbiterJ * 247494692039140973U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17585001605131977341U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9964478171465522911U;
            aOrbiterF = RotL64((aOrbiterF * 13484044854790175315U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2710943171829692624U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17809072853457153057U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 16341884203303271365U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12814092033910687774U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1743186323268668740U;
            aOrbiterB = RotL64((aOrbiterB * 11150822630624332557U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10750472346626754704U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15925901217078035356U;
            aOrbiterG = RotL64((aOrbiterG * 9276504171291801637U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2569102106359362359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8868261301410769739U;
            aOrbiterE = RotL64((aOrbiterE * 3662495603133918101U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 2143691008373582476U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10606616796243205921U;
            aOrbiterI = RotL64((aOrbiterI * 15794414817813485643U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16258070651850746855U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11720192793689633315U;
            aOrbiterK = RotL64((aOrbiterK * 14475623219460678021U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8230871037292355675U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16898650748046368353U;
            aOrbiterD = RotL64((aOrbiterD * 7368697435476300255U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9071122174426904737U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4506737259011736474U;
            aOrbiterA = RotL64((aOrbiterA * 11903039808814842447U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4545409671845718259U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 8767379393098711499U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1210632171306946669U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 34U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 27U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aNonceWordG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 5U)) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 54U) + RotL64(aOrbiterD, 35U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterK, 26U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_e loop 6
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29944U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 32460U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28516U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31571U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 32431U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aCross, 40U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererA + RotL64(aCross, 11U)) + 479672811032092393U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 4U)) + 18061121631394564425U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 37U)) + 14237400452740566065U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 6723123812257706134U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 57U)) + 4247997188026499248U) + aNonceWordI;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 1939107415066134869U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 27U)) + 3912640123546395979U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 19U)) + 8295478436553964298U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 3218960600711526885U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 46U)) + 5874096203353388890U) + aNonceWordE;
            aOrbiterI = (aWandererG + RotL64(aCross, 41U)) + 10294536533673023358U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11268561953904130747U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16693201256788898423U;
            aOrbiterB = RotL64((aOrbiterB * 16291987237693567209U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7550969634681894654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9501647424602245869U;
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8881869255994319423U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 16770136406906800016U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1782039587385512923U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16185384746435761363U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13841034186650721627U;
            aOrbiterK = RotL64((aOrbiterK * 12000155593277035447U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15229062695864608309U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 3576122704615303733U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2433987493885779279U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 13898167174453181224U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12878032061609524049U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18104665741338251495U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12719156051299028649U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8640980843376950769U;
            aOrbiterH = RotL64((aOrbiterH * 10242616778390983333U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12133332160916004365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8743563985229104484U;
            aOrbiterA = RotL64((aOrbiterA * 4575129690615054691U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7362223873479167793U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4230720394788635807U;
            aOrbiterD = RotL64((aOrbiterD * 3658720603716856293U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5095842824285329272U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7483469517256234638U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 9782114499878763883U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17426017004856399653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 479672811032092393U;
            aOrbiterC = RotL64((aOrbiterC * 14921028515589317919U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterD, 24U));
            aWandererC = aWandererC + (((RotL64(aScatter, 12U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ) + aNonceWordM);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + aNonceWordG);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 37U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 5U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 44U) + aOrbiterA) + RotL64(aOrbiterI, 13U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 60U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 58U);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x93CC9A86DD181D6FULL + 0x9901954A7BDABDB6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB9BE4C0F01BA56C7ULL + 0xC634F3BFD64A31EAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCAAF407B34F4B92BULL + 0xB50F4426EC3CB9ABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA17FDC5E51926E03ULL + 0xED20377B6B23494DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCDEAEAD9C835725BULL + 0x91B0509E6A088BEDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE500BB4A2356C6B5ULL + 0xE0FFF33A68727C7BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x85507074B1C7C9D9ULL + 0xA08776EA990BDC97ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF62B71995C90B66DULL + 0xFFC741CB2EFBFF1CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD914C9908EC5C663ULL + 0xC08D24B6BE83C6DBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC4D0D611C725919FULL + 0xA6E9CF9CCEF770EDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA7E2A2BAC6ED230BULL + 0xAB3FFB61214E0208ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAF985C15B6271191ULL + 0xE478AD16E665E42FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDDA6A8F7D8BF9A3FULL + 0xA8405DA7C692F984ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x89BE06238A216EFDULL + 0xC71E546567F12CB6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9BEC7E938F6495BBULL + 0xA9A673581D9BF463ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x945FC38ADAB6B9CBULL + 0xFFA0F8A68353DBFEULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aSnowLaneA, aFireLaneC, aFireLaneD, aSnowLaneB, aInvestLaneA, aExpandLaneA, aInvestLaneB, aExpandLaneB, aInvestLaneC, aExpandLaneC, aInvestLaneD
        // write to: aSnowLaneA, aSnowLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2982U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 3025U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2628U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4939U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 488U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 457U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 15316464782468770057U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + 6642872057476351588U) + aNonceWordF;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 29U)) + 660732654689529192U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 41U)) + 7235418086884000655U) + aNonceWordH;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 3U)) + 14784518476694580493U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 12222433977933449375U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 36U)) + RotL64(aCarry, 47U)) + 8573001207708329927U) + aPhaseFOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 16035256260815013172U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 23U)) + 15767726974121910203U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17712217935322939971U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13488963456923357159U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16785285630840310405U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10222949131965611079U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1495561412321657209U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9706305581868526265U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 11544578291333360613U) + aNonceWordI;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3665587867634242865U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4840528190844842595U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15248434984650998090U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15487979645426567581U;
            aOrbiterG = RotL64((aOrbiterG * 10868107809356766183U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6972347795052712690U) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16074994810010431338U;
            aOrbiterI = RotL64((aOrbiterI * 1262655238856775853U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16851139687900415292U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14630026837021552812U;
            aOrbiterK = RotL64((aOrbiterK * 9577900853521254603U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14236330619137368169U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17778707026111136216U;
            aOrbiterB = RotL64((aOrbiterB * 16239561893843454747U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9390961969105999083U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1174881758316573228U;
            aOrbiterH = RotL64((aOrbiterH * 6602061268277529311U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 6U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aNonceWordD);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterI, 43U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aNonceWordK) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 56U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9723U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 8154U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7476U)) & S_BLOCK1], 56U) ^ RotL64(aFireLaneC[((aIndex + 7786U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8651U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5732U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 8026U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 58U)) + 12027839670755583592U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 3U)) + 15380130703509859843U) + aPhaseFOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + 4590907433867798074U) + aNonceWordP;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 1754574023602519724U) + aNonceWordC;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 9832756659564903767U;
            aOrbiterG = (aWandererK + RotL64(aCross, 42U)) + 5035088494491470403U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 51U)) + 14199170923323644638U) + aNonceWordL;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 3U)) + 8325619421264440438U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 23U)) + 969534320779067977U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 270575869402913847U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13344806516599578910U;
            aOrbiterK = RotL64((aOrbiterK * 10193544126281901579U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 15143147951139409101U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14425582489214169238U;
            aOrbiterF = RotL64((aOrbiterF * 16893787086337916355U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 13951127523239064584U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 14177925225918293579U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13079514031864998485U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8258920744278218901U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7408161179397242453U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8581481606764773468U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10078416198417433133U;
            aOrbiterG = RotL64((aOrbiterG * 1102721083915858247U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 18299772198826189580U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18304668908084397946U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 10589455451200578687U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16729632621573817223U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13362300981585573239U;
            aOrbiterB = RotL64((aOrbiterB * 9824473895535518785U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8629682832849915380U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6852852009091469641U;
            aOrbiterD = RotL64((aOrbiterD * 11912646687050011915U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 7433098156961745198U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10931806208899417308U;
            aOrbiterE = RotL64((aOrbiterE * 14699197041038067483U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 26U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + aNonceWordB) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterG, 24U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 51U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 35U));
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 38U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15569U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 14991U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 12332U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13080U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 12053U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 24U)) + 4751694786009671052U) + aNonceWordE;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 16362725160370844224U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 6360885380915941057U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 5154536007972297036U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 9362540581874808253U) + aNonceWordC;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 58U)) + 13902493871525612934U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 19U)) + 10208452885367546542U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 35U)) + 3117030377279160998U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 29U)) + 17286247690414027870U) + aNonceWordP;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 3930314320040949141U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7289525252391668404U;
            aOrbiterF = RotL64((aOrbiterF * 15452162299105112187U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3434167955466809185U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17852573095128575663U;
            aOrbiterC = RotL64((aOrbiterC * 1485660158767033425U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6137259687928853253U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13992510605237574698U;
            aOrbiterA = RotL64((aOrbiterA * 15346263295995333395U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6470556523400123474U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7700424876430257995U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16920736951239453071U;
            aOrbiterG = RotL64((aOrbiterG * 8920407493132380497U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1635071690430295730U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9966700845966398620U;
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9833458070123027075U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1990346556486746432U;
            aOrbiterE = RotL64((aOrbiterE * 8704943923474148699U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13339523466436517327U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5018264760406215603U;
            aOrbiterB = RotL64((aOrbiterB * 2769197961801783627U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 123427497520755346U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4535841104215792886U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 1417676310539177131U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 14U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 3U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aNonceWordL) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterB, 30U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneA, aInvestLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18140U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((aIndex + 17956U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 19599U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21354U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((aIndex + 17237U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 13U)) ^ (RotL64(aIngress, 26U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (aWandererI + RotL64(aPrevious, 41U)) + 16651241552253078315U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 4558144676982478003U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 8814884320080367550U) + aNonceWordF;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 29U)) + 16011579668555672117U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aCross, 13U)) + 4738918668759862438U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererA + RotL64(aScatter, 19U)) + 12526083125540985108U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 3U)) + 8048723561746000552U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 37U)) + 1082218464034639039U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 24U)) + RotL64(aCarry, 11U)) + 8432043246965946816U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9982080524048636852U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6720069955755215919U;
            aOrbiterD = RotL64((aOrbiterD * 1025046364205332059U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1019035028070247757U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7360619079463870467U;
            aOrbiterK = RotL64((aOrbiterK * 6623074813047915863U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 10893918488381348474U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1390297670907738019U;
            aOrbiterA = RotL64((aOrbiterA * 11909657437658597735U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12512200589031203480U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14741471280748399540U;
            aOrbiterJ = RotL64((aOrbiterJ * 3012135242889901095U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8543897248359826770U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 8545972622733791272U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11793879362775346821U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7049384618581928664U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14730773807906925408U;
            aOrbiterE = RotL64((aOrbiterE * 10711566871536755073U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11480717275652449986U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1135397594974536859U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 6347492892938856497U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6897207625849516702U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10920630712550287148U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4140705091806993359U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1094056478999931332U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 6784487144549717207U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6295177724167067891U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 38U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterE, 52U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterF, 43U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + (((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 11U)) + aNonceWordI) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterA, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aExpandLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aExpandLaneA, aSnowLaneA
        // cross directions: aExpandLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26103U)) & S_BLOCK1], 34U) ^ RotL64(aSnowLaneB[((aIndex + 24308U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 23036U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26724U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 27165U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererJ + RotL64(aCross, 19U)) + 11521331427196538632U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 11U)) + 16653824187682957632U;
            aOrbiterI = ((((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 13U)) + 11654676587350088289U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererG + RotL64(aIngress, 57U)) + 8010313317412193584U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 41U)) + 1108775560502907471U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 3U)) + 243952321439823521U) + aNonceWordI;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 2324945800401240403U;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 9257554497543369657U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aPrevious, 46U)) + 16701314607244592540U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3900445848034341782U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7652316487347103658U;
            aOrbiterI = RotL64((aOrbiterI * 11480123491361589799U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 14980368605272070578U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2001165460948764796U;
            aOrbiterD = RotL64((aOrbiterD * 8110980921827107649U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1911044015666991050U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11366207111147818339U;
            aOrbiterK = RotL64((aOrbiterK * 17234439040652553865U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16469329744002456607U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8062793687044950815U;
            aOrbiterE = RotL64((aOrbiterE * 5856142259851144369U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15364721421972807872U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8979915611483540231U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10899377466171153383U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 7654234623563110457U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1526832460342135008U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12766083052650723051U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1596625448797520938U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15723912914858523080U;
            aOrbiterJ = RotL64((aOrbiterJ * 6003857787643420337U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7664226719746532168U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13767298788411473401U;
            aOrbiterG = RotL64((aOrbiterG * 15663266144965532019U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8371251860069346385U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10143279934304029980U;
            aOrbiterH = RotL64((aOrbiterH * 12764966547132248131U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 48U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 43U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 56U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aNonceWordG) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterI) + aNonceWordE) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 54U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 60U)) + aOrbiterA) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 22U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 27338U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 27480U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 29502U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27488U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29470U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 6361545377408870615U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 60U)) + 2967245486744774933U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 37U)) + 3836634268482850139U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 51U)) + 7691642115360086297U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aScatter, 41U)) + 16479280384178279281U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 2901468732552539249U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 47U)) + 2600353867755647475U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 23U)) + 5666596904781510956U) + aNonceWordP;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 16108791609267427553U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8389926875737312112U) + aNonceWordO;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1689501721163024426U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 6517194895779049139U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11721701506949917719U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 3963842745030140473U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 6692473494944919373U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8510538243472109368U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18281865214102080387U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 1351546966368884609U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2259725140963665123U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11652011949557979650U;
            aOrbiterF = RotL64((aOrbiterF * 11260100762113295037U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1116085424226174473U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4725260319270802912U;
            aOrbiterC = RotL64((aOrbiterC * 4697109059565450269U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7348945429843437036U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1249234309180653260U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3136745255820405881U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12463505532573389603U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2304125977906510386U;
            aOrbiterE = RotL64((aOrbiterE * 9960816714791454421U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2178037443783425551U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11712110130079307683U;
            aOrbiterK = RotL64((aOrbiterK * 9797864956200779505U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10703510612147312252U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18155460326242413483U;
            aOrbiterB = RotL64((aOrbiterB * 6903953708987478723U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterE, 51U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 36U)) + aPhaseFWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB0C0911F91C6FB91ULL + 0xF8C0AE045B7766CCULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBF37A122B679220BULL + 0xDD99AB72E88D68B6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB06CF07C9E8EA39DULL + 0xF48902C780B72961ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAD51BAD98D09B263ULL + 0xB53849724CB1EC06ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFC407DE4EB642117ULL + 0xBFC2888C5B3DF8ABULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x86551CF7B61C45EFULL + 0xE37E74C34ED8C4A2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8766FF704B93D58BULL + 0xF37739A38DB0A98AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC11E8AEA016CA303ULL + 0xB117C2883F7A04FEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xAF5FDE9AF07385EDULL + 0xFDF6F796E9CE0A30ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD10E84DDF983B22BULL + 0x9C167211FEA22D07ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC48C0C210469B5D9ULL + 0xE6352E9A8C7BE191ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDE49F779738C5F1BULL + 0x8B40110D541E05D5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA95C9C0C90890D5DULL + 0xF43D452ABD197725ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x81FB7D9F5AD90047ULL + 0xDE5E1EB9F63165D4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8593C1F3EAE43413ULL + 0xD880DFFDA78BBE38ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9A3C318FC989BC0FULL + 0xEEEA28D85B5EF105ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aOperationLaneA, aExpandLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aExpandLaneC, aOperationLaneD
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneB
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1293U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 3944U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2441U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 2467U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 4107U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5384U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCross, 53U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (((aWandererH + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 7948891781097675369U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((((aWandererE + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 13928362874228230226U) + aPhaseHOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 10776180542602258926U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 21U)) + 5735115172149470447U) + aNonceWordC;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 35U)) + 5353591822981766987U) + aNonceWordF;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 43U)) + 562301708107268570U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 13U)) + 10467810247578364868U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14541630141152308564U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2350076897065139429U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12222554362482034393U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17519109078651162228U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6061035173339902910U;
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 15654836633731000065U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13723521735153718904U;
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2849680038315532197U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17336102435576647923U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7671010488872356142U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11485114338165600777U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 4162584865462407791U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8759060657343458985U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11009137869375286581U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 8741417343929809115U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15792999392743144135U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6180808423175992479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13681230339693676907U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 11U)) + aNonceWordI);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aNonceWordO) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterK, 60U)) + aNonceWordB) + aPhaseHWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10503U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((aIndex + 5633U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7564U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 6812U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 7638U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10566U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10039U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 48U)) + (RotL64(aCarry, 35U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 35U)) + 10812151398716051703U) + aNonceWordC;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 22U)) + 18202551453336003710U) + aNonceWordF;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 13U)) + 9434410809101973752U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 57U)) + 12955829998028534045U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 12271740641929640181U) + aNonceWordD;
            aOrbiterF = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 14009351527014534752U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 4316296955679133450U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 16473324966997442872U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15735123324965019802U;
            aOrbiterC = RotL64((aOrbiterC * 5624078184997601019U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17656375090484080236U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 16066325053456055298U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 17912970706985130327U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12908968778503516903U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12761433987676836197U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1023329467480907925U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 12737513138040664509U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 14535795767570998392U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15560519667062222269U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 14370908061811284364U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7001358781208669795U;
            aOrbiterH = RotL64((aOrbiterH * 11641248025734015835U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7298578161120090849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10498302152357484629U;
            aOrbiterA = RotL64((aOrbiterA * 13144110412179037175U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11447343228638006767U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 18284143620422655675U;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aNonceWordH);
            aWandererK = aWandererK + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordN) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + aNonceWordP) + aPhaseHWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 18U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aOperationLaneA
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11562U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneA[((aIndex + 12401U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 11092U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16317U)) & S_BLOCK1], 38U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13904U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 4U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 5U)) + 8604208734152026945U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 1374329953253889829U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 41U)) + 5779278910548228339U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 17670451230882805140U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 11U)) + 8193848740764866860U) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aCross, 53U)) + 15801168428145650104U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 2584718176087499066U) + aNonceWordJ;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 14950366247822737997U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9779293225265670135U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11625969538497982117U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8688968319288372383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13665723186950342601U;
            aOrbiterH = RotL64((aOrbiterH * 292035540396910837U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9395428688359973510U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2152719218018108418U;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1350324137411377992U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8729317951386057921U;
            aOrbiterA = RotL64((aOrbiterA * 6008790836417785083U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6317310451893678411U) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1203082119358827708U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 523869107818193101U;
            aOrbiterB = RotL64((aOrbiterB * 4629501113595689157U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4028324959540432983U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 15447631947468213912U;
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 51U)) + aPhaseHWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterH, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterB, 60U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 41U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 48U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 4
        // ingress from: aExpandLaneA, aWorkLaneA, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneB, aSnowLaneD
        // cross directions: aWorkLaneB backward forced, aSnowLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20311U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 18837U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19887U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17499U)) & S_BLOCK1], 23U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19435U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 56U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 5U)) + 2558105147674438050U;
            aOrbiterE = (aWandererE + RotL64(aCross, 13U)) + 15856662514774702561U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 13346869226246584582U) + aNonceWordD;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 7632111846116243973U) + aNonceWordE;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 35U)) + 2102101361626976279U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = ((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 47U)) + 5605968705067851563U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 29U)) + 6842483186584326681U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5559797213819425064U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12422313931331576759U;
            aOrbiterC = RotL64((aOrbiterC * 7399849122565913401U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2751024420047872601U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11031320239359798610U;
            aOrbiterE = RotL64((aOrbiterE * 8607639453141148025U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14366375309473793217U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11971479429768505316U;
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3947595951884469542U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 17882767922372770896U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 3361906348965810211U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 513871456983509223U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5951677013597794294U;
            aOrbiterI = RotL64((aOrbiterI * 8508629569649935293U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 437626309049021931U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 466674061172005705U;
            aOrbiterF = RotL64((aOrbiterF * 1310502572084891157U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12362602809233133718U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10525852878882195702U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 17755022180514914325U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 6U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterG) + aPhaseHWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26752U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 23716U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26197U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24748U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27280U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 41U)) + 6771552164800695068U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 35U)) + 12131763371571322040U;
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 3326182381395522013U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aIngress, 4U)) + 12288775097697156383U;
            aOrbiterG = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 5195948373449796741U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + 14404044002250137144U) + aNonceWordC;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 3U)) + 11142382920035825426U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2967149520256475485U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1470907369577818097U;
            aOrbiterF = RotL64((aOrbiterF * 9398653295177725883U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9231668148004163910U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13078929163913892386U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7509829068700523627U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9485274692075657877U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12216951187543631673U;
            aOrbiterE = RotL64((aOrbiterE * 6571066246507310805U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6933334652581744234U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17260276102423580920U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7796879893790990605U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 387767848169714392U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 8597538259308082638U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 4888054690557707241U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7996708724489146033U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15357384191688149939U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 9827691726832491373U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17739222908739454637U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1614322333281471170U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 7063116837752240891U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aPhaseHWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + aNonceWordG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 18U)) + aOrbiterB) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + aNonceWordJ);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28176U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 32701U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 27437U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30368U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 28622U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterD = (aWandererA + RotL64(aCross, 23U)) + 15920462086654025436U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 13U)) + 487844076858004017U) + aNonceWordD;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 47U)) + 14502883786442630566U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 27U)) + 3787107318658233674U) + aNonceWordN;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 12548777544693755491U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 57U)) + 4907309444075181683U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 29U)) + 18342396700266492072U) + aPhaseHOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13503051997624242670U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17845742460521374571U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 1366356786138085155U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 8640887211877858169U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5273913123709097537U;
            aOrbiterC = RotL64((aOrbiterC * 1661149444148461791U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17756844173695563883U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6713055830729302951U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 2832836748513174311U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5106468334224035972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10228769728713526172U;
            aOrbiterD = RotL64((aOrbiterD * 9760310686414358435U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 7687649520668883142U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7757480627354711605U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7222553727737349209U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10876291698508634557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8149278085586014186U;
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15592893988925610485U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8639028256640537165U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1880655276432963955U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 58U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 37U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterD, 20U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 44U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
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
        // read from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // twist_loop_a loop 1
        // ingress from: aKeyRowReadA, aKeyRowReadB
        // ingress directions: aKeyRowReadA forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource
        // cross directions: aKeyRowReadA backward forced, mSource backward/forward random
        // write to: aFireLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aKeyRowReadA[((aIndex + 334U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 754U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1240U)) & W_KEY1], 40U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2670U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 12615321415808640429U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 53U)) + 15712784676459931207U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 53U)) + 11013335427004930046U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aScatter, 27U)) + 8298733856304768806U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 39U)) + 6207732959150824216U;
            aOrbiterA = (aWandererE + RotL64(aCross, 19U)) + 9769864876127544038U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 46U)) + 10782181918651152563U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 3U)) + 5790454015845620939U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 15606578025386733803U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5522352539991175304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 5993355818572869649U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15221467311057431139U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10864534396947622047U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12090053126235913528U;
            aOrbiterA = RotL64((aOrbiterA * 7250801471645972261U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14191181677234981396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2258570108233924592U;
            aOrbiterF = RotL64((aOrbiterF * 8307541155393855209U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8448114811381534603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2702389315763499817U;
            aOrbiterH = RotL64((aOrbiterH * 6710443836432274393U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17202184076718780200U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 150549910056015002U;
            aOrbiterI = RotL64((aOrbiterI * 195034681254956335U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4910512055808124967U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4783477997418403079U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 861977492146512865U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13842899106208709771U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7930112618036681468U;
            aOrbiterD = RotL64((aOrbiterD * 8609551859830858419U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8790107242863198659U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6882768826643279144U;
            aOrbiterK = RotL64((aOrbiterK * 13745521454063360763U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12136498871759890015U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8120456314755584336U;
            aOrbiterG = RotL64((aOrbiterG * 1830725195528043575U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 46U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterB) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterF, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterE, 40U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 2
        // ingress from: aFireLaneA, aKeyRowReadA
        // ingress directions: aFireLaneA forward forced, aKeyRowReadA forward/backward random
        // cross from: aKeyRowReadB, mSource
        // cross directions: aKeyRowReadB backward forced, mSource backward/forward random
        // write to: aFireLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneA[((aIndex + 4908U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 4008U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3617U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 4623U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 28U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 39U)) + 17081642665820489793U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 47U)) + 14468854040067229623U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 56U)) + 2249450222593057429U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 43U)) + 14964389079511378664U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 17003491054252360650U) + aPhaseAOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 27U)) + 12710882240582032588U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 9887078182156755359U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 14U)) + RotL64(aCarry, 43U)) + 7665284531810584704U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 7304284015511876717U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5517927023543751734U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17704756310857362759U;
            aOrbiterI = RotL64((aOrbiterI * 15826832172923213591U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11347400363019508578U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11696395232760991243U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9725231749679442003U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10875780291242873583U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 7808740614343437672U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8889516201913716283U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3145390996141902032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16080636485642732615U;
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3929263288176983844U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18210228766683996806U;
            aOrbiterA = RotL64((aOrbiterA * 13178080076505449091U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13948962323541421431U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3037683309790156893U;
            aOrbiterC = RotL64((aOrbiterC * 13406672352222636739U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17827265198532699474U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7270895262023504864U;
            aOrbiterK = RotL64((aOrbiterK * 13467417362477308167U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6431243064980879185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6680205390976259885U;
            aOrbiterJ = RotL64((aOrbiterJ * 10421386694108590789U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 15910655919164357152U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8046213498216027383U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18061867495824063553U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 38U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterK, 52U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 12U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 41U)) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aFireLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 3
        // ingress from: aFireLaneB, aKeyRowReadB
        // ingress directions: aFireLaneB forward forced, aKeyRowReadB forward/backward random
        // cross from: aKeyRowReadA, mSource, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aFireLaneA backward/forward random
        // write to: aFireLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aFireLaneB[((aIndex + 6886U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7067U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6299U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6689U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 5804U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aScatter, 41U)) + 6024062041314952357U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 51U)) + 18340757093658015585U;
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 11911120493880346751U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 37U)) + 17428074353884654439U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 12U)) + RotL64(aCarry, 37U)) + 12790849760814795936U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 12633397052172117800U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 11946150433665237945U) + aPhaseAOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 27U)) + 16842157900909419285U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 46U)) + 14186235783224155962U) + aPhaseAOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13284904542579767591U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11609181965078844357U;
            aOrbiterE = RotL64((aOrbiterE * 5455780554452453513U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9628562297095374984U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 7850281529011259759U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17611485102925470357U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 257458718073794527U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10693404545773519306U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14821443722828498323U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3430519236533871460U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6183054506953198055U;
            aOrbiterC = RotL64((aOrbiterC * 6121082743789970911U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2905610989884221654U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterH = RotL64((aOrbiterH * 7770678426310856745U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16870142883133769663U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1403692060594816451U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9740854430251597879U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16904169913507057108U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4773518591580333357U;
            aOrbiterF = RotL64((aOrbiterF * 5306070307776061267U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6528141733853494275U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11254806909313951442U;
            aOrbiterD = RotL64((aOrbiterD * 6316669786405548827U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6857506858448143407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2855763534355983644U;
            aOrbiterJ = RotL64((aOrbiterJ * 16881334940165182415U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 20U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 58U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 28U) + aOrbiterJ) + RotL64(aOrbiterC, 4U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aFireLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 4
        // ingress from: aFireLaneC, aKeyRowReadB, mSource, aFireLaneA
        // ingress directions: aFireLaneC forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aFireLaneB backward/forward random
        // write to: aFireLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneC[((aIndex + 9602U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 10164U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(mSource[((aIndex + 9234U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10025U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10130U)) & W_KEY1], 20U) ^ RotL64(aFireLaneB[((aIndex + 8629U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 20U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 3105313968748067810U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 23U)) + 9977249451119627064U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 17941392803495349366U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 53U)) + 4279533326705471133U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 46U)) + 13983828966811580039U;
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 3983490984234810378U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 308786542215259956U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 39U)) + 8443607695364427037U) + aPhaseBOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 34U)) + 14939626441464340668U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9350693577306121110U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1717071159396961752U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11062480662625054525U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15911765265202100610U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14898546272333182767U;
            aOrbiterC = RotL64((aOrbiterC * 2674900543810733067U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 3560903518513465868U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5367062725726860234U;
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15233321480618877327U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 9288449812290126074U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5504840529511585676U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6825598386801620046U;
            aOrbiterD = RotL64((aOrbiterD * 11666542445846250077U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6433024450721339470U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 97934156644929458U;
            aOrbiterJ = RotL64((aOrbiterJ * 8630530773006923215U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3260053604798744515U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16539416623243059076U;
            aOrbiterG = RotL64((aOrbiterG * 12199577351166064503U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9814290051339038920U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13280156404507444041U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15269010043398910061U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 11853942590993546833U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13207869904312989977U;
            aOrbiterA = RotL64((aOrbiterA * 15503461937625795969U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 42U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 24U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + (((RotL64(aIngress, 14U) + RotL64(aOrbiterK, 35U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aPhaseBWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 41U)) + aPhaseBWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 18U));
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aFireLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 5
        // ingress from: aFireLaneD, aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB
        // ingress directions: aFireLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, mSource forward forced, aFireLaneB forward/backward random
        // cross from: aFireLaneA, aFireLaneC
        // cross directions: aFireLaneA backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aFireLaneD[((aIndex + 12357U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 12730U)) & W_KEY1], 23U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12473U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 12687U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11470U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12439U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneC[((aIndex + 12136U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 22U)) + RotL64(aCarry, 53U)) + 14624277139785904404U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 6966977309498165611U;
            aOrbiterC = (aWandererB + RotL64(aCross, 47U)) + 205536824352530761U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 13U)) + 16629575265808255692U) + aPhaseBOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 53U)) + 596881340147972746U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 11944412799107412650U;
            aOrbiterF = (aWandererE + RotL64(aCross, 35U)) + 4615021315668210206U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 29U)) + 8497630055977606216U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 41U)) + 11131601107309336885U) + aPhaseBOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5935883479805510099U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15629346719765798174U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8535523790685945275U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5279128339113651273U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16778365912440331821U;
            aOrbiterK = RotL64((aOrbiterK * 705421028266789241U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16003052937645491524U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6723226158737614764U;
            aOrbiterD = RotL64((aOrbiterD * 16690657664909260573U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9785784358981219543U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10055457337292292710U;
            aOrbiterJ = RotL64((aOrbiterJ * 17919129940751761111U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 11779163108592974175U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1177999477942202687U;
            aOrbiterA = RotL64((aOrbiterA * 13475069421684114643U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9190694445141492214U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15605342360346353457U;
            aOrbiterH = RotL64((aOrbiterH * 14547769706392595647U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14877565450677523492U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1074095623308025684U;
            aOrbiterG = RotL64((aOrbiterG * 7884068939436891093U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12803174154216941583U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8813356463693637033U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4898237214617563167U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6063909634038581414U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15112191502834052566U;
            aOrbiterB = RotL64((aOrbiterB * 6780741782103553485U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 34U));
            aWandererB = aWandererB + (((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + aPhaseBWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 18U) + aOrbiterC) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterB, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 6
        // ingress from: aWorkLaneA, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, mSource, aFireLaneB, aFireLaneA
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, mSource backward forced, aFireLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWorkLaneA[((aIndex + 14740U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14179U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15731U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16328U)) & W_KEY1], 3U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 16095U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 14727U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 15537U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 5U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 43U)) + 6361545377408870615U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 19U)) + 2967245486744774933U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 34U)) + RotL64(aCarry, 57U)) + 3836634268482850139U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 39U)) + 7691642115360086297U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 57U)) + 16479280384178279281U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 43U)) + 2901468732552539249U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 30U)) + 2600353867755647475U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 5666596904781510956U) + aPhaseBOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 3U)) + 16108791609267427553U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8389926875737312112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1689501721163024426U;
            aOrbiterG = RotL64((aOrbiterG * 6517194895779049139U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11721701506949917719U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 3963842745030140473U;
            aOrbiterF = RotL64((aOrbiterF * 6692473494944919373U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8510538243472109368U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 18281865214102080387U;
            aOrbiterA = RotL64((aOrbiterA * 1351546966368884609U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2259725140963665123U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 11652011949557979650U;
            aOrbiterI = RotL64((aOrbiterI * 11260100762113295037U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1116085424226174473U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4725260319270802912U;
            aOrbiterD = RotL64((aOrbiterD * 4697109059565450269U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7348945429843437036U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1249234309180653260U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3136745255820405881U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12463505532573389603U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 2304125977906510386U;
            aOrbiterK = RotL64((aOrbiterK * 9960816714791454421U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2178037443783425551U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11712110130079307683U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9797864956200779505U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10703510612147312252U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18155460326242413483U;
            aOrbiterE = RotL64((aOrbiterE * 6903953708987478723U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 22U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aPhaseBWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 46U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterD, 52U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 7
        // ingress from: aWorkLaneB, aKeyRowReadA, mSource, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aKeyRowReadA forward forced, mSource forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadB, aFireLaneD, aWorkLaneA
        // cross directions: aKeyRowReadB backward forced, aFireLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17447U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 18957U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(mSource[((aIndex + 18410U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneA[((aIndex + 17509U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17752U)) & W_KEY1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17419U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 17540U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 30U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 3U)) + 7948891781097675369U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 56U)) + RotL64(aCarry, 11U)) + 13928362874228230226U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 10776180542602258926U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 47U)) + 5735115172149470447U) + aPhaseCOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 5353591822981766987U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 562301708107268570U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 42U)) + 10467810247578364868U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 13U)) + 14541630141152308564U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 35U)) + 2350076897065139429U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17519109078651162228U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6061035173339902910U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10021905773432907835U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15654836633731000065U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13723521735153718904U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14459516479283070563U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2849680038315532197U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17336102435576647923U;
            aOrbiterD = RotL64((aOrbiterD * 10984689101753586739U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7671010488872356142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11485114338165600777U;
            aOrbiterA = RotL64((aOrbiterA * 4162584865462407791U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8759060657343458985U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11009137869375286581U;
            aOrbiterB = RotL64((aOrbiterB * 8741417343929809115U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 15792999392743144135U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6180808423175992479U;
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 361487389591183005U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15292753806514404853U;
            aOrbiterG = RotL64((aOrbiterG * 17478232597253311153U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14929153438443362045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7904556383593914086U;
            aOrbiterK = RotL64((aOrbiterK * 2484130486635511403U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3793180909904286848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10391957637467171320U;
            aOrbiterF = RotL64((aOrbiterF * 505484041943467117U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 27U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 23U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterK, 34U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 8
        // ingress from: aWorkLaneC, mSource, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, mSource forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aKeyRowReadA, aKeyRowReadB, aWorkLaneB, aFireLaneB
        // cross directions: aKeyRowReadA backward forced, aKeyRowReadB backward forced, aWorkLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 21019U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 19514U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19786U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneA[((aIndex + 19422U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21096U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19747U)) & W_KEY1], 47U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19536U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19764U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 1087148170018530502U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 51U)) + 15530846874509311414U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 16987358651515511212U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 5U)) + 12504143181007924259U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 24U)) + 393322117322732418U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 13U)) + 14325937299241887166U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 9395262907017475742U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 19U)) + 13658510441418344769U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 38U)) + 6410754322737005336U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9257290738538818434U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7489828960857692286U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16519674788777989043U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4118778591214588387U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16619215231168796563U;
            aOrbiterH = RotL64((aOrbiterH * 14876884956536265157U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11326283811003573430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1865401866017614604U;
            aOrbiterB = RotL64((aOrbiterB * 8378326058282460073U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 670150121105733604U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1499331510641068749U;
            aOrbiterF = RotL64((aOrbiterF * 16623742535540383107U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1116410848560838532U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2696841341036281779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9598953298074904869U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5487352391229549881U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12008243050943342979U;
            aOrbiterE = RotL64((aOrbiterE * 9087261224804582459U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 552859665927882960U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8426942688524814473U;
            aOrbiterA = RotL64((aOrbiterA * 10916963622695549105U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1613287981244830815U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15592897923468694288U;
            aOrbiterG = RotL64((aOrbiterG * 6600750586743893303U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7629853970631002676U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13778028957247561272U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4063798788229605659U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + aPhaseCWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 12U) + aOrbiterJ) + RotL64(aOrbiterG, 58U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 9
        // ingress from: aWorkLaneD, aKeyRowReadA, aKeyRowReadB, aWorkLaneC
        // ingress directions: aWorkLaneD forward forced, aKeyRowReadA forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: mSource, aWorkLaneA, aFireLaneC, aFireLaneD
        // cross directions: mSource backward forced, aWorkLaneA backward forced, aFireLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneD[((aIndex + 24570U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadA[((aIndex + 22608U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23380U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 21998U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23405U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22254U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22696U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 22233U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 26U)) + 1393781663398437180U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 19U)) + 17414594746688585273U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 13U)) + 2823888497053071250U;
            aOrbiterD = (aWandererF + RotL64(aCross, 51U)) + 17032631958617884859U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 15222697630461125019U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 35U)) + 15737414920751551780U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 1357196111055783001U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 5315122321649251691U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 30U)) + 7893744655508595974U) + aPhaseCOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16721939414324611738U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3444375866323610848U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10874157227815775661U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1825716513674511632U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15582066843912467318U;
            aOrbiterG = RotL64((aOrbiterG * 12765146555943757373U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15673590949193923915U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13887365046280406413U;
            aOrbiterJ = RotL64((aOrbiterJ * 3169061375011420121U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12730414371734709356U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterK = RotL64((aOrbiterK * 8782547948627685451U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3089925954422937464U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7180179304678622530U;
            aOrbiterD = RotL64((aOrbiterD * 16118051565147747413U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17030269962085008657U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 6675917351883004046U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14134335325316949687U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12572022803491077491U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2801421744689267375U;
            aOrbiterF = RotL64((aOrbiterF * 315045745990934023U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4335148696780313055U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12526298573395110141U;
            aOrbiterE = RotL64((aOrbiterE * 11276803410698178607U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6984239833558496091U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12195433952105336808U;
            aOrbiterI = RotL64((aOrbiterI * 8642600547427664495U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 36U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 28U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 52U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterE, 39U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 58U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 52U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 10
        // ingress from: aExpandLaneA, aKeyRowReadA, aWorkLaneD, aWorkLaneB
        // ingress directions: aExpandLaneA forward forced, aKeyRowReadA forward forced, aWorkLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aKeyRowReadB, mSource, aWorkLaneC, aFireLaneD
        // cross directions: aKeyRowReadB backward forced, mSource backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26224U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[((aIndex + 24744U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25896U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25640U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24704U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26781U)) & S_BLOCK1], 48U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25667U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25515U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + 2915859148137000694U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 210680583721444425U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 29U)) + 6668118118775650387U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 5U)) + 15794200818099010989U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 6U)) + 6565076707062828369U;
            aOrbiterI = (aWandererG + RotL64(aCross, 47U)) + 16323164497808856719U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 53U)) + 7965435318816716560U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 41U)) + 7390281030573369017U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 34U)) + RotL64(aCarry, 37U)) + 2269738866911824875U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9664014216039993873U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18284857398028357633U;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 367667619795303009U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16683666162337789540U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10655658270998102390U;
            aOrbiterC = RotL64((aOrbiterC * 15231596813382239841U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8307037916581540297U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 3247742749860703524U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15052136713218656641U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10446792483683818139U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16374602929344972364U;
            aOrbiterE = RotL64((aOrbiterE * 12599903932725787599U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 2411334498322777183U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1093701164116833765U;
            aOrbiterH = RotL64((aOrbiterH * 13129220206835381729U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17018480952982840635U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17348395690080029814U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6212591395713433257U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16111252311283623152U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12776492920397785951U;
            aOrbiterB = RotL64((aOrbiterB * 6136009241593081821U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12214538600808144816U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10043377462096783363U;
            aOrbiterG = RotL64((aOrbiterG * 14639467375095185877U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 18U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 12U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 23U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_a loop 11
        // ingress from: aExpandLaneB, aWorkLaneD, aKeyRowReadB, aWorkLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aKeyRowReadB forward forced, aWorkLaneC forward/backward random
        // cross from: aKeyRowReadA, mSource, aExpandLaneA, aWorkLaneB
        // cross directions: aKeyRowReadA backward forced, mSource backward forced, aExpandLaneA backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29632U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 29218U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27386U)) & W_KEY1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 27396U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28956U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27863U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28138U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29636U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 19U)) + (RotL64(aIngress, 40U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 14499676118633326000U;
            aOrbiterE = (aWandererH + RotL64(aCross, 27U)) + 17191273593018552288U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 53U)) + 4085176294948097737U) + aPhaseDOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 57U)) + 11112671474158908186U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 8745787969012266485U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 18074049663777707948U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 19U)) + 2543758649719164688U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 43U)) + 4659584749412700523U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 4U)) + 974639159259871273U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9211220687971081987U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8567024626862182714U;
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5803002132294840900U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11968489432878148467U;
            aOrbiterE = RotL64((aOrbiterE * 4501441062617123165U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9470807228394903442U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1692347973120388469U;
            aOrbiterK = RotL64((aOrbiterK * 17433393164156231575U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16510815732690193145U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 755159406833096510U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1518824876475937620U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 701225390867330446U;
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8425976693733003889U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7182176375442410367U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8860605703761731859U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4546566785167467924U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2593340999038753749U;
            aOrbiterH = RotL64((aOrbiterH * 10152461487764567563U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9756331608356622299U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5511625814747641978U;
            aOrbiterF = RotL64((aOrbiterF * 4806076157539829529U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8694400787420160733U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12648969491371382682U;
            aOrbiterJ = RotL64((aOrbiterJ * 5346585704222643759U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 26U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 38U) + aOrbiterJ) + RotL64(aOrbiterC, 12U));
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterI) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_a loop 12
        // ingress from: aExpandLaneC, aKeyRowReadA
        // ingress directions: aExpandLaneC forward forced, aKeyRowReadA forward/backward random
        // cross from: aWorkLaneD, aExpandLaneA, aExpandLaneB, aKeyRowReadB
        // cross directions: aWorkLaneD backward forced, aExpandLaneA backward forced, aExpandLaneB backward forced, aKeyRowReadB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aExpandLaneC[((aIndex + 30149U)) & S_BLOCK1], 50U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31798U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 32057U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31032U)) & S_BLOCK1], 40U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30162U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadB[((aIndex + 30673U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCarry, 11U)) + (RotL64(aIngress, 47U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 13U)) + 7270044678408187242U) + aPhaseDOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 10192278965379756766U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 14U)) + RotL64(aCarry, 35U)) + 17568666746676060748U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 47U)) + 14312927531124963037U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 43U)) + 9825825726152087706U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 5U)) + 9696778570255265896U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 56U)) + 17657841352013417228U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 29U)) + 16207815085909628439U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 39U)) + 1752979206374514227U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10456310689643905854U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16127830548663742550U;
            aOrbiterJ = RotL64((aOrbiterJ * 4355938404839045417U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2940917376003930842U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7353596864777649953U;
            aOrbiterK = RotL64((aOrbiterK * 7499468723171042005U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12725092740446150705U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5791296650856037010U;
            aOrbiterG = RotL64((aOrbiterG * 760379251950502133U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1200130368046206150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16689604428598558547U;
            aOrbiterC = RotL64((aOrbiterC * 13815324235939996623U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14359561591103730856U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3975025843599045263U;
            aOrbiterD = RotL64((aOrbiterD * 5025047888533298617U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14017901732955607601U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10431526786489555196U;
            aOrbiterE = RotL64((aOrbiterE * 10181915874476132407U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 7320527073559849223U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15333411223710709907U;
            aOrbiterH = RotL64((aOrbiterH * 3488684905528068775U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14302474063321663801U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2104154521019935187U;
            aOrbiterF = RotL64((aOrbiterF * 12944382959742278055U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 5167600586916325228U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4566823109447208716U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9997799807454267443U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 10U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 6U) + aOrbiterH) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 24U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 20U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneB, aOperationLaneA, aFireLaneC, aFireLaneD, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneB
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneB backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2791U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 731U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 494U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 151U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 286U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6287U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 11480359716598965890U;
            aOrbiterC = (aWandererA + RotL64(aCross, 43U)) + 15431182525482873419U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 13U)) + 11360504974812776707U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 9292576416573382769U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 19U)) + 1549257414531028975U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 60U)) + 5347769463033129317U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 17019199177478377234U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16558106007323125094U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3976182233825939422U;
            aOrbiterJ = RotL64((aOrbiterJ * 4392162052317572289U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2889047161195954395U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2241831345026962605U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5757458560979927857U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12850802412140579294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13541744735436450160U;
            aOrbiterF = RotL64((aOrbiterF * 906089290000537439U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2085863085516538212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2969034221711544086U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6482666944512391472U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16969153556875844613U;
            aOrbiterB = RotL64((aOrbiterB * 9483462388353216219U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5161314086757363678U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7150282484670673211U;
            aOrbiterI = RotL64((aOrbiterI * 8522427002337918663U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5465304381272305847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2344610773390354017U;
            aOrbiterG = RotL64((aOrbiterG * 17010258514288089191U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 18U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 3U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterB, 39U));
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 56U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererI = aWandererI + (((RotL64(aCross, 36U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 9004U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 11096U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10724U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10083U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12765U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13538U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 11904U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aPrevious, 51U)) + 9435962834163239322U;
            aOrbiterA = (aWandererD + RotL64(aCross, 11U)) + 10524704356081318973U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 7403401305665208680U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 7525414805023556493U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 57U)) + 1116686470029070951U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 3U)) + 13257612299137802420U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 38U)) + RotL64(aCarry, 41U)) + 9181543003986598283U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9739384852307501107U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11308402900229016057U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12690186771773188967U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14935167593705272337U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7171824007631943535U;
            aOrbiterK = RotL64((aOrbiterK * 4839974427616194289U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8068411284829563567U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12350207458513447578U;
            aOrbiterD = RotL64((aOrbiterD * 813973258659041895U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17039236343991574134U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18291683592714999632U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7771718817924840713U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6239616841884430968U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10604527977569876774U;
            aOrbiterC = RotL64((aOrbiterC * 6972820410084939637U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1707724300671717658U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 3802268808625297647U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9423064323799920219U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 242153923313096551U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12117679073775630197U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 22U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 11U)) + aOrbiterG) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterA, 51U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 60U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 12U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneA forward forced, aExpandLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 20328U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 21771U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 21263U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 17048U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21441U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18487U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17307U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 51U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 43U)) + 13854738573712660276U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 29U)) + 16835460633412286294U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 13U)) + 6785859293758091931U) + aPhaseEOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 47U)) + 126317283127992659U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 41U)) + 7568963536291415413U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 12294016745653004819U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 35U)) + 18269588932920281147U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5872406424994751026U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7764434758831474129U;
            aOrbiterJ = RotL64((aOrbiterJ * 3772146788188420071U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4804168969415573371U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 959601763507651280U;
            aOrbiterE = RotL64((aOrbiterE * 4647396592804833217U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9257644462479293048U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14332699366894494579U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8829304078930625541U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10487012596470786004U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 612729229562321440U;
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7845523921295625315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10294667720904610944U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14369711143154904567U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13753005602288309379U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10918344717497681894U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18136794828308636957U;
            aOrbiterK = RotL64((aOrbiterK * 17899418637978002409U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 44U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 50U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 38U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aExpandLaneD, aWorkLaneC
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aExpandLaneD forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneB, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32153U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 28212U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30398U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 24631U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29910U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30771U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 31416U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 51U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 43U)) + 5171470532667965920U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 5U)) + 750549462358682403U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 35U)) + 3325689257577120525U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 27U)) + 18031575461559790826U;
            aOrbiterD = (aWandererI + RotL64(aCross, 19U)) + 13874739537012288677U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 4250029868785016865U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 8211158803112611161U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1083939790236786027U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3446525462376962464U;
            aOrbiterC = RotL64((aOrbiterC * 13603702473750888213U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6973817815000417325U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 15230876489676945543U;
            aOrbiterH = RotL64((aOrbiterH * 7737039082964537651U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9359727659738755880U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8775170107816327654U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6910680458261008653U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11958941755525038545U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16966819714283167348U;
            aOrbiterJ = RotL64((aOrbiterJ * 16363457661846050749U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14556087985619763243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17915047508377045221U;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8578745677485367222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7002181668717618866U;
            aOrbiterG = RotL64((aOrbiterG * 12329703532414955235U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3569939503066735457U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2956247934282522184U;
            aOrbiterE = RotL64((aOrbiterE * 9946650822131152531U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 38U) + aOrbiterE) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 6U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aWorkLaneA, aFireLaneC, aFireLaneD, aWorkLaneB, aExpandLaneA, aExpandLaneB, aWorkLaneC, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 6843U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 5944U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2521U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4858U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1519U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4668U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 54U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 5U)) + 8604208734152026945U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 1374329953253889829U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 41U)) + 5779278910548228339U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 27U)) + 17670451230882805140U;
            aOrbiterA = (aWandererI + RotL64(aCross, 29U)) + 8193848740764866860U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 15801168428145650104U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 20U)) + 2584718176087499066U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 39U)) + 14950366247822737997U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 23U)) + 9779293225265670135U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 53U)) + 8688968319288372383U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 51U)) + 13665723186950342601U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9395428688359973510U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 2152719218018108418U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15271961483518392671U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1350324137411377992U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8729317951386057921U;
            aOrbiterB = RotL64((aOrbiterB * 6008790836417785083U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 6317310451893678411U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10175620379041384281U;
            aOrbiterE = RotL64((aOrbiterE * 14079679617394330781U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1203082119358827708U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 523869107818193101U;
            aOrbiterA = RotL64((aOrbiterA * 4629501113595689157U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4028324959540432983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterI = RotL64((aOrbiterI * 6037306615787729185U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14225888694733041031U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 11925000696281947629U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4337022940520411253U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15015531024930608745U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16752579225076943550U;
            aOrbiterC = RotL64((aOrbiterC * 15551083683579981439U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2432733494869267901U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10103430321388601485U;
            aOrbiterJ = RotL64((aOrbiterJ * 18372919379972432569U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15943360147468638325U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9782703760233558733U;
            aOrbiterF = RotL64((aOrbiterF * 685056980418243879U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18345087852012669037U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8897505040792027675U;
            aOrbiterH = RotL64((aOrbiterH * 14333687539092412967U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7402581293947129667U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8604208734152026945U;
            aOrbiterG = RotL64((aOrbiterG * 9965525485538037673U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 46U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 30U) + aOrbiterF) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 10U)) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 40U) + aOrbiterD) + RotL64(aOrbiterE, 46U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12230U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 15030U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 14338U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 9815U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15751U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10996U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 13300U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 3U)) + 10038936806177516123U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 21U)) + 1773168435195292638U;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 46U)) + RotL64(aCarry, 41U)) + 10655711161526628072U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 43U)) + 14422295664639740437U;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 19U)) + 4125228715513159576U;
            aOrbiterD = (aWandererE + RotL64(aCross, 29U)) + 3670449653158650845U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 35U)) + 17553727567180813057U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 5111401772713882743U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 27U)) + 7688573124662314413U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 9438375825507814395U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 54U)) + 14177477039902118886U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16329942595859623928U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3990536794006836672U;
            aOrbiterB = RotL64((aOrbiterB * 579024714339065373U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5072881436583180756U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16789727877867289997U;
            aOrbiterA = RotL64((aOrbiterA * 8766246302636197905U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17313956922306689438U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 11530878396329822041U;
            aOrbiterJ = RotL64((aOrbiterJ * 11356860047841383129U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3612616532321160196U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4172189825359187763U;
            aOrbiterI = RotL64((aOrbiterI * 12938945495299393177U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8677279703778052804U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1912172980909479362U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10053289257955474143U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1460085850227494500U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12116763868122868147U;
            aOrbiterK = RotL64((aOrbiterK * 6076945628020280957U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17571840610366424432U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15581362592611080868U;
            aOrbiterH = RotL64((aOrbiterH * 1129054058044872003U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14434700039977611666U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4534294602623329152U;
            aOrbiterG = RotL64((aOrbiterG * 5860911553425182045U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 865998255725903702U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16407778704555344108U;
            aOrbiterE = RotL64((aOrbiterE * 15571344643129797977U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1948990288894429805U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18218556219056835250U;
            aOrbiterD = RotL64((aOrbiterD * 16574160087642377293U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1309229265173143398U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10038936806177516123U;
            aOrbiterF = RotL64((aOrbiterF * 12954594462760207923U), 27U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 14U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aScatter, 34U) + aOrbiterH) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterB, 34U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneC, aExpandLaneB
        // cross directions: aWorkLaneA backward forced, aOperationLaneC backward forced, aExpandLaneB backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21568U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 22409U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20584U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 17463U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22636U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23640U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 19049U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 4U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 11U)) + 17936518874386450467U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 53U)) + 13722737841589910344U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 48U)) + 11774969167948715796U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 3640101505680493777U) + aPhaseFOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 23U)) + 1369495382725650822U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 11827310354654653345U;
            aOrbiterG = (aWandererF + RotL64(aCross, 14U)) + 186037671377175394U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 41U)) + 11428829344234627340U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 2275016369870029068U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 15471646673734798328U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 37U)) + 12172082573115640145U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6626736341348283154U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12220614992483863623U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8137086205714097487U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13157102324253760215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4143587482368093601U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5060677690991506895U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11007575246013796426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11721585930088637162U;
            aOrbiterB = RotL64((aOrbiterB * 15009627907125738519U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5720789204450196217U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 3094696226821431648U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4412033981712165541U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14675830108100986773U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9444071495289719645U;
            aOrbiterC = RotL64((aOrbiterC * 10983136361953366557U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5106753847015199956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7585421898593510010U;
            aOrbiterH = RotL64((aOrbiterH * 140996914192351011U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11746948407655524690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16336323220286344483U;
            aOrbiterG = RotL64((aOrbiterG * 6590417628835864497U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8030445186765781136U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 276034088015165891U;
            aOrbiterD = RotL64((aOrbiterD * 7626025612710225099U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8116955322602209153U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5704503350608834450U;
            aOrbiterA = RotL64((aOrbiterA * 7049558959583832449U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8063875087087055875U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1111816778196345760U;
            aOrbiterK = RotL64((aOrbiterK * 13820440198677609571U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7702895879089714461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 17936518874386450467U;
            aOrbiterE = RotL64((aOrbiterE * 12767279443267850009U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 6U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 34U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 11U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 29U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterB, 24U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD, aExpandLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward forced, aExpandLaneC forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB, aExpandLaneD
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward forced, aExpandLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26230U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((aIndex + 31282U)) & S_BLOCK1], 53U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 27536U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 30852U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24971U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29091U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 25826U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 5041131702736607991U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 9295010428212681446U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 29U)) + 6235875895358766017U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 2622227802531866918U;
            aOrbiterC = (aWandererB + RotL64(aCross, 3U)) + 3888894734834524972U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 14U)) + 241682012014701753U) + aPhaseFOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 57U)) + 15758000422451568079U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 2061944548396976912U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 21U)) + 8177144990755754531U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 41U)) + 554978075608818497U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 60U)) + 250408260560714933U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8700027645880997552U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10026130047465480902U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9785843014096326696U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9998582683258411251U;
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13817734599383455151U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6647207154174092691U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1578528131687283531U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4957715980509035719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4994885315786213197U;
            aOrbiterD = RotL64((aOrbiterD * 5676683798126497011U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5072908311783966503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5535039946192891515U;
            aOrbiterF = RotL64((aOrbiterF * 2989412783482309753U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6594577050344146271U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8750154123258714856U;
            aOrbiterK = RotL64((aOrbiterK * 6942158167127532003U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3514769314840874873U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8626045200273524281U;
            aOrbiterA = RotL64((aOrbiterA * 4315441782689789689U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8524870284841706517U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1841819423572964209U;
            aOrbiterB = RotL64((aOrbiterB * 9802481758007234681U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12668382464510772517U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6330331402801670515U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9096920618612750935U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10346986196055766087U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10932918162471200996U;
            aOrbiterH = RotL64((aOrbiterH * 6863632877625141567U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6264557195446069146U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5041131702736607991U;
            aOrbiterJ = RotL64((aOrbiterJ * 4978591546106895045U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 28U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterE, 56U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 6U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 54U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
        // ingress from: aWorkLaneA, aWorkLaneB, aWorkLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aWorkLaneB, aWorkLaneC, aWorkLaneD
        // cross directions: aWorkLaneB backward forced, aWorkLaneC backward forced, aWorkLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7532U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 6770U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3758U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2619U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4124U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4294U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 6654158889644956636U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 56U)) + 9045779659363991870U) + aPhaseGOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 3888897662136993491U) + aPhaseGOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 51U)) + 6882016842864459345U;
            aOrbiterE = (aWandererD + RotL64(aCross, 47U)) + 15601891715956172291U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5176811598629335350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12519945150889074325U;
            aOrbiterD = RotL64((aOrbiterD * 8721098129033306427U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4552583214397603278U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14225482701804864688U;
            aOrbiterJ = RotL64((aOrbiterJ * 8526052833180466359U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5485298070606280363U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11237713257388094289U;
            aOrbiterH = RotL64((aOrbiterH * 11032429223099413011U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14340345895626142788U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16275167270553643347U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14041860597556520250U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1436068974197066343U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3938460345031496843U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 14U)) + aPhaseGWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10645U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 12334U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11200U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13811U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14666U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12645U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 12380376990224645149U) + aPhaseGOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 18296928500297384014U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 13U)) + 3550626816361145100U) + aPhaseGOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 2667792936946706027U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 42U)) + RotL64(aCarry, 29U)) + 12020969779370926953U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 737340727886903447U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1681797651799760502U;
            aOrbiterK = RotL64((aOrbiterK * 11923920414802777451U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2956186342689489064U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1876852870402977177U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8875540081346621757U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6433205819353555071U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9065076854974222998U;
            aOrbiterE = RotL64((aOrbiterE * 5459675878087242021U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3254410578766789992U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2005081975473815576U;
            aOrbiterH = RotL64((aOrbiterH * 9947701153722014085U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15992999234834560419U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3458344156815120948U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 48U)) + aOrbiterE) + aPhaseGWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23506U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 16574U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 21342U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24384U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17442U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18344U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 6361545377408870615U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 2967245486744774933U) + aPhaseGOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 3836634268482850139U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 7691642115360086297U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 52U)) + 16479280384178279281U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2901468732552539249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2600353867755647475U;
            aOrbiterF = RotL64((aOrbiterF * 1140827276372862433U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5666596904781510956U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16108791609267427553U;
            aOrbiterB = RotL64((aOrbiterB * 8904649663479834199U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 8389926875737312112U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1689501721163024426U;
            aOrbiterC = RotL64((aOrbiterC * 6517194895779049139U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11721701506949917719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3963842745030140473U;
            aOrbiterJ = RotL64((aOrbiterJ * 6692473494944919373U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 8510538243472109368U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 18281865214102080387U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1351546966368884609U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 58U)) + aOrbiterF) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30472U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 27582U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31858U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29685U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26197U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 27174U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 35U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 51U)) + 12583180859826261500U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 9067093488553721468U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 43U)) + 12173106198862881754U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 11333491014394592654U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 24U)) + RotL64(aCarry, 37U)) + 3511883526940919554U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7416810692106273044U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8341174972619784110U;
            aOrbiterE = RotL64((aOrbiterE * 17722163445765437279U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2220852854836962979U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8090781422229383825U;
            aOrbiterF = RotL64((aOrbiterF * 578293950675644397U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2338801236599102223U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12484514711848308104U;
            aOrbiterG = RotL64((aOrbiterG * 10364216764253366067U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 13684861340589131816U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12796636819991873058U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5533508014234835669U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7634198650894837690U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10240326122201201762U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8758703497719125901U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterG, 19U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 52U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2789U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 4905U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 897U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2039U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4309U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4075U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 40U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 19U)) + 13333509828310369865U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 7645352517103840797U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 5310766306660062655U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 5165635069832352932U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aIngress, 30U)) + 15684141764734281849U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3327963374225061738U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8625811794878848871U;
            aOrbiterE = RotL64((aOrbiterE * 16327750494894125333U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7598657468430485291U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2881171216276746485U;
            aOrbiterA = RotL64((aOrbiterA * 3331350584102843605U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10237691227222918101U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6419254255884834497U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3816625473642865305U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4238455444646479956U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14936613353493061492U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3544216916806292273U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15324699725208372627U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9506640480601832011U;
            aOrbiterB = RotL64((aOrbiterB * 12819564111348390227U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 36U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 57U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 54U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10055U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((aIndex + 11989U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12563U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10143U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15399U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8217U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 8367680518550579791U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 11U)) + 11491674725611181241U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 11U)) + 16673861720782164214U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 9786610124108350855U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 19U)) + 5745080601557577637U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1959402215131684684U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6121650036079196522U;
            aOrbiterF = RotL64((aOrbiterF * 13375345606276198671U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12016309761037342392U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5986936646177049603U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3585650475703294895U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1000367700904043468U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17425288243569101032U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2174614006719048535U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4856917474950325209U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 16312111093223166419U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11046477664487805241U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 456110002032422270U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11393724374787795662U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterH, 21U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterH, 40U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererH, 36U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22580U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 21637U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 24433U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22546U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16643U)) & S_BLOCK1], 24U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 22179U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 34U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 13U)) + 5906639480605353429U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 3U)) + 5293518570213287605U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 15383185501428521377U) + aPhaseHOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aScatter, 39U)) + 15364072512743978902U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 4525473357144014271U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10400911938125603074U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16417506293824627550U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8303380456072515611U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2419329331753341815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14929222427923332069U;
            aOrbiterD = RotL64((aOrbiterD * 11596261802662514979U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16771573504983922586U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1863466450051787622U;
            aOrbiterB = RotL64((aOrbiterB * 2585626547126027053U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12895350137096692415U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3700979086526298327U;
            aOrbiterG = RotL64((aOrbiterG * 10279730254867618193U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1977099106211282426U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6144698304096915742U;
            aOrbiterI = RotL64((aOrbiterI * 5039822990560519609U), 51U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterG, 43U));
            aWandererA = aWandererA + (((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterG, 23U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26207U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 28322U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32598U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25133U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25806U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32164U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 42U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 58U)) + 16189787374324972735U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 17563763730956242224U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 10572803498593789385U;
            aOrbiterB = ((aWandererE + RotL64(aCross, 47U)) + 7713105232072974166U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 10760839534772718139U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13397069448391230253U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4569255679998375682U;
            aOrbiterE = RotL64((aOrbiterE * 15163488708398248639U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9888769350817876949U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11351796060878856300U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13356749147334008399U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18153775071965707204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1282846411145853435U;
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16457743979262460660U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 173493260775251032U;
            aOrbiterG = RotL64((aOrbiterG * 4935807229040883505U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 3927345926316409630U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 5158769729850853623U;
            aOrbiterB = RotL64((aOrbiterB * 2446452358663812945U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 38U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 22U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
