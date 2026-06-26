#include "TwistExpander_Cricket_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Cricket_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCFA2B3B32B58F677ULL + 0xFF52800E0EDC1864ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF8E6CB79BDAB7E39ULL + 0x833149B16AD61579ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD8E5D75D988531CFULL + 0xC18C5F8FBDF37211ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCCB4FF824E3C017BULL + 0xAE34400408224B48ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC0CDF5C6863651CBULL + 0xD135190B9733033DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC0CA25DD9CD4D78DULL + 0x9B48F03E9F4F1184ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x871D4CA0B8F26487ULL + 0xAD8CBA85B9F543C2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE0AD43FD8712B2E9ULL + 0x90DBC62222669A0DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEA9A5D04BBCD0DB1ULL + 0xB36F99224935495AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC950860A3264840FULL + 0xBD2E721E5C288BFFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBCF7399389C7A40BULL + 0xA83EB992A0927FBAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAAA2409A67ACC785ULL + 0xA349A69B5D840204ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDB2311380038853FULL + 0xD6DF6F57613A2AD6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x871572C2780F8F0BULL + 0xE23361339F348C4BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEDB8EA95A224A00DULL + 0xD0D5C6EF23F63D07ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC001F03B8D83A81FULL + 0xC62A25C11C295F97ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1709U)) & S_BLOCK1], 50U) ^ RotL64(pSnow[((aIndex + 1483U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3112U)) & S_BLOCK1], 30U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3065U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 38U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aIngress, 46U)) + 1888427424966603593U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 41U)) + 5436761445660415091U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 27U)) + 17322876217962143270U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 9728299982740564979U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 29U)) + 301720335271716921U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 23U)) + 8069685428854814396U;
            aOrbiterH = (aWandererF + RotL64(aCross, 5U)) + 1973715500949100991U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 19U)) + 87666408799854155U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 12195436904339035245U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 57U)) + 4578742069143400295U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 35U)) + 7828776048774876484U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17203146364542781833U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16913369550858890466U;
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9632761514552265402U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9106637671877341286U;
            aOrbiterG = RotL64((aOrbiterG * 9073709119482640391U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15423680889126750876U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6087310684583331882U;
            aOrbiterB = RotL64((aOrbiterB * 8964465129744898619U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5420955876411796789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14166807419730848032U;
            aOrbiterE = RotL64((aOrbiterE * 442659738632823751U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8118312450347026824U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 4253043584558403086U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5651748455190536467U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8810774678371762700U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 12218479555589447835U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11026364205248516355U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11389930523582876358U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16334420553471379915U;
            aOrbiterC = RotL64((aOrbiterC * 13830132212033904777U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18201289372553710279U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7196540389657785361U;
            aOrbiterF = RotL64((aOrbiterF * 13058135202554889791U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 2601046573550065116U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2243003381737071984U;
            aOrbiterD = RotL64((aOrbiterD * 10518763530499878945U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6058992247656841580U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10083863011670540073U;
            aOrbiterJ = RotL64((aOrbiterJ * 17908394295613117155U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8505005026063156940U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1888427424966603593U;
            aOrbiterA = RotL64((aOrbiterA * 18298382581929885653U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 39U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterH, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 21U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 50U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7995U)) & S_BLOCK1], 4U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8465U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6327U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 7073U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 17668251151213543491U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 16101602509895104517U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 39U)) + 9083915270773304935U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aPrevious, 18U)) + 12810720730318214811U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 57U)) + 18113428002071925621U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 47U)) + 1582208899354109878U) + aNonceWordO;
            aOrbiterI = (aWandererB + RotL64(aIngress, 43U)) + 4180688104819188154U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 5U)) + 8954598189262820611U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 14U)) + 15360094153175355879U) + aNonceWordP;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 23U)) + 8383954114668216260U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 15626783326234049197U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 10609978564404958066U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17656516608997517984U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4590620354119899777U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 760077259110786536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3597338735888033063U;
            aOrbiterA = RotL64((aOrbiterA * 6548831472863517621U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4431777844935985157U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10710423172154671296U;
            aOrbiterD = RotL64((aOrbiterD * 16267496318491473315U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10240882795242085185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7826053487019825891U;
            aOrbiterI = RotL64((aOrbiterI * 15053729937684375907U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9418883403715727353U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11507423614799075545U;
            aOrbiterG = RotL64((aOrbiterG * 16189463984557044693U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11545217316421066655U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 617921402135485341U;
            aOrbiterC = RotL64((aOrbiterC * 8182920764965471653U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14456933220749921009U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7990243583564535387U;
            aOrbiterB = RotL64((aOrbiterB * 5994900368027985469U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14023633125757654751U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11319146808574958827U;
            aOrbiterF = RotL64((aOrbiterF * 13676159969338309307U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14161653180846538446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17993503892528842342U;
            aOrbiterK = RotL64((aOrbiterK * 12184170842617942651U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 10449311783872638478U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17210495321003036773U;
            aOrbiterJ = RotL64((aOrbiterJ * 17591257107603354151U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14586515403314763393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17668251151213543491U;
            aOrbiterH = RotL64((aOrbiterH * 9367185933291003363U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 18U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 27U)) + aOrbiterK) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterI, 5U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + aNonceWordE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + aNonceWordH);
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterG, 50U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15769U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13656U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11457U)) & S_BLOCK1], 41U) ^ RotL64(pSnow[((aIndex + 16277U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 50U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 1457104756581596530U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 6127240317844622874U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 51U)) + 16492290056044189421U) + aNonceWordJ;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 56U)) + 10963676850938416468U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 11U)) + 4872917367399752405U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 15218882377875616148U) + aNonceWordB;
            aOrbiterB = (aWandererE + RotL64(aCross, 29U)) + 5934166612122118251U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 27U)) + 14215280930872003003U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 11428034799044600979U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 60U)) + 5453003654321728726U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 13U)) + 14273775120265649389U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 328723770018440271U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13032190719588211088U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2386881543033598494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1649501123340887116U;
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16462401546754210583U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1510579201823042227U;
            aOrbiterA = RotL64((aOrbiterA * 16287912400104043275U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6889066000014251983U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11324594596597724357U;
            aOrbiterF = RotL64((aOrbiterF * 15344987814648586023U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12237796033168436537U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17306069670330000343U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3167451351403385259U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14197284538008811658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4754134852883071927U;
            aOrbiterE = RotL64((aOrbiterE * 3484427259538998699U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17201907781639753736U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8318419319239859855U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 10320390501983802091U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16012488623961565780U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15583721012865354925U;
            aOrbiterK = RotL64((aOrbiterK * 10656414363201743961U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14680351201973315018U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14483973292275372321U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 9279222721410811027U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16324317860030681248U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7038506963317910910U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2960451734542956767U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12767672960346001218U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1457104756581596530U;
            aOrbiterI = RotL64((aOrbiterI * 1560375242310194691U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 58U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + aNonceWordL);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterA, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16894U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 18803U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17754U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((aIndex + 19373U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 47U)) + 9471546960258473684U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 18050235435948942244U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 4U)) + RotL64(aCarry, 53U)) + 3005107102671544641U;
            aOrbiterB = (aWandererG + RotL64(aCross, 13U)) + 17898396434573801850U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 53U)) + 15071602525497771648U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 51U)) + 5780119462702672108U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 18U)) + 13301326224151025687U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 29U)) + 18129323022260575961U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 1199228670638790709U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 1839199978088021020U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 27U)) + 4999517042246790165U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8788607633376516299U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15143903839930468749U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12735914889325422675U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16674732686428431869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15908873150953195581U;
            aOrbiterE = RotL64((aOrbiterE * 18049755517524334107U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 11204775359756474667U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2525984309543939465U;
            aOrbiterA = RotL64((aOrbiterA * 3988529812023791571U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4566345170476825512U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14876612901557406267U;
            aOrbiterC = RotL64((aOrbiterC * 9047956948845135339U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14926290877038883931U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12710203178186614846U;
            aOrbiterK = RotL64((aOrbiterK * 14841163494801662515U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7315094513967387996U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11050116830482816766U;
            aOrbiterJ = RotL64((aOrbiterJ * 3702999495721152019U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4505368486032503953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17905748055257551092U;
            aOrbiterG = RotL64((aOrbiterG * 14775870175093453197U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 5728886950801376350U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17998141690182325170U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16008599930125391379U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4325978018819134558U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13526905108565989379U;
            aOrbiterH = RotL64((aOrbiterH * 14121321495714166291U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10597169665474269506U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7500801022830471869U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 3702717219742363777U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17063616328548689935U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9471546960258473684U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 3029748230803396737U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 10U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterF, 22U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererD = aWandererD + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 24U)) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + aOrbiterG) + RotL64(aOrbiterD, 13U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererC, 34U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26239U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 22671U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24444U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23613U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 37U)) + 7075016829833562104U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 19U)) + 8783765886115517036U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 2996723892384565829U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 21U)) + 9494134707342189476U) + aNonceWordA;
            aOrbiterG = (aWandererA + RotL64(aScatter, 23U)) + 5052642981395679904U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 41U)) + 8766787055127962238U) + aNonceWordP;
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 4467211954388738079U;
            aOrbiterA = (aWandererH + RotL64(aCross, 46U)) + 8030255604633658608U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 16962408063455702251U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 53U)) + 3768222186567699076U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 14930990410207899871U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14179761938395502502U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1879084742719898108U;
            aOrbiterH = RotL64((aOrbiterH * 16783034788172670121U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5535012408925981515U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12792553516710295939U;
            aOrbiterI = RotL64((aOrbiterI * 8577530993755159329U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8979253163346099252U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5559189896063990740U;
            aOrbiterA = RotL64((aOrbiterA * 8832485423727331621U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13937564337299044079U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2393376759689394948U;
            aOrbiterJ = RotL64((aOrbiterJ * 2352815657830413941U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12647519563697356479U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10946871249960389549U;
            aOrbiterC = RotL64((aOrbiterC * 6272580371881237173U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13376798695582123147U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10958115913599631271U;
            aOrbiterE = RotL64((aOrbiterE * 18233981473003345217U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4283914227806672773U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 910842005516235816U;
            aOrbiterB = RotL64((aOrbiterB * 6722229871617873429U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1509644316619370324U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 165987596716078174U;
            aOrbiterK = RotL64((aOrbiterK * 13600064054240185123U), 37U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 12491315345199091186U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5982431705686495125U;
            aOrbiterF = RotL64((aOrbiterF * 2547243804779022665U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 231183123382412440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2872632389683254396U;
            aOrbiterD = RotL64((aOrbiterD * 1972278820468847241U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15259314110008210315U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7075016829833562104U;
            aOrbiterG = RotL64((aOrbiterG * 8350093877370898869U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterC, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 39U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterG, 46U));
            aWandererB = aWandererB + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterK, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aNonceWordL);
            aWandererA = aWandererA + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterB, 48U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28197U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 27315U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29291U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28019U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 60U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 11U)) + 16451272412693907816U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 10099485419723255462U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 51U)) + 17668900099534923192U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 3U)) + 5497093724143181753U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 37U)) + 10354044773550071706U;
            aOrbiterB = (aWandererD + RotL64(aCross, 27U)) + 12728258851198019099U;
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 4144050505314242618U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererE + RotL64(aScatter, 13U)) + 14133805325480076530U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 23U)) + 308863673210602899U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 46U)) + 11741180130160569753U) + aOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 39U)) + 12926863156769180448U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 211920854786494259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13234608842479411078U;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9164711974854618892U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6667377062281954219U;
            aOrbiterI = RotL64((aOrbiterI * 2603737166987437649U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4559040002406721850U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1749875480850675109U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15822640067349481089U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9555365165561936366U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18289733999504213574U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14156217554673229429U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8727162691639622461U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 291406782452963706U;
            aOrbiterC = RotL64((aOrbiterC * 8413500075082350243U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8294911802626492257U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15853578397277298548U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13256191781365357747U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11535146194939658681U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2177540476748375661U;
            aOrbiterG = RotL64((aOrbiterG * 15791341922007841029U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2705306323728084136U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17617871830709148043U;
            aOrbiterF = RotL64((aOrbiterF * 3449981219502809255U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3699834746313613206U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17952609181629473245U;
            aOrbiterE = RotL64((aOrbiterE * 6103160209028988839U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8016694658897707674U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6971251395823324489U;
            aOrbiterJ = RotL64((aOrbiterJ * 13483776115929040277U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17467528888050817915U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 16451272412693907816U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 13689734638238895071U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 52U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterE) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterH, 6U));
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 28U)) + aOrbiterD) + aNonceWordB);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererK, 26U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Cricket_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8E71AF932E9BB7CFULL + 0xE6C162C8D499A231ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x80E216C4B4F28EC9ULL + 0xAE9362B36BC96D1FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD330F5040650E397ULL + 0x9BD12AED25B9B230ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAC8C25D3F292349BULL + 0xCD23964025F7F4F3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE0529CAFC4053FAFULL + 0xC16CB3F9C8A0E167ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA02B2AD7154C192FULL + 0xE5288DB7B3D82F60ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCE7A86135C006E43ULL + 0xEED764A3F9C0D975ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDB48250CD5931CAFULL + 0xE287990816475F0BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD9FB90FC35309B9DULL + 0xAD0C080AD14326A1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF51692EB83788359ULL + 0xF3966909569C24BFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCF5BBF3173B79A87ULL + 0xF58F5D0003C9439EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x87115E7C61F4DD9DULL + 0xBF3D4E126ED247DCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB376F67668C1A759ULL + 0xCA66FF1DB7C35A66ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF7322D7B9DFBFD93ULL + 0xEC16C967F5123FE6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF336FD4C7E0B5023ULL + 0xF2D2720DD3F8E0A5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9CB8861649FA88F1ULL + 0xC435D0E4019DC52FULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1921U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 1429U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2833U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 7580U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 40U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 47U)) + 2617613537256538553U) + aNonceWordP;
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 16642868916835132715U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 10860291124337073254U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 24U)) + 6432511273906902472U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 37U)) + 7505375005848241910U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 13U)) + 11086616004678821329U) + aNonceWordA;
            aOrbiterD = (aWandererF + RotL64(aCross, 19U)) + 3298830587569881951U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 30U)) + 9775143140064220979U) + aNonceWordO;
            aOrbiterB = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 4147601326580823120U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12245920269898100415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8391940489176734499U;
            aOrbiterI = RotL64((aOrbiterI * 9119606167674098007U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 17876893379544668477U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18301882058180370541U;
            aOrbiterK = RotL64((aOrbiterK * 16680384667098921309U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6869225862715140102U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15404118372589259800U;
            aOrbiterG = RotL64((aOrbiterG * 5766851935950389915U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17757381020518233814U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17677969146092374455U;
            aOrbiterB = RotL64((aOrbiterB * 3469432916562405063U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 15783378556632870114U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5792858258663697864U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 12008981883482080427U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11737803388202260296U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16001927091970715330U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1749586939123286632U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6169421068855905938U;
            aOrbiterD = RotL64((aOrbiterD * 12374789910763348695U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10073586820719728062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17744171227198661555U;
            aOrbiterJ = RotL64((aOrbiterJ * 10658375268803957647U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1149819647337612792U) + aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7725598665625892006U;
            aOrbiterE = RotL64((aOrbiterE * 15097586655234391559U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 52U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aNonceWordC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aNonceWordG) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 40U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13174U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 10458U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12831U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 9766U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 35U)) + 2571116506511057880U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 23U)) + 13112435411509707292U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 29U)) + 10403251762787357256U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 14U)) + 8461951095541400405U) + aNonceWordH;
            aOrbiterI = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 9890793478557463815U) + aNonceWordE;
            aOrbiterH = (aWandererF + RotL64(aIngress, 3U)) + 3030229465991783707U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 7273848154043719247U) + aNonceWordI;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 10681774862516028276U;
            aOrbiterB = (aWandererB + RotL64(aCross, 58U)) + 7105082755586853104U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6588579345319551129U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 14616333550242386092U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2934574715879306337U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15439666290229654921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3360304356760164799U;
            aOrbiterI = RotL64((aOrbiterI * 5164191920584106237U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14438730801970761889U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14515616787452085729U;
            aOrbiterE = RotL64((aOrbiterE * 2041601927968559821U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4167853822635132419U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8950982233003320239U;
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12391327853728029953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7100871010552394421U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16552349374101955967U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 15381697462381887944U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6801677551341079401U;
            aOrbiterC = RotL64((aOrbiterC * 13325954438427340703U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 947011315719204867U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6356920162398333481U;
            aOrbiterA = RotL64((aOrbiterA * 5566721941682667419U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8910262020598577378U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8778455415977526457U;
            aOrbiterH = RotL64((aOrbiterH * 4092470497616637283U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5585696961453127223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9670655481681494412U;
            aOrbiterJ = RotL64((aOrbiterJ * 7863197168965036383U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 56U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterK, 39U));
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterH, 24U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21630U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21797U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16685U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21675U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 22U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 48U)) + 4970414922752555648U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 27U)) + 9462756592787669327U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererK + RotL64(aScatter, 19U)) + 3948790686662213095U;
            aOrbiterH = (aWandererH + RotL64(aCross, 23U)) + 14542857212241578311U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 53U)) + 3387479009827029547U) + aNonceWordO;
            aOrbiterG = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 1411421370057797877U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 42U)) + 16894451466895681236U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 12727136462290223542U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 4625389198191960525U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3471881403786164913U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6433115856048534831U;
            aOrbiterA = RotL64((aOrbiterA * 9363233870194144053U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9825592965466157982U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1553125767261293088U;
            aOrbiterD = RotL64((aOrbiterD * 411535191177308781U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 9951616357109647617U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterH = RotL64((aOrbiterH * 14024961994986659187U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13419663264017317947U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4835055642466215566U;
            aOrbiterF = RotL64((aOrbiterF * 17898065852351759171U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14558747666410946768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13120938960926874504U;
            aOrbiterC = RotL64((aOrbiterC * 5681766019285559739U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11910501376797343986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15074100100781785300U;
            aOrbiterG = RotL64((aOrbiterG * 228976960937473851U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12415377930578091821U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 14882039078390681802U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13855446647753150713U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8094338361713756895U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5478280604704108822U;
            aOrbiterE = RotL64((aOrbiterE * 18062931724700600993U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6977017654546871841U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4131602217285988962U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11865422227883712419U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 10U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 14U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 50U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 34U)) + aOrbiterI) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29821U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30220U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30617U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26103U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 1888427424966603593U) + aNonceWordA;
            aOrbiterC = (aWandererD + RotL64(aScatter, 29U)) + 5436761445660415091U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + 17322876217962143270U) + aNonceWordP;
            aOrbiterI = ((aWandererE + RotL64(aCross, 43U)) + 9728299982740564979U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 301720335271716921U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 39U)) + 8069685428854814396U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + 1973715500949100991U) + aNonceWordO;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 87666408799854155U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 19U)) + 12195436904339035245U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4578742069143400295U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7828776048774876484U;
            aOrbiterF = RotL64((aOrbiterF * 4047964518501081039U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17203146364542781833U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16913369550858890466U;
            aOrbiterH = RotL64((aOrbiterH * 13534417587921978507U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 9632761514552265402U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 9106637671877341286U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 9073709119482640391U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15423680889126750876U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6087310684583331882U;
            aOrbiterG = RotL64((aOrbiterG * 8964465129744898619U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5420955876411796789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14166807419730848032U;
            aOrbiterI = RotL64((aOrbiterI * 442659738632823751U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8118312450347026824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4253043584558403086U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5651748455190536467U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8810774678371762700U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12218479555589447835U;
            aOrbiterJ = RotL64((aOrbiterJ * 11026364205248516355U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11389930523582876358U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16334420553471379915U;
            aOrbiterD = RotL64((aOrbiterD * 13830132212033904777U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 18201289372553710279U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 7196540389657785361U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 13058135202554889791U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterE, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 42U));
            aWandererC = aWandererC + ((RotL64(aCross, 14U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterH, 48U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Cricket_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x943DFC7F15436FBBULL + 0x82F70544C0E89A97ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD2A45D7020202F05ULL + 0x8EE87F0C8D521B74ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x864357882543E72BULL + 0xA283A8D7230FFB07ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC1A3C81E905DA533ULL + 0x846A2EC31B1D3BB3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x89958B1E924904A1ULL + 0xED2610A760E36CEDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBC5C1CAF5B2DAF63ULL + 0xA67DD625CB22E568ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA82A5CB887A9E6DBULL + 0xC31703E971A29DE8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDB87CBFAB6C4C4CBULL + 0x9874892160445108ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x855129938E27C13FULL + 0xFBFC3ABDFD471964ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xED09389917A8623FULL + 0x8063E2EB7D9DE724ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8F8C8C946DC07311ULL + 0xB75AA900EA6758BEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD8351742D3D006E5ULL + 0x8A5D819027EEBF82ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x807CE188799E0C07ULL + 0x84D3C9C00901D02CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC2C38AC3FBFCA35FULL + 0xB367038EB72D86B3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8CCDBAFE59EE39DDULL + 0xC4D9513CAC512FE9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x992ABB388F752EFBULL + 0x9F98BDF3F4C7E4F3ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6946U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4839U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5890U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 2699U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 6318740973868639425U) + aNonceWordF;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 5U)) + 5487840061430920881U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aPrevious, 13U)) + 10258706763248072672U;
            aOrbiterG = ((((aWandererJ + RotL64(aIngress, 56U)) + RotL64(aCarry, 51U)) + 18356875269730338208U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 12883160282903147010U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1010140474942697730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17733939421700898293U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9233534157871885251U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13693055887924981201U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14574732452793385269U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9373765929885750185U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10832873941223609012U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8212600587135328040U;
            aOrbiterG = RotL64((aOrbiterG * 5334613996794796145U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5312744319781971178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6173741211706546923U;
            aOrbiterH = RotL64((aOrbiterH * 12854414066390848249U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3693249147883790810U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 18365859989736602556U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3348463719324104997U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterB, 57U)) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterA);
            aWandererC = aWandererC + (((((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U)) + aNonceWordJ) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 36U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererH = aWandererH + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 42U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordB) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14874U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneD[((aIndex + 13993U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13682U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((aIndex + 9320U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 20U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 51U)) + 12046647397183218524U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 2760779375026461991U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 13735454443176855650U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 4370377000586647724U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 19U)) + 14566322384189969094U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5056565959818422786U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8795403810686579209U;
            aOrbiterI = RotL64((aOrbiterI * 11205867337479457471U), 37U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 9625947666256011567U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1703669290934254701U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5763881345676123583U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6664070663184147951U) + aNonceWordJ;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 2104148316797553431U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 12887842067180975983U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1197910004222596145U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9922977170060903197U;
            aOrbiterA = RotL64((aOrbiterA * 13047828062605568603U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2048376210852567829U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12568990647075931409U;
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterI, 19U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18421U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 20723U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21679U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 17843U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 54U)) + 8367680518550579791U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 43U)) + 11491674725611181241U;
            aOrbiterK = ((((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 16673861720782164214U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 9786610124108350855U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 5745080601557577637U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1959402215131684684U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6121650036079196522U;
            aOrbiterK = RotL64((aOrbiterK * 13375345606276198671U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12016309761037342392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5986936646177049603U;
            aOrbiterB = RotL64((aOrbiterB * 3585650475703294895U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1000367700904043468U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17425288243569101032U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 2174614006719048535U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 4856917474950325209U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16312111093223166419U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 456110002032422270U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11393724374787795662U;
            aOrbiterA = RotL64((aOrbiterA * 1176984359123668389U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterI, 52U));
            aWandererJ = aWandererJ + (((((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 13U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordM);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24722U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25440U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32629U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24680U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 27U)) + 1708250618750199233U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 12009147777553691142U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 27U)) + 8393982703399156592U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 51U)) + 3247327098356831221U) + aOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 35U)) + 3403590155376353737U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18197244558104735044U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3096253642040701606U;
            aOrbiterD = RotL64((aOrbiterD * 6656168712438620783U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8012692688785412179U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 17531946907545680745U) ^ aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16510602981731506381U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17687695944270225817U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 16147773866007628769U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 16926442582711557877U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18244641303026196497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8839160526348897457U;
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10599266240854068246U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 2056723540756216155U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 24U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterH, 48U)) + RotL64(aCarry, 19U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterD, 13U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterE, 37U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Cricket_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9888CC46A898E095ULL + 0xEBE01FFFE86C7A86ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA6EBFC99F6BE5BE7ULL + 0xF2392B240F6D2A43ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE2F81CC37E600981ULL + 0x84A4892382AA7002ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xAC5654BD64F78A79ULL + 0xB99E88B46FD101C1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8F814216A5018851ULL + 0xDD96B97433F1B338ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xAEF34B545461DBF7ULL + 0xF2AA4DF41ACCC435ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBC23EBCAAF545909ULL + 0x9A40C95D7A0D9BDCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96916B8CDB592851ULL + 0xD510991656E87FB8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF993D2CD60444A11ULL + 0x848D1387AC5C8534ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBCEF02F0E0C34FFBULL + 0x87D5C81DE4050A34ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB1005520893D860BULL + 0xFF9FF3905036BB91ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF5B42D4EE606EF75ULL + 0xEA2D09212F36CDA0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x983D9F199ACF00D1ULL + 0xC00B3F6CCD7DEA50ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x818B355DF41FAC83ULL + 0xD1F9D5292509C1AAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDE4CBE7B00FC1FCBULL + 0xAB328CC2C8104BA1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF26037DF0D242F39ULL + 0xABDEC8890191E51AULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4384U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((aIndex + 4966U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7534U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3540U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 41U)) + 17225673071833726819U) + aNonceWordP;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 3U)) + 10301458382103627331U) + aNonceWordM;
            aOrbiterE = (aWandererE + RotL64(aScatter, 21U)) + 3960233050857362414U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 57U)) + 17768665685046605837U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 14471018461213959767U) + aNonceWordE;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 10730597892721340453U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 51U)) + 14863394003122760542U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9948587274816688296U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3573569431435100993U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2303922230056523077U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8153670675740450590U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16438856577722561424U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4689247488336908827U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 15765587867581925041U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4202521649260798876U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15877659681260461141U;
            aOrbiterA = RotL64((aOrbiterA * 11369910758551088173U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 2551560426129646123U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3005102326163906320U;
            aOrbiterI = RotL64((aOrbiterI * 4241583192662435107U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1675501058857208089U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12774812270956702043U;
            aOrbiterJ = RotL64((aOrbiterJ * 5488437008504905105U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1044886020922563597U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4857445127457225171U;
            aOrbiterG = RotL64((aOrbiterG * 13223560654459705259U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererE = aWandererE ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 41U)) + aOrbiterE) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 60U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 35U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11154U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 13900U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14557U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 14947U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aIngress, 48U)) + 11039986441331892533U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 57U)) + 6256024955965426119U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aPrevious, 11U)) + 9857443189988995666U;
            aOrbiterF = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 11900944813380998208U) + aNonceWordB;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 21U)) + 8422577734978875541U) + aNonceWordK;
            aOrbiterJ = ((((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 3100835100713928724U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 11871553509810206993U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17614749493763417027U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3638372131856199916U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 480683274898147025U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6582275259281025770U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17016882418498941958U;
            aOrbiterD = RotL64((aOrbiterD * 4269869255230867823U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1747214688658984715U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9356088987044015278U;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4056238112133473456U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16013150119949532998U;
            aOrbiterI = RotL64((aOrbiterI * 12913648646318115315U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 16076621211111834889U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9940824359571581765U;
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15624084004784515753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7630989544834680335U;
            aOrbiterJ = RotL64((aOrbiterJ * 12261063237156822067U), 41U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 18003586430673313786U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 1654118743290334161U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1153250137357176071U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 6U)) + aOrbiterI) + aNonceWordA);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 14U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordO) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 10U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18972U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 21091U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17942U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 21228U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 37U) + RotL64(aIngress, 4U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 53U)) + 9774364261626083532U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 19U)) + 18059001521926116420U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aIngress, 35U)) + 10615626210406381148U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 10536484278007898620U) + aNonceWordB;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 47U)) + 13320663045139972700U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 17127001787268166583U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 16742574590844166551U) + aNonceWordN;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8347719720758228053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13502468705946051986U;
            aOrbiterI = RotL64((aOrbiterI * 13822952083584784695U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3512687886188904904U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 495660316165795934U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5092722552034477356U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15641128019608284015U;
            aOrbiterH = RotL64((aOrbiterH * 3621036395703527059U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15421873776811085458U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17978775513204574125U;
            aOrbiterC = RotL64((aOrbiterC * 18359600395119440183U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16617179197537669849U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1931805387534012528U;
            aOrbiterK = RotL64((aOrbiterK * 3400139345857733775U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9544923119559308431U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12930999400470173353U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13673733276226249890U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 2032263473309124738U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 3088728329261360607U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 23U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aNonceWordG) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 14U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 34U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + aNonceWordE) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 41U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25359U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 32384U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24969U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 28168U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 35U)) + 5960680319644404115U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aIngress, 13U)) + 16050752633567034185U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 8447503223226854741U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 58U)) + RotL64(aCarry, 51U)) + 14176813813397917591U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 23U)) + 10534915376130006644U) + aNonceWordH;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 6866224454375302514U) + aNonceWordI;
            aOrbiterA = (((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 16506374165041008396U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7167814023968794098U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13870852197416596664U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 17015971222069856463U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18064038854848993105U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9869630811507771691U;
            aOrbiterK = RotL64((aOrbiterK * 13723164383800461387U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 863613100452759380U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16597969741225436529U;
            aOrbiterC = RotL64((aOrbiterC * 2680793528887208903U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6575347108051310653U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17062262265485019063U;
            aOrbiterG = RotL64((aOrbiterG * 7601045488473620019U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7193399224636409133U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14146747818810433849U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5273185769989530041U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 9441449106442431427U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4303295336545399503U;
            aOrbiterD = RotL64((aOrbiterD * 8829695296836242587U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12604760768543193458U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15779327512379787715U;
            aOrbiterA = RotL64((aOrbiterA * 14000905201441272597U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 38U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 12U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + aNonceWordC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordG) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 40U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordJ);
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

void TwistExpander_Cricket_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8F334FB0367CA6ADULL + 0xB4ECBE0CAB185973ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9631FAF67D69E439ULL + 0x8931F31562EBC594ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x836BE220D84A0EF1ULL + 0xFC235DB64F0B267EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8AB2EB5612D584FBULL + 0x820E9DE53EF5147CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF05EEF080C3679B1ULL + 0xB5E61407D168C54FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEB936231FC4EABFDULL + 0xF5264B2706C4BC10ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAC8A51C61AC2EED9ULL + 0x901532105E9F88FFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x85F6F61BAB1838ADULL + 0xDA36ED5D19BB195BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC161113C705B46DDULL + 0xFDD0638C5AF76F5BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA564A49964C50BA9ULL + 0xA3FDDE3D86C7C82CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xED2EECE158BFD36BULL + 0xBEBCF2CCD3C451B6ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF62FB561086A3B65ULL + 0xC98E7CC91992FFC4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD86642FB30765F7FULL + 0xBFD059B2A13CE923ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEB6142F5B22D1341ULL + 0xEF7BFBA8CFE3061DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA8ECFF018FF356CDULL + 0x9B9F917ECD0A15CFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB650E431CFD4783BULL + 0xDE4926B1CB1F0096ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2268U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 3101U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6745U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 365U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCarry, 21U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 12980104182836602177U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 14U)) + 3172622203188863995U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 1170974132219980203U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 6035201940965047490U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 21U)) + 18033907118424996722U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 53U)) + 14604813424800580304U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 27U)) + 13720232492851066035U) + aNonceWordM;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3902659710585257448U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8331560652661619868U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11418103770615560205U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4485014147538689794U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 168202636924512424U;
            aOrbiterE = RotL64((aOrbiterE * 13711020666131492091U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16227825670092707848U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12636865372722601282U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3650053185419807206U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5897288963905408776U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 3706949366974086151U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9922308113622901726U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13352279749091561510U;
            aOrbiterB = RotL64((aOrbiterB * 4025213180483632557U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14969461950939646117U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10231661776135056651U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11284575051455238501U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            aWandererI = aWandererI + (((((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 51U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 22U)) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13956U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8792U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15270U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 14665U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 22U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 21U)) + 337587740689259575U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 4927686903263973950U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 3742409032569801033U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 27U)) + 1608092659172197650U) + aNonceWordA;
            aOrbiterF = ((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 15848744267145717509U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 53U)) + 15300174177963339253U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14162868453323648628U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12020167069983729869U;
            aOrbiterC = RotL64((aOrbiterC * 2071080217680099017U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16259538291658723956U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8516686212464112245U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4731296903548893627U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3722184575520553132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5663609293306386784U;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15265344442454471986U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3050323350098829515U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 5890624677162388135U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 1093356813820599238U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15170797965325981472U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17826286701992981628U;
            aOrbiterF = RotL64((aOrbiterF * 11186808881726573677U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14710892030473425181U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterG = RotL64((aOrbiterG * 14368930300818752833U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 27U));
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterJ, 58U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 28U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24107U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 21837U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23997U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((aIndex + 23421U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aPrevious, 6U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererE + RotL64(aCross, 20U)) + RotL64(aCarry, 51U)) + 2974056819475622600U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 7345051759236356098U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 43U)) + 12738468816846628882U;
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 7694520596043297922U) + aOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 5530753590015084774U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + 3776309161718383105U) + aNonceWordA;
            aOrbiterI = ((aWandererA + RotL64(aCross, 37U)) + 784780304358106404U) + aNonceWordP;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8999942326995036509U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5194986506064092779U;
            aOrbiterC = RotL64((aOrbiterC * 15070787038006135963U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7920040007459652762U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11311997270710107937U;
            aOrbiterH = RotL64((aOrbiterH * 6227571709361790209U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5365231114813547251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8630110234623825263U;
            aOrbiterA = RotL64((aOrbiterA * 2735881715888325759U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2358235238039571072U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 18059414891616491807U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14526050556461782864U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6937282036603272474U;
            aOrbiterB = RotL64((aOrbiterB * 14954512365270028029U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10105832250694931310U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3884223553012098137U;
            aOrbiterF = RotL64((aOrbiterF * 16340956813003906195U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10385284339549648087U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1257633893341505930U;
            aOrbiterI = RotL64((aOrbiterI * 2669950791270500977U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 4U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 35U)) + aNonceWordD);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aNonceWordJ) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 41U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 54U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32257U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((aIndex + 24986U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29994U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24594U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 29U)) + 10726035965553989335U) + aNonceWordM;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 27U)) + 967354339530195662U) + aNonceWordP;
            aOrbiterH = (aWandererB + RotL64(aScatter, 21U)) + 10834593005478605624U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 1012888282838656933U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 41U)) + 15283530351725183253U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 53U)) + 11724495956731703750U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 4288330117317505776U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10894778070022873473U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15563886747621617467U;
            aOrbiterH = RotL64((aOrbiterH * 17884709931569040065U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11182488628562891937U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10420140066310588580U;
            aOrbiterF = RotL64((aOrbiterF * 13898299782819948719U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11775138062167543111U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16545391898578161683U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 14588306527161321535U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1550144656312299266U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 14903504853138279883U;
            aOrbiterJ = RotL64((aOrbiterJ * 8003033561266164387U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 309935535526750396U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13991265868040011411U;
            aOrbiterB = RotL64((aOrbiterB * 2887531132228588441U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1755976294857114222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2259275858478396846U;
            aOrbiterK = RotL64((aOrbiterK * 7416165760067878161U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4838175912944552936U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12307900457200936013U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14719363144850838805U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 58U);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 26U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererB = aWandererB + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordJ) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterJ, 37U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_Cricket_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC9480C2E9CDC6637ULL + 0xAA0F1EB8FADBB386ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA4E704B675C70019ULL + 0x891940FFC44BDEACULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xEA2E76D4237D2647ULL + 0x95F2B4C494A5BB3FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9C7872A988A0F4D5ULL + 0x9F4DE4F53F646029ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xEBA7CE4EC05E8409ULL + 0xF7D9C9C9053F8FD7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF2376A761CC32B25ULL + 0xBC0BC4E56684FE78ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD27DCC68C8347F35ULL + 0x9B545E5B3DA5213DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB9F897AEF7D37E9FULL + 0x81697B8459E11456ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCDF15521EAE6C7AFULL + 0xA2A424708917B509ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAF80D5F69C2D0AD1ULL + 0xF33C886B595626B2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA71277D0ECBA0E7BULL + 0xE04926927D183B2DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8EE02C17CD1D5919ULL + 0x99E97B1AAB644B87ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC16F15BC2F8FF78DULL + 0xC85DC712163F2155ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xC7D7349A79F07563ULL + 0xB5DFB54002CA9246ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC03F2CB10ADD1BD9ULL + 0x94FB749E1B4212B9ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x95D5ABA76343AB45ULL + 0xFAA4BF5D18AF2BD1ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3942U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 4243U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1754U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6775U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCross, 26U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 53U)) + 12615321415808640429U) + aNonceWordK;
            aOrbiterI = (aWandererA + RotL64(aCross, 37U)) + 15712784676459931207U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 51U)) + 11013335427004930046U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 11U)) + 8298733856304768806U) + aNonceWordJ;
            aOrbiterA = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 6207732959150824216U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 24U)) + RotL64(aCarry, 37U)) + 9769864876127544038U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 43U)) + 10782181918651152563U) + aNonceWordA;
            aOrbiterD = (aWandererC + RotL64(aScatter, 35U)) + 5790454015845620939U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 21U)) + 15606578025386733803U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 53U)) + 5522352539991175304U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aScatter, 39U)) + 5993355818572869649U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10864534396947622047U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12090053126235913528U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7250801471645972261U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14191181677234981396U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2258570108233924592U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8307541155393855209U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8448114811381534603U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2702389315763499817U;
            aOrbiterJ = RotL64((aOrbiterJ * 6710443836432274393U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17202184076718780200U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 150549910056015002U;
            aOrbiterB = RotL64((aOrbiterB * 195034681254956335U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4910512055808124967U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4783477997418403079U;
            aOrbiterH = RotL64((aOrbiterH * 861977492146512865U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13842899106208709771U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7930112618036681468U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 8609551859830858419U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8790107242863198659U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6882768826643279144U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13745521454063360763U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12136498871759890015U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8120456314755584336U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 1830725195528043575U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14425711740351183016U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15907406009196323049U;
            aOrbiterA = RotL64((aOrbiterA * 8599371693260686839U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4878521420367891861U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1184672056055028939U;
            aOrbiterD = RotL64((aOrbiterD * 5963961755367831967U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10126736568567000180U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12615321415808640429U;
            aOrbiterK = RotL64((aOrbiterK * 11663715449073755137U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 22U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 56U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 28U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterD, 21U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14669U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 10035U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15111U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8606U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 43U)) + 16200278595895089008U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 27U)) + 1029614154810465897U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 12U)) + RotL64(aCarry, 21U)) + 7129562468705441295U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 51U)) + 14388903902433951274U;
            aOrbiterH = (aWandererK + RotL64(aCross, 41U)) + 1013568949315967455U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 53U)) + 3128823373497815651U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 13U)) + 14525694606889470589U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 14443983602196782887U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 12244220415328641190U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 35U)) + 10477159225338766614U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 57U)) + 2842870123078131566U) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8621138818955849917U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5038396344400303181U;
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2768613802894372496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2027754864051410015U;
            aOrbiterC = RotL64((aOrbiterC * 2461322540050569287U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2848088309172056399U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15017458513904884651U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9926904679902843055U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9079797279596336139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15424866642305110811U;
            aOrbiterK = RotL64((aOrbiterK * 12912331089970158845U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13751764050290602740U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7694557131324740282U;
            aOrbiterD = RotL64((aOrbiterD * 14980807690491467023U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3508673897305667669U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3600868397311393233U;
            aOrbiterJ = RotL64((aOrbiterJ * 5165032044164139165U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1222655844979128996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2257342337168905875U;
            aOrbiterF = RotL64((aOrbiterF * 6198995971182272119U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6290990717563682725U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15308494772443447109U;
            aOrbiterB = RotL64((aOrbiterB * 1925593111157842325U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4065385272074155855U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17216369169581934516U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16172589962950781777U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15683161334290612079U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4197626901960576264U;
            aOrbiterI = RotL64((aOrbiterI * 2822547214684481747U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4400047838649306704U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16200278595895089008U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6603195071605635697U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 37U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterK, 4U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterE, 60U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 24U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20345U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 21081U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19749U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20527U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aScatter, 27U)) + 3970829908171131502U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 7040283759419531991U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 42U)) + RotL64(aCarry, 43U)) + 11856292169397052901U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 47U)) + 819598588791819022U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 57U)) + 2176451710970866848U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 51U)) + 6454704928613390494U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 11792122387218053841U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 22U)) + 9254780213489752211U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 3U)) + 16591812589999846482U) + aNonceWordI;
            aOrbiterA = (aWandererE + RotL64(aScatter, 37U)) + 1471246223935074832U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 39U)) + 1424843083106386453U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1856469958050891629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6331743690452052712U;
            aOrbiterB = RotL64((aOrbiterB * 15327924647897459645U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10351075711345476487U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9518585245330480185U;
            aOrbiterI = RotL64((aOrbiterI * 3792179827396760391U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17787514620244712033U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14182328067398162557U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18107337388659070197U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12798088948801072444U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9563215159275202323U;
            aOrbiterH = RotL64((aOrbiterH * 7058145016617349141U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9904919772580498232U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16579777394992143043U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10516761340320196661U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6344049286854588503U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3531503618941046788U;
            aOrbiterA = RotL64((aOrbiterA * 10855385899703024105U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11334308840132700377U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11093833870078787770U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16105889714648555755U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3831491136025364271U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12505259454860591372U;
            aOrbiterF = RotL64((aOrbiterF * 6135450888433504093U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2210290810330253363U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10786160915224323113U;
            aOrbiterJ = RotL64((aOrbiterJ * 799075068398619501U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 7791474921127653867U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1046454625851499863U;
            aOrbiterE = RotL64((aOrbiterE * 18040454167287729591U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14636813124839719351U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3970829908171131502U;
            aOrbiterD = RotL64((aOrbiterD * 2737568880005765517U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + aOrbiterF) + RotL64(aOrbiterH, 38U));
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG + (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + (((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterI, 36U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 25995U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29520U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29755U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31884U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 3U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 21U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 1210605127156905516U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 13U)) + 11964595428173569519U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 22U)) + 16277319029916258482U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 12369497463101824572U;
            aOrbiterH = (aWandererG + RotL64(aCross, 41U)) + 6201248574067068202U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 39U)) + 1727477025667206661U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 51U)) + 1404510627789806851U) + aNonceWordD;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 26U)) + 6948213591282018925U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 6688865181284421478U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 37U)) + 3351130769402360855U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 12681032488906270823U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3591412591193726763U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16153817571210878589U;
            aOrbiterE = RotL64((aOrbiterE * 4165137036092246349U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3808228354421006630U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1427373776207504205U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 4534374093769595531U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1831554180932501132U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1114853085120949215U;
            aOrbiterC = RotL64((aOrbiterC * 4264176108298812905U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2080935638828366835U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16104777999646489828U;
            aOrbiterJ = RotL64((aOrbiterJ * 15205199362011777473U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9782806013673440791U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3721620299829386454U;
            aOrbiterD = RotL64((aOrbiterD * 6286765834910272409U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4013706412064296527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5751022780695158579U;
            aOrbiterK = RotL64((aOrbiterK * 13766736471646116397U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17684546333240329338U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1106947111128020920U;
            aOrbiterA = RotL64((aOrbiterA * 3158839453318658951U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11564229705849500598U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1585817314460274286U;
            aOrbiterG = RotL64((aOrbiterG * 12687162159791577431U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13549147977354138518U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5148731385622182707U;
            aOrbiterB = RotL64((aOrbiterB * 11016443961557395981U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17048442399822433365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13772472534194030098U;
            aOrbiterF = RotL64((aOrbiterF * 13155895389652826889U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9982971300679888388U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1210605127156905516U;
            aOrbiterI = RotL64((aOrbiterI * 9183351854400012949U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 43U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 10U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 22U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterH, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + RotL64(aCarry, 51U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Cricket_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDC8527AAA936552DULL + 0xC245C6A9289AE6ECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFAD5CA4494152E9DULL + 0x990E6767989ACD7CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE338A9DA0763F617ULL + 0xDCA3349B858F9F1FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE18ECD5E3FBEB655ULL + 0x900D421CCE0E1E91ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF9FD0CE885CC4F75ULL + 0xD21F0FAC5B3A9E1AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x94F56D2108E46979ULL + 0xF4D9ABAE8F41DE1DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAB785570925C63F9ULL + 0xFC3EB68C6F71FAACULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBFB599C606D1F9F1ULL + 0x828D93989377CFC9ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF0AE88A48D386AF9ULL + 0xC852BDCCFC4CF083ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCD480231CB94AAFBULL + 0x84A12291E0D1400AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF96C42562EBFD865ULL + 0x990DBE09108A2361ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAD15A6DDCA923B13ULL + 0xD75000F58C896AD0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8236649254F63B5DULL + 0x866A65979BE022E1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x896AAE092922F047ULL + 0xDBC6973A1FE7D524ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x97717E918006D28BULL + 0xD07F8371034B63C8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE949E8DC974D4619ULL + 0xE9AD93FEB032596FULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1655U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5378U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3156U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3090U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 13U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 56U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 19U)) + 8020711767807230555U) + aNonceWordC;
            aOrbiterC = (aWandererC + RotL64(aScatter, 60U)) + 15368693777246341570U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 5117523734225562401U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 13155269151097507808U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 23U)) + 9879303753623578272U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 1165799257173794826U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 11U)) + 930641942062732091U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 34U)) + 11330571332221123153U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 3U)) + 2862963158282518899U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6019186399361476659U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1924419843785161958U;
            aOrbiterD = RotL64((aOrbiterD * 9485557122500346869U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12618629043591380461U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9334176504266512405U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18239109235362925739U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16829692481030013551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5604784396927022709U;
            aOrbiterF = RotL64((aOrbiterF * 2833893610883508353U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16124030106598549644U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16571659812830230677U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4668250364992383549U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15171089673591843703U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2826755560293849328U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397017963457655287U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9976785768283589291U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11845100564714691809U;
            aOrbiterE = RotL64((aOrbiterE * 4935139932585319251U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7318560453127859950U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3039196878830506712U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 3140508261330698717U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8850992055588337843U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4219373528176869146U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1310964742529956743U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1341474458715938799U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 15937557372891732898U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 11437307017920192915U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 4U) + RotL64(aOrbiterG, 18U)) + aOrbiterA) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6591U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5843U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9288U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8223U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 22U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 3U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 51U)) + 13960289014350612206U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 11U)) + 3483331015269589730U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 6873299241002444518U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 3U)) + 3562094007125534229U) + aNonceWordJ;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 23U)) + 11422367439932782705U) + aOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 532453428514259816U) + aNonceWordE;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 56U)) + 17810941465810193088U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 29U)) + 11869759058631106331U;
            aOrbiterA = (aWandererA + RotL64(aCross, 47U)) + 8837581071876177566U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17185378327053837778U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7578253375676981500U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13371647568758721729U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17112646434432814442U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14949096407295697881U;
            aOrbiterI = RotL64((aOrbiterI * 14770977858283051753U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4259590620758467836U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6534899413644542303U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7987609419215568661U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2637407498893694243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15819295597921425711U;
            aOrbiterH = RotL64((aOrbiterH * 5202015597375051399U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 6373559542002699718U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11694562937392022505U;
            aOrbiterA = RotL64((aOrbiterA * 9311557972331218597U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3308736483775453062U) + aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12749929710650475901U;
            aOrbiterD = RotL64((aOrbiterD * 248428400724560945U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1569528215675579656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1044077933631689572U;
            aOrbiterB = RotL64((aOrbiterB * 6443796233912755143U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8393422728124537471U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2002732612516530754U;
            aOrbiterC = RotL64((aOrbiterC * 13702146823622364279U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13469191942843147943U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7633171368709520560U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9713514012478203047U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 52U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aIngress, 36U) + aOrbiterA) + RotL64(aOrbiterE, 60U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterB) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterH, 12U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 10U) + RotL64(aOrbiterI, 39U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12768U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 15440U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12467U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12348U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 41U)) + 5295352595333316211U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 2341795367042042605U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 34U)) + 10122175780504033663U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 10084612804696198554U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 16470424309851045971U) + aNonceWordB;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 11U)) + 656016130975227994U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 53U)) + 15313268829659834317U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 18U)) + 3795220914993923394U) + aOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 14044442220988813825U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3804224626734584802U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7980006306010255693U;
            aOrbiterC = RotL64((aOrbiterC * 13958505239726088561U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13746830564584711549U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11852212099729274845U;
            aOrbiterB = RotL64((aOrbiterB * 2164880979318247855U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9083223471018084847U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13706723820703853346U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11361854103656219887U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1713819986642275223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1382000168233902914U;
            aOrbiterJ = RotL64((aOrbiterJ * 3894160765130198157U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4540474625764565485U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1756168174375757220U;
            aOrbiterE = RotL64((aOrbiterE * 12739160208010092017U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1409297070183609309U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6082750101445444357U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17438740230251860935U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1113239890859479202U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10932192439503964363U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 5915660289913324281U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3732595033748508428U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5117760372351117286U;
            aOrbiterF = RotL64((aOrbiterF * 2671510075176315761U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7399968659654088641U) + aNonceWordL;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 14835608167871904147U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 8312521710415756159U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 20U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterF, 19U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 20U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 58U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 46U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16435U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 17684U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18740U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18198U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 52U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 14008824488073394623U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 13317978415866411468U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + 13209180141897453900U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 11870521586865233578U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + 8052156380448047385U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aPrevious, 57U)) + 12158131176743680605U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 35U)) + 14674467487607719347U) + aNonceWordP;
            aOrbiterF = (aWandererG + RotL64(aCross, 29U)) + 18055496790566231147U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 14U)) + 3838105585041578784U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 2839568255183054418U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11933612922864258179U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7571964469321160347U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6289849094151630580U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2640344350528492271U;
            aOrbiterJ = RotL64((aOrbiterJ * 16197726750829369365U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16306175266267657791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3339898380394883600U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15017076663742800002U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8973064296077602496U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9309462227233615761U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17580319233338139859U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14063208878807603874U;
            aOrbiterB = RotL64((aOrbiterB * 16601475239075164585U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13326130855721009942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12843186026737544416U;
            aOrbiterC = RotL64((aOrbiterC * 4975848122837321619U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14102887715772847499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14495942314329085733U;
            aOrbiterF = RotL64((aOrbiterF * 4236795312917583565U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11564857125101669667U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17435970784822000464U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1472691848852381173U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16561390130356833062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9952805588514363872U;
            aOrbiterI = RotL64((aOrbiterI * 3720874990001086597U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 58U)) + aOrbiterJ);
            aWandererD = aWandererD + (((((RotL64(aScatter, 36U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 23U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterF, 46U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23520U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 27099U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24926U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 26782U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aIngress, 34U)) + 9133751643283278896U) + aNonceWordN;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 3U)) + 8971581804375380408U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 47U)) + 12559650383714566592U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 15753206088872859163U;
            aOrbiterD = (((aWandererA + RotL64(aScatter, 19U)) + 7640756270450762350U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 23U)) + 7340073357551376125U;
            aOrbiterF = (aWandererB + RotL64(aCross, 58U)) + 5270256573644196046U;
            aOrbiterC = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 3567367996479995928U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 11939634537492733738U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7051817732424527120U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 1730487669951837941U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 15191634337956285841U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18009252467909454817U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2361024272031696442U;
            aOrbiterG = RotL64((aOrbiterG * 15215151562500226027U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15902755877642960397U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12243517544704116184U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2576071074148141447U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16846181962302186187U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 636121425116506681U;
            aOrbiterA = RotL64((aOrbiterA * 17075030673338779993U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 6887385655828217318U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3705834550934775862U;
            aOrbiterH = RotL64((aOrbiterH * 11275428284929594435U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11165142437077969438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6426659930331618269U;
            aOrbiterB = RotL64((aOrbiterB * 17170640810530893705U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12629082390899315789U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4277510580069574724U;
            aOrbiterF = RotL64((aOrbiterF * 9829125163412708305U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13814834144170469978U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3698381854100295826U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126359230872258015U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11623170635983579937U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7247413650388803796U;
            aOrbiterD = RotL64((aOrbiterD * 3403219499465560059U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 48U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterC, 19U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 44U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterF, 53U));
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29727U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 30689U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31025U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 31887U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererI + RotL64(aCross, 27U)) + 11998579547770778580U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + 8409465187298704610U) + aNonceWordO;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 18U)) + RotL64(aCarry, 35U)) + 3470222286110333500U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 43U)) + 5704486785203069994U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 39U)) + 10334944660253279633U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 23U)) + 7626852700722567477U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererD + RotL64(aCross, 12U)) + 14631310754943209743U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 807160297237854120U) + aNonceWordE;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 53U)) + 5624154783624196107U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4971444394698940423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6340057638461027062U;
            aOrbiterJ = RotL64((aOrbiterJ * 12027586111086798629U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9003019862787819481U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13632057463595873033U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12575202147280216765U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 12766104026871797746U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4062118445824915939U;
            aOrbiterB = RotL64((aOrbiterB * 13130770039048080701U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5258212525426469978U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9956946981015983939U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 8106382657040497669U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10837606223056473999U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13292864885504191134U;
            aOrbiterI = RotL64((aOrbiterI * 4445739587553669471U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 166087925900318658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6786842221885441388U;
            aOrbiterC = RotL64((aOrbiterC * 4411147600413147773U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16888086378070246404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5240855484445974002U;
            aOrbiterD = RotL64((aOrbiterD * 402652898573422271U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6874866669211571608U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 732890824978127460U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 3776365957702257453U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5541380495707308058U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17947326584411475765U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10920952349981652899U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 38U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterG, 29U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 22U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + aNonceWordP) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aIngress, 48U) + RotL64(aOrbiterF, 58U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 11U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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

void TwistExpander_Cricket_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC74FB95CF38CB0ABULL + 0x963D2124F25186FEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x98F00F9B269E264DULL + 0xABF06AFF3E1F93AFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE7B89498D0F44E15ULL + 0xA937E759FF069392ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF343888D5F73F851ULL + 0xFD6FBA8668CF81C5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBF544D95C0CEF4F9ULL + 0xA53E0F44D83F5DF9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xED8E12C21736A839ULL + 0xBF3E798DFF9A6D3BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8FC70F09AB381719ULL + 0xFA9973F60D7B67CEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x94CCCEDDA34BB883ULL + 0xC53A5809442E2C58ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDA5E28541F81659DULL + 0xA8311FF11710ED59ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBD8FA8BD3C6142C7ULL + 0xB3F32114B996CDC5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF872D820DB816DD5ULL + 0x9E39D3A2A6045A66ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB5B80205E8B21797ULL + 0x9F9A55F3620FD7CFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB48C67E7A3963C85ULL + 0x921005F15D6200EAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD12DD4F0AB1DFB09ULL + 0xE26CF434C22925C8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9076C4E5523D7707ULL + 0xD37153C2E55C0FA7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x90CD03754DA8152FULL + 0x9C904DBB9DAB8ECFULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 100U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 449U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3132U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2600U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 58U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 3U)) + 7893287783892523139U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 10257331997383491153U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 47U)) + 14562226733652231753U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 14320342577110737851U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 58U)) + 9816717579822880756U) + aNonceWordB;
            aOrbiterH = (aWandererH + RotL64(aIngress, 29U)) + 9558926960095881953U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 35U)) + 9230371862654338324U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6414274291252913420U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13868546184398350849U;
            aOrbiterF = RotL64((aOrbiterF * 1547986864837497409U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16940736952569949038U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2866957764814864371U;
            aOrbiterC = RotL64((aOrbiterC * 3554702178644797003U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 7916721976073979724U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1602444214978842275U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11072503711308122385U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9529061385251008037U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8402775110887376588U;
            aOrbiterI = RotL64((aOrbiterI * 13980225144628227381U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15003592180290390713U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14195681406520825751U;
            aOrbiterA = RotL64((aOrbiterA * 11455000833788877217U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3263577002367714202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12019422062655581928U;
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8508638054582582917U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 6536618106353552880U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6233964121117511885U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 56U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + aPhaseAWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 60U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8388U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 10840U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8365U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 7425U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 50U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aScatter, 19U)) + 3550722402315312207U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 16724184551669522754U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 51U)) + 981751330116773021U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 5U)) + 7891159229704944868U) + aNonceWordP;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 37U)) + 13618396711464799841U;
            aOrbiterK = ((((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 57U)) + 5969291018449003648U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordN;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 14595540413313640042U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3287990436916111762U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12534369400200483704U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2345945228434740707U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2277312067930392274U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10026320559261334353U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11020464940995912637U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 11258082063135659551U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1445958517675746990U;
            aOrbiterC = RotL64((aOrbiterC * 10062265337488757971U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1011298251290970844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6487834862470043744U;
            aOrbiterJ = RotL64((aOrbiterJ * 15477913837027179675U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9966279022928268335U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 10285993486057704393U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15965714363201157535U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16005362468813966136U) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 223843444699390781U;
            aOrbiterK = RotL64((aOrbiterK * 665392038954573081U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18178876294968532775U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12490136112181806806U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 16380841616662993709U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 47U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aPhaseAWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterB, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16330U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11762U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13684U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 15131U)) & W_KEY1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 51U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 35U)) + 16651241552253078315U) + aNonceWordH;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 4558144676982478003U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 29U)) + 8814884320080367550U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 37U)) + 16011579668555672117U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 23U)) + 4738918668759862438U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + 12526083125540985108U) + aNonceWordN;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 8048723561746000552U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1082218464034639039U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 8432043246965946816U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 7801965585991025451U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9982080524048636852U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6720069955755215919U;
            aOrbiterG = RotL64((aOrbiterG * 1025046364205332059U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1019035028070247757U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7360619079463870467U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6623074813047915863U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10893918488381348474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1390297670907738019U;
            aOrbiterF = RotL64((aOrbiterF * 11909657437658597735U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12512200589031203480U) + aNonceWordG;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14741471280748399540U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3012135242889901095U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8543897248359826770U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8545972622733791272U;
            aOrbiterK = RotL64((aOrbiterK * 11793879362775346821U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7049384618581928664U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14730773807906925408U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10711566871536755073U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererD = aWandererD + ((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterI, 60U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterI) + aPhaseAWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordE;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17466U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19435U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21812U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20204U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 50U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aIngress, 29U)) + 8866844335448071821U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 5U)) + 15159698739856430085U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 43U)) + 9582805772989594633U) + aPhaseAOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 1438538239931588373U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 10862044156620436139U) + aNonceWordC;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 12U)) + RotL64(aCarry, 11U)) + 13682173320058164615U;
            aOrbiterC = (aWandererI + RotL64(aCross, 35U)) + 8351013291045977592U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15777857431516633916U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 16178966745333885377U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 7545129923202147703U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9031889187993001617U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6308472367425865347U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17118710301967158153U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 642109145903321046U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 9186268569255318035U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 10714674348507516749U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6091345356803675860U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13218507921880873749U;
            aOrbiterH = RotL64((aOrbiterH * 15415157927185637717U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4266652275234474616U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4391422098164506195U;
            aOrbiterA = RotL64((aOrbiterA * 17634679403195085867U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5160682323243635577U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 10351728852161347404U;
            aOrbiterJ = RotL64((aOrbiterJ * 11105410036471745951U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3950932176454814023U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9536466386833427441U;
            aOrbiterC = RotL64((aOrbiterC * 18064984243491293435U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterK) + aNonceWordK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 58U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + aNonceWordE) + aPhaseAWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 14U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22067U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 22449U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26401U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 22400U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 4U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 23U)) + 9774364261626083532U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 18059001521926116420U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 10615626210406381148U) + aPhaseAOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 10536484278007898620U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 47U)) + 13320663045139972700U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 60U)) + 17127001787268166583U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 3U)) + 16742574590844166551U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 8347719720758228053U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13502468705946051986U;
            aOrbiterE = RotL64((aOrbiterE * 13822952083584784695U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3512687886188904904U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 495660316165795934U;
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5092722552034477356U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15641128019608284015U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3621036395703527059U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15421873776811085458U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17978775513204574125U;
            aOrbiterI = RotL64((aOrbiterI * 18359600395119440183U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 16617179197537669849U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 1931805387534012528U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3400139345857733775U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9544923119559308431U) + aNonceWordH;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 12930999400470173353U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 16791006919271490005U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13673733276226249890U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2032263473309124738U;
            aOrbiterA = RotL64((aOrbiterA * 3088728329261360607U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aCross, 54U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aNonceWordN);
            aWandererD = aWandererD + (((((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 53U)) + aNonceWordI) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 60U)) + aOrbiterE) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27684U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 30463U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31689U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31610U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 6U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 3U)) + 16189787374324972735U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererD + RotL64(aCross, 19U)) + 17563763730956242224U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 27U)) + 10572803498593789385U) + aNonceWordB;
            aOrbiterH = (aWandererG + RotL64(aScatter, 50U)) + 7713105232072974166U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 10760839534772718139U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 13397069448391230253U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 4569255679998375682U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 9888769350817876949U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11351796060878856300U;
            aOrbiterJ = RotL64((aOrbiterJ * 13356749147334008399U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18153775071965707204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1282846411145853435U;
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16457743979262460660U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3927345926316409630U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5158769729850853623U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2446452358663812945U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 12331351600010165154U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3940794200348684050U;
            aOrbiterE = RotL64((aOrbiterE * 13248997263062075043U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11248514843822945425U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1391497323278226522U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8376841806072565005U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13265623528678787307U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2802033745265647317U;
            aOrbiterK = RotL64((aOrbiterK * 3437626962562016147U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 19U)) + aOrbiterI) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 34U)) + aOrbiterH) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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

