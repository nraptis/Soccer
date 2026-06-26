#include "TwistExpander_Hockey_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Hockey_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD09E45CE94ED0605ULL + 0xF54680BCCDEFEA0BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93BF48B1350DB037ULL + 0x9576F2852DAFD025ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB814E458701E96D5ULL + 0xD41A39D0CBF66090ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA1782AC12907A3BFULL + 0x9DD4F2BD64714DC7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8F5B49008367EAC1ULL + 0xA058FCFE7F88AA27ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF4FA6E021607BDCBULL + 0xF37507FEB2BE3989ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD4FE096A81CCD871ULL + 0xFADE548D32491250ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDFBA21F99B73EB2BULL + 0xF054A385339B36C5ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 12U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordA, 29U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1787U)) & S_BLOCK1], 41U) ^ RotL64(mSnow[((aIndex + 3272U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordB, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3393U)) & S_BLOCK1], 54U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 2545U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 4U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aCross, 41U)) + 13278949403988203974U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 43U)) + 9213599924054673756U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 27U)) + 1255746482932381798U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 57U)) + 11575321997144516122U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 20U)) + 15881587525529432437U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 9846195809864862707U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 12319815691858217670U) + RotL64(aNonceWordD, 49U);
            aOrbiterA = ((aWandererF + RotL64(aScatter, 37U)) + 16322617427294439587U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 46U)) + 16332130810525887437U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 47U)) + 4920951156015336794U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 23U)) + 16767126455124552329U) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12553595911087945223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1437522202135436142U;
            aOrbiterG = RotL64((aOrbiterG * 2001992794165550905U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12313100454852227143U) + RotL64(aNonceWordC, 3U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2761983020631055729U;
            aOrbiterI = RotL64((aOrbiterI * 3874839760378039509U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17635303588421554367U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 788212489507463763U) ^ RotL64(aNonceWordG, 7U);
            aOrbiterE = RotL64((aOrbiterE * 17896475584538528059U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5192552894670654434U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6784748488807738811U;
            aOrbiterC = RotL64((aOrbiterC * 8077237651953896479U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 16113417046719114943U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1096874945215225916U;
            aOrbiterK = RotL64((aOrbiterK * 17308604412622879833U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 7610274704570171595U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10466070212284342550U;
            aOrbiterB = RotL64((aOrbiterB * 6449728258497920613U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6777845928873855221U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5251515022021984126U;
            aOrbiterD = RotL64((aOrbiterD * 9018277343404261611U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13849343158824111498U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7977711210181714021U;
            aOrbiterJ = RotL64((aOrbiterJ * 4182053966171053577U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6494539818728106982U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11314590450226080781U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12455979257225599157U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 552687702594328012U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 14961304171192292246U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 846375892915484717U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9771874402848476494U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13278949403988203974U;
            aOrbiterF = RotL64((aOrbiterF * 2119203863777871233U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 54U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 18U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterH, 21U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + RotL64(aNonceWordE, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterG, 5U)) + RotL64(aNonceWordH, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 8702U)) & S_BLOCK1], 46U) ^ RotL64(mSnow[((aIndex + 6790U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordH, 46U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6576U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 10246U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aScatter, 30U)) + RotL64(aCarry, 43U)) + 17936518874386450467U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 37U)) + 13722737841589910344U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 41U)) + 11774969167948715796U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 39U)) + 3640101505680493777U) + RotL64(aNonceWordH, 35U);
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + 1369495382725650822U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 11827310354654653345U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 34U)) + 186037671377175394U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 11428829344234627340U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aIngress, 11U)) + 2275016369870029068U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 5U)) + 15471646673734798328U) + RotL64(aNonceWordG, 45U);
            aOrbiterH = (aWandererI + RotL64(aCross, 13U)) + 12172082573115640145U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6626736341348283154U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12220614992483863623U;
            aOrbiterD = RotL64((aOrbiterD * 8137086205714097487U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13157102324253760215U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4143587482368093601U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterJ = RotL64((aOrbiterJ * 5060677690991506895U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11007575246013796426U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11721585930088637162U;
            aOrbiterI = RotL64((aOrbiterI * 15009627907125738519U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5720789204450196217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3094696226821431648U;
            aOrbiterE = RotL64((aOrbiterE * 4412033981712165541U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14675830108100986773U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9444071495289719645U;
            aOrbiterG = RotL64((aOrbiterG * 10983136361953366557U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5106753847015199956U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7585421898593510010U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 140996914192351011U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11746948407655524690U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16336323220286344483U;
            aOrbiterB = RotL64((aOrbiterB * 6590417628835864497U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8030445186765781136U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 276034088015165891U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordD, 57U);
            aOrbiterK = RotL64((aOrbiterK * 7626025612710225099U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8116955322602209153U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5704503350608834450U;
            aOrbiterF = RotL64((aOrbiterF * 7049558959583832449U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8063875087087055875U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1111816778196345760U;
            aOrbiterC = RotL64((aOrbiterC * 13820440198677609571U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7702895879089714461U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17936518874386450467U;
            aOrbiterH = RotL64((aOrbiterH * 12767279443267850009U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterE, 35U)) + RotL64(aNonceWordC, 38U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 22U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + RotL64(aOrbiterG, 13U)) + aOrbiterK) + RotL64(aNonceWordF, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 29U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordH, 47U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 15361U)) & S_BLOCK1], 35U) ^ RotL64(mSnow[((aIndex + 11073U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12835U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13314U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 57U)) + 1364174714924216027U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 6U)) + 13561796874229506613U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 11845572344206238305U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 37U)) + 15762708240326773763U) + RotL64(aNonceWordC, 53U);
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 1157119665207900473U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 6823546624372055260U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 48U)) + RotL64(aCarry, 19U)) + 14465564210523945121U) + RotL64(aNonceWordA, 59U);
            aOrbiterI = (aWandererD + RotL64(aIngress, 27U)) + 10667464548080807531U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 11U)) + 13445737493224316575U;
            aOrbiterB = (aWandererB + RotL64(aCross, 43U)) + 3009837893785957665U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 3U)) + 2886920524111083752U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10886177449328249656U) + RotL64(aNonceWordD, 13U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15067759884678100433U;
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 18307930462682331536U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8791864377579255801U;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 805797468642992351U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5743305867058244964U;
            aOrbiterD = RotL64((aOrbiterD * 16263000753351131717U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17102025528234481273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 1841579177327486899U;
            aOrbiterC = RotL64((aOrbiterC * 3841603385577825265U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2189493507896508972U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 18209567010094914374U;
            aOrbiterI = RotL64((aOrbiterI * 3737080408976852351U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6697069234216868330U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 927471474577415372U;
            aOrbiterB = RotL64((aOrbiterB * 10680760991009199309U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13155854301197725408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1014625081915435892U;
            aOrbiterA = RotL64((aOrbiterA * 11592754232949990435U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12697209921410914931U) + RotL64(aNonceWordB, 36U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 11555096613655648647U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4598821388864997089U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9335308231651271690U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3160859883353473444U;
            aOrbiterJ = RotL64((aOrbiterJ * 4753600703924906409U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 15681189182414315768U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3147692210581710663U;
            aOrbiterG = RotL64((aOrbiterG * 6271949093080510861U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5373388632562432117U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1364174714924216027U;
            aOrbiterE = RotL64((aOrbiterE * 4694926665965807945U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 18U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 11U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterI, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordG, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 24U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 53U)) + aOrbiterE) + RotL64(aNonceWordF, 45U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterC) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 57U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordG, 28U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 20124U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20755U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 50U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16870U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 20589U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 41U)) + 13714409587461539863U) + RotL64(aNonceWordH, 39U);
            aOrbiterE = (aWandererC + RotL64(aPrevious, 37U)) + 14101156723903265839U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 13U)) + 7063754562895369001U;
            aOrbiterC = (aWandererI + RotL64(aCross, 6U)) + 12320578575245519386U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 11744826789631008424U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 8744816505096675597U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 10405435520084528645U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 1463157688070683543U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 10U)) + 12379603577919617703U) + RotL64(aNonceWordB, 21U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 3U)) + 1343439118031348146U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 23U)) + 16118850268070235540U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14116264435819277136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterG = RotL64((aOrbiterG * 1495818611622063967U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14806408656041403829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11569345414052398227U;
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17063874769147888574U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9927420478679581917U;
            aOrbiterF = RotL64((aOrbiterF * 9042782809534196563U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2550285599827162167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17801534123304996448U;
            aOrbiterH = RotL64((aOrbiterH * 2160836889363614721U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6456685241021762041U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17064208177372969289U;
            aOrbiterD = RotL64((aOrbiterD * 13726627607233302493U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 18279938244131982650U) + RotL64(aNonceWordG, 37U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8211002229712129419U;
            aOrbiterA = RotL64((aOrbiterA * 12931373380977640645U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12795832560781931767U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 286378504074349650U;
            aOrbiterB = RotL64((aOrbiterB * 85453101173293509U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 5835304250436889513U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 12704972686724379659U) ^ RotL64(aNonceWordE, 27U);
            aOrbiterI = RotL64((aOrbiterI * 1198789639656336053U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12555700587254295099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6740149669657971715U;
            aOrbiterJ = RotL64((aOrbiterJ * 9376048577305482691U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 1541392147096889431U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16891341703173286949U) ^ aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 697452963711223355U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8811637585092392653U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13714409587461539863U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2578939920876994763U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterI, 48U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + ((RotL64(aIngress, 26U) + aOrbiterK) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 24U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 37U)) + RotL64(aNonceWordA, 22U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 56U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aNonceWordF, 49U)) + aWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererI, 34U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordA, 52U)) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 27176U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 22674U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 52U) ^ RotL64(aNonceWordD, 43U)) ^ RotL64(aNonceWordF, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24316U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25116U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aCross, 3U)) + 479672811032092393U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 13U)) + 18061121631394564425U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 5U)) + 14237400452740566065U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 11U)) + 6723123812257706134U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 4247997188026499248U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 41U)) + 1939107415066134869U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 3912640123546395979U) + RotL64(aNonceWordC, 58U);
            aOrbiterA = (aWandererB + RotL64(aScatter, 51U)) + 8295478436553964298U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 27U)) + 3218960600711526885U;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 35U)) + 5874096203353388890U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterF = (aWandererH + RotL64(aIngress, 48U)) + 10294536533673023358U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11268561953904130747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16693201256788898423U) ^ RotL64(aNonceWordG, 11U);
            aOrbiterC = RotL64((aOrbiterC * 16291987237693567209U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7550969634681894654U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9501647424602245869U;
            aOrbiterK = RotL64((aOrbiterK * 11265865222096866605U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8881869255994319423U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16770136406906800016U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1782039587385512923U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16185384746435761363U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13841034186650721627U;
            aOrbiterE = RotL64((aOrbiterE * 12000155593277035447U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15229062695864608309U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3576122704615303733U;
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13898167174453181224U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12878032061609524049U;
            aOrbiterD = RotL64((aOrbiterD * 18104665741338251495U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12719156051299028649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8640980843376950769U;
            aOrbiterG = RotL64((aOrbiterG * 10242616778390983333U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12133332160916004365U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8743563985229104484U;
            aOrbiterJ = RotL64((aOrbiterJ * 4575129690615054691U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7362223873479167793U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4230720394788635807U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3658720603716856293U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5095842824285329272U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7483469517256234638U) ^ RotL64(aNonceWordH, 43U);
            aOrbiterI = RotL64((aOrbiterI * 9782114499878763883U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17426017004856399653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 479672811032092393U;
            aOrbiterB = RotL64((aOrbiterB * 14921028515589317919U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 52U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterH, 60U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 53U)) + aOrbiterG) + RotL64(aNonceWordD, 7U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + RotL64(aOrbiterG, 41U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 48U)) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 51U)) + RotL64(aNonceWordA, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 26U) + RotL64(aOrbiterJ, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordC, 37U)) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 31853U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 31042U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordA, 24U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31039U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 30278U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 12U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 7948891781097675369U) + RotL64(aNonceWordA, 37U);
            aOrbiterB = (aWandererA + RotL64(aPrevious, 43U)) + 13928362874228230226U;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 27U)) + 10776180542602258926U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + 5735115172149470447U) + RotL64(aNonceWordF, 41U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 23U)) + 5353591822981766987U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 562301708107268570U) + aOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 10467810247578364868U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 60U)) + 14541630141152308564U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 37U)) + 2350076897065139429U;
            aOrbiterG = (aWandererF + RotL64(aCross, 3U)) + 17519109078651162228U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 53U)) + 6061035173339902910U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15654836633731000065U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13723521735153718904U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterJ = RotL64((aOrbiterJ * 14459516479283070563U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 2849680038315532197U) + RotL64(aNonceWordD, 61U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17336102435576647923U;
            aOrbiterE = RotL64((aOrbiterE * 10984689101753586739U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8759060657343458985U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11009137869375286581U;
            aOrbiterH = RotL64((aOrbiterH * 8741417343929809115U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15792999392743144135U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6180808423175992479U;
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 361487389591183005U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15292753806514404853U;
            aOrbiterK = RotL64((aOrbiterK * 17478232597253311153U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14929153438443362045U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7904556383593914086U;
            aOrbiterG = RotL64((aOrbiterG * 2484130486635511403U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3793180909904286848U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10391957637467171320U;
            aOrbiterF = RotL64((aOrbiterF * 505484041943467117U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11648765065563798353U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17601185776537566611U;
            aOrbiterD = RotL64((aOrbiterD * 4753179291885740011U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2907499704986356444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17048858067202291241U;
            aOrbiterB = RotL64((aOrbiterB * 2607549567999666889U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4340465159886930775U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7948891781097675369U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12913104720552907335U), 41U);
            //
            aIngress = RotL64(aOrbiterG, 40U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 34U)) + RotL64(aCarry, 47U)) + RotL64(aNonceWordC, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 34U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + RotL64(aNonceWordE, 12U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterD, 53U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 58U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_Hockey_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x96679BD4E3989FDDULL + 0xA72D6CECDDCE6F28ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCD5781BED569FFBDULL + 0xD39FCF149886C577ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8D9D7DE6454C4371ULL + 0xD0850B66E16DD1C8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDF19150A38664837ULL + 0xE0F1275CAE8DFF42ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF9BF6EF2F675E2F5ULL + 0xC3F68A99387D4842ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD624F05931C27C3DULL + 0xB1CB85DA096667FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDD1FF7A8D724D463ULL + 0xFA80CCFAEF4E2CE0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFE1CB5D5AEA87F2FULL + 0x90ED599C308C1560ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 23U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordB, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3020U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 1797U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordF, 14U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5520U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 7133U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U)) + (RotL64(aPrevious, 54U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererE + RotL64(aIngress, 13U)) + 1888427424966603593U) + RotL64(aNonceWordG, 21U);
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 34U)) + RotL64(aCarry, 43U)) + 5436761445660415091U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 17322876217962143270U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 29U)) + 9728299982740564979U) + RotL64(aNonceWordB, 17U);
            aOrbiterJ = (aWandererK + RotL64(aCross, 53U)) + 301720335271716921U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 8069685428854814396U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 43U)) + 1973715500949100991U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 47U)) + 87666408799854155U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 60U)) + 12195436904339035245U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4578742069143400295U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7828776048774876484U;
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17203146364542781833U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16913369550858890466U) ^ RotL64(aNonceWordH, 48U);
            aOrbiterI = RotL64((aOrbiterI * 13534417587921978507U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9632761514552265402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9106637671877341286U;
            aOrbiterE = RotL64((aOrbiterE * 9073709119482640391U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15423680889126750876U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6087310684583331882U;
            aOrbiterD = RotL64((aOrbiterD * 8964465129744898619U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5420955876411796789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14166807419730848032U;
            aOrbiterK = RotL64((aOrbiterK * 442659738632823751U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8118312450347026824U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4253043584558403086U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5651748455190536467U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8810774678371762700U) + RotL64(aNonceWordE, 41U);
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12218479555589447835U;
            aOrbiterB = RotL64((aOrbiterB * 11026364205248516355U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11389930523582876358U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16334420553471379915U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13830132212033904777U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 18201289372553710279U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7196540389657785361U;
            aOrbiterJ = RotL64((aOrbiterJ * 13058135202554889791U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 60U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterD, 51U)) + aOrbiterH) + RotL64(aNonceWordC, 47U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterE, 26U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aNonceWordD, 7U));
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 5U) ^ RotL64(aNonceWordD, 18U)) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14076U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9471U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 6U) ^ RotL64(aNonceWordG, 29U)) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15777U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 10781U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 4U)) + RotL64(aCarry, 57U)) + 4179952823252098240U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 47U)) + 3745613452332101749U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 2955689793395307176U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 23U)) + 5639060180251322019U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 36U)) + 7901969163853586463U) + RotL64(aNonceWordF, 61U);
            aOrbiterI = ((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 2242166787816318119U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 27U)) + 5239936443960750064U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 11U)) + 13939136954732185558U) + RotL64(aNonceWordB, 31U);
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 43U)) + 17058884136712717463U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18148618660054585941U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7022023484530327814U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 650100011311048589U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7722084537340095637U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11764151879690934182U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12264384877711365655U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16412785901758144708U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9666718667728274824U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10865799822751771795U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4307127540152109364U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2457646804702647606U;
            aOrbiterJ = RotL64((aOrbiterJ * 6340030928007058595U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3179394870088602208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 504977947273774249U;
            aOrbiterE = RotL64((aOrbiterE * 16190282058883481551U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16182729401018310837U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7110817020445860609U;
            aOrbiterA = RotL64((aOrbiterA * 13371352088428584087U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12960656706837391973U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7103806893724395904U;
            aOrbiterB = RotL64((aOrbiterB * 14365984439655979791U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1248300178080633527U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7195473175424961337U;
            aOrbiterI = RotL64((aOrbiterI * 4633558992739305045U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 13007951568242991449U) + RotL64(aNonceWordH, 5U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10296811247653636372U) ^ RotL64(aNonceWordD, 25U);
            aOrbiterK = RotL64((aOrbiterK * 16469682651380549395U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 43U);
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterE, 53U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 18U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 4U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + RotL64(aNonceWordC, 24U));
            aWandererK = aWandererK + ((((RotL64(aCross, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aCarry, 19U)) + RotL64(aNonceWordE, 27U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 10U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 38U) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23414U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 16877U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 37U)) ^ RotL64(aNonceWordH, 12U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16404U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19541U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 52U)) + RotL64(aCarry, 19U)) + 15188686795415908074U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aScatter, 19U)) + 17310049041983079779U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + RotL64(aNonceWordG, 39U);
            aOrbiterH = (aWandererF + RotL64(aCross, 57U)) + 8246925977992441471U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 5U)) + 8644260919918112781U) + RotL64(aNonceWordH, 17U);
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 13401663736874819483U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 7940358935238314973U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 11U)) + 13278990328548007839U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 29U)) + 11346868298353840706U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 40U)) + 2374077904806833579U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 6978903378645019166U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 40U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11951633297870965212U;
            aOrbiterH = RotL64((aOrbiterH * 12778236598654492185U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17398460995357409673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1215437945597836770U;
            aOrbiterG = RotL64((aOrbiterG * 9322970054123481621U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1878751468043972239U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5343002808239712390U;
            aOrbiterJ = RotL64((aOrbiterJ * 11878640995447558811U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9884918450053276861U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15894599082080422550U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8359936745539546131U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13917339232771145459U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18101134009493720683U;
            aOrbiterK = RotL64((aOrbiterK * 15835859435306756387U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3830086372356903769U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15894394599564584010U;
            aOrbiterI = RotL64((aOrbiterI * 9513921913446609263U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5127590955274245812U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9410946933309720054U;
            aOrbiterE = RotL64((aOrbiterE * 14507476989423060561U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15544384157294987085U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 998801294460434123U) ^ RotL64(aNonceWordC, 55U);
            aOrbiterF = RotL64((aOrbiterF * 5946968142746472745U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16442095194965452163U) + aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14294936349037516932U) ^ aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14655345374740882581U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 28U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 40U) + RotL64(aOrbiterF, 5U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterA, 23U)) + RotL64(aNonceWordA, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 56U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordE, 5U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterI, 18U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordA, 39U)) ^ RotL64(aNonceWordB, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30409U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30806U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 27U) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31040U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 25975U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 50U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aCross, 23U)) + 14686411261024919129U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 19U)) + 7514582233957632005U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 38U)) + RotL64(aCarry, 51U)) + 6520710480103365552U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 47U)) + 1983621978676188036U) + aOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (((aWandererH + RotL64(aScatter, 3U)) + 9003524602590749672U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordB, 29U);
            aOrbiterE = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 6428568234045228995U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 43U)) + 8656552687136446989U) + RotL64(aNonceWordC, 7U);
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 16916248288415922490U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 14U)) + 9740237548002535784U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 907561000814618339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4751108900841197631U;
            aOrbiterG = RotL64((aOrbiterG * 4545395964730641957U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 167774899400732287U) + RotL64(aNonceWordA, 43U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 11907484918310854962U;
            aOrbiterF = RotL64((aOrbiterF * 7213139491146402985U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14910318613649863924U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14882888155751455276U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11394136445442060201U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16175942562693781908U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11022373758481651102U;
            aOrbiterJ = RotL64((aOrbiterJ * 6836331461393816027U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12548405399045031548U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10850926364556828443U;
            aOrbiterB = RotL64((aOrbiterB * 16231561687709867431U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13391684887911141790U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 14648937281264822988U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordD, 23U);
            aOrbiterE = RotL64((aOrbiterE * 6533299316940026059U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8298658887198526821U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 13822977698661348891U;
            aOrbiterI = RotL64((aOrbiterI * 17769262972278410937U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7505646847564645719U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3238749538197209166U;
            aOrbiterA = RotL64((aOrbiterA * 15394286542600778567U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15853506915123709257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8426329899401071248U;
            aOrbiterC = RotL64((aOrbiterC * 1330397096577715113U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 12U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 48U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + RotL64(aNonceWordF, 60U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aNonceWordH, 3U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 52U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + ((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Hockey_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFB5FC40669ADF36DULL + 0xD0BC994A554308A5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x82516216DAC045A7ULL + 0xECC61FA6395BBA31ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8814D34DA6DF1C7DULL + 0x86A127E72F9F97F6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xDF0C489C23D3A7FFULL + 0xFDB5C99118BA0C47ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x99E0DC90783F37BFULL + 0xAAAF7B628BE9C3A8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFEFF42415AD7C403ULL + 0x86BA14197138D464ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x820A1829CB08D1C5ULL + 0xA2F429E21DFD1B01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB969661AF84014F5ULL + 0xDF02E5B171542AA3ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 358U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 6904U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordD, 19U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2991U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 4184U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 44U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 8685374557928800912U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 49U);
            aOrbiterK = ((aWandererA + RotL64(aScatter, 52U)) + RotL64(aCarry, 29U)) + 3482312691892161229U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 6948130297389161165U) + RotL64(aNonceWordC, 45U);
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 43U)) + 5506385663788942690U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aIngress, 21U)) + 17859982009307397161U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9178488809207094043U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1835479501226057169U;
            aOrbiterC = RotL64((aOrbiterC * 5671861318767342087U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5368101733632614939U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 9050459666576835422U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterI = RotL64((aOrbiterI * 10351719549990259551U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9042186993119635078U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17528342580198295025U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6495418332558436882U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 8834495762667327342U;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4364314196965690905U) + aOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6357485231062120459U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterB = RotL64((aOrbiterB * 289429584586504995U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterC, 58U)) + RotL64(aNonceWordE, 13U)) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 30U) + RotL64(aOrbiterI, 47U)) + aOrbiterC) + RotL64(aCarry, 23U)) + RotL64(aNonceWordA, 34U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 58U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13248U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 12823U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordA, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13864U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15648U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 36U)) ^ (RotL64(aIngress, 19U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 1042610313571524121U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 43U)) + 3505725321008825582U) + aOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            aOrbiterF = ((aWandererA + RotL64(aCross, 19U)) + 12584654563843782991U) + RotL64(aNonceWordB, 10U);
            aOrbiterH = (((aWandererH + RotL64(aPrevious, 52U)) + RotL64(aCarry, 5U)) + 6645399144515770935U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 3608978423753715584U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8089198857670370983U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15207251813516399879U;
            aOrbiterF = RotL64((aOrbiterF * 7596841660069752069U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 9579268660105824516U) + RotL64(aNonceWordD, 49U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16055044469473802812U;
            aOrbiterJ = RotL64((aOrbiterJ * 2269649280637188723U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 583811872609805949U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12686754713465826139U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 18256061823189677508U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordG, 35U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 12708429127816136937U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12593886633108075321U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12169216645156306078U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 12694325407567795065U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3711789483877261899U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 34U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 23U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 54U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordH, 7U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 11U)) + aOrbiterH) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterH, 41U)) + RotL64(aNonceWordA, 9U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordE, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21619U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21999U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordB, 26U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17358U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23896U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 22U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 4259993311776766595U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 21U)) + 2857813330021126753U;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 29U)) + 1345396841329442896U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 48U);
            aOrbiterA = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 320992148982301024U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 10U)) + RotL64(aCarry, 23U)) + 5619109532065293074U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10380157329426706345U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12449831150625409695U) ^ RotL64(aNonceWordH, 47U);
            aOrbiterC = RotL64((aOrbiterC * 3354095240459774437U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7847096607042268396U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11707184096803214678U;
            aOrbiterH = RotL64((aOrbiterH * 1959476948106553973U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 9893643746186827088U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 333687403830908774U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17911256836121454271U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13837360705077441580U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4367119682175710689U;
            aOrbiterA = RotL64((aOrbiterA * 10295744669174603401U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 1193493435041306784U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordG, 41U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 15062951612027370606U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2509383510565136549U), 51U);
            //
            aIngress = RotL64(aOrbiterH, 28U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + RotL64(aNonceWordF, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 21U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28481U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27340U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordE, 40U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31245U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27935U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 3U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 4U)) + 2101601659597850213U) + RotL64(aNonceWordC, 31U);
            aOrbiterI = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 2759794072560720121U) + RotL64(aNonceWordH, 9U);
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 9443562552411269339U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 10801360546699857975U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 37U)) + 8020716394829332019U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1021894212367773801U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13346855534622490176U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12668950387932320985U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16359309548462953836U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 12642446944680783519U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12197935153255283321U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8197424982767553380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 14346334610901859094U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16982899923227935679U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14171304260534233539U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 334531601308283605U) ^ RotL64(aNonceWordE, 35U);
            aOrbiterI = RotL64((aOrbiterI * 5012968232749075075U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10707856298471572695U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 18364775750091914766U) ^ RotL64(aNonceWordA, 57U);
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + RotL64(aNonceWordD, 5U)) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 42U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceWordF, 20U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 14U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Hockey_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCC85B827E0E07355ULL + 0x8D010B0A60F2FA90ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB3A2CD48717D8D33ULL + 0x8966051CB67EC671ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8AA7EA9EB25B3FDDULL + 0xCF93E2388737D936ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x84DFE84319A947AFULL + 0xFF391F4D0D36F55BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDEFDD27537A68569ULL + 0xF2E72CCA9D5AD48AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x811E45DB37BAB08FULL + 0xB9AA5FE793D24D6EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD6EE3F4091487BFBULL + 0xCD094C7D7747247FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB8329C01DE379F8FULL + 0x95549254114974DFULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordH, 46U)) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6023U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 1639U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordF, 54U)) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2888U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 5326U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 21U)) + 11039986441331892533U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 6256024955965426119U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 60U)) + 9857443189988995666U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 35U)) + 11900944813380998208U) + RotL64(aNonceWordG, 13U);
            aOrbiterF = ((aWandererA + RotL64(aScatter, 41U)) + 8422577734978875541U) + aOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 3100835100713928724U) + RotL64(aNonceWordA, 41U);
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 11871553509810206993U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17614749493763417027U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3638372131856199916U;
            aOrbiterD = RotL64((aOrbiterD * 480683274898147025U), 43U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 6582275259281025770U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17016882418498941958U;
            aOrbiterF = RotL64((aOrbiterF * 4269869255230867823U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 1747214688658984715U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordH, 47U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9356088987044015278U;
            aOrbiterA = RotL64((aOrbiterA * 16221733545319753695U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4056238112133473456U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16013150119949532998U;
            aOrbiterB = RotL64((aOrbiterB * 12913648646318115315U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16076621211111834889U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9940824359571581765U;
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15624084004784515753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7630989544834680335U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12261063237156822067U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18003586430673313786U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1654118743290334161U;
            aOrbiterE = RotL64((aOrbiterE * 1153250137357176071U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 13U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 29U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterB, 19U)) + RotL64(aNonceWordC, 59U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 23U)) + RotL64(aNonceWordE, 56U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterK, 36U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 28U) + aOrbiterD) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 26U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordB, 50U)) ^ RotL64(aNonceWordD, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8554U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9508U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordE, 52U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11952U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11588U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 18U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 37U)) + 16160838483846078448U) + RotL64(aNonceWordB, 27U);
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 57U)) + 15404960896190227946U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 12U)) + 16904160594024977199U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 17790460246821031802U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 23U)) + 16395168254086971959U) + RotL64(aNonceWordF, 15U);
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 7484373204039901786U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 18026814691322913510U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15244817793136966450U) + aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5795491730356335666U;
            aOrbiterJ = RotL64((aOrbiterJ * 13253529465289332171U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3163873518027801504U) + RotL64(aNonceWordC, 5U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2690791759507349172U;
            aOrbiterF = RotL64((aOrbiterF * 16677948635136515083U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17898067251167087906U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8028010015006604239U;
            aOrbiterA = RotL64((aOrbiterA * 5601629670521300241U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7304739457289910555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6476837815096530043U;
            aOrbiterI = RotL64((aOrbiterI * 16380545138701113267U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 14242499233467960602U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 17305645693017634630U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14442976693206929569U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 9772864059444171908U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordE, 47U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7897200728282156408U;
            aOrbiterD = RotL64((aOrbiterD * 816306719390807411U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4890999319172950996U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8165132649356094963U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17297706071263690189U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 11U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aNonceWordG, 9U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 26U)) + aOrbiterF) + RotL64(aNonceWordA, 14U));
            aWandererD = aWandererD + ((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 24U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 34U) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17034U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 21182U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordC, 52U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24461U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 24025U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 28U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 13U)) + 8101351470141807662U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 43U)) + 6965474099521076705U) + RotL64(aNonceWordB, 11U);
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 29U)) + 6803828268885684784U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 43U)) + 13454235922950972488U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 11678091885751244777U) + RotL64(aNonceWordA, 47U);
            aOrbiterB = (aWandererF + RotL64(aCross, 23U)) + 5307134544628507141U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 4873703518950429353U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 8542156221858586039U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordC, 13U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 3993726182905296513U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11331376012938127609U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12113047622035464386U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1944244448665721151U;
            aOrbiterF = RotL64((aOrbiterF * 7010050836758762003U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12914188029425467576U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2486762763475327024U;
            aOrbiterJ = RotL64((aOrbiterJ * 12319769994433811617U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14580191602982245481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12093414832400135066U;
            aOrbiterH = RotL64((aOrbiterH * 12720286833215690663U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13623906997320021065U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9977356009806428696U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2005536391712733499U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3694954095397810851U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11453812627797091638U;
            aOrbiterB = RotL64((aOrbiterB * 13730420725113907161U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 542311345544726351U) + RotL64(aNonceWordF, 49U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3024285045990499484U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5153745952148205645U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterF, 13U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 34U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 58U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterB, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterI) + RotL64(aNonceWordD, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordG, 56U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24794U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 26035U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 26U) ^ RotL64(aNonceWordH, 53U)) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27918U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 29558U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 21U)) + (RotL64(aIngress, 47U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 7722279280863371124U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + 11584220561732385598U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 7834679350105534657U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 11U)) + 11347994382444180879U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 29U)) + 9449903188047063431U) + RotL64(aNonceWordG, 9U);
            aOrbiterK = (aWandererD + RotL64(aPrevious, 4U)) + 6516243976652795170U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 8420815253991184777U) + RotL64(aNonceWordA, 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9081386852515170937U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14375955191735286867U;
            aOrbiterG = RotL64((aOrbiterG * 2772840314542262283U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 880757589768436072U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 3349856625725164229U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 681514212582331781U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7826309957607577207U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8057435761214313635U;
            aOrbiterB = RotL64((aOrbiterB * 4718430712767038607U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 9565237500443303103U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 55U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15893066735310588501U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterE = RotL64((aOrbiterE * 8457633439171452397U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3276844534476430842U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6828644383891274120U;
            aOrbiterC = RotL64((aOrbiterC * 979580351653410157U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2815676923011504251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5030251870850928417U;
            aOrbiterA = RotL64((aOrbiterA * 7075653570570819253U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13464083008377887034U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8994560761846897590U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9892839554658865143U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 46U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + RotL64(aNonceWordC, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterC, 53U)) + aOrbiterI) + RotL64(aNonceWordD, 42U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterC, 14U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Hockey_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x807C1313A78F1C09ULL + 0x87A3ABB674F719C4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8FC53F321D2D4BD5ULL + 0xB4C1B697CCD4E4FFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE2A1F3776A81F0F1ULL + 0xEA8F6031590B9797ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB79BE246A64FAD23ULL + 0xC0281434789D1046ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9684E3333BB1C54DULL + 0xD2FEDA823AEE8A3AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA44BFA14359DA2C1ULL + 0xFE4B5ECE826413BAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xEBCC1D48E1C0EA97ULL + 0xF0C98969812C67CCULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF7ADA31F160E0F59ULL + 0xE61B92CB9B39F20BULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4807U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 1635U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordF, 51U)) ^ RotL64(aNonceWordE, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 405U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 4818U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 41U)) + 7722279280863371124U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 57U)) + 11584220561732385598U) + RotL64(aNonceWordF, 15U);
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 10U)) + 7834679350105534657U) + RotL64(aNonceWordA, 23U);
            aOrbiterF = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 11347994382444180879U;
            aOrbiterA = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 9449903188047063431U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 6516243976652795170U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 3U)) + 8420815253991184777U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9081386852515170937U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14375955191735286867U;
            aOrbiterH = RotL64((aOrbiterH * 2772840314542262283U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 880757589768436072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3349856625725164229U;
            aOrbiterA = RotL64((aOrbiterA * 681514212582331781U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 7826309957607577207U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8057435761214313635U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4718430712767038607U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 9565237500443303103U) + RotL64(aNonceWordG, 57U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15893066735310588501U;
            aOrbiterI = RotL64((aOrbiterI * 8457633439171452397U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3276844534476430842U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6828644383891274120U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 979580351653410157U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2815676923011504251U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5030251870850928417U;
            aOrbiterF = RotL64((aOrbiterF * 7075653570570819253U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13464083008377887034U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 8994560761846897590U) ^ RotL64(aNonceWordB, 35U);
            aOrbiterD = RotL64((aOrbiterD * 9892839554658865143U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + RotL64(aNonceWordD, 14U)) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterA, 50U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aNonceWordH, 31U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 4U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordE, 21U)) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9892U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15511U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 30U) ^ RotL64(aNonceWordA, 53U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13866U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 16258U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 34U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 50U)) + 6469584119078165548U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 14329756366517987910U) + aOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 51U)) + 12890831797059772123U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 3164503807500018990U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 3U)) + 177531431387646836U) + RotL64(aNonceWordE, 61U);
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 39U)) + 3167421392893561015U) + RotL64(aNonceWordC, 34U);
            aOrbiterJ = (aWandererF + RotL64(aCross, 57U)) + 2813174781844753460U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10953270419153249857U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16911518309710356951U;
            aOrbiterG = RotL64((aOrbiterG * 13162785997686570445U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6616750447844893150U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 10276741398025985982U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6824712685896987133U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6206043608461213208U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 12021552904553405793U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ RotL64(aNonceWordH, 27U);
            aOrbiterD = RotL64((aOrbiterD * 10023362889960174909U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15283586234744144846U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 5923238786775948571U) ^ RotL64(aNonceWordB, 29U);
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11044014510971660078U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9351141024085076044U;
            aOrbiterE = RotL64((aOrbiterE * 13316079344614432317U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17703395981862992420U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10154548848376027087U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12324478347590509035U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8836420852291617425U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10193385413543886344U;
            aOrbiterJ = RotL64((aOrbiterJ * 824935982418585449U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 26U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK) + RotL64(aNonceWordD, 17U));
            aWandererF = aWandererF + (((RotL64(aCross, 36U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 41U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterD, 60U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + RotL64(aNonceWordA, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 46U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordB, 3U)) ^ RotL64(aNonceWordD, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20118U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17680U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordA, 13U)) ^ RotL64(aNonceWordE, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20612U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19498U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 9023059520606551446U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 662441755115638133U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 16957253361196144712U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 19U)) + 7840955025765308605U) + RotL64(aNonceWordG, 17U);
            aOrbiterI = ((aWandererF + RotL64(aCross, 51U)) + 346855809270395799U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 27U)) + 16099139781586668343U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 36U)) + 3706457327118322098U) + RotL64(aNonceWordE, 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12166825885547622870U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7792658665720344200U;
            aOrbiterG = RotL64((aOrbiterG * 16305542632794270697U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7128477606152986326U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11116533962780290084U;
            aOrbiterF = RotL64((aOrbiterF * 11993485572912492297U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10443889548568288532U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4402387036946561017U) ^ RotL64(aNonceWordF, 54U);
            aOrbiterC = RotL64((aOrbiterC * 9032964741841833277U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13002706161178447654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7005639090871200285U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10949073760696935106U) + RotL64(aNonceWordD, 53U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15405923432006783533U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17989565878445202495U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18096057968822208905U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 3032155040484574973U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17462076466907467134U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15471015427013701406U;
            aOrbiterB = RotL64((aOrbiterB * 6113474000571976139U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterK, 37U)) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordC, 49U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aNonceWordA, 13U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 21U) ^ RotL64(aNonceWordB, 48U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28408U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27638U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordH, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32329U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 25925U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 43U)) + (RotL64(aIngress, 26U) ^ RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aIngress, 57U)) + 12311607308490066301U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordE, 11U);
            aOrbiterC = ((aWandererE + RotL64(aScatter, 5U)) + 13100864684740679846U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 13697304189274329704U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 9047976902871216732U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 14U)) + 2147897579538537888U) + RotL64(aNonceWordC, 39U);
            aOrbiterE = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 2072444829390996142U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 2129307836981020908U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10663145333751112064U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15019844390503785459U;
            aOrbiterK = RotL64((aOrbiterK * 7442321463110790449U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5460865577557928142U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15806522559993224197U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8722932687972240099U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6361113778657833389U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8306013884615042570U) ^ aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8234258702656728667U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4038420580499706912U) + RotL64(aNonceWordF, 34U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11908091484457158973U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3964111175645156719U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11133912466611921250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2469227904206936928U;
            aOrbiterG = RotL64((aOrbiterG * 2704438771198001599U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13234017916788297295U) + RotL64(aNonceWordD, 7U);
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9061117693840451988U;
            aOrbiterH = RotL64((aOrbiterH * 3637440416741459419U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 12013423690843812324U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14371779015144617412U;
            aOrbiterD = RotL64((aOrbiterD * 3359568073302062667U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 20U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aNonceWordB, 23U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterK) + RotL64(aCarry, 5U)) + RotL64(aNonceWordA, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 46U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterA, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA4B0F50A77D5D1CFULL + 0xF418AEE91F855CEFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8548D941CBD22B5BULL + 0xB20BDF1FCCB6BF0EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA0C0901A94D8EBD9ULL + 0xFF778DE3604D3334ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x909B29458F5290ADULL + 0xF0290F5D293768F9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD324C4453446218FULL + 0xD9602E2982E68081ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xACACECF8F9657F91ULL + 0xDA6E4D12DCC0E9B1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xBD3962BF41BDC96BULL + 0x9FBCF45CFB38F01DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xEF33E1FF22D13BE1ULL + 0x8CB681191C18A3BDULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4084U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2486U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordG, 56U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5219U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 3020U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 43U)) + 7270044678408187242U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 10192278965379756766U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 11U)) + 17568666746676060748U) + RotL64(aNonceWordD, 26U);
            aOrbiterI = (aWandererA + RotL64(aPrevious, 37U)) + 14312927531124963037U;
            aOrbiterA = (((aWandererF + RotL64(aCross, 34U)) + 9825825726152087706U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordH, 59U);
            aOrbiterE = (aWandererE + RotL64(aIngress, 39U)) + 9696778570255265896U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 21U)) + 17657841352013417228U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 27U)) + 16207815085909628439U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 58U)) + 1752979206374514227U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 3U)) + 10456310689643905854U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 16127830548663742550U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2940917376003930842U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7353596864777649953U;
            aOrbiterG = RotL64((aOrbiterG * 7499468723171042005U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12725092740446150705U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5791296650856037010U;
            aOrbiterE = RotL64((aOrbiterE * 760379251950502133U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 1200130368046206150U) + RotL64(aNonceWordA, 43U);
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16689604428598558547U;
            aOrbiterK = RotL64((aOrbiterK * 13815324235939996623U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14359561591103730856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 3975025843599045263U;
            aOrbiterI = RotL64((aOrbiterI * 5025047888533298617U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14017901732955607601U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10431526786489555196U;
            aOrbiterH = RotL64((aOrbiterH * 10181915874476132407U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7320527073559849223U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 15333411223710709907U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3488684905528068775U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14302474063321663801U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2104154521019935187U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12944382959742278055U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5167600586916325228U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4566823109447208716U) ^ RotL64(aNonceWordE, 61U);
            aOrbiterB = RotL64((aOrbiterB * 9997799807454267443U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12475580453805083495U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15461491763911887974U;
            aOrbiterA = RotL64((aOrbiterA * 13548865386159287481U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11000532703581114393U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7815822789941347770U;
            aOrbiterC = RotL64((aOrbiterC * 1476638214324946775U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2166336159928211562U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7270044678408187242U;
            aOrbiterF = RotL64((aOrbiterF * 10648564933168714815U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 42U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 41U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordC, 9U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 26U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceWordB, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererK, 36U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8876U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneD[((aIndex + 11619U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordC, 5U)) ^ RotL64(aNonceWordH, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13664U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13397U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 42U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 8767379393098711499U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 39U)) + 7168159491580816433U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 9879279829061883406U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 60U)) + 10537167136053399303U;
            aOrbiterE = (aWandererD + RotL64(aCross, 5U)) + 2839070018069188936U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 11U)) + 13844278063968429732U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 21U)) + 11278946626186474646U) + RotL64(aNonceWordB, 55U);
            aOrbiterF = ((aWandererH + RotL64(aIngress, 47U)) + 11798425216660557799U) + RotL64(aNonceWordG, 48U);
            aOrbiterB = ((aWandererK + RotL64(aCross, 27U)) + 7618446090703335192U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 57U)) + 695423597006983660U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 34U)) + RotL64(aCarry, 41U)) + 14344728202803488813U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11656100506575697086U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10384358779985773937U) ^ RotL64(aNonceWordC, 19U);
            aOrbiterC = RotL64((aOrbiterC * 247494692039140973U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17585001605131977341U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9964478171465522911U;
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 41U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 2710943171829692624U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17809072853457153057U;
            aOrbiterE = RotL64((aOrbiterE * 16341884203303271365U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12814092033910687774U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1743186323268668740U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10750472346626754704U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15925901217078035356U;
            aOrbiterB = RotL64((aOrbiterB * 9276504171291801637U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2569102106359362359U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8868261301410769739U;
            aOrbiterI = RotL64((aOrbiterI * 3662495603133918101U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2143691008373582476U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10606616796243205921U;
            aOrbiterJ = RotL64((aOrbiterJ * 15794414817813485643U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 16258070651850746855U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11720192793689633315U;
            aOrbiterK = RotL64((aOrbiterK * 14475623219460678021U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8230871037292355675U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16898650748046368353U;
            aOrbiterF = RotL64((aOrbiterF * 7368697435476300255U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 9071122174426904737U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4506737259011736474U;
            aOrbiterH = RotL64((aOrbiterH * 11903039808814842447U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4545409671845718259U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8767379393098711499U;
            aOrbiterG = RotL64((aOrbiterG * 1210632171306946669U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 60U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterH, 22U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + RotL64(aNonceWordE, 59U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterD, 39U)) + RotL64(aNonceWordD, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 44U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 22U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 13U) ^ RotL64(aNonceWordA, 56U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18457U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17627U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 12U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordG, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20766U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19998U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererG + RotL64(aPrevious, 3U)) + 8866844335448071821U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 11U)) + 15159698739856430085U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 40U)) + RotL64(aCarry, 41U)) + 9582805772989594633U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererC + RotL64(aCross, 23U)) + 1438538239931588373U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 10862044156620436139U;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 27U)) + 13682173320058164615U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordH, 11U);
            aOrbiterJ = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 8351013291045977592U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 60U)) + 15777857431516633916U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 53U)) + 16178966745333885377U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 9031889187993001617U;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 6308472367425865347U) + RotL64(aNonceWordE, 59U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 642109145903321046U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9186268569255318035U;
            aOrbiterB = RotL64((aOrbiterB * 10714674348507516749U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6091345356803675860U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13218507921880873749U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15415157927185637717U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4266652275234474616U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4391422098164506195U) ^ RotL64(aNonceWordG, 55U);
            aOrbiterC = RotL64((aOrbiterC * 17634679403195085867U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5160682323243635577U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10351728852161347404U;
            aOrbiterF = RotL64((aOrbiterF * 11105410036471745951U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3950932176454814023U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 9536466386833427441U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18064984243491293435U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9927425919978776529U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterB) ^ 6819384090527481081U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordC, 21U);
            aOrbiterI = RotL64((aOrbiterI * 18032965969184368561U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1646274931424218507U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16166524473976135097U;
            aOrbiterD = RotL64((aOrbiterD * 11672192658072663849U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11252501968059485262U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16847854447987609067U;
            aOrbiterG = RotL64((aOrbiterG * 6326299154627028295U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16723218285355036446U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13870211254243048975U;
            aOrbiterJ = RotL64((aOrbiterJ * 10203222183774624097U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11401147367366049493U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 4266628469244269926U;
            aOrbiterH = RotL64((aOrbiterH * 2409934496621365221U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11578385782347296942U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8866844335448071821U;
            aOrbiterA = RotL64((aOrbiterA * 6456956795450036515U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 14U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 4U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterG, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + RotL64(aNonceWordD, 40U));
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterI, 10U)) + RotL64(aNonceWordF, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 21U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 40U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30119U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 31624U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordG, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29695U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 29537U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 24U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererI + RotL64(aIngress, 23U)) + 964165145848253292U;
            aOrbiterJ = ((((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 10645976767204934746U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 27U);
            aOrbiterD = ((aWandererB + RotL64(aScatter, 20U)) + 8241612229349212650U) + RotL64(aNonceWordD, 58U);
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 4159196033256913347U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 3U)) + 7194795864620233507U;
            aOrbiterH = (aWandererA + RotL64(aCross, 37U)) + 7638928444536778384U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 35U)) + 11819105916503968109U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 44U)) + 18052213302858186237U;
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 8663575313970041570U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 16644136720439299786U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 27U)) + 16930316530442679864U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16251107616988250593U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7171986193609401665U;
            aOrbiterD = RotL64((aOrbiterD * 3543709971414550087U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17885046834432626644U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7757069274715713557U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2212805322061155615U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6368539134638838822U;
            aOrbiterH = RotL64((aOrbiterH * 13383744883433594259U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5264326094252925613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6126345334815012938U;
            aOrbiterK = RotL64((aOrbiterK * 17180934809764905307U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 13826731214018407061U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6621261811613643620U;
            aOrbiterC = RotL64((aOrbiterC * 2823596473596114171U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5964406317285863781U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2167324450276308078U) ^ RotL64(aNonceWordC, 17U);
            aOrbiterF = RotL64((aOrbiterF * 1098346374733634905U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16740710162977859724U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8236083581048717923U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4364887787000704039U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 13967473987446124012U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5136051802217149813U;
            aOrbiterI = RotL64((aOrbiterI * 13997246005108872883U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5842999397215390366U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8621394946580065499U;
            aOrbiterE = RotL64((aOrbiterE * 11658023035736362355U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 18086875424872976900U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7429246355923896047U) ^ RotL64(aNonceWordA, 59U);
            aOrbiterJ = RotL64((aOrbiterJ * 5077079237334961761U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18123753993386959014U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 964165145848253292U;
            aOrbiterB = RotL64((aOrbiterB * 3178072569980307307U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterB, 54U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordB, 15U)) + aWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 6U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + RotL64(aNonceWordF, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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

void TwistExpander_Hockey_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8F5927799DAAC2F5ULL + 0xABD00AD0E7725EEBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFB3B9ADC46C67583ULL + 0xE1A2CCA7FE499861ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCCB8415E6BBE9F93ULL + 0xAE97389AF59A9D12ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA0687EFA3B3A3BADULL + 0xDBAA8343076760C8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x96E730619A72990BULL + 0xBCCE2B0E706A4C62ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD8164007A4C4F7D5ULL + 0xE47B9527F003F5C5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFBBB8FEF30F152F1ULL + 0x8DA97ED7CA2B11F9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x984706F82B47A04DULL + 0xEF60743F2C9720FAULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2176U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 2634U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordD, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 785U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 1768U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aScatter, 41U)) + 5697928251815176134U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 337587740689259575U) + RotL64(aNonceWordE, 25U);
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 29U)) + 4927686903263973950U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 5U)) + 3742409032569801033U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aScatter, 37U)) + 1608092659172197650U;
            aOrbiterA = (aWandererH + RotL64(aCross, 51U)) + 15848744267145717509U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 30U)) + 15300174177963339253U) + RotL64(aNonceWordC, 57U);
            aOrbiterB = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 14162868453323648628U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 13U)) + 12020167069983729869U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16259538291658723956U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8516686212464112245U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterF = RotL64((aOrbiterF * 4731296903548893627U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3722184575520553132U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterA = RotL64((aOrbiterA * 14364218128780764749U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15265344442454471986U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 3050323350098829515U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ RotL64(aNonceWordB, 49U);
            aOrbiterB = RotL64((aOrbiterB * 5890624677162388135U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1093356813820599238U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 15170797965325981472U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17826286701992981628U;
            aOrbiterC = RotL64((aOrbiterC * 11186808881726573677U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14710892030473425181U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 397194787697553904U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14368930300818752833U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1273724124862533034U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13018397560392545616U;
            aOrbiterG = RotL64((aOrbiterG * 4644812473262395329U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9638716186445643730U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7255587739807843785U;
            aOrbiterI = RotL64((aOrbiterI * 6055682981584011189U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9272350563697399628U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 56U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aNonceWordD, 22U));
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 43U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 14U) + aOrbiterI) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aNonceWordF, 7U));
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 20U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordD, 37U)) ^ RotL64(aNonceWordC, 6U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9354U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9008U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordG, 43U)) ^ RotL64(aNonceWordB, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9373U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10429U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 57U)) + 8685374557928800912U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 19U)) + 3482312691892161229U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 50U)) + 6948130297389161165U) + RotL64(aNonceWordF, 5U);
            aOrbiterE = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 5506385663788942690U) + RotL64(aNonceWordB, 41U);
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 17859982009307397161U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 3U)) + 9178488809207094043U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 1835479501226057169U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 5368101733632614939U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 27U)) + 9050459666576835422U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9042186993119635078U) + RotL64(aNonceWordD, 29U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17528342580198295025U;
            aOrbiterD = RotL64((aOrbiterD * 14316671546614386775U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6495418332558436882U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8834495762667327342U;
            aOrbiterH = RotL64((aOrbiterH * 10783141541937645995U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4364314196965690905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6357485231062120459U;
            aOrbiterC = RotL64((aOrbiterC * 289429584586504995U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3321488322626415347U) + RotL64(aNonceWordE, 18U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10817330671781848737U;
            aOrbiterA = RotL64((aOrbiterA * 15875919466358823335U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17974092279281611763U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2871472057292789157U;
            aOrbiterG = RotL64((aOrbiterG * 16104199340711015181U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15187929795092006849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13482063681546475923U;
            aOrbiterJ = RotL64((aOrbiterJ * 14466266308157364963U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6232152545071397380U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17488906002621373262U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4719340606442742577U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12444819880507588549U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13808941689757772497U;
            aOrbiterF = RotL64((aOrbiterF * 6541360905282412317U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8049361354387692374U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7137831335606542401U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11022231291507235007U), 53U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aNonceWordH, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 6U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 18U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterG, 22U));
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + RotL64(aNonceWordC, 49U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordC, 20U)) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14751U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 14449U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordF, 53U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15261U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 14871U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 51U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 10U)) + 16451272412693907816U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 23U)) + 10099485419723255462U) + RotL64(aNonceWordG, 54U);
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 17668900099534923192U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 5497093724143181753U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 10354044773550071706U) + RotL64(aNonceWordD, 13U);
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 12728258851198019099U;
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 4144050505314242618U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 41U)) + 14133805325480076530U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 18U)) + 308863673210602899U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 11741180130160569753U) + RotL64(aNonceWordB, 23U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12926863156769180448U;
            aOrbiterH = RotL64((aOrbiterH * 9726030996091054939U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 211920854786494259U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13234608842479411078U;
            aOrbiterG = RotL64((aOrbiterG * 2556747209733759467U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9164711974854618892U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6667377062281954219U;
            aOrbiterJ = RotL64((aOrbiterJ * 2603737166987437649U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4559040002406721850U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1749875480850675109U;
            aOrbiterD = RotL64((aOrbiterD * 15822640067349481089U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 9555365165561936366U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18289733999504213574U;
            aOrbiterA = RotL64((aOrbiterA * 14156217554673229429U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8727162691639622461U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 291406782452963706U;
            aOrbiterF = RotL64((aOrbiterF * 8413500075082350243U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8294911802626492257U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15853578397277298548U;
            aOrbiterC = RotL64((aOrbiterC * 13256191781365357747U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 11535146194939658681U) + RotL64(aNonceWordC, 45U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2177540476748375661U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15791341922007841029U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2705306323728084136U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17617871830709148043U;
            aOrbiterI = RotL64((aOrbiterI * 3449981219502809255U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 35U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 44U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterD) + RotL64(aNonceWordE, 9U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 42U) + RotL64(aOrbiterJ, 56U)) + aOrbiterF) + RotL64(aNonceWordF, 15U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordA, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21013U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19423U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordG, 56U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21500U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20270U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 39U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aCross, 57U)) + 3970829908171131502U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 27U)) + 7040283759419531991U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 11856292169397052901U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 819598588791819022U) + RotL64(aNonceWordB, 30U);
            aOrbiterD = (((aWandererD + RotL64(aScatter, 22U)) + RotL64(aCarry, 29U)) + 2176451710970866848U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 13U)) + 6454704928613390494U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 47U)) + 11792122387218053841U;
            aOrbiterB = ((((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 9254780213489752211U) + aOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordH, 37U);
            aOrbiterH = (aWandererA + RotL64(aScatter, 6U)) + 16591812589999846482U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1471246223935074832U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1424843083106386453U;
            aOrbiterC = RotL64((aOrbiterC * 15020536982657410783U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1856469958050891629U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6331743690452052712U;
            aOrbiterD = RotL64((aOrbiterD * 15327924647897459645U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10351075711345476487U) + aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9518585245330480185U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3792179827396760391U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17787514620244712033U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14182328067398162557U;
            aOrbiterA = RotL64((aOrbiterA * 18107337388659070197U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12798088948801072444U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9563215159275202323U;
            aOrbiterJ = RotL64((aOrbiterJ * 7058145016617349141U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9904919772580498232U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16579777394992143043U;
            aOrbiterF = RotL64((aOrbiterF * 10516761340320196661U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6344049286854588503U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3531503618941046788U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10855385899703024105U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11334308840132700377U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11093833870078787770U;
            aOrbiterH = RotL64((aOrbiterH * 16105889714648555755U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3831491136025364271U) + RotL64(aNonceWordA, 21U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 12505259454860591372U) ^ RotL64(aNonceWordG, 19U);
            aOrbiterI = RotL64((aOrbiterI * 6135450888433504093U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterB, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 23U)) + aOrbiterH) + RotL64(aNonceWordD, 9U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + RotL64(aNonceWordF, 25U));
            aWandererG = aWandererG + ((RotL64(aCross, 14U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 6U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordE, 41U)) ^ RotL64(aNonceWordG, 58U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 27020U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26204U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27134U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 26349U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 34U)) + RotL64(aCarry, 47U)) + 18144572925667544139U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 5U)) + 5659758077574059728U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 6343330616999166392U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 53U)) + 17754639838410839447U) + RotL64(aNonceWordA, 39U);
            aOrbiterH = (aWandererA + RotL64(aCross, 23U)) + 9451843819849581729U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 48U)) + RotL64(aCarry, 21U)) + 7957854457197462212U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 19U)) + 1461994799722205010U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 61U);
            aOrbiterA = (aWandererC + RotL64(aIngress, 39U)) + 18002214276252170177U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 27U)) + 14689869073147027164U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3978104368003440293U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8512135845221335386U;
            aOrbiterB = RotL64((aOrbiterB * 10506667163729414667U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1477533446382953439U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2166717790929947990U;
            aOrbiterE = RotL64((aOrbiterE * 6538884492418324461U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8082437060686606995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4363687722464700362U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7199165810993478887U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15782763348014924206U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8572509150015960728U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterK = RotL64((aOrbiterK * 3340528604891897779U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12248271773316742521U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9602078627638561949U;
            aOrbiterC = RotL64((aOrbiterC * 1860631869877427405U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 17244849374768558859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1030743048280579012U;
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 17722342363541914280U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 15667504059789880034U) ^ RotL64(aNonceWordB, 19U);
            aOrbiterJ = RotL64((aOrbiterJ * 15872269872168533709U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12645332941998550794U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9938135244509986497U) ^ aOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16548185968987392957U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4024609904162105979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6732064218696157303U;
            aOrbiterH = RotL64((aOrbiterH * 3815409766145891393U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 40U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 60U));
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aNonceWordD, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 28U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 53U)) + RotL64(aNonceWordC, 18U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 34U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30012U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31225U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordG, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31867U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 28102U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 28U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 43U)) + 1557680213571812384U;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 7387349725778021121U) + RotL64(aNonceWordB, 52U);
            aOrbiterG = (aWandererE + RotL64(aIngress, 29U)) + 15379264067601586976U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 3U)) + 3730195724576043708U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 35U)) + 9637070085323827066U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 19U)) + 1170865717363676184U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 13U)) + 2750833653175252030U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aIngress, 60U)) + 15118992811225568305U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 51U)) + 4974092922102988451U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordH, 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10625719096296719514U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 855167122475471865U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7441090331293158773U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11322911068958340262U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 4334591909425429835U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10059025861172038183U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14263701737208936392U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 678723206735649084U;
            aOrbiterB = RotL64((aOrbiterB * 10823239851733632227U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15652053114252065230U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1705225940224061401U;
            aOrbiterC = RotL64((aOrbiterC * 3626023093533713579U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6826394665732900206U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11902946775066981141U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18300629262162694137U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9802212958998591310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14001358545610206524U;
            aOrbiterK = RotL64((aOrbiterK * 13172645840788327099U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4299184726135884309U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 7288757011999872416U) ^ RotL64(aNonceWordE, 9U);
            aOrbiterJ = RotL64((aOrbiterJ * 16806027820468277393U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 233801262480580205U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 14208660347238680268U;
            aOrbiterD = RotL64((aOrbiterD * 6299693448313154603U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9217797359740446104U) + RotL64(aNonceWordA, 47U);
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18165073197136050838U;
            aOrbiterE = RotL64((aOrbiterE * 11677479094709512887U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 52U)) + aOrbiterA);
            aWandererH = aWandererH + (((((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 53U)) + RotL64(aNonceWordC, 51U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 60U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 14U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + RotL64(aNonceWordG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + RotL64(aWandererB, 14U);
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

void TwistExpander_Hockey_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x829803D46C183E85ULL + 0xB0C8E80106FCC3FDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA916CA04AE67022DULL + 0xC09C83A612F9D78AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA1336505667ECA43ULL + 0xF4BC18A168C3233AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC465CCB508E3BB7DULL + 0xDC4354F23728F35DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x83E36FD42FC1F9EDULL + 0xC009F40D9D37EE8BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC259A9B6F4094A45ULL + 0x9632B7D3BF7D315DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB39F012102A15775ULL + 0xAA218B2862029F35ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9B33AC79B7393FC1ULL + 0xEE8CA7140CBFAB18ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordA, 57U)) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3376U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2075U)) & W_KEY1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 13U)) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3671U)) & W_KEY1], 47U) ^ RotL64(mSource[((aIndex + 2779U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 44U)) + RotL64(aCarry, 41U)) + 12136097566601676613U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 57U)) + 7969431322248040056U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 10530676021510553889U) + RotL64(aNonceWordE, 47U);
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 8740777303075445264U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 13U)) + 13249434169895564739U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 12U);
            aOrbiterB = (aWandererC + RotL64(aCross, 3U)) + 15529577005925628472U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 27U)) + 344627093687331562U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8824277416519988893U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5636276438449709875U;
            aOrbiterH = RotL64((aOrbiterH * 222817930773618893U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2079413361031851552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7807998179168655561U;
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13589392896232029112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10733011474804473996U;
            aOrbiterB = RotL64((aOrbiterB * 361749145931578805U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 15934162328347805968U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + RotL64(aNonceWordB, 17U);
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7573511217796245232U;
            aOrbiterG = RotL64((aOrbiterG * 10694563909931636155U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4828475187337891975U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13284974329890393113U;
            aOrbiterF = RotL64((aOrbiterF * 10831075817642374287U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 13173869918669643112U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15841507674783398167U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15632933198136963277U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 14168272451055700516U) + RotL64(aNonceWordD, 37U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11134471485501999898U;
            aOrbiterI = RotL64((aOrbiterI * 8019507184494591705U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 28U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordC, 9U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 53U)) + aOrbiterG) + RotL64(aNonceWordH, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 4U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordA, 10U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9264U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7946U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 21U) ^ RotL64(aNonceWordF, 35U)) ^ RotL64(aNonceWordC, 48U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9675U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 10054U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 58U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 35U)) + 12131317914288566437U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 19U)) + 5672805657999385496U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 47U)) + 3581710244233124197U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 53U)) + 15251296040538489436U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 11295008604679904153U) + RotL64(aNonceWordB, 58U);
            aOrbiterB = (((aWandererA + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 2230897493419504490U) + aPhaseAOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 7109600123297458999U) + aPhaseAOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordA, 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13119156643107683803U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14755160867807355250U;
            aOrbiterF = RotL64((aOrbiterF * 10007087518844899239U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16829363373287496832U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 16981122946707720883U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) ^ RotL64(aNonceWordH, 3U);
            aOrbiterC = RotL64((aOrbiterC * 5394974422201576627U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8806000776958603317U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16810923047720876014U;
            aOrbiterJ = RotL64((aOrbiterJ * 17872735050219539145U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8129657889554436328U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8653100378491974463U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11395283153912468661U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17048985838727432415U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10892675550889823573U;
            aOrbiterI = RotL64((aOrbiterI * 976298937314081913U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 15960158965421254346U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12290011578634850001U) ^ RotL64(aNonceWordE, 21U);
            aOrbiterB = RotL64((aOrbiterB * 9280475585104357745U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16265047040311479093U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10312956912303656248U;
            aOrbiterK = RotL64((aOrbiterK * 3012584393253845131U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 20U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 30U)) + aOrbiterC) + RotL64(aNonceWordD, 39U));
            aWandererI = aWandererI + (((((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordF, 41U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterB) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 56U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordA, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12515U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13947U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15942U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12035U)) & W_KEY1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 18U)) + (RotL64(aCross, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 2783898056762489197U) + RotL64(aNonceWordE, 57U);
            aOrbiterD = (aWandererH + RotL64(aPrevious, 43U)) + 7177192902873343053U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 3U)) + 12254703232691980774U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 37U)) + 15446547245691219559U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 21U)) + 888475203006174856U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 28U)) + RotL64(aCarry, 41U)) + 3649183529366307877U;
            aOrbiterH = ((((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 4642631047518805167U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordB, 61U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6108329730724782250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8334054653023816636U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9352516059501924393U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5891895375031474350U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3176720746238477862U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterD = RotL64((aOrbiterD * 1869961473768307911U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6111038696865301675U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11914998302228682704U;
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17005063057791320948U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 18333780598768130670U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5416759844884107303U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2056115016443263153U) + RotL64(aNonceWordF, 37U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10245512728872962677U;
            aOrbiterA = RotL64((aOrbiterA * 707106795383284903U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4810366069422162351U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3051442983125942469U;
            aOrbiterI = RotL64((aOrbiterI * 13558537578054436423U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9285068547223654308U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13067251130180968842U;
            aOrbiterH = RotL64((aOrbiterH * 7000687697769766605U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 53U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 59U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aNonceWordA, 18U));
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 13U)) + aPhaseAWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordD, 46U)) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16925U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19429U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordB, 10U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16697U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 19693U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aScatter, 43U)) + 3255291173184001106U) + RotL64(aNonceWordC, 27U);
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 15308468160116255528U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 18186972408589866656U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 29U)) + 4439324265978331914U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 41U)) + 13099263173016322486U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 11U)) + 7041561081767500660U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 37U)) + 6196422612687812971U) + RotL64(aNonceWordF, 49U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 7664260932541281413U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17802347823020441056U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2220679459017369255U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4253107484061190446U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13799496534030645312U;
            aOrbiterI = RotL64((aOrbiterI * 9167675060053848207U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14252892847595951926U) + RotL64(aNonceWordA, 47U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5663527578664291422U) ^ RotL64(aNonceWordE, 14U);
            aOrbiterA = RotL64((aOrbiterA * 18314294235895182465U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11148755959699137661U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17036900929333594592U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16041243617369003291U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2403828181385259549U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 17813580350434928194U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13666780980793857831U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5623611126885414523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7293224381174846969U;
            aOrbiterF = RotL64((aOrbiterF * 7032561584670788117U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10602620906929686163U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18015916257203385982U;
            aOrbiterC = RotL64((aOrbiterC * 10684090189688871993U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 22U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 15U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 41U)) + aOrbiterE) + RotL64(aNonceWordH, 37U)) + aPhaseAWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 60U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 52U) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25682U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 26710U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 22U) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23048U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 26070U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 56U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aScatter, 5U)) + 9654059367478508868U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 13U)) + 6473006635864677427U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 57U)) + 6944184481315853243U) + RotL64(aNonceWordG, 17U);
            aOrbiterD = (aWandererE + RotL64(aIngress, 37U)) + 4061496421939102306U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 22U)) + RotL64(aCarry, 11U)) + 15791809275719085463U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 14050798802646323055U) + RotL64(aNonceWordE, 37U);
            aOrbiterC = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 12072905924741758266U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17639076509231343896U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 12195388285571234715U) ^ RotL64(aNonceWordH, 49U);
            aOrbiterF = RotL64((aOrbiterF * 4317060502521195769U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4325404419499496529U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5910567888204238382U;
            aOrbiterJ = RotL64((aOrbiterJ * 11503787177122206937U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13092940059929942699U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13381962590820308761U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6345904465930943295U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15622862439323440527U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14027151901132249793U;
            aOrbiterH = RotL64((aOrbiterH * 2273573821630510087U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4584410023907605157U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 15763755180625487157U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ RotL64(aNonceWordD, 43U);
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17023059745666559199U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5298529579288492971U;
            aOrbiterG = RotL64((aOrbiterG * 2483562793328357721U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2870152867331654736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12017191100173748848U;
            aOrbiterC = RotL64((aOrbiterC * 9958191466506480519U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + RotL64(aNonceWordB, 57U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordA, 12U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterF, 36U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aPhaseAWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 38U) ^ RotL64(aNonceWordF, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32561U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29515U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 34U) ^ RotL64(aNonceWordC, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28085U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31245U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 53U)) + 14499676118633326000U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 43U)) + 17191273593018552288U) + aPhaseAOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordB, 41U);
            aOrbiterE = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 4085176294948097737U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + 11112671474158908186U) + RotL64(aNonceWordD, 4U);
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 10U)) + RotL64(aCarry, 35U)) + 8745787969012266485U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 53U)) + 18074049663777707948U;
            aOrbiterA = (aWandererE + RotL64(aCross, 23U)) + 2543758649719164688U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4659584749412700523U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 974639159259871273U;
            aOrbiterE = RotL64((aOrbiterE * 17918719351847605523U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9211220687971081987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8567024626862182714U;
            aOrbiterI = RotL64((aOrbiterI * 7755874089832496393U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 5803002132294840900U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + RotL64(aNonceWordE, 45U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11968489432878148467U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9470807228394903442U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1692347973120388469U;
            aOrbiterA = RotL64((aOrbiterA * 17433393164156231575U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 16510815732690193145U) + RotL64(aNonceWordG, 23U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 755159406833096510U;
            aOrbiterF = RotL64((aOrbiterF * 14091736464659561165U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1518824876475937620U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 701225390867330446U;
            aOrbiterJ = RotL64((aOrbiterJ * 12264618860580199927U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8425976693733003889U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7182176375442410367U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8860605703761731859U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 57U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 30U)) + aOrbiterI) + RotL64(aNonceWordF, 49U)) + aPhaseAWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordH, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA2D00CBFAE31D4F9ULL + 0xDD5B3487B99D36D9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF164F8806D03E0F9ULL + 0xB38F052E846FC8EFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA55019E123CE382DULL + 0x878946E7BC530B08ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB9F4A3D59786043FULL + 0xC5B01E944C28A2E5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA3C497F69FAA113FULL + 0x8EC6F0A45C5B9121ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD97825C682B18A67ULL + 0x982214F0ECEA1FD1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8ADD373219E81C4DULL + 0x9621C9A087A6F644ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE8CCAACFF8B38F0FULL + 0x8BC4A81DE537A0E1ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordD, 30U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1909U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 2896U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 58U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4028U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 108U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aCross, 58U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 11998579547770778580U) + RotL64(aNonceWordB, 23U);
            aOrbiterD = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 8409465187298704610U) + aPhaseBOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aIngress, 46U)) + 3470222286110333500U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 5704486785203069994U) + RotL64(aNonceWordF, 49U);
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 37U)) + 10334944660253279633U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7626852700722567477U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14631310754943209743U;
            aOrbiterG = RotL64((aOrbiterG * 1958866541508493967U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 807160297237854120U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5624154783624196107U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2404066593958052159U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4971444394698940423U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6340057638461027062U) ^ RotL64(aNonceWordH, 13U);
            aOrbiterB = RotL64((aOrbiterB * 12027586111086798629U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9003019862787819481U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13632057463595873033U;
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12766104026871797746U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4062118445824915939U) ^ RotL64(aNonceWordA, 14U);
            aOrbiterE = RotL64((aOrbiterE * 13130770039048080701U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 19U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 54U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordG, 47U)) + aPhaseBWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aNonceWordC, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordE, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10743U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10372U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordB, 10U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9973U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10356U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 252059974543142812U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 11690823093681457368U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 13282189752890971123U;
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 3U)) + 9507416294305708435U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordG, 5U);
            aOrbiterB = ((aWandererG + RotL64(aScatter, 13U)) + 14053038174390776539U) + RotL64(aNonceWordB, 14U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 14605253312318725009U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 18138286582677863671U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ RotL64(aNonceWordF, 7U);
            aOrbiterJ = RotL64((aOrbiterJ * 10595905899691011321U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8530091235978489988U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14381731677571170073U;
            aOrbiterB = RotL64((aOrbiterB * 11675896999665768253U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13316413456378978456U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3910529530149320706U;
            aOrbiterE = RotL64((aOrbiterE * 16000139333493588429U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6302070286831566901U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 12324134652758551396U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17136438281540250165U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4773478557638475048U) + RotL64(aNonceWordE, 35U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4031153435446078944U;
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 28U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aNonceWordD, 37U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + RotL64(aNonceWordC, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterB, 22U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11909U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 15755U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordF, 27U)) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12758U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 11309U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 58U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aCross, 27U)) + 10805654776556844351U) + RotL64(aNonceWordD, 47U);
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 47U)) + 582794182442795335U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + RotL64(aNonceWordB, 22U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 57U)) + 2858343650974681068U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 44U)) + RotL64(aCarry, 3U)) + 8189584049022064284U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 1565100751996962893U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 8062028016947611891U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordC, 3U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8280504280578451745U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterB = RotL64((aOrbiterB * 5212851648135050483U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11326869194491655350U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1671695656567777163U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7511554500524257921U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2349843105293943452U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13015545152052004254U;
            aOrbiterE = RotL64((aOrbiterE * 1316662811685429983U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16703354404749291869U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8713231044374305801U;
            aOrbiterC = RotL64((aOrbiterC * 9242480982197688625U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11118401674497783533U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 14857556493734710364U;
            aOrbiterA = RotL64((aOrbiterA * 3452566050389715195U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 30U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 14U)) + aOrbiterA) + RotL64(aCarry, 35U)) + RotL64(aNonceWordA, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 11U)) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordG, 39U)) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21832U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 18997U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordH, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18772U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 21042U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 43U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 1952750591494698524U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 27U)) + 4488270851303332830U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 2738763375328927635U) + RotL64(aNonceWordC, 12U);
            aOrbiterE = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 13U)) + 6728843649480454340U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 36U)) + 10490717875258865358U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordA, 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1429288737812910205U) + RotL64(aNonceWordB, 37U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2761375016998907636U) ^ RotL64(aNonceWordD, 45U);
            aOrbiterI = RotL64((aOrbiterI * 16589197409983023283U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1088988605204499835U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6829840407300289709U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13101432880030791787U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9267240337867690471U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8120113021183975703U;
            aOrbiterE = RotL64((aOrbiterE * 14296504593187173107U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 1340980511302566784U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 11874452169979878835U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8638486178860092537U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1872314794140971426U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6013952618696225751U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7994863587373565715U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aNonceWordE, 19U)) + aPhaseBWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 36U)) + aOrbiterF) + RotL64(aCarry, 3U)) + RotL64(aNonceWordH, 5U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + aPhaseBWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 23U) ^ RotL64(aNonceWordA, 34U)) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22950U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 27150U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21939U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 25371U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 35U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aCross, 5U)) + 9446153639709651566U;
            aOrbiterH = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 10550762260670758167U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordH, 5U);
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 57U)) + 7062634922142578383U) + RotL64(aNonceWordE, 61U);
            aOrbiterC = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 9178499097812764515U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 14U)) + RotL64(aCarry, 3U)) + 6887103379773525538U) + aPhaseBOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6239750312052010257U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17645022614523287959U;
            aOrbiterJ = RotL64((aOrbiterJ * 14448140327044053545U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3639618183259408272U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 3131737117548745095U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordG, 53U);
            aOrbiterD = RotL64((aOrbiterD * 6585057380704940395U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7253994382396406554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15217993711938379561U;
            aOrbiterE = RotL64((aOrbiterE * 17853313384747259923U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12594152227603630033U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 11250170200489647869U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ RotL64(aNonceWordF, 25U);
            aOrbiterH = RotL64((aOrbiterH * 546800378327864723U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12936942656624279424U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10990736056052106149U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7123916809953459187U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 24U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 60U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + RotL64(aNonceWordA, 45U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + RotL64(aNonceWordD, 26U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordC, 56U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28659U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29409U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 54U) ^ RotL64(aNonceWordA, 27U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30239U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30258U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 13499155707765393469U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 47U)) + 3740324981823726185U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aIngress, 58U)) + 5470765363949735652U) + aPhaseBOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 3446436171274452326U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 1778929412631211933U) + RotL64(aNonceWordB, 50U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14666308799855220954U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4548410236791175055U;
            aOrbiterG = RotL64((aOrbiterG * 6822908616815218501U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5829739767694190372U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14319231414903675748U;
            aOrbiterJ = RotL64((aOrbiterJ * 4966501102515775601U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 1513851750246111405U) + RotL64(aNonceWordH, 43U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1685620217748986019U;
            aOrbiterI = RotL64((aOrbiterI * 9286548037413609445U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16284162182006054402U) + RotL64(aNonceWordD, 27U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 6271539598462003309U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13923286694131331137U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 12669312437565969473U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterF = RotL64((aOrbiterF * 12556759675372354075U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterG) + RotL64(aNonceWordG, 15U));
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 34U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aPhaseBWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 43U) + RotL64(aOrbiterA, 54U)) + aOrbiterG) + RotL64(aCarry, 23U)) + RotL64(aNonceWordF, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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

void TwistExpander_Hockey_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE0DDDC36873E33B7ULL + 0x89A82AE44E96958AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC10D7AA396078553ULL + 0xCDD3A6982D59005CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFE682354C3C2212BULL + 0xEE5BFE9DC23C3B18ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8116B7DCA243A2D9ULL + 0xA87ECDD386BCF3D3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE4C5FE2E415E9EC3ULL + 0xAF897EC7AB4A3982ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA72EEC0F91C10F63ULL + 0xD4CFC8EBE00EA895ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF9221A572A89D4EBULL + 0xF4930A37FA5B740BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD948A3B2D9CA3F4BULL + 0xCB6F8DEA75C26395ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordB, 22U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 180U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3361U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordE, 48U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7751U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 1471U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 3U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 23U)) + 898812731947995389U) + aPhaseCOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aIngress, 13U)) + 8677347622525527167U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 58U)) + RotL64(aCarry, 57U)) + 770321564027567654U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 11020474858081526395U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 53U)) + 17289793580414993470U) + aPhaseCOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 19U)) + 10111912559295118444U) + RotL64(aNonceWordD, 46U);
            aOrbiterE = (aWandererG + RotL64(aCross, 43U)) + 8083622125544542011U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 28U)) + 7149858558922988240U) + RotL64(aNonceWordF, 23U);
            aOrbiterK = (aWandererF + RotL64(aCross, 3U)) + 5919683821379905699U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6860902846079238714U) + RotL64(aNonceWordA, 15U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15083517836867542075U;
            aOrbiterJ = RotL64((aOrbiterJ * 4686657139237578325U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14852868368708376381U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9860233289028878323U;
            aOrbiterA = RotL64((aOrbiterA * 13418143547952204667U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 772406119079116272U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 7971141501337627589U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10168120622976358617U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8478568022896691911U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4027604850785607101U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4826627523578901467U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17199331557841535430U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7515957656979776361U;
            aOrbiterC = RotL64((aOrbiterC * 5468950152869656599U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17138249294921502391U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 16236812863923234668U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2925542836624164807U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16941524155859123682U) + RotL64(aNonceWordC, 35U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11240343728857342866U;
            aOrbiterE = RotL64((aOrbiterE * 7281012444214294659U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15163914964139858328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6673576554415729652U;
            aOrbiterH = RotL64((aOrbiterH * 1558880328574736975U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5399050402101642989U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11806006719060024615U;
            aOrbiterI = RotL64((aOrbiterI * 15782156615926092159U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 30U)) + aOrbiterK) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aNonceWordB, 11U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 5U)) + aOrbiterD) + RotL64(aCarry, 37U)) + RotL64(aNonceWordG, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 14U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 48U) ^ RotL64(aNonceWordB, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12861U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 11082U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 39U) ^ RotL64(aNonceWordE, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11546U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 10629U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 5697928251815176134U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 43U)) + 337587740689259575U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 4927686903263973950U) + RotL64(aNonceWordB, 17U);
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 3742409032569801033U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 3U)) + 1608092659172197650U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 48U)) + 15848744267145717509U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 35U)) + 15300174177963339253U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 19U)) + 14162868453323648628U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordC, 7U);
            aOrbiterK = (aWandererJ + RotL64(aCross, 13U)) + 12020167069983729869U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16259538291658723956U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8516686212464112245U;
            aOrbiterA = RotL64((aOrbiterA * 4731296903548893627U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3722184575520553132U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5663609293306386784U) ^ RotL64(aNonceWordF, 56U);
            aOrbiterC = RotL64((aOrbiterC * 14364218128780764749U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15265344442454471986U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3050323350098829515U;
            aOrbiterJ = RotL64((aOrbiterJ * 5890624677162388135U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1093356813820599238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15167726103772238440U;
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15170797965325981472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17826286701992981628U;
            aOrbiterK = RotL64((aOrbiterK * 11186808881726573677U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14710892030473425181U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterD = RotL64((aOrbiterD * 14368930300818752833U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1273724124862533034U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13018397560392545616U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4644812473262395329U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9638716186445643730U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7255587739807843785U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6055682981584011189U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 9272350563697399628U) + RotL64(aNonceWordG, 31U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1040729335295009339U;
            aOrbiterI = RotL64((aOrbiterI * 17825687660830291443U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 6U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 38U)) + aPhaseCWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceWordA, 55U));
            aWandererI = aWandererI + ((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 34U)) + aOrbiterC) + RotL64(aNonceWordH, 49U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordH, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18702U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 21187U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordB, 40U)) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22118U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19294U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 8793908991006073956U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 58U)) + 2932916283348441943U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 11069042087940968262U;
            aOrbiterD = (aWandererE + RotL64(aCross, 19U)) + 14369628676782894441U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 3U)) + 8602903272780978282U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 11U)) + 3827036107178568820U) + aPhaseCOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (((aWandererI + RotL64(aCross, 28U)) + RotL64(aCarry, 3U)) + 8905245209036772489U) + RotL64(aNonceWordD, 13U);
            aOrbiterF = ((aWandererG + RotL64(aScatter, 37U)) + 13331387530760017893U) + RotL64(aNonceWordE, 21U);
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + 9880107580289737823U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10199619040626900278U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2466307560891374281U) ^ RotL64(aNonceWordF, 52U);
            aOrbiterA = RotL64((aOrbiterA * 6295342978834217571U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13973403407981259448U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2851460278409385243U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11226902976321781743U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10365453393815690776U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2382382358987358791U;
            aOrbiterD = RotL64((aOrbiterD * 481563628980705781U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5058198848163792422U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10500434740387593487U;
            aOrbiterH = RotL64((aOrbiterH * 5946747708776079787U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11289798395177667084U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14327152153231286666U;
            aOrbiterI = RotL64((aOrbiterI * 18155778059595245561U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8065137263811956313U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3865153574847924816U;
            aOrbiterG = RotL64((aOrbiterG * 9495741102667755161U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18102279969722473375U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6306428427188742325U;
            aOrbiterB = RotL64((aOrbiterB * 17826782872351406167U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16953348204663693724U) + RotL64(aNonceWordA, 51U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11950791817032898613U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1498946055469611133U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11980823193543752994U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17845490308799454871U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385153013485463791U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 24U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 30U)) + aOrbiterG) + RotL64(aNonceWordG, 43U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterA, 10U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 18U) + aOrbiterF) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordC, 45U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 6U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26674U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31951U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 58U) ^ RotL64(aNonceWordB, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30568U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32148U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 58U)) + RotL64(aCarry, 35U)) + 5171470532667965920U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 750549462358682403U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 3325689257577120525U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 51U)) + 18031575461559790826U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 47U)) + 13874739537012288677U) + RotL64(aNonceWordE, 31U);
            aOrbiterB = (((aWandererD + RotL64(aScatter, 5U)) + 4250029868785016865U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterJ = (aWandererE + RotL64(aCross, 27U)) + 8211158803112611161U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 22U)) + RotL64(aCarry, 51U)) + 1083939790236786027U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 11U)) + 3446525462376962464U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6973817815000417325U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15230876489676945543U;
            aOrbiterD = RotL64((aOrbiterD * 7737039082964537651U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9359727659738755880U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8775170107816327654U;
            aOrbiterF = RotL64((aOrbiterF * 6910680458261008653U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 11958941755525038545U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16966819714283167348U;
            aOrbiterJ = RotL64((aOrbiterJ * 16363457661846050749U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14556087985619763243U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 17915047508377045221U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6727635453185130109U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8578745677485367222U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7002181668717618866U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3569939503066735457U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 2956247934282522184U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ RotL64(aNonceWordC, 57U);
            aOrbiterB = RotL64((aOrbiterB * 9946650822131152531U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 4285180013402474041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5976239869535619811U;
            aOrbiterH = RotL64((aOrbiterH * 3458095419039067465U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2424524955161695463U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6849595426583763537U;
            aOrbiterA = RotL64((aOrbiterA * 12727902040238318101U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11414890686374886716U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5668287266836153445U;
            aOrbiterG = RotL64((aOrbiterG * 8011885266143066285U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 12U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterB, 43U)) + aOrbiterG) + RotL64(aNonceWordA, 9U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 27U)) + aOrbiterH) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 60U)) + aPhaseCWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterB, 58U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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

void TwistExpander_Hockey_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF1DF4020EFC8C29ULL + 0xCB7FE215CE7D9E8FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAFBE00C5A1F678E9ULL + 0x92500ECECC35E6ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD8DB20114D0DDBADULL + 0x9FBFC00189758CCDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC418B5F3FB702BB9ULL + 0xB742EE61E1C55013ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x86709F1CE1CD3D5BULL + 0x9CE6E9AC8C3B8DBAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFAC3FFB5367123AFULL + 0xDE9D84DE22EF62B3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFFF48C500575B69DULL + 0x8FC06F5B1023F683ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xACEF4E74E59FD3B7ULL + 0xEBE27E9735DFE7CFULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordD, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4875U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 2112U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 41U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3551U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4392U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 58U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 29U)) + 12131317914288566437U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 37U)) + 5672805657999385496U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 50U)) + 3581710244233124197U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 15251296040538489436U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 11295008604679904153U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 5U)) + 2230897493419504490U) + RotL64(aNonceWordE, 17U);
            aOrbiterC = ((aWandererB + RotL64(aCross, 35U)) + 7109600123297458999U) + RotL64(aNonceWordB, 61U);
            aOrbiterB = (aWandererD + RotL64(aScatter, 53U)) + 13119156643107683803U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 11U)) + 14755160867807355250U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 20U)) + 16829363373287496832U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 16981122946707720883U) + aPhaseDOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8806000776958603317U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16810923047720876014U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17872735050219539145U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8129657889554436328U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8653100378491974463U;
            aOrbiterG = RotL64((aOrbiterG * 11395283153912468661U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17048985838727432415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10892675550889823573U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 976298937314081913U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15960158965421254346U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12290011578634850001U;
            aOrbiterE = RotL64((aOrbiterE * 9280475585104357745U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 16265047040311479093U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10312956912303656248U;
            aOrbiterC = RotL64((aOrbiterC * 3012584393253845131U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16706890352221352779U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10630955894218491929U;
            aOrbiterA = RotL64((aOrbiterA * 12675937483456206355U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4009352551041162434U) + RotL64(aNonceWordF, 57U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3043810773683888556U;
            aOrbiterF = RotL64((aOrbiterF * 4328135390387997315U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1398071019814944785U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16689766557488135301U;
            aOrbiterJ = RotL64((aOrbiterJ * 8403881916549404871U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15934647144489136524U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13521276033614992223U) ^ RotL64(aNonceWordH, 15U);
            aOrbiterK = RotL64((aOrbiterK * 18003640895553609933U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4281211055727414100U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11848150507497406421U;
            aOrbiterB = RotL64((aOrbiterB * 1107789990317433481U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12022829841608199449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12131317914288566437U;
            aOrbiterD = RotL64((aOrbiterD * 13275753083882829973U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 44U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aNonceWordA, 30U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aPhaseDWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 56U)) + aOrbiterB) + RotL64(aNonceWordG, 59U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterG, 3U));
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 26U) + aOrbiterF) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5734U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 6934U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordA, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7787U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 9831U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aScatter, 35U)) + 12426357877879529292U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 47U)) + 12604900366173639176U;
            aOrbiterC = (aWandererA + RotL64(aCross, 5U)) + 13511119007338929401U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 30U)) + 9878720081166788060U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 27U)) + 15463195409806395076U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordH, 21U);
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 6407922778852833423U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 21U)) + 7690427254160734016U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 35U)) + 18030974031722143619U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 17983938038322737041U;
            aOrbiterH = ((((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 43U)) + 16605512170117753884U) + aPhaseDOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordG, 19U);
            aOrbiterF = (aWandererK + RotL64(aIngress, 58U)) + 681802273302348322U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15550312921312083819U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1939207786756735430U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3132864634777826569U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13606281919426730325U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12822929773923954849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16576106045887115660U;
            aOrbiterG = RotL64((aOrbiterG * 16370914370769903051U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2398825881649235260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13700821892926092479U;
            aOrbiterB = RotL64((aOrbiterB * 10830623703416956043U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 2439833784883391606U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15870638514107637833U;
            aOrbiterI = RotL64((aOrbiterI * 3797380922767479287U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9165457123134229670U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8736642509192659417U;
            aOrbiterK = RotL64((aOrbiterK * 16219277537523484065U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9232719746484835693U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7826680628853322541U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12578050118133526187U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14323652326982518782U) + RotL64(aNonceWordC, 61U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2254524512851399313U;
            aOrbiterA = RotL64((aOrbiterA * 4119339547645451149U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14459632243829356472U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8591197056749497716U;
            aOrbiterE = RotL64((aOrbiterE * 13053836520694721881U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17220196418897000411U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7186579019945992185U;
            aOrbiterH = RotL64((aOrbiterH * 12406048515179065691U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7554005180895698880U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12426357877879529292U;
            aOrbiterF = RotL64((aOrbiterF * 5090046967147694465U), 39U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 42U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aPhaseDWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + RotL64(aNonceWordE, 7U));
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterH, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 44U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterG, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 34U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + (((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordD, 14U)) + aPhaseDWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordG, 56U)) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12509U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 11585U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordB, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15443U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 12686U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 13U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 4773124477323378268U;
            aOrbiterE = (aWandererC + RotL64(aCross, 29U)) + 16848723289435796005U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 13U)) + 13846642134917107058U;
            aOrbiterI = (((aWandererF + RotL64(aScatter, 14U)) + RotL64(aCarry, 29U)) + 6472057872482789939U) + RotL64(aNonceWordG, 17U);
            aOrbiterH = (aWandererH + RotL64(aIngress, 23U)) + 2747019500690707226U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 11U)) + 9003965289739733880U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 37U)) + 3013390651936257377U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordF, 31U);
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 3331004709895625067U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 19U)) + 15355010435553517129U) + aPhaseDOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 51U)) + 7709870658004280052U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 60U)) + 13568728443963926564U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12409548853419307131U) + RotL64(aNonceWordD, 13U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterJ = RotL64((aOrbiterJ * 5549220554838837145U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15370309834426476775U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3896803894396631184U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11018830202891911603U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10848873633291935766U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12885336509190543440U;
            aOrbiterE = RotL64((aOrbiterE * 1487357252619221365U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8252290890093788010U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9201553615601641350U;
            aOrbiterH = RotL64((aOrbiterH * 420321130559162915U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14014209645503188472U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4015071464301844550U;
            aOrbiterF = RotL64((aOrbiterF * 17444195018239904971U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16173085647514027347U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16916627014974363360U;
            aOrbiterG = RotL64((aOrbiterG * 7699587344277490953U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1591680303404522110U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16499606051269327916U;
            aOrbiterA = RotL64((aOrbiterA * 814405848002794813U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6932673635509444619U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8745681160108707944U;
            aOrbiterI = RotL64((aOrbiterI * 14565255558668084787U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10387263947888920455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2553335462317280031U) ^ RotL64(aNonceWordB, 37U);
            aOrbiterB = RotL64((aOrbiterB * 7253573275397985211U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17449861295444216249U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 15716408844914738774U;
            aOrbiterD = RotL64((aOrbiterD * 10132631423215542589U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16974370193820578179U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4773124477323378268U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8982190762960590543U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 10U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 46U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterG, 51U));
            aWandererI = aWandererI + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + RotL64(aNonceWordA, 28U));
            aWandererD = aWandererD + (((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 56U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB + (((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterJ, 21U)) + RotL64(aNonceWordC, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordA, 18U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 20352U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20454U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16803U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 18075U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 2558105147674438050U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 24U)) + 15856662514774702561U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 57U)) + 13346869226246584582U) + RotL64(aNonceWordH, 30U);
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 7632111846116243973U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 2102101361626976279U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 51U)) + 5605968705067851563U;
            aOrbiterB = (aWandererF + RotL64(aCross, 41U)) + 6842483186584326681U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 5U)) + 5559797213819425064U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 60U)) + 12422313931331576759U) + aPhaseDOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterI = (aWandererD + RotL64(aIngress, 11U)) + 2751024420047872601U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 35U)) + 11031320239359798610U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14366375309473793217U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11971479429768505316U;
            aOrbiterH = RotL64((aOrbiterH * 10063001532313098203U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3947595951884469542U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17882767922372770896U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3361906348965810211U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 513871456983509223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5951677013597794294U;
            aOrbiterC = RotL64((aOrbiterC * 8508629569649935293U), 37U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 437626309049021931U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordD, 13U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 466674061172005705U) ^ RotL64(aNonceWordC, 35U);
            aOrbiterB = RotL64((aOrbiterB * 1310502572084891157U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12362602809233133718U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10525852878882195702U;
            aOrbiterJ = RotL64((aOrbiterJ * 17755022180514914325U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17927000184308583095U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 566723721423470052U;
            aOrbiterA = RotL64((aOrbiterA * 17710534355278632573U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9504585484034413577U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 4614306037721859929U;
            aOrbiterI = RotL64((aOrbiterI * 170807293799483539U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 1463218357720031588U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4036696102163560633U;
            aOrbiterE = RotL64((aOrbiterE * 15389914226155130065U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9907678911300898726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11804311892289601322U;
            aOrbiterD = RotL64((aOrbiterD * 13986106774841242253U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6514645538508331396U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17246364354815744899U;
            aOrbiterF = RotL64((aOrbiterF * 12800661037742526999U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6725706155285333764U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2558105147674438050U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6752457079901154727U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 18U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 21U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 39U)) + aOrbiterE) + RotL64(aNonceWordA, 39U));
            aWandererC = aWandererC + ((RotL64(aIngress, 56U) + RotL64(aOrbiterC, 54U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aNonceWordF, 61U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterI, 26U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aScatter, 38U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 12U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 30U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23985U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22228U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordF, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22204U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24452U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 38U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (((aWandererH + RotL64(aScatter, 47U)) + 17711946802293254150U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 16652362590489569378U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 6972810344198183097U;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 13117100889782940546U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 19U)) + 13199305696782626591U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 6U)) + 992156184392760945U;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 37U)) + 13791265442074543880U) + RotL64(aNonceWordA, 25U);
            aOrbiterK = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 21U)) + 17057087245252294859U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 39U)) + 13444195995883541046U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 11U)) + 6723678233676059420U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 26U)) + RotL64(aCarry, 35U)) + 7913379431208430475U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 4481887195529300665U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordF, 5U);
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11892724101424384078U;
            aOrbiterF = RotL64((aOrbiterF * 3468639499716604111U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7700902083270424194U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1888001433557140271U;
            aOrbiterJ = RotL64((aOrbiterJ * 8975562955027025349U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14996753906788986929U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 939004845422123765U;
            aOrbiterK = RotL64((aOrbiterK * 2507090308972292313U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11922230289291941807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15681187459741147199U;
            aOrbiterE = RotL64((aOrbiterE * 10124947739653819101U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9119043713532718155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 8327697433992362166U;
            aOrbiterA = RotL64((aOrbiterA * 11157657162184304567U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13630755116592440359U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 771252613886022889U;
            aOrbiterD = RotL64((aOrbiterD * 2958918915223536519U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8524239721467527770U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17732617735422435572U;
            aOrbiterH = RotL64((aOrbiterH * 13992947983987668631U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5265753270696005619U) + RotL64(aNonceWordE, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 14456128349522985053U;
            aOrbiterC = RotL64((aOrbiterC * 5406509991740849617U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12909993509014176457U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10113568710432654194U;
            aOrbiterB = RotL64((aOrbiterB * 6857806395910432831U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14818978163348513071U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17843349910031998923U;
            aOrbiterI = RotL64((aOrbiterI * 13608449524810499593U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12589077818524017161U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17711946802293254150U;
            aOrbiterG = RotL64((aOrbiterG * 9454569713107675231U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterI) + RotL64(aNonceWordD, 51U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterH, 40U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 18U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 35U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aNonceWordB, 12U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 50U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordH, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29296U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 32337U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31969U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 29644U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 39U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 19U)) + 6733949564325516029U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 23U)) + 7304098437143918796U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 28U)) + 3923949518391777800U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordG, 60U);
            aOrbiterG = (aWandererE + RotL64(aPrevious, 3U)) + 14243591003388927124U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 11U)) + 18329498724605410406U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 5U)) + 13118172167747037249U) + aPhaseDOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 11U);
            aOrbiterI = (aWandererF + RotL64(aCross, 53U)) + 5272025143849174212U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 16075917179214318424U;
            aOrbiterC = (aWandererK + RotL64(aCross, 60U)) + 15263590648674658399U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 13730046728289525921U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 7703141464499623408U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 1382279753822135359U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2973369221699098292U;
            aOrbiterJ = RotL64((aOrbiterJ * 7440242040663550631U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11578274119583013219U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3419411247737896674U;
            aOrbiterB = RotL64((aOrbiterB * 17814942652262802991U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2582783513078999303U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3959762790273529677U;
            aOrbiterE = RotL64((aOrbiterE * 383974377372162751U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 465795011576934604U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17880826624185821135U) ^ RotL64(aNonceWordB, 59U);
            aOrbiterI = RotL64((aOrbiterI * 4445949147592860913U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10819659185349413173U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17298208553586835030U;
            aOrbiterK = RotL64((aOrbiterK * 1965860510614222093U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12585880006661489402U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16650193903267408586U) ^ RotL64(aNonceWordC, 13U);
            aOrbiterC = RotL64((aOrbiterC * 5781132589396936615U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 885882046325991589U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 869560078374809974U;
            aOrbiterD = RotL64((aOrbiterD * 13440973563438747181U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 11871305571797951851U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12137095015607196226U;
            aOrbiterA = RotL64((aOrbiterA * 7618152256560808581U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6044048326509186958U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 622564532811968856U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14988345089359014037U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17133994029325040272U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8612895899003926829U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2128664397481732179U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2169081503433534750U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6733949564325516029U;
            aOrbiterG = RotL64((aOrbiterG * 10062179904046311601U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 20U) + aOrbiterH) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 20U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 60U));
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH + ((((RotL64(aCross, 52U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterD, 53U)) + RotL64(aNonceWordD, 5U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + RotL64(aNonceWordH, 61U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC4A7B564A8DF4F41ULL + 0x9DB7EAE3C1B06C50ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x966DD264363AECA3ULL + 0xF39A6EC935F74B3BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEDFFFE1338B36B37ULL + 0xD33D84F9B0DB390AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9C9C7A0A32C14F0DULL + 0xE7F6D343A608E5E5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB498C94D52F1BC55ULL + 0xAE61FB242395D470ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAF500364DE00B8B9ULL + 0xFAEEA2BD81330BB9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF1225FAE7BD02853ULL + 0xC630A3CB35992501ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFF347149AB4A82D7ULL + 0x9E9576FAC6327A03ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordD, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3601U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 279U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordG, 52U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 184U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4210U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 53U)) + 9630214189402543339U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 11U)) + 4072576573737526819U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 15994787452709618869U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 39U)) + 6403240137132259482U;
            aOrbiterB = ((((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 10229266900170507720U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordB, 25U);
            aOrbiterG = (aWandererF + RotL64(aPrevious, 24U)) + 5025294577989748989U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 21U)) + 16696461238217956883U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 27U)) + 9878318855341719119U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 16086635438116177346U;
            aOrbiterE = (aWandererG + RotL64(aCross, 29U)) + 12295437783084203730U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 34U)) + 7681150419912842402U) + RotL64(aNonceWordF, 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2639104034287637448U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12298170009332243573U;
            aOrbiterK = RotL64((aOrbiterK * 9397919591171238575U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3485932317267669626U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16569551670038752475U;
            aOrbiterG = RotL64((aOrbiterG * 8139802826402217631U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 4448490103784103954U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14510534073046885941U;
            aOrbiterC = RotL64((aOrbiterC * 7777192047386438305U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 4286195398675733451U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15790355933840266463U;
            aOrbiterF = RotL64((aOrbiterF * 13342257823027075501U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6362891510370156055U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15121822034579983174U;
            aOrbiterJ = RotL64((aOrbiterJ * 7268045994574844937U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13817341015719915628U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14113474087906143783U;
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9988301252236121106U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11287477288382171758U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4979297247881426383U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9491727010910328644U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7961202721830514030U;
            aOrbiterI = RotL64((aOrbiterI * 16300364540313620767U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10058066852293995222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 541563830282750968U;
            aOrbiterB = RotL64((aOrbiterB * 1516823517052019845U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 7791201128863372861U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8334318157449352359U) ^ RotL64(aNonceWordG, 43U);
            aOrbiterD = RotL64((aOrbiterD * 2924838607279239375U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6861081455774799715U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9630214189402543339U) ^ RotL64(aNonceWordH, 10U);
            aOrbiterE = RotL64((aOrbiterE * 10837610668580336781U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC + ((RotL64(aScatter, 18U) + RotL64(aOrbiterK, 43U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterB, 35U)) + RotL64(aNonceWordA, 35U));
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + RotL64(aOrbiterH, 37U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 20U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterG, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 34U) + aOrbiterJ) + RotL64(aOrbiterC, 40U)) + RotL64(aNonceWordE, 19U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 54U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 44U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10468U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6113U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 52U) ^ RotL64(aNonceWordE, 5U)) ^ RotL64(aNonceWordH, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7380U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 10643U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 8506388683755208267U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 39U)) + 2179323259055019735U) + RotL64(aNonceWordA, 21U);
            aOrbiterI = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 3345902531140983016U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 22U)) + 17456139311481306584U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 29U)) + 14587864088462311164U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 27U)) + 13178947246650647057U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 41U)) + 12866578138946916962U) + RotL64(aNonceWordB, 36U);
            aOrbiterE = ((aWandererD + RotL64(aCross, 47U)) + 13098524333655118173U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 3U)) + 15451329483787541982U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 9494299579678389385U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 54U)) + 15581954810375490643U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4487042505730624892U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2774455928791636186U;
            aOrbiterI = RotL64((aOrbiterI * 15847933919136777451U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12435319582397755819U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10077180055177766823U;
            aOrbiterK = RotL64((aOrbiterK * 3924363471701748703U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10391963896910956455U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 6149237416725301794U;
            aOrbiterB = RotL64((aOrbiterB * 10115917698918612823U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15673402771629639978U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14729117178956592426U;
            aOrbiterH = RotL64((aOrbiterH * 9070464269215820531U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 14492001279368870240U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6278248084483259952U;
            aOrbiterA = RotL64((aOrbiterA * 16731228350971263873U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15727518866499740411U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8652631010810965473U;
            aOrbiterG = RotL64((aOrbiterG * 9508484121620912715U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13660890300188313775U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14699253534935936300U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3978135617259934869U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1621689916308271346U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5651399428852950385U;
            aOrbiterD = RotL64((aOrbiterD * 12220143634120124133U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 9833573729127477238U) + RotL64(aNonceWordF, 37U);
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11171647423058940388U;
            aOrbiterE = RotL64((aOrbiterE * 9692915620701425697U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10346908196429120039U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11972183669378621435U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterF = RotL64((aOrbiterF * 12364429258926549335U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11063215816236490488U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8506388683755208267U;
            aOrbiterJ = RotL64((aOrbiterJ * 11514304191652750181U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 27U)) + aOrbiterC) + RotL64(aNonceWordC, 13U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterG, 38U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterD, 43U)) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 44U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aNonceWordG, 29U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterD, 36U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordC, 57U)) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15564U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12937U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11373U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 12011U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 3550722402315312207U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 60U)) + 16724184551669522754U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aIngress, 27U)) + 981751330116773021U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 21U)) + 7891159229704944868U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 51U)) + 13618396711464799841U) + RotL64(aNonceWordE, 9U);
            aOrbiterD = (aWandererK + RotL64(aIngress, 19U)) + 5969291018449003648U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 3U)) + 14595540413313640042U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 34U)) + 3287990436916111762U) + RotL64(aNonceWordB, 23U);
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 12534369400200483704U;
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 2277312067930392274U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 10026320559261334353U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11258082063135659551U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1445958517675746990U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10062265337488757971U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1011298251290970844U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6487834862470043744U;
            aOrbiterD = RotL64((aOrbiterD * 15477913837027179675U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9966279022928268335U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10285993486057704393U;
            aOrbiterA = RotL64((aOrbiterA * 15965714363201157535U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16005362468813966136U) + RotL64(aNonceWordC, 59U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 223843444699390781U;
            aOrbiterH = RotL64((aOrbiterH * 665392038954573081U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18178876294968532775U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 12490136112181806806U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) ^ RotL64(aNonceWordH, 55U);
            aOrbiterE = RotL64((aOrbiterE * 16380841616662993709U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8775696166557913635U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16464340319444310842U;
            aOrbiterC = RotL64((aOrbiterC * 18111632334728200721U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6296039992673546227U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7152939277656436037U;
            aOrbiterB = RotL64((aOrbiterB * 15183918431501487319U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14066791413416223271U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5026743227399908016U;
            aOrbiterJ = RotL64((aOrbiterJ * 5891343232759075675U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12923870516588764609U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2509970166609982397U;
            aOrbiterF = RotL64((aOrbiterF * 10708677957633925007U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15155802288437422950U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15615656627428205711U;
            aOrbiterI = RotL64((aOrbiterI * 6199439196177598589U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17233751123865498186U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3550722402315312207U;
            aOrbiterG = RotL64((aOrbiterG * 2247546626523919155U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterE, 56U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterC, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 60U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 43U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 34U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aNonceWordD, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + RotL64(aNonceWordF, 14U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 18U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 10U) ^ RotL64(aNonceWordB, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18764U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 20395U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 35U) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18220U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20336U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 12U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 9751314027302668907U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 30U)) + 12175450995523107056U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 53U)) + 17519694958730119552U) + RotL64(aNonceWordE, 45U);
            aOrbiterD = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 9093525527925682263U) + RotL64(aNonceWordH, 6U);
            aOrbiterG = (aWandererE + RotL64(aIngress, 27U)) + 3713831321786810138U;
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 10108355209191835040U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 51U)) + 12956307447311314768U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 5U)) + 1904298513945877359U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 4658049993308574460U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 44U)) + 9826333658248851902U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 12058666914724365134U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2516574707110528099U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8230749255538495304U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16536559486797811486U;
            aOrbiterG = RotL64((aOrbiterG * 7097036838156464969U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12387639130570188998U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 8459259798142872020U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8001346480955847013U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 16083784052002800300U) + RotL64(aNonceWordG, 43U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1957284290736468379U;
            aOrbiterF = RotL64((aOrbiterF * 5046501301740813065U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7349538179311335863U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16395170077006105258U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4230485452156662763U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3317652065873784068U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5517155804799120700U;
            aOrbiterK = RotL64((aOrbiterK * 9789270651974719183U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5568525912112200094U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9334250662962319598U;
            aOrbiterE = RotL64((aOrbiterE * 5034887614541768961U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5641394627075994165U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13524971148931512745U;
            aOrbiterC = RotL64((aOrbiterC * 3699457147759854357U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15124425790244392471U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7896294947517723306U;
            aOrbiterH = RotL64((aOrbiterH * 7526632360108129915U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 15241686066829586263U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordA, 7U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12099799118961857495U;
            aOrbiterI = RotL64((aOrbiterI * 10456171163074630861U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17529688916595727188U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9751314027302668907U;
            aOrbiterD = RotL64((aOrbiterD * 521888849578281715U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 35U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 30U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aNonceWordF, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 22U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 28U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + RotL64(aOrbiterF, 23U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 44U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + RotL64(aNonceWordC, 13U));
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 10U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 22U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25210U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24108U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordC, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22013U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 25243U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 43U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 44U)) + 6469584119078165548U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 39U)) + 14329756366517987910U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 12890831797059772123U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 51U)) + 3164503807500018990U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 41U)) + 177531431387646836U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 3167421392893561015U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 2813174781844753460U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordG, 55U);
            aOrbiterD = (aWandererK + RotL64(aCross, 18U)) + 10953270419153249857U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 13U)) + 16911518309710356951U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 39U)) + 6616750447844893150U) + RotL64(aNonceWordE, 35U);
            aOrbiterF = (aWandererI + RotL64(aPrevious, 3U)) + 10276741398025985982U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6206043608461213208U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12021552904553405793U;
            aOrbiterK = RotL64((aOrbiterK * 10023362889960174909U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15283586234744144846U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5923238786775948571U;
            aOrbiterE = RotL64((aOrbiterE * 8200882393521882651U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11044014510971660078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9351141024085076044U;
            aOrbiterD = RotL64((aOrbiterD * 13316079344614432317U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17703395981862992420U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10154548848376027087U;
            aOrbiterJ = RotL64((aOrbiterJ * 12324478347590509035U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8836420852291617425U) + RotL64(aNonceWordD, 27U);
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10193385413543886344U;
            aOrbiterG = RotL64((aOrbiterG * 824935982418585449U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8248580084535685190U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3910083671888152974U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17825311776715895927U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12350341628569930642U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2565977481575002842U;
            aOrbiterC = RotL64((aOrbiterC * 18233446879833776677U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9271041067874027417U) + RotL64(aNonceWordB, 18U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14289254596554201861U;
            aOrbiterB = RotL64((aOrbiterB * 7985522692852251413U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5981802134118235214U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 14047813418129636856U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15961435325216504877U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11808443842149398212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11380858372643695792U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 100198424024622179U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10385375464069162356U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6469584119078165548U;
            aOrbiterI = RotL64((aOrbiterI * 5263876933019848989U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 58U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 4U) + aOrbiterI) + RotL64(aOrbiterC, 12U)) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 19U)) + RotL64(aNonceWordA, 39U));
            aWandererA = aWandererA + (((RotL64(aScatter, 54U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterD, 14U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterG) + RotL64(aNonceWordF, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 37U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28993U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30253U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 35U) ^ RotL64(aNonceWordD, 52U)) ^ RotL64(aNonceWordA, 13U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32656U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28622U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCarry, 28U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 29U)) + 12131317914288566437U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 30U);
            aOrbiterI = (aWandererD + RotL64(aIngress, 5U)) + 5672805657999385496U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 46U)) + 3581710244233124197U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 57U)) + 15251296040538489436U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 11295008604679904153U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 39U)) + 2230897493419504490U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + 7109600123297458999U) + RotL64(aNonceWordH, 31U);
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 13119156643107683803U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 14755160867807355250U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 53U)) + 16829363373287496832U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 34U)) + 16981122946707720883U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8806000776958603317U) + RotL64(aNonceWordG, 27U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16810923047720876014U;
            aOrbiterA = RotL64((aOrbiterA * 17872735050219539145U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8129657889554436328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8653100378491974463U;
            aOrbiterK = RotL64((aOrbiterK * 11395283153912468661U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17048985838727432415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10892675550889823573U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 976298937314081913U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15960158965421254346U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12290011578634850001U;
            aOrbiterF = RotL64((aOrbiterF * 9280475585104357745U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16265047040311479093U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10312956912303656248U;
            aOrbiterE = RotL64((aOrbiterE * 3012584393253845131U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16706890352221352779U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10630955894218491929U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12675937483456206355U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4009352551041162434U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3043810773683888556U;
            aOrbiterG = RotL64((aOrbiterG * 4328135390387997315U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1398071019814944785U) + RotL64(aNonceWordA, 3U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16689766557488135301U;
            aOrbiterD = RotL64((aOrbiterD * 8403881916549404871U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15934647144489136524U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13521276033614992223U;
            aOrbiterC = RotL64((aOrbiterC * 18003640895553609933U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4281211055727414100U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11848150507497406421U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1107789990317433481U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12022829841608199449U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12131317914288566437U;
            aOrbiterJ = RotL64((aOrbiterJ * 13275753083882829973U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 20U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + RotL64(aNonceWordF, 49U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterA, 24U)) + RotL64(aNonceWordD, 13U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 58U) + aOrbiterJ) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 18U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 51U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Hockey_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE23F78D4A35A2DE5ULL + 0xE00C68B1698B8557ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEBD618CE78EB4029ULL + 0xDF655E34E9C7C89DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x854484F6CF18F2A3ULL + 0xB7E7DFF8900F446AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA6778639FC35DC25ULL + 0xD9136A57B6D2C019ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB74734B71611C659ULL + 0xDE3C63A5E9CBE857ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCB8D98FC6549B53FULL + 0xDBA0BE91BE8A202DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDFB315DE9DE12D77ULL + 0xF2CB2F871F996706ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDEC1846A2577BA0FULL + 0x93A9A5CBAF6C7E23ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordH, 34U)) ^ RotL64(aNonceWordA, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4402U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5448U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordB, 4U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3302U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4254U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 5U)) + 5088525177670191619U;
            aOrbiterJ = ((((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 9966456257813932112U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 61U);
            aOrbiterI = (aWandererG + RotL64(aCross, 21U)) + 7707646574027146307U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 14U)) + 75480203757681173U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 35U)) + 384659134071835163U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 23U)) + 3158769775373307778U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 19U)) + 17360830943513941272U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 37U)) + 5317278822721604586U) + RotL64(aNonceWordH, 25U);
            aOrbiterE = (aWandererA + RotL64(aPrevious, 12U)) + 1371427105215954781U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 41U)) + 3162710551223553423U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 5332921933853550756U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10572462410297815854U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 10234389605554817892U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2130374833440291193U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13421365517991380605U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10186643614984034083U;
            aOrbiterA = RotL64((aOrbiterA * 8554471709467808453U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4742438973260817120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15360092808493795340U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12186413069553132646U;
            aOrbiterK = RotL64((aOrbiterK * 3815981440611914267U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16756221656224451552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12232880965861373143U;
            aOrbiterH = RotL64((aOrbiterH * 14196910735715726471U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10090954323470840557U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 15615770271463853537U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13544181592829027283U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 556029032505658411U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13311879111583579039U;
            aOrbiterC = RotL64((aOrbiterC * 3924744868168749003U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8646360871497847336U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2064833941982069154U) ^ RotL64(aNonceWordB, 49U);
            aOrbiterJ = RotL64((aOrbiterJ * 10016546852137913163U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 1701847261278886621U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9654208200019718374U) ^ RotL64(aNonceWordF, 10U);
            aOrbiterF = RotL64((aOrbiterF * 4398089490129603677U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14276143262844412074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10738184916176200661U;
            aOrbiterB = RotL64((aOrbiterB * 8940267914440361883U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2966052720680305600U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5088525177670191619U;
            aOrbiterG = RotL64((aOrbiterG * 11621585388684456139U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceWordG, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 27U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 12U)) + RotL64(aNonceWordE, 59U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 54U) + aOrbiterH) + RotL64(aOrbiterI, 43U)) + aPhaseFWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 51U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordE, 60U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7952U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7745U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 34U) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6439U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 9794U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 24U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aCross, 43U)) + 4068921616130916949U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 12077715273915151726U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 19U)) + 16047546802670596833U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 47U)) + 9690277462716999763U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 41U)) + 14484814700447992628U) + RotL64(aNonceWordF, 35U);
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + 17089267243053958210U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 54U)) + 9138746214446211147U;
            aOrbiterA = (aWandererG + RotL64(aCross, 23U)) + 10181001536979097045U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 21U)) + 6657458969093373191U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 7515983477876590988U) + RotL64(aNonceWordA, 51U);
            aOrbiterJ = ((aWandererH + RotL64(aCross, 52U)) + RotL64(aCarry, 29U)) + 3039935555863947600U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16209389224740851136U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 725253312098083182U;
            aOrbiterG = RotL64((aOrbiterG * 17535989492095522597U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13307041115748941383U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7159572004825238263U;
            aOrbiterK = RotL64((aOrbiterK * 4855009895002398449U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12027236743251643820U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8717826175991286553U;
            aOrbiterH = RotL64((aOrbiterH * 1175614802543098451U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4769096034227659937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11201226563992939616U;
            aOrbiterC = RotL64((aOrbiterC * 15595355978388159931U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17295978531215563256U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11850923890626719833U) ^ RotL64(aNonceWordH, 27U);
            aOrbiterB = RotL64((aOrbiterB * 3854851059897397075U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 14139441565288097706U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 988684899382304485U;
            aOrbiterI = RotL64((aOrbiterI * 11929090869999700891U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6159251276942253175U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4849529993914550651U;
            aOrbiterF = RotL64((aOrbiterF * 18240712676783671317U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6679745455842119497U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15838404437552215214U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17357853511591350887U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15853153471104458948U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12542164757451566994U) ^ RotL64(aNonceWordB, 42U);
            aOrbiterA = RotL64((aOrbiterA * 12163611303899312043U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14304233464055838869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4037999346933039765U;
            aOrbiterD = RotL64((aOrbiterD * 564236202758328407U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3582312827630995454U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4068921616130916949U;
            aOrbiterJ = RotL64((aOrbiterJ * 1527829107415867363U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 30U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + RotL64(aNonceWordC, 17U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 42U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 27U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 23U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 48U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 10U) + aOrbiterB) + RotL64(aOrbiterJ, 19U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + RotL64(aNonceWordD, 59U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 20U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 53U) ^ RotL64(aNonceWordH, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13838U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 11760U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 60U) ^ RotL64(aNonceWordG, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14256U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11617U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 56U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aIngress, 39U)) + 3236820517816085022U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 43U)) + 741288875914097926U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 22U)) + 8417246926007729580U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 57U)) + 9715717805774537170U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 14360243844821619482U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 41U)) + 10760908100206775334U) + RotL64(aNonceWordB, 37U);
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 21U)) + 3434641779946167811U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 35U)) + 7885568822756234567U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 24U)) + 3041563437672051294U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 47U)) + 15761355327564963516U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 1158633562785937421U) + RotL64(aNonceWordE, 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9338581575871970653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14653924713599790081U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3854497592598563309U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11737111068815795303U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16286980180327600557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5092583772591249756U;
            aOrbiterB = RotL64((aOrbiterB * 13955105624639442903U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4288397994175567333U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15584236478994873104U;
            aOrbiterJ = RotL64((aOrbiterJ * 1860480595862755379U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5557463939827483792U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2659814275753280856U;
            aOrbiterF = RotL64((aOrbiterF * 17702430405693184643U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6941807963525063449U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 2040598555191211307U;
            aOrbiterG = RotL64((aOrbiterG * 14750544987531722765U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 347572666231116258U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 779304821185302523U) ^ RotL64(aNonceWordH, 25U);
            aOrbiterA = RotL64((aOrbiterA * 14180254150318109855U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10632524582873079742U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9761308771280517212U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13926235411726048921U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2097439707055737964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2813977930321463948U;
            aOrbiterK = RotL64((aOrbiterK * 14983538728730662603U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6080592019313796689U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5396623654821376409U;
            aOrbiterH = RotL64((aOrbiterH * 15478858835919398677U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8460497459575045342U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 3236820517816085022U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordA, 59U);
            aOrbiterE = RotL64((aOrbiterE * 5530411244458067093U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 22U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 47U)) + aOrbiterB) + RotL64(aNonceWordC, 14U));
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterH, 50U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererI = aWandererI + (((RotL64(aScatter, 24U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 10U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererF = aWandererF + ((((RotL64(aCross, 44U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + RotL64(aNonceWordD, 17U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 21U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordA, 60U)) ^ RotL64(aNonceWordH, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16797U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 21282U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordE, 12U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21694U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 17126U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCross, 3U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aPrevious, 23U)) + 11410829607777684449U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 43U)) + 7502698839700975347U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 60U)) + 13267685058252106173U) + RotL64(aNonceWordC, 8U);
            aOrbiterD = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 238242706996630625U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 47U)) + 8184695499511454281U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 35U)) + 12767823220461985403U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 21U)) + 12293198423143850330U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 11149495229952495939U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 37U)) + 7556992689338382800U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 30U)) + 3431338808774134649U;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 19U)) + 16863099140844995099U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordB, 9U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17872458049880677604U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16760153457252546974U;
            aOrbiterE = RotL64((aOrbiterE * 11225037229069712805U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3115544493537438408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4359882942759752958U;
            aOrbiterA = RotL64((aOrbiterA * 561477566995575801U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13387113067202396536U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 12955690074544490161U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterC = RotL64((aOrbiterC * 12449941770827974511U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 15614054443728226807U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1939441328066616114U;
            aOrbiterH = RotL64((aOrbiterH * 4484917074808974359U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4599016263007782537U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9962305629016158048U;
            aOrbiterG = RotL64((aOrbiterG * 1496184427500037279U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8428467674122750557U) + RotL64(aNonceWordD, 15U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3938884087806393439U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12810531094050481761U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6018636830758044658U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1510372000641305416U;
            aOrbiterI = RotL64((aOrbiterI * 9002834928626918247U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17592782466215337843U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8119921507606870360U;
            aOrbiterJ = RotL64((aOrbiterJ * 1299795061644535485U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8753237702359236964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12389957327067768090U;
            aOrbiterK = RotL64((aOrbiterK * 4586786761936601607U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17791633199762408683U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11606494383812053915U;
            aOrbiterF = RotL64((aOrbiterF * 13041480602055778521U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4418614662439151979U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11410829607777684449U;
            aOrbiterD = RotL64((aOrbiterD * 3342270212301058781U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 52U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererA = aWandererA + ((RotL64(aScatter, 34U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 10U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aNonceWordA, 5U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterF, 41U));
            aWandererE = aWandererE + (((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 21U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterH, 58U)) + RotL64(aNonceWordE, 25U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordA, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24439U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26482U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23513U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25403U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 3U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 27U)) + 11698283336767769359U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 29U)) + 13297826354831483872U;
            aOrbiterB = (aWandererA + RotL64(aCross, 14U)) + 15254999058287530795U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 21U)) + 17474166585085346567U;
            aOrbiterK = ((((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 15684783498452840289U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 43U);
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 5061229733465216486U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 53U)) + 15370981279168377944U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 17966672773619554092U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 14685092893994491068U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 12U)) + 12798804186209406389U) + RotL64(aNonceWordE, 47U);
            aOrbiterI = (aWandererE + RotL64(aPrevious, 3U)) + 2848444181474221574U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8551142075919636146U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8833198159158950723U;
            aOrbiterB = RotL64((aOrbiterB * 7650289040764974737U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7351473160893666232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7008985178526543258U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 13576796403863120356U;
            aOrbiterG = RotL64((aOrbiterG * 13745839827679114077U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5769784656937900699U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14075925808204936705U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5844894088757604713U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17818667502858010896U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 16016922065572683130U) ^ RotL64(aNonceWordB, 53U);
            aOrbiterH = RotL64((aOrbiterH * 7525645833898085373U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1582458237855075977U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10830440354527138227U;
            aOrbiterF = RotL64((aOrbiterF * 10499386926982228251U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10653964151654643772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11218475491129483859U;
            aOrbiterD = RotL64((aOrbiterD * 3338108067044357141U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9863649760189649255U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13790281439048354358U;
            aOrbiterC = RotL64((aOrbiterC * 4682098083538482849U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14846954923718136337U) + RotL64(aNonceWordG, 29U);
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 522207783972623813U;
            aOrbiterI = RotL64((aOrbiterI * 14299798934454852811U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 426829715716262697U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7482977730216354509U;
            aOrbiterJ = RotL64((aOrbiterJ * 6317437989422015173U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10736099808538972990U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11698283336767769359U;
            aOrbiterK = RotL64((aOrbiterK * 17230175904095995929U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterG, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 14U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aNonceWordF, 7U));
            aWandererI = aWandererI + (((RotL64(aIngress, 42U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + aPhaseFWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 39U)) + RotL64(aNonceWordH, 26U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 53U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 56U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 11U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32141U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30250U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordD, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30286U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 31664U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 28U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 8367680518550579791U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 11491674725611181241U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 19U)) + 16673861720782164214U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 53U)) + 9786610124108350855U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 27U)) + 5745080601557577637U) + RotL64(aNonceWordE, 43U);
            aOrbiterH = (aWandererB + RotL64(aScatter, 37U)) + 1959402215131684684U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 10U)) + 6121650036079196522U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 21U)) + 12016309761037342392U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 23U)) + 5986936646177049603U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 35U)) + 1000367700904043468U;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 17425288243569101032U) + RotL64(aNonceWordF, 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4856917474950325209U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16312111093223166419U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11046477664487805241U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 456110002032422270U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 11393724374787795662U;
            aOrbiterJ = RotL64((aOrbiterJ * 1176984359123668389U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8378176867715697176U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8086186452345234815U;
            aOrbiterH = RotL64((aOrbiterH * 8450438271765985235U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8470349167474173245U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2528229938740192694U;
            aOrbiterI = RotL64((aOrbiterI * 8717790851266520943U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 13247168811545753141U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8745293957516815264U;
            aOrbiterB = RotL64((aOrbiterB * 14270617180621072619U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6165915500564961987U) + RotL64(aNonceWordD, 20U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12015407798844173213U) ^ RotL64(aNonceWordH, 31U);
            aOrbiterF = RotL64((aOrbiterF * 3913451986559154153U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 545006684939922156U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 16366753936267185001U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6495185976430013201U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3097605623436091728U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15950167830259022926U;
            aOrbiterD = RotL64((aOrbiterD * 4415538963984293323U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8356327899232213426U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10183421678251169945U;
            aOrbiterK = RotL64((aOrbiterK * 9474380650337109299U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 16327340177970834683U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7086901180933495535U;
            aOrbiterG = RotL64((aOrbiterG * 1276521829484494857U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13421211370092080006U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8367680518550579791U;
            aOrbiterA = RotL64((aOrbiterA * 12256662446176946163U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 20U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 43U)) + RotL64(aNonceWordA, 59U));
            aWandererC = aWandererC + ((RotL64(aIngress, 20U) + aOrbiterA) + RotL64(aOrbiterD, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterI, 34U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 5U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 18U) + RotL64(aOrbiterD, 13U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG + ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterA) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 35U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterC, 23U));
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 18U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 51U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAE1F4ED55B73A9D3ULL + 0xB95E8DC452D6CC91ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E5EAB81E2B077F9ULL + 0xCFBC1EF966A8DF70ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE9F8B69F60CD6051ULL + 0xF19610B501B6DA31ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF9F05415C2969FE7ULL + 0xAFB2B83D63375D9FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x99702B01817B789BULL + 0x9C1535068202A4F5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEB0234095ADFD275ULL + 0xBB00B93B5F260278ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFAC3CF5E3BB1E60DULL + 0x84F855C6E8C98473ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9DD9879F0ABD92EBULL + 0xFBD9B0DF29F5D42DULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordB, 56U)) ^ RotL64(aNonceWordG, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1138U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4792U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 4U) ^ RotL64(aNonceWordA, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1890U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 1743U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 19U)) + 6024062041314952357U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 37U)) + 18340757093658015585U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 48U)) + 11911120493880346751U) + RotL64(aNonceWordA, 45U);
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 17428074353884654439U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aScatter, 21U)) + 12790849760814795936U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 53U)) + 12633397052172117800U) + RotL64(aNonceWordB, 39U);
            aOrbiterB = (aWandererK + RotL64(aPrevious, 50U)) + 11946150433665237945U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 16842157900909419285U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 11U)) + 14186235783224155962U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 39U)) + 13284904542579767591U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 37U)) + 11609181965078844357U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 9628562297095374984U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7850281529011259759U;
            aOrbiterD = RotL64((aOrbiterD * 17611485102925470357U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 257458718073794527U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10693404545773519306U;
            aOrbiterJ = RotL64((aOrbiterJ * 14821443722828498323U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3430519236533871460U) + RotL64(aNonceWordE, 19U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6183054506953198055U;
            aOrbiterA = RotL64((aOrbiterA * 6121082743789970911U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2905610989884221654U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4472163910775333862U;
            aOrbiterK = RotL64((aOrbiterK * 7770678426310856745U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16870142883133769663U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1403692060594816451U;
            aOrbiterB = RotL64((aOrbiterB * 9740854430251597879U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16904169913507057108U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4773518591580333357U;
            aOrbiterE = RotL64((aOrbiterE * 5306070307776061267U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6528141733853494275U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11254806909313951442U;
            aOrbiterC = RotL64((aOrbiterC * 6316669786405548827U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6857506858448143407U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2855763534355983644U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16881334940165182415U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12328391751024624740U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16475072086109949522U;
            aOrbiterH = RotL64((aOrbiterH * 15218626930666825883U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15505670341076785424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6972128419331939330U;
            aOrbiterG = RotL64((aOrbiterG * 12206069109180246067U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7151546362283646210U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 6024062041314952357U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1]) ^ RotL64(aNonceWordD, 53U);
            aOrbiterI = RotL64((aOrbiterI * 10243806128059850493U), 37U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 24U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + RotL64(aNonceWordG, 31U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 58U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 11U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 47U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aCarry, 23U)) + RotL64(aNonceWordC, 8U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterF, 51U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 36U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 19U) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8399U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((aIndex + 6985U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 11U) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6566U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 9308U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 18U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 11U)) + 5295352595333316211U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 20U)) + 2341795367042042605U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 39U)) + 10122175780504033663U) + RotL64(aNonceWordE, 53U);
            aOrbiterK = (aWandererJ + RotL64(aCross, 23U)) + 10084612804696198554U;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 16470424309851045971U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 3U)) + 656016130975227994U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 15313268829659834317U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 3795220914993923394U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 14044442220988813825U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 53U)) + 3804224626734584802U) + RotL64(aNonceWordD, 12U);
            aOrbiterE = (aWandererE + RotL64(aScatter, 58U)) + 7980006306010255693U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13746830564584711549U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11852212099729274845U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2164880979318247855U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9083223471018084847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13706723820703853346U;
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1713819986642275223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1382000168233902914U;
            aOrbiterF = RotL64((aOrbiterF * 3894160765130198157U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4540474625764565485U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1756168174375757220U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12739160208010092017U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1409297070183609309U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6082750101445444357U;
            aOrbiterD = RotL64((aOrbiterD * 17438740230251860935U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1113239890859479202U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 10932192439503964363U) ^ RotL64(aNonceWordA, 39U);
            aOrbiterA = RotL64((aOrbiterA * 5915660289913324281U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3732595033748508428U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5117760372351117286U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2671510075176315761U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7399968659654088641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14835608167871904147U;
            aOrbiterG = RotL64((aOrbiterG * 8312521710415756159U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7851355416751467648U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 262169565276199916U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11801419425408657509U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1771847554312299305U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15588805765521695222U;
            aOrbiterJ = RotL64((aOrbiterJ * 8541206691371972017U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6162696602553964144U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5295352595333316211U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterE = RotL64((aOrbiterE * 8368226841948931873U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterB, 35U));
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 23U)) + RotL64(aNonceWordF, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 46U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordC, 7U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterD, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterG, 58U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 12U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 5U) ^ RotL64(aNonceWordH, 29U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14770U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneA[((aIndex + 11488U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 19U) ^ RotL64(aNonceWordC, 60U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15682U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15761U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 10U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 7960325128608297381U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 12773836012104052042U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 3173972621347773016U) + RotL64(aNonceWordB, 25U);
            aOrbiterJ = ((aWandererK + RotL64(aCross, 60U)) + 3708401356314308171U) + RotL64(aNonceWordG, 9U);
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 21U)) + 950774285720019449U) + aPhaseFOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aIngress, 57U)) + 4170092315705438265U;
            aOrbiterB = (aWandererF + RotL64(aCross, 41U)) + 17000449130864980747U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 43U)) + 8793910540062893860U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 30U)) + 520277969543516469U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 23U)) + 12762214857389827271U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 35U)) + 2932451184340207695U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11062179998786293839U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7919119215271524178U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9053677007180081359U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1774988449597115155U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3799792889466518953U;
            aOrbiterH = RotL64((aOrbiterH * 17512791286490623455U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1815062051307896589U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15260373951371654483U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2208604434669491625U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12867546628945676853U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7772820973895846946U;
            aOrbiterE = RotL64((aOrbiterE * 7581704643538761985U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14213957831821966834U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16561105721170419454U) ^ RotL64(aNonceWordA, 13U);
            aOrbiterG = RotL64((aOrbiterG * 2540533987337175367U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16556502948339949526U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9706742922075498974U;
            aOrbiterF = RotL64((aOrbiterF * 8527361328901355457U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13455756934917486016U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 9107769876332723454U;
            aOrbiterC = RotL64((aOrbiterC * 1722386100852683783U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 15793099079168487016U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7968278803691283365U;
            aOrbiterJ = RotL64((aOrbiterJ * 11644765391940099387U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15068302421261745111U) + RotL64(aNonceWordE, 19U);
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11373111908765197862U;
            aOrbiterB = RotL64((aOrbiterB * 17756438368103196771U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6362100123286229887U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 528778333872160609U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17377710146983314215U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6116442644744391285U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7960325128608297381U;
            aOrbiterD = RotL64((aOrbiterD * 17826511435509927061U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 44U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterK, 13U));
            aWandererF = aWandererF + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + RotL64(aCarry, 35U)) + RotL64(aNonceWordF, 48U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 26U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 36U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + RotL64(aNonceWordD, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 24U) ^ RotL64(aNonceWordG, 51U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20691U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16900U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17666U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20133U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 37U)) + 7896237440058555694U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 11U)) + 11870529476037558635U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + 9158983227801569448U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 5U)) + 4710172270996950329U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 39U)) + 14634482800356647630U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 8822207952170610891U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 41U)) + 13755891414028982553U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 54U)) + 4555293067488040719U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 13U)) + 2816805148093762081U;
            aOrbiterC = ((aWandererD + RotL64(aCross, 23U)) + 2122631477965135190U) + RotL64(aNonceWordB, 52U);
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 4592922416380416071U) + RotL64(aNonceWordH, 9U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 7102471666524164715U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17274623547879474204U;
            aOrbiterA = RotL64((aOrbiterA * 5443572270546181789U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 938587316977094680U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18258015823797023523U;
            aOrbiterE = RotL64((aOrbiterE * 6068819567674605919U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5809987756043471595U) + RotL64(aNonceWordE, 7U);
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5083075160112581620U;
            aOrbiterF = RotL64((aOrbiterF * 3313957222154937503U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5960021727750946496U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5967477320950630150U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 330964768256424655U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6578428711689296132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5601728218197771276U;
            aOrbiterD = RotL64((aOrbiterD * 9552559022315971847U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7923809409017855241U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16479366540906497019U;
            aOrbiterK = RotL64((aOrbiterK * 7118578387798460919U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17000467091738009736U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6801634573655508028U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10584635770060137089U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 123668445682719574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14462802805503986316U;
            aOrbiterG = RotL64((aOrbiterG * 12398236364304875941U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2433338393261685871U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13869012262404991729U;
            aOrbiterB = RotL64((aOrbiterB * 12443261517483942937U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4832421585086516998U) + RotL64(aNonceWordD, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11284414949564414958U;
            aOrbiterI = RotL64((aOrbiterI * 1586650935440790991U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17872556812561387030U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7896237440058555694U;
            aOrbiterH = RotL64((aOrbiterH * 16784165278693056013U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 36U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 35U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 44U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aNonceWordF, 41U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 58U) ^ RotL64(aNonceWordB, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25039U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 25293U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 23U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordA, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24241U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25557U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 29U)) + 5173905450211892891U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 3555542451908039957U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 39U)) + 11559884700283861559U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 3U)) + 1352524329968738673U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 3U)) + 8914206450420616349U) + RotL64(aNonceWordG, 49U);
            aOrbiterH = (aWandererA + RotL64(aPrevious, 41U)) + 2251523378498463946U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 9541575923299247038U) + RotL64(aNonceWordE, 41U);
            aOrbiterB = (aWandererD + RotL64(aCross, 5U)) + 1239854507907214595U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 56U)) + 17698101462598498934U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 11U)) + 12305566971683256060U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 35U)) + 13804545036303215569U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10239749097704329264U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4212214906286320308U;
            aOrbiterG = RotL64((aOrbiterG * 3661436621615751071U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12192418916967430783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4475514289326450361U;
            aOrbiterH = RotL64((aOrbiterH * 17497164630368757887U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 17376102613298827459U) + RotL64(aNonceWordD, 7U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18129393209955439341U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6404089025014118979U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4014763724300253568U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17325007199676828814U;
            aOrbiterJ = RotL64((aOrbiterJ * 1420888274815627083U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15480474849292388685U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14357924730184375449U;
            aOrbiterF = RotL64((aOrbiterF * 16723492259068034209U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4335731868597970070U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 8296023680394303015U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordF, 38U);
            aOrbiterK = RotL64((aOrbiterK * 14027415401430120543U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2807312426993262800U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15510369660839648501U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18207954408298333959U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12597844696606519907U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7231012798553551535U;
            aOrbiterD = RotL64((aOrbiterD * 2841306785994479299U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 849663631945232360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4002310581470781194U;
            aOrbiterI = RotL64((aOrbiterI * 2148877014350721479U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16067735571435654555U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4607980694199923842U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10401780756830017477U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5346879191913449715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5173905450211892891U;
            aOrbiterE = RotL64((aOrbiterE * 15360571827429301833U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 34U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 5U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterH, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 38U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aNonceWordC, 5U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + RotL64(aNonceWordA, 31U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30492U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28247U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 47U) ^ RotL64(aNonceWordE, 30U)) ^ RotL64(aNonceWordB, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29233U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 29727U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 40U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + 13481227414590594621U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 58U)) + 17425964381118918026U) + RotL64(aNonceWordF, 15U);
            aOrbiterF = (aWandererA + RotL64(aScatter, 21U)) + 4792004356135956581U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 39U)) + 11926849936000639098U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 51U)) + 990697329347742142U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 27U)) + 9307721505373076588U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 17605732738841908719U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 19U)) + 13110764518634187439U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + 17970109897810645911U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 10273133817644703654U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 44U)) + RotL64(aCarry, 11U)) + 11239046688920468137U) + RotL64(aNonceWordD, 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8355821483275763145U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15522151127786049345U;
            aOrbiterF = RotL64((aOrbiterF * 4844278537850520413U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5381663179722418112U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9551368011768104906U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14202470972121732997U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16264476585232221270U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7721417776432288282U;
            aOrbiterA = RotL64((aOrbiterA * 10267770327791051869U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 339418090653475277U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 3247926250495935511U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ RotL64(aNonceWordH, 41U);
            aOrbiterB = RotL64((aOrbiterB * 16824669543765729097U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3390560045236418590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3894024951542543635U;
            aOrbiterE = RotL64((aOrbiterE * 10599637790900418767U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3878539166189668154U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5617705593218220843U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterJ = RotL64((aOrbiterJ * 82771190372750823U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12320861089148474544U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14943790251625519550U;
            aOrbiterK = RotL64((aOrbiterK * 13758322022902008313U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18119213517612562775U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1413193144229486646U;
            aOrbiterH = RotL64((aOrbiterH * 14562375280658115687U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14810150213456844196U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8468712395797520201U;
            aOrbiterC = RotL64((aOrbiterC * 8167911669632436949U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 13501570100536254566U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 15409772061478100850U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 955182899606655851U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8621805947309982779U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13481227414590594621U;
            aOrbiterD = RotL64((aOrbiterD * 9591362493722704105U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 20U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterI, 29U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aNonceWordA, 54U)) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + aOrbiterG) + RotL64(aOrbiterK, 42U));
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 27U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 60U)) + RotL64(aNonceWordC, 55U));
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterH) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 225U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[((aIndex + 6784U)) & W_KEY1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4066U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 3127U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererC + RotL64(aCross, 36U)) + 2558105147674438050U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 51U)) + 15856662514774702561U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 13346869226246584582U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 11U)) + 7632111846116243973U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 28U)) + 2102101361626976279U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 41U)) + 5605968705067851563U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 6842483186584326681U) + aPhaseCOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 5559797213819425064U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 3U)) + 12422313931331576759U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2751024420047872601U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11031320239359798610U;
            aOrbiterB = RotL64((aOrbiterB * 8607639453141148025U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14366375309473793217U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11971479429768505316U;
            aOrbiterI = RotL64((aOrbiterI * 10063001532313098203U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3947595951884469542U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17882767922372770896U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 513871456983509223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 5951677013597794294U;
            aOrbiterE = RotL64((aOrbiterE * 8508629569649935293U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 437626309049021931U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 466674061172005705U;
            aOrbiterH = RotL64((aOrbiterH * 1310502572084891157U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12362602809233133718U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10525852878882195702U;
            aOrbiterF = RotL64((aOrbiterF * 17755022180514914325U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17927000184308583095U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 566723721423470052U;
            aOrbiterG = RotL64((aOrbiterG * 17710534355278632573U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9504585484034413577U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4614306037721859929U;
            aOrbiterJ = RotL64((aOrbiterJ * 170807293799483539U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1463218357720031588U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 4036696102163560633U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15389914226155130065U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterE, 38U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 5U)) + aOrbiterE) + aPhaseCWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 14U) + RotL64(aOrbiterJ, 12U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + aPhaseCWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + RotL64(aOrbiterI, 18U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 41U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 15893U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((aIndex + 12661U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10082U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 14147U)) & W_KEY1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aIngress, 23U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 43U)) + 13714409587461539863U) + aPhaseCOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 10U)) + 14101156723903265839U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 7063754562895369001U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aPrevious, 19U)) + 12320578575245519386U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 47U)) + 11744826789631008424U;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 38U)) + RotL64(aCarry, 5U)) + 8744816505096675597U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 29U)) + 10405435520084528645U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 1463157688070683543U;
            aOrbiterC = (aWandererI + RotL64(aCross, 53U)) + 12379603577919617703U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1343439118031348146U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16118850268070235540U;
            aOrbiterJ = RotL64((aOrbiterJ * 11184386483735388257U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14116264435819277136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5251698273012432109U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1495818611622063967U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 14806408656041403829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11569345414052398227U;
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17063874769147888574U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9927420478679581917U;
            aOrbiterE = RotL64((aOrbiterE * 9042782809534196563U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2550285599827162167U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17801534123304996448U;
            aOrbiterC = RotL64((aOrbiterC * 2160836889363614721U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6456685241021762041U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17064208177372969289U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13726627607233302493U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 18279938244131982650U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8211002229712129419U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12931373380977640645U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12795832560781931767U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 286378504074349650U;
            aOrbiterK = RotL64((aOrbiterK * 85453101173293509U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5835304250436889513U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12704972686724379659U;
            aOrbiterG = RotL64((aOrbiterG * 1198789639656336053U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 34U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterK, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 46U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterD, 39U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterE, 60U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 23U)) + aOrbiterK) + RotL64(aCarry, 27U)) + aPhaseCWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererC, 44U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24001U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 22132U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21632U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 22862U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererD + RotL64(aIngress, 35U)) + 6381335981879993247U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 57U)) + 15595429101600023172U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 6U)) + 5449234297249826461U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + 11213734849329731168U) + aPhaseCOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aIngress, 19U)) + 16438473952464514248U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 7357872882115186976U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 52U)) + RotL64(aCarry, 21U)) + 394402075160738643U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 43U)) + 11112941985410283532U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 14955125011182736212U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14770727009821304070U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11286366598129204910U;
            aOrbiterK = RotL64((aOrbiterK * 15884310771003021989U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7358400908565425780U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15635109923749114761U;
            aOrbiterB = RotL64((aOrbiterB * 12415152149408700329U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13826842523738623579U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1072811298828325231U;
            aOrbiterH = RotL64((aOrbiterH * 9662800288646215083U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4017334196009350776U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8812213572751410831U;
            aOrbiterI = RotL64((aOrbiterI * 12744171921566782795U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6723457786170634403U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9785583533999417673U;
            aOrbiterA = RotL64((aOrbiterA * 7776915427605471097U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10265132640322153964U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8435670887514808087U;
            aOrbiterJ = RotL64((aOrbiterJ * 2706263045620662131U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4303823386961718326U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 4214384238167491037U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8490707334221154005U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8740835037840799136U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5988815405391206280U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17838555472135715929U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15539461383052981747U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3743772525784217714U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6352086797545969187U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 50U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterB, 14U));
            aWandererD = aWandererD + (((RotL64(aScatter, 42U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 21U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31395U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28372U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27574U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 30609U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCarry, 39U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 47U)) + 6069475454765660321U) + aPhaseCOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 11483704742497268068U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 11055697447388986418U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 57U)) + 10897095046039997004U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 12U)) + 4731637118230457840U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 43U)) + 13855839187084986751U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 11U)) + 5328208115460188239U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 37U)) + 12479538544291412985U;
            aOrbiterK = (aWandererI + RotL64(aCross, 30U)) + 10740165998792608231U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6492798157284955373U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13056825957483891921U;
            aOrbiterA = RotL64((aOrbiterA * 14882112110627751751U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2068184064919194657U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11193756120230763294U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17306750816837208999U;
            aOrbiterB = RotL64((aOrbiterB * 7949360041241439741U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12952818800389361804U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15380412293642628312U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2914662289178925547U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7706090204767242996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14598802276412649570U;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17819762117328075515U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6481384240915075101U;
            aOrbiterG = RotL64((aOrbiterG * 4836701121865783029U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 754936290510338717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15510875946573720154U;
            aOrbiterE = RotL64((aOrbiterE * 2994718968852184303U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9245381722813944586U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2629847912019726214U;
            aOrbiterK = RotL64((aOrbiterK * 6718795794951106961U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3909987749797113773U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9277056074757335265U;
            aOrbiterC = RotL64((aOrbiterC * 11580847505996697115U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 35U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 22U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 6U) + aOrbiterA) + RotL64(aOrbiterF, 18U)) + aPhaseCWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterF) + aPhaseCWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 46U) + RotL64(aOrbiterF, 4U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3299U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 1876U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2105U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7155U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 10U)) + RotL64(aCarry, 5U)) + 11039986441331892533U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 6256024955965426119U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 39U)) + 9857443189988995666U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 11900944813380998208U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 27U)) + 8422577734978875541U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3100835100713928724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11871553509810206993U;
            aOrbiterB = RotL64((aOrbiterB * 15501681886909921677U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 17614749493763417027U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3638372131856199916U;
            aOrbiterC = RotL64((aOrbiterC * 480683274898147025U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6582275259281025770U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17016882418498941958U;
            aOrbiterE = RotL64((aOrbiterE * 4269869255230867823U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1747214688658984715U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9356088987044015278U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16221733545319753695U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4056238112133473456U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16013150119949532998U;
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 42U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 54U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13625U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((aIndex + 8502U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15294U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15985U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 54U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 39U)) + 1557680213571812384U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 7387349725778021121U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 54U)) + RotL64(aCarry, 29U)) + 15379264067601586976U;
            aOrbiterH = (((aWandererA + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 3730195724576043708U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 29U)) + 9637070085323827066U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1170865717363676184U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 2750833653175252030U;
            aOrbiterF = RotL64((aOrbiterF * 1937822982381882775U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15118992811225568305U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 4974092922102988451U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10575977398702460975U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10625719096296719514U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 855167122475471865U;
            aOrbiterI = RotL64((aOrbiterI * 7441090331293158773U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11322911068958340262U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4334591909425429835U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10059025861172038183U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14263701737208936392U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 678723206735649084U;
            aOrbiterH = RotL64((aOrbiterH * 10823239851733632227U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + aPhaseDWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 13U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19925U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18697U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18723U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((aIndex + 20190U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 51U) ^ RotL64(aPrevious, 36U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 1708250618750199233U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 56U)) + 12009147777553691142U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 8393982703399156592U;
            aOrbiterA = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 3247327098356831221U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 35U)) + RotL64(aCarry, 29U)) + 3403590155376353737U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18197244558104735044U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3096253642040701606U;
            aOrbiterD = RotL64((aOrbiterD * 6656168712438620783U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8012692688785412179U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17531946907545680745U;
            aOrbiterH = RotL64((aOrbiterH * 16510602981731506381U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17687695944270225817U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16147773866007628769U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 18244641303026196497U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8839160526348897457U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14268021129087663397U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10599266240854068246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2056723540756216155U;
            aOrbiterJ = RotL64((aOrbiterJ * 13311591601230386375U), 43U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 6U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererG = aWandererG + (((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28790U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 30158U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27192U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29565U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererB + RotL64(aIngress, 30U)) + RotL64(aCarry, 47U)) + 2225397913940961213U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 13U)) + 8342544893601343643U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 162922186381417187U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 11660218373710972210U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 53U)) + 14909034764605802354U) + aPhaseDOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16776955237009701511U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5834487809188925253U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4458820879204327709U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1498492772767040320U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4161765458781579617U;
            aOrbiterH = RotL64((aOrbiterH * 15535994410289065281U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10511923076962447765U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8575954471692620021U;
            aOrbiterA = RotL64((aOrbiterA * 12526744988828982731U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6536325446331340573U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1790628986900286346U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5262997114200816715U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2623814807619278590U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11676970995834706612U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10057461115132434901U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 10U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 54U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 746U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6597U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7206U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 2115U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 23U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 3684295017013759987U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 43U)) + 6740408842457292881U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 4563975890702399441U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 797804144825287940U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 19U)) + 2763779540450101303U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 5U)) + 13211846164102089685U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 58U)) + 15214578447281401982U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13745208628754232427U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17358621225969190747U;
            aOrbiterB = RotL64((aOrbiterB * 5325024317338823061U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 779739369960480023U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4370963533701407813U;
            aOrbiterD = RotL64((aOrbiterD * 3123135216876641039U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6061333005507739975U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3589705340762734456U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16499293983611196967U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10607697666369230567U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9356757995305239271U;
            aOrbiterG = RotL64((aOrbiterG * 10945513661439954731U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10093033335903048138U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 558431161176115540U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17795680919453449358U;
            aOrbiterE = RotL64((aOrbiterE * 3910117359996283803U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6096779391116214109U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17594243286880690775U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12655610181937429915U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 26U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 50U) + RotL64(aOrbiterB, 19U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14147U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 15338U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13129U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 9677U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 52U)) + (RotL64(aCross, 3U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + 12027839670755583592U) + aPhaseEOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15380130703509859843U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 4590907433867798074U;
            aOrbiterK = (aWandererA + RotL64(aCross, 48U)) + 1754574023602519724U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 19U)) + 9832756659564903767U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 13U)) + 5035088494491470403U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 14199170923323644638U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8325619421264440438U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 969534320779067977U;
            aOrbiterA = RotL64((aOrbiterA * 17767548306355264705U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 270575869402913847U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13344806516599578910U;
            aOrbiterC = RotL64((aOrbiterC * 10193544126281901579U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15143147951139409101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14425582489214169238U;
            aOrbiterK = RotL64((aOrbiterK * 16893787086337916355U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13951127523239064584U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14177925225918293579U;
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8258920744278218901U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7408161179397242453U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 975737128100519169U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8581481606764773468U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10078416198417433133U;
            aOrbiterG = RotL64((aOrbiterG * 1102721083915858247U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18299772198826189580U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 18304668908084397946U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10589455451200578687U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 54U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19244U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18863U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24494U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 19992U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 8506388683755208267U;
            aOrbiterE = (aWandererF + RotL64(aCross, 35U)) + 2179323259055019735U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 51U)) + 3345902531140983016U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 17456139311481306584U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 13U)) + 14587864088462311164U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 23U)) + 13178947246650647057U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 44U)) + RotL64(aCarry, 39U)) + 12866578138946916962U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13098524333655118173U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15451329483787541982U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13580376920467431451U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9494299579678389385U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15581954810375490643U;
            aOrbiterE = RotL64((aOrbiterE * 13670002280188424825U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4487042505730624892U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2774455928791636186U;
            aOrbiterG = RotL64((aOrbiterG * 15847933919136777451U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12435319582397755819U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 10077180055177766823U;
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10391963896910956455U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6149237416725301794U;
            aOrbiterJ = RotL64((aOrbiterJ * 10115917698918612823U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15673402771629639978U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14729117178956592426U;
            aOrbiterA = RotL64((aOrbiterA * 9070464269215820531U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14492001279368870240U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6278248084483259952U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16731228350971263873U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 4U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 4U) + aOrbiterG) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 58U)) + aPhaseEWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29225U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 26998U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24996U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27808U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 5573188770530340913U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 1431772230889897111U;
            aOrbiterD = (aWandererG + RotL64(aCross, 19U)) + 4809192776429682319U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 11U)) + 5576603692574369341U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 37U)) + 2720143226007220386U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 17220328778565331629U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 9629485808442089423U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1136998437010390983U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11893390497814523841U;
            aOrbiterD = RotL64((aOrbiterD * 5329621622743089531U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1764986431917532370U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1741014798007010376U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13414914086049500731U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12221368453236547044U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7694538641172350430U;
            aOrbiterC = RotL64((aOrbiterC * 8439120733670016501U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17472344518811560603U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3308740700728172984U;
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9535358833412446771U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11192312491731312451U;
            aOrbiterA = RotL64((aOrbiterA * 17405609148475445743U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14850451970047190039U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11932493299452443256U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7964808728820467795U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5972619895614731870U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17174497535809891690U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15471084511364572533U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + aPhaseEWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 60U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 7606U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((aIndex + 7080U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1586U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 5434U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 51U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 6024062041314952357U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 5U)) + 18340757093658015585U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 11911120493880346751U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 34U)) + RotL64(aCarry, 19U)) + 17428074353884654439U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 12790849760814795936U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12633397052172117800U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11946150433665237945U;
            aOrbiterJ = RotL64((aOrbiterJ * 10324089534873171291U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16842157900909419285U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14186235783224155962U;
            aOrbiterH = RotL64((aOrbiterH * 10521157787073684417U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 13284904542579767591U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 11609181965078844357U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5455780554452453513U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9628562297095374984U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7850281529011259759U;
            aOrbiterK = RotL64((aOrbiterK * 17611485102925470357U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 257458718073794527U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10693404545773519306U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14821443722828498323U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 24U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB + (((RotL64(aCross, 14U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10510U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 12064U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10726U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9075U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 56U)) + RotL64(aCarry, 5U)) + 5171470532667965920U;
            aOrbiterA = (aWandererE + RotL64(aCross, 19U)) + 750549462358682403U;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 3325689257577120525U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 18031575461559790826U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aScatter, 39U)) + 13874739537012288677U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4250029868785016865U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8211158803112611161U;
            aOrbiterK = RotL64((aOrbiterK * 9205801383408193959U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1083939790236786027U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3446525462376962464U;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 6973817815000417325U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15230876489676945543U;
            aOrbiterF = RotL64((aOrbiterF * 7737039082964537651U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9359727659738755880U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8775170107816327654U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6910680458261008653U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11958941755525038545U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16966819714283167348U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16363457661846050749U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 60U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 56U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterK, 11U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19433U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17964U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21494U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17154U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 51U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aCross, 29U)) + 18319689184146942855U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 8041304130090501019U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 43U)) + 11347064191990897738U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 4U)) + RotL64(aCarry, 57U)) + 15242243470024447468U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 10619749107163611105U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 14795614276221947128U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1578095288886372393U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9953192041564147241U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13593906305770501684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8919815528334599172U;
            aOrbiterI = RotL64((aOrbiterI * 2033810402808238127U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17425548324720065145U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11125018338392347335U;
            aOrbiterH = RotL64((aOrbiterH * 4377887040461528587U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3779189180734244399U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10958224663276134041U;
            aOrbiterB = RotL64((aOrbiterB * 6206963519509783781U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4317305352561612995U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4891139433808505355U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11507024985663120317U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 18U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 37U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 47U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25372U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25708U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31190U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 25399U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 8975885703279267062U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 5U)) + 8664844915562660637U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 12281774799736296726U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 51U)) + 15347461352311329726U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 27U)) + 12967500561828907834U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5002833859280402726U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11908257536954668983U;
            aOrbiterC = RotL64((aOrbiterC * 4384790916151202785U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17017174811949227162U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16851323125613931180U;
            aOrbiterD = RotL64((aOrbiterD * 12446990992858763577U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13469326957728686706U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5228638551056105241U;
            aOrbiterI = RotL64((aOrbiterI * 13369947664646167255U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11945166198089308564U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14781204627695095701U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5365325354838101092U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8017284997946310807U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 23U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 34U) + RotL64(aOrbiterD, 24U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 1255U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4415U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6354U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 289U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 6916817163240024692U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 6U)) + RotL64(aCarry, 11U)) + 14554930751292077817U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 41U)) + 1098305064484336101U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 41U)) + 12192821172420471527U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 53U)) + 2435134991707318845U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 1896745368738512624U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 1114996424222923873U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6248754732325773087U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9839135798371512656U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8037967239603177043U;
            aOrbiterG = RotL64((aOrbiterG * 7848951103759663025U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15185468738487237432U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4912098316394854543U;
            aOrbiterE = RotL64((aOrbiterE * 3072785550384399929U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13142688607850380888U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4507379759608945839U;
            aOrbiterD = RotL64((aOrbiterD * 2989332387754215967U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7299006009652289342U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 5390655277207053627U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10973744708856143715U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 20U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 9933U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 10616U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14960U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12081U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 36U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 15316464782468770057U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 5U)) + 6642872057476351588U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 42U)) + RotL64(aCarry, 21U)) + 660732654689529192U;
            aOrbiterE = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 7235418086884000655U) + aPhaseGOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 51U)) + 14784518476694580493U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12222433977933449375U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8573001207708329927U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17771120145431297541U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16035256260815013172U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15767726974121910203U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 719060452537759331U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 17712217935322939971U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 13488963456923357159U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16785285630840310405U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10222949131965611079U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1495561412321657209U;
            aOrbiterA = RotL64((aOrbiterA * 9706305581868526265U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16156530750584361434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7773792489045606309U;
            aOrbiterE = RotL64((aOrbiterE * 10730624207715601393U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18490U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 20978U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23042U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((aIndex + 20500U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 36U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 16922357079016918108U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 24U)) + RotL64(aCarry, 29U)) + 11771749797137599131U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 13U)) + 4635668433708036077U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 15827952719230577008U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 53U)) + 1495675306110023086U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7294835466949728365U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 179122461212041978U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14467072888722097971U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 545981421632236251U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15338259639814630535U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14895421566334357871U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12924313840290895215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17846785921286020610U;
            aOrbiterB = RotL64((aOrbiterB * 18309347016029917133U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 5721472794107057875U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16359630793856870319U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14186771515526698907U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10614102110239037308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16421992251278236531U;
            aOrbiterK = RotL64((aOrbiterK * 2561232904676068089U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 28U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 12U) + aOrbiterE) + RotL64(aOrbiterC, 50U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 13U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 26408U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26568U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30567U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27397U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 26U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 3U)) + 11700815697312060726U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 41U)) + 11808423452327465441U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 8670503858631730886U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 2400061067991988544U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 54U)) + RotL64(aCarry, 39U)) + 16163118178366229686U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3280178595904941068U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 3298683600817047727U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9865649058799255343U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16321624053445183574U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6730229877611375225U;
            aOrbiterD = RotL64((aOrbiterD * 2022290495153519279U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10162830636713641322U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15646771327759599256U;
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14841751262270544102U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9545541117228834895U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11529769874752969377U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 14676615635857599982U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1231768638470558855U;
            aOrbiterF = RotL64((aOrbiterF * 2716808508509014677U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 22U) + aOrbiterF) + RotL64(aOrbiterD, 56U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 39U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5869U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((aIndex + 1173U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4558U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 5880U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCarry, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererH + RotL64(aScatter, 27U)) + 13583136155674166402U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 12830472187484919497U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 4U)) + 18081197909484522509U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 39U)) + 8680634051297891550U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 13939998767458656823U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1795730579103692594U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17369751719734069999U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2633464694273697123U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 224769585901248068U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 4133547085925268180U;
            aOrbiterB = RotL64((aOrbiterB * 2611561365156544735U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7022512056309567391U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10319484359046945495U;
            aOrbiterJ = RotL64((aOrbiterJ * 3400140531307001933U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10483878349412282069U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6481381149199985736U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9701719367082506253U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13721077228796934509U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 9704818014314175007U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 760445624027740287U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 46U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 57U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterH, 10U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10316U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12177U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9529U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 11333U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 44U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 53U)) + 9041099828460168106U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 12883711604096848454U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 17420968786226443079U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 53U)) + 3448213891716125104U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aCross, 24U)) + 11866455977445336560U) + aPhaseHOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4119356835384495905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2186212599698637068U;
            aOrbiterK = RotL64((aOrbiterK * 6756888950976735707U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6506144898969301620U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 12556800923644051626U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15961043406612913121U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4075551535185182945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17877694808492008749U;
            aOrbiterE = RotL64((aOrbiterE * 901315308379887473U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5553428900598223316U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 14362304852277160675U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11415103199856419303U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9174200302876075831U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16110739511917638547U;
            aOrbiterJ = RotL64((aOrbiterJ * 7004356839428657949U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 60U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 21598U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 18901U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17215U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 22113U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 13U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 10805654776556844351U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 582794182442795335U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 39U)) + 2858343650974681068U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 8189584049022064284U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 51U)) + 1565100751996962893U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 8062028016947611891U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8280504280578451745U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5212851648135050483U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11326869194491655350U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1671695656567777163U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7511554500524257921U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2349843105293943452U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13015545152052004254U;
            aOrbiterB = RotL64((aOrbiterB * 1316662811685429983U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16703354404749291869U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8713231044374305801U;
            aOrbiterK = RotL64((aOrbiterK * 9242480982197688625U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11118401674497783533U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14857556493734710364U;
            aOrbiterD = RotL64((aOrbiterD * 3452566050389715195U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterK, 21U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 52U)) + aOrbiterB) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 31157U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31154U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24933U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 29344U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 37U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 12583180859826261500U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 9067093488553721468U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 12173106198862881754U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 23U)) + 11333491014394592654U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 40U)) + 3511883526940919554U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7416810692106273044U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8341174972619784110U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17722163445765437279U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2220852854836962979U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8090781422229383825U;
            aOrbiterA = RotL64((aOrbiterA * 578293950675644397U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2338801236599102223U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 12484514711848308104U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10364216764253366067U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13684861340589131816U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12796636819991873058U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5533508014234835669U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7634198650894837690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10240326122201201762U;
            aOrbiterG = RotL64((aOrbiterG * 8758703497719125901U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererF = aWandererF + (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterI, 60U)) + aOrbiterH) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 21U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