void TwistExpander_Cricket_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x93C5C64AA2557A59ULL + 0x85D62C0776231A93ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA182E12F0356DDC9ULL + 0xED590A02054D3F81ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD058E4F42E0ADC41ULL + 0x8F5AEBD7170D384DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF7FB5FF4D973EC07ULL + 0x8C7E9F229D22C551ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBE4A5F57E0353B89ULL + 0xCF07628A1CD89842ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF66C67E6BBEFE377ULL + 0x83BA2AEF7B9A6079ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE41EDCB3BA35071DULL + 0xE86BC598BEB730A4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF830D2369ED46233ULL + 0xDFF60837985BFAC1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFE64FFC4D546F5D1ULL + 0xC7B2C58375AE1609ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCA4D64C99EAB9231ULL + 0xAEA09351553DCAD9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8CCD9600F24A3609ULL + 0xFCF61E2FE907349EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD2D16131C8AF7723ULL + 0xE7F50F8BBA32E73BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9A6894B84D2CA11BULL + 0x9F1509AD36B1D16CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD2CDD6A8086AA24FULL + 0xD5E3D5373ED2FC94ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFC598E737F133BF1ULL + 0xAB5A36DF4FE82BA5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBDCFA96C51478239ULL + 0x9163500F40426A52ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5302U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 1341U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4615U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 4098U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 38U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 19U)) + 5573188770530340913U) + aNonceWordG;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 1431772230889897111U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 48U)) + 4809192776429682319U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 5576603692574369341U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 2720143226007220386U) + aPhaseBOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17220328778565331629U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9629485808442089423U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18349580416082045015U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1136998437010390983U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 11893390497814523841U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 5329621622743089531U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1764986431917532370U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1741014798007010376U;
            aOrbiterH = RotL64((aOrbiterH * 13414914086049500731U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12221368453236547044U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7694538641172350430U;
            aOrbiterI = RotL64((aOrbiterI * 8439120733670016501U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17472344518811560603U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3308740700728172984U;
            aOrbiterA = RotL64((aOrbiterA * 15290400462887712083U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + aNonceWordP) + aPhaseBWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterA, 26U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 43U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5894U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 5530U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8369U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10613U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 51U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 12380376990224645149U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 18296928500297384014U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + 3550626816361145100U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 2667792936946706027U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 38U)) + 12020969779370926953U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 737340727886903447U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1681797651799760502U;
            aOrbiterF = RotL64((aOrbiterF * 11923920414802777451U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2956186342689489064U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1876852870402977177U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8875540081346621757U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 6433205819353555071U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9065076854974222998U;
            aOrbiterA = RotL64((aOrbiterA * 5459675878087242021U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3254410578766789992U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2005081975473815576U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9947701153722014085U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 15992999234834560419U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3458344156815120948U;
            aOrbiterJ = RotL64((aOrbiterJ * 1668460113964608051U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 48U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 58U)) + aOrbiterD) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13030U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 11449U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13834U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11321U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 19U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 37U)) + 15910560457440369082U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 17953072986407436888U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 15446940721193538669U;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 3020785262774422009U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aCross, 20U)) + 7001288645424994404U) + aPhaseBOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 13385250665458462689U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 4841895644623005949U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3898487345974386945U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13053476783239482065U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 641996979335975244U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3697673197256549833U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16211238020928688299U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12715448751323279480U;
            aOrbiterC = RotL64((aOrbiterC * 2116880429675303291U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17784406727699995290U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16626339815786580778U;
            aOrbiterB = RotL64((aOrbiterB * 13940754474750138041U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9035070625716345139U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6085848172494001945U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10405728912339646693U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 28U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20255U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 20775U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18018U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((aIndex + 20433U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 10U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 7790166497945719700U) + aPhaseBOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 40U)) + 7136208896846119188U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 12123156943355100886U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 11U)) + 5095546037880875199U) + aNonceWordB;
            aOrbiterA = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 17642705393916765992U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9918479837334416990U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 4890009823843176466U;
            aOrbiterJ = RotL64((aOrbiterJ * 16898633181256061239U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17652590786213674124U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 870002527644696135U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 915408393979165539U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterJ) + 12545429703552643682U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 5310272867406182581U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 10420003334833925011U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3264719049050179440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1967241238180278937U;
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 773883832927040736U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12766817190261232485U;
            aOrbiterA = RotL64((aOrbiterA * 7448864556802318431U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 48U)) + aOrbiterA) + aNonceWordE) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 26689U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22672U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26268U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22182U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 17711946802293254150U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 54U)) + 16652362590489569378U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (((aWandererD + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 6972810344198183097U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 13117100889782940546U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 27U)) + 13199305696782626591U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 992156184392760945U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13791265442074543880U;
            aOrbiterI = RotL64((aOrbiterI * 1263919538622722673U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17057087245252294859U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 13444195995883541046U;
            aOrbiterJ = RotL64((aOrbiterJ * 13067044288608808777U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6723678233676059420U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7913379431208430475U;
            aOrbiterC = RotL64((aOrbiterC * 2295062944289127123U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4481887195529300665U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11892724101424384078U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3468639499716604111U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7700902083270424194U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1888001433557140271U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8975562955027025349U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aCross, 10U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + aNonceWordN) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 6U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 37U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30050U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27364U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32565U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 28574U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 40U)) + 3970829908171131502U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 21U)) + 7040283759419531991U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 11856292169397052901U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 819598588791819022U) + aNonceWordO;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 2176451710970866848U) + aPhaseBOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6454704928613390494U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11792122387218053841U;
            aOrbiterI = RotL64((aOrbiterI * 17994898985794518565U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9254780213489752211U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16591812589999846482U;
            aOrbiterF = RotL64((aOrbiterF * 5425771603523423167U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1471246223935074832U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1424843083106386453U;
            aOrbiterG = RotL64((aOrbiterG * 15020536982657410783U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 1856469958050891629U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6331743690452052712U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15327924647897459645U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10351075711345476487U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 9518585245330480185U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3792179827396760391U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 22U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 58U)) + aOrbiterF) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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

void TwistExpander_Cricket_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCD3CD13A02043B21ULL + 0x9271FC8E32EDE146ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA53FF1242D7F4499ULL + 0xC2B4609731C009C6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB944A244990207B5ULL + 0xAF91B914C143B177ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD523A0B44A8BBF0DULL + 0xDD19DF04E8C51F10ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFC82B53C1214FAC3ULL + 0x8CE093A16A9AAF5EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB327A1F98CD8CAF1ULL + 0xBE6221B17F295F09ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x87307898ADDA8141ULL + 0xE48E9A4097E2D866ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8C236253F6E733E9ULL + 0x8034A53270711846ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x842D64A2210FEEE3ULL + 0xBD6B04B8296DBD79ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8231833950031DBBULL + 0xE42A56BC44E450BCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xED360A23559D5C79ULL + 0x83024F25080A4908ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9938F64C4A27DA9FULL + 0xDAF5B87B5E3E51C7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xABBF6BB9BBE75335ULL + 0xFACF26554321908DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB90AB23CC845459DULL + 0xE71F040FBFC5D00AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB53DD6704DB65E31ULL + 0xA1018084B830719AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB0F646B13D8BF90BULL + 0x9A55C96C504B5213ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3974U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4050U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1358U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6693U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 28U)) + 18191288703716505885U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 9824014524910417136U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 57U)) + 11953012029254917548U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 51U)) + 6297568011027199089U) + aPhaseCOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 2576999400457367975U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 3U)) + 13176139160575558254U) + aPhaseCOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 22U)) + 9978408174563621810U) + aNonceWordI;
            aOrbiterI = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 16765834875061607142U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 16534507305459121344U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3114710944346151807U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 10240517868726718592U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4645691562915606463U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10721450637990777883U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16689590768796583952U;
            aOrbiterF = RotL64((aOrbiterF * 3046344179729901637U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2427422768928450209U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13495584061816457831U;
            aOrbiterI = RotL64((aOrbiterI * 6670984773768885119U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7058636403765106682U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9897341853944713767U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14286816859999869231U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17749559755733386064U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12515645083926326659U;
            aOrbiterJ = RotL64((aOrbiterJ * 6582878478865838245U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2625692458813609962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10596240255026143019U;
            aOrbiterA = RotL64((aOrbiterA * 11605800195771080135U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12374290338067865540U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1507386663796330249U;
            aOrbiterC = RotL64((aOrbiterC * 1210241080424446087U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9288099549484146726U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15159312464747000702U;
            aOrbiterG = RotL64((aOrbiterG * 500055502081347757U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 14998608679505446229U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17625038109437732009U;
            aOrbiterD = RotL64((aOrbiterD * 14785862243019841689U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 58U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 46U)) + aPhaseCWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 37U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterB, 18U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8679U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 9423U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9718U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12983U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 4U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 1866656689936219099U) + aNonceWordJ;
            aOrbiterH = (aWandererF + RotL64(aIngress, 29U)) + 2312314528139448289U;
            aOrbiterI = ((((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 3554037526469185237U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 405707755060974111U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 57U)) + 1862976326004007697U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 41U)) + 12992483065443288263U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 3793854946371595197U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 5U)) + 4244007978867369382U;
            aOrbiterG = (aWandererH + RotL64(aCross, 24U)) + 10280867500312580308U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 472563452959164242U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12041770406895816553U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 17811798500132002631U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6118634015704900486U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13637107920449233307U;
            aOrbiterK = RotL64((aOrbiterK * 17712028184714868053U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16673735670669318830U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8602681273646630496U;
            aOrbiterD = RotL64((aOrbiterD * 6995213887710749241U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7683264695930369476U) + aNonceWordE;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 9146674871199188218U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 7403427067419261981U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3012935612827493084U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1259789268731661945U;
            aOrbiterG = RotL64((aOrbiterG * 2372843620327050137U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5623690455471160780U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18355567776031865462U;
            aOrbiterE = RotL64((aOrbiterE * 9553862670107886679U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7705134893833304792U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4435192506444773834U;
            aOrbiterB = RotL64((aOrbiterB * 5249651218395299501U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6204683785806409075U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17886971535016484255U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6047216474762933535U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4430578901091376829U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 607557685798141547U;
            aOrbiterH = RotL64((aOrbiterH * 12342665567201483107U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererH = aWandererH + ((((RotL64(aCross, 37U) + RotL64(aOrbiterK, 34U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 46U) + aOrbiterH) + RotL64(aOrbiterA, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterE, 20U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 42U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + aPhaseCWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19975U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 17718U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21229U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22193U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 13333509828310369865U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 7645352517103840797U) + aPhaseCOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 18U)) + 5310766306660062655U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 41U)) + 5165635069832352932U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 39U)) + 15684141764734281849U;
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 3327963374225061738U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 28U)) + 8625811794878848871U;
            aOrbiterB = (((aWandererF + RotL64(aScatter, 23U)) + 7598657468430485291U) + aPhaseCOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 35U)) + 2881171216276746485U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 10237691227222918101U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6419254255884834497U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3816625473642865305U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 4238455444646479956U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 14936613353493061492U;
            aOrbiterF = RotL64((aOrbiterF * 3544216916806292273U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15324699725208372627U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9506640480601832011U;
            aOrbiterE = RotL64((aOrbiterE * 12819564111348390227U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3709149613660215641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1724290199312754307U;
            aOrbiterK = RotL64((aOrbiterK * 12597580418257897965U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13191172833570139194U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3686087945377837886U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10418330386245397022U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5383531313632347245U;
            aOrbiterH = RotL64((aOrbiterH * 2987755379396160073U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7414716553072652212U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11301761123966206201U;
            aOrbiterG = RotL64((aOrbiterG * 1546727321088592187U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8570229732236388847U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8773754460060264773U;
            aOrbiterB = RotL64((aOrbiterB * 3251360788932563495U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13636929800504199371U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5486599841558573720U;
            aOrbiterA = RotL64((aOrbiterA * 2867914211589815153U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 44U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + aNonceWordP);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 22U)) + aOrbiterB) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererI = aWandererI + (((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordH) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterJ, 38U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30529U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24621U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31435U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneD[((aIndex + 24614U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 30U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 18U)) + 252059974543142812U) + aNonceWordG;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 11690823093681457368U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 39U)) + 13282189752890971123U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 47U)) + 9507416294305708435U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 22U)) + 14053038174390776539U) + aPhaseCOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 14605253312318725009U;
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 18138286582677863671U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 8530091235978489988U) + aNonceWordK;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 14381731677571170073U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13316413456378978456U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3910529530149320706U;
            aOrbiterC = RotL64((aOrbiterC * 16000139333493588429U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6302070286831566901U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12324134652758551396U;
            aOrbiterE = RotL64((aOrbiterE * 17136438281540250165U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4773478557638475048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4031153435446078944U;
            aOrbiterG = RotL64((aOrbiterG * 3876928995240982769U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3114794895962903899U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3552936509969106796U;
            aOrbiterK = RotL64((aOrbiterK * 16823186892738820299U), 27U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterK) + 5828754613946145627U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17985241114076114558U;
            aOrbiterJ = RotL64((aOrbiterJ * 1986669631395606833U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11319331046368072261U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6104267020171882160U;
            aOrbiterB = RotL64((aOrbiterB * 12525117969211576177U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 7662668379725735125U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6583034411403600735U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 262095656452193889U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5569865728026310280U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4176065898330374039U;
            aOrbiterA = RotL64((aOrbiterA * 11305749530796963967U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13677146592276526676U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2734371113158117596U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13146444882662731975U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 54U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 52U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aNonceWordB) + aPhaseCWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 24U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterJ, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 48U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 26U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 50U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8A92AE9699148F61ULL + 0xE5C87EF85FACA4CFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEFC45EA3BDA95CD9ULL + 0x91AB4D8E3951D8F5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB85234B7A3AFA087ULL + 0xE11E6A6638522065ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xED50D88609F93A5FULL + 0xE0A1A49E45BA1150ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x83E1C8AA85331703ULL + 0x9ECF918E6941BD60ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8467BB8A9BA8E217ULL + 0xB93D38BF4C197641ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC7ED879D51ED6031ULL + 0xF000B2FCC2DBE91CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x80613D319E913BC1ULL + 0xFC948ECB18AF7B25ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBD0CDBFC3E22E481ULL + 0xF8A315FAC09C326DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBEF93B21729B5DADULL + 0x9C7BFE3C02F62BB6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9C896486215C524FULL + 0xBD948732A40A872CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF6BE07312863BBBFULL + 0xA5A716C310C9ED62ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF06733975A86C2FDULL + 0xEAEA571FCF6D5E4CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD225B8D4E380D9E9ULL + 0xF80FF37E06AB4CAFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDB2A33899E6DE79BULL + 0xCFA01BBA58058AD5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x929A6137C77DC77FULL + 0x899C9DDF309C051FULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2483U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 2037U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2401U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5067U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 13650869943246163567U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 14U)) + 3435284932011770999U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 53U)) + 12388155658186776579U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 37U)) + 2374345913955712039U;
            aOrbiterE = (aWandererI + RotL64(aCross, 29U)) + 6095094526980292156U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 23U)) + 4965147025852444174U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 43U)) + 3261881216269075298U;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 4939780217097329222U) + aNonceWordP;
            aOrbiterA = (aWandererK + RotL64(aCross, 43U)) + 3019862009792676287U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 39U)) + 901910626217143974U) + aNonceWordG;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 47U)) + 3647055146712366383U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7731765438957392967U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13409819457393479741U;
            aOrbiterH = RotL64((aOrbiterH * 3345078200262410715U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5415832109107794258U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8876738832313114471U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 1304277600444504135U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17135570542519390359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2373193062766802082U;
            aOrbiterF = RotL64((aOrbiterF * 4213691513185791519U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16318403285501718552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8456043288604687045U;
            aOrbiterC = RotL64((aOrbiterC * 10556964529144571683U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10572534930284516528U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14616251186735204677U;
            aOrbiterI = RotL64((aOrbiterI * 2048651204265459805U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2837006243817205610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5315917323622194254U;
            aOrbiterA = RotL64((aOrbiterA * 4080522050089666599U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12084676282761185907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7922080344175593788U;
            aOrbiterG = RotL64((aOrbiterG * 7603522302708937379U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17620847289789547792U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12140386059533463650U;
            aOrbiterK = RotL64((aOrbiterK * 1443266480620969535U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4006608081473218762U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3152507055132739011U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 11929522909695002321U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 10845720206369283181U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16572752872386133133U;
            aOrbiterD = RotL64((aOrbiterD * 2891952650448087211U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15544908026178481075U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13650869943246163567U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1275090431127426217U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 48U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 3U)) + aNonceWordI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 40U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 5U));
            aWandererH = aWandererH + ((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterE, 11U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 42U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 42U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9339U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8756U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8706U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 7935U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 53U)) + 1087148170018530502U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 47U)) + 15530846874509311414U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 16987358651515511212U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 12U)) + 12504143181007924259U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 393322117322732418U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 19U)) + 14325937299241887166U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 39U)) + 9395262907017475742U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererD + RotL64(aIngress, 37U)) + 13658510441418344769U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 57U)) + 6410754322737005336U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 42U)) + RotL64(aCarry, 41U)) + 9257290738538818434U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 7489828960857692286U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 4118778591214588387U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16619215231168796563U;
            aOrbiterB = RotL64((aOrbiterB * 14876884956536265157U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11326283811003573430U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1865401866017614604U;
            aOrbiterA = RotL64((aOrbiterA * 8378326058282460073U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 670150121105733604U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1499331510641068749U;
            aOrbiterD = RotL64((aOrbiterD * 16623742535540383107U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1116410848560838532U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2696841341036281779U;
            aOrbiterJ = RotL64((aOrbiterJ * 9598953298074904869U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5487352391229549881U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12008243050943342979U;
            aOrbiterC = RotL64((aOrbiterC * 9087261224804582459U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 552859665927882960U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8426942688524814473U;
            aOrbiterG = RotL64((aOrbiterG * 10916963622695549105U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1613287981244830815U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15592897923468694288U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 6600750586743893303U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7629853970631002676U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13778028957247561272U;
            aOrbiterE = RotL64((aOrbiterE * 4063798788229605659U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2932956928094332652U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 14855524972646900872U;
            aOrbiterF = RotL64((aOrbiterF * 9546042275547649745U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11071597794692793784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6327727700942234552U;
            aOrbiterK = RotL64((aOrbiterK * 15301120263944789797U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5147576281502110428U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1087148170018530502U;
            aOrbiterH = RotL64((aOrbiterH * 18045084130531645749U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 36U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 58U) + aOrbiterE) + RotL64(aOrbiterH, 11U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 30U)) + aOrbiterF) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aNonceWordO);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 34U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12138U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 14206U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12395U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16019U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 10805654776556844351U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 50U)) + 582794182442795335U) + aNonceWordG;
            aOrbiterI = (aWandererA + RotL64(aCross, 27U)) + 2858343650974681068U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 43U)) + 8189584049022064284U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 29U)) + 1565100751996962893U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 35U)) + 8062028016947611891U) + aPhaseDOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aCross, 58U)) + 8280504280578451745U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 11326869194491655350U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 1671695656567777163U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 41U)) + 2349843105293943452U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 21U)) + 13015545152052004254U) + aPhaseDOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16703354404749291869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8713231044374305801U;
            aOrbiterI = RotL64((aOrbiterI * 9242480982197688625U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11118401674497783533U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14857556493734710364U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3452566050389715195U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12953419670951660965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12666121730825089017U;
            aOrbiterD = RotL64((aOrbiterD * 14049925256934142519U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11075249639473053423U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9374217688244187867U;
            aOrbiterC = RotL64((aOrbiterC * 5261156325627117877U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17608340953291367867U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13159437499327086340U;
            aOrbiterK = RotL64((aOrbiterK * 4882100944453534805U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4304700511322366815U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10172544755256706767U;
            aOrbiterE = RotL64((aOrbiterE * 4013006212154771797U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17340067939877432472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14130447570008179105U;
            aOrbiterG = RotL64((aOrbiterG * 8178075071208718915U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2652532710498072378U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10384945384238518296U;
            aOrbiterB = RotL64((aOrbiterB * 17137694272394304045U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15292159041119433363U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12103644911645285108U;
            aOrbiterJ = RotL64((aOrbiterJ * 4565615406415614103U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16307525158627275744U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 3786908390177579447U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6592585847755318801U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13595883419843505634U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10805654776556844351U;
            aOrbiterA = RotL64((aOrbiterA * 10956465099104915639U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterH, 54U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 51U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 39U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aIngress, 26U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 56U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordD);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19398U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18965U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17699U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17725U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 13U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 53U)) + 6521330037475130256U) + aNonceWordN;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 12611880456055428940U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aPrevious, 43U)) + 12061611078130934708U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 39U)) + 1558112410801116984U) + aNonceWordH;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 53U)) + 10509115227850160786U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 4045915960688792066U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 41U)) + 1196541286513243082U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 60U)) + 15564991032722373702U) + aPhaseDOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 4897765238703641798U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 35U)) + 12327429514907752733U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 37U)) + 6189189797708711636U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6374267075282018852U) + aNonceWordG;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1888758503831341439U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 74387714918264257U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14956857689299491800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14879361107223331957U;
            aOrbiterA = RotL64((aOrbiterA * 9166712966729591953U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16086885494838105042U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8069724185844303923U;
            aOrbiterJ = RotL64((aOrbiterJ * 8878470736758734353U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 10854345917959911439U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7078313614360332089U;
            aOrbiterK = RotL64((aOrbiterK * 9864025732292844871U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15083669236062255011U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 594879695916679116U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 9852515479152735283U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6721466068234534523U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 475816724162626782U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4799725182757588407U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4341655358154605899U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15477254302340298586U;
            aOrbiterB = RotL64((aOrbiterB * 13961520225881974201U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10179091913200895775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6310490897546909571U;
            aOrbiterI = RotL64((aOrbiterI * 15080621088825477613U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13462682513035460711U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16739138858084100385U;
            aOrbiterF = RotL64((aOrbiterF * 16386371811268298031U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13608837667062268989U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12902415667552110103U;
            aOrbiterH = RotL64((aOrbiterH * 16398790854093048017U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16596211634603915761U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6521330037475130256U;
            aOrbiterE = RotL64((aOrbiterE * 631958426544321145U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 54U)) + aOrbiterH) + aNonceWordM);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterB, 13U)) + aOrbiterI) + aNonceWordD) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterG, 24U));
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterG);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 37U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 25290U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25425U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23117U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 23928U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aIngress, 51U)) + 14008824488073394623U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 47U)) + 13317978415866411468U;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 20U)) + RotL64(aCarry, 23U)) + 13209180141897453900U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 11870521586865233578U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 43U)) + 8052156380448047385U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 12158131176743680605U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 27U)) + 14674467487607719347U;
            aOrbiterG = (aWandererK + RotL64(aCross, 23U)) + 18055496790566231147U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 29U)) + 3838105585041578784U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 35U)) + 2839568255183054418U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 56U)) + 11933612922864258179U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 6289849094151630580U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2640344350528492271U;
            aOrbiterJ = RotL64((aOrbiterJ * 16197726750829369365U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16306175266267657791U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3339898380394883600U;
            aOrbiterD = RotL64((aOrbiterD * 7105436590182982373U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 15017076663742800002U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8973064296077602496U;
            aOrbiterG = RotL64((aOrbiterG * 9309462227233615761U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17580319233338139859U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 14063208878807603874U;
            aOrbiterK = RotL64((aOrbiterK * 16601475239075164585U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 13326130855721009942U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12843186026737544416U;
            aOrbiterH = RotL64((aOrbiterH * 4975848122837321619U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14102887715772847499U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14495942314329085733U;
            aOrbiterE = RotL64((aOrbiterE * 4236795312917583565U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11564857125101669667U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17435970784822000464U;
            aOrbiterA = RotL64((aOrbiterA * 1472691848852381173U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16561390130356833062U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 9952805588514363872U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3720874990001086597U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8246822023509690545U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 305480212301772662U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4295787267516476485U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11729872285756639125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9669174142543613799U;
            aOrbiterF = RotL64((aOrbiterF * 9443240779947114779U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 7653344907616923293U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14008824488073394623U;
            aOrbiterB = RotL64((aOrbiterB * 8362849599309360823U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 20U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 44U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterJ);
            aWandererH = aWandererH + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterE, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28550U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 30045U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32560U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 30399U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aCross, 57U)) + 9023059520606551446U) + aPhaseDOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 5U)) + 662441755115638133U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 5U)) + 16957253361196144712U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 11U)) + 7840955025765308605U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 346855809270395799U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 35U)) + 16099139781586668343U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 21U)) + 3706457327118322098U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 12166825885547622870U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 37U)) + 7792658665720344200U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 30U)) + RotL64(aCarry, 47U)) + 7128477606152986326U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 39U)) + 11116533962780290084U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10443889548568288532U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4402387036946561017U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13002706161178447654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13929727277530310708U;
            aOrbiterB = RotL64((aOrbiterB * 7005639090871200285U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10949073760696935106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15405923432006783533U;
            aOrbiterE = RotL64((aOrbiterE * 17989565878445202495U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 18096057968822208905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3032155040484574973U;
            aOrbiterJ = RotL64((aOrbiterJ * 448597307502544605U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17462076466907467134U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15471015427013701406U;
            aOrbiterF = RotL64((aOrbiterF * 6113474000571976139U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3549031751266594344U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14243218483842508113U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9041601306479302047U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5803147589312920032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5549470512227427855U;
            aOrbiterI = RotL64((aOrbiterI * 12592362489263862879U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10076661824293832189U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3196799148974716550U;
            aOrbiterG = RotL64((aOrbiterG * 8183276968961467775U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5245559903456662243U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5907555542861339984U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 10224549416454347583U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12670710096595941569U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 655047039452620836U;
            aOrbiterH = RotL64((aOrbiterH * 9717552134857988153U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2654837870443908572U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9023059520606551446U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 170905364378771841U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 30U)) + aOrbiterC) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 43U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterE, 60U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Cricket_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD43E088FC8CD698BULL + 0xEE8391E540925662ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9C5B6706CCFC35CFULL + 0xC7E03D615C1F00AFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF58994FD2504883FULL + 0xB053554D04DB1A8DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAA2701405BA9D3A9ULL + 0x97EA77D672B7436EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xEA4C4DA04BF81DD5ULL + 0xB29FE7AACC2966D0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFF1E1E2A2095310BULL + 0xCF38AFF58F60B00AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x93817BED490E1AFFULL + 0x89D455F98BB5DC9BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x907F55B69A4D394FULL + 0xD1141B396074E88DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB013B1241D9DBD3BULL + 0xBE00E86E0D982AFFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xB5A24D7F967E7115ULL + 0xC3B257B54F4647C3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD8BCD52C9769F219ULL + 0x954FB86889437D27ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x80B9FD9DF4CFDF61ULL + 0xAE84DC6075D115FEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9895B9BBF45F3839ULL + 0xC934E4BDF1B96BDDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB2BE9003C41ED2D7ULL + 0xEB396F50B2F9491DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x87141CCA39EFE967ULL + 0x95958B2B03324586ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB73BA23ABD4285F1ULL + 0x879A9B69FD0EF483ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5354U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2037U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2239U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 4082U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 34U)) + 1297415699043177788U) + aNonceWordN;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 51U)) + 17583786534509260153U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 53U)) + 643197858925708798U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 41U)) + 5062653766915694874U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 19U)) + 7034273638367180511U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 2026909726972916996U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 2785690475553211646U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 27U)) + 2910341716302991892U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 57U)) + 2834181605200829791U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 13323052600571281928U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 38U)) + 10434901530315760460U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 247903955625194782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5196515747387257163U;
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7196305682377987476U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14777739876892587484U;
            aOrbiterI = RotL64((aOrbiterI * 95220583948241581U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10609060796540136671U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8386027207212484155U;
            aOrbiterH = RotL64((aOrbiterH * 4855610536246556893U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 729659744301903424U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2350564261412606157U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16713856782349084977U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16611987556673864177U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1525195188708550503U;
            aOrbiterG = RotL64((aOrbiterG * 10045858602151004553U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 4654808490980989596U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8189569777087686263U;
            aOrbiterJ = RotL64((aOrbiterJ * 17278657566389299577U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10932857495004451792U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1833880112534916813U;
            aOrbiterB = RotL64((aOrbiterB * 8004341577533825681U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13100236350175516423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2773759534195186313U;
            aOrbiterE = RotL64((aOrbiterE * 3194954066097323161U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13963126688973399221U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1464529855671190406U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 6129954747502059213U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 9489842625026216815U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17806120432918490594U;
            aOrbiterK = RotL64((aOrbiterK * 349307975773661379U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13833297268854563081U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1297415699043177788U;
            aOrbiterD = RotL64((aOrbiterD * 4818542043777342249U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterF, 6U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 21U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterD, 40U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9931U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9003U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6284U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6688U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 11U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 57U)) + 9914837590440975587U) + aPhaseEOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 39U)) + 6706125076401958051U) + aNonceWordN;
            aOrbiterK = (aWandererA + RotL64(aCross, 47U)) + 16570817772679258409U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 50U)) + 6843705658115186948U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 3U)) + 16099930446791572351U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aScatter, 35U)) + 5420550009556030459U) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 5729549069420177477U;
            aOrbiterC = (aWandererF + RotL64(aCross, 53U)) + 15590601126188675834U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 13044027390998620029U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 11068338135659636772U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 44U)) + RotL64(aCarry, 51U)) + 6584988841809544332U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8516813219883915404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10647314042912492785U;
            aOrbiterK = RotL64((aOrbiterK * 15559481057047148785U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 201691689889605304U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15512161798401184003U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11473219183982564709U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3883760518944464145U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13861805129175491145U;
            aOrbiterG = RotL64((aOrbiterG * 17194438894492581181U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12019138626550801486U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13030350224959652248U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11724200983306280107U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2643807255422544248U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4127143302485631794U;
            aOrbiterJ = RotL64((aOrbiterJ * 5441038881111578487U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14602951930809633069U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4555737199162278494U;
            aOrbiterD = RotL64((aOrbiterD * 12415825635220991865U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6343143902997169834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10404783711336491985U;
            aOrbiterB = RotL64((aOrbiterB * 6235474458879439079U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 7406959231434835393U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6684368109277850196U;
            aOrbiterE = RotL64((aOrbiterE * 8760360417572331159U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 4835889355927954728U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7917682889852676712U;
            aOrbiterC = RotL64((aOrbiterC * 9045350756570117327U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10268055422944417055U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5563744562922937643U;
            aOrbiterH = RotL64((aOrbiterH * 12442484191329795173U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17244672945880141679U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9914837590440975587U;
            aOrbiterA = RotL64((aOrbiterA * 12269340309792850489U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 30U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 51U)) + aOrbiterI) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterG, 28U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 35U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 36U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13489U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11559U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15979U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 15323U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aIngress, 5U)) + 6654158889644956636U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 21U)) + 9045779659363991870U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 3888897662136993491U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 26U)) + 6882016842864459345U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 47U)) + 15601891715956172291U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 19U)) + 5176811598629335350U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 12519945150889074325U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + 4552583214397603278U) + aNonceWordD;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 53U)) + 14225482701804864688U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 5485298070606280363U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 37U)) + 11237713257388094289U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 14340345895626142788U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16275167270553643347U;
            aOrbiterD = RotL64((aOrbiterD * 7308578867128951199U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14041860597556520250U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1436068974197066343U;
            aOrbiterA = RotL64((aOrbiterA * 3938460345031496843U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 11483155566419547004U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4608508534724289325U;
            aOrbiterF = RotL64((aOrbiterF * 13461385011638899485U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2389196334288832895U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4062682330273866602U;
            aOrbiterG = RotL64((aOrbiterG * 8787682133271101901U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5655656046585592034U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7977947821249746880U;
            aOrbiterB = RotL64((aOrbiterB * 10082104644185964787U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 11653718118543974168U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5456429682072377614U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 12504180638665296649U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12457179652004203574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 445821754230182952U;
            aOrbiterC = RotL64((aOrbiterC * 16043092621697786393U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12429505513284703263U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 12480745784412363537U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 643617210585287593U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6952219750393303609U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13965647644550998416U) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 5395755018020115073U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5602193483992512507U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9593414134773695959U;
            aOrbiterE = RotL64((aOrbiterE * 2186313187456153775U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16469843418561148995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6654158889644956636U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17490973872858383001U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 12U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 48U)) + aOrbiterH) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterD, 11U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterE, 3U));
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterE, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19221U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20175U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20976U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 17519U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 37U)) + 701291026547470433U) + aNonceWordE;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 17283292650462111643U;
            aOrbiterH = (aWandererB + RotL64(aCross, 35U)) + 9969124091931303406U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 21U)) + 889176772718046988U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 18U)) + RotL64(aCarry, 43U)) + 6054541844643748084U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 14703226235143028132U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 47U)) + 7977975878522921062U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 23U)) + 16894322614172266274U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 56U)) + 12160451749345900570U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 13U)) + 10870847008043897470U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 5U)) + 8159920947172520247U) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2440099120969517932U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2428396147731468007U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9363073341539598441U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2213226274394673479U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7079731443427765333U;
            aOrbiterJ = RotL64((aOrbiterJ * 16918930776877030559U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 958896789550478970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10788682955708075458U;
            aOrbiterG = RotL64((aOrbiterG * 913321215613559729U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2003386579317564870U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8419686358774204999U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6547052526438697621U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6989167615157578904U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17636634003643824148U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11038576417283732937U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13824962118933907859U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 9543912892587859646U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 14736710162285997415U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15729878041027706114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9542137475454825463U;
            aOrbiterI = RotL64((aOrbiterI * 11420547128115090491U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5327302277575009955U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2707383132257428583U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6120763309390182129U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 9008601903853562620U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11050463189491777908U;
            aOrbiterD = RotL64((aOrbiterD * 9178386878636430553U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14683684132116778056U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5390271065690907120U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 17903005409098232619U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5183407290520277451U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 701291026547470433U;
            aOrbiterC = RotL64((aOrbiterC * 16329261100139524239U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 58U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 46U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 21U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + aNonceWordA) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25688U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25659U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23013U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 25150U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 12U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 23U)) + 6318740973868639425U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 60U)) + 5487840061430920881U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 29U)) + 10258706763248072672U;
            aOrbiterC = (aWandererK + RotL64(aCross, 47U)) + 18356875269730338208U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 12883160282903147010U) + aNonceWordE;
            aOrbiterJ = (aWandererH + RotL64(aCross, 53U)) + 1010140474942697730U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + 17733939421700898293U) + aNonceWordL;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 13693055887924981201U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 11U)) + 14574732452793385269U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 26U)) + RotL64(aCarry, 51U)) + 10832873941223609012U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 13U)) + 8212600587135328040U) + aNonceWordM;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5312744319781971178U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6173741211706546923U;
            aOrbiterK = RotL64((aOrbiterK * 12854414066390848249U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3693249147883790810U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18365859989736602556U;
            aOrbiterJ = RotL64((aOrbiterJ * 3348463719324104997U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10645056678337549771U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1175668356822251045U;
            aOrbiterB = RotL64((aOrbiterB * 6579675292775345579U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13556844570541823717U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 4790355739411849736U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 4083544011788850307U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14905575502272644116U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17047244574558476634U;
            aOrbiterG = RotL64((aOrbiterG * 2356386971503880047U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10161614295718414869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13413914082651612468U;
            aOrbiterC = RotL64((aOrbiterC * 16224039093981079491U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6072693130156927774U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4333656233793103787U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9374745547133955709U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17209776289202130250U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11752001118070361543U;
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15367365111105608277U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8650687767097460704U;
            aOrbiterF = RotL64((aOrbiterF * 11430451559660578667U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18074648514448405693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10857586858462237581U;
            aOrbiterH = RotL64((aOrbiterH * 3722891011080095849U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 17219932344278345591U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6318740973868639425U;
            aOrbiterA = RotL64((aOrbiterA * 8846295038878812229U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 44U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 58U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterA, 40U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterH, 19U)) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 13U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 34U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32477U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((aIndex + 31767U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27662U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 32296U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aScatter, 37U)) + 17264605017518259932U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 13U)) + 15209184354580778643U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 3299527965014731384U;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 21U)) + 16293096431816127821U) + aNonceWordJ;
            aOrbiterG = (aWandererC + RotL64(aScatter, 57U)) + 11031983436878828337U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 48U)) + 9188018632448236358U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 5U)) + 13420816400363406556U) + aNonceWordM;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 3U)) + 2485063384097917101U;
            aOrbiterF = (aWandererG + RotL64(aCross, 43U)) + 3089135816938128264U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 34U)) + 10730544971770435788U) + aPhaseEOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 10431767565618874806U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14883796491656899074U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterC = RotL64((aOrbiterC * 14311686051108108503U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13322163435314643713U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4950101626975919939U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2596253994220103666U;
            aOrbiterJ = RotL64((aOrbiterJ * 7181706961838582889U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17961706029559914243U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterI = RotL64((aOrbiterI * 16189559888625084711U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18146616411403012772U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8414050129421955787U;
            aOrbiterB = RotL64((aOrbiterB * 14879448948196182863U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11739172334166341121U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7936637782633487291U;
            aOrbiterF = RotL64((aOrbiterF * 14940929920543800413U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3160044627483874242U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16816384076887379704U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8101560104988710226U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8851416379738817624U;
            aOrbiterE = RotL64((aOrbiterE * 16767420038937389027U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9941784290055185679U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14495651885701938495U;
            aOrbiterA = RotL64((aOrbiterA * 1540692851998143607U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10599676325220702167U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16092000942942971187U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2457268192247656817U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16168470945107928109U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17264605017518259932U;
            aOrbiterD = RotL64((aOrbiterD * 15038386057529909273U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterG, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 58U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterA, 3U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 30U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD168258907B7EF3DULL + 0x920C80D269C8BB96ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB10ECD5EBB1BC983ULL + 0xA5EDDE0629A8EC8AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC52DFADC054EDC9DULL + 0xBF8494568FB453D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFAAEE32C756C70FBULL + 0xA5A659DB300C34BBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB3BC0EE3497CB91FULL + 0x98690F606FC8112FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCEE2A5FCECCFCEE9ULL + 0xE24EA887C7D9A2CBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBD17904897ACB8BFULL + 0xA7D379C2AEBEED0AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF8C331E24BF22BC7ULL + 0xD3ABDFFD7FE13A33ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE7BFC06F10D3422FULL + 0xC6D2C2799261504CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAE487BC66A75E14FULL + 0xB55B880F87BF7D45ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x81944623683A4A67ULL + 0xA7B8597203D8D5FFULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF90B49B6382A04F1ULL + 0xC3941FF9E1F036B9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xE688A6BE6B8E6E45ULL + 0x800F5E4DA711FA33ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD88642796FBB83C3ULL + 0x90183C865A1CA8EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8263BD00810097F1ULL + 0xC02BB925638BF025ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8B917C3F2CF8336FULL + 0x887C25344F56FAD7ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1644U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1732U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4369U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 2447U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aScatter, 54U)) + 7960325128608297381U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 43U)) + 12773836012104052042U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aIngress, 5U)) + 3173972621347773016U) + aNonceWordF;
            aOrbiterD = (aWandererJ + RotL64(aCross, 35U)) + 3708401356314308171U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 41U)) + 950774285720019449U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 27U)) + 4170092315705438265U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 17000449130864980747U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 8793910540062893860U;
            aOrbiterE = (aWandererI + RotL64(aCross, 39U)) + 520277969543516469U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 57U)) + 12762214857389827271U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 10U)) + RotL64(aCarry, 57U)) + 2932451184340207695U) + aNonceWordM;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 11062179998786293839U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7919119215271524178U;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1774988449597115155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1815062051307896589U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15260373951371654483U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12867546628945676853U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7772820973895846946U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7581704643538761985U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14213957831821966834U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16561105721170419454U;
            aOrbiterB = RotL64((aOrbiterB * 2540533987337175367U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16556502948339949526U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9706742922075498974U;
            aOrbiterE = RotL64((aOrbiterE * 8527361328901355457U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13455756934917486016U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9107769876332723454U;
            aOrbiterJ = RotL64((aOrbiterJ * 1722386100852683783U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15793099079168487016U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7968278803691283365U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 11644765391940099387U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15068302421261745111U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11373111908765197862U;
            aOrbiterK = RotL64((aOrbiterK * 17756438368103196771U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6362100123286229887U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 528778333872160609U;
            aOrbiterG = RotL64((aOrbiterG * 17377710146983314215U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6116442644744391285U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7960325128608297381U;
            aOrbiterA = RotL64((aOrbiterA * 17826511435509927061U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 47U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 23U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aPrevious, 60U) + aOrbiterK) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + aNonceWordL);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 4U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8625U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 9671U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5608U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8832U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 23U)) + (RotL64(aCarry, 56U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 6467297102954816305U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 27U)) + 7921154109831114952U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 5701131763215638919U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 10022999076719002684U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 52U)) + 4367135243038982316U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 21U)) + 14445846824810383592U) + aNonceWordM;
            aOrbiterA = (aWandererB + RotL64(aIngress, 3U)) + 7683697954545773253U;
            aOrbiterB = (aWandererH + RotL64(aCross, 23U)) + 17517006750428030899U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 5U)) + 2052484792684025476U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 41U)) + 6279463052085808926U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 50U)) + 679280153651813684U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2939516520188460569U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1960616434964712325U;
            aOrbiterC = RotL64((aOrbiterC * 15145998415466343039U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12273819390719947361U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5685033154709449397U;
            aOrbiterF = RotL64((aOrbiterF * 9845666295874714959U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9314494172199500653U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15757631834636427621U;
            aOrbiterG = RotL64((aOrbiterG * 15483543888965744529U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10878078046389399574U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3583495913766365232U;
            aOrbiterA = RotL64((aOrbiterA * 2913540984990155225U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7385544065754622301U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16839599460207922881U;
            aOrbiterD = RotL64((aOrbiterD * 240651605910592561U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13038163804940349251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2587538594933924000U;
            aOrbiterH = RotL64((aOrbiterH * 3091149760401278671U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13109518583364738004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2447689055742474261U;
            aOrbiterE = RotL64((aOrbiterE * 12100180201235703193U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5752044906692668618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6637725371036522120U;
            aOrbiterK = RotL64((aOrbiterK * 6021986525167161115U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16549229877442298618U) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12825651879441561108U;
            aOrbiterB = RotL64((aOrbiterB * 9079931351967033993U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16088338999978085987U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12584648360998154782U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2109996837220975261U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7526256599938771686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6467297102954816305U;
            aOrbiterJ = RotL64((aOrbiterJ * 9289442676936248653U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 44U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterA, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterC, 34U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13253U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13180U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14310U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15511U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 34U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aScatter, 29U)) + 1898718075389870739U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 46U)) + 5631794889237247403U;
            aOrbiterI = (aWandererE + RotL64(aCross, 5U)) + 18219714659484524607U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 15419581386225732921U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 39U)) + 9125575431710198210U) + aNonceWordK;
            aOrbiterE = (aWandererF + RotL64(aIngress, 53U)) + 12205871520544965505U;
            aOrbiterH = (aWandererG + RotL64(aCross, 57U)) + 7617534300497343422U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 11U)) + 18017579105368135814U;
            aOrbiterB = ((((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 10693882161946020042U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererC + RotL64(aCross, 41U)) + 11669615701700895306U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 18U)) + 11045110212889232165U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18019107802806469913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4899009736070044310U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17412253404253730364U;
            aOrbiterE = RotL64((aOrbiterE * 10791901166391946485U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4826286251927854181U) + aNonceWordE;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4523455921321845084U;
            aOrbiterF = RotL64((aOrbiterF * 14534103906736598099U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4132514462154182215U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 7164745605985109269U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14107325508977225261U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6297434295807635654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8813887638672996646U;
            aOrbiterJ = RotL64((aOrbiterJ * 17495632530773158201U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11086381278955626084U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5660733992573928887U;
            aOrbiterG = RotL64((aOrbiterG * 11248164458720777889U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14851044686208609882U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12707776386060264479U;
            aOrbiterD = RotL64((aOrbiterD * 4470919091467313071U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11508023384209716657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11752973809740920034U;
            aOrbiterA = RotL64((aOrbiterA * 10212754472298834769U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16746821150860017820U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9659421716296641396U;
            aOrbiterH = RotL64((aOrbiterH * 7530071874978553673U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3192309064305104593U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11409078048681398061U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14991409124701807765U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 315359495275427324U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1898718075389870739U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13126661894614781343U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterI, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ) + aNonceWordI) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterB, 58U));
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 34U));
            aWandererE = aWandererE + ((RotL64(aScatter, 6U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordP);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21749U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 18640U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16966U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((aIndex + 21040U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 13U) ^ RotL64(aPrevious, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 58U)) + 439898681482066326U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 47U)) + 17362083676671776094U) + aNonceWordH;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 6418499837265155024U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 37U)) + 17262244253027454972U) + aPhaseFOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 3U)) + 2382066162993139503U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 50U)) + 14345808395587174135U) + aNonceWordD;
            aOrbiterF = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 47U)) + 7534743166385552851U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 16994453324688523966U;
            aOrbiterD = (aWandererF + RotL64(aCross, 41U)) + 7079553728544045092U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 53U)) + 3562822704508440641U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 21U)) + 13990892681975857821U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1796728922368577238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6605161260520067178U;
            aOrbiterI = RotL64((aOrbiterI * 8147537646591674091U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13994083795942328918U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6144523182899107711U;
            aOrbiterJ = RotL64((aOrbiterJ * 4153879991344611283U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12247462325297436642U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1065809332002012789U;
            aOrbiterA = RotL64((aOrbiterA * 5496601177032953251U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10147919864511540753U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17138553441127273354U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 5773875596275267871U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 2653924016109573974U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6254416952351699582U;
            aOrbiterE = RotL64((aOrbiterE * 12756861659704947257U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 813046408080197079U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9624466135414123483U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 6960320253124395015U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 972586705850825744U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 155283774901960223U;
            aOrbiterK = RotL64((aOrbiterK * 9928051687724257041U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18200100644751360406U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1168426822045686004U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5867027156069481313U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2271564377169233643U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1896317305868283986U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8080751157990019287U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10209708407397294552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 947585551223387294U;
            aOrbiterH = RotL64((aOrbiterH * 15339472308062247067U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12313594490465462211U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 439898681482066326U;
            aOrbiterB = RotL64((aOrbiterB * 12336632799055203705U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterA, 50U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererI = aWandererI + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterD) + aNonceWordG) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 41U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterG, 46U));
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 6U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordD);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26871U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27098U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23420U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24178U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 51U) ^ RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 12136097566601676613U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 43U)) + 7969431322248040056U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aScatter, 47U)) + 10530676021510553889U) + aNonceWordL;
            aOrbiterK = ((aWandererI + RotL64(aCross, 19U)) + 8740777303075445264U) + aPhaseFOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 35U)) + 13249434169895564739U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 15529577005925628472U) + aNonceWordA;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 11U)) + 344627093687331562U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 8824277416519988893U;
            aOrbiterG = (aWandererC + RotL64(aCross, 27U)) + 5636276438449709875U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 51U)) + 2079413361031851552U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 38U)) + RotL64(aCarry, 19U)) + 7807998179168655561U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13589392896232029112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10733011474804473996U;
            aOrbiterH = RotL64((aOrbiterH * 361749145931578805U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15934162328347805968U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7573511217796245232U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 10694563909931636155U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4828475187337891975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13284974329890393113U;
            aOrbiterJ = RotL64((aOrbiterJ * 10831075817642374287U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13173869918669643112U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 15841507674783398167U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15632933198136963277U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14168272451055700516U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11134471485501999898U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 8019507184494591705U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2611858916687822610U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17863271539727513641U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4987884722174985677U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 8874401993454249066U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5131480593493950665U;
            aOrbiterI = RotL64((aOrbiterI * 8585874663602346121U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9366563022381918996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7890729519928340296U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11428572374057899517U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 131774386529223292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4108356674478240148U;
            aOrbiterB = RotL64((aOrbiterB * 2492753294539081613U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7651738365157869789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2745458108574051004U;
            aOrbiterA = RotL64((aOrbiterA * 2175955806036373729U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10492013124307434604U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12136097566601676613U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13128652803485742119U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterE, 5U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterC, 39U)) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterD, 10U)) + aNonceWordK);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterF, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 41U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 46U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30460U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 27578U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29000U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 27776U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 12U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 701291026547470433U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 19U)) + 17283292650462111643U;
            aOrbiterK = (aWandererC + RotL64(aCross, 43U)) + 9969124091931303406U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 41U)) + 889176772718046988U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 6054541844643748084U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 14703226235143028132U) + aNonceWordM;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 53U)) + 7977975878522921062U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aCross, 50U)) + 16894322614172266274U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 39U)) + 12160451749345900570U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 5U)) + 10870847008043897470U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 35U)) + 8159920947172520247U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2440099120969517932U) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2428396147731468007U) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 9363073341539598441U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2213226274394673479U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7079731443427765333U;
            aOrbiterE = RotL64((aOrbiterE * 16918930776877030559U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 958896789550478970U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10788682955708075458U;
            aOrbiterF = RotL64((aOrbiterF * 913321215613559729U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2003386579317564870U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8419686358774204999U;
            aOrbiterH = RotL64((aOrbiterH * 6547052526438697621U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6989167615157578904U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17636634003643824148U;
            aOrbiterC = RotL64((aOrbiterC * 11038576417283732937U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13824962118933907859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9543912892587859646U;
            aOrbiterD = RotL64((aOrbiterD * 14736710162285997415U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15729878041027706114U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9542137475454825463U;
            aOrbiterI = RotL64((aOrbiterI * 11420547128115090491U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5327302277575009955U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2707383132257428583U;
            aOrbiterJ = RotL64((aOrbiterJ * 6120763309390182129U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 9008601903853562620U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11050463189491777908U;
            aOrbiterB = RotL64((aOrbiterB * 9178386878636430553U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14683684132116778056U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5390271065690907120U;
            aOrbiterA = RotL64((aOrbiterA * 17903005409098232619U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 5183407290520277451U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 701291026547470433U;
            aOrbiterG = RotL64((aOrbiterG * 16329261100139524239U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 6U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 42U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 58U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterK, 54U)) + aOrbiterI) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererC, 22U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Cricket_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDEE7CB60F605A3A7ULL + 0xCE5D47F396830C61ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xFCC7B24D515D669DULL + 0xD50A6FE6876C9761ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB4AB316D32637BAFULL + 0xCA3818B3F6489C8EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB672260BAE2BA107ULL + 0x98F444EAD46A3417ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBA6F98678E6809D5ULL + 0xF102BDE6572C2511ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x877087EAFEFBD56FULL + 0xE41A9411B1FB3C9DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD11F937A540A734DULL + 0xE29F31B589315D5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8046DCC958B46083ULL + 0xE17927F92D140C4BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCD3AA2615520E673ULL + 0x8D364448F0392044ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF9D6F6F654FF368FULL + 0xFC6BB21C4BE28115ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC05B132CE5021AB5ULL + 0xC0FB20A0453BCD4AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x80571EF50768CF6FULL + 0xEE4D323D47D50FC1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDB19BC3AC394458DULL + 0x98072EF87C41821AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA38775B52628F367ULL + 0xA92B63AC2A859656ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x95AE260522507DE7ULL + 0xF66A07B28145BD54ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF1CDDD59CA394373ULL + 0xF135F2FA4AD5F722ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 936U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3959U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3869U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 424U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 10336802574069791273U;
            aOrbiterC = (aWandererG + RotL64(aCross, 10U)) + 169025388197058936U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 29U)) + 6541354188379168846U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 16223920526599306104U;
            aOrbiterE = (aWandererF + RotL64(aCross, 37U)) + 12756613707692514808U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 47U)) + 5082475548176484035U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 14U)) + 4907435526952698526U;
            aOrbiterF = ((((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 14236627073831834337U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererI + RotL64(aCross, 51U)) + 11502511046130497584U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 3679044835550219497U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 53U)) + 11254838916686736746U) + aNonceWordI;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10582608424233200966U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10449735026385340313U;
            aOrbiterH = RotL64((aOrbiterH * 7363770199734997411U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4628253464169957835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterI = RotL64((aOrbiterI * 4234720298731378527U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3798386391743884889U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 1379331161819246587U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 13086160171095077295U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9816600392407327227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16781971616348376878U;
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4807797577690520554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2492057261148595922U;
            aOrbiterD = RotL64((aOrbiterD * 9453302540675483005U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 7909676419643119585U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 256053568910383007U;
            aOrbiterK = RotL64((aOrbiterK * 11965085163352053161U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16179914439220412472U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3968867762761955845U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 7473632378251893139U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7474832923901283742U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4736994731050735779U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9839654409121414047U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 596484364660389193U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13822222274464306169U;
            aOrbiterE = RotL64((aOrbiterE * 1723502278319885511U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16307920280681985443U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3505106171801702915U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4987142580981135150U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10336802574069791273U;
            aOrbiterG = RotL64((aOrbiterG * 2670706512498539705U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterH, 6U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 50U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + aNonceWordE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5538U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 5500U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7562U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 10031U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 39U)) + 1393781663398437180U;
            aOrbiterH = (aWandererG + RotL64(aCross, 10U)) + 17414594746688585273U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 5U)) + 2823888497053071250U;
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 17032631958617884859U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 27U)) + 15222697630461125019U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 15737414920751551780U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 53U)) + 1357196111055783001U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 12U)) + 5315122321649251691U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 19U)) + 7893744655508595974U) + aNonceWordC;
            aOrbiterA = (aWandererD + RotL64(aIngress, 47U)) + 16721939414324611738U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 3444375866323610848U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1825716513674511632U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15582066843912467318U;
            aOrbiterK = RotL64((aOrbiterK * 12765146555943757373U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15673590949193923915U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13887365046280406413U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12730414371734709356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4819112390640821927U;
            aOrbiterC = RotL64((aOrbiterC * 8782547948627685451U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3089925954422937464U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7180179304678622530U;
            aOrbiterD = RotL64((aOrbiterD * 16118051565147747413U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17030269962085008657U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6675917351883004046U;
            aOrbiterF = RotL64((aOrbiterF * 14134335325316949687U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12572022803491077491U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 2801421744689267375U;
            aOrbiterJ = RotL64((aOrbiterJ * 315045745990934023U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4335148696780313055U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12526298573395110141U;
            aOrbiterB = RotL64((aOrbiterB * 11276803410698178607U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6984239833558496091U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12195433952105336808U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8642600547427664495U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6392683095502982341U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18047201953488013325U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16151795290455603489U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 15433458942878109208U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1700365768743794306U;
            aOrbiterA = RotL64((aOrbiterA * 16151638348775286903U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10951473638533187729U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1393781663398437180U;
            aOrbiterG = RotL64((aOrbiterG * 2661447713922232789U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 44U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14941U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 14381U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13957U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((aIndex + 11237U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererJ + RotL64(aIngress, 24U)) + 15920462086654025436U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 37U)) + 487844076858004017U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 51U)) + 14502883786442630566U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 47U)) + 3787107318658233674U) + aNonceWordB;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 28U)) + 12548777544693755491U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 4907309444075181683U) + aNonceWordC;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 18342396700266492072U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 13503051997624242670U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 13U)) + 17845742460521374571U) + aNonceWordI;
            aOrbiterF = (aWandererH + RotL64(aIngress, 35U)) + 8640887211877858169U;
            aOrbiterB = (aWandererA + RotL64(aCross, 53U)) + 5273913123709097537U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17756844173695563883U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 6713055830729302951U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5106468334224035972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10228769728713526172U;
            aOrbiterH = RotL64((aOrbiterH * 9760310686414358435U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7687649520668883142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7757480627354711605U;
            aOrbiterE = RotL64((aOrbiterE * 7222553727737349209U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10876291698508634557U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8149278085586014186U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8577133863470695381U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15592893988925610485U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8639028256640537165U;
            aOrbiterG = RotL64((aOrbiterG * 1880655276432963955U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 475660347892196219U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1903736092401853832U;
            aOrbiterF = RotL64((aOrbiterF * 8486318978769094799U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12463250192809450953U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7253918448601703982U;
            aOrbiterI = RotL64((aOrbiterI * 3821034106528009129U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5171661020093804486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11627344933828324146U;
            aOrbiterA = RotL64((aOrbiterA * 5388047063152043277U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6206801139131132815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9221302203943031377U;
            aOrbiterD = RotL64((aOrbiterD * 12912049016813367241U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1798857939965423979U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 5476854168685641232U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3884216989250294213U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2816659151953455230U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15920462086654025436U;
            aOrbiterB = RotL64((aOrbiterB * 17843161654734820613U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 10U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterG, 27U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aCross, 46U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 60U)) + aOrbiterB) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16518U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20352U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16426U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17377U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 3U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererC + RotL64(aCross, 6U)) + 6243113109470883144U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 47U)) + 3891552123999605832U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 37U)) + 8758797898587019128U) + aNonceWordL;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 47U)) + 1005891374086408851U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 3713426782180050764U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 54U)) + 18358143862391573534U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 27U)) + 17504394029693712404U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 21U)) + 5312729289027417014U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 11U)) + 2560873623431186029U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 51U)) + 16309322822806704211U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 10195513918020652600U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2552116263258744287U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7732784879810980089U;
            aOrbiterJ = RotL64((aOrbiterJ * 15041929399477790999U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16499127570665381507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10890036715535519036U;
            aOrbiterF = RotL64((aOrbiterF * 9065115450010475187U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16288944603478791554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14542766121469312846U;
            aOrbiterH = RotL64((aOrbiterH * 8435383464425875209U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5973595239494084696U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1820492719977197097U;
            aOrbiterI = RotL64((aOrbiterI * 16164917159141304405U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10489529555776381736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6392552206958240484U;
            aOrbiterE = RotL64((aOrbiterE * 11761477994533503307U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 10163241948999404556U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 16054678853554707148U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 10570418210789350091U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 3606021702108590330U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16920568417324295852U;
            aOrbiterB = RotL64((aOrbiterB * 5222656554577625385U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13889995689147406315U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7908387312354285092U;
            aOrbiterC = RotL64((aOrbiterC * 7995682580514280949U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14161911472715334589U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12386100977925313406U;
            aOrbiterK = RotL64((aOrbiterK * 17136336570895231639U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14408470657696841139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7466281699619513012U;
            aOrbiterD = RotL64((aOrbiterD * 2706710684289882025U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11125044052260579351U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6243113109470883144U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17390954549755941181U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 20U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterD, 27U)) + aNonceWordN) + aPhaseFWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 60U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 5U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 51U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterI, 37U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 46U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 21U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26274U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23743U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27081U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23616U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aPrevious, 21U)) + 13204735390996728477U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 3U)) + 851171359595647173U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 16745304202825290723U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 37U)) + 562392736584913979U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + 3244267012529053918U) + aNonceWordK;
            aOrbiterG = (aWandererB + RotL64(aIngress, 57U)) + 17282536111067869133U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 6U)) + 14851130066471729068U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 5256130407952363129U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 2904742485828362001U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 13U)) + 3723346325449225387U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 60U)) + 5344621093694027341U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12919263300833603026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17989801264160996071U;
            aOrbiterB = RotL64((aOrbiterB * 15468293047311883751U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5022175042377172157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16684822380107847758U;
            aOrbiterG = RotL64((aOrbiterG * 2834049270263837537U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2740326510600876682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13981423865219318820U;
            aOrbiterK = RotL64((aOrbiterK * 14593082145080056441U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 231945878229848395U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14139797734944312580U;
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16704102101387552373U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8506734780526852552U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4684566118627414659U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 2774630043988894695U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12490034334296488127U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16765455396278233145U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 545238171291436006U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1023872898002379590U;
            aOrbiterE = RotL64((aOrbiterE * 8626333831510136515U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5065187021047872560U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10391809965648089863U;
            aOrbiterJ = RotL64((aOrbiterJ * 10912471108849550469U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5576919045471579002U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9761904001375034639U;
            aOrbiterC = RotL64((aOrbiterC * 8612901811320541361U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2001472279505185946U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11576457012366242134U;
            aOrbiterA = RotL64((aOrbiterA * 1070815118051466731U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17713147845216099336U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 13204735390996728477U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 10889281795183444943U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 60U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterI, 51U));
            aWandererE = aWandererE + ((((RotL64(aCross, 23U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + aOrbiterK) + RotL64(aOrbiterE, 53U)) + aNonceWordH);
            aWandererK = aWandererK + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterK, 48U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28288U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 31769U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27867U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 32160U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 2974056819475622600U) + aNonceWordA;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 13U)) + 7345051759236356098U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 6U)) + 12738468816846628882U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 7694520596043297922U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 35U)) + 5530753590015084774U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 3776309161718383105U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 60U)) + 784780304358106404U) + aNonceWordM;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 53U)) + 8999942326995036509U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 51U)) + 5194986506064092779U;
            aOrbiterA = (aWandererG + RotL64(aCross, 39U)) + 7920040007459652762U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 11311997270710107937U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5365231114813547251U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8630110234623825263U;
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2358235238039571072U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18059414891616491807U;
            aOrbiterB = RotL64((aOrbiterB * 17150786106857185467U), 41U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 14526050556461782864U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6937282036603272474U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14954512365270028029U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10105832250694931310U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3884223553012098137U;
            aOrbiterG = RotL64((aOrbiterG * 16340956813003906195U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 10385284339549648087U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1257633893341505930U;
            aOrbiterD = RotL64((aOrbiterD * 2669950791270500977U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5528890519572824318U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15664241747527713256U;
            aOrbiterF = RotL64((aOrbiterF * 16670884497088220497U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 14264122979415331887U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17985061405540198036U;
            aOrbiterA = RotL64((aOrbiterA * 2729487440173395133U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1663986734997903415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3706166884286400587U;
            aOrbiterI = RotL64((aOrbiterI * 10549736618301955745U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12736963182099961466U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 95411267612114381U;
            aOrbiterK = RotL64((aOrbiterK * 8011937916302325057U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4966620136499917388U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8478316876240452401U;
            aOrbiterE = RotL64((aOrbiterE * 13297718919105366563U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11123814701411614557U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2974056819475622600U;
            aOrbiterH = RotL64((aOrbiterH * 5913569942407618997U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 3U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 12U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 41U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterH, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Cricket_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 552U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[((aIndex + 361U)) & W_KEY1], 6U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5731U)) & W_KEY1], 11U) ^ RotL64(mSource[((aIndex + 8186U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 14U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 6916817163240024692U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aScatter, 60U)) + 14554930751292077817U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 41U)) + 1098305064484336101U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 11U)) + 12192821172420471527U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 53U)) + 2435134991707318845U) + aPhaseCOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 1896745368738512624U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 19U)) + 1114996424222923873U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 34U)) + 9839135798371512656U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 8037967239603177043U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 15185468738487237432U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4912098316394854543U;
            aOrbiterH = RotL64((aOrbiterH * 3072785550384399929U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13142688607850380888U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4507379759608945839U;
            aOrbiterK = RotL64((aOrbiterK * 2989332387754215967U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7299006009652289342U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5390655277207053627U;
            aOrbiterA = RotL64((aOrbiterA * 10973744708856143715U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6744737023577785725U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15539737698867067285U;
            aOrbiterJ = RotL64((aOrbiterJ * 4686092035261336911U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13329866734681377952U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13284937458969166257U;
            aOrbiterF = RotL64((aOrbiterF * 3965985432462699445U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8695002088915702168U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3858059421620839286U;
            aOrbiterD = RotL64((aOrbiterD * 9559783727301092937U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6609163873243179836U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9416165620556710540U;
            aOrbiterC = RotL64((aOrbiterC * 240385043740268229U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1578449067529000433U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14309000104419489303U;
            aOrbiterB = RotL64((aOrbiterB * 7599078306153684729U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15785180680737461320U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10099222679918382021U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2012232597046182581U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 26U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterF, 14U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterH, 18U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 18U) + RotL64(aOrbiterD, 57U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9518U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13793U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13511U)) & W_KEY1], 22U) ^ RotL64(aKeyRowReadB[((aIndex + 14095U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 41U)) + 4622023259121087483U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 27U)) + 10253505250223501352U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 51U)) + 17133877904420462669U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 4U)) + 6162827793741796700U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 57U)) + 9610986424765907615U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 11210747154264753754U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 16554205219580654546U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 10352576357413766388U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 12U)) + 3651845783283479752U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18145542190463500476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5415609566767162857U;
            aOrbiterD = RotL64((aOrbiterD * 6474184559323816389U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2033734872464201570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3507213117125813345U;
            aOrbiterA = RotL64((aOrbiterA * 5453058336688881113U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8716253393049851856U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 695984869565941856U;
            aOrbiterG = RotL64((aOrbiterG * 8377921610764044735U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7661578828878284931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 906654265099155956U;
            aOrbiterI = RotL64((aOrbiterI * 8117625377607536949U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6050049984731254612U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 17882717590338190821U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10807367411402733215U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4996521991532815957U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4246460672800604436U;
            aOrbiterE = RotL64((aOrbiterE * 12047466401960824903U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8700148116452518842U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10039050281847466206U;
            aOrbiterJ = RotL64((aOrbiterJ * 11884791271239660157U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 4513844680425845372U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3037563127442815153U;
            aOrbiterK = RotL64((aOrbiterK * 18363509277992292407U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1005237931570968724U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1373258132025712065U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10458020799382532395U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 24U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 51U)) + aOrbiterA) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 34U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 39U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterA, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterA, 28U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererH, 20U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22903U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19872U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20554U)) & W_KEY1], 22U) ^ RotL64(aKeyRowReadB[((aIndex + 21415U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 51U)) + 15726877954695761686U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 28U)) + RotL64(aCarry, 27U)) + 14187652171881943587U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 43U)) + 8420423151313882782U) + aPhaseCOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aCross, 5U)) + 14942322692433259283U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 47U)) + 7272331475919796255U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 57U)) + 154504365041805840U) + aPhaseCOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 34U)) + RotL64(aCarry, 57U)) + 17475491222554948786U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 5759181483165339605U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 13U)) + 5993060214499322845U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10901786237875941844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17135786595614068473U;
            aOrbiterC = RotL64((aOrbiterC * 15923538730142047043U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5208202073886811165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6821452921018900631U;
            aOrbiterI = RotL64((aOrbiterI * 13119330055184115669U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13348064837402206969U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8967943922403445136U;
            aOrbiterG = RotL64((aOrbiterG * 300168481725373093U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8130283784171430891U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6351113882502502876U;
            aOrbiterB = RotL64((aOrbiterB * 15960622823993072903U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6894708729226455769U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 12065058511247133944U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5432601727436935831U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17138279326229372741U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12987698199066890628U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12665716655177320977U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13688833537574196675U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4211971980434000618U;
            aOrbiterK = RotL64((aOrbiterK * 1374411763361518851U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10376917117582537592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4807742522197923516U;
            aOrbiterE = RotL64((aOrbiterE * 15257251453302090961U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 18038296468177121243U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6879666349379745258U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15819475269715810555U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 50U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + aPhaseCWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterI, 44U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterB, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29341U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 25071U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27512U)) & S_BLOCK1], 30U) ^ RotL64(mSource[((aIndex + 26317U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 24U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 35U)) + 11039986441331892533U;
            aOrbiterH = (aWandererK + RotL64(aCross, 23U)) + 6256024955965426119U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 4U)) + RotL64(aCarry, 27U)) + 9857443189988995666U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 39U)) + 11900944813380998208U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 43U)) + 8422577734978875541U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 47U)) + 3100835100713928724U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 51U)) + 11871553509810206993U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 17614749493763417027U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 3638372131856199916U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6582275259281025770U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17016882418498941958U;
            aOrbiterC = RotL64((aOrbiterC * 4269869255230867823U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 1747214688658984715U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9356088987044015278U;
            aOrbiterD = RotL64((aOrbiterD * 16221733545319753695U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4056238112133473456U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16013150119949532998U;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16076621211111834889U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9940824359571581765U;
            aOrbiterF = RotL64((aOrbiterF * 11624767861336495331U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15624084004784515753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7630989544834680335U;
            aOrbiterG = RotL64((aOrbiterG * 12261063237156822067U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 18003586430673313786U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1654118743290334161U;
            aOrbiterE = RotL64((aOrbiterE * 1153250137357176071U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3254189676528343910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15629083361573065165U;
            aOrbiterA = RotL64((aOrbiterA * 17024833368570949107U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10056859810555674806U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15976683222786846254U;
            aOrbiterB = RotL64((aOrbiterB * 2801754232182942635U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11872378594829637933U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7633773773528713489U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8218288492011593353U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + aPhaseCWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 34U) + RotL64(aOrbiterD, 58U)) + aOrbiterC) + aPhaseCWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 29U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterE, 48U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Cricket_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3107U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 1713U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1982U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 932U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererH + RotL64(aIngress, 3U)) + 12980104182836602177U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 3172622203188863995U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 14U)) + 1170974132219980203U) + aPhaseDOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 6035201940965047490U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 18033907118424996722U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 14604813424800580304U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 13720232492851066035U;
            aOrbiterD = RotL64((aOrbiterD * 8927246214721284759U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3902659710585257448U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8331560652661619868U;
            aOrbiterB = RotL64((aOrbiterB * 11418103770615560205U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4485014147538689794U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 168202636924512424U;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16227825670092707848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4792781933944671365U;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12636865372722601282U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18198291399585556632U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18155803890313399795U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 58U) + aOrbiterH) + RotL64(aOrbiterF, 3U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 22U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12589U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 9990U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15212U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10452U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 44U)) + RotL64(aCarry, 57U)) + 2225397913940961213U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 11U)) + 8342544893601343643U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 162922186381417187U) + aPhaseDOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 11660218373710972210U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 3U)) + 14909034764605802354U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16776955237009701511U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 5834487809188925253U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4458820879204327709U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1498492772767040320U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4161765458781579617U;
            aOrbiterJ = RotL64((aOrbiterJ * 15535994410289065281U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10511923076962447765U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8575954471692620021U;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6536325446331340573U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1790628986900286346U;
            aOrbiterH = RotL64((aOrbiterH * 5262997114200816715U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2623814807619278590U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11676970995834706612U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10057461115132434901U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterE, 58U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterE, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18953U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19116U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19150U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17435U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 42U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 13499155707765393469U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 3U)) + 3740324981823726185U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 44U)) + RotL64(aCarry, 41U)) + 5470765363949735652U) + aPhaseDOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 3446436171274452326U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 27U)) + 1778929412631211933U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14666308799855220954U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4548410236791175055U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6822908616815218501U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 5829739767694190372U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14319231414903675748U;
            aOrbiterE = RotL64((aOrbiterE * 4966501102515775601U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1513851750246111405U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1685620217748986019U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9286548037413609445U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16284162182006054402U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6271539598462003309U;
            aOrbiterB = RotL64((aOrbiterB * 13923286694131331137U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12669312437565969473U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11894755313393001665U;
            aOrbiterK = RotL64((aOrbiterK * 12556759675372354075U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 56U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterE, 56U)) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28711U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30181U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32026U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 29896U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 41U)) + 1142447269198373880U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 10581460640040336191U) + aPhaseDOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 28U)) + 14703062773878202900U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 15737525756286914746U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 16178774478273186999U) + aPhaseDOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2514897053906809160U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13702496607592508464U;
            aOrbiterG = RotL64((aOrbiterG * 16540143680974064057U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18030885275418337965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5241783876161655984U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10970981186787227937U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2807052676283587925U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8022804576763271327U;
            aOrbiterH = RotL64((aOrbiterH * 11727096043219370577U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15597099852232205860U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 1538435607932096400U;
            aOrbiterJ = RotL64((aOrbiterJ * 7900752511710516981U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11147868774413615365U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9325213746830411568U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 561819005818948769U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 46U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterC) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterK, 44U)) + aPhaseDWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_Cricket_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5510U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4743U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2421U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((aIndex + 46U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 42U)) + (RotL64(aPrevious, 29U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (aWandererC + RotL64(aCross, 11U)) + 14823268998003220191U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 15295237288788213847U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 16434853402001133899U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 46U)) + 7555911304407871631U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 14977248264994834620U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 37U)) + 9707764144919392380U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + 1277304385464681529U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 3089786220465849395U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3700503853358695085U;
            aOrbiterB = RotL64((aOrbiterB * 2079089949442685421U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3240054112993517371U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16897532076915366859U;
            aOrbiterH = RotL64((aOrbiterH * 4120874717534309035U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18167359289798364307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8870819278575769863U;
            aOrbiterF = RotL64((aOrbiterF * 9334066154398059075U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15363069206212330251U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14858164441499725158U;
            aOrbiterI = RotL64((aOrbiterI * 14931933411393847915U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5357144808788707522U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2910681277417754860U;
            aOrbiterA = RotL64((aOrbiterA * 13170868582159347059U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9824408699018165151U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 368370224788793300U;
            aOrbiterE = RotL64((aOrbiterE * 14358982366258729959U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7095398304588825115U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11418879758164313554U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5983520332639771791U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 44U) + aOrbiterH) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterF, 36U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 22U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12652U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 8906U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14977U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14295U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 3U)) + 11521331427196538632U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + 16653824187682957632U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 11654676587350088289U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 47U)) + 8010313317412193584U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 1108775560502907471U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 54U)) + 243952321439823521U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 2324945800401240403U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9257554497543369657U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16701314607244592540U;
            aOrbiterK = RotL64((aOrbiterK * 8790054741039817107U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3900445848034341782U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7652316487347103658U;
            aOrbiterI = RotL64((aOrbiterI * 11480123491361589799U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14980368605272070578U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2001165460948764796U;
            aOrbiterE = RotL64((aOrbiterE * 8110980921827107649U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1911044015666991050U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11366207111147818339U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17234439040652553865U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16469329744002456607U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8062793687044950815U;
            aOrbiterG = RotL64((aOrbiterG * 5856142259851144369U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15364721421972807872U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8979915611483540231U;
            aOrbiterJ = RotL64((aOrbiterJ * 10899377466171153383U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7654234623563110457U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1526832460342135008U;
            aOrbiterA = RotL64((aOrbiterA * 12766083052650723051U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 12U) + aOrbiterG) + RotL64(aOrbiterE, 47U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 12U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 35U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22829U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 22968U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21096U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22931U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 50U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 51U)) + 17912271996338180948U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 18U)) + RotL64(aCarry, 57U)) + 13259276608841847058U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 11U)) + 16225936008657276089U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 2243058962151834071U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 27U)) + 10637439274127347861U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 37U)) + 15312219216405992627U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 2393933972129878613U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4327069337247976513U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8307656353434167837U;
            aOrbiterK = RotL64((aOrbiterK * 11386588389133096705U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17299145556933889336U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14458100581172798164U;
            aOrbiterA = RotL64((aOrbiterA * 16543734663677070509U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 6410095654927998067U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6168964796264687686U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16218071040190475953U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3667999465041020730U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 16021552859323602007U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6427266472526362663U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12941668202330045095U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4222032891850449934U;
            aOrbiterI = RotL64((aOrbiterI * 17292856787431308097U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1346342592002730785U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16860611785008118820U;
            aOrbiterC = RotL64((aOrbiterC * 384963420804756607U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3193572711804730241U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5866881282680588589U;
            aOrbiterD = RotL64((aOrbiterD * 9226331800853634597U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterD, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 20U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 4U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32501U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26823U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32306U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneD[((aIndex + 28114U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aScatter, 19U)) + 12632404972795375757U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 5351879979055988456U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 3597737727467443413U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 11U)) + 2830846754917852318U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 29U)) + 17311925960294518018U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 4U)) + 2083584640523695383U;
            aOrbiterG = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 15049343611387010158U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6443050378205811147U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6021965178697344070U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6054064448935006741U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5080289878758029976U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 576927745306972983U;
            aOrbiterC = RotL64((aOrbiterC * 16008958833683246115U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4728489691382690859U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6184355840165758855U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1515043910404156423U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11220539885798595450U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11091438724966718214U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8225347114759391961U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17184210490020062419U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2150997767099116408U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8058553821648892499U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7021953562676903717U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17159676348343312834U;
            aOrbiterJ = RotL64((aOrbiterJ * 13877284519668483549U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10367891770525239784U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11922478487264201233U;
            aOrbiterG = RotL64((aOrbiterG * 9195137452661956029U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterF, 21U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 42U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Cricket_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2464U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 6440U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5853U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 5543U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 898812731947995389U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 8677347622525527167U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 770321564027567654U) + aPhaseFOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 58U)) + 11020474858081526395U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 43U)) + 17289793580414993470U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10111912559295118444U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8083622125544542011U;
            aOrbiterC = RotL64((aOrbiterC * 3610772128071340341U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7149858558922988240U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 5919683821379905699U;
            aOrbiterG = RotL64((aOrbiterG * 16705119888884231567U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6860902846079238714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15083517836867542075U;
            aOrbiterK = RotL64((aOrbiterK * 4686657139237578325U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14852868368708376381U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9860233289028878323U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13418143547952204667U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 772406119079116272U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 7971141501337627589U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10168120622976358617U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 30U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 58U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 39U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14799U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14618U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11904U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 12652U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 53U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 4970414922752555648U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 41U)) + 9462756592787669327U;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 4U)) + RotL64(aCarry, 41U)) + 3948790686662213095U) + aPhaseFOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 14542857212241578311U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 13U)) + 3387479009827029547U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1411421370057797877U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16894451466895681236U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13825974818858676215U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12727136462290223542U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4625389198191960525U;
            aOrbiterF = RotL64((aOrbiterF * 5726474430977810191U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3471881403786164913U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6433115856048534831U;
            aOrbiterA = RotL64((aOrbiterA * 9363233870194144053U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9825592965466157982U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1553125767261293088U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 411535191177308781U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9951616357109647617U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11231080382787286889U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14024961994986659187U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterK, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 18U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21049U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 23148U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23047U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneC[((aIndex + 19266U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 22U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 3255291173184001106U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 15308468160116255528U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aCross, 41U)) + 18186972408589866656U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 4439324265978331914U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 13099263173016322486U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7041561081767500660U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6196422612687812971U;
            aOrbiterA = RotL64((aOrbiterA * 13359900204297781063U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7664260932541281413U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17802347823020441056U;
            aOrbiterD = RotL64((aOrbiterD * 2220679459017369255U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4253107484061190446U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13799496534030645312U;
            aOrbiterC = RotL64((aOrbiterC * 9167675060053848207U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14252892847595951926U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5663527578664291422U;
            aOrbiterB = RotL64((aOrbiterB * 18314294235895182465U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11148755959699137661U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17036900929333594592U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16041243617369003291U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterH, 26U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererG = aWandererG + ((((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30713U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 27325U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31969U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30742U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 52U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 37U)) + 9107326720193244489U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 10868585484401664145U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 13637736741437846622U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 53U)) + 6130725216183918844U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 13U)) + 2063834478521338187U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8564870627911949158U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6524015751064086390U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12055267995727104463U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 9874937766875388236U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14723718409522680894U;
            aOrbiterJ = RotL64((aOrbiterJ * 17379140128833323431U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 13767059954741528279U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6387608251033722169U;
            aOrbiterK = RotL64((aOrbiterK * 6601902195707980693U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5391425980008431000U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11524218415655093779U;
            aOrbiterF = RotL64((aOrbiterF * 12508457981779189389U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 155510463350385905U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10554591788433641311U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5412084824127934293U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 56U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Cricket_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6562U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((aIndex + 5760U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3543U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 5486U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 3U)) + 9023059520606551446U) + aPhaseGOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 662441755115638133U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 16957253361196144712U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 19U)) + 7840955025765308605U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 39U)) + 346855809270395799U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16099139781586668343U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3706457327118322098U;
            aOrbiterE = RotL64((aOrbiterE * 7810030620470889591U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 12166825885547622870U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7792658665720344200U;
            aOrbiterC = RotL64((aOrbiterC * 16305542632794270697U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7128477606152986326U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 11116533962780290084U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11993485572912492297U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10443889548568288532U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4402387036946561017U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9032964741841833277U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13002706161178447654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 13929727277530310708U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7005639090871200285U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 48U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 9901U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11648U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8883U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11731U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 7270044678408187242U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 10192278965379756766U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 13U)) + 17568666746676060748U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 21U)) + 14312927531124963037U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 19U)) + 9825825726152087706U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9696778570255265896U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17657841352013417228U;
            aOrbiterJ = RotL64((aOrbiterJ * 17562220176018833833U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 16207815085909628439U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1752979206374514227U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14182667540650694199U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10456310689643905854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16127830548663742550U;
            aOrbiterI = RotL64((aOrbiterI * 4355938404839045417U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 2940917376003930842U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7353596864777649953U;
            aOrbiterE = RotL64((aOrbiterE * 7499468723171042005U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12725092740446150705U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5791296650856037010U;
            aOrbiterF = RotL64((aOrbiterF * 760379251950502133U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aPhaseGWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterC, 3U));
            aWandererI = aWandererI + ((((RotL64(aCross, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterI, 58U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 22639U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((aIndex + 24450U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17482U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16763U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 52U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 479672811032092393U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + 18061121631394564425U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 52U)) + 14237400452740566065U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 6723123812257706134U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 4247997188026499248U) + aPhaseGOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1939107415066134869U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3912640123546395979U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9779626695085572877U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8295478436553964298U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3218960600711526885U;
            aOrbiterJ = RotL64((aOrbiterJ * 15443507655470278069U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 5874096203353388890U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10294536533673023358U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15561710414949058923U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11268561953904130747U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16693201256788898423U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16291987237693567209U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 7550969634681894654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9501647424602245869U;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 4U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 12U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aPhaseGWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28003U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32758U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31932U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26306U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 60U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 15045917390223766480U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 10763054007033668758U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aCross, 3U)) + 13190170142593666607U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 40U)) + RotL64(aCarry, 35U)) + 9657025731441167065U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 19U)) + 11433367178975954211U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17904920143996810366U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3244383020512113283U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 552521443123433353U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 6538815775171139091U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 7195368312757976343U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10515679176134176565U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 18134430713910279374U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6571776588427107976U;
            aOrbiterK = RotL64((aOrbiterK * 11916502085252589161U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11830778129647517758U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2287235876793192036U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8951959188326141794U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9968356718110753845U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 40U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 38U) + RotL64(aOrbiterI, 26U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterD) + aPhaseGWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Cricket_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4155U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2353U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6399U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 6440U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 21U)) + 11039986441331892533U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 35U)) + 6256024955965426119U) + aPhaseHOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 39U)) + 9857443189988995666U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 12U)) + 11900944813380998208U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 8422577734978875541U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3100835100713928724U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11871553509810206993U;
            aOrbiterE = RotL64((aOrbiterE * 15501681886909921677U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17614749493763417027U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3638372131856199916U;
            aOrbiterF = RotL64((aOrbiterF * 480683274898147025U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6582275259281025770U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 17016882418498941958U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4269869255230867823U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1747214688658984715U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9356088987044015278U;
            aOrbiterG = RotL64((aOrbiterG * 16221733545319753695U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4056238112133473456U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16013150119949532998U;
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 56U)) + aOrbiterG) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 29U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10902U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 10366U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12903U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14297U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererA + RotL64(aCross, 12U)) + 1042610313571524121U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 3505725321008825582U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 12584654563843782991U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 6645399144515770935U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 21U)) + 3608978423753715584U) + aPhaseHOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8089198857670370983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15207251813516399879U;
            aOrbiterI = RotL64((aOrbiterI * 7596841660069752069U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 9579268660105824516U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16055044469473802812U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2269649280637188723U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 583811872609805949U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7027491967970873942U;
            aOrbiterK = RotL64((aOrbiterK * 12686754713465826139U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18256061823189677508U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12708429127816136937U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12593886633108075321U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 12169216645156306078U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12694325407567795065U;
            aOrbiterE = RotL64((aOrbiterE * 3711789483877261899U), 19U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 27U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterE, 46U)) + aPhaseHWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 23156U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 24067U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22392U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18284U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 44U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 13U)) + 17470880031634374199U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 757565846006937746U) + aPhaseHOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 38U)) + 9419282475801345674U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 2014248014107898196U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 15113928519446490441U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 7346126964886259935U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5594123113093162359U;
            aOrbiterE = RotL64((aOrbiterE * 18043634828891483403U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5659237263369402005U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11565709683423969703U;
            aOrbiterK = RotL64((aOrbiterK * 16731289017588574671U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16782863743534856287U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13499100900072115907U;
            aOrbiterF = RotL64((aOrbiterF * 5567729598873214433U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11414447651044205242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7545993795121430538U;
            aOrbiterC = RotL64((aOrbiterC * 10758488381206257261U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 11778229237616454988U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2544793391976514665U;
            aOrbiterI = RotL64((aOrbiterI * 4021060413798523299U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 10U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aCross, 22U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30902U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27897U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27572U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26546U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 2101601659597850213U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 37U)) + 2759794072560720121U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 9443562552411269339U) + aPhaseHOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 5U)) + 10801360546699857975U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 35U)) + 8020716394829332019U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1021894212367773801U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13346855534622490176U;
            aOrbiterI = RotL64((aOrbiterI * 12668950387932320985U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16359309548462953836U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12642446944680783519U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12197935153255283321U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8197424982767553380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14346334610901859094U;
            aOrbiterG = RotL64((aOrbiterG * 16982899923227935679U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14171304260534233539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 334531601308283605U;
            aOrbiterD = RotL64((aOrbiterD * 5012968232749075075U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10707856298471572695U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 18364775750091914766U;
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererF = aWandererF + ((((RotL64(aCross, 48U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 23U));
            aWandererK = aWandererK + ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
